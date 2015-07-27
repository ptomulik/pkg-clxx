// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/memoized_function1.cpp {{{
 * \file clxx/common/memoized_function1.cpp
 * \brief Usage example for \ref clxx::memoized_function
 */ // }}}
/** // doc: clxx/common/memoized_function1.cpp {{{
 * \example clxx/common/memoized_function1.cpp
 * \brief Usage example for \ref clxx::memoized_function
 */ // }}}

// [Program]
#include <clxx/common/memoized_function.hpp>
#include <iostream>

/// Adds two numbers
int add(int a, int b)
{
  std::cout << "(computing sum...) ";
  return a+b;
}

/// Memoized version of the add() function
auto lazy_add = clxx::make_memoized_function(add);

/// Main function
int main() 
{
  std::cout << "2 + 2 = " << lazy_add(2,2) << std::endl;
  std::cout << "3 + 4 = " << lazy_add(3,4) << std::endl;
  std::cout << "2 + 2 = " << lazy_add(2,2) << std::endl;
  std::cout << "3 + 4 = " << lazy_add(3,4) << std::endl;

  std::cout << "discard_cached_result(2,2)" << std::endl;
  lazy_add.discard_cached_result(2,2);
  std::cout << "2 + 2 = " << lazy_add(2,2) << std::endl;
  std::cout << "3 + 4 = " << lazy_add(3,4) << std::endl;

  return 0;
}
// [Program]

/** [Output]
2 + 2 = (computing sum...) 4
3 + 4 = (computing sum...) 7
2 + 2 = 4
3 + 4 = 7
discard_cached_result(2,2)
2 + 2 = (computing sum...) 4
3 + 4 = 7
 *  [Output] */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
