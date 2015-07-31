// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/io/autosep1.cpp {{{
 * \file clxx/io/autosep1.cpp
 * \brief Provides io/autosep1.cpp example.
 */ // }}}
/** // example {{{
 * \example clxx/io/autosep1.cpp
 * This example demonstrates how one may use the clxx::io::autosep_ object
 * to format sequences when printing them to a stream.
 */ // }}}
// [Program]
#include <clxx/io/autosep.hpp>
#include <iostream>
/// Main function
int main(int, char**)
{
  clxx::io::autosep_<const char*> as(", ");
  std::cout << "tab[] = {";
  for(int i = 1; i <= 3; ++i) {
    std::cout << as << i;
  }
  std::cout << "}" << std::endl;
  return EXIT_SUCCESS;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
