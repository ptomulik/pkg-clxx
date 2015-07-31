// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/s11n/s11n1.cpp {{{
 * \file clxx/s11n/s11n1.cpp
 * \brief Usage example for \ref clxx_s11n
 */ // }}}
/** // doc: s11n/s11n1.cpp {{{
 * \example clxx/s11n/s11n1.cpp
 * \brief Usage example for \ref clxx_s11n -- store a clxx::platform_layer_info
 *        to XML archive
 */ // }}}

// [Program]
#include <clxx/cl/platform_layer.hpp>
#include <clxx/s11n/platform_layer_info.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <iostream>

/// Main function
int main() 
{
  clxx::platform_layer_info obj{ clxx::query_platform_layer_info() };
  boost::archive::xml_oarchive ar(std::cout);
  ar << boost::serialization::make_nvp("platform_layer_info", obj);
  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
