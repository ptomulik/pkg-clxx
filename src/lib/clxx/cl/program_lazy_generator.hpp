// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_lazy_generator.hpp

/** // doc: clxx/cl/program_lazy_generator.hpp {{{
 * \file clxx/cl/program_lazy_generator.hpp
 * \brief Provides the \ref clxx::program_lazy_generator "program_lazy_generator"
 */ // }}}
#ifndef CLXX_CL_PROGRAM_LAZY_GENERATOR_HPP_INCLUDED
#define CLXX_CL_PROGRAM_LAZY_GENERATOR_HPP_INCLUDED

#include <clxx/cl/program_generator.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/common/memoized_function.hpp>

namespace clxx {
/** // doc: program_lazy_generator {{{
 * \brief Abstract base class for lazy program generators
 *
 * Lazy program generator creates its \ref clxx::program "program" object
 * only once for a given \c context. Each subsequent call to #get_program()
 * with the same \c context returns memoized \ref clxx::program "program"
 * object. #discard_memoized_program() and #discard_memoized_programs() can be
 * used to forget the memoized object, such that next call to #get_program()
 * will create new \ref clxx::program "program" from scratch.
 */ // }}}
class program_lazy_generator
  : public program_generator
{
private:
  typedef clxx::memoized_function<clxx::program(clxx::context const&)> lazy_get_program_t;
  lazy_get_program_t _lazy_get_program;
public:
  using program_generator::program_generator;
  /** // doc: program_lazy_generator() {{{
   * \brief Default constructor
   */ // }}}
  program_lazy_generator();
  /** // doc: get_program() {{{
   * \brief Return the generated program
   *
   * When invoked for the first time, the method calls the
   * \ref clxx::program_generator::get_program(), memoizes the created 
   * \ref clxx::program "program" and returns it. Each subsequent invocation
   * with same \p context returns the memoized program, until it is discarded
   * with #discard_memoized_program() or #discard_memoized_programs().
   *
   * \param context
   *    A valid \ref clxx::context "context" object for which the program
   *    is to be created.
   */ // }}}
  virtual clxx::program get_program(clxx::context const& context) const;
  /** // doc: get_memoized_program() {{{
   * \brief Returns cached program
   *
   * If the program for the given \p context is not found in cache, the method
   * throws \ref clxx::invalid_key_error.
   *
   * \param context
   *    A \ref clxx::context "context" object for which the program was
   *    memoized.
   *
   * \throw clxx::invalid_key_error
   *    If there is no memoized result for the given \p context
   */ // }}}
  clxx::program get_memoized_program(clxx::context const& context) const;
  /** // doc: discard_memoized_program() {{{
   * \brief Discards \ref clxx::program "program" cached for \p context
   *
   * \param context
   *    A \ref clxx::context "context" object for which the program was
   *    memoized.
   *
   * \returns
   *    Number of entries discarded from the internal cache. It may be either 0
   *    or 1.
   */ // }}}
  size_t discard_memoized_program(clxx::context const& context) const;
  /** // doc: discard_memoized_programs() {{{
   * \brief Discards all the cached \ref clxx::program "programs"
   */ // }}}
  void discard_memoized_programs() const;
};
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_LAZY_GENERATOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
