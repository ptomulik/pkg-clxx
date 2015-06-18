// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_partition.cpp

/** // doc: clxx/device_partition.cpp {{{
 * \file clxx/device_partition.cpp
 * \brief Implements API for \ref clxx::device "device" partitioning
 */ // }}}
#include <clxx/device_partition.hpp>
#include <clxx/functions.hpp>
#include <boost/shared_array.hpp>

namespace clxx {
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
/* ------------------------------------------------------------------------ */
static void
_create_sub_devices(cl_device_id in_device,
                    device_partition_properties const& properties,
                    cl_uint num_devices,
                    cl_device_id *out_devices,
                    cl_uint *num_devices_ret)
{
  const size_t array_size = device_partition_properties_array_size(properties);
  boost::shared_array<cl_device_partition_property> array(new cl_device_partition_property[array_size]);
  device_partition_properties_fill_array(properties, array.get(), array_size);
  create_sub_devices(in_device, array.get(), num_devices, out_devices, num_devices_ret);
}
/* ------------------------------------------------------------------------ */
cl_uint
get_num_sub_devices(device const& in_device, device_partition_properties const& properties)
{
  cl_uint num_devices = 0;
  _create_sub_devices(in_device.get_valid_id(), properties, 0, nullptr, &num_devices);
  return num_devices;
}
/* ------------------------------------------------------------------------ */
devices
create_sub_devices(device const& in_device,device_partition_properties const& properties)
{
  std::vector<cl_device_id> ids(get_num_sub_devices(in_device, properties));
  if(ids.size() > 0)
    _create_sub_devices(in_device.get_valid_id(), properties, ids.size(), &ids[0], NULL);
  return make_devices(ids);
}
/* ------------------------------------------------------------------------ */
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
