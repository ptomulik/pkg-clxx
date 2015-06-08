// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/app/clcc/options.cpp {{{
 * \file clxx/app/clcc/options.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/app/clcc/options.hpp>
#include <clxx/app/options/rethrow.hpp>
#include <vector>
#include <string>

namespace clxx { namespace app { namespace clcc {
/* ------------------------------------------------------------------------ */
static const char* _default_output_file = "cl.out";
/* ------------------------------------------------------------------------ */
static device_type_t
_parse_device_type(std::string const& type)
{
  using clxx::app::options::invalid_option_value_error;
  using boost::program_options::invalid_option_value;
  if(type == "ACCELERATOR")
    return device_type_t::accelerator;
  else if(type == "GPU")
    return device_type_t::gpu;
  else if(type == "CPU")
    return device_type_t::cpu;
  else if(type == "ALL")
    return device_type_t::all;
  else
    throw invalid_option_value_error(invalid_option_value("device_type"));
}
/* ------------------------------------------------------------------------ */
options::
options(int argc, char const* argv[])
 : _map(),
   _visible_options_description("Allowed Options"),
   _hidden_options_description("Hidden Options"),
   _help(false),
   _version(false),
   _info(false),
   _build(false),
   _short_info(false),
   _device_type(device_type_t::all),
   _cloptions(),
   _platform_filter(),
   _device_filter(),
   _output_file(),
   _platform_index(-1),
   _device_index(-1)
{
  this->_init(argc, argv);
}
/* ------------------------------------------------------------------------ */
options::
~options()
{
}
/* ------------------------------------------------------------------------ */
void options::
_init_visible_options()
{
  using std::string;
  using std::vector;
  using clxx::app::options::value;

  _visible_options_description.add_options()

  ("help,h",
   "print help")

  ("version,v",
   "print program version")

  ("info,i",
   "display OpenCL platforms and devices")

  ("short_info",
   "same as --info but less verbose")

  ("cloptions",
   value<string>(&_cloptions)->value_name("opts")->default_value(_cloptions),
   "options to pass to the OpenCL compiler")

  ("output_file,o",
   value<string>(&_output_file)->value_name("file")->default_value(_default_output_file),
   "output file name")

  ("platform_filter",
   value<string>(&_platform_filter)->value_name("name"),
   "case-insensitive platform name filter")

  ("device_filter",
   value<string>(&_device_filter)->value_name("name"),
   "case-insensitive device name filter")

  ("device_type",
   value<string>()->value_name("type")->default_value("ALL"),
   "specify which device type to compile for (CPU, GPU, ACCELERATOR, ALL)")

  ("platform_index,p",
   value<int>(&_platform_index)->value_name("i"),
   "zero-based index of device to compile for")

  ("device_index,d",
   value<int>(&_device_index)->value_name("j"),
   "zero-based index of device to compile for")
  ;
}
/* ------------------------------------------------------------------------ */
void options::
_init_hidden_options()
{
  using std::string;
  using std::vector;
  using clxx::app::options::value;

  _hidden_options_description.add_options()
  ("input_file",
   value< vector<string> >()->value_name("file"),
   "input file(s)")
  ;
}
/* ------------------------------------------------------------------------ */
void options::
_init(int argc, const char* argv[])
{
  using clxx::app::options::positional_options_description;
  using clxx::app::options::command_line_parser;
  using clxx::app::options::store;
  using clxx::app::options::notify;

  _init_visible_options();
  _init_hidden_options();

  options_description all;
  all.add(_visible_options_description).add(_hidden_options_description);

  // Set "input_file" option as positional
  positional_options_description po;
  po.add("input_file", -1);

  try {
    store(command_line_parser(argc, argv).options(all).positional(po).run(), _map);
  } CLXX_APP_OPTIONS_RETHROW_ALL()

  notify(_map);

  _help = (_map.count("help") != 0);
  _version = (_map.count("version") != 0);
  _info = (_map.count("info") != 0);
  _short_info = (_map.count("short_info") != 0);
  _build = (_map.count("input_file") != 0);

  if(_map.count("device_type"))
    _device_type = _parse_device_type(_map["device_type"].as<std::string>());
}
/* ------------------------------------------------------------------------ */
} } } // end namespace clxx::app::clcc

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
