// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/rethrow.hpp

/** // doc: clxx/app/options/rethrow.hpp {{{
 * \file clxx/app/options/rethrow.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_RETHROW_HPP_INCLUDED
#define CLXX_APP_OPTIONS_RETHROW_HPP_INCLUDED

#include <clxx/app/options/exceptions.hpp>

/** // doc: CLXX_APP_OPTIONS_RETHROW {{{
 * \todo Write documentation
 */ // }}}
#define CLXX_APP_OPTIONS_RETHROW(__ex,__as) \
  catch(boost::program_options::__ex const& e) { \
    throw clxx::app::options::__as(e); \
  }

/** // doc: CLXX_APP_OPTIONS_RETHROW_ALL {{{
 * \todo Write documentation
 */ // }}}
#define CLXX_APP_OPTIONS_RETHROW_ALL() \
  CLXX_APP_OPTIONS_RETHROW(too_many_positional_options_error, too_many_positional_options_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_command_line_style, invalid_command_line_style_error) \
  CLXX_APP_OPTIONS_RETHROW(reading_file, reading_options_file_error) \
  CLXX_APP_OPTIONS_RETHROW(multiple_values, multiple_option_values_error) \
  CLXX_APP_OPTIONS_RETHROW(multiple_occurrences, multiple_option_occurrences_error) \
  CLXX_APP_OPTIONS_RETHROW(required_option, required_option_error) \
  CLXX_APP_OPTIONS_RETHROW(unknown_option, unknown_option_error) \
  CLXX_APP_OPTIONS_RETHROW(ambiguous_option, ambiguous_option_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_config_file_syntax, invalid_config_file_syntax_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_command_line_syntax, invalid_command_line_syntax_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_option_value, invalid_option_value_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_bool_value, invalid_bool_option_value_error)

#endif /* CLXX_APP_OPTIONS_RETHROW_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
