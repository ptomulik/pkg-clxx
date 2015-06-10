// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/**
 * Swig wrapper for OpenCL 1.0.
 *
 * Important: we ignore all functions that are konwn to be present in 1.2 but
 * not in 1.0. This is necessary to avoid unresolved symbols when using the
 * binding. It's common that Linux distros provide OpenCL 1.2 headers but the
 * library is only 1.0. By restricting ourselves to 1.0 here we guarantee that
 * our binding will still work with older shared libraries.
 */
%import <clxx/config.h>
%import <clxx/config.hpp>

#if HAVE_OPENCL_CL_H_VERSION_1_0
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
//
// These functions are present in 1.2 but not in 1.0
//
%ignore clCompileProgram;
%ignore clCreateEventFromEGLSyncKHR;
%ignore clCreateEventFromGLsyncKHR;
%ignore clCreateFromEGLImageKHR;
%ignore clCreateFromGLTexture;
%ignore clCreateImage;
%ignore clCreateProgramWithBuiltInKernels;
%ignore clCreateSubBuffer;
%ignore clCreateSubDevices;
%ignore clCreateSubDevicesEXT;
%ignore clCreateUserEvent;
%ignore clEnqueueAcquireEGLObjectsKHR;
%ignore clEnqueueBarrierWithWaitList;
%ignore clEnqueueCopyBufferRect;
%ignore clEnqueueFillBuffer;
%ignore clEnqueueFillImage;
%ignore clEnqueueMarkerWithWaitList;
%ignore clEnqueueMigrateMemObjects;
%ignore clEnqueueReadBufferRect;
%ignore clEnqueueReleaseEGLObjectsKHR;
%ignore clEnqueueWriteBufferRect;
%ignore clGetContextInfo;
%ignore clGetDeviceImageInfoQCOM;
%ignore clGetDeviceInfo;
%ignore clGetExtensionFunctionAddress;
%ignore clGetExtensionFunctionAddressForPlatform;
%ignore clGetExtensionFunctionAddressForPlatform;
%ignore clGetKernelArgInfo;
%ignore clGetPlatformInfo;
%ignore clIcdGetPlatformIDsKHR;
%ignore clLinkProgram;
%ignore clReleaseDevice;
%ignore clReleaseDeviceEXT;
%ignore clRetainDevice;
%ignore clRetainDeviceEXT;
%ignore clSetEventCallback;
%ignore clSetMemObjectDestructorCallback;
%ignore clSetUserEventStatus;
%ignore clUnloadPlatformCompiler;
//
%include <stdint.i>
%include <CL/cl_platform.h>
%include <CL/cl.h>
#endif

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
