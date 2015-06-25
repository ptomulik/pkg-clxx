// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform.li.i {{{
 * \file clxx/platform.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>

%import <clxx/wknd.swg>
%include <clxx/exception_support.swg>

%import <clxx/std/string.i>
%import <clxx/std/map.i>
%import <clxx/std/set.i>
%import <clxx/platforms.i>
%import <clxx/devices.i>
%import <clxx/platform_layer_info.i>

%{
#include <clxx/std/string.i.hpp>
#include <clxx/std/map.i.hpp>
#include <clxx/std/set.i.hpp>
#include <clxx/platforms.i.hpp>
#include <clxx/devices.i.hpp>
#include <clxx/platform_layer_info.i.hpp>
%}

%include <clxx/platform_layer.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
