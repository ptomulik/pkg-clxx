// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/unit.hpp

/** // doc: clxx/unit.hpp {{{
 * \file clxx/unit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_PARSERS_HPP_INCLUDED
#define CLXX_APP_OPTIONS_PARSERS_HPP_INCLUDED

#include <boost/program_options/parsers.hpp>

namespace clxx { namespace app { namespace options {
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
template <typename charT>
  using basic_parsed_options
    = boost::program_options::basic_parsed_options<charT>;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
template <typename charT>
  using basic_command_line_parser
    = boost::program_options::basic_command_line_parser<charT>;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::collect_unrecognized_mode;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::parsed_options;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::wparsed_options;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::ext_parser;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::command_line_parser;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::wcommand_line_parser;
/** // doc: basic_parsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::parse_command_line;
} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_PARSERS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
