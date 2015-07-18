// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/kernel.li.i {{{
 * \file clxx/cl/kernel.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>
%import <clxx/wknd.swg>
%include <clxx/exception_support.swg>

%import <clxx/common/types.i>
%import <clxx/cl/clobj.i>
%import <clxx/cl/devices.i>
%import <clxx/cl/program.i>
%import <clxx/cl/context.i>
%import <clxx/std/string.i>

%{
#include <clxx/common/types.i.hpp>
#include <clxx/cl/clobj.i.hpp>
#include <clxx/cl/devices.i.hpp>
#include <clxx/cl/program.i.hpp>
#include <clxx/cl/context.i.hpp>
#include <clxx/std/string.i.hpp>
%}

%include <clxx/common/ndrange.swg>
%include <clxx/cl/kernel.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
