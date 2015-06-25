// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/kernel.li.i {{{
 * \file clxx/kernel.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>
%import <clxx/wknd.swg>
%include <clxx/exception_support.swg>

%import <clxx/types.i>
%import <clxx/devices.i>
%import <clxx/program.i>
%import <clxx/context.i>
%import <clxx/std/string.i>

%{
#include <clxx/types.i.hpp>
#include <clxx/devices.i.hpp>
#include <clxx/program.i.hpp>
#include <clxx/context.i.hpp>
#include <clxx/std/string.i.hpp>
%}

%include <clxx/ndrange.swg>
%include <clxx/kernel.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
