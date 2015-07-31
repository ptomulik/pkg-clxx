// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/platform4.cpp {{{
 * \file clxx/cl/platform4.cpp
 * \brief Example with \ref clxx::query_platform_layer_info() "query_platform_layer_info()"
 */ // }}}
/** // doc: cl/platform4.cpp {{{
 * \example clxx/cl/platform4.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally.
 */ // }}}
// [Program]
#include <clxx/cl/platform_layer.hpp>
#include <clxx/io/platform_layer_info.hpp>
#include <iostream>

/// Main function
int main(int, char const*[])
{
  try {
    std::cout << clxx::query_platform_layer_info() << std::endl;
  } catch (std::exception const& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
