// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/platforms.li.swg {{{
 * \file clxx/cl/platforms.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/cl/platforms.hpp>
%}
//%include <clxx/cl/platform.swg>
%include <std_vector.i>
%template() std::vector<cl_platform_id>; // used by get_platform_ids();
%template(platforms) std::vector<clxx::platform>;
%ignore clxx::platforms;

%include <clxx/exception_support.swg>

%throws_clerror(clxx::get_num_platforms());
%throws_clerror_badalloc(clxx::get_platform_ids());
%throws_clerror_badalloc(clxx::get_platforms());
%throws_badalloc(clxx::make_platforms(std::vector<cl_platform_id> const&));

%include <clxx/cl/platforms.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
