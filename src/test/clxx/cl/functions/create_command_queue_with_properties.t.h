// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_command_queue.t.h

/** // doc: clxx/cl/functions/create_command_queue_with_properties.t.h {{{
 * \file clxx/cl/functions/create_command_queue_with_properties.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_command_queue_with_properties_test_suite; }

/** // doc: class clxx::functions_create_command_queue_with_properties_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_command_queue_with_properties_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_command_queue_with_properties()
  ////////////////////////////////////////////////////////////////////////////
  /** // doc: test__create_command_queue_with_properties() {{{
   * \brief Test create_command_queue_with_properties() in a normal situation.
   */ // }}}
  void test__create_command_queue_with_properties( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL, (const cl_queue_properties*)NULL));
    //TS_ASSERT(mock.called_once_with((cl_context)NULL,0,nullptr,nullptr,nullptr,??? - local variable within create_command_queue_with_properties(...){...}));
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_context() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_device() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_DEVICE.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_device>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_value() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__invalid_command_queue() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_command_queue_with_properties__invalid_command_queue( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::invalid_queue_properties>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__out_of_resources() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_command_queue_with_properties__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__out_of_host_memory() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueueWithProperties() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_command_queue_with_properties__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_command_queue_with_properties__other_error() {{{
   * \brief Test create_command_queue_with_properties() in a situation when clCreateCommandQueue() returns an unexpected error code.
   */ // }}}
  void test__create_command_queue_with_properties__other_error( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock((cl_command_queue)NULL, -0x3456);
    TS_ASSERT_THROWS(create_command_queue_with_properties((cl_context)NULL,(cl_device_id)NULL,(const cl_queue_properties*)NULL), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_COMMAND_QUEUE_WITH_PROPERTIES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
