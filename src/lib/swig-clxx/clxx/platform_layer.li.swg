// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform_layer.li.swg {{{
 * \file clxx/platform_layer.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/platform_layer.hpp>
%}

%include <clxx/exception_support.swg>

%throws_clerror_badalloc(clxx::platform_layer::platform_layer(device_type_t));
%throws_clerror_badalloc(clxx::platform_layer::platform_layer(bool, device_type_t));
%throws_badalloc(clxx::platform_layer::get_devices(const platform&) const);
%throws_invalid_key_error(clxx::platform_layer::get_platform);
%throws_badalloc(clxx::platform_layer::add);
%throws_invalid_key_error_badalloc(clxx::platform_layer::erase(device const&));
%throws_invalid_key_error_badalloc(clxx::platform_layer::erase(platform const&));
%throws_clerror_badalloc(clxx::platform_layer::load_opencl(device_type_t));

%throws_clerror_badalloc(clxx::query_platform_layer_info);

%include <clxx/platform_layer.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
