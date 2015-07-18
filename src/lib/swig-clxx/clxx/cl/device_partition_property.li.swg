// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/device_partition_property.li.swg {{{
 * \file clxx/cl/device_partition_property.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/cl/device_partition_property.hpp>
%}

%include <clxx/exception_support.swg>

%define %throws_as_device_partition_property_setter(decl)
%exception decl {
  try { $action }
  %catch_value_access_error
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_as_device_partition_property_getter(decl)
%exception decl {
  try { $action }
  %catch_value_access_error
  %catch_exception
}
%enddef

%throws_as_device_partition_property_setter(clxx::device_partition_property::device_partition_property(clxx::device_partition_property_t, clxx::device_partition_counts const&));
%throws_as_device_partition_property_setter(clxx::device_partition_property::device_partition_property(cl_device_partition_property, clxx::device_partition_counts const&));
%throws_as_device_partition_property_getter(clxx::device_partition_property::value() const);
%throws_as_device_partition_property_getter(clxx::device_partition_property::value(size_t) const);
%throws_as_device_partition_property_getter(clxx::device_partition_property::values() const);
%throws_as_device_partition_property_setter(clxx::device_partition_property::set_value(cl_device_partition_property));
%throws_as_device_partition_property_setter(clxx::device_partition_property::set_values(clxx::device_partition_counts const&));
%throws_badalloc(clxx::device_partition_property::read(cl_device_partition_property const *));

%throws_badalloc(clxx::make_device_partition_propety);
%throws_badalloc(clxx::device_partition_equally(unsigned int));
%throws_badalloc(clxx::device_partition_by_counts(clxx::device_partition_counts const&));
%throws_badalloc(clxx::device_partition_by_affinity_domain(clxx::affinity_domain_t));

%include <clxx/cl/device_partition_property.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
