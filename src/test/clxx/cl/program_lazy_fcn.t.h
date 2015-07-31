// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_lazy_fcnt.h

/** // doc: clxx/cl/program_lazy_fcnt.h {{{
 * \file clxx/cl/program_lazy_fcnt.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_LAZY_FCN_T_H_INCLUDED
#define CLXX_CL_PROGRAM_LAZY_FCN_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/program_lazy_fcn.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/mock.hpp>
#include <clxx/cl/mocks/lazy_build_program.hpp>
#include <map>
#include <cstring>
#include <tuple>

namespace clxx { class program_lazy_fcn_test_suite; }

/** // doc: class clxx::program_lazy_fcn_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_lazy_fcn_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__lazy_build_program__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__lazy_build_program__1( )
  {
    cl_device_id devices[2] = { (cl_device_id)0x1234, (cl_device_id)0x5678 };
    const size_t devices_size = sizeof(devices);
    T::Dummy_clGetProgramInfo mockGetProgramInfo(CL_SUCCESS, devices, &devices_size);
    T::Dummy_clRetainProgram  mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram  mockReleaseProgram(CL_SUCCESS);
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice  mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice  mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clBuildProgram mockBuildProgram(CL_SUCCESS);

    T::LazyBuildProgram_clGetProgramBuildInfo::status_map_t status;
    T::LazyBuildProgram_clGetProgramBuildInfo::options_map_t options;
    status[devices[0]] = CL_BUILD_NONE;
    status[devices[1]] = CL_BUILD_SUCCESS;
    options[devices[0]] = "";
    options[devices[1]] = "";

    T::LazyBuildProgram_clGetProgramBuildInfo mockGetProgramBuildInfo(status, options);

    clxx::program p{(cl_program)0x4321};
    lazy_build_program(p, "");

    // The build was invoked only for the first device
    TS_ASSERT(mockBuildProgram.called_once());
    TS_ASSERT(std::get<0>(mockBuildProgram.calls().front()) == p.get());
    TS_ASSERT_EQUALS(std::get<1>(mockBuildProgram.calls().front()), 1u);
    TS_ASSERT(std::get<2>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<3>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockBuildProgram.calls().front()) == nullptr);
    TS_ASSERT(std::get<5>(mockBuildProgram.calls().front()) == nullptr);

    // The build should not be invoked again (call count shall not increase)
    mockBuildProgram.reset();
    status[devices[0]] = CL_BUILD_SUCCESS;
    lazy_build_program(p, "");
    TS_ASSERT(mockBuildProgram.never_called());

    mockBuildProgram.reset();
    options[devices[1]] = "-cl-opt-disable";
    lazy_build_program(p, "");
    TS_ASSERT(mockBuildProgram.called_once());
    TS_ASSERT(std::get<0>(mockBuildProgram.calls().front()) == p.get());
    TS_ASSERT_EQUALS(std::get<1>(mockBuildProgram.calls().front()), 1u);
    TS_ASSERT(std::get<2>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<3>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockBuildProgram.calls().front()) == nullptr);
    TS_ASSERT(std::get<5>(mockBuildProgram.calls().front()) == nullptr);
  }
  /** // doc: test__lazy_build_program__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__lazy_build_program__2( )
  {
    clxx::devices devices{ clxx::device((cl_device_id)0x1234),
                           clxx::device((cl_device_id)0x5678),
                           clxx::device((cl_device_id)0x9012) };

    T::Dummy_clRetainProgram  mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram  mockReleaseProgram(CL_SUCCESS);
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice  mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice  mockReleaseDevice(CL_SUCCESS);
#endif
    T::Dummy_clBuildProgram mockBuildProgram(CL_SUCCESS);

    T::LazyBuildProgram_clGetProgramBuildInfo::status_map_t status;
    T::LazyBuildProgram_clGetProgramBuildInfo::options_map_t options;
    status[devices[0].get()] = CL_BUILD_NONE;
    status[devices[1].get()] = CL_BUILD_SUCCESS;
    status[devices[2].get()] = CL_BUILD_NONE;
    options[devices[0].get()] = "";
    options[devices[1].get()] = "";
    options[devices[2].get()] = "";

    T::LazyBuildProgram_clGetProgramBuildInfo mockGetProgramBuildInfo(status, options);

    clxx::program p{(cl_program)0x4321};
    lazy_build_program(p, clxx::devices{ devices[0], devices[1] }, "");

    // The build was invoked only for the first device
    TS_ASSERT(mockBuildProgram.called_once());
    TS_ASSERT(std::get<0>(mockBuildProgram.calls().front()) == p.get());
    TS_ASSERT_EQUALS(std::get<1>(mockBuildProgram.calls().front()), 1u);
    TS_ASSERT(std::get<2>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<3>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockBuildProgram.calls().front()) == nullptr);
    TS_ASSERT(std::get<5>(mockBuildProgram.calls().front()) == nullptr);

    status[devices[0].get()] = CL_BUILD_SUCCESS;

    mockBuildProgram.reset();
    lazy_build_program(p, devices, "");
    TS_ASSERT(mockBuildProgram.called_once());
    TS_ASSERT(std::get<0>(mockBuildProgram.calls().front()) == p.get());
    TS_ASSERT_EQUALS(std::get<1>(mockBuildProgram.calls().front()), 1u);
    TS_ASSERT(std::get<2>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<3>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockBuildProgram.calls().front()) == nullptr);
    TS_ASSERT(std::get<5>(mockBuildProgram.calls().front()) == nullptr);

    status[devices[2].get()] = CL_BUILD_SUCCESS;

    mockBuildProgram.reset();
    lazy_build_program(p, devices, "");
    TS_ASSERT(mockBuildProgram.never_called());

    mockBuildProgram.reset();
    options[devices[1].get()] = "-cl-opt-disable";
    lazy_build_program(p, devices, "");
    TS_ASSERT(mockBuildProgram.called_once());
    TS_ASSERT(std::get<0>(mockBuildProgram.calls().front()) == p.get());
    TS_ASSERT_EQUALS(std::get<1>(mockBuildProgram.calls().front()), 1u);
    TS_ASSERT(std::get<2>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<3>(mockBuildProgram.calls().front()) != nullptr);
    TS_ASSERT(std::get<4>(mockBuildProgram.calls().front()) == nullptr);
    TS_ASSERT(std::get<5>(mockBuildProgram.calls().front()) == nullptr);
  }
};

#endif /* CLXX_CL_PROGRAM_LAZY_FCN_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
