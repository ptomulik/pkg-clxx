// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_info_ptrs.hpp

/** // doc: clxx/device_info_ptrs.hpp {{{
 * \file clxx/device_info_ptrs.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_INFO_PTRS_HPP_INCLUDED
#define CLXX_DEVICE_INFO_PTRS_HPP_INCLUDED

#include <clxx/device_info_ptr.hpp>
#include <vector>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
typedef std::vector<clxx::device_info_ptr> device_info_ptrs;
typedef std::vector<clxx::const_device_info_ptr> const_device_info_ptrs;
/** \endcond */
} // end namespace clxx

#endif /* CLXX_DEVICE_INFO_PTRS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
