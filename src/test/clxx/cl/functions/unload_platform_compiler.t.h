// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/unload_platform_compiler.t.h

/** // doc: clxx/cl/functions/unload_platform_compiler.t.h {{{
 * \file clxx/cl/functions/unload_platform_compiler.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_UNLOAD_PLATFORM_COMPILER_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_UNLOAD_PLATFORM_COMPILER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_unload_platform_compiler_test_suite; }

/** // doc: class clxx::functions_unload_platform_compiler_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_unload_platform_compiler_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  unload_platform_compiler()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__unload_platform_compiler() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
    T::Dummy_clUnloadPlatformCompiler mock(CL_SUCCESS);
    unload_platform_compiler       ((cl_platform_id)0x937);
    TS_ASSERT(mock.called_once_with((cl_platform_id)0x937));
#endif // CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
  }
  /** // doc: test__unload_platform_compiler__invalid_platform() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler__invalid_platform( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
    T::Dummy_clUnloadPlatformCompiler mock(CL_INVALID_PLATFORM);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL),clerror_no<status_t::invalid_platform>);
#endif // CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
  }
  /** // doc: test__unload_platform_compiler__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__unload_platform_compiler__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
    T::Dummy_clUnloadPlatformCompiler mock(-0x1234567);
    TS_ASSERT_THROWS(unload_platform_compiler((cl_platform_id)NULL), unexpected_clerror);
#endif // CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
  }
};

#endif /* CLXX_CL_FUNCTIONS_UNLOAD_PLATFORM_COMPILER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
