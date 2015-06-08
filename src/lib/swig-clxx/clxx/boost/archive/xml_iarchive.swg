// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/xml_iarchive.swg {{{
 * \file clxx/boost/archive/xml_iarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/std/iostream_mod.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <clxx/device_info.hpp>
#include <boost/serialization/shared_ptr.hpp>
%}

%import <clxx/std/iostream_mod.i>
%include <clxx/boost/archive/detail/interface_iarchive.swg>

namespace boost {
namespace archive {
class xml_iarchive;
%template(interface_iarchive_T_xml_iarchive) detail::interface_iarchive<xml_iarchive>;
class xml_iarchive
  : public detail::interface_iarchive<xml_iarchive>
  {
  public:
    xml_iarchive(std::istream &os, unsigned int flags = 0);
   ~xml_iarchive();
  };
} /* namespace archive */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
