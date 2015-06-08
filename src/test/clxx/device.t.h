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
#include <clxx/device.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class device_test_suite; }

/** // doc: class clxx::device_test_suite {{{
 * \brief Unit tests for clxx::device class
 */ // }}}
class clxx::device_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_ctor_default() {{{
   * \brief Ensure that id() == NULL by default.
   */ // }}}
  void test_ctor_default( )
  {
    device d;
    TS_ASSERT_EQUALS(d.id(), reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_ctor_assign() {{{
   * \brief Ensure that assigining constructor works as expected.
   */ // }}}
  void test_ctor_assign( )
  {
    device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS(d1.id(), reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_ctor_copy() {{{
   * \brief Ensure that copy constructor works as expected.
   */ // }}}
  void test_ctor_copy( )
  {
    device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    device d2(d1);
    TS_ASSERT_EQUALS(d2.id(), d1.id());
  }
  /** // doc: test_op_assign() {{{
   * \brief Ensure that assignment operator works.
   */ // }}}
  void test_op_assign( )
  {
    device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    device d2;
    TS_ASSERT_EQUALS(&(d2 = d1), &d2);
    TS_ASSERT_EQUALS(d2.id(), d1.id());
  }
  /** // doc: test_op_cast() {{{
   * \brief Ensure that conversion operator works.
   */ // }}}
  void test_op_cast( )
  {
    device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS((cl_device_id)d1, reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_assign() {{{
   * \brief Ensure that assign() method works.
   */ // }}}
  void test_assign( )
  {
    device d1(reinterpret_cast<cl_device_id>(0x1234ul));
    device d2;
    d2.assign(d1);
    TS_ASSERT_EQUALS(d2.id(), d1.id());
  }
  /** // doc: test_is_initialized_1() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_1( )
  {
    device d;
    TS_ASSERT(!d.is_initialized());
  }
  /** // doc: test_is_initialized_2() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_2( )
  {
    device d(reinterpret_cast<cl_device_id>(NULL));
    TS_ASSERT(!d.is_initialized());
  }
  /** // doc: test_is_initialized_3() {{{
   * \brief Ensure that is_initialized() method works.
   */ // }}}
  void test_is_initialized_3( )
  {
    device d(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT(d.is_initialized());
  }
  /** // doc: test_id_1() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_1( )
  {
    device d(reinterpret_cast<cl_device_id>(NULL));
    TS_ASSERT_EQUALS(d.id(),reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_id_2() {{{
   * \brief Ensure that id() method works.
   */ // }}}
  void test_id_2( )
  {
    device d(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS(d.id(),reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_get_valid_id_1() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_1( )
  {
    device d(reinterpret_cast<cl_device_id>(NULL));
    TS_ASSERT_THROWS(d.get_valid_id(), uninitialized_device_error);
  }
  /** // doc: test_get_valid_id_2() {{{
   * \brief Ensure that get_valid_id() method works.
   */ // }}}
  void test_get_valid_id_2( )
  {
    device d(reinterpret_cast<cl_device_id>(0x1234ul));
    TS_ASSERT_EQUALS(d.get_valid_id(),reinterpret_cast<cl_device_id>(0x1234ul));
  }
  /** // doc: test_get_info_wrong_id() {{{
   * \brief Test get_info(device_info_t::profile, ...) on device object having wrong id.
   */ // }}}
  void test_get_info_wrong_id( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(reinterpret_cast<cl_device_id>(0x34556ul));
    TS_ASSERT_THROWS(d.get_info(device_info_t::profile, 0, NULL, NULL), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test_get_info_0() {{{
   * \brief Test get_info(0, ...).
   */ // }}}
  void test_get_info_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(static_cast<device_info_t>(0), 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_1() {{{
   * \brief Test get_info(device_info_t::profile, 1, &value, NULL).
   */ // }}}
  void test_get_info_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    char value[1];
    TS_ASSERT_THROWS(d.get_info(device_info_t::profile, 1, &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_type_0() {{{
   * \brief Test get_info(device_info_t::type, 0, NULL, &size).
   */ // }}}
  void test_get_info_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::type, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(device_type_t));
  }
  /** // doc: test_get_info_type_1() {{{
   * \brief Test get_info(device_info_t::type, ...).
   */ // }}}
  void test_get_info_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_type_t value;
    d.get_info(device_info_t::type, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_type_t::cpu);
  }
  /** // doc: test_get_info_vendor_id_0() {{{
   * \brief Test get_info(device_info_t::vendor_id, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_id_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::vendor_id, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_vendor_id_1() {{{
   * \brief Test get_info(device_info_t::vendor_id, ...).
   */ // }}}
  void test_get_info_vendor_id_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::vendor_id, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0x1002);
  }
  /** // doc: test_get_info_vendor_id_2() {{{
   * \brief Test get_info(device_info_t::vendor_id, ...).
   */ // }}}
  void test_get_info_vendor_id_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::vendor_id, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0x10de);
  }
  /** // doc: test_get_info_max_compute_units_0() {{{
   * \brief Test get_info(device_info_t::max_compute_units, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_compute_units_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_compute_units, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_compute_units_1() {{{
   * \brief Test get_info(device_info_t::max_compute_units, ...).
   */ // }}}
  void test_get_info_max_compute_units_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::max_compute_units, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_max_compute_units_2() {{{
   * \brief Test get_info(device_info_t::max_compute_units, ...).
   */ // }}}
  void test_get_info_max_compute_units_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::max_compute_units, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 30);
  }
  /** // doc: test_get_info_max_work_item_dimensions_0() {{{
   * \brief Test get_info(device_info_t::max_work_item_dimensions, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_work_item_dimensions_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_work_item_dimensions, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_work_item_dimensions_1() {{{
   * \brief Test get_info(device_info_t::max_work_item_dimensions, ...).
   */ // }}}
  void test_get_info_max_work_item_dimensions_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::max_work_item_dimensions, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 3);
  }
  /** // doc: test_get_info_max_work_item_dimensions_2() {{{
   * \brief Test get_info(device_info_t::max_work_item_dimensions, ...).
   */ // }}}
  void test_get_info_max_work_item_dimensions_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::max_work_item_dimensions, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 3);
  }
  /** // doc: test_get_info_max_work_item_sizes_0() {{{
   * \brief Test get_info(device_info_t::max_work_item_sizes, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_work_item_sizes_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_work_item_sizes, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 3 * sizeof(size_t));
  }
  /** // doc: test_get_info_max_work_item_sizes_1() {{{
   * \brief Test get_info(device_info_t::max_work_item_sizes, ...).
   */ // }}}
  void test_get_info_max_work_item_sizes_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value[3];
    d.get_info(device_info_t::max_work_item_sizes, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], 1024);
    TS_ASSERT_EQUALS(value[1], 1024);
    TS_ASSERT_EQUALS(value[2], 1024);
  }
  /** // doc: test_get_info_max_work_item_sizes_2() {{{
   * \brief Test get_info(device_info_t::max_work_item_sizes, ...).
   */ // }}}
  void test_get_info_max_work_item_sizes_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value[3];
    d.get_info(device_info_t::max_work_item_sizes, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], 512);
    TS_ASSERT_EQUALS(value[1], 512);
    TS_ASSERT_EQUALS(value[2], 64);
  }
  /** // doc: test_get_info_max_work_group_size_0() {{{
   * \brief Test get_info(device_info_t::max_work_group_size, 0, NULL, &size).
   */ // }}}
  void test_get_info_max_work_group_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_work_group_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_max_work_group_size_1() {{{
   * \brief Test get_info(device_info_t::max_work_group_size, ...).
   */ // }}}
  void test_get_info_max_work_group_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::max_work_group_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1024);
  }
  /** // doc: test_get_info_max_work_group_size_2() {{{
   * \brief Test get_info(device_info_t::max_work_group_size, ...).
   */ // }}}
  void test_get_info_max_work_group_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::max_work_group_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 512);
  }
  /** // doc: test_get_info_preferred_vector_width_char_0() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_char, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_char_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_vector_width_char, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_char_1() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_char, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_char_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_char, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_preferred_vector_width_char_2() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_char, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_char_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_char, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_short_0() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_short, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_short_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_vector_width_short, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_short_1() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_short, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_short_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_short, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_preferred_vector_width_short_2() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_short, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_short_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_short, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_int_0() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_int, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_int_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_vector_width_int, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_int_1() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_int, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_int_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_int, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_preferred_vector_width_int_2() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_int, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_int_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_int, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_long_0() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_long, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_long_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_vector_width_long, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_long_1() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_long, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_long_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_long, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_preferred_vector_width_long_2() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_long, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_long_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_long, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_float_0() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_float, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_float_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_vector_width_float, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_float_1() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_float, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_float_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_float, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_preferred_vector_width_float_2() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_float, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_float_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_float, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_preferred_vector_width_double_0() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_double, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_double_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_vector_width_double, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_double_1() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_double, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_double_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_double, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_preferred_vector_width_double_2() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_double, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_double_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_double, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_max_clock_frequency_0() {{{ * \brief Test get_info(device_info_t::max_clock_frequency, 0, NULL, &size).  */ // }}}
  void test_get_info_max_clock_frequency_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_clock_frequency, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_clock_frequency_1() {{{
   * \brief Test get_info(device_info_t::max_clock_frequency, ...).
   */ // }}}
  void test_get_info_max_clock_frequency_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::max_clock_frequency, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2401);
  }
  /** // doc: test_get_info_max_clock_frequency_2() {{{
   * \brief Test get_info(device_info_t::max_clock_frequency, ...).
   */ // }}}
  void test_get_info_max_clock_frequency_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::max_clock_frequency, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1296);
  }
  /** // doc: test_get_info_address_bits_0() {{{ * \brief Test get_info(device_info_t::address_bits, 0, NULL, &size).  */ // }}}
  void test_get_info_address_bits_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::address_bits, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_address_bits_1() {{{
   * \brief Test get_info(device_info_t::address_bits, ...).
   */ // }}}
  void test_get_info_address_bits_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::address_bits, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 64);
  }
  /** // doc: test_get_info_address_bits_2() {{{
   * \brief Test get_info(device_info_t::address_bits, ...).
   */ // }}}
  void test_get_info_address_bits_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::address_bits, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 32);
  }
  /** // doc: test_get_info_max_mem_alloc_size_0() {{{ * \brief Test get_info(device_info_t::max_mem_alloc_size, 0, NULL, &size).  */ // }}}
  void test_get_info_max_mem_alloc_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_mem_alloc_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_max_mem_alloc_size_1() {{{
   * \brief Test get_info(device_info_t::max_mem_alloc_size, ...).
   */ // }}}
  void test_get_info_max_mem_alloc_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(device_info_t::max_mem_alloc_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4214191104ul);
  }
  /** // doc: test_get_info_max_mem_alloc_size_2() {{{
   * \brief Test get_info(device_info_t::max_mem_alloc_size, ...).
   */ // }}}
  void test_get_info_max_mem_alloc_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(device_info_t::max_mem_alloc_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1073692672ul);
  }
  /** // doc: test_get_info_image_support_0() {{{ * \brief Test get_info(device_info_t::image_support, 0, NULL, &size).  */ // }}}
  void test_get_info_image_support_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image_support, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_image_support_1() {{{
   * \brief Test get_info(device_info_t::image_support, ...).
   */ // }}}
  void test_get_info_image_support_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::image_support, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_image_support_2() {{{
   * \brief Test get_info(device_info_t::image_support, ...).
   */ // }}}
  void test_get_info_image_support_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(device_info_t::image_support, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_max_read_image_args_0() {{{ * \brief Test get_info(device_info_t::max_read_image_args, 0, NULL, &size).  */ // }}}
  void test_get_info_max_read_image_args_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_read_image_args, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_read_image_args_1() {{{
   * \brief Test get_info(device_info_t::max_read_image_args, ...).
   */ // }}}
  void test_get_info_max_read_image_args_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::max_read_image_args, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_max_read_image_args_2() {{{
   * \brief Test get_info(device_info_t::max_read_image_args, ...).
   */ // }}}
  void test_get_info_max_read_image_args_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::max_read_image_args, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_max_write_image_args_0() {{{ * \brief Test get_info(device_info_t::max_write_image_args, 0, NULL, &size).  */ // }}}
  void test_get_info_max_write_image_args_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_write_image_args, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_write_image_args_1() {{{
   * \brief Test get_info(device_info_t::max_write_image_args, ...).
   */ // }}}
  void test_get_info_max_write_image_args_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::max_write_image_args, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_max_write_image_args_2() {{{
   * \brief Test get_info(device_info_t::max_write_image_args, ...).
   */ // }}}
  void test_get_info_max_write_image_args_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::max_write_image_args, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_image2d_max_width_0() {{{ * \brief Test get_info(device_info_t::image2d_max_width, 0, NULL, &size).  */ // }}}
  void test_get_info_image2d_max_width_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image2d_max_width, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image2d_max_width_1() {{{
   * \brief Test get_info(device_info_t::image2d_max_width, ...).
   */ // }}}
  void test_get_info_image2d_max_width_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::image2d_max_width, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8192);
  }
  /** // doc: test_get_info_image2d_max_width_2() {{{
   * \brief Test get_info(device_info_t::image2d_max_width, ...).
   */ // }}}
  void test_get_info_image2d_max_width_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::image2d_max_width, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4096);
  }
  /** // doc: test_get_info_image2d_max_height_0() {{{ * \brief Test get_info(device_info_t::image2d_max_height, 0, NULL, &size).  */ // }}}
  void test_get_info_image2d_max_height_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image2d_max_height, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image2d_max_height_1() {{{
   * \brief Test get_info(device_info_t::image2d_max_height, ...).
   */ // }}}
  void test_get_info_image2d_max_height_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::image2d_max_height, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8192);
  }
  /** // doc: test_get_info_image2d_max_height_2() {{{
   * \brief Test get_info(device_info_t::image2d_max_height, ...).
   */ // }}}
  void test_get_info_image2d_max_height_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::image2d_max_height, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16383);
  }
  /** // doc: test_get_info_image3d_max_width_0() {{{ * \brief Test get_info(device_info_t::image3d_max_width, 0, NULL, &size).  */ // }}}
  void test_get_info_image3d_max_width_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image3d_max_width, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image3d_max_width_1() {{{
   * \brief Test get_info(device_info_t::image3d_max_width, ...).
   */ // }}}
  void test_get_info_image3d_max_width_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::image3d_max_width, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_width_2() {{{
   * \brief Test get_info(device_info_t::image3d_max_width, ...).
   */ // }}}
  void test_get_info_image3d_max_width_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::image3d_max_width, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_height_0() {{{ * \brief Test get_info(device_info_t::image3d_max_height, 0, NULL, &size).  */ // }}}
  void test_get_info_image3d_max_height_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image3d_max_height, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image3d_max_height_1() {{{
   * \brief Test get_info(device_info_t::image3d_max_height, ...).
   */ // }}}
  void test_get_info_image3d_max_height_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::image3d_max_height, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_height_2() {{{
   * \brief Test get_info(device_info_t::image3d_max_height, ...).
   */ // }}}
  void test_get_info_image3d_max_height_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::image3d_max_height, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_depth_0() {{{ * \brief Test get_info(device_info_t::image3d_max_depth, 0, NULL, &size).  */ // }}}
  void test_get_info_image3d_max_depth_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image3d_max_depth, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image3d_max_depth_1() {{{
   * \brief Test get_info(device_info_t::image3d_max_depth, ...).
   */ // }}}
  void test_get_info_image3d_max_depth_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::image3d_max_depth, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image3d_max_depth_2() {{{
   * \brief Test get_info(device_info_t::image3d_max_depth, ...).
   */ // }}}
  void test_get_info_image3d_max_depth_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::image3d_max_depth, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_max_samplers_0() {{{ * \brief Test get_info(device_info_t::max_samplers, 0, NULL, &size).  */ // }}}
  void test_get_info_max_samplers_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_samplers, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_samplers_1() {{{
   * \brief Test get_info(device_info_t::max_samplers, ...).
   */ // }}}
  void test_get_info_max_samplers_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::max_samplers, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_max_samplers_2() {{{
   * \brief Test get_info(device_info_t::max_samplers, ...).
   */ // }}}
  void test_get_info_max_samplers_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::max_samplers, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_max_parameter_size_0() {{{ * \brief Test get_info(device_info_t::max_parameter_size, 0, NULL, &size).  */ // }}}
  void test_get_info_max_parameter_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_parameter_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_max_parameter_size_1() {{{
   * \brief Test get_info(device_info_t::max_parameter_size, ...).
   */ // }}}
  void test_get_info_max_parameter_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::max_parameter_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4096);
  }
  /** // doc: test_get_info_max_parameter_size_2() {{{
   * \brief Test get_info(device_info_t::max_parameter_size, ...).
   */ // }}}
  void test_get_info_max_parameter_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::max_parameter_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4352);
  }
  /** // doc: test_get_info_mem_base_addr_align_0() {{{ * \brief Test get_info(device_info_t::mem_base_addr_align, 0, NULL, &size).  */ // }}}
  void test_get_info_mem_base_addr_align_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::mem_base_addr_align, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_mem_base_addr_align_1() {{{
   * \brief Test get_info(device_info_t::mem_base_addr_align, ...).
   */ // }}}
  void test_get_info_mem_base_addr_align_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::mem_base_addr_align, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1024);
  }
  /** // doc: test_get_info_mem_base_addr_align_2() {{{
   * \brief Test get_info(device_info_t::mem_base_addr_align, ...).
   */ // }}}
  void test_get_info_mem_base_addr_align_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::mem_base_addr_align, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_min_data_type_align_size_0() {{{ * \brief Test get_info(device_info_t::min_data_type_align_size, 0, NULL, &size).  */ // }}}
  void test_get_info_min_data_type_align_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::min_data_type_align_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_min_data_type_align_size_1() {{{
   * \brief Test get_info(device_info_t::min_data_type_align_size, ...).
   */ // }}}
  void test_get_info_min_data_type_align_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::min_data_type_align_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_min_data_type_align_size_2() {{{
   * \brief Test get_info(device_info_t::min_data_type_align_size, ...).
   */ // }}}
  void test_get_info_min_data_type_align_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::min_data_type_align_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 128);
  }
  /** // doc: test_get_info_single_fp_config_0() {{{ * \brief Test get_info(device_info_t::single_fp_config, 0, NULL, &size).  */ // }}}
  void test_get_info_single_fp_config_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::single_fp_config, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(device_fp_config_t));
  }
  /** // doc: test_get_info_single_fp_config_1() {{{
   * \brief Test get_info(device_info_t::single_fp_config, ...).
   */ // }}}
  void test_get_info_single_fp_config_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_fp_config_t value;
    d.get_info(device_info_t::single_fp_config, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_fp_config_t::denorm
                          | device_fp_config_t::inf_nan
                          | device_fp_config_t::round_to_nearest
                          | device_fp_config_t::round_to_zero
                          | device_fp_config_t::round_to_inf
                          | device_fp_config_t::fma);
  }
  /** // doc: test_get_info_single_fp_config_2() {{{
   * \brief Test get_info(device_info_t::single_fp_config, ...).
   */ // }}}
  void test_get_info_single_fp_config_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_fp_config_t value;
    d.get_info(device_info_t::single_fp_config, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_fp_config_t::inf_nan
                          | device_fp_config_t::round_to_nearest
                          | device_fp_config_t::round_to_zero
                          | device_fp_config_t::round_to_inf
                          | device_fp_config_t::fma);
  }
  /** // doc: test_get_info_global_mem_cache_type_0() {{{ * \brief Test get_info(device_info_t::global_mem_cache_type, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_cache_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::global_mem_cache_type, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(device_mem_cache_type_t));
  }
  /** // doc: test_get_info_global_mem_cache_type_1() {{{
   * \brief Test get_info(device_info_t::global_mem_cache_type, ...).
   */ // }}}
  void test_get_info_global_mem_cache_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_mem_cache_type_t value;
    d.get_info(device_info_t::global_mem_cache_type, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_mem_cache_type_t::read_write_cache);
  }
  /** // doc: test_get_info_global_mem_cache_type_2() {{{
   * \brief Test get_info(device_info_t::global_mem_cache_type, ...).
   */ // }}}
  void test_get_info_global_mem_cache_type_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_mem_cache_type_t value;
    d.get_info(device_info_t::global_mem_cache_type, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_mem_cache_type_t::none);
  }
  /** // doc: test_get_info_global_mem_cacheline_size_0() {{{ * \brief Test get_info(device_info_t::global_mem_cacheline_size, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_cacheline_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::global_mem_cacheline_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_global_mem_cacheline_size_1() {{{
   * \brief Test get_info(device_info_t::global_mem_cacheline_size, ...).
   */ // }}}
  void test_get_info_global_mem_cacheline_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::global_mem_cacheline_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 64);
  }
  /** // doc: test_get_info_global_mem_cacheline_size_2() {{{
   * \brief Test get_info(device_info_t::global_mem_cacheline_size, ...).
   */ // }}}
  void test_get_info_global_mem_cacheline_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::global_mem_cacheline_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_global_mem_cache_size_0() {{{ * \brief Test get_info(device_info_t::global_mem_cache_size, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_cache_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::global_mem_cache_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_global_mem_cache_size_1() {{{
   * \brief Test get_info(device_info_t::global_mem_cache_size, ...).
   */ // }}}
  void test_get_info_global_mem_cache_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(device_info_t::global_mem_cache_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 32768ul);
  }
  /** // doc: test_get_info_global_mem_cache_size_2() {{{
   * \brief Test get_info(device_info_t::global_mem_cache_size, ...).
   */ // }}}
  void test_get_info_global_mem_cache_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(device_info_t::global_mem_cache_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_global_mem_size_0() {{{ * \brief Test get_info(device_info_t::global_mem_size, 0, NULL, &size).  */ // }}}
  void test_get_info_global_mem_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::global_mem_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_global_mem_size_1() {{{
   * \brief Test get_info(device_info_t::global_mem_size, ...).
   */ // }}}
  void test_get_info_global_mem_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(device_info_t::global_mem_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16856764416ul);
  }
  /** // doc: test_get_info_global_mem_size_2() {{{
   * \brief Test get_info(device_info_t::global_mem_size, ...).
   */ // }}}
  void test_get_info_global_mem_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(device_info_t::global_mem_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4294770688ul);
  }
  /** // doc: test_get_info_max_constant_buffer_size_0() {{{ * \brief Test get_info(device_info_t::max_constant_buffer_size, 0, NULL, &size).  */ // }}}
  void test_get_info_max_constant_buffer_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_constant_buffer_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_max_constant_buffer_size_1() {{{
   * \brief Test get_info(device_info_t::max_constant_buffer_size, ...).
   */ // }}}
  void test_get_info_max_constant_buffer_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(device_info_t::max_constant_buffer_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_max_constant_buffer_size_2() {{{
   * \brief Test get_info(device_info_t::max_constant_buffer_size, ...).
   */ // }}}
  void test_get_info_max_constant_buffer_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(device_info_t::max_constant_buffer_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_max_constant_args_0() {{{ * \brief Test get_info(device_info_t::max_constant_args, 0, NULL, &size).  */ // }}}
  void test_get_info_max_constant_args_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::max_constant_args, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_max_constant_args_1() {{{
   * \brief Test get_info(device_info_t::max_constant_args, ...).
   */ // }}}
  void test_get_info_max_constant_args_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::max_constant_args, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_max_constant_args_2() {{{
   * \brief Test get_info(device_info_t::max_constant_args, ...).
   */ // }}}
  void test_get_info_max_constant_args_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::max_constant_args, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 9);
  }
  /** // doc: test_get_info_local_mem_type_0() {{{ * \brief Test get_info(device_info_t::local_mem_type, 0, NULL, &size).  */ // }}}
  void test_get_info_local_mem_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::local_mem_type, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(device_local_mem_type_t));
  }
  /** // doc: test_get_info_local_mem_type_1() {{{
   * \brief Test get_info(device_info_t::local_mem_type, ...).
   */ // }}}
  void test_get_info_local_mem_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_local_mem_type_t value;
    d.get_info(device_info_t::local_mem_type, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_local_mem_type_t::global);
  }
  /** // doc: test_get_info_local_mem_type_2() {{{
   * \brief Test get_info(device_info_t::local_mem_type, ...).
   */ // }}}
  void test_get_info_local_mem_type_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_local_mem_type_t value;
    d.get_info(device_info_t::local_mem_type, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_local_mem_type_t::local);
  }
  /** // doc: test_get_info_local_mem_size_0() {{{ * \brief Test get_info(device_info_t::local_mem_size, 0, NULL, &size).  */ // }}}
  void test_get_info_local_mem_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::local_mem_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_ulong));
  }
  /** // doc: test_get_info_local_mem_size_1() {{{
   * \brief Test get_info(device_info_t::local_mem_size, ...).
   */ // }}}
  void test_get_info_local_mem_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_ulong value;
    d.get_info(device_info_t::local_mem_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 32768);
  }
  /** // doc: test_get_info_local_mem_size_2() {{{
   * \brief Test get_info(device_info_t::local_mem_size, ...).
   */ // }}}
  void test_get_info_local_mem_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_ulong value;
    d.get_info(device_info_t::local_mem_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16384);
  }
  /** // doc: test_get_info_error_correction_support_0() {{{ * \brief Test get_info(device_info_t::error_correction_support, 0, NULL, &size).  */ // }}}
  void test_get_info_error_correction_support_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::error_correction_support, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_error_correction_support_1() {{{
   * \brief Test get_info(device_info_t::error_correction_support, ...).
   */ // }}}
  void test_get_info_error_correction_support_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::error_correction_support, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_error_correction_support_2() {{{
   * \brief Test get_info(device_info_t::error_correction_support, ...).
   */ // }}}
  void test_get_info_error_correction_support_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(device_info_t::error_correction_support, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_profiling_timer_resolution_0() {{{ * \brief Test get_info(device_info_t::profiling_timer_resolution, 0, NULL, &size).  */ // }}}
  void test_get_info_profiling_timer_resolution_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::profiling_timer_resolution, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_profiling_timer_resolution_1() {{{
   * \brief Test get_info(device_info_t::profiling_timer_resolution, ...).
   */ // }}}
  void test_get_info_profiling_timer_resolution_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::profiling_timer_resolution, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_profiling_timer_resolution_2() {{{
   * \brief Test get_info(device_info_t::profiling_timer_resolution, ...).
   */ // }}}
  void test_get_info_profiling_timer_resolution_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    d.get_info(device_info_t::profiling_timer_resolution, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1000);
  }
  /** // doc: test_get_info_endian_little_0() {{{ * \brief Test get_info(device_info_t::endian_little, 0, NULL, &size).  */ // }}}
  void test_get_info_endian_little_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::endian_little, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_endian_little_1() {{{
   * \brief Test get_info(device_info_t::endian_little, ...).
   */ // }}}
  void test_get_info_endian_little_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::endian_little, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_endian_little_2() {{{
   * \brief Test get_info(device_info_t::endian_little, ...).
   */ // }}}
  void test_get_info_endian_little_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(device_info_t::endian_little, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_available_0() {{{ * \brief Test get_info(device_info_t::available, 0, NULL, &size).  */ // }}}
  void test_get_info_available_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::available, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_available_1() {{{
   * \brief Test get_info(device_info_t::available, ...).
   */ // }}}
  void test_get_info_available_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::available, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_available_2() {{{
   * \brief Test get_info(device_info_t::available, ...).
   */ // }}}
  void test_get_info_available_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(device_info_t::available, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_compiler_available_0() {{{ * \brief Test get_info(device_info_t::compiler_available, 0, NULL, &size).  */ // }}}
  void test_get_info_compiler_available_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::compiler_available, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_compiler_available_1() {{{
   * \brief Test get_info(device_info_t::compiler_available, ...).
   */ // }}}
  void test_get_info_compiler_available_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::compiler_available, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_compiler_available_2() {{{
   * \brief Test get_info(device_info_t::compiler_available, ...).
   */ // }}}
  void test_get_info_compiler_available_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(device_info_t::compiler_available, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_execution_capabilities_0() {{{
   *  \brief Test get_info(device_info_t::execution_capabilities, 0, NULL, &size).
   */ // }}}
  void test_get_info_execution_capabilities_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::execution_capabilities, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(device_exec_capabilities_t));
  }
  /** // doc: test_get_info_execution_capabilities_1() {{{
   * \brief Test get_info(device_info_t::execution_capabilities, ...).
   */ // }}}
  void test_get_info_execution_capabilities_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_exec_capabilities_t value;
    d.get_info(device_info_t::execution_capabilities, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_exec_capabilities_t::kernel | device_exec_capabilities_t::native_kernel);
  }
  /** // doc: test_get_info_execution_capabilities_2() {{{
   * \brief Test get_info(device_info_t::execution_capabilities, ...).
   */ // }}}
  void test_get_info_execution_capabilities_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_exec_capabilities_t value;
    d.get_info(device_info_t::execution_capabilities, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_exec_capabilities_t::kernel);
  }
  /** // doc: test_get_info_queue_properties_0() {{{ * \brief Test get_info(device_info_t::queue_properties, 0, NULL, &size).  */ // }}}
  void test_get_info_queue_properties_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::queue_properties, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(command_queue_properties_t));
  }
  /** // doc: test_get_info_queue_properties_1() {{{
   * \brief Test get_info(device_info_t::queue_properties, ...).
   */ // }}}
  void test_get_info_queue_properties_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    command_queue_properties_t value;
    d.get_info(device_info_t::queue_properties, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, command_queue_properties_t::profiling_enable);
  }
  /** // doc: test_get_info_queue_properties_2() {{{
   * \brief Test get_info(device_info_t::queue_properties, ...).
   */ // }}}
  void test_get_info_queue_properties_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    command_queue_properties_t value;
    d.get_info(device_info_t::queue_properties, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, command_queue_properties_t::out_of_order_exec_mode_enable | command_queue_properties_t::profiling_enable);
  }
  /** // doc: test_get_info_platform_0() {{{ * \brief Test get_info(device_info_t::platform, 0, NULL, &size).  */ // }}}
  void test_get_info_platform_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::platform, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_platform_id));
  }
  /** // doc: test_get_info_platform_1() {{{
   * \brief Test get_info(device_info_t::platform, ...).
   */ // }}}
  void test_get_info_platform_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_platform_id value;
    d.get_info(device_info_t::platform, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, T::Newton_clGetPlatformIDs::platforms[0]);
  }
  /** // doc: test_get_info_platform_2() {{{
   * \brief Test get_info(device_info_t::platform, ...).
   */ // }}}
  void test_get_info_platform_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_platform_id value;
    d.get_info(device_info_t::platform, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_info_name_0() {{{
   * \brief Test get_info(device_info_t::name, 0, NULL, &size).
   */ // }}}
  void test_get_info_name_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(device_info_t::name, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 48);
  }
  /** // doc: test_get_info_name_1() {{{
   * \brief Test get_info(device_info_t::name, 0, NULL, &size).
   */ // }}}
  void test_get_info_name_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(device_info_t::name, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 12);
  }
//  /** // doc: test_get_info_name_2() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_name_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[48];
    p.get_info(device_info_t::name, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
  }
//  /** // doc: test_get_info_name_3() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_name_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[12];
    p.get_info(device_info_t::name, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "Tesla C1060");
  }
  /** // doc: test_get_info_vendor_0() {{{
   * \brief Test get_info(device_info_t::vendor, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(device_info_t::vendor, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
  /** // doc: test_get_info_vendor_1() {{{
   * \brief Test get_info(device_info_t::vendor, 0, NULL, &size).
   */ // }}}
  void test_get_info_vendor_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(device_info_t::vendor, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 19);
  }
//  /** // doc: test_get_info_vendor_2() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_vendor_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[13];
    p.get_info(device_info_t::vendor, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "GenuineIntel");
  }
//  /** // doc: test_get_info_vendor_3() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_vendor_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[20];
    p.get_info(device_info_t::vendor, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "NVIDIA Corporation");
  }
  /** // doc: test_get_info_driver_version_0() {{{
   * \brief Test get_info(device_info_t::driver_version, 0, NULL, &size).
   */ // }}}
  void test_get_info_driver_version_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(device_info_t::driver_version, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 14);
  }
  /** // doc: test_get_info_driver_version_1() {{{
   * \brief Test get_info(device_info_t::driver_version, 0, NULL, &size).
   */ // }}}
  void test_get_info_driver_version_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(device_info_t::driver_version, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 7);
  }
//  /** // doc: test_get_info_driver_version_2() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_driver_version_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[14];
    p.get_info(device_info_t::driver_version, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "1348.4 (sse2)");
  }
//  /** // doc: test_get_info_driver_version_3() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_driver_version_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[7];
    p.get_info(device_info_t::driver_version, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "319.76");
  }
  /** // doc: test_get_info_driver_profile_0() {{{
   * \brief Test get_info(device_info_t::device_profile, 0, NULL, &size).
   */ // }}}
  void test_get_info_driver_profile_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(device_info_t::profile, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
  /** // doc: test_get_info_device_profile_1() {{{
   * \brief Test get_info(device_info_t::device_profile, 0, NULL, &size).
   */ // }}}
  void test_get_info_device_profile_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(device_info_t::profile, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 13);
  }
//  /** // doc: test_get_info_device_profile_2() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_device_profile_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[13];
    p.get_info(device_info_t::profile, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "FULL_PROFILE");
  }
//  /** // doc: test_get_info_device_profile_3() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_device_profile_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[13];
    p.get_info(device_info_t::profile, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "FULL_PROFILE");
  }
  /** // doc: test_get_info_version_0() {{{
   * \brief Test get_info(device_info_t::device_version, 0, NULL, &size).
   */ // }}}
  void test_get_info_version_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(device_info_t::version, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 28);
  }
  /** // doc: test_get_info_version_1() {{{
   * \brief Test get_info(device_info_t::device_version, 0, NULL, &size).
   */ // }}}
  void test_get_info_version_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(device_info_t::version, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 16);
  }
//  /** // doc: test_get_info_version_2() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_version_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[28];
    p.get_info(device_info_t::version, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "OpenCL 1.2 AMD-APP (1348.4)");
  }
//  /** // doc: test_get_info_version_3() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_version_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[16];
    p.get_info(device_info_t::version, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "OpenCL 1.0 CUDA");
  }
  /** // doc: test_get_info_extensions_0() {{{
   * \brief Test get_info(device_info_t::device_extensions, 0, NULL, &size).
   */ // }}}
  void test_get_info_extensions_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(device_info_t::extensions, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 416);
  }
  /** // doc: test_get_info_extensions_1() {{{
   * \brief Test get_info(device_info_t::device_extensions, 0, NULL, &size).
   */ // }}}
  void test_get_info_extensions_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    p.get_info(device_info_t::extensions, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 281);
  }
//  /** // doc: test_get_info_extensions_2() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_extensions_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[416];
    p.get_info(device_info_t::extensions, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "cl_khr_fp64 cl_amd_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_byte_addressable_store cl_khr_gl_sharing cl_ext_device_fission cl_amd_device_attribute_query cl_amd_vec3 cl_amd_printf cl_amd_media_ops cl_amd_media_ops2 cl_amd_popcnt");
  }
//  /** // doc: test_get_info_extensions_3() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_extensions_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[281];
    p.get_info(device_info_t::extensions, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll  cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_fp6");
  }
#if CL_VERSION_1_2
  /** // doc: test_get_info_double_fp_config_0() {{{
   *  \brief Test get_info(device_info_t::double_fp_config, 0, NULL, &size).
   */ // }}}
  void test_get_info_double_fp_config_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::double_fp_config, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(device_fp_config_t));
  }
  /** // doc: test_get_info_double_fp_config_1() {{{
   *  \brief Test get_info(device_info_t::double_fp_config, 0, NULL, &size).
   */ // }}}
  void test_get_info_double_fp_config_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::double_fp_config, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_double_fp_config_2() {{{
   * \brief Test get_info(device_info_t::double_fp_config, ...).
   */ // }}}
  void test_get_info_double_fp_config_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_fp_config_t value;
    d.get_info(device_info_t::double_fp_config, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_fp_config_t::denorm
                          | device_fp_config_t::inf_nan
                          | device_fp_config_t::round_to_nearest
                          | device_fp_config_t::round_to_zero
                          | device_fp_config_t::round_to_inf
                          | device_fp_config_t::fma);
  }
  /** // doc: test_get_info_double_fp_config_3() {{{
   * \brief Test get_info(device_info_t::double_fp_config, ...).
   */ // }}}
  void test_get_info_double_fp_config_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_fp_config_t value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::double_fp_config, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
#endif
#if CL_VERSION_1_1
  /** // doc: test_get_info_preferred_vector_width_half_0() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_half, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_vector_width_half_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_vector_width_half, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_preferred_vector_width_half_1() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_half, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_half_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_half, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_preferred_vector_width_half_2() {{{
   * \brief Test get_info(device_info_t::preferred_vector_width_half, ...).
   */ // }}}
  void test_get_info_preferred_vector_width_half_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::preferred_vector_width_half, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_host_unified_memory_0() {{{
   * \brief Test get_info(device_info_t::host_unified_memory, 0, NULL, &size).
   */ // }}}
  void test_get_info_host_unified_memory_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::host_unified_memory, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_host_unified_memory_1() {{{
   * \brief Test get_info(device_info_t::host_unified_memory, ...).
   */ // }}}
  void test_get_info_host_unified_memory_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::host_unified_memory, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_host_unified_memory_2() {{{
   * \brief Test get_info(device_info_t::host_unified_memory, ...).
   */ // }}}
  void test_get_info_host_unified_memory_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    d.get_info(device_info_t::host_unified_memory, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_native_vector_width_char_0() {{{
   * \brief Test get_info(device_info_t::native_vector_width_char, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_char_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::native_vector_width_char, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_char_1() {{{
   * \brief Test get_info(device_info_t::native_vector_width_char, ...).
   */ // }}}
  void test_get_info_native_vector_width_char_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_char, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_native_vector_width_char_2() {{{
   * \brief Test get_info(device_info_t::native_vector_width_char, ...).
   */ // }}}
  void test_get_info_native_vector_width_char_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_char, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_short_0() {{{
   * \brief Test get_info(device_info_t::native_vector_width_short, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_short_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::native_vector_width_short, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_short_1() {{{
   * \brief Test get_info(device_info_t::native_vector_width_short, ...).
   */ // }}}
  void test_get_info_native_vector_width_short_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_short, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 8);
  }
  /** // doc: test_get_info_native_vector_width_short_2() {{{
   * \brief Test get_info(device_info_t::native_vector_width_short, ...).
   */ // }}}
  void test_get_info_native_vector_width_short_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_short, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_int_0() {{{
   * \brief Test get_info(device_info_t::native_vector_width_int, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_int_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::native_vector_width_int, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_int_1() {{{
   * \brief Test get_info(device_info_t::native_vector_width_int, ...).
   */ // }}}
  void test_get_info_native_vector_width_int_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_int, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_native_vector_width_int_2() {{{
   * \brief Test get_info(device_info_t::native_vector_width_int, ...).
   */ // }}}
  void test_get_info_native_vector_width_int_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_int, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_long_0() {{{
   * \brief Test get_info(device_info_t::native_vector_width_long, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_long_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::native_vector_width_long, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_long_1() {{{
   * \brief Test get_info(device_info_t::native_vector_width_long, ...).
   */ // }}}
  void test_get_info_native_vector_width_long_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_long, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_native_vector_width_long_2() {{{
   * \brief Test get_info(device_info_t::native_vector_width_long, ...).
   */ // }}}
  void test_get_info_native_vector_width_long_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_long, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_float_0() {{{
   * \brief Test get_info(device_info_t::native_vector_width_float, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_float_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::native_vector_width_float, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_float_1() {{{
   * \brief Test get_info(device_info_t::native_vector_width_float, ...).
   */ // }}}
  void test_get_info_native_vector_width_float_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_float, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 4);
  }
  /** // doc: test_get_info_native_vector_width_float_2() {{{
   * \brief Test get_info(device_info_t::native_vector_width_float, ...).
   */ // }}}
  void test_get_info_native_vector_width_float_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_float, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_double_0() {{{
   * \brief Test get_info(device_info_t::native_vector_width_double, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_double_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::native_vector_width_double, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_double_1() {{{
   * \brief Test get_info(device_info_t::native_vector_width_double, ...).
   */ // }}}
  void test_get_info_native_vector_width_double_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_double, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_native_vector_width_double_2() {{{
   * \brief Test get_info(device_info_t::native_vector_width_double, ...).
   */ // }}}
  void test_get_info_native_vector_width_double_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_double, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_native_vector_width_half_0() {{{
   * \brief Test get_info(device_info_t::native_vector_width_half, 0, NULL, &size).
   */ // }}}
  void test_get_info_native_vector_width_half_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::native_vector_width_half, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_native_vector_width_half_1() {{{
   * \brief Test get_info(device_info_t::native_vector_width_half, ...).
   */ // }}}
  void test_get_info_native_vector_width_half_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_half, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2);
  }
  /** // doc: test_get_info_native_vector_width_half_2() {{{
   * \brief Test get_info(device_info_t::native_vector_width_half, ...).
   */ // }}}
  void test_get_info_native_vector_width_half_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    d.get_info(device_info_t::native_vector_width_half, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_get_info_linker_available_0() {{{
   *  \brief Test get_info(device_info_t::linker_available, 0, NULL, &size).
   */ // }}}
  void test_get_info_linker_available_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::linker_available, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_linker_available_1() {{{
   *  \brief Test get_info(device_info_t::linker_available, 0, NULL, &size).
   */ // }}}
  void test_get_info_linker_available_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::linker_available, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_linker_available_2() {{{
   * \brief Test get_info(device_info_t::linker_available, ...).
   */ // }}}
  void test_get_info_linker_available_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::linker_available, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_FALSE);
  }
  /** // doc: test_get_info_linker_available_3() {{{
   * \brief Test get_info(device_info_t::linker_available, ...).
   */ // }}}
  void test_get_info_linker_available_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::linker_available, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_built_in_kernels_0() {{{
   * \brief Test get_info(device_info_t::device_built_in_kernels, 0, NULL, &size).
   */ // }}}
  void test_get_info_built_in_kernels_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    p.get_info(device_info_t::built_in_kernels, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 1);
  }
  /** // doc: test_get_info_built_in_kernels_1() {{{
   * \brief Test get_info(device_info_t::device_built_in_kernels, 0, NULL, &size).
   */ // }}}
  void test_get_info_built_in_kernels_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(p.get_info(device_info_t::built_in_kernels, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
//  /** // doc: test_get_info_built_in_kernels_2() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_built_in_kernels_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[0]);
    char value[1];
    p.get_info(device_info_t::built_in_kernels, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value, "");
  }
//  /** // doc: test_get_info_built_in_kernels_3() {{{
//   * \brief Test get_info(device_info_t::profile, ...).
//   */ // }}}
  void test_get_info_built_in_kernels_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device p(T::Newton_clGetDeviceIDs::devices[1]);
    char value[1];
    TS_ASSERT_THROWS(p.get_info(device_info_t::built_in_kernels, sizeof(value), value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_max_buffer_size_0() {{{
   *  \brief Test get_info(device_info_t::image_max_buffer_size, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_buffer_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image_max_buffer_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image_max_buffer_size_1() {{{
   *  \brief Test get_info(device_info_t::image_max_buffer_size, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_buffer_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_max_buffer_size, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_max_buffer_size_2() {{{
   * \brief Test get_info(device_info_t::image_max_buffer_size, ...).
   */ // }}}
  void test_get_info_image_max_buffer_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::image_max_buffer_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_image_max_buffer_size_3() {{{
   * \brief Test get_info(device_info_t::image_max_buffer_size, ...).
   */ // }}}
  void test_get_info_image_max_buffer_size_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_max_buffer_size, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_max_array_size_0() {{{
   *  \brief Test get_info(device_info_t::image_max_array_size, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_array_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image_max_array_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_image_max_array_size_1() {{{
   *  \brief Test get_info(device_info_t::image_max_array_size, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_max_array_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_max_array_size, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_max_array_size_2() {{{
   * \brief Test get_info(device_info_t::image_max_array_size, ...).
   */ // }}}
  void test_get_info_image_max_array_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::image_max_array_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 2048);
  }
  /** // doc: test_get_info_image_max_array_size_3() {{{
   * \brief Test get_info(device_info_t::image_max_array_size, ...).
   */ // }}}
  void test_get_info_image_max_array_size_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_max_array_size, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_parent_device_id_0() {{{
   *  \brief Test get_info(device_info_t::parent_device, 0, NULL, &size).
   */ // }}}
  void test_get_info_parent_device_id_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::parent_device, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_device_id));
  }
  /** // doc: test_get_info_parent_device_id_1() {{{
   *  \brief Test get_info(device_info_t::parent_device, 0, NULL, &size).
   */ // }}}
  void test_get_info_parent_device_id_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::parent_device, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_parent_device_id_2() {{{
   * \brief Test get_info(device_info_t::parent_device, ...).
   */ // }}}
  void test_get_info_parent_device_id_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_device_id value;
    d.get_info(device_info_t::parent_device, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_get_info_parent_device_id_3() {{{
   * \brief Test get_info(device_info_t::parent_device, ...).
   */ // }}}
  void test_get_info_parent_device_id_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_device_id value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::parent_device, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_max_sub_devices_0() {{{
   *  \brief Test get_info(device_info_t::partition_max_sub_devices, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_max_sub_devices_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::partition_max_sub_devices, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_partition_max_sub_devices_1() {{{
   *  \brief Test get_info(device_info_t::partition_max_sub_devices, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_max_sub_devices_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_max_sub_devices, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_max_sub_devices_2() {{{
   * \brief Test get_info(device_info_t::partition_max_sub_devices, ...).
   */ // }}}
  void test_get_info_partition_max_sub_devices_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::partition_max_sub_devices, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 16);
  }
  /** // doc: test_get_info_partition_max_sub_devices_3() {{{
   * \brief Test get_info(device_info_t::partition_max_sub_devices, ...).
   */ // }}}
  void test_get_info_partition_max_sub_devices_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_max_sub_devices, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_properties_0() {{{
   *  \brief Test get_info(device_info_t::partition_properties, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_properties_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::partition_properties, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 3 * sizeof(device_partition_property_t));
  }
  /** // doc: test_get_info_partition_properties_1() {{{
   *  \brief Test get_info(device_info_t::partition_properties, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_properties_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_properties, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_properties_2() {{{
   * \brief Test get_info(device_info_t::partition_properties, ...).
   */ // }}}
  void test_get_info_partition_properties_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_partition_property_t value[3];
    d.get_info(device_info_t::partition_properties, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], device_partition_property_t::equally);
    TS_ASSERT_EQUALS(value[1], device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(value[2], device_partition_property_t::by_affinity_domain);
  }
  /** // doc: test_get_info_partition_properties_3() {{{
   * \brief Test get_info(device_info_t::partition_properties, ...).
   */ // }}}
  void test_get_info_partition_properties_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_partition_property_t value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_properties, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_affinity_domain_0() {{{
   *  \brief Test get_info(device_info_t::partition_affinity_domain, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_affinity_domain_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::partition_affinity_domain, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(device_affinity_domain_t));
  }
  /** // doc: test_get_info_partition_affinity_domain_1() {{{
   *  \brief Test get_info(device_info_t::partition_affinity_domain, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_affinity_domain_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_affinity_domain, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_affinity_domain_2() {{{
   * \brief Test get_info(device_info_t::partition_affinity_domain, ...).
   */ // }}}
  void test_get_info_partition_affinity_domain_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_affinity_domain_t value;
    d.get_info(device_info_t::partition_affinity_domain, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, device_affinity_domain_t::l3_cache
                          | device_affinity_domain_t::l2_cache
                          | device_affinity_domain_t::l1_cache
                          | device_affinity_domain_t::next_partitionable);
  }
  /** // doc: test_get_info_partition_affinity_domain_3() {{{
   * \brief Test get_info(device_info_t::partition_affinity_domain, ...).
   */ // }}}
  void test_get_info_partition_affinity_domain_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_affinity_domain_t value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_affinity_domain, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_type_0() {{{
   *  \brief Test get_info(device_info_t::partition_type, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_type_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::partition_type, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, 0 * sizeof(device_partition_property_t));
  }
  /** // doc: test_get_info_partition_type_1() {{{
   *  \brief Test get_info(device_info_t::partition_type, 0, NULL, &size).
   */ // }}}
  void test_get_info_partition_type_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_type, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_partition_type_2() {{{
   * \brief Test get_info(device_info_t::partition_type, ...).
   */ // }}}
  void test_get_info_partition_type_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_partition_property_t value[1] = { static_cast<device_partition_property_t>(0x1234) };
    d.get_info(device_info_t::partition_type, sizeof(value), value, NULL);
    TS_ASSERT_EQUALS(value[0], static_cast<device_partition_property_t>(0x1234) ); // unchanged
  }
  /** // doc: test_get_info_partition_type_3() {{{
   * \brief Test get_info(device_info_t::partition_type, ...).
   */ // }}}
  void test_get_info_partition_type_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    device_partition_property_t value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::partition_type, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_reference_count_0() {{{
   *  \brief Test get_info(device_info_t::reference_count, 0, NULL, &size).
   */ // }}}
  void test_get_info_reference_count_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::reference_count, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_reference_count_1() {{{
   *  \brief Test get_info(device_info_t::reference_count, 0, NULL, &size).
   */ // }}}
  void test_get_info_reference_count_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::reference_count, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_reference_count_2() {{{
   * \brief Test get_info(device_info_t::reference_count, ...).
   */ // }}}
  void test_get_info_reference_count_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::reference_count, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 1);
  }
  /** // doc: test_get_info_reference_count_3() {{{
   * \brief Test get_info(device_info_t::reference_count, ...).
   */ // }}}
  void test_get_info_reference_count_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::reference_count, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_preferred_interop_user_sync_0() {{{
   *  \brief Test get_info(device_info_t::preferred_interop_user_sync, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::preferred_interop_user_sync, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_bool));
  }
  /** // doc: test_get_info_preferred_interop_user_sync_1() {{{
   *  \brief Test get_info(device_info_t::preferred_interop_user_sync, 0, NULL, &size).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::preferred_interop_user_sync, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_preferred_interop_user_sync_2() {{{
   * \brief Test get_info(device_info_t::preferred_interop_user_sync, ...).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_bool value;
    d.get_info(device_info_t::preferred_interop_user_sync, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, CL_TRUE);
  }
  /** // doc: test_get_info_preferred_interop_user_sync_3() {{{
   * \brief Test get_info(device_info_t::preferred_interop_user_sync, ...).
   */ // }}}
  void test_get_info_preferred_interop_user_sync_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_bool value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::preferred_interop_user_sync, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_printf_buffer_size_0() {{{
   *  \brief Test get_info(device_info_t::printf_buffer_size, 0, NULL, &size).
   */ // }}}
  void test_get_info_printf_buffer_size_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::printf_buffer_size, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(size_t));
  }
  /** // doc: test_get_info_printf_buffer_size_1() {{{
   *  \brief Test get_info(device_info_t::printf_buffer_size, 0, NULL, &size).
   */ // }}}
  void test_get_info_printf_buffer_size_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::printf_buffer_size, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_printf_buffer_size_2() {{{
   * \brief Test get_info(device_info_t::printf_buffer_size, ...).
   */ // }}}
  void test_get_info_printf_buffer_size_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t value;
    d.get_info(device_info_t::printf_buffer_size, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 65536);
  }
  /** // doc: test_get_info_printf_buffer_size_3() {{{
   * \brief Test get_info(device_info_t::printf_buffer_size, ...).
   */ // }}}
  void test_get_info_printf_buffer_size_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::printf_buffer_size, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_pitch_alignment_0() {{{
   *  \brief Test get_info(device_info_t::image_pitch_alignment, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_pitch_alignment_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image_pitch_alignment, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_image_pitch_alignment_1() {{{
   *  \brief Test get_info(device_info_t::image_pitch_alignment, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_pitch_alignment_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_pitch_alignment, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_pitch_alignment_2() {{{
   * \brief Test get_info(device_info_t::image_pitch_alignment, ...).
   */ // }}}
  void test_get_info_image_pitch_alignment_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::image_pitch_alignment, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_image_pitch_alignment_3() {{{
   * \brief Test get_info(device_info_t::image_pitch_alignment, ...).
   */ // }}}
  void test_get_info_image_pitch_alignment_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_pitch_alignment, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_base_address_alignment_0() {{{
   *  \brief Test get_info(device_info_t::image_base_address_alignment, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_base_address_alignment_0( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t size;
    d.get_info(device_info_t::image_base_address_alignment, 0, NULL, &size);
    TS_ASSERT_EQUALS(size, sizeof(cl_uint));
  }
  /** // doc: test_get_info_image_base_address_alignment_1() {{{
   *  \brief Test get_info(device_info_t::image_base_address_alignment, 0, NULL, &size).
   */ // }}}
  void test_get_info_image_base_address_alignment_1( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t size;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_base_address_alignment, 0, NULL, &size), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_info_image_base_address_alignment_2() {{{
   * \brief Test get_info(device_info_t::image_base_address_alignment, ...).
   */ // }}}
  void test_get_info_image_base_address_alignment_2( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    cl_uint value;
    d.get_info(device_info_t::image_base_address_alignment, sizeof(value), &value, NULL);
    TS_ASSERT_EQUALS(value, 0);
  }
  /** // doc: test_get_info_image_base_address_alignment_3() {{{
   * \brief Test get_info(device_info_t::image_base_address_alignment, ...).
   */ // }}}
  void test_get_info_image_base_address_alignment_3( )
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    cl_uint value;
    TS_ASSERT_THROWS(d.get_info(device_info_t::image_base_address_alignment, sizeof(value), &value, NULL), clerror_no<status_t::invalid_value>);
  }
#endif
  /** // doc: test_get_type_1() {{{
   * \brief Test get_type()
   */ // }}}
  void test_get_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_type(), device_type_t::cpu);
  }
  /** // doc: test_get_type_2() {{{
   * \brief Test get_type()
   */ // }}}
  void test_get_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_type(), device_type_t::gpu);
  }
  /** // doc: test_get_vendor_id_1() {{{
   * \brief Test get_vendor_id()
   */ // }}}
  void test_get_vendor_id_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_vendor_id(), 0x1002);
  }
  /** // doc: test_get_vendor_id_2() {{{
   * \brief Test get_vendor_id()
   */ // }}}
  void test_get_vendor_id_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_vendor_id(), 0x10de);
  }
  /** // doc: test_get_max_compute_units_1() {{{
   * \brief Test get_max_compute_units()
   */ // }}}
  void test_get_max_compute_units_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_compute_units(), 16);
  }
  /** // doc: test_get_max_compute_units_2() {{{
   * \brief Test get_max_compute_units()
   */ // }}}
  void test_get_max_compute_units_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_compute_units(), 30);
  }
  /** // doc: test_get_max_work_item_dimensions_1() {{{
   * \brief Test get_max_work_item_dimensions()
   */ // }}}
  void test_get_max_work_item_dimensions_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_work_item_dimensions(), 3);
  }
  /** // doc: test_get_max_work_item_dimensions_2() {{{
   * \brief Test get_max_work_item_dimensions()
   */ // }}}
  void test_get_max_work_item_dimensions_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_work_item_dimensions(), 3);
  }
  /** // doc: test_get_max_work_item_sizes_1() {{{
   * \brief Test get_max_work_item_sizes()
   */ // }}}
  void test_get_max_work_item_sizes_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    size_t sizes[3] = {1024, 1024, 1024};
    TS_ASSERT_EQUALS(d.get_max_work_item_sizes(), std::vector<size_t>(sizes,sizes+3));
  }
  /** // doc: test_get_max_work_item_sizes_2() {{{
   * \brief Test get_max_work_item_sizes()
   */ // }}}
  void test_get_max_work_item_sizes_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    size_t sizes[3] = {512, 512, 64};
    TS_ASSERT_EQUALS(d.get_max_work_item_sizes(), std::vector<size_t>(sizes,sizes+3));
  }
  /** // doc: test_get_max_work_group_size_1() {{{
   * \brief Test get_max_work_group_size()
   */ // }}}
  void test_get_max_work_group_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_work_group_size(), 1024);
  }
  /** // doc: test_get_max_work_group_size_2() {{{
   * \brief Test get_max_work_group_size()
   */ // }}}
  void test_get_max_work_group_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_work_group_size(), 512);
  }
  /** // doc: test_get_preferred_vector_width_char_1() {{{
   * \brief Test get_preferred_vector_width_char()
   */ // }}}
  void test_get_preferred_vector_width_char_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_char(), 16);
  }
  /** // doc: test_get_preferred_vector_width_char_2() {{{
   * \brief Test get_preferred_vector_width_char()
   */ // }}}
  void test_get_preferred_vector_width_char_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_char(), 1);
  }
  /** // doc: test_get_preferred_vector_width_short_1() {{{
   * \brief Test get_preferred_vector_width_short()
   */ // }}}
  void test_get_preferred_vector_width_short_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_short(), 8);
  }
  /** // doc: test_get_preferred_vector_width_short_2() {{{
   * \brief Test get_preferred_vector_width_short()
   */ // }}}
  void test_get_preferred_vector_width_short_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_short(), 1);
  }
  /** // doc: test_get_preferred_vector_width_int_1() {{{
   * \brief Test get_preferred_vector_width_int()
   */ // }}}
  void test_get_preferred_vector_width_int_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_int(), 4);
  }
  /** // doc: test_get_preferred_vector_width_int_2() {{{
   * \brief Test get_preferred_vector_width_int()
   */ // }}}
  void test_get_preferred_vector_width_int_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_int(), 1);
  }
  /** // doc: test_get_preferred_vector_width_long_1() {{{
   * \brief Test get_preferred_vector_width_long()
   */ // }}}
  void test_get_preferred_vector_width_long_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_long(), 2);
  }
  /** // doc: test_get_preferred_vector_width_long_2() {{{
   * \brief Test get_preferred_vector_width_long()
   */ // }}}
  void test_get_preferred_vector_width_long_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_long(), 1);
  }
  /** // doc: test_get_preferred_vector_width_float_1() {{{
   * \brief Test get_preferred_vector_width_float()
   */ // }}}
  void test_get_preferred_vector_width_float_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_float(), 4);
  }
  /** // doc: test_get_preferred_vector_width_float_2() {{{
   * \brief Test get_preferred_vector_width_float()
   */ // }}}
  void test_get_preferred_vector_width_float_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_float(), 1);
  }
  /** // doc: test_get_preferred_vector_width_double_1() {{{
   * \brief Test get_preferred_vector_width_double()
   */ // }}}
  void test_get_preferred_vector_width_double_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_double(), 2);
  }
  /** // doc: test_get_preferred_vector_width_double_2() {{{
   * \brief Test get_preferred_vector_width_double()
   */ // }}}
  void test_get_preferred_vector_width_double_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_double(), 1);
  }
  /** // doc: test_get_max_clock_frequency_1() {{{
   * \brief Test get_max_clock_frequency()
   */ // }}}
  void test_get_max_clock_frequency_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_clock_frequency(), 2401);
  }
  /** // doc: test_get_max_clock_frequency_2() {{{
   * \brief Test get_max_clock_frequency()
   */ // }}}
  void test_get_max_clock_frequency_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_clock_frequency(), 1296);
  }
  /** // doc: test_get_address_bits_1() {{{
   * \brief Test get_address_bits()
   */ // }}}
  void test_get_address_bits_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_address_bits(), 64);
  }
  /** // doc: test_get_address_bits_2() {{{
   * \brief Test get_address_bits()
   */ // }}}
  void test_get_address_bits_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_address_bits(), 32);
  }
  /** // doc: test_get_max_mem_alloc_size_1() {{{
   * \brief Test get_max_mem_alloc_size()
   */ // }}}
  void test_get_max_mem_alloc_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_mem_alloc_size(), 4214191104ul);
  }
  /** // doc: test_get_max_mem_alloc_size_2() {{{
   * \brief Test get_max_mem_alloc_size()
   */ // }}}
  void test_get_max_mem_alloc_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_mem_alloc_size(), 1073692672ul);
  }
  /** // doc: test_get_image_support_1() {{{
   * \brief Test get_image_support()
   */ // }}}
  void test_get_image_support_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_support(), CL_TRUE);
  }
  /** // doc: test_get_image_support_2() {{{
   * \brief Test get_image_support()
   */ // }}}
  void test_get_image_support_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image_support(), CL_TRUE);
  }
  /** // doc: test_get_max_read_image_args_1() {{{
   * \brief Test get_max_read_image_args()
   */ // }}}
  void test_get_max_read_image_args_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_read_image_args(), 128);
  }
  /** // doc: test_get_max_read_image_args_2() {{{
   * \brief Test get_max_read_image_args()
   */ // }}}
  void test_get_max_read_image_args_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_read_image_args(), 128);
  }
  /** // doc: test_get_max_write_image_args_1() {{{
   * \brief Test get_max_write_image_args()
   */ // }}}
  void test_get_max_write_image_args_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_write_image_args(), 8);
  }
  /** // doc: test_get_max_write_image_args_2() {{{
   * \brief Test get_max_write_image_args()
   */ // }}}
  void test_get_max_write_image_args_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_write_image_args(), 8);
  }
  /** // doc: test_get_image2d_max_width_1() {{{
   * \brief Test get_image2d_max_width()
   */ // }}}
  void test_get_image2d_max_width_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image2d_max_width(), 8192);
  }
  /** // doc: test_get_image2d_max_width_2() {{{
   * \brief Test get_image2d_max_width()
   */ // }}}
  void test_get_image2d_max_width_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image2d_max_width(), 4096);
  }
  /** // doc: test_get_image2d_max_height_1() {{{
   * \brief Test get_image2d_max_height()
   */ // }}}
  void test_get_image2d_max_height_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image2d_max_height(), 8192);
  }
  /** // doc: test_get_image2d_max_height_2() {{{
   * \brief Test get_image2d_max_height()
   */ // }}}
  void test_get_image2d_max_height_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image2d_max_height(), 16383);
  }
  /** // doc: test_get_image3d_max_width_1() {{{
   * \brief Test get_image3d_max_width()
   */ // }}}
  void test_get_image3d_max_width_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image3d_max_width(), 2048);
  }
  /** // doc: test_get_image3d_max_width_2() {{{
   * \brief Test get_image3d_max_width()
   */ // }}}
  void test_get_image3d_max_width_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image3d_max_width(), 2048);
  }
  /** // doc: test_get_image3d_max_height_1() {{{
   * \brief Test get_image3d_max_height()
   */ // }}}
  void test_get_image3d_max_height_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image3d_max_height(), 2048);
  }
  /** // doc: test_get_image3d_max_height_2() {{{
   * \brief Test get_image3d_max_height()
   */ // }}}
  void test_get_image3d_max_height_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image3d_max_height(), 2048);
  }
  /** // doc: test_get_image3d_max_depth_1() {{{
   * \brief Test get_image3d_max_depth()
   */ // }}}
  void test_get_image3d_max_depth_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image3d_max_depth(), 2048);
  }
  /** // doc: test_get_image3d_max_depth_2() {{{
   * \brief Test get_image3d_max_depth()
   */ // }}}
  void test_get_image3d_max_depth_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_image3d_max_depth(), 2048);
  }
  /** // doc: test_get_max_samplers_1() {{{
   * \brief Test get_max_samplers()
   */ // }}}
  void test_get_max_samplers_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_samplers(), 16);
  }
  /** // doc: test_get_max_samplers_2() {{{
   * \brief Test get_max_samplers()
   */ // }}}
  void test_get_max_samplers_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_samplers(), 16);
  }
  /** // doc: test_get_max_parameter_size_1() {{{
   * \brief Test get_max_parameter_size()
   */ // }}}
  void test_get_max_parameter_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_parameter_size(), 4096);
  }
  /** // doc: test_get_max_parameter_size_2() {{{
   * \brief Test get_max_parameter_size()
   */ // }}}
  void test_get_max_parameter_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_parameter_size(), 4352);
  }
  /** // doc: test_get_mem_base_addr_align_1() {{{
   * \brief Test get_mem_base_addr_align()
   */ // }}}
  void test_get_mem_base_addr_align_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_mem_base_addr_align(), 1024);
  }
  /** // doc: test_get_mem_base_addr_align_2() {{{
   * \brief Test get_mem_base_addr_align()
   */ // }}}
  void test_get_mem_base_addr_align_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_mem_base_addr_align(), 2048);
  }
  /** // doc: test_get_min_data_type_align_size_1() {{{
   * \brief Test get_min_data_type_align_size()
   */ // }}}
  void test_get_min_data_type_align_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_min_data_type_align_size(), 128);
  }
  /** // doc: test_get_min_data_type_align_size_2() {{{
   * \brief Test get_min_data_type_align_size()
   */ // }}}
  void test_get_min_data_type_align_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_min_data_type_align_size(), 128);
  }
  /** // doc: test_get_single_fp_config_1() {{{
   * \brief Test get_single_fp_config()
   */ // }}}
  void test_get_single_fp_config_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_single_fp_config(), device_fp_config_t::denorm
                                             | device_fp_config_t::inf_nan
                                             | device_fp_config_t::round_to_nearest
                                             | device_fp_config_t::round_to_zero
                                             | device_fp_config_t::round_to_inf
                                             | device_fp_config_t::fma);
  }
  /** // doc: test_get_single_fp_config_2() {{{
   * \brief Test get_single_fp_config()
   */ // }}}
  void test_get_single_fp_config_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_single_fp_config(), device_fp_config_t::inf_nan
                                             | device_fp_config_t::round_to_nearest
                                             | device_fp_config_t::round_to_zero
                                             | device_fp_config_t::round_to_inf
                                             | device_fp_config_t::fma);
  }
  /** // doc: test_get_global_mem_cache_type_1() {{{
   * \brief Test get_global_mem_cache_type()
   */ // }}}
  void test_get_global_mem_cache_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_type(), device_mem_cache_type_t::read_write_cache);
  }
  /** // doc: test_get_global_mem_cache_type_2() {{{
   * \brief Test get_global_mem_cache_type()
   */ // }}}
  void test_get_global_mem_cache_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_type(), device_mem_cache_type_t::none);
  }
  /** // doc: test_get_global_mem_cacheline_size_1() {{{
   * \brief Test get_global_mem_cacheline_size()
   */ // }}}
  void test_get_global_mem_cacheline_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_cacheline_size(), 64);
  }
  /** // doc: test_get_global_mem_cacheline_size_2() {{{
   * \brief Test get_global_mem_cacheline_size()
   */ // }}}
  void test_get_global_mem_cacheline_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_cacheline_size(), 0);
  }
  /** // doc: test_get_global_mem_cache_size_1() {{{
   * \brief Test get_global_mem_cache_size()
   */ // }}}
  void test_get_global_mem_cache_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_size(), 32768ul);
  }
  /** // doc: test_get_global_mem_cache_size_2() {{{
   * \brief Test get_global_mem_cache_size()
   */ // }}}
  void test_get_global_mem_cache_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_cache_size(), 0);
  }
  /** // doc: test_get_global_mem_size_1() {{{
   * \brief Test get_global_mem_size()
   */ // }}}
  void test_get_global_mem_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_global_mem_size(), 16856764416ul);
  }
  /** // doc: test_get_global_mem_size_2() {{{
   * \brief Test get_global_mem_size()
   */ // }}}
  void test_get_global_mem_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_global_mem_size(), 4294770688ul);
  }
  /** // doc: test_get_max_constant_buffer_size_1() {{{
   * \brief Test get_max_constant_buffer_size()
   */ // }}}
  void test_get_max_constant_buffer_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_constant_buffer_size(), 65536);
  }
  /** // doc: test_get_max_constant_buffer_size_2() {{{
   * \brief Test get_max_constant_buffer_size()
   */ // }}}
  void test_get_max_constant_buffer_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_constant_buffer_size(), 65536);
  }
  /** // doc: test_get_max_constant_args_1() {{{
   * \brief Test get_max_constant_args()
   */ // }}}
  void test_get_max_constant_args_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_max_constant_args(), 8);
  }
  /** // doc: test_get_max_constant_args_2() {{{
   * \brief Test get_max_constant_args()
   */ // }}}
  void test_get_max_constant_args_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_max_constant_args(), 9);
  }
  /** // doc: test_get_local_mem_type_1() {{{
   * \brief Test get_local_mem_type()
   */ // }}}
  void test_get_local_mem_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_local_mem_type(), device_local_mem_type_t::global);
  }
  /** // doc: test_get_local_mem_type_2() {{{
   * \brief Test get_local_mem_type()
   */ // }}}
  void test_get_local_mem_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_local_mem_type(), device_local_mem_type_t::local);
  }
  /** // doc: test_get_local_mem_size_1() {{{
   * \brief Test get_local_mem_size()
   */ // }}}
  void test_get_local_mem_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_local_mem_size(), 32768);
  }
  /** // doc: test_get_local_mem_size_2() {{{
   * \brief Test get_local_mem_size()
   */ // }}}
  void test_get_local_mem_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_local_mem_size(), 16384);
  }
  /** // doc: test_get_error_correction_support_1() {{{
   * \brief Test get_error_correction_support()
   */ // }}}
  void test_get_error_correction_support_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_error_correction_support(), CL_FALSE);
  }
  /** // doc: test_get_error_correction_support_2() {{{
   * \brief Test get_error_correction_support()
   */ // }}}
  void test_get_error_correction_support_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_error_correction_support(), CL_FALSE);
  }
  /** // doc: test_get_profiling_timer_resolution_1() {{{
   * \brief Test get_profiling_timer_resolution()
   */ // }}}
  void test_get_profiling_timer_resolution_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_profiling_timer_resolution(), 1);
  }
  /** // doc: test_get_profiling_timer_resolution_2() {{{
   * \brief Test get_profiling_timer_resolution()
   */ // }}}
  void test_get_profiling_timer_resolution_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_profiling_timer_resolution(), 1000);
  }
  /** // doc: test_get_endian_little_1() {{{
   * \brief Test get_endian_little()
   */ // }}}
  void test_get_endian_little_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_endian_little(), CL_TRUE);
  }
  /** // doc: test_get_endian_little_2() {{{
   * \brief Test get_endian_little()
   */ // }}}
  void test_get_endian_little_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_endian_little(), CL_TRUE);
  }
  /** // doc: test_get_available_1() {{{
   * \brief Test get_available()
   */ // }}}
  void test_get_available_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_available(), CL_TRUE);
  }
  /** // doc: test_get_available_2() {{{
   * \brief Test get_available()
   */ // }}}
  void test_get_available_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_available(), CL_TRUE);
  }
  /** // doc: test_get_compiler_available_1() {{{
   * \brief Test get_compiler_available()
   */ // }}}
  void test_get_compiler_available_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_compiler_available(), CL_TRUE);
  }
  /** // doc: test_get_compiler_available_2() {{{
   * \brief Test get_compiler_available()
   */ // }}}
  void test_get_compiler_available_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_compiler_available(), CL_TRUE);
  }
  /** // doc: test_get_execution_capabilities_1() {{{
   * \brief Test get_execution_capabilities()
   */ // }}}
  void test_get_execution_capabilities_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_execution_capabilities(), device_exec_capabilities_t::kernel
                                                   | device_exec_capabilities_t::native_kernel);
  }
  /** // doc: test_get_execution_capabilities_2() {{{
   * \brief Test get_execution_capabilities()
   */ // }}}
  void test_get_execution_capabilities_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_execution_capabilities(), device_exec_capabilities_t::kernel);
  }
  /** // doc: test_get_queue_properties_1() {{{
   * \brief Test get_queue_properties()
   */ // }}}
  void test_get_queue_properties_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_queue_properties(), command_queue_properties_t::profiling_enable);
  }
  /** // doc: test_get_queue_properties_2() {{{
   * \brief Test get_queue_properties()
   */ // }}}
  void test_get_queue_properties_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_queue_properties(), command_queue_properties_t::out_of_order_exec_mode_enable
                                             | command_queue_properties_t::profiling_enable);
  }
  /** // doc: test_get_platform_id_1() {{{
   * \brief Test get_platform_id()
   */ // }}}
  void test_get_platform_id_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_platform_id(), T::Newton_clGetPlatformIDs::platforms[0]);
  }
  /** // doc: test_get_platform_id_2() {{{
   * \brief Test get_platform_id()
   */ // }}}
  void test_get_platform_id_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_platform_id(), T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test_get_name_1() {{{
   * \brief Test get_name()
   */ // }}}
  void test_get_name_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
  }
  /** // doc: test_get_name_2() {{{
   * \brief Test get_name()
   */ // }}}
  void test_get_name_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_name(), "Tesla C1060");
  }
  /** // doc: test_get_vendor_1() {{{
   * \brief Test get_vendor()
   */ // }}}
  void test_get_vendor_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_vendor(), "GenuineIntel");
  }
  /** // doc: test_get_vendor_2() {{{
   * \brief Test get_vendor()
   */ // }}}
  void test_get_vendor_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_vendor(), "NVIDIA Corporation");
  }
  /** // doc: test_get_driver_version_1() {{{
   * \brief Test get_driver_version()
   */ // }}}
  void test_get_driver_version_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_driver_version(), "1348.4 (sse2)");
  }
  /** // doc: test_get_driver_version_2() {{{
   * \brief Test get_driver_version()
   */ // }}}
  void test_get_driver_version_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_driver_version(), "319.76");
  }
  /** // doc: test_get_profile_1() {{{
   * \brief Test get_profile()
   */ // }}}
  void test_get_profile_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
  }
  /** // doc: test_get_profile_2() {{{
   * \brief Test get_profile()
   */ // }}}
  void test_get_profile_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
  }
  /** // doc: test_get_version_1() {{{
   * \brief Test get_version()
   */ // }}}
  void test_get_version_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test_get_version_2() {{{
   * \brief Test get_version()
   */ // }}}
  void test_get_version_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test_get_extensions_1() {{{
   * \brief Test get_extensions()
   */ // }}}
  void test_get_extensions_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_extensions(), "cl_khr_fp64 cl_amd_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_byte_addressable_store cl_khr_gl_sharing cl_ext_device_fission cl_amd_device_attribute_query cl_amd_vec3 cl_amd_printf cl_amd_media_ops cl_amd_media_ops2 cl_amd_popcnt");
  }
  /** // doc: test_get_extensions_2() {{{
   * \brief Test get_extensions()
   */ // }}}
  void test_get_extensions_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_extensions(), "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll  cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_fp6");
  }
#if CL_VERSION_1_2
  /** // doc: test_get_double_fp_config_1() {{{
   * \brief Test get_double_fp_config()
   */ // }}}
  void test_get_double_fp_config_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_double_fp_config(), device_fp_config_t::denorm
                                             | device_fp_config_t::inf_nan
                                             | device_fp_config_t::round_to_nearest
                                             | device_fp_config_t::round_to_zero
                                             | device_fp_config_t::round_to_inf
                                             | device_fp_config_t::fma);
  }
  /** // doc: test_get_double_fp_config_2() {{{
   * \brief Test get_double_fp_config()
   */ // }}}
  void test_get_double_fp_config_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_double_fp_config(), clerror_no<status_t::invalid_value>);
  }
#endif
#if CL_VERSION_1_1
  /** // doc: test_get_preferred_vector_width_half_1() {{{
   * \brief Test get_preferred_vector_width_half()
   */ // }}}
  void test_get_preferred_vector_width_half_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_half(), 2);
  }
  /** // doc: test_get_preferred_vector_width_half_2() {{{
   * \brief Test get_preferred_vector_width_half()
   */ // }}}
  void test_get_preferred_vector_width_half_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_preferred_vector_width_half(), 0);
  }
  /** // doc: test_get_host_unified_memory_1() {{{
   * \brief Test get_host_unified_memory()
   */ // }}}
  void test_get_host_unified_memory_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_host_unified_memory(), CL_TRUE);
  }
  /** // doc: test_get_host_unified_memory_2() {{{
   * \brief Test get_host_unified_memory()
   */ // }}}
  void test_get_host_unified_memory_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_host_unified_memory(), CL_FALSE);
  }
  /** // doc: test_get_native_vector_width_char_1() {{{
   * \brief Test get_native_vector_width_char()
   */ // }}}
  void test_get_native_vector_width_char_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_char(), 16);
  }
  /** // doc: test_get_native_vector_width_char_2() {{{
   * \brief Test get_native_vector_width_char()
   */ // }}}
  void test_get_native_vector_width_char_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_char(), 1);
  }
  /** // doc: test_get_native_vector_width_short_1() {{{
   * \brief Test get_native_vector_width_short()
   */ // }}}
  void test_get_native_vector_width_short_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_short(), 8);
  }
  /** // doc: test_get_native_vector_width_short_2() {{{
   * \brief Test get_native_vector_width_short()
   */ // }}}
  void test_get_native_vector_width_short_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_short(), 1);
  }
  /** // doc: test_get_native_vector_width_int_1() {{{
   * \brief Test get_native_vector_width_int()
   */ // }}}
  void test_get_native_vector_width_int_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_int(), 4);
  }
  /** // doc: test_get_native_vector_width_int_2() {{{
   * \brief Test get_native_vector_width_int()
   */ // }}}
  void test_get_native_vector_width_int_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_int(), 1);
  }
  /** // doc: test_get_native_vector_width_long_1() {{{
   * \brief Test get_native_vector_width_long()
   */ // }}}
  void test_get_native_vector_width_long_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_long(), 2);
  }
  /** // doc: test_get_native_vector_width_long_2() {{{
   * \brief Test get_native_vector_width_long()
   */ // }}}
  void test_get_native_vector_width_long_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_long(), 1);
  }
  /** // doc: test_get_native_vector_width_float_1() {{{
   * \brief Test get_native_vector_width_float()
   */ // }}}
  void test_get_native_vector_width_float_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_float(), 4);
  }
  /** // doc: test_get_native_vector_width_float_2() {{{
   * \brief Test get_native_vector_width_float()
   */ // }}}
  void test_get_native_vector_width_float_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_float(), 1);
  }
  /** // doc: test_get_native_vector_width_double_1() {{{
   * \brief Test get_native_vector_width_double()
   */ // }}}
  void test_get_native_vector_width_double_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_double(), 2);
  }
  /** // doc: test_get_native_vector_width_double_2() {{{
   * \brief Test get_native_vector_width_double()
   */ // }}}
  void test_get_native_vector_width_double_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_double(), 1);
  }
  /** // doc: test_get_native_vector_width_half_1() {{{
   * \brief Test get_native_vector_width_half()
   */ // }}}
  void test_get_native_vector_width_half_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_half(), 2);
  }
  /** // doc: test_get_native_vector_width_half_2() {{{
   * \brief Test get_native_vector_width_half()
   */ // }}}
  void test_get_native_vector_width_half_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_native_vector_width_half(), 0);
  }
  /** // doc: test_get_opencl_c_version_1() {{{
   * \brief Test get_opencl_c_version()
   */ // }}}
  void test_get_opencl_c_version_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_opencl_c_version(), "OpenCL C 1.2");
  }
  /** // doc: test_get_opencl_c_version_2() {{{
   * \brief Test get_opencl_c_version()
   */ // }}}
  void test_get_opencl_c_version_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_opencl_c_version(), "OpenCL C 1.1");
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_get_linker_available_1() {{{
   * \brief Test get_linker_available()
   */ // }}}
  void test_get_linker_available_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_linker_available(), CL_FALSE);
  }
  /** // doc: test_get_linker_available_2() {{{
   * \brief Test get_linker_available()
   */ // }}}
  void test_get_linker_available_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_linker_available(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_built_in_kernels_1() {{{
   * \brief Test get_built_in_kernels()
   */ // }}}
  void test_get_built_in_kernels_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_built_in_kernels(), "");
  }
  /** // doc: test_get_built_in_kernels_2() {{{
   * \brief Test get_built_in_kernels()
   */ // }}}
  void test_get_built_in_kernels_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_built_in_kernels(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_image_max_buffer_size_1() {{{
   * \brief Test get_image_max_buffer_size()
   */ // }}}
  void test_get_image_max_buffer_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_max_buffer_size(), 65536);
  }
  /** // doc: test_get_image_max_buffer_size_2() {{{
   * \brief Test get_image_max_buffer_size()
   */ // }}}
  void test_get_image_max_buffer_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_max_buffer_size(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_image_max_array_size_1() {{{
   * \brief Test get_image_max_array_size()
   */ // }}}
  void test_get_image_max_array_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_max_array_size(), 2048);
  }
  /** // doc: test_get_image_max_array_size_2() {{{
   * \brief Test get_image_max_array_size()
   */ // }}}
  void test_get_image_max_array_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_max_array_size(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_parent_device_id_1() {{{
   * \brief Test get_parent_device_id()
   */ // }}}
  void test_get_parent_device_id_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_parent_device_id(), reinterpret_cast<cl_device_id>(NULL));
  }
  /** // doc: test_get_parent_device_id_2() {{{
   * \brief Test get_parent_device_id()
   */ // }}}
  void test_get_parent_device_id_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_parent_device_id(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_partition_max_sub_devices_1() {{{
   * \brief Test get_partition_max_sub_devices()
   */ // }}}
  void test_get_partition_max_sub_devices_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_partition_max_sub_devices(), 16);
  }
  /** // doc: test_get_partition_max_sub_devices_2() {{{
   * \brief Test get_partition_max_sub_devices()
   */ // }}}
  void test_get_partition_max_sub_devices_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_max_sub_devices(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_partition_properties_1() {{{
   * \brief Test get_partition_properties()
   */ // }}}
  void test_get_partition_properties_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    device_partition_property_t const props[3] = {
      device_partition_property_t::equally,
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    TS_ASSERT_EQUALS(d.get_partition_properties(), std::vector<device_partition_property_t>(props,props+3));
  }
  /** // doc: test_get_partition_properties_2() {{{
   * \brief Test get_partition_properties()
   */ // }}}
  void test_get_partition_properties_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_properties(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_partition_affinity_domain_1() {{{
   * \brief Test get_partition_affinity_domain()
   */ // }}}
  void test_get_partition_affinity_domain_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_partition_affinity_domain(),
                      device_affinity_domain_t::l3_cache
                    | device_affinity_domain_t::l2_cache
                    | device_affinity_domain_t::l1_cache
                    | device_affinity_domain_t::next_partitionable);
  }
  /** // doc: test_get_partition_affinity_domain_2() {{{
   * \brief Test get_partition_affinity_domain()
   */ // }}}
  void test_get_partition_affinity_domain_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_affinity_domain(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_partition_type_1() {{{
   * \brief Test get_partition_type()
   */ // }}}
  void test_get_partition_type_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_partition_type(), std::vector<device_partition_property_t>());
  }
  /** // doc: test_get_partition_type_2() {{{
   * \brief Test get_partition_type()
   */ // }}}
  void test_get_partition_type_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_partition_type(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_reference_count_1() {{{
   * \brief Test get_reference_count()
   */ // }}}
  void test_get_reference_count_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_reference_count(), 1);
  }
  /** // doc: test_get_reference_count_2() {{{
   * \brief Test get_reference_count()
   */ // }}}
  void test_get_reference_count_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_reference_count(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_preferred_interop_user_sync_1() {{{
   * \brief Test get_preferred_interop_user_sync()
   */ // }}}
  void test_get_preferred_interop_user_sync_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_preferred_interop_user_sync(), CL_TRUE);
  }
  /** // doc: test_get_preferred_interop_user_sync_2() {{{
   * \brief Test get_preferred_interop_user_sync()
   */ // }}}
  void test_get_preferred_interop_user_sync_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_preferred_interop_user_sync(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_printf_buffer_size_1() {{{
   * \brief Test get_printf_buffer_size()
   */ // }}}
  void test_get_printf_buffer_size_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_printf_buffer_size(), 65536);
  }
  /** // doc: test_get_printf_buffer_size_2() {{{
   * \brief Test get_printf_buffer_size()
   */ // }}}
  void test_get_printf_buffer_size_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_printf_buffer_size(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_image_pitch_alignment_1() {{{
   * \brief Test get_image_pitch_alignment()
   */ // }}}
  void test_get_image_pitch_alignment_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_pitch_alignment(), 0);
  }
  /** // doc: test_get_image_pitch_alignment_2() {{{
   * \brief Test get_image_pitch_alignment()
   */ // }}}
  void test_get_image_pitch_alignment_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_pitch_alignment(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_get_image_base_address_alignment_1() {{{
   * \brief Test get_image_base_address_alignment()
   */ // }}}
  void test_get_image_base_address_alignment_1()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_image_base_address_alignment(), 0);
  }
  /** // doc: test_get_image_base_address_alignment_2() {{{
   * \brief Test get_image_base_address_alignment()
   */ // }}}
  void test_get_image_base_address_alignment_2()
  {
    T::Newton_clGetDeviceInfo mock;
    device d(T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_THROWS(d.get_image_base_address_alignment(), clerror_no<status_t::invalid_value>);
  }
#endif
// sorry, but this may irritate OOM instead of throwing bad_alloc
//  /** // doc: test_get_name_negsize() {{{
//   * \brief Test get_name(device_info_t::profile, ...) in a situation when clGetDeviceInfo returns negative string size.
//   */ // }}}
//  void test_get_name_negsize( )
//  {
//    T::SizeRet_clGetDeviceInfo mock(-1);
//    device d(reinterpret_cast<cl_device_id>(0x34556ul));
//    TS_ASSERT_THROWS(d.get_name(), CLXX_EXCEPTION(Bad_Alloc));
//  }
// sorry, but this may irritate OOM instead of throwing bad_alloc
//  /** // doc: test_get_name_negsize() {{{
//   * \brief Test get_name(device_info_t::profile, ...) in a situation when clGetDeviceInfo returns negative string size.
//   */ // }}}
//  void test_get_max_work_item_sizes_negsize( )
//  {
//    T::SizeRet_clGetDeviceInfo mock(-64);
//    device d(reinterpret_cast<cl_device_id>(0x34556ul));
//    TS_ASSERT_THROWS(d.get_max_work_item_sizes(), CLXX_EXCEPTION(Bad_Alloc));
//  }
  /** // doc: test_out_of_resources() {{{
   * \brief Test get_xxx() methods in a situation when clGetDeviceInfo returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test_out_of_resources( )
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_RESOURCES);
    device d(reinterpret_cast<cl_device_id>(0x34556ul));
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
#if CL_VERSION_1_2
    TS_ASSERT_THROWS(d.get_double_fp_config(), clerror_no<status_t::out_of_resources>);
#endif
#if CL_VERSION_1_1
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
#if CL_VERSION_1_2
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
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() methods in a situation when clGetDeviceInfo returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test_out_of_host_memory( )
  {
    T::Dummy_clGetDeviceInfo mock(CL_OUT_OF_HOST_MEMORY);
    device d(reinterpret_cast<cl_device_id>(0x34556ul));
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
#if CL_VERSION_1_2
    TS_ASSERT_THROWS(d.get_double_fp_config(), clerror_no<status_t::out_of_host_memory>);
#endif
#if CL_VERSION_1_1
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
#if CL_VERSION_1_2
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
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() methods in a situation when clGetDeviceInfo returns unknown error.
   */ // }}}
  void test_other_error( )
  {
    T::Dummy_clGetDeviceInfo mock(-0x432534);
    device d(reinterpret_cast<cl_device_id>(0x34556ul));
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
#if CL_VERSION_1_2
    TS_ASSERT_THROWS(d.get_double_fp_config(), unexpected_clerror);
#endif
#if CL_VERSION_1_1
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
#if CL_VERSION_1_2
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
  /** doc: test_query_device_info_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_query_device_info_1()
  {
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
  /** doc: test_query_device_info_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_query_device_info_2()
  {
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
//  /** // doc: test_eq_op_1() {{{
//   * \brief Test operator==()
//   */ // }}}
  void test_eq_op_1( )
  {
    TS_ASSERT(  device((cl_device_id)0x0000) == device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x1234) == device((cl_device_id)0x1234));
    TS_ASSERT(!(device((cl_device_id)0x1234) == device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x0000) == device((cl_device_id)0x1234)));
  }
//  /** // doc: test_neq_op_1() {{{
//   * \brief Test operator!=()
//   */ // }}}
  void test_neq_op_1( )
  {
    TS_ASSERT(!(device((cl_device_id)0x0000) != device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x1234) != device((cl_device_id)0x1234)));
    TS_ASSERT(  device((cl_device_id)0x1234) != device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x0000) != device((cl_device_id)0x1234));
  }
//  /** // doc: test_lt_op_1() {{{
//   * \brief Test operator<
//   */ // }}}
  void test_lt_op_1( )
  {
    TS_ASSERT(!(device((cl_device_id)0x0000) < device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x1234) < device((cl_device_id)0x1234)));
    TS_ASSERT(!(device((cl_device_id)0x1234) < device((cl_device_id)0x0000)));
    TS_ASSERT(  device((cl_device_id)0x0000) < device((cl_device_id)0x1234));
  }
//  /** // doc: test_gt_op_1() {{{
//   * \brief Test operator>
//   */ // }}}
  void test_gt_op_1( )
  {
    TS_ASSERT(!(device((cl_device_id)0x0000) > device((cl_device_id)0x0000)));
    TS_ASSERT(!(device((cl_device_id)0x1234) > device((cl_device_id)0x1234)));
    TS_ASSERT(  device((cl_device_id)0x1234) > device((cl_device_id)0x0000));
    TS_ASSERT(!(device((cl_device_id)0x0000) > device((cl_device_id)0x1234)));
  }
//  /** // doc: test_le_op_1() {{{
//   * \brief Test operator<=
//   */ // }}}
  void test_le_op_1( )
  {
    TS_ASSERT(  device((cl_device_id)0x0000) <= device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x1234) <= device((cl_device_id)0x1234));
    TS_ASSERT(!(device((cl_device_id)0x1234) <= device((cl_device_id)0x0000)));
    TS_ASSERT(  device((cl_device_id)0x0000) <= device((cl_device_id)0x1234));
  }
//  /** // doc: test_ge_op_1() {{{
//   * \brief Test operator>=
//   */ // }}}
  void test_ge_op_1( )
  {
    TS_ASSERT(  device((cl_device_id)0x0000) >= device((cl_device_id)0x0000));
    TS_ASSERT(  device((cl_device_id)0x1234) >= device((cl_device_id)0x1234));
    TS_ASSERT(  device((cl_device_id)0x1234) >= device((cl_device_id)0x0000));
    TS_ASSERT(!(device((cl_device_id)0x0000) >= device((cl_device_id)0x1234)));
  }
//  /** // doc: test_bool_op_1() {{{
//   * \brief Test operator bool
//   */ // }}}
  void test_bool_op_1( )
  {
    TS_ASSERT((bool)device((cl_device_id)0x1234));
    TS_ASSERT(!(bool)device((cl_device_id)0x000));
  }
};

#endif /* CLXX_CL_DEVICE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
