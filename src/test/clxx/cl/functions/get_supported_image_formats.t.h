// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/get_supported_image_formats.t.h

/** // doc: clxx/cl/functions/get_supported_image_formats.t.h {{{
 * \file clxx/cl/functions/get_supported_image_formats.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_GET_SUPPORTED_IMAGE_FORMATS_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_GET_SUPPORTED_IMAGE_FORMATS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_supported_image_formats_test_suite; }

/** // doc: class clxx::functions_get_supported_image_formats_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_supported_image_formats_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_supported_image_formats()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_supported_image_formats() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_supported_image_formats( )
  {
    T::Dummy_clGetSupportedImageFormats mock(CL_SUCCESS);
    get_supported_image_formats    ((cl_context)0x395, mem_flags_t::read_write,         mem_object_type_t::image2d,                123, (cl_image_format*)0x7654, (cl_uint*)0x321);
    TS_ASSERT(mock.called_once_with((cl_context)0x395, (cl_mem_flags)CL_MEM_READ_WRITE, (cl_mem_object_type)CL_MEM_OBJECT_IMAGE2D, 123, (cl_image_format*)0x7654, (cl_uint*)0x321));
  }
  /** // doc: test__get_supported_image_formats__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_supported_image_formats__invalid_context( )
  {
    T::Dummy_clGetSupportedImageFormats mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(get_supported_image_formats((cl_context)NULL, mem_flags_t::read_write, mem_object_type_t::image2d, 0, nullptr, nullptr),clerror_no<status_t::invalid_context>);
  }
  /** // doc: test__get_supported_image_formats__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_supported_image_formats__invalid_value( )
  {
    T::Dummy_clGetSupportedImageFormats mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_supported_image_formats((cl_context)NULL, mem_flags_t::read_write, mem_object_type_t::image2d, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_supported_image_formats__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_supported_image_formats__out_of_resources( )
  {
    T::Dummy_clGetSupportedImageFormats mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_supported_image_formats((cl_context)NULL, mem_flags_t::read_write, mem_object_type_t::image2d, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_supported_image_formats__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_supported_image_formats__out_of_host_memory( )
  {
    T::Dummy_clGetSupportedImageFormats mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_supported_image_formats((cl_context)NULL, mem_flags_t::read_write, mem_object_type_t::image2d, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_supported_image_formats__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_supported_image_formats__unexpected_clerror( )
  {
    T::Dummy_clGetSupportedImageFormats mock(-0x1234567);
    TS_ASSERT_THROWS(get_supported_image_formats((cl_context)NULL, mem_flags_t::read_write, mem_object_type_t::image2d, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_GET_SUPPORTED_IMAGE_FORMATS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
