// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

#include <clxx/app/clcc/main.hpp>
#include <exception>
#include <iostream>

int main(int argc, char const* argv[])
{
  try
    {
      return clxx::app::clcc::run(argc, argv);
    }
  catch(std::exception const& e)
    {
      std::cerr << "error: " << e.what() << std::endl;
    }
  catch(...)
    {
      std::cerr << "error: caught unhandled exception" << std::endl;
    }
  return EXIT_FAILURE;
}
