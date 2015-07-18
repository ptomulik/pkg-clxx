// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/device_info_ptr.hpp

/** // doc: clxx/info/device_info_ptr.hpp {{{
 * \file clxx/info/device_info_ptr.hpp
 * \brief Defines \ref clxx::device_info_ptr "device_info_ptr"
 */ // }}}
#ifndef CLXX_INFO_DEVICE_INFO_PTR_HPP_INCLUDED
#define CLXX_INFO_DEVICE_INFO_PTR_HPP_INCLUDED

#include <clxx/common/shared_ptr.hpp>

namespace clxx {

class device_info;
/** // doc: device_info_ptr // {{{
 * \brief Shared pointer to \ref clxx::device_info "device_info" object
 *
 * This is used by containers such as \ref clxx::platform_layer_info.
 */ // }}}
typedef shared_ptr<device_info> device_info_ptr;
/** // doc: device_info_ptr // {{{
 * \brief Shared pointer to const \ref clxx::device_info "device_info" object
 *
 * This is used by containers such as \ref clxx::platform_layer_info.
 */ // }}}
typedef shared_ptr<const device_info> const_device_info_ptr;

} // end namespace clxx;

#endif /* CLXX_INFO_DEVICE_INFO_PTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
