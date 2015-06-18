// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/invalid_option_value.hpp

/** // doc: clxx/app/options/exceptions/invalid_option_value.hpp {{{
 * \file clxx/app/options/exceptions/invalid_option_value.hpp
 * \brief Defines the \ref clxx::app::options::invalid_option_value_error
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_OPTION_VALUE_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_OPTION_VALUE_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::invalid_option_value>
  { typedef boost::program_options::invalid_option_value type; };
/** \endcond */
} // end namespace clxx

namespace clxx { namespace app { namespace options {
/** doc: invalid_option_value_error {{{
 * \brief Exception thrown when invalid value for an option is provided
 */ // }}}
class invalid_option_value_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_option_value
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_option_value
    > base_;
public:
  /** // doc: invalid_option_value_error(boost::program_options::invalid_option_value) {{{
   * \brief Constructor
   */ // }}}
  invalid_option_value_error(boost::program_options::invalid_option_value const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_OPTION_VALUE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
