// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_program_with_binary.t.h

/** // doc: clxx/cl/functions/create_program_with_binary.t.h {{{
 * \file clxx/cl/functions/create_program_with_binary.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_BINARY_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_BINARY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_program_with_binary_test_suite; }

/** // doc: class clxx::functions_create_program_with_binary_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_program_with_binary_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_program_with_binary()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_program_with_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary( )
  {
    //T::Dummy_clCreateProgramWithBinary mock((cl_program)0x1234, CL_SUCCESS);
    //create_program_with_binary     ((cl_context)0x567, 5, (const cl_device_id*)0x487, (const size_t*)0x634, (const unsigned char**)0x174, (cl_int*)0x757);
    //TS_ASSERT(mock.called_once_with((cl_context)0x567, 5, (const cl_device_id*)0x487, (const size_t*)0x634, (const unsigned char**)0x174, (cl_int*)0x757));
  }
  /** // doc: test__create_program_with_binary__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_context( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__create_program_with_binary__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_value( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_program_with_binary__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_device( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__create_program_with_binary__invalid_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__invalid_binary( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_BINARY);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_binary>);
  }
  /** // doc: test__create_program_with_binary__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__out_of_resources( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_program_with_binary__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__out_of_host_memory( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_program_with_binary__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_binary__unexpected_clerror( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_PROGRAM_WITH_BINARY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
