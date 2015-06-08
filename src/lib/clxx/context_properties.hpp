// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/context_properties.hpp

/** // doc: clxx/context_properties.hpp {{{
 * \file clxx/context_properties.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CONTEXT_PROPERTIES_HPP_INCLUDED
#define CLXX_CONTEXT_PROPERTIES_HPP_INCLUDED

#include <clxx/context_property.hpp>
#include <clxx/cl/cl.h>
#include <vector>

namespace clxx {
/** // doc: context_properties {{{
 * \ingroup clxx_platform_layer
 * \brief Container for context properties
 */ // }}}
typedef std::vector<context_property> context_properties;

/** \ingroup clxx_platform_layer
 * @{ */
/** // doc: context_properties_array_size(const context_properties&) {{{
 * \brief Compute minium size of C array necessary to store context properties
 *
 * This function computes minimal size (number of elements) of a C array
 * of type \c cl_context_properties necessary to hold context properties
 * encapsulated within \ref context_properties container together with the
 * trailing zero.
 *
 * \param props encapsulated context properties
 * \returns the minimum size of array (number of elements)
 */ // }}}
size_t context_properties_array_size(const context_properties& props);
/** // doc: context_properties_fill_array(const context_properties&, cl_context_properties*, size_t) {{{
 * \brief Write context properties to a C array
 *
 * This function writes context properties encapsulated within
 * \ref context_properties container to a plain C array of type
 * \c cl_context_properties. It also appends the trailing zero to the end of
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
 *        minimum (see \ref context_properties_array_size()).
 */ // }}}
size_t context_properties_fill_array(const context_properties& props,
                                     cl_context_properties* array,
                                     size_t size);
/** // doc: context_properties_parse_array(context_properties&, const cl_context_properties*) {{{
 * \brief Parse array of OpenCL context properties
 *
 * This function parses an array of \c cl_context_properties and appends new
 * properties retrieved from this array to \ref context_properties container.
 *
 * \param props destination container,
 * \param array source array to be parsed.
 * \returns number of elements retrieved from **array** (does not count the
 *          trailing zero)
 *
 * \throw invalid_argument_error if **array** <tt>== nullefttr</tt>,
 */ // }}}
size_t context_properties_parse_array(context_properties& props,
                                      const cl_context_properties* array);
/** // doc: operator & (context_property, context_property) {{{
 * \brief Join context properties
 *
 * \param left  left operand, an single \ref context_property
 * \param right  right operand, a single \ref context_property
 *
 * \returns a new instance of \ref context_properties containing **left** property
 *    followed by the **right** property.
 */ // }}}
context_properties operator& (context_property const& left,
                              context_property const& right);
/** // doc: operator & (context_properties, context_property) {{{
 * \brief Join \ref context_properties and \ref context_property
 *
 * \param left  left operand, an instance of \ref context_properties
 * \param right  right operand, a single \ref context_property
 *
 * \returns a new instance of \ref context_properties containing **left**
 *    properties followed by **right** property.
 */ // }}}
context_properties operator& (context_properties const& left,
                              context_property const& right);
/** // doc: operator & (context_property, context_properties) {{{
 * \brief Join \ref context_property and \ref context_properties
 *
 * \param left  left operand, a single \ref context_property,
 * \param right  right operand, an instance of \ref context_properties.
 *
 * \returns a new instance of \ref context_properties containing **left**
 *    property followed by **right** properties.
 */ // }}}
context_properties operator& (context_property const& left,
                              context_properties const& right);
/** // doc: operator & (context_properties, context_properties) {{{
 * \brief Joint two instances of \ref context_properties
 *
 * \param left  left operand, an instance of \ref context_properties
 * \param right  right operand, an instance of \ref context_properties.
 *
 * \returns a new instance of \ref context_properties containing **left**
 *    properties followed by **right** properties.
 */ // }}}
context_properties operator& (context_properties const& left,
                              context_properties const& right);
/** // doc: make_context_properties() {{{
 * \brief Create empty container for context properties
 *
 * \returns a new instance of \ref context_properties, an empty container
 */ // }}}
inline context_properties
make_context_properties()
{
  return context_properties();
}
/** // doc: make_context_properties(x1,...) {{{
 * \brief Generate context properties
 *
 * This template function provides convenient and flexible way to initialize
 * \ref context_properties. It recursivelly invokes the \c operator&.
 *
 * **Example:**
 * \code
 *  platforms ps = get_platforms();
 *  context_properties cp = make_context_properties(ps[0], context_interop_user_sync(true));
 *  // ...
 * \endcode
 *
 * \returns a new instance of \ref context_properties initialized with values
 *    provided as arguments to the function.
 */ // }}}
template <class T1, class... Tail>
inline context_properties
make_context_properties(T1 const& x1, Tail const&... tail)
{
  return x1 & make_context_properties(tail...);
}
/** @} */

} // end namespace clxx

#endif /* CLXX_CONTEXT_PROPERTIES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
