// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform1.cpp {{{
 * \file clxx/platform1.cpp
 * \brief Example with \ref clxx::platform and \ref clxx::platforms
 */ // }}}
/** // doc: platform1.cpp {{{
 * \example platform1.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms available
 * locally. We use clxx::platforms and clxx::platform.
 */ // }}}
// [Program]
// [DumpPlatform]
#include <clxx/cl/platform.hpp>
#include <iostream>
/// \brief Dump platform information to stdout. Functor.
class dump_platform
  {
    /// \internal
    int count;
  public:
    /// \brief Default constructor
    dump_platform() : count(0) { }
    /// \brief Core operator
    void operator()(clxx::platform const& p)
    {
      std::cout << "Platform " << count << ":" << std::endl;
      std::cout << "  Id ........ : " << p.get() << std::endl;
      std::cout << "  Name ...... : " << p.get_name() << std::endl;
      std::cout << "  Vendor .... : " << p.get_vendor() << std::endl;
      std::cout << "  Version ... : " << p.get_version() << std::endl;
      ++count;
    }
  };
// [DumpPlatform]

// [Main]
#include <clxx/cl/platforms.hpp>
#include <algorithm>
/// \brief Main function
int main(int, char const*[])
{
  try {
    clxx::platforms ps(clxx::get_platforms());
    std::for_each(ps.begin(), ps.end(), dump_platform());
  } catch (std::exception const& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Main]
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
