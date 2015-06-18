// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/device_query.hpp

/** // doc: clxx/s11n/device_query.hpp {{{
 * \file clxx/s11n/device_query.hpp
 * \brief Declares a specialization of boost::serialization::serialize function
 *    for \ref clxx::device_query "device_query" class
 */ // }}}
#ifndef CLXX_S11N_DEVICE_QUERY_HPP_INCLUDED
#define CLXX_S11N_DEVICE_QUERY_HPP_INCLUDED

#include <clxx/device_query.hpp>
#include <boost/serialization/version.hpp>

BOOST_CLASS_VERSION( clxx::device_query
                   , clxx::device_query::class_version )

namespace boost {
namespace serialization {
/** \addtogroup clxx_s11n
 * @{ */
/** // doc: serialize(ar,obj,ver) {{{
 * \brief Serialize or deserialize \ref clxx::device_query "device_query" object
 *
 * \param ar  Archive used to store or restore the object \e obj.
 * \param obj The object to be serialized
 * \param ver Version of the object \e obj being serialized or deserialized.
 *
 * \note When serializing, the \e ver argument shall receive the value of
 *       \ref clxx::device_query::class_version "device_query::class_version".
 */ // }}}
template<class Archive>
void serialize(Archive& ar, clxx::device_query& obj, const unsigned int ver);
/** @} */
} /* namespace serialization */
} /* namespace boost */

#endif /* CLXX_S11N_DEVICE_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
