// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/kernel_exec.cpp {{{
 * \file clxx/kernel_exec.cpp
 * \brief Implements \ref clxx::enqueue_ndrange_kernel(clxx::command_queue const&, clxx::kernel const&, clxx::ndrange const&, clxx::events const&) "enqueue_ndrange_kernel()" and friends.
 */ // }}}
#include <clxx/kernel_exec.hpp>
#include <clxx/functions.hpp>
#include <clxx/command_queue.hpp>
#include <clxx/kernel.hpp>
#include <clxx/util/obj2cl.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       cl_uint num_events_in_wait_list,
                       clxx::event const* event_wait_list,
                       clxx::event* event)
{
  clxx::event tmp;
  enqueue_ndrange_kernel(command_queue.chk_get(),
                         kernel.chk_get(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         num_events_in_wait_list,
                         obj2cl(event_wait_list),
                         event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintain reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::events const& event_wait_list,
                       clxx::event* event)
{
  clxx::event tmp;
  enqueue_ndrange_kernel(command_queue.chk_get(),
                         kernel.chk_get(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         event_wait_list.size(),
                         obj2cl(event_wait_list),
                         event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintain reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::event* event)
{
  clxx::event tmp;
  enqueue_ndrange_kernel(command_queue.chk_get(),
                         kernel.chk_get(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         0,
                         nullptr,
                         event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintain reference count in *event
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
