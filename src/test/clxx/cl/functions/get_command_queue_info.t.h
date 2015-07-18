// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_command_queue_info.t.h

/** // doc: clxx/cl/functions/get_command_queue_info.t.h {{{
 * \file clxx/cl/functions/get_command_queue_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_COMMAND_QUEUE_INFO_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_COMMAND_QUEUE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_command_queue_info_test_suite; }

/** // doc: class clxx::functions_get_command_queue_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_command_queue_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_command_queue_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_command_queue_info() {{{
   * \brief Test get_command_queue_info() in a normal situation
   */ // }}}
  void test__get_command_queue_info( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL, CL_QUEUE_REFERENCE_COUNT, 0, nullptr, nullptr));
  }
  /** // doc: test__get_command_queue_info__invalid_command_queue() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__get_command_queue_info__invalid_command_queue( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__get_command_queue_info__invalid_value() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_INVALID_VALUE
   */ // }}}
  void test__get_command_queue_info__invalid_value( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_command_queue_info__out_of_resources() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__get_command_queue_info__out_of_resources( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_command_queue_info__out_of_host_memory() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__get_command_queue_info__out_of_host_memory( )
  {
    T::Dummy_clGetCommandQueueInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_command_queue_info__other_error() {{{
   * \brief Test get_command_queue_info() in a situation when clGetCommandQueueInfo() returns an unexpected error code.
   */ // }}}
  void test__get_command_queue_info__other_error( )
  {
    T::Dummy_clGetCommandQueueInfo mock(-0x3456);
    TS_ASSERT_THROWS(get_command_queue_info((cl_command_queue)NULL, command_queue_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_COMMAND_QUEUE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
