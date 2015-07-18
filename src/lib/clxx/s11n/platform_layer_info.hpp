// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/platform_layer_info.hpp

/** // doc: clxx/s11n/platform_layer_info.hpp {{{
 * \file clxx/s11n/platform_layer_info.hpp
 * \brief Declares boost::serialization::serialize function for
 *    \ref clxx::platform_layer_info "platform_layer_info" class
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_LAYER_INFO_HPP_INCLUDED
#define CLXX_S11N_PLATFORM_LAYER_INFO_HPP_INCLUDED

#include <clxx/info/platform_layer_info.hpp>
#include <boost/serialization/version.hpp>

BOOST_CLASS_VERSION( clxx::platform_layer_info
                   , clxx::platform_layer_info::class_version )

namespace boost {
namespace serialization {
/** \addtogroup clxx_s11n
 * @{ */
/** // doc: serialize(ar,obj,ver) {{{
 * \brief Serialize or deserialize \ref clxx::platform_layer_info
 *    "platform_layer_info" object
 *
 * \param ar  Archive used to store or restore \e obj.
 * \param obj The object to be serialized
 * \param ver Version of the object \e obj being serialized or deserialized.
 *
 * \note When serializing, the \e ver argument shall receive the value of
 *       \ref clxx::platform_layer_info::class_version "platform_layer_info::class_version".
 */ // }}}
template<class Archive>
void serialize(Archive& ar, clxx::platform_layer_info& obj, const unsigned int ver);
/** @} */
} /* namespace serialization */
} /* namespace boost */

#endif /* CLXX_S11N_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
