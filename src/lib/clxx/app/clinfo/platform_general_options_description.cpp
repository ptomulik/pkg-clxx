// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/platform_general_options_description.cpp

/** // doc: clxx/app/clinfo/platform_general_options_description.cpp {{{
 * \file clxx/app/clinfo/platform_general_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/app/clinfo/platform_general_options_description.hpp>
#include <clxx/app/options/option_value.hpp>
#include <vector>
#include <string>

namespace clxx { namespace app { namespace clinfo {

platform_general_options_description::
platform_general_options_description( unsigned line_length
                                    , unsigned min_description_length )
  : clxx::app::options::options_description("Platform General Options"
                                            , line_length
                                            , min_description_length )
{
  this->_init_options_description();
}
platform_general_options_description::
platform_general_options_description( const std::string & caption
                                    , unsigned line_length
                                    , unsigned min_description_length )
  : clxx::app::options::options_description( caption, line_length
                                            , min_description_length )
{
  this->_init_options_description();
}

platform_general_options_description::
~platform_general_options_description()
{
}

void platform_general_options_description::
_init_options_description()
{
  /* typically this will contain something like:
  using clxx::app::options::value;
  this->add_options()
    ("option-name"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for option-name")
  ;
  */
}

} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
