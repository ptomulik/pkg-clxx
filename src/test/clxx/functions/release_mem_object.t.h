// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/release_mem_object.t.h

/** // doc: clxx/functions/release_mem_object.t.h {{{
 * \file clxx/functions/release_mem_object.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_RELEASE_MEM_OBJECT_T_H_INCLUDED
#define CLXX_FUNCTIONS_RELEASE_MEM_OBJECT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_release_mem_object_test_suite; }

/** // doc: class clxx::functions_release_mem_object_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_release_mem_object_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_mem_object()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object( )
  {
    T::Dummy_clReleaseMemObject mock(CL_SUCCESS);
    release_mem_object             ((cl_mem)0x433);
    TS_ASSERT(mock.called_once_with((cl_mem)0x433));
  }
  /** // doc: test__release_mem_object__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__invalid_mem_object( )
  {
    T::Dummy_clReleaseMemObject mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL),clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__release_mem_object__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__out_of_resources( )
  {
    T::Dummy_clReleaseMemObject mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_mem_object__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__out_of_host_memory( )
  {
    T::Dummy_clReleaseMemObject mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_mem_object__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_mem_object__unexpected_clerror( )
  {
    T::Dummy_clReleaseMemObject mock(-0x1234567);
    TS_ASSERT_THROWS(release_mem_object((cl_mem)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_RELEASE_MEM_OBJECT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
