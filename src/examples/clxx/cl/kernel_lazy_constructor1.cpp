// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/kernel_lazy_constructor1.cpp {{{
 * \file clxx/cl/kernel_lazy_constructor1.cpp
 * \brief Usage example for \ref clxx::kernel_lazy_constructor
 */ // }}}
/** // doc: clxx/cl/kernel_lazy_constructor1.cpp {{{
 * \example clxx/cl/kernel_lazy_constructor1.cpp
 * \brief Usage example for \ref clxx::kernel_lazy_constructor
 */ // }}}

// [Program]
#include <clxx/cl/kernel_lazy_constructor.hpp>
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/context.hpp>
#include <iostream>

/// Main function
int main() 
{
  std::string                     source    { "__kernel void trivial() { }\n" };
  clxx::platforms                 platforms { clxx::get_platforms() };
  clxx::platform                  platform  { platforms[0] };
  clxx::context                   context   { make_context_properties(platform), clxx::device_type_t::all };
  clxx::program                   program   ( context, clxx::program_sources { source } );
  clxx::devices                   devices   { program.get_devices()[0] };

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

  clxx::kernel_lazy_constructor   lazy_kernel_constructor;
  clxx::kernel                    kernel1, kernel2;
  clxx::kernel                    kernel3, kernel4;
  clxx::kernel                    kernel5;
  
  // Here the clxx::create_kernel() is invoked
  kernel1 = lazy_kernel_constructor(program, "trivial");
  // Here a memoized kernel is returned
  kernel2 = lazy_kernel_constructor(program, "trivial");
  // Remove the kernel from cache
  lazy_kernel_constructor.discard_cached_kernel(program, "trivial");
  // New kernel object will be created as the old one was discarded
  kernel3 = lazy_kernel_constructor(program, "trivial");
  // For comparison - each call creates new kernel object
  kernel4 = clxx::kernel(program, "trivial");
  kernel5 = clxx::kernel(program, "trivial");

  std::cout << std::boolalpha << "kernel1 == kernel2 : " << (kernel1 == kernel2) << std::endl;
  std::cout << std::boolalpha << "kernel1 == kernel3 : " << (kernel1 == kernel3) << std::endl;
  std::cout << std::boolalpha << "kernel4 == kernel5 : " << (kernel4 == kernel5) << std::endl;


  return 0;
}
// [Program]

/* [Output]
building the OpenCL program... done.
kernel1 == kernel2 : true
kernel1 == kernel3 : false
kernel4 == kernel5 : false
 * [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
