// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/io_options_description.cpp

/** // doc: clxx/app/clinfo/io_options_description.cpp {{{
 * \file clxx/app/clinfo/io_options_description.cpp
 * \brief Implements \ref clxx::app::clinfo::io_options_description
 */ // }}}
#include <clxx/app/clinfo/io_options_description.hpp>
#include <clxx/app/options/option_value.hpp>
#include <vector>
#include <string>

namespace clxx { namespace app { namespace clinfo {

/* ------------------------------------------------------------------------ */
io_options_description::
io_options_description( unsigned line_length
                      , unsigned min_description_length )
  : clxx::app::options::options_description("Output Options", line_length
                                            , min_description_length )
{
  this->_init_options_description();
}
/* ------------------------------------------------------------------------ */
io_options_description::
io_options_description( const std::string & caption
                      , unsigned line_length
                      , unsigned min_description_length )
  : clxx::app::options::options_description( caption, line_length
                                            , min_description_length )
{
  this->_init_options_description();
}
/* ------------------------------------------------------------------------ */
io_options_description::
~io_options_description()
{
}
/* ------------------------------------------------------------------------ */
void io_options_description::
_init_options_description()
{
  using std::vector;
  using std::string;
  using clxx::app::options::value;
  this->add_options()
    ("output-format,O", value<string>()->value_name("fmt"),
      "output format (uff/xml/txt/bin)")
    ("input-format,I", value<string>()->value_name("fmt")->default_value("xml"),
      "input format (xml/text/bin), relevant only with --input")
    ("input,i", value<string>()->value_name("file"),
      "read previously saved data from file, see also --input-format")
    ("output,o", value<string>()->value_name("file"),
      "save the output to file instead of stdout, see also --output-format")
  ;
}
/* ------------------------------------------------------------------------ */

} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
