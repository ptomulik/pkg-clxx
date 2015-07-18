// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/retain_kernel.t.h

/** // doc: clxx/cl/functions/retain_kernel.t.h {{{
 * \file clxx/cl/functions/retain_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_RETAIN_KERNEL_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_RETAIN_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_retain_kernel_test_suite; }

/** // doc: class clxx::functions_retain_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_retain_kernel_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel( )
  {
    T::Dummy_clRetainKernel mock(CL_SUCCESS);
    retain_kernel                 ((cl_kernel)0x344);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x344));
  }
  /** // doc: test__retain_kernel__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__invalid_kernel( )
  {
    T::Dummy_clRetainKernel mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL),clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__retain_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__out_of_resources( )
  {
    T::Dummy_clRetainKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__out_of_host_memory( )
  {
    T::Dummy_clRetainKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__retain_kernel__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_kernel__unexpected_clerror( )
  {
    T::Dummy_clRetainKernel mock(-0x1234567);
    TS_ASSERT_THROWS(retain_kernel((cl_kernel)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_RETAIN_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
