// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions.t.h

/** // doc: clxx/app/options/exceptions.t.h {{{
 * \file clxx/app/options/exceptions.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_T_H_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/app/options/exceptions.hpp>
#include <clxx/app/options/rethrow.hpp>

namespace clxx { namespace app { namespace options { class exceptions_test_suite; } } }

/** // doc: class clxx::App::Options::Exceptions_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class clxx::app::options::exceptions_test_suite : public CxxTest::TestSuite
{
protected:
  void rethrow_ambiguous_option()
  {
    char const* tmp[] = { "-a", "-b", "-c" };
    std::vector<std::string> xalternatives(tmp,tmp+3);
    try { throw boost::program_options::ambiguous_option(xalternatives); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_bool_value()
  {
    try { throw boost::program_options::invalid_bool_value("bleah bleah"); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_command_line_style()
  {
    try { throw boost::program_options::invalid_command_line_style("bleah bleah"); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_command_line_syntax()
  {
    boost::program_options::invalid_syntax::kind_t const kind =
      boost::program_options::invalid_syntax::long_not_allowed;
    try { throw boost::program_options::invalid_command_line_syntax(kind); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_config_file_syntax()
  {
    boost::program_options::invalid_syntax::kind_t const kind =
      boost::program_options::invalid_syntax::long_not_allowed;
    try { throw boost::program_options::invalid_config_file_syntax("bleah bleah", kind); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_invalid_option_value()
  {
    try { throw boost::program_options::invalid_option_value("bleah bleah"); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_multiple_occurrences()
  {
    try { throw boost::program_options::multiple_occurrences(); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_multiple_values()
  {
    try { throw boost::program_options::multiple_values(); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_reading_file()
  {
    try { throw boost::program_options::reading_file("bleah bleah"); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_required_option()
  {
    try { throw boost::program_options::required_option("bleah bleah"); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_too_many_positional_options_error()
  {
    try { throw boost::program_options::too_many_positional_options_error(); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
  void rethrow_unknown_option()
  {
    try { throw boost::program_options::unknown_option(); }
    CLXX_APP_OPTIONS_RETHROW_ALL()
  }
public:
  /** // doc: test_rethrow_ambiguous_option() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_ambiguous_option( )
  {
    TS_ASSERT_THROWS(rethrow_ambiguous_option(), ambiguous_option_error);
  }
  /** // doc: test_rethrow_invalid_bool_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_bool_value( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_bool_value(), invalid_bool_option_value_error);
  }
  /** // doc: test_rethrow_invalid_command_line_style() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_command_line_style( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_command_line_style(), invalid_command_line_style_error);
  }
  /** // doc: test_rethrow_invalid_command_line_syntax() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_command_line_syntax( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_command_line_syntax(), invalid_command_line_syntax_error);
  }
  /** // doc: test_rethrow_invalid_config_file_syntax() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_config_file_syntax( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_config_file_syntax(), invalid_config_file_syntax_error);
  }
  /** // doc: test_rethrow_invalid_option_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_invalid_option_value( )
  {
    TS_ASSERT_THROWS(rethrow_invalid_option_value(), invalid_option_value_error);
  }
  /** // doc: test_rethrow_multiple_occurrences() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_multiple_occurrences( )
  {
    TS_ASSERT_THROWS(rethrow_multiple_occurrences(), multiple_option_occurrences_error);
  }
  /** // doc: test_rethrow_multiple_values() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_multiple_values( )
  {
    TS_ASSERT_THROWS(rethrow_multiple_values(), multiple_option_values_error);
  }
  /** // doc: test_rethrow_reading_file() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_reading_file( )
  {
    TS_ASSERT_THROWS(rethrow_reading_file(), reading_options_file_error);
  }
  /** // doc: test_rethrow_required_option() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_required_option( )
  {
    TS_ASSERT_THROWS(rethrow_required_option(), required_option_error);
  }
  /** // doc: test_rethrow_too_many_positional_options_error() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_too_many_positional_options_error( )
  {
    TS_ASSERT_THROWS(rethrow_too_many_positional_options_error(), too_many_positional_options_error);
  }
  /** // doc: test_rethrow_unknown_option() {{{
   * \todo Write documentation
   */ // }}}
  void test_rethrow_unknown_option( )
  {
    TS_ASSERT_THROWS(rethrow_unknown_option(), unknown_option_error);
  }
};

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
