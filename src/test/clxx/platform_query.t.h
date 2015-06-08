// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_query.t.h

/** // doc: clxx/platform_query.t.h {{{
 * \file clxx/platform_query.t.h
 * \brief Unit tests for clxx::platform_query
 */ // }}}
#ifndef CLXX_PLATFORM_QUERY_T_H_INCLUDED
#define CLXX_PLATFORM_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/platform_query.hpp>
#include <clxx/platform_query_fixtures.hpp>

namespace clxx { class platform_query_test_suite; }

/** // doc: class clxx::platform_query_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::platform_query_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \brief Test default constructor
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(platform_query().id_selected());
    TS_ASSERT(platform_query().profile_selected());
    TS_ASSERT(platform_query().version_selected());
    TS_ASSERT(platform_query().name_selected());
    TS_ASSERT(platform_query().vendor_selected());
    TS_ASSERT(platform_query().extensions_selected());
  }
  /** // doc: test_ctor_true() {{{
   * \brief Test default constructor
   */ // }}}
  void test_ctor_true( )
  {
    TS_ASSERT(platform_query(true).id_selected());
    TS_ASSERT(platform_query(true).profile_selected());
    TS_ASSERT(platform_query(true).version_selected());
    TS_ASSERT(platform_query(true).name_selected());
    TS_ASSERT(platform_query(true).vendor_selected());
    TS_ASSERT(platform_query(true).extensions_selected());
  }
  /** // doc: test_ctor_false() {{{
   * \brief Test default constructor
   */ // }}}
  void test_ctor_false( )
  {
    TS_ASSERT(!platform_query(false).id_selected());
    TS_ASSERT(!platform_query(false).profile_selected());
    TS_ASSERT(!platform_query(false).version_selected());
    TS_ASSERT(!platform_query(false).name_selected());
    TS_ASSERT(!platform_query(false).vendor_selected());
    TS_ASSERT(!platform_query(false).extensions_selected());
  }
  /** // doc: test_set_get_1() {{{
   * \brief Test set_get_1() method.
   */ // }}}
  void test_set_get_1( )
  {
    TS_ASSERT(!platform_query(true).select_id(false).id_selected());
    TS_ASSERT(!platform_query(true).select_profile(false).profile_selected());
    TS_ASSERT(!platform_query(true).select_version(false).version_selected());
    TS_ASSERT(!platform_query(true).select_name(false).name_selected());
    TS_ASSERT(!platform_query(true).select_vendor(false).vendor_selected());
    TS_ASSERT(!platform_query(true).select_extensions(false).extensions_selected());
  }
  /** // doc: test_eq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op( )
  {
    TS_ASSERT(!(platform_query(true).select_id(false) == platform_query(true)));
    TS_ASSERT(!(platform_query(true).select_profile(false) == platform_query(true)));
    TS_ASSERT(!(platform_query(true).select_version(false) == platform_query(true)));
    TS_ASSERT(!(platform_query(true).select_name(false) == platform_query(true)));
    TS_ASSERT(!(platform_query(true).select_vendor(false) == platform_query(true)));
    TS_ASSERT(!(platform_query(true).select_extensions(false) == platform_query(true)));
  }
  /** // doc: test_neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op( )
  {
    TS_ASSERT((platform_query(true).select_id(false) != platform_query(true)));
    TS_ASSERT((platform_query(true).select_profile(false) != platform_query(true)));
    TS_ASSERT((platform_query(true).select_version(false) != platform_query(true)));
    TS_ASSERT((platform_query(true).select_name(false) != platform_query(true)));
    TS_ASSERT((platform_query(true).select_vendor(false) != platform_query(true)));
    TS_ASSERT((platform_query(true).select_extensions(false) != platform_query(true)));
  }
  /** // doc: test_select_all() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_all( )
  {
    TS_ASSERT((platform_query(false).select_all().id_selected()));
    TS_ASSERT((platform_query(false).select_all().profile_selected()));
    TS_ASSERT((platform_query(false).select_all().version_selected()));
    TS_ASSERT((platform_query(false).select_all().name_selected()));
    TS_ASSERT((platform_query(false).select_all().vendor_selected()));
    TS_ASSERT((platform_query(false).select_all().extensions_selected()));
  }
  /** // doc: test_select_none() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_none( )
  {
    TS_ASSERT(!(platform_query(true).select_none().id_selected()));
    TS_ASSERT(!(platform_query(true).select_none().profile_selected()));
    TS_ASSERT(!(platform_query(true).select_none().version_selected()));
    TS_ASSERT(!(platform_query(true).select_none().name_selected()));
    TS_ASSERT(!(platform_query(true).select_none().vendor_selected()));
    TS_ASSERT(!(platform_query(true).select_none().extensions_selected()));
  }
  /** // doc: test_select_all() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_default( )
  {
    TS_ASSERT((platform_query(false).select_default() == platform_query()));
    TS_ASSERT((platform_query(true).select_default() == platform_query()));
  }
};

#endif /* CLXX_PLATFORM_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
