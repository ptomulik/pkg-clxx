// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_program_build_info.t.h

/** // doc: clxx/cl/functions/get_program_build_info.t.h {{{
 * \file clxx/cl/functions/get_program_build_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_PROGRAM_BUILD_INFO_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_PROGRAM_BUILD_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_program_build_info_test_suite; }

/** // doc: class clxx::functions_get_program_build_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_program_build_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_program_build_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_program_build_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_SUCCESS);
    get_program_build_info         ((cl_program)0x253, (cl_device_id)0x563, program_build_info_t::status,                   4, (void*)0x973, (size_t*)0x938);
    TS_ASSERT(mock.called_once_with((cl_program)0x253, (cl_device_id)0x563, (cl_program_build_info)CL_PROGRAM_BUILD_STATUS, 4, (void*)0x973, (size_t*)0x938));
  }
  /** // doc: test__get_program_build_info__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__invalid_device( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__get_program_build_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__invalid_value( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_program_build_info__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__invalid_program( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__get_program_build_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__out_of_resources( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_program_build_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__out_of_host_memory( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_program_build_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_build_info__unexpected_clerror( )
  {
    T::Dummy_clGetProgramBuildInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_PROGRAM_BUILD_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
