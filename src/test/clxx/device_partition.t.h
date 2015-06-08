// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_partition.t.h

/** // doc: clxx/device_partition.t.h {{{
 * \file clxx/device_partition.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_T_H_INCLUDED
#define CLXX_DEVICE_PARTITION_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/device_partition.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class device_partition_test_suite; }

/** // doc: class clxx::device_partition_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::device_partition_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_get_num_sub_devices_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_num_sub_devices_1( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_num_sub_devices(device((cl_device_id)0x1234),device_partition_properties()));
    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()),0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().back()),nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) != nullptr);
#endif
  }
  /** // doc: test_create_sub_devices_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_create_sub_devices_1( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(create_sub_devices(device((cl_device_id)0x1234), make_device_partition_properties(device_partition_equally(2))));

    TS_ASSERT(mock.called_once());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().front()), nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
#endif
  }
  /** // doc: test_create_sub_devices_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_create_sub_devices_2( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    cl_device_id const out_devices[] = { (cl_device_id)0x2345, (cl_device_id)0x3456 };
    cl_uint const num_devices_ret = 2;
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS, out_devices, &num_devices_ret);

    devices devs(create_sub_devices(device((cl_device_id)0x1234), make_device_partition_properties(device_partition_equally(2))));

    TS_ASSERT(mock.called_twice());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT_EQUALS(std::get<3>(mock.calls().front()), nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()),(cl_device_id)0x1234);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock.calls().back()), nullptr);

    TS_ASSERT_EQUALS(devs.size(),2);
    TS_ASSERT_EQUALS(devs[0].id(), (cl_device_id)0x2345);
    TS_ASSERT_EQUALS(devs[1].id(), (cl_device_id)0x3456);
#endif
  }
};

#endif /* CLXX_DEVICE_PARTITION_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
