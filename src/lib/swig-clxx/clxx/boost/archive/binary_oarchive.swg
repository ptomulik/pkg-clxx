// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/binary_oarchive.swg {{{
 * \file clxx/boost/archive/binary_oarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/std/iostream_mod.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <clxx/device_info.hpp>
#include <boost/serialization/shared_ptr.hpp>
%}

%import <clxx/std/iostream_mod.i>
%include <clxx/boost/archive/detail/interface_oarchive.swg>

namespace boost {
namespace archive {
class binary_oarchive;
%template(interface_oarchive_T_binary_oarchive) detail::interface_oarchive<binary_oarchive>;
class binary_oarchive
  : public detail::interface_oarchive<binary_oarchive>
  {
  public:
    binary_oarchive(std::ostream &os, unsigned int flags = 0);
    binary_oarchive(std::streambuf &bsb, unsigned int flags = 0);
   ~binary_oarchive();
  };
} /* namespace archive */
} /* namespace boost */


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
