// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/retain_mem_object.t.h

/** // doc: clxx/functions/retain_mem_object.t.h {{{
 * \file clxx/functions/retain_mem_object.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_RETAIN_MEM_OBJECT_T_H_INCLUDED
#define CLXX_FUNCTIONS_RETAIN_MEM_OBJECT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_retain_mem_object_test_suite; }

/** // doc: class clxx::functions_retain_mem_object_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_retain_mem_object_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_mem_object()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_mem_object( )
  {
    T::Dummy_clRetainMemObject mock(CL_SUCCESS);
    retain_mem_object              ((cl_mem)0x344);
    TS_ASSERT(mock.called_once_with((cl_mem)0x344));
  }
  /** // doc: test__retain_mem_object__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_mem_object__invalid_mem_object( )
  {
    T::Dummy_clRetainMemObject mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(retain_mem_object((cl_mem)NULL),clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__retain_mem_object__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_mem_object__out_of_resources( )
  {
    T::Dummy_clRetainMemObject mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_mem_object((cl_mem)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_mem_object__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_mem_object__out_of_host_memory( )
  {
    T::Dummy_clRetainMemObject mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_mem_object((cl_mem)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__retain_mem_object__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_mem_object__unexpected_clerror( )
  {
    T::Dummy_clRetainMemObject mock(-0x1234567);
    TS_ASSERT_THROWS(retain_mem_object((cl_mem)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_RETAIN_MEM_OBJECT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
