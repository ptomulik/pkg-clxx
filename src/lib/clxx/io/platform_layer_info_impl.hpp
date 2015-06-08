// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/platform_layer_info_impl.hpp

/** // doc: clxx/io/platform_layer_info_impl.hpp {{{
 * \file clxx/io/platform_layer_info_impl.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_IO_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED
#define CLXX_IO_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED

/** // doc: clxx/io/platform_info_impl.hpp {{{
 * \file clxx/io/platform_info_impl.hpp
 * \todo Write documentation
 */ // }}}
#include <clxx/io/platform_layer_info.hpp>
#include <clxx/io/platform_info.hpp>
#include <clxx/io/device_info.hpp>
#include <ostream>
#include <string>

namespace clxx { namespace io {

template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_layer_info const& info, int ind)
{
  using clxx::platform_layer_info;
  using const_platform_info_ptrs = clxx::const_platform_info_ptrs;
  using const_device_info_ptrs = clxx::const_device_info_ptrs;

  std::string pre(ind, ' ');

  const_platform_info_ptrs plats(info.get_platforms());
  const_platform_info_ptrs::const_iterator pend(plats.end());
  const_platform_info_ptrs::const_iterator pbeg(plats.begin());
  const_platform_info_ptrs::const_iterator pcur(pbeg);
  for(;pcur != pend; ++ pcur)
    {
      os << "Platform " << (pcur - pbeg) << ":\n";
      clxx::io::write(os, **pcur, ind) << "\n";
      os << "\n";
      const_device_info_ptrs devs(info.get_devices(*pcur));
      const_device_info_ptrs::const_iterator dend(devs.end());
      const_device_info_ptrs::const_iterator dbeg(devs.begin());
      const_device_info_ptrs::const_iterator dcur(dbeg);
      for(;dcur != dend; ++dcur)
        {
           os << pre << "Device " << (dcur - dbeg) << ":\n";
           clxx::io::write(os, **dcur, 2*ind ) << "\n";
           os << "\n";
        }
    }
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_layer_info const& info)
{
  return write(os, info, 0);
}

} } // end namespace clxx::io


#endif /* CLXX_IO_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
