// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/event.t.h

/** // doc: clxx/event.t.h {{{
 * \file clxx/event.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_EVENT_T_H_INCLUDED
#define CLXX_EVENT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/event.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class event_test_suite; }

/** // doc: class clxx::event_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::event_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event e;
    TS_ASSERT(!e.is_initialized());
    TS_ASSERT_EQUALS(e.get(), (cl_event)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event e((cl_event)0x1234);
    TS_ASSERT(e.is_initialized());
    TS_ASSERT_EQUALS(e.get(), (cl_event)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_event)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1__null_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1__null_id( )
  {
    T::Dummy_clRetainEvent mock1(CL_INVALID_EVENT);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(event((cl_event)NULL));
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2( )
  {
    T::Dummy_clCreateUserEvent mock1((cl_event)0x1234, CL_SUCCESS);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);

    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);


    context c((cl_context)0x3456);
    event e(c);

    TS_ASSERT(e.is_initialized());
    TS_ASSERT_EQUALS(e.get(), (cl_event)0x1234);
    TS_ASSERT(mock2.never_called());
    TS_ASSERT(mock3.never_called());
  }
  /** // doc: test__copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__copy_ctor( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event k1((cl_event)0x1234);
    event k2(k1);
    TS_ASSERT(k2.is_initialized());
    TS_ASSERT(mock1.called_twice());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(k2, event((cl_event)0x1234));
  }
  /** // doc: test__dtor__notnull() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__notnull( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    {
      event e((cl_event)0x1234);
    }
    TS_ASSERT(mock2.called_once_with((cl_event)0x1234));
  }
  /** // doc: test__dtor__null() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__null( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    {
      event e((cl_event)NULL);
    }
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__id() {{{
   * \todo Write documentation
   */ // }}}
  void test__id( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(event((cl_event)0x1234).get(), (cl_event)0x1234);
    TS_ASSERT_EQUALS(event((cl_event)NULL).get(), (cl_event)NULL);
  }
  /** // doc: test__chk_get() {{{
   * \todo Write documentation
   */ // }}}
  void test__chk_get( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(event((cl_event)0x1234).chk_get(), (cl_event)0x1234);
    TS_ASSERT_THROWS(event((cl_event)NULL).chk_get(), uninitialized_event_error);
  }
  /** // doc: test__assign__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__1( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event c1((cl_event)0x1234);
    event c2((cl_event)0x5678);
    TS_ASSERT(c1 != c2);
    c2.assign(c1);
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_event)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_event)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__2( )
  {
    event c1;
    event c2;
    {
      T::Dummy_clRetainEvent mock_clRetainEvent(CL_SUCCESS);
      T::Dummy_clReleaseEvent mock_clReleaseEvent(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainEvent.never_called());
      TS_ASSERT(mock_clReleaseEvent.never_called());
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__3( )
  {
    T::Dummy_clRetainEvent mock_clRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock_clReleaseEvent(CL_SUCCESS);
    event c1;
    event c2((cl_event)0x1234);
    {
      T::Dummy_clRetainEvent mock_clRetainEvent2(CL_SUCCESS);
      T::Dummy_clReleaseEvent mock_clReleaseEvent2(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainEvent2.never_called());
      TS_ASSERT(mock_clReleaseEvent2.called_once_with((cl_event)0x1234));
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_assign( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event p1((cl_event)0x1234);
    event p2((cl_event)0x5678);
    p1 = p2;
    TS_ASSERT_EQUALS(p1.get(), (cl_event)0x5678);
  }
  /** // doc: test__op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_eq( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT( (event((cl_event)0x1234) == event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) == event((cl_event)0x5678)));
    TS_ASSERT(!(event((cl_event)0x5678) == event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) == event((cl_event)NULL)));
    TS_ASSERT(!(event((cl_event)NULL)   == event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)NULL)   == event((cl_event)NULL)));
  }
  /** // doc: test__op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_neq( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT(!(event((cl_event)0x1234) != event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) != event((cl_event)0x5678)));
    TS_ASSERT( (event((cl_event)0x5678) != event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) != event((cl_event)NULL)));
    TS_ASSERT( (event((cl_event)NULL)   != event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)NULL)   != event((cl_event)NULL)));
  }
  /** // doc: test__op_lt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_lt( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT(!(event((cl_event)0x1234) < event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) < event((cl_event)0x5678)));
    TS_ASSERT(!(event((cl_event)0x5678) < event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) < event((cl_event)NULL)));
    TS_ASSERT( (event((cl_event)NULL)   < event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)NULL)   < event((cl_event)NULL)));
  }
  /** // doc: test__op_gt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_gt( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT(!(event((cl_event)0x1234) > event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) > event((cl_event)0x5678)));
    TS_ASSERT( (event((cl_event)0x5678) > event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) > event((cl_event)NULL)));
    TS_ASSERT(!(event((cl_event)NULL)   > event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)NULL)   > event((cl_event)NULL)));
  }
  /** // doc: test__op_le() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_le( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT( (event((cl_event)0x1234) <= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) <= event((cl_event)0x5678)));
    TS_ASSERT(!(event((cl_event)0x5678) <= event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) <= event((cl_event)NULL)));
    TS_ASSERT( (event((cl_event)NULL)   <= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)NULL)   <= event((cl_event)NULL)));
  }
  /** // doc: test__op_ge() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_ge( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT( (event((cl_event)0x1234) >= event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) >= event((cl_event)0x5678)));
    TS_ASSERT( (event((cl_event)0x5678) >= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) >= event((cl_event)NULL)));
    TS_ASSERT(!(event((cl_event)NULL)   >= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)NULL)   >= event((cl_event)NULL)));
  }
  /** // doc: test__get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventInfo mock3(CL_SUCCESS);

    event e((cl_event)0x4321);
    e.get_info(event_info_t::context, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_event)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_CONTEXT);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_info__uninitialized_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info__uninitialized_event( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventInfo mock3(CL_SUCCESS);

    event e((cl_event)NULL);
    TS_ASSERT_THROWS(e.get_info(event_info_t::context, 0, nullptr, nullptr), uninitialized_event_error);
  }
  /** // doc: test__get_profiling_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_info( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS);

    event e((cl_event)0x4321);
    e.get_profiling_info(profiling_info_t::start, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_event)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROFILING_COMMAND_START);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_profiling_info__uninitialized_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_info__uninitialized_event( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS);

    event e((cl_event)NULL);
    TS_ASSERT_THROWS(e.get_profiling_info(profiling_info_t::start, 0, nullptr, nullptr), uninitialized_event_error);
  }
  /** // doc: test__get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_reference_count( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_uint var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetEventInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);
    TS_ASSERT_EQUALS(e.get_reference_count(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_REFERENCE_COUNT);
  }
  /** // doc: test__get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_context( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_context var = (cl_context)12;
    size_t n = sizeof(var);

    T::Dummy_clGetEventInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(e.get_context().get(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_CONTEXT);
  }
  /** // doc: test__get_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_command_queue( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_command_queue var = (cl_command_queue)12;
    size_t n = sizeof(var);

    T::Dummy_clGetEventInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(e.get_command_queue().get(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_COMMAND_QUEUE);
  }
  /** // doc: test__get_command_type() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_command_type( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_command_type var = (cl_command_type)CL_COMMAND_READ_BUFFER;
    size_t n = sizeof(var);

    T::Dummy_clGetEventInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(static_cast<cl_command_type>(e.get_command_type()), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_COMMAND_TYPE);
  }
  /** // doc: test__get_command_exec_status() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_command_exec_status( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_int var = (cl_int)CL_COMMAND_READ_BUFFER;
    size_t n = sizeof(var);

    T::Dummy_clGetEventInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(static_cast<cl_int>(e.get_command_exec_status()), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_COMMAND_EXECUTION_STATUS);
  }
  /** // doc: test__get_profiling_command_queued() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_queued( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_ulong var = 123ul;
    size_t n = sizeof(var);

    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_queued(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_QUEUED);
  }
  /** // doc: test__get_profiling_command_submit() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_submit( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_ulong var = 123ul;
    size_t n = sizeof(var);

    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_submit(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_SUBMIT);
  }
  /** // doc: test__get_profiling_command_start() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_start( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_ulong var = 123ul;
    size_t n = sizeof(var);

    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_start(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_START);
  }
  /** // doc: test__get_profiling_command_end() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_end( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_ulong var = 123ul;
    size_t n = sizeof(var);

    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_end(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_END);
  }
  /** // doc: test__get_profiling_command_complete() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_complete( )
  {
#if CLXX_CL_H_VERSION_2_0
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    cl_ulong var = 123ul;
    size_t n = sizeof(var);

    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS, &var, &n);

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_complete(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_COMPLETE);
#endif
  }
};

#endif /* CLXX_EVENT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
