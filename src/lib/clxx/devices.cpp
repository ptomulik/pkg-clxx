// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/devices.cpp

/** // doc: clxx/devices.cpp {{{
 * \file clxx/devices.cpp
 * \brief Implements functions used to create \ref clxx::device "device" objects
 */ // }}}
#include <clxx/devices.hpp>
#include <clxx/functions.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
cl_uint
get_num_devices(cl_platform_id platform, device_type_t device_type)
{
  cl_uint num_devices = 0;
  get_device_ids(platform, device_type, 0, NULL, &num_devices);
  return num_devices;
}
/* ------------------------------------------------------------------------ */
std::vector<cl_device_id>
get_device_ids(cl_platform_id platform, device_type_t device_type)
{
  std::vector<cl_device_id> ids(get_num_devices(platform, device_type));
  if(ids.size() > 0)
    get_device_ids(platform, device_type, ids.size(), &ids[0], NULL);
  return ids;
}
/* ------------------------------------------------------------------------ */
devices
get_devices(cl_platform_id platform, device_type_t device_type)

{
  return make_devices(get_device_ids(platform, device_type));
}
/* ------------------------------------------------------------------------ */
devices
get_devices(platform const& platform, device_type_t device_type)

{
  return get_devices(platform.handle(), device_type);
}
/* ------------------------------------------------------------------------ */
devices
make_devices(std::vector<cl_device_id> const& ids)
{
  return devices(ids.begin(), ids.end());
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
