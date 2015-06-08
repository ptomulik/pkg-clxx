// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/exceptions.hpp

/** // doc: clxx/exceptions.hpp {{{
 * \file clxx/exceptions.hpp
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
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
 * \todo Write documentation
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
/** // doc: uninitialized_program_error {{{
 * \todo Write documentation
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
/** // doc: uninitialized_value_error {{{
 * \todo Write documentation
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
 * \todo Write documentation
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
/** // doc: invalid_key_error {{{
 * \todo Write documentation
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
 * \todo Write documentation
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
     * \todo Write documentation
     */ // }}}
    status_t code() const noexcept
    { return this->_code; }
  private:
    /** // doc: _code {{{
     * \todo Write documentation
     */ // }}}
    status_t _code;
  protected:
    unexpected_clerror();
  };
} // end namespace clxx

#endif /* CLXX_EXCEPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
