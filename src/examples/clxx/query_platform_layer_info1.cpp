// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/query_platform_layer_info1.cpp {{{
 * \file clxx/query_platform_layer_info1.cpp
 * \brief Usage example for \ref clxx::query_platform_layer_info() "query_platform_layer_info()"
 */ // }}}
/** // doc: query_platform_layer_info1.cpp {{{
 * \example clxx/query_platform_layer_info1.cpp
 * \brief Usage example for \ref clxx::query_platform_layer_info() "query_platform_layer_info()"
 */ // }}}
// [Program]
#include <clxx/cl/platform_layer.hpp>
#include <clxx/io/platform_layer_info.hpp>
#include <iostream>

/// Main function
int main(int, char const*[])
{
  // query all the platforms/devices for info and print it
  std::cout << clxx::query_platform_layer_info() << std::endl;
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
