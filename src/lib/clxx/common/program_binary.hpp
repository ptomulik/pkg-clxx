// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/program_binary.hpp

/** // doc: clxx/common/program_binary.hpp {{{
 * \file clxx/common/program_binary.hpp
 * \brief Declares the \ref clxx::program_binary "program_binary" type
 */ // }}}
#ifndef CLXX_COMMON_PROGRAM_BINARY_HPP_INCLUDED
#define CLXX_COMMON_PROGRAM_BINARY_HPP_INCLUDED

#include <vector>

namespace clxx {
/** // doc: program_binary {{{
 * \ingroup clxx_program_objects
 * \brief A type used to represent OpenCL program binary
 */ // }}}
typedef std::vector<unsigned char> program_binary;
} // end namespace clxx

#endif /* CLXX_COMMON_PROGRAM_BINARY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
