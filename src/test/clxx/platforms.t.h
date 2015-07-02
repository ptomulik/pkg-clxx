// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platforms.t.h

/** // doc: clxx/platforms.t.h {{{
 * \file clxx/platforms.t.h
 * \brief Unit tests for clxx/platforms.hpp
 */ // }}}
#ifndef CLXX_CL_PLATFORMS_T_H_INCLUDED
#define CLXX_CL_PLATFORMS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/platforms.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class Platforms_TestSuite; }

/** // doc: class Platforms_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class clxx::Platforms_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_get_num_platforms_1() {{{
   * \brief Test get_num_platforms()
   */ // }}}
  void test_get_num_platforms( )
  {
    cl_platform_id _platforms[] = { (cl_platform_id)0x1234, (cl_platform_id)0x5678 };
    cl_uint _num_platforms = 2;
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS, _platforms, &_num_platforms);

    TS_ASSERT_EQUALS(get_num_platforms(), 2);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), 0u);
    TS_ASSERT(std::get<1>(mock.calls().back()) == nullptr);
    TS_ASSERT(std::get<2>(mock.calls().back()) != nullptr);
  }
  /** // doc: test_get_platform_ids() {{{
   * \brief Test get_platform_ids()
   */ // }}}
  void test_get_platform_ids( )
  {
    cl_platform_id _platforms[] = { (cl_platform_id)0x1234, (cl_platform_id)0x5678 };
    cl_uint _num_platforms = 2;
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS, _platforms, &_num_platforms);

    std::vector<cl_platform_id> ids(get_platform_ids());
    TS_ASSERT_EQUALS(ids.size(), 2);
    TS_ASSERT_EQUALS(ids[0], _platforms[0]);
    TS_ASSERT_EQUALS(ids[1], _platforms[1]);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<1>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<2>(mock.calls().front()) != nullptr);
    //
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<2>(mock.calls().back()) == nullptr);
  }
//  /** // doc: test_get_platforms() {{{
//   * \brief Test get_platforms()
//   */ // }}}
  void test_get_platforms( )
  {
    cl_platform_id _platforms[] = { (cl_platform_id)0x1234, (cl_platform_id)0x5678 };
    cl_uint _num_platforms = 2;
    T::Dummy_clGetPlatformIDs mock(CL_SUCCESS, _platforms, &_num_platforms);

    platforms p(get_platforms());
    TS_ASSERT_EQUALS(p.size(), 2);
    TS_ASSERT_EQUALS(p[0].handle(), _platforms[0]);
    TS_ASSERT_EQUALS(p[1].handle(), _platforms[1]);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<1>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<2>(mock.calls().front()) != nullptr);
    //
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<2>(mock.calls().back()) == nullptr);
  }
  /** // doc: test_invalid_value() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        status_t::invalid_value.
   */ // }}}
  void test_invalid_value( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_num_platforms(), clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_platform_ids(), clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_platforms(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        status_t::out_of_host_memory.
   */ // }}}
  void test_out_of_host_memory( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_num_platforms(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_platform_ids(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_platforms(), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_other_error() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        unknown error code.
   */ // }}}
  void test_other_error( )
  {
    T::Dummy_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_num_platforms(), unexpected_clerror);
    TS_ASSERT_THROWS(get_platform_ids(), unexpected_clerror);
    TS_ASSERT_THROWS(get_platforms(), unexpected_clerror);
  }
};

#endif /* CLXX_CL_PLATFORMS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
