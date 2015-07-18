// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/finish.t.h

/** // doc: clxx/cl/functions/finish.t.h {{{
 * \file clxx/cl/functions/finish.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_FLUSH_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_FLUSH_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_finish_test_suite; }

/** // doc: class clxx::functions_finish_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_finish_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  finish()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__finish() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish( )
  {
    T::Dummy_clFinish mock(CL_SUCCESS);
    finish                          ((cl_command_queue)0x344);
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x344));
  }
  /** // doc: test__finish__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__invalid_command_queue( )
  {
    T::Dummy_clFinish mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL),clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__finish__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__out_of_resources( )
  {
    T::Dummy_clFinish mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__finish__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__out_of_host_memory( )
  {
    T::Dummy_clFinish mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__finish__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__unexpected_clerror( )
  {
    T::Dummy_clFinish mock(-0x1234567);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_FLUSH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
