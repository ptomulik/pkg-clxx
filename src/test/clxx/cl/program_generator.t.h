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
#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/command_queue.hpp>
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
    std::string program_path(clxx::context const&) const { return "/tmp/clxx/g0.cl"; }
    void generate_program_source(std::string&, clxx::context const&) const { }
  };

  class G1 : public program_generator
  {
  public:
    std::string program_path(clxx::context const&) const { return "/tmp/clxx/g1.cl"; }
    void generate_program_source(std::string& src, clxx::context const&) const
    { src.append("__kernel void foo() {}\n"); }
  };

public:
  /** // doc: test__program_path__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_path__1( )
  {
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    clxx::context const& c{ (cl_context)0x4567 };
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_path(c), "/tmp/clxx/g0.cl");
    TS_ASSERT_EQUALS(g1.program_path(c), "/tmp/clxx/g1.cl");
  }
  /** // doc: test__line_directive__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__line_directive__1( )
  {
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    clxx::context const& c{ (cl_context)0x4567 };
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.line_directive(c,123), "#line 123 \"/tmp/clxx/g0.cl\"");
    TS_ASSERT_EQUALS(g1.line_directive(c,456), "#line 456 \"/tmp/clxx/g1.cl\"");
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
};

#endif /* CLXX_CL_PROGRAM_GENERATOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
