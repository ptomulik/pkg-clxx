// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platforms.li.i {{{
 * \file clxx/platforms.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>
%include <clxx/exception_support.swg>

%import <clxx/types.i>
%import <clxx/std/string.i>
%import <clxx/platform_query.i>
%import <clxx/platform_info.i>

%{
#include <clxx/types.i.hpp>
#include <clxx/std/string.i.hpp>
#include <clxx/platform_query.i.hpp>
#include <clxx/platform_info.i.hpp>
%}

%include <clxx/platform.swg>
%include <clxx/platforms.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
