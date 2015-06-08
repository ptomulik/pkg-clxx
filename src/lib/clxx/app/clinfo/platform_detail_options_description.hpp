// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/platform_detail_options_description.hpp

/** // doc: clxx/app/clinfo/platform_detail_options_description.hpp {{{
 * \file clxx/app/clinfo/platform_detail_options_description.hpp
 * \brief Defines the \ref clxx::app::clinfo::platform_detail_options_description
 */ // }}}
#ifndef CLXX_APP_CLINFO_PLATFORM_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_PLATFORM_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class platform_detail_options_description {{{
 * \brief Provides detailed platform CLI options for \c clxx-clinfo program
 *
 * The class defines the following options
 *
 *  - <tt>--platform-profile</tt> - query (or not) for platform profile,
 *  - <tt>--platform-version</tt> - query (or not) for platform version,
 *  - <tt>--platform-name</tt> - query for platform name,
 *  - <tt>--platform-vendor</tt> - query for platform vendor,
 *  - <tt>platform-extensions</tt> - query for platform extensions.
 */ // }}}
class platform_detail_options_description
  : public clxx::app::options::options_description
{
private:
  void _init_options_description();
public:
  /** // doc: ~platform_detail_options_description() {{{
   * \brief Destructor
   */ // }}}
  virtual ~platform_detail_options_description();
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
  platform_detail_options_description( unsigned line_length = m_default_line_length
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
  platform_detail_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};

} } } // end namespace clxx

#endif /* CLXX_APP_CLINFO_PLATFORM_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
