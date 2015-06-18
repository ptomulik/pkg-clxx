// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_info_ptrs.hpp

/** // doc: clxx/device_info_ptrs.hpp {{{
 * \file clxx/device_info_ptrs.hpp
 * \brief Defines \ref clxx::device_info_ptrs "device_info_ptrs"
 */ // }}}
#ifndef CLXX_DEVICE_INFO_PTRS_HPP_INCLUDED
#define CLXX_DEVICE_INFO_PTRS_HPP_INCLUDED

#include <clxx/device_info_ptr.hpp>
#include <vector>

namespace clxx {
/** // doc: device_info_ptrs {{{
 * \brief Sequence of (shared) pointers to \ref clxx::device_info "device_info" objects
 */ // }}}
typedef std::vector<clxx::device_info_ptr> device_info_ptrs;
/** // doc: const_device_info_ptrs {{{
 * \brief Sequence of (shared) pointers to const \ref clxx::device_info "device_info" objects
 */ // }}}
typedef std::vector<clxx::const_device_info_ptr> const_device_info_ptrs;
} // end namespace clxx

#endif /* CLXX_DEVICE_INFO_PTRS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
