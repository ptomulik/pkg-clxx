// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/device_detail_options_description.hpp

/** // doc: clxx/app/clinfo/device_detail_options_description.hpp {{{
 * \file clxx/app/clinfo/device_detail_options_description.hpp
 * \brief Defines \ref clxx::app::clinfo::device_detail_options_description
 */ // }}}
#ifndef CLXX_APP_CLINFO_DEVICE_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_DEVICE_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class device_detail_options_description {{{
 * \brief Defines detailed device CLI options for clxx-clinfo program
 *
 * The class defines a lot of options that we're unable to list here. See the
 * implementation of method <tt>_init_options_description()</tt> in the file
 * \ref clxx/app/clinfo/device_detail_options_description.cpp.
 */ // }}}
class device_detail_options_description
  : public clxx::app::options::options_description
{
private:
  void _init_options_description();
public:
  /** // doc: ~device_detail_options_description() {{{
   * \brief Descructor
   */ // }}}
  virtual ~device_detail_options_description();
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
  device_detail_options_description( unsigned line_length = m_default_line_length
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
  device_detail_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_DEVICE_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
