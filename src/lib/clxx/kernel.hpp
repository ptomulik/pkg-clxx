// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/kernel.hpp

/** // doc: clxx/kernel.hpp {{{
 * \file clxx/kernel.hpp
 * \brief Defines the \ref clxx::kernel "kernel" class
 */ // }}}
#ifndef CLXX_KERNEL_HPP_INCLUDED
#define CLXX_KERNEL_HPP_INCLUDED

#include <clxx/kernel_fwd.hpp>
#include <clxx/program_fwd.hpp>
#include <clxx/context_fwd.hpp>
#include <clxx/device.hpp>
#include <clxx/types.hpp>
#include <clxx/config.hpp>
#include <string>

namespace clxx {
/** // doc: kernel {{{
 * \ingroup clxx_kernel_objects
 * \brief Encapsulates an OpenCL kernel object
 *
 * This class represents OpenCL kernel and forwards basic operations on
 * kernels to OpenCL. It encapsulates a \c cl_kernel identifier and
 * supports following operations:
 *
 * - kernel creation (constructors), by calling internally #create_kernel(),
 * - automatic reference count management by using internally
 *   #retain_kernel() and #release_kernel(),
 * - retrieving kernel information from OpenCL (via class methods), by
 *   invoking internally #get_kernel_info().
 * - retrieving kernel argument information from OpenCL (via class methods), by
 *   invoking internally #get_kernel_arg_info().
 * - retrieving kernel work-group information from OpenCL (via class methods),
 *   by invoking internally #get_kernel_work_group_info().
 * - setting kernel arguments by calling internally #set_kernel_arg(), and
 *   #set_kernel_arg_svm_pointer().
 *
 * Although \ref clxx::kernel "kernel" maintains internally reference count
 * for its \c cl_kernel handle, it doesn't prevent one from stealing the \c
 * cl_kernel handle (#id(), #get_valid_id()). This gives rise to
 * manipulate the reference count outside of the \ref clxx::kernel "kernel"
 * object for the given OpenCL kernel object. If you need to steal, use the
 * retrieved handle with care. If you retrieve the handle from
 * \ref clxx::kernel "kernel" object, increase its reference count with
 * \ref clxx::retain_kernel() "retain_kernel()" as soon as possible, and
 * decrease the reference count with \ref clxx::release_kernel() "release_kernel()"
 * once you don't need the handle. If you don't retain the kernel, it may be
 * unexpectedly released by \ref clxx::kernel "kernel's"  destructor,
 * assignment operator or the #assign() method.
 *
 * There is a constructors which create new OpenCL kernel (a costly operation).
 * However, assignment operator and copy constructors just copy over the
 * \c cl_kernel handle and maintain reference count appropriately. To verify
 * if two \ref clxx::kernel "kernel" objects refer to the same OpenCL
 * kernel, use \c == operator (of \c != operator).
 *
 * An OpenCL kernel (identified by \c cl_kernel handle) is not released
 * until there is at least one \ref clxx::kernel "kernel" object
 * encapsulating its handle. On the other hand - the kernel may get released
 * by OpenCL when last \ref clxx::kernel "kernel" object gets deleted (the
 * ~kernel() destructor decreases reference count for its \c cl_kernel
 * handle with \ref clxx::release_kernel() "release_kernel()") or when the last
 * object gets assigned another OpenCL kernel (via assignment operator or the
 * #assign() method).
 */ // }}}
class alignas(cl_kernel) kernel
{
private:
  cl_kernel _id;
protected:
  /** // doc: _set_id(cl_kernel, bool, bool) {{{
   * \brief Set the \c cl_kernel handle to this object
   *
   * \param kern the \c cl_kernel handle (OpenCL kernel),
   * \param retain_new whether to invoke \ref retain_kernel() on *kern*,
   * \param release_old whether to invoke \ref release_kernel() on the handle
   *        held up to this moment by this object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_kernel().
   */ // }}}
  void _set_id(cl_kernel kern, bool retain_new, bool release_old);
public:
  /** // doc: kernel() {{{
   * \brief Default constructor
   *
   * Sets the internal \c cl_kernel handle to NULL. A default-constructed
   * \ref clxx::kernel "kernel" object is considered to be uninitialized (see
   * #is_initialized()).
   */ // }}}
  kernel() noexcept;
  /** // doc: kernel(cl_kernel) {{{
   * \brief Creates \ref clxx::kernel "kernel" object from explicitly given
   *        OpenCL \c cl_kernel handle.
   *
   * The constructor internally retains the provided OpenCL kernel identified
   * by *id* (\ref clxx::retain_kernel()).
   *
   * \param id handle (identifier) to an OpenCL kernel that has to be
   *           encapsulated by the newly created \ref clxx::kernel "kernel"
   *           object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_kernel().
   */ // }}}
  explicit kernel(cl_kernel id);
  /** // doc: kernel(kernel const&) {{{
   * \brief Copy constructor
   *
   * The constructor internally retains the provided OpenCL kernel identified
   * by *id* (\ref clxx::retain_kernel()).
   *
   * \param k a \ref clxx::kernel "kernel" object to be copied.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_kernel().
   */ // }}}
  kernel(kernel const& k);
  /** // doc: kernel(prog, name) {{{
   * \brief Constructor
   *
   * Creates new OpenCL kernel. Internally calls the #create_kernel() function.
   *
   * \param prog A program object with a successfully built executable.
   * \param name A function name in the program declared with the \c __kernel qualifier.
   *
   * \throw uninitialized_program_error
   *    When \em prog is not properly initialized (see \ref clxx::program::is_initialized())
   *
   * Also throws exceptions originating from #create_kernel().
   */ // }}}
  kernel(program const& prog, std::string const& name);
  /** // doc: ~kernel() {{{
   * \brief Destructor
   *
   * If the kernel was initialized properly, then it internally releases the
   * kernel by \ref release_kernel().
   */ // }}}
  ~kernel();
  /** // doc: id() {{{
   * \brief Get the \c cl_kernel handle held by this object
   *
   * \returns the OpenCL kernel handle of type \c cl_kernel held by this
   *          object
   */ // }}}
  cl_kernel id() const noexcept
  { return this->_id; }
  /** // doc: get_valid_id() {{{
   * \brief Check if \c this object is initialized and return \c cl_kernel
   *        handle held by this object.
   *
   * \returns The \c cl_kernel handle to OpenCL kernel encapsulated within
   *          this object.
   *
   * \throws uninitialized_kernel_error when the object was not properly
   *        initialized (see is_initialized()).
   */ // }}}
  cl_kernel get_valid_id() const;
  /** // doc: operator= {{{
   * \brief Assignment operator
   *
   * \param rhs Another kernel object to be assigned to this object
   *
   *  This operation copies the \c cl_kernel handle held by \e rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throws uninitialized_kernel_error
   *    when the \e rhs object is in uninitialized state
   * \throws clerror_no<status_t::invalid_kernel>
   *    when the \e rhs holds invalid \c cl_kernel handle
   * \throws unexpected_clerror
   */ // }}}
  kernel& operator=(kernel const& rhs)
  { this->assign(rhs); return *this; }
  /** // doc: operator== {{{
   * \brief Compare this kernel with another one
   *
   * \param rhs
   *    Another kernel object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->id() == rhs.id()</tt>
   */ // }}}
  bool operator == (kernel const& rhs) const noexcept
  { return this->id() == rhs.id(); }
  /** // doc: operator!= {{{
   * \brief Compare this kernel with another one
   *
   * \param rhs
   *    Another kernel object to be compared to \c this object.
   *
   * \returns <tt>this->id() != rhs.id()</tt>
   */ // }}}
  bool operator != (kernel const& rhs) const noexcept
  { return this->id() != rhs.id(); }
  /** // doc: operator< {{{
   * \brief Compare this kernel with another one
   *
   * \param rhs
   *    Another kernel object to be compared to \c this object.
   *
   * \return <tt>this->id() < rhs.id())</tt>
   */ // }}}
  bool operator < (kernel const& rhs) const noexcept
  { return this->id() < rhs.id(); }
  /** // doc: operator> {{{
   * \brief Compare this kernel with another one
   *
   * \param rhs
   *    Another kernel object to be compared to \c this object.
   *
   * \return <tt>this->id() > rhs.id()</tt>
   */ // }}}
  bool operator > (kernel const& rhs) const noexcept
  { return this->id() > rhs.id(); }
  /** // doc: operator<= {{{
   * \brief Compare this kernel with another one
   *
   * \param rhs
   *    Another kernel object to be compared to \c this object.
   *
   * \return <tt>this->id() <= rhs.id()</tt>
   */ // }}}
  bool operator <= (kernel const& rhs) const noexcept
  { return this->id() <= rhs.id(); }
  /** // doc: operator>= {{{
   * \brief Compare this kernel with another one
   *
   * \param rhs
   *    Another kernel object to be compared to \c this object.
   *
   * \return <tt>this->id() >= rhs.id()</tt>
   */ // }}}
  bool operator >= (kernel const& rhs) const noexcept
  { return this->id() >= rhs.id(); }
  /** // doc: is_initialized() {{{
   * \brief Is this object properly initialized?
   *
   * \return Returns \c true if \c this object is initialized or \c false
   *         otherwise.
   */ // }}}
  bool is_initialized() const noexcept
  { return this->_id != NULL; }
  /** // doc: assign() {{{
   * \brief Assignment
   *
   * This operation copies the \c cl_kernel handle held by \e rhs to \c this
   * object and maintains reference count appropriately. The reference count
   * for handle originating from \e rhs gets increased by one, as it acquires
   * new user (\c this object). The reference count for handle held up to now
   * by \c this object is decreased by one, as it is forgotten by one user
   * (namely, by \c this object).
   *
   * \throws uninitialized_kernel_error
   *    when \e rhs is an uninitialized kernel object.
   * \throws clerror_no<status_t::invalid_kernel>
   *    when \e rhs holds a \c cl_kernel handle that is invalid.
   * \throws unexpected_clerror
   */ // }}}
  void assign(kernel const& rhs)
  { this->_set_id(rhs.get_valid_id(), true, true); }
  /** // doc: get_info(...) {{{
   * \brief Get certain kernel information from OpenCL
   *
   * This function calls internally \ref clxx::get_kernel_info() "get_kernel_info()".
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   *     See documentation of \ref kernel_info_t for possible values.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \e value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \ref clxx::get_kernel_info() "get_kernel_info()").
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \e value is \c NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \e value. If
   *    \e value_size_ret is \c NULL, it is ignored.
   *
   * \throws uninitialized_kernel_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_kernel_info().
   */ // }}}
  void get_info(kernel_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
  /** // doc: get_reference_count() {{{
   * \brief Get reference count for the kernel
   *
   * \returns reference count for the kernel.
   *
   * \throws uninitialized_kernel_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_kernel_info().
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_function_name() {{{
   * \brief Return the kernel function name
   * \returns A string with kernel function's name
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   * \throw std::bad_alloc
   *    When the string can't be allocated
   *
   * Also throws exceptions originating from #get_kernel_info()
   */ // }}}
  std::string get_function_name() const;
  /** // doc: get_num_args()  {{{
   * \brief Return the number of arguments to kernel
   * \returns The number of arguments to kernel's function
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_info()
   */ // }}}
  cl_uint get_num_args() const;
  /** // doc: get_context()  {{{
   * \brief Return the context associated with kernel.
   * \returns The context associated with kernel.
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_info()
   */ // }}}
  context get_context() const;
  /** // doc: get_program()  {{{
   * \brief Return the program object associated with kernel
   * \returns The program object associated with kernel
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_info()
   */ // }}}
  program get_program() const;
#if CLXX_CL_H_VERSION_1_2
  /** // doc: get_attributes()  {{{
   * \brief Returns any attributes specified with the kernel function declaration
   *
   *  Returns any attributes specified using the \c __attribute__ qualifier with
   *  the kernel function declaration in the program source. These attributes
   *  include those on the \c __attribute__ page and other attributes supported
   *  by an implementation.
   *
   *  Attributes are returned as they were declared inside
   *  <tt>__attribute__((...))</tt>, with any surrounding whitespace and
   *  embedded newlines removed. When multiple attributes are present, they are
   *  returned as a single, space delimited string.
   *
   *  \returns A string containing kernel attributes
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   * \throw std::bad_alloc
   *    When the string can't be allocated
   *
   * Also throws exceptions originating from #get_kernel_info()
   */ // }}}
  std::string get_attributes() const;
#endif
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
  /** // doc: get_arg_info() {{{
   * \brief Returns information about the arguments of the kernel
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel
   * \param name
   *    Specifies the argument information to query. The list of supported
   *    \em name values may be found in the documentation of \ref clxx::kernel "kernel"_arg_info_t.
   *    The information returned in \em value by get_arg_info corresponding
   *    to given info types is described in the OpenCL standard for the function
   *    (\c clGetKernelArgInfo()).
   * \param value_size
   *    Used to specify the size in bytes of memory pointed to by \em value.
   *    This size must be > size of return type as described in the OpenCL
   *    standard.
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \em value is \c NULL, it is ignored
   * \param value_size_ret
   *    Returns the actual size in bytes of data copied to \em value. If \em
   *    value_size_ret is \c NULL, it is ignored.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_arg_info()
   */ // }}}
  void get_arg_info(cl_uint arg_index, kernel_arg_info_t name,
                    size_t value_size, void* value, size_t* value_size_ret) const;
  /** // doc: get_arg_address_qualifier() {{{
   * \brief Returns the address qualifier specified for kernel's argument
   *
   * Returns the address qualifier specified for the argument given by
   * \em arg_index. If no address qualifier is specified, the default address
   * qualifier which is \ref clxx::kernel "kernel"_arg_address_qualifier_t::private_ is returned.
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel
   *
   * \returns The address qualifier
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_arg_info()
   */ // }}}
  kernel_arg_address_qualifier_t get_arg_address_qualifier(cl_uint arg_index) const;
  /** // doc: get_arg_access_qualifier() {{{
   * \brief Returns the access qualifier specified for kernel's argument
   *
   * Returns the access qualifier specified for the argument given by
   * \em arg_index. If argument is not an image type and is not declared with
   * the \c pipe qualifier, kernel_arg_access_qualifier_t::none is returned. If
   * argument is an image type, the access qualifier specified or the default
   * access qualifier is returned.
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel
   *
   * \returns The access qualifier
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_arg_info()
   */ // }}}
  kernel_arg_access_qualifier_t get_arg_access_qualifier(cl_uint arg_index) const;
  /** // doc: get_arg_type_name() {{{
   * \brief Returns the type name specified for kernel's argument
   *
   * Returns the type name specified for the argument given by \em arg_index.
   * The type name returned will be the argument type name as it was declared
   * with any whitespace removed. If argument type name is an unsigned scalar
   * type (i.e. <tt>unsigned char</tt>, <tt>unsigned short</tt>, <tt>unsigned
   * int</tt>, <tt>unsigned long</tt>), \c uchar, \c ushort, \c uint and \c
   * ulong will be returned. The argument type name returned does not include
   * any type qualifiers.
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel
   *
   * \returns The type name specified for kernel's argument
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   * \throw std::bad_alloc
   *    When the string can't be allocated
   *
   * Also throws exceptions originating from #get_kernel_arg_info()
   */ // }}}
  std::string get_arg_type_name(cl_uint arg_index) const;
  /** // doc: get_arg_type_qualifier() {{{
   * \brief Returns the type qualifier specified for kernel's argument
   *
   * Returns the type qualifier specified for the argument given by
   * \em arg_index.
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel
   *
   * \returns The type qualifier
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_arg_info()
   */ // }}}
  kernel_arg_type_qualifier_t get_arg_type_qualifier(cl_uint arg_index) const;
  /** // doc: get_arg_name() {{{
   * \brief Returns the name specified for kernel's argument
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel
   *
   * \returns The name specified for kernel's argument
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   * \throw std::bad_alloc
   *    When the string can't be allocated
   *
   * Also throws exceptions originating from #get_kernel_arg_info()
   */ // }}}
  std::string get_arg_name(cl_uint arg_index) const;
#endif
  /** // doc: get_work_group_info() {{{
   * \brief Returns information about the kernel object that may be specific to a device.
   *
   * \param dev
   *    Identifies a specific device in the list of devices associated with
   *    kernel. The list of devices is the list of devices in the OpenCL context
   *    that is associated with kernel.
   * \param name
   *    Specifies the information to query. The list of supported \em name
   *    types is documented in \ref clxx::kernel_work_group_info_t. The
   *    information returned in \em value is described in the OpenCL
   *    standard.
   * \param value_size
   *    Used to specify the size in bytes of memory pointed to by \em value.
   *    This size must be \c >= size of return type as described in the OpenCL
   *    standard.
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \em value is \c NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data copied to \em value. If
   *    \em value_size_ret is \c NULL, it is ignored.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_work_group_info()
   */ // }}}
  void get_work_group_info(device const& dev, kernel_work_group_info_t name,
                           size_t value_size, void* value,
                           size_t* value_size_ret) const;
  /** // doc: get_work_group_size() {{{
   * \brief Maximum work-group size that can be used to execute a kernel
   *
   * This provides a mechanism for the application to query the maximum
   * work-group size that can be used to execute a kernel on a specific device
   * given by \em dev. The OpenCL implementation uses the resource requirements
   * of the kernel (register usage etc.) to determine what this work-group size
   * should be.
   *
   * \param dev
   *    Identifies a specific device in the list of devices associated with
   *    kernel. The list of devices is the list of devices in the OpenCL
   *    context that is associated with kernel. If the list of devices
   *    associated with kernel is a single device, \em dev can be omitted
   *    or \c NULL device may be provided.
   *
   * \returns Maximum work-group size that can be used to execute a kernel.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_work_group_info()
   */ // }}}
  size_t get_work_group_size(device const& dev = device()) const;
  /** // doc: get_compile_work_group_size() {{{
   * \brief Returns reqd_work_group_size
   *
   * Returns the work-group size specified by the
   * <tt>__attribute__((reqd_work_group_size(X, Y, Z)))</tt> qualifier.
   * If the work-group size is not specified using the above attribute
   * qualifier <tt>(0, 0, 0)</tt> is returned.
   *
   * \param result
   *    Where the query result is to be stored. It must point to an array of at
   *    least three \c size_t elements.
   * \param dev
   *    Identifies a specific device in the list of devices associated with
   *    kernel. The list of devices is the list of devices in the OpenCL
   *    context that is associated with kernel. If the list of devices
   *    associated with kernel is a single device, \em dev can be omitted
   *    or \c NULL device may be provided.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_work_group_info()
   */ // }}}
  void get_compile_work_group_size(size_t* result, device const& dev = device()) const;
  /** // doc: get_local_mem_size() {{{
   * \brief Returns the amount of local memory being used by kernel
   *
   *  Returns the amount of local memory in bytes being used by a kernel. This
   *  includes local memory that may be needed by an implementation to execute
   *  the kernel, variables declared inside the kernel with the \c __local
   *  address qualifier and local memory to be allocated for arguments to the
   *  kernel declared as pointers with the \c __local address qualifier and
   *  whose size is specified with #set_arg().
   *
   *  If the local memory size, for any pointer argument to the kernel declared
   *  with the \c __local address qualifier, is not specified, its size is
   *  assumed to be \c 0.
   *
   * \param dev
   *    Identifies a specific device in the list of devices associated with
   *    kernel. The list of devices is the list of devices in the OpenCL
   *    context that is associated with kernel. If the list of devices
   *    associated with kernel is a single device, \em dev can be omitted
   *    or \c NULL device may be provided.
   *
   * \returns The amount of local memory being used by kernel
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_work_group_info()
   */ // }}}
  cl_ulong get_local_mem_size(device const& dev = device()) const;
#if CLXX_CL_H_VERSION_1_1
  /** // doc: get_preferred_work_group_size_multiple() {{{
   * \brief Returns the preferred multiple of workgroup size for launch
   *
   * Returns the preferred multiple of workgroup size for launch. This is a
   * performance hint. Specifying a workgroup size that is not a multiple of
   * the value returned by this query as the value of the local work size
   * argument to #enqueue_ndrange_kernel() will not fail to enqueue the kernel
   * for execution unless the work-group size specified is larger than the
   * device maximum.
   *
   * \param dev
   *    Identifies a specific device in the list of devices associated with
   *    kernel. The list of devices is the list of devices in the OpenCL
   *    context that is associated with kernel. If the list of devices
   *    associated with kernel is a single device, \em dev can be omitted
   *    or \c NULL device may be provided.
   *
   * \returns The preferred multiple of workgroup size for launch
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_work_group_info()
   */ // }}}
  size_t get_preferred_work_group_size_multiple(device const& dev = device()) const;
  /** // doc: get_private_mem_size() {{{
   * \brief Returns the minimum amount of private memory used by workitems
   *
   * Returns the minimum amount of private memory, in bytes, used by each
   * workitem in the kernel. This value may include any private memory needed
   * by an implementation to execute the kernel, including that used by the
   * language built-ins and variable declared inside the kernel with the
   * \c __private qualifier.
   *
   * \param dev
   *    Identifies a specific device in the list of devices associated with
   *    kernel. The list of devices is the list of devices in the OpenCL
   *    context that is associated with kernel. If the list of devices
   *    associated with kernel is a single device, \em dev can be omitted
   *    or \c NULL device may be provided.
   *
   * \returns The minimum amount of private memory used by workitems
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_work_group_info()
   */ // }}}
  cl_ulong get_private_mem_size(device const& dev = device()) const;
#endif
#if CLXX_CL_H_VERSION_1_2
  /** // doc: get_global_work_size() {{{
   * \brief Query the maximum global size that can be used to execute a kernel
   *
   *  This provides a mechanism for the application to query the maximum global
   *  size that can be used to execute a kernel (i.e. global_work_size argument
   *  to enqueue_ndrange_kernel()) on a custom device given by device or a
   *  built-in kernel on an OpenCL device given by device.
   *
   *  If device is not a custom device or kernel is not a built-in kernel,
   *  #get_arg_info() throws an clerror_no<status_t::invalid_value>.
   *
   *
   * \param result
   *    Where the query result is to be stored. It must point to an array of at
   *    least three \c size_t elements.
   * \param dev
   *    Identifies a specific device in the list of devices associated with
   *    kernel. The list of devices is the list of devices in the OpenCL
   *    context that is associated with kernel. If the list of devices
   *    associated with kernel is a single device, \em dev can be omitted
   *    or \c NULL device may be provided.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #get_kernel_work_group_info()
   */ // }}}
  void get_global_work_size(size_t* result, device const& dev = device()) const;
#endif
  /** // doc: set_arg() {{{
   * \brief Used to set the argument value to a specific argument of the kernel
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel.
   * \param size
   *    Specifies the size of the argument value. If the argument is a memory
   *    object, the size is the size of the memory object. For arguments
   *    declared with the local qualifier, the size specified will be the size
   *    in bytes of the buffer that must be allocated for the local argument.
   *    If the argument is of type \c sampler_t, the \em arg_size value must be
   *    equal to <tt>sizeof(cl_sampler)</tt>. If the argument is of type
   *    \c queue_t, the \em arg_size value must be equal to
   *    <tt>sizeof(cl_command_queue)</tt>. For all other arguments, the size
   *    will be the size of argument type.
   * \param arg_value
   *    A pointer to data that should be used as the argument value for
   *    argument specified by \em arg_index. The argument data pointed to by
   *    \em arg_value is copied and the \em arg_value pointer can therefore be
   *    reused by the application after #set_arg() returns. The argument
   *    value specified is the value used by all API calls that enqueue kernel
   *    (#enqueue_ndrange_kernel()) until the argument value is changed by a
   *    call to #set_arg() for kernel.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #set_kernel_arg()
   */ // }}}
  void set_arg(cl_uint arg_index, size_t size, const void* arg_value) const;
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
  /** // doc: set_arg_svm_pointer() {{{
   * \brief Used to set a SVM pointer as the argument value for a specific argument of the kernel
   *
   * \param arg_index
   *    The argument index. Arguments to the kernel are referred by indices
   *    that go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where
   *    \c n is the total number of arguments declared by a kernel.
   * \param arg_value
   *    A pointer to the SVM pointer that should be used as the argument value
   *    for argument specified by \em arg_index. The SVM pointer specified is
   *    the value used by all API calls that enqueue kernel
   *    (#enqueue_ndrange_kernel()) until the argument value is changed by a
   *    call to #set_arg_svm_pointer() for kernel. The SVM pointer can
   *    only be used for arguments that are declared to be a pointer to global
   *    or constant memory. The SVM pointer value must be aligned according to
   *    the argument's type. For example, if the argument is declared to be
   *    global <tt>float4 *p</tt>, the SVM pointer value passed for \c p must
   *    be at a minimum aligned to a \c float4. The SVM pointer value specified
   *    as the argument value can be the pointer returned by \c clSVMAlloc or
   *    can be a <tt>pointer + offset</tt> into the SVM region.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #set_kernel_arg_svm_pointer()
   */ // }}}
  void set_arg_svm_pointer(cl_uint arg_index, const void* arg_value) const;
#endif
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
  /** // doc: set_exec_info() {{{
   * \brief Used to pass additional information other than argument values to a kernel
   *
   * \param name
   *   Specifies the information to be passed to kernel. The list of supported
   *   param_name types may be found in the documentation of
   *   kernel_exec_info_t. The corresponding values passed in \em value are
   *   described in the OpenCL standard.
   * \param value_size
   *    Specifies the size in bytes of the memory pointed to by \em value
   * \param value
   *    A pointer to memory where the appropriate values determined by \em name
   *    are specified.
   *
   * \throw uninitialized_kernel_error
   *    When the \ref clxx::kernel "kernel" object is not properly initialized
   *
   * Also throws exceptions originating from #set_kernel_exec_info()
   */ // }}}
  void set_exec_info(kernel_exec_info_t name, size_t value_size, const void* value) const;
#endif
};

} // end namespace clxx

#endif /* CLXX_KERNEL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
