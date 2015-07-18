// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/program_sources.hpp

/** // doc: clxx/common/program_sources.hpp {{{
 * \file clxx/common/program_sources.hpp
 * \brief Defines the \ref clxx::program_sources "program_sources" type
 */ // }}}
#ifndef CLXX_COMMON_PROGRAM_SOURCES_HPP_INCLUDED
#define CLXX_COMMON_PROGRAM_SOURCES_HPP_INCLUDED

#include <clxx/common/program_source.hpp>
#include <vector>

namespace clxx {
/** // doc: program_sources {{{
 * \ingroup clxx_program_objects
 * \brief A type used to represent multiple OpenCL program sources
 * \sa \ref clxx::program_source "program_source"
 */ // }}}
typedef std::vector<program_source> program_sources;
} // end namespace clxx

#endif /* CLXX_COMMON_PROGRAM_SOURCES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
