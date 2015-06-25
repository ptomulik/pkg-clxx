// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/device_partition_property_type.hpp

/** // doc: clxx/util/device_partition_property_type.hpp {{{
 * \file clxx/util/device_partition_property_type.hpp
 * \brief Defines the \ref clxx::device_partition_property_type "device_partition_property_type meta-function
 */ // }}}
#ifndef CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED
#define CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED

#include <clxx/util/device_partition_property_type_fwd.hpp>
#include <clxx/types.hpp>
#include <vector>

namespace clxx {

/** // doc: device_partition_property_type {{{
 * \brief Determines what type is used to represent given device partition property
 *
 * This meta-function returns a type that is used to represent a device
 * partitioning property's value. Device partitioning properties determine how
 * a device is going to be partitioned by \ref clxx::create_sub_devices()
 * "create_sub_devices()". A partitioning property is identified by it's
 * "name" (which is just a value of \ref clxx::device_partition_property_t
 * "device_partition_property_t") and has a value, whose type is specific to
 * given "name". This meta-function maps the predefined "names" onto
 * appropriate property value types.
 *
 * \tparam Name
 *      Partition property, for which the value type has to be determined
 *
 * \par Example
 *
 * Determine what type is used to represent device partition property
 * \ref clxx::device_partition_property_type_t::equally
 * "device_partition_property_type_t::equally"
 *
 * \code
 *    typedef clxx::device_partition_property_type<
 *      clxx::device_partition_property_t::equally
 *    >::type T;
 * \endcode
 *
 * This should yield <tt>unsigned int</tt> (which is the underlying value
 * type for \ref clxx::device_partition_property_t::equally
 * "device_partition_property_t::equally" or \c CL_DEVICE_PARTITION_EQUALLY
 * in the OpenCL terms).
 */ // }}}
template <device_partition_property_t Name>
  struct device_partition_property_type;

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
#if CLXX_CL_H_VERSION_1_2
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
