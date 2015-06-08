// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/text_iarchive.swg {{{
 * \file clxx/boost/archive/text_iarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/std/iostream_mod.hpp>
#include <boost/archive/text_iarchive.hpp>
%}

%import <clxx/std/iostream_mod.i>
%include <clxx/boost/archive/detail/interface_iarchive.swg>

namespace boost {
namespace archive {
class text_iarchive;
%template(interface_iarchive_T_text_iarchive) detail::interface_iarchive<text_iarchive>;
class text_iarchive
  : public detail::interface_iarchive<text_iarchive>
  {
  public:
    text_iarchive(std::istream &os, unsigned int flags = 0);
   ~text_iarchive();
  };
} /* namespace archive */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
