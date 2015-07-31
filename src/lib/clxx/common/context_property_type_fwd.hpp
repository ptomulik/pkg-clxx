// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/context_property_type_fwd.hpp

/** // doc: clxx/common/context_property_type_fwd.hpp {{{
 * \file clxx/common/context_property_type_fwd.hpp
 * \brief Forward-declares the \ref clxx::context_property_type "conext_property_type" metafunction
 */ // }}}
#ifndef COMMON_CONTEXT_PROPERTY_TYPE_FWD_HPP_INCLUDED
#define COMMON_CONTEXT_PROPERTY_TYPE_FWD_HPP_INCLUDED

namespace clxx {

/** // doc: context_property_type {{{
 * \ingroup clxx_util
 * \brief Returns a type used to represent given context property
 *
 * Context properties defined by OpenCL are identified by enums
 * of type \ref clxx::context_properties_t "context_properties_t".
 * Values of particular context properties may have different types,
 * for example \ref context_properties_t::platform uses \c cl_platform_id,
 * whereas \ref context_properties_t::adapter_d3d9_khr is stored
 * as \c IDirect3DDevice9*.
 *
 * This meta-function maps the enums to appropriate types used to represent
 * particular context properties.
 *
 * \tparam Property property of the question
 *
 * \par Example:
 * \code
 *    typedef clxx::context_property_type<
 *        context_properties_t::interop_user_sync
 *    >::type ius_type;
 * \endcode
 */ // }}}
template <context_properties_t Property> struct context_property_type;

} // end namespace clxx

#endif /* COMMON_CONTEXT_PROPERTY_TYPE_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
