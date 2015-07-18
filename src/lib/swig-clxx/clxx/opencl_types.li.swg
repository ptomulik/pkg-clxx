// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/opencl_types.li.swg {{
 * \file clxx/opencl_types.li.swg
 * \todo Write documentation
 */ // }}}

%import <clxx/config.h>
%import <clxx/config.hpp>

%{
#include <CL/cl_platform.h>
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

%include <stdint.i>
%include <CL/cl_platform.h>
%rename("$ignore",%$isfunction) "";
%include <CL/cl.h>
%rename("%s",%$isfunction) "";

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
