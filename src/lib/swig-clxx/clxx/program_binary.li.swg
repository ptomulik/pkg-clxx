// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/program_binary.li.swg {{{
 * \file clxx/program_binary.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/program_binary.hpp>
%}
%template(program_binary) std::vector<unsigned char>;
%ignore clxx::program_binary;
%include <clxx/program_binary.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
