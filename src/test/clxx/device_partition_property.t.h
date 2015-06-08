// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_partition_property.t.h

/** // doc: clxx/device_partition_property.t.h {{{
 * \file clxx/device_partition_property.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_PROPERTY_T_H_INCLUDED
#define CLXX_DEVICE_PARTITION_PROPERTY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/device_partition_property.hpp>

namespace clxx { class device_partition_property_test_suite; }

/** // doc: class clxx::device_partition_property_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::device_partition_property_test_suite : public CxxTest::TestSuite
{
  void call_with_device_partition_property(device_partition_property const&) { }
public:
  /** // doc: test_default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_ctor( )
  {
    TS_ASSERT_THROWS_NOTHING(device_partition_property());
    TS_ASSERT_EQUALS(device_partition_property().name(),static_cast<device_partition_property_t>((cl_device_partition_property)0ul));
    TS_ASSERT_EQUALS(device_partition_property().value(),(cl_device_partition_property)0ul);
  }
  /** // doc: test_ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1( )
  {
    TS_ASSERT_THROWS_NOTHING(device_partition_property(device_partition_property_t::equally, (cl_device_partition_property)2));
    TS_ASSERT_THROWS_NOTHING(device_partition_property(device_partition_property_t::by_counts, device_partition_counts({2u})));
#if CL_VERSION_1_2
    TS_ASSERT_THROWS_NOTHING(device_partition_property(device_partition_property_t::by_affinity_domain, static_cast<cl_device_partition_property>(device_affinity_domain_t::l4_cache)));
#endif
  }
  /** // doc: test_ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2( )
  {
    TS_ASSERT_THROWS_NOTHING(device_partition_property(CL_DEVICE_PARTITION_EQUALLY, (cl_device_partition_property)1));
    TS_ASSERT_THROWS_NOTHING(device_partition_property(CL_DEVICE_PARTITION_BY_COUNTS, device_partition_counts({2ul})));
#if CL_VERSION_1_2
    TS_ASSERT_THROWS_NOTHING(device_partition_property(CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN, (cl_device_partition_property)CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE));
#endif
  }
  /** // doc: test_name() {{{
   * \todo Write documentation
   */ // }}}
  void test_name( )
  {
    TS_ASSERT_EQUALS(device_partition_property(device_partition_property_t::equally, 4).name(), device_partition_property_t::equally);
  }
  /** // doc: test_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_value( )
  {
    TS_ASSERT_EQUALS(device_partition_property(device_partition_property_t::equally, 0).value(), (cl_device_partition_property)0);
    TS_ASSERT_EQUALS(device_partition_property(device_partition_property_t::equally, 3).value(), (cl_device_partition_property)3);
  }
  /** // doc: test_set_name() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_name( )
  {
    device_partition_property cp;
    TS_ASSERT_THROWS_NOTHING(cp.set_name(device_partition_property_t::equally));
    TS_ASSERT_EQUALS(cp.name(), device_partition_property_t::equally);
    TS_ASSERT_THROWS_NOTHING(cp.set_name(device_partition_property_t::by_counts));
    TS_ASSERT_EQUALS(cp.name(), device_partition_property_t::by_counts);
  }
  /** // doc: test_set_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_value( )
  {
    device_partition_property cp;
    TS_ASSERT_THROWS_NOTHING(cp.set_value((cl_device_partition_property)0));
    TS_ASSERT_EQUALS(cp.value(), (cl_device_partition_property)0);
    TS_ASSERT_THROWS_NOTHING(cp.set_value((cl_device_partition_property)123));
    TS_ASSERT_EQUALS(cp.value(), (cl_device_partition_property)123);
  }
  /** // doc: test_write() {{{
   * \todo Write documentation
   */ // }}}
  void test_write( )
  {
    cl_device_partition_property array[3] = {(cl_device_partition_property)0, (cl_device_partition_property)0, (cl_device_partition_property)123};
    device_partition_property cp(device_partition_property_t::equally, 4);
    cp.write(array);
    TS_ASSERT_EQUALS(array[0], (cl_device_partition_property)CL_DEVICE_PARTITION_EQUALLY);
    TS_ASSERT_EQUALS(array[1], (cl_device_partition_property)4);
    TS_ASSERT_EQUALS(array[2], (cl_device_partition_property)123);
  }
  /** // doc: test_read() {{{
   * \todo Write documentation
   */ // }}}
  void test_read( )
  {
    cl_device_partition_property array[3] = {CL_DEVICE_PARTITION_EQUALLY, (cl_device_partition_property)4, (cl_device_partition_property)1234};
    device_partition_property cp;
    cp.read(array);
    TS_ASSERT_EQUALS(cp.name(), device_partition_property_t::equally);
    TS_ASSERT_EQUALS(cp.value(), (cl_device_partition_property)4);
  }
  /** // doc: test_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_size( )
  {
    TS_ASSERT_EQUALS(device_partition_property(device_partition_property_t::equally, (cl_device_partition_property)4).size(), 2);
    TS_ASSERT_EQUALS(device_partition_property(device_partition_property_t::by_counts, device_partition_counts({3u,4u})).size(), 4);
  }
  /** // doc: test_make_device_partition_property() {{{
   * \todo Write documentation
   */ // }}}
  void test_make_device_partition_property( )
  {
    TS_ASSERT_EQUALS(make_device_partition_property<device_partition_property_t::equally>(4).name(),device_partition_property_t::equally);
    TS_ASSERT_EQUALS(make_device_partition_property<device_partition_property_t::equally>(4).value(),(cl_device_partition_property)4);

    TS_ASSERT_EQUALS(make_device_partition_property<device_partition_property_t::by_counts>({1u,2u}).name(),device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(make_device_partition_property<device_partition_property_t::by_counts>({1u,2u}).value(0),(cl_device_partition_property)1u);
    TS_ASSERT_EQUALS(make_device_partition_property<device_partition_property_t::by_counts>({1u,2u}).value(1),(cl_device_partition_property)2u);
  }
  /** // doc: test_creators() {{{
   * \todo Write documentation
   */ // }}}
  void test_creators( )
  {
    TS_ASSERT_EQUALS(device_partition_equally(4).name(),device_partition_property_t::equally);
    TS_ASSERT_EQUALS(device_partition_equally(4).value(),(cl_device_partition_property)4);
    TS_ASSERT_EQUALS(device_partition_by_counts({4u,5u}).name(),device_partition_property_t::by_counts);
    TS_ASSERT_EQUALS(device_partition_by_counts({4u,5u}).value(0),(cl_device_partition_property)4);
    TS_ASSERT_EQUALS(device_partition_by_counts({4u,5u}).value(1),(cl_device_partition_property)5);
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(device_partition_by_affinity_domain(device_affinity_domain_t::l4_cache).name(),device_partition_property_t::by_affinity_domain);
    TS_ASSERT_EQUALS(device_partition_by_affinity_domain(device_affinity_domain_t::l4_cache).value(),(cl_device_partition_property)device_affinity_domain_t::l4_cache);
#endif
  }
};

#endif /* CLXX_DEVICE_PARTITION_PROPERTY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
