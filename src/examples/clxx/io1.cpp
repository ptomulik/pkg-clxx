// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/io1.cpp {{{
 * \file clxx/io1.cpp
 * \brief Example usage for I/O functions used to pring an enum value
 */ // }}}
/** // doc: io1.cpp {{{
 * \example io1.cpp
 * This example demonstrates usage of I/O functions with clxx enum value.
 */ // }}}
// [Program]
#include <clxx/io/types.hpp>
#include <clxx/common/types.hpp>
#include <iostream>
// [Main]
/// \brief Main function
int main(int, char const*[])
{
  // [OutputStatusT]
  clxx::status_t err = clxx::status_t::device_not_found;
  std::cout << "1. Error code: " << err << std::endl;
  // [OutputStatusT]
  return EXIT_SUCCESS;
}
// [Main]
// [Program]



// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
