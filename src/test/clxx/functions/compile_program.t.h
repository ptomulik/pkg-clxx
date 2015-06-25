// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/compile_program.t.h

/** // doc: clxx/functions/compile_program.t.h {{{
 * \file clxx/functions/compile_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_COMPILE_PROGRAM_T_H_INCLUDED
#define CLXX_FUNCTIONS_COMPILE_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_compile_program_test_suite; }

/** // doc: class clxx::functions_compile_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_compile_program_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  compile_program()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__compile_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_SUCCESS);
    compile_program                ((cl_program)0x344, 7, (const cl_device_id*)0x543, (const char*)0x937, 5, (const cl_program*)0x634, (const char**)0x834, (void(*)(cl_program,void*))0x936, (void*)0x234);
    TS_ASSERT(mock.called_once_with((cl_program)0x344, 7, (const cl_device_id*)0x543, (const char*)0x937, 5, (const cl_program*)0x634, (const char**)0x834, (void(*)(cl_program,void*))0x936, (void*)0x234));
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_program( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_compiler_options() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_compiler_options( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_COMPILER_OPTIONS);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_compiler_options>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__compiler_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__compiler_not_available( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_COMPILER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compiler_not_available>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__compile_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__compile_program_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_COMPILE_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compile_program_failure>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(-0x1234567);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
};

#endif /* CLXX_FUNCTIONS_COMPILE_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
