// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/runtime.t.h

/** // doc: clxx/cl/runtime.t.h {{{
 * \file clxx/cl/runtime.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_RUNTIME_T_H_INCLUDED
#define CLXX_CL_RUNTIME_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/runtime.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx { class runtime_test_suite; }

/** // doc: class clxx::runtime_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::runtime_test_suite : public CxxTest::TestSuite
{
  class G0
    : public clxx::program_generator
  {
    std::string program_path(clxx::context const&) const { return "/tmp/clxx/g0.cl"; }
    void generate_program_source(std::string& src, clxx::context const&) const
    { src.append("__kernel void trivial() { }\n"); }
  };
public:
  void test__static_instances__1( )
  {
    TS_ASSERT(&runtime::get_shared_instance() != &runtime::get_local_instance());
    TS_ASSERT(&runtime::get_current_instance() == &runtime::get_shared_instance());
    runtime::set_current_instance(runtime::get_local_instance());
    TS_ASSERT(&runtime::get_current_instance() == &runtime::get_local_instance());
  }
  /** // doc: test__has_program_generator() {{{
   * \todo Write documentation
   */ // }}}
  void test__has_program_generator( )
  {
    runtime r;
    TS_ASSERT(!r.has_program_generator("clxx::g0"));
    r.set_program_generator("clxx::g0", clxx::make_shared<G0>());
    TS_ASSERT(r.has_program_generator("clxx::g0"));
    TS_ASSERT(!r.has_program_generator("foo"));
  }
  /** // doc: test__get_program_generator__invalid_key_error() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_generator__invalid_key_error( )
  {
    TS_ASSERT_THROWS(runtime().get_program_generator("foo"), clxx::invalid_key_error);
  }
  /** // doc: test__set_program_generator() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_program_generator( )
  {
    runtime r;
    program_generator_ptr g = r.set_program_generator("clxx::g0", clxx::make_shared<G0>());
    TS_ASSERT(r.has_program_generator("clxx::g0"));
    TS_ASSERT(r.get_program_generator("clxx::g0") == g);
  }
  /** // doc: test__foo() {{{
   * \todo Write documentation
   */ // }}}
  void test__foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_CL_RUNTIME_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
