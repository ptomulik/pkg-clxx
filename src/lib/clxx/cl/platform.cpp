// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/platform.hpp

/** // doc: clxx/cl/platform.cpp {{{
 * \file clxx/cl/platform.cpp
 * \brief Implements the \ref clxx::platform "platform" class
 */ // }}}
#include <clxx/cl/platform.hpp>
#include <clxx/cl/clobj_impl.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
/** \cond SHOW_IGNORED_COMPOUNDS */
template<>
cl_uint clobj<cl_platform_id>::
get_reference_count() const
{
  // FIXME: elaborate how to generate a compile-time error here.
  return 0u;
}
/** \endcond */
/* ----------------------------------------------------------------------- */
}

namespace clxx {
/* ------------------------------------------------------------------------ */
// Instantiate the base class
template class clobj<cl_platform_id>;
static_assert(
    sizeof(clobj<cl_platform_id>) == sizeof(cl_platform_id),
    "sizeof(clobj<cl_platform_id>) differs from sizeof(cl_platform_id)"
);
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
    info.set_id(reinterpret_cast<unsigned long>(p.get()));
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
