// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/query_platform_info1.cpp {{{
 * \file clxx/query_platform_info1.cpp
 * \brief Usage example for clxx::query_platform_info()
 */ // }}}
/** // doc: query_platform_info1.cpp {{{
 * \example clxx/query_platform_info1.cpp
 * \brief Usage example for \ref clxx::query_platform_info()
 */ // }}}

// [Program]
#include <clxx/platforms.hpp>
#include <clxx/io/platform_info.hpp>
#include <iostream>

/// main function
int main()
{
  using namespace clxx;
  platforms ps{get_platforms()};
  if(!ps.empty())
    {
      // print platform info for first OpenCL platform found
      std::cout << query_platform_info(ps[0]) << std::endl;
    }
  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
