// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/device_info1.cpp {{{
 * \file clxx/device_info1.cpp
 * \brief Usage example for clxx::device_info
 */ // }}}
/** // doc: device_info1.cpp {{{
 * \example clxx/device_info1.cpp
 * \brief Usage example for \ref clxx::device_info
 */ // }}}

// [Program]
#include <clxx/device_info.hpp>
#include <clxx/io/device_info.hpp>
#include <iostream>

/// main function
int main()
{
  using namespace clxx;
  device_info di;

  di.set_name("MY LOVELY GPU");
  di.set_vendor_id(0x1234);
  di.set_version("OpenCL 2.1");

  std::cout << "---- Device Info ----" << std::endl;
  std::cout << di << std::endl;

  std::cout << std::endl;
  std::cout << "has_name:              " << di.has_name() << std::endl;
  std::cout << "has_max_compute_units: " << di.has_max_compute_units() << std::endl;

  di.clear_name();
  std::cout << std::endl;
  std::cout << "---- after clear_name ----" << std::endl;
  std::cout << "has_name:              " << di.has_name() << std::endl;

  return 0;
}
// [Program]

/* [Output]
---- Device Info ----
Vendor Id ....................: 0x1234
Name .........................: MY LOVELY GPU
Version ......................: OpenCL 2.1

has_name:              1
has_max_compute_units: 0

---- after clear_name ----
has_name:              0
   [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
