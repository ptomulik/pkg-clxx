// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_native_kernel.t.h

/** // doc: clxx/cl/functions/enqueue_native_kernel.t.h {{{
 * \file clxx/cl/functions/enqueue_native_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_NATIVE_KERNEL_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_NATIVE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_native_kernel_test_suite; }

/** // doc: class clxx::functions_enqueue_native_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_native_kernel_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_native_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_native_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_native_kernel(
                                      (cl_command_queue)0x123,
                                      (void(CL_CALLBACK*)(void*))0x234,
                                      (void*)0x345,
                                      0x456,
                                      0x567,
                                      (const cl_mem*)0x678,
                                      (const void**)0x789,
                                      0x890,
                                      (const cl_event*)0x901,
                                      (cl_event*)0x134) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (void(CL_CALLBACK*)(void*))0x234,
                                      (void*)0x345,
                                      0x456,
                                      0x567,
                                      (const cl_mem*)0x678,
                                      (const void**)0x789,
                                      0x890,
                                      (const cl_event*)0x901,
                                      (cl_event*)0x134) );
  }
  /** // doc: test__enqueue_native_kernel__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_command_queue( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__enqueue_native_kernel__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_context( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__enqueue_native_kernel__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_value( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__enqueue_native_kernel__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_operation( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_operation>);
  }
  /** // doc: test__enqueue_native_kernel__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_mem_object( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__enqueue_native_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__out_of_resources( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__enqueue_native_kernel__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__mem_object_allocation_failure( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
  }
  /** // doc: test__enqueue_native_kernel__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_event_wait_list( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
  }
  /** // doc: test__enqueue_native_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__out_of_host_memory( )
  {
    T::Dummy_clEnqueueNativeKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_NATIVE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
