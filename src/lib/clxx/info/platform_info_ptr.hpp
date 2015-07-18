// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/platform_info_ptr.hpp

/** // doc: clxx/info/platform_info_ptr.hpp {{{
 * \file clxx/info/platform_info_ptr.hpp
 * \brief Defines \ref clxx::platform_info_ptr "platform_info_ptr"
 */ // }}}
#ifndef CLXX_INFO_PLATFORM_INFO_PTR_HPP_INCLUDED
#define CLXX_INFO_PLATFORM_INFO_PTR_HPP_INCLUDED

#include <clxx/shared_ptr.hpp>

namespace clxx {

class platform_info;
/** // doc: platform_info_ptr // {{{
 * \brief Shared pointer to \ref clxx::platform_info "platform_info" object
 *
 * This is used by containers such as \ref clxx::platform_layer_info.
 */ // }}}
typedef shared_ptr<platform_info> platform_info_ptr;
/** // doc: platform_info_ptr // {{{
 * \brief Shared pointer to const \ref clxx::platform_info "platform_info" object
 *
 * This is used by containers such as \ref clxx::platform_layer_info.
 */ // }}}
typedef shared_ptr<const platform_info> const_platform_info_ptr;

} // end namespace clxx

#endif /* CLXX_INFO_PLATFORM_INFO_PTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
