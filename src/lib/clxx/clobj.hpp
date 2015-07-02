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
/** // doc: clobj_info_type {{{
 * \brief Return the info name type for a particular OpenCL object
 *
 * This meta-function is used by \ref clxx::clobj "clobj" to determine the type
 * of the first argument to \ref clxx::clobj::get_info() "clobj::get_info()".
 */ // }}}
template< typename Handle >
  struct clobj_info_type;
/** // doc: invalid_clobj_error {{{
 * \brief Return the numeric value that represents invalid info name error
 *
 * The returned value is #status_t::invalid_command_queue for
 * \c cl_command_queue, #status_t::invalid_context for \c cl_context etc.
 *
 * The meta-function is used by \ref clxx::clobj "clobj's" destructor. It is
 * also referred to by documentation.
 */ // }}}
template< typename Handle >
  struct invalid_clobj_error;
/** // doc: uninitialized_clobj_error {{{
 * \brief Return the exception type for uninitialized \ref clxx::clobj "clobj"
 *
 * The returned type is \ref clxx::uninitialized_command_queue_error
 * "clxx::uninitialized_command_queue_error" for \c cl_command_queue,
 * \ref clxx::uninitialized_context_error "uninitialized_context_error" for
 * \c cl_context, and so forth.
 *
 * This is used by several methods of the \ref clxx::clobj "clobj" and is
 * referred to by documentation.
 */ // }}}
template< typename Handle >
  struct uninitialized_clobj_error;

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template< >
  struct clobj_info_type<cl_command_queue>
  { typedef command_queue_info_t type; };
template< >
  struct clobj_info_type<cl_context>
  { typedef context_info_t type; };
template< >
  struct clobj_info_type<cl_device_id>
  { typedef device_info_t type; };
template< >
  struct clobj_info_type<cl_event>
  { typedef event_info_t type; };
template< >
  struct clobj_info_type<cl_kernel>
  { typedef kernel_info_t type; };
template< >
  struct clobj_info_type<cl_mem>
  { typedef mem_info_t type; };
template< >
  struct clobj_info_type<cl_platform_id>
  { typedef platform_info_t type; };
template< >
  struct clobj_info_type<cl_program>
  { typedef program_info_t type; };
template< >
  struct clobj_info_type<cl_sampler>
  { typedef sampler_info_t type; };

template< >
  struct invalid_clobj_error<cl_command_queue>
  { static constexpr status_t value = status_t::invalid_command_queue; };
template< >
  struct invalid_clobj_error<cl_context>
  { static constexpr status_t value = status_t::invalid_context; };
template< >
  struct invalid_clobj_error<cl_device_id>
  { static constexpr status_t value = status_t::invalid_device; };
template< >
  struct invalid_clobj_error<cl_event>
  { static constexpr status_t value = status_t::invalid_event; };
template< >
  struct invalid_clobj_error<cl_kernel>
  { static constexpr status_t value = status_t::invalid_kernel; };
template< >
  struct invalid_clobj_error<cl_mem>
  { static constexpr status_t value = status_t::invalid_mem_object; };
template< >
  struct invalid_clobj_error<cl_platform_id>
  { static constexpr status_t value = status_t::invalid_platform; };
template< >
  struct invalid_clobj_error<cl_program>
  { static constexpr status_t value = status_t::invalid_program; };
template< >
  struct invalid_clobj_error<cl_sampler>
  { static constexpr status_t value = status_t::invalid_sampler; };

template<>
  struct uninitialized_clobj_error<cl_command_queue>
  { typedef uninitialized_command_queue_error type; };
template<>
  struct uninitialized_clobj_error<cl_context>
  { typedef uninitialized_context_error type; };
template<>
  struct uninitialized_clobj_error<cl_device_id>
  { typedef uninitialized_device_error type; };
template<>
  struct uninitialized_clobj_error<cl_event>
  { typedef uninitialized_event_error type; };
template<>
  struct uninitialized_clobj_error<cl_kernel>
  { typedef uninitialized_kernel_error type; };
template<>
  struct uninitialized_clobj_error<cl_mem>
  { typedef uninitialized_mem_error type; };
template<>
  struct uninitialized_clobj_error<cl_platform_id>
  { typedef uninitialized_platform_error type; };
template<>
  struct uninitialized_clobj_error<cl_program>
  { typedef uninitialized_program_error type; };
#if 0
template<>
  struct uninitialized_clobj_error<cl_sampler>
  { typedef uninitialized_sampler_error type; };
#endif
/** \endcond */
} // end namespace clxx

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
 * That way it reduces a boilerplate that would otherwise go to the particular
 * clxx classes.
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
  typedef typename clobj_info_type<Handle>::type info_t;
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
   * \throw clerror_no<invalid_clobj_error<handle_t>::value>
   *    when the \p retain_new is true and \p handle is not a valid OpenCL
   *    object handle or when \p release_old is \c true and \c this object
   *    holds an invalid handle.
   * \throw unexpected_clerror
   *
   * Also may throw other exceptions originating from the corresponding
   * overload of the \ref clxx::retain_clobj() "retain_clobj()" function.
   */ // }}}
  void _set_handle(handle_t handle, bool retain_new, bool release_old);
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
   * \throw clerror_no<invalid_clobj_error<handle_t>::value>
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
   * internal call to #retain_clobj().
   *
   * \param other
   *    Another #clobj object to be assigned to this object.
   *
   * \throw uninitialized_clobj_error<handle_t>::type
   *    thrown when \p other is uninitialized (see #is_initialized()).
   * \throw clerror_no<invalid_clobj_error<handle_t>::value>
   *    thrown when \p other holds an invalid (but not-null) handle.
   * \throw unexpected_clerror
   *
   * Also may throw other exceptions originating from the corresponding
   * overload of the \ref clxx::retain_clobj() "retain_clobj()" function.
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
  /** // doc: handle() {{{
   * \brief Get the OpenCL object handle held by \c this object.
   * \return The OpenCL object handle held by \c this object.
   */ // }}}
  handle_t handle() const noexcept;
  /** // doc: get_valid_handle() {{{
   * \brief Check if \c this object is initialized and return the OpenCL
   *        object handle held by \c this object.
   *
   * \return  The OpenCL object handle encapsulated within \c this object.
   *
   * \throw uninitialized_clobj_error<handle_t>::type
   *    when the object was not properly initialized (see #is_initialized()).
   */ // }}}
  handle_t get_valid_handle() const;
  /** // doc: get_info() {{{
   * \brief Get certain information from OpenCL platform layer.
   *
   * This function calls internally \c get_clobj_info().
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
   * \par Exceptions
   *
   * In case of errors, this function throws one of the exceptions defined by
   * corresponding overload of the #get_clobj_info() function.
   */ // }}}
  void get_info(info_t name, size_t value_size, void* value, size_t* value_size_ret) const;
  /** // doc: get_reference_count() {{{
   * \brief Get reference count for the OpenCL object referred to by \c this
   *        object.
   *
   * \return The reference count for the OpenCL object referred to by \c this
   *         object.
   *
   * \par Exceptions
   *
   * In case of errors, the method throws one of the exceptions defined
   * by corresponding overload of the #get_clobj_info() function.
   */ // }}}
  cl_uint get_reference_count() const;
  /** // {{{
   * \brief Assignment
   *
   *  This operation copies the \c handle_t handle held by \e rhs
   *  to \c this object and maintains reference count appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  handle held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \throw uninitialized_clobj_error<handle_t>::type
   *    when \e rhs is an uninitialized clobj object.
   * \throw clerror_no<status_t::invalid_clobj>
   *    when \e rhs holds a \c handle_t handle that is invalid.
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_clobj() and release_clobj()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_clobj() and release_clobj()
   * \throw unexpected_clerror
   *    propagated from retain_clobj() and release_clobj()
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
   * \throw uninitialized_clobj_error<handle_t>::type
   *    when the \e rhs object is in uninitialized state
   * \throw clerror_no<status_t::invalid_clobj>
   *    propagated from retain_clobj() and release_clobj()
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_clobj() and release_clobj()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_clobj() and release_clobj()
   * \throw unexpected_clerror
   *    propagated from retain_clobj() and release_clobj()
   */ // }}}
  clobj& operator=(clobj const& rhs);
  /** // doc: operator== {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->handle() == rhs.handle()</tt>
   */ // }}}
  bool operator == (clobj const& rhs) const noexcept;
  /** // doc: operator!= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \returns <tt>this->handle() != rhs.handle()</tt>
   */ // }}}
  bool operator != (clobj const& rhs) const noexcept;
  /** // doc: operator< {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() < rhs.handle())</tt>
   */ // }}}
  bool operator < (clobj const& rhs) const noexcept;
  /** // doc: operator> {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() > rhs.handle()</tt>
   */ // }}}
  bool operator > (clobj const& rhs) const noexcept;
  /** // doc: operator<= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() <= rhs.handle()</tt>
   */ // }}}
  bool operator <= (clobj const& rhs) const noexcept;
  /** // doc: operator>= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() >= rhs.handle()</tt>
   */ // }}}
  bool operator >= (clobj const& rhs) const noexcept;
};
} // end namespace clxx

#endif /* CLXX_CLOBJ_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
