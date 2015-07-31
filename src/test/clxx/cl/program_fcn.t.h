// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_fcn.t.h

/** // doc: clxx/cl/program_fcn.t.h {{{
 * \file clxx/cl/program_fcn.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_FCN_T_H_INCLUDED
#define CLXX_CL_PROGRAM_FCN_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/program_fcn.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class program_fcn_test_suite; }

/** // doc: class clxx::program_fcn_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_fcn_test_suite : public CxxTest::TestSuite
{
public:
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

#endif /* CLXX_CL_PROGRAM_FCN_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
