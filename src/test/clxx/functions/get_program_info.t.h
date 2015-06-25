// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/get_program_info.t.h

/** // doc: clxx/functions/get_program_info.t.h {{{
 * \file clxx/functions/get_program_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_GET_PROGRAM_INFO_T_H_INCLUDED
#define CLXX_FUNCTIONS_GET_PROGRAM_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_get_program_info_test_suite; }

/** // doc: class clxx::functions_get_program_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_get_program_info_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  get_program_info()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__get_program_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info( )
  {
    T::Dummy_clGetProgramInfo mock(CL_SUCCESS);
    get_program_info               ((cl_program)0x395, program_info_t::reference_count,             5, (void*)0x124, (size_t*)0x934);
    TS_ASSERT(mock.called_once_with((cl_program)0x395, (cl_program_info)CL_PROGRAM_REFERENCE_COUNT, 5, (void*)0x124, (size_t*)0x934));
  }
  /** // doc: test__get_program_info__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__invalid_value( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_value>);
  }
  /** // doc: test__get_program_info__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__invalid_program( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_program>);
  }
  /** // doc: test__get_program_info__invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__invalid_program_executable( )
  {
    T::Dummy_clGetProgramInfo mock(CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::invalid_program_executable>);
  }
  /** // doc: test__get_program_info__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__out_of_resources( )
  {
    T::Dummy_clGetProgramInfo mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__get_program_info__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__out_of_host_memory( )
  {
    T::Dummy_clGetProgramInfo mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__get_program_info__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program_info__unexpected_clerror( )
  {
    T::Dummy_clGetProgramInfo mock(-0x1234567);
    TS_ASSERT_THROWS(get_program_info((cl_program)NULL, program_info_t::reference_count, 0, nullptr, nullptr), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_GET_PROGRAM_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
