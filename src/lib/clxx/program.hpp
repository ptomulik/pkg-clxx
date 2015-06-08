// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/program.hpp

/** // doc: clxx/program.hpp {{{
 * \file clxx/program.hpp
 * \todo Write documentation
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
 * \todo Write documentation
 */ // }}}
class program
{
private:
  cl_program _id;
  program();
protected:
  /** // doc: _set_id(cl_program, bool, bool) {{{
   * \todo Write documentation
   */ // }}}
  void _set_id(cl_program p, bool retain_new, bool release_old);
public:
  /** // doc: program(cl_program) {{{
   * \todo Write documentation
   */ // }}}
  explicit program(cl_program id);
  /** // doc: program(program const&) {{{
   * \todo Write documentation
   */ // }}}
  program(program const& p);
  /** // doc: program(context const&, program_sources const&) {{{
   * \todo Write documentation
   */ // }}}
  program(context const& ctx, program_sources const& sources);
  /** // doc: program(context, device_list, binaries, binary_statuses) {{{
   * \todo Write documentation
   */ // }}}
  program(context const& ctx, devices const& device_list,
          program_binaries const& binaries,
          std::vector<status_t>& binary_status);
  /** // doc: program(context, device_list, binaries) {{{
   * \todo Write documentation
   */ // }}}
  program(context const& ctx, devices const& device_list,
          program_binaries const& binaries);
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  /** // doc: program(context, device_list, kernel_names) {{{
   * \todo Write documentation
   */ // }}}
  program(context const& ctx, devices const& device_list,
          std::string const& kernel_names);
#endif
  /** // doc: ~program() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~program();
  /** // doc: id() {{{
   * \todo Write documentation
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
   * \throw uninitialized_program_error when the object was not properly
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
   * \throw uninitialized_program_error
   *    when the \e rhs object is in uninitialized state
   * \throw clerror_no<status_t::invalid_program>
   *    when the \e rhs holds invalid \c cl_program handle
   * \throw unexpected_clerror
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
   * \throws uninitialized_program_error if the object was not initialied
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions defined by \ref get_program_info().
   */ // }}}
  void get_info(program_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
  /** // doc: get_build_info(...) {{{
   * \todo Write documentation
   */ // }}}
  void get_build_info(device const& dev, program_build_info_t name,
                      size_t value_size, void* value,
                      size_t* value_size_ret) const;
  /** // doc: get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_context() {{{
   * \todo Write documentation
   */ // }}}
  context get_context() const;
  /** // doc: get_num_devices() {{{
   * \todo Write documentation
   */ // }}}
  cl_uint get_num_devices() const;
  /** // doc: get_devices() {{{
   * \todo Write documentation
   */ // }}}
  devices get_devices() const;
  /** // doc: get_source() {{{
   * \todo Write documentation
   */ // }}}
  program_source get_source() const;
  /** // doc: get_binary_sizes() {{{
   * \todo Write documentation
   */ // }}}
  std::vector<size_t> get_binary_sizes() const;
  /** // doc: get_binaries() {{{
   * \todo Write documentation
   */ // }}}
  program_binaries get_binaries() const;
  /** // doc: get_num_kernels() {{{
   * \todo Write documentation
   */ // }}}
  size_t get_num_kernels() const;
  /** // doc: get_kernel_names() {{{
   * \todo Write documentation
   */ // }}}
  std::string get_kernel_names() const;
  /** doc: get_build_status() {{{
   * \todo Write documentation
   */ // }}}
  build_status_t get_build_status(device const& dev) const;
  /** doc: get_build_options() {{{
   * \todo Write documentation
   */ // }}}
  std::string get_build_options(device const& dev) const;
  /** doc: get_build_log() {{{
   * \todo Write documentation
   */ // }}}
  std::string get_build_log(device const& dev) const;
  /** doc: get_binary_type() {{{
   * \todo Write documentation
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
   * \throw uninitialized_program_error
   *    when \e rhs is an uninitialized program object.
   * \throw clerror_no<status_t::invalid_program>
   *    when \e rhs holds a \c cl_program handle that is invalid.
   * \throw unexpected_clerror
   */ // }}}
  void assign(program const& rhs)
  { this->_set_id(rhs.get_valid_id(), true, true); }
};
} // end namespace clxx

namespace clxx {
  /** // doc: programs {{{
   * \todo Write documentation
   */ // }}}
typedef std::vector<program> programs;
/** // doc: build_program(options) {{{
 * \todo Write documentation
 */ // }}}
void build_program(program const& prog, std::string const& options);
/** // doc: build_program(devices, options) {{{
 * \todo Write documentation
 */ // }}}
void build_program(program const& prog, devices const& devs, std::string const& options);
/** // doc: build_program(options, observer) {{{
 * \todo Write documentation
 */ // }}}
void build_program(program const& prog, std::string const& options,
                   program_observer& observer);
/** // doc: build_program(devices, options, observer) {{{
 * \todo Write documentation
 */ // }}}
void build_program(program const& prog, devices const& devs,
                   std::string const& options, program_observer& observer);
#if HAVE_OPENCL_clCompileProgram
/** // doc: compile_program(...) {{{
 * \todo Write documentation
 */ // }}}
void compile_program(program const&, std::string const& options,
                     programs const& input_headers,
                     std::vector<std::string> const& header_include_names);
/** // doc: compile_program(...) {{{
 * \todo Write documentation
 */ // }}}
void compile_program(program const&, std::string const& options,
                     programs const& input_headers,
                     std::vector<std::string> const& header_include_names,
                     program_observer& observer);
/** // doc: compile_program(...) {{{
 * \todo Write documentation
 */ // }}}
void compile_program(program const&, devices const& devs,
                     std::string const& options, programs const& input_headers,
                     std::vector<std::string> const& header_include_names);
/** // doc: compile_program(...) {{{
 * \todo Write documentation
 */ // }}}
void compile_program(program const&, devices const& devs,
                     std::string const& options, programs const& input_headers,
                     std::vector<std::string> const& header_include_names,
                     program_observer& observer);
#endif
#if HAVE_OPENCL_clLinkProgram
  /** // doc: link_program(context, devices, options, input_programs) {{{
   * \todo Write documentation
   */ // }}}
program link_program(context const& ctx, devices const& device_list,
                     std::string const& options,
                     programs const& input_programs);
  /** // doc: link_program(context, devices, options, input_programs, observer) {{{
   * \todo Write documentation
   */ // }}}
program link_program(context const& ctx, devices const& device_list,
                     std::string const& options,
                     programs const& input_programs,
                     program_observer& observer);
#endif
} // end namespace clxx
#endif /* CLXX_PROGRAM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
