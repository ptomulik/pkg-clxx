// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/device_info.hpp

/** // doc: clxx/s11n/device_info.hpp {{{
 * \file clxx/s11n/device_info.hpp
 * \brief Declares a specialization of boost::serialization::serialize function
 *    for \ref clxx::device_info "device_info" class
 */ // }}}
#ifndef CLXX_S11N_DEVICE_INFO_HPP_INCLUDED
#define CLXX_S11N_DEVICE_INFO_HPP_INCLUDED

#include <clxx/device_info.hpp>
#include <boost/serialization/version.hpp>

BOOST_CLASS_VERSION( clxx::device_info
                   , clxx::device_info::class_version )

namespace boost {
namespace serialization {
/** \addtogroup clxx_s11n
 *  @{ */
/** // doc: serialize(ar,obj,ver) {{{
 * \brief Serialize or deserialize \ref clxx::device_info "device_info" object
 *
 * \param ar  Archive used to store or restore the object \e obj.
 * \param obj The object to be serialized
 * \param ver Version of the object \e obj being serialized or deserialized.
 *
 * \note When serializing, the \e ver argument shall receive the value of
 *       \ref clxx::device_info::class_version "device_info::class_version".
 */ // }}}
template<class Archive>
void serialize(Archive& ar, clxx::device_info& obj, const unsigned int ver);
/** @} */
} /* namespace serialization */
} /* namespace boost */

#endif /* CLXX_S11N_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
