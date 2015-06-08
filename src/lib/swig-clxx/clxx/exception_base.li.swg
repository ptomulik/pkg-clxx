// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exception_base.li.swg {{{
 * \file clxx/exception_base.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/exception_base.hpp>
%}
%include <clxx/exception.swg>
%include <clxx/util/std_except_ctor_arg.swg>

%include <clxx/exception_base.hpp>

// Instantiate most commonly used specializations of exception_base
%template(exception_base_logic_error) clxx::exception_base<clxx::exception, std::logic_error>;
%template(exception_base_invalid_argument) clxx::exception_base<clxx::exception, std::invalid_argument>;
%template(exception_base_length_error) clxx::exception_base<clxx::exception, std::length_error>;
%template(exception_base_out_of_range) clxx::exception_base< clxx::exception,std::out_of_range >;

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
