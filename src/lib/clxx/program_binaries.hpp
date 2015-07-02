// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/program_binaries.hpp

/** // doc: clxx/program_binaries.hpp {{{
 * \file clxx/program_binaries.hpp
 * \brief Declares the \ref clxx::program_binaries "program_binaries" type
 */ // }}}
#ifndef CLXX_PROGRAM_BINARIES_HPP_INCLUDED
#define CLXX_PROGRAM_BINARIES_HPP_INCLUDED

#include <clxx/program_binary.hpp>
#include <vector>

namespace clxx {
/** // doc: program_binaries {{{
 * \ingroup clxx_program_objects
 * \brief A type used to represent multiple OpenCL program binaries
 * \sa \ref clxx::program_binary "program_binary".
 */ // }}}
typedef std::vector<program_binary> program_binaries;
} // end namespace clxx

#endif /* CLXX_PROGRAM_BINARIES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
