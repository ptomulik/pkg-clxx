// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/enqueue_unmap_mem_object.t.h

/** // doc: clxx/functions/enqueue_unmap_mem_object.t.h {{{
 * \file clxx/functions/enqueue_unmap_mem_object.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_ENQUEUE_UNMAP_MEM_OBJECT_T_H_INCLUDED
#define CLXX_FUNCTIONS_ENQUEUE_UNMAP_MEM_OBJECT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_unmap_mem_object_test_suite; }

/** // doc: class clxx::functions_enqueue_unmap_mem_object_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_unmap_mem_object_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_unmap_mem_object()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_unmap_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_unmap_mem_object(
                                        (cl_command_queue)0x123,
                                        (cl_mem)0x234,
                                        (void*)0x567,
                                        12u,
                                        (const cl_event*)0x890,
                                        (cl_event*)0x901));

    TS_ASSERT(mock.called_once_with(    (cl_command_queue)0x123,
                                        (cl_mem)0x234,
                                        (void*)0x567,
                                        12u,
                                        (const cl_event*)0x890,
                                        (cl_event*)0x901));
  }
  /** // doc: test__enqueue_unmap_mem_object__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object__invalid_command_queue( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_unmap_mem_object((cl_command_queue)NULL,(cl_mem)NULL,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__enqueue_unmap_mem_object__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object__invalid_mem_object( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_unmap_mem_object((cl_command_queue)NULL,(cl_mem)NULL,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__enqueue_unmap_mem_object__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object__invalid_value( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_unmap_mem_object((cl_command_queue)NULL,(cl_mem)NULL,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__enqueue_unmap_mem_object__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object__invalid_event_wait_list( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_unmap_mem_object((cl_command_queue)NULL,(cl_mem)NULL,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_event_wait_list>);
  }
  /** // doc: test__enqueue_unmap_mem_object__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object__out_of_resources( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_unmap_mem_object((cl_command_queue)NULL,(cl_mem)NULL,nullptr,0u,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__enqueue_unmap_mem_object__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object__out_of_host_memory( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_unmap_mem_object((cl_command_queue)NULL,(cl_mem)NULL,nullptr,0u,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__enqueue_unmap_mem_object__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_unmap_mem_object__unexpected_clerror( )
  {
    T::Dummy_clEnqueueUnmapMemObject mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_unmap_mem_object((cl_command_queue)NULL,(cl_mem)NULL,nullptr,0u,nullptr,nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_ENQUEUE_UNMAP_MEM_OBJECT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
