// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/mocks/newton.hpp

/** // doc: clxx/cl/mocks/newton.hpp {{{
 * \file clxx/cl/mocks/newton.hpp
 *
 * This file implements OpenCL mocks emulating a node that has two OpenCL
 * platforms: platform 0 is AMD CPU platform, platform 1 contains 2 nVidia GPU
 * C1060 devices.
 *
 * Platform IDs:
 *
 * * Platform 0 (CPU): 0x7f1b791754c0,
 * * Platform 1 (GPU): 0x2479be0
 *
 * Device IDs:
 *
 * * Platform 0:
 *   - Device 0: 0x2473a20
 * * Platform 1:
 *   - Device 0 (Tesla C1060): 0x2479c80
 *   - Device 1 (Tesla C1060): 0x2479cf0
 *
 *  **Example**:
 *
 *  The following is a unit test for clxx::Device::get_vendor_id()
 *  which calls clGetDeviceInfo().
 *
 *  \code
 *  void test_get_vendor_id()
 *  {
 *    T::Newton_clGetDeviceInfo mock;
 *    Device d(T::Newton_clGetDeviceIDs::devices[1]);
 *    TS_ASSERT_EQUALS(d.get_vendor_id(), 0x10de); // "NVIDIA Corporation"
 *  }
 *  \endcode
 *
 */ // }}}
#ifndef CLXX_CL_MOCKS_NEWTON_HPP_INCLUDED
#define CLXX_CL_MOCKS_NEWTON_HPP_INCLUDED

/* Mock class declarations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE) || defined(CXXTEST_FLAGS) \
  || defined(CXXTEST_RUNNING) || defined(DOXYGEN)

#include <algorithm>
#include <map>
#include <vector>
/** \cond SHOW_IGNORED_COMPOUNDS */
namespace T {
/** // doc: Newton_clGetPlatformIDs {{{
 * \todo Write documentation
 */ // }}}
class Newton_clGetPlatformIDs
  : public T::Base_clGetPlatformIDs
{
  cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                          cl_uint *num_platforms);
public:
  static cl_uint const num_platforms;
  static cl_platform_id const platforms[2];
  static int find(cl_platform_id platform);
};

/** // doc: Newton_clGetPlatformInfo {{{
 * \todo Write documentation
 */ // }}}
class Newton_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo
{
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  static char const* const profile[2];
  static char const* const version[2];
  static char const* const name[2];
  static char const* const vendor[2];
  static char const* const extensions[2];
};

/** // doc: Newton_clGetDeviceIDs {{{
 * \todo Write documentation
 */ // }}}
class Newton_clGetDeviceIDs
  : public T::Base_clGetDeviceIDs
{
  cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
                        cl_uint num_entries, cl_device_id* devices,
                        cl_uint *num_devices);
public:
  static cl_uint const num_devices;
  static cl_device_id const devices[3];
  static int find(cl_device_id device);
};

/** // doc: Newton_clGetDeviceInfo {{{
 * \todo Write documentation
 */ // }}}
class Newton_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo
{
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
public:
  static bool const is_default[3];
  static cl_device_type const type[3];
  static cl_uint const vendor_id[3];
  static cl_uint const max_compute_units[3];
  static cl_uint const max_work_item_dimensions[3];
  static size_t const max_work_item_sizes[3][3];
  static size_t const max_work_group_size[3];
  static cl_uint const preferred_vector_width_char[3];
  static cl_uint const preferred_vector_width_short[3];
  static cl_uint const preferred_vector_width_int[3];
  static cl_uint const preferred_vector_width_long[3];
  static cl_uint const preferred_vector_width_float[3];
  static cl_uint const preferred_vector_width_double[3];
  static cl_uint const preferred_vector_width_half[3];
  static cl_uint const native_vector_width_char[3];
  static cl_uint const native_vector_width_short[3];
  static cl_uint const native_vector_width_int[3];
  static cl_uint const native_vector_width_long[3];
  static cl_uint const native_vector_width_float[3];
  static cl_uint const native_vector_width_double[3];
  static cl_uint const native_vector_width_half[3];
  static cl_uint const max_clock_frequency[3];
  static cl_uint const address_bits[3];
  static cl_ulong const max_mem_alloc_size[3];
  static cl_bool const image_support[3];
  static cl_uint const max_read_image_args[3];
  static cl_uint const max_write_image_args[3];
  static size_t const image2d_max_width[3];
  static size_t const image2d_max_height[3];
  static size_t const image3d_max_width[3];
  static size_t const image3d_max_height[3];
  static size_t const image3d_max_depth[3];
  static cl_uint const max_samplers[3];
  static size_t const max_parameter_size[3];
  static cl_uint const mem_base_addr_align[3];
  static cl_uint const min_data_type_align_size[3];
  static cl_device_fp_config const single_fp_config[3];
  static cl_device_mem_cache_type const global_mem_cache_type[3];
  static cl_uint const global_mem_cacheline_size[3];
  static cl_ulong const global_mem_cache_size[3];
  static cl_ulong const global_mem_size[3];
  static cl_ulong const max_constant_buffer_size[3];
  static cl_uint const max_constant_args[3];
  static cl_device_local_mem_type const local_mem_type[3];
  static cl_ulong const local_mem_size[3];
  static cl_bool const error_correction_support[3];
  static cl_bool const host_unified_memory[3];
  static size_t const profiling_timer_resolution[3];
  static cl_bool const endian_little[3];
  static cl_bool const available[3];
  static cl_bool const compiler_available[3];
  static cl_device_exec_capabilities const execution_capabilities[3];
  static cl_command_queue_properties const queue_properties[3];
  static cl_platform_id const platform[3];
  static char const* const name[3];
  static char const* const vendor[3];
  static char const* const driver_version[3];
  static char const* const profile[3];
  static char const* const version[3];
  static char const* const opencl_c_version[3];
  static char const* const extensions[3];
  static cl_device_fp_config const double_fp_config[1];
  static cl_bool const linker_available[1];
  static char const* const built_in_kernels[1];
  static size_t const image_max_buffer_size[1];
  static size_t const image_max_array_size[1];
  static cl_device_id const parent_device_id[1];
  static cl_uint const partition_max_sub_devices[1];
  static std::vector<cl_device_partition_property> const partition_properties[1];
  static cl_device_affinity_domain const partition_affinity_domain[1];
  static std::vector<cl_device_partition_property> const partition_type[1];
  static cl_uint const reference_count[1];
  static cl_bool const preferred_interop_user_sync[1];
  static size_t const printf_buffer_size[1];
  static cl_uint const image_pitch_alignment[1];
  static cl_uint const image_base_address_alignment[1];
};

/** // doc: Newton_Context {{{
 * \todo Write documentation
 */ // }}}
class Newton_Context
{
public:
  typedef void(CL_CALLBACK* Callback)(const char*,const void*, size_t, void*);

  static cl_context create();
  static cl_context create(const cl_context_properties*, cl_uint,
                           const cl_device_id*, Callback, void*, cl_int*);
  static cl_int retain(cl_context);
  static cl_int release(cl_context);
  static Newton_Context* find(cl_context);


  std::vector<cl_device_id> devices;
  std::vector<cl_context_properties> properties;
  Callback callback;
  void* user_data;
  cl_int refcount;

private:
  typedef std::map<cl_context, Newton_Context*> Map;
  static Map contexts;


  Newton_Context();
  Newton_Context(const cl_context_properties*, cl_uint, const cl_device_id*, Callback, void*);

  static cl_context register_(Newton_Context* obj);
  static size_t properties_size(const cl_context_properties*);
};

/** // doc: Newton_clCreateContext {{{
 * \todo Write documentation
 */ // }}}
class Newton_clCreateContext
  : public T::Base_clCreateContext
{
  cl_context clCreateContext(
      const cl_context_properties*, cl_uint, const cl_device_id*,
      void(CL_CALLBACK*)(const char*,const void*, size_t, void*),
      void*, cl_int*);
public:
  static cl_context contexts[8];
};

/** // doc: Newton_clCreateContextFromType {{{
 * \todo Write documentation
 */ // }}}
class Newton_clCreateContextFromType
  : public T::Base_clCreateContextFromType
{
  cl_context clCreateContextFromType(
        const cl_context_properties*, cl_device_type,
        void(CL_CALLBACK*)(const char*, const void*, size_t, void*),
        void*, cl_int*);
};

/** // doc: Newton_clRetainContext {{{
 * \todo Write documentation
 */ // }}}
class Newton_clRetainContext
  : public T::Base_clRetainContext
{
  cl_int clRetainContext(cl_context);
};

/** // doc: Newton_clReleaseContext {{{
 * \todo Write documentation
 */ // }}}
class Newton_clReleaseContext
  : public T::Base_clReleaseContext
{
  cl_int clReleaseContext(cl_context);
};
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE || ... */

/* Mock class implementations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE)

#include <cstring>

namespace T {

cl_uint const Newton_clGetPlatformIDs::num_platforms = 2;
cl_platform_id const Newton_clGetPlatformIDs::platforms[2] = {
  reinterpret_cast<cl_platform_id>(0x7f1b791754c0),
  reinterpret_cast<cl_platform_id>(0x2479be0)
};

int Newton_clGetPlatformIDs::
find(cl_platform_id platform)
{
  for(cl_uint i = 0; i < Newton_clGetPlatformIDs::num_platforms; ++i)
    {
      if(platform == Newton_clGetPlatformIDs::platforms[i])
        {
          return (int)i;
        }
    }
  return -1;
}

cl_int Newton_clGetPlatformIDs::
clGetPlatformIDs( cl_uint num_entries,
                  cl_platform_id* platforms,
                  cl_uint *num_platforms )
{
  if((num_entries == 0 && platforms != NULL) ||
     (num_platforms == NULL && platforms == NULL))
     {
       return CL_INVALID_VALUE;
     }
  if(num_platforms != NULL)
    *num_platforms = Newton_clGetPlatformIDs::num_platforms;
  if(platforms != NULL)
    {
      for(cl_uint i = 0;
          i < num_entries && i < Newton_clGetPlatformIDs::num_platforms;
          ++i)
      {
        platforms[i] = Newton_clGetPlatformIDs::platforms[i];
      }
    }
  return CL_SUCCESS;
}

char const* const Newton_clGetPlatformInfo::profile[2] = {
  "FULL_PROFILE",
  "FULL_PROFILE"
};
char const* const Newton_clGetPlatformInfo::version[2] = {
  "OpenCL 1.2 AMD-APP (1348.4)",
  "OpenCL 1.1 CUDA 4.2.1"
};
char const* const Newton_clGetPlatformInfo::name[2] = {
  "AMD Accelerated Parallel Processing",
  "NVIDIA CUDA"
};
char const* const Newton_clGetPlatformInfo::vendor[2] = {
  "Advanced Micro Devices, Inc.",
  "NVIDIA Corporation"
};
char const* const Newton_clGetPlatformInfo::extensions[2] = {
  "cl_khr_icd cl_amd_event_callback cl_amd_offline_devices",
  "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll"
};

cl_int Newton_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  void const* ptr;
  size_t size;

  if(platform == NULL)
    {
      return CL_INVALID_PLATFORM; // implementation-defined behavior.
    }

  int pi = Newton_clGetPlatformIDs::find(platform);
  if(pi == -1)
    {
      return CL_INVALID_PLATFORM;
    }

  switch(param_name)
  {
    case CL_PLATFORM_PROFILE:
      ptr = Newton_clGetPlatformInfo::profile[pi];
      size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
      break;
    case CL_PLATFORM_VERSION:
      ptr = Newton_clGetPlatformInfo::version[pi];
      size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
      break;
    case CL_PLATFORM_NAME:
      ptr = Newton_clGetPlatformInfo::name[pi];
      size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
      break;
    case CL_PLATFORM_VENDOR:
      ptr = Newton_clGetPlatformInfo::vendor[pi];
      size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
      break;
    case CL_PLATFORM_EXTENSIONS:
      ptr = Newton_clGetPlatformInfo::extensions[pi];
      size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
      break;
    default:
      return CL_INVALID_VALUE;
  }


  if(param_value_size_ret != NULL)
    {
      *param_value_size_ret = size;
    }
  if(param_value != NULL)
    {
      if(param_value_size < size)
        {
          return CL_INVALID_VALUE;
        }
      std::memcpy(param_value, ptr, size);
    }
  return CL_SUCCESS;
}

cl_uint const Newton_clGetDeviceIDs::num_devices = 3;
cl_device_id const Newton_clGetDeviceIDs::devices[3] =
  {
    reinterpret_cast<cl_device_id>(0x2473a20),
    reinterpret_cast<cl_device_id>(0x2479c80),
    reinterpret_cast<cl_device_id>(0x2479cf0)
  };

int Newton_clGetDeviceIDs::
find(cl_device_id device)
{
  for(cl_uint i = 0; i < Newton_clGetDeviceIDs::num_devices; ++i)
    {
      if(device == Newton_clGetDeviceIDs::devices[i])
        {
          return (int)i;
        }
    }
  return -1;
}

cl_int Newton_clGetDeviceIDs::
clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices,
               cl_uint *num_devices)
{
  int pi = Newton_clGetPlatformIDs::find(platform);

  if(pi ==-1)
    {
      return CL_INVALID_PLATFORM;
    }

  if((num_entries == 0 && devices != NULL) ||
     (num_devices == NULL && devices == NULL))
    {
      return CL_INVALID_VALUE;
    }

  switch(device_type)
  {
    case CL_DEVICE_TYPE_CPU:
    case CL_DEVICE_TYPE_GPU:
    case CL_DEVICE_TYPE_ACCELERATOR:
    case CL_DEVICE_TYPE_CUSTOM:
    case CL_DEVICE_TYPE_DEFAULT:
    case CL_DEVICE_TYPE_ALL:
      break;
    default:
      return CL_INVALID_DEVICE_TYPE;
  }

  cl_uint i2 = 0;
  for(cl_uint i = 0; i < Newton_clGetDeviceIDs::num_devices; ++i)
    {
      if(Newton_clGetDeviceInfo::platform[i] == platform)
        {
          bool is_default = Newton_clGetDeviceInfo::is_default[i];
          cl_device_type type = Newton_clGetDeviceInfo::type[i];
          if((device_type == CL_DEVICE_TYPE_ALL) ||
             (device_type == CL_DEVICE_TYPE_DEFAULT && is_default) ||
             (device_type != CL_DEVICE_TYPE_DEFAULT && device_type == type))
            {
              if(devices)
                {
                  if(i2 >= num_entries)
                    {
                      return CL_INVALID_VALUE;
                    }
                  devices[i2] = Newton_clGetDeviceIDs::devices[i];
                }
              ++i2;
            }
        }
    }

  if(num_devices)
    {
      *num_devices = i2;
    }

  if(devices && i2 == 0)
    {
      return CL_DEVICE_NOT_FOUND;
    }

  return CL_SUCCESS;
}


///////////////// Values for clGetDeviceInfo /////////////////////////////////
// CL_DEVICE_TYPE
bool const Newton_clGetDeviceInfo::
is_default[3] = { true, true, false };
cl_device_type const Newton_clGetDeviceInfo::
type[3] = { CL_DEVICE_TYPE_CPU, CL_DEVICE_TYPE_GPU, CL_DEVICE_TYPE_GPU };
// CL_DEVICE_VENDOR_ID
cl_uint const Newton_clGetDeviceInfo::
vendor_id[3] = { 0x1002, 0x10de, 0x10de };
// CL_DEVICE_MAX_COMPUTE_UNITS
cl_uint const Newton_clGetDeviceInfo::
max_compute_units[3] = { 16, 30, 30 };
// CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS
cl_uint const Newton_clGetDeviceInfo::
max_work_item_dimensions[3] = { 3, 3, 3 };
// CL_DEVICE_MAX_WORK_ITEM_SIZES
size_t const Newton_clGetDeviceInfo::
max_work_item_sizes[3][3] = { {1024,1024,1024}, {512,512,64}, {512,512,64} };
// CL_DEVICE_MAX_WORK_GROUP_SIZE
size_t const Newton_clGetDeviceInfo::
max_work_group_size[3] = { 1024, 512, 512 };
// CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR
cl_uint const Newton_clGetDeviceInfo::
preferred_vector_width_char[3] = { 16, 1, 1 };
// CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT
cl_uint const Newton_clGetDeviceInfo::
preferred_vector_width_short[3] = { 8, 1, 1 };
// CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT
cl_uint const Newton_clGetDeviceInfo::
preferred_vector_width_int[3] = { 4, 1, 1 };
// CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG
cl_uint const Newton_clGetDeviceInfo::
preferred_vector_width_long[3] = { 2, 1, 1 };
// CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT
cl_uint const Newton_clGetDeviceInfo::
preferred_vector_width_float[3] = { 4, 1, 1 };
// CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE
cl_uint const Newton_clGetDeviceInfo::
preferred_vector_width_double[3] = { 2, 1, 1 };
// CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF
cl_uint const Newton_clGetDeviceInfo::
preferred_vector_width_half[3] = { 2, 0, 0 };
// CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR
cl_uint const Newton_clGetDeviceInfo::
native_vector_width_char[3] = { 16, 1, 1 };
// CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT
cl_uint const Newton_clGetDeviceInfo::
native_vector_width_short[3] = { 8, 1, 1 };
// CL_DEVICE_NATIVE_VECTOR_WIDTH_INT
cl_uint const Newton_clGetDeviceInfo::
native_vector_width_int[3] = { 4, 1, 1 };
// CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG
cl_uint const Newton_clGetDeviceInfo::
native_vector_width_long[3] = { 2, 1, 1 };
// CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT
cl_uint const Newton_clGetDeviceInfo::
native_vector_width_float[3] = { 4, 1, 1 };
// CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE
cl_uint const Newton_clGetDeviceInfo::
native_vector_width_double[3] = { 2, 1, 1 };
// CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF
cl_uint const Newton_clGetDeviceInfo::
native_vector_width_half[3] = { 2, 0, 0 };
// CL_DEVICE_MAX_CLOCK_FREQUENCY
cl_uint const Newton_clGetDeviceInfo::
max_clock_frequency[3] = { 2401, 1296, 1296 };
// CL_DEVICE_ADDRESS_BITS
cl_uint const Newton_clGetDeviceInfo::
address_bits[3] = { 64, 32, 32 };
// CL_DEVICE_MAX_MEM_ALLOC_SIZE
cl_ulong const Newton_clGetDeviceInfo::
max_mem_alloc_size[3] = { 4214191104ul, 1073692672ul, 1073692672ul};
// CL_DEVICE_IMAGE_SUPPORT
cl_bool const Newton_clGetDeviceInfo::
image_support[3] = { CL_TRUE, CL_TRUE, CL_TRUE};
// CL_DEVICE_MAX_READ_IMAGE_ARGS
cl_uint const Newton_clGetDeviceInfo::
max_read_image_args[3] = { 128, 128, 128 };
// CL_DEVICE_MAX_WRITE_IMAGE_ARGS
cl_uint const Newton_clGetDeviceInfo::
max_write_image_args[3] = { 8, 8, 8 };
// CL_DEVICE_IMAGE2D_MAX_WIDTH
size_t const Newton_clGetDeviceInfo::
image2d_max_width[3] = { 8192, 4096, 4096 };
// CL_DEVICE_IMAGE2D_MAX_HEIGHT
size_t const Newton_clGetDeviceInfo::
image2d_max_height[3] = { 8192, 16383, 16383 };
// CL_DEVICE_IMAGE3D_MAX_WIDTH
size_t const Newton_clGetDeviceInfo::
image3d_max_width[3] = { 2048, 2048, 2048 };
// CL_DEVICE_IMAGE3D_MAX_HEIGHT
size_t const Newton_clGetDeviceInfo::
image3d_max_height[3] = { 2048, 2048, 2048 };
// CL_DEVICE_IMAGE3D_MAX_DEPTH
size_t const Newton_clGetDeviceInfo::
image3d_max_depth[3] = { 2048, 2048, 2048 };
// CL_DEVICE_MAX_SAMPLERS
cl_uint const Newton_clGetDeviceInfo::
max_samplers[3] = { 16, 16, 16 };
// CL_DEVICE_MAX_PARAMETER_SIZE
size_t const Newton_clGetDeviceInfo::
max_parameter_size[3] = { 4096, 4352, 4352 };
// CL_DEVICE_MEM_BASE_ADDR_ALIGN
cl_uint const Newton_clGetDeviceInfo::
mem_base_addr_align[3] = { 1024, 2048, 2048 };
// CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE
cl_uint const Newton_clGetDeviceInfo::
min_data_type_align_size[3] = { 128, 128, 128 };
// CL_DEVICE_SINGLE_FP_CONFIG
cl_device_fp_config const Newton_clGetDeviceInfo::
single_fp_config[3] = {
  CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA,
  CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA,
  CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA
};
// CL_DEVICE_GLOBAL_MEM_CACHE_TYPE
cl_device_mem_cache_type const Newton_clGetDeviceInfo::
global_mem_cache_type[3] = { CL_READ_WRITE_CACHE, CL_NONE, CL_NONE };
// CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE
cl_uint const Newton_clGetDeviceInfo::
global_mem_cacheline_size[3] = { 64, 0, 0 };
// CL_DEVICE_GLOBAL_MEM_CACHE_SIZE
cl_ulong const Newton_clGetDeviceInfo::
global_mem_cache_size[3] = { 32768ul, 0, 0 };
// CL_DEVICE_GLOBAL_MEM_SIZE
cl_ulong const Newton_clGetDeviceInfo::
global_mem_size[3] = { 16856764416ul, 4294770688ul, 4294770688ul };
// CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE
cl_ulong const Newton_clGetDeviceInfo::
max_constant_buffer_size[3] = { 65536, 65536, 65536 };
// CL_DEVICE_MAX_CONSTANT_ARGS
cl_uint const Newton_clGetDeviceInfo::
max_constant_args[3] = { 8, 9, 9 };
//  CL_DEVICE_LOCAL_MEM_TYPE
cl_device_local_mem_type const Newton_clGetDeviceInfo::
local_mem_type[3] = { CL_GLOBAL, CL_LOCAL, CL_LOCAL };
// CL_DEVICE_LOCAL_MEM_SIZE
cl_ulong const Newton_clGetDeviceInfo::
local_mem_size[3] = { 32768, 16384, 16384 };
// CL_DEVICE_ERROR_CORRECTION_SUPPORT
cl_bool const Newton_clGetDeviceInfo::
error_correction_support[3] = { CL_FALSE, CL_FALSE, CL_FALSE };
// CL_DEVICE_HOST_UNIFIED_MEMORY
cl_bool const Newton_clGetDeviceInfo::
host_unified_memory[3] = { CL_TRUE, CL_FALSE, CL_FALSE };
// CL_DEVICE_PROFILING_TIMER_RESOLUTION
size_t const Newton_clGetDeviceInfo::
profiling_timer_resolution[3] = { 1, 1000, 1000 };
// CL_DEVICE_ENDIAN_LITTLE
cl_bool const Newton_clGetDeviceInfo::
endian_little[3] = { CL_TRUE, CL_TRUE, CL_TRUE };
// CL_DEVICE_AVAILABLE
cl_bool const Newton_clGetDeviceInfo::
available[3] = { CL_TRUE, CL_TRUE, CL_TRUE };
// CL_DEVICE_COMPILER_AVAILABLE
cl_bool const Newton_clGetDeviceInfo::
compiler_available[3] = { CL_TRUE, CL_TRUE, CL_TRUE };
// CL_DEVICE_EXECUTION_CAPABILITIES
cl_device_exec_capabilities const Newton_clGetDeviceInfo::
execution_capabilities[3] = {
  CL_EXEC_KERNEL | CL_EXEC_NATIVE_KERNEL,
  CL_EXEC_KERNEL,
  CL_EXEC_KERNEL,
};
// CL_DEVICE_QUEUE_PROPERTIES_
cl_command_queue_properties const Newton_clGetDeviceInfo::
queue_properties[3] = {
  CL_QUEUE_PROFILING_ENABLE,
  CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE,
  CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE
};
// CL_DEVICE_PLATFORM
cl_platform_id const Newton_clGetDeviceInfo::
platform[3] = {
  Newton_clGetPlatformIDs::platforms[0],
  Newton_clGetPlatformIDs::platforms[1],
  Newton_clGetPlatformIDs::platforms[1]
};
// CL_DEVICE_NAME
char const* const Newton_clGetDeviceInfo::
name[3] = {
  "Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz",
  "Tesla C1060",
  "Tesla C1060"
};
// CL_DEVICE_VENDOR
char const* const Newton_clGetDeviceInfo::
vendor[3] = {
  "GenuineIntel",
  "NVIDIA Corporation",
  "NVIDIA Corporation"
};
// CL_DRIVER_VERSION
char const* const Newton_clGetDeviceInfo::
driver_version[3] = {
  "1348.4 (sse2)",
  "319.76",
  "319.76"
};
// CL_DEVICE_PROFILE
char const* const Newton_clGetDeviceInfo::
profile[3] = {
  "FULL_PROFILE",
  "FULL_PROFILE",
  "FULL_PROFILE"
};
// CL_DEVICE_VERSION
char const* const Newton_clGetDeviceInfo::
version[3] = {
  "OpenCL 1.2 AMD-APP (1348.4)",
  "OpenCL 1.0 CUDA",
  "OpenCL 1.0 CUDA"
};
// CL_DEVICE_OPENCL_C_VERSION
char const* const Newton_clGetDeviceInfo::
opencl_c_version[3] = {
  "OpenCL C 1.2",
  "OpenCL C 1.1",
  "OpenCL C 1.1"
};
// CL_DEVICE_EXTENSIONS
char const* const Newton_clGetDeviceInfo::
extensions[3] = {
  "cl_khr_fp64 cl_amd_fp64 cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_int64_base_atomics cl_khr_int64_extended_atomics cl_khr_3d_image_writes cl_khr_byte_addressable_store cl_khr_gl_sharing cl_ext_device_fission cl_amd_device_attribute_query cl_amd_vec3 cl_amd_printf cl_amd_media_ops cl_amd_media_ops2 cl_amd_popcnt",
  "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll  cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_fp6",
  "cl_khr_byte_addressable_store cl_khr_icd cl_khr_gl_sharing cl_nv_compiler_options cl_nv_device_attribute_query cl_nv_pragma_unroll  cl_khr_global_int32_base_atomics cl_khr_global_int32_extended_atomics cl_khr_local_int32_base_atomics cl_khr_local_int32_extended_atomics cl_khr_fp6"
};
cl_device_fp_config const Newton_clGetDeviceInfo::double_fp_config[1] = {
  CL_FP_DENORM | CL_FP_INF_NAN | CL_FP_ROUND_TO_NEAREST | CL_FP_ROUND_TO_ZERO | CL_FP_ROUND_TO_INF | CL_FP_FMA
};
cl_bool const Newton_clGetDeviceInfo::linker_available[1] = { CL_FALSE };
char const* const Newton_clGetDeviceInfo::built_in_kernels[1] = { "" };
size_t const Newton_clGetDeviceInfo::image_max_buffer_size[1] = { 65536 };
size_t const Newton_clGetDeviceInfo::image_max_array_size[1] = { 2048 };
cl_device_id const Newton_clGetDeviceInfo::parent_device_id[1] = { NULL };
cl_uint const Newton_clGetDeviceInfo::partition_max_sub_devices[1] = { 16 };
static cl_device_partition_property const _pprops0[3] = {
  CL_DEVICE_PARTITION_EQUALLY,
  CL_DEVICE_PARTITION_BY_COUNTS,
  CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN
};
std::vector<cl_device_partition_property> const Newton_clGetDeviceInfo::
partition_properties[1] = {
  std::vector<cl_device_partition_property>(_pprops0, _pprops0+3)
};
cl_device_affinity_domain const Newton_clGetDeviceInfo::
partition_affinity_domain[1] = {
      CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE
    | CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE
    | CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE
    | CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE
};
std::vector<cl_device_partition_property> const Newton_clGetDeviceInfo::
partition_type[1] = {
  std::vector<cl_device_partition_property>()
};
cl_uint const Newton_clGetDeviceInfo::reference_count[1] = { 1 };
cl_bool const Newton_clGetDeviceInfo::preferred_interop_user_sync[1] = { CL_TRUE };
size_t const Newton_clGetDeviceInfo::printf_buffer_size[1] = { 65536 };
cl_uint const Newton_clGetDeviceInfo::image_pitch_alignment[1] = { 0 };
cl_uint const Newton_clGetDeviceInfo::image_base_address_alignment[1] = { 0 };
//////////////////////////////////////////////////////////////////////////////


cl_int Newton_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  void const* ptr;
  size_t size;

  int di = Newton_clGetDeviceIDs::find(device);

  if(di == -1)
    {
      return CL_INVALID_DEVICE;
    }

  switch(param_name)
    {
      case CL_DEVICE_TYPE:
        ptr = &type[di];
        size = sizeof(cl_device_type);
        break;
      case CL_DEVICE_VENDOR_ID:
        ptr = &vendor_id[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MAX_COMPUTE_UNITS:
        ptr = &max_compute_units[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS:
        ptr = &max_work_item_dimensions[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MAX_WORK_ITEM_SIZES:
        ptr = &max_work_item_sizes[di];
        size = 3 * sizeof(size_t);
        break;
      case CL_DEVICE_MAX_WORK_GROUP_SIZE:
        ptr = &max_work_group_size[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR:
        ptr = &preferred_vector_width_char[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT:
        ptr = &preferred_vector_width_short[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT:
        ptr = &preferred_vector_width_int[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG:
        ptr = &preferred_vector_width_long[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT:
        ptr = &preferred_vector_width_float[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE:
        ptr = &preferred_vector_width_double[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF:
        ptr = &preferred_vector_width_half[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR:
        ptr = &native_vector_width_char[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT:
        ptr = &native_vector_width_short[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_NATIVE_VECTOR_WIDTH_INT:
        ptr = &native_vector_width_int[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG:
        ptr = &native_vector_width_long[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT:
        ptr = &native_vector_width_float[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE:
        ptr = &native_vector_width_double[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF:
        ptr = &native_vector_width_half[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MAX_CLOCK_FREQUENCY:
        ptr = &max_clock_frequency[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_ADDRESS_BITS:
        ptr = &address_bits[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MAX_MEM_ALLOC_SIZE:
        ptr = &max_mem_alloc_size[di];
        size = sizeof(cl_ulong);
        break;
      case CL_DEVICE_IMAGE_SUPPORT:
        ptr = &image_support[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_MAX_READ_IMAGE_ARGS:
        ptr = &max_read_image_args[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MAX_WRITE_IMAGE_ARGS:
        ptr = &max_write_image_args[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_IMAGE2D_MAX_WIDTH:
        ptr = &image2d_max_width[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_IMAGE2D_MAX_HEIGHT:
        ptr = &image2d_max_height[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_IMAGE3D_MAX_WIDTH:
        ptr = &image3d_max_width[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_IMAGE3D_MAX_HEIGHT:
        ptr = &image3d_max_height[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_IMAGE3D_MAX_DEPTH:
        ptr = &image3d_max_depth[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_MAX_SAMPLERS:
        ptr = &max_samplers[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MAX_PARAMETER_SIZE:
        ptr = &max_parameter_size[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_MEM_BASE_ADDR_ALIGN:
        ptr = &mem_base_addr_align[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE:
        ptr = &min_data_type_align_size[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_SINGLE_FP_CONFIG:
        ptr = &single_fp_config[di];
        size = sizeof(cl_device_fp_config);
        break;
      case CL_DEVICE_GLOBAL_MEM_CACHE_TYPE:
        ptr = &global_mem_cache_type[di];
        size = sizeof(cl_device_mem_cache_type);
        break;
      case CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE:
        ptr = &global_mem_cacheline_size[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_GLOBAL_MEM_CACHE_SIZE:
        ptr = &global_mem_cache_size[di];
        size = sizeof(cl_ulong);
        break;
      case CL_DEVICE_GLOBAL_MEM_SIZE:
        ptr = &global_mem_size[di];
        size = sizeof(cl_ulong);
        break;
      case CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE:
        ptr = &max_constant_buffer_size[di];
        size = sizeof(cl_ulong);
        break;
      case CL_DEVICE_MAX_CONSTANT_ARGS:
        ptr = &max_constant_args[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_LOCAL_MEM_TYPE:
        ptr = &local_mem_type[di];
        size = sizeof(cl_device_local_mem_type);
        break;
      case CL_DEVICE_LOCAL_MEM_SIZE:
        ptr = &local_mem_size[di];
        size = sizeof(cl_ulong);
        break;
      case CL_DEVICE_ERROR_CORRECTION_SUPPORT:
        ptr = &error_correction_support[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_HOST_UNIFIED_MEMORY:
        ptr = &host_unified_memory[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_PROFILING_TIMER_RESOLUTION:
        ptr = &profiling_timer_resolution[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_ENDIAN_LITTLE:
        ptr = &endian_little[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_AVAILABLE:
        ptr = &available[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_COMPILER_AVAILABLE:
        ptr = &compiler_available[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_EXECUTION_CAPABILITIES:
        ptr = &execution_capabilities[di];
        size = sizeof(cl_device_exec_capabilities);
        break;
      case CL_DEVICE_QUEUE_PROPERTIES:
        ptr = &queue_properties[di];
        size = sizeof(cl_command_queue_properties);
        break;
      case CL_DEVICE_PLATFORM:
        ptr = &platform[di];
        size = sizeof(cl_platform_id);
        break;
      case CL_DEVICE_NAME:
        ptr = name[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DEVICE_VENDOR:
        ptr = vendor[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DRIVER_VERSION:
        ptr = driver_version[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DEVICE_PROFILE:
        ptr = profile[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DEVICE_VERSION:
        ptr = version[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DEVICE_OPENCL_C_VERSION:
        ptr = opencl_c_version[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DEVICE_EXTENSIONS:
        ptr = extensions[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DEVICE_DOUBLE_FP_CONFIG:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &double_fp_config[di];
        size = sizeof(cl_device_fp_config);
        break;
      case CL_DEVICE_LINKER_AVAILABLE:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &linker_available[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_BUILT_IN_KERNELS:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = built_in_kernels[di];
        size = std::strlen(reinterpret_cast<char const*>(ptr)) + 1;
        break;
      case CL_DEVICE_IMAGE_MAX_BUFFER_SIZE:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &image_max_buffer_size[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_IMAGE_MAX_ARRAY_SIZE:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &image_max_array_size[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_PARENT_DEVICE:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &parent_device_id[di];
        size = sizeof(cl_device_id);
        break;
      case CL_DEVICE_PARTITION_MAX_SUB_DEVICES:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &partition_max_sub_devices[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PARTITION_PROPERTIES:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &partition_properties[di].front();
        size = partition_properties[di].size() * sizeof(cl_device_partition_property);
        break;
      case CL_DEVICE_PARTITION_AFFINITY_DOMAIN:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &partition_affinity_domain[di];
        size = sizeof(cl_device_affinity_domain);
        break;
      case CL_DEVICE_PARTITION_TYPE:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &partition_type[di].front();
        size = partition_type[di].size() * sizeof(cl_device_partition_property);
        break;
      case CL_DEVICE_REFERENCE_COUNT:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &reference_count[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_PREFERRED_INTEROP_USER_SYNC:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &preferred_interop_user_sync[di];
        size = sizeof(cl_bool);
        break;
      case CL_DEVICE_PRINTF_BUFFER_SIZE:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &printf_buffer_size[di];
        size = sizeof(size_t);
        break;
      case CL_DEVICE_IMAGE_PITCH_ALIGNMENT:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &image_pitch_alignment[di];
        size = sizeof(cl_uint);
        break;
      case CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT:
        if(di > 0)
          return CL_INVALID_VALUE;
        ptr = &image_base_address_alignment[di];
        size = sizeof(cl_uint);
        break;
      default:
        return CL_INVALID_VALUE;
    }

  if(param_value != NULL)
    {
      if(param_value_size < size)
        {
          return CL_INVALID_VALUE;
        }
      std::memcpy(param_value, ptr, size);
    }

  if(param_value_size_ret != NULL)
    {
      *param_value_size_ret = size;
    }
  return CL_SUCCESS;
}

Newton_Context::Map Newton_Context::contexts;

Newton_Context::
Newton_Context()
  : callback(nullptr), user_data(nullptr), refcount(1)
{
  this->properties.push_back((cl_context_properties)0ul);
}

Newton_Context::
Newton_Context(const cl_context_properties* properties, cl_uint num_devices,
               const cl_device_id* devices, Callback callback, void* user_data)
  : callback(callback), user_data(user_data), refcount(1)
{
  size_t n = properties_size(properties);

  // insert properties to our vector
  this->properties.insert(this->properties.begin(), properties, properties+n);
  this->devices.insert(this->devices.begin(), devices, devices + num_devices);

  // copy other properties
  this->callback = callback;
  this->user_data = user_data;
}

size_t Newton_Context::
properties_size(const cl_context_properties* properties)
{
  size_t n=1;
  for(; n<255 && properties[n-1] != (cl_context_properties)0ul; n+=2) { }
  return n;
}

cl_context Newton_Context::
register_(Newton_Context* obj)
{
  cl_context context = reinterpret_cast<cl_context>(obj);
  contexts[context] = obj;
  return context;
}

cl_context Newton_Context::
create()
{
  Newton_Context *obj = new Newton_Context();
  return Newton_Context::register_(obj);
}

cl_context Newton_Context::
create(const cl_context_properties* properties, cl_uint num_devices,
       const cl_device_id* devices, Callback callback, void* user_data,
       cl_int* errcode_ret)
{
  if(properties_size(properties) >= 255)
    {
      if(errcode_ret)
        {
          *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
      return NULL;
    }
  Newton_Context *obj = new Newton_Context(properties, num_devices, devices, callback, user_data);
  return Newton_Context::register_(obj);
}

Newton_Context* Newton_Context::
find(cl_context context)
{
  Map::iterator found(contexts.find(context));
  if(found == contexts.end()) {
    return NULL;
  }
  return found->second;
}

cl_int Newton_Context::
retain(cl_context context)
{
  Newton_Context* obj = find(context);
  if(obj == nullptr) {
    return CL_INVALID_CONTEXT;
  }
  obj->refcount++;
  return CL_SUCCESS;
}

cl_int Newton_Context::
release(cl_context context)
{
  Map::iterator found(contexts.find(context));
  if(found == contexts.end()) {
    return CL_INVALID_CONTEXT;
  }
  if(found->second->refcount > 1)
    {
      found->second->refcount--;
    }
  else
    {
      contexts.erase(found);
      delete found->second;
    }
  return CL_SUCCESS;
}


cl_context Newton_clCreateContext::
contexts[8] = {
  reinterpret_cast<cl_context>(0),
  reinterpret_cast<cl_context>(0x02c0293c),
  reinterpret_cast<cl_context>(0x192f7300),
  reinterpret_cast<cl_context>(0x0eb916ec),
  reinterpret_cast<cl_context>(0x50575d9a),
  reinterpret_cast<cl_context>(0xf1f1b0c6),
  reinterpret_cast<cl_context>(0x3f0165af),
  reinterpret_cast<cl_context>(0x3258d035)
};

cl_context Newton_clCreateContext::
clCreateContext(const cl_context_properties* properties,
                cl_uint num_devices,
                const cl_device_id* devices,
                void(CL_CALLBACK* pfn_notify)(const char*,const void*, size_t, void*),
                void* user_data,
                cl_int* errcode_ret)
{
  if(num_devices == 0 || devices == NULL
     || (pfn_notify == NULL && user_data != NULL)) {
    if(errcode_ret) {
      *errcode_ret = CL_INVALID_VALUE;
    }
    return NULL;
  }

  if(properties == NULL) {
    // no platform can be selected? (we have two platforms on newton)
    if(errcode_ret) {
      *errcode_ret = CL_INVALID_PLATFORM;
    }
    return NULL;
  }

  if(properties) {
    const cl_context_properties *p = properties;
    while(*p) {
      switch(*p) {
        case CL_CONTEXT_PLATFORM:
          p+=2;
          break;
        case CL_CONTEXT_INTEROP_USER_SYNC:
          p+=2;
          break;
        default:
          if(errcode_ret) {
            *errcode_ret = CL_INVALID_PROPERTY;
          }
          return NULL;
      }
    }
  }

  int ctx_i = 0;
  for(cl_uint i = 0; i < num_devices; ++i) {
    int dev_i = Newton_clGetDeviceIDs::find(devices[i]);
    if(dev_i == -1) {
      if(errcode_ret) {
        *errcode_ret = CL_INVALID_DEVICE;
      }
      return NULL;
    }
    ctx_i |= (1 << dev_i);
  }
  if(errcode_ret) {
    *errcode_ret = CL_SUCCESS;
  }
  return Newton_clCreateContext::contexts[ctx_i];
}

cl_context Newton_clCreateContextFromType::
clCreateContextFromType(const cl_context_properties*,
                        cl_device_type,
                        void(CL_CALLBACK*)(const char*, const void*, size_t, void*),
                        void*,
                        cl_int*)
{
  return NULL;
}

cl_int Newton_clRetainContext::
clRetainContext(cl_context context)
{
  return Newton_Context::retain(context);
}

cl_int Newton_clReleaseContext::
clReleaseContext(cl_context context)
{
  return Newton_Context::release(context);
}

} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */
/** \endcond */
#endif /* CLXX_CL_MOCKS_NEWTON_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
