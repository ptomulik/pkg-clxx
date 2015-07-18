// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/retain_program.t.h

/** // doc: clxx/cl/functions/retain_program.t.h {{{
 * \file clxx/cl/functions/retain_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_RETAIN_PROGRAM_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_RETAIN_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_retain_program_test_suite; }

/** // doc: class clxx::functions_retain_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_retain_program_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  retain_program()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__retain_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program( )
  {
    T::Dummy_clRetainProgram mock(CL_SUCCESS);
    retain_program                 ((cl_program)0x344);
    TS_ASSERT(mock.called_once_with((cl_program)0x344));
  }
  /** // doc: test__retain_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__invalid_program( )
  {
    T::Dummy_clRetainProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__retain_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__out_of_resources( )
  {
    T::Dummy_clRetainProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__retain_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__out_of_host_memory( )
  {
    T::Dummy_clRetainProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__retain_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_program__unexpected_clerror( )
  {
    T::Dummy_clRetainProgram mock(-0x1234567);
    TS_ASSERT_THROWS(retain_program((cl_program)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_RETAIN_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
