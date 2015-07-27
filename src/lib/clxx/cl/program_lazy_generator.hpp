// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_lazy_generator.hpp

/** // doc: clxx/cl/program_lazy_generator.hpp {{{
 * \file clxx/cl/program_lazy_generator.hpp
 * \todo Write documentation
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
 * Lazy program generators generates the source only once. Each subsequent call
 * to #get_program() returns memoized \ref clxx::program "program" object
 * until the result is discarded from cache by user (see
 * #discard_cached_program() and #discard_cached_programs()).
 */ // }}}
class program_lazy_generator
  : public program_generator
{
private:
  typedef clxx::memoized_function<clxx::program(clxx::context const&)> lazy_get_program_t;
  lazy_get_program_t _lazy_get_program;
public:
  /** // doc: program_lazy_generator() {{{
   * \brief Default constructor
   */ // }}}
  program_lazy_generator();
  /** // doc: get_program() {{{
   * \brief Return the generated program
   *
   * When invoked for the first time, the method calls the
   * \ref clxx::program_generator::get_program(), caches the created 
   * \ref clxx::program "program" and returns it. Each subsequent invocation
   * returns the cached program, unless someone discards the cached program
   * with #discard_cached_program() or #discard_cached_programs().
   */ // }}}
  virtual clxx::program get_program(clxx::context const& context) const;
  /** // doc: get_cached_program() {{{
   * \brief Returns cached program
   *
   * If the program for the given \p context is not found in cache, the method
   * throws \ref clxx::invalid_key_error.
   */ // }}}
  clxx::program get_cached_program(clxx::context const& context) const;
  /** // doc: discard_cached_program() {{{
   * \brief Discards \ref clxx::program "program" cached for \p context
   */ // }}}
  size_t discard_cached_program(clxx::context const& context) const;
  /** // doc: discard_cached_programs() {{{
   * \brief Discards all the cached \ref clxx::program "programs"
   */ // }}}
  void discard_cached_programs() const;
};
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_LAZY_GENERATOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
