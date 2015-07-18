// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device.t.h

/** // doc: clxx/device.t.h {{{
 * \file clxx/device.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_DEVICE_T_H_INCLUDED
#define CLXX_CL_DEVICE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/device.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>
#include <cstring>

namespace clxx { class device_test__suite; }

/** // doc: class clxx::device_test__suite {{{
 * \brief Unit tests for clxx::device class
 */ // }}}
class clxx::device_test__suite : public CxxTest::TestSuite
{
public:
//  /** // doc: test__ctor_default() {{{
//   * \brief Ensure that id() == NULL by default.
//   */ // }}}
  void test__ctor_default( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    TS_ASSERT_EQUALS(device().get(), (cl_device_id)NULL);
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    TS_ASSERT(mockRetainDevice.never_called());
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    TS_ASSERT(mockReleaseDevice.never_called());
#endif
  }
//  /** // doc: test__ctor_assign() {{{
//   * \brief Ensure that assigining constructor works as expected.
//   */ // }}}
  void test__ctor_assign( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    {
      device d1((cl_device_id)0x1234ul);
      TS_ASSERT_EQUALS(d1.get(), (cl_device_id)0x1234ul);
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//      TS_ASSERT(mockRetainDevice.called_once_with((cl_device_id)0x1234ul));
//#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
      TS_ASSERT(mockReleaseDevice.never_called());
#endif
    }
//#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
//    TS_ASSERT(mockReleaseDevice.called_once_with((cl_device_id)0x1234ul));
//#endif
  }
//  /** // doc: test__ctor_copy() {{{
//   * \brief Ensure that copy constructor works as expected.
//   */ // }}}
  void test__ctor_copy( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    {
      device d1((cl_device_id)0x1234ul);
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//      TS_ASSERT(mockRetainDevice.called_once_with((cl_device_id)0x1234ul));
//#endif
      device d2(d1);
      TS_ASSERT_EQUALS(d2.get(), d1.get());
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//      TS_ASSERT(mockRetainDevice.called_twice());
//      TS_ASSERT_EQUALS(std::get<0>(mockRetainDevice.calls().front()), (cl_device_id)0x1234ul);
//      TS_ASSERT_EQUALS(std::get<0>(mockRetainDevice.calls().back()), (cl_device_id)0x1234ul);
//#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
      TS_ASSERT(mockReleaseDevice.never_called());
#endif
    }
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//    TS_ASSERT(mockReleaseDevice.called_twice());
//    TS_ASSERT_EQUALS(std::get<0>(mockReleaseDevice.calls().front()), (cl_device_id)0x1234ul);
//    TS_ASSERT_EQUALS(std::get<0>(mockReleaseDevice.calls().back()), (cl_device_id)0x1234ul);
//#endif
  }
//  /** // doc: test__op_assign() {{{
//   * \brief Ensure that assignment operator works.
//   */ // }}}
  void test__op_assign( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    {
      device d1((cl_device_id)0x1234ul);
      device d2;
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//      TS_ASSERT(mockRetainDevice.called_once_with((cl_device_id)0x1234ul));
//#endif
      TS_ASSERT_EQUALS(&(d2 = d1), &d2);
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//      TS_ASSERT(mockRetainDevice.called_twice());
//      TS_ASSERT_EQUALS(std::get<0>(mockRetainDevice.calls().front()), (cl_device_id)0x1234ul);
//      TS_ASSERT_EQUALS(std::get<0>(mockRetainDevice.calls().back()), (cl_device_id)0x1234ul);
//#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
      TS_ASSERT(mockReleaseDevice.never_called());
#endif
      TS_ASSERT_EQUALS(d2.get(), d1.get());
    }
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//    TS_ASSERT(mockReleaseDevice.called_twice());
//    TS_ASSERT_EQUALS(std::get<0>(mockReleaseDevice.calls().front()), (cl_device_id)0x1234ul);
//    TS_ASSERT_EQUALS(std::get<0>(mockReleaseDevice.calls().back()), (cl_device_id)0x1234ul);
//#endif
  }
  /** // doc: test__assign() {{{
   * \brief Ensure that assign() method works.
   */ // }}}
  void test__assign( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    {
      device d1((cl_device_id)0x1234ul);
      device d2;
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//      TS_ASSERT(mockRetainDevice.called_once_with((cl_device_id)0x1234ul));
//#endif
      d2.assign(d1);
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//      TS_ASSERT(mockRetainDevice.called_twice());
//      TS_ASSERT_EQUALS(std::get<0>(mockRetainDevice.calls().front()), (cl_device_id)0x1234ul);
//      TS_ASSERT_EQUALS(std::get<0>(mockRetainDevice.calls().back()), (cl_device_id)0x1234ul);
//#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
      TS_ASSERT(mockReleaseDevice.never_called());
#endif
      TS_ASSERT_EQUALS(d2.get(), d1.get());
    }
//#if CLXX_OPENCL_ALLOWED(clRetainDevice)
//    TS_ASSERT(mockReleaseDevice.called_twice());
//    TS_ASSERT_EQUALS(std::get<0>(mockReleaseDevice.calls().front()), (cl_device_id)0x1234ul);
//    TS_ASSERT_EQUALS(std::get<0>(mockReleaseDevice.calls().back()), (cl_device_id)0x1234ul);
//#endif
  }
  /** // doc: test__is_initialized_1() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test__is_initialized_1( )
  {
    device d;
    TS_ASSERT(!d.is_initialized());
  }
  /** // doc: test__is_initialized_2() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test__is_initialized_2( )
  {
    device d((cl_device_id)NULL);
    TS_ASSERT(!d.is_initialized());
  }
  /** // doc: test__is_initialized_3() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test__is_initialized_3( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    device d((cl_device_id)0x1234ul);
    TS_ASSERT(d.is_initialized());
  }
  /** // doc: test__handle_1() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test__handle_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    device d((cl_device_id)NULL);
    TS_ASSERT_EQUALS(d.get(),(cl_device_id)NULL);
  }
  /** // doc: test__handle_2() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test__handle_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    device d((cl_device_id)0x1234ul);
    TS_ASSERT_EQUALS(d.get(),(cl_device_id)0x1234ul);
  }
  /** // doc: test__chk_get_1() {{{
   * \brief Ensure that chk_get() method works.
   */ // }}}
  void test__chk_get_1( )
  {
    device d((cl_device_id)NULL);
    TS_ASSERT_THROWS(d.chk_get(), uninitialized_device_error);
  }
  /** // doc: test__chk_get_2() {{{
   * \brief Ensure that chk_get() method works.
   */ // }}}
  void test__chk_get_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    device d((cl_device_id)0x1234ul);
    TS_ASSERT_EQUALS(d.chk_get(),(cl_device_id)0x1234ul);
  }
  /** // doc: test__get_info__1() {{{
   * \brief Test device::get_info().
   */ // }}}
  void test__get_info__1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_type _type = CL_DEVICE_TYPE_GPU;
    size_t _type_size = sizeof(_type);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_type, &_type_size);
    device d((cl_device_id)0x1234);
    size_t size;
    d.get_info(device_info_t::type, 0, nullptr, &size);

    TS_ASSERT_EQUALS(size, sizeof(device_type_t));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), 0u);
    TS_ASSERT(std::get<3>(mock.calls().back()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == &size);
  }
  /** // doc: test__get_info__2() {{{
   * \brief Test device::get_info().
   */ // }}}
  void test__get_info__2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_type _type = CL_DEVICE_TYPE_GPU;
    size_t _type_size = sizeof(_type);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_type, &_type_size);
    device d((cl_device_id)0x1234);
    device_type_t type;
    size_t size;
    d.get_info(device_info_t::type, sizeof(type), &type, &size);

    TS_ASSERT_EQUALS(type, device_type_t::gpu);
    TS_ASSERT_EQUALS(size, sizeof(device_type_t));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(type));
    TS_ASSERT(std::get<3>(mock.calls().back()) == &type);
    TS_ASSERT(std::get<4>(mock.calls().back()) == &size);
  }
  /** // doc: test__get_info__invalid_device() {{{
   * \brief Test device::get_info()
   */ // }}}
  void test__get_info__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_DEVICE);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_info(device_info_t::profile, 0, NULL, NULL), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__get_info__invalid_value() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test__get_info__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_VALUE);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_info(device_info_t::profile, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_info__out_of_resources() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test__get_info__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_RESOURCES);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_info(device_info_t::profile, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_info__out_of_host_memory() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test__get_info__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_HOST_MEMORY);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_info(device_info_t::profile, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_info__unexpected_clerror() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test__get_info__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock((cl_int)-0x1234567);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_info(device_info_t::profile, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test__get_type() {{{
   * \brief Test get_type()
   */ // }}}
  void test__get_type()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_type _value = CL_DEVICE_TYPE_GPU;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_type(), device_type_t::gpu);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(device_type_t));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_vendor_id() {{{
   * \brief Test get_vendor_id()
   */ // }}}
  void test__get_vendor_id()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif

    cl_uint _value = 0x102;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_vendor_id(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_VENDOR_ID);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_compute_units() {{{
   * \brief Test get_max_compute_units()
   */ // }}}
  void test__get_max_compute_units()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif

    cl_uint _value = 16u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_compute_units(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_COMPUTE_UNITS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_work_item_dimensions() {{{
   * \brief Test get_max_work_item_dimensions()
   */ // }}}
  void test__get_max_work_item_dimensions()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif

    cl_uint _value = 3u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_work_item_dimensions(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_work_item_sizes() {{{
   * \brief Test get_max_work_item_sizes()
   */ // }}}
  void test__get_max_work_item_sizes()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value[] = { 512ul, 512ul, 64ul }; 
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_work_item_sizes(),
                     std::vector<size_t>(_value, _value+3ul));

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_MAX_WORK_ITEM_SIZES);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_WORK_ITEM_SIZES);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_work_group_size() {{{
   * \brief Test get_max_work_group_size()
   */ // }}}
  void test__get_max_work_group_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 1024u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_work_group_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_preferred_vector_width_char() {{{
   * \brief Test get_preferred_vector_width_char()
   */ // }}}
  void test__get_preferred_vector_width_char()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_vector_width_char(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_preferred_vector_width_short() {{{
   * \brief Test get_preferred_vector_width_short()
   */ // }}}
  void test__get_preferred_vector_width_short()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_vector_width_short(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_preferred_vector_width_int_1() {{{
   * \brief Test get_preferred_vector_width_int()
   */ // }}}
  void test__get_preferred_vector_width_int_1()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_vector_width_int(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_preferred_vector_width_long() {{{
   * \brief Test get_preferred_vector_width_long()
   */ // }}}
  void test__get_preferred_vector_width_long()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_vector_width_long(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_preferred_vector_width_float() {{{
   * \brief Test get_preferred_vector_width_float()
   */ // }}}
  void test__get_preferred_vector_width_float()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_vector_width_float(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_preferred_vector_width_double() {{{
   * \brief Test get_preferred_vector_width_double()
   */ // }}}
  void test__get_preferred_vector_width_double()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_vector_width_double(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_clock_frequency() {{{
   * \brief Test get_max_clock_frequency()
   */ // }}}
  void test__get_max_clock_frequency()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1000000000ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_clock_frequency(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_CLOCK_FREQUENCY);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_address_bits() {{{
   * \brief Test get_address_bits()
   */ // }}}
  void test__get_address_bits()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 32u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_address_bits(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_ADDRESS_BITS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_mem_alloc_size() {{{
   * \brief Test get_max_mem_alloc_size()
   */ // }}}
  void test__get_max_mem_alloc_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_ulong _value = 4214191104ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_mem_alloc_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_MEM_ALLOC_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_image_support() {{{
   * \brief Test get_image_support()
   */ // }}}
  void test__get_image_support()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_TRUE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image_support(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE_SUPPORT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_read_image_args() {{{
   * \brief Test get_max_read_image_args()
   */ // }}}
  void test__get_max_read_image_args()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 128u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_read_image_args(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_READ_IMAGE_ARGS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_write_image_args() {{{
   * \brief Test get_max_write_image_args()
   */ // }}}
  void test__get_max_write_image_args()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 8u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_write_image_args(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_WRITE_IMAGE_ARGS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_image2d_max_width() {{{
   * \brief Test get_image2d_max_width()
   */ // }}}
  void test__get_image2d_max_width()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 8192ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image2d_max_width(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE2D_MAX_WIDTH);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_image2d_max_height() {{{
   * \brief Test get_image2d_max_height()
   */ // }}}
  void test__get_image2d_max_height()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 8192ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image2d_max_height(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE2D_MAX_HEIGHT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_image3d_max_width() {{{
   * \brief Test get_image3d_max_width()
   */ // }}}
  void test__get_image3d_max_width()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 2048ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image3d_max_width(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE3D_MAX_WIDTH);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_image3d_max_height() {{{
   * \brief Test get_image3d_max_height()
   */ // }}}
  void test__get_image3d_max_height()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 2048ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image3d_max_height(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE3D_MAX_HEIGHT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_image3d_max_depth() {{{
   * \brief Test get_image3d_max_depth()
   */ // }}}
  void test__get_image3d_max_depth()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 2048ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image3d_max_depth(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE3D_MAX_DEPTH);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_samplers() {{{
   * \brief Test get_max_samplers()
   */ // }}}
  void test__get_max_samplers()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 16u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_samplers(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_SAMPLERS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_parameter_size() {{{
   * \brief Test get_max_parameter_size()
   */ // }}}
  void test__get_max_parameter_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 4096ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_parameter_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_PARAMETER_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_mem_base_addr_align() {{{
   * \brief Test get_mem_base_addr_align()
   */ // }}}
  void test__get_mem_base_addr_align()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 1024u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_mem_base_addr_align(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MEM_BASE_ADDR_ALIGN);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_min_data_type_align_size() {{{
   * \brief Test get_min_data_type_align_size()
   */ // }}}
  void test__get_min_data_type_align_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 128u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_min_data_type_align_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_single_fp_config() {{{
   * \brief Test get_single_fp_config()
   */ // }}}
  void test__get_single_fp_config()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_fp_config _value = CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_FMA;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_single_fp_config(), static_cast<device_fp_config_t>(_value));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_SINGLE_FP_CONFIG);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_global_mem_cache_type() {{{
   * \brief Test get_global_mem_cache_type()
   */ // }}}
  void test__get_global_mem_cache_type()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_mem_cache_type _value = CL_READ_WRITE_CACHE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_global_mem_cache_type(), static_cast<device_mem_cache_type_t>(_value));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_GLOBAL_MEM_CACHE_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_global_mem_cacheline_size() {{{
   * \brief Test get_global_mem_cacheline_size()
   */ // }}}
  void test__get_global_mem_cacheline_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 64;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_global_mem_cacheline_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_global_mem_cache_size() {{{
   * \brief Test get_global_mem_cache_size()
   */ // }}}
  void test__get_global_mem_cache_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_ulong _value = 32768ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_global_mem_cache_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_GLOBAL_MEM_CACHE_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_global_mem_size() {{{
   * \brief Test get_global_mem_size()
   */ // }}}
  void test__get_global_mem_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_ulong _value = 16856764416ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_global_mem_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_GLOBAL_MEM_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_constant_buffer_size_1() {{{
   * \brief Test get_max_constant_buffer_size()
   */ // }}}
  void test__get_max_constant_buffer_size_1()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_ulong _value = 65536ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_constant_buffer_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_max_constant_args() {{{
   * \brief Test get_max_constant_args()
   */ // }}}
  void test__get_max_constant_args()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 8u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_max_constant_args(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_MAX_CONSTANT_ARGS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_local_mem_type() {{{
   * \brief Test get_local_mem_type()
   */ // }}}
  void test__get_local_mem_type()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_local_mem_type _value = CL_GLOBAL;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_local_mem_type(), static_cast<device_local_mem_type_t>(_value));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_LOCAL_MEM_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_local_mem_size() {{{
   * \brief Test get_local_mem_size()
   */ // }}}
  void test__get_local_mem_size()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_ulong _value = 32768ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_local_mem_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_LOCAL_MEM_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_error_correction_support() {{{
   * \brief Test get_error_correction_support()
   */ // }}}
  void test__get_error_correction_support()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_FALSE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_error_correction_support(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_ERROR_CORRECTION_SUPPORT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_profiling_timer_resolution() {{{
   * \brief Test get_profiling_timer_resolution()
   */ // }}}
  void test__get_profiling_timer_resolution()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 1000ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_profiling_timer_resolution(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PROFILING_TIMER_RESOLUTION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_endian_little() {{{
   * \brief Test get_endian_little()
   */ // }}}
  void test__get_endian_little()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_TRUE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_endian_little(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_ENDIAN_LITTLE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_available() {{{
   * \brief Test get_available()
   */ // }}}
  void test__get_available()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_TRUE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_available(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_AVAILABLE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_compiler_available() {{{
   * \brief Test get_compiler_available()
   */ // }}}
  void test__get_compiler_available()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_TRUE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_compiler_available(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_COMPILER_AVAILABLE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_execution_capabilities() {{{
   * \brief Test get_execution_capabilities()
   */ // }}}
  void test__get_execution_capabilities()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_exec_capabilities _value = CL_EXEC_KERNEL | CL_EXEC_NATIVE_KERNEL;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_execution_capabilities(), static_cast<device_exec_capabilities_t>(_value));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_EXECUTION_CAPABILITIES);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_queue_properties() {{{
   * \brief Test get_queue_properties()
   */ // }}}
  void test__get_queue_properties()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_command_queue_properties _value = CL_QUEUE_PROFILING_ENABLE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_queue_properties(), static_cast<command_queue_properties_t>(_value));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_QUEUE_PROPERTIES);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_platform_id() {{{
   * \brief Test get_platform_id()
   */ // }}}
  void test__get_platform_id()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_platform_id _value = (cl_platform_id)0x5678;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_platform_id(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PLATFORM);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_name() {{{
   * \brief Test get_name()
   */ // }}}
  void test__get_name()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "Intel(R) Xeon(R) CPU E5620 @ 2.40GHz";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_name(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_NAME);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NAME);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_vendor() {{{
   * \brief Test get_vendor()
   */ // }}}
  void test__get_vendor()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "GenuineIntel";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_vendor(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_VENDOR);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_VENDOR);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_driver_version() {{{
   * \brief Test get_driver_version()
   */ // }}}
  void test__get_driver_version()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "1348.4 (sse2)";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_driver_version(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DRIVER_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DRIVER_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_profile() {{{
   * \brief Test get_profile()
   */ // }}}
  void test__get_profile()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "FULL_PROFILE";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_profile(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_PROFILE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PROFILE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_version() {{{
   * \brief Test get_version()
   */ // }}}
  void test__get_version()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "OpenCL 1.2 AMD-APP (1348.4)";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_version(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_extensions() {{{
   * \brief Test get_extensions()
   */ // }}}
  void test__get_extensions()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "cl_khr_fp64 cl_amd_fp64 cl_khr_global_int32_base_atomics";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_extensions(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_EXTENSIONS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_EXTENSIONS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
  /** // doc: test__get_double_fp_config() {{{
   * \brief Test get_double_fp_config()
   */ // }}}
  void test__get_double_fp_config()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_fp_config _value = CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_FMA;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_double_fp_config(), static_cast<device_fp_config_t>(_value));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_DOUBLE_FP_CONFIG);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_preferred_vector_width_half() {{{
   * \brief Test get_preferred_vector_width_half()
   */ // }}}
  void test__get_preferred_vector_width_half()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 2u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_vector_width_half(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_host_unified_memory_1() {{{
   * \brief Test get_host_unified_memory()
   */ // }}}
  void test__get_host_unified_memory_1()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_TRUE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_host_unified_memory(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_HOST_UNIFIED_MEMORY);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_native_vector_width_char_1() {{{
   * \brief Test get_native_vector_width_char()
   */ // }}}
  void test__get_native_vector_width_char_1()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 16u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_native_vector_width_char(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_native_vector_width_short() {{{
   * \brief Test get_native_vector_width_short()
   */ // }}}
  void test__get_native_vector_width_short()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 8u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_native_vector_width_short(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_native_vector_width_int() {{{
   * \brief Test get_native_vector_width_int()
   */ // }}}
  void test__get_native_vector_width_int()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 4u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_native_vector_width_int(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NATIVE_VECTOR_WIDTH_INT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_native_vector_width_long() {{{
   * \brief Test get_native_vector_width_long()
   */ // }}}
  void test__get_native_vector_width_long()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 2u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_native_vector_width_long(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_native_vector_width_float() {{{
   * \brief Test get_native_vector_width_float()
   */ // }}}
  void test__get_native_vector_width_float()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 4u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_native_vector_width_float(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_native_vector_width_double() {{{
   * \brief Test get_native_vector_width_double()
   */ // }}}
  void test__get_native_vector_width_double()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 2u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_native_vector_width_double(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_native_vector_width_half() {{{
   * \brief Test get_native_vector_width_half()
   */ // }}}
  void test__get_native_vector_width_half()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 2u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_native_vector_width_half(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_opencl_c_version() {{{
   * \brief Test get_opencl_c_version()
   */ // }}}
  void test__get_opencl_c_version()
  {
#if CLXX_CL_H_VERSION_1_1
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "OpenCL C 1.2";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_opencl_c_version(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_OPENCL_C_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_OPENCL_C_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_linker_available() {{{
   * \brief Test get_linker_available()
   */ // }}}
  void test__get_linker_available()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_TRUE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_linker_available(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_LINKER_AVAILABLE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_built_in_kernels() {{{
   * \brief Test get_built_in_kernels()
   */ // }}}
  void test__get_built_in_kernels()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    const char* _value = "kernel1 kernel2";
    size_t _value_size = std::strlen(_value) + 1;
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_built_in_kernels(), _value);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_BUILT_IN_KERNELS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_BUILT_IN_KERNELS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _value_size);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_image_max_buffer_size() {{{
   * \brief Test get_image_max_buffer_size()
   */ // }}}
  void test__get_image_max_buffer_size()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 65536ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image_max_buffer_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE_MAX_BUFFER_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_image_max_array_size() {{{
   * \brief Test get_image_max_array_size()
   */ // }}}
  void test__get_image_max_array_size()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 2048ul;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image_max_array_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE_MAX_ARRAY_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_parent_device_id() {{{
   * \brief Test get_parent_device_id()
   */ // }}}
  void test__get_parent_device_id()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_id _value = (cl_device_id)0x5678;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_parent_device_id(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PARENT_DEVICE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_partition_max_sub_devices() {{{
   * \brief Test get_partition_max_sub_devices()
   */ // }}}
  void test__get_partition_max_sub_devices()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 16u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_partition_max_sub_devices(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PARTITION_MAX_SUB_DEVICES);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_partition_properties() {{{
   * \brief Test get_partition_properties()
   */ // }}}
  void test__get_partition_properties()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    device_partition_property_t const _props[3] = {
      device_partition_property_t::equally,
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };

    cl_device_partition_property _value[] = { CL_DEVICE_PARTITION_EQUALLY,
                                              CL_DEVICE_PARTITION_BY_COUNTS,
                                              CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN }; 
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_partition_properties(),
                     std::vector<device_partition_property_t>(_props, _props+3ul));

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_PARTITION_PROPERTIES);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PARTITION_PROPERTIES);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_partition_affinity_domain() {{{
   * \brief Test get_partition_affinity_domain()
   */ // }}}
  void test__get_partition_affinity_domain()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_device_affinity_domain _value = CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE |
                                       CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE |
                                       CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE |
                                       CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE;

    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_partition_affinity_domain(), static_cast<device_affinity_domain_t>(_value));

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PARTITION_AFFINITY_DOMAIN);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_partition_type() {{{
   * \brief Test get_partition_type()
   */ // }}}
  void test__get_partition_type()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    device_partition_property_t const _props[] = {
      device_partition_property_t::equally,
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain,
      static_cast<device_partition_property_t>(0)
    };

    cl_device_partition_property _value[] = { CL_DEVICE_PARTITION_EQUALLY,
                                              CL_DEVICE_PARTITION_BY_COUNTS,
                                              CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN,
                                              0}; 
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, _value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_partition_type(),
                     std::vector<device_partition_property_t>(_props, _props+4ul));

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_DEVICE_PARTITION_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0ul);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PARTITION_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_reference_count() {{{
   * \brief Test get_reference_count()
   */ // }}}
  void test__get_reference_count()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 3u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_reference_count(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_preferred_interop_user_sync() {{{
   * \brief Test get_preferred_interop_user_sync()
   */ // }}}
  void test__get_preferred_interop_user_sync()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_bool _value = CL_TRUE;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_preferred_interop_user_sync(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PREFERRED_INTEROP_USER_SYNC);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_printf_buffer_size() {{{
   * \brief Test get_printf_buffer_size()
   */ // }}}
  void test__get_printf_buffer_size()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    size_t _value = 65536u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_printf_buffer_size(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_PRINTF_BUFFER_SIZE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_image_pitch_alignment() {{{
   * \brief Test get_image_pitch_alignment()
   */ // }}}
  void test__get_image_pitch_alignment()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 32u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image_pitch_alignment(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE_PITCH_ALIGNMENT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__get_image_base_address_alignment() {{{
   * \brief Test get_image_base_address_alignment()
   */ // }}}
  void test__get_image_base_address_alignment()
  {
#if CLXX_CL_H_VERSION_1_2
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    cl_uint _value = 32u;
    size_t _value_size = sizeof(_value);
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS, &_value, &_value_size);

    TS_ASSERT_EQUALS(device((cl_device_id)0x1234).get_image_base_address_alignment(), _value);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), sizeof(_value));
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
#endif
  }
  /** // doc: test__out_of_resources() {{{
   * \brief Test get_xxx() methods in a situation when clGetDeviceInfo returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_RESOURCES);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_type(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_vendor_id(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_compute_units(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_work_item_dimensions(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_work_group_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_work_item_sizes(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_char(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_short(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_int(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_long(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_float(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_double(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_clock_frequency(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_address_bits(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_read_image_args(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_write_image_args(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_mem_alloc_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image2d_max_width(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image2d_max_height(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image3d_max_width(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image3d_max_height(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image3d_max_depth(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image_support(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_max_parameter_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_mem_base_addr_align(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_min_data_type_align_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_single_fp_config(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_global_mem_cache_type(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_global_mem_cacheline_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_global_mem_cache_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_global_mem_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_error_correction_support(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_profiling_timer_resolution(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_endian_little(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_available(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_compiler_available(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_execution_capabilities(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_queue_properties(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_name(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_vendor(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_driver_version(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_profile(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_version(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_extensions(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_platform_id(), clerror_no<status_t::out_of_resources>);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_THROWS(d.get_double_fp_config(), clerror_no<status_t::out_of_resources>);
#endif
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_THROWS(d.get_preferred_vector_width_half(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_host_unified_memory(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_native_vector_width_char(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_native_vector_width_short(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_native_vector_width_int(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_native_vector_width_long(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_native_vector_width_float(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_native_vector_width_double(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_native_vector_width_half(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_opencl_c_version(), clerror_no<status_t::out_of_resources>);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_THROWS(d.get_linker_available(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_built_in_kernels(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image_max_buffer_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image_max_array_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_parent_device_id(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_partition_max_sub_devices(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_partition_properties(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_partition_affinity_domain(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_partition_type(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_reference_count(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_preferred_interop_user_sync(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_printf_buffer_size(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image_pitch_alignment(), clerror_no<status_t::out_of_resources>);
    TS_ASSERT_THROWS(d.get_image_base_address_alignment(), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__out_of_host_memory() {{{
   * \brief Test get_xxx() methods in a situation when clGetDeviceInfo returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_HOST_MEMORY);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_type(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_vendor_id(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_compute_units(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_work_item_dimensions(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_work_group_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_work_item_sizes(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_char(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_short(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_int(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_long(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_float(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_double(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_clock_frequency(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_address_bits(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_read_image_args(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_write_image_args(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_mem_alloc_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image2d_max_width(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image2d_max_height(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image3d_max_width(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image3d_max_height(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image3d_max_depth(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image_support(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_max_parameter_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_mem_base_addr_align(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_min_data_type_align_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_single_fp_config(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_global_mem_cache_type(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_global_mem_cacheline_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_global_mem_cache_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_global_mem_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_error_correction_support(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_profiling_timer_resolution(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_endian_little(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_available(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_compiler_available(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_execution_capabilities(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_queue_properties(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_name(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_vendor(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_driver_version(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_profile(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_version(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_extensions(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_platform_id(), clerror_no<status_t::out_of_host_memory>);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_THROWS(d.get_double_fp_config(), clerror_no<status_t::out_of_host_memory>);
#endif
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_THROWS(d.get_preferred_vector_width_half(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_host_unified_memory(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_native_vector_width_char(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_native_vector_width_short(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_native_vector_width_int(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_native_vector_width_long(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_native_vector_width_float(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_native_vector_width_double(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_native_vector_width_half(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_opencl_c_version(), clerror_no<status_t::out_of_host_memory>);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_THROWS(d.get_linker_available(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_built_in_kernels(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image_max_buffer_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image_max_array_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_parent_device_id(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_partition_max_sub_devices(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_partition_properties(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_partition_affinity_domain(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_partition_type(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_reference_count(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_preferred_interop_user_sync(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_printf_buffer_size(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image_pitch_alignment(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(d.get_image_base_address_alignment(), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__out_of_host_memory() {{{
   * \brief Test get_xxx() methods in a situation when clGetDeviceInfo returns unknown error.
   */ // }}}
  void test__other_error( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clGetDeviceInfo mock(-0x432534);
    device d((cl_device_id)0x34556ul);
    TS_ASSERT_THROWS(d.get_type(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_vendor_id(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_compute_units(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_work_item_dimensions(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_work_group_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_work_item_sizes(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_char(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_short(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_int(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_long(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_float(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_preferred_vector_width_double(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_clock_frequency(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_address_bits(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_read_image_args(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_write_image_args(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_mem_alloc_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image2d_max_width(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image2d_max_height(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image3d_max_width(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image3d_max_height(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image3d_max_depth(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image_support(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_max_parameter_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_mem_base_addr_align(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_min_data_type_align_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_single_fp_config(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_global_mem_cache_type(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_global_mem_cacheline_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_global_mem_cache_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_global_mem_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_error_correction_support(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_profiling_timer_resolution(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_endian_little(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_available(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_compiler_available(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_execution_capabilities(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_queue_properties(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_name(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_vendor(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_driver_version(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_profile(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_version(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_extensions(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_platform_id(), unexpected_clerror);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_THROWS(d.get_double_fp_config(), unexpected_clerror);
#endif
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_THROWS(d.get_preferred_vector_width_half(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_host_unified_memory(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_native_vector_width_char(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_native_vector_width_short(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_native_vector_width_int(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_native_vector_width_long(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_native_vector_width_float(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_native_vector_width_double(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_native_vector_width_half(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_opencl_c_version(), unexpected_clerror);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_THROWS(d.get_linker_available(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_built_in_kernels(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image_max_buffer_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image_max_array_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_parent_device_id(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_partition_max_sub_devices(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_partition_properties(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_partition_affinity_domain(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_partition_type(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_reference_count(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_preferred_interop_user_sync(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_printf_buffer_size(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image_pitch_alignment(), unexpected_clerror);
    TS_ASSERT_THROWS(d.get_image_base_address_alignment(), unexpected_clerror);
#endif
  }
  /** doc: test__query_device_info_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__query_device_info_1()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    clxx::device_info info(query_device_info(d));

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(info.id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[0]));
    TS_ASSERT_EQUALS(info.name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(info.vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(info.driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(info.profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(info.version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** doc: test__query_device_info_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__query_device_info_2()
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    clxx::device_info info(query_device_info(d));

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(info.id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[1]));
    TS_ASSERT_EQUALS(info.name(), "Tesla C1060");
    TS_ASSERT_EQUALS(info.vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(info.driver_version(), "319.76");
    TS_ASSERT_EQUALS(info.profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(info.version(), "OpenCL 1.0 CUDA");
  }
//  /** // doc: test__eq_op_1() {{{
//   * \brief Test operator==()
//   */ // }}}
  void test__eq_op_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    TS_ASSERT(  device((cl_device_id)0x0000) == device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x1234) == device((cl_device_id)0x1234));
    TS_ASSERT(!(device((cl_device_id)0x1234) == device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x0000) == device((cl_device_id)0x1234)));
  }
//  /** // doc: test__neq_op_1() {{{
//   * \brief Test operator!=()
//   */ // }}}
  void test__neq_op_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    TS_ASSERT(!(device((cl_device_id)0x0000) != device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x1234) != device((cl_device_id)0x1234)));
    TS_ASSERT(  device((cl_device_id)0x1234) != device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x0000) != device((cl_device_id)0x1234));
  }
//  /** // doc: test__lt_op_1() {{{
//   * \brief Test operator<
//   */ // }}}
  void test__lt_op_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    TS_ASSERT(!(device((cl_device_id)0x0000) < device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x1234) < device((cl_device_id)0x1234)));
    TS_ASSERT(!(device((cl_device_id)0x1234) < device((cl_device_id)0x0000)));
    TS_ASSERT(  device((cl_device_id)0x0000) < device((cl_device_id)0x1234));
  }
//  /** // doc: test__gt_op_1() {{{
//   * \brief Test operator>
//   */ // }}}
  void test__gt_op_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    TS_ASSERT(!(device((cl_device_id)0x0000) > device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x1234) > device((cl_device_id)0x1234)));
    TS_ASSERT(  device((cl_device_id)0x1234) > device((cl_device_id)0x0000));
    TS_ASSERT(!(device((cl_device_id)0x0000) > device((cl_device_id)0x1234)));
  }
//  /** // doc: test__le_op_1() {{{
//   * \brief Test operator<=
//   */ // }}}
  void test__le_op_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    TS_ASSERT(  device((cl_device_id)0x0000) <= device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x1234) <= device((cl_device_id)0x1234));
    TS_ASSERT(!(device((cl_device_id)0x1234) <= device((cl_device_id)0x0000)));
    TS_ASSERT(  device((cl_device_id)0x0000) <= device((cl_device_id)0x1234));
  }
//  /** // doc: test__ge_op_1() {{{
//   * \brief Test operator>=
//   */ // }}}
  void test__ge_op_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    TS_ASSERT(  device((cl_device_id)0x0000) >= device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x1234) >= device((cl_device_id)0x1234));
    TS_ASSERT(  device((cl_device_id)0x1234) >= device((cl_device_id)0x0000));
    TS_ASSERT(!(device((cl_device_id)0x0000) >= device((cl_device_id)0x1234)));
  }
};

#endif /* CLXX_CL_DEVICE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
