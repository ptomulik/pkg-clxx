// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/wait_for_events.t.h

/** // doc: clxx/functions/wait_for_events.t.h {{{
 * \file clxx/functions/wait_for_events.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_WAIT_FOR_EVENTS_T_H_INCLUDED
#define CLXX_FUNCTIONS_WAIT_FOR_EVENTS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_wait_for_events_test_suite; }

/** // doc: class clxx::functions_wait_for_events_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_wait_for_events_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  wait_for_events()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__wait_for_events() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events( )
  {
    T::Dummy_clWaitForEvents mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(wait_for_events(0x123, (cl_event const*)0x7654));
    TS_ASSERT(mock.called_once_with(0x123, (cl_event const*)0x7654));
  }
  /** // doc: test__wait_for_events__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__invalid_value( )
  {
    T::Dummy_clWaitForEvents mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__wait_for_events__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__invalid_context( )
  {
    T::Dummy_clWaitForEvents mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__wait_for_events__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__invalid_event( )
  {
    T::Dummy_clWaitForEvents mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::invalid_event>);
  }
  /** // doc: test__wait_for_events__exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__exec_status_error_for_events_in_wait_list( )
  {
    T::Dummy_clWaitForEvents mock(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
  }
  /** // doc: test__wait_for_events__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__out_of_resources( )
  {
    T::Dummy_clWaitForEvents mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__wait_for_events__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__out_of_host_memory( )
  {
    T::Dummy_clWaitForEvents mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__wait_for_events__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__wait_for_events__unexpected_clerror( )
  {
    T::Dummy_clWaitForEvents mock(-0x1234567);
    TS_ASSERT_THROWS(wait_for_events(0x123, (cl_event const*)0x7654), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_WAIT_FOR_EVENTS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
