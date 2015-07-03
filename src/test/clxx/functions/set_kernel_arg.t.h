// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/set_kernel_arg.t.h

/** // doc: clxx/functions/set_kernel_arg.t.h {{{
 * \file clxx/functions/set_kernel_arg.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_SET_KERNEL_ARG_T_H_INCLUDED
#define CLXX_FUNCTIONS_SET_KERNEL_ARG_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_set_kernel_arg_test_suite; }

/** // doc: class clxx::functions_set_kernel_arg_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_set_kernel_arg_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_kernel_arg()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_kernel_arg() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg( )
  {
    T::Dummy_clSetKernelArg mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876));
    TS_ASSERT(mock.called_once_with(        (cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876));
  }
  /** // doc: test__set_kernel_arg__invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_kernel( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_KERNEL);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_kernel>);
  }
  /** // doc: test__set_kernel_arg__invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_arg_index( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_ARG_INDEX);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_arg_index>);
  }
  /** // doc: test__set_kernel_arg__invalid_arg_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_arg_value( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_ARG_VALUE);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_arg_value>);
  }
  /** // doc: test__set_kernel_arg__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_mem_object( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__set_kernel_arg__invalid_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_sampler( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_SAMPLER);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_sampler>);
  }
  /** // doc: test__set_kernel_arg__invalid_device_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_device_queue( )
  {
#if CLXX_CL_H_VERSION_2_0
    T::Dummy_clSetKernelArg mock(CL_INVALID_DEVICE_QUEUE);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_device_queue>);
#endif
  }
  /** // doc: test__set_kernel_arg__invalid_arg_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__invalid_arg_size( )
  {
    T::Dummy_clSetKernelArg mock(CL_INVALID_ARG_SIZE);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::invalid_arg_size>);
  }
  /** // doc: test__set_kernel_arg__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__out_of_resources( )
  {
    T::Dummy_clSetKernelArg mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__set_kernel_arg__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__out_of_host_memory( )
  {
    T::Dummy_clSetKernelArg mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__set_kernel_arg__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_kernel_arg__unexpected_clerror( )
  {
    T::Dummy_clSetKernelArg mock(-0x12345678);
    TS_ASSERT_THROWS(set_kernel_arg((cl_kernel)NULL, 0x123, 0x543ul, (const void*)0x9876), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_SET_KERNEL_ARG_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
