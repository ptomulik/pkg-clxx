// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_generator.hpp

/** // doc: clxx/cl/program_generator.hpp {{{
 * \file clxx/cl/program_generator.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED
#define CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED

#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <string>

namespace clxx {
/** // doc: program_generator {{{
 * \todo Write documentation
 */ // }}}
class program_generator
{
public:
  /** // doc: program_generator() {{{
   * \todo Write documentation
   */ // }}}
  program_generator() = default;
  /** // doc: ~program_generator() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~program_generator();
  /** // doc: generate_program_source(std::string&) {{{
   * \todo Write documentation
   */ // }}}
  virtual void generate_program_source(std::string& str,
                                       clxx::context const& context) const = 0;
  /** // doc: program_name() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string program_name() const = 0;
  /** // doc: program_namespace() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string program_namespace() const;
  /** // doc: program_full_name() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string program_full_name() const;
  /** // doc: program_file_suffix() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string program_file_suffix() const;
  /** // doc: program_file() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string program_file() const;
  /** // doc: program_dir() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string program_dir() const;
  /** // doc: program_path() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string program_path() const;
  /** // doc: line_directive() {{{
   * \todo Write documentation
   */ // }}}
  virtual std::string line_directive(size_t line) const;
  /** // doc: get_program() {{{
   * \todo Write documentation
   */ // }}}
  virtual clxx::program get_program(clxx::context const& context) const;
};
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
