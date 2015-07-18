// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/platform_info.cpp

/** // doc: clxx/info/platform_info.cpp {{{
 * \file clxx/info/platform_info.cpp
 * \brief Implements the clxx::platform_info class.
 */ // }}}
#include <clxx/info/platform_info.hpp>
#include <clxx/exceptions.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
platform_info::
platform_info()
{
  _init();
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
clear()
{
  this->_clear();
  return *this;
}
/* ------------------------------------------------------------------------ */
bool platform_info::
cmp(platform_info const& rhs) const
  noexcept
{
  return ((this->_id == rhs._id)
      && ((this->_profile == rhs._profile))
      && ((this->_version == rhs._version))
      && ((this->_name == rhs._name))
      && ((this->_vendor == rhs._vendor))
      && ((this->_extensions == rhs._extensions)));
}

//
// getters
//

/* ------------------------------------------------------------------------ */
unsigned long platform_info::
id() const
{
  if(!this->has_id()) { throw uninitialized_value_error(); }
  return this->_id.get();
}
/* ------------------------------------------------------------------------ */
std::string const& platform_info::
profile() const
{
  if(!this->has_profile()) { throw uninitialized_value_error(); }
  return this->_profile.get();
}
/* ------------------------------------------------------------------------ */
std::string const& platform_info::
version() const
{
  if(!this->has_version()) { throw uninitialized_value_error(); }
  return this->_version.get();
}
/* ------------------------------------------------------------------------ */
std::string const& platform_info::
name() const
{
  if(!this->has_name()) { throw uninitialized_value_error(); }
  return this->_name.get();
}
/* ------------------------------------------------------------------------ */
std::string const& platform_info::
vendor() const
{
  if(!this->has_vendor()) { throw uninitialized_value_error(); }
  return this->_vendor.get();
}
/* ------------------------------------------------------------------------ */
std::string const& platform_info::
extensions() const
{
  if(!this->has_extensions()) { throw uninitialized_value_error(); }
  return this->_extensions.get();
}
/* ------------------------------------------------------------------------ */

//
// setters
//

/* ------------------------------------------------------------------------ */
platform_info& platform_info::
set_id(unsigned long val) noexcept
{
  this->_id = val;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
set_profile(std::string const& val)
{
  this->_profile = val;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
set_version(std::string const& val)
{
  this->_version = val;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
set_name(std::string const& val)
{
  this->_name = val;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
set_vendor(std::string const& val)
{
  this->_vendor = val;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
set_extensions(std::string const& val)
{
  this->_extensions = val;
  return *this;
}

//
// cleaners
//

platform_info& platform_info::
clear_id() noexcept
{
  this->_id = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
clear_profile() noexcept
{
  this->_profile = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
clear_version() noexcept
{
  this->_version = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
clear_name() noexcept
{
  this->_name = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
clear_vendor() noexcept
{
  this->_vendor = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_info& platform_info::
clear_extensions()
noexcept
{
  this->_extensions = boost::none;
  return *this;
}
/* ------------------------------------------------------------------------ */
// }}}
// presence {{{
bool platform_info::
has_id() const noexcept
{
  return this->_id.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool platform_info::
has_profile() const noexcept
{
  return this->_profile.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool platform_info::
has_version() const noexcept
{
  return this->_version.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool platform_info::
has_name() const noexcept
{
  return this->_name.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool platform_info::
has_vendor() const noexcept
{
  return this->_vendor.is_initialized();
}
/* ------------------------------------------------------------------------ */
bool platform_info::
has_extensions() const noexcept
{
  return this->_extensions.is_initialized();
}
// }}}
/* ------------------------------------------------------------------------ */
void platform_info::
_init()
{
  this->_clear();
}
/* ------------------------------------------------------------------------ */
void platform_info::
_clear()
{
  this->_id = boost::none;
  this->_profile = boost::none;
  this->_version = boost::none;
  this->_name = boost::none;
  this->_vendor = boost::none;
  this->_extensions = boost::none;
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
