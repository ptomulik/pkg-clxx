// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/link_program.t.h

/** // doc: clxx/cl/functions/link_program.t.h {{{
 * \file clxx/cl/functions/link_program.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_LINK_PROGRAM_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_LINK_PROGRAM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_link_program_test_suite; }

/** // doc: class clxx::functions_link_program_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_link_program_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  link_program()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__link_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)0x1234, CL_SUCCESS);
    link_program                   ((cl_context)0x539, 6, (cl_device_id*)0x195, (const char*)0x542, 9, (const cl_program*)0x532, (void(*)(cl_program, void*))0x253, (void*)0x837);
    TS_ASSERT(mock.called_once());
    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_context)0x539);
    TS_ASSERT(std::get<1>(mock.calls().back()) == 6);
    TS_ASSERT(std::get<2>(mock.calls().back()) == (cl_device_id*)0x195);
    TS_ASSERT(std::get<3>(mock.calls().back()) == (const char*)0x542);
    TS_ASSERT(std::get<4>(mock.calls().back()) == 9);
    TS_ASSERT(std::get<5>(mock.calls().back()) == (const cl_program*)0x532);
    TS_ASSERT(std::get<6>(mock.calls().back()) == (void(*)(cl_program,void*))0x253);
    TS_ASSERT(std::get<7>(mock.calls().back()) == (void*)0x837);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_context( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_context>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_program( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_PROGRAM);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_program>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_value( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_value>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_device>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_linker_options() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_linker_options( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_LINKER_OPTIONS);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_linker_options>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__invalid_operation( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::invalid_operation>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__linker_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__linker_not_available( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_LINKER_NOT_AVAILABLE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::linker_not_available>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__link_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__link_program_failure( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_LINK_PROGRAM_FAILURE);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::link_program_failure>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_resources>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr),clerror_no<status_t::out_of_host_memory>);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
  /** // doc: test__link_program__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__link_program__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
    T::Dummy_clLinkProgram mock((cl_program)NULL, -0x1234567);
    TS_ASSERT_THROWS(link_program((cl_context)NULL, 0, nullptr, nullptr, 0, nullptr, nullptr, nullptr), unexpected_clerror);
#endif //  CLXX_OPENCL_ALLOWED(clLinkProgram)
  }
};

#endif /* CLXX_CL_FUNCTIONS_LINK_PROGRAM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
