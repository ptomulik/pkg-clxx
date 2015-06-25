// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/retain_context.t.h

/** // doc: clxx/functions/retain_context.t.h {{{
 * \file clxx/functions/retain_context.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_RETAIN_CONTEXT_T_H_INCLUDED
#define CLXX_FUNCTIONS_RETAIN_CONTEXT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_retain_context_test_suite; }

/** // doc: class clxx::functions_retain_context_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_retain_context_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_context()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_context() {{{
   * \brief Test retain_context() in a normal situation
   */ // }}}
  void test__retain_context( )
  {
    T::Dummy_clRetainContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test__retain_context__invalid_context() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__retain_context__invalid_context( )
  {
    T::Dummy_clRetainContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__retain_context__out_of_resources() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__retain_context__out_of_resources( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_context__out_of_host_memory() {{{
   * \brief Test retain_context() in a situation when clRetainContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__retain_context__out_of_host_memory( )
  {
    T::Dummy_clRetainContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_FUNCTIONS_RETAIN_CONTEXT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
