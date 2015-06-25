// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/exceptions.hpp

/** // doc: clxx/exceptions.hpp {{{
 * \file clxx/exceptions.hpp
 * \brief Defines several exceptions used across clxx project
 */ // }}}
#ifndef CLXX_EXCEPTIONS_HPP_INCLUDED
#define CLXX_EXCEPTIONS_HPP_INCLUDED

#include <clxx/exception_base.hpp>
#include <clxx/clerror_no.hpp>
#include <clxx/util/to_string.hpp>
#include <clxx/types.hpp>
#include <string>

namespace clxx {

/** // doc: invalid_argument_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception thrown when an invalid argument is provided to a function
 */ // }}}
struct invalid_argument_error
    : public exception_base<clxx::exception, std::invalid_argument>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::invalid_argument> Base;
    /** // doc: invalid_argument_error() {{{
     * \brief Default constructor
     */ // }}}
    invalid_argument_error() noexcept
      : Base("invalid argument")
    { }
    /** // doc: invalid_argument_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_argument_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: invalid_argument_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_argument_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: length_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception thrown when a sequence of invalid length is provided as an argument to a function
 */ // }}}
struct length_error
    : public exception_base<clxx::exception, std::length_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::length_error> Base;
    /** // doc: length_error() {{{
     * \brief Default constructor
     */ // }}}
    length_error() noexcept
      : Base("length error")
    { }
    /** // doc: length_error() {{{
     * \brief Constructor
     */ // }}}
    length_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: length_error() {{{
     * \brief Constructor
     */ // }}}
    length_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: out_of_range_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception thrown when a value provided to a function is out of allowed range
 */ // }}}
struct out_of_range_error
    : public exception_base<clxx::exception, std::out_of_range>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::out_of_range> Base;
    /** // doc: out_of_range_error() {{{
     * \brief Default constructor
     */ // }}}
    out_of_range_error() noexcept
      : Base("out_of_range error")
    { }
    /** // doc: out_of_range_error() {{{
     * \brief Constructor
     */ // }}}
    out_of_range_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: out_of_range_error() {{{
     * \brief Constructor
     */ // }}}
    out_of_range_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: not_enough_space_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception thrown when a user-defined storage is not sufficient to
 *        contain data provided by function caller
 */ // }}}
struct not_enough_space_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: not_enough_space_error() {{{
     * \brief Default constructor
     */ // }}}
    not_enough_space_error() noexcept
      : Base("not enough space")
    { }
    /** // doc: not_enough_space_error() {{{
     * \brief Constructor
     */ // }}}
    not_enough_space_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: not_enough_space_error() {{{
     * \brief Constructor
     */ // }}}
    not_enough_space_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_platform_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception thrown when user tries to operate on an uninitialized
 *        \ref clxx::platform "platform" object
 */ // }}}
struct uninitialized_platform_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_platform_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_platform_error() noexcept
      : Base("attempted to use uninitialized clxx::platform object")
    { }
    /** // doc: uninitialized_platform_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_platform_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_platform_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_platform_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_device_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception thrown when a user tries to operate on an uninitialized
 *        \ref clxx::device "device" object
 */ // }}}
struct uninitialized_device_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_device_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_device_error() noexcept
      : Base("attempted to use uninitialized clxx::device object")
    { }
    /** // doc: uninitialized_device_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_device_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_device_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_device_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_context_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::context "context" object
 */ // }}}
struct uninitialized_context_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_context_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_context_error() noexcept
      : Base("attempted to use uninitialized clxx::context object")
    { }
    /** // doc: uninitialized_context_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_context_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_context_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_context_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_command_queue_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::command_queue "command_queue" object
 */ // }}}
struct uninitialized_command_queue_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_command_queue_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_command_queue_error() noexcept
      : Base("attempted to use uninitialized clxx::command_queue object")
    { }
    /** // doc: uninitialized_command_queue_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_command_queue_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_command_queue_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_command_queue_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_mem_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::mem "mem" object
 */ // }}}
struct uninitialized_mem_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_mem_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_mem_error() noexcept
      : Base("attempted to use uninitialized clxx::mem object")
    { }
    /** // doc: uninitialized_mem_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_mem_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_mem_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_mem_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_program_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::program "program" object
 */ // }}}
struct uninitialized_program_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_program_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_program_error() noexcept
      : Base("attempted to use uninitialized clxx::program object")
    { }
    /** // doc: uninitialized_program_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_program_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_program_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_program_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_kernel_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::kernel "kernel" object
 */ // }}}
struct uninitialized_kernel_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_kernel_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_kernel_error() noexcept
      : Base("attempted to use uninitialized clxx::kernel object")
    { }
    /** // doc: uninitialized_kernel_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_kernel_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_kernel_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_kernel_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_event_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when a user tries to operate on an
 *        uninitialized \ref clxx::event "event" object
 */ // }}}
struct uninitialized_event_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_event_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_event_error() noexcept
      : Base("attempted to use uninitialized clxx::event object")
    { }
    /** // doc: uninitialized_event_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_event_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_event_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_event_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: uninitialized_value_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception begin thrown when a user tries to access a value which
 *        was not initialized
 *
 * This is used mainly by the \ref clxx::platform_info "platform_info" and
 * \ref clxx::device_info "device_info" object, which contain attributes that
 * may have a value but may also be in uninitialized state.
 */ // }}}
struct uninitialized_value_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: uninitialized_value_error() {{{
     * \brief Default constructor
     */ // }}}
    uninitialized_value_error() noexcept
      : Base("attempted to access uninitialized value")
    { }
    /** // doc: uninitialized_value_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_value_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: uninitialized_value_error() {{{
     * \brief Constructor
     */ // }}}
    uninitialized_value_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: value_access_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when there is an error in a value access
 *        logic
 *
 *  This is used, for example, by a \ref clxx::device_partition_property
 *  "device_partition_property". If, for example, it is of a non-sequence type
 *  and user tries to access its value as a sequence, then the
 *  #value_access_error is thrown.
 */ // }}}
struct value_access_error
    : public exception_base<clxx::exception, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::logic_error> Base;
    /** // doc: value_access_error() {{{
     * \brief Default constructor
     */ // }}}
    value_access_error() noexcept
      : Base("attempted to access value in a wrong way")
    { }
    /** // doc: value_access_error() {{{
     * \brief Constructor
     */ // }}}
    value_access_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: value_access_error() {{{
     * \brief Constructor
     */ // }}}
    value_access_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: invalid_index_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when index to an array is out of range
 */ // }}}
struct invalid_index_error
    : public exception_base<clxx::exception, std::out_of_range>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::out_of_range> Base;
    /** // doc: invalid_index_error() {{{
     * \brief Default constructor
     */ // }}}
    invalid_index_error() noexcept
      : Base("invalid index")
    { }
    /** // doc: invalid_index_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_index_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: invalid_index_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_index_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: invalid_key_error {{{
 * \ingroup clxx_exceptions
 * \brief An exception being thrown when an inexistent key is used to lookup a map
 */ // }}}
struct invalid_key_error
    : public exception_base<clxx::exception, std::out_of_range>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::exception, std::out_of_range> Base;
    /** // doc: invalid_key_error() {{{
     * \brief Default constructor
     */ // }}}
    invalid_key_error() noexcept
      : Base("invalid key")
    { }
    /** // doc: invalid_key_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_key_error(std::string const& what_arg) noexcept
      : Base(what_arg)
    { }
    /** // doc: invalid_key_error() {{{
     * \brief Constructor
     */ // }}}
    invalid_key_error(char const* what_arg) noexcept
      : Base(what_arg)
    { }
  };
/** // doc: unexpected_clerror {{{
 * \ingroup clxx_exceptions
 * \brief An exception when an OpenCL function returns error code that is unknown to clxx
 */ // }}}
struct unexpected_clerror
    : public exception_base<clxx::clerror, std::logic_error>
  {
    /** // doc: Base {{{
     * \brief Typedef for base class
     */ // }}}
    typedef clxx::exception_base<clxx::clerror, std::logic_error> Base;
    /** // doc: unexpected_clerror() {{{
     * \brief Default constructor
     */ // }}}
    unexpected_clerror(status_t c) noexcept
      : Base(std::string("unexpected OpenCL error: ") + std::to_string(c))
      , _code(c)
    { }
    /** // doc: unexpected_clerror() {{{
     * \brief Constructor
     */ // }}}
    unexpected_clerror(status_t c, std::string const& what_arg) noexcept
      : Base(what_arg),
        _code(c)
    { }
    /** // doc: unexpected_clerror() {{{
     * \brief Constructor
     */ // }}}
    unexpected_clerror(status_t c, char const* what_arg) noexcept
      : Base(what_arg),
        _code(c)
    { }
    /** // doc: code() {{{
     * \brief Returns the OpenCL error code encapsulated in the exception
     * \returns The OpenCL error code
     */ // }}}
    status_t code() const noexcept
    { return this->_code; }
  private:
    status_t _code;
  protected:
    unexpected_clerror();
  };

} // end namespace clxx

#endif /* CLXX_EXCEPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
