// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

%{
#include <CL/cl.h>
%}

%import <clxx/config.h>
%import <clxx/config.hpp>
/* XXX: This is necessary for "stdint.i" to choose proper declaration of intptr_t
 *      which is used in turn by CL/cl.h */
#ifdef CLXX_ARCH_64BIT
#  define SWIGWORDSIZE64
#else
#  define SWIGWORDSIZE32
#endif
#define __attribute__(x)
#define __extension__
/* not usable */
%ignore clSetPrintfCallback;
/* deprecated */
%ignore clEnqueueMarker;
%ignore clEnqueueWaitForEvents;
%ignore clEnqueueBarrier;
%ignore clUnloadCompiler;
%ignore clGetExtensionFunctionAddress;
%ignore clCreateImage2D;
%ignore clCreateImage3D;
%include <stdint.i>
%include <CL/cl_platform.h>
%include <CL/cl.h>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
