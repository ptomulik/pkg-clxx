// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/device1.cpp {{{
 * \file clxx/device1.cpp
 * \brief Example with \ref clxx::device and \ref clxx::platform
 */ // }}}
/** // doc: device1.cpp {{{
 * \example device1.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally.
 */ // }}}
// [Program]
#include <clxx/platforms.hpp>
#include <clxx/devices.hpp>
#include <algorithm>

// [DumpDevice]
#include <clxx/device.hpp>
#include <iostream>
/// \brief Dump OpenCL device info to stdout. Functor.
class dump_device
{
  /// \internal
  int count;
public:
  /// \brief Default constructor
  dump_device() : count(0) { }
  /// \brief Core operator
  void operator ()(clxx::device const& d)
  {
    std::cout << "  Device " << count << ":" << std::endl;
    std::cout << "    Id ........ : " << d.get() << std::endl;
    std::cout << "    Name ...... : " << d.get_name() << std::endl;
    std::cout << "    Vendor .... : " << d.get_vendor() << std::endl;
    std::cout << "    Version: .. : " << d.get_version() << std::endl;
    ++count;
  }
};
// [DumpDevice]

// [DumpPlatform]
/// \brief Dump OpenCL platform info to stdout. Functor.
class dump_platform
{
  /// \internal
  int count;
public:
  /// \brief Default constructor
  dump_platform() : count(0) { }
  /// \brief Core operator
  void operator () (clxx::platform const& p)
  {
    std::cout << "Platform " << count << ":" << std::endl;
    std::cout << "  Id .......... : " << p.get() << std::endl;
    std::cout << "  Name ........ : " << p.get_name() << std::endl;
    std::cout << "  Profile ..... : " << p.get_profile() << std::endl;
    std::cout << "  Version ..... : " << p.get_version() << std::endl;
    std::cout << "  Extensions .. : " << p.get_extensions() << std::endl;

    clxx::devices ds(clxx::get_devices(p));
    std::for_each(ds.begin(), ds.end(), dump_device());
    std::cout << std::endl;

    ++count;
  }
};
// [DumpPlatform]

// [Main]
#include <algorithm>
/// \brief Main function
int main(int, char const*[])
{
  using clxx::get_platforms;
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
