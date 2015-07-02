// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/devices.li.i {{{
 * \file clxx/devices.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>

%import <clxx/wknd.swg>
%include <clxx/exception_support.swg>

%import <clxx/types.i>
%import <clxx/clobj.i>
%import <clxx/std/string.i>
%import <clxx/device_query.i>
%import <clxx/device_info.i>
%import <clxx/platforms.i>

%{
#include <clxx/types.i.hpp>
#include <clxx/clobj.i.hpp>
#include <clxx/std/string.i.hpp>
#include <clxx/device_query.i.hpp>
#include <clxx/device_info.i.hpp>
#include <clxx/platforms.i.hpp>
%}

%include <clxx/device.swg>
%include <clxx/devices.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
