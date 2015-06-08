// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/program.li.i {{{
 * \file clxx/program.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>
%include <clxx/exception_support.swg>

%import <clxx/types.i>
%import <clxx/devices.i>
%import <clxx/context.i>
%import <clxx/program_sources.i>
%import <clxx/program_binaries.i>
%import <clxx/std/string.i>

%{
#include <clxx/types.i.hpp>
#include <clxx/devices.i.hpp>
#include <clxx/context.i.hpp>
#include <clxx/program_sources.i.hpp>
#include <clxx/program_binaries.i.hpp>
#include <clxx/std/string.i.hpp>
%}

%include <clxx/program_observer.swg>
%include <clxx/program.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
