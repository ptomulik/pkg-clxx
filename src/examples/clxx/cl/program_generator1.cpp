// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_generator1.cpp {{{
 * \file clxx/cl/program_generator1.cpp
 * \brief Usage example for \ref clxx::program_generator
 */ // }}}
/** // doc: clxx/cl/program_generator1.cpp {{{
 * \example clxx/cl/program_generator1.cpp
 * \brief Usage example for \ref clxx::program_generator
 */ // }}}

// [Program]
#include <clxx/cl/program_generator.hpp>
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/program_fcn.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/devices.hpp>
#include <clxx/cl/device.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/io/types.hpp>
#include <iostream>

namespace clxx {
/// \brief A trivial program generator (with a single empty kernel)
class trivial_program
  : public clxx::program_generator
{
  std::string program_path(clxx::context const&) const { return "clxx/trivial_program.cl"; }
  void generate_program_source(std::string& src, clxx::context const& c) const
  {
    src.append(this->line_directive(c, 1)); src.append("\n");
    src.append("__kernel void trivial() { }\n");
  }
};
}

/// Main function
int main() 
{
  clxx::platforms                 platforms { clxx::get_platforms() };
  clxx::platform                  platform  { platforms[0] };
  clxx::context                   context   { make_context_properties(platform), clxx::device_type_t::all };
  clxx::program_generator const&  generator = clxx::trivial_program();
  clxx::program                   program   { generator.get_program(context) };
  clxx::devices                   devices   { program.get_devices()[0] };

  // Print some characteristics
  std::cout << "program path  : " << generator.program_path(context) << std::endl;
  std::cout << "================================= SOURCE ======================" << std::endl;
  std::cout << program.get_source() << std::endl;
  std::cout << "=================================  INFO  ======================" << std::endl;
  std::cout << "build status  : " << program.get_build_status(devices[0]) << std::endl;
  std::cout << "===============================================================" << std::endl;

  // Build the program
  std::cout << "building the OpenCL program... ";
  try {
    clxx::build_program(program, devices, "");
    std::cout << "done." << std::endl;
  } catch(clxx::clerror_no<clxx::status_t::build_program_failure> const&) {
    std::cout << "failed." << std::endl;
    std::cerr << program.get_build_log(devices[0]) << std::endl;
    return 1;
  }

  std::cout << "=================================  INFO  ======================" << std::endl;
  std::cout << "build status  : " << program.get_build_status(devices[0]) << std::endl;
  std::cout << "build options : " << program.get_build_options(devices[0]) << std::endl;

  return 0;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
