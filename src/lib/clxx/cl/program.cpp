// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program.cpp {{{
 * \file clxx/cl/program.cpp
 * \brief Implements the \ref clxx::program "program" class and related functions
 */ // }}}
#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/common/obj2cl.hpp>
#include <clxx/cl/clobj_impl.hpp>
#include <boost/shared_array.hpp>
#include <algorithm>

namespace clxx {
/* ------------------------------------------------------------------------ */
// Instantiate the base class
template class clobj<cl_program>;
static_assert(
    sizeof(clobj<cl_program>) == sizeof(cl_program),
    "sizeof(clobj<cl_program>) differs from sizeof(cl_program)"
);
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
program::
program(context const& ctx, program_sources const& sources)
  :Base((cl_program)NULL) // because it's read by _set_handle()
{
  if(sources.size() == 0ul)
      throw invalid_argument_error();

  cl_program id = create_program_with_source(
      ctx.chk_get(),
      sources.size(),
      _cstrings(sources).get(),
      NULL
  );
  // create_program_with_source() performs implicit retain, so we don't
  // have to retain it again here (thus 2 x false below)
  this->_set_handle(id, false, false);
}
/* ----------------------------------------------------------------------- */
program::
program(context const& ctx, devices const& device_list,
        program_binaries const& binaries,
        std::vector<status_t>& binary_status)
  : Base()
{
  if(device_list.size() == 0ul || device_list.size() != binaries.size())
      throw invalid_argument_error();

  binary_status.resize(device_list.size());
  cl_program id = create_program_with_binary(
      ctx.chk_get(),
      device_list.size(),
      obj2cl(device_list),
      _lengths(binaries).get(),
      _pointers(binaries).get(),
      (cl_int*)binary_status.data()
  );
  // create_program_with_binary() performs implicit retain, so we don't
  // have to retain it again here (thus 2 x false below)
  this->_set_handle(id, false, false);
}
/* ----------------------------------------------------------------------- */
program::
program(context const& ctx, devices const& device_list,
        program_binaries const& binaries)
  : Base()
{
  if(device_list.size() == 0ul || device_list.size() != binaries.size())
      throw invalid_argument_error();

  cl_program id = create_program_with_binary(
      ctx.chk_get(),
      device_list.size(),
      obj2cl(device_list),
      _lengths(binaries).get(),
      _pointers(binaries).get(),
      NULL
  );
  // create_program_with_binary() performs implicit retain, so we don't
  // have to retain it again here (thus 2 x false below)
  this->_set_handle(id, false, false);
}
/* ----------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
program::
program(context const& ctx, devices const& device_list,
        std::string const& kernel_names)
  : Base()
{
  cl_program id = create_program_with_built_in_kernels(
      ctx.chk_get(),
      device_list.size(),
      obj2cl(device_list),
      kernel_names.data()
  );
  // create_program_with_built_in_kernels() performs implicit retain, so we
  // don't have to retain it again here (thus 2 x false below)
  this->_set_handle(id, false, false);
}
#endif
/* ----------------------------------------------------------------------- */
void program::
get_build_info(device const& dev, program_build_info_t name,
               size_t value_size, void* value, size_t* value_size_ret) const
{
  get_program_build_info(
      this->chk_get(),
      dev.chk_get(),
      name,
      value_size,
      value,
      value_size_ret
  );
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
      this->chk_get(),
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

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
