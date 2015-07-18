// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/info/platform_info_ptrs.li.swg {{{
 * \file clxx/info/platform_info_ptrs.li.swg
 * \todo Write documentation
 */ // }}}
%{
#include <clxx/info/platform_info_ptrs.hpp>
%}

%include <clxx/info/platform_info_ptr.swg>
%include <std_vector.i>
%template(platform_info_ptrs) std::vector< clxx::platform_info_ptr >;
%template(const_platform_info_ptrs) std::vector< clxx::const_platform_info_ptr >;
%include <clxx/info/platform_info_ptrs.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
