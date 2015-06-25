// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/enqueue_write_image.t.h

/** // doc: clxx/functions/enqueue_write_image.t.h {{{
 * \file clxx/functions/enqueue_write_image.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_ENQUEUE_WRITE_IMAGE_T_H_INCLUDED
#define CLXX_FUNCTIONS_ENQUEUE_WRITE_IMAGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_write_image_test_suite; }

/** // doc: class clxx::functions_enqueue_write_image_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_write_image_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_write_image()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_write_image() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_write_image(
                                      (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_bool)1,
                                      (const size_t*)0x7654,
                                      (const size_t*)0x5432,
                                      123ul,
                                      456ul,
                                      (const void*)0x678,
                                      789ul,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (cl_bool)1,
                                      (const size_t*)0x7654,
                                      (const size_t*)0x5432,
                                      123ul,
                                      456ul,
                                      (const void*)0x678,
                                      789ul,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
  }
  /** // doc: test__enqueue_write_image__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__invalid_command_queue( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__enqueue_write_image__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__invalid_context( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__enqueue_write_image__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__invalid_mem_object( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__enqueue_write_image__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__invalid_value( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__enqueue_write_image__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__invalid_event_wait_list( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
  }
  /** // doc: test__enqueue_write_image__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__invalid_image_size( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::invalid_image_size>);
  }
  /** // doc: test__enqueue_write_image__image_format_not_supported() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__image_format_not_supported( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::image_format_not_supported>);
  }
  /** // doc: test__enqueue_write_image__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__mem_object_allocation_failure( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
  }
  /** // doc: test__enqueue_write_image__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__invalid_operation( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::invalid_operation>);
  }
  /** // doc: test__enqueue_write_image__exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__exec_status_error_for_events_in_wait_list( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
  }
  /** // doc: test__enqueue_write_image__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__out_of_resources( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__enqueue_write_image__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__out_of_host_memory( )
  {
    T::Dummy_clEnqueueWriteImage mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__enqueue_write_image__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_image__unexpected_clerror( )
  {
    T::Dummy_clEnqueueWriteImage mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_write_image((cl_command_queue)NULL, (cl_mem)NULL, 0, nullptr, nullptr, 0ul, 0ul, nullptr, 0ul, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_ENQUEUE_WRITE_IMAGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
