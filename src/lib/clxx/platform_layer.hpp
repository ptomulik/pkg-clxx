// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_layer.hpp

/** // doc: clxx/platform_layer.hpp {{{
 * \file clxx/platform_layer.hpp
 * \brief Defines the \ref clxx::platform_layer "platform_layer" class
 */ // }}}
#ifndef CLXX_PLATFORM_LAYER_HPP_INCLUDED
#define CLXX_PLATFORM_LAYER_HPP_INCLUDED

#include <clxx/platforms.hpp>
#include <clxx/devices.hpp>

#include <clxx/platform_layer_info.hpp>
#include <clxx/platform_query.hpp>
#include <clxx/device_query.hpp>

#include <set>
#include <map>
#include <vector>

namespace clxx {

/** // doc: class platform_layer {{{
 * \ingroup clxx_platform_layer
 *
 * Simple associative container to store \ref clxx::device "devices",
 * \ref clxx::platform "platforms" and relations between them. Note, that this
 * is just a container. It's not synchronized with OpenCL platform layer by
 * definition (it may be filled-in quite arbitrarily by user). However, it has
 * an interface that allows to initialize it with the actual data retrieved
 * from OpenCL, see \ref load_opencl().
 *
 * The implemented relations fulfill the following constraints (enforced
 * internally by the class):
 *
 *  - each \ref clxx::device "device" stored in the container refers exactly
 *    one \ref clxx::platform "platform" (also stored in the container),
 *  - each \ref clxx::platform "platform" stored in the container is referred
 *    by one or more \ref clxx::device "devices" (stored in the container).
 *
 * The contents may be accessed by the following methods:
 *
 *  - \ref get_devices() const get_devices() returns a plain sequence of
 *    \ref clxx::device "devices", where the \ref clxx::device "devices" appear
 *    in the same order as they were added to the container,
 *  - \ref get_platforms() const get_platforms() returns a plain sequence of
 *    \ref clxx::platform "platforms", where the \ref clxx::platform "platforms"
 *    appear in the same order as they were added to the container,
 *  - \ref get_devices(platform const&) const get_devices(platform const&)
 *    returns plain sequence of \ref clxx::device "devices" that refer given
 *    platform,
 *  - \ref get_platform(device const&) const get_platform(device const&)
 *    returns a \ref clxx::platform "platform" referred by given device,
 *
 * The contents may be modified by the following methods:
 *
 *   - \ref add(device const&, platform const&) stores device, platform and
 *     relation between device and platform in the container,
 *   - \ref add(devices const&, platform const&) stores multiple devices and a
 *     single platform at once and establishes relations between devices and
 *     the platform,
 *   - \ref erase(device const&) removes device from the container, if it was
 *     the last device referencing its platform, the platform will also be
 *     removed from container,
 *   - \ref clear() clears the container entirely.
 *
 * and
 *
 *   - \ref load_opencl(device_type_t) retrieves the platforms, devices and
 *     relations from OpenCL platform layer and adds them to the container.
 *     Note, that this appends stuff to- or overrides the existing content.
 *
 * The container may also be filled-in with a data obtained from OpenCL at
 * initialization phase (in constructor).
 */ // }}}
class platform_layer
{
public:
  /** // doc: device_platform_map {{{
   * \brief Map type used to map devices to their platforms
   */ // }}}
  typedef std::map<device, platform> device_platform_map;
public:
  /** // doc: platform_layer() {{{
   * \brief Default constructor
   *
   * Initializes empty container.
   */ // }}}
  platform_layer() noexcept;
  /** // doc: platform_layer(device_type_t) {{{
   * \brief Constructor
   *
   * Initializes container with OpenCL data.
   *
   * \param type OpenCL device type, retrieve only devices of a given type.
   *
   * \code
   *  platform_layer pl(t);
   * \endcode
   *
   * is equivalent to:
   *
   * \code
   *  platform_layer pl;
   *  pl.load_opencl(t);
   * \endcode
   *
   * \throws clerror_no<status_t::invalid_device_type>
   *    propagated from clxx::get_device_ids()
   * \throws clerror_no<status_t::invalid_platform>
   *    propagated from clxx::get_device_ids()
   * \throws clerror_no<status_t::invalid_value>
   *    propagated from clxx::get_device_ids() and clxx::get_platform_ids()
   * \throws clerror_no<status_t::out_of_host_memory>
   *    propagated from clxx::get_device_ids() and clxx::get_platform_ids()
   * \throws clerror_no<status_t::out_of_resources>
   *    propagated from clxx::get_device_ids()
   * \throws std::bad_alloc
   *    may be raised occasionally
   */ // }}}
  platform_layer(device_type_t type);
  /** // doc: platform_layer(bool, device_type_t) {{{
   * \brief Constructor
   *
   * Either, initializes empty container or retrieves data from OpenCL,
   * depending on the value of \e load flag. The following calls are
   * equivalent
   *
   * \code
   *  platform_layer(false);         // =>  platform_layer();
   *  platform_layer(false, type);   // =>  platform_layer();
   *  platform_layer(true);          // =>  platform_layer(device_type_t::all);
   *  platform_layer(true, type);    // =>  platform_layer(type);
   * \endcode
   *
   *
   * \param load  decides whether to load OpenCL platform layer layout or not,
   * \param type  if \e load is \c true, then retrieve from OpenCL only devices
   *  of this \e type
   *
   * \throws clerror_no<status_t::invalid_device_type>
   *    propagated from clxx::get_device_ids()
   * \throws clerror_no<status_t::invalid_platform>
   *    propagated from clxx::get_device_ids()
   * \throws clerror_no<status_t::invalid_value>
   *    propagated from clxx::get_device_ids() and clxx::get_platform_ids()
   * \throws clerror_no<status_t::out_of_host_memory>
   *    propagated from clxx::get_device_ids() and clxx::get_platform_ids()
   * \throws clerror_no<status_t::out_of_resources>
   *    propagated from clxx::get_device_ids()
   * \throws std::bad_alloc
   *    may be raised occasionally
   */ // }}}
  platform_layer(bool load, device_type_t type = device_type_t::all);
  /** // doc: ~platform_layer() {{{
   * \brief Destructor
   */ // }}}
  virtual ~platform_layer() noexcept;
  /** // doc: get_platforms() {{{
   * \fn get_platforms() const
   * \brief Get platforms
   *
   * Return flat sequence of platforms stored in container. The order of
   * elements in sequence is same as the order of their insertion to the
   * container.
   *
   * \returns flat sequence of platforms stored in container.
   */ // }}}
  platforms const& get_platforms() const noexcept;
  /** // doc: get_devices() {{{
   * \fn get_devices() const
   * \brief Get devices
   *
   * Returns flat sequence of devices stored in container. The order of
   * elements in sequence is same as the order of their insertion to the
   * container.
   *
   * \returns sequence of devices stored in container.
   */ // }}}
  devices const& get_devices() const noexcept;
  /** // doc: get_devices(platform const&) {{{
   * \fn get_devices(platform const&) const
   * \brief Get devices that refer platform \e p
   * \param p the platform
   * \returns flat sequence of devices that reference platform \e p
   * \throws std::bad_alloc may be raised occasionally
   */ // }}}
  devices get_devices(platform const& p) const;
  /** // doc: get_platform(device const&) {{{
   * \fn get_platform(device const&) const
   * \brief Get platform referenced by given device
   * \param d the device
   * \throws invalid_key_error if \e d does not exist in the container
   * \returns a platform referred by \e d.
   */ // }}}
  platform const& get_platform(device const& d) const;
  /** // doc: has_device(device const&) {{{
   * \brief Check presence of device \e d in container
   * \param d the \ref clxx::device "device" to check
   * \returns \c true if device is found in container, otherwise \c false
   */ // }}}
  bool has_device(device const& d) const noexcept;
  /** // doc: has_platform(platform const&) {{{
   * \brief Check presence of platform \e p in container
   * \param p the \ref clxx::platform "platform" to check
   * \returns \c true if device is found in container, otherwise \c false
   */ // }}}
  bool has_platform(platform const& p) const noexcept;
  /** // doc: add(platform const&, device const&) {{{
   * \brief Add device to container
   * \param d device,
   * \param p platform referenced by device \e d
   * \returns \c true if the number of devices in container increased,
   *    if the device already existed in container returns \c false
   * \throws std::bad_alloc may be raised occasionally
   */ // }}}
  bool add(device const& d, platform const& p);
  /** // doc: add(platform const&, devices const&) {{{
   * \brief Add device to container
   * \param ds devices
   * \param p platform referenced by devices \e ds
   * \returns number of new devices added to container, the devices that
   *    already existed in container are not counted in the return value
   * \throws std::bad_alloc may be raised occasionally
   */ // }}}
  size_t add(devices const& ds, platform const& p);
  /** // doc: erase(device const&) {{{
   * \brief Remove device from container
   * \param d the device to remove from container
   * \throws invalid_key_error if \e d does not exist in the container
   * \throws std::bad_alloc may be raised occasionally
   */ // }}}
  void erase(device const& d);
  /** // doc: erase(device const&) {{{
   * \brief Remove from container all devices of a given platform
   * \param p the platform whose devices are to be removed from container
   * \throws invalid_key_error if \e p does not exist in the container
   * \throws std::bad_alloc may be raised occasionally
   */ // }}}
  void erase(platform const& p);
  /** // doc: clear() {{{
   * \brief Clear the container entirelly
   * \throws std::bad_alloc may be raised occasionally
   */ // }}}
  void clear() noexcept;
  /** // doc: load_opencl(device_type_t) {{{
   * \brief Retrieve and load data from OpenCL
   *
   * This function retrieves from OpenCL and stores in container the platform
   * layer layout (devices, platforms and relations).
   *
   * \param type retrieve only devices of given type
   *
   * \throws clerror_no<status_t::invalid_device_type>
   *    propagated from clxx::get_device_ids()
   * \throws clerror_no<status_t::invalid_platform>
   *    propagated from clxx::get_device_ids()
   * \throws clerror_no<status_t::invalid_value>
   *    propagated from clxx::get_device_ids() and clxx::get_platform_ids()
   * \throws clerror_no<status_t::out_of_host_memory>
   *    propagated from clxx::get_device_ids() and clxx::get_platform_ids()
   * \throws clerror_no<status_t::out_of_resources>
   *    propagated from clxx::get_device_ids()
   * \throws std::bad_alloc
   *    may be raised occasionally
   */ // }}}
  void load_opencl(device_type_t type = device_type_t::all);
private:
  platforms _platforms;
  devices _devices;
  device_platform_map _device_platform;
};

/** \addtogroup clxx_info
 * @{ */
/** // doc: query_platform_layer_info(layer,pquery,dquery) {{{
 * \brief Perform an aggregate query on multiple platforms and devices
 *
 * Queries multiple OpenCL platforms and their devices for information
 * specified in \em pquery and \em dquery respectivelly. Internally this yields
 * a series of calls to \ref clxx::query_platform_info()
 * "query_platform_info()" and \ref clxx::query_device_info()
 * "query_device_info()".
 *
 * \param layer   A \ref clxx::platform_layer "platform_layer" to be queried
 * \param pquery  What information to retrieve from platforms.
 * \param dquery  What information to retrieve from devices.
 * \returns \ref clxx::platform_layer_info "platform_layer_info" object
 *    containing the result of the query.
 *
 * \par Example
 *
 * Print complete information about all OpenCL platforms/devices available
 *
 * \snippet clxx/query_platform_layer_info1.cpp Program
 */ // }}}
platform_layer_info
query_platform_layer_info(
    platform_layer const& layer = platform_layer(device_type_t::all),
    platform_query const& pquery = platform_query(),
    device_query const& dquery = device_query()
);
/** @} */
} // end namespace clxx

#endif /* CLXX_PLATFORM_LAYER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
