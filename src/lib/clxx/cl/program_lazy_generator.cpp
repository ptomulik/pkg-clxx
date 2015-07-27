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
       make_memoized_function(
         &clxx::program_generator::get_program, 
         static_cast<program_generator const*>(this)
       )
   )
{ }
/* ----------------------------------------------------------------------- */
clxx::program program_lazy_generator::
get_program(clxx::context const& context) const
{ return _lazy_get_program(context); }
/* ----------------------------------------------------------------------- */
clxx::program program_lazy_generator::
get_cached_program(clxx::context const& context) const
{ return _lazy_get_program.get_cached_result(context); }
/* ----------------------------------------------------------------------- */
size_t program_lazy_generator::
discard_cached_program(clxx::context const& context) const
{ return _lazy_get_program.discard_cached_result(context); }
/* ----------------------------------------------------------------------- */
void program_lazy_generator::
discard_cached_programs() const
{ _lazy_get_program.discard_cached_results(); }
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
