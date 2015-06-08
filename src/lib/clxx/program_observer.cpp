// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/program_observer.cpp {{{
 * \file clxx/program_observer.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/program_observer.hpp>
#include <clxx/program.hpp>

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
