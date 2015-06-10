// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/unit.hpp

/** // doc: clxx/unit.hpp {{{
 * \file clxx/unit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CONFIG_HPP_INCLUDED
#define CLXX_CONFIG_HPP_INCLUDED

#include <clxx/config.h>

// #define CLXX_USE_DEPRECATED_clCompileProgram
#define CLXX_USE_DEPRECATED_clCreateCommandQueue
// #define CLXX_USE_DEPRECATED_clCreateCommandQueueWithProperties
// #define CLXX_USE_DEPRECATED_clCreateProgramWithBuiltInKernels
// #define CLXX_USE_DEPRECATED_clCreateSubDevices
// #define CLXX_USE_DEPRECATED_clLinkProgram
// #define CLXX_USE_DEPRECATED_clReleaseDevice
// #define CLXX_USE_DEPRECATED_clRetainDevice
// #define CLXX_USE_DEPRECATED_clUnloadPlatformCompiler

#define CLXX_OPENCL_PROVIDES(fun) (defined(CLXX_IS_DECLARED_ ## fun) && defined(CLXX_IS_LINKABLE_ ## fun))
#define CLXX_OPENCL_UNDEPRECATED(fun) (!defined (CLXX_IS_DEPRECATED_ ## fun) || defined (CLXX_USE_DEPRECATED_ ## fun))
#define CLXX_OPENCL_ALLOWED(fun) CLXX_OPENCL_PROVIDES(fun) && CLXX_OPENCL_UNDEPRECATED(fun)


#if defined(__clang__)
# define CLXX_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
# define CLXX_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
# define CLXX_UNDEPRECATE _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
#elif defined(__GNUC__)
# define CLXX_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
# define CLXX_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
# define CLXX_UNDEPRECATE _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif defined(SWIG)
# define CLXX_DIAGNOSTIC_PUSH
# define CLXX_DIAGNOSTIC_POP
# define CLXX_UNDEPRECATE
#endif

#endif /* CLXX_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
