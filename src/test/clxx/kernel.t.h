// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/kernel.t.h

/** // doc: clxx/kernel.t.h {{{
 * \file clxx/kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_KERNEL_T_H_INCLUDED
#define CLXX_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/kernel.hpp>
#include <clxx/device.hpp>
#include <clxx/context.hpp>
#include <clxx/program.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class kernel_test_suite; }

/** // doc: class clxx::kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::kernel_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel k;
    TS_ASSERT(!k.is_initialized());
    TS_ASSERT_EQUALS(k.id(), (cl_kernel)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel k((cl_kernel)0x1234);
    TS_ASSERT(k.is_initialized());
    TS_ASSERT_EQUALS(k.id(), (cl_kernel)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_kernel)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1__null_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1__null_id( )
  {
    T::Dummy_clRetainKernel mock1(CL_INVALID_KERNEL);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(kernel((cl_kernel)NULL));
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clCreateKernel mock3((cl_kernel)0x5678, CL_SUCCESS);
    T::Dummy_clRetainProgram mock4(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock5(CL_SUCCESS);

    program prog((cl_program)0x1234);
    kernel k(prog, "foo");

    TS_ASSERT(k.is_initialized());
    TS_ASSERT_EQUALS(k.id(), (cl_kernel)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateKernelWithSource()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__copy_ctor( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel k1((cl_kernel)0x1234);
    kernel k2(k1);
    TS_ASSERT(k2.is_initialized());
    TS_ASSERT(mock1.called_twice());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(k2, kernel((cl_kernel)0x1234));
  }
  /** // doc: test__dtor__notnull() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__notnull( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    {
      kernel k((cl_kernel)0x1234);
    }
    TS_ASSERT(mock2.called_once_with((cl_kernel)0x1234));
  }
  /** // doc: test__dtor__null() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__null( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    {
      kernel k((cl_kernel)NULL);
    }
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__id() {{{
   * \todo Write documentation
   */ // }}}
  void test__id( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(kernel((cl_kernel)0x1234).id(), (cl_kernel)0x1234);
    TS_ASSERT_EQUALS(kernel((cl_kernel)NULL).id(), (cl_kernel)NULL);
  }
  /** // doc: test__get_valid_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_valid_id( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(kernel((cl_kernel)0x1234).get_valid_id(), (cl_kernel)0x1234);
    TS_ASSERT_THROWS(kernel((cl_kernel)NULL).get_valid_id(), uninitialized_kernel_error);
  }
  /** // doc: test__op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_assign( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    kernel p1((cl_kernel)0x1234);
    kernel p2((cl_kernel)0x5678);
    p1 = p2;
    TS_ASSERT_EQUALS(p1.id(), (cl_kernel)0x5678);
  }
  /** // doc: test__op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_eq( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT( (kernel((cl_kernel)0x1234) == kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) == kernel((cl_kernel)0x5678)));
    TS_ASSERT(!(kernel((cl_kernel)0x5678) == kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) == kernel((cl_kernel)NULL)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   == kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   == kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_neq( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT(!(kernel((cl_kernel)0x1234) != kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) != kernel((cl_kernel)0x5678)));
    TS_ASSERT( (kernel((cl_kernel)0x5678) != kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) != kernel((cl_kernel)NULL)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   != kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   != kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_lt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_lt( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT(!(kernel((cl_kernel)0x1234) < kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) < kernel((cl_kernel)0x5678)));
    TS_ASSERT(!(kernel((cl_kernel)0x5678) < kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) < kernel((cl_kernel)NULL)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   < kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   < kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_gt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_gt( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT(!(kernel((cl_kernel)0x1234) > kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) > kernel((cl_kernel)0x5678)));
    TS_ASSERT( (kernel((cl_kernel)0x5678) > kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) > kernel((cl_kernel)NULL)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   > kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   > kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_le() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_le( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT( (kernel((cl_kernel)0x1234) <= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) <= kernel((cl_kernel)0x5678)));
    TS_ASSERT(!(kernel((cl_kernel)0x5678) <= kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) <= kernel((cl_kernel)NULL)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   <= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   <= kernel((cl_kernel)NULL)));
  }
  /** // doc: test__op_ge() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_ge( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    TS_ASSERT( (kernel((cl_kernel)0x1234) >= kernel((cl_kernel)0x1234)));
    TS_ASSERT(!(kernel((cl_kernel)0x1234) >= kernel((cl_kernel)0x5678)));
    TS_ASSERT( (kernel((cl_kernel)0x5678) >= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)0x1234) >= kernel((cl_kernel)NULL)));
    TS_ASSERT(!(kernel((cl_kernel)NULL)   >= kernel((cl_kernel)0x1234)));
    TS_ASSERT( (kernel((cl_kernel)NULL)   >= kernel((cl_kernel)NULL)));
  }
  /** // doc: test__get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);
    k.get_info(kernel_info_t::context, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_CONTEXT);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_info__uninitialized_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info__uninitialized_kernel( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)NULL);
    TS_ASSERT_THROWS(k.get_info(kernel_info_t::context, 0, nullptr, nullptr), uninitialized_kernel_error);
  }
  /** // doc: test__get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_reference_count( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_uint var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_reference_count(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_REFERENCE_COUNT);
  }
  /** // doc: test__get_function_name() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_function_name( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    char array[] = {"foo_function"};
    size_t n = sizeof(array);

    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS, array, &n);

    kernel k((cl_kernel)0x4321);
    std::string str = k.get_function_name();

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_FUNCTION_NAME);
    TS_ASSERT_EQUALS(str.size(), (n-1));
    TS_ASSERT_EQUALS(str, array);
  }
  /** // doc: test__get_num_args() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_num_args( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_uint var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_num_args(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_NUM_ARGS);
  }
  /** // doc: test__get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_context( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_context var = (cl_context)12;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(k.get_context().id(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_CONTEXT);
  }
  /** // doc: test__get_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_program var = (cl_program)12;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainProgram mock4(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(k.get_program().id(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_PROGRAM);
  }
  /** // doc: test__get_attributes() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_attributes( )
  {
#if CL_VERSION_1_2
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    char array[] = {"attr1 attr2"};
    size_t n = sizeof(array);

    T::Dummy_clGetKernelInfo mock3(CL_SUCCESS, array, &n);

    kernel k((cl_kernel)0x4321);
    std::string str = k.get_attributes();

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_KERNEL_ATTRIBUTES);
    TS_ASSERT_EQUALS(str.size(), (n-1));
    TS_ASSERT_EQUALS(str, array);
#endif
  }
  /** // doc: test__get_arg_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_info( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKenelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelArgInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);
    k.get_arg_info(0, kernel_arg_info_t::address_qualifier, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 0);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_ADDRESS_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (size_t*)0x5678);
#endif
  }
  /** // doc: test__get_arg_address_qualifier() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_address_qualifier( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKenelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_kernel_arg_address_qualifier var = CL_KERNEL_ARG_ADDRESS_LOCAL;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelArgInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);
    TS_ASSERT(k.get_arg_address_qualifier(2) == kernel_arg_address_qualifier_t::local);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_ADDRESS_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_kernel_arg_address_qualifier));
#endif
  }
  /** // doc: test__get_arg_access_qualifier() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_access_qualifier( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKenelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_kernel_arg_access_qualifier var = CL_KERNEL_ARG_ACCESS_WRITE_ONLY;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelArgInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);
    TS_ASSERT(k.get_arg_access_qualifier(2) == kernel_arg_access_qualifier_t::write_only);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_ACCESS_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_kernel_arg_access_qualifier));
#endif
  }
  /** // doc: test__get_arg_type_name() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_type_name( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKenelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    char var[] = { "argument1type" };
    size_t n = sizeof(var);

    T::Dummy_clGetKernelArgInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_arg_type_name(2), var);
    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_TYPE_NAME);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(var));
#endif
  }
  /** // doc: test__get_arg_type_qualifier() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_type_qualifier( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKenelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_kernel_arg_type_qualifier var = CL_KERNEL_ARG_TYPE_CONST;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelArgInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);
    TS_ASSERT(k.get_arg_type_qualifier(2) == kernel_arg_type_qualifier_t::const_);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_TYPE_QUALIFIER);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(cl_kernel_arg_type_qualifier));
#endif
  }
  /** // doc: test__get_arg_name() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_arg_name( )
  {
#if CLXX_OPENCL_ALLOWED(clGetKenelArgInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    char var[] = { "argument1" };
    size_t n = sizeof(var);

    T::Dummy_clGetKernelArgInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);
    TS_ASSERT_EQUALS(k.get_arg_name(2), var);
    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_ARG_NAME);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(var));
#endif
  }
  /** // doc: test__get_work_group_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_work_group_info( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);
    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);

    device d((cl_device_id)0x7654);

    k.get_work_group_info(d, kernel_work_group_info_t::work_group_size, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());

    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_work_group_info)CL_KERNEL_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_work_group_size( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    size_t var = 123;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_work_group_size(d) == var);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(var));
  }
  /** // doc: test__get_compile_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_compile_work_group_size( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    size_t var[] = {123, 124, 125};
    size_t n = sizeof(var);

    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);

    device d((cl_device_id)0x7654);

    size_t array[4] = {0};

    k.get_compile_work_group_size(array, d);

    TS_ASSERT_EQUALS(array[0], 123);
    TS_ASSERT_EQUALS(array[1], 124);
    TS_ASSERT_EQUALS(array[2], 125);
    TS_ASSERT_EQUALS(array[3], 0);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_COMPILE_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 3*sizeof(size_t));
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), array);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), nullptr);
  }
  /** // doc: test__get_local_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_local_mem_size( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_ulong var = 123;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_local_mem_size(d) == var);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_LOCAL_MEM_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(size_t));
  }
  /** // doc: test__get_preferred_work_group_size_multiple() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_preferred_work_group_size_multiple( )
  {
#if CL_VERSION_1_1
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    size_t var = 123;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_preferred_work_group_size_multiple(d) == var);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(var));
#endif
  }
  /** // doc: test__get_private_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_private_mem_size( )
  {
#if CL_VERSION_1_1
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    cl_ulong var = 123;
    size_t n = sizeof(var);

    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);

    device d((cl_device_id)0x7654);

    TS_ASSERT(k.get_private_mem_size(d) == var);
    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_PRIVATE_MEM_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), sizeof(size_t));
#endif
  }
  /** // doc: test__get_global_work_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_global_work_size( )
  {
#if CL_VERSION_1_2
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    size_t var[] = {123, 124, 125};
    size_t n = sizeof(var);

    T::Dummy_clGetKernelWorkGroupInfo mock3(CL_SUCCESS, &var, &n);

    kernel k((cl_kernel)0x4321);

    T::Dummy_clRetainDevice mock4(CL_SUCCESS);
    T::Dummy_clReleaseDevice mock5(CL_SUCCESS);

    device d((cl_device_id)0x7654);

    size_t array[4] = {0};

    k.get_global_work_size(array, d);

    TS_ASSERT_EQUALS(array[0], 123);
    TS_ASSERT_EQUALS(array[1], 124);
    TS_ASSERT_EQUALS(array[2], 125);
    TS_ASSERT_EQUALS(array[3], 0);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x7654);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_kernel_arg_info)CL_KERNEL_GLOBAL_WORK_SIZE);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 3*sizeof(size_t));
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), array);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), nullptr);
#endif
  }
  /** // doc: test__set_arg() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_arg( )
  {
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    T::Dummy_clSetKernelArg mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    k.set_arg(2, 7, (const void*)0x7654);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 7);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (const void*)0x7654);
  }
  /** // doc: test__set_arg_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_arg_svm_pointer( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    T::Dummy_clSetKernelArgSVMPointer mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    k.set_arg_svm_pointer(2, (const void*)0x7654);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (const void*)0x7654);
#endif
  }
  /** // doc: test__set_exec_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_exec_info( )
  {
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
    T::Dummy_clRetainKernel mock1(CL_SUCCESS);
    T::Dummy_clReleaseKernel mock2(CL_SUCCESS);

    T::Dummy_clSetKernelExecInfo mock3(CL_SUCCESS);

    kernel k((cl_kernel)0x4321);

    k.set_exec_info(kernel_exec_info_t::svm_ptrs, 7, (const void*)0x7654);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_kernel)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_KERNEL_EXEC_INFO_SVM_PTRS);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 7);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (const void*)0x7654);
#endif
  }
};

#endif /* CLXX_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
