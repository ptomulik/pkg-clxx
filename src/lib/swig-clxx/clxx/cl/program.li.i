// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program.li.i {{{
 * \file clxx/cl/program.li.i
 * \todo Write documentation
 */ // }}}

%include <std_vector.i>

%import <clxx/wknd.swg>
%include <clxx/exception_support.swg>

%import <clxx/types.i>
%import <clxx/cl/clobj.i>
%import <clxx/cl/devices.i>
%import <clxx/cl/context.i>
%import <clxx/program_sources.i>
%import <clxx/program_binaries.i>
%import <clxx/std/string.i>

%{
#include <clxx/types.i.hpp>
#include <clxx/cl/clobj.i.hpp>
#include <clxx/cl/devices.i.hpp>
#include <clxx/cl/context.i.hpp>
#include <clxx/program_sources.i.hpp>
#include <clxx/program_binaries.i.hpp>
#include <clxx/std/string.i.hpp>
%}

%include <clxx/cl/program_observer.swg>
%include <clxx/cl/program.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
