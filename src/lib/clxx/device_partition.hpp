// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_partition.hpp

/** // doc: clxx/device_partition.hpp {{{
 * \file clxx/device_partition.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_HPP_INCLUDED
#define CLXX_DEVICE_PARTITION_HPP_INCLUDED

#include <clxx/devices.hpp>
#include <clxx/device_partition_properties.hpp>

namespace clxx {

/** \ingroup clxx_platform_layer */
/** @{ */
#if HAVE_OPENCL_clCreateSubDevices
/** // doc: get_num_sub_devices() {{{
 * \todo Write documentation
 */ // }}}
cl_uint get_num_sub_devices(device const& in_device,
                            device_partition_properties const& properties);
/** // doc: create_sub_devices() {{{
 * \todo Write documentation
 */ // }}}
devices create_sub_devices(device const& in_device,
                           device_partition_properties const& properties);
#endif
/** @} */

} // end namespace clxx

#endif /* CLXX_DEVICE_PARTITION_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
