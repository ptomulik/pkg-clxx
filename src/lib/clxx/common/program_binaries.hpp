// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/program_binaries.hpp

/** // doc: clxx/common/program_binaries.hpp {{{
 * \file clxx/common/program_binaries.hpp
 * \brief Declares the \ref clxx::program_binaries "program_binaries" type
 */ // }}}
#ifndef CLXX_COMMON_PROGRAM_BINARIES_HPP_INCLUDED
#define CLXX_COMMON_PROGRAM_BINARIES_HPP_INCLUDED

#include <clxx/common/program_binary.hpp>
#include <vector>

namespace clxx {
/** // doc: program_binaries {{{
 * \ingroup clxx_program_objects
 * \brief A type used to represent multiple OpenCL program binaries
 * \sa \ref clxx::program_binary "program_binary".
 */ // }}}
typedef std::vector<program_binary> program_binaries;
} // end namespace clxx

#endif /* CLXX_COMMON_PROGRAM_BINARIES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
