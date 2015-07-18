// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/build_program.t.h

/** // doc: clxx/cl/functions/build_program.t.h {{{
 * \file clxx/cl/functions/build_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_BUILD_PROGRAM_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_BUILD_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_build_program_test_suite; }

/** // doc: class clxx::functions_build_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_build_program_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  build_program()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__build_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program( )
  {
    T::Dummy_clBuildProgram mock(CL_SUCCESS);
    build_program                  ((cl_program)0x634, 7, (const cl_device_id*)0x543, (const char*)0x5234, (void(*)(cl_program,void*))0x654, (void*)0x122);
    TS_ASSERT(mock.called_once_with((cl_program)0x634, 7, (const cl_device_id*)0x543, (const char*)0x5234, (void(*)(cl_program,void*))0x654, (void*)0x122));
  }
  /** // doc: test__build_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__invalid_program( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__build_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__invalid_value( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__build_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__invalid_device( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__build_program__invalid_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__invalid_binary( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_BINARY);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_binary>);
  }
  /** // doc: test__build_program__invalid_build_options() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__invalid_build_options( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_BUILD_OPTIONS);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_build_options>);
  }
  /** // doc: test__build_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__invalid_operation( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
  }
  /** // doc: test__build_program__compiler_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__compiler_not_available( )
  {
    T::Dummy_clBuildProgram mock(CL_COMPILER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compiler_not_available>);
  }
  /** // doc: test__build_program__build_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__build_program_failure( )
  {
    T::Dummy_clBuildProgram mock(CL_BUILD_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::build_program_failure>);
  }
  /** // doc: test__build_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__out_of_resources( )
  {
    T::Dummy_clBuildProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__build_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__out_of_host_memory( )
  {
    T::Dummy_clBuildProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__build_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__build_program__unexpected_clerror( )
  {
    T::Dummy_clBuildProgram mock(-0x1234567);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_BUILD_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
