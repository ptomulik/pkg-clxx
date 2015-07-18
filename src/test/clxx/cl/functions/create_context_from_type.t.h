// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/create_context.t.h

/** // doc: clxx/cl/functions/create_context_from_type.t.h {{{
 * \file clxx/cl/functions/create_context_from_type.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_CREATE_CONTEXT_FROM_TYPE_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_CREATE_CONTEXT_FROM_TYPE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_context_from_type_test_suite; }

/** // doc: class clxx::functions_create_context_from_type_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_context_from_type_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_context_from_type()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_context_from_type() {{{
   * \brief Test create_context_from_type().
   */ // }}}
  void test__create_context_from_type( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr));
  }
  /** // doc: test__create_context_from_type__invalid_platform() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test__create_context_from_type__invalid_platform( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__create_context_from_type__invalid_property() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test__create_context_from_type__invalid_property( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_property>);
  }
  /** // doc: test__create_context_from_type__invalid_value() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_context_from_type__invalid_value( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_context_from_type__invalid_device_type() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_INVALID_DEVICE_TYPE.
   */ // }}}
  void test__create_context_from_type__invalid_device_type( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::invalid_device_type>);
  }
  /** // doc: test__create_context_from_type__device_not_available() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_context_from_type__device_not_available( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test__create_context_from_type__out_of_resources() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_context_from_type__out_of_resources( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_context_from_type__out_of_host_memory() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_context_from_type__out_of_host_memory( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_context_from_type__other_error() {{{
   * \brief Test create_context_from_type() in a situation when clCreateContextFromType() returns an unexpected error code.
   */ // }}}
  void test__create_context_from_type__other_error( )
  {
    T::Dummy_clCreateContextFromType mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context_from_type(nullptr,device_type_t::all,nullptr,nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_CL_FUNCTIONS_CREATE_CONTEXT_FROM_TYPE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
