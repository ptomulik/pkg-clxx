// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_user_event.t.h

/** // doc: clxx/cl/functions/create_user_event.t.h {{{
 * \file clxx/cl/functions/create_user_event.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_USER_EVENT_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_USER_EVENT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_user_event_test_suite; }

/** // doc: class clxx::functions_create_user_event_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_user_event_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_user_event()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_user_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_SUCCESS);
    TS_ASSERT(create_user_event((cl_context)0x7654) == (cl_event)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654);
#endif
  }
  /** // doc: test__create_user_event__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), clerror_no<status_t::invalid_context>);
#endif
  }
  /** // doc: test__create_user_event__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), clerror_no<status_t::out_of_resources>);
#endif
  }
  /** // doc: test__create_user_event__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), clerror_no<status_t::out_of_host_memory>);
#endif
  }
  /** // doc: test__create_user_event__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_user_event__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
    T::Dummy_clCreateUserEvent mock((cl_event)0x1234, -0x1234567);
    TS_ASSERT_THROWS(create_user_event((cl_context)0), unexpected_clerror);
#endif
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_USER_EVENT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
