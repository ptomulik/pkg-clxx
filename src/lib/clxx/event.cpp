// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/event.cpp {{{
 * \file clxx/event.cpp
 * \brief Implements the \ref clxx::event class
 */ // }}}
#include <clxx/event.hpp>
#include <clxx/clobj_impl.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
// Instantiate the base class
template class clobj<cl_event>;
static_assert(
    sizeof(clobj<cl_event>) == sizeof(cl_event),
    "sizeof(clobj<cl_event>) differs from sizeof(cl_event)"
);
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_profiling_info(event const& p, profiling_info_t name)
{
  T value;
  p.get_profiling_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ----------------------------------------------------------------------- */
event::
event(context const& ctx)
  :Base((cl_event)NULL) // because it's read by _set_handle()
{
  this->_set_handle(create_user_event(ctx.chk_get()), false, false);
}
/* ----------------------------------------------------------------------- */
void event::
get_profiling_info(profiling_info_t name, size_t value_size, void* value,
                   size_t* value_size_ret) const
{
  get_event_profiling_info(
      this->chk_get(),
      name,
      value_size,
      value,
      value_size_ret
  );
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
cl_ulong event::
get_profiling_command_queued() const
{
  return _get_pod_profiling_info<cl_ulong>(*this, profiling_info_t::queued);
}
/* ----------------------------------------------------------------------- */
cl_ulong event::
get_profiling_command_submit() const
{
  return _get_pod_profiling_info<cl_ulong>(*this, profiling_info_t::submit);
}
/* ----------------------------------------------------------------------- */
cl_ulong event::
get_profiling_command_start() const
{
  return _get_pod_profiling_info<cl_ulong>(*this, profiling_info_t::start);
}
/* ----------------------------------------------------------------------- */
cl_ulong event::
get_profiling_command_end() const
{
  return _get_pod_profiling_info<cl_ulong>(*this, profiling_info_t::end);
}
/* ----------------------------------------------------------------------- */
#if CLXX_CL_H_VERSION_2_0
cl_ulong event::
get_profiling_command_complete() const
{
  return _get_pod_profiling_info<cl_ulong>(*this, profiling_info_t::complete);
}
#endif
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
