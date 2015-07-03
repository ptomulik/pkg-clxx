// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/command_queue.hpp

/** // doc: clxx/command_queue.hpp {{{
 * \file clxx/command_queue.hpp
 * \brief Defines the \ref clxx::command_queue "command_queue" class
 */ // }}}
#ifndef CLXX_COMMAND_QUEUE_HPP_INCLUDED
#define CLXX_COMMAND_QUEUE_HPP_INCLUDED

#include <clxx/command_queue_fwd.hpp>
#include <clxx/context_fwd.hpp>
#include <clxx/device_fwd.hpp>
#include <clxx/clobj.hpp>

namespace clxx {
/** // doc: command_queue {{{
 * \ingroup clxx_command_queues
 * \brief OpenCL Command Queue.
 *
 * Represents OpenCL Command Queue and forwards basic operations on a Command
 * Queue to OpenCL API.
 *
 * The \ref command_queue encapsulates a \c cl_command_queue handle and
 * supports the following operations (in addition to operations supported
 * by \ref clxx::clobj "clobj<cl_command_queue>":
 *
 * - command_queue creation (constructors), by calling internally
 *   \ref create_command_queue() and \ref create_command_queue_with_properties(),
 * - retrieving command_queue properties from OpenCL (\ref get_properties()).
 *
 * Although \ref command_queue maintains internally reference count for its
 * \c cl_command_queue handle, it doesn't prevent one from stealing the
 * \c cl_command_queue handle (get(), chk_get()). This gives rise
 * to manipulate the reference count outside of object. If you need to steal
 * the handle, use the retrieved handle with care. If you retrieve the handle
 * from \ref command_queue object, increase its reference count with
 * \ref retain_command_queue() as soon as possible, and decrease the reference
 * count with \ref release_command_queue() once you don't need the handle. If
 * you don't retain the command_queue, it may be unexpectedly released by
 * \ref command_queue's destructor.
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
class alignas(cl_command_queue) command_queue
  : public clobj<cl_command_queue>
{
public:
  /** // doc: Base {{{
   * \brief Typedef for the base class type
   */ // }}}
  typedef clobj<cl_command_queue> Base;
  using Base::Base;
  /** // doc: command_queue() {{{
   * \brief Default constructor, see \ref clobj::clobj()
   */ // }}}
  command_queue() = default;
  /** // doc: command_queue() {{{
   * \brief Copy constructor, see \ref clobj::clobj(clobj const&)
   */ // }}}
  command_queue(command_queue const&) = default;
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
  /** // doc: get_properties() {{{
   * \brief Get command-queue properties specified at command-queue creation.
   *
   * \return Properties of this OpenCL command-queue.
   *
   * In case of errors, this method throws one of the exceptions defined by
   * \ref get_command_queue_info().
   */ // }}}
  command_queue_properties_t get_properties() const;
  /** // doc: flush() {{{
   * \brief Issues all previously queued OpenCL commands in the command_queue
   *        to the device associated with the command_queue
   *
   * \throw uninitialized_command_queue_error
   *    when the command_queue object is uninitialized (see #is_initialized())
   *
   *  Also may throw exceptions originating from \ref clxx::flush() "flush()"
   */ // }}}
  void flush() const;
  /** // doc: finish() {{{
   * \brief Blocks until all previously queued OpenCL commands in the
   *        command_queue are issued to the associated device and have completed
   *
   * \throw uninitialized_command_queue_error
   *    when the command_queue object is uninitialized (see #is_initialized())
   *
   *  Also may throw exceptions originating from \ref clxx::finish() "finish()"
   */ // }}}
  void finish() const;
};
} // end namespace clxx

#endif /* CLXX_COMMAND_QUEUE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
