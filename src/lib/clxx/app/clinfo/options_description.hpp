// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/options_description.hpp

/** // doc: clxx/app/clinfo/options_description.hpp {{{
 * \file clxx/app/clinfo/options_description.hpp
 * \brief Defines clxx::app::clinfo::options_description
 */ // }}}
#ifndef CLXX_APP_CLINFO_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>
#include <clxx/app/clinfo/common_options_description.hpp>
#include <clxx/app/clinfo/platform_general_options_description.hpp>
#include <clxx/app/clinfo/platform_detail_options_description.hpp>
#include <clxx/app/clinfo/device_general_options_description.hpp>
#include <clxx/app/clinfo/device_detail_options_description.hpp>
#include <clxx/app/clinfo/io_options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // {{{
 * \brief Defines all the CLI options for clxx-clinfo program
 *
 * This class gathers together options defined by the following classes:
 *
 *   - \ref clxx::app::clinfo::common_options_description "common_options_description",
 *   - \ref clxx::app::clinfo::platform_general_options_description "platform_general_options_description",
 *   - \ref clxx::app::clinfo::platform_detail_options_description "platform_detail_options_description",
 *   - \ref clxx::app::clinfo::device_general_options_description "device_general_options_description",
 *   - \ref clxx::app::clinfo::device_detail_options_description "device_detail_options_description",
 *   - \ref clxx::app::clinfo::io_options_description "io_options_description".
 */ // }}}
class options_description
  : public clxx::app::options::options_description
{
public:
  /** // doc: ~options_description() {{{
   * \brief Destructor
   */ // }}}
  virtual ~options_description();
  /** // doc: options_description(...) {{{
   * \brief Constructor
   *
   * \param line_length
   *    Passed as \e line_length to
   *    \ref clxx::app::options::options_description(unsigned, unsigned)
   * \param min_description_length
   *    Passed as \e min_description_length to
   *    \ref clxx::app::options::options_description(unsigned, unsigned)
   */ // }}}
  options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: options_description(...) {{{
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
  options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // {{{
   * \brief Returns common CLI options of the clxx-clinfo program
   *
   * It returns options definition object, not the options values.
   */ // }}}
  common_options_description const& common_options() const
    {
      return this->_common_options;
    }
  /** // {{{
   * \brief Returns general platform CLI options of the clxx-clinfo program
   *
   * It returns options definition object, not the options values.
   */ // }}}
  platform_general_options_description const& platform_general_options() const
    {
      return this->_platform_general_options;
    }
  /** // {{{
   * \brief Returns detailed platform CLI options of the clxx-clinfo program
   *
   * It returns options definition object, not the options values.
   */ // }}}
  platform_detail_options_description const& platform_detail_options() const
    {
      return this->_platform_detail_options;
    }
  /** // {{{
   * \brief Returns general device CLI options of the clxx-clinfo program
   *
   * It returns options definition object, not the options values.
   */ // }}}
  device_general_options_description const& device_general_options() const
    {
      return this->_device_general_options;
    }
  /** // {{{
   * \brief Returns detailed device CLI options of the clxx-clinfo program
   *
   * It returns options definition object, not the options values.
   */ // }}}
  device_detail_options_description const& device_detail_options() const
    {
      return this->_device_detail_options;
    }
  /** // {{{
   * \brief Returns I/O-related CLI optins of the clxx-clinfo program
   *
   * It returns options definition object, not the options values.
   */ // }}}
  io_options_description const& io_options() const
    {
      return this->_io_options;
    }
private:
  void _init_options_description( );
private:
  common_options_description _common_options;
  platform_general_options_description _platform_general_options;
  platform_detail_options_description _platform_detail_options;
  device_general_options_description _device_general_options;
  device_detail_options_description _device_detail_options;
  io_options_description _io_options;
};

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
