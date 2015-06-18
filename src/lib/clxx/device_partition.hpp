// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_partition.hpp

/** // doc: clxx/device_partition.hpp {{{
 * \file clxx/device_partition.hpp
 * \brief Declares clxx API for \ref clxx::device "device" partitioning
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_HPP_INCLUDED
#define CLXX_DEVICE_PARTITION_HPP_INCLUDED

#include <clxx/devices.hpp>
#include <clxx/device_partition_properties.hpp>

namespace clxx {

/** \addtogroup clxx_platform_layer
 *  @{ */
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
/** // doc: get_num_sub_devices() {{{
 * \brief Determine the number of sub-devices that would be created by
 *        partitioning \em in_device
 *
 * \param in_device
 *    The device to be partitioned
 * \param properties
 *    Specifies how \e in_device is to be partition described by a partition
 *    name and its corresponding value.
 *
 * \returns
 *    The number of sub-devices that would be created by partitioning the
 *    \em in_device with given partition properties.
 *
 * \throw uninitialized_device_error
 *    if \em in_device is not properly initialized (see \ref
 *    clxx::device::is_initialized()),
 *
 * It also throws exceptions originating from the base wrapper
 * \ref clxx::create_sub_devices() "create_sub_devices()".
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 */ // }}}
cl_uint get_num_sub_devices(device const& in_device,
                            device_partition_properties const& properties);
/** // doc: create_sub_devices() {{{
 * \brief Creates an array of sub-devices that each reference
 *    a non-intersecting set of compute units within \e in_device.
 *
 * \param in_device
 *    The device to be partitioned
 * \param properties
 *    Specifies how \e in_device is to be partition described by a partition
 *    name and its corresponding value.
 *
 * \returns
 *    The sub-devices created as a result of partitioning.
 *
 * \throw std::bad_alloc
 *    if the vector of devices can't be allocated,
 * \throw uninitialized_device_error
 *    if \em in_device is not properly initialized (see \ref
 *    clxx::device::is_initialized()),
 *
 * It also throws exceptions originating from the base wrapper
 * \ref clxx::create_sub_devices() "create_sub_devices()".
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 */ // }}}
devices create_sub_devices(device const& in_device,
                           device_partition_properties const& properties);
#endif
/** @} */

} // end namespace clxx

#endif /* CLXX_DEVICE_PARTITION_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
