// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/event.hpp

/** // doc: clxx/cl/event.hpp {{{
 * \file clxx/cl/event.hpp
 * \brief defines the \ref clxx::event class
 */ // }}}
#ifndef CLXX_CL_EVENT_HPP_INCLUDED
#define CLXX_CL_EVENT_HPP_INCLUDED

#include <clxx/cl/event_fwd.hpp>
#include <clxx/common/opencl.h>
#include <clxx/cl/command_queue.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/common/types.hpp>
#include <clxx/cl/clobj.hpp>

namespace clxx {
/** // doc: event {{{
 * \ingroup clxx_event_objects
 * \brief Encapsulates an OpenCL event object
 *
 * This class represents OpenCL event and forwards basic operations on
 * events to OpenCL. It encapsulates a \c cl_event identifier and
 * supports following operations:
 *
 * - event creation (constructors),
 * - automatic reference count management by using internally
 *   \ref retain_event() and \ref release_event(),
 * - retrieving event information from OpenCL (via class methods), by
 *   invoking internally \ref get_event_info().
 *
 * Although \ref clxx::event "event" maintains internally reference count
 * for its \c cl_event handle, it doesn't prevent one from stealing the
 * \c cl_event handle (\ref get(), \ref chk_get()). This gives rise to
 * manipulate the reference count outside of the \ref clxx::event object for
 * the given OpenCL event object. If you need to steal, use the retrieved
 * handle with care. If you retrieve the handle from \ref clxx::event
 * "event" object, increase its reference count with \ref
 * clxx::retain_event() "retain_event()" as soon as possible, and decrease
 * the reference count with \ref clxx::release_event() "release_event()"
 * once you don't need the handle. If you don't retain the event, it may be
 * unexpectedly released by \ref clxx::event "event's"  destructor,
 * assignment operator or the #assign() method.
 *
 * There are constructors which create new OpenCL event (a costly operation).
 * However, assignment operator and copy constructors just copy over the \c
 * cl_event handle and maintain reference count appropriately. To verify
 * if two \ref clxx::event "event" objects refer to the same OpenCL
 * event, use \c == operator (of \c != operator).
 *
 * An OpenCL event (identified by \c cl_event handle) is not released
 * until there is at least one \ref clxx::event "event" object
 * encapsulating its handle. On the other hand - the event may get released
 * by OpenCL when last \ref clxx::event "event" object gets deleted (the
 * ~event() destructor decreases reference count for its \c cl_event
 * handle with \ref clxx::release_event() "release_event()") or when the
 * last object gets assigned another OpenCL event (assignment operator or the
 * #assign() method).
 */ // }}}
class alignas(cl_event) event
  : public clobj<cl_event>
{
public:
  /** // doc: Base {{{
   * \brief Typedef for the base class type
   */ // }}}
  typedef clobj<cl_event> Base;
  using Base::Base;
  /** // doc: event() {{{
   * \brief Default constructor, see \ref clobj::clobj()
   */ // }}}
  event() = default;
  /** // doc: event() {{{
   * \brief Copy constructor, see \ref clobj::clobj(clobj const&)
   */ // }}}
  event(event const&) = default;
  /** // doc: event(context) {{{
   * \brief Create user event with #create_user_event()
   * \throw uninitialized_context_error
   *    Then \p ctx is uninitialized
   *
   * Also throws exceptions originating from #create_user_event().
   */ // }}}
  explicit event(context const& ctx);
  /** // doc: get_info(...) {{{
   * \brief Get profiling information for the command associated with event if
   *        profiling is enabled
   *
   * This function calls internally \ref clxx::get_event_profiling_info()
   * "get_event_profiling_info()".
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   *     See documentation of \ref profiling_info_t for possible values.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \e value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \ref clxx::get_event_profiling_info() "get_event_profiling_info()").
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \e value is \c NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \e value. If
   *    \e value_size_ret is \c NULL, it is ignored.
   *
   * \throws uninitialized_event_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_event_profiling_info().
   */ // }}}
  void get_profiling_info(profiling_info_t name, size_t value_size, void* value,
                          size_t* value_size_ret) const;
  /** // doc: get_command_queue() {{{
   * \brief Return the command-queue associated with this \ref clxx::event "event"
   *
   * \returns The command-queue associated with this \ref clxx::event "event"
   *
   * \throw uninitialized_event_error
   *    If this object is not initialized (see #is_initialized())
   *
   * Also throws exceptions originating from #get_event_info()
   */ // }}}
  command_queue get_command_queue() const;
  /** // doc: get_context() {{{
   * \brief Return the context associated with this \ref clxx::event "event"
   *
   * \returns The context associated with this \ref clxx::event "event"
   *
   * \throw uninitialized_event_error
   *    If this object is not initialized (see #is_initialized())
   *
   * Also throws exceptions originating from #get_event_info()
   */ // }}}
  context get_context() const;
  /** // doc: get_command_type() {{{
   * \brief Return the command associated with this \ref clxx::event "event"
   *
   * \returns The command associated with this \ref clxx::event "event"
   *
   * \throw uninitialized_event_error
   *    If this object is not initialized (see #is_initialized())
   *
   * Also throws exceptions originating from #get_event_info()
   */ // }}}
  command_type_t get_command_type() const;
  /** // doc: get_command_exec_status() {{{
   * \brief Return the execution status of the command identified by this \ref clxx::event "event"
   *
   * \returns The execution status of the command identified by this \ref clxx::event "event"
   *
   * \throw uninitialized_event_error
   *    If this object is not initialized (see #is_initialized())
   *
   * Also throws exceptions originating from #get_event_info()
   */ // }}}
  command_exec_status_t get_command_exec_status() const;
  /** // doc: get_profiling_command_queued() {{{
   * \brief Returns a 64-bit value that describes the current device time
   *        counter in nanoseconds when the command identified by event is
   *        enqueued in a command-queue by the host
   * \throw uninitialized_event_error
   *    If the \ref clxx::event "event" object is uninitialized
   *
   * Also may throw exceptions originating from #get_event_profiling_info()
   */ // }}}
  cl_ulong get_profiling_command_queued() const;
  /** // doc: get_profiling_command_submit() {{{
   * \brief Returns 64-bit value that describes the current device time counter
   *        in nanoseconds when the command identified by event that has been
   *        enqueued is submitted by the host to the device associated with the
   *        command-queue
   * \throw uninitialized_event_error
   *    If the \ref clxx::event "event" object is uninitialized
   *
   * Also may throw exceptions originating from #get_event_profiling_info()
   */ // }}}
  cl_ulong get_profiling_command_submit() const;
  /** // doc: get_profiling_command_start() {{{
   * \brief Returns 64-bit value that describes the current device time counter
   *        in nanoseconds when the command identified by event starts
   *        execution on the device
   * \throw uninitialized_event_error
   *    If the \ref clxx::event "event" object is uninitialized
   *
   * Also may throw exceptions originating from #get_event_profiling_info()
   */ // }}}
  cl_ulong get_profiling_command_start() const;
  /** // doc: get_profiling_command_end() {{{
   * \brief Returns 64-bit value that describes the current device time counter
   *        in nanoseconds when the command identified by event has finished
   *        execution on the device
   * \throw uninitialized_event_error
   *    If the \ref clxx::event "event" object is uninitialized
   *
   * Also may throw exceptions originating from #get_event_profiling_info()
   */ // }}}
  cl_ulong get_profiling_command_end() const;
#if CLXX_CL_H_VERSION_2_0
  /** // doc: get_profiling_command_complete() {{{
   * \brief Returns 64-bit value that describes the current device time counter
   *        in nanoseconds when the command identified by event and any child
   *        commands enqueued by this command on the device have finished
   *        execution
   * \throw uninitialized_event_error
   *    If the \ref clxx::event "event" object is uninitialized
   *
   * Also may throw exceptions originating from #get_event_profiling_info()
   */ // }}}
  cl_ulong get_profiling_command_complete() const;
#endif
};
} // end namespace clxx
#endif /* CLXX_CL_EVENT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
