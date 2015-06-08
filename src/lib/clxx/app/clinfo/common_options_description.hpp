// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/common_options_description.hpp

/** // doc: clxx/app/clinfo/common_options_description.hpp {{{
 * \file clxx/app/clinfo/common_options_description.hpp
 * \brief Defines the clxx::app::clinfo::common_optins_description
 */ // }}}
#ifndef CLXX_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/common_options_description.hpp>

namespace clxx { namespace app { namespace clinfo {
/** // doc: class common_options_description {{{
 * \brief Defines common CLI options for the clxx-clinfo program
 *
 * The following CLI options are defined in addition to these provided by
 * \ref clxx::app::common_options_description
 *
 *  - <tt>--help-detail</tt> - displays help on detailed (platform and device) options,
 *  - <tt>--help-platform</tt> - displays detailed platform options,
 *  - <tt>--help-device</tt> - displays detailed device options,
 *  - <tt>--config, -c file</tt> - read options from \c file,
 *  - <tt>--indent num</tt> - indent each level of output by \c num spaces,
 *  - <tt>--short, -s</tt> - short listing (no details).
 */ // }}}
class common_options_description
  : public clxx::app::common_options_description
{
  /** // doc: common_options_description::_init_options_description() {{{
   * \brief Initializes the common_options_description
   */ // }}}
  void _init_options_description( ) ;
public:
  /** // doc: common_options_description::~common_options_description() {{{
   * \brief Destructor
   */ // }}}
  virtual ~common_options_description();
  /** // doc: common_options_description(...) {{{
   * \brief Constructor
   *
   * \param line_length
   *    Passed as \e line_length to
   *    \ref clxx::app::common_options_description::common_options_description(unsigned, unsigned)
   * \param min_description_length
   *    Passed as \e min_description_length to
   *    \ref clxx::app::common_options_description::common_options_description(unsigned, unsigned)
   */ // }}}
  common_options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: common_options_description(...) {{{
   * \brief Constructor
   *
   * \param caption
   *    Passed as \e caption to
   *    \ref clxx::app::common_options_description::common_options_description(const std::string&, unsigned, unsigned)
   * \param line_length
   *    Passed as \e line_length to
   *    \ref clxx::app::common_options_description::common_options_description(const std::string&, unsigned, unsigned)
   * \param min_description_length
   *    Passed as \e min_description_length to
   *    \ref clxx::app::common_options_description::common_options_description(const std::string&, unsigned, unsigned)
   */ // }}}
  common_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
