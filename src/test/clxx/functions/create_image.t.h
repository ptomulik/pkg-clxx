// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/create_image.t.h

/** // doc: clxx/functions/create_image.t.h {{{
 * \file clxx/functions/create_image.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_CREATE_IMAGE_T_H_INCLUDED
#define CLXX_FUNCTIONS_CREATE_IMAGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_image_test_suite; }

/** // doc: class clxx::functions_create_image_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_image_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_image()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_image() {{{
   * \brief Test create_image() in a normal situation.
   */ // }}}
  void test__create_image( )
  {
    T::Dummy_clCreateImage mock((cl_mem)0x1234, CL_SUCCESS);
    TS_ASSERT(create_image((cl_context)0x7654, mem_flags_t::read_write, (const cl_image_format*)0x4567, (const cl_image_desc*)0x8901, (void*)0x2345) == (cl_mem)0x1234);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x7654)
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_mem_flags)CL_MEM_READ_WRITE)
    TS_ASSERT(std::get<2>(mock.calls().back()) == (const cl_image_format*)0x4567)
    TS_ASSERT(std::get<3>(mock.calls().back()) == (const cl_image_desc*)0x8901)
    TS_ASSERT(std::get<4>(mock.calls().back()) == (void*)0x2345)
    TS_ASSERT(std::get<5>(mock.calls().back()) != nullptr)
  }
  /** // doc: test__create_image__invalid_context() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_image__invalid_context( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr, nullptr), clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__create_image__invalid_value() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_image__invalid_value( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_image__invalid_image_format_descriptor() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_image__invalid_image_format_descriptor( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_image_format_descriptor>);
  }
  /** // doc: test__create_image__invalid_image_descriptor() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_image__invalid_image_descriptor( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_INVALID_IMAGE_DESCRIPTOR);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_image_descriptor>);
  }
  /** // doc: test__create_image__invalid_image_size() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_image__invalid_image_size( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_image_size>);
  }
  /** // doc: test__create_image__invalid_host_ptr() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_HOST_PTR.
   */ // }}}
  void test__create_image__invalid_host_ptr( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_INVALID_HOST_PTR);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_host_ptr>);
  }
  /** // doc: test__create_image__image_format_not_supported() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_BUFFER_SIZE.
   */ // }}}
  void test__create_image__image_format_not_supported( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::image_format_not_supported>);
  }
  /** // doc: test__create_image__mem_object_allocation_failure() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_MEM_OBJECT_ALLOCATION_FAILURE.
   */ // }}}
  void test__create_image__mem_object_allocation_failure( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
  }
  /** // doc: test__create_image__invalid_operation() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_image__invalid_operation( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_operation>);
  }
  /** // doc: test__create_image__out_of_resources() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_image__out_of_resources( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_image__out_of_host_memory() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_image__out_of_host_memory( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_image__unexpected_clerror() {{{
   * \brief Test create_image() in a situation when clCreateImage() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_image__unexpected_clerror( )
  {
    T::Dummy_clCreateImage mock((cl_mem)NULL, -0x1234567);
    TS_ASSERT_THROWS(create_image((cl_context)0,mem_flags_t::read_write,nullptr,nullptr,nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_CREATE_IMAGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
