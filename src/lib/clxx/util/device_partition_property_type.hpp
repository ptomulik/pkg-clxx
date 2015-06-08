// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/device_partition_property_type.hpp

/** // doc: clxx/util/device_partition_property_type.hpp {{{
 * \file clxx/util/device_partition_property_type.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED
#define CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/util/device_partition_property_type_fwd.hpp>
#include <vector>

namespace clxx {

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <>
  struct device_partition_property_type<device_partition_property_t::equally>
  {
    typedef unsigned int type;
  };
template <>
  struct device_partition_property_type<device_partition_property_t::by_counts>
  {
    typedef std::vector<unsigned int> const& type;
  };
#if CL_VERSION_1_2
template <>
  struct device_partition_property_type<device_partition_property_t::by_affinity_domain>
  {
    typedef device_affinity_domain_t type;
  };
#endif
/** \endcond */

} // end namespace clxx

#endif /* CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
