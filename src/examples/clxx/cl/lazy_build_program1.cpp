// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/lazy_build_program1.cpp {{{
 * \file clxx/cl/lazy_build_program1.cpp
 * \brief Usage example for \ref clxx::lazy_build_program() "lazy_build_program()"
 */ // }}}
/** // doc: clxx/cl/lazy_build_program1.cpp {{{
 * \example clxx/cl/lazy_build_program1.cpp
 * \brief Usage example for \ref clxx::lazy_build_program() "lazy_build_program()"
 */ // }}}

// [Program]
#include <clxx/cl/program_lazy_fcn.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/device.hpp>
#include <clxx/cl/devices.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/common/exceptions.hpp>
#include <ctime>

/// Number of kernels to be generated and compiled in this example
#define NUM_KERNELS 2000

/// Generate large source for this experiment
void
generate_large_source(std::string& source)
{
  // generate "complex" source
  std::cout << "generating large OpenCL program source (" << NUM_KERNELS << " kernels)... ";
  std::flush(std::cout);
  source.reserve(32 * NUM_KERNELS);
  for(size_t i = 0; i < NUM_KERNELS; ++i)
    source.append("__kernel void trivial" + std::to_string(i) + "(){}\n");
  std::cout << "done" << std::endl;
}

/// Build program with lazy_build_program() and measure build time
void
call_lazy_build_program(clxx::program const& program, std::string const& options)
{
  std::clock_t begin, end;
  std::cout << "invoking lazy_build_program(program, \"" << options << "\") ... ";
  std::flush(std::cout);
  begin = std::clock();
  clxx::lazy_build_program(program, options);
  end = std::clock();
  std::cout << "done in " << (end - begin)/(double)CLOCKS_PER_SEC << " seconds" << std::endl;
}

/// Main function
int main() 
{
  std::string source;
  generate_large_source(source);

  clxx::platforms platforms { clxx::get_platforms() };
  clxx::platform  platform  { platforms[0] };
  clxx::context   context   { make_context_properties(platform), clxx::device_type_t::all };
  clxx::program   program   ( context, clxx::program_sources { source } );
  clxx::devices   devices   { program.get_devices() };

  call_lazy_build_program(program, "");
  call_lazy_build_program(program, "");
  call_lazy_build_program(program, "-cl-opt-disable");

  return 0;
}
// [Program]

/* [Output]
generating large OpenCL program source (2000 kernels)... done
invoking lazy_build_program(program, "") ... done in 5.8595 seconds
invoking lazy_build_program(program, "") ... done in 1.1e-05 seconds
invoking lazy_build_program(program, "-cl-opt-disable") ... done in 4.87581 seconds
 * [Output] */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
