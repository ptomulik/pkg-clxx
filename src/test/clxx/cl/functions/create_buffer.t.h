// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_buffer.t.h

/** // doc: clxx/cl/functions/create_buffer.t.h {{{
 * \file clxx/cl/functions/create_buffer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_BUFFER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_BUFFER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_buffer_test_suite; }

/** // doc: class clxx::functions_create_buffer_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_buffer_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_buffer()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_buffer() {{{
   * \brief Test create_buffer() in a normal situation.
   */ // }}}
  void test__create_buffer( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)0x1234, CL_SUCCESS);
    TS_ASSERT(create_buffer((cl_context)0x7654, mem_flags_t::read_write, 123ul, (void*)0x4567) == (cl_mem)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_mem_flags)CL_MEM_READ_WRITE)
    TS_ASSERT(std::get<2>(mock.calls().back()) == 123ul)
    TS_ASSERT(std::get<3>(mock.calls().back()) == (void*)0x4567)
  }
  /** // doc: test__create_buffer__invalid_context() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_buffer__invalid_context( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__create_buffer__invalid_value() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_buffer__invalid_value( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_buffer__invalid_buffer_size() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_buffer__invalid_buffer_size( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, CL_INVALID_BUFFER_SIZE);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), clerror_no<status_t::invalid_buffer_size>);
  }
  /** // doc: test__create_buffer__invalid_host_ptr() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_INVALID_HOST_PTR.
   */ // }}}
  void test__create_buffer__invalid_host_ptr( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, CL_INVALID_HOST_PTR);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), clerror_no<status_t::invalid_host_ptr>);
  }
  /** // doc: test__create_buffer__mem_object_allocation_failure() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_MEM_OBJECT_ALLOCATION_FAILURE.
   */ // }}}
  void test__create_buffer__mem_object_allocation_failure( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
  }
  /** // doc: test__create_buffer__out_of_resources() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_buffer__out_of_resources( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_buffer__out_of_host_memory() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_buffer__out_of_host_memory( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_buffer__unexpected_clerror() {{{
   * \brief Test create_buffer() in a situation when clCreateBuffer() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_buffer__unexpected_clerror( )
  {
    T::Dummy_clCreateBuffer mock((cl_mem)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_buffer((cl_context)0,mem_flags_t::read_write,0ul,nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_BUFFER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
