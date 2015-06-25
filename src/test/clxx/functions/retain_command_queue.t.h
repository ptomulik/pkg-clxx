// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/retain_command_queue.t.h

/** // doc: clxx/functions/retain_command_queue.t.h {{{
 * \file clxx/functions/retain_command_queue.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_RETAIN_COMMAND_QUEUE_T_H_INCLUDED
#define CLXX_FUNCTIONS_RETAIN_COMMAND_QUEUE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_retain_command_queue_test_suite; }

/** // doc: class clxx::functions_retain_command_queue_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_retain_command_queue_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_command_queue()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_command_queue() {{{
   * \brief Test retain_command_queue() in a normal situation
   */ // }}}
  void test__retain_command_queue( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(retain_command_queue((cl_command_queue)NULL));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL));
  }
  /** // doc: test__retain_command_queue__invalid_command_queue() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__retain_command_queue__invalid_command_queue( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__retain_command_queue__out_of_resources() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__retain_command_queue__out_of_resources( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_command_queue__out_of_host_memory() {{{
   * \brief Test retain_command_queue() in a situation when clRetainCommandQueue() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__retain_command_queue__out_of_host_memory( )
  {
    T::Dummy_clRetainCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_FUNCTIONS_RETAIN_COMMAND_QUEUE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
