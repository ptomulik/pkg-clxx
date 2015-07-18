// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/platform_layer.cpp

/** // doc: clxx/cl/platform_layer.cpp {{{
 * \file clxx/cl/platform_layer.cpp
 * \brief Implements the \ref clxx::platform_layer "platform_layer" class
 */ // }}}
#include <clxx/cl/platform_layer.hpp>
#include <clxx/cl/platform.hpp>
#include <clxx/cl/device.hpp>
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/devices.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>
#include <algorithm>
#include <iostream>

namespace clxx {

template <class X, typename T>
static void
remove_value(X& x, T const& v)
{
  for(typename X::iterator i(x.begin()); i != x.end();)
    i = (*i == v) ? x.erase(i) : i + 1;
}
/* ------------------------------------------------------------------------ */
template <class X, typename T, class Map>
static void
remove_if_unref(X& x, T const& v, Map const& map)
{
  // check if we still have the references to the v T,
  auto pred = [&v](typename Map::const_reference x)
            -> bool { return x.second == v; };
  if(std::find_if(map.begin(), map.end(), pred) == map.end())
    remove_value(x, v);
}
/* ------------------------------------------------------------------------ */
platform_layer::
platform_layer() noexcept
{
}
/* ------------------------------------------------------------------------ */
platform_layer::
platform_layer(device_type_t type)
{
  this->load_opencl(type);
}
/* ------------------------------------------------------------------------ */
platform_layer::
platform_layer(bool load, device_type_t type)
{
  if(load)
    this->load_opencl(type);
}
/* ------------------------------------------------------------------------ */
platform_layer::
~platform_layer() noexcept
{
}
/* ------------------------------------------------------------------------ */
platforms const& platform_layer::
get_platforms() const noexcept
{
  return _platforms;
}
/* ------------------------------------------------------------------------ */
devices const& platform_layer::
get_devices() const noexcept
{
  return _devices;
}
/* ------------------------------------------------------------------------ */
devices platform_layer::
get_devices(platform const& p) const
{
  typedef device_platform_map::const_iterator iterator;
  device_platform_map const& dp = this->_device_platform;
  devices ds;

  for(iterator cur = dp.begin(); cur != dp.end(); ++cur)
    {
      if(cur->second == p)
        ds.push_back(cur->first);
    }
  if(ds.empty())
    throw invalid_key_error();
  return ds;
}
/* ------------------------------------------------------------------------ */
platform const& platform_layer::
get_platform(device const& d) const
{
  typedef device_platform_map::const_iterator iterator;
  device_platform_map const& dp = this->_device_platform;

  iterator it = dp.find(d);
  if(it == dp.end())
    throw invalid_key_error();

  return it->second;
}
/* ------------------------------------------------------------------------ */
bool platform_layer::
has_device(device const& d) const noexcept
{
  devices const& ds = this->_devices;
  return (std::find(ds.begin(), ds.end(), d) != ds.end());
}
/* ------------------------------------------------------------------------ */
bool platform_layer::
has_platform(platform const& p) const noexcept
{
  platforms const& ps = this->_platforms;
  return (std::find(ps.begin(), ps.end(), p) != ps.end());
}
/* ------------------------------------------------------------------------ */
bool platform_layer::
add(device const& d, platform const& p)
{
  typedef device_platform_map::iterator iterator;
  device_platform_map& dp = _device_platform;;
  devices& ds = _devices;
  platforms& ps = _platforms;

  std::pair<iterator, bool> ir = dp.insert(std::make_pair(d,p));

  if(ir.second)
    {
      // new device, just add it to vector (it's already added to map)
      ds.push_back(d);
    }
  else
    {
      // we already know the device 'd'
      iterator pos = ir.first;
      platform org(pos->second);
      if(org != p)
        {
          // but it looks like its platform has to be updated
          pos->second = p;
          remove_if_unref(ps, org, dp);
        }
    }

  // add platform if we don't have one in vector
  if(std::find(ps.begin(), ps.end(), p) == ps.end())
    ps.push_back(p);

  return ir.second;
}
/* ------------------------------------------------------------------------ */
size_t platform_layer::
add(devices const& ds, platform const& p)
{
  size_t n = 0ul;
  for(devices::const_iterator d(ds.begin()); d != ds.end(); ++d)
    n += (this->add(*d, p) ? 1ul : 0ul);
  return n;
}
/* ------------------------------------------------------------------------ */
void platform_layer::
erase(device const& d)
{
  typedef device_platform_map::iterator iterator;
  device_platform_map& dp = this->_device_platform;
  devices& ds = this->_devices;
  platforms& ps = this->_platforms;

  iterator it = dp.find(d);
  if(it == dp.end())
    throw invalid_key_error();

  platform p = it->second;

  dp.erase(it);
  remove_if_unref(ps, p, dp);
  remove_value(ds, d);
}
/* ------------------------------------------------------------------------ */
void platform_layer::
erase(platform const& p)
{
  devices ds(get_devices(p));
  for(devices::const_iterator d = ds.begin(); d != ds.end(); erase(*d), ++d);
}
/* ------------------------------------------------------------------------ */
void platform_layer::
clear() noexcept
{
  _device_platform.clear();
  _devices.clear();
  _platforms.clear();
}
/* ------------------------------------------------------------------------ */
void platform_layer::
load_opencl(device_type_t type)
{
  platforms ps(clxx::get_platforms());
  for(platforms::iterator cur = ps.begin(); cur != ps.end(); ++cur)
    this->add(clxx::get_devices(*cur, type), *cur);
}
/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
platform_layer_info
query_platform_layer_info(platform_layer const& layer,
                          platform_query const& pquery,
                          device_query const& dquery)
{
  platforms plats(layer.get_platforms());
  platforms::const_iterator pend(plats.end());
  platforms::const_iterator pcur(plats.begin());

  platform_layer_info info;

  for(;pcur != pend; ++pcur)
    {
      platform_info_ptr pinfo(
          new platform_info(
            query_platform_info(*pcur, pquery)
          )
      );
      devices devs(layer.get_devices(*pcur));
      devices::const_iterator dend(devs.end());
      devices::const_iterator dcur(devs.begin());
      for(;dcur != dend; ++dcur)
        {
          info.push_back(
            device_info_ptr(
              new device_info(
                query_device_info(*dcur, dquery)
              )
            ),
            pinfo
          );
        }
    }
  return info;
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
