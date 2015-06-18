// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_layer_info.hpp

/** // doc: clxx/platform_layer_info.hpp {{{
 * \file clxx/platform_layer_info.hpp
 * \brief Defines \ref clxx::platform_layer_info "platform_layer_info" class
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
 * \ingroup clxx_info
 * \brief Platform layer info
 *
 * This object gathers together a couple of \ref clxx::platform_info
 * "platform_infos" and \ref clxx::device_info "device_infos" to represent
 * a complete information about an OpenCL platform layer (including, for
 * example, all locally available platforms together with their devices).
 *
 * It's possible to preserve the original layout of an OpenCL platform layer,
 * and browse through either platforms or devices.
 */ // }}}
class platform_layer_info
{
  template <class Archive>
  friend void _serialize(Archive&, platform_layer_info&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \brief Class version number
   *
   * This is used by the serialization machinery (see \ref clxx_s11n)
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
private:
  typedef boost::bimaps::vector_of<const_platform_info_ptr> Left_Set;
  typedef boost::bimaps::set_of<const_device_info_ptr> Right_Set;
  typedef boost::bimaps::bimap<Left_Set, Right_Set> bimap;

public:
  /** // doc: platform_layer_info() {{{
   * \brief Default constructor
   *
   * Initializes an empty platform_layer_info object.
   */ // }}}
  platform_layer_info();
  /** // doc: ~platform_layer_info() {{{
   * \brief Destructor
   */ // }}}
  virtual ~platform_layer_info();
  /** // doc: clear() {{{
   * \brief Clears the whole platform layer info
   *
   * This deletes all the platform and device infos contained in the object.
   */ // }}}
  void clear();
  /** // doc: platforms() {{{
   * \brief Retrieve all the platform infos
   * \returns A sequence of pointers to platform_info objects for the platform
   *          layer described by this object
   */ // }}}
  platform_info_ptrs get_platforms();
  /** // doc: platforms() {{{
   * \brief Retrieve all the platform infos (const version)
   * \returns A sequence of pointers to platform_info objects for the platform
   *          layer described by this object
   */ // }}}
  const_platform_info_ptrs get_platforms() const;
  /** // doc: get_platform() {{{
   * \brief Get a platform info for given device
   *
   * The \em dev must belong to this platform layer, that is it must be stored
   * in this #platform_layer_info object. In short, it must be one of the
   * pointers returned by #get_devices().
   *
   * \param dev A pointer to device info for which the platform has to be returned
   * \returns A pointer to the platform requested
   */ // }}}
  platform_info_ptr get_platform(const_device_info_ptr dev);
  /** // doc: get_platform() {{{
   * \brief Get a platform info for given device (const version)
   *
   * The \em dev must belong to this platform layer, that is it must be stored
   * in this #platform_layer_info object. In short, it must be one of the
   * pointers returned by #get_devices() const.
   *
   * \param dev A pointer to device info for which the platform has to be returned
   * \returns A pointer to the platform requested
   */ // }}}
  const_platform_info_ptr get_platform(const_device_info_ptr dev) const;
  /** // doc: get_devices() {{{
   * \brief Get devices that belong to this platform layer
   * \return A sequence of pointers to \ref clxx::device_info "device_infos"
   *         that belong to this #platform_layer_info.
   */ // }}}
  device_info_ptrs get_devices();
  /** // doc: get_devices() {{{
   * \brief Get devices that belong to this platform layer
   * \return A sequence of pointers to \ref clxx::device_info "device_infos"
   *         that belong to this #platform_layer_info.
   */ // }}}
  const_device_info_ptrs get_devices() const;
  /** // doc: get_devices(plat) {{{
   * \brief Get devices that belong to a given platform
   * \param plat Platform info for the platform in question.
   * \return A sequence of pointers to \ref clxx::device_info "device_infos"
   *         that belong to the platform \em plat.
   */ // }}}
  device_info_ptrs get_devices(const_platform_info_ptr plat);
  /** // doc: get_devices(plat) {{{
   * \brief Get devices that belong to a given platform (const version)
   * \param plat Platform info for the platform in question.
   * \return A sequence of pointers to \ref clxx::device_info "device_infos"
   *         that belong to the platform \em plat.
   */ // }}}
  const_device_info_ptrs get_devices(const_platform_info_ptr plat) const;
  /** // doc: push_back(dev) {{{// end namespace clxx
   * \brief Add device (together with its platform) to #platform_layer_info
   * \param dev Device to be included.
   * \param plat Platform, to which the device \em dev belongs.
   */ // }}}
  void push_back(device_info_ptr dev, platform_info_ptr plat);
  /** // doc: remove(dev) {{{
   * \brief Remove a platform from the #platform_layer_info
   *
   * Together with platform, all their devices get removed from
   * #platform_layer_info.
   *
   * \param plat The platform to be removed
   */ // }}}
  void remove(const_platform_info_ptr plat);
  /** // doc: remove(dev) {{{
   * \brief Remove a device from the #platform_layer_info
   * \param dev Device to be removed
   *
   * When last device of some platform gets removed, the platform gets
   * automatically removed from #platform_layer_info automatically.
   */ // }}}
  void remove(const_device_info_ptr dev);
  /** // doc: empty() {{{
   * \brief Whether this object is empty
   * \returns \c true if there is no device nor platform infos in the object
   */ // }}}
  bool empty() const;
  /** // doc: cmp(p) {{{
   * \brief Compare this object with an other one
   * \param other The other object to be compared with this one
   *
   * Two \ref clxx::platform_layer_info "platform_layer_infos" are equal if and
   * only if
   *
   * - they're equal in size (have same number of platforms/devices), and
   * - underlying platform layers they describe have same layout, and
   * - corresponding platform infos and device infos on both sides are equal.
   *
   * \returns \c true if this object equals the other or \c false otherwise
   */ // }}}
  bool cmp(platform_layer_info const& other) const;
  /** // doc: indices() {{{
   * \brief Indices that describe mapping of devices to their platforms in
   *        #platform_layer_info container
   *
   * The #platform_layer_info object contains a set of
   * \ref clxx::platform_info "platform_info" objects and a set of
   * \ref clxx::device_info "device_info" objects. Each device shall be related
   * to one of the platforms contained in the #platform_layer_info. The
   * sequence of \ref clxx::platform_info "platform_infos" can be retrieved
   * with #get_platforms() whereas the sequence of \ref clxx::device_info
   * "device_infos" may be obtained with #get_devices().
   *
   * The indices returned by #indices() establish the mapping between devices
   * retrieved with #get_devices() and their platforms as obtained by
   * #get_platforms(). The notation
   *
   * \code
   *    get_platforms()[indices()[i]]
   * \endcode
   *
   * returns a platform info for platform of device <tt>devices()[i]</tt>.
   *
   * \returns A vector of integer indices that define the mapping
   */ // }}}
  std::vector<int> indices() const;
private:
  bimap _bimap;
};

/** \addtogroup clxx_info
 * @{ */
/** // doc: operator==(l,r) {{{
 * \brief Compare two \ref clxx::platform_layer_info "platform_layer_infos"
 *
 * See the \ref clxx::platform_layer_info::cmp() for definition of the
 * \ref clxx::platform_layer_info "platform_layer_info's" equality.
 *
 * \param a Left hand side operand to the comparison
 * \param b Right hand side operand to the comparison
 * \returns \c true if two infos are same or \c false otherwise
 */ // }}}
inline bool operator==(platform_layer_info const& a, platform_layer_info const& b)
{
  return a.cmp(b);
}
/** // doc: operator!=(l,r) {{{
 * \brief Compare two \ref clxx::platform_layer_info "platform_layer_infos"
 *
 * See the \ref clxx::platform_layer_info::cmp() for definition of the
 * \ref clxx::platform_layer_info "platform_layer_info's" equality.
 *
 * \param a Left hand side operand to the comparison
 * \param b Right hand side operand to the comparison
 * \returns \c false if two infos are same or \c true otherwise
 */ // }}}
inline bool operator!=(platform_layer_info const& a, platform_layer_info const& b)
{
  return !a.cmp(b);
}
/** @} */
} // end namespace clxx

#endif /* CLXX_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
