// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_info_ptrs.hpp

/** // doc: clxx/platform_info_ptrs.hpp {{{
 * \file clxx/platform_info_ptrs.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PLATFORM_INFO_PTRS_HPP_INCLUDED
#define CLXX_PLATFORM_INFO_PTRS_HPP_INCLUDED

#include <clxx/platform_info_ptr.hpp>
#include <vector>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
typedef std::vector<clxx::platform_info_ptr> platform_info_ptrs;
typedef std::vector<clxx::const_platform_info_ptr> const_platform_info_ptrs;
/** \endcond */
} // end namespace clxx

#endif /* CLXX_PLATFORM_INFO_PTRS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
