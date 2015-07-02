// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/program.t.h

/** // doc: clxx/program.t.h {{{
 * \file clxx/program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PROGRAM_T_H_INCLUDED
#define CLXX_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/program.hpp>
#include <clxx/context.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class program_test_suite; }

/** // doc: class clxx::program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p;
    TS_ASSERT(!p.is_initialized());
    TS_ASSERT_EQUALS(p.handle(), (cl_program)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p((cl_program)0x1234);
    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.handle(), (cl_program)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_program)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_1__null_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1__null_id( )
  {
    T::Dummy_clRetainProgram mock1(CL_INVALID_PROGRAM);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(program((cl_program)NULL));
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    program_sources srcs({"src1;", "src2;"});
    program p(ctx, srcs);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.handle(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithSource()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_3( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithBinary mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    devices devs({ device((cl_device_id)0x123), device((cl_device_id)0x456) });
    program_binaries bins({ program_binary({1,2}), program_binary({3,4,5}) });
    std::vector<status_t> stats;

    program p(ctx, devs, bins, stats);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.handle(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithSource()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(stats.size(), 2);
  }
  /** // doc: test_ctor_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_4( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithBinary mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    devices devs({ device((cl_device_id)0x123), device((cl_device_id)0x456) });
    program_binaries bins({ program_binary({1,2}), program_binary({3,4,5}) });

    program p(ctx, devs, bins);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.handle(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithBinary()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_5() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_5( )
  {
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCreateProgramWithBuiltInKernels mock3((cl_program)0x5678, CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    context ctx((cl_context)0x1234);
    devices devs({ device((cl_device_id)0x123), device((cl_device_id)0x456) });
    std::string kerns("kern1 kern2");

    program p(ctx, devs, kerns);

    TS_ASSERT(p.is_initialized());
    TS_ASSERT_EQUALS(p.handle(), (cl_program)0x5678);
    TS_ASSERT(mock3.called_once());
    // mock1 not called because the class assumes the implicit retain performed
    // by clCreateProgramWithBuiltinKernels()
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
#endif
  }
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p1((cl_program)0x1234);
    program p2(p1);
    TS_ASSERT(p2.is_initialized());
    TS_ASSERT(mock1.called_twice());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(p2, program((cl_program)0x1234));
  }
  /** // doc: test_dtor__notnull() {{{
   * \todo Write documentation
   */ // }}}
  void test_dtor__notnull( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    {
      program p((cl_program)0x1234);
    }
    TS_ASSERT(mock2.called_once_with((cl_program)0x1234));
  }
  /** // doc: test_dtor__null() {{{
   * \todo Write documentation
   */ // }}}
  void test_dtor__null( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    {
      program p((cl_program)NULL);
    }
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_id() {{{
   * \todo Write documentation
   */ // }}}
  void test_id( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(program((cl_program)0x1234).handle(), (cl_program)0x1234);
    TS_ASSERT_EQUALS(program((cl_program)NULL).handle(), (cl_program)NULL);
  }
  /** // doc: test_get_valid_handle() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_valid_handle( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(program((cl_program)0x1234).get_valid_handle(), (cl_program)0x1234);
    TS_ASSERT_THROWS(program((cl_program)NULL).get_valid_handle(), uninitialized_program_error);
  }
  /** // doc: test_op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_assign( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    program p1((cl_program)0x1234);
    program p2((cl_program)0x5678);
    p1 = p2;
    TS_ASSERT_EQUALS(p1.handle(), (cl_program)0x5678);
  }
  /** // doc: test_op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_eq( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT( (program((cl_program)0x1234) == program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) == program((cl_program)0x5678)));
    TS_ASSERT(!(program((cl_program)0x5678) == program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) == program((cl_program)NULL)));
    TS_ASSERT(!(program((cl_program)NULL)   == program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)NULL)   == program((cl_program)NULL)));
  }
  /** // doc: test_op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_neq( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT(!(program((cl_program)0x1234) != program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) != program((cl_program)0x5678)));
    TS_ASSERT( (program((cl_program)0x5678) != program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) != program((cl_program)NULL)));
    TS_ASSERT( (program((cl_program)NULL)   != program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)NULL)   != program((cl_program)NULL)));
  }
  /** // doc: test_op_lt() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_lt( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT(!(program((cl_program)0x1234) < program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) < program((cl_program)0x5678)));
    TS_ASSERT(!(program((cl_program)0x5678) < program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) < program((cl_program)NULL)));
    TS_ASSERT( (program((cl_program)NULL)   < program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)NULL)   < program((cl_program)NULL)));
  }
  /** // doc: test_op_gt() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_gt( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT(!(program((cl_program)0x1234) > program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) > program((cl_program)0x5678)));
    TS_ASSERT( (program((cl_program)0x5678) > program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) > program((cl_program)NULL)));
    TS_ASSERT(!(program((cl_program)NULL)   > program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)NULL)   > program((cl_program)NULL)));
  }
  /** // doc: test_op_le() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_le( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT( (program((cl_program)0x1234) <= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) <= program((cl_program)0x5678)));
    TS_ASSERT(!(program((cl_program)0x5678) <= program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) <= program((cl_program)NULL)));
    TS_ASSERT( (program((cl_program)NULL)   <= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)NULL)   <= program((cl_program)NULL)));
  }
  /** // doc: test_op_ge() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_ge( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    TS_ASSERT( (program((cl_program)0x1234) >= program((cl_program)0x1234)));
    TS_ASSERT(!(program((cl_program)0x1234) >= program((cl_program)0x5678)));
    TS_ASSERT( (program((cl_program)0x5678) >= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)0x1234) >= program((cl_program)NULL)));
    TS_ASSERT(!(program((cl_program)NULL)   >= program((cl_program)0x1234)));
    TS_ASSERT( (program((cl_program)NULL)   >= program((cl_program)NULL)));
  }
  /** // doc: test_get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_info( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS);

    program p((cl_program)0x4321);
    p.get_info(program_info_t::context, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_CONTEXT);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test_get_info__uninitialized_program() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_info__uninitialized_program( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS);

    program p((cl_program)NULL);
    TS_ASSERT_THROWS(p.get_info(program_info_t::context, 0, nullptr, nullptr), uninitialized_program_error);
  }
  /** // doc: test_get_build_info() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_info( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clGetProgramBuildInfo mock3(CL_SUCCESS);

    program p((cl_program)0x4321);
    p.get_build_info(device((cl_device_id)0x8765), program_build_info_t::status, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_device_id)0x8765);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BUILD_STATUS);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test_get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_reference_count( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    cl_uint var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, &var, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_reference_count(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_REFERENCE_COUNT);
  }
  /** // doc: test_get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_context( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    cl_context var = (cl_context)0x123;
    size_t n = sizeof(var);

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, &var, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_context(), context((cl_context)0x123));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_CONTEXT);
  }
  /** // doc: test_get_num_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_num_devices( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    size_t var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, &var, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_num_devices(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_NUM_DEVICES);
  }
  /** // doc: test_get_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_devices( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    cl_device_id array[3] = {(cl_device_id)0x123, (cl_device_id)0x456, (cl_device_id)0x789};
    size_t n = sizeof(array);

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, array, &n);

    program p((cl_program)0x4321);
    devices ds(p.get_devices());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_DEVICES);
    TS_ASSERT_EQUALS(ds.size(), 3);
    TS_ASSERT_EQUALS(ds[0].handle(), (cl_device_id)0x123);
    TS_ASSERT_EQUALS(ds[1].handle(), (cl_device_id)0x456);
    TS_ASSERT_EQUALS(ds[2].handle(), (cl_device_id)0x789);
  }
  /** // doc: test_get_source() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_source( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    char array[] = {"this is a good source"};
    size_t n = sizeof(array);

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, array, &n);

    program p((cl_program)0x4321);
    program_source src(p.get_source());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_SOURCE);
    TS_ASSERT_EQUALS(src.size(), (n-1));
    TS_ASSERT_EQUALS(src, array);
  }
  /** // doc: test_get_binary_sizes() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_binary_sizes( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    size_t array[3] = {0x123ul, 0x456ul, 0x789ul};
    size_t n = sizeof(array);

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, array, &n);

    program p((cl_program)0x4321);
    std::vector<size_t> sizes(p.get_binary_sizes());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BINARY_SIZES);
    TS_ASSERT_EQUALS(sizes.size(), 3);
    TS_ASSERT_EQUALS(sizes[0], 0x123ul);
    TS_ASSERT_EQUALS(sizes[1], 0x456ul);
    TS_ASSERT_EQUALS(sizes[2], 0x789ul);
  }
  /** // doc: test_get_binaries() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_binaries( )
  {
    TS_ASSERT(true); // no idea ATM how to mock and test it
  }
  /** // doc: test_get_num_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_num_kernels( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    size_t var = 3;
    size_t n = sizeof(var);

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, &var, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_num_kernels(), 3);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_NUM_KERNELS);
  }
  /** // doc: test_get_kernel_names() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_kernel_names( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    char const* array = "kernel1 kernel2";
    size_t n = std::strlen(array) + 1;

    T::Dummy_clGetProgramInfo mock3(CL_SUCCESS, (void*)array, &n);

    program p((cl_program)0x4321);
    std::string kerns(p.get_kernel_names());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROGRAM_KERNEL_NAMES);
    TS_ASSERT_EQUALS(kerns, array);
  }
  /** // doc: test_get_build_status() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_status( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    cl_build_status var = (cl_build_status)CL_BUILD_IN_PROGRESS;
    size_t n = sizeof(var);

    T::Dummy_clGetProgramBuildInfo mock3(CL_SUCCESS, &var, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_build_status(device((cl_device_id)0x1234)), build_status_t::in_progress);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_build_status)CL_PROGRAM_BUILD_STATUS);
  }
  /** // doc: test_get_build_options() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_options( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    char const* array = "--option1 --option2";
    size_t n = std::strlen(array) + 1;

    T::Dummy_clGetProgramBuildInfo mock3(CL_SUCCESS, (void*)array, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_build_options(device((cl_device_id)0x1234)), array);

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BUILD_OPTIONS);
  }
  /** // doc: test_get_build_log() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_build_log( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    char const* array = "blah blah blah";
    size_t n = std::strlen(array) + 1;

    T::Dummy_clGetProgramBuildInfo mock3(CL_SUCCESS, (void*)array, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_build_log(device((cl_device_id)0x1234)), array);

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_uint)CL_PROGRAM_BUILD_LOG);
  }
  /** // doc: test_get_binary_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_binary_type( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);

    cl_program_binary_type var = (cl_build_status)CL_PROGRAM_BINARY_TYPE_LIBRARY;
    size_t n = sizeof(var);

    T::Dummy_clGetProgramBuildInfo mock3(CL_SUCCESS, &var, &n);

    program p((cl_program)0x4321);
    TS_ASSERT_EQUALS(p.get_binary_type(device((cl_device_id)0x1234)), program_binary_type_t::library);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), (cl_build_status)CL_PROGRAM_BINARY_TYPE);
  }
/** // doc: test_build_program_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_build_program_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clBuildProgram mock3(CL_SUCCESS);

    build_program(program((cl_program)0x1234), std::string("--opt1 --opt2"));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 0ul);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), nullptr);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), nullptr);
  }
/** // doc: test_build_program_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_build_program_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clBuildProgram mock3(CL_SUCCESS);

    build_program(program((cl_program)0x1234),
                  devices({device((cl_device_id)0x1234), device((cl_device_id)0x5678)}),
                  std::string("--opt1 --opt2"));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<2>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), nullptr);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), nullptr);
  }
/** // doc: test_build_program_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_build_program_3( )
  {
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clBuildProgram mock3(CL_SUCCESS);

    class PO : public program_observer { void notify(program const&) { } };
    PO po;

    build_program(program((cl_program)0x1234), std::string("--opt1 --opt2"), po);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 0ul);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (void*)&po);
  }
/** // doc: test_build_program_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_build_program_4( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clBuildProgram mock3(CL_SUCCESS);

    class PO : public program_observer { void notify(program const&) { } };
    PO po;

    build_program(program((cl_program)0x1234),
                  devices({device((cl_device_id)0x1234), device((cl_device_id)0x5678)}),
                  std::string("--opt1 --opt2"),
                  po);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<2>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<5>(mock3.calls().back()), (void*)&po);
  }
/** // doc: test_compile_program_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_compile_program_1( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCompileProgram mock3(CL_SUCCESS);

    compile_program(program((cl_program)0x1234),
                    std::string("--opt1 --opt2"),
                    programs(),
                    std::vector<std::string>());

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 0ul);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), 0ul);
    TS_ASSERT(std::get<5>(mock3.calls().back()) == nullptr);
    TS_ASSERT(std::get<6>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<7>(mock3.calls().back()), nullptr);
    TS_ASSERT_EQUALS(std::get<8>(mock3.calls().back()), nullptr);
#endif
  }
/** // doc: test_compile_program_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_compile_program_2( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCompileProgram mock3(CL_SUCCESS);

    class PO : public program_observer { void notify(program const&) { } };
    PO po;

    compile_program(program((cl_program)0x1234),
                    std::string("--opt1 --opt2"),
                    programs(),
                    std::vector<std::string>(),
                    po);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 0ul);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), 0ul);
    TS_ASSERT(std::get<5>(mock3.calls().back()) == nullptr);
    TS_ASSERT(std::get<6>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<7>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<8>(mock3.calls().back()), (void*)&po);
#endif
  }
/** // doc: test_compile_program_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_compile_program_3( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCompileProgram mock3(CL_SUCCESS);

    compile_program(program((cl_program)0x1234),
                    devices({device((cl_device_id)0x1234), device((cl_device_id)0x5678)}),
                    std::string("--opt1 --opt2"),
                    programs(),
                    std::vector<std::string>());

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<2>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), 0ul);
    TS_ASSERT(std::get<5>(mock3.calls().back()) == nullptr);
    TS_ASSERT(std::get<6>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<7>(mock3.calls().back()), nullptr);
    TS_ASSERT_EQUALS(std::get<8>(mock3.calls().back()), nullptr);
#endif
  }
/** // doc: test_compile_program_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_compile_program_4( )
  {
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clCompileProgram mock3(CL_SUCCESS);

    class PO : public program_observer { void notify(program const&) { } };
    PO po;

    compile_program(program((cl_program)0x1234),
                    devices({device((cl_device_id)0x1234), device((cl_device_id)0x5678)}),
                    std::string("--opt1 --opt2"),
                    programs(),
                    std::vector<std::string>(),
                    po);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_program)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<2>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), 0ul);
    TS_ASSERT(std::get<5>(mock3.calls().back()) == nullptr);
    TS_ASSERT(std::get<6>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<7>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<8>(mock3.calls().back()), (void*)&po);
#endif
  }
/** // doc: test_link_program_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_link_program_1( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clLinkProgram mock3((cl_program)0x1234,CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    programs iprogs({program((cl_program)0x56), program((cl_program)0x78)});
    devices devs({device((cl_device_id)0x560), device((cl_device_id)0x780)});
    context ctx((cl_context)0x8765);

    program p(link_program(ctx, devs, std::string("-o1 -o2"), iprogs));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_context)0x8765);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<2>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<5>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<6>(mock3.calls().back()), nullptr);
    TS_ASSERT_EQUALS(std::get<7>(mock3.calls().back()), nullptr);
    TS_ASSERT(std::get<8>(mock3.calls().back()) != nullptr);

#endif
  }
/** // doc: test_link_program_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_link_program_2( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clRetainProgram mock1(CL_SUCCESS);
    T::Dummy_clReleaseProgram mock2(CL_SUCCESS);
    T::Dummy_clLinkProgram mock3((cl_program)0x1234,CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    class PO : public program_observer { void notify(program const&) { } };
    PO po;

    programs iprogs({program((cl_program)0x56), program((cl_program)0x78)});
    devices devs({device((cl_device_id)0x560), device((cl_device_id)0x780)});
    context ctx((cl_context)0x8765);

    program p(link_program(ctx, devs, std::string("-o1 -o2"), iprogs, po));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_context)0x8765);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<2>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<3>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), 2ul);
    TS_ASSERT(std::get<5>(mock3.calls().back()) != nullptr);
    TS_ASSERT(std::get<6>(mock3.calls().back()) != nullptr);
    TS_ASSERT_EQUALS(std::get<7>(mock3.calls().back()), (void*)&po)
    TS_ASSERT(std::get<8>(mock3.calls().back()) != nullptr);

#endif
  }
};

#endif /* CLXX_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
