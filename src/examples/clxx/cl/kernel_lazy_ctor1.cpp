// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/kernel_lazy_ctor1.cpp {{{
 * \file clxx/cl/kernel_lazy_ctor1.cpp
 * \brief Usage example for \ref clxx::kernel_lazy_ctor
 */ // }}}
/** // doc: clxx/cl/kernel_lazy_ctor1.cpp {{{
 * \example clxx/cl/kernel_lazy_ctor1.cpp
 * \brief Usage example for \ref clxx::kernel_lazy_ctor
 */ // }}}

// [Program]
#include <clxx/cl/kernel_lazy_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/program_fcn.hpp>
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/device.hpp>
#include <clxx/cl/devices.hpp>
#include <clxx/cl/context.hpp>
#include <iostream>

/// Main function
int main() 
{
  std::string     source    { "__kernel void mykernel() { }\n" };
  clxx::platforms platforms { clxx::get_platforms() };
  clxx::platform  platform  { platforms[0] };
  clxx::context   context   { make_context_properties(platform), clxx::device_type_t::all };
  clxx::program   program   { context, clxx::program_sources { source } };
  clxx::devices   devices   { program.get_devices()[0] };

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

  clxx::kernel            kernel1, kernel2;
  clxx::kernel            kernel3, kernel4;
  clxx::kernel            kernel5;

  // [LazyKernelDemo]
  clxx::kernel_lazy_ctor  lazy_kernel;
  // Here the clxx::create_kernel() is invoked
  kernel1 = lazy_kernel(program, "mykernel");
  // Here a memoized kernel is returned
  kernel2 = lazy_kernel(program, "mykernel");
  // Remove the kernel from cache
  lazy_kernel.discard_memoized_kernel(program, "mykernel");
  // New kernel object will be created as the old one was discarded
  kernel3 = lazy_kernel(program, "mykernel");
  // [LazyKernelDemo]
  // For comparison - each call creates new kernel object
  kernel4 = clxx::kernel(program, "mykernel");
  kernel5 = clxx::kernel(program, "mykernel");

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
