// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/release_event.t.h

/** // doc: clxx/functions/release_event.t.h {{{
 * \file clxx/functions/release_event.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_RELEASE_EVENT_T_H_INCLUDED
#define CLXX_FUNCTIONS_RELEASE_EVENT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_release_event_test_suite; }

/** // doc: class clxx::functions_release_event_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_release_event_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_event()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_event( )
  {
    T::Dummy_clReleaseEvent mock(CL_SUCCESS);
    release_event                  ((cl_event)0x433);
    TS_ASSERT(mock.called_once_with((cl_event)0x433));
  }
  /** // doc: test__release_event__invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_event__invalid_event( )
  {
    T::Dummy_clReleaseEvent mock(CL_INVALID_EVENT);
    TS_ASSERT_THROWS(release_event((cl_event)NULL),clerror_no<status_t::invalid_event>);
  }
  /** // doc: test__release_event__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_event__out_of_resources( )
  {
    T::Dummy_clReleaseEvent mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_event((cl_event)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_event__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_event__out_of_host_memory( )
  {
    T::Dummy_clReleaseEvent mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_event((cl_event)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_event__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_event__unexpected_clerror( )
  {
    T::Dummy_clReleaseEvent mock(-0x1234567);
    TS_ASSERT_THROWS(release_event((cl_event)NULL), unexpected_clerror);
  }

};

#endif /* CLXX_FUNCTIONS_RELEASE_EVENT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
