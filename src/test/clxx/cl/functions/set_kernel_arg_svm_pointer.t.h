// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/set_kernel_arg_svm_pointer.t.h

/** // doc: clxx/cl/functions/set_kernel_arg_svm_pointer.t.h {{{
 * \file clxx/cl/functions/set_kernel_arg_svm_pointer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_SET_KERNEL_ARG_SVM_POINTER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_SET_KERNEL_ARG_SVM_POINTER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_set_kernel_arg_svm_pointer_test_suite; }

/** // doc: class clxx::functions_set_kernel_arg_svm_pointer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_set_kernel_arg_svm_pointer_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_kernel_arg_svm_pointer()
  ////////////////////////////////////////////////////////////////////////////
  /** // doc: test__set_kernel_arg_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(                    (cl_kernel)NULL, 0x123, (const void*)0x9876));
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_kernel( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_arg_index( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_ARG_INDEX);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_arg_index>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__invalid_arg_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__invalid_arg_value( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_INVALID_ARG_VALUE);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::invalid_arg_value>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__set_kernel_arg_svm_pointer__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg_svm_pointer__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clSetKernelArgSVMPointer mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_arg_svm_pointer((cl_kernel)NULL, 0x123, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_SET_KERNEL_ARG_SVM_POINTER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
