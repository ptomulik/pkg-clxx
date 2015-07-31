// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_lazy_generator.cpp {{{
 * \file clxx/cl/program_lazy_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_lazy_generator.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
program_lazy_generator::
program_lazy_generator()
  : program_generator(),
   _lazy_get_program(
       [this](clxx::context const& context) -> clxx::program {
          return this->program_generator::get_program(context);
       }
   )
{ }
/* ----------------------------------------------------------------------- */
clxx::program program_lazy_generator::
get_program(clxx::context const& context) const
{ return _lazy_get_program(context); }
/* ----------------------------------------------------------------------- */
clxx::program program_lazy_generator::
get_memoized_program(clxx::context const& context) const
{ return _lazy_get_program.get_memoized_result(context); }
/* ----------------------------------------------------------------------- */
size_t program_lazy_generator::
discard_memoized_program(clxx::context const& context) const
{ return _lazy_get_program.discard_memoized_result(context); }
/* ----------------------------------------------------------------------- */
void program_lazy_generator::
discard_memoized_programs() const
{ _lazy_get_program.discard_memoized_results(); }
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
