// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_program_with_source.t.h

/** // doc: clxx/cl/functions/create_program_with_source.t.h {{{
 * \file clxx/cl/functions/create_program_with_source.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_SOURCE_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_SOURCE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_program_with_source_test_suite; }

/** // doc: class clxx::functions_create_program_with_source_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_program_with_source_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_program_with_source()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_program_with_source() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_source( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)0x1234, CL_SUCCESS);
    create_program_with_source     ((cl_context)0x567, 3, (const char**)0x787, (const size_t*)0x235);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x567);
    TS_ASSERT(std::get<1>(mock.calls().back()) == 3);
    TS_ASSERT(std::get<2>(mock.calls().back()) == (const char**)0x787);
    TS_ASSERT(std::get<3>(mock.calls().back()) == (const size_t*)0x235);
  }
  /** // doc: test__create_program_with_source__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_source__invalid_context( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__create_program_with_source__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_source__invalid_value( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_program_with_source__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_source__out_of_resources( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_program_with_source__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_source__out_of_host_memory( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_program_with_source__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_source__unexpected_clerror( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_SOURCE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
