// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/mem.hpp

/** // doc: clxx/mem.hpp {{{
 * \file clxx/mem.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_MEM_HPP_INCLUDED
#define CLXX_MEM_HPP_INCLUDED

#include <clxx/mem_fwd.hpp>
#include <clxx/context_fwd.hpp>
#include <clxx/types.hpp>
#include <clxx/cl/cl.h>

namespace clxx {
/** // doc: mem {{{
 * \ingroup clxx_buffer_objects
 * \brief Encapsulates an OpenCL memory object
 *
 * This class represents OpenCL memory object (e.g. buffer or image) and
 * forwards basic operations on memory objects to OpenCL. It encapsulates a
 * \c cl_mem identifier and supports following operations:
 *
 * - memory object creation (constructors),
 * - automatic reference count management by using internally
 *   \ref retain_mem_object() and \ref release_mem_object(),
 * - retrieving mem information from OpenCL (via class methods), by
 *   invoking internally \ref get_mem_object_info() and \ref get_image_info().
 *
 * Although \ref clxx::mem "mem" maintains internally reference count
 * for its \c cl_mem handle, it doesn't prevent one from stealing the
 * \c cl_mem handle (#id(), #get_valid_id()). This gives rise to manipulate the
 * reference count outside of the \ref clxx::mem object for the given OpenCL
 * memory object. If you need to steal, use the retrieved handle with care. If
 * you retrieve the handle from \ref clxx::mem "mem" object, increase its
 * reference count with \ref clxx::retain_mem_object() "retain_mem_object()"
 * as soon as possible, and decrease the reference count with
 * \ref clxx::release_mem_object() "release_mem_object()" once you don't need
 * the handle. If you don't retain the mem, it may be unexpectedly released by
 * \ref clxx::mem "mem's"  destructor, assignment operator or the #assign()
 * method.
 *
 * There are constructors which create new OpenCL memory object (a costly
 * operation). However, assignment operator and copy constructors just copy
 * over the \c cl_mem handle and maintain reference count appropriately. To
 * verify if two \ref clxx::mem "mem" objects refer to the same OpenCL
 * mem, use \c == operator (of \c != operator).
 *
 * An OpenCL memory object (identified by \c cl_mem handle) is not released
 * until there is at least one \ref clxx::mem "mem" object
 * encapsulating its handle. On the other hand - the mem may get released
 * by OpenCL when last \ref clxx::mem "mem" object gets deleted (the
 * ~mem() destructor decreases reference count for its \c cl_mem
 * handle with \ref clxx::release_mem_object() "release_mem_object()") or when
 * the last object gets assigned another OpenCL memory object (assignment
 * operator or the #assign() method).
 */ // }}}
class alignas(cl_mem) mem
{
private:
  cl_mem _id;
protected:
  /** // doc: _set_id(cl_mem, bool, bool) {{{
   * \brief Set the \c cl_mem handle to this object
   *
   * \param prog the \c cl_mem handle (OpenCL mem),
   * \param retain_new whether to invoke \ref retain_mem_object() on *prog*,
   * \param release_old whether to invoke \ref release_mem_object() on the handle
   *        held up to this moment by this object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_mem_object().
   */ // }}}
  void _set_id(cl_mem prog, bool retain_new, bool release_old);
public:
  /** // doc: mem() {{{
   * \brief Default constructor
   *
   * Sets the internal \c cl_mem handle to \c NULL. A default-constructed
   * \ref clxx::mem "mem" object is considered to be uninitialized (see
   * #is_initialized()).
   */ // }}}
  mem() noexcept;
  /** // doc: mem(cl_mem) {{{
   * \brief Creates \ref clxx::mem "mem" object from explicitly given
   *        OpenCL \c cl_mem handle.
   *
   * The constructor internally retains the provided OpenCL mem identified
   * by *id* (\ref clxx::retain_mem_object()).
   *
   * \param id handle (identifier) to an OpenCL mem that has to be
   *           encapsulated by the newly created \ref clxx::mem "mem"
   *           object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_mem_object().
   */ // }}}
  explicit mem(cl_mem id);
  /** // doc: mem(context const&, mem_flags_t, size_t, void*) {{{
   * \todo Write documentation
   */ // }}}
  explicit mem(context const& ctx, mem_flags_t flags, size_t size, void* host_ptr);
  /** // doc: mem(mem const&) {{{
   * \brief Copy constructor
   *
   * The constructor internally retains the provided OpenCL mem identified
   * by *id* (\ref clxx::retain_mem_object()).
   *
   * \param e a \ref clxx::mem "mem" object to be copied.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_mem_object().
   */ // }}}
  mem(mem const& e);
  /** // doc: ~mem() {{{
   * \brief Destructor
   *
   * If the mem was initialized properly, then it internally releases the
   * mem by \ref release_mem_object().
   */ // }}}
  ~mem();
  /** // doc: id() {{{
   * \brief Get the \c cl_mem handle held by this object
   *
   * \returns the OpenCL mem handle of type \c cl_mem held by this
   *          object
   */ // }}}
  cl_mem id() const noexcept
  { return this->_id; }
  /** // doc: get_valid_id() {{{
   * \brief Check if \c this object is initialized and return \c cl_mem
   *        handle held by this object.
   *
   * \returns The \c cl_mem handle to OpenCL mem encapsulated within
   *          this object.
   *
   * \throws uninitialized_mem_error when the object was not properly
   *        initialized (see is_initialized()).
   */ // }}}
  cl_mem get_valid_id() const;
  /** // doc: operator= {{{
   * \brief Assignment operator
   *
   * \param rhs Another mem object to be assigned to this object
   *
   *  This operation copies the \c cl_mem handle held by \e rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throws uninitialized_mem_error
   *    when the \e rhs object is in uninitialized state
   * \throws clerror_no<status_t::invalid_mem>
   *    when the \e rhs holds invalid \c cl_mem handle
   * \throws unexpected_clerror
   */ // }}}
  mem& operator=(mem const& rhs)
  { this->assign(rhs); return *this; }
  /** // doc: operator== {{{
   * \brief Compare this mem with another one
   *
   * \param rhs
   *    Another mem object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->id() == rhs.id()</tt>
   */ // }}}
  bool operator == (mem const& rhs) const noexcept
  { return this->id() == rhs.id(); }
  /** // doc: operator!= {{{
   * \brief Compare this mem with another one
   *
   * \param rhs
   *    Another mem object to be compared to \c this object.
   *
   * \returns <tt>this->id() != rhs.id()</tt>
   */ // }}}
  bool operator != (mem const& rhs) const noexcept
  { return this->id() != rhs.id(); }
  /** // doc: operator< {{{
   * \brief Compare this mem with another one
   *
   * \param rhs
   *    Another mem object to be compared to \c this object.
   *
   * \return <tt>this->id() < rhs.id())</tt>
   */ // }}}
  bool operator < (mem const& rhs) const noexcept
  { return this->id() < rhs.id(); }
  /** // doc: operator> {{{
   * \brief Compare this mem with another one
   *
   * \param rhs
   *    Another mem object to be compared to \c this object.
   *
   * \return <tt>this->id() > rhs.id()</tt>
   */ // }}}
  bool operator > (mem const& rhs) const noexcept
  { return this->id() > rhs.id(); }
  /** // doc: operator<= {{{
   * \brief Compare this mem with another one
   *
   * \param rhs
   *    Another mem object to be compared to \c this object.
   *
   * \return <tt>this->id() <= rhs.id()</tt>
   */ // }}}
  bool operator <= (mem const& rhs) const noexcept
  { return this->id() <= rhs.id(); }
  /** // doc: operator>= {{{
   * \brief Compare this mem with another one
   *
   * \param rhs
   *    Another mem object to be compared to \c this object.
   *
   * \return <tt>this->id() >= rhs.id()</tt>
   */ // }}}
  bool operator >= (mem const& rhs) const noexcept
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
   * \brief Get certain mem information from OpenCL
   *
   * This function calls internally \ref clxx::get_mem_object_info() "get_mem_object_info()".
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   *     See documentation of \ref mem_info_t for possible values.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \e value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \ref clxx::get_mem_object_info() "get_mem_object_info()").
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \e value is \c NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \e value. If
   *    \e value_size_ret is \c NULL, it is ignored.
   *
   * \throws uninitialized_mem_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_mem_object_info().
   */ // }}}
  void get_info(mem_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
  /** // doc: get_type() {{{
   * \todo Write documentation
   */ // }}}
  mem_object_type_t get_type() const;
  /** // doc: get_flags() {{{
   * \todo Write documentation
   */ // }}}
  mem_flags_t get_flags() const;
  /** // doc: get_size() {{{
   * \todo Write documentation
   */ // }}}
  size_t get_size() const;
  /** // doc: get_host_ptr() {{{
   * \todo Write documentation
   */ // }}}
  void* get_host_ptr() const;
  /** // doc: get_map_count() {{{
   * \todo Write documentation
   */ // }}}
  cl_uint get_map_count() const;
  /** // doc: get_reference_count() {{{
   * \brief Get reference count for the memory object
   *
   * \returns reference count for the memory object.
   *
   * \throws uninitialized_mem_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_mem_object_info().
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_context() {{{
   * \todo Write documentation
   */ // }}}
  context get_context() const;
#if CLXX_CL_H_VERSION_1_1
  /** // doc: get_associated_memobject() {{{
   * \todo Write documentation
   */ // }}}
  mem get_associated_memobject() const;
  /** // doc: get_offset() {{{
   * \todo Write documentation
   */ // }}}
  size_t get_offset() const;
#endif
#if CLXX_CL_H_VERSION_2_0
  /** // doc: get_uses_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  cl_bool get_uses_svm_pointer() const;
#endif
  /** // doc: assign() {{{
   * \brief Assignment
   *
   * This operation copies the \c cl_mem handle held by \e rhs to \c this
   * object and maintains reference count appropriately. The reference count
   * for handle originating from \e rhs gets increased by one, as it acquires
   * new user (\c this object). The reference count for handle held up to now
   * by \c this object is decreased by one, as it is forgotten by one user
   * (namely, by \c this object).
   *
   * \throws uninitialized_mem_error
   *    when \e rhs is an uninitialized mem object.
   * \throws clerror_no<status_t::invalid_mem>
   *    when \e rhs holds a \c cl_mem handle that is invalid.
   * \throws unexpected_clerror
   */ // }}}
  void assign(mem const& rhs)
  { this->_set_id(rhs.get_valid_id(), true, true); }
};
} // end namespace clxx

#endif /* CLXX_MEM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
