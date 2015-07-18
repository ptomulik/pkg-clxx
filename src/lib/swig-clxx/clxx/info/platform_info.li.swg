// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/info/platform_info.li.swg {{{
 * \file clxx/info/platform_info.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/info/platform_info.hpp>
%}
%include <clxx/exception_support.swg>

%throws_uninitialized_value_error(clxx::platform_info::id() const);
%throws_uninitialized_value_error(clxx::platform_info::profile() const);
%throws_uninitialized_value_error(clxx::platform_info::version() const);
%throws_uninitialized_value_error(clxx::platform_info::name() const);
%throws_uninitialized_value_error(clxx::platform_info::vendor() const);
%throws_uninitialized_value_error(clxx::platform_info::extensions() const);
%throws_badalloc(clxx::platform_info::set_profile(std::string const&));
%throws_badalloc(clxx::platform_info::set_version(std::string const&));
%throws_badalloc(clxx::platform_info::set_name(std::string const&));
%throws_badalloc(clxx::platform_info::set_vendor(std::string const&));
%throws_badalloc(clxx::platform_info::set_extensions(std::string const&));

%include <clxx/info/platform_info.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
