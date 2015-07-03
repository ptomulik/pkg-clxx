// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform.li.swg {{{
 * \file clxx/platform.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/platform.hpp>
%}

%include <clxx/exception_support.swg>

%define %throws_as_platform_get_str_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_platform_error
  %catch_clerror
  %catch_badalloc
  %catch_exception
}
%enddef

%exception clxx::platform::chk_get() const {
  try { $action }
  %catch_uninitialized_platform_error
  %catch_exception
}

%exception clxx::platform::get_info(clxx::platform_info_t, size_t, void *, size_t *) const {
  try { $action }
  %catch_uninitialized_platform_error
  %catch_clerror
  %catch_exception
}

%throws_as_platform_get_str_info(clxx::platform::get_profile() const);
%throws_as_platform_get_str_info(clxx::platform::get_version() const);
%throws_as_platform_get_str_info(clxx::platform::get_name() const);
%throws_as_platform_get_str_info(clxx::platform::get_vendor() const);
%throws_as_platform_get_str_info(clxx::platform::get_extensions() const);

// TODO: specify exceptions for the following function
//clxx::get_platform_info(clxx::platform, const& p, clxx::platform_query const&)

%template(clobj_platform) clxx::clobj<cl_platform_id>;

%include <clxx/platform.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
