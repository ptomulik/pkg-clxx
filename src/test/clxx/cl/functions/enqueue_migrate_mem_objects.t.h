// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/enqueue_migrate_mem_objects.t.h

/** // doc: clxx/cl/functions/enqueue_migrate_mem_objects.t.h {{{
 * \file clxx/cl/functions/enqueue_migrate_mem_objects.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_ENQUEUE_MIGRATE_MEM_OBJECTS_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_ENQUEUE_MIGRATE_MEM_OBJECTS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_enqueue_migrate_mem_objects_test_suite; }

/** // doc: class clxx::functions_enqueue_migrate_mem_objects_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_enqueue_migrate_mem_objects_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_migrate_mem_objects()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_migrate_mem_objects() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_migrate_mem_objects(
                                        (cl_command_queue)0x123,
                                        23ul,
                                        (const cl_mem*)0x234,
                                        mem_migration_flags_t::mem_object_host,
                                        12u,
                                        (const cl_event*)0x890,
                                        (cl_event*)0x901));

    TS_ASSERT(mock.called_once_with(   (cl_command_queue)0x123,
                                        23ul,
                                        (const cl_mem*)0x234,
                                        (cl_mem_migration_flags)CL_MIGRATE_MEM_OBJECT_HOST,
                                        12u,
                                        (const cl_event*)0x890,
                                        (cl_event*)0x901));
  }
  /** // doc: test__enqueue_migrate_mem_objects__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__invalid_command_queue( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__invalid_context( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__invalid_mem_object( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::invalid_mem_object>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__invalid_value( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__invalid_event_wait_list( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::invalid_event_wait_list>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__mem_object_allocation_failure( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__out_of_resources( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__out_of_host_memory( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__enqueue_migrate_mem_objects__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_migrate_mem_objects__unexpected_clerror( )
  {
    T::Dummy_clEnqueueMigrateMemObjects mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_migrate_mem_objects((cl_command_queue)NULL,0ul,(const cl_mem*)NULL,mem_migration_flags_t::mem_object_host,0u,nullptr,nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_ENQUEUE_MIGRATE_MEM_OBJECTS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
