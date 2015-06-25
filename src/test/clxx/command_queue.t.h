// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/command_queue.t.h

/** // doc: clxx/command_queue.t.h {{{
 * \file clxx/command_queue.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMAND_QUEUE_T_H_INCLUDED
#define CLXX_COMMAND_QUEUE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/command_queue.hpp>
#include <clxx/context.hpp>
#include <clxx/device.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class command_queue_test__suite; }

/** // doc: class clxx::command_queue_test__suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::command_queue_test__suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue q;
    TS_ASSERT(!q.is_initialized());
    TS_ASSERT_EQUALS(q.id(), (cl_command_queue)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c((cl_command_queue)0x1234);
    TS_ASSERT(c.is_initialized());
    TS_ASSERT(mock1.called_once_with((cl_command_queue)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock1((cl_command_queue)0, CL_SUCCESS);
#elif CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock1((cl_command_queue)0, CL_SUCCESS);
#endif
    T::Dummy_clRetainCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock3(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    command_queue c(context((cl_context)0x1234), device((cl_device_id)0x5678), command_queue_properties_t::none);
    TS_ASSERT(!c.is_initialized());
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT(mock3.never_called());
  }
  /** // doc: test__ctor_2__uninitialized_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2__uninitialized_context( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock1((cl_command_queue)0, CL_SUCCESS);
#elif CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock1((cl_command_queue)0, CL_SUCCESS);
#endif
    T::Dummy_clRetainCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock3(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    TS_ASSERT_THROWS(command_queue(context((cl_context)NULL), device((cl_device_id)0x5678), command_queue_properties_t::none), uninitialized_context_error);
  }
  /** // doc: test__ctor_2__uninitialized_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2__uninitialized_device( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock1((cl_command_queue)0, CL_SUCCESS);
#elif CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock1((cl_command_queue)0, CL_SUCCESS);
#endif
    T::Dummy_clRetainCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock3(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    TS_ASSERT_THROWS(command_queue(context((cl_context)0x1234), device((cl_device_id)NULL), command_queue_properties_t::none), uninitialized_device_error);
  }
  /** // doc: test__copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__copy_ctor( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
    T::Dummy_clCreateCommandQueue mock1((cl_command_queue)0x123, CL_SUCCESS);
#elif CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
    T::Dummy_clCreateCommandQueueWithProperties mock1((cl_command_queue)0x123, CL_SUCCESS);
#endif
    T::Dummy_clRetainCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock3(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    command_queue c1(context((cl_context)0x8765), device((cl_device_id)0x4321), command_queue_properties_t::none);
    command_queue c2(c1);
    TS_ASSERT(c2.is_initialized());
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(mock2.called_once());
    TS_ASSERT(mock3.never_called());
    TS_ASSERT_EQUALS(c2, command_queue((cl_command_queue)0x123));
  }
  /** // doc: test__dtor() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    {
      command_queue c((cl_command_queue)0x1234);
      TS_ASSERT(mock1.called_once_with((cl_command_queue)0x1234));
      TS_ASSERT(mock2.never_called());
    }
    TS_ASSERT(mock2.called_once_with((cl_command_queue)0x1234));
  }
  /** // doc: test__op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_assign( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c1((cl_command_queue)0x1234);
    command_queue c2((cl_command_queue)0x5678);
    TS_ASSERT(c1 != c2);
    c2 = c1;
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_command_queue)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_command_queue)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_eq( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c1((cl_command_queue)0x1234);
    command_queue c2((cl_command_queue)0x5678);
    command_queue c3((cl_command_queue)0x1234);
    TS_ASSERT(c1 == c1);
    TS_ASSERT(!(c1 == c2));
    TS_ASSERT(!(c2 == c1));
    TS_ASSERT(!(c2 == c3));
    TS_ASSERT(!(c3 == c2));
    TS_ASSERT(c1 == c3);
    TS_ASSERT(c3 == c1);
  }
  /** // doc: test__op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_neq( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c1((cl_command_queue)0x1234);
    command_queue c2((cl_command_queue)0x5678);
    command_queue c3((cl_command_queue)0x1234);
    TS_ASSERT(!(c1 != c1));
    TS_ASSERT((c1 != c2));
    TS_ASSERT((c2 != c1));
    TS_ASSERT((c2 != c3));
    TS_ASSERT((c3 != c2));
    TS_ASSERT(!(c1 != c3));
    TS_ASSERT(!(c3 != c1));
  }
  /** // doc: test__assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c1((cl_command_queue)0x1234);
    command_queue c2((cl_command_queue)0x5678);
    TS_ASSERT(c1 != c2);
    c2.assign(c1);
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_command_queue)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_command_queue)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__uninitialized_command_queue_error() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__uninitialized_command_queue_error( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c1((cl_command_queue)NULL);
    command_queue c2((cl_command_queue)0x5678);
    TS_ASSERT_THROWS(c2.assign(c1), uninitialized_command_queue_error);
  }
  /** // doc: test__is_initialized() {{{
   * \todo Write documentation
   */ // }}}
  void test__is_initialized( )
  {
    TS_ASSERT(true); // we've actually tested it with constructors...
  }
  /** // doc: test__get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mock3(CL_SUCCESS);
    command_queue c((cl_command_queue)0x1234);
    char value;
    size_t value_size_ret;

    c.get_info(command_queue_info_t::context, 1, (void*)&value, &value_size_ret);

    TS_ASSERT(mock3.called_once_with((cl_command_queue)0x1234, CL_QUEUE_CONTEXT, 1, (void*)&value, &value_size_ret));
  }
  /** // doc: test__get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_context( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mock3(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    command_queue c((cl_command_queue)0x1234);

    c.get_context();

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_command_queue)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_QUEUE_CONTEXT);
  }
  /** // doc: test__get_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_device( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mock3(CL_SUCCESS);
    command_queue c((cl_command_queue)0x1234);

    c.get_device();

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_command_queue)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_QUEUE_DEVICE);
  }
  /** // doc: test__get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_reference_count( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mock3(CL_SUCCESS);
    command_queue c((cl_command_queue)0x1234);

    c.get_reference_count();

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_command_queue)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_QUEUE_REFERENCE_COUNT);
  }
  /** // doc: test__get_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_properties( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mock3(CL_SUCCESS);
    command_queue c((cl_command_queue)0x1234);

    c.get_properties();

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_command_queue)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_QUEUE_PROPERTIES);
  }
  void test__flush( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clFlush mock3(CL_SUCCESS);

    command_queue q((cl_command_queue)0x1234);
    q.flush();

    TS_ASSERT(mock3.called_once_with((cl_command_queue)0x1234));
  }
  void test__finish( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    T::Dummy_clFinish mock3(CL_SUCCESS);

    command_queue q((cl_command_queue)0x1234);
    q.finish();

    TS_ASSERT(mock3.called_once_with((cl_command_queue)0x1234));
  }
};

#endif /* CLXX_COMMAND_QUEUE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
