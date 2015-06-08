// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_info_ptr.hpp

/** // doc: clxx/platform_info_ptr.hpp {{{
 * \file clxx/platform_info_ptr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PLATFORM_INFO_PTR_HPP_INCLUDED
#define CLXX_PLATFORM_INFO_PTR_HPP_INCLUDED

#include <clxx/shared_ptr.hpp>

namespace clxx {

class platform_info;
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
typedef shared_ptr<platform_info> platform_info_ptr;
typedef shared_ptr<const platform_info> const_platform_info_ptr;
/** \endcond */

} // end namespace clxx

#endif /* CLXX_PLATFORM_INFO_PTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
