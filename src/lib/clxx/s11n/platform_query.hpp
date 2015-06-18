// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/platform_query.hpp

/** // doc: clxx/s11n/platform_query.hpp {{{
 * \file clxx/s11n/platform_query.hpp
 * \brief Declares boos::serialization::serialize function for
 *    \ref clxx::platform_query "platform_query" class
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_QUERY_HPP_INCLUDED
#define CLXX_S11N_PLATFORM_QUERY_HPP_INCLUDED

#include <clxx/platform_query.hpp>
#include <boost/serialization/version.hpp>

BOOST_CLASS_VERSION( clxx::platform_query
                   , clxx::platform_query::class_version )

namespace boost {
namespace serialization {
/** \addtogroup clxx_s11n
 *  @{ */
/** // doc: serialize(ar,obj,ver) {{{
 * \brief Serialize or deserialize \ref clxx::platform_query "platform_query" object
 *
 * \param ar  Archive used to store or restore \e obj.
 * \param obj The object to be serialized
 * \param ver Version of the object \e obj being serialized or deserialized.
 *
 * \note When serializing, the \e ver argument shall receive the value of
 *       \ref clxx::platform_query::class_version "platform_query::class_version".
 */ // }}}
template<class Archive>
void serialize(Archive& ar, clxx::platform_query& obj, const unsigned int ver);
/** @} */
} /* namespace serialization */
} /* namespace boost */

#endif /* CLXX_S11N_PLATFORM_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
