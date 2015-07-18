// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/release_device.t.h

/** // doc: clxx/cl/functions/release_device.t.h {{{
 * \file clxx/cl/functions/release_device.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_RELEASE_DEVICE_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_RELEASE_DEVICE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_release_device_test_suite; }

/** // doc: class clxx::functions_release_device_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_release_device_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  release_device()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__release_device() {{{
   * \brief Test \ref release_device() in normal situation
   */ // }}}
  void test__release_device( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(release_device((cl_device_id)0x1234));
    TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__invalid_device() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_INVALID_DEVICE
   */ // }}}
  void test__release_device__invalid_device( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::invalid_device>);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__out_of_resources() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_RESOURCES
   */ // }}}
  void test__release_device__out_of_resources( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_resources>);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__out_of_host_memory() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns CL_OUT_OF_HOST_MEMORY
   */ // }}}
  void test__release_device__out_of_host_memory( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(release_device(NULL),clerror_no<status_t::out_of_host_memory>);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
  /** // doc: test__release_device__unexpected_clerror() {{{
   * \brief Test \ref release_device() in a situation when \c clReleaseDevice() returns unexpected error code
   */ // }}}
  void test__release_device__unexpected_clerror( )
  {
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mock(-0x1234567);
    TS_ASSERT_THROWS(release_device(NULL),unexpected_clerror);
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
  }
};

#endif /* CLXX_CL_FUNCTIONS_RELEASE_DEVICE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
