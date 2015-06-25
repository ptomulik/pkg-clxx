// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions/flush.t.h

/** // doc: clxx/functions/flush.t.h {{{
 * \file clxx/functions/flush.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_FUNCTIONS_FLUSH_T_H_INCLUDED
#define CLXX_FUNCTIONS_FLUSH_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_flush_test_suite; }

/** // doc: class clxx::functions_flush_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_flush_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  flush()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__flush() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush( )
  {
    T::Dummy_clFlush mock(CL_SUCCESS);
    flush                          ((cl_command_queue)0x344);
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x344));
  }
  /** // doc: test__flush__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__invalid_command_queue( )
  {
    T::Dummy_clFlush mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL),clerror_no<status_t::invalid_command_queue>);
  }
  /** // doc: test__flush__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__out_of_resources( )
  {
    T::Dummy_clFlush mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL),clerror_no<status_t::out_of_resources>);
  }
  /** // doc: test__flush__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__out_of_host_memory( )
  {
    T::Dummy_clFlush mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL),clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test__flush__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__unexpected_clerror( )
  {
    T::Dummy_clFlush mock(-0x1234567);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL), unexpected_clerror);
  }
};

#endif /* CLXX_FUNCTIONS_FLUSH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
