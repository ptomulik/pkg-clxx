// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/binary_iarchive.swg {{{
 * \file clxx/boost/archive/binary_iarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/std/iostream_mod.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <clxx/device_info.hpp>
#include <boost/serialization/shared_ptr.hpp>
%}

%import <clxx/std/iostream_mod.i>
%include <clxx/boost/archive/detail/interface_iarchive.swg>

namespace boost {
namespace archive {
class binary_iarchive;
%template(interface_iarchive_T_binary_iarchive) detail::interface_iarchive<binary_iarchive>;
class binary_iarchive
  : public detail::interface_iarchive<binary_iarchive>
  {
  public:
    binary_iarchive(std::istream &os, unsigned int flags = 0);
    binary_iarchive(std::streambuf &bsb, unsigned int flags = 0);
   ~binary_iarchive();
  };
} /* namespace archive */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
