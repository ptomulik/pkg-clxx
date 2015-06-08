// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/device_info.cpp

/** // doc: clxx/io/device_info.cpp {{{
 * \file clxx/io/device_info.cpp
 * \todo Write documentation
 */ // }}}
#include <ostream>

template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}

#include <clxx/io/device_info_impl.hpp>


template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::device_info const& info)
{
  return clxx::io::write(os, info);
}

#include <string>
//
// Instantiations:
//
namespace clxx { namespace io {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template std::basic_ostream<char> &
write( std::basic_ostream<char> &, clxx::device_info const&, int );
template std::basic_ostream<wchar_t> &
write( std::basic_ostream<wchar_t> &, clxx::device_info const&, int );
/** \endcond */
} } // end namespace clxx::io

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template std::basic_ostream<char> &
operator << ( std::basic_ostream<char> & os
            , clxx::device_info const& info );
template std::basic_ostream<wchar_t> &
operator << ( std::basic_ostream<wchar_t> & os
            , clxx::device_info const& info );
/** \endcond */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
