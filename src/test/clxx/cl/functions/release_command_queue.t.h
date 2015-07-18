// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/release_command_queue.t.h

/** // doc: clxx/cl/functions/release_command_queue.t.h {{{
 * \file clxx/cl/functions/release_command_queue.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_RELEASE_COMMAND_QUEUE_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_RELEASE_COMMAND_QUEUE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_release_command_queue_test_suite; }

/** // doc: class clxx::functions_release_command_queue_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_release_command_queue_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_command_queue()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_command_queue() {{{
   * \brief Test release_command_queue() in a normal situation
   */ // }}}
  void test__release_command_queue( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_command_queue((cl_command_queue)NULL));
    TS_ASSERT(mock.called_once_with((cl_command_queue)NULL));
  }
  /** // doc: test__release_command_queue__invalid_command_queue() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_INVALID_CONTEXT
   */ // }}}
  void test__release_command_queue__invalid_command_queue( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__release_command_queue__out_of_resources() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_command_queue__out_of_resources( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_command_queue__out_of_host_memory() {{{
   * \brief Test release_command_queue() in a situation when clReleaseCommandQueue() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_command_queue__out_of_host_memory( )
  {
    T::Dummy_clReleaseCommandQueue mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_command_queue((cl_command_queue)NULL), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_CL_FUNCTIONS_RELEASE_COMMAND_QUEUE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
