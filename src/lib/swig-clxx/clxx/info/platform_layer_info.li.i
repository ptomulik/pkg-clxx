// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: platform_layer_info.li.i {{{
 * \file platform_layer_info.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>
%import <clxx/wknd.swg>
%include <clxx/common/shared_ptr.swg>
%include <clxx/exception_support.swg>

%import <clxx/info/platform_info.i>
%import <clxx/info/device_info.i>
%{
#include <clxx/info/platform_info.i.hpp>
#include <clxx/info/device_info.i.hpp>
%}

%include <clxx/info/platform_layer_info.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
