// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_layer_info.hpp

/** // doc: clxx/platform_layer_info.hpp {{{
 * \file clxx/platform_layer_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PLATFORM_LAYER_INFO_HPP_INCLUDED
#define CLXX_PLATFORM_LAYER_INFO_HPP_INCLUDED

#include <clxx/platform_info_ptrs.hpp>
#include <clxx/device_info_ptrs.hpp>

#include <boost/bimap/bimap.hpp>
#include <boost/bimap/vector_of.hpp>
#include <boost/bimap/set_of.hpp>
#include <vector>

namespace clxx {

/** // doc: class platform_layer_info {{{
 * \ingroup Clxx_Clinfo_Platform
 * \todo Write documentation
 */ // }}}
class platform_layer_info
{
  template <class Archive>
  friend void _serialize(Archive&, platform_layer_info&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \todo Write documentation
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
private:
  typedef boost::bimaps::vector_of<const_platform_info_ptr> Left_Set;
  typedef boost::bimaps::set_of<const_device_info_ptr> Right_Set;
  typedef boost::bimaps::bimap<Left_Set, Right_Set> bimap;

public:
  /** // doc: platform_layer_info() {{{
   * \todo Write documentation
   */ // }}}
  platform_layer_info();
  /** // doc: ~platform_layer_info() {{{
   * \todo Write documentation for class platform_layer_info
   */ // }}}
  virtual ~platform_layer_info();
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  void clear();
  /** // doc: platforms() {{{
   * \todo Write documentation
   */ // }}}
  platform_info_ptrs get_platforms();
  /** // doc: platforms() {{{
   * \todo Write documentation
   */ // }}}
  const_platform_info_ptrs get_platforms() const;
  /** // doc: get_platform() {{{
   * \todo Write documentation
   */ // }}}
  platform_info_ptr get_platform(const_device_info_ptr dev);
  /** // doc: get_platform() {{{
   * \todo Write documentation
   */ // }}}
  const_platform_info_ptr get_platform(const_device_info_ptr dev) const;
  /** // doc: get_devices() {{{
   * \todo Write documentation
   */ // }}}
  device_info_ptrs get_devices();
  /** // doc: get_devices() {{{
   * \todo Write documentation
   */ // }}}
  const_device_info_ptrs get_devices() const;
  /** // doc: get_devices(plat) {{{
   * \todo Write documentation
   */ // }}}
  device_info_ptrs get_devices(const_platform_info_ptr plat);
  /** // doc: get_devices(plat) {{{
   * \todo Write documentation
   */ // }}}
  const_device_info_ptrs get_devices(const_platform_info_ptr plat) const;
  /** // doc: push_back(dev) {{{// end namespace clxx
   * \todo Write documentation
   */ // }}}
  void push_back(device_info_ptr dev, platform_info_ptr plat);
  /** // doc: remove(dev) {{{
   * \todo Write documentation
   */ // }}}
  void remove(const_platform_info_ptr plat);
  /** // doc: remove(dev) {{{
   * \todo Write documentation
   */ // }}}
  void remove(const_device_info_ptr dev);
  /** // doc: empty() {{{
   * \todo Write documentation
   */ // }}}
  bool empty() const;
  /** // doc: cmp(p) {{{
   * \todo Write documentation
   */ // }}}
  bool cmp(platform_layer_info const& p) const;
  /** // doc: indices() {{{
   * \todo Write documentation
   */ // }}}
  std::vector<int> indices() const;
private:
  bimap _bimap;
};

/** // doc: operator==(l,r) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator==(platform_layer_info const& a, platform_layer_info const& b)
{
  return a.cmp(b);
}
/** // doc: operator!=(l,r) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!=(platform_layer_info const& a, platform_layer_info const& b)
{
  return !a.cmp(b);
}

} // end namespace clxx

#endif /* CLXX_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
