// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/text_oarchive.swg {{{
 * \file clxx/boost/archive/text_oarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/std/iostream_mod.hpp>
#include <boost/archive/text_oarchive.hpp>
%}

%import <clxx/std/iostream_mod.i>
%include <clxx/boost/archive/detail/interface_oarchive.swg>

namespace boost {
namespace archive {
class text_oarchive;
%template(interface_oarchive_T_text_oarchive) detail::interface_oarchive<text_oarchive>;
class text_oarchive
  : public detail::interface_oarchive<text_oarchive>
  {
  public:
    text_oarchive(std::ostream &os, unsigned int flags = 0);
   ~text_oarchive();
  };
} /* namespace archive */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
