// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/event.hpp

/** // doc: clxx/event.hpp {{{
 * \file clxx/event.hpp
 * \brief defines the \ref clxx::event class
 */ // }}}
#ifndef CLXX_EVENT_HPP_INCLUDED
#define CLXX_EVENT_HPP_INCLUDED

#include <clxx/event_fwd.hpp>
#include <clxx/cl/cl.h>
#include <clxx/command_queue.hpp>
#include <clxx/context.hpp>
#include <clxx/types.hpp>

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
 * \c cl_event handle (\ref id(), \ref get_valid_id()). This gives rise to
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
{
private:
  cl_event _id;
protected:
  /** // doc: _set_id(cl_event, bool, bool) {{{
   * \brief Set the \c cl_event handle to this object
   *
   * \param prog the \c cl_event handle (OpenCL event),
   * \param retain_new whether to invoke \ref retain_event() on *prog*,
   * \param release_old whether to invoke \ref release_event() on the handle
   *        held up to this moment by this object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_event().
   */ // }}}
  void _set_id(cl_event prog, bool retain_new, bool release_old);
public:
  /** // doc: event() {{{
   * \brief Default constructor
   *
   * Sets the internal \c cl_event identifier to \c NULL. The
   * default-constructed \ref clxx::event "event" object is considered to be
   * uninitialized.
   */ // }}}
  event() noexcept;
  /** // doc: event(cl_event) {{{
   * \brief Creates \ref clxx::event "event" object from explicitly given
   *        OpenCL \c cl_event handle.
   *
   * The constructor internally retains the provided OpenCL event identified
   * by *id* (\ref clxx::retain_event()).
   *
   * \param id handle (identifier) to an OpenCL event that has to be
   *           encapsulated by the newly created \ref clxx::event "event"
   *           object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_event().
   */ // }}}
  explicit event(cl_event id);
  /** // doc: event(context) {{{
   * \brief Create user event with #create_user_event()
   * \throw uninitialized_context_error
   *    Then \p ctx is uninitialized
   *
   * Also throws exceptions originating from #create_user_event().
   */ // }}}
  explicit event(context const& ctx);
  /** // doc: event(event const&) {{{
   * \brief Copy constructor
   *
   * The constructor internally retains the provided OpenCL event identified
   * by *id* (\ref clxx::retain_event()).
   *
   * \param e a \ref clxx::event "event" object to be copied.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_event().
   */ // }}}
  event(event const& e);
  /** // doc: ~event() {{{
   * \brief Destructor
   *
   * If the event was initialized properly, then it internally releases the
   * event by \ref release_event().
   */ // }}}
  ~event();
  /** // doc: id() {{{
   * \brief Get the \c cl_event handle held by this object
   *
   * \returns the OpenCL event handle of type \c cl_event held by this
   *          object
   */ // }}}
  cl_event id() const noexcept
  { return this->_id; }
  /** // doc: get_valid_id() {{{
   * \brief Check if \c this object is initialized and return \c cl_event
   *        handle held by this object.
   *
   * \returns The \c cl_event handle to OpenCL event encapsulated within
   *          this object.
   *
   * \throws uninitialized_event_error when the object was not properly
   *        initialized (see is_initialized()).
   */ // }}}
  cl_event get_valid_id() const;
  /** // doc: operator= {{{
   * \brief Assignment operator
   *
   * \param rhs Another event object to be assigned to this object
   *
   *  This operation copies the \c cl_event handle held by \e rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throws uninitialized_event_error
   *    when the \e rhs object is in uninitialized state
   * \throws clerror_no<status_t::invalid_event>
   *    when the \e rhs holds invalid \c cl_event handle
   * \throws unexpected_clerror
   */ // }}}
  event& operator=(event const& rhs)
  { this->assign(rhs); return *this; }
  /** // doc: operator== {{{
   * \brief Compare this event with another one
   *
   * \param rhs
   *    Another event object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->id() == rhs.id()</tt>
   */ // }}}
  bool operator == (event const& rhs) const noexcept
  { return this->id() == rhs.id(); }
  /** // doc: operator!= {{{
   * \brief Compare this event with another one
   *
   * \param rhs
   *    Another event object to be compared to \c this object.
   *
   * \returns <tt>this->id() != rhs.id()</tt>
   */ // }}}
  bool operator != (event const& rhs) const noexcept
  { return this->id() != rhs.id(); }
  /** // doc: operator< {{{
   * \brief Compare this event with another one
   *
   * \param rhs
   *    Another event object to be compared to \c this object.
   *
   * \return <tt>this->id() < rhs.id())</tt>
   */ // }}}
  bool operator < (event const& rhs) const noexcept
  { return this->id() < rhs.id(); }
  /** // doc: operator> {{{
   * \brief Compare this event with another one
   *
   * \param rhs
   *    Another event object to be compared to \c this object.
   *
   * \return <tt>this->id() > rhs.id()</tt>
   */ // }}}
  bool operator > (event const& rhs) const noexcept
  { return this->id() > rhs.id(); }
  /** // doc: operator<= {{{
   * \brief Compare this event with another one
   *
   * \param rhs
   *    Another event object to be compared to \c this object.
   *
   * \return <tt>this->id() <= rhs.id()</tt>
   */ // }}}
  bool operator <= (event const& rhs) const noexcept
  { return this->id() <= rhs.id(); }
  /** // doc: operator>= {{{
   * \brief Compare this event with another one
   *
   * \param rhs
   *    Another event object to be compared to \c this object.
   *
   * \return <tt>this->id() >= rhs.id()</tt>
   */ // }}}
  bool operator >= (event const& rhs) const noexcept
  { return this->id() >= rhs.id(); }
  /** // doc: is_initialized() {{{
   * \brief Is this object properly initialized?
   *
   * \return Returns \c true if \c this object is initialized or \c false
   *         otherwise.
   */ // }}}
  bool is_initialized() const noexcept
  { return this->_id != NULL; }
  /** // doc: get_info(...) {{{
   * \brief Get certain event information from OpenCL
   *
   * This function calls internally \ref clxx::get_event_info() "get_event_info()".
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   *     See documentation of \ref event_info_t for possible values.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \e value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \ref clxx::get_event_info() "get_event_info()").
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
   * It also throws exceptions originating from \ref get_event_info().
   */ // }}}
  void get_info(event_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
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
  /** // doc: get_reference_count() {{{
   * \brief Get reference count for the event
   *
   * \returns reference count for the event.
   *
   * \throws uninitialized_event_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_event_info().
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_profiling_command_queued() {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong get_profiling_command_queued() const;
  /** // doc: get_profiling_command_submit() {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong get_profiling_command_submit() const;
  /** // doc: get_profiling_command_start() {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong get_profiling_command_start() const;
  /** // doc: get_profiling_command_end() {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong get_profiling_command_end() const;
#if CLXX_CL_H_VERSION_2_0
  /** // doc: get_profiling_command_complete() {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong get_profiling_command_complete() const;
#endif
  /** // doc: assign() {{{
   * \brief Assignment
   *
   * This operation copies the \c cl_event handle held by \e rhs to \c this
   * object and maintains reference count appropriately. The reference count
   * for handle originating from \e rhs gets increased by one, as it acquires
   * new user (\c this object). The reference count for handle held up to now
   * by \c this object is decreased by one, as it is forgotten by one user
   * (namely, by \c this object).
   *
   * \throws uninitialized_event_error
   *    when \e rhs is an uninitialized event object.
   * \throws clerror_no<status_t::invalid_event>
   *    when \e rhs holds a \c cl_event handle that is invalid.
   * \throws unexpected_clerror
   */ // }}}
  void assign(event const& rhs)
  { this->_set_id(rhs.get_valid_id(), true, true); }
};
} // end namespace clxx
#endif /* CLXX_EVENT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
