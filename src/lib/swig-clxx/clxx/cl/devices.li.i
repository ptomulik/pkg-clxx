// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/devices.li.i {{{
 * \file clxx/cl/devices.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>

%import <clxx/wknd.swg>
%include <clxx/exception_support.swg>

%import <clxx/types.i>
%import <clxx/cl/clobj.i>
%import <clxx/std/string.i>
%import <clxx/info/device_query.i>
%import <clxx/info/device_info.i>
%import <clxx/cl/platforms.i>

%{
#include <clxx/types.i.hpp>
#include <clxx/cl/clobj.i.hpp>
#include <clxx/std/string.i.hpp>
#include <clxx/info/device_query.i.hpp>
#include <clxx/info/device_info.i.hpp>
#include <clxx/cl/platforms.i.hpp>
%}

%include <clxx/cl/device.swg>
%include <clxx/cl/devices.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
