// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/platform_info.t.h

/** // doc: clxx/info/platform_info.t.h {{{
 * \file clxx/info/platform_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_INFO_PLATFORM_INFO_T_H_INCLUDED
#define CLXX_INFO_PLATFORM_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/info/platform_info.hpp>
#include <clxx/platform_info_fixtures.hpp>
#include <clxx/common/exceptions.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace clxx { class platform_info_test_suite; }

/** // doc: class clxx::platform_info_test_suite {{{
 * \brief Unit tests for clxx::platform_info class
 */ // }}}
class clxx::platform_info_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \todo Write documentation
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(!platform_info().has_id());
    TS_ASSERT(!platform_info().has_profile());
    TS_ASSERT(!platform_info().has_version());
    TS_ASSERT(!platform_info().has_name());
    TS_ASSERT(!platform_info().has_vendor());
    TS_ASSERT(!platform_info().has_extensions());
  }
  /** // doc: test_getter_exceptions() {{{
   * \todo Write documentation
   */ // }}}
  void test_getter_exceptions( )
  {
    TS_ASSERT_THROWS(platform_info().id(), uninitialized_value_error);
    TS_ASSERT_THROWS(platform_info().profile(), uninitialized_value_error);
    TS_ASSERT_THROWS(platform_info().version(), uninitialized_value_error);
    TS_ASSERT_THROWS(platform_info().name(), uninitialized_value_error);
    TS_ASSERT_THROWS(platform_info().vendor(), uninitialized_value_error);
    TS_ASSERT_THROWS(platform_info().extensions(), uninitialized_value_error);
  }
  /** // doc: test_set_get() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get( )
  {
    TS_ASSERT_EQUALS(platform_info().set_id(0x12345ul).id(), 0x12345ul);
    TS_ASSERT_EQUALS(platform_info().set_profile("profile").profile(), "profile");
    TS_ASSERT_EQUALS(platform_info().set_version("version").version(), "version");
    TS_ASSERT_EQUALS(platform_info().set_name("name").name(), "name");
    TS_ASSERT_EQUALS(platform_info().set_vendor("vendor").vendor(), "vendor");
    TS_ASSERT_EQUALS(platform_info().set_extensions("extensions").extensions(), "extensions");
  }
  /** // doc: test_set_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_has_1( )
  {
    TS_ASSERT(platform_info().set_id(0x12345ul).has_id());
    TS_ASSERT(platform_info().set_profile("profile").has_profile());
    TS_ASSERT(platform_info().set_version("version").has_version());
    TS_ASSERT(platform_info().set_name("name").has_name());
    TS_ASSERT(platform_info().set_vendor("vendor").has_vendor());
    TS_ASSERT(platform_info().set_extensions("extensions").has_extensions());
  }
  /** // doc: test_set_has_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_has_2( )
  {
    platform_info const infos[2] = { platform_info_fixtures::_1(), platform_info_fixtures::_2() };
    for(platform_info const* info = infos; info < infos + 2; ++info)
    {
      TS_ASSERT(info->has_id());
      TS_ASSERT(info->has_profile());
      TS_ASSERT(info->has_version());
      TS_ASSERT(info->has_name());
      TS_ASSERT(info->has_vendor());
      TS_ASSERT(info->has_extensions());
    }
  }
  /** // doc: test_clear_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_has_1( )
  {
    TS_ASSERT(!platform_info().set_id(0x12345ul).clear_id().has_id());
    TS_ASSERT(!platform_info().set_profile("profile").clear_profile().has_profile());
    TS_ASSERT(!platform_info().set_version("version").clear_version().has_version());
    TS_ASSERT(!platform_info().set_name("name").clear_name().has_name());
    TS_ASSERT(!platform_info().set_vendor("vendor").clear_vendor().has_vendor());
    TS_ASSERT(!platform_info().set_extensions("extensions").clear_extensions().has_extensions());
  }
  /** // doc: test_clear_has_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_has_2( )
  {
    platform_info info(platform_info_fixtures::_1());

    info.clear();

    TS_ASSERT(!info.has_id());
    TS_ASSERT(!info.has_profile());
    TS_ASSERT(!info.has_version());
    TS_ASSERT(!info.has_name());
    TS_ASSERT(!info.has_vendor());
    TS_ASSERT(!info.has_extensions());
  }
  /** // doc: test_eq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_1()
  {
    TS_ASSERT((platform_info() == platform_info()));
  }
  /** // doc: test_eq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_2()
  {
    TS_ASSERT(!(platform_info().set_id(0x12345ul) == platform_info()));
    TS_ASSERT(!(platform_info().set_profile("profile") == platform_info()));
    TS_ASSERT(!(platform_info().set_version("version") == platform_info()));
    TS_ASSERT(!(platform_info().set_name("name") == platform_info()));
    TS_ASSERT(!(platform_info().set_vendor("vendor") == platform_info()));
    TS_ASSERT(!(platform_info().set_extensions("extensions") == platform_info()));
  }
  /** // doc: test_eq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_3()
  {
    TS_ASSERT(!(platform_info().set_id(0x12345ul) == platform_info().set_id(0x56798ul)));
    TS_ASSERT(!(platform_info().set_profile("profile") == platform_info().set_profile("xxx")));
    TS_ASSERT(!(platform_info().set_version("version") == platform_info().set_version("xxx")));
    TS_ASSERT(!(platform_info().set_name("name") == platform_info().set_name("xxx")));
    TS_ASSERT(!(platform_info().set_vendor("vendor") == platform_info().set_vendor("xxx")));
    TS_ASSERT(!(platform_info().set_extensions("extensions") == platform_info().set_extensions("xxx")));
  }
  /** // doc: test_eq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_4()
  {
    TS_ASSERT((platform_info().set_id(0x12345ul) == platform_info().set_id(0x12345ul)));
    TS_ASSERT((platform_info().set_profile("profile") == platform_info().set_profile("profile")));
    TS_ASSERT((platform_info().set_version("version") == platform_info().set_version("version")));
    TS_ASSERT((platform_info().set_name("name") == platform_info().set_name("name")));
    TS_ASSERT((platform_info().set_vendor("vendor") == platform_info().set_vendor("vendor")));
    TS_ASSERT((platform_info().set_extensions("extensions") == platform_info().set_extensions("extensions")));
  }
  /** // doc: test_neq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_1()
  {
    TS_ASSERT(!(platform_info() != platform_info()));
  }
  /** // doc: test_neq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_2()
  {
    TS_ASSERT((platform_info().set_id(0x12345ul) != platform_info()));
    TS_ASSERT((platform_info().set_profile("profile") != platform_info()));
    TS_ASSERT((platform_info().set_version("version") != platform_info()));
    TS_ASSERT((platform_info().set_name("name") != platform_info()));
    TS_ASSERT((platform_info().set_vendor("vendor") != platform_info()));
    TS_ASSERT((platform_info().set_extensions("extensions") != platform_info()));
  }
  /** // doc: test_neq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_3()
  {
    TS_ASSERT((platform_info().set_id(0x12345ul) != platform_info().set_id(0x56798ul)));
    TS_ASSERT((platform_info().set_profile("profile") != platform_info().set_profile("xxx")));
    TS_ASSERT((platform_info().set_version("version") != platform_info().set_version("xxx")));
    TS_ASSERT((platform_info().set_name("name") != platform_info().set_name("xxx")));
    TS_ASSERT((platform_info().set_vendor("vendor") != platform_info().set_vendor("xxx")));
    TS_ASSERT((platform_info().set_extensions("extensions") != platform_info().set_extensions("xxx")));
  }
  /** // doc: test_neq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_4()
  {
    TS_ASSERT(!(platform_info().set_id(0x12345ul) != platform_info().set_id(0x12345ul)));
    TS_ASSERT(!(platform_info().set_profile("profile") != platform_info().set_profile("profile")));
    TS_ASSERT(!(platform_info().set_version("version") != platform_info().set_version("version")));
    TS_ASSERT(!(platform_info().set_name("name") != platform_info().set_name("name")));
    TS_ASSERT(!(platform_info().set_vendor("vendor") != platform_info().set_vendor("vendor")));
    TS_ASSERT(!(platform_info().set_extensions("extensions") != platform_info().set_extensions("extensions")));
  }
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor()
  {
    platform_info a(platform_info_fixtures::_1());
    platform_info b(a);
    TS_ASSERT((a == b));
  }
  /** // doc: test_assign_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_assign_op()
  {
    platform_info a(platform_info_fixtures::_1());
    platform_info b;
    b = a;
    TS_ASSERT((a == b));
  }
};

#endif /* CLXX_INFO_PLATFORM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
