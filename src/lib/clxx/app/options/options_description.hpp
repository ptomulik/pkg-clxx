// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/options_description.hpp

/** // doc: clxx/app/options/options_description.hpp {{{
 * \file clxx/app/options/options_description.hpp
 * \brief Defines the \ref clxx::app::options::options_description class
 */ // }}}
#ifndef CLXX_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <boost/program_options/options_description.hpp>

namespace clxx { namespace app { namespace options {
/** // doc: option_description {{{
 * \todo Write documentation
 */ // }}}
using option_description = boost::program_options::option_description;
/** // doc: options_description_easy_init {{{
 * \todo Write documentation
 */ // }}}
using options_description_easy_init = boost::program_options::options_description_easy_init;
/** // doc: options_description {{{
 * \brief A set of option descriptions
 *
 * This is just a direct descendant of
 * <a href="www.boost.org/doc/html/boost/program_options/options_description.html">boost::program_options::options_description</a>
 * class. It's here in case we had to introduce any fixes/workarounds etc.
 */ // }}}
class options_description
  : public boost::program_options::options_description
{
public:
  /** // doc: option_description {{{
   * \brief A type used to represent single option description
   */ // }}}
  typedef boost::program_options::option_description option_description;
public:
  /** // doc: ~options_description() {{{
   * \brief Destructor
   */ // }}}
  ~options_description();
  /** // doc: options_description(...) {{{
   * \brief Constructor
   *
   * \param line_length Passed directly to the constructor of the base class
   *    \c boost::program_options::options_description.
   * \param min_description_length Passed directly to the constructor of the
   *    base class \c boost::program_options::options_description.
   */ // }}}
  options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: options_description(...) {{{
   * \brief Constructor
   *
   * \param caption Passed directly to the constructor of the base class
   *    \c boost::program_options::options_description.
   * \param line_length Passed directly to the constructor of the base class
   *    \c boost::program_options::options_description.
   * \param min_description_length Passed directly to the constructor of the
   *    base class \c boost::program_options::options_description.
   */ // }}}
  options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
