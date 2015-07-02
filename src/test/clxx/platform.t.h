// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform.t.h

/** // doc: clxx/platform.t.h {{{
 * \file clxx/platform.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PLATFORM_T_H_INCLUDED
#define CLXX_CL_PLATFORM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/platform.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>
#include <cstring>

namespace clxx { class platform_test__suite; }

/** // doc: class clxx::platform_test__suite {{{
 * \brief Unit tests for clxx::platform class
 */ // }}}
class clxx::platform_test__suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__ctor_default() {{{
   * \brief Ensure that id() == NULL by default.
   */ // }}}
  void test__ctor_default( )
  {
    TS_ASSERT_EQUALS(platform().handle(), (cl_platform_id)NULL);
  }
  /** // doc: test__ctor_assign() {{{
   * \brief Ensure that assigining constructor works as expected.
   */ // }}}
  void test__ctor_assign( )
  {
    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234ul).handle(), (cl_platform_id)0x1234ul);
  }
  /** // doc: test__ctor_copy() {{{
   * \brief Ensure that copy constructor works as expected.
   */ // }}}
  void test__ctor_copy( )
  {
    platform p1((cl_platform_id)0x1234ul);
    platform p2(p1);
    TS_ASSERT_EQUALS(p2.handle(), p1.handle());
  }
  /** // doc: test__op_assign() {{{
   * \brief Ensure that assignment operator works.
   */ // }}}
  void test__op_assign( )
  {
    platform p1((cl_platform_id)0x1234ul);
    platform p2;
    TS_ASSERT_EQUALS(&(p2 = p1), &p2);
    TS_ASSERT_EQUALS(p2.handle(), p1.handle());
  }
  /** // doc: test__assign() {{{
   * \brief Ensure that assign() method works.
   */ // }}}
  void test__assign( )
  {
    platform p1((cl_platform_id)0x1234ul);
    platform p2;
    p2.assign(p1);
    TS_ASSERT_EQUALS(p2.handle(), p1.handle());
  }
  /** // doc: test__is_initialized_1() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test__is_initialized_1( )
  {
    TS_ASSERT(!platform().is_initialized());
  }
  /** // doc: test__is_initialized_2() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test__is_initialized_2( )
  {
    TS_ASSERT(!platform((cl_platform_id)NULL).is_initialized());
  }
  /** // doc: test__is_initialized_3() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test__is_initialized_3( )
  {
    TS_ASSERT(platform((cl_platform_id)0x1234ul).is_initialized());
  }
  /** // doc: test__id_1() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test__id_1( )
  {
    TS_ASSERT_EQUALS(platform((cl_platform_id)NULL).handle(), (cl_platform_id)NULL);
  }
  /** // doc: test__id_2() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test__id_2( )
  {
    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234ul).handle(), (cl_platform_id)0x1234ul);
  }
  /** // doc: test__get_valid_handle_1() {{{
   * \brief Ensure that get_valid_handle() method works.
   */ // }}}
  void test__get_valid_handle_1( )
  {
    TS_ASSERT_THROWS(platform((cl_platform_id)NULL).get_valid_handle(), uninitialized_platform_error);
  }
  /** // doc: test__get_valid_handle_2() {{{
   * \brief Ensure that get_valid_handle() method works.
   */ // }}}
  void test__get_valid_handle_2( )
  {
    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234ul).get_valid_handle(), (cl_platform_id)0x1234ul);
  }
  /** // doc: test__get_info() {{{
   * \brief Test platform::get_info().
   */ // }}}
  void test__get_info( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS);
    platform((cl_platform_id)0x1234).get_info(platform_info_t::name, 123, (void*)0x4321, (size_t*)0x8765);
    TS_ASSERT(mock.called_once_with((cl_platform_id)0x1234, CL_PLATFORM_NAME, 123, (void*)0x4321, (size_t*)0x8765));
  }
  /** // doc: test__get_info__uninitialized_platform_error() {{{
   * \brief Test platform::get_info() 
   */ // }}}
  void test__get_info__uninitialized_platform_error( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(platform().get_info(platform_info_t::profile, 0, NULL, NULL), uninitialized_platform_error);
  }
  /** // doc: test__get_info__invalid_platform() {{{
   * \brief Test platform::get_info() 
   */ // }}}
  void test__get_info__invalid_platform( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(platform((cl_platform_id)0x34556ul).get_info(platform_info_t::profile, 0, NULL, NULL), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__get_info__invalid_value() {{{
   * \brief Test platform::get_info() 
   */ // }}}
  void test__get_info__invalid_value( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(platform((cl_platform_id)0x34556ul).get_info(platform_info_t::profile, 0, NULL, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_info__out_of_host_memory() {{{
   * \brief Test platform::get_info() 
   */ // }}}
  void test__get_info__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(platform((cl_platform_id)0x34556ul).get_info(platform_info_t::profile, 0, NULL, NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_info__unexpected_clerror() {{{
   * \brief Test platform::get_info() 
   */ // }}}
  void test__get_info__unexpected_clerror( )
  {
    T::Dummy_clGetPlatformInfo mock((cl_int)-0x1234567);
    TS_ASSERT_THROWS(platform((cl_platform_id)0x34556ul).get_info(platform_info_t::profile, 0, NULL, NULL), unexpected_clerror);
  }
  /** // doc: test__get_profile_1() {{{
   * \brief Test get_profile()
   */ // }}}
  void test__get_profile_1( )
  {
    const char* _profile = "FULL_PROFILE";
    size_t _profile_len = std::strlen(_profile) + 1;
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS, _profile, &_profile_len);

    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234).get_profile(), "FULL_PROFILE");

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_PLATFORM_PROFILE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_PLATFORM_PROFILE);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _profile_len);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
//  /** // doc: test__get_version() {{{
//   * \brief Test get_version()
//   */ // }}}
  void test__get_version( )
  {
    const char* _version = "OpenCL 1.2 AMD-APP (1348.4)";
    size_t _version_len = std::strlen(_version) + 1;
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS, _version, &_version_len);

    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234).get_version(), "OpenCL 1.2 AMD-APP (1348.4)");

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_PLATFORM_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_PLATFORM_VERSION);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _version_len);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
//  /** // doc: test__get_name() {{{
//   * \brief Test get_name()
//   */ // }}}
  void test__get_name( )
  {
    const char* _name = "AMD Accelerated Parallel Processing";
    size_t _name_len = std::strlen(_name) + 1;
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS, _name, &_name_len);

    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234).get_name(), "AMD Accelerated Parallel Processing");

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_PLATFORM_NAME);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_PLATFORM_NAME);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _name_len);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
//  /** // doc: test__get_vendor() {{{
//   * \brief Test get_vendor()
//   */ // }}}
  void test__get_vendor( )
  {
    const char* _vendor = "Advanced Micro Devices, Inc.";
    size_t _vendor_len = std::strlen(_vendor) + 1;
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS, _vendor, &_vendor_len);

    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234).get_vendor(), "Advanced Micro Devices, Inc.");

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_PLATFORM_VENDOR);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_PLATFORM_VENDOR);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _vendor_len);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
//  /** // doc: test__get_extensions() {{{
//   * \brief Test get_extensions()
//   */ // }}}
  void test__get_extensions( )
  {
    const char* _extensions = "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices";
    size_t _extensions_len = std::strlen(_extensions) + 1;
    T::Dummy_clGetPlatformInfo mock(CL_SUCCESS, _extensions, &_extensions_len);

    TS_ASSERT_EQUALS(platform((cl_platform_id)0x1234).get_extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().front()), CL_PLATFORM_EXTENSIONS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<3>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<4>(mock.calls().front()) != nullptr);

    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock.calls().back()), CL_PLATFORM_EXTENSIONS);
    TS_ASSERT_EQUALS(std::get<2>(mock.calls().back()), _extensions_len);
    TS_ASSERT(std::get<3>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock.calls().back()) == nullptr);
  }
//  /** // doc: test__eq_op_1() {{{
//   * \brief Test operator==()
//   */ // }}}
  void test__eq_op_1( )
  {
    TS_ASSERT(  platform((cl_platform_id)0x0000) == platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x1234) == platform((cl_platform_id)0x1234));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) == platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x0000) == platform((cl_platform_id)0x1234)));
  }
//  /** // doc: test__neq_op_1() {{{
//   * \brief Test operator!=()
//   */ // }}}
  void test__neq_op_1( )
  {
    TS_ASSERT(!(platform((cl_platform_id)0x0000) != platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) != platform((cl_platform_id)0x1234)));
    TS_ASSERT(  platform((cl_platform_id)0x1234) != platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x0000) != platform((cl_platform_id)0x1234));
  }
//  /** // doc: test__lt_op_1() {{{
//   * \brief Test operator<
//   */ // }}}
  void test__lt_op_1( )
  {
    TS_ASSERT(!(platform((cl_platform_id)0x0000) < platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) < platform((cl_platform_id)0x1234)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) < platform((cl_platform_id)0x0000)));
    TS_ASSERT(  platform((cl_platform_id)0x0000) < platform((cl_platform_id)0x1234));
  }
//  /** // doc: test__gt_op_1() {{{
//   * \brief Test operator>
//   */ // }}}
  void test__gt_op_1( )
  {
    TS_ASSERT(!(platform((cl_platform_id)0x0000) > platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) > platform((cl_platform_id)0x1234)));
    TS_ASSERT(  platform((cl_platform_id)0x1234) > platform((cl_platform_id)0x0000));
    TS_ASSERT(!(platform((cl_platform_id)0x0000) > platform((cl_platform_id)0x1234)));
  }
//  /** // doc: test__le_op_1() {{{
//   * \brief Test operator<=
//   */ // }}}
  void test__le_op_1( )
  {
    TS_ASSERT(  platform((cl_platform_id)0x0000) <= platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x1234) <= platform((cl_platform_id)0x1234));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) <= platform((cl_platform_id)0x0000)));
    TS_ASSERT(  platform((cl_platform_id)0x0000) <= platform((cl_platform_id)0x1234));
  }
//  /** // doc: test__ge_op_1() {{{
//   * \brief Test operator>=
//   */ // }}}
  void test__ge_op_1( )
  {
    TS_ASSERT(  platform((cl_platform_id)0x0000) >= platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x1234) >= platform((cl_platform_id)0x1234));
    TS_ASSERT(  platform((cl_platform_id)0x1234) >= platform((cl_platform_id)0x0000));
    TS_ASSERT(!(platform((cl_platform_id)0x0000) >= platform((cl_platform_id)0x1234)));
  }
  /** // doc: test__out_of_host_memory() {{{
   * \brief Test get_xxx() methods in a situation when clGetPlatformInfo returns status_t::out_of_host_memory.
   */ // }}}
  void test__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_OUT_OF_HOST_MEMORY);
    platform p((cl_platform_id)0x34556ul);
    TS_ASSERT_THROWS(p.get_profile(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_version(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_name(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_vendor(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_extensions(), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__unexpected_clerror() {{{
   * \brief Test get_xxx() methods in a situation when clGetPlatformInfo returns unknown error.
   */ // }}}
  void test__unexpected_clerror( )
  {
    T::Dummy_clGetPlatformInfo mock(-0x432534);
    platform p((cl_platform_id)0x34556ul);
    TS_ASSERT_THROWS(p.get_profile(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_version(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_name(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_vendor(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_extensions(), unexpected_clerror);
  }
//  /** // doc: test__query_platform_info() {{{
//   * \brief Test query_platform_info()
//   */ // }}}
  void test__query_platform_info( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    platform_info info(query_platform_info(p));

    TS_ASSERT_EQUALS(info.profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(info.version(), "OpenCL 1.2 AMD-APP (1348.4)");
    TS_ASSERT_EQUALS(info.name(), "AMD Accelerated Parallel Processing");
    TS_ASSERT_EQUALS(info.vendor(), "Advanced Micro Devices, Inc.");
    TS_ASSERT_EQUALS(info.extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }
};

#endif /* CLXX_CL_PLATFORM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
