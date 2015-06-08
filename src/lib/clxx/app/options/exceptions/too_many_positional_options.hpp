// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/too_many_positional_options.hpp

/** // doc: clxx/app/options/exceptions/too_many_positional_options.hpp {{{
 * \file clxx/app/options/exceptions/too_many_positional_options.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_TOO_MANY_POSITIONAL_OPTIONS_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_TOO_MANY_POSITIONAL_OPTIONS_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg<
  boost::program_options::too_many_positional_options_error
>
  { typedef boost::program_options::too_many_positional_options_error type; };
/** \endcond */
} /* namespace clxx */

namespace clxx { namespace app { namespace options {

/** // doc: too_many_positional_options_error {{{
 * \brief Exception thrown when there is too many positional options on command
 *    line
 */ // }}}
class too_many_positional_options_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::too_many_positional_options_error
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::too_many_positional_options_error
    > base_;
public:
  /** // doc: too_many_positional_options_error(boost::program_options::too_many_positional_options_error) {{{
   * \brief Constructor
   */ // }}}
  too_many_positional_options_error(boost::program_options::too_many_positional_options_error const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_TOO_MANY_POSITIONAL_OPTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
