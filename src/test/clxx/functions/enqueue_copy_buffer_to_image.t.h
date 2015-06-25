// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/enqueue_copy_buffer_to_image.t.h

/** // doc: clxx/functions/enqueue_copy_buffer_to_image.t.h {{{
 * \file clxx/functions/enqueue_copy_buffer_to_image.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_ENQUEUE_COPY_BUFFER_TO_IMAGE_T_H_INCLUDED
#define CLXX_FUNCTIONS_ENQUEUE_COPY_BUFFER_TO_IMAGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_copy_buffer_to_image_test_suite; }

/** // doc: class clxx::functions_enqueue_copy_buffer_to_image_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_copy_buffer_to_image_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_copy_buffer_to_image()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_copy_buffer_to_image() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_copy_buffer_to_image(
                                      (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_mem)0x567,
                                      123ul,
                                      (const size_t*)0x123,
                                      (const size_t*)0x456,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_mem)0x567,
                                      123ul,
                                      (const size_t*)0x123,
                                      (const size_t*)0x456,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
  }
  /** // doc: test__enqueue_copy_buffer_to_image__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__invalid_command_queue( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__invalid_context( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__invalid_mem_object( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__invalid_value( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__invalid_event_wait_list( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__misaligned_sub_buffer_offset( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::misaligned_sub_buffer_offset>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__invalid_image_size( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_image_size>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__image_format_not_supported() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__image_format_not_supported( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::image_format_not_supported>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__mem_object_allocation_failure( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__invalid_operation( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_operation>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__out_of_resources( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__out_of_host_memory( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__enqueue_copy_buffer_to_image__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_copy_buffer_to_image__unexpected_clerror( )
  {
    T::Dummy_clEnqueueCopyBufferToImage mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_copy_buffer_to_image((cl_command_queue)NULL, (cl_mem)NULL, (cl_mem)NULL, 0ul, nullptr, nullptr, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_ENQUEUE_COPY_BUFFER_TO_IMAGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
