// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform.hpp

/** // doc: clxx/platform.cpp {{{
 * \file clxx/platform.cpp
 * \brief Implements the \ref clxx::platform "platform" class
 */ // }}}
#include <clxx/platform.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <boost/shared_array.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
static std::string
_get_str_info(platform const& p, platform_info_t name)
{
  size_t size;
  p.get_info(name, 0, NULL, &size);

  boost::shared_array<char> str(new char[size]);
  // FIXME: if(str == nullptr) { throw clxx::bad_alloc() }
  p.get_info(name, size, str.get(), &size);
  return std::string(str.get());
}
/* ------------------------------------------------------------------------ */
cl_platform_id platform::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_platform_error();
  return this->_platform_id;
}
/* ------------------------------------------------------------------------ */
void platform::
get_info( platform_info_t name, size_t value_size, void* value,
          size_t* value_size_ret) const
{
  get_platform_info(this->get_valid_id(),name,value_size,value,value_size_ret);
}
/* ------------------------------------------------------------------------ */
std::string platform::
get_profile() const
{
  return _get_str_info(*this, platform_info_t::profile);
}
/* ------------------------------------------------------------------------ */
std::string platform::
get_version() const
{
  return _get_str_info(*this, platform_info_t::version);
}
/* ------------------------------------------------------------------------ */
std::string platform::
get_name() const
{
  return _get_str_info(*this, platform_info_t::name);
}
/* ------------------------------------------------------------------------ */
std::string platform::
get_vendor() const
{
  return _get_str_info(*this, platform_info_t::vendor);
}
/* ------------------------------------------------------------------------ */
std::string platform::
get_extensions() const
{
  return _get_str_info(*this, platform_info_t::extensions);
}
} // end namespace clxx

namespace clxx {

platform_info
query_platform_info(platform const& p, platform_query const& query)
{
  platform_info info;
  if(query.id_selected())
    info.set_id(reinterpret_cast<unsigned long>(p.id()));
  if(query.profile_selected())
    info.set_profile(p.get_profile());
  if(query.version_selected())
    info.set_version(p.get_version());
  if(query.name_selected())
    info.set_name(p.get_name());
  if(query.vendor_selected())
    info.set_vendor(p.get_vendor());
  if(query.extensions_selected())
    info.set_extensions(p.get_extensions());
  return info;
}

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
