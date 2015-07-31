// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/sha1.t.h

/** // doc: clxx/common/sha1.t.h {{{
 * \file clxx/common/sha1.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_SHA1_T_H_INCLUDED
#define CLXX_COMMON_SHA1_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/sha1.hpp>

namespace clxx { class sha1_test_suite; }

/** // doc: class clxx::sha1_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::sha1_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__sha1__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__sha1__1( )
  {
    clxx::sha1 sha1;
    sha1.process_bytes("abc", 3);

    uint32_t digest[5];
    sha1.get_digest(digest);
    TS_ASSERT_EQUALS(digest[0], 0xA9993E36);
    TS_ASSERT_EQUALS(digest[1], 0x4706816A);
    TS_ASSERT_EQUALS(digest[2], 0xBA3E2571);
    TS_ASSERT_EQUALS(digest[3], 0x7850C26C);
    TS_ASSERT_EQUALS(digest[4], 0x9CD0D89D);
  }
  /** // doc: test__sha1__bytes__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__sha1__bytes__1( )
  {
    clxx::sha1 sha1;
    sha1.process_bytes("abc", 3);

    uint8_t digest[20];
    sha1.get_digest(digest);
    TS_ASSERT_EQUALS(digest[0],  0xA9);
    TS_ASSERT_EQUALS(digest[1],  0x99);
    TS_ASSERT_EQUALS(digest[2],  0x3E);
    TS_ASSERT_EQUALS(digest[3],  0x36);
    TS_ASSERT_EQUALS(digest[4],  0x47);
    TS_ASSERT_EQUALS(digest[5],  0x06);
    TS_ASSERT_EQUALS(digest[6],  0x81);
    TS_ASSERT_EQUALS(digest[7],  0x6A);
    TS_ASSERT_EQUALS(digest[8],  0xBA);
    TS_ASSERT_EQUALS(digest[9],  0x3E);
    TS_ASSERT_EQUALS(digest[10], 0x25);
    TS_ASSERT_EQUALS(digest[11], 0x71);
    TS_ASSERT_EQUALS(digest[12], 0x78);
    TS_ASSERT_EQUALS(digest[13], 0x50);
    TS_ASSERT_EQUALS(digest[14], 0xC2);
    TS_ASSERT_EQUALS(digest[15], 0x6C);
    TS_ASSERT_EQUALS(digest[16], 0x9C);
    TS_ASSERT_EQUALS(digest[17], 0xD0);
    TS_ASSERT_EQUALS(digest[18], 0xD8);
    TS_ASSERT_EQUALS(digest[19], 0x9D);
  }
  /** // doc: test__sha1__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__sha1__2( )
  {
    clxx::sha1 sha1;
    sha1.process_bytes("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq", 56);

    uint32_t digest[5];
    sha1.get_digest(digest);
    TS_ASSERT_EQUALS(digest[0], 0x84983E44);
    TS_ASSERT_EQUALS(digest[1], 0x1C3BD26E);
    TS_ASSERT_EQUALS(digest[2], 0xBAAE4AA1);
    TS_ASSERT_EQUALS(digest[3], 0xF95129E5);
    TS_ASSERT_EQUALS(digest[4], 0xE54670F1);
  }
  /** // doc: test__sha1__bytes__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__sha1__bytes__2( )
  {
    clxx::sha1 sha1;
    sha1.process_bytes("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq", 56);

    uint8_t digest[20];
    sha1.get_digest(digest);
    TS_ASSERT_EQUALS(digest[0],  0x84);
    TS_ASSERT_EQUALS(digest[1],  0x98);
    TS_ASSERT_EQUALS(digest[2],  0x3E);
    TS_ASSERT_EQUALS(digest[3],  0x44);
    TS_ASSERT_EQUALS(digest[4],  0x1C);
    TS_ASSERT_EQUALS(digest[5],  0x3B);
    TS_ASSERT_EQUALS(digest[6],  0xD2);
    TS_ASSERT_EQUALS(digest[7],  0x6E);
    TS_ASSERT_EQUALS(digest[8],  0xBA);
    TS_ASSERT_EQUALS(digest[9],  0xAE);
    TS_ASSERT_EQUALS(digest[10], 0x4A);
    TS_ASSERT_EQUALS(digest[11], 0xA1);
    TS_ASSERT_EQUALS(digest[12], 0xF9);
    TS_ASSERT_EQUALS(digest[13], 0x51);
    TS_ASSERT_EQUALS(digest[14], 0x29);
    TS_ASSERT_EQUALS(digest[15], 0xE5);
    TS_ASSERT_EQUALS(digest[16], 0xE5);
    TS_ASSERT_EQUALS(digest[17], 0x46);
    TS_ASSERT_EQUALS(digest[18], 0x70);
    TS_ASSERT_EQUALS(digest[19], 0xF1);
  }
  /** // doc: test__sha1__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__sha1__3( )
  {
    clxx::sha1 sha1;
    uint32_t digest[5];
    for(size_t i = 0; i < 1000000; i++)
      {
        sha1.process_byte('a');
      }
    sha1.get_digest(digest);
    TS_ASSERT_EQUALS(digest[0], 0x34AA973C);
    TS_ASSERT_EQUALS(digest[1], 0xD4C4DAA4);
    TS_ASSERT_EQUALS(digest[2], 0xF61EEB2B);
    TS_ASSERT_EQUALS(digest[3], 0xDBAD2731);
    TS_ASSERT_EQUALS(digest[4], 0x6534016F);
  }
  /** // doc: test__sha1str__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__sha1str__1( )
  {
    TS_ASSERT_EQUALS(sha1str("abc"), "A9993E364706816ABA3E25717850C26C9CD0D89D");
  }
};

#endif /* CLXX_COMMON_SHA1_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
