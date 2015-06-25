// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/create_sub_devices.t.h

/** // doc: clxx/functions/create_sub_devices.t.h {{{
 * \file clxx/functions/create_sub_devices.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_CREATE_SUB_DEVICES_T_H_INCLUDED
#define CLXX_FUNCTIONS_CREATE_SUB_DEVICES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_sub_devices_test_suite; }

/** // doc: class clxx::functions_create_sub_devices_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_sub_devices_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_sub_devices()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_sub_devices() {{{
   * \brief Test \ref create_sub_devices()() in normal situation.
   */ // }}}
  void test__create_sub_devices( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_sub_devices((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
#endif
  }
  /** // doc: test__create_sub_devices__invalid_device() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE
   */ // }}}
  void test__create_sub_devices__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device>);
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
  }
  /** // doc: test__create_sub_devices__invalid_value() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_VALUE
   */ // }}}
  void test__create_sub_devices__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
  }
  /** // doc: test__create_sub_devices__device_partition_failed() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_DEVICE_PARTITION_FAILED
   */ // }}}
  void test__create_sub_devices__device_partition_failed( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(CL_DEVICE_PARTITION_FAILED);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::device_partition_failed>);
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
  }
  /** // doc: test__create_sub_devices__invalid_device_partition_count() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE_PARTITION_COUNT
   */ // }}}
  void test__create_sub_devices__invalid_device_partition_count( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE_PARTITION_COUNT);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_partition_count>);
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
  }
  /** // doc: test__create_sub_devices__out_of_resources() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__create_sub_devices__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
  }
  /** // doc: test__create_sub_devices__out_of_host_memory() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__create_sub_devices__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
  }
  /** // doc: test__create_sub_devices__unexpected_clerror() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns unexpected error code
   */ // }}}
  void test__create_sub_devices__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
    T::Dummy_clCreateSubDevices mock(-0x12334567);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), unexpected_clerror);
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
  }
};

#endif /* CLXX_FUNCTIONS_CREATE_SUB_DEVICES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
