// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/context_property.t.h

/** // doc: clxx/context_property.t.h {{{
 * \file clxx/context_property.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CONTEXT_PROPERTY_T_H_INCLUDED
#define CLXX_CONTEXT_PROPERTY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/context_property.hpp>

namespace clxx { class context_property_test_suite; }

/** // doc: class clxx::context_property_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::context_property_test_suite : public CxxTest::TestSuite
{
  void call_with_context_property(context_property const&) { }
public:
  /** // doc: test_default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_ctor( )
  {
    TS_ASSERT_THROWS_NOTHING(context_property());
    TS_ASSERT_EQUALS(context_property().name(),static_cast<context_properties_t>((cl_context_properties)0ul));
    TS_ASSERT_EQUALS(context_property().value(),(cl_context_properties)0ul);
  }
  /** // doc: test_ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1( )
  {
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::platform, (cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::interop_user_sync, (cl_context_properties)true));
#if cl_khr_gl_sharing
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::gl_context_khr,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::egl_display_khr,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::glx_display_khr,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::wgl_hdc_khr,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::cgl_sharegroup_khr,(cl_context_properties)nullptr));
#endif

#if cl_khr_dx9_media_sharing && defined(_WIN32)
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::adapter_d3d9_khr,(cl_context_properties)((IDirect3DDevice9*)nullptr)));
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::adapter_d3d9ex_khr,(cl_context_properties)((IDirect3DDeviceEx*)nullptr)));
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::adapter_dxva_khr,(cl_context_properties)((IDXVAHD_Device*)nullptr)));
#endif

#if cl_khr_d3d10_sharing
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::d3d10_device_khr,(cl_context_properties)((ID3D10Device*)nullptr)));
#endif

#if cl_khr_d3d11_sharing
    TS_ASSERT_THROWS_NOTHING(context_property(context_properties_t::d3d11_device_khr,(cl_context_properties)((ID3D11Device*)nullptr)));
#endif
  }
  /** // doc: test_ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2( )
  {
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CONTEXT_PLATFORM, (cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CONTEXT_INTEROP_USER_SYNC, (cl_context_properties)true));
#if cl_khr_gl_sharing
    TS_ASSERT_THROWS_NOTHING(context_property(CL_GL_CONTEXT_KHR,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(CL_EGL_DISPLAY_KHR,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(CL_GLX_DISPLAY_KHR,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(CL_WGL_HDC_KHR,(cl_context_properties)nullptr));
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CGL_SHAREGROUP_KHR,(cl_context_properties)nullptr));
#endif

#if cl_khr_dx9_media_sharing && defined(_WIN32)
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CONTEXT_ADAPTER_D3D9_KHR,(cl_context_properties)((IDirect3DDevice9*)nullptr)));
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CONTEXT_ADAPTER_D3D9EX_KHR,(cl_context_properties)((IDirect3DDeviceEx*)nullptr)));
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CONTEXT_ADAPTER_DXVA_KHR,(cl_context_properties)((IDXVAHD_Device*)nullptr)));
#endif

#if cl_khr_d3d10_sharing
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CONTEXT_D3D10_DEVICE_KHR,(cl_context_properties)((ID3D10Device*)nullptr)));
#endif

#if cl_khr_d3d11_sharing
    TS_ASSERT_THROWS_NOTHING(context_property(CL_CONTEXT_D3D11_DEVICE_KHR,(cl_context_properties)((ID3D11Device*)nullptr)));
#endif
  }
  /** // doc: test_ctor_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_3( )
  {
    platform p((cl_platform_id)0x1234);
    TS_ASSERT_THROWS_NOTHING(context_property(p));
    TS_ASSERT_THROWS_NOTHING(call_with_context_property(p));
  }
  /** // doc: test_name() {{{
   * \todo Write documentation
   */ // }}}
  void test_name( )
  {
    TS_ASSERT_EQUALS(context_property(context_properties_t::interop_user_sync, false).name(), context_properties_t::interop_user_sync);
  }
  /** // doc: test_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_value( )
  {
    TS_ASSERT_EQUALS(context_property(context_properties_t::interop_user_sync, false).value(), (cl_context_properties)CL_FALSE);
    TS_ASSERT_EQUALS(context_property(context_properties_t::interop_user_sync, true).value(), (cl_context_properties)CL_TRUE);
  }
  /** // doc: test_set_name() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_name( )
  {
    context_property cp;
    TS_ASSERT_THROWS_NOTHING(cp.set_name(context_properties_t::platform));
    TS_ASSERT_EQUALS(cp.name(), context_properties_t::platform);
    TS_ASSERT_THROWS_NOTHING(cp.set_name(context_properties_t::interop_user_sync));
    TS_ASSERT_EQUALS(cp.name(), context_properties_t::interop_user_sync);
  }
  /** // doc: test_set_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_value( )
  {
    context_property cp;
    TS_ASSERT_THROWS_NOTHING(cp.set_value((cl_context_properties)0));
    TS_ASSERT_EQUALS(cp.value(), (cl_context_properties)0);
    TS_ASSERT_THROWS_NOTHING(cp.set_value((cl_context_properties)123));
    TS_ASSERT_EQUALS(cp.value(), (cl_context_properties)123);
  }
  /** // doc: test_write() {{{
   * \todo Write documentation
   */ // }}}
  void test_write( )
  {
    cl_context_properties array[3] = {(cl_context_properties)0, (cl_context_properties)0, (cl_context_properties)123};
    context_property cp(context_properties_t::interop_user_sync, true);
    cp.write(array);
    TS_ASSERT_EQUALS(array[0], (cl_context_properties)CL_CONTEXT_INTEROP_USER_SYNC);
    TS_ASSERT_EQUALS(array[1], (cl_context_properties)CL_TRUE);
    TS_ASSERT_EQUALS(array[2], (cl_context_properties)123);
  }
  /** // doc: test_read() {{{
   * \todo Write documentation
   */ // }}}
  void test_read( )
  {
    cl_context_properties array[3] = {CL_CONTEXT_INTEROP_USER_SYNC, CL_TRUE, (cl_context_properties)1234};
    context_property cp;
    cp.read(array);
    TS_ASSERT_EQUALS(cp.name(), context_properties_t::interop_user_sync);
    TS_ASSERT_EQUALS(cp.value(), (cl_context_properties)CL_TRUE);
  }
  /** // doc: test_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_size( )
  {
    TS_ASSERT_EQUALS(context_property(context_properties_t::interop_user_sync, false).size(), 2);
  }
  /** // doc: test_make_context_property() {{{
   * \todo Write documentation
   */ // }}}
  void test_make_context_property( )
  {
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::platform>(nullptr).name(),context_properties_t::platform);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::platform>(nullptr).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::interop_user_sync>(false).name(),context_properties_t::interop_user_sync);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::interop_user_sync>(false).value(),(cl_context_properties)false);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::interop_user_sync>(true).name(),context_properties_t::interop_user_sync);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::interop_user_sync>(true).value(),(cl_context_properties)true);
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::gl_context_khr>(nullptr).name(),context_properties_t::gl_context_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::gl_context_khr>(nullptr).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::egl_display_khr>(nullptr).name(),context_properties_t::egl_display_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::egl_display_khr>(nullptr).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::glx_display_khr>(nullptr).name(),context_properties_t::glx_display_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::glx_display_khr>(nullptr).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::wgl_hdc_khr>(nullptr).name(),context_properties_t::wgl_hdc_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::wgl_hdc_khr>(nullptr).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::cgl_sharegroup_khr>(nullptr).name(),context_properties_t::cgl_sharegroup_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::cgl_sharegroup_khr>(nullptr).value(),(cl_context_properties)nullptr);
#endif

#if cl_khr_dx9_media_sharing && defined(_WIN32)
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::adapter_d3d9_khr>(nullptr).name(),context_properties_t::adapter_d3d9_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::adapter_d3d9_khr>(nullptr).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::adapter_d3d9ex_khr>(nullptr).name(),context_properties_t::adapter_d3d9ex_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::adapter_d3d9ex_khr>(nullptr).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::adapter_dxva_khr>(nullptr).name(),context_properties_t::adapter_dxva_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::adapter_dxva_khr>(nullptr).value(),(cl_context_properties)nullptr);
#endif

#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::d3d10_device_khr>(nullptr).name(),context_properties_t::d3d10_device_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::d3d10_device_khr>(nullptr).value(),(cl_context_properties)nullptr);
#endif

#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::d3d11_device_khr>(nullptr).name(),context_properties_t::d3d11_device_khr);
    TS_ASSERT_EQUALS(make_context_property<context_properties_t::d3d11_device_khr>(nullptr).value(),(cl_context_properties)nullptr);
#endif
  }
  /** // doc: test_creators() {{{
   * \todo Write documentation
   */ // }}}
  void test_creators( )
  {
    TS_ASSERT_EQUALS(context_platform((cl_platform_id)0x1234).name(),context_properties_t::platform);
    TS_ASSERT_EQUALS(context_platform((cl_platform_id)0x1234).value(),(cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(context_platform(platform()).name(),context_properties_t::platform);
    TS_ASSERT_EQUALS(context_platform(platform()).value(),(cl_context_properties)nullptr);
    TS_ASSERT_EQUALS(context_interop_user_sync(true).name(),context_properties_t::interop_user_sync);
    TS_ASSERT_EQUALS(context_interop_user_sync(true).value(),(cl_context_properties)true);
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(context_gl_context_khr((void*)0x1234).name(),context_properties_t::gl_context_khr);
    TS_ASSERT_EQUALS(context_gl_context_khr((void*)0x1234).value(),(cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(context_egl_display_khr((void*)0x1234).name(),context_properties_t::egl_display_khr);
    TS_ASSERT_EQUALS(context_egl_display_khr((void*)0x1234).value(),(cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(context_glx_display_khr((void*)0x1234).name(),context_properties_t::glx_display_khr);
    TS_ASSERT_EQUALS(context_glx_display_khr((void*)0x1234).value(),(cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(context_wgl_hdc_khr((void*)0x1234).name(),context_properties_t::wgl_hdc_khr);
    TS_ASSERT_EQUALS(context_wgl_hdc_khr((void*)0x1234).value(),(cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(context_cgl_sharegroup_khr((void*)0x1234).name(),context_properties_t::cgl_sharegroup_khr);
    TS_ASSERT_EQUALS(context_cgl_sharegroup_khr((void*)0x1234).value(),(cl_context_properties)0x1234);
#endif

#if cl_khr_dx9_media_sharing && defined(_WIN32)
    TS_ASSERT_EQUALS(context_adapter_d3d9_khr((IDirect3DDevice9*)0x1234).name(),context_properties_t::adapter_d3d9_khr);
    TS_ASSERT_EQUALS(context_adapter_d3d9_khr((IDirect3DDevice9*)0x1234).value(),(cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(context_adapter_d3d9ex_khr((IDirect3DDeviceEx*)0x1234).name(),context_properties_t::adapter_d3d9ex_khr);
    TS_ASSERT_EQUALS(context_adapter_d3d9ex_khr((IDirect3DDeviceEx*)0x1234).value(),(cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(context_adapter_dxva_khr((IDXVAHD_Device*)0x1234).name(),context_properties_t::adapter_dxva_khr);
    TS_ASSERT_EQUALS(context_adapter_dxva_khr((IDXVAHD_Device*)0x1234).value(),(cl_context_properties)0x1234);
#endif

#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(context_d3d10_device_khr((ID3D10Device*)0x1234).name(),context_properties_t::d3d10_device_khr);
    TS_ASSERT_EQUALS(context_d3d10_device_khr((ID3D10Device*)0x1234).value(),(cl_context_properties)0x1234);
#endif

#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(context_d3d11_device_khr((ID3D11Device*)0x1234).name(),context_properties_t::d3d11_device_khr);
    TS_ASSERT_EQUALS(context_d3d11_device_khr((ID3D11Device*)0x1234).value(),(cl_context_properties)0x1234);
#endif
  }
};

#endif /* CLXX_CONTEXT_PROPERTY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
