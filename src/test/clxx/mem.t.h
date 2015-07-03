// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/mem.t.h

/** // doc: clxx/mem.t.h {{{
 * \file clxx/mem.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_MEM_T_H_INCLUDED
#define CLXX_MEM_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/mem.hpp>
#include <clxx/context.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class mem_test_suite; }

/** // doc: class clxx::mem_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::mem_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    mem m;
    TS_ASSERT(!m.is_initialized());
    TS_ASSERT_EQUALS(m.get(), (cl_mem)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    mem m((cl_mem)0x1234);
    TS_ASSERT(m.is_initialized());
    TS_ASSERT_EQUALS(m.get(), (cl_mem)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_mem)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1__null_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1__null_id( )
  {
    T::Dummy_clRetainMemObject mock1(CL_INVALID_MEM_OBJECT);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(mem((cl_mem)NULL));
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2( )
  {
    T::Dummy_clCreateBuffer mock1((cl_mem)0x1234, CL_SUCCESS);
    T::Dummy_clRetainMemObject mock2(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock3(CL_SUCCESS);
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    context ctx((cl_context)0x4321);
    mem m(ctx, mem_flags_t::read_write, 123ul, (void*)0x7654);
    TS_ASSERT(m.is_initialized());
    TS_ASSERT_EQUALS(m.get(), (cl_mem)0x1234);
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(std::get<0>(mock1.calls().back()) == (cl_context)0x4321);
    TS_ASSERT(std::get<1>(mock1.calls().back()) == (cl_mem_flags)CL_MEM_READ_WRITE);
    TS_ASSERT(std::get<2>(mock1.calls().back()) == 123ul);
    TS_ASSERT(std::get<3>(mock1.calls().back()) == (void*)0x7654);
    TS_ASSERT(mock2.never_called());
    TS_ASSERT(mock3.never_called());
  }
  /** // doc: test__copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__copy_ctor( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    mem k1((cl_mem)0x1234);
    mem k2(k1);
    TS_ASSERT(k2.is_initialized());
    TS_ASSERT(mock1.called_twice());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(k2, mem((cl_mem)0x1234));
  }
  /** // doc: test__dtor__notnull() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__notnull( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    {
      mem m((cl_mem)0x1234);
    }
    TS_ASSERT(mock2.called_once_with((cl_mem)0x1234));
  }
  /** // doc: test__dtor__null() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__null( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    {
      mem m((cl_mem)NULL);
    }
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__id() {{{
   * \todo Write documentation
   */ // }}}
  void test__id( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(mem((cl_mem)0x1234).get(), (cl_mem)0x1234);
    TS_ASSERT_EQUALS(mem((cl_mem)NULL).get(), (cl_mem)NULL);
  }
  /** // doc: test__chk_get() {{{
   * \todo Write documentation
   */ // }}}
  void test__chk_get( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(mem((cl_mem)0x1234).chk_get(), (cl_mem)0x1234);
    TS_ASSERT_THROWS(mem((cl_mem)NULL).chk_get(), uninitialized_mem_error);
  }
  /** // doc: test__op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_assign( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    mem p1((cl_mem)0x1234);
    mem p2((cl_mem)0x5678);
    p1 = p2;
    TS_ASSERT_EQUALS(p1.get(), (cl_mem)0x5678);
  }
  /** // doc: test__op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_eq( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    TS_ASSERT( (mem((cl_mem)0x1234) == mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)0x1234) == mem((cl_mem)0x5678)));
    TS_ASSERT(!(mem((cl_mem)0x5678) == mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)0x1234) == mem((cl_mem)NULL)));
    TS_ASSERT(!(mem((cl_mem)NULL)   == mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)NULL)   == mem((cl_mem)NULL)));
  }
  /** // doc: test__op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_neq( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    TS_ASSERT(!(mem((cl_mem)0x1234) != mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)0x1234) != mem((cl_mem)0x5678)));
    TS_ASSERT( (mem((cl_mem)0x5678) != mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)0x1234) != mem((cl_mem)NULL)));
    TS_ASSERT( (mem((cl_mem)NULL)   != mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)NULL)   != mem((cl_mem)NULL)));
  }
  /** // doc: test__op_lt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_lt( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    TS_ASSERT(!(mem((cl_mem)0x1234) < mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)0x1234) < mem((cl_mem)0x5678)));
    TS_ASSERT(!(mem((cl_mem)0x5678) < mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)0x1234) < mem((cl_mem)NULL)));
    TS_ASSERT( (mem((cl_mem)NULL)   < mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)NULL)   < mem((cl_mem)NULL)));
  }
  /** // doc: test__op_gt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_gt( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    TS_ASSERT(!(mem((cl_mem)0x1234) > mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)0x1234) > mem((cl_mem)0x5678)));
    TS_ASSERT( (mem((cl_mem)0x5678) > mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)0x1234) > mem((cl_mem)NULL)));
    TS_ASSERT(!(mem((cl_mem)NULL)   > mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)NULL)   > mem((cl_mem)NULL)));
  }
  /** // doc: test__op_le() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_le( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    TS_ASSERT( (mem((cl_mem)0x1234) <= mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)0x1234) <= mem((cl_mem)0x5678)));
    TS_ASSERT(!(mem((cl_mem)0x5678) <= mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)0x1234) <= mem((cl_mem)NULL)));
    TS_ASSERT( (mem((cl_mem)NULL)   <= mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)NULL)   <= mem((cl_mem)NULL)));
  }
  /** // doc: test__op_ge() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_ge( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    TS_ASSERT( (mem((cl_mem)0x1234) >= mem((cl_mem)0x1234)));
    TS_ASSERT(!(mem((cl_mem)0x1234) >= mem((cl_mem)0x5678)));
    TS_ASSERT( (mem((cl_mem)0x5678) >= mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)0x1234) >= mem((cl_mem)NULL)));
    TS_ASSERT(!(mem((cl_mem)NULL)   >= mem((cl_mem)0x1234)));
    TS_ASSERT( (mem((cl_mem)NULL)   >= mem((cl_mem)NULL)));
  }
  /** // doc: test__get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS);

    mem m((cl_mem)0x4321);
    m.get_info(mem_info_t::context, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_mem)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_MEM_CONTEXT);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_info__uninitialized_mem() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info__uninitialized_mem( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);
    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS);

    mem m((cl_mem)NULL);
    TS_ASSERT_THROWS(m.get_info(mem_info_t::context, 0, nullptr, nullptr), uninitialized_mem_error);
  }
  /** // doc: test__get_type() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_type( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    mem_object_type_t var = mem_object_type_t::buffer;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_type(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_TYPE);
  }
  /** // doc: test__get_flags() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_flags( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    mem_flags_t var = mem_flags_t::read_write;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_flags(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_FLAGS);
  }
  /** // doc: test__get_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_size( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    size_t var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_size(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_SIZE);
  }
  /** // doc: test__get_host_ptr() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_host_ptr( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    void* var = (void*)0x1234;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_host_ptr(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_HOST_PTR);
  }
  /** // doc: test__get_map_count() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_map_count( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    cl_uint var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_map_count(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_MAP_COUNT);
  }
  /** // doc: test__get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_reference_count( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    cl_uint var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_reference_count(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_REFERENCE_COUNT);
  }
  /** // doc: test__get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_context( )
  {
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    cl_context var = (cl_context)0x1234;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    
    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);

    TS_ASSERT(m.get_context() == context(var));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_CONTEXT);
  }
  /** // doc: test__get_associated_memobject() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_associated_memobject( )
  {
#if CLXX_CL_H_VERSION_1_1
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    cl_mem var = (cl_mem)0x1234;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT(m.get_associated_memobject() == mem(var));

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_ASSOCIATED_MEMOBJECT);
#endif
  }
  /** // doc: test__get_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_offset( )
  {
#if CLXX_CL_H_VERSION_1_1
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    size_t var = 12;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_offset(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_OFFSET);
#endif
  }
  /** // doc: test__get_uses_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_uses_svm_pointer( )
  {
#if CLXX_CL_H_VERSION_2_0
    T::Dummy_clRetainMemObject mock1(CL_SUCCESS);
    T::Dummy_clReleaseMemObject mock2(CL_SUCCESS);

    cl_bool var = 1;
    size_t n = sizeof(var);

    T::Dummy_clGetMemObjectInfo mock3(CL_SUCCESS, &var, &n);

    mem m((cl_mem)0x4321);
    TS_ASSERT_EQUALS(m.get_uses_svm_pointer(), var);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_mem_info)CL_MEM_USES_SVM_POINTER);
#endif
  }
};

#endif /* CLXX_MEM_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
