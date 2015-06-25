// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/event.cpp {{{
 * \file clxx/event.cpp
 * \brief Implements the \ref clxx::event class
 */ // }}}
#include <clxx/event.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(event const& p, event_info_t name)
{
  T value;
  p.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ----------------------------------------------------------------------- */
void event::
_set_id(cl_event p, bool retain_new, bool release_old)
{
  if(p != this->_id) // Avoid unintended deletion by clReleaseEvent()
    {
      if(release_old && this->is_initialized())
        {
          release_event(this->_id);
        }
      this->_id = p;
      if(retain_new)
        {
          retain_event(this->_id);
        }
    }
}
/* ----------------------------------------------------------------------- */
event::
event() noexcept
  : _id((cl_event)NULL)
{
}
/* ----------------------------------------------------------------------- */
event::
event(cl_event id)
  :_id((cl_event)NULL) // because it's read by _set_id()
{
  this->_set_id(id, true, false);
}
/* ----------------------------------------------------------------------- */
event::
event(context const& ctx)
  :_id((cl_event)NULL) // because it's read by _set_id()
{
  this->_set_id(create_user_event(ctx.get_valid_id()), false, false);
}
/* ----------------------------------------------------------------------- */
event::
event(event const& p)
  :_id((cl_event)NULL) // because it's read by _set_id()
{
  this->_set_id(p.id(), true, false);
}
/* ----------------------------------------------------------------------- */
event::
~event()
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(clerror_no<status_t::invalid_event> const&) { }
    }
}
/* ------------------------------------------------------------------------ */
void event::
get_info(event_info_t name, size_t value_size, void* value,
         size_t* value_size_ret) const
{
  get_event_info(
      this->get_valid_id(),
      name,
      value_size,
      value,
      value_size_ret
  );
}
/* ----------------------------------------------------------------------- */
cl_event event::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_event_error();
  return this->_id;
}
/* ----------------------------------------------------------------------- */
cl_uint event::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, event_info_t::reference_count);
}
/* ----------------------------------------------------------------------- */
context event::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, event_info_t::context));
}
/* ----------------------------------------------------------------------- */
command_queue event::
get_command_queue() const
{
  return command_queue(_get_pod_info<cl_command_queue>(*this, event_info_t::command_queue));
}
/* ----------------------------------------------------------------------- */
command_type_t event::
get_command_type() const
{
  return _get_pod_info<command_type_t>(*this, event_info_t::command_type);
}
/* ----------------------------------------------------------------------- */
command_exec_status_t event::
get_command_exec_status() const
{
  return _get_pod_info<command_exec_status_t>(*this, event_info_t::command_execution_status);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
