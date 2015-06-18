// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clcc/options.hpp

/** // doc: clxx/app/clcc/options.hpp {{{
 * \file clxx/app/clcc/options.hpp
 * \brief Defines \ref clxx::app::clcc::options class.
 */ // }}}
#ifndef CLXX_APP_CLCC_OPTIONS_HPP_INCLUDED
#define CLXX_APP_CLCC_OPTIONS_HPP_INCLUDED

#include <boost/noncopyable.hpp>
#include <clxx/app/options.hpp>
#include <clxx/types.hpp>

namespace clxx { namespace app { namespace clcc {

/** // doc: options {{{
 * \brief Options for clxx-clcc aplication
 *
 * This class encapsulates command line options for the *clxx-clcc* (OpenCL
 * compiler) application.
 */ // }}}
class options : boost::noncopyable
{
  typedef clxx::app::options::options_map options_map;
  typedef clxx::app::options::options_description options_description;
public:
  /** // doc: options(argc, argv[]) {{{
   * \brief Constructor
   *
   * Initializes internal data of the \ref options object and parses options
   * passed  in (*argc*,*argv*) pair and stores result in the object.
   *
   * \param argc
   *    this argument has same meaning, as the corresponding *argc* argument in
   *    the global \c main() function - it passes number of command line
   *    parameters passed to the application (including the application name).
   * \param argv
   *    this argument has same meaning, as the corresponding *argv* argument in
   *    the global \c main() function; argv is a pointer to array of C strings
   *    containing command-line arguments passed to the application.
   */ // }}}
  options(int argc, char const* argv[]);
  /** // doc: ~options() {{{
   * \brief Destructor
   */ // }}}
  ~options();
  /** // doc: visible_options_description() {{{
   * \brief Return map of options
   *
   * \returns map of options representing options and their values produced
   *          by command-line parser
   */ // }}}
  options_map const& map() const noexcept
  { return this->_map; }
  /** // doc: visible_options_description() {{{
   * \brief Returns description of application's visible options
   */ // }}}
  options_description const& visible_options_description() const noexcept
  { return this->_visible_options_description; }
  /** // doc: hidden_options_description() {{{
   * \brief Returns description of application's hidden options
   */ // }}}
  options_description const& hidden_options_description() const noexcept
  { return this->_hidden_options_description; }
  /** // doc: help() {{{
   * \brief Check if \em --help option is active
   *
   * \returns \c true if \em --help option was provided via **argv**, or
   *    \c false otherwise.
   */ // }}}
  bool help() const noexcept
  { return this->_help; }
  /** // doc: version() {{{
   * \brief Check if \em --version option is active
   *
   * \returns \c true if \em --version option was provided via **argv**,
   *    or \c false otherwise.
   */ // }}}
  bool version() const noexcept
  { return this->_version; }
  /** // doc: info() {{{
   * \brief Check if \em --info option is active
   *
   * \returns \c true if \em --info option was provided via **argv**,
   *    or \c false otherwise.
   */ // }}}
  bool info() const noexcept
  { return this->_info; }
  /** // doc: build() {{{
   * \brief Check if the application is supposed to build a program
   *
   * \returns \c true if conditions allow for program to be built (currently
   *    it's required that number of input files is non-zero).
   */ // }}}
  bool build() const noexcept
  { return this->_build; }
  /** // doc: short_info() {{{
   * \brief Check if \em --short_info option is active
   *
   * \returns \c true if \em --short_info option was provided via **argv**,
   *    or \c false otherwise.
   */ // }}}
  bool short_info() const noexcept
  { return this->_short_info; }
  /** // doc: device_type() {{{
   * \brief Returns value of \em --device_type option
   *
   * \returns value of \em --device_type option converted to
   *    \ref clxx::device_type_t "device_type_t" enum; by default
   *    (in the absence of \em --device_type) \ref clxx::device_type_t::all
   *    "device_type_t::all" is returned.
   */ // }}}
  device_type_t device_type() const noexcept
  { return this->_device_type; }
  /** // doc: cloptions() {{{
   * \brief Returns compiler options passed via \em --cloptions option
   *
   * \returns a string of OpenCL compiler options provided through
   *    \em --cloptions, by default (in the absence of \em --cloptions) an
   *    empty string is returned.
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
   * \brief Returns the value of \em --output_file option
   *
   * \returns the value of \em --output_file
   */ // }}}
  std::string const& output_file() const noexcept
  { return this->_output_file; }
  /** // doc: platform_index() {{{
   * \brief Returns the value of \em --platform_index option
   *
   * \returns the value of \em --platform_index option converted to \c int;
   *    by default (in the absence of \em --platform_index) a value of \c -1
   *    is returned.
   */ // }}}
  int platform_index() const noexcept
  { return this->_platform_index; }
  /** // doc: device_index() {{{
   * \brief Returns the value of \em --device_index option
   *
   * \returns the value of \em --device_index option converted to \c int;
   *    by default (in the absence of \em --device_index) a value of \c -1
   *    is returned.
   */ // }}}
  int device_index() const noexcept
  { return this->_device_index; }
  /** // doc: has_input_files() {{{
   * \brief Check, whether input files were provided
   *
   * \returns \c true if at least one input file was specified via command-line
   *    or \c false otherwise.
   */ // }}}
  bool has_input_files() const noexcept
  { return this->_map.count("input_file"); }
  /** // doc: input_files() {{{
   * \brief Returns names of input files specified in commandline
   *
   * \returns a vector of strings containing names of input files specified
   *    in the command-line.
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
