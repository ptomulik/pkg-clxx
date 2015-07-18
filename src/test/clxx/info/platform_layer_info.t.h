// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/platform_layer_info.t.h

/** // doc: clxx/info/platform_layer_info.t.h {{{
 * \file clxx/info/platform_layer_info.t.h
 * \brief Unit tests for clxx::platform_layer_info
 */ // }}}
#ifndef CLXX_INFO_PLATFORM_LAYER_INFO_T_H_INCLUDED
#define CLXX_INFO_PLATFORM_LAYER_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/info/platform_layer_info.hpp>
#include <clxx/platform_layer_info_fixtures.hpp>
#include <clxx/info/platform_info.hpp>
#include <clxx/info/device_info.hpp>

namespace clxx { class platform_layer_info_test_suite; }

/** // doc: class clxx::platform_layer_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::platform_layer_info_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_ctor( )
  {
    TS_ASSERT_THROWS_NOTHING(platform_layer_info p);
    TS_ASSERT(platform_layer_info().get_platforms().empty());
    TS_ASSERT(platform_layer_info().get_devices().empty());
  }
  /** // doc: test_mapping_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_mapping_1( )
  {
    platform_layer_info pli(platform_layer_info_fixtures::_1());

    TS_ASSERT_EQUALS(pli.get_platforms().size(), 2);

    const_platform_info_ptr p1(pli.get_platforms()[0]);
    const_platform_info_ptr p2(pli.get_platforms()[1]);

    TS_ASSERT_EQUALS(pli.get_devices().size(), 4);
    TS_ASSERT_EQUALS(pli.get_devices(p1).size(), 2);
    TS_ASSERT_EQUALS(pli.get_devices(p2).size(), 2);

    TS_ASSERT_EQUALS(pli.get_platforms()[0]->name(),"platform 1");
    TS_ASSERT_EQUALS(pli.get_platforms()[1]->name(),"platform 2");

    TS_ASSERT_EQUALS(pli.get_devices()[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(pli.get_devices()[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(pli.get_devices()[2]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(pli.get_devices()[3]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(pli.get_devices(p1)[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(pli.get_devices(p1)[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(pli.get_devices(p2)[0]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(pli.get_devices(p2)[1]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[0]), p1);
    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[1]), p1);
    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[2]), p2);
    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[3]), p2);

    // peek some functions via the const platform_layer_info object
    platform_layer_info const& cpli = pli;
    TS_ASSERT_EQUALS(cpli.get_platforms()[0]->name(),"platform 1");
    TS_ASSERT_EQUALS(cpli.get_platforms()[1]->name(),"platform 2");

    TS_ASSERT_EQUALS(cpli.get_devices()[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices()[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(cpli.get_devices()[2]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices()[3]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(cpli.get_devices(p1)[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices(p1)[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(cpli.get_devices(p2)[0]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices(p2)[1]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[0]), p1);
    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[1]), p1);
    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[2]), p2);
    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[3]), p2);
  }
  /** // doc: test_remove_device() {{{
   * \todo Write documentation
   */ // }}}
  void test_remove_device( )
  {
    platform_layer_info pli(platform_layer_info_fixtures::_1());

    pli.remove(pli.get_devices(pli.get_platforms()[1])[0]);
    TS_ASSERT_EQUALS(pli.get_devices().size(), 3);
    TS_ASSERT_EQUALS(pli.get_devices()[0]->name(),"platform 1 device 1")
    TS_ASSERT_EQUALS(pli.get_devices()[1]->name(),"platform 1 device 2")
    TS_ASSERT_EQUALS(pli.get_devices()[2]->name(),"platform 2 device 2")

    pli.remove(pli.get_platforms()[0]);
    TS_ASSERT_EQUALS(pli.get_devices().size(), 1);
    TS_ASSERT_EQUALS(pli.get_platforms().size(), 1);
    TS_ASSERT_EQUALS(pli.get_devices()[0]->name(),"platform 2 device 2");

    pli.remove(pli.get_devices()[0]);
    TS_ASSERT(pli.get_devices().empty());
    TS_ASSERT(pli.get_platforms().empty());
  }
  /** // doc: test_clear() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear( )
  {
    platform_layer_info pli(platform_layer_info_fixtures::_1());
    pli.clear();
    TS_ASSERT(pli.get_platforms().empty());
    TS_ASSERT(pli.get_devices().empty());
  }
  /** // doc: test_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_empty( )
  {
    platform_layer_info pli;
    TS_ASSERT(pli.empty());
    pli = platform_layer_info_fixtures::_1();
    TS_ASSERT(!pli.empty());
    pli.clear();
    TS_ASSERT(pli.empty());
  }
};

#endif /* CLXX_INFO_PLATFORM_LAYER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
