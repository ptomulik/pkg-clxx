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
#include <map>
#include <mutex>

namespace clxx {
/** // doc: program_lazy_generator {{{
 * \todo Write documentation
 */ // }}}
class program_lazy_generator
  : public program_generator
{
private:
  mutable std::map<clxx::context, clxx::program> _programs;
  mutable std::mutex _programs_mutex;
public:
  /** // doc: get_program() {{{
   * \todo Write documentation
   */ // }}}
  virtual clxx::program get_program(clxx::context const& context) const;
  /** // doc: forget_memoized_program() {{{
   * \todo Write documentation
   */ // }}}
  virtual size_t forget_memoized_program(clxx::context const& context) const;
  /** // doc: forget_memoized_programs() {{{
   * \todo Write documentation
   */ // }}}
  virtual void forget_memoized_programs() const;
};
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_LAZY_GENERATOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
