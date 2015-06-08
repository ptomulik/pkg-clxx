// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/io_options_description.hpp

/** // doc: clxx/app/clinfo/io_options_description.hpp {{{
 * \file clxx/app/clinfo/io_options_description.hpp
 * \brief Defines clxx::app::clinfo::io_options_description
 */ // }}}
#ifndef CLXX_APP_CLINFO_io_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_io_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class io_options_description {{{
 * \brief Defines I/O-related CLI options for the clxx-clinfo program
 *
 * The class defines the following options:
 *
 *  - <tt>--output-format, -O</tt> - output format (uff/xml/txt/bin),
 *  - <tt>--input-format, -I</tt> - input format (xml/text/bin), relevant only with \c --input,
 *  - <tt>--input, -i</tt> - read previously saved data from file, see also \c --input-format,
 *  - <tt>--output, -o</tt> - save the output to file instead of stdout, see also \c --output-format,
 */ // }}}
class io_options_description
  : public clxx::app::options::options_description
{
  void _init_options_description( ) ;
public:
  /** // doc: ~io_options_description() {{{
   * \brief Destructor
   */ // }}}
  virtual ~io_options_description();
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
  io_options_description( unsigned line_length = m_default_line_length
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
  io_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_io_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
