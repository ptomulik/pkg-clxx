// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/options_map.hpp

/** // doc: clxx/app/options/options_map.hpp {{{
 * \file clxx/app/options/options_map.hpp
 * \brief Defines the \ref clxx::app::options::options_map class
 */ // }}}
#ifndef CLXX_APP_OPTIONS_OPTIONS_MAP_HPP_INCLUDED
#define CLXX_APP_OPTIONS_OPTIONS_MAP_HPP_INCLUDED

#include <boost/program_options/variables_map.hpp>

namespace clxx { namespace app { namespace options {
/** // doc: options_map {{{
 * \brief Storage for option values
 *
 * This is just a direct descendant of
 * <a href="www.boost.org/doc/html/boost/program_options/variables_map.html">boost::program_options::variables_map</a>.
 * It's here in case we had to introduce any workarounds, fixes or our special
 * features to the boost's variable map.
 */ // }}}
class options_map
  : public boost::program_options::variables_map
{
public:
  /** // doc: ~options_map() {{{
   * \brief Destructor
   */ // }}}
  virtual ~options_map();
  /** // doc: options_map() {{{
   * \brief Constructor
   */ // }}}
  options_map();
};
/** // doc: store() {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::store;
/** // doc: notify() {{{
 * \todo Write documentation
 */ // }}}
using boost::program_options::notify;
} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_OPTIONS_MAP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
