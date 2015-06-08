// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_info_ptr.hpp

/** // doc: clxx/device_info_ptr.hpp {{{
 * \file clxx/device_info_ptr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_INFO_PTR_HPP_INCLUDED
#define CLXX_DEVICE_INFO_PTR_HPP_INCLUDED

#include <clxx/shared_ptr.hpp>

namespace clxx {

class device_info;
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
typedef shared_ptr<device_info> device_info_ptr;
typedef shared_ptr<const device_info> const_device_info_ptr;
/** \endcond */

} // end namespace clxx;

#endif /* CLXX_DEVICE_INFO_PTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
