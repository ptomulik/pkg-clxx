// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clcc/options.hpp

/** // doc: clxx/app/clcc/options.hpp {{{
 * \file clxx/app/clcc/options.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_CLCC_OPTIONS_HPP_INCLUDED
#define CLXX_APP_CLCC_OPTIONS_HPP_INCLUDED

#include <boost/noncopyable.hpp>
#include <clxx/app/options.hpp>
#include <clxx/types.hpp>

namespace clxx { namespace app { namespace clcc {

class options : boost::noncopyable
{
  typedef clxx::app::options::options_map options_map;
  typedef clxx::app::options::options_description options_description;
public:
  /** // doc: options(argc, argv[]) {{{
   * \todo Write documentation
   */ // }}}
  options(int argc, char const* argv[]);
  /** // doc: ~options() {{{
   * \todo Write documentation
   */ // }}}
  ~options();
  /** // doc: visible_options_description() {{{
   * \todo Write documentation
   */ // }}}
  options_map const& map() const noexcept
  { return this->_map; }
  /** // doc: visible_options_description() {{{
   * \todo Write documentation
   */ // }}}
  options_description const& visible_options_description() const noexcept
  { return this->_visible_options_description; }
  /** // doc: hidden_options_description() {{{
   * \todo Write documentation
   */ // }}}
  options_description const& hidden_options_description() const noexcept
  { return this->_hidden_options_description; }
  /** // doc: help() {{{
   * \todo Write documentation
   */ // }}}
  bool help() const noexcept
  { return this->_help; }
  /** // doc: version() {{{
   * \todo Write documentation
   */ // }}}
  bool version() const noexcept
  { return this->_version; }
  /** // doc: info() {{{
   * \todo Write documentation
   */ // }}}
  bool info() const noexcept
  { return this->_info; }
  /** // doc: build() {{{
   * \todo Write documentation
   */ // }}}
  bool build() const noexcept
  { return this->_build; }
  /** // doc: short_info() {{{
   * \todo Write documentation
   */ // }}}
  bool short_info() const noexcept
  { return this->_short_info; }
  /** // doc: device_type() {{{
   * \todo Write documentation
   */ // }}}
  device_type_t device_type() const noexcept
  { return this->_device_type; }
  /** // doc: cloptions() {{{
   * \todo Write documentation
   */ // }}}
  std::string const& cloptions() const noexcept
  { return this->_cloptions; }
  /** // doc: platform_filter() {{{
   * \todo Write documentation
   */ // }}}
  std::string const& platform_filter() const noexcept
  { return this->_platform_filter; }
  /** // doc: device_filter() {{{
   * \todo Write documentation
   */ // }}}
  std::string const& device_filter() const noexcept
  { return this->_device_filter; }
  /** // doc: output_file() {{{
   * \todo Write documentation
   */ // }}}
  std::string const& output_file() const noexcept
  { return this->_output_file; }
  /** // doc: platform_index() {{{
   * \todo Write documentation
   */ // }}}
  int platform_index() const noexcept
  { return this->_platform_index; }
  /** // doc: device_index() {{{
   * \todo Write documentation
   */ // }}}
  int device_index() const noexcept
  { return this->_device_index; }
  /** // doc: has_input_files() {{{
   * \todo Write documentation
   */ // }}}
  bool has_input_files() const noexcept
  { return this->_map.count("input_file"); }
  /** // doc: input_files() {{{
   * \todo Write documentation
   */ // }}}
  std::vector<std::string> const& input_files() const noexcept
  { return this->_map["input_file"].as< std::vector<std::string> >(); }

private:
  void _init(int argc, char const* argv[]);
  void _init_visible_options();
  void _init_hidden_options();

  options_map         _map;
  options_description _visible_options_description;
  options_description _hidden_options_description;

  bool            _help;
  bool            _version;
  bool            _info;
  bool            _build;
  bool            _short_info;
  device_type_t   _device_type;
  std::string     _cloptions;
  std::string     _platform_filter;
  std::string     _device_filter;
  std::string     _output_file;
  int             _platform_index;
  int             _device_index;
};

} } } // end namespace clxx::app::clcc

#endif /* CLXX_APP_CLCC_OPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
