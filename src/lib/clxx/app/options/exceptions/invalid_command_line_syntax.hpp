// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/invalid_command_line_syntax.hpp

/** // doc: clxx/app/options/exceptions/invalid_command_line_syntax.hpp {{{
 * \file clxx/app/options/exceptions/invalid_command_line_syntax.hpp
 * \brief Defines the \ref clxx::app::options::invalid_command_line_syntax_error
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_COMMAND_LINE_SYNTAX_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_COMMAND_LINE_SYNTAX_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::invalid_command_line_syntax >
  { typedef boost::program_options::invalid_command_line_syntax type; };
/* \endcond */
} /* namespace clxx */

namespace clxx { namespace app { namespace options {
/** doc: invalid_command_line_syntax_error {{{
 * \brief Exception thrown when invalid command line syntax is detected
 */ // }}}
class invalid_command_line_syntax_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_command_line_syntax
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_command_line_syntax
    > base_;
public:
  /** // doc: invalid_command_line_syntax_error(boost::program_options::invalid_command_line_syntax) {{{
   * \brief Constructor
   */ // }}}
  invalid_command_line_syntax_error(boost::program_options::invalid_command_line_syntax const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_COMMAND_LINE_SYNTAX_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
