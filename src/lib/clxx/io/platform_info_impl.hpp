// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/platform_info_impl.hpp

#ifndef CLXX_IO_PLATFORM_INFO_IMPL
#define CLXX_IO_PLATFORM_INFO_IMPL

/** // doc: clxx/io/platform_info_impl.hpp {{{
 * \file clxx/io/platform_info_impl.hpp
 * \todo Write documentation
 */ // }}}
#include <clxx/io/platform_info.hpp>
#include <clxx/io/autosep.hpp>
#include <ostream>
#include <string>
#include <sstream>

namespace clxx { namespace io {

template <typename T>
static std::string
to_hex(T const& x)
{
  std::ostringstream oss;
  oss << "0x" << std::hex << x;
  return oss.str();
}

template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_info const& info, int ind)
{
  autosep_<const char*>  as("\n");
  std::string pre(ind, ' ');

  if(info.has_id())
    os << as << pre << "Id (within current process) ....: " << to_hex(info.id());
  if(info.has_profile())
    os << as << pre << "Profile ........................: " << info.profile();
  if(info.has_version())
    os << as << pre << "Version ........................: " << info.version();
  if(info.has_name())
    os << as << pre << "Name ...........................: " << info.name();
  if(info.has_vendor())
    os << as << pre << "Vendor .........................: " << info.vendor();
  if(info.has_extensions())
    os << as << pre << "Extensions .....................: " << info.extensions();

  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_info const& info)
{
  return write(os, info, 0);
}

} } // end namespace clxx::io

#endif /* CLXX_IO_PLATFORM_INFO_IMPL */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
