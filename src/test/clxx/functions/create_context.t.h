// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/create_context.t.h

/** // doc: clxx/functions/create_context.t.h {{{
 * \file clxx/functions/create_context.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_CREATE_CONTEXT_T_H_INCLUDED
#define CLXX_FUNCTIONS_CREATE_CONTEXT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_create_context_test_suite; }

/** // doc: class clxx::functions_create_context_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_create_context_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  create_context()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_context() {{{
   * \brief Test create_context() in a normal situation.
   */ // }}}
  void test__create_context( )
  {
    T::Dummy_clCreateContext mock((cl_context)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr));
    //TS_ASSERT(mock.called_once_with(nullptr,0,nullptr,nullptr,nullptr,??? - local variable within create_context(...){...}));
  }
  /** // doc: test__create_context__invalid_platform() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PLATFORM.
   */ // }}}
  void test__create_context__invalid_platform( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_platform>);
  }
  /** // doc: test__create_context__invalid_property() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_PROPERTY.
   */ // }}}
  void test__create_context__invalid_property( )
  {
#if CLXX_CL_H_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_PROPERTY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_property>);
#endif
  }
  /** // doc: test__create_context__invalid_operation() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_OPERATION.
   */ // }}}
  void test__create_context__invalid_operation( )
  {
#if CLXX_CL_H_VERSION_1_1
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_operation>);
#endif
  }
  /** // doc: test__create_context__invalid_value() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_context__invalid_value( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__create_context__invalid_device() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_INVALID_DEVICE.
   */ // }}}
  void test__create_context__invalid_device( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::invalid_device>);
  }
  /** // doc: test__create_context__device_not_available() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_context__device_not_available( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::device_not_available>);
  }
  /** // doc: test__create_context__out_of_resources() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_context__out_of_resources( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__create_context__out_of_host_memory() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_context__out_of_host_memory( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__create_context__other_error() {{{
   * \brief Test create_context() in a situation when clCreateContext() returns an unexpected error code.
   */ // }}}
  void test__create_context__other_error( )
  {
    T::Dummy_clCreateContext mock((cl_context)NULL, -0x3456);
    TS_ASSERT_THROWS(clxx::create_context(nullptr,0,nullptr,nullptr,nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_CREATE_CONTEXT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
