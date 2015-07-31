// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/enum2hex.t.h

/** // doc: clxx/enum2hex.t.h {{{
 * \file clxx/enum2hex.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_ENUM2HEX_T_H_INCLUDED
#define CLXX_COMMON_ENUM2HEX_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/enum2hex.hpp>

namespace clxx { class enum2hex_test_suite; }

/** // doc: class clxx::enum2hex_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enum2hex_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_enum_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_char( )
  {
    enum class test_t : char { zero = 0x00, plus = 0x12, minus = -0x12 };
    TS_ASSERT_EQUALS(enum2hex(test_t::zero), "0x00");
    TS_ASSERT_EQUALS(enum2hex(test_t::plus), "0x12");
    TS_ASSERT_EQUALS(enum2hex(test_t::minus), "-0x12");
  }
  /** // doc: test_enum_unsigned_char() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_unsigned_char( )
  {
    enum class test_t : unsigned char { number = 0xff };
    TS_ASSERT_EQUALS(enum2hex(test_t::number), "0xff");
  }
  /** // doc: test_enum_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_short( )
  {
    enum class test_t : short { zero = 0x00, plus = 0x12, minus = -0x12 };
    TS_ASSERT_EQUALS(enum2hex(test_t::zero), "0x0000");
    TS_ASSERT_EQUALS(enum2hex(test_t::plus), "0x0012");
    TS_ASSERT_EQUALS(enum2hex(test_t::minus), "-0x0012");
  }
  /** // doc: test_enum_unsigned_short() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_unsigned_short( )
  {
    enum class test_t : unsigned short { number = 0xffff };
    TS_ASSERT_EQUALS(enum2hex(test_t::number), "0xffff");
  }
  /** // doc: test_enum_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_long( )
  {
    enum class test_t : long { zero = 0x00, plus = 0x12, minus = -0x12 };
    TS_ASSERT_EQUALS(enum2hex(test_t::zero), "0x0000000000000000");
    TS_ASSERT_EQUALS(enum2hex(test_t::plus), "0x0000000000000012");
    TS_ASSERT_EQUALS(enum2hex(test_t::minus), "-0x0000000000000012");
  }
  /** // doc: test_enum_unsigned_long() {{{
   * \todo Write documentation
   */ // }}}
  void test_enum_unsigned_long( )
  {
    enum class test_t : unsigned long { number = 0xffffffffffffffff };
    TS_ASSERT_EQUALS(enum2hex(test_t::number), "0xffffffffffffffff");
  }
};

#endif /* CLXX_COMMON_ENUM2HEX_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
