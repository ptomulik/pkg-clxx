// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/ndrange.t.h

/** // doc: clxx/common/ndrange.t.h {{{
 * \file clxx/common/ndrange.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_NDRANGE_T_H_INCLUDED
#define CLXX_NDRANGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/ndrange.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx { class ndrange_test_suite; }

/** // doc: class clxx::ndrange_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::ndrange_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__ndrange__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__default_ctor( )
  {
    ndrange r;   // default ctor used
    // postconditions
    TS_ASSERT_EQUALS(r.dimension(), 1);
    TS_ASSERT(!r.has_global_offset());
    TS_ASSERT(!r.has_global_size());
    TS_ASSERT(!r.has_local_size());
  }
  /** // doc: test__ndrange__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__ctor_1( )
  {
    {
      ndrange r{1,nullptr,nullptr,nullptr};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT(!r.has_local_size());
    }
    {
      size_t array[] = {7};
      ndrange r{1,array,nullptr,nullptr};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT( r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT(!r.has_local_size());


      // We expect a copy of array[] in r._global_offset
      TS_ASSERT(r.global_offset_ptr() != array);
      TS_ASSERT_EQUALS(r.global_offset_ptr()[0], array[0]);

      // others are null
      TS_ASSERT(r.global_size_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      size_t array[] = {7,8,9};
      ndrange r{3,array,nullptr,nullptr};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT( r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT(!r.has_local_size());

      // We expect a copy of array[] in r._global_offset
      TS_ASSERT(r.global_offset_ptr() != array);
      TS_ASSERT_EQUALS(r.global_offset_ptr()[0], array[0]);
      TS_ASSERT(r.global_offset_ptr() != array);
      TS_ASSERT_EQUALS(r.global_offset_ptr()[1], array[1]);
      TS_ASSERT(r.global_offset_ptr() != array);
      TS_ASSERT_EQUALS(r.global_offset_ptr()[2], array[2]);

      // others are null
      TS_ASSERT(r.global_size_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      size_t array[] = {7};
      ndrange r{1,nullptr,array,nullptr};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT( r.has_global_size());
      TS_ASSERT(!r.has_local_size());

      // We expect a copy of array[] in r._global_size
      TS_ASSERT(r.global_size_ptr() != array);
      TS_ASSERT_EQUALS(r.global_size_ptr()[0], array[0]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      size_t array[] = {7,8,9};
      ndrange r{3,nullptr,array,nullptr};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT( r.has_global_size());
      TS_ASSERT(!r.has_local_size());

      // We expect a copy of array[] in r._global_size
      TS_ASSERT(r.global_size_ptr() != array);
      TS_ASSERT_EQUALS(r.global_size_ptr()[0], array[0]);
      TS_ASSERT(r.global_size_ptr() != array);
      TS_ASSERT_EQUALS(r.global_size_ptr()[1], array[1]);
      TS_ASSERT(r.global_size_ptr() != array);
      TS_ASSERT_EQUALS(r.global_size_ptr()[2], array[2]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      size_t array[] = {7};
      ndrange r{1,nullptr,nullptr,array};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT( r.has_local_size());

      // We expect a copy of array[] in r._local_size
      TS_ASSERT(r.local_size_ptr() != array);
      TS_ASSERT_EQUALS(r.local_size_ptr()[0], array[0]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.global_size_ptr() == nullptr);
    }
    {
      size_t array[] = {7,8,9};
      ndrange r{3,nullptr,nullptr,array};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT( r.has_local_size());

      // We expect a copy of array[] in r._local_size
      TS_ASSERT(r.local_size_ptr() != array);
      TS_ASSERT_EQUALS(r.local_size_ptr()[0], array[0]);
      TS_ASSERT(r.local_size_ptr() != array);
      TS_ASSERT_EQUALS(r.local_size_ptr()[1], array[1]);
      TS_ASSERT(r.local_size_ptr() != array);
      TS_ASSERT_EQUALS(r.local_size_ptr()[2], array[2]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.global_size_ptr() == nullptr);
    }
    {
      size_t array1[] = {1,2,3};
      size_t array2[] = {4,5,6};
      size_t array3[] = {7,8,9};
      ndrange r{3,array1,array2,array3};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT( r.has_global_offset());
      TS_ASSERT( r.has_global_size());
      TS_ASSERT( r.has_local_size());

      TS_ASSERT(r.global_offset_ptr() != array1);
      TS_ASSERT_EQUALS(r.global_offset_ptr()[0], array1[0]);
      TS_ASSERT(r.global_offset_ptr() != array1);
      TS_ASSERT_EQUALS(r.global_offset_ptr()[1], array1[1]);
      TS_ASSERT(r.global_offset_ptr() != array1);
      TS_ASSERT_EQUALS(r.global_offset_ptr()[2], array1[2]);

      TS_ASSERT(r.global_size_ptr() != array2);
      TS_ASSERT_EQUALS(r.global_size_ptr()[0], array2[0]);
      TS_ASSERT(r.global_size_ptr() != array2);
      TS_ASSERT_EQUALS(r.global_size_ptr()[1], array2[1]);
      TS_ASSERT(r.global_size_ptr() != array2);
      TS_ASSERT_EQUALS(r.global_size_ptr()[2], array2[2]);

      TS_ASSERT(r.local_size_ptr() != array3);
      TS_ASSERT_EQUALS(r.local_size_ptr()[0], array3[0]);
      TS_ASSERT(r.local_size_ptr() != array3);
      TS_ASSERT_EQUALS(r.local_size_ptr()[1], array3[1]);
      TS_ASSERT(r.local_size_ptr() != array3);
      TS_ASSERT_EQUALS(r.local_size_ptr()[2], array3[2]);
    }
  }  /** // doc: test__ndrange__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__ctor_2( )
  {
    typedef std::vector<size_t> vec_t;
    {
      ndrange r{1,vec_t(),vec_t(),vec_t()};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT(!r.has_local_size());
    }
    {
      vec_t vec{7};
      ndrange r{1,vec,vec_t(),vec_t()};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT( r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT(!r.has_local_size());


      // We expect a copy of vec[] in r._global_offset
      TS_ASSERT(r.global_offset_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_offset_ptr()[0], vec[0]);

      // others are null
      TS_ASSERT(r.global_size_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      vec_t vec{{7,8,9}};
      ndrange r{3,vec,vec_t(),vec_t()};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT( r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT(!r.has_local_size());

      // We expect a copy of vec[] in r._global_offset
      TS_ASSERT(r.global_offset_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_offset_ptr()[0], vec[0]);
      TS_ASSERT(r.global_offset_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_offset_ptr()[1], vec[1]);
      TS_ASSERT(r.global_offset_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_offset_ptr()[2], vec[2]);

      // others are null
      TS_ASSERT(r.global_size_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      vec_t vec{7};
      ndrange r{1,vec_t(),vec,vec_t()};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT( r.has_global_size());
      TS_ASSERT(!r.has_local_size());

      // We expect a copy of vec[] in r._global_size
      TS_ASSERT(r.global_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_size_ptr()[0], vec[0]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      vec_t vec{{7,8,9}};
      ndrange r{3,vec_t(),vec,vec_t()};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT( r.has_global_size());
      TS_ASSERT(!r.has_local_size());

      // We expect a copy of vec[] in r._global_size
      TS_ASSERT(r.global_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_size_ptr()[0], vec[0]);
      TS_ASSERT(r.global_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_size_ptr()[1], vec[1]);
      TS_ASSERT(r.global_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.global_size_ptr()[2], vec[2]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.local_size_ptr() == nullptr);
    }
    {
      vec_t vec{7};
      ndrange r{1,vec_t(),vec_t(),vec};
      TS_ASSERT_EQUALS(r.dimension(),1);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT( r.has_local_size());

      // We expect a copy of vec[] in r._local_size
      TS_ASSERT(r.local_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.local_size_ptr()[0], vec[0]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.global_size_ptr() == nullptr);
    }
    {
      vec_t vec{{7,8,9}};
      ndrange r{3,vec_t(),vec_t(),vec};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT(!r.has_global_offset());
      TS_ASSERT(!r.has_global_size());
      TS_ASSERT( r.has_local_size());

      // We expect a copy of vec[] in r._local_size
      TS_ASSERT(r.local_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.local_size_ptr()[0], vec[0]);
      TS_ASSERT(r.local_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.local_size_ptr()[1], vec[1]);
      TS_ASSERT(r.local_size_ptr() != vec.data());
      TS_ASSERT_EQUALS(r.local_size_ptr()[2], vec[2]);

      // others are null
      TS_ASSERT(r.global_offset_ptr() == nullptr);
      TS_ASSERT(r.global_size_ptr() == nullptr);
    }
    {
      vec_t vec1{{1,2,3}};
      vec_t vec2{{4,5,6}};
      vec_t vec3{{7,8,9}};
      ndrange r{3,vec1,vec2,vec3};
      TS_ASSERT_EQUALS(r.dimension(),3);
      TS_ASSERT( r.has_global_offset());
      TS_ASSERT( r.has_global_size());
      TS_ASSERT( r.has_local_size());

      TS_ASSERT(r.global_offset_ptr() != vec1.data());
      TS_ASSERT_EQUALS(r.global_offset_ptr()[0], vec1[0]);
      TS_ASSERT(r.global_offset_ptr() != vec1.data());
      TS_ASSERT_EQUALS(r.global_offset_ptr()[1], vec1[1]);
      TS_ASSERT(r.global_offset_ptr() != vec1.data());
      TS_ASSERT_EQUALS(r.global_offset_ptr()[2], vec1[2]);

      TS_ASSERT(r.global_size_ptr() != vec2.data());
      TS_ASSERT_EQUALS(r.global_size_ptr()[0], vec2[0]);
      TS_ASSERT(r.global_size_ptr() != vec2.data());
      TS_ASSERT_EQUALS(r.global_size_ptr()[1], vec2[1]);
      TS_ASSERT(r.global_size_ptr() != vec2.data());
      TS_ASSERT_EQUALS(r.global_size_ptr()[2], vec2[2]);

      TS_ASSERT(r.local_size_ptr() != vec3.data());
      TS_ASSERT_EQUALS(r.local_size_ptr()[0], vec3[0]);
      TS_ASSERT(r.local_size_ptr() != vec3.data());
      TS_ASSERT_EQUALS(r.local_size_ptr()[1], vec3[1]);
      TS_ASSERT(r.local_size_ptr() != vec3.data());
      TS_ASSERT_EQUALS(r.local_size_ptr()[2], vec3[2]);
    }
  }

  /** // doc: test__ndrange__setup_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__setup_1( )
  {
    size_t array1[] = {1,2,3};
    size_t array2[] = {4,5,6};
    size_t array3[] = {7,8,9};
    ndrange r;

    r.setup(3,array1,array2,array3);

    TS_ASSERT_EQUALS(r.dimension(),3);
    TS_ASSERT( r.has_global_offset() );
    TS_ASSERT( r.has_global_size() );
    TS_ASSERT( r.has_local_size() );

    TS_ASSERT(r.global_offset_ptr() != array1);
    TS_ASSERT_EQUALS(r.global_offset_ptr()[0], array1[0]);
    TS_ASSERT(r.global_offset_ptr() != array1);
    TS_ASSERT_EQUALS(r.global_offset_ptr()[1], array1[1]);
    TS_ASSERT(r.global_offset_ptr() != array1);
    TS_ASSERT_EQUALS(r.global_offset_ptr()[2], array1[2]);

    TS_ASSERT(r.global_size_ptr() != array2);
    TS_ASSERT_EQUALS(r.global_size_ptr()[0], array2[0]);
    TS_ASSERT(r.global_size_ptr() != array2);
    TS_ASSERT_EQUALS(r.global_size_ptr()[1], array2[1]);
    TS_ASSERT(r.global_size_ptr() != array2);
    TS_ASSERT_EQUALS(r.global_size_ptr()[2], array2[2]);

    TS_ASSERT(r.local_size_ptr() != array3);
    TS_ASSERT_EQUALS(r.local_size_ptr()[0], array3[0]);
    TS_ASSERT(r.local_size_ptr() != array3);
    TS_ASSERT_EQUALS(r.local_size_ptr()[1], array3[1]);
    TS_ASSERT(r.local_size_ptr() != array3);
    TS_ASSERT_EQUALS(r.local_size_ptr()[2], array3[2]);

    r.setup(1, nullptr, nullptr, nullptr);
    TS_ASSERT_EQUALS(r.dimension(),1);
    TS_ASSERT(!r.has_global_offset());
    TS_ASSERT(!r.has_global_size());
    TS_ASSERT(!r.has_local_size());
  }
  /** // doc: test__ndrange__setup_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__setup_2( )
  {
    typedef std::vector<size_t> vec_t;
    vec_t vec1{{1,2,3}};
    vec_t vec2{{4,5,6}};
    vec_t vec3{{7,8,9}};
    ndrange r;

    r.setup(3,vec1,vec2,vec3);

    TS_ASSERT_EQUALS(r.dimension(),3);
    TS_ASSERT( r.has_global_offset() );
    TS_ASSERT( r.has_global_size() );
    TS_ASSERT( r.has_local_size() );

    TS_ASSERT(r.global_offset_ptr() != vec1.data());
    TS_ASSERT_EQUALS(r.global_offset_ptr()[0], vec1[0]);
    TS_ASSERT(r.global_offset_ptr() != vec1.data());
    TS_ASSERT_EQUALS(r.global_offset_ptr()[1], vec1[1]);
    TS_ASSERT(r.global_offset_ptr() != vec1.data());
    TS_ASSERT_EQUALS(r.global_offset_ptr()[2], vec1[2]);

    TS_ASSERT(r.global_size_ptr() != vec2.data());
    TS_ASSERT_EQUALS(r.global_size_ptr()[0], vec2[0]);
    TS_ASSERT(r.global_size_ptr() != vec2.data());
    TS_ASSERT_EQUALS(r.global_size_ptr()[1], vec2[1]);
    TS_ASSERT(r.global_size_ptr() != vec2.data());
    TS_ASSERT_EQUALS(r.global_size_ptr()[2], vec2[2]);

    TS_ASSERT(r.local_size_ptr() != vec3.data());
    TS_ASSERT_EQUALS(r.local_size_ptr()[0], vec3[0]);
    TS_ASSERT(r.local_size_ptr() != vec3.data());
    TS_ASSERT_EQUALS(r.local_size_ptr()[1], vec3[1]);
    TS_ASSERT(r.local_size_ptr() != vec3.data());
    TS_ASSERT_EQUALS(r.local_size_ptr()[2], vec3[2]);

    r.setup(1, std::vector<size_t>(), std::vector<size_t>(), std::vector<size_t>());
    TS_ASSERT_EQUALS(r.dimension(),1);
    TS_ASSERT(!r.has_global_offset());
    TS_ASSERT(!r.has_global_size());
    TS_ASSERT(!r.has_local_size());

    // Check for the length_error exception ...
    TS_ASSERT_THROWS(r.setup(3, vec_t({1,2}), vec_t(), vec_t()), length_error);
    TS_ASSERT_THROWS(r.setup(3, vec_t(), vec_t({1,2}), vec_t()), length_error);
    TS_ASSERT_THROWS(r.setup(3, vec_t(), vec_t(), vec_t({1,2})), length_error);

    TS_ASSERT_THROWS(r.setup(1, vec_t({1,2}), vec_t(), vec_t()), length_error);
    TS_ASSERT_THROWS(r.setup(1, vec_t(), vec_t({1,2}), vec_t()), length_error);
    TS_ASSERT_THROWS(r.setup(1, vec_t(), vec_t(), vec_t({1,2})), length_error);
  }
  /** // doc: test__ndrange__dimension() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__dimension( )
  {
    ndrange r;

    TS_ASSERT_EQUALS(r.dimension(), 1);

    r.set_dimension(3);
    TS_ASSERT_EQUALS(r.dimension(), 3);

    // ensure that nothing else was touched
    TS_ASSERT(!r.has_global_offset());
    TS_ASSERT(!r.has_global_size());
    TS_ASSERT(!r.has_local_size());

    TS_ASSERT_THROWS(r.set_dimension(CLXX_MAX_NDRANGE_DIMENSIONS+1), invalid_argument_error);
  }
  /** // doc: test__ndrange__global_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__global_offset( )
  {
    ndrange r;

    TS_ASSERT(!r.has_global_offset() );
    TS_ASSERT(r.global_offset_ptr() == nullptr);
    TS_ASSERT_THROWS(r.global_offset(), uninitialized_value_error);

    r.set_global_offset(0,7);
    TS_ASSERT( r.has_global_offset() );
    TS_ASSERT(r.global_offset_ptr() != nullptr);
    TS_ASSERT_EQUALS(r.global_offset(0), 7);
    TS_ASSERT_EQUALS(r.global_offset_ptr()[0], 7);
    TS_ASSERT_EQUALS(r.global_offset().size(), 1);
    TS_ASSERT_EQUALS(r.global_offset()[0], 7 );

    TS_ASSERT_THROWS(r.set_global_offset(1,9), invalid_index_error);
    TS_ASSERT_THROWS(r.global_offset(1), invalid_index_error);

    r.set_dimension(2);
    r.set_global_offset(1,8);
    TS_ASSERT_EQUALS(r.global_offset(0),7);
    TS_ASSERT_EQUALS(r.global_offset(1),8);
    TS_ASSERT_EQUALS(r.global_offset_ptr()[0],7);
    TS_ASSERT_EQUALS(r.global_offset_ptr()[1],8);
    TS_ASSERT_EQUALS(r.global_offset().size(), 2);
    TS_ASSERT_EQUALS(r.global_offset()[0], 7);
    TS_ASSERT_EQUALS(r.global_offset()[1], 8);

  }
  /** // doc: test__ndrange__global_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__global_size( )
  {
    ndrange r;

    TS_ASSERT(!r.has_global_size() );
    TS_ASSERT(r.global_size_ptr() == nullptr);
    TS_ASSERT_THROWS(r.global_size(), uninitialized_value_error);

    r.set_global_size(0,7);
    TS_ASSERT( r.has_global_size() );
    TS_ASSERT(r.global_size_ptr() != nullptr);
    TS_ASSERT_EQUALS(r.global_size(0), 7);
    TS_ASSERT_EQUALS(r.global_size_ptr()[0], 7);
    TS_ASSERT_EQUALS(r.global_size().size(), 1);
    TS_ASSERT_EQUALS(r.global_size()[0], 7 );

    TS_ASSERT_THROWS(r.set_global_size(1,9), invalid_index_error);
    TS_ASSERT_THROWS(r.global_size(1), invalid_index_error);

    r.set_dimension(2);
    r.set_global_size(1,8);
    TS_ASSERT_EQUALS(r.global_size(0),7);
    TS_ASSERT_EQUALS(r.global_size(1),8);
    TS_ASSERT_EQUALS(r.global_size_ptr()[0],7);
    TS_ASSERT_EQUALS(r.global_size_ptr()[1],8);
    TS_ASSERT_EQUALS(r.global_size().size(), 2);
    TS_ASSERT_EQUALS(r.global_size()[0], 7);
    TS_ASSERT_EQUALS(r.global_size()[1], 8);

  }
  /** // doc: test__ndrange__local_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__local_size( )
  {
    ndrange r;

    TS_ASSERT(!r.has_local_size() );
    TS_ASSERT(r.local_size_ptr() == nullptr);
    TS_ASSERT_THROWS(r.local_size(), uninitialized_value_error);

    r.set_local_size(0,7);
    TS_ASSERT( r.has_local_size() );
    TS_ASSERT(r.local_size_ptr() != nullptr);
    TS_ASSERT_EQUALS(r.local_size(0), 7);
    TS_ASSERT_EQUALS(r.local_size_ptr()[0], 7);
    TS_ASSERT_EQUALS(r.local_size().size(), 1);
    TS_ASSERT_EQUALS(r.local_size()[0], 7 );

    TS_ASSERT_THROWS(r.set_local_size(1,9), invalid_index_error);
    TS_ASSERT_THROWS(r.local_size(1), invalid_index_error);

    r.set_dimension(2);
    r.set_local_size(1,8);
    TS_ASSERT_EQUALS(r.local_size(0),7);
    TS_ASSERT_EQUALS(r.local_size(1),8);
    TS_ASSERT_EQUALS(r.local_size_ptr()[0],7);
    TS_ASSERT_EQUALS(r.local_size_ptr()[1],8);
    TS_ASSERT_EQUALS(r.local_size().size(), 2);
    TS_ASSERT_EQUALS(r.local_size()[0], 7);
    TS_ASSERT_EQUALS(r.local_size()[1], 8);

  }
  /** // doc: test__ndrange__set_chain() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__set_chain( )
  {
    ndrange r;

    r.set_dimension(3)
      .set_global_offset(2,12)
      .set_global_size(2,22)
      .set_local_size(2,32);

    TS_ASSERT_EQUALS(r.dimension(), 3);
    TS_ASSERT_EQUALS(r.global_offset(2), 12);
    TS_ASSERT_EQUALS(r.global_size(2), 22);
    TS_ASSERT_EQUALS(r.local_size(2), 32);
  }
  /** // doc: test__ndrange__eq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__eq_op( )
  {
    {
      ndrange r1, r2;
      TS_ASSERT(r1 == r2);
    }
    {
      ndrange r1{1,{1},{},{}}, r2;
      TS_ASSERT(!(r1 == r2));
    }
    {
      ndrange r1{1,{1},{},{}}, r2{1,{1},{},{}};
      TS_ASSERT(r1 == r2);
    }
    {
      ndrange r1{1,{},{2},{}}, r2{1,{},{2},{}};
      TS_ASSERT(r1 == r2);
    }
    {
      ndrange r1{1,{},{},{3}}, r2{1,{},{},{3}};
      TS_ASSERT(r1 == r2);
    }
    {
      ndrange r1{2,{1,2},{},{}}, r2{1,{1},{},{}};
      TS_ASSERT(!(r1 == r2));
    }
  }
  /** // doc: test__ndrange__neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__neq_op( )
  {
    {
      ndrange r1, r2;
      TS_ASSERT(!(r1 != r2));
    }
    {
      ndrange r1{1,{1},{},{}}, r2;
      TS_ASSERT((r1 != r2));
    }
    {
      ndrange r1{1,{1},{},{}}, r2{1,{1},{},{}};
      TS_ASSERT(!(r1 != r2));
    }
    {
      ndrange r1{1,{},{2},{}}, r2{1,{},{2},{}};
      TS_ASSERT(!(r1 != r2));
    }
    {
      ndrange r1{1,{},{},{3}}, r2{1,{},{},{3}};
      TS_ASSERT(!(r1 != r2));
    }
    {
      ndrange r1{2,{1,2},{},{}}, r2{1,{1},{},{}};
      TS_ASSERT(r1 != r2);
    }
  }
  /** // doc: test__ndrange__assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__ndrange__assign( )
  {
    ndrange r1{3, {1,2,3}, {4,5,6}, {7,8,9}};
    ndrange r2;

    r2 = r1;
    TS_ASSERT(r2 == r1);
  }
};

#endif /* CLXX_NDRANGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
