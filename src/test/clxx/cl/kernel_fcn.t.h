// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/kernel_fcn.t.h

/** // doc: clxx/cl/kernel_fcn.t.h {{{
 * \file clxx/cl/kernel_fcn.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_KERNEL_FCN_T_H_INCLUDED
#define CLXX_CL_KERNEL_FCN_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/kernel_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/command_queue.hpp>
#include <clxx/cl/kernel.hpp>
#include <clxx/cl/mock.hpp>
#include <clxx/common/ndrange.hpp>

namespace clxx { class kernel_fcn_test_suite; }

/** // doc: class clxx::kernel_fcn_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::kernel_fcn_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__enqueue_ndrange_kernel_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel_1( )
  {
    cl_event var = (cl_event)0x1234;

    T::Dummy_clEnqueueNDRangeKernel mock1(CL_SUCCESS, &var);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    T::Dummy_clRetainKernel mock6(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x2345);
    kernel k((cl_kernel)0x3456);
    ndrange r{3,{1,2,3},{4,5,6},{7,8,9}};
    events ews{event((cl_event)0x765), event((cl_event)0x876)};
    event e;

    TS_ASSERT_THROWS_NOTHING(enqueue_ndrange_kernel(q,k,r,ews,&e));
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == q.get());
    TS_ASSERT(std::get<1>(mock1.calls().back()) == k.get());
    TS_ASSERT(std::get<2>(mock1.calls().back()) == r.dimension());
    TS_ASSERT(std::get<3>(mock1.calls().back()) == r.global_offset_ptr());
    TS_ASSERT(std::get<4>(mock1.calls().back()) == r.global_size_ptr());
    TS_ASSERT(std::get<5>(mock1.calls().back()) == r.local_size_ptr());
    TS_ASSERT(std::get<6>(mock1.calls().back()) == ews.size());
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_ndrange_kernel_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel_2( )
  {
    cl_event var = (cl_event)0x1234;

    T::Dummy_clEnqueueNDRangeKernel mock1(CL_SUCCESS, &var);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    T::Dummy_clRetainKernel mock6(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x2345);
    kernel k((cl_kernel)0x3456);
    ndrange r{3,{1,2,3},{4,5,6},{7,8,9}};
    event e;

    TS_ASSERT_THROWS_NOTHING(enqueue_ndrange_kernel(q,k,r,&e));
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == q.get());
    TS_ASSERT(std::get<1>(mock1.calls().back()) == k.get());
    TS_ASSERT(std::get<2>(mock1.calls().back()) == r.dimension());
    TS_ASSERT(std::get<3>(mock1.calls().back()) == r.global_offset_ptr());
    TS_ASSERT(std::get<4>(mock1.calls().back()) == r.global_size_ptr());
    TS_ASSERT(std::get<5>(mock1.calls().back()) == r.local_size_ptr());
    TS_ASSERT(std::get<6>(mock1.calls().back()) == 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
  /** // doc: test__enqueue_ndrange_kernel_3() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel_3( )
  {
    cl_event var = (cl_event)0x1234;

    T::Dummy_clEnqueueNDRangeKernel mock1(CL_SUCCESS, &var);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    T::Dummy_clRetainKernel mock6(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x2345);
    kernel k((cl_kernel)0x3456);
    ndrange r{3,{1,2,3},{4,5,6},{7,8,9}};
    events ews{event((cl_event)0x765), event((cl_event)0x876)};

    TS_ASSERT_THROWS_NOTHING(enqueue_ndrange_kernel(q,k,r,ews));
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == q.get());
    TS_ASSERT(std::get<1>(mock1.calls().back()) == k.get());
    TS_ASSERT(std::get<2>(mock1.calls().back()) == r.dimension());
    TS_ASSERT(std::get<3>(mock1.calls().back()) == r.global_offset_ptr());
    TS_ASSERT(std::get<4>(mock1.calls().back()) == r.global_size_ptr());
    TS_ASSERT(std::get<5>(mock1.calls().back()) == r.local_size_ptr());
    TS_ASSERT(std::get<6>(mock1.calls().back()) == ews.size());
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_ndrange_kernel_4() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel_4( )
  {
    cl_event var = (cl_event)0x1234;

    T::Dummy_clEnqueueNDRangeKernel mock1(CL_SUCCESS, &var);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    T::Dummy_clRetainKernel mock6(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x2345);
    kernel k((cl_kernel)0x3456);
    ndrange r{3,{1,2,3},{4,5,6},{7,8,9}};

    TS_ASSERT_THROWS_NOTHING(enqueue_ndrange_kernel(q,k,r));
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == q.get());
    TS_ASSERT(std::get<1>(mock1.calls().back()) == k.get());
    TS_ASSERT(std::get<2>(mock1.calls().back()) == r.dimension());
    TS_ASSERT(std::get<3>(mock1.calls().back()) == r.global_offset_ptr());
    TS_ASSERT(std::get<4>(mock1.calls().back()) == r.global_size_ptr());
    TS_ASSERT(std::get<5>(mock1.calls().back()) == r.local_size_ptr());
    TS_ASSERT(std::get<6>(mock1.calls().back()) == 0);
    TS_ASSERT(std::get<7>(mock1.calls().back()) == nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) == nullptr);
  }
  /** // doc: test__enqueue_ndrange_kernel_5() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_ndrange_kernel_5( )
  {
    cl_event var = (cl_event)0x1234;

    T::Dummy_clEnqueueNDRangeKernel mock1(CL_SUCCESS, &var);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    T::Dummy_clRetainKernel mock6(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock7(CL_SUCCESS);

    command_queue q((cl_command_queue)0x2345);
    kernel k((cl_kernel)0x3456);
    ndrange r{3,{1,2,3},{4,5,6},{7,8,9}};
    event ews[2] = { event((cl_event)0x765), event((cl_event)0x876) };
    event e;

    TS_ASSERT_THROWS_NOTHING(enqueue_ndrange_kernel(q,k,r,2,ews,&e));
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == q.get());
    TS_ASSERT(std::get<1>(mock1.calls().back()) == k.get());
    TS_ASSERT(std::get<2>(mock1.calls().back()) == r.dimension());
    TS_ASSERT(std::get<3>(mock1.calls().back()) == r.global_offset_ptr());
    TS_ASSERT(std::get<4>(mock1.calls().back()) == r.global_size_ptr());
    TS_ASSERT(std::get<5>(mock1.calls().back()) == r.local_size_ptr());
    TS_ASSERT(std::get<6>(mock1.calls().back()) == 2);
    TS_ASSERT(std::get<7>(mock1.calls().back()) != nullptr);
    TS_ASSERT(std::get<8>(mock1.calls().back()) != nullptr);
  }
};

#endif /* CLXX_CL_KERNEL_FCN_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
