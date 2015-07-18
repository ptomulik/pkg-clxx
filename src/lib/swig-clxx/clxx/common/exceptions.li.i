// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/exceptions.li.i {{{
 * \file clxx/common/exceptions.li.i
 * \todo Write documentation
 */ // }}}


%import <clxx/std/string.i>
%import <clxx/std/exception.i>
%import <clxx/std/bad_alloc.i>

%import <clxx/wknd.swg>
%import <clxx/common/types.i>
%{
#include <clxx/std/string.i.hpp>
#include <clxx/std/exception.i.hpp>
#include <clxx/std/bad_alloc.i.hpp>
#include <clxx/common/types.i.hpp>
%}


//%include <clxx/common/exception.swg>
%include <clxx/common/exception_base.swg>
//%include <clxx/common/clerror_base.swg>
//%include <clxx/common/clerror.swg>
%include <clxx/common/clerror_no.swg>
%include <clxx/common/exceptions.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
