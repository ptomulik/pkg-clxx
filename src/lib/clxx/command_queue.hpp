// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/command_queue.hpp

/** // doc: clxx/command_queue.hpp {{{
 * \file clxx/command_queue.hpp
 * \brief Defines the \ref clxx::command_queue "command_queue" class
 */ // }}}
#ifndef CLXX_COMMAND_QUEUE_HPP_INCLUDED
#define CLXX_COMMAND_QUEUE_HPP_INCLUDED

#include <clxx/context.hpp>
#include <clxx/device.hpp>
#include <clxx/types.hpp>

namespace clxx {
/** // doc: command_queue {{{
 * \ingroup clxx_command_queues
 * \brief Proxy to OpenCL command_queue.
 *
 * This class represents OpenCL command_queue and forwards basic operations on
 * command_queues to OpenCL platform layer. It encapsulates a \c cl_command_queue handle
 * and supports following operations:
 *
 * - command_queue creation (constructors), by calling internally
 *   \ref create_command_queue() and \ref create_command_queue_with_properties(),
 * - automatic reference count management by using internally
 *   \ref retain_command_queue() and \ref release_command_queue(),
 * - retrieving command_queue information from OpenCL (via class methods),
 *   by invoking internally \ref get_command_queue_info().
 *
 * Although \ref command_queue maintains internally reference count for its
 * \c cl_command_queue handle, it doesn't prevent one from stealing the
 * \c cl_command_queue handle (id(), get_valid_id()). This gives rise to manipulate
 * the reference count outside of object. If you need to steal, use the
 * retrieved handle with care. If you retrieve the handle from \ref command_queue
 * object, increase its reference count with \ref retain_command_queue() as soon as
 * possible, and decrease the reference count with \ref release_command_queue() once
 * you don't need the handle. If you don't retain the command_queue, it may be
 * unexpectedly released by \ref command_queue's destructor.
 *
 * There are constructors which create new OpenCL command_queue (a costly operation).
 * However, assignment operator and copy constructors just copy over the
 * \c cl_command_queue handle and maintain reference count appropriately. To verify
 * if two command_queue objects refer to the same OpenCL command_queue use \c == operator
 * (or \c != operator).
 *
 * An OpenCL command_queue (identified by \c cl_command_queue handle) is not released until
 * there is at least one command_queue object encapsulating its handle. On the other
 * hand - the command_queue may get released by OpenCL when last \ref command_queue object
 * gets deleted (the ~command_queue() destructor decreases reference count for its
 * \c cl_command_queue handle with \ref release_command_queue()).
 */ // }}}
class command_queue
{
private:
  cl_command_queue  _id;
  command_queue();
protected:
  /** // doc: _sdoc: _set_id() {{{
   * \brief Set new \c cl_command_queue handle to this object
   *
   * \param id
   *    A \c cl_command_queue handle to OpenCL command_queue. It must be a valid handle if
   *    \e retain_new is true.
   * \param retain_new
   *    If \c true, the reference count for \e id gets increased,
   * \param release_old
   *    If \c true, the reference count for old identifier encapsulated to this
   *    end by the object gets decreased,
   *
   * \throw clerror_no<status_t::invalid_command_queue>
   *    when the \e retain_new is true and \e id is not a valid \c cl_command_queue
   *    handle or when \e release_old is \c true and \c this object holds an
   *    invalid \c cl_command_queue handle.
   * \throw unexpected_clerror
   */ // }}}
  void _set_id(cl_command_queue id, bool retain_new, bool release_old);
public:
  /** // doc: command_queue(cl_command_queue) {{{
   * \brief Constructor
   *
   * Initializes new \ref command_queue object with OpenCL command_queue handle.
   *
   * \param id OpenCL command_queue handle
   *
   * It may throw exceptions described in \ref retain_command_queue().
   */ // }}}
  explicit command_queue(cl_command_queue id);
  /** // doc: command_queue(context, device, properties) {{{
   * \brief Constructor - create new OpenCL command-queue (costly).
   *
   * This constructor calls \ref create_command_queue() to create new OpenCL
   * command-queue and stores the returned \c cl_command_queue handle to the
   * newly created command-queue object. It does not increment the reference
   * count internally, as it obtains from OpenCL a new command-queue with
   * reference count set to 1.
   *
   * \param ctx
   *    An initialized context object.
   * \param dev
   *    An initialized device object. It must be device associated with \e ctx.
   * \param props
   *    Specifies a list of properties for the command-queue.
   *
   * \throw uninitialized_context_error
   * \throw uninitialized device_error
   *
   * It also propagates exceptions thrown by \ref create_command_queue().
   */ // }}}
  command_queue(context const& ctx, device const& dev,
                command_queue_properties_t props);
  /** // doc: command_queue(rhs) {{{
   * \brief Copy constructor (reference copy).
   *
   * This constructor creates command_queue object referring to the same OpenCL
   * command_queue as \e rhs does. After that, the newly created (this) object
   * and the \e rhs hold \c cl_command_queue handle to the same OpenCL
   * command-queue. The reference count for this handle is increased by one
   * during copy-construction by performing an internal call to
   * \ref retain_command_queue().
   *
   * \param rhs
   *    Another command_queue object to be assigned to this object.
   *
   * \throw uninitialized_command_queue_error
   *    thrown when \e rhs is uninitialized.
   * \throw clerror_no<status_t::invalid_command_queue>
   *    propagated from retain_command_queue()
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_command_queue()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_command_queue()
   * \throw unexpected_clerror
   *    propagated from retain_command_queue()
   */ // }}}
  command_queue(command_queue const& rhs);
  /** // doc: ~command_queue() {{{
   * \brief Destructor
   *
   * Internally decreases reference count for this command_queue.
   */ // }}}
  virtual ~command_queue();
  /** // doc: id() {{{
   * \brief   Get \c cl_command_queue handle held by \c this object.
   *
   * \return  The \c cl_command_queue handle held by \c this object.
   */ // }}}
  cl_command_queue id() const noexcept
  { return this->_id; }
  /** // doc: get_valid_id() {{{
   * \brief   Check if \c this object is initialized and return \c cl_command_queue
   *          handle held by this object.
   *
   * \return  The \c cl_command_queue handle to OpenCL command_queue encapsulated within
   *          this object.
   *
   * \throw uninitialized_command_queue_error when the object was not properly
   *        initialized (see is_initialized()).
   */ // }}}
  cl_command_queue get_valid_id() const;
  /** // doc: operator= {{{
   * \brief Assignment operator
   *
   * \param rhs Another command_queue object to be assigned to this object
   *
   *  This operation copies the \c cl_command_queue handle held by \e rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throw uninitialized_command_queue_error
   *    when the \e rhs object is in uninitialized state
   * \throw clerror_no<status_t::invalid_command_queue>
   *    propagated from retain_command_queue() and release_command_queue()
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_command_queue() and release_command_queue()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_command_queue() and release_command_queue()
   * \throw unexpected_clerror
   *    propagated from retain_command_queue() and release_command_queue()
   */ // }}}
  command_queue& operator=(command_queue const& rhs)
  { this->assign(rhs); return *this; }
  /** // doc: operator== {{{
   * \brief Compare this command_queue with another one
   *
   * \param rhs
   *    Another command_queue object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->id() == rhs.id()</tt>
   */ // }}}
  bool operator == (command_queue const& rhs) const noexcept
  { return this->id() == rhs.id(); }
  /** // doc: operator!= {{{
   * \brief Compare this command_queue with another one
   *
   * \param rhs
   *    Another command_queue object to be compared to \c this object.
   *
   * \returns <tt>this->id() != rhs.id()</tt>
   */ // }}}
  bool operator != (command_queue const& rhs) const noexcept
  { return this->id() != rhs.id(); }
  /** // doc: operator< {{{
   * \brief Compare this command_queue with another one
   *
   * \param rhs
   *    Another command_queue object to be compared to \c this object.
   *
   * \return <tt>this->id() < rhs.id())</tt>
   */ // }}}
  bool operator < (command_queue const& rhs) const noexcept
  { return this->id() < rhs.id(); }
  /** // doc: operator> {{{
   * \brief Compare this command_queue with another one
   *
   * \param rhs
   *    Another command_queue object to be compared to \c this object.
   *
   * \return <tt>this->id() > rhs.id()</tt>
   */ // }}}
  bool operator > (command_queue const& rhs) const noexcept
  { return this->id() > rhs.id(); }
  /** // doc: operator<= {{{
   * \brief Compare this command_queue with another one
   *
   * \param rhs
   *    Another command_queue object to be compared to \c this object.
   *
   * \return <tt>this->id() <= rhs.id()</tt>
   */ // }}}
  bool operator <= (command_queue const& rhs) const noexcept
  { return this->id() <= rhs.id(); }
  /** // doc: operator>= {{{
   * \brief Compare this command_queue with another one
   *
   * \param rhs
   *    Another command_queue object to be compared to \c this object.
   *
   * \return <tt>this->id() >= rhs.id()</tt>
   */ // }}}
  bool operator >= (command_queue const& rhs) const noexcept
  { return this->id() >= rhs.id(); }
  /** // {{{
   * \brief Assignment
   *
   *  This operation copies the \c cl_command_queue handle held by \e rhs
   *  to \c this object and maintains reference count appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  handle held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \throw uninitialized_command_queue_error
   *    when \e rhs is an uninitialized command_queue object.
   * \throw clerror_no<status_t::invalid_command_queue>
   *    when \e rhs holds a \c cl_command_queue handle that is invalid.
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_command_queue() and release_command_queue()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_command_queue() and release_command_queue()
   * \throw unexpected_clerror
   *    propagated from retain_command_queue() and release_command_queue()
   */ // }}}
  void assign(command_queue const& rhs);
  /** // {{{
   * \brief   Is this object properly initialized?
   *
   * \return  Returns \c true if \c this object is initialized or \c false
   *          otherwise.
   */ // }}}
  bool is_initialized() const noexcept
  { return (this->_id != NULL); }
  /** // doc: get_info() {{{
   * \brief Get certain command_queue information from OpenCL platform layer.
   *
   * This function calls internally \c get_command_queue_info().
   *
   * \param name
   *     An enumeration constant that specifies the information to query,
   *     for example \ref command_queue_info_t::reference_count. The complete
   *     list of allowed parameter names may be found in
   *     \ref command_queue_info_t.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \c value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \ref get_command_queue_info()).
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \e value is \c NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \e value. If
   *    \e value_size_ret is \c NULL, it is ignored.
   *
   * In case of errors, this function throws one of the exceptions defined by
   * \ref get_command_queue_info().
   */ // }}}
  void get_info(command_queue_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
  /** // doc: get_context() {{{
   * \brief Get the context associated with command-queue.
   *
   * \return A clxx::context object associated with this command-queue.
   *
   * The returned result contains context as returned by the call
   * get_command_queue_info(this->_id, command_queue_info_t::context, ...).
   *
   * In case of errors, this method throws one of the exceptions defined by
   * \ref get_command_queue_info().
   */ // }}}
  context get_context() const;
  /** // doc: get_device() {{{
   * \brief Get the device associated with command-queue.
   *
   * \return A clxx::device object associated with this command-queue.
   *
   * The returned result contains device as returned by the call
   * get_command_queue_info(this->_id, command_queue_info_t::device, ...).
   *
   * In case of errors, this method throws one of the exceptions defined by
   * \ref get_command_queue_info().
   */ // }}}
  device get_device() const;
  /** // doc: get_reference_count() {{{
   * \brief   Get reference count for the OpenCL command_queue referred to by
   *          \c this object.
   *
   * \return  The reference count for the OpenCL command_queue referred to by
   *          \c this object as returned by
   *          get_command_queue_info(this->_id, command_queue_info_t::reference_count, ...)
   *
   * In case of errors, the method throws one of the exceptions defined
   * by \ref get_command_queue_info().
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_properties() {{{
   * \brief Get command-queue properties specified at command-queue creation.
   *
   * \return Properties of this OpenCL command-queue.
   *
   * In case of errors, this method throws one of the exceptions defined by
   * \ref get_command_queue_info().
   */ // }}}
  command_queue_properties_t get_properties() const;
};
} // end namespace clxx

#endif /* CLXX_COMMAND_QUEUE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
