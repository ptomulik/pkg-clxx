// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform_info_ptrs.li.swg {{{
 * \file clxx/platform_info_ptrs.li.swg
 * \todo Write documentation
 */ // }}}
%{
#include <clxx/platform_info_ptrs.hpp>
%}

%include <clxx/platform_info_ptr.swg>
%include <std_vector.i>
%template(platform_info_ptrs) std::vector< clxx::platform_info_ptr >;
%template(const_platform_info_ptrs) std::vector< clxx::const_platform_info_ptr >;
%include <clxx/platform_info_ptrs.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
