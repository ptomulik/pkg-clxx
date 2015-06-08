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
  /** // doc: test_get_platform_ids__success() {{{
   * \brief Test get_platform_ids() in a normal situation
   */ // }}}
  void test_get_platform_ids__success( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_ids(0,nullptr,NULL));
    TS_ASSERT(mock.called_once_with(0,nullptr,NULL));
  }
  /** // doc: test_get_platform_ids__invalid_value() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_platform_ids__invalid_value( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_platform_ids__out_of_host_memory() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_platform_ids__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_platform_ids__other_error() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns unexpected error code.
   */ // }}}
  void test_get_platform_ids__other_error( )
  {
    T::Dummy_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), unexpected_clerror);
  }
  /** // doc: test_get_platform_info__success() {{{
   * \brief Test get_platform_info()
   */ // }}}
  void test_get_platform_info__success( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, (cl_platform_info)0, 0, nullptr, nullptr));
  }
  /** // doc: test_get_platform_info__invalid_platform() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_PLATFORM
   */ // }}}
  void test_get_platform_info__invalid_platform( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_get_platform_info__invalid_value() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_platform_info__invalid_value( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_platform_info__out_of_host_memory() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_platform_info__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_platform_info__other_error() {{{
   * \brief Test get_platform_info() in a situation when clGetPlatformInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_platform_info__other_error( )
  {
    T::Dummy_clGetPlatformInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_info((cl_platform_id)NULL, static_cast<platform_info_t>(0), 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_get_device_ids__success() {{{
   * \brief Test get_device_ids()
   */ // }}}
  void test_get_device_ids__success( )
  {
    T::Dummy_clGetDeviceIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_platform_id)NULL, CL_DEVICE_TYPE_ALL, 0, nullptr, nullptr));
  }
  /** // doc: test_get_device_ids__invalid_platform() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_PLATFORM
   */ // }}}
  void test_get_device_ids__invalid_platform()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_get_device_ids__invalid_device_type() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_DEVICE_TYPE
   */ // }}}
  void test_get_device_ids__invalid_device_type()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test_get_device_ids__invalid_value() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_device_ids__invalid_value()
  {
    T::Dummy_clGetDeviceIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_device_ids__device_not_found() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_DEVICE_NOT_FOUND
   */ // }}}
  void test_get_device_ids__device_not_found()
  {
    T::Dummy_clGetDeviceIDs mock(CL_DEVICE_NOT_FOUND);
    //TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::device_not_found>);
    TS_ASSERT_THROWS_NOTHING(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr));
  }
  /** // doc: test_get_device_ids__out_of_resources() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_get_device_ids__out_of_resources()
  {
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_device_ids__out_of_host_memory() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_device_ids__out_of_host_memory()
  {
    T::Dummy_clGetDeviceIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_device_ids__other_error() {{{
   * \brief Test get_device_ids() in a situation when clGetDeviceIDs() returns an unexpected error code
   */ // }}}
  void test_get_device_ids__other_error()
  {
    T::Dummy_clGetDeviceIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_device_ids((cl_platform_id)NULL, device_type_t::all, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_get_device_info__success() {{{
   * \brief Test get_device_info() in a normal situation
   */ // }}}
  void test_get_device_info__success()
  {
    T::Dummy_clGetDeviceInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_device_id)NULL, CL_DEVICE_VENDOR_ID, 0, nullptr, nullptr));
  }
  /** // doc: test_get_device_info__invalid_device() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_INVALID_DEVICE
   */ // }}}
  void test_get_device_info__invalid_device()
  {
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_get_device_info__invalid_value() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_device_info__invalid_value()
  {
    T::Dummy_clGetDeviceInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_device_info__out_of_resources() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_get_device_info__out_of_resources()
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_device_info__out_of_host_memory() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_device_info__out_of_host_memory()
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_device_info__other_error() {{{
   * \brief Test get_device_info() in a situation when clGetDeviceInfo() returns an unexpected error code
   */ // }}}
  void test_get_device_info__other_error()
  {
    T::Dummy_clGetDeviceInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_device_info((cl_device_id)NULL, device_info_t::vendor_id, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_create_context__success() {{{
   * \brief Test create_context() in a normal situation.
   */ // }}}
  void test_create_context__success( )
  {
    T::Dummy_clCreateContext mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr));
    //TS_ASSERT(mock.called_once_with(nullptr,0,nullptr,nullptr,nullptr,??? - local variable within create_context(...){...}));
  }
  /** // doc: test_create_context__invalid_platform() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test_create_context__invalid_platform( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_create_context__invalid_property() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test_create_context__invalid_property( )
  {
#if CL_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_property>);
#endif
  }
  /** // doc: test_create_context__invalid_operation() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_OPERATION.
   */ // }}}
  void test_create_context__invalid_operation( )
  {
#if CL_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test_create_context__invalid_value() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_VALUE.
   */ // }}}
  void test_create_context__invalid_value( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_create_context__invalid_device() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_DEVICE.
   */ // }}}
  void test_create_context__invalid_device( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_create_context__device_not_available() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test_create_context__device_not_available( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test_create_context__out_of_resources() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_create_context__out_of_resources( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_create_context__out_of_host_memory() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_create_context__out_of_host_memory( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_create_context__other_error() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns an unexpected error code.
   */ // }}}
  void test_create_context__other_error( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), unexpected_clerror);
  }
  /** // doc: test_create_context_from_type__success() {{{
   * \brief Test create_context_from_type().
   */ // }}}
  void test_create_context_from_type__success( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr));
  }
  /** // doc: test_create_context_from_type__invalid_platform() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test_create_context_from_type__invalid_platform( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_create_context_from_type__invalid_property() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test_create_context_from_type__invalid_property( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_property>);
  }
  /** // doc: test_create_context_from_type__invalid_value() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_VALUE.
   */ // }}}
  void test_create_context_from_type__invalid_value( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_create_context_from_type__invalid_device_type() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test_create_context_from_type__invalid_device_type( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test_create_context_from_type__device_not_available() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test_create_context_from_type__device_not_available( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test_create_context_from_type__out_of_resources() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_create_context_from_type__out_of_resources( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_create_context_from_type__out_of_host_memory() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_create_context_from_type__out_of_host_memory( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_create_context_from_type__other_error() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns an unexpected error code.
   */ // }}}
  void test_create_context_from_type__other_error( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), unexpected_clerror);
  }
  /** // doc: test_retain_context__success() {{{
   * \brief Test retain_context() in a normal situation
   */ // }}}
  void test_retain_context__success( )
  {
    T::Dummy_clRetainContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test_retain_context__invalid_context() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_retain_context__invalid_context( )
  {
    T::Dummy_clRetainContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_retain_context__out_of_resources() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_retain_context__out_of_resources( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_retain_context__out_of_host_memory() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_retain_context__out_of_host_memory( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_release_context__success() {{{
   * \brief Test release_context() in a normal situation
   */ // }}}
  void test_release_context__success( )
  {
    T::Dummy_clReleaseContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test_release_context__invalid_context() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_release_context__invalid_context( )
  {
    T::Dummy_clReleaseContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_release_context__out_of_resources() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_release_context__out_of_resources( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_release_context__out_of_host_memory() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_release_context__out_of_host_memory( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_context_info__success() {{{
   * \brief Test get_context_info() in a normal situation
   */ // }}}
  void test_get_context_info__success( )
  {
    T::Dummy_clGetContextInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_context)NULL, CL_CONTEXT_REFERENCE_COUNT, 0, nullptr, nullptr));
  }
  /** // doc: test_get_context_info__invalid_context() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_get_context_info__invalid_context( )
  {
    T::Dummy_clGetContextInfo mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_get_context_info__invalid_value() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_context_info__invalid_value( )
  {
    T::Dummy_clGetContextInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_context_info__out_of_resources() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_get_context_info__out_of_resources( )
  {
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_context_info__out_of_host_memory() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_context_info__out_of_host_memory( )
  {
    T::Dummy_clGetContextInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_context_info__other_error() {{{
   * \brief Test get_context_info() in a situation when clGetContextInfo() returns an unexpected error code.
   */ // }}}
  void test_get_context_info__other_error( )
  {
    T::Dummy_clGetContextInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_context_info((cl_context)NULL, context_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_create_sub_devices() {{{
   * \brief Test \ref create_sub_devices()() in normal situation.
   */ // }}}
  void test_create_sub_devices( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_sub_devices((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234, (const cl_device_partition_property*)0x5678, 2, (cl_device_id*)0x4321, (cl_uint*)0x8765));
#endif
  }
  /** // doc: test_create_sub_devices__invalid_device() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE
   */ // }}}
  void test_create_sub_devices__invalid_device( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__invalid_value() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_VALUE
   */ // }}}
  void test_create_sub_devices__invalid_value( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__device_partition_failed() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_DEVICE_PARTITION_FAILED
   */ // }}}
  void test_create_sub_devices__device_partition_failed( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_DEVICE_PARTITION_FAILED);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::device_partition_failed>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__invalid_device_partition_count() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_INVALID_DEVICE_PARTITION_COUNT
   */ // }}}
  void test_create_sub_devices__invalid_device_partition_count( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_INVALID_DEVICE_PARTITION_COUNT);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_device_partition_count>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__out_of_resources() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_create_sub_devices__out_of_resources( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__out_of_host_memory() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_create_sub_devices__out_of_host_memory( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_create_sub_devices__unexpected_clerror() {{{
   * \brief Test \ref create_sub_devices() in a situation when \c clCreateSubDevices() returns unexpected error code
   */ // }}}
  void test_create_sub_devices__unexpected_clerror( )
  {
#if HAVE_OPENCL_clCreateSubDevices
    T::Dummy_clCreateSubDevices mock(-0x12334567);
    TS_ASSERT_THROWS(create_sub_devices(NULL, nullptr, 0, nullptr, nullptr), unexpected_clerror);
#endif // HAVE_OPENCL_clCreateSubDevices
  }
  /** // doc: test_retain_device() {{{
   * Test \ref retain_device() in normal situation
   */ // }}}
  void test_retain_device( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__invalid_device() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test_retain_device__invalid_device( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::invalid_device>);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__out_of_resources() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_retain_device__out_of_resources( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_resources>);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__out_of_host_memory() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_retain_device__out_of_host_memory( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_device(NULL),clerror_no<status_t::out_of_host_memory>);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_retain_device__unexpected_clerror() {{{
   * \brief Test \ref retain_device() in a situation when \c clRetainDevice() returns unexpected error code
   */ // }}}
  void test_retain_device__unexpected_clerror( )
  {
#if HAVE_OPENCL_clRetainDevice
    T::Dummy_clRetainDevice mock(-0x1234567);
    TS_ASSERT_THROWS(retain_device(NULL),unexpected_clerror);
#endif // HAVE_OPENCL_clRetainDevice
  }
  /** // doc: test_release_device() {{{
   * \brief Test \ref release_device() in normal situation
   */ // }}}
  void test_release_device( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__invalid_device() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test_release_device__invalid_device( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::invalid_device>);
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__out_of_resources() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_release_device__out_of_resources( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_resources>);
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__out_of_host_memory() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_release_device__out_of_host_memory( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_host_memory>);
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_release_device__unexpected_clerror() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns unexpected error code
   */ // }}}
  void test_release_device__unexpected_clerror( )
  {
#if HAVE_OPENCL_clReleaseDevice
    T::Dummy_clReleaseDevice mock(-0x1234567);
    TS_ASSERT_THROWS(release_device(NULL),unexpected_clerror);
#endif // HAVE_OPENCL_clReleaseDevice
  }
  /** // doc: test_create_command_queue__success() {{{
   * \brief Test create_command_queue() in a normal situation.
   */ // }}}
  void test_create_command_queue__success( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_command_queue((cl_context)NULL,(cl_device_id)NULL, command_queue_properties_t::profiling_enable));
    //TS_ASSERT(mock.called_once_with((cl_context)NULL,0,nullptr,nullptr,nullptr,??? - local variable within create_command_queue(...){...}));
#endif
  }
  /** // doc: test_create_command_queue__invalid_context() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test_create_command_queue__invalid_context( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test_create_command_queue__invalid_device() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_DEVICE.
   */ // }}}
  void test_create_command_queue__invalid_device( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_device>);
#endif
  }
  /** // doc: test_create_command_queue__invalid_value() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_VALUE.
   */ // }}}
  void test_create_command_queue__invalid_value( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test_create_command_queue__invalid_command_queue() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test_create_command_queue__invalid_command_queue( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::none), clerror_no<status_t::invalid_queue_properties>);
#endif
  }
  /** // doc: test_create_command_queue__out_of_resources() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_create_command_queue__out_of_resources( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test_create_command_queue__out_of_host_memory() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_create_command_queue__out_of_host_memory( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test_create_command_queue__other_error() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns an unexpected error code.
   */ // }}}
  void test_create_command_queue__other_error( )
  {
#if HAVE_OPENCL_clCreateCommandQueue
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, -0x3456);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), unexpected_clerror);
#endif
  }
  /** // doc: test_create_command_queue_with_properties__success() {{{
   * \brief Test create_command_queue_with_properties() in a normal situation.
   */ // }}}
  void test_create_command_queue_with_properties__success( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL, (const cl_queue_properties*)NULL));
    //TS_ASSERT(mock.called_once_with((cl_context)NULL,0,nullptr,nullptr,nullptr,??? - local variable within create_command_queue_with_properties(...){...}));
#endif
  }
  /** // doc: test_create_command_queue_with_properties__invalid_context() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test_create_command_queue_with_properties__invalid_context( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test_create_command_queue_with_properties__invalid_device() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_DEVICE.
   */ // }}}
  void test_create_command_queue_with_properties__invalid_device( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_device>);
#endif
  }
  /** // doc: test_create_command_queue_with_properties__invalid_value() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_VALUE.
   */ // }}}
  void test_create_command_queue_with_properties__invalid_value( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test_create_command_queue_with_properties__invalid_command_queue() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test_create_command_queue_with_properties__invalid_command_queue( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_queue_properties>);
#endif
  }
  /** // doc: test_create_command_queue_with_properties__out_of_resources() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_create_command_queue_with_properties__out_of_resources( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test_create_command_queue_with_properties__out_of_host_memory() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_create_command_queue_with_properties__out_of_host_memory( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test_create_command_queue_with_properties__other_error() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueue() returns an unexpected error code.
   */ // }}}
  void test_create_command_queue_with_properties__other_error( )
  {
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, -0x3456);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), unexpected_clerror);
#endif
  }
  /** // doc: test_retain_command_queue__success() {{{
   * \brief Test retain_command_queue() in a normal situation
   */ // }}}
  void test_retain_command_queue__success( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_command_queue((cl_command_queue)NULL));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL));
  }
  /** // doc: test_retain_command_queue__invalid_command_queue() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_retain_command_queue__invalid_command_queue( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test_retain_command_queue__out_of_resources() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_retain_command_queue__out_of_resources( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_retain_command_queue__out_of_host_memory() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_retain_command_queue__out_of_host_memory( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_release_command_queue__success() {{{
   * \brief Test release_command_queue() in a normal situation
   */ // }}}
  void test_release_command_queue__success( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_command_queue((cl_command_queue)NULL));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL));
  }
  /** // doc: test_release_command_queue__invalid_command_queue() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_release_command_queue__invalid_command_queue( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test_release_command_queue__out_of_resources() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_release_command_queue__out_of_resources( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_release_command_queue__out_of_host_memory() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_release_command_queue__out_of_host_memory( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_command_queue_info__success() {{{
   * \brief Test get_command_queue_info() in a normal situation
   */ // }}}
  void test_get_command_queue_info__success( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL, CL_QUEUE_REFERENCE_COUNT, 0, nullptr, nullptr));
  }
  /** // doc: test_get_command_queue_info__invalid_command_queue() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_INVALID_CONTEXT
   */ // }}}
  void test_get_command_queue_info__invalid_command_queue( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test_get_command_queue_info__invalid_value() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test_get_command_queue_info__invalid_value( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_command_queue_info__out_of_resources() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test_get_command_queue_info__out_of_resources( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_command_queue_info__out_of_host_memory() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test_get_command_queue_info__out_of_host_memory( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_command_queue_info__other_error() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns an unexpected error code.
   */ // }}}
  void test_get_command_queue_info__other_error( )
  {
    T::Dummy_clGetCommandQueueInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_create_program_with_source() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_source( )
  {
    //T::Dummy_clCreateProgramWithSource mock((cl_program)0x1234, CL_SUCCESS);
    //create_program_with_source     ((cl_context)0x567, 3, (const char**)0x787, (const size_t*)0x235);
    //TS_ASSERT(mock.called_once_with((cl_context)0x567, 3, (const char**)0x787, (const size_t*)0x235));
  }
  /** // doc: test_create_program_with_source__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_source__invalid_context( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_create_program_with_source__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_source__invalid_value( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_create_program_with_source__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_source__out_of_resources( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_create_program_with_source__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_source__out_of_host_memory( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_create_program_with_source__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_source__unexpected_clerror( )
  {
    T::Dummy_clCreateProgramWithSource mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_source((cl_context)NULL, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_create_program_with_binary() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary( )
  {
    //T::Dummy_clCreateProgramWithBinary mock((cl_program)0x1234, CL_SUCCESS);
    //create_program_with_binary     ((cl_context)0x567, 5, (const cl_device_id*)0x487, (const size_t*)0x634, (const unsigned char**)0x174, (cl_int*)0x757);
    //TS_ASSERT(mock.called_once_with((cl_context)0x567, 5, (const cl_device_id*)0x487, (const size_t*)0x634, (const unsigned char**)0x174, (cl_int*)0x757));
  }
  /** // doc: test_create_program_with_binary__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary__invalid_context( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_context>);
  }
  /** // doc: test_create_program_with_binary__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary__invalid_value( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_create_program_with_binary__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary__invalid_device( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_create_program_with_binary__invalid_binary() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary__invalid_binary( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_INVALID_BINARY);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_binary>);
  }
  /** // doc: test_create_program_with_binary__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary__out_of_resources( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_create_program_with_binary__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary__out_of_host_memory( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_create_program_with_binary__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_binary__unexpected_clerror( )
  {
    T::Dummy_clCreateProgramWithBinary mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_binary((cl_context)NULL, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_create_program_with_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_built_in_kernels( )
  {
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
    // T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)0x1234, CL_SUCCESS);
    // create_program_with_built_in_kernels((cl_context)0x113, 8, (const cl_device_id*)0x654, (const size_t*)0x165, (const unsigned char**)0x938747, (cl_int*)0x214);
    // TS_ASSERT(mock.called_once_with     ((cl_context)0x113, 8, (const cl_device_id*)0x654, (const size_t*)0x165, (const unsigned char**)0x938747, (cl_int*)0x214));
#endif //  HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  }
  /** // doc: test_create_program_with_built_in_kernels__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_built_in_kernels__invalid_context( )
  {
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_context>);
#endif //  HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  }
  /** // doc: test_create_program_with_built_in_kernels__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_built_in_kernels__invalid_value( )
  {
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  }
  /** // doc: test_create_program_with_built_in_kernels__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_built_in_kernels__invalid_device( )
  {
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  }
  /** // doc: test_create_program_with_built_in_kernels__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_built_in_kernels__out_of_resources( )
  {
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  }
  /** // doc: test_create_program_with_built_in_kernels__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_built_in_kernels__out_of_host_memory( )
  {
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  }
  /** // doc: test_create_program_with_built_in_kernels__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_create_program_with_built_in_kernels__unexpected_clerror( )
  {
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
    T::Dummy_clCreateProgramWithBuiltInKernels mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_program_with_built_in_kernels((cl_context)NULL, 0, nullptr, nullptr), unexpected_clerror);
#endif //  HAVE_OPENCL_clCreateProgramWithBuiltInKernels
  }
  /** // doc: test_retain_program() {{{
   * \todo Write documentation
   */ // }}}
void test_retain_program( )
  {
    T::Dummy_clRetainProgram mock(CL_SUCCESS);
    retain_program                 ((cl_program)0x344);
    TS_ASSERT(mock.called_once_with((cl_program)0x344));
  }
  /** // doc: test_retain_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
void test_retain_program__invalid_program( )
  {
    T::Dummy_clRetainProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test_retain_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_retain_program__out_of_resources( )
  {
    T::Dummy_clRetainProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_retain_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_retain_program__out_of_host_memory( )
  {
    T::Dummy_clRetainProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_retain_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_retain_program__unexpected_clerror( )
  {
    T::Dummy_clRetainProgram mock(-0x1234567);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL), unexpected_clerror);
  }
  /** // doc: test_release_program() {{{
   * \todo Write documentation
   */ // }}}
void test_release_program( )
  {
    T::Dummy_clReleaseProgram mock(CL_SUCCESS);
    release_program                ((cl_program)0x433);
    TS_ASSERT(mock.called_once_with((cl_program)0x433));
  }
  /** // doc: test_release_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
void test_release_program__invalid_program( )
  {
    T::Dummy_clReleaseProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test_release_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_release_program__out_of_resources( )
  {
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_release_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_release_program__out_of_host_memory( )
  {
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_release_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_release_program__unexpected_clerror( )
  {
    T::Dummy_clReleaseProgram mock(-0x1234567);
    TS_ASSERT_THROWS(release_program((cl_program)NULL), unexpected_clerror);
  }
  /** // doc: test_build_program() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program( )
  {
    T::Dummy_clBuildProgram mock(CL_SUCCESS);
    build_program                  ((cl_program)0x634, 7, (const cl_device_id*)0x543, (const char*)0x5234, (void(*)(cl_program,void*))0x654, (void*)0x122);
    TS_ASSERT(mock.called_once_with((cl_program)0x634, 7, (const cl_device_id*)0x543, (const char*)0x5234, (void(*)(cl_program,void*))0x654, (void*)0x122));
  }
  /** // doc: test_build_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__invalid_program( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test_build_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__invalid_value( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_build_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__invalid_device( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_build_program__invalid_binary() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__invalid_binary( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_BINARY);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_binary>);
  }
  /** // doc: test_build_program__invalid_build_options() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__invalid_build_options( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_BUILD_OPTIONS);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_build_options>);
  }
  /** // doc: test_build_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__invalid_operation( )
  {
    T::Dummy_clBuildProgram mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
  }
  /** // doc: test_build_program__compiler_not_available() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__compiler_not_available( )
  {
    T::Dummy_clBuildProgram mock(CL_COMPILER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compiler_not_available>);
  }
  /** // doc: test_build_program__build_program_failure() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__build_program_failure( )
  {
    T::Dummy_clBuildProgram mock(CL_BUILD_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::build_program_failure>);
  }
  /** // doc: test_build_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__out_of_resources( )
  {
    T::Dummy_clBuildProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_build_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__out_of_host_memory( )
  {
    T::Dummy_clBuildProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_build_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_build_program__unexpected_clerror( )
  {
    T::Dummy_clBuildProgram mock(-0x1234567);
    TS_ASSERT_THROWS(build_program((cl_program)NULL, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_compile_program() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_SUCCESS);
    compile_program                ((cl_program)0x344, 7, (const cl_device_id*)0x543, (const char*)0x937, 5, (const cl_program*)0x634, (const char**)0x834, (void(*)(cl_program,void*))0x936, (void*)0x234);
    TS_ASSERT(mock.called_once_with((cl_program)0x344, 7, (const cl_device_id*)0x543, (const char*)0x937, 5, (const cl_program*)0x634, (const char**)0x834, (void(*)(cl_program,void*))0x936, (void*)0x234));
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__invalid_program( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__invalid_value( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__invalid_device( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__invalid_compiler_options() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__invalid_compiler_options( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_INVALID_COMPILER_OPTIONS);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_compiler_options>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__invalid_operation( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__compiler_not_available() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__compiler_not_available( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_COMPILER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compiler_not_available>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__compile_program_failure() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__compile_program_failure( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_COMPILE_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::compile_program_failure>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__out_of_resources( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__out_of_host_memory( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_compile_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_compile_program__unexpected_clerror( )
  {
#if HAVE_OPENCL_clCompileProgram
    T::Dummy_clCompileProgram mock(-0x1234567);
    TS_ASSERT_THROWS(compile_program((cl_program)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr, nullptr), unexpected_clerror);
#endif //  HAVE_OPENCL_clCompileProgram
  }
  /** // doc: test_link_program() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program( )
  {
#if HAVE_OPENCL_clLinkProgram
//    T::Dummy_clLinkProgram mock((cl_program)0x1234, CL_SUCCESS);
//    link_program                   ((cl_context)0x539, 6, (cl_device_id*)0x195, (const char*)0x542, 9, (const cl_program*)0x532, (void(*)(cl_program, void*))0x253, (void*)0x837);
//    TS_ASSERT(mock.called_once_with((cl_context)0x539, 6, (cl_device_id*)0x195, (const char*)0x542, 9, (const cl_program*)0x532, (void(*)(cl_program, void*))0x253, (void*)0x837));
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__invalid_context( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_context>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__invalid_program( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__invalid_value( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__invalid_device( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__invalid_linker_options() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__invalid_linker_options( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_LINKER_OPTIONS);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_linker_options>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__invalid_operation( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__linker_not_available() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__linker_not_available( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_LINKER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::linker_not_available>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__link_program_failure() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__link_program_failure( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_LINK_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::link_program_failure>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__out_of_resources( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__out_of_host_memory( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_link_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_link_program__unexpected_clerror( )
  {
#if HAVE_OPENCL_clLinkProgram
    T::Dummy_clLinkProgram mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr), unexpected_clerror);
#endif //  HAVE_OPENCL_clLinkProgram
  }
  /** // doc: test_unload_platform_compiler() {{{
   * \todo Write documentation
   */ // }}}
void test_unload_platform_compiler( )
  {
#if HAVE_OPENCL_clUnloadPlatformCompiler
    T::Dummy_clUnloadPlatformCompiler mock(CL_SUCCESS);
    unload_platform_compiler       ((cl_platform_id)0x937);
    TS_ASSERT(mock.called_once_with((cl_platform_id)0x937));
#endif // HAVE_OPENCL_clUnloadPlatformCompiler
  }
  /** // doc: test_unload_platform_compiler__invalid_platform() {{{
   * \todo Write documentation
   */ // }}}
void test_unload_platform_compiler__invalid_platform( )
  {
#if HAVE_OPENCL_clUnloadPlatformCompiler
    T::Dummy_clUnloadPlatformCompiler mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL),clerror_no<status_t::invalid_platform>);
#endif // HAVE_OPENCL_clUnloadPlatformCompiler
  }
  /** // doc: test_unload_platform_compiler__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_unload_platform_compiler__unexpected_clerror( )
  {
#if HAVE_OPENCL_clUnloadPlatformCompiler
    T::Dummy_clUnloadPlatformCompiler mock(-0x1234567);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL), unexpected_clerror);
#endif // HAVE_OPENCL_clUnloadPlatformCompiler
  }
  /** // doc: test_get_program_info() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_info( )
  {
    T::Dummy_clGetProgramInfo mock(CL_SUCCESS);
    get_program_info               ((cl_program)0x395, program_info_t::reference_count,             5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_program)0x395, (cl_program_info)CL_PROGRAM_REFERENCE_COUNT, 5, (void*)0x124, (size_t*)0x934));
  }
  /** // doc: test_get_program_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_info__invalid_value( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_program_info__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_info__invalid_program( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test_get_program_info__invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_info__invalid_program_executable( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test_get_program_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_info__out_of_resources( )
  {
    T::Dummy_clGetProgramInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_program_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_info__out_of_host_memory( )
  {
    T::Dummy_clGetProgramInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_program_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_info__unexpected_clerror( )
  {
    T::Dummy_clGetProgramInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
  /** // doc: test_get_program_build_info() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_build_info( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_SUCCESS);
    get_program_build_info         ((cl_program)0x253, (cl_device_id)0x563, program_build_info_t::status,                   4, (void*)0x973, (size_t*)0x938);
    TS_ASSERT(mock.called_once_with((cl_program)0x253, (cl_device_id)0x563, (cl_program_build_info)CL_PROGRAM_BUILD_STATUS, 4, (void*)0x973, (size_t*)0x938));
  }
  /** // doc: test_get_program_build_info__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_build_info__invalid_device( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_get_program_build_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_build_info__invalid_value( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_program_build_info__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_build_info__invalid_program( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test_get_program_build_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_build_info__out_of_resources( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test_get_program_build_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_build_info__out_of_host_memory( )
  {
    T::Dummy_clGetProgramBuildInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_get_program_build_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
void test_get_program_build_info__unexpected_clerror( )
  {
    T::Dummy_clGetProgramBuildInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_program_build_info((cl_program)NULL, (cl_device_id)NULL, program_build_info_t::status, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
