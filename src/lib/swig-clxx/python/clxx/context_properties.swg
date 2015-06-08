// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: python/clxx/context_properties.swg {{{
 * \file python/clxx/context_properties.swg
 * \todo Write documentation
 */ // }}}

%include <clxx/context_properties.li.swg>

%extend std::vector<clxx::context_property> {
  std::vector<clxx::context_property> __and__(clxx::context_property const& right) const {
    return clxx::operator&(*$self, right);
  }
  std::vector<clxx::context_property> __and__(std::vector<clxx::context_property> const& right) const {
    return clxx::operator&(*$self, right);
  }
};

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
