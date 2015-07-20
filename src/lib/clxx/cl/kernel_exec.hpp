// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/kernel_exec.hpp

/** // doc: clxx/cl/kernel_exec.hpp {{{
 * \file clxx/cl/kernel_exec.hpp
 * \brief Declares \ref clxx::enqueue_ndrange_kernel(clxx::command_queue const&, clxx::kernel const&, clxx::ndrange const&, clxx::events const&, clxx::event*) "enqueue_ndrange_kernel()" and friends.
 */ // }}}
#ifndef CLXX_CL_KERNEL_EXEC_HPP_INCLUDED
#define CLXX_CL_KERNEL_EXEC_HPP_INCLUDED

#include <clxx/cl/command_queue_fwd.hpp>
#include <clxx/cl/kernel_fwd.hpp>
#include <clxx/common/ndrange.hpp>
#include <clxx/cl/events.hpp>

namespace clxx {
/** \addtogroup clxx_executing_kernels
 * @{ */
/** // doc: enqueue_ndrange_kernel() {{{
 * \brief Enqueues a command to execute a kernel on a device
 *
 * \param command_queue
 *    A valid host command-queue. The \p kenel will be queued for execution on
 *    the device associated with \p command_queue.
 * \param kernel
 *    A valid \ref clxx::kernel "kernel" object. The OpenCL context associated
 *    with \p kernel and \p command_queue must be the same.
 * \param ndrange
 *    A valid \ref clxx::ndrange "ndrange" object. Defines work size and work
 *    group size used to execute the kernel.
 * \param num_events_in_wait_list
 *    Number of events in \p event_wait_list. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed.
 * \param event
 *    Returns an \ref clxx::event "event" object that identifies this
 *    particular kernel execution instance. Event obejcts are unique and can be
 *    used to identify a particular kernel execution instance later on.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_kernel_error
 *    When the \p kernel is uninitialized
 *
 * Also throws exceptions originating from #enqueue_ndrange_kernel() and from
 * \ref clxx::event::operator=.
 */ // }}}
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       cl_uint num_events_in_wait_list,
                       clxx::event const* event_wait_list,
                       clxx::event* event = nullptr);
/** // doc: enqueue_ndrange_kernel() {{{
 * \brief Enqueues a command to execute a kernel on a device
 *
 * \param command_queue
 *    A valid host command-queue. The \p kenel will be queued for execution on
 *    the device associated with \p command_queue.
 * \param kernel
 *    A valid \ref clxx::kernel "kernel" object. The OpenCL context associated
 *    with \p kernel and \p command_queue must be the same.
 * \param ndrange
 *    A valid \ref clxx::ndrange "ndrange" object. Defines work size and work
 *    group size used to execute the kernel.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed.
 * \param event
 *    Returns an \ref clxx::event "event" object that identifies this
 *    particular kernel execution instance. Event obejcts are unique and can be
 *    used to identify a particular kernel execution instance later on.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_kernel_error
 *    When the \p kernel is uninitialized
 *
 * Also throws exceptions originating from #enqueue_ndrange_kernel() and from
 * \ref clxx::event::operator=.
 */ // }}}
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::events const& event_wait_list,
                       clxx::event* event = nullptr);
/** // doc: enqueue_ndrange_kernel() {{{
 * \brief Enqueues a command to execute a kernel on a device
 *
 * \param command_queue
 *    A valid host command-queue. The \p kenel will be queued for execution on
 *    the device associated with \p command_queue.
 * \param kernel
 *    A valid \ref clxx::kernel "kernel" object. The OpenCL context associated with \p kernel
 *    and \p command_queue must be the same.
 * \param ndrange
 *    A valid \ref clxx::ndrange "ndrange" object. Defines work size and work
 *    group size used to execute the kernel.
 * \param event
 *    Returns an \ref clxx::event "event" object that identifies this
 *    particular kernel execution instance. Event obejcts are unique and can be
 *    used to identify a particular kernel execution instance later on.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_kernel_error
 *    When the \p kernel is uninitialized
 *
 * Also throws exceptions originating from #enqueue_ndrange_kernel() and from
 * \ref clxx::event::operator=.
 */ // }}}
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::event* event = nullptr);
/* @} */
} // end namespace clxx

#endif /* CLXX_CL_KERNEL_EXEC_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
