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

namespace clxx { class platform_test_suite; }

/** // doc: class clxx::platform_test_suite {{{
 * \brief Unit tests for clxx::platform class
 */ // }}}
class clxx::platform_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_ctor_default() {{{
   * \brief Ensure that id() == NULL by default.
   */ // }}}
  void test_ctor_default( )
  {
    platform p;
    TS_ASSERT_EQUALS(p.id(), reinterpret_cast<cl_platform_id>(NULL));
  }
  /** // doc: test_ctor_assign() {{{
   * \brief Ensure that assigining constructor works as expected.
   */ // }}}
  void test_ctor_assign( )
  {
    platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS(p1.id(), reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_ctor_copy() {{{
   * \brief Ensure that copy constructor works as expected.
   */ // }}}
  void test_ctor_copy( )
  {
    platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    platform p2(p1);
    TS_ASSERT_EQUALS(p2.id(), p1.id());
  }
  /** // doc: test_op_assign() {{{
   * \brief Ensure that assignment operator works.
   */ // }}}
  void test_op_assign( )
  {
    platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    platform p2;
    TS_ASSERT_EQUALS(&(p2 = p1), &p2);
    TS_ASSERT_EQUALS(p2.id(), p1.id());
  }
  /** // doc: test_op_cast() {{{
   * \brief Ensure that conversion operator works.
   */ // }}}
  void test_op_cast( )
  {
    platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS((cl_platform_id)p1, reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_assign() {{{
   * \brief Ensure that assign() method works.
   */ // }}}
  void test_assign( )
  {
    platform p1(reinterpret_cast<cl_platform_id>(0x1234ul));
    platform p2;
    p2.assign(p1);
    TS_ASSERT_EQUALS(p2.id(), p1.id());
  }
  /** // doc: test_is_initialized_1() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_1( )
  {
    platform p;
    TS_ASSERT(!p.is_initialized());
  }
  /** // doc: test_is_initialized_2() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_2( )
  {
    platform p(reinterpret_cast<cl_platform_id>(NULL));
    TS_ASSERT(!p.is_initialized());
  }
  /** // doc: test_is_initialized_3() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_3( )
  {
    platform p(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT(p.is_initialized());
  }
  /** // doc: test_id_1() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_1( )
  {
    platform p(reinterpret_cast<cl_platform_id>(NULL));
    TS_ASSERT_EQUALS(p.id(), reinterpret_cast<cl_platform_id>(NULL));
  }
  /** // doc: test_id_2() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_2( )
  {
    platform p(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS(p.id(), reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_get_valid_id_1() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_1( )
  {
    platform p(reinterpret_cast<cl_platform_id>(NULL));
    TS_ASSERT_THROWS(p.get_valid_id(), uninitialized_platform_error);
  }
  /** // doc: test_get_valid_id_2() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_2( )
  {
    platform p(reinterpret_cast<cl_platform_id>(0x1234ul));
    TS_ASSERT_EQUALS(p.get_valid_id(), reinterpret_cast<cl_platform_id>(0x1234ul));
  }
  /** // doc: test_get_info_wrong_id() {{{
   * \brief Test get_info(platform_info_t::profile, ...) on platform object having wrong id.
   */ // }}}
  void test_get_info_wrong_id( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(reinterpret_cast<cl_platform_id>(0x34556ul));
    TS_ASSERT_THROWS(p.get_info(platform_info_t::profile, 0, NULL, NULL), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test_get_info_0() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test_get_info_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    TS_ASSERT_THROWS(p.get_info(static_cast<platform_info_t>(0), 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_1() {{{
   * \brief Test get_info(platform_info_t::profile, 1, value, NULL).
   */ // }}}
  void test_get_info_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[1];
    TS_ASSERT_THROWS(p.get_info(platform_info_t::profile, 1, value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_profile_0() {{{
   * \brief Test get_info(platform_info_t::profile, 0, NULL, &size).
   */ // }}}
  void test_get_info_profile_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(platform_info_t::profile, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
  /** // doc: test_get_info_profile_1() {{{
   * \brief Test get_info(platform_info_t::profile, ...).
   */ // }}}
  void test_get_info_profile_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[13];
    p.get_info(platform_info_t::profile, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "FULL_PROFILE");
  }
  /** // doc: test_get_info_version_0() {{{
   * \brief Test get_info(platform_info_t::version, 0, NULL, &size).
   */ // }}}
  void test_get_info_version_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(platform_info_t::version, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 28);
  }
//  /** // doc: test_get_info_version_1() {{{
//   * \brief Test get_info(platform_info_t::profile, ...).
//   */ // }}}
  void test_get_info_version_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[28];
    p.get_info(platform_info_t::version, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test_get_info_name_0() {{{
   * \brief Test get_info(platform_info_t::name, 0, NULL, &size).
   */ // }}}
  void test_get_info_name_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(platform_info_t::name, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 36);
  }
//  /** // doc: test_get_info_name_1() {{{
//   * \brief Test get_info(platform_info_t::profile, ...).
//   */ // }}}
  void test_get_info_name_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[36];
    p.get_info(platform_info_t::name, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "AMD Accelerated Parallel Processing");
  }
  /** // doc: test_get_info_vendor_0() {{{
   * \brief Test get_info(platform_info_t::vendor, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(platform_info_t::vendor, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 29);
  }
//  /** // doc: test_get_info_vendor_1() {{{
//   * \brief Test get_info(platform_info_t::profile, ...).
//   */ // }}}
  void test_get_info_vendor_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[29];
    p.get_info(platform_info_t::vendor, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "Advanced Micro Devices, Inc.");
  }
  /** // doc: test_get_info_extensions_0() {{{
   * \brief Test get_info(platform_info_t::extensions, 0, NULL, &size).
   */ // }}}
  void test_get_info_extensions_0( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    size_t size;
    p.get_info(platform_info_t::extensions, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 56);
  }
//  /** // doc: test_get_info_extensions_1() {{{
//   * \brief Test get_info(platform_info_t::profile, ...).
//   */ // }}}
  void test_get_info_extensions_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    char value[56];
    p.get_info(platform_info_t::extensions, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }
  /** // doc: test_get_profile_1() {{{
   * \brief Test get_profile()
   */ // }}}
  void test_get_profile_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_profile(), "FULL_PROFILE");
  }
//  /** // doc: test_get_version_1() {{{
//   * \brief Test get_version()
//   */ // }}}
  void test_get_version_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
//  /** // doc: test_get_name_1() {{{
//   * \brief Test get_name()
//   */ // }}}
  void test_get_name_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_name(), "AMD Accelerated Parallel Processing");
  }
//  /** // doc: test_get_vendor_1() {{{
//   * \brief Test get_vendor()
//   */ // }}}
  void test_get_vendor_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_vendor(), "Advanced Micro Devices, Inc.");
  }
//  /** // doc: test_get_extensions_1() {{{
//   * \brief Test get_extensions()
//   */ // }}}
  void test_get_extensions_1( )
  {
    T::Newton_clGetPlatformInfo mock;
    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }
//  /** // doc: test_eq_op_1() {{{
//   * \brief Test operator==()
//   */ // }}}
  void test_eq_op_1( )
  {
    TS_ASSERT(  platform((cl_platform_id)0x0000) == platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x1234) == platform((cl_platform_id)0x1234));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) == platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x0000) == platform((cl_platform_id)0x1234)));
  }
//  /** // doc: test_neq_op_1() {{{
//   * \brief Test operator!=()
//   */ // }}}
  void test_neq_op_1( )
  {
    TS_ASSERT(!(platform((cl_platform_id)0x0000) != platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) != platform((cl_platform_id)0x1234)));
    TS_ASSERT(  platform((cl_platform_id)0x1234) != platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x0000) != platform((cl_platform_id)0x1234));
  }
//  /** // doc: test_lt_op_1() {{{
//   * \brief Test operator<
//   */ // }}}
  void test_lt_op_1( )
  {
    TS_ASSERT(!(platform((cl_platform_id)0x0000) < platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) < platform((cl_platform_id)0x1234)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) < platform((cl_platform_id)0x0000)));
    TS_ASSERT(  platform((cl_platform_id)0x0000) < platform((cl_platform_id)0x1234));
  }
//  /** // doc: test_gt_op_1() {{{
//   * \brief Test operator>
//   */ // }}}
  void test_gt_op_1( )
  {
    TS_ASSERT(!(platform((cl_platform_id)0x0000) > platform((cl_platform_id)0x0000)));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) > platform((cl_platform_id)0x1234)));
    TS_ASSERT(  platform((cl_platform_id)0x1234) > platform((cl_platform_id)0x0000));
    TS_ASSERT(!(platform((cl_platform_id)0x0000) > platform((cl_platform_id)0x1234)));
  }
//  /** // doc: test_le_op_1() {{{
//   * \brief Test operator<=
//   */ // }}}
  void test_le_op_1( )
  {
    TS_ASSERT(  platform((cl_platform_id)0x0000) <= platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x1234) <= platform((cl_platform_id)0x1234));
    TS_ASSERT(!(platform((cl_platform_id)0x1234) <= platform((cl_platform_id)0x0000)));
    TS_ASSERT(  platform((cl_platform_id)0x0000) <= platform((cl_platform_id)0x1234));
  }
//  /** // doc: test_ge_op_1() {{{
//   * \brief Test operator>=
//   */ // }}}
  void test_ge_op_1( )
  {
    TS_ASSERT(  platform((cl_platform_id)0x0000) >= platform((cl_platform_id)0x0000));
    TS_ASSERT(  platform((cl_platform_id)0x1234) >= platform((cl_platform_id)0x1234));
    TS_ASSERT(  platform((cl_platform_id)0x1234) >= platform((cl_platform_id)0x0000));
    TS_ASSERT(!(platform((cl_platform_id)0x0000) >= platform((cl_platform_id)0x1234)));
  }
//  /** // doc: test_bool_op_1() {{{
//   * \brief Test operator bool
//   */ // }}}
  void test_bool_op_1( )
  {
    TS_ASSERT((bool)platform((cl_platform_id)0x1234));
    TS_ASSERT(!(bool)platform((cl_platform_id)0x000));
  }
// sorry, but this may irritate OOM instead of throwing bad_alloc
//  /** // doc: test_negsize() {{{
//   * \brief Test get_xxx() methods in a situation when clGetPlatformInfo returns negative string size.
//   */ // }}}
//  void test_negsize( )
//  {
//    T::SizeRet_clGetPlatformInfo mock(-64);
//    platform p(reinterpret_cast<cl_platform_id>(0x34556ul));
//    TS_ASSERT_THROWS(p.get_profile(), CLXX_EXCEPTION(Bad_Alloc));
//    TS_ASSERT_THROWS(p.get_version(), CLXX_EXCEPTION(Bad_Alloc));
//    TS_ASSERT_THROWS(p.get_name(), CLXX_EXCEPTION(Bad_Alloc));
//    TS_ASSERT_THROWS(p.get_vendor(), CLXX_EXCEPTION(Bad_Alloc));
//    TS_ASSERT_THROWS(p.get_extensions(), CLXX_EXCEPTION(Bad_Alloc));
//  }
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() methods in a situation when clGetPlatformInfo returns status_t::out_of_host_memory.
   */ // }}}
  void test_out_of_host_memory( )
  {
    T::Dummy_clGetPlatformInfo mock(CL_OUT_OF_HOST_MEMORY);
    platform p(reinterpret_cast<cl_platform_id>(0x34556ul));
    TS_ASSERT_THROWS(p.get_profile(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_version(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_name(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_vendor(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(p.get_extensions(), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() methods in a situation when clGetPlatformInfo returns unknown error.
   */ // }}}
  void test_other_error( )
  {
    T::Dummy_clGetPlatformInfo mock(-0x432534);
    platform p(reinterpret_cast<cl_platform_id>(0x34556ul));
    TS_ASSERT_THROWS(p.get_profile(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_version(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_name(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_vendor(), unexpected_clerror);
    TS_ASSERT_THROWS(p.get_extensions(), unexpected_clerror);
  }
//  /** // doc: test_query_platform_info_1() {{{
//   * \todo Write documentation
//   */ // }}}
//  void test_query_platform_info_1( )
//  {
//    T::Newton_clGetPlatformInfo mock;
//    platform p(T::Newton_clGetPlatformIDs::platforms[0]);
//    Dimbo::Clinfo::Platform_Info info(query_platform_info(p));
//    TS_ASSERT_EQUALS(info.profile(), "FULL_PROFILE");
//    TS_ASSERT_EQUALS(info.version(), "OpenCL 1.2 AMD-APP (1348.4)");
//    TS_ASSERT_EQUALS(info.name(), "AMD Accelerated Parallel Processing");
//    TS_ASSERT_EQUALS(info.vendor(), "Advanced Micro Devices, Inc.");
//    TS_ASSERT_EQUALS(info.extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
//  }
//  /** // doc: test_query_platform_info_2() {{{
//   * \todo Write documentation
//   */ // }}}
//  void test_query_platform_info_2( )
//  {
//    T::Newton_clGetPlatformInfo mock;
//    platform p(T::Newton_clGetPlatformIDs::platforms[1]);
//    Dimbo::Clinfo::Platform_Info info(query_platform_info(p));
//    TS_ASSERT_EQUALS(info.profile(), "FULL_PROFILE");
//    TS_ASSERT_EQUALS(info.version(), "OpenCL 1.1 CUDA 4.2.1");
//    TS_ASSERT_EQUALS(info.name(), "NVIDIA CUDA");
//    TS_ASSERT_EQUALS(info.vendor(), "NVIDIA Corporation");
//    TS_ASSERT_EQUALS(info.extensions(), "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll");
//  }
};

#endif /* CLXX_CL_PLATFORM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
