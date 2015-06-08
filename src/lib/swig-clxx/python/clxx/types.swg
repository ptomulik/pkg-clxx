// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: python/clxx/types.swg {{{
 * \file python/clxx/types.swg
 * \brief Python specific implementation of clxx/types.swg
 */ // }}}

// Rename some symbols
%rename(_global) clxx::device_local_mem_type_t::global;
%rename(_global) clxx::kernel_arg_address_qualifier_t::global;

// use enchanced enums (strongly typed and scoped)
%include <enums.swg>

%include <clxx/types.li.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
