// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/device_partition_properties.hpp

/** // doc: clxx/cl/device_partition_properties.hpp {{{
 * \file clxx/cl/device_partition_properties.hpp
 * \brief Defines the \ref clxx::device_partition_properties "device_partition_properties"
 */ // }}}
#ifndef CLXX_CL_DEVICE_PARTITION_PROPERTIES_HPP_INCLUDED
#define CLXX_CL_DEVICE_PARTITION_PROPERTIES_HPP_INCLUDED

#include <clxx/cl/device_partition_property.hpp>
#include <clxx/opencl.h>
#include <vector>

namespace clxx {
/** // doc: device_partition_properties {{{
 * \ingroup clxx_platform_layer
 * \brief Container for context properties
 */ // }}}
typedef std::vector<device_partition_property> device_partition_properties;

/** \addtogroup clxx_platform_layer
 * @{ */
/** // doc: device_partition_properties_array_size(const device_partition_properties&) {{{
 * \brief Compute minium size of C array necessary to store context properties
 *
 * This function computes minimal size (number of elements) of a C array
 * of type \c cl_device_partition_property necessary to hold context properties
 * encapsulated within \ref device_partition_properties container together with the
 * trailing zero.
 *
 * \param props encapsulated context properties
 * \returns the minimum size of array (number of elements)
 */ // }}}
size_t device_partition_properties_array_size(const device_partition_properties& props);
/** // doc: device_partition_properties_fill_array(const device_partition_properties&, cl_device_partition_property*, size_t) {{{
 * \brief Write context properties to a C array
 *
 * This function writes context properties encapsulated within
 * \ref device_partition_properties container to a plain C array of type
 * \c cl_device_partition_property. It also appends the trailing zero to the end of
 * the properties (as it's required by most OpenCL functions).
 *
 * \param props the encapsulated properties to be written out,
 * \param array the destination array,
 * \param size array size (number of elements).
 *
 * \returns number of elements written out to **array** (including the trailing
 *          zero).
 *
 * \throw invalid_argument_error if **array** <tt>== nullefttr</tt>,
 * \throw not_enough_space_error if **size** is lower than required
 *        minimum (see \ref device_partition_properties_array_size()).
 */ // }}}
size_t device_partition_properties_fill_array(const device_partition_properties& props,
                                     cl_device_partition_property* array,
                                     size_t size);
/** // doc: device_partition_properties_parse_array(device_partition_properties&, const cl_device_partition_property*) {{{
 * \brief Parse array of OpenCL context properties
 *
 * This function parses an array of \c cl_device_partition_property and appends new
 * properties retrieved from this array to \ref device_partition_properties container.
 *
 * \param props destination container,
 * \param array source array to be parsed.
 * \returns number of elements retrieved from **array** (does not count the
 *          trailing zero)
 *
 * \throw invalid_argument_error if **array** <tt>== nullefttr</tt>,
 */ // }}}
size_t device_partition_properties_parse_array(device_partition_properties& props,
                                      const cl_device_partition_property* array);
/** // doc: operator & (device_partition_property, device_partition_property) {{{
 * \brief Join context properties
 *
 * \param left  left operand, an single \ref device_partition_property
 * \param right  right operand, a single \ref device_partition_property
 *
 * \returns a new instance of \ref device_partition_properties containing **left** property
 *    followed by the **right** property.
 */ // }}}
device_partition_properties operator& (device_partition_property const& left,
                              device_partition_property const& right);
/** // doc: operator & (device_partition_properties, device_partition_property) {{{
 * \brief Join \ref device_partition_properties and \ref device_partition_property
 *
 * \param left  left operand, an instance of \ref device_partition_properties
 * \param right  right operand, a single \ref device_partition_property
 *
 * \returns a new instance of \ref device_partition_properties containing **left**
 *    properties followed by **right** property.
 */ // }}}
device_partition_properties operator& (device_partition_properties const& left,
                              device_partition_property const& right);
/** // doc: operator & (device_partition_property, device_partition_properties) {{{
 * \brief Join \ref device_partition_property and \ref device_partition_properties
 *
 * \param left  left operand, a single \ref device_partition_property,
 * \param right  right operand, an instance of \ref device_partition_properties.
 *
 * \returns a new instance of \ref device_partition_properties containing **left**
 *    property followed by **right** properties.
 */ // }}}
device_partition_properties operator& (device_partition_property const& left,
                              device_partition_properties const& right);
/** // doc: operator & (device_partition_properties, device_partition_properties) {{{
 * \brief Joint two instances of \ref device_partition_properties
 *
 * \param left  left operand, an instance of \ref device_partition_properties
 * \param right  right operand, an instance of \ref device_partition_properties.
 *
 * \returns a new instance of \ref device_partition_properties containing **left**
 *    properties followed by **right** properties.
 */ // }}}
device_partition_properties operator& (device_partition_properties const& left,
                              device_partition_properties const& right);
/** // doc: make_device_partition_properties() {{{
 * \brief Create empty container for context properties
 *
 * \returns a new instance of \ref device_partition_properties, an empty container
 */ // }}}
inline device_partition_properties
make_device_partition_properties()
{
  return device_partition_properties();
}
/** // doc: make_device_partition_properties(x1,...) {{{
 * \brief Generate context properties
 *
 * This template function provides convenient and flexible way to initialize
 * \ref device_partition_properties. It recursivelly invokes the \c operator&.
 *
 * **Example:**
 * \code
 *  platforms ps = get_platforms();
 *  device_partition_properties cp = make_device_partition_properties(ps[0], context_interop_user_sync(true));
 *  // ...
 * \endcode
 *
 * \returns a new instance of \ref device_partition_properties initialized with values
 *    provided as arguments to the function.
 */ // }}}
template <class T1, class... Tail>
inline device_partition_properties
make_device_partition_properties(T1 const& x1, Tail const&... tail)
{
  return x1 & make_device_partition_properties(tail...);
}
/** @} */

} // end namespace clxx

#endif /* CLXX_CL_DEVICE_PARTITION_PROPERTIES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
