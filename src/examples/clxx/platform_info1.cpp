// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/platform_info1.cpp {{{
 * \file clxx/platform_info1.cpp
 * \brief Usage example for clxx::platform_info
 */ // }}}
/** // doc: platform_info1.cpp {{{
 * \example clxx/platform_info1.cpp
 * \brief Usage example for \ref clxx::platform_info
 */ // }}}

// [Program]
#include <clxx/info/platform_info.hpp>
#include <clxx/io/platform_info.hpp>
#include <iostream>

/// main function
int main()
{
  using namespace clxx;
  platform_info pi;

  pi.set_name("MY OpenCL platform");
  pi.set_vendor("Me");
  pi.set_version("OpenCL 2.1");

  std::cout << "---- Platform Info ----" << std::endl;
  std::cout << pi << std::endl;

  std::cout << std::endl;
  std::cout << "has_name:       " << pi.has_name() << std::endl;
  std::cout << "has_extensions: " << pi.has_extensions() << std::endl;

  pi.clear_name();
  std::cout << std::endl;
  std::cout << "---- after clear_name ----" << std::endl;
  std::cout << "has_name:              " << pi.has_name() << std::endl;

  return 0;
}
// [Program]

/* [Output]
---- Platform Info ----
Version ........................: OpenCL 2.1
Name ...........................: MY OpenCL platform
Vendor .........................: Me

has_name:       1
has_extensions: 0

---- after clear_name ----
has_name:              0
   [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
