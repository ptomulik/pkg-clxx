// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/command_queue.cpp {{{
 * \file clxx/command_queue.cpp
 * \brief Implements the \ref clxx::command_queue "command_queue" class
 */ // }}}
#include <clxx/command_queue.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <vector>

namespace clxx {

/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(command_queue const& p, command_queue_info_t name)
{
  T value;
  p.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
void command_queue::
_set_id(cl_command_queue id, bool retain_new, bool release_old)
{
  if(id != this->_id) // Avoid unintended deletion by clReleaseCommandQueue()
    {
      if(release_old && this->is_initialized())
        {
          release_command_queue(this->_id);
        }
      this->_id = id;
      if(retain_new)
        {
          retain_command_queue(this->_id);
        }
    }
}
/* ------------------------------------------------------------------------ */
command_queue::
command_queue(cl_command_queue id)
{
  this->_set_id(id, true, false);
}
/* ------------------------------------------------------------------------ */
command_queue::
command_queue(context const& ctx, device const& dev, command_queue_properties_t props)
{
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
  cl_command_queue id = create_command_queue(ctx.get_valid_id(),
                                             dev.get_valid_id(),
                                             props);
#elif CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
  cl_queue_properties props_array[3] = {CL_QUEUE_PROPERTIES, intval(props),
                                        static_cast<cl_queue_properties>(0)};
  cl_command_queue id = create_command_queue_with_properties(ctx.get_valid_id(),
                                                             dev.get_valid_id(),
                                                             props_array);
#endif
  this->_set_id(id, false, false);
}
/* ------------------------------------------------------------------------ */
command_queue::
command_queue(const command_queue& rhs)
{
  this->_set_id(rhs.get_valid_id(), true, false);
}
/* ------------------------------------------------------------------------ */
command_queue::
~command_queue()
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(clerror_no<status_t::invalid_command_queue> const&){ }
    }
}
/* ------------------------------------------------------------------------ */
void command_queue::
get_info(command_queue_info_t name, size_t value_size, void* value,
         size_t* value_size_ret) const
{
  get_command_queue_info(this->get_valid_id(), name, value_size, value, value_size_ret);
}
/* ------------------------------------------------------------------------ */
cl_command_queue command_queue::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_command_queue_error();
  return this->_id;
}
/* ------------------------------------------------------------------------ */
void command_queue::
assign(command_queue const& rhs)
{
  if(&rhs != this)
    this->_set_id(rhs.get_valid_id(), true, true);
}
/* ------------------------------------------------------------------------ */
context command_queue::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, command_queue_info_t::context));
}
/* ------------------------------------------------------------------------ */
device command_queue::
get_device() const
{
  return device(_get_pod_info<cl_device_id>(*this, command_queue_info_t::device));
}
/* ------------------------------------------------------------------------ */
cl_uint command_queue::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, command_queue_info_t::reference_count);
}
/* ------------------------------------------------------------------------ */
command_queue_properties_t command_queue::
get_properties() const
{
  return static_cast<command_queue_properties_t>(
    _get_pod_info<cl_command_queue_properties>(*this,command_queue_info_t::properties)
  );
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
