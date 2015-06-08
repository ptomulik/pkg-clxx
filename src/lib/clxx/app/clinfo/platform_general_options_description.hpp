// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/platform_general_options_description.hpp

/** // doc: clxx/app/clinfo/platform_general_options_description.hpp {{{
 * \file clxx/app/clinfo/platform_general_options_description.hpp
 * \brief Defines \ref clxx::app::clinfo::platform_general_options_description
 */ // }}}
#ifndef CLXX_APP_CLINFO_PLATFORM_GENERAL_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_PLATFORM_GENERAL_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class platform_general_options_description {{{
 * \brief Defines general platform CLI options for clxx-clinfo program
 *
 * Currently there is no options defined by this class. It's provided for
 * further extensions that may potentially be needed.
 */ // }}}
class platform_general_options_description
  : public clxx::app::options::options_description
{
private:
  void _init_options_description();
public:
  /** // doc: ~platform_general_options_description() {{{
   * \brief Destructor
   */ // }}}
  virtual ~platform_general_options_description();
  /** // {{{
   * \brief Constructor
   *
   * \param line_length
   *    Passed as \e line_length to
   *    \ref clxx::app::options::options_description(unsigned, unsigned)
   * \param min_description_length
   *    Passed as \e min_description_length to
   *    \ref clxx::app::options::options_description(unsigned, unsigned)
   */ // }}}
  platform_general_options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // {{{
   * \brief Constructor
   *
   * \param caption
   *    Passed as \e caption to
   *    \ref clxx::app::options::options_description(const std::string&, unsigned, unsigned)
   * \param line_length
   *    Passed as \e line_length to
   *    \ref clxx::app::options::options_description(const std::string&, unsigned, unsigned)
   * \param min_description_length
   *    Passed as \e min_description_length to
   *    \ref clxx::app::options::options_description(const std::string&, unsigned, unsigned)
   */ // }}}
  platform_general_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_PLATFORM_GENERAL_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
