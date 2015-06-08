// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/main.hpp

/** // doc: clxx/app/main.hpp {{{
 * \file clxx/app/main.hpp
 * \brief Defines clxx::app::main
 */ // }}}
#ifndef CLXX_APP_MAIN_HPP_INCLUDED
#define CLXX_APP_MAIN_HPP_INCLUDED

namespace clxx { namespace app {

/** // doc: class main {{{
 * \brief Base class for clxx program implementation classes
 *
 * The methodology for implementing clxx applications is to write one class
 * per application. Any such class should derive from clxx::app::main. The
 * class should implement at least its own methods init() and run().
 */ // }}}
class main
{
public:
  /** // doc: ~main() {{{
   * \brief Destructor
   */ // }}}
  virtual ~main();
  /** // doc: main() {{{
   * \brief Default constructor
   */ // }}}
  main();
  /** // doc: run() {{{
   * \brief Initializes the object
   *
   * This method should be implemented in a derived class.
   */ // }}}
  virtual void init(int argc, char const* argv[]) = 0;
  /** // doc: run() {{{
   * \brief Executes the program implemented by the class
   *
   * This method should be implemented in a derived class.
   */ // }}}
  virtual int run( ) = 0;
};

} } // end namespace clxx::app

#endif /* CLXX_APP_MAIN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
