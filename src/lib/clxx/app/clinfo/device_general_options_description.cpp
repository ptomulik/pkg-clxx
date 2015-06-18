// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/device_general_options_description.cpp

/** // doc: clxx/app/clinfo/device_general_options_description.cpp {{{
 * \file clxx/app/clinfo/device_general_options_description.cpp
 * \brief Implements \ref clxx::app::clinfo::device_general_options_description
 */ // }}}
#include <clxx/app/clinfo/device_general_options_description.hpp>
#include <clxx/app/options/option_value.hpp>
#include <vector>
#include <string>

namespace clxx { namespace app { namespace clinfo {

device_general_options_description::
device_general_options_description( unsigned line_length
                                  , unsigned min_description_length )
  : clxx::app::options::options_description("Device General Options"
                                            , line_length
                                            , min_description_length)
{
  this->_init_options_description();
}

device_general_options_description::
device_general_options_description( const std::string & caption
                                  , unsigned line_length
                                  , unsigned min_description_length)
  : clxx::app::options::options_description( caption, line_length
                                            , min_description_length)
{
  this->_init_options_description();
}

device_general_options_description::
~device_general_options_description()
{
}

void device_general_options_description::
_init_options_description()
{
#if 0
  using clxx::app::options::value;
  using clxx::app::options::bool_switch;
  using std::vector;
  using std::string;
  // NOTE: for the moment I have no idea of how I could implement this option
  this->add_options()
    ("no-devices,D"
    , bool_switch()->default_value(false)
      /* TRANSLATORS: this is for --no-devices option */
    , "do not list devices")
  ;
#endif
  using clxx::app::options::value;
  this->add_options()
    ("device-info"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for device information")
    ("compute-unit-info"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for compute unit information")
    ("vector-width-info"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for xxx-vector-width-xxx options")
    ("image-support-info"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for information on image support")
    ("global-mem-info"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for global memory information")
    ("device-generic-info"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for generic device info")
  ;
}

} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
