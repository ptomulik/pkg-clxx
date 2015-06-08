// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/program_binary.hpp

/** // doc: clxx/program_binary.hpp {{{
 * \file clxx/program_binary.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PROGRAM_BINARY_HPP_INCLUDED
#define CLXX_PROGRAM_BINARY_HPP_INCLUDED

#include <vector>

namespace clxx {
/** // doc: program_binary {{{
 * \brief A type used to represent OpenCL program binary
 * \todo Refine documentation (assumed API of the program_binary???, tell
 *       explicitly that it's std::vector<unsigned char>???)
 */ // }}}
typedef std::vector<unsigned char> program_binary;
} // end namespace clxx

#endif /* CLXX_PROGRAM_BINARY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
