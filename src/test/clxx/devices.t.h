// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/devices.t.h

/** // doc: clxx/devices.t.h {{{
 * \file clxx/devices.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_DEVICES_T_H_INCLUDED
#define CLXX_CL_DEVICES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/devices.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class devices_test__suite; }

/** // doc: class clxx::devices_test__suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::devices_test__suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__get_num_devices() {{{
   * \brief Test get_num_devices()
   */ // }}}
  void test__get_num_devices( )
  {
    cl_device_id _devices[] = { (cl_device_id)0x1234, (cl_device_id)0x5678 };
    cl_uint _num_devices = 2u;
    T::Dummy_clGetDeviceIDs mock(CL_SUCCESS, _devices, &_num_devices);
    TS_ASSERT_EQUALS(get_num_devices((cl_platform_id)0x4321, device_type_t::cpu), 2);
    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_TYPE_CPU);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), 0);
    TS_ASSERT(std::get<3>(mock.calls().back()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) != nullptr);
  }
  /** // doc: test__get_device_ids() {{{
   * \brief Test get_device_ids()
   */ // }}}
  void test__get_device_ids( )
  {
    cl_device_id _devices[] = { (cl_device_id)0x1234, (cl_device_id)0x5678 };
    cl_uint _num_devices = 2u;
    T::Dummy_clGetDeviceIDs mock(CL_SUCCESS, _devices, &_num_devices);
    std::vector<cl_device_id> devices(get_device_ids((cl_platform_id)0x4321, device_type_t::all));
    TS_ASSERT(mock.called_twice());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_platform_id)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_TYPE_ALL);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_TYPE_ALL);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);

    TS_ASSERT_EQUALS(devices.size(), 2u);
    TS_ASSERT_EQUALS(devices[0], _devices[0]);
    TS_ASSERT_EQUALS(devices[1], _devices[1]);
  }
  /** // doc: test__get_devices() {{{
   * \brief Test get_devices()
   */ // }}}
  void test__get_devices( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_id _devices[] = { (cl_device_id)0x1234, (cl_device_id)0x5678 };
    cl_uint _num_devices = 2u;
    T::Dummy_clGetDeviceIDs mock(CL_SUCCESS, _devices, &_num_devices);
    devices devices(get_devices((cl_platform_id)0x4321, device_type_t::all));

    TS_ASSERT(mock.called_twice());

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_platform_id)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_TYPE_ALL);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_TYPE_ALL);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);

    TS_ASSERT_EQUALS(devices.size(), 2u);
    TS_ASSERT_EQUALS(static_cast<device>(devices[0]).handle(), _devices[0]);
    TS_ASSERT_EQUALS(static_cast<device>(devices[1]).handle(), _devices[1]);
  }
  /** // doc: test__invalid_platform() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_PLATFORM.
   */ // }}}
  void test__invalid_platform( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_platform>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_platform>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__invalid_device_type() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test__invalid_device_type( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test__invalid_value() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_INVALID_VALUE.
   */ // }}}
  void test__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__device_not_found() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_DEVICE_NOT_FOUND.
   */ // }}}
  void test__device_not_found( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_DEVICE_NOT_FOUND);
    TS_ASSERT_THROWS_NOTHING(get_num_devices(NULL,static_cast<device_type_t>(0)))
    TS_ASSERT_THROWS_NOTHING(get_device_ids(NULL,static_cast<device_type_t>(0)))
    TS_ASSERT_THROWS_NOTHING(get_devices(NULL,static_cast<device_type_t>(0)))
    TS_ASSERT_THROWS_NOTHING(get_devices(platform(NULL),static_cast<device_type_t>(0)))
  }
  /** // doc: test__out_of_resources() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__out_of_host_memory() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__other_error() {{{
   * \brief Test get_xxx() functions in a situation when clGetDeviceIDs returns
   *        unknown error code.
   */ // }}}
  void test__other_error( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_num_devices(NULL,static_cast<device_type_t>(0)),unexpected_clerror);
    TS_ASSERT_THROWS(get_device_ids(NULL,static_cast<device_type_t>(0)),unexpected_clerror);
    TS_ASSERT_THROWS(get_devices(NULL,static_cast<device_type_t>(0)),unexpected_clerror);
    TS_ASSERT_THROWS(get_devices(platform(NULL),static_cast<device_type_t>(0)),unexpected_clerror);
  }
};

#endif /* CLXX_CL_DEVICES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
