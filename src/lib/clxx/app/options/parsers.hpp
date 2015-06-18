// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/parsers.hpp

/** // doc: clxx/app/options/parsers.hpp {{{
 * \file clxx/app/options/parsers.hpp
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
/** // doc: basic_command_line_parser {{{
 * \todo Write documentation
 */ // }}}
template <typename charT>
  using basic_command_line_parser
    = boost::program_options::basic_command_line_parser<charT>;
/** // doc: collect_unrecognized_mode {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::collect_unrecognized_mode;
/** // doc: parsed_options {{{
 * \brief Results of parsing aninput source
 *
 * From the Boost documentation: the primary use of this class is passing
 * information from parsers component to value storage component. This class
 * does not makes much sense itself.
 */ // }}}
using boost::program_options::parsed_options;
/** // doc: wparsed_options {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::wparsed_options;
/** // doc: ext_parser {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::ext_parser;
/** // doc: command_line_parser {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::command_line_parser;
/** // doc: wcommand_line_parser {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::wcommand_line_parser;
/** // doc: parse_command_line {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::parse_command_line;
} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_PARSERS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
