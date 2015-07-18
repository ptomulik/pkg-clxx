// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_platform_ids.t.h

/** // doc: clxx/cl/functions/get_platform_ids.t.h {{{
 * \file clxx/cl/functions/get_platform_ids.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_PLATFORM_IDS_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_PLATFORM_IDS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_platform_ids_test_suite; }

/** // doc: class clxx::functions_get_platform_ids_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_platform_ids_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  // get_platform_ids()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_platform_ids() {{{
   * \brief Test get_platform_ids() in a normal situation
   */ // }}}
  void test__get_platform_ids( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_platform_ids(0,nullptr,NULL));
    TS_ASSERT(mock.called_once_with(0,nullptr,NULL));
  }
  /** // doc: test__get_platform_ids__invalid_value() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_platform_ids__invalid_value( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_platform_ids__out_of_host_memory() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_platform_ids__out_of_host_memory( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_platform_ids__other_error() {{{
   * \brief Test get_platform_ids() in a situation when clGetPlatformIDs() returns unexpected error code.
   */ // }}}
  void test__get_platform_ids__other_error( )
  {
    T::Dummy_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_platform_ids(0,NULL,NULL), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_PLATFORM_IDS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
