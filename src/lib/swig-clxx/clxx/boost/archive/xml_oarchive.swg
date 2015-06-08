// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/xml_oarchive.swg {{{
 * \file clxx/boost/archive/xml_oarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/std/iostream_mod.hpp>
#include <boost/archive/xml_oarchive.hpp>
%}

%import <clxx/std/iostream_mod.i>
%include <clxx/boost/archive/detail/interface_oarchive.swg>

namespace boost {
namespace archive {
class xml_oarchive;
%template(interface_oarchive_T_xml_oarchive) detail::interface_oarchive<xml_oarchive>;
class xml_oarchive
  : public detail::interface_oarchive<xml_oarchive>
  {
  public:
    xml_oarchive(std::ostream &os, unsigned int flags = 0);
   ~xml_oarchive();
  };
} /* namespace archive */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
