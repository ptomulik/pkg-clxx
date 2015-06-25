// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/release_kernel.t.h

/** // doc: clxx/functions/release_kernel.t.h {{{
 * \file clxx/functions/release_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_RELEASE_KERNEL_T_H_INCLUDED
#define CLXX_FUNCTIONS_RELEASE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_release_kernel_test_suite; }

/** // doc: class clxx::functions_release_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_release_kernel_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel( )
  {
    T::Dummy_clReleaseKernel mock(CL_SUCCESS);
    release_kernel                ((cl_kernel)0x433);
    TS_ASSERT(mock.called_once_with((cl_kernel)0x433));
  }
  /** // doc: test__release_kernel__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__invalid_kernel( )
  {
    T::Dummy_clReleaseKernel mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__release_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__out_of_resources( )
  {
    T::Dummy_clReleaseKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__out_of_host_memory( )
  {
    T::Dummy_clReleaseKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_kernel__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_kernel__unexpected_clerror( )
  {
    T::Dummy_clReleaseKernel mock(-0x1234567);
    TS_ASSERT_THROWS(release_kernel((cl_kernel)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_RELEASE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
