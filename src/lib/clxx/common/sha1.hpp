// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/sha1.hpp

/** // doc: clxx/common/sha1.hpp {{{
 * \file clxx/common/sha1.hpp
 * \brief Header only c++11 implementation of the SHA-1 algorithm
 */ // }}}
#ifndef CLXX_COMMON_SHA1_HPP_INCLUDED
#define CLXX_COMMON_SHA1_HPP_INCLUDED

#include <cstdint>
#include <string>

namespace clxx {
/** // doc: sha1 {{{
 * \ingroup clxx_util
 * \todo Write documentation
 */ // }}}
class sha1
{
public:
  /** // doc: digest32_t {{{
   * \todo Write documentation
   */ // }}}
  typedef uint32_t(&digest32_t)[5];
  /** // doc: digest8_t {{{
   * \todo Write documentation
   */ // }}}
  typedef uint8_t(&digest8_t)[20];
public:
  /** // doc: left_rotate {{{
   * \todo Write documentation
   */ // }}}
  inline static int left_rotate(uint32_t x, size_t n)
  { return (x<<n) ^ (x>>(32-n)); }
public:
  /** // doc: sha1 {{{
   * \todo Write documentation
   */ // }}}
  sha1()
  {
    reset();
  }
  /** // doc: reset() {{{
   * \todo Write documentation
   */ // }}}
  inline void reset()
  {
    _h[0] = 0x67452301;
    _h[1] = 0xEFCDAB89;
    _h[2] = 0x98BADCFE;
    _h[3] = 0x10325476;
    _h[4] = 0xC3D2E1F0;

    _block_byte_index = 0;
    _bit_cnt_lo = 0;
    _bit_cnt_hi = 0;
  }
  /** // doc: process_byte() {{{
   * \todo Write documentation
   */ // }}}
  inline void process_byte(uint8_t b)
  {
    process_byte_impl(b);
    if(_bit_cnt_lo < 0xFFFFFFF8)
      {
        _bit_cnt_lo += 8;
      }
    else
      {
        _bit_cnt_lo = 0;
        if(_bit_cnt_hi <= 0xFFFFFFFE)
          {
            ++_bit_cnt_hi;
          }
        else
          {
            throw std::runtime_error("sha1 too many bytes");
          }
      }
  }
  /** // doc: process_block() {{{
   * \todo Write documentation
   */ // }}}
  inline void process_block(void const* bytes_begin, void const* bytes_end)
  {
    uint8_t const* begin = static_cast<uint8_t const*>(bytes_begin);
    uint8_t const* end = static_cast<uint8_t const*>(bytes_end);
    for(; begin != end; ++begin)
      {
        process_byte(*begin);
      }
  }
  /** // doc: process_bytes() {{{
   * \todo Write documentation
   */ // }}}
  inline void process_bytes(void const* buffer, size_t byte_count)
  {
    uint8_t const* b = static_cast<uint8_t const*>(buffer);
    process_block(b, b + byte_count);
  }
  /** // doc: get_digest() {{{
   * \todo Write documentation
   */ // }}}
  inline void get_digest(digest32_t digest)
  {
    // append the bit '1' to the message
    process_byte_impl(0x80);

    // append k bits '0', where k is the minimum number >= 0
    // such that the resulting message length is congruent to 56 (mod 64)
    // check if there is enough space for padding and bit_count
    if (_block_byte_index > 56) {
        // finish this block
        while (_block_byte_index != 0) {
            process_byte_impl(0);
        }

        // one more block
        while (_block_byte_index < 56) {
            process_byte_impl(0);
        }
    } else {
        while (_block_byte_index < 56) {
            process_byte_impl(0);
        }
    }

    // append length of message (before pre-processing) 
    // as a 64-bit big-endian integer
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_hi>>24) & 0xFF) );
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_hi>>16) & 0xFF) );
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_hi>>8 ) & 0xFF) );
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_hi)     & 0xFF) );
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_lo>>24) & 0xFF) );
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_lo>>16) & 0xFF) );
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_lo>>8 ) & 0xFF) );
    process_byte_impl( static_cast<uint8_t>((_bit_cnt_lo)     & 0xFF) );

    // get final digest
    digest[0] = _h[0];
    digest[1] = _h[1];
    digest[2] = _h[2];
    digest[3] = _h[3];
    digest[4] = _h[4];
  }
  /** // doc: get_digest() {{{
   * \todo Write documentation
   */ // }}}
  inline void get_digest(digest8_t digest)
  {
    uint32_t d32[5];
    get_digest(d32);
    size_t di = 0;

    digest[di++] = static_cast<uint8_t>((d32[0] >> 24) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[0] >> 16) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[0] >>  8) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[0])       & 0xFF);

    digest[di++] = static_cast<uint8_t>((d32[1] >> 24) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[1] >> 16) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[1] >>  8) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[1])       & 0xFF);

    digest[di++] = static_cast<uint8_t>((d32[2] >> 24) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[2] >> 16) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[2] >>  8) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[2])       & 0xFF);

    digest[di++] = static_cast<uint8_t>((d32[3] >> 24) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[3] >> 16) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[3] >>  8) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[3])       & 0xFF);

    digest[di++] = static_cast<uint8_t>((d32[4] >> 24) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[4] >> 16) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[4] >>  8) & 0xFF);
    digest[di++] = static_cast<uint8_t>((d32[4])       & 0xFF);
  }
private:
  inline void process_byte_impl(uint8_t b)
  {
    _block[_block_byte_index++] = b;
    if(_block_byte_index == 64)
      {
        _block_byte_index = 0;
        process_block();
      }
  }
  inline void process_block()
  {
    uint32_t w[80];
    for (size_t i=0; i<16; ++i) {
        w[i]  = (_block[i*4 + 0] << 24);
        w[i] |= (_block[i*4 + 1] << 16);
        w[i] |= (_block[i*4 + 2] << 8);
        w[i] |= (_block[i*4 + 3]);
    }
    for (size_t i=16; i<80; ++i) {
        w[i] = left_rotate((w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16]), 1);
    }

    uint32_t a = _h[0];
    uint32_t b = _h[1];
    uint32_t c = _h[2];
    uint32_t d = _h[3];
    uint32_t e = _h[4];

    for (size_t i=0; i<80; ++i) {
        uint32_t f;
        uint32_t k;

        if (i<20) {
            f = (b & c) | (~b & d);
            k = 0x5A827999;
        } else if (i<40) {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        } else if (i<60) {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        } else {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }

        unsigned temp = left_rotate(a, 5) + f + e + k + w[i];
        e = d;
        d = c;
        c = left_rotate(b, 30);
        b = a;
        a = temp;
    }

    _h[0] += a;
    _h[1] += b;
    _h[2] += c;
    _h[3] += d;
    _h[4] += e;
  }
private:
  uint32_t  _h[5];
  uint8_t   _block[64];
  size_t _block_byte_index;
  size_t _bit_cnt_lo;
  size_t _bit_cnt_hi;;
};
/** // doc: {{{
 * \todo Write documentation
 */ // }}}
inline std::string sha1str(std::string const& str)
{
  clxx::sha1 sha1;
  sha1.process_bytes(str.data(), str.size());

  uint8_t digest[20];
  sha1.get_digest(digest);

  std::string s(40,'0');
  for(size_t i = 0; i < 20; ++i)
    {
      char hi = static_cast<char>((digest[i] >> 4)& 0x0F);
      char lo = static_cast<char>((digest[i])     & 0x0F);
      s[0 + 2*i] = (hi < 0xA) ? ('0' + hi) : ('A' + (hi - 0xA));
      s[1 + 2*i] = (lo < 0xA) ? ('0' + lo) : ('A' + (lo - 0xA));
    }
  return s;
}
} // end namespace clxx

#endif /* CLXX_COMMON_SHA1_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
