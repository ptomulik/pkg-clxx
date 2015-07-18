// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/set_user_event_status.t.h

/** // doc: clxx/cl/functions/set_user_event_status.t.h {{{
 * \file clxx/cl/functions/set_user_event_status.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_SET_USER_EVENT_STATUS_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_SET_USER_EVENT_STATUS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_set_user_event_status_test_suite; }

/** // doc: class clxx::functions_set_user_event_status_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_set_user_event_status_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_user_event_status()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_user_event_status() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status( )
  {
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
    T::Dummy_clSetUserEventStatus mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_user_event_status((cl_event)0x123, CL_COMPLETE));
    TS_ASSERT(mock.called_once_with((cl_event)0x123, CL_COMPLETE));
#endif
  }
  /** // doc: test__set_user_event_status__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__invalid_event( )
  {
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
    T::Dummy_clSetUserEventStatus mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::invalid_event>);
#endif
  }
  /** // doc: test__set_user_event_status__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
    T::Dummy_clSetUserEventStatus mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::invalid_value>);
#endif
  }
  /** // doc: test__set_user_event_status__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
    T::Dummy_clSetUserEventStatus mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test__set_user_event_status__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
    T::Dummy_clSetUserEventStatus mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__set_user_event_status__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
    T::Dummy_clSetUserEventStatus mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__set_user_event_status__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_user_event_status__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
    T::Dummy_clSetUserEventStatus mock(-0x1234567);
    TS_ASSERT_THROWS(set_user_event_status((cl_event)0, CL_COMPLETE), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_SET_USER_EVENT_STATUS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
