// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exceptions.li.i {{{
 * \file clxx/exceptions.li.i
 * \todo Write documentation
 */ // }}}


%import <clxx/std/string.i>
%import <clxx/std/exception.i>
%import <clxx/std/bad_alloc.i>
%import <clxx/types.i>
%{
#include <clxx/std/string.i.hpp>
#include <clxx/std/exception.i.hpp>
#include <clxx/std/bad_alloc.i.hpp>
#include <clxx/types.i.hpp>
%}


//%include <clxx/exception.swg>
%include <clxx/exception_base.swg>
//%include <clxx/clerror_base.swg>
//%include <clxx/clerror.swg>
%include <clxx/clerror_no.swg>
%include <clxx/exceptions.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
