// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/s11n2.cpp {{{
 * \file clxx/s11n2.cpp
 * \brief Usage example for \ref clxx_s11n
 */ // }}}
/** // doc: s11n2.cpp {{{
 * \example clxx/s11n2.cpp
 * \brief Usage example for \ref clxx_s11n
 *
 * Read clxx::platform_layer_info from an XML archive and print it to std::cout.
 */ // }}}

// [Program]
#include <clxx/info/platform_layer_info.hpp>
#include <clxx/s11n/platform_layer_info.hpp>
#include <clxx/io/platform_layer_info.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <iostream>

int main() 
{
  clxx::platform_layer_info obj;
  boost::archive::xml_iarchive ar(std::cin);
  ar >> boost::serialization::make_nvp("platform_layer_info", obj);
  std::cout << obj;
  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
