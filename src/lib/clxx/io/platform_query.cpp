// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/platform_query.cpp

/** // doc: clxx/io/platform_query.cpp {{{
 * \file clxx/io/platform_query.cpp
 * \brief Implements and instantiates template I/O functions for \ref clxx::platform_query "platform_query" objects
 */ // }}}
#include <clxx/io/platform_query.hpp>
#include <clxx/io/autosep.hpp>
#include <ostream>
#include <string>

template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}

/// Name-pointer pair
struct Npp
{
  const char* name; //!< name of the named pointer
  bool (clxx::platform_query::*ptr) () const; //!< the pointer stored by Npp
};
/// Supports creation of Npp pairs
#define NPP(name) { #name, &clxx::platform_query::name ## _selected}

static Npp npps[] =
{
  NPP(id)
, NPP(profile)
, NPP(version)
, NPP(name)
, NPP(vendor)
, NPP(extensions)
};

namespace clxx { namespace io {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_query const& query, int ind)
{
  autosep_<const char*> as("\n");
  std::string pre(ind, ' ');
  for(int i=0; i<(int)(sizeof(npps)/sizeof(*npps));++i) {
    if((query.*(npps[i].ptr))())
      os << as << pre << npps[i].name;
  }
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_query const& query)
{
  return write(os, query, 0);
}
/** \endcond */
} } // end namespace clxx::io

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::platform_query const& query)
{
  return clxx::io::write(os, query);
}

// Instantiate our operator for several types.
template std::basic_ostream<char>&
operator << ( std::basic_ostream<char>& os
            , clxx::platform_query const& query );
template std::basic_ostream<wchar_t>&
operator << ( std::basic_ostream<wchar_t>& os
            , clxx::platform_query const& query );
/** \endcond */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
