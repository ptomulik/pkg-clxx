// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/platform_layer_info.hpp

/** // doc: clxx/s11n/platform_layer_info.hpp {{{
 * \file clxx/s11n/platform_layer_info.hpp
 * \brief Implements serialization of \ref clxx::platform_layer_info "platform_layer_info"
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED
#define CLXX_S11N_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED

#include <clxx/s11n/platform_layer_info.hpp>
#include <clxx/s11n/platform_info.hpp>
#include <clxx/s11n/device_info.hpp>
#include <clxx/s11n/shared_ptr.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/utility.hpp>

namespace clxx {

/** // doc: _serialize(Archive, platform_layer_info&, const unsigned int) {{{
 * \brief Implements serialization of \ref clxx::platform_layer_info "platform_layer_info"
 *
 * \param ar  Archive used for serialization.
 * \param obj The object to be serialized.
 * \param ver Class version
 */ // }}}
template<class Archive>
void _serialize(Archive& ar, platform_layer_info& obj, const unsigned int ver)
{
  (void)ver;
  using boost::serialization::make_nvp;
  ar & make_nvp("bimap", obj._bimap);
}

} // end namespace clxx

namespace boost {
namespace serialization {

/* ------------------------------------------------------------------------ */
template <class Archive>
void serialize(Archive& ar, clxx::platform_layer_info& obj, const unsigned int ver)
{
  clxx::_serialize(ar, obj, ver);
}
/* ------------------------------------------------------------------------ */

} /* namespace boost */
} /* namespace serialization */

#endif /* CLXX_S11N_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
