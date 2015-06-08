// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/context_property.hpp

/** // doc: clxx/context_property.hpp {{{
 * \file clxx/context_property.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CONTEXT_PROPERTY_HPP_INCLUDED
#define CLXX_CONTEXT_PROPERTY_HPP_INCLUDED

#include <clxx/util/context_property_type.hpp>
#include <clxx/types.hpp>
#include <clxx/platform.hpp>

namespace clxx {

/** \ingroup clxx_platform_layer
 * @{ */

/** // struct context_property {{{
 * \class context_property
 * \brief Encapsulate single OpenCL context property
 *
 * OpenCL uses so called "context properties" to parametrize OpenCL contexts.
 * OpenCL functions accept or return lists of these context properties. An
 * OpenCL list of context properties is simply a C array of type
 * \c cl_context_properties. Each property involves two elements of the array
 * &mdash; one for property name and one for property value.
 *
 * The \ref context_property structure represents a single named context
 * property. It encapsulates both, the property's name and value. It has also
 * the interface allowing read from and write to OpenCL arrays.
 */ // }}}
struct context_property
{
  /** // doc: class_version {{{
   * \brief Class version
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
  /** // doc: context_property() {{{
   * \brief Default constructor
   *
   * Initializes empty context property (with zeroed name and value).
   */ // }}}
  constexpr context_property() noexcept
    : _name(static_cast<context_properties_t>(0ul)), _value((cl_context_properties)0ul)
  {}
  /** // doc: context_property(context_properties_t, cl_context_properties) {{{
   * \brief Constructor
   *
   * \param name property name
   * \param value property value
   */ // }}}
  constexpr context_property(context_properties_t name, cl_context_properties value) noexcept
    : _name(name), _value(value)
  {}
  /** // doc: context_property(cl_context_properties, cl_context_properties) {{{
   * \brief Constructor
   *
   * \param name property name
   * \param value property value
   */ // }}}
  constexpr context_property(cl_context_properties name, cl_context_properties value) noexcept
    : _name(static_cast<context_properties_t>(name)), _value(value)
  {}
  /** // doc: context_property(platform const&) {{{
   * \brief Conversion from \ref platform to \ref context_property
   *
   * Initializes the \ref context_property setting \ref name() to \ref
   * context_properties_t::platform and \ref value() to **p.id()**.
   *
   * This constructor enables type promotion of \ref platform to \ref
   * context_property. It simplifies notation for \ref platform in several
   * expressions including the \c operator& and \ref make_context_properties()
   * function. For example, instead of writting
   * \code
   *  make_context_properties(context_platform(p))
   * \endcode
   * one just writes
   * \code
   *  make_context_properties(p)
   * \endcode
   *
   * \param p   platform used to initialize
   */ // }}}
  context_property(platform const& p) noexcept
    : _name(context_properties_t::platform), _value((cl_context_properties)p.id())
  {}
  /** // doc: name() const {{{
   * \brief Returns property's name
   * \returns The name of this property
   */ // }}}
  constexpr context_properties_t name() const noexcept
  { return _name; }
  /** // doc: value() const {{{
   * \brief Returns property's value
   * \returns The value of this property
   */ // }}}
  constexpr cl_context_properties value() const noexcept
  { return _value; }
  /** // doc: set_name() {{{
   * \brief Set property's name
   *
   * \param name new name for this property
   */ // }}}
  void set_name(context_properties_t name) noexcept
  { _name = name; }
  /** // doc: set_value() {{{
   * \brief Set property value
   *
   * \param value new value for this property
   */ // }}}
  void set_value(cl_context_properties value) noexcept
  { _value = value; }
  /** // doc: write(cl_context_properties*) const {{{
   * \brief Write the property to OpenCL array
   *
   * \param props pointer to the starting position of the destination array
   *
   * \note **props[0]** and **props[1]** must be writeable. The function **does
   *        not** append trailing zero to array.
   */ // }}}
  void write(cl_context_properties* props) const noexcept
  {
    props[0] = intval(_name);
    props[1] = _value;
  }
  /** // doc: read(const cl_context_properties*) {{{
   * \brief Read single property from OpenCL array
   *
   * \param props pointer to the starting position of the source array
   *
   * \note **props[0]** and **props[1]** must be readable.
   */ // }}}
  void read(const cl_context_properties* props) noexcept
  {
    _name = static_cast<context_properties_t>(props[0]);
    _value = props[1];
  }
  /** // doc: size() {{{
   * \brief Return size of the property
   *
   * \returns number of elements occupied by the property when stored in an
   *          OpenCL array.
   */ // }}}
  constexpr size_t size() const noexcept
  { return 2; }
private:
  context_properties_t _name;
  cl_context_properties _value;
};
/** @} */

/** \ingroup clxx_platform_layer
 * @{ */
/** // doc: make_context_property_c<N>(context_property_type<N>::type) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * \tparam N property name
 * \param x Property value
 *
 * \returns A new instance of \ref clxx::context_property with value
 *  initialized to \b x.
 */ // }}}
template <context_properties_t N>
constexpr context_property
make_context_property(typename context_property_type<N>::type x) noexcept
{
  return context_property(N, (cl_context_properties)x);
}
/** // doc: context_platform(cl_platform_id) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_platform(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::platform>(x);
 * \endcode
 */ // }}}
constexpr context_property
context_platform(cl_platform_id x) noexcept
  {
    return make_context_property<context_properties_t::platform>(x);
  }
/** // doc: context_platform(platform) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_platform(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = context_platform(x.id());
 * \endcode
 */ // }}}
inline context_property
context_platform(const platform& x) noexcept
  {
    return context_platform(x.id());
  }
/** // doc: context_interop_user_sync(bool) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_interop_user_sync(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::interop_user_sync>(x);
 * \endcode
 */ // }}}
constexpr context_property
context_interop_user_sync(bool x) noexcept
  {
    return make_context_property<context_properties_t::interop_user_sync>(x);
  }

#if cl_khr_gl_sharing
/** // doc: context_gl_context_khr(void*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_gl_context_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::gl_context_khr>(x);
 * \endcode
 *
 * The function is defined only when \c cl_khr_gl_sharing extension is enabled.
 */ // }}}
constexpr context_property
context_gl_context_khr(void* x) noexcept
  {
    return make_context_property<context_properties_t::gl_context_khr>(x);
  }
/** // doc: context_el_display_khr(void*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_egl_display_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::egl_display_khr>(x);
 * \endcode
 *
 * The function is defined only when \c cl_khr_gl_sharing extension is enabled.
 */ // }}}
constexpr context_property
context_egl_display_khr(void* x) noexcept
  {
    return make_context_property<context_properties_t::egl_display_khr>(x);
  }
/** // doc: context_glx_display_khr(void*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_glx_display_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::glx_display_khr>(x);
 * \endcode
 *
 * The function is defined only when \c cl_khr_gl_sharing extension is enabled.
 */ // }}}
constexpr context_property
context_glx_display_khr(void* x) noexcept
  {
    return make_context_property<context_properties_t::glx_display_khr>(x);
  }
/** // doc: context_wgl_hdc_khr(void*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_wgl_hdc_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::wgl_hdc_khr>(x);
 * \endcode
 *
 * The function is defined only when \c cl_khr_gl_sharing extension is enabled.
 */ // }}}
constexpr context_property
context_wgl_hdc_khr(void* x) noexcept
  {
    return make_context_property<context_properties_t::wgl_hdc_khr>(x);
  }
/** // doc: context_cgl_sharegroup_khr(void*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_cgl_sharegroup_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::cgl_sharegroup_khr>(x);
 * \endcode
 *
 * The function is defined only when \c cl_khr_gl_sharing extension is enabled.
 */ // }}}
constexpr context_property
context_cgl_sharegroup_khr(void* x) noexcept
  {
    return make_context_property<context_properties_t::cgl_sharegroup_khr>(x);
  }
#endif

#if cl_khr_dx9_media_sharing && defined(_WIN32)
/** // doc: context_adapter_d3d9_khr(IDirect3DDevice9*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_adapter_d3d9_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::adapter_d3d9_khr>(x);
 * \endcode
 *
 * The function is defined only on Windows when \c cl_khr_dx9_media_sharing
 * extension is enabled.
 */ // }}}
constexpr context_property
context_adapter_d3d9_khr(IDirect3DDevice9* x) noexcept
  {
    return make_context_property<context_properties_t::adapter_d3d9_khr>(x);
  }
/** // doc: context_adapter_d3d9ex_khr(IDirect3DDeviceEx*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_adapter_d3d9ex_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::adapter_d3d9ex_khr>(x);
 * \endcode
 *
 * The function is defined only on Windows when \c cl_khr_dx9_media_sharing
 * extension is enabled.
 */ // }}}
constexpr context_property
context_adapter_d3d9ex_khr(IDirect3DDeviceEx* x) noexcept
  {
    return make_context_property<context_properties_t::adapter_d3d9ex_khr>(x);
  }
/** // doc: context_adapter_dxva_khr(IDXVAHD_Device*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_adapter_dxva_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::adapter_dxva_khr>(x);
 * \endcode
 *
 * The function is defined only on Windows when \c cl_khr_dx9_media_sharing
 * extension is enabled.
 */ // }}}
constexpr context_property
context_adapter_dxva_khr(IDXVAHD_Device* x) noexcept
  {
    return make_context_property<context_properties_t::adapter_dxva_khr>(x);
  }
#endif

#if cl_khr_d3d10_sharing
/** // doc: context_d3d10_device_khr(ID3D10Device*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_d3d10_device_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::d3d10_device_khr>(x);
 * \endcode
 *
 * The function is defined only when \c cl_khr_d3d10_sharing extension is
 * enabled.
 */ // }}}
constexpr context_property
context_d3d10_device_khr(ID3D10Device* x) noexcept
  {
    return make_context_property<context_properties_t::d3d10_device_khr>(x);
  }
#endif

#if cl_khr_d3d11_sharing
/** // doc: context_d3d11_device_khr(ID3D11Device*) {{{
 * \brief Type-safe constructor for \ref clxx::context_property
 *
 * The invocation
 * \code
 *   y = context_d3d11_device_khr(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_context_property<context_properties_t::d3d11_device_khr>(x);
 * \endcode
 *
 * The function is defined only when \c cl_khr_d3d11_sharing extension is
 * enabled.
 */ // }}}
constexpr context_property
context_d3d11_device_khr(ID3D11Device* x) noexcept
  {
    return make_context_property<context_properties_t::d3d11_device_khr>(x);
  }
#endif
/** @} */

} // end namespace clxx

#endif /* CLXX_CONTEXT_PROPERTY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
