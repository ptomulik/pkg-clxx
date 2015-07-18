// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_device_ids.t.h

/** // doc: clxx/cl/functions/get_device_ids.t.h {{{
 * \file clxx/cl/functions/get_device_ids.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_DEVICE_IDS_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_DEVICE_IDS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_device_ids_test_suite; }

/** // doc: class clxx::functions_get_device_ids_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_device_ids_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  get_device_ids()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_device_ids() {{{
   * \brief Test get_device_ids()
   */ // }}}
  void test__get_device_ids( )
  {
    T::Dummy_clGetDeviceIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, CL_DEVICE_TYPE_ALL, 0, nullptr, nullptr));
  }
  /** // doc: test__get_device_ids__invalid_platform() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_PLATFORM
   */ // }}}
  void test__get_device_ids__invalid_platform()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__get_device_ids__invalid_device_type() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_DEVICE_TYPE
   */ // }}}
  void test__get_device_ids__invalid_device_type()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test__get_device_ids__invalid_value() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_device_ids__invalid_value()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_device_ids__device_not_found() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_DEVICE_NOT_FOUND
   */ // }}}
  void test__get_device_ids__device_not_found()
  {
    T::Dummy_clGetDeviceIDs mock(CL_DEVICE_NOT_FOUND);
    //TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::device_not_found>);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
  }
  /** // doc: test__get_device_ids__out_of_resources() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_device_ids__out_of_resources()
  {
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_device_ids__out_of_host_memory() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_device_ids__out_of_host_memory()
  {
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_device_ids__other_error() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns an unexpected error code
   */ // }}}
  void test__get_device_ids__other_error()
  {
    T::Dummy_clGetDeviceIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_DEVICE_IDS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
