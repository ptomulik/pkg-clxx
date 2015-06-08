// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/common_options_description.cpp

/** // doc: clxx/app/clinfo/common_options_description.cpp {{{
 * \file clxx/app/clinfo/common_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/app/clinfo/common_options_description.hpp>
#include <clxx/app/options/option_value.hpp>
#include <vector>
#include <string>

namespace clxx { namespace app { namespace clinfo {
/* ----------------------------------------------------------------------- */
common_options_description::
~common_options_description()
{
}
/* ----------------------------------------------------------------------- */
common_options_description::
common_options_description( unsigned line_length
                          , unsigned min_description_length )
  : clxx::app::common_options_description(line_length, min_description_length)
{
  this->_init_options_description();
}
/* ----------------------------------------------------------------------- */
common_options_description::
common_options_description( const std::string & caption, unsigned line_length
                   , unsigned min_description_length )
  : clxx::app::common_options_description( caption, line_length
                                          , min_description_length)
{
  this->_init_options_description();
}
/* ----------------------------------------------------------------------- */
void common_options_description::
_init_options_description()
{
  using std::vector;
  using std::string;
  using clxx::app::options::value;
  using clxx::app::options::bool_switch;
  this->add_options()
    ("help-detail", "display detailed options")
    ("help-platform", "display detailed platform options")
    ("help-device", "display detailed device options")
    ("config,c", value<string>()->value_name("file"),
      "read options from `file' (not implemented yet)")
    ("indent", value<int>()->value_name("num")->default_value(2),
      "indent each level of output by `num' spaces")
    ("short,s", bool_switch()->default_value(false),
      "short listing (no details)")
  ;
}
/* ----------------------------------------------------------------------- */
} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:

