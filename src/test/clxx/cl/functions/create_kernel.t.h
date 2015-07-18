// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_kernel.t.h

/** // doc: clxx/cl/functions/create_kernel.t.h {{{
 * \file clxx/cl/functions/create_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_KERNEL_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_kernel_test_suite; }

/** // doc: class clxx::functions_create_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_kernel_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_kernel() {{{
   * \brief Test create_kernel() in a normal situation.
   */ // }}}
  void test__create_kernel( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_kernel(nullptr,"mykernel"));
    TS_ASSERT(mock.called_once());
    TS_ASSERT(clxx::create_kernel(nullptr,0) == (cl_kernel)0x1234);
  }
  /** // doc: test__create_kernel__invalid_program() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_PROGRAM.
   */ // }}}
  void test__create_kernel__invalid_program( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__create_kernel__invalid_program_executable() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_PROGRAM_EXECUTABLE.
   */ // }}}
  void test__create_kernel__invalid_program_executable( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test__create_kernel__invalid_kernel_name() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_KERNEL_NAME.
   */ // }}}
  void test__create_kernel__invalid_kernel_name( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_KERNEL_NAME);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_kernel_name>);
  }
  /** // doc: test__create_kernel__invalid_kernel_definition() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_KERNEL_DEFINITION.
   */ // }}}
  void test__create_kernel__invalid_kernel_definition( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_KERNEL_DEFINITION);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_kernel_definition>);
  }
  /** // doc: test__create_kernel__invalid_value() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_kernel__invalid_value( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_kernel__out_of_resources() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_kernel__out_of_resources( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_kernel__out_of_host_memory() {{{
   * \brief Test create_kernel() in a situation when clCreateKernel() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_kernel__out_of_host_memory( )
  {
    T::Dummy_clCreateKernel mock((cl_kernel)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_kernel(nullptr,"mykernel"), clerror_no<status_t::out_of_host_memory>);
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
