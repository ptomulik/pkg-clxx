// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/events.t.h

/** // doc: clxx/events.t.h {{{
 * \file clxx/events.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_EVENTS_T_H_INCLUDED
#define CLXX_EVENTS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/events.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class events_test_suite; }

/** // doc: class clxx::events_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::events_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__wait_for_events__1() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__1( )
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_SUCCESS);

    events e;

    TS_ASSERT_THROWS_NOTHING(wait_for_events(e));
    TS_ASSERT(mockRetainEvent.never_called());
    TS_ASSERT(mockReleaseEvent.never_called());
    TS_ASSERT(mockWaitForEvents.never_called());
  }

  /** // doc: test__wait_for_events__1() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__2( )
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_SUCCESS);

    events e = { event((cl_event)0x1234), event((cl_event)0x5678) };

    TS_ASSERT_THROWS_NOTHING(wait_for_events(e));
    TS_ASSERT(mockWaitForEvents.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mockWaitForEvents.calls().front()), 2);
    TS_ASSERT(std::get<1>(mockWaitForEvents.calls().front()) == reinterpret_cast<cl_event const*>(e.data()));
  }

  /** // doc: test__wait_for_events__invalid_value() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__invalid_value()
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_INVALID_VALUE);

    events e = { event((cl_event)0x1234), event((cl_event)0x5678) };

    TS_ASSERT_THROWS(wait_for_events(e), clerror_no<status_t::invalid_value>);
  }

  /** // doc: test__wait_for_events__invalid_context() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__invalid_context()
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_INVALID_CONTEXT);

    events e = { event((cl_event)0x1234), event((cl_event)0x5678) };

    TS_ASSERT_THROWS(wait_for_events(e), clerror_no<status_t::invalid_context>);
  }

  /** // doc: test__wait_for_events__invalid_event() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__invalid_event()
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_INVALID_EVENT);

    events e = { event((cl_event)0x1234), event((cl_event)0x5678) };

    TS_ASSERT_THROWS(wait_for_events(e), clerror_no<status_t::invalid_event>);
  }

  /** // doc: test__wait_for_events__exec_status_error_for_events_in_wait_list() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__exec_status_error_for_events_in_wait_list()
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);

    events e = { event((cl_event)0x1234), event((cl_event)0x5678) };

    TS_ASSERT_THROWS(wait_for_events(e), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
  }

  /** // doc: test__wait_for_events__out_of_resources() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__out_of_resources()
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_OUT_OF_RESOURCES);

    events e = { event((cl_event)0x1234), event((cl_event)0x5678) };

    TS_ASSERT_THROWS(wait_for_events(e), clerror_no<status_t::out_of_resources>);
  }
  
  /** // doc: test__wait_for_events__out_of_host_memory() {{{
   * \brief Test wait_for_events(clxx::events const&)
   */ // }}}
  void test__wait_for_events__out_of_host_memory()
  {
    T::Dummy_clRetainEvent mockRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mockReleaseEvent(CL_SUCCESS);
    T::Dummy_clWaitForEvents mockWaitForEvents(CL_OUT_OF_HOST_MEMORY);

    events e = { event((cl_event)0x1234), event((cl_event)0x5678) };

    TS_ASSERT_THROWS(wait_for_events(e), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_EVENTS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
