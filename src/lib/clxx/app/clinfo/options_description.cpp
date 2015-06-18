// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/options_description.cpp

/** // doc: clxx/app/clinfo/options_description.cpp {{{
 * \file clxx/app/clinfo/options_description.cpp
 * \brief Implements the \ref clxx::app::clinfo::options_description class
 */ // }}}
#include <clxx/app/clinfo/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {
/* ------------------------------------------------------------------------ */
options_description::
options_description( unsigned line_length, unsigned min_description_length )
  : clxx::app::options::options_description( line_length
                                            , min_description_length)
  , _common_options("Common Options",line_length,min_description_length)
  , _platform_general_options(line_length,min_description_length)
  , _platform_detail_options(line_length,min_description_length)
  , _device_general_options(line_length,min_description_length)
  , _device_detail_options(line_length,min_description_length)
  , _io_options(line_length,min_description_length)
{
  this->_init_options_description();
}
/* ------------------------------------------------------------------------ */
options_description::
options_description( const std::string & caption, unsigned line_length
                   , unsigned min_description_length )
  : clxx::app::options::options_description( caption, line_length
                                   , min_description_length)
  , _common_options(line_length,min_description_length)
  , _platform_general_options(line_length,min_description_length)
  , _platform_detail_options(line_length,min_description_length)
  , _device_general_options(line_length,min_description_length)
  , _device_detail_options(line_length,min_description_length)
  , _io_options(line_length,min_description_length)
{
  this->_init_options_description();
}
/* ------------------------------------------------------------------------ */
options_description::
~options_description()
{
}
/* ------------------------------------------------------------------------ */
void options_description::
_init_options_description()
{
  this->add(this->common_options());
  this->add(this->platform_general_options());
  this->add(this->platform_detail_options());
  this->add(this->device_general_options());
  this->add(this->device_detail_options());
  this->add(this->io_options());
}
/* ------------------------------------------------------------------------ */
} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
