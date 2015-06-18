// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/common_options_description.cpp

/** // doc: clxx/app/common_options_description.cpp {{{
 * \file clxx/app/common_options_description.cpp
 * \brief Implements the \ref clxx::app::common_options_description class
 */ // }}}
#include <clxx/app/common_options_description.hpp>

namespace clxx { namespace app {
/* ------------------------------------------------------------------------ */
common_options_description::
~common_options_description()
{
}
/* ------------------------------------------------------------------------ */
common_options_description::
common_options_description( unsigned line_length
                          , unsigned min_description_length )
  : options::options_description(line_length, min_description_length)
{
  this->_init_options_description();
}
/* ------------------------------------------------------------------------ */
common_options_description::
common_options_description( const std::string & caption, unsigned line_length
                   , unsigned min_description_length )
  : options::options_description(caption, line_length, min_description_length)
{
  this->_init_options_description();
}
/* ------------------------------------------------------------------------ */
void common_options_description::
_init_options_description()
{
  this->add_options()
    ("help,h","print help")
    ("version,v","print program version")
  ;
}
/* ------------------------------------------------------------------------ */
} } // end namespace clxx::app

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
