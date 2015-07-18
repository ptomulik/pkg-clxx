// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_kernels_in_program.t.h

/** // doc: clxx/cl/functions/create_kernels_in_program.t.h {{{
 * \file clxx/cl/functions/create_kernels_in_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_KERNELS_IN_PROGRAM_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_KERNELS_IN_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_kernels_in_program_test_suite; }

/** // doc: class clxx::functions_create_kernels_in_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_kernels_in_program_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_kernels_in_program()
  ////////////////////////////////////////////////////////////////////////////
  /** // doc: test__create_kernels_in_program() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_SUCCESS, nullptr, nullptr);
    TS_ASSERT_THROWS_NOTHING(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr));
    TS_ASSERT(mock.called_once_with((cl_program)NULL,0,nullptr,nullptr));
  }
  /** // doc: test__create_kernels_in_program__invalid_program() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_program( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_PROGRAM, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__create_kernels_in_program__invalid_program_executable() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_program_executable( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_PROGRAM_EXECUTABLE, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test__create_kernels_in_program__invalid_value() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__invalid_value( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_INVALID_VALUE, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_kernels_in_program__out_of_resources() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__out_of_resources( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_OUT_OF_RESOURCES, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_kernels_in_program__out_of_host_memory() {{{
   * \brief Test create_kernels_in_program() in a normal situation.
   */ // }}}
  void test__create_kernels_in_program__out_of_host_memory( )
  {
    T::Dummy_clCreateKernelsInProgram mock(CL_OUT_OF_HOST_MEMORY, nullptr, nullptr);
    TS_ASSERT_THROWS(create_kernels_in_program((cl_program)NULL,0,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_KERNELS_IN_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
