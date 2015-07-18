// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: python/clxx/cl/device_partition_property.swg {{{
 * \file python/clxx/cl/device_partition_property.swg
 * \todo Write documentation
 */ // }}}

// We need the following include here, as we use clxx::operator& which is
// defined in clxx/cl/device_partition_properties.hpp
%{
#include <clxx/cl/device_partition_properties.hpp>
%}

%include <clxx/cl/device_partition_property.li.swg>

%extend clxx::device_partition_property {
  std::vector<clxx::device_partition_property> __and__(clxx::device_partition_property const& right) const {
    return clxx::operator&(*$self, right);
  }
  std::vector<clxx::device_partition_property> __and__(std::vector<clxx::device_partition_property> const& right) const {
    return clxx::operator&(*$self, right);
  }
}

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
