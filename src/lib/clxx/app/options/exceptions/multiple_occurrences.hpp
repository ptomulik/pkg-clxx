// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/multiple_occurrences.hpp

/** // doc: clxx/app/options/exceptions/multiple_occurrences.hpp {{{
 * \file clxx/app/options/exceptions/multiple_occurrences.hpp
 * \brief Defines the \ref clxx::app::options::multiple_option_occurrences_error
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_MULTIPLE_OCCURRENCES_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_MULTIPLE_OCCURRENCES_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/common/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::multiple_occurrences>
  { typedef boost::program_options::multiple_occurrences type; };
/** \endcond */
} // end namespace clxx

namespace clxx { namespace app { namespace options {

/** // doc: multiple_option_occurrences_error {{{
 * \brief Exception thrown when a multiple occurrences of an option is detected
 */ // }}}
class multiple_option_occurrences_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::multiple_occurrences
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::multiple_occurrences
    > base_;
public:
  /** // doc: multiple_option_occurrences_error(boost::program_options::multiple_occurrences) {{{
   * \brief Constructor
   */ // }}}
  multiple_option_occurrences_error(boost::program_options::multiple_occurrences const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_MULTIPLE_OCCURRENCES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
