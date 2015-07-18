// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: python/clxx/cl/context_property.swg {{{
 * \file python/clxx/cl/context_property.swg
 * \todo Write documentation
 */ // }}}
// We need the following include here, as we use clxx::operator& which is
// defined in clxx/cl/context_properties.hpp. It's python specific, because we
// need it for the python %extend clxx::context_property.
%{
#include <clxx/cl/context_properties.hpp>
%}

%include <clxx/cl/context_property.li.swg>

%extend clxx::context_property {
  std::vector<clxx::context_property> __and__(clxx::context_property const& right) const {
    return clxx::operator&(*$self, right);
  }
  std::vector<clxx::context_property> __and__(std::vector<clxx::context_property> const& right) const {
    return clxx::operator&(*$self, right);
  }
}

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
