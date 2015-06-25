// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exception_support.li.swg {{{
 * \file clxx/exception_support.li.swg
 * \todo Write documentation
 */ // }}}

%include <exception.i>
%include <clxx/clerror_support.swg>

%{
#define SWIG_Clxx_MemoryError(e) SWIG_exception(SWIG_MemoryError, (e).what())
#define SWIG_Clxx_IOError(e) SWIG_exception(SWIG_IOError, (e).what())
#define SWIG_Clxx_RuntimeError(e) SWIG_exception(SWIG_RuntimeError, (e).what())
#define SWIG_Clxx_IndexError(e) SWIG_exception(SWIG_IndexError, (e).what())
#define SWIG_Clxx_TypeError(e) SWIG_exception(SWIG_TypeError, (e).what())
#define SWIG_Clxx_DivisionByZeroError(e) SWIG_exception(SWIG_DivisionByZeroError, (e).what())
#define SWIG_Clxx_OverflowError(e) SWIG_exception(SWIG_OverflowError, (e).what())
#define SWIG_Clxx_SyntaxError(e) SWIG_exception(SWIG_SyntaxError, (e).what())
#define SWIG_Clxx_ValueError(e) SWIG_exception(SWIG_ValueError, (e).what())
#define SWIG_Clxx_SystemError(e) SWIG_exception(SWIG_SystemError, (e).what())
%}

//
// Macros that define how we catch particular exceptions
//

// standard exceptions
#define %catch_exception catch(std::exception const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_badalloc catch(std::bad_alloc const& e) { SWIG_Clxx_MemoryError(e); }

// clxx::clerror
#define %catch_clerror catch(clxx::clerror const& e) { SWIG_Clxx_clerror(e); }

// stuff frim clxx/exceptions.hpp
#define %catch_invalid_argument_error catch(clxx::invalid_argument_error const& e) { SWIG_Clxx_ValueError(e); }
#define %catch_length_error catch(clxx::length_error const& e) { SWIG_Clxx_ValueError(e); }
#define %catch_not_enough_space_error catch(clxx::not_enough_space_error const& e) { SWIG_Clxx_ValueError(e); }
#define %catch_uninitialized_platform_error catch(clxx::uninitialized_platform_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_device_error catch(clxx::uninitialized_device_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_context_error catch(clxx::uninitialized_context_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_command_queue_error catch(clxx::uninitialized_command_queue_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_mem_error catch(clxx::uninitialized_mem_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_program_error catch(clxx::uninitialized_program_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_kernel_error catch(clxx::uninitialized_kernel_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_event_error catch(clxx::uninitialized_event_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_uninitialized_value_error catch(clxx::uninitialized_value_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_value_access_error catch(clxx::value_access_error const& e) { SWIG_Clxx_RuntimeError(e); }
#define %catch_invalid_key_error catch(clxx::invalid_key_error const& e) { SWIG_Clxx_KeyError(e); }
#define %catch_unexpected_clerror catch(clxx::unexpected_clerror const& e) { SWIG_Clxx_clerror(e); }

//
// Macros for most commonly used exception specifications
//

%define %throws_clerror(decl)
%exception decl {
  try { $action }
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_badalloc(decl)
%exception decl {
  try { $action }
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_clerror_badalloc(decl)
%exception decl {
  try { $action }
  %catch_clerror
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_uninitialized_value_error(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_value_error
  %catch_exception
}
%enddef

%define %throws_badalloc_uninitialized_value_error(decl)
%exception decl {
  try { $action }
  %catch_badalloc
  %catch_uninitialized_value_error
  %catch_exception
}
%enddef

%define %throws_invalid_key_error(decl)
%exception decl {
  try { $action }
  %catch_invalid_key_error
  %catch_exception
}
%enddef
%define %throws_invalid_key_error_badalloc(decl)
%exception decl {
  try { $action }
  %catch_invalid_key_error
  %catch_badalloc
  %catch_exception
}
%enddef

%import <clxx/exceptions.i>
%{
#include <clxx/exceptions.i.hpp>
%}
%exception {
  try {
    $action
  } catch(std::exception const& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  }
}

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
