// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/options_description.cpp

/** // doc: clxx/app/options/options_description.cpp {{{
 * \file  clxx/app/options/options_description.cpp
 * \brief Implements the \ref clxx::app::options::options_description class
 */ // }}}
#include <clxx/app/options/options_description.hpp>

namespace clxx{ namespace app { namespace options {
/* ------------------------------------------------------------------------ */
options_description::
~options_description()
{
}
/* ------------------------------------------------------------------------ */
options_description::
options_description( unsigned line_length, unsigned min_description_length )
  : boost::program_options::options_description( line_length
                                               , min_description_length)
{
}
/* ------------------------------------------------------------------------ */
options_description::
options_description( const std::string & caption, unsigned line_length
                   , unsigned min_description_length )
  : boost::program_options::options_description( caption, line_length
                                               , min_description_length)
{
}
/* ------------------------------------------------------------------------ */
} } } // end namespace clxx::app::options

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
