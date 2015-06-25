// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/get_platform_info.t.h

/** // doc: clxx/functions/get_platform_info.t.h {{{
 * \file clxx/functions/get_platform_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_GET_PLATFORM_INFO_T_H_INCLUDED
#define CLXX_FUNCTIONS_GET_PLATFORM_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_platform_info_test_suite; }

/** // doc: class clxx::functions_get_platform_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_platform_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_platform_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_platform_info() {{{
   * \brief Test get_platform_info()
   */ // }}}
  void test__get_platform_info( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, (cl_platform_info)0, 0, nullptr, nullptr));
  }
  /** // doc: test__get_platform_info__invalid_platform() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_PLATFORM
   */ // }}}
  void test__get_platform_info__invalid_platform( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__get_platform_info__invalid_value() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_platform_info__invalid_value( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_platform_info__out_of_host_memory() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_platform_info__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_platform_info__other_error() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_platform_info__other_error( )
  {
    T::Dummy_clGetPlatformInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_GET_PLATFORM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
