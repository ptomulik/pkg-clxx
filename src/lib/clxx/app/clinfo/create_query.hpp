// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/create_query.hpp

/** // doc: clxx/app/clinfo/create_query.hpp {{{
 * \file clxx/app/clinfo/create_query.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED
#define CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED

#include <clxx/platform_query.hpp>
#include <clxx/device_query.hpp>
#include <clxx/app/options/options_map.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: create_platform_query(optmap) {{{
 * \todo Write documentation
 */ // }}}
clxx::platform_query
create_platform_query(clxx::app::options::options_map const& optmap);
/** // doc: create_platform_query(optmap) {{{
 * \todo Write documentation
 */ // }}}
clxx::device_query
create_device_query(clxx::app::options::options_map const& optmap);

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
