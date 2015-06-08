// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/mocks/dummy.hpp

/** // doc: clxx/cl/mocks/dummy.hpp {{{
 * \file clxx/cl/mocks/dummy.hpp
 *
 * This file implements OpenCL mocks emulating several dummy cases, such as
 * memory allocation errors.
 *
 * The implementation is created only when the \c CXXTEST_MOCK_TEST_SOURCE_FILE
 * constant is defined,
 *
 */ // }}}
#ifndef CLXX_CL_MOCKS_DUMMY_HPP_INCLUDED
#define CLXX_CL_MOCKS_DUMMY_HPP_INCLUDED

/* Mock class declarations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE) || defined(CXXTEST_FLAGS) \
  || defined(CXXTEST_RUNNING) || defined(DOXYGEN)

#include <tuple>
#include <vector>
#include <cstring>

namespace T {
/** // doc: Dummy_CallArgs {{{
 * \todo Write documentation
 */ // }}}
template<class... Args>
class Dummy_CallArgs
{
public:
  /** // doc: args_tuple {{{
   * \todo Write documentation
   */ // }}}
  typedef std::tuple<Args...> args_tuple;
  /** // doc: reset() {{{
   * \todo Write documentation
   */ // }}}
  inline void reset() { _calls.clear(); }

  // return the calls
  /** // doc: () {{{
   * \todo Write documentation
   */ // }}}
  inline std::vector<args_tuple> const& calls() const { return _calls; }

  // mock tests
  /** // doc: never_called() {{{
   * \todo Write documentation
   */ // }}}
  inline bool never_called() const noexcept
  { return _calls.size() == 0ul; }
  /** // doc: called_once() {{{
   * \todo Write documentation
   */ // }}}
  inline bool called_once() const noexcept
  { return _calls.size() == 1ul; }
  /** // doc: called_twice() {{{
   * \todo Write documentation
   */ // }}}
  inline bool called_twice() const noexcept
  { return _calls.size() == 2ul; }
  /** // doc: called_three_times() {{{
   * \todo Write documentation
   */ // }}}
  inline bool called_three_times() const noexcept
  { return _calls.size() == 3ul; }
  /** // doc: called_four_times() {{{
   * \todo Write documentation
   */ // }}}
  inline bool called_four_times() const noexcept
  { return _calls.size() == 3ul; }
  /** // doc: called_n_times() {{{
   * \todo Write documentation
   */ // }}}
  inline bool called_n_times(unsigned long n) const noexcept
  { return _calls.size() == n; }
  /** // doc: last_called_with() {{{
   * \todo Write documentation
   */ // }}}
  inline bool last_called_with(Args... args) const
  { return (_calls.back() == args_tuple(args...)); }
  /** // doc: caled_once_with() {{{
   * \todo Write documentation
   */ // }}}
  inline bool called_once_with(Args... args) const
  { return called_once() && last_called_with(args...); }
protected:
  /** // doc: call_with(args) {{{
   * \todo Write documentation
   */ // }}}
  inline void call_with(Args... args)
  {
    _calls.push_back(args_tuple(args...));
  }
  /** // doc: call_with(args) {{{
   * \todo Write documentation
   */ // }}}
  std::vector<args_tuple> _calls;
};

/** // doc: Dummy_clGetPlatformIDs {{{
 * \brief Mock for clGetPlatformIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class Dummy_clGetPlatformIDs
  : public T::Base_clGetPlatformIDs,
    public T::Dummy_CallArgs<cl_uint, cl_platform_id*, cl_uint*>
{
  cl_int _err;
  cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                          cl_uint* num_platforms);
public:
  /** // doc: Dummy_clGetPlatformIDs() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetPlatformIDs(cl_int err);
};
/** // doc: Dummy_clGetPlatformInfo {{{
 * \brief Mock for clGetPlatformInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo,
    public T::Dummy_CallArgs<cl_platform_id, cl_platform_info, size_t, void*, size_t*>
{
  cl_int _err;
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetPlatformInfo() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetPlatformInfo(cl_int err);
};
/** // doc: Dummy_clGetDeviceIDs {{{
 * \brief Mock for clGetDeviceIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class Dummy_clGetDeviceIDs
  : public T::Base_clGetDeviceIDs,
    public T::Dummy_CallArgs<cl_platform_id, cl_device_type, cl_uint, cl_device_id*, cl_uint*>
{
  cl_int _err;
  cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
                        cl_uint num_entries, cl_device_id* devices,
                        cl_uint* num_devices);
public:
  /** // doc: Dummy_clGetDeviceIDs() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetDeviceIDs(cl_int err);
};
/** // doc: Dummy_clGetDeviceInfo {{{
 * \brief Mock for clGetDeviceInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo,
    public T::Dummy_CallArgs<cl_device_id, cl_device_info, size_t, void*, size_t*>
{
  cl_int _err;
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetDeviceInfo() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetDeviceInfo(cl_int err);
};
/** // doc: Dummy_clCreateContext {{{
 * \brief Default mock for clCreateContext OpenCL function.
 */ // }}}
class Dummy_clCreateContext
  : public T::Base_clCreateContext,
    public T::Dummy_CallArgs< const cl_context_properties*, cl_uint, const cl_device_id*,
                            void(CL_CALLBACK*)(const char*,const void*, size_t, void*),
                            void*, cl_int*>
{
  cl_context _ctx;
  cl_int _err;
  cl_context clCreateContext(
      const cl_context_properties* properties, cl_uint num_devices,
      const cl_device_id* devices,
      void(CL_CALLBACK* pfn_notify)(const char*,const void*, size_t, void*),
      void* user_data,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateContext() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateContext(cl_context ctx, cl_int err);
};

/** // doc: Dummy_clCreateContextFromType {{{
 * \brief Default mock for clCreateContextFromType OpenCL function.
 */ // }}}
class Dummy_clCreateContextFromType
  : public T::Base_clCreateContextFromType,
    public T::Dummy_CallArgs< const cl_context_properties*, const cl_device_type,
                            void(CL_CALLBACK*)(const char*,const void*, size_t, void*),
                            void*, cl_int*>
{
  cl_context _ctx;
  cl_int _err;
  cl_context clCreateContextFromType(
      const cl_context_properties* properties,
      cl_device_type device_type,
      void(CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
      void* user_data,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateContextFromType() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateContextFromType(cl_context ctx, cl_int err);
};

/** // doc: Dummy_clRetainContext {{{
 * \brief Default mock for clRetainContext OpenCL function.
 */ // }}}
class Dummy_clRetainContext
  : public T::Base_clRetainContext,
    public T::Dummy_CallArgs<cl_context>
{
  cl_int _err;
  cl_int clRetainContext(cl_context);
public:
  /** // doc: Dummy_clRetainContext() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clRetainContext(cl_int err);
};

/** // doc: Dummy_clReleaseContext {{{
 * \brief Default mock for clReleaseContext OpenCL function.
 */ // }}}
class Dummy_clReleaseContext
  : public T::Base_clReleaseContext,
    public T::Dummy_CallArgs<cl_context>
{
  cl_int _err;
  cl_int clReleaseContext(cl_context);
public:
  /** // doc: Dummy_clReleaseContext() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clReleaseContext(cl_int err);
};
/** // doc: Dummy_clGetContextInfo {{{
 * \brief Default mock for clGetContextInfo OpenCL function.
 */ // }}}
class Dummy_clGetContextInfo
  : public T::Base_clGetContextInfo,
    public T::Dummy_CallArgs<cl_context,cl_context_info,size_t,void*,size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t _param_value_size_ret;
  cl_int clGetContextInfo(cl_context context, cl_context_info param_name,
                          size_t param_value_size, void* param_value,
                          size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetContextInfo() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetContextInfo(cl_int err, void* pv = nullptr, size_t pvs = 0);
};
#if HAVE_OPENCL_clCreateSubDevices
/** // doc: Dummy_clCreateSubDevices {{{
 * \brief Default mock for clCreateSubDevices OpenCL function.
 */ // }}}
class Dummy_clCreateSubDevices
  : public T::Base_clCreateSubDevices,
    public T::Dummy_CallArgs<cl_device_id,const cl_device_partition_property*,cl_uint,cl_device_id*,cl_uint*>
{
  cl_int _err;
  cl_device_id const* _out_devices;
  cl_uint const* _num_devices_ret;
  cl_int clCreateSubDevices(cl_device_id in_device,
                            const cl_device_partition_property* properties,
                            cl_uint num_devices,
                            cl_device_id* out_devices,
                            cl_uint* num_devices_ret);
public:
  /** // doc: Dummy_clCreateSubDevices() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateSubDevices(cl_int err, cl_device_id const* out_devices = nullptr, cl_uint const* num_devices_ret = nullptr);
};
#endif
#if HAVE_OPENCL_clRetainDevice
/** // doc: Dummy_clRetainDevice {{{
 * \brief Default mock for clRetainDevice OpenCL function.
 */ // }}}
class Dummy_clRetainDevice
  : public T::Base_clRetainDevice,
    public T::Dummy_CallArgs<cl_device_id>
{
  cl_int _err;
  cl_int clRetainDevice(cl_device_id device);
public:
  /** // doc: Dummy_clRetainDevice() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clRetainDevice(cl_int err);
};
#endif
#if HAVE_OPENCL_clReleaseDevice
/** // doc: Dummy_clReleaseDevice {{{
 * \brief Default mock for clReleaseDevice OpenCL function.
 */ // }}}
class Dummy_clReleaseDevice
  : public T::Base_clReleaseDevice,
    public T::Dummy_CallArgs<cl_device_id>
{
  cl_int _err;
  cl_int clReleaseDevice(cl_device_id device);
public:
  /** // doc: Dummy_clReleaseDevice() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clReleaseDevice(cl_int err);
};
#endif
#if HAVE_OPENCL_clCreateCommandQueue
/** // doc: Dummy_clCreateCommandQueue {{{
 * \brief Default mock for clCreateCommandQueue OpenCL function.
 */ // }}}
class Dummy_clCreateCommandQueue
  : public T::Base_clCreateCommandQueue,
    public T::Dummy_CallArgs<cl_context, cl_device_id,
                             cl_command_queue_properties, cl_int*>
{
  cl_command_queue _ctx;
  cl_int _err;
  cl_command_queue clCreateCommandQueue(
      cl_context context,
      cl_device_id device,
      cl_command_queue_properties properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateCommandQueue() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateCommandQueue(cl_command_queue ctx, cl_int err);
};
#endif
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
/** // doc: Dummy_clCreateCommandQueueWithProperties {{{
 * \brief Default mock for clCreateCommandQueueWithProperties OpenCL function.
 */ // }}}
class Dummy_clCreateCommandQueueWithProperties
  : public T::Base_clCreateCommandQueueWithProperties,
    public T::Dummy_CallArgs<cl_context, cl_device_id,
                             const cl_queue_properties*, cl_int*>
{
  cl_command_queue _ctx;
  cl_int _err;
  cl_command_queue clCreateCommandQueueWithProperties(
      cl_context context,
      cl_device_id device,
      const cl_queue_properties* properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateCommandQueueWithProperties() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateCommandQueueWithProperties(cl_command_queue ctx, cl_int err);
};
#endif
/** // doc: Dummy_clRetainCommandQueue {{{
 * \brief Default mock for clRetainCommandQueue OpenCL function.
 */ // }}}
class Dummy_clRetainCommandQueue
  : public T::Base_clRetainCommandQueue,
    public T::Dummy_CallArgs<cl_command_queue>
{
  cl_int _err;
  cl_int clRetainCommandQueue(cl_command_queue);
public:
  /** // doc: Dummy_clRetainCommandQueue() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clRetainCommandQueue(cl_int err);
};

/** // doc: Dummy_clReleaseCommandQueue {{{
 * \brief Default mock for clReleaseCommandQueue OpenCL function.
 */ // }}}
class Dummy_clReleaseCommandQueue
  : public T::Base_clReleaseCommandQueue,
    public T::Dummy_CallArgs<cl_command_queue>
{
  cl_int _err;
  cl_int clReleaseCommandQueue(cl_command_queue);
public:
  /** // doc: Dummy_clReleaseCommandQueue() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clReleaseCommandQueue(cl_int err);
};
/** // doc: Dummy_clGetCommandQueueInfo {{{
 * \brief Default mock for clGetCommandQueueInfo OpenCL function.
 */ // }}}
class Dummy_clGetCommandQueueInfo
  : public T::Base_clGetCommandQueueInfo,
    public T::Dummy_CallArgs<cl_command_queue,cl_command_queue_info,size_t,void*,size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t _param_value_size_ret;
  cl_int clGetCommandQueueInfo(cl_command_queue command_queue,
                               cl_command_queue_info param_name,
                               size_t param_value_size, void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetCommandQueueInfo() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetCommandQueueInfo(cl_int err, void* pv = nullptr, size_t pvs = 0);
};
/** // doc: Dummy_clCreateProgramWithSource {{{
 * \brief Default mock for clCreateProgramWithSource OpenCL function.
 */ // }}}
class Dummy_clCreateProgramWithSource
  : public T::Base_clCreateProgramWithSource,
    public T::Dummy_CallArgs<cl_context, cl_uint, const char**, const size_t*, cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clCreateProgramWithSource(cl_context context,
                                       cl_uint count,
                                       const char** strings,
                                       const size_t* lengths,
                                       cl_int* errcode_ret);
public:
  /** // doc: Dummy_clCreateProgramWithSource() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateProgramWithSource(cl_program program, cl_int err);
};
/** // doc: Dummy_clCreateProgramWithBinary {{{
 * \brief Default mock for clCreateProgramWithBinary OpenCL function.
 */ // }}}
class Dummy_clCreateProgramWithBinary
  : public T::Base_clCreateProgramWithBinary,
    public T::Dummy_CallArgs<cl_context, cl_uint, const cl_device_id*,
                              const size_t*, const unsigned char**, cl_int*,
                              cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clCreateProgramWithBinary(cl_context context,
                                       cl_uint num_devices,
                                       const cl_device_id* device_list,
                                       const size_t* lengths,
                                       const unsigned char** binaries,
                                       cl_int* binary_status,
                                       cl_int* errcode_ret);
public:
  /** // doc: Dummy_clCreateProgramWithBinary() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateProgramWithBinary(cl_program program, cl_int err);
};
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
/** // doc: Dummy_clCreateProgramWithBuiltInKernels {{{
 * \brief Default mock for clCreateProgramWithBuiltInKernels OpenCL function.
 */ // }}}
class Dummy_clCreateProgramWithBuiltInKernels
  : public T::Base_clCreateProgramWithBuiltInKernels,
    public T::Dummy_CallArgs<cl_context, cl_uint, const cl_device_id*,
                              const char*, cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clCreateProgramWithBuiltInKernels(cl_context context,
                                               cl_uint num_devices,
                                               const cl_device_id* device_list,
                                               const char* kernel_names,
                                               cl_int* errcode_ret);
public:
  /** // doc: Dummy_clCreateProgramWithBuiltInKernels() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCreateProgramWithBuiltInKernels(cl_program program, cl_int err);
};
#endif
/** // doc: Dummy_clRetainProgram {{{
 * \brief Default mock for clRetainProgram OpenCL function.
 */ // }}}
class Dummy_clRetainProgram
  : public T::Base_clRetainProgram,
    public T::Dummy_CallArgs<cl_program>
{
  cl_int _err;
  cl_int clRetainProgram(cl_program program);
public:
  /** // doc: Dummy_clRetainProgram() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clRetainProgram(cl_int err);
};
/** // doc: Dummy_clReleaseProgram {{{
 * \brief Default mock for clReleaseProgram OpenCL function.
 */ // }}}
class Dummy_clReleaseProgram
  : public T::Base_clReleaseProgram,
    public T::Dummy_CallArgs<cl_program>
{
  cl_int _err;
  cl_int clReleaseProgram(cl_program program);
public:
  /** // doc: Dummy_clReleaseProgram() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clReleaseProgram(cl_int err);
};
/** // doc: Dummy_clBuildProgram {{{
 * \brief Default mock for clBuildProgram OpenCL function.
 */ // }}}
class Dummy_clBuildProgram
  : public T::Base_clBuildProgram,
    public T::Dummy_CallArgs<cl_program, cl_uint, const cl_device_id*, const char*,
                              void (CL_CALLBACK*)(cl_program, void*), void*>
{
  cl_int _err;
  cl_int clBuildProgram(cl_program program,
                        cl_uint num_devices,
                        const cl_device_id* device_list,
                        const char* options,
                        void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                        void* user_data);
public:
  /** // doc: Dummy_clBuildProgram() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clBuildProgram(cl_int err);
};
#if HAVE_OPENCL_clCompileProgram
/** // doc: Dummy_clCompileProgram {{{
 * \brief Default mock for clCompileProgram OpenCL function.
 */ // }}}
class Dummy_clCompileProgram
  : public T::Base_clCompileProgram,
    public T::Dummy_CallArgs<cl_program, cl_uint, const cl_device_id*, const char*,
                             cl_uint, const cl_program*, const char**,
                             void (CL_CALLBACK*)(cl_program, void*), void*>
{
  cl_int _err;
  cl_int clCompileProgram(cl_program program,
                        cl_uint num_devices,
                        const cl_device_id* device_list,
                        const char* options,
                        cl_uint num_input_headers,
                        const cl_program* input_headers,
                        const char** header_include_names,
                        void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                        void* user_data);
public:
  /** // doc: Dummy_clCompileProgram() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clCompileProgram(cl_int err);
};
#endif
#if HAVE_OPENCL_clLinkProgram
/** // doc: Dummy_clLinkProgram {{{
 * \brief Default mock for clLinkProgram OpenCL function.
 */ // }}}
class Dummy_clLinkProgram
  : public T::Base_clLinkProgram,
    public T::Dummy_CallArgs<cl_context, cl_uint, const cl_device_id*,
                             const char*, cl_uint, const cl_program*,
                             void (CL_CALLBACK*)(cl_program, void*), void*,
                             cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clLinkProgram(cl_context context,
                           cl_uint num_devices,
                           const cl_device_id* device_list,
                           const char* options,
                           cl_uint num_input_programs,
                           const cl_program* input_programs,
                           void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                           void* user_data,
                           cl_int* errcode_ret);
public:
  /** // doc: Dummy_clLinkProgram() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clLinkProgram(cl_program program, cl_int err);
};
#endif
#if HAVE_OPENCL_clUnloadPlatformCompiler
/** // doc: Dummy_clUnloadPlatformCompiler {{{
 * \brief Default mock for clUnloadPlatformCompiler OpenCL function.
 */ // }}}
class Dummy_clUnloadPlatformCompiler
  : public T::Base_clUnloadPlatformCompiler,
    public T::Dummy_CallArgs<cl_platform_id>
{
  cl_int _err;
  cl_int clUnloadPlatformCompiler(cl_platform_id);
public:
  /** // doc: Dummy_clUnloadPlatformCompiler() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clUnloadPlatformCompiler(cl_int err);
};
#endif
/** // doc: Dummy_clGetProgramInfo {{{
 * \brief Mock for clGetProgramInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetProgramInfo
  : public T::Base_clGetProgramInfo,
    public T::Dummy_CallArgs<cl_program, cl_program_info, size_t, void*, size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t* _param_value_size_ret;
  cl_int clGetProgramInfo(cl_program program, cl_program_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetProgramInfo() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetProgramInfo(cl_int err, void* param_value = nullptr, size_t* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clGetProgramBuildInfo {{{
 * \brief Mock for clGetProgramBuildInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetProgramBuildInfo
  : public T::Base_clGetProgramBuildInfo,
    public T::Dummy_CallArgs<cl_program, cl_device_id, cl_program_build_info,
                             size_t, void*, size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t* _param_value_size_ret;
  cl_int clGetProgramBuildInfo(cl_program program,
                               cl_device_id device,
                               cl_program_build_info param_name,
                               size_t param_value_size,
                               void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetProgramBuildInfo() {{{
   * \todo Write documentation
   */ // }}}
  Dummy_clGetProgramBuildInfo(cl_int err, void* param_value = nullptr, size_t* param_value_size_ret = nullptr);
};
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE || ... */

/* Mock class implementations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE)
namespace T {
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetPlatformIDs::
clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                 cl_uint* num_platforms)
{
  call_with(num_entries, platforms, num_platforms);
  return _err;
}
Dummy_clGetPlatformIDs::
Dummy_clGetPlatformIDs(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  call_with(platform, param_name, param_value_size, param_value, param_value_size_ret);
  return _err;
}
Dummy_clGetPlatformInfo::
Dummy_clGetPlatformInfo(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetDeviceIDs::
clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices,
               cl_uint* num_devices)
{
  call_with(platform, device_type, num_entries, devices, num_devices);
  return _err;
}
Dummy_clGetDeviceIDs::
Dummy_clGetDeviceIDs(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(device, param_name, param_value_size, param_value, param_value_size_ret);
  return _err;
}

Dummy_clGetDeviceInfo::
Dummy_clGetDeviceInfo(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_context Dummy_clCreateContext::
clCreateContext(const cl_context_properties* properties,
                cl_uint num_devices,
                const cl_device_id* devices,
                void(CL_CALLBACK* pfn_notify)(const char*,const void*, size_t, void*),
                void* user_data,
                cl_int* errcode_ret)
{
  call_with(properties, num_devices, devices, pfn_notify, user_data, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_ctx;
}
Dummy_clCreateContext::
Dummy_clCreateContext(cl_context ctx, cl_int err)
  : _ctx(ctx), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_context Dummy_clCreateContextFromType::
clCreateContextFromType(const cl_context_properties* properties,
                        cl_device_type device_type,
                        void(CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
                        void* user_data,
                        cl_int* errcode_ret)
{
  call_with(properties, device_type, pfn_notify, user_data, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_ctx;
}
Dummy_clCreateContextFromType::
Dummy_clCreateContextFromType(cl_context ctx, cl_int err)
  : _ctx(ctx), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainContext::
clRetainContext(cl_context context)
{
  call_with(context);
  return _err;
}
Dummy_clRetainContext::
Dummy_clRetainContext(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseContext::
clReleaseContext(cl_context context)
{
  call_with(context);
  return _err;
}
Dummy_clReleaseContext::
Dummy_clReleaseContext(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetContextInfo::
clGetContextInfo(cl_context context, cl_context_info param_name,
                 size_t param_value_size, void* param_value,
                 size_t* param_value_size_ret)
{
  call_with(context, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value_size_ret) {
    *param_value_size_ret = _param_value_size_ret;
  }
  if(param_value && _param_value) {
    std::memcpy(param_value, _param_value, std::min(param_value_size, _param_value_size_ret));
  }
  return _err;
}
Dummy_clGetContextInfo::
Dummy_clGetContextInfo(cl_int err, void* pv, size_t pvs)
  : _err(err), _param_value(pv), _param_value_size_ret(pvs)
{
}
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clCreateSubDevices
cl_int Dummy_clCreateSubDevices::
clCreateSubDevices(cl_device_id in_device,
                   const cl_device_partition_property* properties,
                   cl_uint num_devices,
                   cl_device_id* out_devices,
                   cl_uint* num_devices_ret)
{
  call_with(in_device, properties, num_devices, out_devices, num_devices_ret);
  if(out_devices && _out_devices && _num_devices_ret)
    {
      std::memcpy(out_devices, _out_devices, std::min(num_devices, *_num_devices_ret) * sizeof(cl_device_id));
    }
  if(num_devices_ret && _num_devices_ret)
    {
      *num_devices_ret = *_num_devices_ret;
    }
  return _err;
}
Dummy_clCreateSubDevices::
Dummy_clCreateSubDevices(cl_int err, cl_device_id const* out_devices, cl_uint const* num_devices_ret)
  : _err(err), _out_devices(out_devices), _num_devices_ret(num_devices_ret)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clRetainDevice
cl_int Dummy_clRetainDevice::
clRetainDevice(cl_device_id device)
{
  call_with(device);
  return _err;
}
Dummy_clRetainDevice::
Dummy_clRetainDevice(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clReleaseDevice
cl_int Dummy_clReleaseDevice::
clReleaseDevice(cl_device_id device)
{
  call_with(device);
  return _err;
}
Dummy_clReleaseDevice::
Dummy_clReleaseDevice(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clCreateCommandQueue
cl_command_queue Dummy_clCreateCommandQueue::
clCreateCommandQueue(cl_context context, cl_device_id device,
                     cl_command_queue_properties properties,
                     cl_int* errcode_ret)
{
  call_with(context, device, properties, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_ctx;
}
Dummy_clCreateCommandQueue::
Dummy_clCreateCommandQueue(cl_command_queue ctx, cl_int err)
  : _ctx(ctx), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
cl_command_queue Dummy_clCreateCommandQueueWithProperties::
clCreateCommandQueueWithProperties(cl_context context, cl_device_id device,
                                   const cl_queue_properties* properties,
                                   cl_int* errcode_ret)
{
  call_with(context, device, properties, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_ctx;
}
Dummy_clCreateCommandQueueWithProperties::
Dummy_clCreateCommandQueueWithProperties(cl_command_queue ctx, cl_int err)
  : _ctx(ctx), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainCommandQueue::
clRetainCommandQueue(cl_command_queue command_queue)
{
  call_with(command_queue);
  return _err;
}
Dummy_clRetainCommandQueue::
Dummy_clRetainCommandQueue(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseCommandQueue::
clReleaseCommandQueue(cl_command_queue command_queue)
{
  call_with(command_queue);
  return _err;
}
Dummy_clReleaseCommandQueue::
Dummy_clReleaseCommandQueue(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetCommandQueueInfo::
clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name,
                 size_t param_value_size, void* param_value,
                 size_t* param_value_size_ret)
{
  call_with(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value_size_ret) {
    *param_value_size_ret = _param_value_size_ret;
  }
  if(param_value && _param_value) {
    std::memcpy(param_value, _param_value, std::min(param_value_size, _param_value_size_ret));
  }
  return _err;
}
Dummy_clGetCommandQueueInfo::
Dummy_clGetCommandQueueInfo(cl_int err, void* pv, size_t pvs)
  : _err(err), _param_value(pv), _param_value_size_ret(pvs)
{
}
/* ------------------------------------------------------------------------- */
cl_program Dummy_clCreateProgramWithSource::
clCreateProgramWithSource(cl_context context,
                          cl_uint count,
                          const char** strings,
                          const size_t* lengths,
                          cl_int* errcode_ret)
{
  call_with(context, count, strings, lengths, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clCreateProgramWithSource::
Dummy_clCreateProgramWithSource(cl_program program, cl_int err)
  :_program(program), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_program Dummy_clCreateProgramWithBinary::
clCreateProgramWithBinary(cl_context context,
                          cl_uint num_devices,
                          const cl_device_id* device_list,
                          const size_t* lengths,
                          const unsigned char** binaries,
                          cl_int* binary_status,
                          cl_int* errcode_ret)
{
  call_with(context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clCreateProgramWithBinary::
Dummy_clCreateProgramWithBinary(cl_program program, cl_int err)
  : _program(program), _err(err)
{
}
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
cl_program Dummy_clCreateProgramWithBuiltInKernels::
clCreateProgramWithBuiltInKernels(cl_context context,
                                  cl_uint num_devices,
                                  const cl_device_id* device_list,
                                  const char* kernel_names,
                                  cl_int* errcode_ret)
{
  call_with(context, num_devices, device_list, kernel_names, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clCreateProgramWithBuiltInKernels::
Dummy_clCreateProgramWithBuiltInKernels(cl_program program, cl_int err)
  :_program(program), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainProgram::
clRetainProgram(cl_program program)
{
  call_with(program);
  return _err;
}
Dummy_clRetainProgram::
Dummy_clRetainProgram(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseProgram::
clReleaseProgram(cl_program program)
{
  call_with(program);
  return _err;
}
Dummy_clReleaseProgram::
Dummy_clReleaseProgram(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clBuildProgram::
clBuildProgram(cl_program program,
               cl_uint num_devices,
               const cl_device_id* device_list,
               const char* options,
               void (CL_CALLBACK* pfn_notify)(cl_program, void*),
               void* user_data)
{
  call_with(program, num_devices,device_list, options, pfn_notify, user_data);
  return _err;
}
Dummy_clBuildProgram::
Dummy_clBuildProgram(cl_int err)
  :_err(err)
{
}
#if HAVE_OPENCL_clCompileProgram
/* ------------------------------------------------------------------------- */
cl_int Dummy_clCompileProgram::
clCompileProgram(cl_program program,
                 cl_uint num_devices,
                 const cl_device_id* device_list,
                 const char* options,
                 cl_uint num_input_headers,
                 const cl_program* input_headers,
                 const char** header_include_names,
                 void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                 void* user_data)
{
  call_with(program, num_devices, device_list, options, num_input_headers,
            input_headers, header_include_names, pfn_notify, user_data);
  return _err;
}
Dummy_clCompileProgram::
Dummy_clCompileProgram(cl_int err)
  :_err(err)
{
}
#endif
#if HAVE_OPENCL_clLinkProgram
/* ------------------------------------------------------------------------- */
cl_program Dummy_clLinkProgram::
clLinkProgram(cl_context context,
              cl_uint num_devices,
              const cl_device_id* device_list,
              const char* options,
              cl_uint num_input_programs,
              const cl_program* input_programs,
              void (CL_CALLBACK* pfn_notify)(cl_program, void*),
              void* user_data,
              cl_int* errcode_ret)
{
  call_with(context, num_devices, device_list, options, num_input_programs,
            input_programs, pfn_notify, user_data, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clLinkProgram::
Dummy_clLinkProgram(cl_program program, cl_int err)
  :_program(program), _err(err)
{
}
#endif
#if HAVE_OPENCL_clUnloadPlatformCompiler
/* ------------------------------------------------------------------------- */
cl_int Dummy_clUnloadPlatformCompiler::
clUnloadPlatformCompiler(cl_platform_id platform)
{
  call_with(platform);
  return _err;
}
Dummy_clUnloadPlatformCompiler::
Dummy_clUnloadPlatformCompiler(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetProgramInfo::
clGetProgramInfo(cl_program program, cl_program_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(program, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value && _param_value && _param_value_size_ret)
    {
      std::memcpy(param_value, _param_value, std::min(*_param_value_size_ret, param_value_size));
    }
  if(_param_value_size_ret && param_value_size_ret)
    {
      *param_value_size_ret = *_param_value_size_ret;
    }
  return _err;
}

Dummy_clGetProgramInfo::
Dummy_clGetProgramInfo(cl_int err, void* param_value, size_t* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetProgramBuildInfo::
clGetProgramBuildInfo(cl_program program, cl_device_id device,
                      cl_program_build_info param_name, size_t param_value_size,
                      void* param_value, size_t* param_value_size_ret)
{
  call_with(program, device, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value && _param_value && _param_value_size_ret)
    {
      std::memcpy(param_value, _param_value, std::min(*_param_value_size_ret, param_value_size));
    }
  if(_param_value_size_ret && param_value_size_ret)
    {
      *param_value_size_ret = *_param_value_size_ret;
    }
  return _err;
}

Dummy_clGetProgramBuildInfo::
Dummy_clGetProgramBuildInfo(cl_int err, void* param_value, size_t* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */

#endif /* CLXX_CL_MOCKS_DUMMY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
