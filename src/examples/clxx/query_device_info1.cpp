// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/query_device_info1.cpp {{{
 * \file clxx/query_device_info1.cpp
 * \brief Usage example for clxx::query_device_info()
 */ // }}}
/** // doc: query_device_info1.cpp {{{
 * \example clxx/query_device_info1.cpp
 * \brief Usage example for \ref clxx::query_device_info()
 */ // }}}

// [Program]
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/devices.hpp>
#include <clxx/io/device_info.hpp>
#include <iostream>

/// main function
int main()
{
  using namespace clxx;
  platforms ps{get_platforms()};
  if(!ps.empty())
    {
      devices ds{get_devices(ps[0])};
      if(!ds.empty())
        {
          // print device info for first OpenCL device of the first platform found
          std::cout << query_device_info(ds[0]) << std::endl;
        }
    }
  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
