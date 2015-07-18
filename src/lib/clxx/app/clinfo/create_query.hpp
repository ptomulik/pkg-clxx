// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/create_query.hpp

/** // doc: clxx/app/clinfo/create_query.hpp {{{
 * \file clxx/app/clinfo/create_query.hpp
 * \brief Declares function that prepare platform/device queries for clinfo application
 */ // }}}
#ifndef CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED
#define CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED

#include <clxx/info/platform_query.hpp>
#include <clxx/info/device_query.hpp>
#include <clxx/app/options/options_map.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: create_platform_query(optmap) {{{
 * \brief Create \ref clxx::platform_query object to be used by clinfo application
 * \param optmap Options map with command-line options as provided by user
 * \returns An instance of \ref clxx::platform_query "platform_query" object
 *          created accordingly to requirements specified in command-line
 *          options specified in \em optmap
 */ // }}}
clxx::platform_query
create_platform_query(clxx::app::options::options_map const& optmap);
/** // doc: create_platform_query(optmap) {{{
 * \brief Create \ref clxx::device_query object to be used by clinfo application
 * \param optmap Options map with command-line options as provided by user
 * \returns An instance of \ref clxx::device_query "device_query" object
 *          created accordingly to requirements specified in command-line
 *          options specified in \em optmap
 */ // }}}
clxx::device_query
create_device_query(clxx::app::options::options_map const& optmap);

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
