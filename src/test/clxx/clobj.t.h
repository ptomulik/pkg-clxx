// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clobj.t.h

/** // doc: clxx/clobj.t.h {{{
 * \file clxx/clobj.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CLOBJ_T_H_INCLUDED
#define CLXX_CLOBJ_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/clobj.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class clobj_test_suite; }

/** // doc: class clxx::clobj_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::clobj_test_suite : public CxxTest::TestSuite
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

#endif /* CLXX_CLOBJ_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
