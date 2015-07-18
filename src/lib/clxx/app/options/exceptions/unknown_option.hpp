// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/unknown_option.hpp

/** // doc: clxx/app/options/exceptions/unknown_option.hpp {{{
 * \file clxx/app/options/exceptions/unknown_option.hpp
 * \brief Defines the \ref clxx::app::options::unknown_option_error
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_UNKNOWN_OPTION_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_UNKNOWN_OPTION_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/common/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::unknown_option>
  { typedef boost::program_options::unknown_option type; };
/** \endcond */
} // end namespace clxx

namespace clxx { namespace app { namespace options {
/** doc: unknown_option_error {{{
 * \brief Exception thrown when unknown option is passed to a clxx application
 */ // }}}
class unknown_option_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::unknown_option
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::unknown_option
    > base_;
public:
  /** // doc: unknown_option_error(boost::program_options::unknown_optione) {{{
   * \brief Constructor
   *
   * \param e
   *    An exception object to be used as this object's initializer.
   */ // }}}
  unknown_option_error(boost::program_options::unknown_option const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_UNKNOWN_OPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
