// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clcc/main.hpp

/** // doc: clxx/app/clcc/main.hpp {{{
 * \file clxx/app/clcc/main.hpp
 * \brief Defines clxx::app::clcc::main
 */ // }}}
#ifndef CLXX_APP_CLCC_MAIN_HPP_INCLUDED
#define CLXX_APP_CLCC_MAIN_HPP_INCLUDED

#include <clxx/app/main.hpp>
#include <clxx/app/clcc/options.hpp>
#include <clxx/cl/platform_layer.hpp>
#include <clxx/cl/context.hpp>
#include <string>
#include <vector>

namespace clxx { namespace app { namespace clcc {

/** // doc: class main {{{
 * \brief Implements the clxx-clcc program
 *
 * This class implements the clxx-clcc application. Its use is as simple as
 * initializing and calling the run() method, for example:
 *
 * \code
 *  int main(int argc, char* argv[]) {
 *    clxx::app:clcc::main clcc(argc, argv[]);
 *    return clcc.run();
 *  }
 * \endcode
 *
 * You may also wish to catch exception thrown by the implementation. Note,
 * that you may instantiate and run several instances of the application.
 *
 * \see clxx::app::clcc::run()
 */ // }}}
class main
  : public clxx::app::main
{
public:
  /** // doc: options_map {{{
   * \brief Type used to represent options map for the clxx-clcc options.
   *
   * For information about option maps see the documentation of
   * <a href="www.boost.org/doc/html/program_options/overview.html">Boost.Program_Options</a>
   */ // }}}
  typedef clxx::app::options::options_map options_map;
  /** // doc: positional_options_description {{{
   * \brief Type used to represent positional options (free CLI arguments).
   */ // }}}
  typedef clxx::app::options::positional_options_description positional_options_description;
  /** // doc: parsed_options {{{
   * \brief Type representing results of parsing an input source.
   */ // }}}
  typedef clxx::app::options::parsed_options parsed_options;
public:
  /** // doc: ~main() {{{
   * \brief Destructor
   */ // }}}
  virtual ~main();
  /** // doc: main() {{{
   * \brief Default constructor
   *
   * The default constructor initializes application without any command-line
   * arguments.
   */ // }}}
  main();
  /** // doc: main(argc, argv) {{{
   * \brief Constructor
   *
   * The arguments \e argc and \e argv have same meaning as the corresponding
   * arguments to the global main() function.
   *
   * \param argc Number of arguments provided via CLI.
   * \param argv An array of null-terminated string with CLI arguments.
   */ // }}}
  main(int argc, char const* argv[]);
  /** // doc: init(argc, argv) {{{
   * \brief Initialize the clxx-clcc instance
   *
   * The arguments \e argc and \e argv have same meaning as the corresponding
   * arguments to the global main() function.
   *
   * \param argc Number of arguments provided via CLI.
   * \param argv An array of null-terminated string with CLI arguments.
   */ // }}}
  virtual void init(int argc, char const* argv[]) ;
  /** // doc: run() {{{
   * \brief Execute the clxx-clcc application
   * \returns Program execution status, may be further returned to the
   *    operating system.
   */ // }}}
  virtual int run( ) ;
  /** // doc: get_options() {{{
   * \brief Returns the definition of CLI options for the clxx-clcc program
   */ // }}}
  clxx::app::clcc::options const& options() const noexcept
  { return this->_options; }
private:
  int             _execute_build();
  int             _execute_info();
  int             _execute_help();
  int             _execute_version();

  platform_layer  _make_platform_layer() const;
  contexts        _make_contexts(platform_layer const& pl) const;
  bool            _match(platform const& p) const;
  bool            _match(device const& d) const;
  platforms       _filter(platforms const& ds) const;
  devices         _filter(devices const& ds) const;

  clxx::app::clcc::options _options;
};

/** // doc: run(argc, argv) {{{
 * \brief Initialize and run the clxx-clcc program.
 *
 * This function is thought to be used from the global main() function. The
 * \e argc and \e argv arguments are same as for the global main(). The
 * returned value may be further returned by the global main() to the operating
 * system.
 *
 * \param argc Number of arguments passed via CLI
 * \param argv Array of null-terminated strings that contain CLI arguments
 *
 * \returns Status code to be returned to the caller.
 */ // }}}
int run(int argc, char const* argv[]);

} } } // end namespace clxx::app::clcc

#endif /* CLXX_APP_CLCC_MAIN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
