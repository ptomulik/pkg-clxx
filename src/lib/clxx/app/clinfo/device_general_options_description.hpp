// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/device_general_options_description.hpp

/** // doc: clxx/app/clinfo/device_general_options_description.hpp {{{
 * \file clxx/app/clinfo/device_general_options_description.hpp
 * \brief Defines \ref clxx::app::clinfo::device_general_options_description
 */ // }}}
#ifndef CLXX_APP_CLINFO_DEVICE_GENERAL_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_DEVICE_GENERAL_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class device_general_options_description {{{
 * \brief Defines general device CLI options for the clxx-clinfo program
 *
 * The following options are provided by the class
 *
 *    - <tt>--device-info</tt> - query for device information,
 *    - <tt>--compute-unit-info</tt> - query for compute unit information,
 *    - <tt>--vector-width-info</tt> - query for xxx-vector-width-xxx options,
 *    - <tt>--image-support-info</tt> - query for information on image support,
 *    - <tt>--global-mem-info</tt> - query for global memory information,
 *    - <tt>--device-generic-info</tt> - query for generic device info.
 */ // }}}
class device_general_options_description
  : public clxx::app::options::options_description
{
private:
  void _init_options_description();
public:
  /** // doc: ~device_general_options_description() {{{
   * \brief Destructor
   */ // }}}
  virtual ~device_general_options_description();
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
  device_general_options_description( unsigned line_length = m_default_line_length
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
  device_general_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_DEVICE_GENERAL_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
