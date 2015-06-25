// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/program.cpp {{{
 * \file clxx/program.cpp
 * \brief Implements the \ref clxx::program "program" class and related functions
 */ // }}}
#include <clxx/program.hpp>
#include <clxx/context.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/util/obj2cl.hpp>
#include <boost/shared_array.hpp>
#include <algorithm>

namespace clxx {
/* ------------------------------------------------------------------------ */
template<class X>
static boost::shared_array<size_t>
_lengths(X const& x)
{
  typedef boost::shared_array<size_t> array;
  array a(new size_t[x.size()]);
  auto op =  [](typename X::const_reference b) -> size_t { return b.size(); };
  std::transform(x.begin(), x.end(), a.get(), op);
  return a;
}
/* ------------------------------------------------------------------------ */
template<typename Ptr, typename Ref, class X>
static boost::shared_array<Ptr>
_pointers_impl(X& x)
{
  typedef boost::shared_array<Ptr> array;
  array a(new Ptr[x.size()]);
  auto op =  [](Ref b) -> Ptr { return b.data(); };
  std::transform(x.begin(), x.end(), a.get(), op);
  return a;
}
/* ------------------------------------------------------------------------ */
static boost::shared_array<unsigned char const*>
_pointers(program_binaries const& x)
{
  typedef unsigned char const* Ptr;
  typedef program_binary const& Ref;
  typedef program_binaries const X;
  return _pointers_impl<Ptr, Ref, X>(x);
}
/* ------------------------------------------------------------------------ */
static boost::shared_array<unsigned char*>
_pointers(program_binaries& x)
{
  typedef unsigned char* Ptr;
  typedef program_binary& Ref;
  typedef program_binaries X;
  return _pointers_impl<Ptr, Ref, X>(x);
}
/* ------------------------------------------------------------------------ */
static boost::shared_array<char const*>
_cstrings(program_sources const& sources)
{
  typedef boost::shared_array<char const*> array;
  array a(new char const*[sources.size()]);
  auto op =  [](program_source const& b) -> char const* { return b.data(); };
  std::transform(sources.begin(), sources.end(), a.get(), op);
  return a;
}
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(program const& p, program_info_t name)
{
  T value;
  p.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
template<typename T> static std::vector<T>
_get_vec_info(program const& p, program_info_t name)
{
  size_t size;
  p.get_info(name,0,NULL,&size);
  std::vector<T> values(size/sizeof(T));
  p.get_info(name,values.size()*sizeof(T),&values.front(),NULL);
  return values;
}
/* ------------------------------------------------------------------------ */
static std::string
_get_str_info(program const& p, program_info_t name)
{
  size_t size;
  p.get_info(name,0,NULL,&size);

  boost::shared_array<char> str(new char[size]);
  // FIXME: is(str == nullptr) { throw clxx::bad_alloc() }
  p.get_info(name,size,str.get(),&size);
  return std::string(str.get());
}
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_build_info(program const& p, device const& d, program_build_info_t name)
{
  T value;
  p.get_build_info(d, name,sizeof(value),&value,NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
static std::string
_get_str_build_info(program const& p, device const& d, program_build_info_t name)
{
  size_t size;
  p.get_build_info(d, name,0,NULL,&size);

  boost::shared_array<char> str(new char[size]);
  // FIXME: is(str == nullptr) { throw clxx::bad_alloc() }
  p.get_build_info(d, name,size,str.get(),&size);
  return std::string(str.get());
}
/* ----------------------------------------------------------------------- */
void program::
_set_id(cl_program p, bool retain_new, bool release_old)
{
  if(p != this->_id) // Avoid unintended deletion by clReleaseProgram()
    {
      if(release_old && this->is_initialized())
        {
          release_program(this->_id);
        }
      this->_id = p;
      if(retain_new)
        {
          retain_program(this->_id);
        }
    }
}
/* ----------------------------------------------------------------------- */
program::
program() noexcept
  :_id((cl_program)NULL)
{
}
/* ----------------------------------------------------------------------- */
program::
program(cl_program id)
  :_id((cl_program)NULL) // because it's read by _set_id()
{
  this->_set_id(id, true, false);
}
/* ----------------------------------------------------------------------- */
program::
program(program const& p)
  :_id((cl_program)NULL) // because it's read by _set_id()
{
  this->_set_id(p.id(), true, false);
}
/* ----------------------------------------------------------------------- */
program::
program(context const& ctx, program_sources const& sources)
  :_id((cl_program)NULL) // because it's read by _set_id()
{
  if(sources.size() == 0ul)
      throw invalid_argument_error();

  cl_program id = create_program_with_source(
      ctx.get_valid_id(),
      sources.size(),
      _cstrings(sources).get(),
      NULL
  );
  // create_program_with_source() performs implicit retain, so we don't
  // have to retain it again here (thus 2 x false below)
  this->_set_id(id, false, false);
}
/* ----------------------------------------------------------------------- */
program::
program(context const& ctx, devices const& device_list,
        program_binaries const& binaries,
        std::vector<status_t>& binary_status)
  :_id((cl_program)NULL) // because it's read by _set_id()
{
  if(device_list.size() == 0ul || device_list.size() != binaries.size())
      throw invalid_argument_error();

  binary_status.resize(device_list.size());
  cl_program id = create_program_with_binary(
      ctx.get_valid_id(),
      device_list.size(),
      obj2cl(device_list),
      _lengths(binaries).get(),
      _pointers(binaries).get(),
      (cl_int*)binary_status.data()
  );
  // create_program_with_binary() performs implicit retain, so we don't
  // have to retain it again here (thus 2 x false below)
  this->_set_id(id, false, false);
}
/* ----------------------------------------------------------------------- */
program::
program(context const& ctx, devices const& device_list,
        program_binaries const& binaries)
  :_id((cl_program)NULL) // because it's read by _set_id()
{
  if(device_list.size() == 0ul || device_list.size() != binaries.size())
      throw invalid_argument_error();

  cl_program id = create_program_with_binary(
      ctx.get_valid_id(),
      device_list.size(),
      obj2cl(device_list),
      _lengths(binaries).get(),
      _pointers(binaries).get(),
      NULL
  );
  // create_program_with_binary() performs implicit retain, so we don't
  // have to retain it again here (thus 2 x false below)
  this->_set_id(id, false, false);
}
/* ----------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
program::
program(context const& ctx, devices const& device_list,
        std::string const& kernel_names)
  :_id((cl_program)NULL) // because it's read by _set_id()
{
  cl_program id = create_program_with_built_in_kernels(
      ctx.get_valid_id(),
      device_list.size(),
      obj2cl(device_list),
      kernel_names.data()
  );
  // create_program_with_built_in_kernels() performs implicit retain, so we
  // don't have to retain it again here (thus 2 x false below)
  this->_set_id(id, false, false);
}
#endif
/* ----------------------------------------------------------------------- */
program::
~program()
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(clerror_no<status_t::invalid_program> const&) { }
    }
}
/* ------------------------------------------------------------------------ */
void program::
get_info(program_info_t name, size_t value_size, void* value,
         size_t* value_size_ret) const
{
  get_program_info(
      this->get_valid_id(),
      name,
      value_size,
      value,
      value_size_ret
  );
}
/* ----------------------------------------------------------------------- */
void program::
get_build_info(device const& dev, program_build_info_t name,
               size_t value_size, void* value, size_t* value_size_ret) const
{
  get_program_build_info(
      this->get_valid_id(),
      dev.get_valid_id(),
      name,
      value_size,
      value,
      value_size_ret
  );
}
/* ----------------------------------------------------------------------- */
cl_program program::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_program_error();
  return this->_id;
}
/* ----------------------------------------------------------------------- */
cl_uint program::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, program_info_t::reference_count);
}
/* ----------------------------------------------------------------------- */
context program::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, program_info_t::context));
}
/* ----------------------------------------------------------------------- */
cl_uint program::
get_num_devices() const
{
  return _get_pod_info<cl_uint>(*this, program_info_t::num_devices);
}
/* ----------------------------------------------------------------------- */
devices program::
get_devices() const
{
  return make_devices(_get_vec_info<cl_device_id>(*this, program_info_t::devices));
}
/* ----------------------------------------------------------------------- */
program_source program::
get_source() const
{
  return _get_str_info(*this, program_info_t::source);
}
/* ----------------------------------------------------------------------- */
std::vector<size_t> program::
get_binary_sizes() const
{
  return _get_vec_info<size_t>(*this, program_info_t::binary_sizes);
}
/* ----------------------------------------------------------------------- */
program_binaries program::
get_binaries() const
{
  std::vector<size_t> sizes(this->get_binary_sizes());
  program_binaries bins(sizes.size());

  for(size_t i = 0; i < sizes.size(); ++i)
    bins[i].resize(sizes[i]);

  get_program_info(
      this->get_valid_id(),
      program_info_t::binaries,
      bins.size(),
      _pointers(bins).get(),
      NULL
  );
  return bins;
}
/* ----------------------------------------------------------------------- */
size_t program::
get_num_kernels() const
{
  return _get_pod_info<size_t>(*this, program_info_t::num_kernels);
}
/* ----------------------------------------------------------------------- */
std::string program::
get_kernel_names() const
{
  return _get_str_info(*this, program_info_t::kernel_names);
}
/* ----------------------------------------------------------------------- */
build_status_t program::
get_build_status(device const& dev) const
{
  return _get_pod_build_info<build_status_t>(*this, dev, program_build_info_t::status);
}
/* ----------------------------------------------------------------------- */
std::string program::
get_build_options(device const& dev) const
{
  return _get_str_build_info(*this, dev, program_build_info_t::options);
}
/* ----------------------------------------------------------------------- */
std::string program::
get_build_log(device const& dev) const
{
  return _get_str_build_info(*this, dev, program_build_info_t::log);
}
/* ----------------------------------------------------------------------- */
program_binary_type_t program::
get_binary_type(device const& dev) const
{
  return _get_pod_build_info<program_binary_type_t>(
      *this,
      dev,
      program_build_info_t::binary_type
  );
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

namespace clxx {
/* ----------------------------------------------------------------------- */
void
build_program(program const& prog, std::string const& options)
{
  build_program(
      prog.get_valid_id(),
      0ul,
      NULL,
      options.data(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
build_program(program const& prog, devices const& devs,
              std::string const& options)
{
  build_program(
      prog.get_valid_id(),
      devs.size(),
      obj2cl(devs),
      options.data(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
build_program(program const& prog, std::string const& options,
              program_observer& observer)
{
  build_program(
      prog.get_valid_id(),
      0ul,
      NULL,
      options.data(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
/* ----------------------------------------------------------------------- */
void
build_program(program const& prog, devices const& devs, std::string const& options,
              program_observer& observer)
{
  build_program(
      prog.get_valid_id(),
      devs.size(),
      obj2cl(devs),
      options.data(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
/* ----------------------------------------------------------------------- */
void
compile_program(program const& prog, std::string const& options,
                programs const& input_headers,
                std::vector<std::string> const& header_include_names)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      prog.get_valid_id(),
      0ul,
      NULL,
      options.data(),
      input_headers.size(),
      obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
compile_program(program const& prog, std::string const& options,
                programs const& input_headers,
                std::vector<std::string> const& header_include_names,
                program_observer& observer)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      prog.get_valid_id(),
      0ul,
      NULL,
      options.data(),
      input_headers.size(),
      obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
/* ----------------------------------------------------------------------- */
void
compile_program(program const& prog, devices const& devs,
                std::string const& options, programs const& input_headers,
                std::vector<std::string> const& header_include_names)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      prog.get_valid_id(),
      devs.size(),
      obj2cl(devs),
      options.data(),
      input_headers.size(),
      obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
compile_program(program const& prog, devices const& devs,
                std::string const& options, programs const& input_headers,
                std::vector<std::string> const& header_include_names,
                program_observer& observer)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      prog.get_valid_id(),
      devs.size(),
      obj2cl(devs),
      options.data(),
      input_headers.size(),
      obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
/* ----------------------------------------------------------------------- */
#endif // CLXX_OPENCL_ALLOWED(clCompileProgram)
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
/* ----------------------------------------------------------------------- */
program
link_program(context const& ctx, devices const& device_list,
             std::string const& options, programs const& input_programs)
{
  return program(
    link_program(
      ctx.get_valid_id(),
      device_list.size(),
      obj2cl(device_list),
      options.data(),
      input_programs.size(),
      obj2cl(input_programs),
      nullptr,
      nullptr
    )
  );
}
/* ----------------------------------------------------------------------- */
program
link_program(context const& ctx, devices const& device_list,
             std::string const& options, programs const& input_programs,
             program_observer& observer)
{
  return program(
    link_program(
      ctx.get_valid_id(),
      device_list.size(),
      obj2cl(device_list),
      options.data(),
      input_programs.size(),
      obj2cl(input_programs),
      observer.fcn_ptr(),
      observer.fcn_arg()
    )
  );
}
#endif // CLXX_OPENCL_ALLOWED(clLinkProgram)
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
