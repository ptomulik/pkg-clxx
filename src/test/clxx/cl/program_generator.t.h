// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_generator.t.h

/** // doc: clxx/cl/program_generator.t.h {{{
 * \file clxx/cl/program_generator.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_GENERATOR_T_H_INCLUDED
#define CLXX_CL_PROGRAM_GENERATOR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/program_generator.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class program_generator_test_suite; }

/** // doc: class clxx::program_generator_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_generator_test_suite : public CxxTest::TestSuite
{
  class G0 : public program_generator
  {
  public:
    std::string program_name() const { return "g0"; }
    void generate_program_source(std::string&, clxx::context const&) const { }
  };

  class G1 : public program_generator
  {
  public:
    std::string program_name() const { return "g1"; }
    std::string program_path() const { return "/tmp/clxx/g1.cl"; }
    void generate_program_source(std::string& src, clxx::context const&) const
    { src.append("__kernel void foo() {}\n"); }
  };

public:
  /** // doc: test__program_name__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_name__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_name(), "g0");
    TS_ASSERT_EQUALS(g1.program_name(), "g1");
  }
  /** // doc: test__program_path__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_path__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_path(), "g0");
    TS_ASSERT_EQUALS(g1.program_path(), "/tmp/clxx/g1.cl");
  }
  /** // doc: test__line_directive__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__line_directive__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.line_directive(123), "#line 123 \"g0\"");
    TS_ASSERT_EQUALS(g1.line_directive(456), "#line 456 \"/tmp/clxx/g1.cl\"");
  }
  /** // doc: test__get_program__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program__1( )
  {
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);

    program_generator const& g0 = G0{};
    clxx::context const& c{ (cl_context)0x4567 };
    clxx::program const& p{ g0.get_program(c) };

    TS_ASSERT(mockRetainContext.called_once_with((cl_context)0x4567));
    TS_ASSERT(mockReleaseContext.never_called());
    TS_ASSERT(mockRetainProgram.never_called());
    TS_ASSERT(mockReleaseProgram.never_called());
    TS_ASSERT(mockCreateProgramWithSource.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mockCreateProgramWithSource.calls().back()), (cl_context)0x4567);
    TS_ASSERT_EQUALS(std::get<1>(mockCreateProgramWithSource.calls().back()), 1);
    TS_ASSERT(p.get() == (cl_program)0x1234);
  }
  /** // doc: test__generate_and_build_program__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__generate_and_build_program__1( )
  {
    union queue_info_t{
      cl_device_id device;
      cl_context context;
    };
    queue_info_t queue_info;
    size_t queue_info_size = sizeof(queue_info);
    queue_info.context = (cl_context)0x5678;

    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mockRetainCommandQueue(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mockReleaseCommandQueue(CL_SUCCESS);
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mockGetCommandQueueInfo(CL_SUCCESS, &queue_info, &queue_info_size);
    T::Dummy_clBuildProgram mockBuildProgram(CL_SUCCESS);

    program_generator const& g1 = G1{};
    program p;
    command_queue q{(cl_command_queue)0x4321};

    generate_and_build_program(p, g1, q);

    TS_ASSERT(p.get() == (cl_program)0x1234);

    TS_ASSERT(mockGetCommandQueueInfo.called_twice());
    //
    TS_ASSERT(std::get<0>(mockGetCommandQueueInfo.calls().front()) == (cl_command_queue)0x4321);
    TS_ASSERT(std::get<1>(mockGetCommandQueueInfo.calls().front()) == CL_QUEUE_CONTEXT);
    TS_ASSERT(std::get<2>(mockGetCommandQueueInfo.calls().front()) == sizeof(cl_context));
    TS_ASSERT(std::get<3>(mockGetCommandQueueInfo.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockGetCommandQueueInfo.calls().front()) == nullptr);
    //
    TS_ASSERT(std::get<0>(mockGetCommandQueueInfo.calls().back()) == (cl_command_queue)0x4321);
    TS_ASSERT(std::get<1>(mockGetCommandQueueInfo.calls().back()) == CL_QUEUE_DEVICE);
    TS_ASSERT(std::get<2>(mockGetCommandQueueInfo.calls().back()) == sizeof(cl_device_id));
    TS_ASSERT(std::get<3>(mockGetCommandQueueInfo.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mockGetCommandQueueInfo.calls().back()) == nullptr);

    TS_ASSERT(mockBuildProgram.called_once());
    TS_ASSERT(std::get<0>(mockBuildProgram.calls().front()) == (cl_program)0x1234);
    TS_ASSERT(std::get<1>(mockBuildProgram.calls().front()) == 1);
    TS_ASSERT(std::get<2>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<3>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockBuildProgram.calls().front()) == nullptr);
    TS_ASSERT(std::get<5>(mockBuildProgram.calls().front()) == nullptr);
  }
  /** // doc: test__generate_and_lazy_build_program__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__generate_and_lazy_build_program__1( )
  {
    union queue_info_t{
      cl_device_id device;
      cl_context context;
    };
    queue_info_t queue_info;
    size_t queue_info_size = sizeof(queue_info);
    queue_info.context = (cl_context)0x5678;

    const cl_build_status build_status = (cl_build_status)CL_BUILD_NONE;
    size_t build_status_size = sizeof(build_status);

    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mockRetainCommandQueue(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mockReleaseCommandQueue(CL_SUCCESS);
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mockGetCommandQueueInfo(CL_SUCCESS, &queue_info, &queue_info_size);
    T::Dummy_clGetProgramBuildInfo mockGetProgramBuildInfo(CL_SUCCESS, &build_status, &build_status_size);
    T::Dummy_clBuildProgram mockBuildProgram(CL_SUCCESS);

    program_generator const& g1 = G1{};
    program p;
    command_queue q{(cl_command_queue)0x4321};

    generate_and_lazy_build_program(p, g1, q);

    TS_ASSERT(p.get() == (cl_program)0x1234);

    TS_ASSERT(mockGetCommandQueueInfo.called_twice());
    //
    TS_ASSERT(std::get<0>(mockGetCommandQueueInfo.calls().front()) == (cl_command_queue)0x4321);
    TS_ASSERT(std::get<1>(mockGetCommandQueueInfo.calls().front()) == CL_QUEUE_CONTEXT);
    TS_ASSERT(std::get<2>(mockGetCommandQueueInfo.calls().front()) == sizeof(cl_context));
    TS_ASSERT(std::get<3>(mockGetCommandQueueInfo.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockGetCommandQueueInfo.calls().front()) == nullptr);
    //
    TS_ASSERT(std::get<0>(mockGetCommandQueueInfo.calls().back()) == (cl_command_queue)0x4321);
    TS_ASSERT(std::get<1>(mockGetCommandQueueInfo.calls().back()) == CL_QUEUE_DEVICE);
    TS_ASSERT(std::get<2>(mockGetCommandQueueInfo.calls().back()) == sizeof(cl_device_id));
    TS_ASSERT(std::get<3>(mockGetCommandQueueInfo.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mockGetCommandQueueInfo.calls().back()) == nullptr);

    TS_ASSERT(mockGetProgramBuildInfo.called_once());
    TS_ASSERT(std::get<0>(mockGetProgramBuildInfo.calls().front()) == (cl_program)0x1234);
    TS_ASSERT(std::get<1>(mockGetProgramBuildInfo.calls().front()) == (cl_device_id)0x5678);
    TS_ASSERT(std::get<2>(mockGetProgramBuildInfo.calls().front()) == CL_PROGRAM_BUILD_STATUS);
    TS_ASSERT(std::get<3>(mockGetProgramBuildInfo.calls().front()) == sizeof(cl_build_status));
    TS_ASSERT(std::get<4>(mockGetProgramBuildInfo.calls().front()) != nullptr);
    TS_ASSERT(std::get<5>(mockGetProgramBuildInfo.calls().front()) == nullptr);

    TS_ASSERT(mockBuildProgram.called_once());
    TS_ASSERT(std::get<0>(mockBuildProgram.calls().front()) == (cl_program)0x1234);
    TS_ASSERT(std::get<1>(mockBuildProgram.calls().front()) == 1);
    TS_ASSERT(std::get<2>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<3>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockBuildProgram.calls().front()) == nullptr);
    TS_ASSERT(std::get<5>(mockBuildProgram.calls().front()) == nullptr);
  }
  /** // doc: test__generate_and_lazy_build_program__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__generate_and_lazy_build_program__2( )
  {
    union queue_info_t{
      cl_device_id device;
      cl_context context;
    };
    queue_info_t queue_info;
    size_t queue_info_size = sizeof(queue_info);
    queue_info.context = (cl_context)0x5678;

    const cl_build_status build_status = (cl_build_status)CL_BUILD_SUCCESS;
    size_t build_status_size = sizeof(build_status);

    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clRetainCommandQueue mockRetainCommandQueue(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mockReleaseCommandQueue(CL_SUCCESS);
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);
    T::Dummy_clGetCommandQueueInfo mockGetCommandQueueInfo(CL_SUCCESS, &queue_info, &queue_info_size);
    T::Dummy_clGetProgramBuildInfo mockGetProgramBuildInfo(CL_SUCCESS, &build_status, &build_status_size);
    T::Dummy_clBuildProgram mockBuildProgram(CL_SUCCESS);

    program_generator const& g1 = G1{};
    program p;
    command_queue q{(cl_command_queue)0x4321};

    generate_and_lazy_build_program(p, g1, q);

    TS_ASSERT(p.get() == (cl_program)0x1234);

    TS_ASSERT(mockGetCommandQueueInfo.called_twice());
    //
    TS_ASSERT(std::get<0>(mockGetCommandQueueInfo.calls().front()) == (cl_command_queue)0x4321);
    TS_ASSERT(std::get<1>(mockGetCommandQueueInfo.calls().front()) == CL_QUEUE_CONTEXT);
    TS_ASSERT(std::get<2>(mockGetCommandQueueInfo.calls().front()) == sizeof(cl_context));
    TS_ASSERT(std::get<3>(mockGetCommandQueueInfo.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockGetCommandQueueInfo.calls().front()) == nullptr);
    //
    TS_ASSERT(std::get<0>(mockGetCommandQueueInfo.calls().back()) == (cl_command_queue)0x4321);
    TS_ASSERT(std::get<1>(mockGetCommandQueueInfo.calls().back()) == CL_QUEUE_DEVICE);
    TS_ASSERT(std::get<2>(mockGetCommandQueueInfo.calls().back()) == sizeof(cl_device_id));
    TS_ASSERT(std::get<3>(mockGetCommandQueueInfo.calls().back()) != nullptr);
    TS_ASSERT(std::get<4>(mockGetCommandQueueInfo.calls().back()) == nullptr);

    TS_ASSERT(mockGetProgramBuildInfo.called_once());
    TS_ASSERT(std::get<0>(mockGetProgramBuildInfo.calls().front()) == (cl_program)0x1234);
    TS_ASSERT(std::get<1>(mockGetProgramBuildInfo.calls().front()) == (cl_device_id)0x5678);
    TS_ASSERT(std::get<2>(mockGetProgramBuildInfo.calls().front()) == CL_PROGRAM_BUILD_STATUS);
    TS_ASSERT(std::get<3>(mockGetProgramBuildInfo.calls().front()) == sizeof(cl_build_status));
    TS_ASSERT(std::get<4>(mockGetProgramBuildInfo.calls().front()) != nullptr);
    TS_ASSERT(std::get<5>(mockGetProgramBuildInfo.calls().front()) == nullptr);

    TS_ASSERT(mockBuildProgram.never_called());
  }
};

#endif /* CLXX_CL_PROGRAM_GENERATOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
