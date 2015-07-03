// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/mem_fcn.t.h

/** // doc: clxx/mem_fcn.t.h {{{
 * \file clxx/mem_fcn.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_MEM_FCN_T_H_INCLUDED
#define CLXX_MEM_FCN_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/mem_fcn.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class mem_fcn_test_suite; }

/** // doc: class clxx::mem_fcn_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::mem_fcn_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__enqueue_read_buffer_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_read_buffer_1( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueReadBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;
    event e;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_read_buffer(q,m,true,123,456,(void*)0x7890,ews,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_read_buffer_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_read_buffer_2( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueReadBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    event e;

    TS_ASSERT_THROWS_NOTHING(enqueue_read_buffer(q,m,true,123,456,(void*)0x7890,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_read_buffer_3() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_read_buffer_3( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueReadBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_read_buffer(q,m,true,123,456,(void*)0x7890,ews));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_read_buffer_4() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_read_buffer_4( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueReadBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);

    TS_ASSERT_THROWS_NOTHING(enqueue_read_buffer(q,m,true,123,456,(void*)0x7890));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_write_buffer_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_1( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueWriteBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;
    event e;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_write_buffer(q,m,true,123,456,(const void*)0x7890,ews,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (const void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_write_buffer_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_2( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueWriteBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    event e;

    TS_ASSERT_THROWS_NOTHING(enqueue_write_buffer(q,m,true,123,456,(const void*)0x7890,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (const void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_write_buffer_3() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_3( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueWriteBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_write_buffer(q,m,true,123,456,(const void*)0x7890,ews));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (const void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_write_buffer_4() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_write_buffer_4( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueWriteBuffer    mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);

    TS_ASSERT_THROWS_NOTHING(enqueue_write_buffer(q,m,true,123,456,(const void*)0x7890));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), (const void*)0x7890);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_copy_buffer_1() {{{
   * \todo Copy documentation
   */ // }}}
  void test__enqueue_copy_buffer_1( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueCopyBuffer   mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem sm((cl_mem)0x9012);
    mem dm((cl_mem)0x2109);
    events ews;
    event e;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_copy_buffer(q,sm,dm,123,456,789,ews,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT(std::get<2>(mock1.calls().back()) == (cl_mem)0x2109);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 789);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_copy_buffer_2() {{{
   * \todo Copy documentation
   */ // }}}
  void test__enqueue_copy_buffer_2( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueCopyBuffer   mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem sm((cl_mem)0x9012);
    mem dm((cl_mem)0x2109);
    event e;

    TS_ASSERT_THROWS_NOTHING(enqueue_copy_buffer(q,sm,dm,123,456,789,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT(std::get<2>(mock1.calls().back()) == (cl_mem)0x2109);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 789);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_copy_buffer_3() {{{
   * \todo Copy documentation
   */ // }}}
  void test__enqueue_copy_buffer_3( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueCopyBuffer   mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem sm((cl_mem)0x9012);
    mem dm((cl_mem)0x2109);
    events ews;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_copy_buffer(q,sm,dm,123,456,789,ews));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT(std::get<2>(mock1.calls().back()) == (cl_mem)0x2109);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 789);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_copy_buffer_4() {{{
   * \todo Copy documentation
   */ // }}}
  void test__enqueue_copy_buffer_4( )
  {
    cl_event res = (cl_event)0x1234;
    T::Dummy_clEnqueueCopyBuffer   mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem sm((cl_mem)0x9012);
    mem dm((cl_mem)0x2109);

    TS_ASSERT_THROWS_NOTHING(enqueue_copy_buffer(q,sm,dm,123,456,789));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT(std::get<2>(mock1.calls().back()) == (cl_mem)0x2109);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 789);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_map_buffer_1() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_map_buffer_1( )
  {
    void* res = (void*)0x1234;
    cl_event var = (cl_event)0x4321;
    T::Dummy_clEnqueueMapBuffer     mock1(res, CL_SUCCESS, &var);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;
    event e;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT(enqueue_map_buffer(q,m,true,map_flags_t::read,123,456,ews,e) == res);
    TS_ASSERT(e.get() == var);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), (cl_map_flags)CL_MAP_READ);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_map_buffer_2() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_map_buffer_2( )
  {
    void* res = (void*)0x1234;
    cl_event var = (cl_event)0x4321;
    T::Dummy_clEnqueueMapBuffer     mock1(res, CL_SUCCESS, &var);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    event e;

    TS_ASSERT(enqueue_map_buffer(q,m,true,map_flags_t::read,123,456,e) == res);
    TS_ASSERT(e.get() == var);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), (cl_map_flags)CL_MAP_READ);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_map_buffer_3() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_map_buffer_3( )
  {
    void* res = (void*)0x1234;
    cl_event var = (cl_event)0x4321;
    T::Dummy_clEnqueueMapBuffer     mock1(res, CL_SUCCESS, &var);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT(enqueue_map_buffer(q,m,true,map_flags_t::read,123,456,ews) == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), (cl_map_flags)CL_MAP_READ);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_map_buffer_4() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_map_buffer_4( )
  {
    void* res = (void*)0x1234;
    cl_event var = (cl_event)0x4321;
    T::Dummy_clEnqueueMapBuffer     mock1(res, CL_SUCCESS, &var);
    T::Dummy_clRetainCommandQueue   mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue  mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject      mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject     mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent          mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent         mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);

    TS_ASSERT(enqueue_map_buffer(q,m,true,map_flags_t::read,123,456) == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), true);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), (cl_map_flags)CL_MAP_READ);
    TS_ASSERT_EQUALS(std::get<4>(mock1.calls().back()), 123);
    TS_ASSERT_EQUALS(std::get<5>(mock1.calls().back()), 456);
    TS_ASSERT_EQUALS(std::get<6>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_unmap_mem_object_1() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_unmap_mem_object_1( )
  {
    cl_event res = (cl_event)0x4321;
    T::Dummy_clEnqueueUnmapMemObject  mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue     mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue    mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject        mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject       mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent            mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent           mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;
    event e;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_unmap_mem_object(q,m,(void*)0x8901,ews,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), (void*)0x8901);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<4>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<5>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_unmap_mem_object_2() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_unmap_mem_object_2( )
  {
    cl_event res = (cl_event)0x4321;
    T::Dummy_clEnqueueUnmapMemObject  mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue     mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue    mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject        mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject       mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent            mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent           mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    event e;

    TS_ASSERT_THROWS_NOTHING(enqueue_unmap_mem_object(q,m,(void*)0x8901,e));
    TS_ASSERT(e.get() == res);

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), (void*)0x8901);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<4>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<5>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_unmap_mem_object_3() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_unmap_mem_object_3( )
  {
    cl_event res = (cl_event)0x4321;
    T::Dummy_clEnqueueUnmapMemObject  mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue     mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue    mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject        mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject       mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent            mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent           mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);
    events ews;

    ews.push_back(event((cl_event)0x3456));
    ews.push_back(event((cl_event)0x4567));

    TS_ASSERT_THROWS_NOTHING(enqueue_unmap_mem_object(q,m,(void*)0x8901,ews));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), (void*)0x8901);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 2);
    TS_ASSERT(std::get<4>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<5>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_unmap_mem_object_4() {{{
   * \todo Map documentation
   */ // }}}
  void test__enqueue_unmap_mem_object_4( )
  {
    cl_event res = (cl_event)0x4321;
    T::Dummy_clEnqueueUnmapMemObject  mock1(CL_SUCCESS, &res);
    T::Dummy_clRetainCommandQueue     mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue    mock3(CL_SUCCESS);
    T::Dummy_clRetainMemObject        mock4(CL_SUCCESS);
    T::Dummy_clReleaseMemObject       mock5(CL_SUCCESS);
    T::Dummy_clRetainEvent            mock6(CL_SUCCESS);
    T::Dummy_clReleaseEvent           mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x5678);
    mem m((cl_mem)0x9012);

    TS_ASSERT_THROWS_NOTHING(enqueue_unmap_mem_object(q,m,(void*)0x8901));

    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_command_queue)0x5678);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem)0x9012);
    TS_ASSERT_EQUALS(std::get<2>(mock1.calls().back()), (void*)0x8901);
    TS_ASSERT_EQUALS(std::get<3>(mock1.calls().back()), 0);
    TS_ASSERT(std::get<4>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<5>(mock1.calls().back()) == nullptr);
  }
};

#endif /* CLXX_MEM_FCN_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
