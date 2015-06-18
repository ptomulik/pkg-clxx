// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions.t.h

/** // doc: clxx/functions.t.h {{{
 * \file clxx/functions.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_T_H_INCLUDED
#define CLXX_FUNCTIONS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_test_suite; }

/** // doc: class clxx::functions_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__get_platform_ids__success() {{{
   * \brief Test get_platform_ids() in a normal situation
   */ // }}}
  void test__get_platform_ids__success( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_ids(0,nullptr,NULL));
    TS_ASSERT(mock.called_once_with(0,nullptr,NULL));
  }
  /** // doc: test__get_platform_ids__invalid_value() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_platform_ids__invalid_value( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_platform_ids__out_of_host_memory() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_platform_ids__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_platform_ids__other_error() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns unexpected error code.
   */ // }}}
  void test__get_platform_ids__other_error( )
  {
    T::Dummy_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), unexpected_clerror);
  }
  /** // doc: test__get_platform_info__success() {{{
   * \brief Test get_platform_info()
   */ // }}}
  void test__get_platform_info__success( )
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
  /** // doc: test__get_device_ids__success() {{{
   * \brief Test get_device_ids()
   */ // }}}
  void test__get_device_ids__success( )
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
  /** // doc: test__get_device_info__success() {{{
   * \brief Test get_device_info() in a normal situation
   */ // }}}
  void test__get_device_info__success()
  {
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_device_id)NULL, CL_DEVICE_VENDOR_ID, 0, nullptr, nullptr));
  }
  /** // doc: test__get_device_info__invalid_device() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_INVALID_DEVICE
   */ // }}}
  void test__get_device_info__invalid_device()
  {
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__get_device_info__invalid_value() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_device_info__invalid_value()
  {
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_device_info__out_of_resources() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_device_info__out_of_resources()
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_device_info__out_of_host_memory() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_device_info__out_of_host_memory()
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_device_info__other_error() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns an unexpected error code
   */ // }}}
  void test__get_device_info__other_error()
  {
    T::Dummy_clGetDeviceInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test__create_context__success() {{{
   * \brief Test create_context() in a normal situation.
   */ // }}}
  void test__create_context__success( )
  {
    T::Dummy_clCreateContext mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr));
    //TS_ASSERT(mock.called_once_with(nullptr,0,nullptr,nullptr,nullptr,??? - local variable within create_context(...){...}));
  }
  /** // doc: test__create_context__invalid_platform() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test__create_context__invalid_platform( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__create_context__invalid_property() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test__create_context__invalid_property( )
  {
#if CL_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_property>);
#endif
  }
  /** // doc: test__create_context__invalid_operation() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_OPERATION.
   */ // }}}
  void test__create_context__invalid_operation( )
  {
#if CL_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test__create_context__invalid_value() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_context__invalid_value( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_context__invalid_device() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_DEVICE.
   */ // }}}
  void test__create_context__invalid_device( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__create_context__device_not_available() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_context__device_not_available( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test__create_context__out_of_resources() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_context__out_of_resources( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_context__out_of_host_memory() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_context__out_of_host_memory( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_context__other_error() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns an unexpected error code.
   */ // }}}
  void test__create_context__other_error( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), unexpected_clerror);
  }
  /** // doc: test__create_context_from_type__success() {{{
   * \brief Test create_context_from_type().
   */ // }}}
  void test__create_context_from_type__success( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr));
  }
  /** // doc: test__create_context_from_type__invalid_platform() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test__create_context_from_type__invalid_platform( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__create_context_from_type__invalid_property() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test__create_context_from_type__invalid_property( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_property>);
  }
  /** // doc: test__create_context_from_type__invalid_value() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_context_from_type__invalid_value( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_context_from_type__invalid_device_type() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test__create_context_from_type__invalid_device_type( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test__create_context_from_type__device_not_available() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_context_from_type__device_not_available( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test__create_context_from_type__out_of_resources() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_context_from_type__out_of_resources( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_context_from_type__out_of_host_memory() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_context_from_type__out_of_host_memory( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_context_from_type__other_error() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns an unexpected error code.
   */ // }}}
  void test__create_context_from_type__other_error( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), unexpected_clerror);
  }
  /** // doc: test__retain_context__success() {{{
   * \brief Test retain_context() in a normal situation
   */ // }}}
  void test__retain_context__success( )
  {
    T::Dummy_clRetainContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test__retain_context__invalid_context() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__retain_context__invalid_context( )
  {
    T::Dummy_clRetainContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__retain_context__out_of_resources() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__retain_context__out_of_resources( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_context__out_of_host_memory() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__retain_context__out_of_host_memory( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_context__success() {{{
   * \brief Test release_context() in a normal situation
   */ // }}}
  void test__release_context__success( )
  {
    T::Dummy_clReleaseContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test__release_context__invalid_context() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__release_context__invalid_context( )
  {
    T::Dummy_clReleaseContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__release_context__out_of_resources() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_context__out_of_resources( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_context__out_of_host_memory() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_context__out_of_host_memory( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_context_info__success() {{{
   * \brief Test get_context_info() in a normal situation
   */ // }}}
  void test__get_context_info__success( )
  {
    T::Dummy_clGetContextInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_context)NULL, CL_CONTEXT_REFERENCE_COUNT, 0, nullptr, nullptr));
  }
  /** // doc: test__get_context_info__invalid_context() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__get_context_info__invalid_context( )
  {
    T::Dummy_clGetContextInfo mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__get_context_info__invalid_value() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_context_info__invalid_value( )
  {
    T::Dummy_clGetContextInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_context_info__out_of_resources() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_context_info__out_of_resources( )
  {
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_context_info__out_of_host_memory() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_context_info__out_of_host_memory( )
  {
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_context_info__other_error() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns an unexpected error code.
   */ // }}}
  void test__get_context_info__other_error( )
  {
    T::Dummy_clGetContextInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
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
  /** // doc: test__retain_device() {{{
   * Test \ref retain_device() in normal situation
   */ // }}}
  void test__retain_device( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#endif // CLXX_OPENCL_ALLOWED(clRetainDevice)
  }
  /** // doc: test__retain_device__invalid_device() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test__retain_device__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::invalid_device>);
#endif // CLXX_OPENCL_ALLOWED(clRetainDevice)
  }
  /** // doc: test__retain_device__out_of_resources() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__retain_device__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_resources>);
#endif // CLXX_OPENCL_ALLOWED(clRetainDevice)
  }
  /** // doc: test__retain_device__out_of_host_memory() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__retain_device__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_host_memory>);
#endif // CLXX_OPENCL_ALLOWED(clRetainDevice)
  }
  /** // doc: test__retain_device__unexpected_clerror() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns unexpected error code
   */ // }}}
  void test__retain_device__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mock(-0x1234567);
    TS_ASSERT_THROWS(retain_device(NULL),unexpected_clerror);
#endif // CLXX_OPENCL_ALLOWED(clRetainDevice)
  }
  /** // doc: test__release_device() {{{
   * \brief Test \ref release_device() in normal situation
   */ // }}}
  void test__release_device( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__invalid_device() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test__release_device__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::invalid_device>);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__out_of_resources() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_device__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_resources>);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__out_of_host_memory() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_device__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_host_memory>);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__unexpected_clerror() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns unexpected error code
   */ // }}}
  void test__release_device__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(-0x1234567);
    TS_ASSERT_THROWS(release_device(NULL),unexpected_clerror);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__create_command_queue__success() {{{
   * \brief Test create_command_queue() in a normal situation.
   */ // }}}
  void test__create_command_queue__success( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_command_queue((cl_context)NULL,(cl_device_id)NULL, command_queue_properties_t::profiling_enable));
    //TS_ASSERT(mock.called_once_with((cl_context)NULL,0,nullptr,nullptr,nullptr,??? - local variable within create_command_queue(...){...}));
#endif
  }
  /** // doc: test__create_command_queue__invalid_context() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_command_queue__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_command_queue__invalid_device() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_DEVICE.
   */ // }}}
  void test__create_command_queue__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_device>);
#endif
  }
  /** // doc: test__create_command_queue__invalid_value() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_command_queue__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__create_command_queue__invalid_command_queue() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_command_queue__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::none), clerror_no<status_t::invalid_queue_properties>);
#endif
  }
  /** // doc: test__create_command_queue__out_of_resources() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_command_queue__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_command_queue__out_of_host_memory() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_command_queue__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_command_queue__other_error() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns an unexpected error code.
   */ // }}}
  void test__create_command_queue__other_error( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, -0x3456);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), unexpected_clerror);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__success() {{{
   * \brief Test create_command_queue_with_properties() in a normal situation.
   */ // }}}
  void test__create_command_queue_with_properties__success( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL, (const cl_queue_properties*)NULL));
    //TS_ASSERT(mock.called_once_with((cl_context)NULL,0,nullptr,nullptr,nullptr,??? - local variable within create_command_queue_with_properties(...){...}));
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_context() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_device() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_DEVICE.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_device>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_value() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_command_queue() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_queue_properties>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__out_of_resources() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_command_queue_with_properties__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__out_of_host_memory() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_command_queue_with_properties__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__other_error() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueue() returns an unexpected error code.
   */ // }}}
  void test__create_command_queue_with_properties__other_error( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, -0x3456);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), unexpected_clerror);
#endif
  }
  /** // doc: test__retain_command_queue__success() {{{
   * \brief Test retain_command_queue() in a normal situation
   */ // }}}
  void test__retain_command_queue__success( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_command_queue((cl_command_queue)NULL));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL));
  }
  /** // doc: test__retain_command_queue__invalid_command_queue() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__retain_command_queue__invalid_command_queue( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__retain_command_queue__out_of_resources() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__retain_command_queue__out_of_resources( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_command_queue__out_of_host_memory() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__retain_command_queue__out_of_host_memory( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_command_queue__success() {{{
   * \brief Test release_command_queue() in a normal situation
   */ // }}}
  void test__release_command_queue__success( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_command_queue((cl_command_queue)NULL));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL));
  }
  /** // doc: test__release_command_queue__invalid_command_queue() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__release_command_queue__invalid_command_queue( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__release_command_queue__out_of_resources() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_command_queue__out_of_resources( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_command_queue__out_of_host_memory() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_command_queue__out_of_host_memory( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_command_queue_info__success() {{{
   * \brief Test get_command_queue_info() in a normal situation
   */ // }}}
  void test__get_command_queue_info__success( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL, CL_QUEUE_REFERENCE_COUNT, 0, nullptr, nullptr));
  }
  /** // doc: test__get_command_queue_info__invalid_command_queue() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__get_command_queue_info__invalid_command_queue( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__get_command_queue_info__invalid_value() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_command_queue_info__invalid_value( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_command_queue_info__out_of_resources() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_command_queue_info__out_of_resources( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_command_queue_info__out_of_host_memory() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_command_queue_info__out_of_host_memory( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_command_queue_info__other_error() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns an unexpected error code.
   */ // }}}
  void test__get_command_queue_info__other_error( )
  {
    T::Dummy_clGetCommandQueueInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test__create_program_with_source() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_source( )
  {
    //T::Dummy_clCreateProgramWithSource mock((cl_program)0x1234, CL_SUCCESS);
    //create_program_with_source     ((cl_context)0x567, 3, (const char**)0x787, (const size_t*)0x235);
    //TS_ASSERT(mock.called_once_with((cl_context)0x567, 3, (const char**)0x787, (const size_t*)0x235));
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
  /** // doc: test__create_program_with_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
    // T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)0x1234, CL_SUCCESS);
    // create_program_with_built_in_kernels((cl_context)0x113, 8, (const cl_device_id*)0x654, (const size_t*)0x165, (const unsigned char**)0x938747, (cl_int*)0x214);
    // TS_ASSERT(mock.called_once_with     ((cl_context)0x113, 8, (const cl_device_id*)0x654, (const size_t*)0x165, (const unsigned char**)0x938747, (cl_int*)0x214));
#endif //  CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  }
  /** // doc: test__create_program_with_built_in_kernels__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_context>);
#endif //  CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  }
  /** // doc: test__create_program_with_built_in_kernels__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  }
  /** // doc: test__create_program_with_built_in_kernels__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  }
  /** // doc: test__create_program_with_built_in_kernels__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  }
  /** // doc: test__create_program_with_built_in_kernels__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  }
  /** // doc: test__create_program_with_built_in_kernels__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_program_with_built_in_kernels__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr), unexpected_clerror);
#endif //  CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
  }
  /** // doc: test__retain_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program( )
  {
    T::Dummy_clRetainProgram mock(CL_SUCCESS);
    retain_program                 ((cl_program)0x344);
    TS_ASSERT(mock.called_once_with((cl_program)0x344));
  }
  /** // doc: test__retain_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__invalid_program( )
  {
    T::Dummy_clRetainProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__retain_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__out_of_resources( )
  {
    T::Dummy_clRetainProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__out_of_host_memory( )
  {
    T::Dummy_clRetainProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__retain_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__unexpected_clerror( )
  {
    T::Dummy_clRetainProgram mock(-0x1234567);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL), unexpected_clerror);
  }
  /** // doc: test__release_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program( )
  {
    T::Dummy_clReleaseProgram mock(CL_SUCCESS);
    release_program                ((cl_program)0x433);
    TS_ASSERT(mock.called_once_with((cl_program)0x433));
  }
  /** // doc: test__release_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__invalid_program( )
  {
    T::Dummy_clReleaseProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__release_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__out_of_resources( )
  {
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__out_of_host_memory( )
  {
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__unexpected_clerror( )
  {
    T::Dummy_clReleaseProgram mock(-0x1234567);
    TS_ASSERT_THROWS(release_program((cl_program)NULL), unexpected_clerror);
  }
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
  /** // doc: test__compile_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_SUCCESS);
    compile_program                ((cl_program)0x344, 7, (const cl_device_id*)0x543, (const char*)0x937, 5, (const cl_program*)0x634, (const char**)0x834, (void(*)(cl_program,void*))0x936, (void*)0x234);
    TS_ASSERT(mock.called_once_with((cl_program)0x344, 7, (const cl_device_id*)0x543, (const char*)0x937, 5, (const cl_program*)0x634, (const char**)0x834, (void(*)(cl_program,void*))0x936, (void*)0x234));
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_program( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_compiler_options() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_compiler_options( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_COMPILER_OPTIONS);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_compiler_options>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__compiler_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__compiler_not_available( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_COMPILER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compiler_not_available>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__compile_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__compile_program_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_COMPILE_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compile_program_failure>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__compile_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__compile_program__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clCompileProgram mock(-0x1234567);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
#endif //  CLXX_OPENCL_ALLOWED(clCompileProgram)
  }
  /** // doc: test__link_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
//    T::Dummy_clLinkProgram mock((cl_program)0x1234, CL_SUCCESS);
//    link_program                   ((cl_context)0x539, 6, (cl_device_id*)0x195, (const char*)0x542, 9, (const cl_program*)0x532, (void(*)(cl_program, void*))0x253, (void*)0x837);
//    TS_ASSERT(mock.called_once_with((cl_context)0x539, 6, (cl_device_id*)0x195, (const char*)0x542, 9, (const cl_program*)0x532, (void(*)(cl_program, void*))0x253, (void*)0x837));
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_context>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_program( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_linker_options() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_linker_options( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_LINKER_OPTIONS);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_linker_options>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__linker_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__linker_not_available( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_LINKER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::linker_not_available>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__link_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__link_program_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_LINK_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::link_program_failure>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr), unexpected_clerror);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__unload_platform_compiler() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
    T::Dummy_clUnloadPlatformCompiler mock(CL_SUCCESS);
    unload_platform_compiler       ((cl_platform_id)0x937);
    TS_ASSERT(mock.called_once_with((cl_platform_id)0x937));
#endif // CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
  }
  /** // doc: test__unload_platform_compiler__invalid_platform() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler__invalid_platform( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
    T::Dummy_clUnloadPlatformCompiler mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL),clerror_no<status_t::invalid_platform>);
#endif // CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
  }
  /** // doc: test__unload_platform_compiler__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
    T::Dummy_clUnloadPlatformCompiler mock(-0x1234567);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL), unexpected_clerror);
#endif // CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
  }
  /** // doc: test__get_program_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info( )
  {
    T::Dummy_clGetProgramInfo mock(CL_SUCCESS);
    get_program_info               ((cl_program)0x395, program_info_t::reference_count,             5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_program)0x395, (cl_program_info)CL_PROGRAM_REFERENCE_COUNT, 5, (void*)0x124, (size_t*)0x934));
  }
  /** // doc: test__get_program_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__invalid_value( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_program_info__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__invalid_program( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__get_program_info__invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__invalid_program_executable( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test__get_program_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__out_of_resources( )
  {
    T::Dummy_clGetProgramInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_program_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__out_of_host_memory( )
  {
    T::Dummy_clGetProgramInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_program_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__unexpected_clerror( )
  {
    T::Dummy_clGetProgramInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
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
  /** // doc: test__create_kernel__success() {{{
   * \brief Test create_kernel() in a normal situation.
   */ // }}}
  void test__create_kernel__success( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_kernel(nullptr,"mykernel"));
    TS_ASSERT(mock.called_once());
    TS_ASSERT(clxx::create_kernel(nullptr,0) == (cl_kernel)0x1234);
  }
  /** // doc: test__create_kernel__invalid_program() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_PROGRAM.
   */ // }}}
  void test__create_kernel__invalid_program( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__create_kernel__invalid_program_executable() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_PROGRAM_EXECUTABLE.
   */ // }}}
  void test__create_kernel__invalid_program_executable( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test__create_kernel__invalid_kernel_name() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_KERNEL_NAME.
   */ // }}}
  void test__create_kernel__invalid_kernel_name( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_KERNEL_NAME);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_kernel_name>);
  }
  /** // doc: test__create_kernel__invalid_kernel_definition() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_KERNEL_DEFINITION.
   */ // }}}
  void test__create_kernel__invalid_kernel_definition( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_KERNEL_DEFINITION);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_kernel_definition>);
  }
  /** // doc: test__create_kernel__invalid_value() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_kernel__invalid_value( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_kernel__out_of_resources() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_kernel__out_of_resources( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_kernel__out_of_host_memory() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_kernel__out_of_host_memory( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_kernels_in_program__success() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__success( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_SUCCESS, nullptr, nullptr);
    TS_ASSERT_THROWS_NOTHING(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr));
    TS_ASSERT(mock.called_once_with((cl_program)NULL,0,nullptr,nullptr));
  }
  /** // doc: test__create_kernels_in_program__invalid_program() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_program( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_PROGRAM, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__create_kernels_in_program__invalid_program_executable() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_program_executable( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_PROGRAM_EXECUTABLE, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test__create_kernels_in_program__invalid_value() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_value( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_VALUE, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_kernels_in_program__out_of_resources() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__out_of_resources( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_OUT_OF_RESOURCES, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_kernels_in_program__out_of_host_memory() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__out_of_host_memory( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_OUT_OF_HOST_MEMORY, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_kernel_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_info( )
  {
    T::Dummy_clGetKernelInfo mock(CL_SUCCESS);
    get_kernel_info                ((cl_kernel)0x395, kernel_info_t::reference_count,            5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x395, (cl_kernel_info)CL_KERNEL_REFERENCE_COUNT, 5, (void*)0x124, (size_t*)0x934));
  }
  /** // doc: test__get_kernel_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_info__invalid_value( )
  {
    T::Dummy_clGetKernelInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_kernel_info((cl_kernel)NULL, kernel_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_kernel_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_info__invalid_kernel( )
  {
    T::Dummy_clGetKernelInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(get_kernel_info((cl_kernel)NULL, kernel_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__get_kernel_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_info__out_of_resources( )
  {
    T::Dummy_clGetKernelInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_kernel_info((cl_kernel)NULL, kernel_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_kernel_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_info__out_of_host_memory( )
  {
    T::Dummy_clGetKernelInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_kernel_info((cl_kernel)NULL, kernel_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_kernel_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_info__unexpected_clerror( )
  {
    T::Dummy_clGetKernelInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_kernel_info((cl_kernel)NULL, kernel_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test__get_kernel_arg_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
    T::Dummy_clGetKernelArgInfo mock(CL_SUCCESS);
    get_kernel_arg_info            ((cl_kernel)0x395, 0, kernel_arg_info_t::name,                5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x395, 0, (cl_kernel_arg_info)CL_KERNEL_ARG_NAME, 5, (void*)0x124, (size_t*)0x934));
#endif
  }
  /** // doc: test__get_kernel_arg_info__invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__invalid_arg_index( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
    T::Dummy_clGetKernelArgInfo mock(CL_INVALID_ARG_INDEX);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::invalid_arg_index>);
#endif
  }
  /** // doc: test__get_kernel_arg_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
    T::Dummy_clGetKernelArgInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__get_kernel_arg_info__kernel_arg_info_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__kernel_arg_info_not_available( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
    T::Dummy_clGetKernelArgInfo mock(CL_KERNEL_ARG_INFO_NOT_AVAILABLE);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::kernel_arg_info_not_available>);
#endif
  }
  /** // doc: test__get_kernel_arg_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__invalid_kernel( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
    T::Dummy_clGetKernelArgInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr),clerror_no<status_t::invalid_kernel>);
#endif
  }
  /** // doc: test__get_kernel_arg_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_arg_info__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
    T::Dummy_clGetKernelArgInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_kernel_arg_info((cl_kernel)NULL, 0, kernel_arg_info_t::name, 0, nullptr, nullptr), unexpected_clerror);
#endif
  }
  /** // doc: test__get_kernel_work_group_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info( )
  {
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_SUCCESS);
    get_kernel_work_group_info     ((cl_kernel)0x395, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size,            5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x395, (cl_device_id)NULL, (cl_kernel_work_group_info)CL_KERNEL_WORK_GROUP_SIZE, 5, (void*)0x124, (size_t*)0x934));
  }
  /** // doc: test__get_kernel_work_group_info__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__invalid_device( )
  {
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__get_kernel_work_group_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__invalid_value( )
  {
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_kernel_work_group_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__invalid_kernel( )
  {
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__get_kernel_work_group_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__out_of_resources( )
  {
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_kernel_work_group_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__out_of_host_memory( )
  {
    T::Dummy_clGetKernelWorkGroupInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_kernel_work_group_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_kernel_work_group_info__unexpected_clerror( )
  {
    T::Dummy_clGetKernelWorkGroupInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_kernel_work_group_info((cl_kernel)NULL, (cl_device_id)NULL, kernel_work_group_info_t::work_group_size, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test__retain_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel( )
  {
    T::Dummy_clRetainKernel mock(CL_SUCCESS);
    retain_kernel                 ((cl_kernel)0x344);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x344));
  }
  /** // doc: test__retain_kernel__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__invalid_kernel( )
  {
    T::Dummy_clRetainKernel mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL),clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__retain_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__out_of_resources( )
  {
    T::Dummy_clRetainKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__out_of_host_memory( )
  {
    T::Dummy_clRetainKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__retain_kernel__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__unexpected_clerror( )
  {
    T::Dummy_clRetainKernel mock(-0x1234567);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL), unexpected_clerror);
  }
  /** // doc: test__release_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel( )
  {
    T::Dummy_clReleaseKernel mock(CL_SUCCESS);
    release_kernel                ((cl_kernel)0x433);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x433));
  }
  /** // doc: test__release_kernel__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__invalid_kernel( )
  {
    T::Dummy_clReleaseKernel mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__release_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__out_of_resources( )
  {
    T::Dummy_clReleaseKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__out_of_host_memory( )
  {
    T::Dummy_clReleaseKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_kernel__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__unexpected_clerror( )
  {
    T::Dummy_clReleaseKernel mock(-0x1234567);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL), unexpected_clerror);
  }
  /** // doc: test__set_kernel_arg() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg( )
  {
    T::Dummy_clSetKernelArg mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(        (cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876));
  }
  /** // doc: test__set_kernel_arg__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_kernel( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__set_kernel_arg__invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_arg_index( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_ARG_INDEX);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_arg_index>);
  }
  /** // doc: test__set_kernel_arg__invalid_arg_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_arg_value( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_ARG_VALUE);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_arg_value>);
  }
  /** // doc: test__set_kernel_arg__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_mem_object( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__set_kernel_arg__invalid_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_sampler( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_SAMPLER);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_sampler>);
  }
  /** // doc: test__set_kernel_arg__invalid_device_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_device_queue( )
  {
#if CL_VERSION_2_0
    T::Dummy_clSetKernelArg mock(CL_INVALID_DEVICE_QUEUE);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_device_queue>);
#endif
  }
  /** // doc: test__set_kernel_arg__invalid_arg_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_arg_size( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_ARG_SIZE);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_arg_size>);
  }
  /** // doc: test__set_kernel_arg__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__out_of_resources( )
  {
    T::Dummy_clSetKernelArg mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__set_kernel_arg__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__out_of_host_memory( )
  {
    T::Dummy_clSetKernelArg mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__set_kernel_arg__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__unexpected_clerror( )
  {
    T::Dummy_clSetKernelArg mock(-0x12345678);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), unexpected_clerror);
  }
  /** // doc: test__set_kernel_arg_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(                    (cl_kernel)NULL, 0x123, (const void*)0x9876));
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_kernel( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_arg_index( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_ARG_INDEX);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_arg_index>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_arg_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_arg_value( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_ARG_VALUE);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_arg_value>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__set_kernel_exec_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(              (cl_kernel)NULL, CL_KERNEL_EXEC_INFO_SVM_PTRS, 0x123, (const void*)0x9876));
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_kernel( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(-0x12345678);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_FUNCTIONS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
