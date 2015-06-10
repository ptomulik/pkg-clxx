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
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class command_queue_test_suite; }

/** // doc: class clxx::command_queue_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::command_queue_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c((cl_command_queue)0x1234);
    TS_ASSERT(c.is_initialized());
    TS_ASSERT(mock1.called_once_with((cl_command_queue)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2( )
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
  /** // doc: test_ctor_2__uninitialized_context() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2__uninitialized_context( )
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
  /** // doc: test_ctor_2__uninitialized_device() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2__uninitialized_device( )
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
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor( )
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
  /** // doc: test_dtor() {{{
   * \todo Write documentation
   */ // }}}
  void test_dtor( )
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
  /** // doc: test_op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_assign( )
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
  /** // doc: test_op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_eq( )
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
  /** // doc: test_op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_neq( )
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
  /** // doc: test_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test_assign( )
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
  /** // doc: test_assign__uninitialized_command_queue_error() {{{
   * \todo Write documentation
   */ // }}}
  void test_assign__uninitialized_command_queue_error( )
  {
    T::Dummy_clRetainCommandQueue mock1(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock2(CL_SUCCESS);
    command_queue c1((cl_command_queue)NULL);
    command_queue c2((cl_command_queue)0x5678);
    TS_ASSERT_THROWS(c2.assign(c1), uninitialized_command_queue_error);
  }
  /** // doc: test_is_initialized() {{{
   * \todo Write documentation
   */ // }}}
  void test_is_initialized( )
  {
    TS_ASSERT(true); // we've actually tested it with constructors...
  }
  /** // doc: test_get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_info( )
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
  /** // doc: test_get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_context( )
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
  /** // doc: test_get_device() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_device( )
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
  /** // doc: test_get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_reference_count( )
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
  /** // doc: test_get_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_properties( )
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
  void test_foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_COMMAND_QUEUE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
