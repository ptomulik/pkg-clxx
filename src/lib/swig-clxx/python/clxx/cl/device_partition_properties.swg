// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: python/clxx/cl/device_partition_properties.swg {{{
 * \file python/clxx/cl/device_partition_properties.swg
 * \todo Write documentation
 */ // }}}

%include <clxx/cl/device_partition_properties.li.swg>

%extend std::vector<clxx::device_partition_property> {
  std::vector<clxx::device_partition_property> __and__(clxx::device_partition_property const& right) const {
    return clxx::operator&(*$self, right);
  }
  std::vector<clxx::device_partition_property> __and__(std::vector<clxx::device_partition_property> const& right) const {
    return clxx::operator&(*$self, right);
  }
};

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
