// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/program_sources.li.swg {{{
 * \file clxx/common/program_sources.li.swg
 * \todo Write documentation
 */ // }}}

%include <clxx/common/program_source.swg>
%{
#include <clxx/common/program_sources.hpp>
%}
%template() std::vector<clxx::program_source>;
%include <clxx/common/program_sources.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
