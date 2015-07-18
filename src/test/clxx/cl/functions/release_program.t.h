// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/release_program.t.h

/** // doc: clxx/cl/functions/release_program.t.h {{{
 * \file clxx/cl/functions/release_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_RELEASE_PROGRAM_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_RELEASE_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_release_program_test_suite; }

/** // doc: class clxx::functions_release_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_release_program_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_program()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program( )
  {
    T::Dummy_clReleaseProgram mock(CL_SUCCESS);
    release_program                ((cl_program)0x433);
    TS_ASSERT(mock.called_once_with((cl_program)0x433));
  }
  /** // doc: test__release_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__invalid_program( )
  {
    T::Dummy_clReleaseProgram mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__release_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__out_of_resources( )
  {
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__release_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__out_of_host_memory( )
  {
    T::Dummy_clReleaseProgram mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_program((cl_program)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__release_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_program__unexpected_clerror( )
  {
    T::Dummy_clReleaseProgram mock(-0x1234567);
    TS_ASSERT_THROWS(release_program((cl_program)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_RELEASE_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
