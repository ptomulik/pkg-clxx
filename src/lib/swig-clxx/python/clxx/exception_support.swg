// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exception_support.swg {{{
 * \file clxx/exception_support.swg
 * \todo Write documentation
 */ // }}}

%{
#define SWIG_Clxx_KeyError(e) { PyErr_SetString(PyExc_KeyError, const_cast<char*>(e.what())); SWIG_fail; }
%}

%include <clxx/exception_support.li.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
