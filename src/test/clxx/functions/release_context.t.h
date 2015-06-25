// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/release_context.t.h

/** // doc: clxx/functions/release_context.t.h {{{
 * \file clxx/functions/release_context.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_RELEASE_CONTEXT_T_H_INCLUDED
#define CLXX_FUNCTIONS_RELEASE_CONTEXT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_release_context_test_suite; }

/** // doc: class clxx::functions_release_context_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_release_context_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_context()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_context() {{{
   * \brief Test release_context() in a normal situation
   */ // }}}
  void test__release_context( )
  {
    T::Dummy_clReleaseContext mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_context((cl_context)NULL));
    TS_ASSERT(mock.called_once_with((cl_context)NULL));
  }
  /** // doc: test__release_context__invalid_context() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__release_context__invalid_context( )
  {
    T::Dummy_clReleaseContext mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__release_context__out_of_resources() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_context__out_of_resources( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_context__out_of_host_memory() {{{
   * \brief Test release_context() in a situation when clReleaseContext() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_context__out_of_host_memory( )
  {
    T::Dummy_clReleaseContext mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_context((cl_context)NULL), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_FUNCTIONS_RELEASE_CONTEXT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
