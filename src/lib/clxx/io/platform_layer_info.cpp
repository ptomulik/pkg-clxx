// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/platform_layer_info.cpp

/** // doc: clxx/io/platform_layer_info.cpp {{{
 * \file clxx/io/platform_layer_info.cpp
 * \brief Instantiates template I/O functions for \ref clxx::platform_layer_info "platform_layer_info" objects
 */ // }}}
#include <ostream>
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}
/** \endcond */

#include <clxx/io/platform_layer_info_impl.hpp>

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::platform_layer_info const& info)
{
  return clxx::io::write(os, info);
}
/** \endcond */

#include <string>

//
// Instantiations:
//
namespace clxx { namespace io {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template std::basic_ostream<char> &
write( std::basic_ostream<char> &, clxx::platform_layer_info const&, int );
template std::basic_ostream<wchar_t> &
write( std::basic_ostream<wchar_t> &, clxx::platform_layer_info const&, int );
/** \endcond */
} } // end namespace clxx::io

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template std::basic_ostream<char> &
operator << ( std::basic_ostream<char> & os
            , clxx::platform_layer_info const& info );
template std::basic_ostream<wchar_t> &
operator << ( std::basic_ostream<wchar_t> & os
            , clxx::platform_layer_info const& info );
/** \endcond */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
