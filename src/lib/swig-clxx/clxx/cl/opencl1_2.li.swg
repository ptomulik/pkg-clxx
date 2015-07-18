// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

%import <clxx/config.h>
%import <clxx/common/config.hpp>

#if CLXX_CL_H_VERSION_1_2

%{
#include <CL/cl.h>
%}

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
// present in 1.0 and 1.1 but not in 1.2
%ignore clSetCommandQueueProperty;
// present in 1.1 but not in 1.2
%ignore clCreateSubDevicesEXT;
%ignore clReleaseDeviceEXT;
%ignore clRetainDeviceEXT;
//
%include <stdint.i>
%include <CL/cl_platform.h>
%include <CL/cl.h>

#endif

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
