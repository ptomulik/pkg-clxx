// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/program.hpp

/** // doc: clxx/program.hpp {{{
 * \file clxx/program.hpp
 * \brief Provides clxx::program class and related functions
 */ // }}}
#ifndef CLXX_PROGRAM_HPP_INCLUDED
#define CLXX_PROGRAM_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/devices.hpp>
#include <clxx/context.hpp>
#include <clxx/program_sources.hpp>
#include <clxx/program_binaries.hpp>
#include <clxx/program_observer.hpp>
#include <vector>
#include <string>

namespace clxx {
/** // doc: program {{{
 * \ingroup clxx_program_objects
 * \brief Encapsulates an OpenCL program object
 *
 * This class represents OpenCL program and forwards basic operations on
 * programs to OpenCL. It encapsulates a \c cl_program identifier and
 * supports following operations:
 *
 * - program creation (constructors), by calling internally \ref
 *   create_program_with_source(), \ref create_program_with_binary(), or
 *   \ref create_program_with_built_in_kernels(),
 * - automatic reference count management by using internally
 *   \ref retain_program() and \ref release_program(),
 * - retrieving program information from OpenCL (via class methods), by
 *   invoking internally \ref get_program_info().
 * - retrieving program build information from OpenCL (via class methods), by
 *   calling internally \ref clxx::get_program_build_info() "get_program_build_info()",
 *
 * Note, that the newly created program (from source) is not compiled. It may
 * be compiled by using \ref clxx::compile_program() "compile_program()",
 * \ref clxx::build_program() "build_program()", and/or \ref clxx::link_program()
 * "link_program()".
 *
 * Although \ref clxx::program "program" maintains internally reference count
 * for its \c cl_program handle, it doesn't prevent one from stealing the \c
 * cl_program handle (\ref id(), \ref get_valid_id()). This gives rise to
 * manipulate the reference count outside of the \ref clxx::program object for
 * the given OpenCL program object. If you need to steal, use the retrieved
 * handle with care. If you retrieve the handle from \ref clxx::program
 * "program" object, increase its reference count with \ref
 * clxx::retain_program() "retain_program()" as soon as possible, and decrease
 * the reference count with \ref clxx::release_program() "release_program()"
 * once you don't need the handle. If you don't retain the program, it may be
 * unexpectedly released by \ref clxx::program "program's"  destructor,
 * assignment operator or the #assign() method.
 *
 * There are constructors which create new OpenCL program (a costly operation).
 * However, assignment operator and copy constructors just copy over the \c
 * cl_program handle and maintain reference count appropriately. To verify
 * if two \ref clxx::program "program" objects refer to the same OpenCL
 * program, use \c == operator (of \c != operator).
 *
 * An OpenCL program (identified by \c cl_program handle) is not released
 * until there is at least one \ref clxx::program "program" object
 * encapsulating its handle. On the other hand - the program may get released
 * by OpenCL when last \ref clxx::program "program" object gets deleted (the
 * ~program() destructor decreases reference count for its \c cl_program
 * handle with \ref clxx::release_program() "release_program()") or when the
 * last object gets assigned another OpenCL program (assignment operator or the
 * #assign() method).
 */ // }}}
class program
{
private:
  cl_program _id;
  program();
protected:
  /** // doc: _set_id(cl_program, bool, bool) {{{
   * \brief Set the \c cl_program handle to this object
   *
   * \param prog the \c cl_program handle (OpenCL program),
   * \param retain_new whether to invoke \ref retain_program() on *prog*,
   * \param release_old whether to invoke \ref release_program() on the handle
   *        held up to this moment by this object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_program().
   */ // }}}
  void _set_id(cl_program prog, bool retain_new, bool release_old);
public:
  /** // doc: program(cl_program) {{{
   * \brief Creates \ref clxx::program "program" object from explicitly given
   *        OpenCL \c cl_program handle.
   *
   * The constructor internally retains the provided OpenCL program identified
   * by *id* (\ref clxx::retain_program()).
   *
   * \param id handle (identifier) to an OpenCL program that has to be
   *           encapsulated by the newly created \ref clxx::program "program"
   *           object.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_program().
   */ // }}}
  explicit program(cl_program id);
  /** // doc: program(program const&) {{{
   * \brief Copy constructor
   *
   * The constructor internally retains the provided OpenCL program identified
   * by *id* (\ref clxx::retain_program()).
   *
   * \param p a \ref clxx::program "program" object to be copied.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref retain_program().
   */ // }}}
  program(program const& p);
  /** // doc: program(context const&, program_sources const&) {{{
   * \brief Create program with sources
   *
   * Creates new program by using \ref create_program_with_source(). Note, that
   * \ref create_program_with_binary() retains the program internally.
   *
   * \param ctx OpenCL context (clxx object \ref clxx::context "context"),
   * \param sources sources that comprise the program.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref create_program_with_source().
   */ // }}}
  program(context const& ctx, program_sources const& sources);
  /** // doc: program(context, device_list, binaries, binary_statuses) {{{
   * \brief Create program with binaries
   *
   * Creates new program by using \ref create_program_with_binary(). Note,
   * that \ref create_program_with_binary() retains the program internally.
   *
   * \param ctx
   *    must be a valid \ref clxx::context "context",
   * \param device_list
   *    list of devices that are in context *ctx*, the binaries are loaded for
   *    devices specified in this list,
   * \param binaries
   *    program binaries to be loaded for devices specified in *device_list*,
   *    for each device given by *device_list[i]*, the binary for that device
   *    is given in *binaries[i]*,
   * \param binary_status
   *    returns whether the program binary for each device specified in
   *    *device_list* was loaded successfully or not.
   *
   * \throws clxx::invalid_argument_error when *device_list* is empty or
   *        *device_list* has different size than *binaries*.
   *
   * In addition exceptions originating from \ref create_program_with_binary()
   * may be thrown.
   */ // }}}
  program(context const& ctx, devices const& device_list,
          program_binaries const& binaries,
          std::vector<status_t>& binary_status);
  /** // doc: program(context, device_list, binaries) {{{
   * \brief Create program with binaries
   *
   * Creates new program by using \ref create_program_with_binary(). Note,
   * that \ref create_program_with_binary() retains the program internally.
   *
   * \param ctx
   *    must be a valid \ref clxx::context "context",
   * \param device_list
   *    list of devices that are in context *ctx*, the binaries are loaded for
   *    devices specified in this list,
   * \param binaries
   *    program binaries to be loaded for devices specified in *device_list*,
   *    for each device given by *device_list[i]*, the binary for that device
   *    is given in *binaries[i]*,
   *
   * \throws clxx::invalid_argument_error when *device_list* is empty or
   *        *device_list* has different size than *binaries*.
   *
   * In addition exceptions originating from \ref create_program_with_binary()
   * may be thrown.
   */ // }}}
  program(context const& ctx, devices const& device_list,
          program_binaries const& binaries);
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  /** // doc: program(context, device_list, kernel_names) {{{
   * \brief Create program with built in kernels
   *
   * Creates new OpenCL program by using
   * \ref create_program_with_built_in_kernels(). Note, that
   * \ref create_program_with_built_in_kernels() performs internal retain.
   *
   * \note Only available if the clxx library is built with OpenCL 1.2 or later.
   *
   * \param ctx
   *    must be a valid \ref clxx::context "context",
   * \param device_list
   *    list of devices that are in context *ctx*, built-in kernels are loaded
   *    for devices specified in this list; the devices associated wit the
   *    program object will be the list of devices specified by *device_list*
   * \param kernel_names
   *    a semi-colon separated list of built-in kernel names.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref create_program_with_built_in_kernels().
   */ // }}}
  program(context const& ctx, devices const& device_list,
          std::string const& kernel_names);
#endif
  /** // doc: ~program() {{{
   * \brief Destructor
   *
   * If the program was initialized properly, then it internally releases the
   * program by \ref release_program().
   */ // }}}
  virtual ~program();
  /** // doc: id() {{{
   * \brief Get the \c cl_program handle held by this object
   *
   * \returns the OpenCL program handle of type \c cl_program held by this
   *          object
   */ // }}}
  cl_program id() const noexcept
  { return this->_id; }
  /** // doc: get_valid_id() {{{
   * \brief Check if \c this object is initialized and return \c cl_program
   *        handle held by this object.
   *
   * \returns The \c cl_program handle to OpenCL program encapsulated within
   *          this object.
   *
   * \throws uninitialized_program_error when the object was not properly
   *        initialized (see is_initialized()).
   */ // }}}
  cl_program get_valid_id() const;
  /** // doc: operator= {{{
   * \brief Assignment operator
   *
   * \param rhs Another program object to be assigned to this object
   *
   *  This operation copies the \c cl_program handle held by \e rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throws uninitialized_program_error
   *    when the \e rhs object is in uninitialized state
   * \throws clerror_no<status_t::invalid_program>
   *    when the \e rhs holds invalid \c cl_program handle
   * \throws unexpected_clerror
   */ // }}}
  program& operator=(program const& rhs)
  { this->assign(rhs); return *this; }
  /** // doc: operator== {{{
   * \brief Compare this program with another one
   *
   * \param rhs
   *    Another program object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->id() == rhs.id()</tt>
   */ // }}}
  bool operator == (program const& rhs) const noexcept
  { return this->id() == rhs.id(); }
  /** // doc: operator!= {{{
   * \brief Compare this program with another one
   *
   * \param rhs
   *    Another program object to be compared to \c this object.
   *
   * \returns <tt>this->id() != rhs.id()</tt>
   */ // }}}
  bool operator != (program const& rhs) const noexcept
  { return this->id() != rhs.id(); }
  /** // doc: operator< {{{
   * \brief Compare this program with another one
   *
   * \param rhs
   *    Another program object to be compared to \c this object.
   *
   * \return <tt>this->id() < rhs.id())</tt>
   */ // }}}
  bool operator < (program const& rhs) const noexcept
  { return this->id() < rhs.id(); }
  /** // doc: operator> {{{
   * \brief Compare this program with another one
   *
   * \param rhs
   *    Another program object to be compared to \c this object.
   *
   * \return <tt>this->id() > rhs.id()</tt>
   */ // }}}
  bool operator > (program const& rhs) const noexcept
  { return this->id() > rhs.id(); }
  /** // doc: operator<= {{{
   * \brief Compare this program with another one
   *
   * \param rhs
   *    Another program object to be compared to \c this object.
   *
   * \return <tt>this->id() <= rhs.id()</tt>
   */ // }}}
  bool operator <= (program const& rhs) const noexcept
  { return this->id() <= rhs.id(); }
  /** // doc: operator>= {{{
   * \brief Compare this program with another one
   *
   * \param rhs
   *    Another program object to be compared to \c this object.
   *
   * \return <tt>this->id() >= rhs.id()</tt>
   */ // }}}
  bool operator >= (program const& rhs) const noexcept
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
   * \brief Get certain program information from OpenCL
   *
   * This function calls internally \ref clxx::get_program_info() "get_program_info()".
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   *     See documentation of \ref program_info_t for possible values.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \e value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \ref clxx::get_program_info() "get_program_info()").
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \e value is \c NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \e value. If
   *    \e value_size_ret is \c NULL, it is ignored.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  void get_info(program_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
  /** // doc: get_build_info(...) {{{
   * \brief Returns build information for each device in the program object
   *
   * \param dev
   *    device for which build information is being queried. device must be a
   *    valid device associated with program.
   * \param name
   *    specifies the information to query; the list of supported *name*
   *    types is documented in \ref program_build_info_t.
   * \param value_size
   *    the size in bytes of memory pointed to by *value*; this size must be >=
   *    size of return type as described in the table above
   * \param value
   *    a pointer to memory where the appropriate result being queried is
   *    returned; if *value* is \c NULL, it is ignored,
   * \param value_size_ret
   *    returns the actual size in bytes of data copied to *value*. If
   *    *value_size_ret* is \c NULL, it is ignored.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  void get_build_info(device const& dev, program_build_info_t name,
                      size_t value_size, void* value,
                      size_t* value_size_ret) const;
  /** // doc: get_reference_count() {{{
   * \brief Get reference count for the program
   *
   * \returns reference count for the program.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_program_info().
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_context() {{{
   * \brief Get context associated with this program
   *
   * \returns context associated with the program.
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_program_info().
   */ // }}}
  context get_context() const;
  /** // doc: get_num_devices() {{{
   * \brief Get number of devices associated with the program
   *
   * \returns number of devices associated with the program.
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_program_info().
   */ // }}}
  cl_uint get_num_devices() const;
  /** // doc: get_devices() {{{
   * \brief Get devices associated with the program
   *
   * \returns list of devices associated with the program.
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_program_info().
   */ // }}}
  devices get_devices() const;
  /** // doc: get_source() {{{
   * \brief Get program source
   *
   * \returns source code for the program
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   * \throws std::bad_alloc when it's unable to allocate memory for device list
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  program_source get_source() const;
  /** // doc: get_binary_sizes() {{{
   * \brief Return sizes of the program binaries
   *
   * \returns
   *    a vector of sizes in bytes of the program binary (could be an
   *    executable binary, compiled binary or library binary) for each device
   *    associated with program; if a binary is not available for a device(s),
   *    a size of zero is returned.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   * \throws std::bad_alloc when the memory for vector can't be allocated,
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  std::vector<size_t> get_binary_sizes() const;
  /** // doc: get_binaries() {{{
   * \brief Return program binaries
   *
   * Return the program binaries (could be an executable binary, compiled
   * binary or library binary) for all devices associated with program.
   * For each device in program, the binary returned can be the binary
   * specified for the device when program is created with binary or it
   * can be the executable binary generated by \ref build_program(),
   * \ref compile_program() or \ref link_program(). The bits returned can be an
   * implementation-specific intermediate representation (a.k.a. IR) or device
   * specific executable bits or both. The decision on which information is
   * returned in the binary is up to the OpenCL implementation.
   *
   * \returns program binaries
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   * \throws std::bad_alloc if a memory for program binaries can't be allocated,
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  program_binaries get_binaries() const;
  /** // doc: get_num_kernels() {{{
   * \brief Return the number of kernels declared in program
   *
   * Returns the number of kernels declared in program that can be created with
   * clCreateKernel. This information is only available after a successful
   * program executable has been built for at least one device in the list of
   * devices associated with program.
   *
   * \returns the number of kernels declared in program
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  size_t get_num_kernels() const;
  /** // doc: get_kernel_names() {{{
   * \brief Return list of kernel names in program
   *
   * \returns a semi-colon separated list of kernel names in program that can
   *          be created with \ref create_kernel().
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  std::string get_kernel_names() const;
  /** doc: get_build_status() {{{
   * \brief Return build, compile or link status
   *
   * Returns the build, compile or link status, whichever was performed last on
   * program for device.
   *
   * \param dev
   *    device associated with the program for which the build status has to be
   *    returned.
   *
   * \returns the status, see \ref build_status_t.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  build_status_t get_build_status(device const& dev) const;
  /** doc: get_build_options() {{{
   * \brief Return build, compile or link options
   *
   * Return the build, compile or link options specified by the options
   * argument to \ref build_program(), \ref compile_program() or \ref
   * link_program() whichever was performed last on this program for device
   * *dev*. If build status of program for device is \c none, an empty
   * string is returned.
   *
   * \param dev
   *    device associated with the program for which the build options have to
   *    be returned.
   *
   * \returns the options, as specified at the build time.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  std::string get_build_options(device const& dev) const;
  /** doc: get_build_log() {{{
   * \brief Return build, compile or link log
   *
   * Return the build, compile or link log for \ref build_program() or
   * \ref compile_program() whichever was performed last on this program for
   * device *dev*. If build status of program for device is \c none, an empty
   * string is returned.
   *
   * \param dev
   *    device associated with the program for which the build options have to
   *    be returned.
   *
   * \returns the log string.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  std::string get_build_log(device const& dev) const;
  /** doc: get_binary_type() {{{
   * \brief Return the program binary type for a device
   *
   * Return the program binary type for device *dev*. Possible values are
   * defined by \ref program_binary_type_t.
   *
   * \returns program binary type for device *dev*.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  program_binary_type_t get_binary_type(device const& dev) const;
  /** // doc: assign() {{{
   * \brief Assignment
   *
   * This operation copies the \c cl_program handle held by \e rhs to \c this
   * object and maintains reference count appropriately. The reference count
   * for handle originating from \e rhs gets increased by one, as it acquires
   * new user (\c this object). The reference count for handle held up to now
   * by \c this object is decreased by one, as it is forgotten by one user
   * (namely, by \c this object).
   *
   * \throws uninitialized_program_error
   *    when \e rhs is an uninitialized program object.
   * \throws clerror_no<status_t::invalid_program>
   *    when \e rhs holds a \c cl_program handle that is invalid.
   * \throws unexpected_clerror
   */ // }}}
  void assign(program const& rhs)
  { this->_set_id(rhs.get_valid_id(), true, true); }
};
} // end namespace clxx

namespace clxx {
/** \addtogroup clxx_program_objects
 * @{ */
  /** // doc: programs {{{
   * \brief Sequence of \ref clxx::program "program"s
   *
   * Same as std::vector<clxx::program>.
   */ // }}}
typedef std::vector<program> programs;
/** // doc: build_program(options) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all the devices in the OpenCL context associated with program.
 *
 * \param prog
 *    the \ref clxx::program "program" to be built,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 *
 * \throws uninitialized_program_error
 *    when \e rhs is an uninitialized program object.
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 */ // }}}
void build_program(program const& prog, std::string const& options);
/** // doc: build_program(devices, options) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for specific devices in the OpenCL context associated with program.
 *
 * \param prog
 *    the \ref clxx::program "program" to be built,
 * \param devs
 *    devices associated with the program *prog*; the executable is built for
 *    these devices, for which a source or binary has been loaded,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 *
 * \throws uninitialized_program_error
 *    when \e rhs is an uninitialized program object.
 * \throws uninitialized_device_error
 *    when one of the devices in \e devs is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 */ // }}}
void build_program(program const& prog, devices const& devs, std::string const& options);
/** // doc: build_program(options, observer) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all devices in the OpenCL context associated with program.
 *
 * \param prog
 *    the \ref clxx::program "program" to be built,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 * \param observer
 *    observer object (see \ref program_observer) used to receive notifications
 *    the callback may be called asynchronously by the OpenCL implementation,
 *    it's the application's responsibility to ensure that the callback
 *    function is thread-safe.
 *
 * \throws uninitialized_program_error
 *    when \e rhs is an uninitialized program object.
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()"
 */ // }}}
void build_program(program const& prog, std::string const& options,
                   program_observer& observer);
/** // doc: build_program(devices, options, observer) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for specific devices in the OpenCL context associated with program.
 *
 * \param prog
 *    the \ref clxx::program "program" to be built,
 * \param devs
 *    devices associated with the program *prog*; the executable is built for
 *    these devices, for which a source or binary has been loaded,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 * \param observer
 *    observer object (see \ref program_observer) used to receive notifications
 *    the callback may be called asynchronously by the OpenCL implementation,
 *    it's the application's responsibility to ensure that the callback
 *    function is thread-safe.
 *
 * \throws uninitialized_program_error
 *    when \e rhs is an uninitialized program object.
 * \throws uninitialized_device_error
 *    when one of the devices in \e devs is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 */ // }}}
void build_program(program const& prog, devices const& devs,
                   std::string const& options, program_observer& observer);
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for all associated devices
 *
 * Compiles a program’s source for all the devices in the OpenCL
 * context associated with program \e prog. The compiled binary can be queried
 * using <tt>prog.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param prog
 *    the program object that is the compilation target,
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 *
 * \throws uninitialized_program_error when the \em prog object was not properly
 *        initialized (see \ref clxx::program::is_initialized()).
 *
 * Throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program()".
 */ // }}}
void compile_program(program const& prog, std::string const& options,
                     programs const& input_headers,
                     std::vector<std::string> const& header_include_names);
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for all associated devices
 *
 * Compiles a program’s source for all the devices in the OpenCL
 * context associated with program \e prog. The compiled binary can be queried
 * using <tt>prog.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param prog
 *    the program object that is the compilation target,
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 * \param observer
 *    an oberver object (\ref clxx::program_observer "program_observer") that
 *    will be notified when program executable has been built; the observer
 *    may be notified asynchronously; it is the application’s responsibility to
 *    ensure that the callback function is thread-safe.
 *
 * \throws uninitialized_program_error when the \em prog object was not properly
 *        initialized (see \ref clxx::program::is_initialized()).
 *
 * Throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program().
 */ // }}}
void compile_program(program const& prog, std::string const& options,
                     programs const& input_headers,
                     std::vector<std::string> const& header_include_names,
                     program_observer& observer);
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for specific devices
 *
 * Compiles a program’s source for all specific devices in the OpenCL
 * context associated with program \e prog. The compiled binary can be queried
 * using <tt>prog.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param prog
 *    the program object that is the compilation target,
 * \param devs
 *    devices associated with \e prog, for which the compile is performed
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 *
 * \throws uninitialized_program_error when the \em prog object was not properly
 *        initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *    when one of the devices in \e devs is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program()".
 */ // }}}
void compile_program(program const& prog, devices const& devs,
                     std::string const& options, programs const& input_headers,
                     std::vector<std::string> const& header_include_names);
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for specific devices
 *
 * Compiles a program’s source for specific devices in the OpenCL
 * context associated with program \e prog. The compiled binary can be queried
 * using <tt>prog.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param prog
 *    the program object that is the compilation target,
 * \param devs
 *    devices associated with \e prog, for which the compile is performed
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 * \param observer
 *    an oberver object (\ref clxx::program_observer "program_observer") that
 *    will be notified when program executable has been built; the observer
 *    may be notified asynchronously; it is the application’s responsibility to
 *    ensure that the callback function is thread-safe.
 *
 * \throws uninitialized_program_error when the \em prog object was not properly
 *        initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *    when one of the devices in \e devs is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program()".
 */ // }}}
void compile_program(program const& prog, devices const& devs,
                     std::string const& options, programs const& input_headers,
                     std::vector<std::string> const& header_include_names,
                     program_observer& observer);
#endif
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
/** // doc: link_program(context, devices, options, input_programs) {{{
 * \brief Links a set of compiled program objects and libraries and creates an
 *    executable.
 *
 *  Creates a new program object which contains executable. The executable
 *  binary can be queried using \ref clxx::program::get_binaries() on the
 *  returned object, and can be specified to \ref clxx::program "program"'s
 *  constructor to create a new program object with binary.
 *
 *  The devices associated with the returned program object will be the list of
 *  devices specified by \e device_list or if \e device_list is \c NULL it will
 *  be the list of devices associated with \e context.
 *
 *  The linking operation can begin if the context, list of devices, input
 *  programs and linker options specified are all valid and appropriate host
 *  and device resources needed to perform the link are available. If the
 *  linking operation can begin, the function returns a valid program object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param ctx
 *    must be a valid \ref clxx::context "context",
 * \param device_list
 *    devices that are in context \em ctx, for which the link is to be
 *    performed,
 * \param options
 *    string of characters that describes the link options to be used for
 *    building the program executable,
 * \param input_programs
 *    \ref clxx::program "program" objects that are compiled binaries or
 *    libraries that are to be linked to create the program executable.
 *
 * \throws uninitialized_context_error when the \em ctx object was not properly
 *        initialized (see \ref clxx::context::is_initialized()).
 * \throws uninitialized_program_error when the \em prog object was not properly
 *        initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *    when one of the devices in \e device_list is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::link_program() "link_program()".
 */ // }}}
program link_program(context const& ctx, devices const& device_list,
                     std::string const& options,
                     programs const& input_programs);
/** // doc: link_program(context, devices, options, input_programs, observer) {{{
 * \brief Links a set of compiled program objects and libraries and creates an
 *    executable.
 *
 *  Creates a new program object which contains executable. The executable
 *  binary can be queried using \ref clxx::program::get_binaries() on the
 *  returned object, and can be specified to \ref clxx::program "program"'s
 *  constructor to create a new program object with binary.
 *
 *  The devices associated with the returned program object will be the list of
 *  devices specified by \e device_list or if \e device_list is \c NULL it will
 *  be the list of devices associated with \e context.
 *
 *  The linking operation can begin if the context, list of devices, input
 *  programs and linker options specified are all valid and appropriate host
 *  and device resources needed to perform the link are available. If the
 *  linking operation can begin, the function returns a valid program object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param ctx
 *    must be a valid \ref clxx::context "context",
 * \param device_list
 *    devices that are in context \em ctx, for which the link is to be
 *    performed,
 * \param options
 *    string of characters that describes the link options to be used for
 *    building the program executable,
 * \param input_programs
 *    \ref clxx::program "program" objects that are compiled binaries or
 *    libraries that are to be linked to create the program executable,
 * \param observer
 *    a \ref clxx::program_observer "program_observer" object which will be
 *    notified when the program executable has been built (successfully or
 *    unsuccessfully); the observer may be called asynchronously, it's the
 *    application's responsibility to ensure that the callback is thread-safe.
 *
 * \throws uninitialized_context_error when the \em ctx object was not properly
 *        initialized (see \ref clxx::context::is_initialized()).
 * \throws uninitialized_program_error when the \em prog object was not properly
 *        initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *    when one of the devices in \e device_list is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::link_program() "link_program()".
 */ // }}}
program link_program(context const& ctx, devices const& device_list,
                     std::string const& options,
                     programs const& input_programs,
                     program_observer& observer);
#endif
/** @} */
} // end namespace clxx
#endif /* CLXX_PROGRAM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
