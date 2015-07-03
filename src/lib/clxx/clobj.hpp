// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clobj.hpp

/** // doc: clxx/clobj.hpp {{{
 * \file clxx/clobj.hpp
 * \brief Declares the \ref clxx::clobj "clobj" class.
 */ // }}}
#ifndef CLXX_CLOBJ_HPP_INCLUDED
#define CLXX_CLOBJ_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/exceptions.hpp>

namespace clxx {
/** // doc: clobj {{{
 * \brief Represents a generic OpenCL object.
 *
 * A typical OpenCL application maintains several types of OpenCL objects.
 * These objects are normally represented by "handles" such as (in alphabetical
 * order):
 *
 * - \c cl_command_queue (OpenCL command queue),
 * - \c cl_context (OpenCL context),
 * - \c cl_device_id (OpenCL device),
 * - \c cl_event (OpenCL event object),
 * - \c cl_kernel (OpenCL kernel),
 * - \c cl_mem (OpenCL memory object &mdash; buffer or image),
 * - \c cl_platform_id (OpenCL platform),
 * - \c cl_program (OpenCL program).
 * - \c cl_sampler (OpenCL sampler).
 *
 * The above OpenCL objects have some common features, mostly:
 *
 * - they are represented by "handles" (pointers, in fact),
 * - there are API calls that characterize them (\c clGetXyzInfo() calls)
 * - most of them support reference counting (\c clRetainXyz(), \c clReleaseXyz()).
 *
 * The #clobj class encapsulates an OpenCL object handle and provides all
 * these commons, that is:
 *
 * - reference count management,
 * - object info retrieval.
 *
 * That way it reduces a boilerplate that would otherwise go to particular
 * clxx classes such as #clxx::device or #clxx::event.
 *
 * The reference count is maintained automatically. A newly created instance 
 * of #clobj increments a reference count for its underlying handle
 * (retains its OpenCL object). The reference count is decreased when the
 * #clobj object goes out of scope or is deleted. Assignment operator
 * and #assign() method maintain the reference count as well.
 *
 * \tparam Handle
 *    Type of OpenCL "handle". This determines the type of underlying OpenCL
 *    object represented by an instantiation of #clobj template.
 */ // }}}
template< typename Handle >
class alignas(Handle) clobj
{
private:
  Handle _handle;
public:
  /** // doc: handle_t {{{
   * \brief Type of the encapsulated OpenCL object handle, same as \c Handle
   */ // }}}
  typedef Handle handle_t;
  /** // doc: info_t {{{
   * \brief A type used to represent object's info name (the first argument to #get_info())
   */ // }}}
  typedef typename cl_object_info_type<Handle>::type info_t;
protected:
  /** // doc: _set_handle() {{{
   * \brief Encapsulate new OpenCL object 
   *
   * This method assigns the new OpenCL object handle to the #clobj object
   * and maintains reference count (for both, the currently held and the new
   * handle) as requested.
   *
   * \param handle
   *    An OpenCL object handle to be encapsulated. It must be a valid OpenCL
   *    object handle if \p retain_new is \c true. It may be \c NULL if
   *    \p retain_new is \c false.
   * \param retain_new
   *    If \c true, the reference count for \p handle gets increased,
   * \param release_old
   *    If \c true, the reference count for old identifier encapsulated to this
   *    end by the object gets decreased,
   *
   * \throw clerror_no<invalid_cl_object_errcode<handle_t>::value>
   *    when the \p retain_new is true and \p handle is not a valid OpenCL
   *    object handle or when \p release_old is \c true and \c this object
   *    holds an invalid handle.
   * \throw unexpected_clerror
   *
   * Also may throw other exceptions originating from the corresponding
   * overload of the \ref clxx::retain_cl_object() "retain_cl_object()" function.
   */ // }}}
  void _set_handle(handle_t handle, bool retain_new, bool release_old);
  /** // doc: _retain() {{{
   * \brief Increment reference count for the OpenCL object identified by \p handle
   */ // }}}
  static void _retain(handle_t handle);
  /** // doc: _retain() {{{
   * \brief Decrement reference count for the OpenCL object identified by \p handle
   */ // }}}
  static void _release(handle_t handle);
public:
  /** // doc: clobj() {{{
   * \brief Default constructor
   *
   * Sets the internal OpenCL handle to \c NULL. A default-constructed
   * #clobj object is considered to be uninitialized (see #is_initialized()).
   */ // }}}
  clobj() noexcept;
  /** // doc: clobj(handle_t) {{{
   * \brief Constructor
   *
   * Initializes new #clobj object with an OpenCL object handle.
   *
   * \param handle An OpenCL object handle
   *
   * \throw clerror_no<invalid_cl_object_errcode<handle_t>::value>
   *    when the \p handle is not \c NULL but it is not a valid OpenCL
   *    object handle.
   */ // }}}
  explicit clobj(handle_t handle);
  /** // doc: clobj(rhs) {{{
   * \brief Copy constructor (reference copy).
   *
   * This constructor creates #clobj object referring to the same OpenCL
   * object as the \p other #clobj. After that, the newly created (this) object
   * and the \p other hold the same OpenCL handle. The reference count for this
   * handle is increased by one during copy-construction by performing an
   * internal call to #retain_cl_object().
   *
   * \param other
   *    Another #clobj object to be assigned to this object.
   *
   * \throw uninitialized_cl_object_error<handle_t>::type
   *    thrown when \p other is uninitialized (see #is_initialized()).
   * \throw clerror_no<invalid_cl_object_errcode<handle_t>::value>
   *    thrown when \p other holds an invalid (but not-null) handle.
   * \throw unexpected_clerror
   *
   * Also may throw other exceptions originating from the corresponding
   * overload of the \ref clxx::retain_cl_object() "retain_cl_object()" function.
   */ // }}}
  clobj(clobj const& other);
  /** // doc: ~clobj() {{{
   * \brief Destructor
   *
   * Internally decreases reference count for the encapsulated OpenCL object.
   */ // }}}
  ~clobj();
  /** // {{{
   * \brief Is this object properly initialized?
   *
   * The object is considered initialized if and only if the OpenCL handle
   * it encapsulates is not \c NULL.
   *
   * \return Returns \c true if \c this object is initialized or \c false
   *          otherwise.
   */ // }}}
  bool is_initialized() const noexcept;
  /** // doc: get() {{{
   * \brief Get the OpenCL object handle held by \c this object.
   * \return The OpenCL object handle held by \c this object.
   */ // }}}
  handle_t get() const noexcept;
  /** // doc: chk_get() {{{
   * \brief Returns the OpenCL object handle if it's not \c NULL
   *
   * If the OpenCL object handle held by this object is \c NULL, an exception
   * is thrown.
   *
   * \return  The OpenCL object handle encapsulated within \c this object.
   *
   * \throw uninitialized_cl_object_error<handle_t>::type
   *    when the object was not properly initialized (see #is_initialized()).
   */ // }}}
  handle_t chk_get() const;
  /** // doc: get_info() {{{
   * \brief Get certain information from OpenCL platform layer.
   *
   * This function calls internally \c get_cl_object_info().
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \p value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification.
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \p value is NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \p value. If
   *    \p value_size_ret is \c NULL, it is ignored.
   *
   * \throw uninitialized_cl_object_error<handle_t>::type
   *    If the \ref clxx::clobj "clobj" object is uninitialized (see #is_initialized())
   *
   * Also throws exceptions originating from #get_cl_object_info() function.
   */ // }}}
  void get_info(info_t name, size_t value_size, void* value, size_t* value_size_ret) const;
  /** // doc: get_reference_count() {{{
   * \brief Get reference count for the OpenCL object referred to by \c this
   *        object.
   *
   * \return The reference count for the OpenCL object referred to by \c this
   *         object.
   *
   * \throw uninitialized_cl_object_error<handle_t>::type
   *    If the \ref clxx::clobj "clobj" object is uninitialized (see #is_initialized())
   *
   * Also throws exceptions originating from #get_cl_object_info() function.
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: assign() {{{
   * \brief Assignment
   *
   *  This operation copies the \c handle_t handle held by \e rhs
   *  to \c this object and maintains reference count appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  handle held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \throw uninitialized_cl_object_error<handle_t>::type
   *    when \e rhs is an uninitialized clobj object.
   * \throw clerror_no<status_t::invalid_clobj>
   *    when \e rhs holds a \c handle_t handle that is invalid.
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_cl_object() and release_cl_object()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_cl_object() and release_cl_object()
   * \throw unexpected_clerror
   *    propagated from retain_cl_object() and release_cl_object()
   */ // }}}
  void assign(clobj const& rhs);
  /** // doc: operator= {{{
   * \brief Assignment operator
   *
   * \param rhs Another clobj object to be assigned to this object
   *
   *  This operation copies the \c handle_t handle held by \e rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throw uninitialized_cl_object_error<handle_t>::type
   *    when the \e rhs object is in uninitialized state
   * \throw clerror_no<status_t::invalid_clobj>
   *    propagated from retain_cl_object() and release_cl_object()
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_cl_object() and release_cl_object()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_cl_object() and release_cl_object()
   * \throw unexpected_clerror
   *    propagated from retain_cl_object() and release_cl_object()
   */ // }}}
  clobj& operator=(clobj const& rhs);
  /** // doc: operator== {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->get() == rhs.get()</tt>
   */ // }}}
  bool operator == (clobj const& rhs) const noexcept;
  /** // doc: operator!= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \returns <tt>this->get() != rhs.get()</tt>
   */ // }}}
  bool operator != (clobj const& rhs) const noexcept;
  /** // doc: operator< {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->get() < rhs.get())</tt>
   */ // }}}
  bool operator < (clobj const& rhs) const noexcept;
  /** // doc: operator> {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->get() > rhs.get()</tt>
   */ // }}}
  bool operator > (clobj const& rhs) const noexcept;
  /** // doc: operator<= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->get() <= rhs.get()</tt>
   */ // }}}
  bool operator <= (clobj const& rhs) const noexcept;
  /** // doc: operator>= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->get() >= rhs.get()</tt>
   */ // }}}
  bool operator >= (clobj const& rhs) const noexcept;
};
} // end namespace clxx

#endif /* CLXX_CLOBJ_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
