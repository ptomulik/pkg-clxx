// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/device_partition_properties.li.swg {{{
 * \file clxx/device_partition_properties.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/device_partition_properties.hpp>
%}
%include <std_vector.i>
%template (device_partition_properties) std::vector<clxx::device_partition_property>;

%exception clxx::device_partition_properties_fill_array(clxx::device_partition_properties const&, cl_device_partition_property *) {
  try { $action }
  %catch_invalid_argument_error
  %catch_not_enough_space_error
  %catch_exception
}
%exception clxx::device_partition_properties_parse_array(clxx::device_partition_properties&, cl_device_partition_property const *) {
  try { $action }
  %catch_invalid_argument_error
  %catch_badalloc
  %catch_exception
}
%throws_badalloc(clxx::operator&(clxx::device_partition_property const&, device_partition_property const&));
%throws_badalloc(clxx::operator&(clxx::device_partition_properties const&, device_partition_property const&));
%throws_badalloc(clxx::operator&(clxx::device_partition_property const&, device_partition_properties const&));
%throws_badalloc(clxx::operator&(clxx::device_partition_properties const&, device_partition_properties const&));
%throws_badalloc(clxx::make_device_partition_properties);

%include <clxx/exception_support.swg>

%include <clxx/device_partition_properties.hpp>

namespace clxx {
  inline device_partition_properties make_device_partition_properties(device_partition_property const&);
  inline device_partition_properties make_device_partition_properties(device_partition_property const&, device_partition_property const&);
  inline device_partition_properties make_device_partition_properties(device_partition_property const&, device_partition_property const&, device_partition_property const&);
  inline device_partition_properties make_device_partition_properties(device_partition_property const&, device_partition_property const&, device_partition_property const&, device_partition_property const&);

  inline device_partition_properties make_device_partition_properties(device_partition_properties const&);
  inline device_partition_properties make_device_partition_properties(device_partition_properties const&, device_partition_property const&);
  inline device_partition_properties make_device_partition_properties(device_partition_properties const&, device_partition_property const&, device_partition_property const&);
  inline device_partition_properties make_device_partition_properties(device_partition_properties const&, device_partition_property const&, device_partition_property const&, device_partition_property const&);
};

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
