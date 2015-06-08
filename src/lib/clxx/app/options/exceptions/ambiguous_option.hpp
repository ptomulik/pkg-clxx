// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/ambiguous_option.hpp

/** // doc: clxx/app/options/exceptions/ambiguous_option.hpp {{{
 * \file clxx/app/options/exceptions/ambiguous_option.hpp
 * \brief Defines the clxx::app::options::ambiguous_option_error exception
 *        class
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_AMBIGUOUS_OPTION_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_AMBIGUOUS_OPTION_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::ambiguous_option>
  { typedef boost::program_options::ambiguous_option type; };
/** \endcond */
} // end namespace clxx

namespace clxx { namespace app { namespace options {
/** // doc: ambiguous_option_error {{{
 * \brief An exception thrown when there is ambiguity between several possible
 *        options
 */ // }}}
class ambiguous_option_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::ambiguous_option
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::ambiguous_option
    > base_;
public:
  /** // doc: ambiguous_option_error(boost::program_options::ambiguous_option) {{{
   * \brief Copy constructor
   */ // }}}
  ambiguous_option_error(boost::program_options::ambiguous_option const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_AMBIGUOUS_OPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
