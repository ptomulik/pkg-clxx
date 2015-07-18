// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/program_binaries.li.swg {{{
 * \file clxx/common/program_binaries.li.swg
 * \todo Write documentation
 */ // }}}

%include <clxx/common/program_binary.swg>
%{
#include <clxx/common/program_binaries.hpp>
%}
%template(program_binaries) std::vector<clxx::program_binary>;
%ignore clxx::program_binaries;
%include <clxx/common/program_binaries.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
