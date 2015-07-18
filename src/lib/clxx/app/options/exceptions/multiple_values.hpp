// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/multiple_values.hpp

/** // doc: clxx/app/options/exceptions/multiple_values.hpp {{{
 * \file clxx/app/options/exceptions/multiple_values.hpp
 * \brief Implements the \ref clxx::app::options::multiple_option_values_error
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_MULTIPLE_VALUES_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_MULTIPLE_VALUES_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/common/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::multiple_values>
  { typedef boost::program_options::multiple_values type; };
/** \endcond */
} // end namespace clxx

namespace clxx { namespace app { namespace options {
/** doc: multiple_option_values_error {{{
 * \brief Exception thrown when multiple options values are provided to a
 *    single-valued option
 */ // }}}
class multiple_option_values_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::multiple_values
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::multiple_values
    > base_;
public:
  /** // doc: multiple_option_values_error(boost::program_options::multiple_values) {{{
   * \brief Constructor
   */ // }}}
  multiple_option_values_error(boost::program_options::multiple_values const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_MULTIPLE_VALUES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
