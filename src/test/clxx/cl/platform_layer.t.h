// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_layer.t.h

/** // doc: clxx/platform_layer.t.h {{{
 * \file clxx/platform_layer.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PLATFORM_LAYER_T_H_INCLUDED
#define CLXX_CL_PLATFORM_LAYER_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/platform_layer.hpp>
#include <clxx/cl/mock.hpp>
#include <clxx/exceptions.hpp>

namespace clxx { class platform_layer_test__suite; }

/** // doc: class clxx::platform_layer_test__suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::platform_layer_test__suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__ctor_0() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_0( )
  {
    TS_ASSERT_EQUALS(platform_layer().get_platforms().size(), 0);
    TS_ASSERT_EQUALS(platform_layer().get_devices().size(), 0);
  }
  /** // doc: test__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;

    TS_ASSERT_EQUALS(platform_layer(true).get_platforms().size(), 2);
    TS_ASSERT_EQUALS(platform_layer(true).get_devices().size(), 3);

    TS_ASSERT_EQUALS(platform_layer(false).get_platforms().size(), 0);
    TS_ASSERT_EQUALS(platform_layer(false).get_devices().size(), 0);

    TS_ASSERT_EQUALS(platform_layer(true, device_type_t::gpu).get_platforms().size(), 1);
    TS_ASSERT_EQUALS(platform_layer(true, device_type_t::gpu).get_devices().size(), 2);

    TS_ASSERT_EQUALS(platform_layer(true, device_type_t::cpu).get_platforms().size(), 1);
    TS_ASSERT_EQUALS(platform_layer(true, device_type_t::cpu).get_devices().size(), 1);
  }
  /** // doc: test__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;

    TS_ASSERT_EQUALS(platform_layer(device_type_t::gpu).get_platforms().size(), 1);
    TS_ASSERT_EQUALS(platform_layer(device_type_t::gpu).get_devices().size(), 2);

    TS_ASSERT_EQUALS(platform_layer(device_type_t::cpu).get_platforms().size(), 1);
    TS_ASSERT_EQUALS(platform_layer(device_type_t::cpu).get_devices().size(), 1);
  }
  /** // doc: test__get_platforms_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_platforms_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    platform p = pl.get_platforms()[0];

    TS_ASSERT_EQUALS(p.get(), T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(p.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(p.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
    TS_ASSERT_EQUALS(p.get_name(), "AMD Accelerated Parallel Processing");
    TS_ASSERT_EQUALS(p.get_vendor(), "Advanced Micro Devices, Inc.");
    TS_ASSERT_EQUALS(p.get_extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }
  /** // doc: test__get_platforms_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_platforms_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    platform p = pl.get_platforms()[1];

    TS_ASSERT_EQUALS(p.get(), T::Newton_clGetPlatformIDs::platforms[1]);
    TS_ASSERT_EQUALS(p.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(p.get_version(), "OpenCL 1.1 CUDA 4.2.1");
    TS_ASSERT_EQUALS(p.get_name(), "NVIDIA CUDA");
    TS_ASSERT_EQUALS(p.get_vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(p.get_extensions(), "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll");
  }
  /** // doc: test__get_platform_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_platform_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    devices d = pl.get_devices();

    TS_ASSERT_EQUALS(pl.get_devices().size(), 3);
    TS_ASSERT_EQUALS(pl.get_platform(d[0]).get(), T::Newton_clGetPlatformIDs::platforms[0]);
    TS_ASSERT_EQUALS(pl.get_platform(d[1]).get(), T::Newton_clGetPlatformIDs::platforms[1]);
    TS_ASSERT_EQUALS(pl.get_platform(d[2]).get(), T::Newton_clGetPlatformIDs::platforms[1]);
  }
  /** // doc: test__get_devices_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_devices_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    device d = pl.get_devices()[0];

    TS_ASSERT_EQUALS(d.get(), T::Newton_clGetDeviceIDs::devices[0]);
    TS_ASSERT_EQUALS(d.get_name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(d.get_vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(d.get_driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test__get_devices_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_devices_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    device d = pl.get_devices()[1];

    TS_ASSERT_EQUALS(d.get(), T::Newton_clGetDeviceIDs::devices[1]);
    TS_ASSERT_EQUALS(d.get_name(), "Tesla C1060");
    TS_ASSERT_EQUALS(d.get_vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(d.get_driver_version(), "319.76");
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test__get_devices_3() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_devices_3( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    device d = pl.get_devices()[2];

    TS_ASSERT_EQUALS(d.get(), T::Newton_clGetDeviceIDs::devices[2]);
    TS_ASSERT_EQUALS(d.get_name(), "Tesla C1060");
    TS_ASSERT_EQUALS(d.get_vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(d.get_driver_version(), "319.76");
    TS_ASSERT_EQUALS(d.get_profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(d.get_version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test__get_devices_4() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_devices_4( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    platform p = pl.get_platforms()[0];
    devices ds = pl.get_devices(p);

    TS_ASSERT_EQUALS(ds.size(), 1);

    device d = ds[0];

    TS_ASSERT_EQUALS(d.get(), T::Newton_clGetDeviceIDs::devices[0]);
  }
  /** // doc: test__get_devices_5() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_devices_5( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    platform p = pl.get_platforms()[1];
    devices ds = pl.get_devices(p);

    TS_ASSERT_EQUALS(ds.size(), 2);

    device d = ds[0];

    TS_ASSERT_EQUALS(d.get(), T::Newton_clGetDeviceIDs::devices[1]);
  }
  /** // doc: test__get_devices_6() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_devices_6( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer pl(true);
    platform p = pl.get_platforms()[1];
    devices ds = pl.get_devices(p);

    TS_ASSERT_EQUALS(ds.size(), 2);

    device d = ds[1];

    TS_ASSERT_EQUALS(d.get(), T::Newton_clGetDeviceIDs::devices[2]);
  }
  /** // doc: test__get_devices__invalid_key_error() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_devices__invalid_key_error( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    platform_layer pl;
    TS_ASSERT_THROWS(pl.get_devices(platform((cl_platform_id)0x1234)), invalid_key_error);
    pl.add({device((cl_device_id)0x1000), device((cl_device_id)0x2000)}, platform((cl_platform_id)0x1234));
    TS_ASSERT_THROWS_NOTHING(pl.get_devices(platform((cl_platform_id)0x1234)));
    TS_ASSERT_THROWS(pl.get_devices(platform((cl_platform_id)0x5678)), invalid_key_error);
  }
  /** // doc: test__has_platform_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__has_platform_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    platform_layer pl;
    TS_ASSERT(!pl.has_platform(platform((cl_platform_id)0x1234)));
    pl.add(device((cl_device_id)0x5678), platform((cl_platform_id)0x1234));
    TS_ASSERT(pl.has_platform(platform((cl_platform_id)0x1234)));
  }
  /** // doc: test__has_device_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__has_device_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    platform_layer pl;
    TS_ASSERT(!pl.has_device(device((cl_device_id)0x5678)));
    pl.add(device((cl_device_id)0x5678), platform((cl_platform_id)0x1234));
    TS_ASSERT(pl.has_device(device((cl_device_id)0x5678)));
  }
  /** // doc: test__add_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__add_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    platform_layer pl;

    TS_ASSERT(pl.add(device((cl_device_id)0x1000), platform((cl_platform_id)0x1234)));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 1);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 1);
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x1000)), platform((cl_platform_id)0x1234));

    TS_ASSERT(pl.add(device((cl_device_id)0x2000), platform((cl_platform_id)0x1234)));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 2);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 1);
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x1000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x2000)), platform((cl_platform_id)0x1234));

    TS_ASSERT(pl.add(device((cl_device_id)0x3000), platform((cl_platform_id)0x5678)));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 3);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 2);
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x1000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x2000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x3000)), platform((cl_platform_id)0x5678));

    TS_ASSERT(!pl.add(device((cl_device_id)0x3000), platform((cl_platform_id)0x1234)));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 3);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 1);
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x1000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x2000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x3000)), platform((cl_platform_id)0x1234));
  }
  /** // doc: test__add_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__add_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    platform_layer pl;

    TS_ASSERT_EQUALS(pl.add(make_devices({ (cl_device_id)0x1000, (cl_device_id)0x2000, (cl_device_id)0x3000 }), platform((cl_platform_id)0x1234)), 3);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 1);
    TS_ASSERT_EQUALS(pl.get_devices().size(), 3);
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x1000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x2000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x3000)), platform((cl_platform_id)0x1234));

    TS_ASSERT_EQUALS(pl.add(make_devices({ (cl_device_id)0x1000, (cl_device_id)0x4000, (cl_device_id)0x5000 }), platform((cl_platform_id)0x5678)), 2);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 2);
    TS_ASSERT_EQUALS(pl.get_devices().size(), 5);
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x1000)), platform((cl_platform_id)0x5678));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x2000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x3000)), platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x4000)), platform((cl_platform_id)0x5678));
    TS_ASSERT_EQUALS(pl.get_platform(device((cl_device_id)0x5000)), platform((cl_platform_id)0x5678));
  }
  /** // doc: test__erase_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__erase_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    platform_layer pl;
    TS_ASSERT_EQUALS(pl.add(make_devices({ (cl_device_id)0x1000, (cl_device_id)0x2000, (cl_device_id)0x3000 }), platform((cl_platform_id)0x1234)), 3);
    TS_ASSERT_EQUALS(pl.add(make_devices({ (cl_device_id)0x4000, (cl_device_id)0x5000 }), platform((cl_platform_id)0x5678)), 2);

    pl.erase(device((cl_device_id)0x1000));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 4);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 2);

    pl.erase(device((cl_device_id)0x2000));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 3);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 2);

    pl.erase(device((cl_device_id)0x3000));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 2);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 1);

    pl.erase(device((cl_device_id)0x4000));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 1);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 1);

    pl.erase(device((cl_device_id)0x5000));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 0);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 0);

    TS_ASSERT_THROWS(pl.erase(device((cl_device_id)0x1234)), invalid_key_error);
  }
  /** // doc: test__erase_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__erase_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    platform_layer pl;
    TS_ASSERT_EQUALS(pl.add(make_devices({ (cl_device_id)0x1000, (cl_device_id)0x2000, (cl_device_id)0x3000 }), platform((cl_platform_id)0x1234)), 3);
    TS_ASSERT_EQUALS(pl.add(make_devices({ (cl_device_id)0x4000, (cl_device_id)0x5000 }), platform((cl_platform_id)0x5678)), 2);

    pl.erase(platform((cl_platform_id)0x1234));
    TS_ASSERT_EQUALS(pl.get_devices().size(), 2);
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 1);

    pl.erase(platform((cl_platform_id)0x5678));
    TS_ASSERT_EQUALS(pl.get_devices().size(),0);
    TS_ASSERT_EQUALS(pl.get_platforms().size(),0);
    TS_ASSERT_THROWS(pl.erase(platform((cl_platform_id)0x1234)), invalid_key_error);
  }
  /** // doc: test__clear_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__clear_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;

    platform_layer pl(true);
    pl.clear();
    TS_ASSERT_EQUALS(pl.get_platforms().size(), 0);
    TS_ASSERT_EQUALS(pl.get_devices().size(), 0);
  }
  /** // doc: test__query_platform_layer_info_1() {{{
   * \brief Test the get_platforms() method.
   */ // }}}
  void test__query_platform_layer_info_1( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer layer(true);
    platform_layer_info p(query_platform_layer_info(layer));
    platform_info_ptrs infos(p.get_platforms());

    TS_ASSERT_EQUALS(infos.size(), 2);

    /* Check if we have obtained  correct information */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetPlatformIDs::platforms[0]));
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.2 AMD-APP (1348.4)");
    TS_ASSERT_EQUALS(infos[0]->name(), "AMD Accelerated Parallel Processing");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "Advanced Micro Devices, Inc.");
    TS_ASSERT_EQUALS(infos[0]->extensions(), "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");

    TS_ASSERT_EQUALS(infos[1]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetPlatformIDs::platforms[1]));
    TS_ASSERT_EQUALS(infos[1]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[1]->version(), "OpenCL 1.1 CUDA 4.2.1");
    TS_ASSERT_EQUALS(infos[1]->name(), "NVIDIA CUDA");
    TS_ASSERT_EQUALS(infos[1]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[1]->extensions(), "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll");
  }
  /** // doc: test__query_platform_layer_info_2() {{{
   * \brief Test the get_devices() method.
   */ // }}}
  void test__query_platform_layer_info_2( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer layer(true);
    platform_layer_info p(query_platform_layer_info(layer));
    device_info_ptrs infos(p.get_devices());

    TS_ASSERT_EQUALS(infos.size(), 3);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[0]));
    TS_ASSERT_EQUALS(infos[0]->name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(infos[0]->driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.2 AMD-APP (1348.4)");

    TS_ASSERT_EQUALS(infos[1]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[1]));
    TS_ASSERT_EQUALS(infos[1]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[1]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[1]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[1]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[1]->version(), "OpenCL 1.0 CUDA");

    TS_ASSERT_EQUALS(infos[2]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[2]));
    TS_ASSERT_EQUALS(infos[2]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[2]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[2]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[2]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[2]->version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test__query_platform_layer_info_2() {{{
   * \brief Test the query_platform_layer_info(get_platforms()[0]) invocation.
   */ // }}}
  void test__query_platform_layer_info_3( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer layer(true);
    platform_layer_info p(query_platform_layer_info(layer));
    device_info_ptrs infos(p.get_devices(p.get_platforms()[0]));

    TS_ASSERT_EQUALS(infos.size(), 1);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[0]));
    TS_ASSERT_EQUALS(infos[0]->name(), "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "GenuineIntel");
    TS_ASSERT_EQUALS(infos[0]->driver_version(), "1348.4 (sse2)");
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.2 AMD-APP (1348.4)");
  }
  /** // doc: test__query_platform_layer_info_2() {{{
   * \brief Test the query_platform_layer_info(get_platforms()[0]) invocation.
   */ // }}}
  void test__query_platform_layer_info_4( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer layer(true);
    platform_layer_info p(query_platform_layer_info(layer));
    device_info_ptrs infos(p.get_devices(p.get_platforms()[1]));

    TS_ASSERT_EQUALS(infos.size(), 2);

    /* Check if we have obtained  correct information. It's far too much fields
     * to check them all, so we look only at some of them */
    TS_ASSERT_EQUALS(infos[0]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[1]));
    TS_ASSERT_EQUALS(infos[0]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[0]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[0]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[0]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[0]->version(), "OpenCL 1.0 CUDA");

    TS_ASSERT_EQUALS(infos[1]->id(), reinterpret_cast<unsigned long>(T::Newton_clGetDeviceIDs::devices[2]));
    TS_ASSERT_EQUALS(infos[1]->name(), "Tesla C1060");
    TS_ASSERT_EQUALS(infos[1]->vendor(), "NVIDIA Corporation");
    TS_ASSERT_EQUALS(infos[1]->driver_version(), "319.76");
    TS_ASSERT_EQUALS(infos[1]->profile(), "FULL_PROFILE");
    TS_ASSERT_EQUALS(infos[1]->version(), "OpenCL 1.0 CUDA");
  }
  /** // doc: test__query_platform_layer_info_5() {{{
   * \brief Test the get_devices(unknown_platform) invocation.
   */ // }}}
  void test__query_platform_layer_info_5( )
  {
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
    T::Dummy_clRetainDevice mockRetainDevice(CL_SUCCESS);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
    T::Dummy_clReleaseDevice mockReleaseDevice(CL_SUCCESS);
#endif
    T::Newton_clGetPlatformIDs mock1;
    T::Newton_clGetPlatformInfo mock2;
    T::Newton_clGetDeviceIDs mock3;
    T::Newton_clGetDeviceInfo mock4;
    platform_layer layer(true);
    platform_layer_info p(query_platform_layer_info(layer));
    const_platform_info_ptr unknown_platform(NULL);
    device_info_ptrs infos(p.get_devices(unknown_platform));

    TS_ASSERT(infos.empty());
  }
};

#endif /* CLXX_CL_PLATFORM_LAYER_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
