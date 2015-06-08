// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/reading_file.hpp

/** // doc: clxx/app/options/exceptions/reading_file.hpp {{{
 * \file clxx/app/options/exceptions/reading_file.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_READING_FILE_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_READING_FILE_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::reading_file>
  { typedef boost::program_options::reading_file type; };
/** \endcond */
} // end namespace clxx

namespace clxx { namespace app { namespace options {
/** // doc: reading_options_file_error {{{
 * \brief Exception thrown in case there is an error when reading a
 *    configuration file
 */ // }}}
class reading_options_file_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::reading_file
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::reading_file
    > base_;
public:
  /** // doc: reading_options_file_error(boost::program_options::reading_file) {{{
   * \brief Constructor
   */ // }}}
  reading_options_file_error(boost::program_options::reading_file const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_READING_FILE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
