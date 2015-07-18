// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_observer.cpp {{{
 * \file clxx/cl/program_observer.cpp
 * \brief Implements the base class \ref clxx::program_observer "program_observer"
 */ // }}}
#include <clxx/cl/program_observer.hpp>
#include <clxx/cl/program.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
void CL_CALLBACK program_observer::
static_notify(cl_program prog, void* ptr)
{ static_cast<program_observer*>(ptr)->notify(program(prog)); }
/* ----------------------------------------------------------------------- */
program_observer::fcn_ptr_t program_observer::
fcn_ptr() const noexcept
{ return static_notify; }
/* ----------------------------------------------------------------------- */
void* program_observer::
fcn_arg() noexcept
{ return static_cast<void*>(this); }
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
