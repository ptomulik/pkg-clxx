// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/kernel.cpp {{{
 * \file clxx/kernel.cpp
 * \brief Implements the \ref clxx::kernel "kernel" class
 */ // }}}
#include <clxx/kernel.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <boost/shared_array.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(kernel const& p, kernel_info_t name)
{
  T value;
  p.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
static std::string
_get_str_info(kernel const& p, kernel_info_t name)
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
_get_arg_pod_info(kernel const& p, cl_uint arg_index, kernel_arg_info_t name)
{
  T value;
  p.get_arg_info(arg_index, name, sizeof(value), &value, NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
static std::string
_get_arg_str_info(kernel const& p, cl_uint arg_index, kernel_arg_info_t name)
{
  size_t size;
  p.get_arg_info(arg_index, name, 0, NULL, &size);

  boost::shared_array<char> str(new char[size]);
  // FIXME: is(str == nullptr) { throw clxx::bad_alloc() }
  p.get_arg_info(arg_index, name, size, str.get(), &size);
  return std::string(str.get());
}
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_work_group_pod_info(kernel const& p, device const& dev, kernel_work_group_info_t name)
{
  T value;
  p.get_work_group_info(dev, name, sizeof(value), &value, NULL);
  return value;
}
/* ----------------------------------------------------------------------- */
void kernel::
_set_id(cl_kernel k, bool retain_new, bool release_old)
{
  if(k != this->_id) // Avoid unintended deletion by clReleaseKernel()
    {
      if(release_old && this->is_initialized())
        {
          release_kernel(this->_id);
        }
      this->_id = k;
      if(retain_new)
        {
          retain_kernel(this->_id);
        }
    }
}
/* ----------------------------------------------------------------------- */
kernel::
kernel(cl_kernel id)
  :_id((cl_kernel)NULL) // because it's read by _set_id()
{
  this->_set_id(id, true, false);
}
/* ----------------------------------------------------------------------- */
kernel::
kernel(kernel const& k)
  :_id((cl_kernel)NULL) // because it's read by _set_id()
{
  this->_set_id(k.id(), true, false);
}
/* ----------------------------------------------------------------------- */
kernel::
kernel(program const& prog, std::string const& name)
  :_id((cl_kernel)NULL) // because it's readby _set_id()
{
  cl_kernel id = create_kernel(prog.get_valid_id(), name.data());
  // create_kernel() performs implicit retain, so we
  // don't have to retain it again here (thus 2 x false below)
  this->_set_id(id, false, false);
}
/* ----------------------------------------------------------------------- */
kernel::
~kernel()
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(clerror_no<status_t::invalid_kernel> const&) { }
    }
}
/* ------------------------------------------------------------------------ */
void kernel::
get_info(kernel_info_t name, size_t value_size, void* value,
         size_t* value_size_ret) const
{
  get_kernel_info(
      this->get_valid_id(),
      name,
      value_size,
      value,
      value_size_ret
  );
}
/* ----------------------------------------------------------------------- */
cl_kernel kernel::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_kernel_error();
  return this->_id;
}
/* ----------------------------------------------------------------------- */
cl_uint kernel::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, kernel_info_t::reference_count);
}
/* ----------------------------------------------------------------------- */
std::string kernel::
get_function_name() const
{
  return _get_str_info(*this, kernel_info_t::function_name);
}
/* ----------------------------------------------------------------------- */
cl_uint kernel::
get_num_args() const
{
  return _get_pod_info<cl_uint>(*this, kernel_info_t::num_args);
}
/* ----------------------------------------------------------------------- */
context kernel::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, kernel_info_t::context));
}
/* ----------------------------------------------------------------------- */
program kernel::
get_program() const
{
  return program(_get_pod_info<cl_program>(*this, kernel_info_t::program));
}
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
std::string kernel::
get_attributes() const
{
  return _get_str_info(*this, kernel_info_t::attributes);
}
#endif
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
/* ----------------------------------------------------------------------- */
void kernel::
get_arg_info(cl_uint arg_index, kernel_arg_info_t name, size_t value_size,
             void* value, size_t* value_size_ret) const
{
  get_kernel_arg_info(this->get_valid_id(),
                      arg_index,
                      name,
                      value_size,
                      value,
                      value_size_ret);
}
/* ----------------------------------------------------------------------- */
kernel_arg_address_qualifier_t kernel::
get_arg_address_qualifier(cl_uint arg_index) const
{
  return _get_arg_pod_info<kernel_arg_address_qualifier_t>(
            *this,
            arg_index,
            kernel_arg_info_t::address_qualifier
         );
}
/* ----------------------------------------------------------------------- */
kernel_arg_access_qualifier_t kernel::
get_arg_access_qualifier(cl_uint arg_index) const
{
  return _get_arg_pod_info<kernel_arg_access_qualifier_t>(
            *this,
            arg_index,
            kernel_arg_info_t::access_qualifier
         );
}
/* ----------------------------------------------------------------------- */
std::string kernel::
get_arg_type_name(cl_uint arg_index) const
{
  return _get_arg_str_info(*this, arg_index, kernel_arg_info_t::type_name);
}
/* ----------------------------------------------------------------------- */
kernel_arg_type_qualifier_t kernel::
get_arg_type_qualifier(cl_uint arg_index) const
{
  return _get_arg_pod_info<kernel_arg_type_qualifier_t>(
            *this,
            arg_index,
            kernel_arg_info_t::type_qualifier
         );
}
/* ----------------------------------------------------------------------- */
std::string kernel::
get_arg_name(cl_uint arg_index) const
{
  return _get_arg_str_info(*this, arg_index, kernel_arg_info_t::name);
}
/* ----------------------------------------------------------------------- */
#endif
void kernel::
get_work_group_info(device const& dev, kernel_work_group_info_t name,
                    size_t value_size, void* value, size_t* value_size_ret) const
{
  // note: NULL is allowed for device ID, see clGetKernelWorkGroupInfo()
  get_kernel_work_group_info(
      this->get_valid_id(),
      dev.id(),
      name,
      value_size,
      value,
      value_size_ret
  );
}
/* ----------------------------------------------------------------------- */
size_t kernel::
get_work_group_size(device const& dev) const
{
  return _get_work_group_pod_info<size_t>(
            *this,
            dev,
            kernel_work_group_info_t::work_group_size
         );
}
/* ----------------------------------------------------------------------- */
void kernel::
get_compile_work_group_size(size_t* result, device const& dev) const
{
  get_work_group_info(dev, kernel_work_group_info_t::compile_work_group_size,
                      3*sizeof(size_t), result, nullptr);
}
/* ----------------------------------------------------------------------- */
cl_ulong kernel::
get_local_mem_size(device const& dev) const
{
  return _get_work_group_pod_info<cl_ulong>(*this, dev,
            kernel_work_group_info_t::local_mem_size
         );
}
#if CL_VERSION_1_1
/* ----------------------------------------------------------------------- */
size_t kernel::
get_preferred_work_group_size_multiple(device const& dev) const
{
  return _get_work_group_pod_info<size_t>(*this, dev,
            kernel_work_group_info_t::preferred_work_group_size_multiple
         );
}
/* ----------------------------------------------------------------------- */
cl_ulong kernel::
get_private_mem_size(device const& dev) const
{
  return _get_work_group_pod_info<cl_ulong>(*this, dev,
            kernel_work_group_info_t::private_mem_size
         );
}
#endif
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
void kernel::
get_global_work_size(size_t* result, device const& dev) const
{
  get_work_group_info(dev, kernel_work_group_info_t::global_work_size,
                      3*sizeof(size_t), result, nullptr);
}
#endif
/* ----------------------------------------------------------------------- */
void kernel::
set_arg(cl_uint arg_index, size_t size, const void* arg_value) const
{
  set_kernel_arg(this->get_valid_id(), arg_index, size, arg_value);
}
/* ----------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
void kernel::
set_arg_svm_pointer(cl_uint arg_index, const void* arg_value) const
{
  set_kernel_arg_svm_pointer(this->get_valid_id(), arg_index, arg_value);
}
#endif
/* ----------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
void kernel::
set_exec_info(kernel_exec_info_t name, size_t value_size, const void* value) const
{
  set_kernel_exec_info(
      this->get_valid_id(),
      name,
      value_size,
      value
  );
}
#endif
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
