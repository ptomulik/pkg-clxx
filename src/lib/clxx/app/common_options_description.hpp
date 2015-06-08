// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/common_options_description.hpp

/** // doc: clxx/app/common_options_description.hpp {{{
 * \file clxx/app/common_options_description.hpp
 * \brief Defines clxx::app::common_options_description
 */ // }}}
#ifndef CLXX_APP_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app {
/** // doc: class common_options_description {{{
 * \brief Defines common options used by all clxx programs
 *
 * Currently it defines the following options
 *
 *  - <tt>--help, -h</tt> - print help,
 *  - <tt>--version, -v</tt> - print program version
 */ // }}}
class common_options_description
  : public options::options_description
{
protected:
  /** // _init_app_common_options() {{{
   * \brief Initialize common options for any clxx program
   *
   * It's thought to be called from constructors.
   */ // }}}
  void _init_options_description();
public:
  /** // doc: ~common_options_description() {{{
   * \brief Destructor
   */ // }}}
  ~common_options_description();
  /** // doc: common_options_description(...) {{{
   * \brief Constructor
   *
   * \param line_length
   *    Passed as \e line_length to
   *    \ref clxx::app::options::options_description(const std::string&, unsigned, unsigned)
   * \param min_description_length
   *    Passed as \e min_description_length to
   *    \ref clxx::app::options::options_description(const std::string&, unsigned, unsigned)
   */ // }}}
  common_options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: common_options_description(...) {{{
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
  common_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} } // end namespace clxx::app

#endif /* CLXX_APP_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
