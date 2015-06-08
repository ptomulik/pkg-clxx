// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform2.cpp {{{
 * \file clxx/platform2.cpp
 * \todo Write file documentation
 */ // }}}
/** // doc: platform2.cpp {{{
 * \example platform2.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally.
 */ // }}}
// [Program]
// [Includes]
#include <clxx/platforms.hpp>
#include <clxx/devices.hpp>
#include <clxx/platform_info.hpp>
#include <clxx/device_info.hpp>
#include <clxx/io/platform_info.hpp>
#include <clxx/io/device_info.hpp>
#include <iostream>
// [Includes]

/// Main function
int main(int, char const*[])
{
  using namespace std;
  using namespace clxx;
  try {
    // [CreatePlatforms]
    // Create proxies for all local OpenCL platforms
    platforms plats(get_platforms());
    // [CreatePlatforms]

    // [PreparePlatformQuery]
    // Prepare platform query
    platform_query pq;
    pq.select_none();
    pq.select_id();
    pq.select_name();
    pq.select_vendor();
    // [PreparePlatformQuery]

    // [PrepareDeviceQuery]
    // Prepare device query
    device_query dq;
    dq.select_none();
    dq.select_id();
    dq.select_name();
    dq.select_vendor();
    dq.select_version();
    // [PrepareDeviceQuery]

    // Query all platforms
    for (platforms::const_iterator pi = plats.begin(); pi != plats.end(); ++ pi)
      {
        // [CreatePlatformInfo]
        // Crete platform_info object and gather information about *pi
        // by performing query described by pq
        platform_info pinfo(query_platform_info(*pi, pq));
        // [CreatePlatformInfo]

        // Print-out pi info
        cout << "Platform " << pi - plats.begin() << ":" << endl;
        io::write(cout, pinfo, 2) << endl;

        // Query all devices that belong to platform *pi
        // [CreateDevices]
        // Create proxies to all devices that belong to platform *pi.
        devices devices(get_devices(*pi));
        // [CreateDevices]
        for(devices::const_iterator di = devices.begin();
            di != devices.end(); ++di)
          {
            // [CreateDeviceInfo]
            // Crete device_info object gather information about *di by
            // performing query described by dq
            device_info dinfo(query_device_info(*di, dq));
            // [CreateDeviceInfo]
            // Print-out device info
            cout << "    Device " << di - devices.begin() << ":" << endl;
            io::write(cout, dinfo, 4) << endl;
          }
    }
  } catch (std::exception const& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
