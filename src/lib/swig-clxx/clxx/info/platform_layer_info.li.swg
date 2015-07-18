// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/info/platform_layer_info.li.swg {{{
 * \file clxx/info/platform_layer_info.li.swg
 * \todo Write documentation
 */ // }}}

%include <clxx/info/platform_info_ptrs.swg>
%include <clxx/info/device_info_ptrs.swg>
%{
#include <clxx/info/platform_layer_info.hpp>
%}

%include <clxx/exception_support.swg>
%define %throws_as_boost_bimap_at(decl)
%exception decl {
  try { $action }
  catch(std::out_of_range const& e) { SWIG_Clxx_KeyError(e); }
  %catch_exception
}
%enddef

%throws_as_boost_bimap_at(clxx::platform_layer_info::get_platform);
%throws_badalloc(clxx::platform_layer_info::get_devices);
%throws_badalloc(clxx::platform_layer_info::push_back);

%include <clxx/info/platform_layer_info.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
