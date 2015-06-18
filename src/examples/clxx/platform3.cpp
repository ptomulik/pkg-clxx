// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform3.cpp {{{
 * \file clxx/platform3.cpp
 * \brief Example with \ref clxx::platform_layer_info "platform_layer_info"
 */ // }}}
/** // doc: platform3.cpp {{{
 * \example platform3.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally.
 */ // }}}
// [Program]
// [Includes]
#include <clxx/platform_layer.hpp>
#include <clxx/io/platform_layer_info.hpp>
#include <iostream>
// [Includes]

/// Main function
int main(int, char const*[])
{
  using namespace std;
  using namespace clxx;
  try {
    // [CreatePlatformLayer]
    platform_layer pl(device_type_t::all);
    // [CreatePlatformLayer]
    // [CreatePlatformLayerInfo]
    platform_layer_info info(query_platform_layer_info(pl));
    // [CreatePlatformLayerInfo]
    // [DumpPlatformLayerInfo]
    io::write(cout, info, 2);
    // [DumpPlatformLayerInfo]
  } catch (std::exception const& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
