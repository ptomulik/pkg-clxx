// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/config.hpp

/** // doc: clxx/config.hpp {{{
 * \file clxx/config.hpp
 * \brief Configuration and preprocessor macros used across clxx project
 */ // }}}
#ifndef CLXX_CONFIG_HPP_INCLUDED
#define CLXX_CONFIG_HPP_INCLUDED

#include <clxx/config.h>

// #define CLXX_USE_DEPRECATED_clCompileProgram
/** // doc: CLXX_USE_DEPRECATED_clCreateDommandQueue {{{
 * \brief Use the \c clCreateCommandQueue() even if it's marked as deprecated
 */ // }}}
#define CLXX_USE_DEPRECATED_clCreateCommandQueue
// #define CLXX_USE_DEPRECATED_clCreateCommandQueueWithProperties
// #define CLXX_USE_DEPRECATED_clCreateProgramWithBuiltInKernels
// #define CLXX_USE_DEPRECATED_clCreateSubDevices
// #define CLXX_USE_DEPRECATED_clLinkProgram
// #define CLXX_USE_DEPRECATED_clReleaseDevice
// #define CLXX_USE_DEPRECATED_clRetainDevice
// #define CLXX_USE_DEPRECATED_clUnloadPlatformCompiler
// #define CLXX_USE_DEPRECATED_clGetKernelArgInfo
// #define CLXX_USE_DEPRECATED_clSetKernelArgSVMPointer
// #define CLXX_USE_DEPRECATED_clSetKernelExecInfo

/** // doc: CLXX_OPENCL_PROVIDES {{{
 * \todo Write documentation
 */ // }}}
#define CLXX_OPENCL_PROVIDES(fun) (defined(CLXX_IS_DECLARED_ ## fun) \
                                && defined(CLXX_IS_LINKABLE_ ## fun))
/** // doc: CLXX_OPENCL_UNDEPRECATED {{{
 * \brief Whether the function \em fun is deprecated or not
 *
 * Evaluates to true if \em fun is marked as deprecated, and there is no
 * preprocessor macro <tt>CLXX_USE_DEPRECATED_<fun></tt> defined.
 */ // }}}
#define CLXX_OPENCL_DEPRECATED(fun) (defined (CLXX_IS_DEPRECATED_ ## fun) \
                                 && !defined (CLXX_USE_DEPRECATED_ ## fun))

/** // doc: CLXX_OPENCL_ALLOWED {{{
 * \brief Is it allowed to use given OpenCL function?
 *
 * For some "suspicious" OpenCL functions determines whether the config phase
 * decided to allow the given function to be used.
 *
 * Some OpenCL functions appear and disappear (being deprecated in the
 * meantime) between versions of the OpenCL standard. We call them "suspicious"
 * functions here. Several check are performed at the configuration phase, for
 * example checking the function presence in <tt>CL/cl.h</tt> header file and
 * in <tt>libOpenCL</tt> library and finally decide whether to allow or deny
 * usage of the function in clxx (especially we can't try to use a function
 * that has gone away and is absent in the library). This macro returns what
 * was the decision that was made during the configuration phase.
 */ // }}}
#define CLXX_OPENCL_ALLOWED(fun) CLXX_OPENCL_PROVIDES(fun) && !CLXX_OPENCL_DEPRECATED(fun)


#if defined(__clang__)
# define CLXX_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
# define CLXX_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
# define CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
#elif defined(__GNUC__)
# define CLXX_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
# define CLXX_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
# define CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif defined(SWIG) || defined(DOXYGEN)
/** // doc: CLXX_DIAGNOSTIC_PUSH {{{
 * \brief Push the configuration of compiler diagnostics
 *
 * This usually is defined as an appropriate \c pragma directive which pushes
 * settings such as warning verbosity, enabled/disabled compiler diagnostics
 * etc., such that they can be later restored.
 *
 * For example, if GCC is used, then it's defined as _Pragma("GCC diagnostic push")
 */ // }}}
# define CLXX_DIAGNOSTIC_PUSH
/** // doc: CLXX_DIAGNOSTIC_POP {{{
 * \brief Pop the configuration of compiler diagnostics
 *
 * This usually is defined as an appropriate \c pragma directive which restores
 * settings such as warning verbosity, enabled/disabled compiler diagnostics
 * etc., previously pushed with \ref CLXX_DIAGNOSTIC_PUSH.
 *
 * For example, if GCC is used, then it's defined as _Pragma("GCC diagnostic pop")
 */ // }}}
# define CLXX_DIAGNOSTIC_POP
/** // doc: CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING {{{
 * \brief Disable "deprecated declaration"
 *
 * This disables warnings normally triggered by a compiler when a deprecated
 * function or other compound is used in code. For example, in gcc a function
 * with <tt>__attribute((deprecated))__</tt> would yield such warning (\c
 * -Wdeprecated-declaration), and it may be disabled with
 *  CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING (which, in this case, equals to
 *  _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")).
 */ // }}}
# define CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING
#endif

#endif /* CLXX_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
