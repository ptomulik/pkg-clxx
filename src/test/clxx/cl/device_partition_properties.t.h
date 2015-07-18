// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_partition_properties.t.h

/** // doc: clxx/device_partition_properties.t.h {{{
 * \file clxx/device_partition_properties.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_PROPERTIES_T_H_INCLUDED
#define CLXX_DEVICE_PARTITION_PROPERTIES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/device_partition_properties.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx { class device_partition_properties_test_suite; }

/** // doc: class clxx::device_partition_properties_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::device_partition_properties_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_device_partition_properties_array_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_array_size()
  {
    TS_ASSERT_EQUALS(device_partition_properties_array_size(device_partition_properties()),1);
    TS_ASSERT_EQUALS(device_partition_properties_array_size(device_partition_properties({device_partition_equally(1)})),3);
    TS_ASSERT_EQUALS(device_partition_properties_array_size(device_partition_properties({device_partition_equally(1), device_partition_by_counts({2u})})),6);
  }
  /** // doc: test_device_partition_properties_fill_array_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_fill_array_1()
  {
    device_partition_properties props;
    cl_device_partition_property array[1];
    TS_ASSERT_EQUALS(device_partition_properties_fill_array(props,array,1ul),1ul);
    TS_ASSERT_EQUALS(array[0],(cl_device_partition_property)0ul);
  }
  /** // doc: test_device_partition_properties_fill_array_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_fill_array_2()
  {
    device_partition_properties props = { device_partition_equally(1) };
    cl_device_partition_property array[5];
    TS_ASSERT_EQUALS(device_partition_properties_fill_array(props,array,5ul),3ul);
    TS_ASSERT_EQUALS(array[0],(cl_device_partition_property)CL_DEVICE_PARTITION_EQUALLY);
    TS_ASSERT_EQUALS(array[1],(cl_device_partition_property)1ul);
    TS_ASSERT_EQUALS(array[2],(cl_device_partition_property)0ul);
  }
  /** // doc: test_device_partition_properties_fill_array_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_fill_array_3()
  {
    device_partition_properties props = { device_partition_equally(1),
                                          device_partition_by_counts({2u}) };
    cl_device_partition_property array[6];
    TS_ASSERT_EQUALS(device_partition_properties_fill_array(props,array,6ul),6ul);
    TS_ASSERT_EQUALS(array[0],(cl_device_partition_property)CL_DEVICE_PARTITION_EQUALLY);
    TS_ASSERT_EQUALS(array[1],(cl_device_partition_property)1ul);
    TS_ASSERT_EQUALS(array[2],(cl_device_partition_property)CL_DEVICE_PARTITION_BY_COUNTS);
    TS_ASSERT_EQUALS(array[3],(cl_device_partition_property)2ul);
    TS_ASSERT_EQUALS(array[4],(cl_device_partition_property)CL_DEVICE_PARTITION_BY_COUNTS_LIST_END);
    TS_ASSERT_EQUALS(array[5],(cl_device_partition_property)0ul);
  }
  /** // doc: test_device_partition_properties_fill_array_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_fill_array_4()
  {
    device_partition_properties props;
    TS_ASSERT_THROWS(device_partition_properties_fill_array(props,nullptr,8), invalid_argument_error);
  }
  /** // doc: test_device_partition_properties_fill_array_5() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_fill_array_5()
  {
    device_partition_properties props = { device_partition_equally(1),
                                          device_partition_by_counts({2u}) };
    cl_device_partition_property array[1];
    TS_ASSERT_THROWS(device_partition_properties_fill_array(props,array,1), not_enough_space_error);
  }
  /** // doc: test_device_partition_properties_fill_array_6() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_fill_array_6()
  {
    device_partition_properties props;
    cl_device_partition_property array[1];
    TS_ASSERT_THROWS(device_partition_properties_fill_array(props,array,0), not_enough_space_error);
  }
  /** // doc: test_device_partition_properties_parse_array_6() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_properties_parse_array_6()
  {
    cl_device_partition_property array[] = {
      CL_DEVICE_PARTITION_EQUALLY, (cl_device_partition_property)1ul,
      CL_DEVICE_PARTITION_BY_COUNTS, (cl_device_partition_property)2ul, CL_DEVICE_PARTITION_BY_COUNTS_LIST_END,
      (cl_device_partition_property)0ul
    };
    device_partition_properties cp;
    TS_ASSERT_EQUALS(device_partition_properties_parse_array(cp, array), 5);
    TS_ASSERT_EQUALS(cp[0].name(), device_partition_property_t::equally);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_device_partition_property)1ul);
    TS_ASSERT_EQUALS(cp[1].name(), device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(cp[1].value(0), (cl_device_partition_property)2ul);
  }
  /** // doc: test_op_and_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_1()
  {
    device_partition_properties cp(device_partition_equally(1) & device_partition_by_counts({2u}));
    TS_ASSERT_EQUALS(cp.size(), 2);
    TS_ASSERT_EQUALS(cp[0].name(), device_partition_property_t::equally);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_device_partition_property)1ul);
    TS_ASSERT_EQUALS(cp[1].name(), device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(cp[1].value(0), (cl_device_partition_property)2ul);
  }
  /** // doc: test_op_and_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_2()
  {
    device_partition_properties cp1;
    cp1.push_back(device_partition_equally(1));
    device_partition_properties cp(cp1 & device_partition_by_counts({2u}));
    TS_ASSERT_EQUALS(cp.size(), 2);
    TS_ASSERT_EQUALS(cp[0].name(), device_partition_property_t::equally);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_device_partition_property)1ul);
    TS_ASSERT_EQUALS(cp[1].name(), device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(cp[1].value(0), (cl_device_partition_property)2ul);
  }
  /** // doc: test_op_and_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_3()
  {
    device_partition_properties cp2;
    cp2.push_back(device_partition_by_counts({2u}));
    device_partition_properties cp(device_partition_equally(1) & cp2);
    TS_ASSERT_EQUALS(cp.size(), 2);
    TS_ASSERT_EQUALS(cp[0].name(), device_partition_property_t::equally);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_device_partition_property)1ul);
    TS_ASSERT_EQUALS(cp[1].name(), device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(cp[1].value(0), (cl_device_partition_property)2ul);
  }
  /** // doc: test_op_and_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_4()
  {
    device_partition_properties cp(device_partition_equally(1) & device_partition_by_counts({2u}) & device_partition_by_counts({3u}));
    TS_ASSERT_EQUALS(cp.size(), 3);
    TS_ASSERT_EQUALS(cp[0].name(), device_partition_property_t::equally);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_device_partition_property)1ul);
    TS_ASSERT_EQUALS(cp[1].name(), device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(cp[1].value(0), (cl_device_partition_property)2ul);
    TS_ASSERT_EQUALS(cp[2].name(), device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(cp[2].value(0), (cl_device_partition_property)3ul);
  }
  /** // doc: test_make_device_partition_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_make_device_partition_properties()
  {
    TS_ASSERT_THROWS_NOTHING(make_device_partition_properties());
    TS_ASSERT_THROWS_NOTHING(make_device_partition_properties(device_partition_equally(1)));
    TS_ASSERT_THROWS_NOTHING(make_device_partition_properties(device_partition_equally(1),device_partition_by_counts({2u})));
    TS_ASSERT_THROWS_NOTHING(make_device_partition_properties(device_partition_equally(1),device_partition_by_counts({2u}),device_partition_by_counts({3u})));
    TS_ASSERT_THROWS_NOTHING(make_device_partition_properties(make_device_partition_properties(device_partition_equally(1),device_partition_by_counts({2u})),device_partition_by_counts({3u})));
    TS_ASSERT_THROWS_NOTHING(make_device_partition_properties(device_partition_equally(1),make_device_partition_properties(device_partition_by_counts({2u}),device_partition_by_counts({3u}))));

    TS_ASSERT_EQUALS(make_device_partition_properties().size(), 0);
    TS_ASSERT_EQUALS(make_device_partition_properties(device_partition_equally(1)).size(), 1);
    TS_ASSERT_EQUALS(make_device_partition_properties(device_partition_equally(1),device_partition_by_counts({2u})).size(), 2);
    TS_ASSERT_EQUALS(make_device_partition_properties(device_partition_equally(1),device_partition_by_counts({2u}),device_partition_by_counts({3u})).size(),3);
  }
};

#endif /* CLXX_DEVICE_PARTITION_PROPERTIES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
