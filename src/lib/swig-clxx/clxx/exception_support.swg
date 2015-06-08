// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exception_support.swg {{{
 * \file clxx/exception_support.swg
 * \todo Write documentation
 */ // }}}

%include <clxx/exception_support.li.swg>

%{
#define SWIG_Clxx_KeyError(e) SWIG_exception(SWIG_IndexError,e.what())
%}

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
