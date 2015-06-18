// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_layer_info.cpp

/** // doc: clxx/platform_layer_info.cpp {{{
 * \file clxx/platform_layer_info.cpp
 * \brief Implements the \ref clxx::platform_layer_info "platform_layer_info" class
 */ // }}}
#include <clxx/platform_layer_info.hpp>
#include <clxx/platform_info.hpp>
#include <clxx/device_info.hpp>
#include <set>

namespace clxx {

/* ------------------------------------------------------------------------ */

platform_layer_info::platform_layer_info()
{
}
/* ------------------------------------------------------------------------ */

platform_layer_info::~platform_layer_info()
{
}
/* ------------------------------------------------------------------------ */
void platform_layer_info::
clear()
{
  this->_bimap.clear();
}
/* ------------------------------------------------------------------------ */
platform_info_ptrs platform_layer_info::
get_platforms()
{
  typedef bimap::left_const_iterator It;
  std::set<const_platform_info_ptr> seen;
  platform_info_ptrs platforms;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    {
      if(seen.find(cur->first) == seen.end())
        {
          platforms.push_back(boost::const_pointer_cast<platform_info>(cur->first));
          seen.insert(cur->first);
        }
    }
  return platforms;
}
/* ------------------------------------------------------------------------ */
const_platform_info_ptrs platform_layer_info::
get_platforms() const
{
  typedef bimap::left_const_iterator It;
  std::set<const_platform_info_ptr> seen;
  const_platform_info_ptrs platforms;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    {
      if(seen.find(cur->first) == seen.end())
        {
          platforms.push_back(cur->first);
          seen.insert(cur->first);
        }
    }
  return platforms;
}
/* ------------------------------------------------------------------------ */
platform_info_ptr platform_layer_info::
get_platform(const_device_info_ptr dev)
{
  // NOTE: this throws an exception if device is an invalid key
  return boost::const_pointer_cast<platform_info>(this->_bimap.right.at(dev));
}
/* ------------------------------------------------------------------------ */
const_platform_info_ptr platform_layer_info::
get_platform(const_device_info_ptr dev) const
{
  // NOTE: this throws an exception if device is an invalid key
  return this->_bimap.right.at(dev);
}
/* ------------------------------------------------------------------------ */
device_info_ptrs platform_layer_info::
get_devices()
{
  typedef bimap::left_const_iterator It;
  device_info_ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    devices.push_back(boost::const_pointer_cast<device_info>(cur->second));
  return devices;
}
/* ------------------------------------------------------------------------ */
const_device_info_ptrs platform_layer_info::
get_devices() const
{
  typedef bimap::left_const_iterator It;
  const_device_info_ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = this->_bimap.left.begin(); cur != end; ++cur)
    devices.push_back(cur->second);
  return devices;
}
/* ------------------------------------------------------------------------ */
device_info_ptrs platform_layer_info::
get_devices(const_platform_info_ptr platform)
{
  typedef bimap::left_const_iterator It;
  device_info_ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = _bimap.left.begin(); cur != end; ++cur)
    if(cur->first == platform)
      devices.push_back(boost::const_pointer_cast<device_info>(cur->second));
  return devices;
}
/* ------------------------------------------------------------------------ */
const_device_info_ptrs platform_layer_info::
get_devices(const_platform_info_ptr platform) const
{
  typedef bimap::left_const_iterator It;
  const_device_info_ptrs devices;
  It end(this->_bimap.left.end());
  for(It cur = _bimap.left.begin(); cur != end; ++cur)
    if(cur->first == platform)
      devices.push_back(cur->second);
  return devices;
}
/* ------------------------------------------------------------------------ */
void platform_layer_info::
push_back(device_info_ptr dev, platform_info_ptr platform)
{
  this->_bimap.left.push_back(bimap::left_value_type(platform, dev));
}
/* ------------------------------------------------------------------------ */
void platform_layer_info::
remove(const_platform_info_ptr platform)
{
  typedef bimap::left_iterator It;
  for(It cur = this->_bimap.left.begin(); cur != this->_bimap.left.end();)
    if(cur->first == platform)
      cur = this->_bimap.left.erase(cur);
    else
      ++cur;
}
/* ------------------------------------------------------------------------ */
void platform_layer_info::
remove(const_device_info_ptr dev)
{
  this->_bimap.right.erase(dev);
}
/* ------------------------------------------------------------------------ */
bool platform_layer_info::
empty() const
{
  return this->_bimap.empty();
}
/* ------------------------------------------------------------------------ */
bool platform_layer_info::
cmp(platform_layer_info const& p) const
{
  // Compare sizes of bimaps first
  if(this->_bimap.left.size() != p._bimap.left.size())
    return false;
  // Compare layout (which device maps to which platform, in order)
  if(this->indices() != p.indices())
    return false;
  // Compare Platforms and Devices one by one
  typedef bimap::left_const_iterator It;
  It cur1(_bimap.left.begin());
  It cur2(p._bimap.left.begin());
  It end1(_bimap.left.end());
  It end2(p._bimap.left.end());
  for(; cur1 != end1 && cur2 != end2; ++cur1, ++cur2)
    {
      if(*(cur1->first) != *(cur2->first) || *(cur1->second) != *(cur2->second))
        return false;
    }
  return true;
}
/* ------------------------------------------------------------------------ */
std::vector<int> platform_layer_info::
indices() const
{
  std::vector<int> is(_bimap.left.size());
  const_platform_info_ptrs ps(this->get_platforms());
  for(size_t i = 0; i < _bimap.left.size(); ++i)
    is[i] = std::find(ps.begin(), ps.end(), _bimap.left[i].first) - ps.begin();
  return is;
}

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
