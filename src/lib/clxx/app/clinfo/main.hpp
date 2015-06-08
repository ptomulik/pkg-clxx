// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/main.hpp

/** // doc: clxx/app/clinfo/main.hpp {{{
 * \file clxx/app/clinfo/main.hpp
 * \brief Defines clxx::app::clinfo::main
 */ // }}}
#ifndef CLXX_APP_CLINFO_MAIN_HPP_INCLUDED
#define CLXX_APP_CLINFO_MAIN_HPP_INCLUDED

#include <clxx/app/main.hpp>
#include <clxx/app/clinfo/options_description.hpp>
#include <clxx/app/options/options_map.hpp>
#include <string>
#include <vector>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class main {{{
 * \brief Implements the clxx-clinfo program
 *
 * This class implements the clxx-clinfo program. Its use is as simple as
 * initializing and calling the run() method, for example:
 *
 * \code
 *  int main(int argc, char* argv[]) {
 *    clxx::app:clinfo::main clinfo(argc, argv[]);
 *    return clinfo.run();
 *  }
 * \endcode
 *
 * You may also wish to catch exception thrown by the implementation. Note,
 * that you may instantiate and run several instances of the application.
 *
 * \see clxx::app::clinfo::run()
 */ // }}}
class main
  : public clxx::app::main
{
public:
  /** // doc: options_map {{{
   * \brief Type used to represent options map for the clxx-clinfo options.
   *
   * For information about option maps see the documentation of
   * <a href="www.boost.org/doc/html/program_options/overview.html">Boost.Program_Options</a>
   */ // }}}
  typedef clxx::app::options::options_map options_map;
public:
  /** // doc: ~main() {{{
   * \brief Destructor
   */ // }}}
  virtual ~main();
  /** // doc: main() {{{
   * \brief Default constructor
   * \todo Write out how does the default-constructed object look like
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
   * \brief Initialize the clxx-clinfo instance
   *
   * The arguments \e argc and \e argv have same meaning as the corresponding
   * arguments to the global main() function.
   *
   * \param argc Number of arguments provided via CLI.
   * \param argv An array of null-terminated string with CLI arguments.
   */ // }}}
  virtual void init(int argc, char const* argv[]) ;
  /** // doc: run() {{{
   * \brief Execute the clxx-clinfo application
   * \returns Program execution status, may be further returned to the
   *    operating system.
   */ // }}}
  virtual int run( ) ;
  /** // doc: get_options_description() {{{
   * \brief Returns the definition of CLI options for the clxx-clinfo program
   */ // }}}
  inline options_description const& get_options_description() const
  {
    return this->_options_description;
  }
  /** // doc: get_options_map() {{{
   * \brief Returns the options map encapsulated within the object
   *
   * For information about option maps see the documentation of
   * <a href="www.boost.org/doc/html/program_options/overview.html">Boost.Program_Options</a>
   */ // }}}
  inline options_map const& get_options_map() const
  {
    return this->_options_map;
  }
private:
  void _init_main( );
private:
  options_description _options_description;
  options_map _options_map;
};

/** // doc: run(argc, argv) {{{
 * \brief Initialize and run the clxx-clinfo program.
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

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_MAIN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
