// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/exception.t.h

/** // doc: clxx/exception.t.h {{{
 * \file clxx/exception.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_EXCEPTION_T_H_INCLUDED
#define CLXX_EXCEPTION_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/exception.hpp>
#include <stdexcept>

namespace clxx { class exception_test; }

/** // doc: class clxx::exception_test {{{
 * \todo Write documentation
 */ // }}}
class clxx::exception_test : public CxxTest::TestSuite
{
public:
  /** // doc: test_exception1() {{{
   * \brief Ensure that we can derive new exceptions from clxx::exception
   */ // }}}
  void test_exception1( )
  {
    struct exception1
      : public clxx::exception,
        public std::exception
    {
      exception1() : clxx::exception(), std::exception() { }
      exception1(exception1 const& e) : clxx::exception(e), std::exception(e) { }
      virtual std::exception const& clxx2std() const noexcept { return *this; }
      virtual const char* what() const noexcept { return "exception1"; }
    };
    TS_ASSERT_EQUALS(exception1().what(), "exception1");
    TS_ASSERT_THROWS(throw exception1(), std::exception const&);
    TS_ASSERT_THROWS(throw exception1(), clxx::exception const&);
    TS_ASSERT_THROWS(throw exception1(), exception1 const&);
  }
  /** // doc: test_exception2() {{{
   * \brief Ensure that we can derive new exceptions from clxx::exception
   */ // }}}
  void test_exception2( )
  {
    struct exception2
      : public clxx::exception,
        public std::runtime_error
    {
      exception2() : clxx::exception(), std::runtime_error("exception2") { }
      exception2(exception2 const& e) : clxx::exception(e), std::runtime_error(e) { }
      virtual std::exception const& clxx2std() const noexcept { return *this; }
    };
    TS_ASSERT_EQUALS(exception2().what(), "exception2");
    TS_ASSERT_THROWS(throw exception2(), std::exception const&);
    TS_ASSERT_THROWS(throw exception2(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw exception2(), clxx::exception const&);
    TS_ASSERT_THROWS(throw exception2(), exception2 const&);
  }
};

#endif /* CLXX_EXCEPTION_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
