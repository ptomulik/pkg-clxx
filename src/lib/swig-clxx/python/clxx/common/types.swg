// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: python/clxx/common/types.swg {{{
 * \file python/clxx/common/types.swg
 * \brief Python specific implementation of clxx/common/types.swg
 */ // }}}

// Rename some symbols
%rename(_global) clxx::device_local_mem_type_t::global;
%rename(_global) clxx::kernel_arg_address_qualifier_t::global;

// use enchanced enums (strongly typed and scoped)
%include <enums.swg>

%include <clxx/common/types.li.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
