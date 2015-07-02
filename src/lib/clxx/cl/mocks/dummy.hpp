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
 * \brief Helper class for OpenCL mocks
 *
 * This class shall be used as a base for other mock classes (\c T::Dummy_clXxx).
 * It allows to record and check calls to a mock function. An instantiation
 * of this template serves a single mock prototype.
 *
 * The typical usage is to spawn an instance of \ref T::Dummy_CallArgs
 * (more precise, an instance of a derived class), then invoke its member
 * function #call_with() one or more times with appropriate arguments. The
 * object records consecutive calls and arguments. After that, it might be
 * checked with one of the methods #never_called(), #called_once(),
 * #called_twice(), #called_three_times(), #called_four_times(),
 * #called_n_times(), #last_called_with(), #called_once_with() to verify if the
 * recorded call history agrees with an expected call history. A user may also
 * retrieve #calls() to see the full invocation history.
 *
 * \tparam Args List of argument types of an OpenCL function being mocked
 *
 * \par Example
 *
 * Create mock for <tt>clGetPlatformIDs(cl_uint, cl_platform_id*, cl_uint*)</tt>
 *
 * \code
 * class Dummy_clGetPlatformIDs
 *   : public T::Base_clGetPlatformIDs,
 *     public T::Dummy_CallArgs<cl_uint, cl_platform_id*, cl_uint*>
 * {
 *    // ...
 * };
 * // ...
 * cl_int Dummy_clGetPlatformIDs::
 * clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
 *                  cl_uint* num_platforms)
 * {
 *   call_with(num_entries, platforms, num_platforms);
 *   return _err;
 * }
 * \endcode
 *
 * Note, that each time the Dummy_clGetPlatformIDs::clGetPlatformIDs() is
 * invoked, the call gets recorded by the Dummy_clGetPlatformIDs object. It
 * may be later verified by a unit-test code how many times and with what
 * argument values the mock has been invoked.
 */ // }}}
template<class... Args>
class Dummy_CallArgs
{
public:
  /** // doc: args_tuple {{{
   * \brief A tuple used to store arguments of a single call to mock function
   */ // }}}
  typedef std::tuple<Args...> args_tuple;
  /** // doc: reset() {{{
   * \brief Reset the call history
   */ // }}}
  inline void reset() { _calls.clear(); }

  // return the calls
  /** // doc: () {{{
   * \brief Returns the full history of mock invocation.
   */ // }}}
  inline std::vector<args_tuple> const& calls() const { return _calls; }

  // mock tests
  /** // doc: never_called() {{{
   * \brief Whether the mock has never been invoked
   * \returns \c true if mock was not invoked since its creation/reset or \c false otherwise
   */ // }}}
  inline bool never_called() const noexcept
  { return _calls.size() == 0ul; }
  /** // doc: called_once() {{{
   * \brief Whether the mock has been invoked exactly once
   * \returns \c true if mock was invoked exactly once since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_once() const noexcept
  { return _calls.size() == 1ul; }
  /** // doc: called_twice() {{{
   * \brief Whether the mock has been invoked exactly twice
   * \returns \c true if mock was invoked exactly twice since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_twice() const noexcept
  { return _calls.size() == 2ul; }
  /** // doc: called_three_times() {{{
   * \brief Whether the mock has been invoked exactly three times
   * \returns \c true if mock was invoked exactly three times since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_three_times() const noexcept
  { return _calls.size() == 3ul; }
  /** // doc: called_four_times() {{{
   * \brief Whether the mock has been invoked exactly four times
   * \returns \c true if mock was invoked exactly four times since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_four_times() const noexcept
  { return _calls.size() == 3ul; }
  /** // doc: called_n_times() {{{
   * \brief Whether the mock has been invoked exactly n times
   * \param n The expected call count
   * \returns \c true if mock was invoked exactly n times since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_n_times(unsigned long n) const noexcept
  { return _calls.size() == n; }
  /** // doc: last_called_with() {{{
   * \brief Verify the arguments used in last call to the mock
   * \param args Expected argument values
   * \returns \c true if the last call arguments were same as the expected \em args or \c false otherwise
   */ // }}}
  inline bool last_called_with(Args... args) const
  { return (_calls.back() == args_tuple(args...)); }
  /** // doc: caled_once_with() {{{
   * \brief Same as <tt>called_once() && last_called_with_args(args...)</tt>
   */ // }}}
  inline bool called_once_with(Args... args) const
  { return called_once() && last_called_with(args...); }
protected:
  /** // doc: call_with(args) {{{
   * \brief Record a call to the mock
   *
   * This should be invoked from within derived class each time the mock is
   * invoked.
   *
   * \param args The arguments used in the invocation being recorded
   */ // }}}
  inline void call_with(Args... args)
  {
    _calls.push_back(args_tuple(args...));
  }
  /** // doc: call_with(args) {{{
   * \brief Invocation history
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
  cl_platform_id const* _platforms;
  cl_uint const* _num_platforms;
  cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                          cl_uint* num_platforms);
public:
  /** // doc: Dummy_clGetPlatformIDs() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param platforms Pointer to the array of platform IDs to be returned
   * \param num_platforms Pointer to an integer variable where the size of \p
   *        platforms array is stored
   */ // }}}
  Dummy_clGetPlatformIDs(cl_int err, cl_platform_id const* platforms = nullptr, cl_uint const* num_platforms = nullptr);
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
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetPlatformInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value Pointer to parameter value that is to be returned
   * \param param_value_size_ret Size of the parameter value (\p param_value) to be returned
   */ // }}}
  Dummy_clGetPlatformInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
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
  cl_device_id const* _devices;
  cl_uint const* _num_devices;
  cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
                        cl_uint num_entries, cl_device_id* devices,
                        cl_uint* num_devices);
public:
  /** // doc: Dummy_clGetDeviceIDs() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param devices Pointer to the array of device IDs to be returned
   * \param num_devices Pointer to an integer variable where the size of
   *        \p devices array is stored
   */ // }}}
  Dummy_clGetDeviceIDs(cl_int err, cl_device_id const* devices = nullptr, cl_uint const* num_devices = nullptr);
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
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetDeviceInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value Pointer to parameter value that is to be returned
   * \param param_value_size_ret Size of the parameter value (\p param_value) to be returned
   */ // }}}
  Dummy_clGetDeviceInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
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
   * \brief Constructor, initializes the mock object.
   *
   * \param ctx OpenCL context to be returned to caller
   * \param err Error code to be returned by the mock
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
   * \brief Constructor, initializes the mock object.
   *
   * \param ctx OpenCL context to be returned to caller
   * \param err Error code to be returned by the mock
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
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
   * \brief Constructor
   *
   * \param err Error code to be returned by the mock
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
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetContextInfo(cl_context context, cl_context_info param_name,
                          size_t param_value_size, void* param_value,
                          size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetContextInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value Pointer to parameter value that is to be returned
   * \param param_value_size_ret Size of the parameter value (\p param_value) to be returned
   */ // }}}
  Dummy_clGetContextInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param out_devices Pointer to the device list that is to be returned by the mock
   * \param num_devices_ret Number of devices specified in \em out_devices
   */ // }}}
  Dummy_clCreateSubDevices(cl_int err, cl_device_id const* out_devices = nullptr, cl_uint const* num_devices_ret = nullptr);
};
#endif
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainDevice(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseDevice(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
/** // doc: Dummy_clCreateCommandQueue {{{
 * \brief Default mock for clCreateCommandQueue OpenCL function.
 */ // }}}
class Dummy_clCreateCommandQueue
  : public T::Base_clCreateCommandQueue,
    public T::Dummy_CallArgs<cl_context, cl_device_id,
                             cl_command_queue_properties, cl_int*>
{
  cl_command_queue _queue;
  cl_int _err;
  cl_command_queue clCreateCommandQueue(
      cl_context context,
      cl_device_id device,
      cl_command_queue_properties properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param queue Command Queue to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateCommandQueue(cl_command_queue queue, cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
/** // doc: Dummy_clCreateCommandQueueWithProperties {{{
 * \brief Default mock for clCreateCommandQueueWithProperties OpenCL function.
 */ // }}}
class Dummy_clCreateCommandQueueWithProperties
  : public T::Base_clCreateCommandQueueWithProperties,
    public T::Dummy_CallArgs<cl_context, cl_device_id,
                             const cl_queue_properties*, cl_int*>
{
  cl_command_queue _queue;
  cl_int _err;
  cl_command_queue clCreateCommandQueueWithProperties(
      cl_context context,
      cl_device_id device,
      const cl_queue_properties* properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param queue Command Queue to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateCommandQueueWithProperties(cl_command_queue queue, cl_int err);
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
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
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetCommandQueueInfo(cl_command_queue command_queue,
                               cl_command_queue_info param_name,
                               size_t param_value_size, void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetCommandQueueInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value Pointer to the parameter value to be returned by a mock
   * \param param_value_size_ret Size of the parameter value \p param_value
   */ // }}}
  Dummy_clGetCommandQueueInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clCreateBuffer {{{
 * \brief Default mock for clCreateBuffer OpenCL function.
 */ // }}}
class Dummy_clCreateBuffer
  : public T::Base_clCreateBuffer,
    public T::Dummy_CallArgs<cl_context, cl_mem_flags, size_t, void*, cl_int*>
{
  cl_mem _mem;
  cl_int _err;
  cl_mem clCreateBuffer( cl_context context, cl_mem_flags flags,
                         size_t size, void* host_ptr, cl_int* errcode_ret );
public:
  /** // doc: Dummy_clCreateBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param mem Memory object to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateBuffer(cl_mem mem, cl_int err);
};
#if CLXX_OPENCL_ALLOWED(clCreateSubBuffer)
/** // doc: Dummy_clCreateSubBuffer {{{
 * \brief Default mock for clCreateSubBuffer OpenCL function.
 */ // }}}
class Dummy_clCreateSubBuffer
  : public T::Base_clCreateSubBuffer,
    public T::Dummy_CallArgs<cl_mem, cl_mem_flags, cl_buffer_create_type, const void*, cl_int*>
{
  cl_mem _mem;
  cl_int _err;
  cl_mem clCreateSubBuffer( cl_mem buffer, cl_mem_flags flags,
                            cl_buffer_create_type buffer_create_type,
                            const void* buffer_create_info,
                            cl_int* errcode_ret );
public:
  /** // doc: Dummy_clCreateSubBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param mem Memory object to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateSubBuffer(cl_mem mem, cl_int err);
};
#endif
/** // doc: Dummy_clEnqueueReadBuffer {{{
 * \brief Default mock for clEnqueueReadBuffer OpenCL function.
 */ // }}}
class Dummy_clEnqueueReadBuffer
  : public T::Base_clEnqueueReadBuffer,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, size_t, size_t,
                             void*, cl_uint, const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueReadBuffer( cl_command_queue command_queue,
                              cl_mem buffer, cl_bool blocking_read,
                              size_t offset, size_t size, void* ptr,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event);
public:
  /** // doc: Dummy_clCreateSubBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueReadBuffer(cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueWriteBuffer {{{
 * \brief Default mock for clEnqueueWriteBuffer OpenCL function.
 */ // }}}
class Dummy_clEnqueueWriteBuffer
  : public T::Base_clEnqueueWriteBuffer,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, size_t, size_t,
                             const void*, cl_uint, const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueWriteBuffer( cl_command_queue command_queue,
                               cl_mem buffer, cl_bool blocking_read,
                               size_t offset, size_t size, const void* ptr,
                               cl_uint num_events_in_wait_list,
                               const cl_event* event_wait_list,
                               cl_event* event);
public:
  /** // doc: Dummy_clCreateSubBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueWriteBuffer(cl_int err, const cl_event* event = nullptr);
};
#if CLXX_OPENCL_ALLOWED(clEnqueueReadBufferRect)
/** // doc: Dummy_clEnqueueReadBufferRect {{{
 * \brief Default mock for clEnqueueReadBufferRect OpenCL function.
 */ // }}}
class Dummy_clEnqueueReadBufferRect
  : public T::Base_clEnqueueReadBufferRect,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, const size_t*,
                             const size_t*, const size_t*, size_t, size_t,
                             size_t, size_t, void*, cl_uint, const cl_event*,
                             cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueReadBufferRectRect( cl_command_queue command_queue,
                                      cl_mem buffer, cl_bool blocking_read,
                                      const size_t* buffer_origin,
                                      const size_t* host_origin,
                                      const size_t* region,
                                      size_t buffer_row_pitch,
                                      size_t buffer_splice_pitch,
                                      size_t host_row_pitch,
                                      size_t host_slice_pitch,
                                      void* ptr,
                                      cl_uint num_events_in_wait_list,
                                      const cl_event* event_wait_list,
                                      cl_event* event );
public:
  /** // doc: Dummy_clEnqueueReadBufferRect() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueReadBufferRect(cl_int err, const cl_event* event = nullptr);
};
#endif
#if CLXX_OPENCL_ALLOWED(clEnqueueWriteBufferRect)
/** // doc: Dummy_clEnqueueWriteBufferRect {{{
 * \brief Default mock for clEnqueueWriteBufferRect OpenCL function.
 */ // }}}
class Dummy_clEnqueueWriteBufferRect
  : public T::Base_clEnqueueWriteBufferRect,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, const size_t*,
                             const size_t*, const size_t*, size_t, size_t,
                             size_t, size_t, void*, cl_uint, const cl_event*,
                             cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueWriteBufferRectRect( cl_command_queue command_queue,
                                      cl_mem buffer, cl_bool blocking_read,
                                      const size_t* buffer_origin,
                                      const size_t* host_origin,
                                      const size_t* region,
                                      size_t buffer_row_pitch,
                                      size_t buffer_splice_pitch,
                                      size_t host_row_pitch,
                                      size_t host_slice_pitch,
                                      void* ptr,
                                      cl_uint num_events_in_wait_list,
                                      const cl_event* event_wait_list,
                                      cl_event* event );
public:
  /** // doc: Dummy_clEnqueueWriteBufferRect() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueWriteBufferRect(cl_int err, const cl_event* event = nullptr);
};
#endif
/** // doc: Dummy_clEnqueueCopyBuffer {{{
 * \brief Default mock for clEnqueueCopyBuffer OpenCL function.
 */ // }}}
class Dummy_clEnqueueCopyBuffer
  : public T::Base_clEnqueueCopyBuffer,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_mem, size_t, size_t,
                             size_t, cl_uint, const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueCopyBuffer( cl_command_queue command_queue,
                              cl_mem src_buffer, cl_mem dst_buffer,
                              size_t src_offset, size_t dst_offset,
                              size_t size, cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event );
public:
  /** // doc: Dummy_clEnqueueCopyBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueCopyBuffer(cl_int err, const cl_event* event = nullptr);
};
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
/** // doc: Dummy_clEnqueueCopyBuffer {{{
 * \brief Default mock for clEnqueueCopyBuffer OpenCL function.
 */ // }}}
class Dummy_clEnqueueCopyBufferRect
  : public T::Base_clEnqueueCopyBufferRect,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_mem, const size_t*,
                             const size_t*, const size_t*, size_t, size_t,
                             size_t, size_t, cl_uint, const cl_event*,
                             cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueCopyBufferRect( cl_command_queue command_queue,
                                  cl_mem src_buffer,
                                  cl_mem dst_buffer,
                                  const size_t* src_origin,
                                  const size_t* dst_origin,
                                  const size_t* region,
                                  size_t src_row_pitch,
                                  size_t src_slice_pitch,
                                  size_t dst_row_pitch,
                                  size_t dst_slice_pitch,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event* event_wait_list,
                                  cl_event* event );
public:
  /** // doc: Dummy_clEnqueueCopyBufferRect() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueCopyBufferRect(cl_int err, const cl_event* event = nullptr);
};
#endif
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
/** // doc: Dummy_clEnqueueCopyBuffer {{{
 * \brief Default mock for clEnqueueCopyBuffer OpenCL function.
 */ // }}}
class Dummy_clEnqueueFillBuffer
  : public T::Base_clEnqueueFillBuffer,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, const void *, size_t,
                             size_t, size_t, cl_uint, const cl_event*,
                             cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueFillBuffer( cl_command_queue command_queue, cl_mem buffer,
                              const void *pattern, size_t pattern_size,
                              size_t offset, size_t size,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event );
public:
  /** // doc: Dummy_clEnqueueFillBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueFillBuffer(cl_int err, const cl_event* event = nullptr);
};
#endif
/** // doc: Dummy_clEnqueueMapBuffer {{{
 * \brief Default mock for clEnqueueMapBuffer OpenCL function.
 */ // }}}
class Dummy_clEnqueueMapBuffer
  : public T::Base_clEnqueueMapBuffer,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, cl_map_flags,
                             size_t, size_t, cl_uint, const cl_event*,
                             cl_event*, cl_int*>
{
  void* _result;
  cl_int _err;
  const cl_event* _event;
  void* clEnqueueMapBuffer( cl_command_queue command_queue, cl_mem buffer,
                            cl_bool blocking_map, cl_map_flags map_flags,
                            size_t offset, size_t size,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event, cl_int* errcode_ret );
public:
  /** // doc: Dummy_clEnqueueMapBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param result A value to be returned by the mock
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueMapBuffer(void* result, cl_int err, const cl_event* event = nullptr);
};
//
#if CLXX_OPENCL_ALLOWED(clCreateImage)
/** // doc: Dummy_clCreateImage {{{
 * \brief Default mock for clCreateImage OpenCL function.
 */ // }}}
class Dummy_clCreateImage
  : public T::Base_clCreateImage,
    public T::Dummy_CallArgs<cl_context, cl_mem_flags, const cl_image_format*,
                             const cl_image_desc*, void*, cl_int*>
{
  cl_mem _mem;
  cl_int _err;
  cl_mem clCreateImage( cl_context context, cl_mem_flags flags,
                        const cl_image_format* image_format,
                        const cl_image_desc* image_desc, void* host_ptr,
                        cl_int* errcode_ret );
public:
  /** // doc: Dummy_clCreateImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param mem Memory object to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateImage(cl_mem mem, cl_int err);
};
#endif
/** // doc: Dummy_clGetSupportedImageFormats {{{
 * \brief Default mock for clGetSupportedImageFormats OpenCL function.
 */ // }}}
class Dummy_clGetSupportedImageFormats
  : public T::Base_clGetSupportedImageFormats,
    public T::Dummy_CallArgs<cl_context, cl_mem_flags, cl_mem_object_type,
                             cl_uint, cl_image_format*, cl_uint*>
{
  cl_int _err;
  const cl_image_format* _image_formats;
  const cl_uint* _num_image_formats;
  cl_int clGetSupportedImageFormats( cl_context context, cl_mem_flags flags,
                                     cl_mem_object_type image_type,
                                     cl_uint num_entries,
                                     cl_image_format* image_formats,
                                     cl_uint* num_image_formats);
public:
  /** // doc: Dummy_clGetSupportedImageFormats() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param image_formats To be returned as image_formats list
   * \param num_image_formats Pointer to unsigned integer with the size of \p image_formats list
   */ // }}}
  Dummy_clGetSupportedImageFormats(cl_int err,
                                   const cl_image_format* image_formats = nullptr,
                                   const cl_uint* num_image_formats = nullptr);
};
/** // doc: Dummy_clEnqueueReadImage {{{
 * \brief Default mock for clEnqueueReadImage OpenCL function.
 */ // }}}
class Dummy_clEnqueueReadImage
  : public T::Base_clEnqueueReadImage,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, const size_t*,
                             const size_t*, size_t, size_t, void*, cl_uint,
                             const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueReadImage( cl_command_queue command_queue,
                             cl_mem image,
                             cl_bool blocking_read,
                             const size_t* origin,
                             const size_t* region,
                             size_t row_pitch,
                             size_t slice_pitch,
                             void* ptr,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event );
public:
  /** // doc: Dummy_clEnqueueReadImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueReadImage(cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueWriteImage {{{
 * \brief Default mock for clEnqueueWriteImage OpenCL function.
 */ // }}}
class Dummy_clEnqueueWriteImage
  : public T::Base_clEnqueueWriteImage,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, const size_t*,
                             const size_t*, size_t, size_t, const void*, cl_uint,
                             const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueWriteImage( cl_command_queue command_queue,
                              cl_mem image,
                              cl_bool blocking_read,
                              const size_t* origin,
                              const size_t* region,
                              size_t input_row_pitch,
                              size_t input_slice_pitch,
                              const void* ptr,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event );
public:
  /** // doc: Dummy_clEnqueueWriteImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueWriteImage(cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueCopyImage {{{
 * \brief Default mock for clEnqueueCopyImage OpenCL function.
 */ // }}}
class Dummy_clEnqueueCopyImage
  : public T::Base_clEnqueueCopyImage,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_mem, const size_t*,
                             const size_t*, const size_t*, cl_uint,
                             const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueCopyImage( cl_command_queue command_queue, cl_mem src_image,
                             cl_mem dst_image, const size_t* src_origin,
                             const size_t* dst_origin, const size_t* region,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event );
public:
  /** // doc: Dummy_clEnqueueCopyImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueCopyImage(cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueCopyImageToBuffer {{{
 * \brief Default mock for clEnqueueCopyImageToBuffer OpenCL function.
 */ // }}}
class Dummy_clEnqueueCopyImageToBuffer
  : public T::Base_clEnqueueCopyImageToBuffer,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_mem, const size_t*,
                             const size_t*, size_t, cl_uint, const cl_event*,
                             cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueCopyImageToBuffer( cl_command_queue command_queue,
                                     cl_mem src_image,
                                     cl_mem dst_buffer,
                                     const size_t* src_origin,
                                     const size_t* region,
                                     size_t dst_offset,
                                     cl_uint num_events_in_wait_list,
                                     const cl_event* event_wait_list,
                                     cl_event* event );
public:
  /** // doc: Dummy_clEnqueueCopyImageToBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueCopyImageToBuffer(cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueCopyBufferToImage {{{
 * \brief Default mock for clEnqueueCopyBufferToImage OpenCL function.
 */ // }}}
class Dummy_clEnqueueCopyBufferToImage
  : public T::Base_clEnqueueCopyBufferToImage,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_mem, size_t,
                             const size_t*, const size_t*, cl_uint,
                             const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueCopyBufferToImage( cl_command_queue command_queue,
                                     cl_mem src_buffer,
                                     cl_mem dst_image,
                                     size_t src_offset,
                                     const size_t* dst_origin,
                                     const size_t* region,
                                     cl_uint num_events_in_wait_list,
                                     const cl_event* event_wait_list,
                                     cl_event* event );
public:
  /** // doc: Dummy_clEnqueueCopyBufferToImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueCopyBufferToImage(cl_int err, const cl_event* event = nullptr);
};
#if CLXX_OPENCL_ALLOWED(clEnqueueFillImage)
/** // doc: Dummy_clEnqueueFillImage {{{
 * \brief Default mock for clEnqueueFillImage OpenCL function.
 */ // }}}
class Dummy_clEnqueueFillImage
  : public T::Base_clEnqueueFillImage,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, const void*, const
                             size_t*, const size_t*, cl_uint, const cl_event*,
                             cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueFillImage( cl_command_queue command_queue,
                             cl_mem image,
                             const void *fill_color,
                             const size_t* origin,
                             const size_t* region,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event);
public:
  /** // doc: Dummy_clEnqueueFillImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueFillImage(cl_int err, const cl_event* event = nullptr);
};
#endif
/** // doc: Dummy_clEnqueueMapImage {{{
 * \brief Default mock for clEnqueueMapImage OpenCL function.
 */ // }}}
class Dummy_clEnqueueMapImage
  : public T::Base_clEnqueueMapImage,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, cl_bool, cl_map_flags,
                             const size_t*, const size_t*, size_t*, size_t*,
                             cl_uint, const cl_event*, cl_event*, cl_int*>
{
  void* _result;
  cl_int _err;
  const cl_event* _event;
  void* clEnqueueMapImage( cl_command_queue command_queue,
                           cl_mem image,
                           cl_bool blocking_map,
                           cl_map_flags map_flags,
                           const size_t* origin,
                           const size_t* region,
                           size_t* image_row_pitch,
                           size_t* image_slice_pitch,
                           cl_uint num_events_in_wait_list,
                           const cl_event* event_wait_list,
                           cl_event* event,
                           cl_int* errcode_ret );
public:
  /** // doc: Dummy_clEnqueueMapImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param result A value to be returned by the mock
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueMapImage(void* result, cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueUnmapMemObject {{{
 * \brief Default mock for clEnqueueUnmapMemObject OpenCL function.
 */ // }}}
class Dummy_clEnqueueUnmapMemObject
  : public T::Base_clEnqueueUnmapMemObject,
    public T::Dummy_CallArgs<cl_command_queue, cl_mem, void*, cl_uint,
                             const cl_event*, cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueUnmapMemObject( cl_command_queue command_queue,
                                  cl_mem memobj,
                                  void* mapped_ptr,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event* event_wait_list,
                                  cl_event* event );
public:
  /** // doc: Dummy_clEnqueueUnmapMemObject() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueUnmapMemObject(cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueMigrateMemObjects {{{
 * \brief Default mock for clEnqueueMigrateMemObjects OpenCL function.
 */ // }}}
class Dummy_clEnqueueMigrateMemObjects
  : public T::Base_clEnqueueMigrateMemObjects,
    public T::Dummy_CallArgs<cl_command_queue, cl_uint, const cl_mem*,
                             cl_mem_migration_flags, cl_uint, const cl_event*,
                             cl_event*>
{
  cl_int _err;
  const cl_event* _event;
  cl_int clEnqueueMigrateMemObjects( cl_command_queue command_queue,
                                     cl_uint num_mem_objects,
                                     const cl_mem* mem_objects,
                                     cl_mem_migration_flags flags,
                                     cl_uint num_events_in_wait_list,
                                     const cl_event* event_wait_list,
                                     cl_event* event );
public:
  /** // doc: Dummy_clEnqueueMigrateMemObjects() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned
   */ // }}}
  Dummy_clEnqueueMigrateMemObjects(cl_int err, const cl_event* event = nullptr);
};
/** // doc: Dummy_clGetImageInfo {{{
 * \brief Mock for clGetImageInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetImageInfo
  : public T::Base_clGetImageInfo,
    public T::Dummy_CallArgs<cl_mem, cl_image_info, size_t, void*, size_t*>
{
  cl_int _err;
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetImageInfo(cl_mem image, cl_image_info param_name,
                        size_t param_value_size, void* param_value,
                        size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetImageInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetImageInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clGetMemObjectInfo {{{
 * \brief Mock for clGetMemObjectInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetMemObjectInfo
  : public T::Base_clGetMemObjectInfo,
    public T::Dummy_CallArgs<cl_mem, cl_mem_info, size_t, void*, size_t*>
{
  cl_int _err;
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetMemObjectInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetMemObjectInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clRetainMemObject {{{
 * \brief Default mock for clRetainMemObject OpenCL function.
 */ // }}}
class Dummy_clRetainMemObject
  : public T::Base_clRetainMemObject,
    public T::Dummy_CallArgs<cl_mem>
{
  cl_int _err;
  cl_int clRetainMemObject(cl_mem memobj);
public:
  /** // doc: Dummy_clRetainMemObject() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainMemObject(cl_int err);
};
/** // doc: Dummy_clReleaseMemObject {{{
 * \brief Default mock for clReleaseMemObject OpenCL function.
 */ // }}}
class Dummy_clReleaseMemObject
  : public T::Base_clReleaseMemObject,
    public T::Dummy_CallArgs<cl_mem>
{
  cl_int _err;
  cl_int clReleaseMemObject(cl_mem memobj);
public:
  /** // doc: Dummy_clReleaseMemObject() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseMemObject(cl_int err);
};
/** // doc: Dummy_clSetMemObjectDestructorCallback {{{
 * \brief Mock for clSetMemObjectDestructorCallback OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetMemObjectDestructorCallback
  : public T::Base_clSetMemObjectDestructorCallback,
    public T::Dummy_CallArgs<cl_mem, void(CL_CALLBACK*)(cl_mem, void*), void*>
{
  cl_int _err;
  cl_int clSetMemObjectDestructorCallback(cl_mem memobj,
                                          void(CL_CALLBACK* pfn_notify)(cl_mem, void*),
                                          void* user_data);
public:
  /** // doc: Dummy_clSetMemObjectDestructorCallback() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetMemObjectDestructorCallback(cl_int err);
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
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
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
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateProgramWithBinary(cl_program program, cl_int err);
};
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
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
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clBuildProgram(cl_int err);
};
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCompileProgram(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
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
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clLinkProgram(cl_program program, cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
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
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
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
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetProgramInfo(cl_program program, cl_program_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetProgramInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetProgramInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
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
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetProgramBuildInfo(cl_program program,
                               cl_device_id device,
                               cl_program_build_info param_name,
                               size_t param_value_size,
                               void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetProgramBuildInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetProgramBuildInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clCreateKernel {{{
 * \brief Default mock for clCreateKernel OpenCL function.
 */ // }}}
class Dummy_clCreateKernel
  : public T::Base_clCreateKernel,
    public T::Dummy_CallArgs< cl_program, const char*, cl_int*>
{
  cl_kernel _kern;
  cl_int _err;
  cl_kernel clCreateKernel(
      cl_program program,
      const char* kernel_name,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param kern OpenCL kernel to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateKernel(cl_kernel kern, cl_int err);
};
/** // doc: Dummy_clCreateKernelsInProgram {{{
 * \brief Default mock for clCreateKernelsInProgram OpenCL function.
 */ // }}}
class Dummy_clCreateKernelsInProgram
  : public T::Base_clCreateKernelsInProgram,
    public T::Dummy_CallArgs< cl_program, cl_uint, cl_kernel*, cl_uint*>
{
  cl_int _err;
  cl_kernel* _kernels;
  cl_uint* _num_kernels_ret;
  cl_int clCreateKernelsInProgram(
      cl_program program,
      cl_uint num_kernels,
      cl_kernel* kernels,
      cl_uint* num_kernels_ret
  );
public:
  /** // doc: Dummy_clCreateKernelsInProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param kernels Keernels to be returned by the mock
   * \param num_kernels_ret Number of kernels to be returned by the mock
   */ // }}}
  Dummy_clCreateKernelsInProgram(cl_int err, cl_kernel* kernels = nullptr, cl_uint* num_kernels_ret = nullptr);
};
/** // doc: Dummy_clGetKernelInfo {{{
 * \brief Mock for clGetKernelInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetKernelInfo
  : public T::Base_clGetKernelInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_kernel_info, size_t, void*, size_t*>
{
  cl_int _err;
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetKernelInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetKernelInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
/** // doc: Dummy_clGetKernelArgInfo {{{
 * \brief Mock for clGetKernelArgInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetKernelArgInfo
  : public T::Base_clGetKernelArgInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_uint, cl_kernel_arg_info, size_t, void*, size_t*>
{
  cl_int _err;
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index,
                            cl_kernel_arg_info param_name,
                            size_t param_value_size, void* param_value,
                            size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetKernelArgInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetKernelArgInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
#endif
/** // doc: Dummy_clGetKernelWorkGroupInfo {{{
 * \brief Mock for clGetKernelWorkGroupInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetKernelWorkGroupInfo
  : public T::Base_clGetKernelWorkGroupInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_device_id, cl_kernel_work_group_info, size_t, void*, size_t*>
{
  cl_int _err;
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device,
                                  cl_kernel_work_group_info param_name,
                                  size_t param_value_size, void* param_value,
                                  size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetKernelWorkGroupInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetKernelWorkGroupInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clRetainKernel {{{
 * \brief Default mock for clRetainKernel OpenCL function.
 */ // }}}
class Dummy_clRetainKernel
  : public T::Base_clRetainKernel,
    public T::Dummy_CallArgs<cl_kernel>
{
  cl_int _err;
  cl_int clRetainKernel(cl_kernel kernel);
public:
  /** // doc: Dummy_clRetainKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainKernel(cl_int err);
};
/** // doc: Dummy_clReleaseKernel {{{
 * \brief Default mock for clReleaseKernel OpenCL function.
 */ // }}}
class Dummy_clReleaseKernel
  : public T::Base_clReleaseKernel,
    public T::Dummy_CallArgs<cl_kernel>
{
  cl_int _err;
  cl_int clReleaseKernel(cl_kernel kernel);
public:
  /** // doc: Dummy_clReleaseKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseKernel(cl_int err);
};
/** // doc: Dummy_clSetKernelArg {{{
 * \brief Mock for clSetKernelArg OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetKernelArg
  : public T::Base_clSetKernelArg,
    public T::Dummy_CallArgs<cl_kernel, cl_uint, size_t, const void*>
{
  cl_int _err;
  cl_int clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size,
                        const void* arg_value);
public:
  /** // doc: Dummy_clSetKernelArg() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetKernelArg(cl_int err);
};
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
/** // doc: Dummy_clSetKernelArgSVMPointer {{{
 * \brief Mock for clSetKernelArgSVMPointer OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetKernelArgSVMPointer
  : public T::Base_clSetKernelArgSVMPointer,
    public T::Dummy_CallArgs<cl_kernel, cl_uint, const void*>
{
  cl_int _err;
  cl_int clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void* arg_value);
public:
  /** // doc: Dummy_clSetKernelArgSVMPointer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetKernelArgSVMPointer(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
/** // doc: Dummy_clSetKernelExecInfo {{{
 * \brief Mock for clSetKernelExecInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetKernelExecInfo
  : public T::Base_clSetKernelExecInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_kernel_exec_info, size_t, const void*>
{
  cl_int _err;
  cl_int clSetKernelExecInfo(cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, const void* arg_value);
public:
  /** // doc: Dummy_clSetKernelExecInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetKernelExecInfo(cl_int err);
};
#endif
/** // doc: Dummy_clEnqueueNDRangeKernel {{{
 * \brief Mock for clEnqueueNDRangeKernel OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clEnqueueNDRangeKernel
  : public T::Base_clEnqueueNDRangeKernel,
    public T::Dummy_CallArgs< cl_command_queue, cl_kernel, cl_uint, const
                              size_t*, const size_t*, const size_t*, cl_uint,
                              const cl_event*, cl_event*>
{
  cl_int _err;
  cl_event* _event;
  cl_int clEnqueueNDRangeKernel( cl_command_queue command_queue,
                                 cl_kernel kernel,
                                 cl_uint work_dim,
                                 const size_t* global_work_offset,
                                 const size_t* global_work_size,
                                 const size_t* local_work_size,
                                 cl_uint num_events_in_wait_list,
                                 const cl_event* event_wait_list,
                                 cl_event* event);
public:
  /** // doc: Dummy_clEnqueueNDRangeKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned by the mock
   */ // }}}
  Dummy_clEnqueueNDRangeKernel(cl_int err, cl_event* event = nullptr);
};
/** // doc: Dummy_clEnqueueNativeKernel {{{
 * \brief Mock for clEnqueueNativeKernel OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clEnqueueNativeKernel
  : public T::Base_clEnqueueNativeKernel,
    public T::Dummy_CallArgs<cl_command_queue, void (CL_CALLBACK*)(void*),
                             void*, size_t, cl_uint, const cl_mem*,
                             const void**, cl_uint, const cl_event*, cl_event*>
{
  cl_int _err;
  cl_event* _event;
  cl_int clEnqueueNativeKernel( cl_command_queue command_queue,
                                void (CL_CALLBACK* user_func)(void*),
                                void* args,
                                size_t cb_args,
                                cl_uint num_mem_objects,
                                const cl_mem* mem_list,
                                const void** args_mem_loc,
                                cl_uint num_events_in_wait_list,
                                const cl_event* event_wait_list,
                                cl_event* event );
public:
  /** // doc: Dummy_clEnqueueNativeKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param event An event to be returned by the mock
   */ // }}}
  Dummy_clEnqueueNativeKernel(cl_int err, cl_event* event = nullptr);
};

#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
/** // doc: Dummy_clCreateUserEvent {{{
 * \brief Mock for clCreateUserEvent OpenCL function.
 *
 * Does nothing except it returns a custom event handle predefined by user.
 */ // }}}
class Dummy_clCreateUserEvent
  : public T::Base_clCreateUserEvent,
    public T::Dummy_CallArgs<cl_context, cl_int*>
{
  cl_event _event;
  cl_int _err;
  cl_event clCreateUserEvent( cl_context context, cl_int* errcode_ret );
public:
  /** // doc: Dummy_clCreateUserEvent() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param event An event to be returned by the mock
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateUserEvent(cl_event event, cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
/** // doc: Dummy_clCreateUserEvent {{{
 * \brief Mock for clCreateUserEvent OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetUserEventStatus
  : public T::Base_clSetUserEventStatus,
    public T::Dummy_CallArgs<cl_event, cl_int>
{
  cl_int _err;
  cl_int clSetUserEventStatus( cl_event event , cl_int execution_status );
public:
  /** // doc: Dummy_clSetUserEventStatus() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetUserEventStatus(cl_int err);
};
#endif
/** // doc: Dummy_clWaitForEvents {{{
 * \brief Mock for clWaitForEvents OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clWaitForEvents
  : public T::Base_clWaitForEvents,
    public T::Dummy_CallArgs<cl_uint, const cl_event*>
{
  cl_int _err;
  cl_int clWaitForEvents(cl_uint num_events, const cl_event* event_list);
public:
  /** // doc: Dummy_clWaitForEvents() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clWaitForEvents(cl_int err);
};
/** // doc: Dummy_clGetEventInfo {{{
 * \brief Mock for clGetEventInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetEventInfo
  : public T::Base_clGetEventInfo,
    public T::Dummy_CallArgs<cl_event, cl_event_info, size_t, void*, size_t*>
{
  cl_int _err;
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetEventInfo(cl_event event, cl_event_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetEventInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetEventInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
#if CLXX_OPENCL_ALLOWED(clSetEventCallback)
/** // doc: Dummy_clSetEventCallback {{{
 * \brief Mock for clSetEventCallback OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetEventCallback
  : public T::Base_clSetEventCallback,
    public T::Dummy_CallArgs<cl_event, cl_int, void(CL_CALLBACK*)(cl_event, cl_int, void*), void*>
{
  cl_int _err;
  cl_int clSetEventCallback(cl_event event, cl_int command_exec_callback_type,
                            void(CL_CALLBACK *pfn_event_notify)(cl_event, cl_int, void*),
                            void* user_data);
public:
  /** // doc: Dummy_clSetEventCallback() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetEventCallback(cl_int err);
};
#endif
/** // doc: Dummy_clRetainEvent {{{
 * \brief Default mock for clRetainEvent OpenCL function.
 */ // }}}
class Dummy_clRetainEvent
  : public T::Base_clRetainEvent,
    public T::Dummy_CallArgs<cl_event>
{
  cl_int _err;
  cl_int clRetainEvent(cl_event);
public:
  /** // doc: Dummy_clRetainEvent() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainEvent(cl_int err);
};
/** // doc: Dummy_clReleaseEvent {{{
 * \brief Default mock for clReleaseEvent OpenCL function.
 */ // }}}
class Dummy_clReleaseEvent
  : public T::Base_clReleaseEvent,
    public T::Dummy_CallArgs<cl_event>
{
  cl_int _err;
  cl_int clReleaseEvent(cl_event);
public:
  /** // doc: Dummy_clReleaseEvent() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseEvent(cl_int err);
};
/** // doc: Dummy_clGetEventProfilingInfo {{{
 * \brief Mock for clGetEventProfilingInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetEventProfilingInfo
  : public T::Base_clGetEventProfilingInfo,
    public T::Dummy_CallArgs<cl_event, cl_profiling_info, size_t, void*, size_t*>
{
  cl_int _err;
  void const* _param_value;
  size_t const* _param_value_size_ret;
  cl_int clGetEventProfilingInfo(cl_event kernel, cl_profiling_info param_name,
                                 size_t param_value_size, void* param_value,
                                 size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetEventProfilingInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetEventProfilingInfo(cl_int err, void const* param_value = nullptr, size_t const* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clFlush {{{
 * \brief Default mock for clFlush OpenCL function.
 */ // }}}
class Dummy_clFlush
  : public T::Base_clFlush,
    public T::Dummy_CallArgs<cl_command_queue>
{
  cl_int _err;
  cl_int clFlush(cl_command_queue);
public:
  /** // doc: Dummy_clFlush() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clFlush(cl_int err);
};
/** // doc: Dummy_clFinish {{{
 * \brief Default mock for clFinish OpenCL function.
 */ // }}}
class Dummy_clFinish
  : public T::Base_clFinish,
    public T::Dummy_CallArgs<cl_command_queue>
{
  cl_int _err;
  cl_int clFinish(cl_command_queue);
public:
  /** // doc: Dummy_clFinish() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clFinish(cl_int err);
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
  if(platforms && _platforms && _num_platforms)
    {
      std::memcpy(platforms, _platforms, std::min(num_entries, *_num_platforms)*sizeof(cl_platform_id));
    }
  if(num_platforms && _num_platforms)
    {
      *num_platforms = *_num_platforms;
    }
  return _err;
}
Dummy_clGetPlatformIDs::
Dummy_clGetPlatformIDs(cl_int err, cl_platform_id const* platforms, cl_uint const* num_platforms)
  : _err(err), _platforms(platforms), _num_platforms(num_platforms)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  call_with(platform, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetPlatformInfo::
Dummy_clGetPlatformInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetDeviceIDs::
clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices,
               cl_uint* num_devices)
{
  call_with(platform, device_type, num_entries, devices, num_devices);
  if(devices && _devices && _num_devices)
    {
      std::memcpy(devices, _devices, std::min(num_entries, *_num_devices)*sizeof(cl_device_id));
    }
  if(num_devices && _num_devices)
    {
      *num_devices = *_num_devices;
    }
  return _err;
}
Dummy_clGetDeviceIDs::
Dummy_clGetDeviceIDs(cl_int err, cl_device_id const* devices, cl_uint const* num_devices)
  : _err(err), _devices(devices), _num_devices(num_devices)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(device, param_name, param_value_size, param_value, param_value_size_ret);
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

Dummy_clGetDeviceInfo::
Dummy_clGetDeviceInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
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
Dummy_clGetContextInfo::
Dummy_clGetContextInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
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
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
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
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
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
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
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
  return this->_queue;
}
Dummy_clCreateCommandQueue::
Dummy_clCreateCommandQueue(cl_command_queue queue, cl_int err)
  : _queue(queue), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
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
  return this->_queue;
}
Dummy_clCreateCommandQueueWithProperties::
Dummy_clCreateCommandQueueWithProperties(cl_command_queue queue, cl_int err)
  : _queue(queue), _err(err)
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
Dummy_clGetCommandQueueInfo::
Dummy_clGetCommandQueueInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_mem Dummy_clCreateBuffer::
clCreateBuffer( cl_context context, cl_mem_flags flags, size_t size,
                void* host_ptr, cl_int* errcode_ret )
{
  call_with(context, flags, size, host_ptr, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return _mem;
}
Dummy_clCreateBuffer::
Dummy_clCreateBuffer(cl_mem mem, cl_int err)
  :_mem(mem), _err(err)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateSubBuffer)
cl_mem Dummy_clCreateSubBuffer::
clCreateSubBuffer( cl_mem buffer, cl_mem_flags flags,
                   cl_buffer_create_type buffer_create_type,
                   const void* buffer_create_info, cl_int* errcode_ret )
{
  call_with(buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return _mem;
}
Dummy_clCreateSubBuffer::
Dummy_clCreateSubBuffer(cl_mem mem, cl_int err)
  : _mem(mem), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueReadBuffer::
clEnqueueReadBuffer( cl_command_queue command_queue,
                     cl_mem buffer, cl_bool blocking_read,
                     size_t offset, size_t size, void* ptr,
                     cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event)
{
  call_with( command_queue, buffer, blocking_read, offset, size, ptr,
             num_events_in_wait_list, event_wait_list, event );
  if(_event && event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueReadBuffer::
Dummy_clEnqueueReadBuffer(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueWriteBuffer::
clEnqueueWriteBuffer( cl_command_queue command_queue,
                      cl_mem buffer, cl_bool blocking_write,
                      size_t offset, size_t size, const void* ptr,
                      cl_uint num_events_in_wait_list,
                      const cl_event* event_wait_list,
                      cl_event* event )
{
  call_with( command_queue, buffer, blocking_write, offset, size, ptr,
             num_events_in_wait_list, event_wait_list, event );
  if(_event && event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueWriteBuffer::
Dummy_clEnqueueWriteBuffer(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clEnqueueReadBufferRect)
cl_int Dummy_clEnqueueReadBufferRect::
clEnqueueReadBufferRectRect( cl_command_queue command_queue,
                             cl_mem buffer, cl_bool blocking_read,
                             const size_t* buffer_origin,
                             const size_t* host_origin,
                             const size_t* region,
                             size_t buffer_row_pitch,
                             size_t buffer_splice_pitch,
                             size_t host_row_pitch,
                             size_t host_slice_pitch,
                             void* ptr,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event )
{
  call_with( command_queue, buffer, blocking_read, buffer_origin, host_origin,
             region, buffer_row_pitch, buffer_splice_pitch, host_row_pitch,
             host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list,
             event);
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueReadBufferRect::
Dummy_clEnqueueReadBufferRect(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clEnqueueWriteBufferRect)
cl_int Dummy_clEnqueueWriteBufferRect::
clEnqueueWriteBufferRectRect( cl_command_queue command_queue,
                             cl_mem buffer, cl_bool blocking_read,
                             const size_t* buffer_origin,
                             const size_t* host_origin,
                             const size_t* region,
                             size_t buffer_row_pitch,
                             size_t buffer_splice_pitch,
                             size_t host_row_pitch,
                             size_t host_slice_pitch,
                             void* ptr,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event )
{
  call_with( command_queue, buffer, blocking_read, buffer_origin, host_origin,
             region, buffer_row_pitch, buffer_splice_pitch, host_row_pitch,
             host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list,
             event);
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueWriteBufferRect::
Dummy_clEnqueueWriteBufferRect(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueCopyBuffer::
clEnqueueCopyBuffer( cl_command_queue command_queue,
                     cl_mem src_buffer, cl_mem dst_buffer,
                     size_t src_offset, size_t dst_offset,
                     size_t size, cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event )
{
  call_with( command_queue, src_buffer, dst_buffer, src_offset, dst_offset,
             size, num_events_in_wait_list, event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueCopyBuffer::
Dummy_clEnqueueCopyBuffer(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clEnqueueCopyBufferRect)
cl_int Dummy_clEnqueueCopyBufferRect::
clEnqueueCopyBufferRect( cl_command_queue command_queue,
                         cl_mem src_buffer,
                         cl_mem dst_buffer,
                         const size_t* src_origin,
                         const size_t* dst_origin,
                         const size_t* region,
                         size_t src_row_pitch,
                         size_t src_slice_pitch,
                         size_t dst_row_pitch,
                         size_t dst_slice_pitch,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event )
{
  call_with( command_queue, src_buffer, dst_buffer, src_origin, dst_origin,
             region, src_row_pitch, src_slice_pitch, dst_row_pitch,
             dst_slice_pitch, num_events_in_wait_list, event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueCopyBufferRect::
Dummy_clEnqueueCopyBufferRect(cl_int err, const cl_event* event)
  : _err(err), _event(event)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clEnqueueFillBuffer)
cl_int Dummy_clEnqueueFillBuffer::
clEnqueueFillBuffer( cl_command_queue command_queue, cl_mem buffer,
                     const void *pattern, size_t pattern_size,
                     size_t offset, size_t size,
                     cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event )
{
  call_with( command_queue, buffer, pattern, pattern_size, offset, size,
             num_events_in_wait_list, event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueFillBuffer::
Dummy_clEnqueueFillBuffer(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
#endif
/* ------------------------------------------------------------------------- */
void* Dummy_clEnqueueMapBuffer::
clEnqueueMapBuffer( cl_command_queue command_queue, cl_mem buffer,
                    cl_bool blocking_map, cl_map_flags map_flags,
                    size_t offset, size_t size,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event, cl_int* errcode_ret )
{
  call_with( command_queue, buffer, blocking_map, map_flags, offset, size,
             num_events_in_wait_list, event_wait_list, event, errcode_ret );
  if(event && _event)
    {
      *event = *_event;
    }
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return _result;
}
Dummy_clEnqueueMapBuffer::
Dummy_clEnqueueMapBuffer(void* result, cl_int err, const cl_event* event)
  : _result(result), _err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateImage)
cl_mem Dummy_clCreateImage::
clCreateImage( cl_context context, cl_mem_flags flags,
               const cl_image_format* image_format,
               const cl_image_desc* image_desc, void* host_ptr,
               cl_int* errcode_ret )
{
  call_with( context, flags, image_format, image_desc, host_ptr, errcode_ret );
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return _mem;
}
Dummy_clCreateImage::
Dummy_clCreateImage(cl_mem mem, cl_int err)
  :_mem(mem), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetSupportedImageFormats::
clGetSupportedImageFormats( cl_context context, cl_mem_flags flags,
                            cl_mem_object_type image_type,
                            cl_uint num_entries,
                            cl_image_format* image_formats,
                            cl_uint* num_image_formats)
{
  call_with( context, flags, image_type, num_entries, image_formats, num_image_formats);
  if(num_image_formats && _num_image_formats)
    {
      *num_image_formats = std::min(*_num_image_formats, num_entries);
    }
  if(image_formats && _image_formats && _num_image_formats)
    {
      std::memcpy(image_formats, _image_formats, std::min(num_entries, *_num_image_formats) * sizeof(cl_image_format));
    }
  return _err;
}
Dummy_clGetSupportedImageFormats::
Dummy_clGetSupportedImageFormats(cl_int err,
                                 const cl_image_format* image_formats,
                                 const cl_uint* num_image_formats)
  : _err(err), _image_formats(image_formats), _num_image_formats(num_image_formats)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueReadImage::
clEnqueueReadImage( cl_command_queue command_queue,
                    cl_mem image,
                    cl_bool blocking_read,
                    const size_t* origin,
                    const size_t* region,
                    size_t row_pitch,
                    size_t slice_pitch,
                    void* ptr,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event )
{
  call_with( command_queue, image, blocking_read, origin, region, row_pitch,
             slice_pitch, ptr, num_events_in_wait_list, event_wait_list,
             event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueReadImage::
Dummy_clEnqueueReadImage(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueWriteImage::
clEnqueueWriteImage( cl_command_queue command_queue,
                    cl_mem image,
                    cl_bool blocking_read,
                    const size_t* origin,
                    const size_t* region,
                    size_t input_row_pitch,
                    size_t input_slice_pitch,
                    const void* ptr,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event )
{
  call_with( command_queue, image, blocking_read, origin, region,
             input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list,
             event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueWriteImage::
Dummy_clEnqueueWriteImage(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueCopyImage::
clEnqueueCopyImage( cl_command_queue command_queue, cl_mem src_image,
                    cl_mem dst_image, const size_t* src_origin,
                    const size_t* dst_origin, const size_t* region,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event )
{
  call_with( command_queue, src_image, dst_image, src_origin, dst_origin,
             region, num_events_in_wait_list, event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueCopyImage::
Dummy_clEnqueueCopyImage(cl_int err, const cl_event* event)
  :_err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueCopyImageToBuffer::
clEnqueueCopyImageToBuffer( cl_command_queue command_queue,
                            cl_mem src_image,
                            cl_mem dst_buffer,
                            const size_t* src_origin,
                            const size_t* region,
                            size_t dst_offset,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event )
{
  call_with( command_queue, src_image, dst_buffer, src_origin, region,
             dst_offset, num_events_in_wait_list, event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueCopyImageToBuffer::
Dummy_clEnqueueCopyImageToBuffer(cl_int err, const cl_event* event)
  : _err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueCopyBufferToImage::
clEnqueueCopyBufferToImage( cl_command_queue command_queue,
                            cl_mem src_buffer,
                            cl_mem dst_image,
                            size_t src_offset,
                            const size_t* dst_origin,
                            const size_t* region,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event )
{
  call_with( command_queue, src_buffer, dst_image, src_offset, dst_origin,
             region, num_events_in_wait_list, event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueCopyBufferToImage::
Dummy_clEnqueueCopyBufferToImage(cl_int err, const cl_event* event)
  : _err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clEnqueueFillImage)
cl_int Dummy_clEnqueueFillImage::
clEnqueueFillImage( cl_command_queue command_queue,
                    cl_mem image,
                    const void *fill_color,
                    const size_t* origin,
                    const size_t* region,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event)
{
  call_with( command_queue, image, fill_color, origin, region,
             num_events_in_wait_list, event_wait_list, event);
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueFillImage::
Dummy_clEnqueueFillImage(cl_int err, const cl_event* event)
  : _err(err), _event(event)
{
}
#endif
/* ------------------------------------------------------------------------- */
void* Dummy_clEnqueueMapImage::
clEnqueueMapImage( cl_command_queue command_queue,
                   cl_mem image,
                   cl_bool blocking_map,
                   cl_map_flags map_flags,
                   const size_t* origin,
                   const size_t* region,
                   size_t* image_row_pitch,
                   size_t* image_slice_pitch,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event,
                   cl_int* errcode_ret )
{
  call_with( command_queue, image, blocking_map, map_flags, origin, region,
             image_row_pitch, image_slice_pitch, num_events_in_wait_list,
             event_wait_list, event, errcode_ret );
  if(event && _event)
    {
      *event = *_event;
    }
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return _result;
}
Dummy_clEnqueueMapImage::
Dummy_clEnqueueMapImage(void* result, cl_int err, const cl_event* event)
  : _result(result), _err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueUnmapMemObject::
clEnqueueUnmapMemObject( cl_command_queue command_queue,
                         cl_mem memobj,
                         void* mapped_ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event )
{
  call_with( command_queue, memobj, mapped_ptr, num_events_in_wait_list,
             event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueUnmapMemObject::
Dummy_clEnqueueUnmapMemObject(cl_int err, const cl_event* event)
  : _err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueMigrateMemObjects::
clEnqueueMigrateMemObjects( cl_command_queue command_queue,
                            cl_uint num_mem_objects,
                            const cl_mem* mem_objects,
                            cl_mem_migration_flags flags,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event )
{
  call_with( command_queue, num_mem_objects, mem_objects, flags,
             num_events_in_wait_list, event_wait_list, event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueMigrateMemObjects::
Dummy_clEnqueueMigrateMemObjects(cl_int err, const cl_event* event)
  : _err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetImageInfo::
clGetImageInfo(cl_mem image, cl_image_info param_name,
               size_t param_value_size, void* param_value,
               size_t* param_value_size_ret)
{
  call_with(image, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetImageInfo::
Dummy_clGetImageInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetMemObjectInfo::
clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name,
                   size_t param_value_size, void* param_value,
                   size_t* param_value_size_ret)
{
  call_with(memobj, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetMemObjectInfo::
Dummy_clGetMemObjectInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainMemObject::
clRetainMemObject(cl_mem memobj)
{
  call_with(memobj);
  return _err;
}
Dummy_clRetainMemObject::
Dummy_clRetainMemObject(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseMemObject::
clReleaseMemObject(cl_mem memobj)
{
  call_with(memobj);
  return _err;
}
Dummy_clReleaseMemObject::
Dummy_clReleaseMemObject(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clSetMemObjectDestructorCallback::
clSetMemObjectDestructorCallback(cl_mem memobj,
                                 void(CL_CALLBACK* pfn_notify)(cl_mem, void*),
                                 void* user_data)
{
  call_with(memobj, pfn_notify, user_data);
  return _err;
}
Dummy_clSetMemObjectDestructorCallback::
Dummy_clSetMemObjectDestructorCallback(cl_int err)
  : _err(err)
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
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
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
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
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
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
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
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
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
Dummy_clGetProgramInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
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
Dummy_clGetProgramBuildInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_kernel Dummy_clCreateKernel::
clCreateKernel(cl_program program, const char* kernel_name, cl_int* errcode_ret)
{
  call_with(program, kernel_name, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_kern;
}
Dummy_clCreateKernel::
Dummy_clCreateKernel(cl_kernel kern, cl_int err)
  : _kern(kern), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clCreateKernelsInProgram::
clCreateKernelsInProgram(cl_program program, cl_uint num_kernels, cl_kernel* kernels,
                         cl_uint* num_kernels_ret)
{
  call_with(program, num_kernels, kernels, num_kernels_ret);
  if(_kernels && kernels && _num_kernels_ret)
    {
      std::memcpy(kernels, _kernels, std::min(*_num_kernels_ret, num_kernels) * sizeof(cl_kernel));
    }
  if(_num_kernels_ret && num_kernels_ret)
    {
      *num_kernels_ret = *_num_kernels_ret;
    }
  return _err;
}
Dummy_clCreateKernelsInProgram::
Dummy_clCreateKernelsInProgram(cl_int err, cl_kernel* kernels, cl_uint* num_kernels_ret)
  : _err(err), _kernels(kernels), _num_kernels_ret(num_kernels_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetKernelInfo::
clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(kernel, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetKernelInfo::
Dummy_clGetKernelInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
cl_int Dummy_clGetKernelArgInfo::
clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info param_name,
                   size_t param_value_size, void* param_value,
                   size_t* param_value_size_ret)
{
  call_with(kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetKernelArgInfo::
Dummy_clGetKernelArgInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetKernelWorkGroupInfo::
clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret)
{
  call_with(kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetKernelWorkGroupInfo::
Dummy_clGetKernelWorkGroupInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainKernel::
clRetainKernel(cl_kernel kernel)
{
  call_with(kernel);
  return _err;
}
Dummy_clRetainKernel::
Dummy_clRetainKernel(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseKernel::
clReleaseKernel(cl_kernel kernel)
{
  call_with(kernel);
  return _err;
}
Dummy_clReleaseKernel::
Dummy_clReleaseKernel(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clSetKernelArg::
clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void* arg_value)
{
  call_with(kernel, arg_index, arg_size, arg_value);
  return _err;
}
Dummy_clSetKernelArg::
Dummy_clSetKernelArg(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
cl_int Dummy_clSetKernelArgSVMPointer::
clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void* arg_value)
{
  call_with(kernel, arg_index, arg_value);
  return _err;
}
Dummy_clSetKernelArgSVMPointer::
Dummy_clSetKernelArgSVMPointer(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
cl_int Dummy_clSetKernelExecInfo::
clSetKernelExecInfo(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, const void* param_value)
{
  call_with(kernel, param_name, param_value_size, param_value);
  return _err;
}
Dummy_clSetKernelExecInfo::
Dummy_clSetKernelExecInfo(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueNDRangeKernel::
clEnqueueNDRangeKernel( cl_command_queue command_queue,
                        cl_kernel kernel,
                        cl_uint work_dim,
                        const size_t* global_work_offset,
                        const size_t* global_work_size,
                        const size_t* local_work_size,
                        cl_uint num_events_in_wait_list,
                        const cl_event* event_wait_list,
                        cl_event* event)
{
  call_with(command_queue, kernel, work_dim, global_work_offset,
            global_work_size, local_work_size, num_events_in_wait_list,
            event_wait_list, event);
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueNDRangeKernel::
Dummy_clEnqueueNDRangeKernel(cl_int err, cl_event* event)
  : _err(err), _event(event)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clEnqueueNativeKernel::
clEnqueueNativeKernel( cl_command_queue command_queue,
                       void (CL_CALLBACK* user_func)(void*),
                       void* args,
                       size_t cb_args,
                       cl_uint num_mem_objects,
                       const cl_mem* mem_list,
                       const void** args_mem_loc,
                       cl_uint num_events_in_wait_list,
                       const cl_event* event_wait_list,
                       cl_event* event )
{
  call_with( command_queue, user_func, args, cb_args, num_mem_objects,
             mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list,
             event );
  if(event && _event)
    {
      *event = *_event;
    }
  return _err;
}
Dummy_clEnqueueNativeKernel::
Dummy_clEnqueueNativeKernel(cl_int err, cl_event* event)
  : _err(err), _event(event)
{
}



/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
cl_event Dummy_clCreateUserEvent::
clCreateUserEvent( cl_context context, cl_int* errcode_ret )
{
  call_with(context, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return _event;
}
Dummy_clCreateUserEvent::
Dummy_clCreateUserEvent(cl_event event, cl_int err)
  :_event(event), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
cl_int Dummy_clSetUserEventStatus::
clSetUserEventStatus( cl_event event , cl_int execution_status )
{
  call_with(event, execution_status);
  return _err;
}
Dummy_clSetUserEventStatus::
Dummy_clSetUserEventStatus(cl_int err)
  :_err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clWaitForEvents::
clWaitForEvents(cl_uint num_events, const cl_event* event_list)
{
  call_with(num_events, event_list);
  return _err;
}
Dummy_clWaitForEvents::
Dummy_clWaitForEvents(cl_int err)
  :_err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetEventInfo::
clGetEventInfo(cl_event event, cl_event_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(event, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetEventInfo::
Dummy_clGetEventInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clSetEventCallback::
clSetEventCallback(cl_event event, cl_int command_exec_callback_type,
                   void(CL_CALLBACK *pfn_event_notify)(cl_event, cl_int, void*),
                   void* user_data)
{
  call_with(event, command_exec_callback_type, pfn_event_notify, user_data);
  return _err;
}
Dummy_clSetEventCallback::
Dummy_clSetEventCallback(cl_int err)
  :_err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainEvent::
clRetainEvent(cl_event event)
{
  call_with(event);
  return _err;
}
Dummy_clRetainEvent::
Dummy_clRetainEvent(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseEvent::
clReleaseEvent(cl_event event)
{
  call_with(event);
  return _err;
}
Dummy_clReleaseEvent::
Dummy_clReleaseEvent(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetEventProfilingInfo::
clGetEventProfilingInfo(cl_event event, cl_profiling_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(event, param_name, param_value_size, param_value, param_value_size_ret);
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
Dummy_clGetEventProfilingInfo::
Dummy_clGetEventProfilingInfo(cl_int err, void const* param_value, size_t const* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clFlush::
clFlush(cl_command_queue command_queue)
{
  call_with(command_queue);
  return _err;
}
Dummy_clFlush::
Dummy_clFlush(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clFinish::
clFinish(cl_command_queue command_queue)
{
  call_with(command_queue);
  return _err;
}
Dummy_clFinish::
Dummy_clFinish(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */

#endif /* CLXX_CL_MOCKS_DUMMY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
