// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/unit.t.h

/** // doc: clxx/unit.t.h {{{
 * \file clxx/unit.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UNIT_T_H_INCLUDED
#define CLXX_UNIT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/unit.hpp>

namespace clxx { class unit_test_suite; }

/** // doc: class clxx::unit_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::unit_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__foo() {{{
   * \todo Write documentation
   */ // }}}
  void test__foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_UNIT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
