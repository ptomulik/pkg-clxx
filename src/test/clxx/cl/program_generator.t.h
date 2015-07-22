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
    void generate_program_source(std::string&) const { }
  };

  class G1 : public program_generator
  {
  public:
    std::string program_name() const { return "g1"; }
    std::string program_namespace() const { return "clxx"; }
    std::string program_file_suffix() const { return ".xyz"; }
    std::string program_dir() const { return "/tmp/clxx"; }
    void generate_program_source(std::string& src) const
    {
      src.append("__kernel void foo() {}\n");
    }
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
  /** // doc: test__program_namespace__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_namespace__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_namespace(), "");
    TS_ASSERT_EQUALS(g1.program_namespace(), "clxx");
  }
  /** // doc: test__program_full_name__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_full_name__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_full_name(), "::g0");
    TS_ASSERT_EQUALS(g1.program_full_name(), "clxx::g1");
  }
  /** // doc: test__program_file_suffix__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_file_suffix__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_file_suffix(), ".cl");
    TS_ASSERT_EQUALS(g1.program_file_suffix(), ".xyz");
  }
  /** // doc: test__program_file__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_file__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_file(), "g0.cl");
    TS_ASSERT_EQUALS(g1.program_file(), "g1.xyz");
  }
  /** // doc: test__program_dir__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_dir__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_dir(), "");
    TS_ASSERT_EQUALS(g1.program_dir(), "/tmp/clxx");
  }
  /** // doc: test__program_path__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_path__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.program_path(), "g0.cl");
    TS_ASSERT_EQUALS(g1.program_path(), "/tmp/clxx/g1.xyz");
  }
  /** // doc: test__program_path__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_path__2( )
  {
    class G : public program_generator
    {
      void generate_program_source(std::string&) const { }
      std::string program_name() const { return "g"; }
      std::string program_dir() const { return "/tmp/clxx/"; }
    };
    program_generator const& g = G{};
    TS_ASSERT_EQUALS(g.program_path(), "/tmp/clxx/g.cl");
  }
  /** // doc: test__line_directive__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__line_directive__1( )
  {
    program_generator const& g0 = G0{};
    program_generator const& g1 = G1{};
    TS_ASSERT_EQUALS(g0.line_directive(123), "#line 123 \"g0.cl\"");
    TS_ASSERT_EQUALS(g1.line_directive(456), "#line 456 \"/tmp/clxx/g1.xyz\"");
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
