// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/platform_query.cpp

/** // doc: clxx/info/platform_query.cpp {{{
 * \file clxx/info/platform_query.cpp
 * \brief Implements the \ref clxx::platform_query "platform_query" class
 */ // }}}
#include <clxx/info/platform_query.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
platform_query::
platform_query() noexcept
{
  this->_init(true);
}
/* ------------------------------------------------------------------------ */
platform_query::
platform_query(bool flag) noexcept
{
  this->_init(flag);
}
/* ------------------------------------------------------------------------ */
platform_query::
~platform_query() noexcept
{
}
/* ------------------------------------------------------------------------ */
void platform_query::
_init(bool flag) noexcept
{
  this->_select(flag);
}
/* ------------------------------------------------------------------------ */
void platform_query::
_select(bool flag) noexcept
{
  this -> select_id(flag);
  this -> select_profile(flag);
  this -> select_version(flag);
  this -> select_name(flag);
  this -> select_vendor(flag);
  this -> select_extensions(flag);
}
/* ------------------------------------------------------------------------ */
platform_query& platform_query::
select_all() noexcept
{
  this->_select(true);
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_query& platform_query::
select_none() noexcept
{
  this->_select(false);
  return *this;
}
/* ------------------------------------------------------------------------ */
platform_query& platform_query::
select_default() noexcept
{
  return this->select_all();
}
/* ------------------------------------------------------------------------ */
bool operator== (platform_query const& a, platform_query const& b) noexcept
{
  return  (a.id_selected() == b.id_selected()) &&
          (a.profile_selected() == b.profile_selected()) &&
          (a.version_selected() == b.version_selected()) &&
          (a.name_selected() == b.name_selected()) &&
          (a.vendor_selected() == b.vendor_selected()) &&
          (a.extensions_selected() == b.extensions_selected());
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
