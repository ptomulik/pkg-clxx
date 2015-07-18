// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/set_kernel_exec_info.t.h

/** // doc: clxx/cl/functions/set_kernel_exec_info.t.h {{{
 * \file clxx/cl/functions/set_kernel_exec_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_SET_KERNEL_EXEC_INFO_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_SET_KERNEL_EXEC_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_set_kernel_exec_info_test_suite; }

/** // doc: class clxx::functions_set_kernel_exec_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_set_kernel_exec_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_kernel_exec_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_kernel_exec_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(              (cl_kernel)NULL, CL_KERNEL_EXEC_INFO_SVM_PTRS, 0x123, (const void*)0x9876));
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_kernel( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__set_kernel_exec_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_exec_info__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clSetKernelExecInfo mock(-0x12345678);
    TS_ASSERT_THROWS(set_kernel_exec_info((cl_kernel)NULL, kernel_exec_info_t::svm_ptrs, 0x123, (const void*)0x9876), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_SET_KERNEL_EXEC_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
