// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/kernel_exec.hpp

/** // doc: clxx/kernel_exec.hpp {{{
 * \file clxx/kernel_exec.hpp
 * \brief Declares \ref clxx::enqueue_ndrange_kernel(clxx::command_queue const&, clxx::kernel const&, clxx::ndrange const&, clxx::events const&) "enqueue_ndrange_kernel()" and friends.
 */ // }}}
#ifndef CLXX_KERNEL_EXEC_HPP_INCLUDED
#define CLXX_KERNEL_EXEC_HPP_INCLUDED

#include <clxx/command_queue_fwd.hpp>
#include <clxx/kernel_fwd.hpp>
#include <clxx/ndrange.hpp>
#include <clxx/events.hpp>

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
                       clxx::event& event);
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
                       clxx::event& event);
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
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_kernel_error
 *    When the \p kernel is uninitialized
 *
 * Also throws exceptions originating from #enqueue_ndrange_kernel().
 */ // }}}
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::events const& event_wait_list);
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
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_kernel_error
 *    When the \p kernel is uninitialized
 *
 * Also throws exceptions originating from #enqueue_ndrange_kernel().
 */ // }}}
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange);
/* @} */
} // end namespace clxx

#endif /* CLXX_KERNEL_EXEC_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
