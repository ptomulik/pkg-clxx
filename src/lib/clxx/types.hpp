// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/types.hpp

/** // doc: clxx/types.hpp {{{
 * \file clxx/types.hpp
 * \brief Plain types used across the CLXX library.
 *
 * This header defines most of the "plain" types, that is integers, enums and
 * so on, used across the CLXX library. The intent is to cover all the types
 * introduced by OpenCL standard with our own C++ types, mostly by an
 * appropriate strongly typed enums.
 */ // }}}
#ifndef CLXX_TYPES_HPP_INCLUDED
#define CLXX_TYPES_HPP_INCLUDED

#include <clxx/cl/cl.h>
#include <clxx/macros.hpp>

namespace clxx {
/** // doc: status_t {{{
 * \brief A value returned by several functions to indicate success or failure.
 *
 * Most OpenCL functions (such as \c clGetPlatforms(), \c clGetPlatformInfo(),
 * etc.) return an integer value of type \c cl_int to indicate success or
 * failure. The corresponding clxx functions return a value of type
 * \ref status_t. The \ref status_t enum covers all the error codes defined by
 * the OpenCL standard.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |  \check |  \check |  \check |  \check |  \check |
 *
 */ // }}}
enum class status_t : cl_int {
  /// Corresponds to \c CL_SUCCESS
  success                         = CL_SUCCESS,
  /// Corresponds to \c CL_DEVICE_NOT_FOUND
  device_not_found                = CL_DEVICE_NOT_FOUND,
  /// Corresponds to \c CL_DEVICE_NOT_AVAILABLE
  device_not_available            = CL_DEVICE_NOT_AVAILABLE,
  /// Corresponds to \c CL_COMPILER_NOT_AVAILABLE
  compiler_not_available          = CL_COMPILER_NOT_AVAILABLE,
  /// Corresponds to \c CL_MEM_OBJECT_ALLOCATION_FAILURE
  mem_object_allocation_failure   = CL_MEM_OBJECT_ALLOCATION_FAILURE,
  /// Corresponds to \c CL_OUT_OF_RESOURCES
  out_of_resources                = CL_OUT_OF_RESOURCES,
  /// Corresponds to \c CL_OUT_OF_HOST_MEMORY
  out_of_host_memory              = CL_OUT_OF_HOST_MEMORY,
  /// Corresponds to \c CL_PROFILING_INFO_NOT_AVAILABLE
  profiling_info_not_available    = CL_PROFILING_INFO_NOT_AVAILABLE,
  /// Corresponds to \c CL_MEM_COPY_OVERLAP
  mem_copy_overlap                = CL_MEM_COPY_OVERLAP,
  /// Corresponds to \c CL_IMAGE_FORMAT_MISMATCH
  image_format_mismatch           = CL_IMAGE_FORMAT_MISMATCH,
  /// Corresponds to \c CL_IMAGE_FORMAT_NOT_SUPPORTED
  image_format_not_supported      = CL_IMAGE_FORMAT_NOT_SUPPORTED,
  /// Corresponds to \c CL_BUILD_PROGRAM_FAILURE
  build_program_failure           = CL_BUILD_PROGRAM_FAILURE,
  /// Corresponds to \c CL_MAP_FAILURE
  map_failure                     = CL_MAP_FAILURE,
#if CLXX_CL_H_VERSION_1_1
  /// Corresponds to \c CL_MISALIGNED_SUB_BUFFER_OFFSET
  misaligned_sub_buffer_offset    = CL_MISALIGNED_SUB_BUFFER_OFFSET,
  /// Corresponds to \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST
  exec_status_error_for_events_in_wait_list = CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST,
#endif
#if CLXX_CL_H_VERSION_1_2
  /// Corresponds to \c CL_COMPILE_PROGRAM_FAILURE
  compile_program_failure         = CL_COMPILE_PROGRAM_FAILURE,
  /// Corresponds to \c CL_LINKER_NOT_AVAILABLE
  linker_not_available            = CL_LINKER_NOT_AVAILABLE,
  /// Corresponds to \c CL_LINK_PROGRAM_FAILURE
  link_program_failure            = CL_LINK_PROGRAM_FAILURE,
  /// Corresponds to \c CL_DEVICE_PARTITION_FAILED
  device_partition_failed         = CL_DEVICE_PARTITION_FAILED,
  /// Corresponds to \c CL_KERNEL_ARG_INFO_NOT_AVAILABLE
  kernel_arg_info_not_available   = CL_KERNEL_ARG_INFO_NOT_AVAILABLE,
#endif
  /// Corresponds to \c CL_INVALID_VALUE
  invalid_value                   = CL_INVALID_VALUE,
  /// Corresponds to \c CL_INVALID_DEVICE_TYPE
  invalid_device_type             = CL_INVALID_DEVICE_TYPE,
  /// Corresponds to \c CL_INVALID_PLATFORM
  invalid_platform                = CL_INVALID_PLATFORM,
  /// Corresponds to \c CL_INVALID_DEVICE
  invalid_device                  = CL_INVALID_DEVICE,
  /// Corresponds to \c CL_INVALID_CONTEXT
  invalid_context                 = CL_INVALID_CONTEXT,
  /// Corresponds to \c CL_INVALID_QUEUE_PROPERTIES
  invalid_queue_properties        = CL_INVALID_QUEUE_PROPERTIES,
  /// Corresponds to \c CL_INVALID_COMMAND_QUEUE
  invalid_command_queue           = CL_INVALID_COMMAND_QUEUE,
  /// Corresponds to \c CL_INVALID_HOST_PTR
  invalid_host_ptr                = CL_INVALID_HOST_PTR,
  /// Corresponds to \c CL_INVALID_MEM_OBJECT
  invalid_mem_object              = CL_INVALID_MEM_OBJECT,
  /// Corresponds to \c CL_INVALID_IMAGE_FORMAT_DESCRIPTOR
  invalid_image_format_descriptor = CL_INVALID_IMAGE_FORMAT_DESCRIPTOR,
  /// Corresponds to \c CL_INVALID_IMAGE_SIZE
  invalid_image_size              = CL_INVALID_IMAGE_SIZE,
  /// Corresponds to \c CL_INVALID_SAMPLER
  invalid_sampler                 = CL_INVALID_SAMPLER,
  /// Corresponds to \c CL_INVALID_BINARY
  invalid_binary                  = CL_INVALID_BINARY,
  /// Corresponds to \c CL_INVALID_BUILD_OPTIONS
  invalid_build_options           = CL_INVALID_BUILD_OPTIONS,
  /// Corresponds to \c CL_INVALID_PROGRAM
  invalid_program                 = CL_INVALID_PROGRAM,
  /// Corresponds to \c CL_INVALID_PROGRAM_EXECUTABLE
  invalid_program_executable      = CL_INVALID_PROGRAM_EXECUTABLE,
  /// Corresponds to \c CL_INVALID_KERNEL_NAME
  invalid_kernel_name             = CL_INVALID_KERNEL_NAME,
  /// Corresponds to \c CL_INVALID_KERNEL_DEFINITION
  invalid_kernel_definition       = CL_INVALID_KERNEL_DEFINITION,
  /// Corresponds to \c CL_INVALID_KERNEL
  invalid_kernel                  = CL_INVALID_KERNEL,
  /// Corresponds to \c CL_INVALID_ARG_INDEX
  invalid_arg_index               = CL_INVALID_ARG_INDEX,
  /// Corresponds to \c CL_INVALID_ARG_VALUE
  invalid_arg_value               = CL_INVALID_ARG_VALUE,
  /// Corresponds to \c CL_INVALID_ARG_SIZE
  invalid_arg_size                = CL_INVALID_ARG_SIZE,
  /// Corresponds to \c CL_INVALID_KERNEL_ARGS
  invalid_kernel_args             = CL_INVALID_KERNEL_ARGS,
  /// Corresponds to \c CL_INVALID_WORK_DIMENSION
  invalid_work_dimension          = CL_INVALID_WORK_DIMENSION,
  /// Corresponds to \c CL_INVALID_WORK_GROUP_SIZE
  invalid_work_group_size         = CL_INVALID_WORK_GROUP_SIZE,
  /// Corresponds to \c CL_INVALID_WORK_ITEM_SIZE
  invalid_work_item_size          = CL_INVALID_WORK_ITEM_SIZE,
  /// Corresponds to \c CL_INVALID_GLOBAL_OFFSET
  invalid_global_offset           = CL_INVALID_GLOBAL_OFFSET,
  /// Corresponds to \c CL_INVALID_EVENT_WAIT_LIST
  invalid_event_wait_list         = CL_INVALID_EVENT_WAIT_LIST,
  /// Corresponds to \c CL_INVALID_EVENT
  invalid_event                   = CL_INVALID_EVENT,
  /// Corresponds to \c CL_INVALID_OPERATION
  invalid_operation               = CL_INVALID_OPERATION,
  /// Corresponds to \c CL_INVALID_GL_OBJECT
  invalid_gl_object               = CL_INVALID_GL_OBJECT,
  /// Corresponds to \c CL_INVALID_BUFFER_SIZE
  invalid_buffer_size             = CL_INVALID_BUFFER_SIZE,
  /// Corresponds to \c CL_INVALID_MIP_LEVEL
  invalid_mip_level               = CL_INVALID_MIP_LEVEL,
  /// Corresponds to \c CL_INVALID_GLOBAL_WORK_SIZE
  invalid_global_work_size        = CL_INVALID_GLOBAL_WORK_SIZE
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_INVALID_PROPERTY
  invalid_property                = CL_INVALID_PROPERTY
#endif
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_INVALID_IMAGE_DESCRIPTOR
  invalid_image_descriptor        = CL_INVALID_IMAGE_DESCRIPTOR,
  /// Corresponds to \c CL_INVALID_COMPILER_OPTIONS
  invalid_compiler_options        = CL_INVALID_COMPILER_OPTIONS,
  /// Corresponds to \c CL_INVALID_LINKER_OPTIONS
  invalid_linker_options          = CL_INVALID_LINKER_OPTIONS,
  /// Corresponds to \c CL_INVALID_DEVICE_PARTITION_COUNT
  invalid_device_partition_count  = CL_INVALID_DEVICE_PARTITION_COUNT
#endif
#if CLXX_CL_H_VERSION_2_0
  ,
  /// Corresponds to \c CL_INVALID_PIPE_SIZE
  invalid_pipe_size               = CL_INVALID_PIPE_SIZE,
  /// Corresponds to \c CL_INVALID_DEVICE_QUEUE
  invalid_device_queue            = CL_INVALID_DEVICE_QUEUE
#endif
//
// codes defined by OpenCL extensions
//
#if cl_khr_icd
  ,
  /// Corresponds to CL_PLATFORM_NOT_FOUND_KHR
  platform_not_found_khr = CL_PLATFORM_NOT_FOUND_KHR
#endif
#if cl_ext_device_fission
  ,
  /// Corresponds to \c CL_DEVICE_PARTITION_FAILED_EXT
  device_partition_failed_ext = CL_DEVICE_PARTITION_FAILED_EXT,
  /// Corresponds to \c CL_INVALID_PARTITION_COUNT_EXT
  invalid_partition_count_ext = CL_INVALID_PARTITION_COUNT_EXT,
  /// Corresponds to \c CL_INVALID_PARTITION_NAME_EXT
  invalid_partition_name_ext = CL_INVALID_PARTITION_NAME_EXT
#endif
#if cl_khr_gl_sharing
  ,
  /// Corresponds to \c CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR
  invalid_gl_sharegroup_reference_khr = CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR
#endif
#if cl_khr_dx9_media_sharing
  ,
  /// Corresponds to \c CL_INVALID_DX9_MEDIA_ADAPTER_KHR
  invalid_dx9_media_adapter_khr = CL_INVALID_DX9_MEDIA_ADAPTER_KHR,
  /// Corresponds to \c CL_INVALID_DX9_MEDIA_SURFACE_KHR
  invalid_dx9_media_surface_khr = CL_INVALID_DX9_MEDIA_SURFACE_KHR,
  /// Corresponds to \c CL_DX9_MEDIA_SURFACE_ALREADY_ACQUIRED_KHR
  dx9_media_surface_already_acquired_khr = CL_DX9_MEDIA_SURFACE_ALREADY_ACQUIRED_KHR,
  /// Corresponds to \c CL_DX9_MEDIA_SURFACE_NOT_ACQUIRED_KHR
  dx9_media_surface_not_acquired_khr = CL_DX9_MEDIA_SURFACE_NOT_ACQUIRED_KHR
#endif
#if cl_khr_d3d10_sharing
  ,
  /// Corresponds to \c CL_INVALID_D3D10_DEVICE_KHR
  invalid_d3d10_device_khr = CL_INVALID_D3D10_DEVICE_KHR,
  /// Corresponds to \c CL_INVALID_D3D10_RESOURCE_KHR
  invalid_d3d10_resource_khr = CL_INVALID_D3D10_RESOURCE_KHR,
  /// Corresponds to \c CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR
  d3d10_resource_already_acquired_khr = CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR,
  /// Corresponds to \c CL_D3D10_RESOURCE_NOT_ACQUIRED_KHR
  d3d10_resource_not_acquired_khr = CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR,
#endif
#if cl_khr_d3d11_sharing
  ,
  /// Corresponds to \c CL_INVALID_D3D11_DEVICE_KHR
  invalid_d3d11_device_khr = CL_INVALID_D3D11_DEVICE_KHR,
  /// Corresponds to \c CL_INVALID_D3D11_RESOURCE_KHR
  invalid_d3d11_resource_khr = CL_INVALID_D3D11_RESOURCE_KHR,
  /// Corresponds to \c CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR
  d3d11_resource_already_acquired_khr = CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR,
  /// Corresponds to \c CL_D3D11_RESOURCE_NOT_ACQUIRED_KHR
  d3d11_resource_not_acquired_khr = CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR,
#endif
};

CLXX_MAKE_INTEGER_ENUM(status_t, cl_int)

/** // doc: is_success() {{{
 * \brief Check if the given result code represents a success.
 *
 * \param code Result code obtained from a clxx function.
 * \return \c true, if the code represents a success or \c false otherwise.
 */ // }}}
constexpr bool is_success(status_t code) noexcept
{ return code == status_t::success; }
/** // doc: is_error() {{{
 * \brief Check if the given status code represents an error.
 *
 * \param code Result code obtained from a clxx function.
 * \return \c true, if the code represents an error or \c false otherwise.
 */ // }}}
constexpr bool is_error(status_t code) noexcept
{ return static_cast<cl_int>(code) < 0; }

/** // doc: platform_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_platform_info.
 *
 * The \c cl_platform_info is used by \c clGetPlatformInfo() to select
 * particular OpenCL platform information to be queried from OpenCL platform
 * layer. The \ref platform_info_t is a C++ equivalent of the \c
 * cl_platform_info, its used by get_platform_info().
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |  \check |  \check |  \check |  \check |  \check |
 *
 */ // }}}
enum class platform_info_t : cl_platform_info {
  /// Corresponds to \c CL_PLATFORM_PROFILE
  profile    = CL_PLATFORM_PROFILE,
  /// Corresponds to \c CL_PLATFORM_VERSION
  version    = CL_PLATFORM_VERSION,
  /// Corresponds to \c CL_PLATFORM_NAME
  name       = CL_PLATFORM_NAME,
  /// Corresponds to \c CL_PLATFORM_VENDOR
  vendor     = CL_PLATFORM_VENDOR,
  /// Corresponds to \c CL_PLATFORM_EXTENSIONS
  extensions = CL_PLATFORM_EXTENSIONS
};

CLXX_MAKE_INTEGER_ENUM(platform_info_t, cl_platform_info)

/** // doc: device_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_type.
 *
 * The \c cl_device_type is used by \c clGetDeviceIDs() to filter-out unwanted
 * device types when retrieving a list of available OpenCL devices. The
 * \ref device_type_t is a C++ equivalent of the \c cl_device_type. It's used
 * by some of clxx functions, such as get_devices().
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |  \check |  \check |  \check |  \check |  \check |
 *
 */ // }}}
enum class device_type_t : cl_device_type {
  /// Zero
  none        = 0ul,
  /// Corresponds to \c CL_DEVICE_TYPE_DEFAULT
  default_    = CL_DEVICE_TYPE_DEFAULT,
  /// Corresponds to \c CL_DEVICE_TYPE_CPU
  cpu         = CL_DEVICE_TYPE_CPU,
  /// Corresponds to \c CL_DEVICE_TYPE_GPU
  gpu         = CL_DEVICE_TYPE_GPU,
  /// Corresponds to \c CL_DEVICE_TYPE_ACCELERATOR
  accelerator = CL_DEVICE_TYPE_ACCELERATOR,
#if CLXX_CL_H_VERSION_1_2
  /// Corresponds to \c CL_DEVICE_TYPE_CUSTOM
  custom      = CL_DEVICE_TYPE_CUSTOM,
#endif
  /// Corresponds to \c CL_DEVICE_TYPE_ALL
  all         = CL_DEVICE_TYPE_ALL
};

CLXX_MAKE_BITMASK_ENUM(device_type_t, cl_device_type)

/** // doc: device_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_info
 *
 * The \c cl_device_info is used by \c clGetDeviceInfo() to select
 * particular OpenCL device information to be queried from OpenCL device
 * layer. The \ref device_info_t is a C++ equivalent of the
 * \c cl_device_info, its used by get_device_info().
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |  \check |  \check |  \check |  \check |  \check |
 *
 */ // }}}
enum class device_info_t : cl_device_info {
  /// Corresponds to \c CL_DEVICE_TYPE
  type                           = CL_DEVICE_TYPE,
  /// Corresponds to \c CL_DEVICE_VENDOR_ID
  vendor_id                      = CL_DEVICE_VENDOR_ID,
  /// Corresponds to \c CL_DEVICE_MAX_COMPUTE_UNITS
  max_compute_units              = CL_DEVICE_MAX_COMPUTE_UNITS,
  /// Corresponds to \c CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS
  max_work_item_dimensions       = CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS,
  /// Corresponds to \c CL_DEVICE_MAX_WORK_GROUP_SIZE
  max_work_group_size            = CL_DEVICE_MAX_WORK_GROUP_SIZE,
  /// Corresponds to \c CL_DEVICE_MAX_WORK_ITEM_SIZES
  max_work_item_sizes            = CL_DEVICE_MAX_WORK_ITEM_SIZES,
  /// Corresponds to \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR
  preferred_vector_width_char    = CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR,
  /// Corresponds to \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT
  preferred_vector_width_short   = CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT,
  /// Corresponds to \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT
  preferred_vector_width_int     = CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT,
  /// Corresponds to \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG
  preferred_vector_width_long    = CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG,
  /// Corresponds to \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT
  preferred_vector_width_float   = CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT,
  /// Corresponds to \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE
  preferred_vector_width_double  = CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE,
  /// Corresponds to \c CL_DEVICE_MAX_CLOCK_FREQUENCY
  max_clock_frequency            = CL_DEVICE_MAX_CLOCK_FREQUENCY,
  /// Corresponds to \c CL_DEVICE_ADDRESS_BITS
  address_bits                   = CL_DEVICE_ADDRESS_BITS,
  /// Corresponds to \c CL_DEVICE_MAX_READ_IMAGE_ARGS
  max_read_image_args            = CL_DEVICE_MAX_READ_IMAGE_ARGS,
  /// Corresponds to \c CL_DEVICE_MAX_WRITE_IMAGE_ARGS
  max_write_image_args           = CL_DEVICE_MAX_WRITE_IMAGE_ARGS,
  /// Corresponds to \c CL_DEVICE_MAX_MEM_ALLOC_SIZE
  max_mem_alloc_size             = CL_DEVICE_MAX_MEM_ALLOC_SIZE,
  /// Corresponds to \c CL_DEVICE_IMAGE2D_MAX_WIDTH
  image2d_max_width              = CL_DEVICE_IMAGE2D_MAX_WIDTH,
  /// Corresponds to \c CL_DEVICE_IMAGE2D_MAX_HEIGHT
  image2d_max_height             = CL_DEVICE_IMAGE2D_MAX_HEIGHT,
  /// Corresponds to \c CL_DEVICE_IMAGE3D_MAX_WIDTH
  image3d_max_width              = CL_DEVICE_IMAGE3D_MAX_WIDTH,
  /// Corresponds to \c CL_DEVICE_IMAGE3D_MAX_HEIGHT
  image3d_max_height             = CL_DEVICE_IMAGE3D_MAX_HEIGHT,
  /// Corresponds to \c CL_DEVICE_IMAGE3D_MAX_DEPTH
  image3d_max_depth              = CL_DEVICE_IMAGE3D_MAX_DEPTH,
  /// Corresponds to \c CL_DEVICE_IMAGE_SUPPORT
  image_support                  = CL_DEVICE_IMAGE_SUPPORT,
  /// Corresponds to \c CL_DEVICE_MAX_PARAMETER_SIZE
  max_parameter_size             = CL_DEVICE_MAX_PARAMETER_SIZE,
  /// Corresponds to \c CL_DEVICE_MAX_SAMPLERS
  max_samplers                   = CL_DEVICE_MAX_SAMPLERS,
  /// Corresponds to \c CL_DEVICE_MEM_BASE_ADDR_ALIGN
  mem_base_addr_align            = CL_DEVICE_MEM_BASE_ADDR_ALIGN,
  /// Corresponds to \c CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE
  min_data_type_align_size       = CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE,
  /// Corresponds to \c CL_DEVICE_SINGLE_FP_CONFIG
  single_fp_config               = CL_DEVICE_SINGLE_FP_CONFIG,
  /// Corresponds to \c CL_DEVICE_GLOBAL_MEM_CACHE_TYPE
  global_mem_cache_type          = CL_DEVICE_GLOBAL_MEM_CACHE_TYPE,
  /// Corresponds to \c CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE
  global_mem_cacheline_size      = CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE,
  /// Corresponds to \c CL_DEVICE_GLOBAL_MEM_CACHE_SIZE
  global_mem_cache_size          = CL_DEVICE_GLOBAL_MEM_CACHE_SIZE,
  /// Corresponds to \c CL_DEVICE_GLOBAL_MEM_SIZE
  global_mem_size                = CL_DEVICE_GLOBAL_MEM_SIZE,
  /// Corresponds to \c CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE
  max_constant_buffer_size       = CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE,
  /// Corresponds to \c CL_DEVICE_MAX_CONSTANT_ARGS
  max_constant_args              = CL_DEVICE_MAX_CONSTANT_ARGS,
  /// Corresponds to \c CL_DEVICE_LOCAL_MEM_TYPE
  local_mem_type                 = CL_DEVICE_LOCAL_MEM_TYPE,
  /// Corresponds to \c CL_DEVICE_LOCAL_MEM_SIZE
  local_mem_size                 = CL_DEVICE_LOCAL_MEM_SIZE,
  /// Corresponds to \c CL_DEVICE_ERROR_CORRECTION_SUPPORT
  error_correction_support       = CL_DEVICE_ERROR_CORRECTION_SUPPORT,
  /// Corresponds to \c CL_DEVICE_PROFILING_TIMER_RESOLUTION
  profiling_timer_resolution     = CL_DEVICE_PROFILING_TIMER_RESOLUTION,
  /// Corresponds to \c CL_DEVICE_ENDIAN_LITTLE
  endian_little                  = CL_DEVICE_ENDIAN_LITTLE,
  /// Corresponds to \c CL_DEVICE_AVAILABLE
  available                      = CL_DEVICE_AVAILABLE,
  /// Corresponds to \c CL_DEVICE_COMPILER_AVAILABLE
  compiler_available             = CL_DEVICE_COMPILER_AVAILABLE,
  /// Corresponds to \c CL_DEVICE_EXECUTION_CAPABILITIES
  execution_capabilities         = CL_DEVICE_EXECUTION_CAPABILITIES,
  /// Corresponds to \c CL_DEVICE_QUEUE_PROPERTIES
  queue_properties               = CL_DEVICE_QUEUE_PROPERTIES,
  /// Corresponds to \c CL_DEVICE_NAME
  name                           = CL_DEVICE_NAME,
  /// Corresponds to \c CL_DEVICE_VENDOR
  vendor                         = CL_DEVICE_VENDOR,
  /// Corresponds to \c CL_DRIVER_VERSION
  driver_version                        = CL_DRIVER_VERSION,
  /// Corresponds to \c CL_DEVICE_PROFILE
  profile                        = CL_DEVICE_PROFILE,
  /// Corresponds to \c CL_DEVICE_VERSION
  version                        = CL_DEVICE_VERSION,
  /// Corresponds to \c CL_DEVICE_EXTENSIONS
  extensions                     = CL_DEVICE_EXTENSIONS,
  /// Corresponds to \c CL_DEVICE_PLATFORM
  platform                       = CL_DEVICE_PLATFORM
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_DEVICE_DOUBLE_FP_CONFIG
  double_fp_config               = CL_DEVICE_DOUBLE_FP_CONFIG
#endif
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF
  preferred_vector_width_half    = CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF,
  /// Corresponds to \c CL_DEVICE_HOST_UNIFIED_MEMORY
  host_unified_memory            = CL_DEVICE_HOST_UNIFIED_MEMORY,
  /// Corresponds to \c CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR
  native_vector_width_char       = CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR,
  /// Corresponds to \c CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT
  native_vector_width_short      = CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT,
  /// Corresponds to \c CL_DEVICE_NATIVE_VECTOR_WIDTH_INT
  native_vector_width_int        = CL_DEVICE_NATIVE_VECTOR_WIDTH_INT,
  /// Corresponds to \c CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG
  native_vector_width_long       = CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG,
  /// Corresponds to \c CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT
  native_vector_width_float      = CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT,
  /// Corresponds to \c CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE
  native_vector_width_double     = CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE,
  /// Corresponds to \c CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF
  native_vector_width_half       = CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF,
  /// Corresponds to \c CL_DEVICE_OPENCL_C_VERSION
  opencl_c_version               = CL_DEVICE_OPENCL_C_VERSION
#endif
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_DEVICE_LINKER_AVAILABLE
  linker_available               = CL_DEVICE_LINKER_AVAILABLE,
  /// Corresponds to \c CL_DEVICE_BUILT_IN_KERNELS
  built_in_kernels               = CL_DEVICE_BUILT_IN_KERNELS,
  /// Corresponds to \c CL_DEVICE_IMAGE_MAX_BUFFER_SIZE
  image_max_buffer_size          = CL_DEVICE_IMAGE_MAX_BUFFER_SIZE,
  /// Corresponds to \c CL_DEVICE_IMAGE_MAX_ARRAY_SIZE
  image_max_array_size           = CL_DEVICE_IMAGE_MAX_ARRAY_SIZE,
  /// Corresponds to \c CL_DEVICE_PARENT_DEVICE
  parent_device                  = CL_DEVICE_PARENT_DEVICE,
  /// Corresponds to \c CL_DEVICE_PARTITION_MAX_SUB_DEVICES
  partition_max_sub_devices      = CL_DEVICE_PARTITION_MAX_SUB_DEVICES,
  /// Corresponds to \c CL_DEVICE_PARTITION_PROPERTIES
  partition_properties           = CL_DEVICE_PARTITION_PROPERTIES,
  /// Corresponds to \c CL_DEVICE_PARTITION_AFFINITY_DOMAIN
  partition_affinity_domain      = CL_DEVICE_PARTITION_AFFINITY_DOMAIN,
  /// Corresponds to \c CL_DEVICE_PARTITION_TYPE
  partition_type                 = CL_DEVICE_PARTITION_TYPE,
  /// Corresponds to \c CL_DEVICE_REFERENCE_COUNT
  reference_count                = CL_DEVICE_REFERENCE_COUNT,
  /// Corresponds to \c CL_DEVICE_PREFERRED_INTEROP_USER_SYNC
  preferred_interop_user_sync    = CL_DEVICE_PREFERRED_INTEROP_USER_SYNC,
  /// Corresponds to \c CL_DEVICE_PRINTF_BUFFER_SIZE
  printf_buffer_size             = CL_DEVICE_PRINTF_BUFFER_SIZE,
  /// Corresponds to \c CL_DEVICE_IMAGE_PITCH_ALIGNMENT
  image_pitch_alignment          = CL_DEVICE_IMAGE_PITCH_ALIGNMENT,
  /// Corresponds to \c CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT
  image_base_address_alignment   = CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT
#endif
};

CLXX_MAKE_INTEGER_ENUM(device_info_t, cl_device_info)

/** // doc: device_fp_config_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_fp_config
 *
 * The OpenCL's \c cl_device_fp_config is returned by \c clGetDeviceInfo() when
 * querying for \c CL_DEVICE_SINGLE_FP_CONFIG or \c CL_DEVICE_DOUBLE_FP_CONFIG.
 * The \ref device_fp_config_t is a C++ equivalent of \c cl_device_fp_config.
 * It's returned by get_device_info() when querying for
 * device_info_t::single_fp_config or device_info_t::double_fp_config.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class device_fp_config_t : cl_device_fp_config {
  /// Zero
  none                           = 0ul,
  /// Corresponds to \c CL_FP_DENORM
  denorm                         = CL_FP_DENORM,
  /// Corresponds to \c CL_FP_INF_NAN
  inf_nan                        = CL_FP_INF_NAN,
  /// Corresponds to \c CL_FP_ROUND_TO_NEAREST
  round_to_nearest               = CL_FP_ROUND_TO_NEAREST,
  /// Corresponds to \c CL_FP_ROUND_TO_ZERO
  round_to_zero                  = CL_FP_ROUND_TO_ZERO,
  /// Corresponds to \c CL_FP_ROUND_TO_INF
  round_to_inf                   = CL_FP_ROUND_TO_INF,
  /// Corresponds to \c CL_FP_FMA
  fma                            = CL_FP_FMA
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_FP_SOFT_FLOAT
  soft_float                     = CL_FP_SOFT_FLOAT
#endif
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT
  correctly_rounded_divide_sqrt  = CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT
#endif
};

CLXX_MAKE_BITMASK_ENUM(device_fp_config_t, cl_device_fp_config)

/** // doc: device_mem_cache_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_mem_cache_type
 *
 * The OpenCL's \c cl_mem_cache_type is returned by \c clGetDeviceInfo() when
 * querying for \c CL_DEVICE_GLOBAL_MEM_CACHE_TYPE. The
 * \ref device_mem_cache_type_t is a C++ equivalent of \c cl_mem_cache_type.
 * It's returned by get_device_info() when querying for
 * device_info_t::global_mem_cache_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class device_mem_cache_type_t : cl_device_mem_cache_type {
  /// Corresponds to \c CL_NONE
  none              = CL_NONE,
  /// Corresponds to \c CL_READ_ONLY_CACHE
  read_only_cache   = CL_READ_ONLY_CACHE,
  /// Corresponds to \c CL_READ_WRITE_CACHE
  read_write_cache  = CL_READ_WRITE_CACHE
};

CLXX_MAKE_INTEGER_ENUM(device_mem_cache_type_t, cl_device_mem_cache_type)

/** // doc: device_local_mem_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_local_mem_type
 *
 * The OpenCL's \c cl_device_local_mem_type is returned by \c clGetDeviceInfo()
 * when querying for \c CL_DEVICE_LOCAL_MEM_TYPE. The
 * \ref device_local_mem_type_t is a C++ equivalent of
 * \c cl_device_local_mem_type. It's returned by get_device_info() when
 * querying for device_info_t::local_mem_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class device_local_mem_type_t : cl_device_local_mem_type {
  /// Corresponds to \c CL_LOCAL
  local   = CL_LOCAL,
  /// Corresponds to \c CL_GLOBAL
  global  = CL_GLOBAL
};

CLXX_MAKE_INTEGER_ENUM(device_local_mem_type_t, cl_device_local_mem_type)

/** // doc: device_exec_capabilities_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_exec_capabilities
 *
 * The OpenCL's \c cl_device_exec_capabilities is returned by
 * \c clGetDeviceInfo() when querying for \c CL_DEVICE_EXECUTION_CAPABILITIES.
 * The \ref device_exec_capabilities_t is a C++ equivalent of
 * \c cl_device_exec_capabilities. It's returned by get_device_info() when
 * querying for device_info_t::execution_capabilities.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class device_exec_capabilities_t : cl_device_exec_capabilities {
  /// Zero
  none           = 0ul,
  /// Corresponds to \c CL_EXEC_KERNEL
  kernel         = CL_EXEC_KERNEL,
  /// Corresponds to \c CL_EXEC_NATIVE_KERNEL
  native_kernel  = CL_EXEC_NATIVE_KERNEL
};

CLXX_MAKE_BITMASK_ENUM(device_exec_capabilities_t, cl_device_exec_capabilities)

/** // doc: device_command_queue_proerties_t {{{
 * \brief Corresponds to OpenCL's \c cl_command_queue_properties
 *
 * The OpenCL's \c cl_command_queue_properties is returned by
 * \c clGetDeviceInfo() when querying for CL_DEVICE_QUEUE_PROPERTIES. It's also
 * used by \c clCreateCommandQueue(). The \ref command_queue_properties_t is
 * a C++ equivalent of \c cl_command_queue_properties. It's returned by
 * get_device_info() when querying for device_info_t::queue_properties.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate how to map \c clCreateCommandQueue() case to CLXX.
 *
 */ // }}}
enum class command_queue_properties_t : cl_command_queue_properties {
  /// Zero
  none                          = 0ul,
  /// Corresponds to \c CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE
  out_of_order_exec_mode_enable = CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE,
  /// Corresponds to \c CL_QUEUE_PROFILING_ENABLE
  profiling_enable              = CL_QUEUE_PROFILING_ENABLE
};

CLXX_MAKE_BITMASK_ENUM(command_queue_properties_t, cl_command_queue_properties)

/** // doc: context_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_context_info
 *
 * The OpenCL's \c cl_context_info is used by \c clGetContextInfo() to select
 * particular context info to be queried from the OpenCL platform layer. The
 * \ref context_info_t is a C++ equivalent of the \c cl_context_info. It's used
 * by get_context_info() for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class context_info_t : cl_context_info {
  /// Corresponds to \c CL_CONTEXT_REFERENCE_COUNT
  reference_count = CL_CONTEXT_REFERENCE_COUNT,
  /// Corresponds to \c CL_CONTEXT_DEVICES
  devices         = CL_CONTEXT_DEVICES,
  /// Corresponds to \c CL_CONTEXT_PROPERTIES
  properties      = CL_CONTEXT_PROPERTIES
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_CONTEXT_NUM_DEVICES
  num_devices     = CL_CONTEXT_NUM_DEVICES
#endif
};

CLXX_MAKE_INTEGER_ENUM(context_info_t, cl_context_info)

/** // doc: context_properties_t {{{
 * \brief Correspons to OpenCL's \c cl_context_properties
 *
 * The OpenCL's \c cl_context_properties are returned by \c clGetContextInfo()
 * when querying for \c CL_CONTEXT_PROPERTIES. The \ref context_properties_t
 * is a C++ equivalent of \c cl_context_properties. It's returned by
 * get_context_properties() when querying for context_info_t::properties.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class context_properties_t : cl_context_properties {
  /// Corresponds to \c CL_CONTEXT_PLATFORM
  platform          = CL_CONTEXT_PLATFORM
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_CONTEXT_INTEROP_USER_SYNC
  interop_user_sync = CL_CONTEXT_INTEROP_USER_SYNC
#endif
#if cl_khr_gl_sharing
  ,
  /// Corresponds to \c CL_GL_CONTEXT_KHR
  gl_context_khr = CL_GL_CONTEXT_KHR,
  /// Corresponds to \c CL_EGL_DISPLAY_KHR
  egl_display_khr = CL_EGL_DISPLAY_KHR,
  /// Corresponds to \c CL_GLX_DISPLAY_KHR
  glx_display_khr = CL_GLX_DISPLAY_KHR,
  /// Corresponds to \c CL_WGL_HDC_KHR
  wgl_hdc_khr = CL_WGL_HDC_KHR,
  /// Corresponds to \c CL_CGL_SHAREGROUP_KHR
  cgl_sharegroup_khr = CL_CGL_SHAREGROUP_KHR
#endif
#if cl_khr_dx9_media_sharing
  ,
  /// Corresponds to \c CL_CONTEXT_ADAPTER_D3D9_KHR
  adapter_d3d9_khr = CL_CONTEXT_ADAPTER_D3D9_KHR,
  /// Corresponds to \c CL_CONTEXT_ADAPTER_D3D9EX_KHR
  adapter_d3d9ex_khr = CL_CONTEXT_ADAPTER_D3D9EX_KHR,
  /// Corresponds to \c CL_CONTEXT_ADAPTER_DXVA_KHR
  adapter_dxva_khr = CL_CONTEXT_ADAPTER_DXVA_KHR
#endif
#if cl_khr_d3d10_sharing
  ,
  /// Corresponds to \c CL_CONTEXT_D3D10_DEVICE_KHR
  d3d10_device_khr = CL_CONTEXT_D3D10_DEVICE_KHR
#endif
#if cl_khr_d3d11_sharing
  ,
  /// Corresponds to \c CL_CONTEXT_D3D11_DEVICE_KHR
  d3d11_device_khr = CL_CONTEXT_D3D11_DEVICE_KHR
#endif
};

CLXX_MAKE_INTEGER_ENUM(context_properties_t, cl_context_properties)

#if CLXX_CL_H_VERSION_1_2
/** // doc: device_partition_property_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_partition_property
 *
 * The OpenCL's \c cl_device_partition_property is returned by \c
 * clGetDeviceInfo() when querying for \c CL_DEVICE_PARTITION_PROPERTIES
 * or \c CL_DEVICE_PARTITION_TYPE. It's also used by \c clCreateSubDevices().
 * The \ref device_partition_property_t is a C++ equivalent of
 * \c cl_device_partition_property. It's returned by get_device_info() when
 * querying for device_info_t::partition_properties or
 * device_info_t::partition_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate how to cover the \c clCreateSubDevices() case.
 *
 */ // }}}
enum class device_partition_property_t : cl_device_partition_property {
  /// Corresponds to \c CL_DEVICE_PARTITION_EQUALLY
  equally            = CL_DEVICE_PARTITION_EQUALLY,
  /// Corresponds to \c CL_DEVICE_PARTITION_BY_COUNTS
  by_counts          = CL_DEVICE_PARTITION_BY_COUNTS,
  /// Corresponds to \c CL_DEVICE_PARTITION_BY_COUNTS_LIST_END
  by_counts_list_end = CL_DEVICE_PARTITION_BY_COUNTS_LIST_END,
  /// Corresponds to \c CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN
  by_affinity_domain = CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN
};

CLXX_MAKE_INTEGER_ENUM(device_partition_property_t, cl_device_partition_property)
#endif

#if CLXX_CL_H_VERSION_1_2
/** // doc: device_affinity_domain_t {{{
 * \brief Corresponds to OpenCL's \c cl_device_affinity_domain
 *
 * The OpenCL's \c cl_device_affinity_domain is returned by
 * \c clGetDeviceInfo() when querying for
 * \c CL_DEVICE_PARTITION_AFFINITY_DOMAIN. It's also used by
 * \c clCreateSubDevices(). The \ref device_affinity_domain_t is a C++
 * equivalent of \c cl_device_affinity_domain. It's returned by
 * get_device_info() when querying for
 * device_info_t::partition_affinity_domain.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate how to cover the \c clCreateSubDevices() case.
 *
 */ // }}}
enum class device_affinity_domain_t : cl_device_affinity_domain {
  /// Zero
  none               = 0ul,
  /// Corresponds to \c CL_DEVICE_AFFINITY_DOMAIN_NUMA
  numa               = CL_DEVICE_AFFINITY_DOMAIN_NUMA,
  /// Corresponds to \c CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE
  l4_cache           = CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE,
  /// Corresponds to \c CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE
  l3_cache           = CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE,
  /// Corresponds to \c CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE
  l2_cache           = CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE,
  /// Corresponds to \c CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE
  l1_cache           = CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE,
  /// Corresponds to \c CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE
  next_partitionable = CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE
};

CLXX_MAKE_BITMASK_ENUM(device_affinity_domain_t, cl_device_affinity_domain)
#endif

/** // doc: command_queue_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_command_queue_info
 *
 * The OpenCL's \c cl_command_queue_info is used by \c clGetCommandQueueInfo()
 * to select particular command queue information to be queried from OpenCL.
 * The \c command_queue_info_t is a C++ equivalent of cl_command_queue_info.
 * It's used by get_command_queue_info() for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class command_queue_info_t : cl_command_queue_info {
  /// Corresponds to \c CL_QUEUE_CONTEXT
  context         = CL_QUEUE_CONTEXT,
  /// Corresponds to \c CL_QUEUE_DEVICE
  device          = CL_QUEUE_DEVICE,
  /// Corresponds to \c CL_QUEUE_REFERENCE_COUNT
  reference_count = CL_QUEUE_REFERENCE_COUNT,
  /// Corresponds to \c CL_QUEUE_PROPERTIES
  properties      = CL_QUEUE_PROPERTIES
};

CLXX_MAKE_INTEGER_ENUM(command_queue_info_t, cl_command_queue_info)

/** // doc: mem_flags_t {{{
 * \brief Corresponds to OpenCL's \c cl_mem_flags
 *
 * The OpenCL's \c cl_mem_flags are used by \c clCreateSubBuffer(),
 * \c clCreateImage(), \c clGetSupportedImageFormats(), and
 * \c clGetMemObjectInfo(). The \ref mem_flags_t is a C++ equivalent of
 * the \c cl_mem_flags.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how the \ref clxx::mem_flags_t are used.
 *
 */ // }}}
enum class mem_flags_t : cl_mem_flags {
  /// Zero
  none            = 0ul,
  /// Corresponds to \c CL_MEM_READ_WRITE
  read_write      = CL_MEM_READ_WRITE,
  /// Corresponds to \c CL_MEM_WRITE_ONLY
  write_only      = CL_MEM_WRITE_ONLY,
  /// Corresponds to \c CL_MEM_READ_ONLY
  read_only       = CL_MEM_READ_ONLY,
  /// Corresponds to \c CL_MEM_USE_HOST_PTR
  use_host_ptr    = CL_MEM_USE_HOST_PTR,
  /// Corresponds to \c CL_MEM_ALLOC_HOST_PTR
  alloc_host_ptr  = CL_MEM_ALLOC_HOST_PTR,
  /// Corresponds to \c CL_MEM_COPY_HOST_PTR
  copy_host_ptr   = CL_MEM_COPY_HOST_PTR
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_MEM_HOST_WRITE_ONLY
  host_write_only = CL_MEM_HOST_WRITE_ONLY,
  /// Corresponds to \c CL_MEM_HOST_READ_ONLY
  host_read_only  = CL_MEM_HOST_READ_ONLY,
  /// Corresponds to \c CL_MEM_HOST_NO_ACCESS
  host_no_access  = CL_MEM_HOST_NO_ACCESS
#endif
};

CLXX_MAKE_BITMASK_ENUM(mem_flags_t, cl_mem_flags)

#if CLXX_CL_H_VERSION_1_2
/** // doc: mem_migration_flags_t {{{
 * \brief Correspond to OpenCL's \c cl_mem_migration_flags
 *
 * The OpenCL's \c cl_mem_migration_flags are used by
 * \c clEnqueueMigrateMemObjects(). The \ref mem_migration_flags_t is a
 * C++ equivalent of the \c cl_mem_migration_flags.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how is the \ref clxx::mem_migration_flags_t used.
 *
 */ // }}}
enum class mem_migration_flags_t : cl_mem_migration_flags {
  /// Zero
  none                         = 0ul,
  /// Corresponds to \c CL_MIGRATE_MEM_OBJECT_HOST
  mem_object_host              = CL_MIGRATE_MEM_OBJECT_HOST,
  /// Corresponds to \c CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED
  mem_object_content_undefined = CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED
};

CLXX_MAKE_BITMASK_ENUM(mem_migration_flags_t, cl_mem_migration_flags)
#endif

/** // doc: channel_order_t {{{
 * \brief Corresponds to OpenCL's \c cl_channel_order
 *
 * The OpenCL's \c cl_channel_order is used as an attribute in the
 * \c cl_image_format structure. The channel_order_t is a C++ equivalent of the
 * \c cl_channel_order.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how is the \ref clxx::channel_order_t used.
 *
 */ // }}}
enum class channel_order_t : cl_channel_order {
  /// Corresponds to \c CL_R
  r             = CL_R,
  /// Corresponds to \c CL_A
  a             = CL_A,
  /// Corresponds to \c CL_RG
  rg            = CL_RG,
  /// Corresponds to \c CL_RA
  ra            = CL_RA,
  /// Corresponds to \c CL_RGB
  rgb           = CL_RGB,
  /// Corresponds to \c CL_RGBA
  rgba          = CL_RGBA,
  /// Corresponds to \c CL_BGRA
  bgra          = CL_BGRA,
  /// Corresponds to \c CL_ARGB
  argb          = CL_ARGB,
  /// Corresponds to \c CL_INTENSITY
  intensity     = CL_INTENSITY,
  /// Corresponds to \c CL_LUMINANCE
  luminance     = CL_LUMINANCE
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_Rx
  rx            = CL_Rx,
  /// Corresponds to \c CL_RGx
  rgx           = CL_RGx,
  /// Corresponds to \c CL_RGBx
  rgbx          = CL_RGBx
#endif
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_DEPTH
  depth         = CL_DEPTH,
  /// Corresponds to \c CL_DEPTH_STENCIL
  depth_stencil = CL_DEPTH_STENCIL,
#endif
};

CLXX_MAKE_INTEGER_ENUM(channel_order_t, cl_channel_order)

/** // doc: channel_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_channel_type
 *
 * The OpenCL's \c cl_channel_type is used as an attribute in the
 * \c cl_image_format structure. The channel_type_t is a C++ equivalent of the
 * \c cl_channel_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how is the \ref clxx::channel_type_t used.
 *
 */ // }}}
enum class channel_type_t : cl_channel_type {
  /// Corresponds to \c CL_SNORM_INT8
  snorm_int8        = CL_SNORM_INT8,
  /// Corresponds to \c CL_SNORM_INT16
  snorm_int16       = CL_SNORM_INT16,
  /// Corresponds to \c CL_UNORM_INT8
  unorm_int8        = CL_UNORM_INT8,
  /// Corresponds to \c CL_UNORM_INT16
  unorm_int16       = CL_UNORM_INT16,
  /// Corresponds to \c CL_UNORM_SHORT_565
  unorm_short_565   = CL_UNORM_SHORT_565,
  /// Corresponds to \c CL_UNORM_SHORT_555
  unorm_short_555   = CL_UNORM_SHORT_555,
  /// Corresponds to \c CL_UNORM_INT_101010
  unorm_int_101010  = CL_UNORM_INT_101010,
  /// Corresponds to \c CL_SIGNED_INT8
  signed_int8       = CL_SIGNED_INT8,
  /// Corresponds to \c CL_SIGNED_INT16
  signed_int16      = CL_SIGNED_INT16,
  /// Corresponds to \c CL_SIGNED_INT32
  signed_int32      = CL_SIGNED_INT32,
  /// Corresponds to \c CL_UNSIGNED_INT8
  unsigned_int8     = CL_UNSIGNED_INT8,
  /// Corresponds to \c CL_UNSIGNED_INT16
  unsigned_int16    = CL_UNSIGNED_INT16,
  /// Corresponds to \c CL_UNSIGNED_INT32
  unsigned_int32    = CL_UNSIGNED_INT32,
  /// Corresponds to \c CL_HALF_FLOAT
  half_float        = CL_HALF_FLOAT,
  /// Corresponds to \c CL_FLOAT
  float_            = CL_FLOAT
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_UNORM_INT24
  unorm_int24       = CL_UNORM_INT24
#endif
};

CLXX_MAKE_INTEGER_ENUM(channel_type_t, cl_channel_type)

/** // doc: mem_object_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_mem_object_type
 *
 * The OpenCL's \c cl_mem_object_type is used by \c
 * clGetSupportedImageFormats(). It's returned by \c clGetMemObjectInfo() when
 * requesting for \c CL_MEM_TYPE. It's also used as a field in the \c
 * cl_image_desc structure. The mem_object_type_t is a C++ equivalent of the
 * \c cl_mem_object_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how is the \ref clxx::mem_object_type_t used.
 *
 */ // }}}
enum class mem_object_type_t : cl_mem_object_type {
  /// Corresponds to \c CL_MEM_OBJECT_BUFFER
  buffer         = CL_MEM_OBJECT_BUFFER,
  /// Corresponds to \c CL_MEM_OBJECT_IMAGE2D
  image2d        = CL_MEM_OBJECT_IMAGE2D,
  /// Corresponds to \c CL_MEM_OBJECT_IMAGE3D
  image3d        = CL_MEM_OBJECT_IMAGE3D
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_MEM_OBJECT_IMAGE2D_ARRAY
  image2d_array  = CL_MEM_OBJECT_IMAGE2D_ARRAY,
  /// Corresponds to \c CL_MEM_OBJECT_IMAGE1D
  image1d        = CL_MEM_OBJECT_IMAGE1D,
  /// Corresponds to \c CL_MEM_OBJECT_IMAGE1D_ARRAY
  image1d_array  = CL_MEM_OBJECT_IMAGE1D_ARRAY,
  /// Corresponds to \c CL_MEM_OBJECT_IMAGE1D_BUFFER
  image1d_buffer = CL_MEM_OBJECT_IMAGE1D_BUFFER
#endif
};

CLXX_MAKE_INTEGER_ENUM(mem_object_type_t, cl_mem_object_type)

/** // doc: mem_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_mem_info
 *
 * The OpenCL's \c cl_mem_info is used by \c clGetMemObjectInfo() to select
 * particular information to be queried from OpenCL. The \ref mem_info_t is
 * a C++ equivalent of the \c cl_mem_info. It's used by gt_mem_object_info()
 * for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class mem_info_t : cl_mem_info {
  /// Corresponds to \c CL_MEM_TYPE
  type                  = CL_MEM_TYPE,
  /// Corresponds to \c CL_MEM_FLAGS
  flags                 = CL_MEM_FLAGS,
  /// Corresponds to \c CL_MEM_SIZE
  size                  = CL_MEM_SIZE,
  /// Corresponds to \c CL_MEM_HOST_PTR
  host_ptr              = CL_MEM_HOST_PTR,
  /// Corresponds to \c CL_MEM_MAP_COUNT
  map_count             = CL_MEM_MAP_COUNT,
  /// Corresponds to \c CL_MEM_REFERENCE_COUNT
  reference_count       = CL_MEM_REFERENCE_COUNT,
  /// Corresponds to \c CL_MEM_CONTEXT
  context               = CL_MEM_CONTEXT
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_MEM_ASSOCIATED_MEMOBJECT
  associated_memobject  = CL_MEM_ASSOCIATED_MEMOBJECT,
  /// Corresponds to \c CL_MEM_OFFSET
  offset                = CL_MEM_OFFSET
#endif
#if CLXX_CL_H_VERSION_2_0
  ,
  /// Corresponds to \c CL_MEM_USES_SVM_POINTER
  uses_svm_pointer      = CL_MEM_USES_SVM_POINTER
#endif
};

CLXX_MAKE_INTEGER_ENUM(mem_info_t, cl_mem_info)

/** // doc: image_info_t {{{
 * \brief Corresponds to OpenCL's cl_image_info
 *
 * The OpenCL's \c cl_image_info is used by \c clGetImageInfo() to select
 * particular information to be queried from OpenCL. The \ref image_info_t is
 * a C++ equivalent of the \c cl_image_info. It's used by gt_image_info()
 * for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class image_info_t : cl_image_info {
  /// Corresponds to \c CL_IMAGE_FORMAT
  format          = CL_IMAGE_FORMAT,
  /// Corresponds to \c CL_IMAGE_ELEMENT_SIZE
  element_size    = CL_IMAGE_ELEMENT_SIZE,
  /// Corresponds to \c CL_IMAGE_ROW_PITCH
  row_pitch       = CL_IMAGE_ROW_PITCH,
  /// Corresponds to \c CL_IMAGE_SLICE_PITCH
  slice_pitch     = CL_IMAGE_SLICE_PITCH,
  /// Corresponds to \c CL_IMAGE_WIDTH
  width           = CL_IMAGE_WIDTH,
  /// Corresponds to \c CL_IMAGE_HEIGHT
  height          = CL_IMAGE_HEIGHT,
  /// Corresponds to \c CL_IMAGE_DEPTH
  depth           = CL_IMAGE_DEPTH
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_IMAGE_ARRAY_SIZE
  array_size      = CL_IMAGE_ARRAY_SIZE,
  /// Corresponds to \c CL_IMAGE_BUFFER
  buffer          = CL_IMAGE_BUFFER,
  /// Corresponds to \c CL_IMAGE_NUM_MIP_LEVELS
  num_mip_levels  = CL_IMAGE_NUM_MIP_LEVELS,
  /// Corresponds to \c CL_IMAGE_NUM_SAMPLES
  num_samples     = CL_IMAGE_NUM_SAMPLES
#endif
};

CLXX_MAKE_INTEGER_ENUM(image_info_t, cl_image_info)

/** // doc: addressing_mode_t {{{
 * \brief Corresponds to OpenCL's cl_addressing_mode
 *
 * The OpenCL's \c cl_addressing_mode is used by \c clCreateSampler(). The
 * \ref addressing_mode_t is a C++ equivalent of the \c cl_addressing_mode.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how is the \ref clxx::addressing_mode_t used.
 *
 */ // }}}
enum class addressing_mode_t : cl_addressing_mode {
  /// Corresponds to \c CL_ADDRESS_NONE
  none            = CL_ADDRESS_NONE,
  /// Corresponds to \c CL_ADDRESS_CLAMP_TO_EDGE
  clamp_to_edge   = CL_ADDRESS_CLAMP_TO_EDGE,
  /// Corresponds to \c CL_ADDRESS_CLAMP
  clamp           = CL_ADDRESS_CLAMP,
  /// Corresponds to \c CL_ADDRESS_REPEAT
  repeat          = CL_ADDRESS_REPEAT
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_ADDRESS_MIRRORED_REPEAT
  mirrored_repeat = CL_ADDRESS_MIRRORED_REPEAT
#endif
};

CLXX_MAKE_INTEGER_ENUM(addressing_mode_t, cl_addressing_mode)

/** // doc: filter_mode_t {{{
 * \brief Corresponds to OpenCL's \c cl_filter_mode
 *
 * The OpenCL's \c cl_filter_mode is used by \c clCreateSampler(). It's also
 * returned by \c clGetSamplerInfo() when querying for
 * \c CL_SAMPLER_FILTER_MODE. The \ref filter_mode_t is a C++ equivalent of the
 * \c cl_filter_mode. It's returned by get_sampler_info() when querying for the
 * sampler_info_t::filter_mode.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate how to cover the \c clCreateSampler() case.
 *
 */ // }}}
enum class filter_mode_t : cl_filter_mode {
  /// Corresponds to \c CL_FILTER_NEAREST
  nearest  = CL_FILTER_NEAREST,
  /// Corresponds to \c CL_FILTER_LINEAR
  linear   = CL_FILTER_LINEAR
};

CLXX_MAKE_INTEGER_ENUM(filter_mode_t, cl_filter_mode)

/** // doc: sampler_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_sampler_info
 *
 * The OpenCL's \c cl_sampler_info is used by \c clGetSamplerInfo() to select
 * particular information to be retrieved from the OpenCL.
 * The \ref sampler_info_t is a C++ equivalent of the \c cl_sampler_info. It's
 * used by get_sampler_info() for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class sampler_info_t : cl_sampler_info {
  /// Corresponds to \c CL_SAMPLER_REFERENCE_COUNT
  reference_count   = CL_SAMPLER_REFERENCE_COUNT,
  /// Corresponds to \c CL_SAMPLER_CONTEXT
  context           = CL_SAMPLER_CONTEXT,
  /// Corresponds to \c CL_SAMPLER_NORMALIZED_COORDS
  normalized_coords = CL_SAMPLER_NORMALIZED_COORDS,
  /// Corresponds to \c CL_SAMPLER_ADDRESSING_MODE
  addressing_mode   = CL_SAMPLER_ADDRESSING_MODE,
  /// Corresponds to \c CL_SAMPLER_FILTER_MODE
  filter_mode       = CL_SAMPLER_FILTER_MODE
};

CLXX_MAKE_INTEGER_ENUM(sampler_info_t, cl_sampler_info)

/** // doc: map_flags_t {{{
 * \brief Corresponds to OpenCL's cl_map_flags
 *
 * The OpenCL's \c cl_map_flags are used by \c clEnqueueMaBuffer() and
 * \c clEnqueueMapImage(). The \ref map_flags_t is a C++ equivalent of the
 * \c cl_map_flags.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how are the clxx::map_flags_t used.
 *
 */ // }}}
enum class map_flags_t : cl_map_flags {
  /// Zero
  none                    = 0ul,
  /// Corresponds to \c CL_MAP_READ
  read                    = CL_MAP_READ,
  /// Corresponds to \c CL_MAP_WRITE
  write                   = CL_MAP_WRITE
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_MAP_WRITE_INVALIDATE_REGION
  write_invalidate_region = CL_MAP_WRITE_INVALIDATE_REGION
#endif
};

CLXX_MAKE_BITMASK_ENUM(map_flags_t, cl_map_flags)

/** // doc: program_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_program_info
 *
 * The OpenCL's \c cl_program_info is used by \c clProgramInfo() to select
 * particular information to be queried form the OpenCL platform layer. The
 * \ref program_info_t is a C++ equivalent of the \c cl_program_info. It's used
 * by get_platform_info() for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class program_info_t : cl_program_info {
  /// Corresponds to \c CL_PROGRAM_REFERENCE_COUNT
  reference_count = CL_PROGRAM_REFERENCE_COUNT,
  /// Corresponds to \c CL_PROGRAM_CONTEXT
  context         = CL_PROGRAM_CONTEXT,
  /// Corresponds to \c CL_PROGRAM_NUM_DEVICES
  num_devices     = CL_PROGRAM_NUM_DEVICES,
  /// Corresponds to \c CL_PROGRAM_DEVICES
  devices         = CL_PROGRAM_DEVICES,
  /// Corresponds to \c CL_PROGRAM_SOURCE
  source          = CL_PROGRAM_SOURCE,
  /// Corresponds to \c CL_PROGRAM_BINARY_SIZES
  binary_sizes    = CL_PROGRAM_BINARY_SIZES,
  /// Corresponds to \c CL_PROGRAM_BINARIES
  binaries        = CL_PROGRAM_BINARIES
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_PROGRAM_NUM_KERNELS
  num_kernels     = CL_PROGRAM_NUM_KERNELS,
  /// Corresponds to \c CL_PROGRAM_KERNEL_NAMES
  kernel_names    = CL_PROGRAM_KERNEL_NAMES
#endif
};

CLXX_MAKE_INTEGER_ENUM(program_info_t, cl_program_info)

/** // doc: program_build_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_program_build_info
 *
 * The OpenCL's \c cl_program_build_info is used by \c clGetProgramBuildInfo()
 * to select particular information to be qeuried from the OpenCL. The
 * \ref program_build_info_t is a C++ equivalent of the
 * \c cl_program_build_info. It's used by get_program_build_info() for the
 * same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class program_build_info_t : cl_program_build_info {
  /// Corresponds to \c CL_PROGRAM_BUILD_STATUS
  status      = CL_PROGRAM_BUILD_STATUS,
  /// Corresponds to \c CL_PROGRAM_BUILD_OPTIONS
  options     = CL_PROGRAM_BUILD_OPTIONS,
  /// Corresponds to \c CL_PROGRAM_BUILD_LOG
  log         = CL_PROGRAM_BUILD_LOG
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_PROGRAM_BINARY_TYPE
  binary_type = CL_PROGRAM_BINARY_TYPE
#endif
};

CLXX_MAKE_INTEGER_ENUM(program_build_info_t, cl_program_build_info)

#if CLXX_CL_H_VERSION_1_2
/** // doc: program_binary_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_program_binary_type
 *
 * The OpenCL's \c cl_program_binary_type is returned by
 * \c clGetProgramBuildInfo() when querying for \c CL_PROGRAM_BINARY_TYPE.
 * The \ref program_binary_type_t is a C++ equivalent of the
 * \c cl_program_binary_type. It's returned by get_program_build_info() when
 * querying for program_build_info_t::binary_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class program_binary_type_t : cl_program_binary_type {
  /// Corresponds to \c CL_PROGRAM_BINARY_TYPE_NONE
  none            = CL_PROGRAM_BINARY_TYPE_NONE,
  /// Corresponds to \c CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT
  compiled_object = CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT,
  /// Corresponds to \c CL_PROGRAM_BINARY_TYPE_LIBRARY
  library         = CL_PROGRAM_BINARY_TYPE_LIBRARY,
  /// Corresponds to \c CL_PROGRAM_BINARY_TYPE_EXECUTABLE
  executable      = CL_PROGRAM_BINARY_TYPE_EXECUTABLE
};

CLXX_MAKE_BITMASK_ENUM(program_binary_type_t, cl_program_binary_type)
#endif

/** // doc: build_status_t {{{
 * \brief Corresponds to OpenCL's \c cl_build_status
 *
 * The OpenCL's \c cl_build_status is returned by \c clGetProgramBuildInfo()
 * when querying for \c CL_PROGRAM_BUILD_STATUS. The \ref build_status_t is
 * a C++ equivalent of the \c cl_build_status. It's returned by
 * get_program_build_info() when querying for program_build_info_t::status.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class build_status_t : cl_build_status {
  /// Corresponds to \c CL_BUILD_SUCCESS
  success     = CL_BUILD_SUCCESS,
  /// Corresponds to \c CL_BUILD_NONE
  none        = CL_BUILD_NONE,
  /// Corresponds to \c CL_BUILD_ERROR
  error       = CL_BUILD_ERROR,
  /// Corresponds to \c CL_BUILD_IN_PROGRESS
  in_progress = CL_BUILD_IN_PROGRESS
};

CLXX_MAKE_INTEGER_ENUM(build_status_t, cl_build_status)

/** // doc: is_success {{{
 * \brief Check if the given build status represents a success.
 *
 * \param status Build status obtained from a clxx function.
 * \return \c true, if the **status** represents a success or \c false
 * otherwise.
 */ // }}}
constexpr bool is_success(build_status_t status)
{ return status == build_status_t::success; }
/** // doc: is_error {{{
 * \brief Check if the given build status represents a success.
 *
 * \param status Build status obtained from a clxx function.
 * \return \c true, if the **status** represents a success or \c false
 * otherwise.
 */ // }}}
constexpr bool is_error(build_status_t status)
{ return !is_success(status); }

/** // doc: kernel_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_kernel_info
 *
 * The OpenCL's \c cl_kernel_info is used by \c clGetKernelInfo() to select
 * particular information to be retrieved from OpenCL. The \ref kernel_info_t
 * is a C++ equivalent of the \c cl_kernel_info. It's used by get_kernel_info()
 * for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class kernel_info_t : cl_kernel_info {
  /// Corresponds to \c CL_KERNEL_FUNCTION_NAME
  function_name    = CL_KERNEL_FUNCTION_NAME,
  /// Corresponds to \c CL_KERNEL_NUM_ARGS
  num_args         = CL_KERNEL_NUM_ARGS,
  /// Corresponds to \c CL_KERNEL_REFERENCE_COUNT
  reference_count  = CL_KERNEL_REFERENCE_COUNT,
  /// Corresponds to \c CL_KERNEL_CONTEXT
  context          = CL_KERNEL_CONTEXT,
  /// Corresponds to \c CL_KERNEL_PROGRAM
  program          = CL_KERNEL_PROGRAM
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_KERNEL_ATTRIBUTES
  attributes       = CL_KERNEL_ATTRIBUTES
#endif
};

CLXX_MAKE_INTEGER_ENUM(kernel_info_t, cl_kernel_info)

#if CLXX_CL_H_VERSION_1_2
/** // doc: kernel_arg_info_t {{{
 * \brief Corresponds to \c cl_kernel_arg_info
 *
 * The OpenCL's \c cl_kernel_arg_info is used by \c clGetKernelArgInfo() to
 * select particular information to be queried from the OpenCL. The
 * \ref kernel_arg_info_t is a C++ equivalent of the \c cl_kernel_arg_info.
 * It's used by get_kernel_arg_info() for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class kernel_arg_info_t : cl_kernel_arg_info {
  /// Corresponds to \c CL_KERNEL_ARG_ADDRESS_QUALIFIER
  address_qualifier  = CL_KERNEL_ARG_ADDRESS_QUALIFIER,
  /// Corresponds to \c CL_KERNEL_ARG_ACCESS_QUALIFIER
  access_qualifier   = CL_KERNEL_ARG_ACCESS_QUALIFIER,
  /// Corresponds to \c CL_KERNEL_ARG_TYPE_NAME
  type_name          = CL_KERNEL_ARG_TYPE_NAME,
  /// Corresponds to \c CL_KERNEL_ARG_TYPE_QUALIFIER
  type_qualifier     = CL_KERNEL_ARG_TYPE_QUALIFIER,
  /// Corresponds to \c CL_KERNEL_ARG_NAME
  name               = CL_KERNEL_ARG_NAME
};

CLXX_MAKE_INTEGER_ENUM(kernel_arg_info_t, cl_kernel_arg_info)
#endif

#if CLXX_CL_H_VERSION_2_0
/** // doc: kernel_exec_info_t {{{
 * \brief Corresponds to \c cl_kernel_exec_info
 *
 * The OpenCL's \c cl_kernel_exec_info is used by \c clSetKernelExecInfo(). The
 * \ref kernel_exec_info_t is a C++ equivalent of the \c cl_kernel_exec_info.
 * It's used by set_kernel_exec_info() for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |           |   \check  |    ???    |
 *
 */ // }}}
enum class kernel_exec_info_t : cl_kernel_exec_info {
  /// Corresponds to \c CL_KERNEL_EXEC_INFO_SVM_PTRS
  svm_ptrs              = CL_KERNEL_EXEC_INFO_SVM_PTRS,
  /// Corresponds to \c CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM
  svm_fine_grain_system = CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM
};

CLXX_MAKE_INTEGER_ENUM(kernel_exec_info_t, cl_kernel_exec_info)
#endif

#if CLXX_CL_H_VERSION_1_2
/** // doc: kernel_arg_address_qualifier_t {{{
 * \brief Corresponds to OpenCL's \c cl_kernel_arg_address_qualifier
 *
 * The OpenCL's \c cl_kernel_arg_address_qualifier is returned by
 * \c clGetKernelArgInfo() when querying for
 * \c CL_KERNEL_ARG_ADDRESS_QUALIFIER. The \ref kernel_arg_address_qualifier_t
 * is a C++ equivalent of the \c cl_kernel_arg_address_qualifier. It's returned
 * by get_kernel_arg_info() when querying for
 * kernel_arg_info_t::address_qualifier.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class kernel_arg_address_qualifier_t : cl_kernel_arg_address_qualifier {
  /// Corresponds to \c CL_KERNEL_ARG_ADDRESS_GLOBAL
  global    = CL_KERNEL_ARG_ADDRESS_GLOBAL,
  /// Corresponds to \c CL_KERNEL_ARG_ADDRESS_LOCAL
  local     = CL_KERNEL_ARG_ADDRESS_LOCAL,
  /// Corresponds to \c CL_KERNEL_ARG_ADDRESS_CONSTANT
  constant  = CL_KERNEL_ARG_ADDRESS_CONSTANT,
  /// Corresponds to \c CL_KERNEL_ARG_ADDRESS_PRIVATE
  private_  = CL_KERNEL_ARG_ADDRESS_PRIVATE
};

CLXX_MAKE_INTEGER_ENUM(kernel_arg_address_qualifier_t, cl_kernel_arg_address_qualifier)
#endif

#if CLXX_CL_H_VERSION_1_2
/** // doc: kernel_arg_access_qualifier_t {{{
 * \brief Corresponds to OpenCL's \c cl_kernel_arg_access_qualifier
 *
 * The OpenCL's \c cl_kernel_arg_access_qualifier is returned by
 * \c clGetKernelArgInfo() when querying for
 * \c CL_KERNEL_ARG_ACCESS_QUALIFIER. The \ref kernel_arg_access_qualifier_t
 * is a C++ equivalent of the \c cl_kernel_arg_access_qualifier. It's returned
 * by get_kernel_arg_info() when querying for
 * kernel_arg_info_t::access_qualifier.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class kernel_arg_access_qualifier_t : cl_kernel_arg_access_qualifier {
  /// Corresponds to \c CL_KERNEL_ARG_ACCESS_READ_ONLY
  read_only   = CL_KERNEL_ARG_ACCESS_READ_ONLY,
  /// Corresponds to \c CL_KERNEL_ARG_ACCESS_WRITE_ONLY
  write_only  = CL_KERNEL_ARG_ACCESS_WRITE_ONLY,
  /// Corresponds to \c CL_KERNEL_ARG_ACCESS_READ_WRITE
  read_write  = CL_KERNEL_ARG_ACCESS_READ_WRITE,
  /// Corresponds to \c CL_KERNEL_ARG_ACCESS_NONE
  none        = CL_KERNEL_ARG_ACCESS_NONE
};

CLXX_MAKE_INTEGER_ENUM(kernel_arg_access_qualifier_t, cl_kernel_arg_access_qualifier)
#endif

#if CLXX_CL_H_VERSION_1_2
/** // doc: kernel_arg_type_qualifier_t {{{
 * \brief Corresponds to OpenCL's \c cl_kernel_arg_type_qualifier
 *
 * The OpenCL's \c cl_kernel_arg_type_qualifier is returned by
 * \c clGetKernelArgInfo() when querying for
 * \c CL_KERNEL_ARG_TYPE_QUALIFIER. The \ref kernel_arg_type_qualifier_t
 * is a C++ equivalent of the \c cl_kernel_arg_type_qualifier. It's returned
 * by get_kernel_arg_info() when querying for
 * kernel_arg_info_t::type_qualifier.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class kernel_arg_type_qualifier_t : cl_kernel_arg_type_qualifier {
  /// Corresponds to \c CL_KERNEL_ARG_TYPE_NONE
  none       = CL_KERNEL_ARG_TYPE_NONE,
  /// Corresponds to \c CL_KERNEL_ARG_TYPE_CONST
  const_     = CL_KERNEL_ARG_TYPE_CONST,
  /// Corresponds to \c CL_KERNEL_ARG_TYPE_RESTRICT
  restrict_  = CL_KERNEL_ARG_TYPE_RESTRICT,
  /// Corresponds to \c CL_KERNEL_ARG_TYPE_VOLATILE
  volatile_  = CL_KERNEL_ARG_TYPE_VOLATILE
};

CLXX_MAKE_BITMASK_ENUM(kernel_arg_type_qualifier_t, cl_kernel_arg_type_qualifier)
#endif

/** // doc: kernel_work_group_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_kernel_work_group_info
 *
 * The OpenCL's \c cl_kernel_work_group_info is used by
 * \c clGetKernelWorkGroupInfo() to select particular information to be queried
 * from the OpenCL. The \ref kernel_work_group_info_t is a C++ equivalent of
 * the \c cl_kernel_work_group_info. It's used by get_kernel_work_group_info()
 * for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class kernel_work_group_info_t : cl_kernel_work_group_info {
  /// Corresponds to \c CL_KERNEL_WORK_GROUP_SIZE
  work_group_size                    = CL_KERNEL_WORK_GROUP_SIZE,
  /// Corresponds to \c CL_KERNEL_COMPILE_WORK_GROUP_SIZE
  compile_work_group_size            = CL_KERNEL_COMPILE_WORK_GROUP_SIZE,
  /// Corresponds to \c CL_KERNEL_LOCAL_MEM_SIZE
  local_mem_size                     = CL_KERNEL_LOCAL_MEM_SIZE
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE
  preferred_work_group_size_multiple = CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE,
  /// Corresponds to \c CL_KERNEL_PRIVATE_MEM_SIZE
  private_mem_size                   = CL_KERNEL_PRIVATE_MEM_SIZE
#endif
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_KERNEL_GLOBAL_WORK_SIZE
  global_work_size                   = CL_KERNEL_GLOBAL_WORK_SIZE
#endif
};

CLXX_MAKE_INTEGER_ENUM(kernel_work_group_info_t, cl_kernel_work_group_info)

/** // doc: event_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_event_info
 *
 * \brief Corresponds to OpenCL's \c cl_event_info
 *
 * The OpenCL's \c cl_event_info is used by \c clGetEventInfo() to select
 * particular information to be queried from the OpenCL. The \ref event_info_t
 * is a C++ equivalent of the \c cl_event_info. It's used by get_event_info()
 * for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class event_info_t : cl_event_info {
  /// Corresponds to \c CL_EVENT_COMMAND_QUEUE
  command_queue             = CL_EVENT_COMMAND_QUEUE,
  /// Corresponds to \c CL_EVENT_COMMAND_TYPE
  command_type              = CL_EVENT_COMMAND_TYPE,
  /// Corresponds to \c CL_EVENT_REFERENCE_COUNT
  reference_count           = CL_EVENT_REFERENCE_COUNT,
  /// Corresponds to \c CL_EVENT_COMMAND_EXECUTION_STATUS
  command_execution_status  = CL_EVENT_COMMAND_EXECUTION_STATUS
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_EVENT_CONTEXT
  context                   = CL_EVENT_CONTEXT
#endif
};

CLXX_MAKE_INTEGER_ENUM(event_info_t, cl_event_info)

/** // doc: command_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_commant_type
 *
 * The OpenCL's \c cl_command_type is returned by \c clGetEventInfo() when
 * querying for \c CL_EVENT_COMMAND_TYPE. The \ref command_type_t is a C++
 * equivalent of the \c cl_command_type. It's returned by get_event_info()
 * when querying for event_info_t::command_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class command_type_t : cl_command_type {
  /// Corresponds to \c CL_COMMAND_NDRANGE_KERNEL
  ndrange_kernel        = CL_COMMAND_NDRANGE_KERNEL,
  /// Corresponds to \c CL_COMMAND_TASK
  task                  = CL_COMMAND_TASK,
  /// Corresponds to \c CL_COMMAND_NATIVE_KERNEL
  native_kernel         = CL_COMMAND_NATIVE_KERNEL,
  /// Corresponds to \c CL_COMMAND_READ_BUFFER
  read_buffer           = CL_COMMAND_READ_BUFFER,
  /// Corresponds to \c CL_COMMAND_WRITE_BUFFER
  write_buffer          = CL_COMMAND_WRITE_BUFFER,
  /// Corresponds to \c CL_COMMAND_COPY_BUFFER
  copy_buffer           = CL_COMMAND_COPY_BUFFER,
  /// Corresponds to \c CL_COMMAND_READ_IMAGE
  read_image            = CL_COMMAND_READ_IMAGE,
  /// Corresponds to \c CL_COMMAND_WRITE_IMAGE
  write_image           = CL_COMMAND_WRITE_IMAGE,
  /// Corresponds to \c CL_COMMAND_COPY_IMAGE
  copy_image            = CL_COMMAND_COPY_IMAGE,
  /// Corresponds to \c CL_COMMAND_COPY_IMAGE_TO_BUFFER
  copy_image_to_buffer  = CL_COMMAND_COPY_IMAGE_TO_BUFFER,
  /// Corresponds to \c CL_COMMAND_COPY_BUFFER_TO_IMAGE
  copy_buffer_to_image  = CL_COMMAND_COPY_BUFFER_TO_IMAGE,
  /// Corresponds to \c CL_COMMAND_MAP_BUFFER
  map_buffer            = CL_COMMAND_MAP_BUFFER,
  /// Corresponds to \c CL_COMMAND_MAP_IMAGE
  map_image             = CL_COMMAND_MAP_IMAGE,
  /// Corresponds to \c CL_COMMAND_UNMAP_MEM_OBJECT
  unmap_mem_object      = CL_COMMAND_UNMAP_MEM_OBJECT,
  /// Corresponds to \c CL_COMMAND_MARKER
  marker                = CL_COMMAND_MARKER,
  /// Corresponds to \c CL_COMMAND_ACQUIRE_GL_OBJECTS
  acquire_gl_objects    = CL_COMMAND_ACQUIRE_GL_OBJECTS,
  /// Corresponds to \c CL_COMMAND_RELEASE_GL_OBJECTS
  release_gl_objects    = CL_COMMAND_RELEASE_GL_OBJECTS
#if CLXX_CL_H_VERSION_1_1
  ,
  /// Corresponds to \c CL_COMMAND_READ_BUFFER_RECT
  read_buffer_rect      = CL_COMMAND_READ_BUFFER_RECT,
  /// Corresponds to \c CL_COMMAND_WRITE_BUFFER_RECT
  write_buffer_rect     = CL_COMMAND_WRITE_BUFFER_RECT,
  /// Corresponds to \c CL_COMMAND_COPY_BUFFER_RECT
  copy_buffer_rect      = CL_COMMAND_COPY_BUFFER_RECT,
  /// Corresponds to \c CL_COMMAND_USER
  user                  = CL_COMMAND_USER
#endif
#if CLXX_CL_H_VERSION_1_2
  ,
  /// Corresponds to \c CL_COMMAND_BARRIER
  barrier               = CL_COMMAND_BARRIER,
  /// Corresponds to \c CL_COMMAND_MIGRATE_MEM_OBJECTS
  migrate_mem_objects   = CL_COMMAND_MIGRATE_MEM_OBJECTS,
  /// Corresponds to \c CL_COMMAND_FILL_BUFFER
  fill_buffer           = CL_COMMAND_FILL_BUFFER,
  /// Corresponds to \c CL_COMMAND_FILL_IMAGE
  fill_image            = CL_COMMAND_FILL_IMAGE
#endif
};

CLXX_MAKE_INTEGER_ENUM(command_type_t, cl_command_type)

/** // doc: command_exec_status_t {{{
 * \brief Corresponds to OpenCL's command execution status
 *
 * The OpenCL's command execution status is returned by \c clGetEventInfo()
 * when querying for \c CL_EVENT_COMMAND_EXECUTION_STATUS.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class command_exec_status_t : cl_int {
  /// Corresponds to \c CL_COMPLETE
  complete  = CL_COMPLETE,
  /// Corresponds to \c CL_RUNNING
  running   = CL_RUNNING,
  /// Corresponds to \c CL_SUBMITTED
  submitted = CL_SUBMITTED,
  /// Corresponds to \c CL_QUEUED
  queued    = CL_QUEUED
};

CLXX_MAKE_INTEGER_ENUM(command_exec_status_t, cl_int)

/** // doc: is_error(command_exec_status_t) {{{
 * \brief Check if a command execution status represents an error.
 *
 * The values returned by
 * ``clGetEventInfo(...,CL_EVENT_COMMAND_EXECUTION_STATUS,...)`` may be
 * negative indicating execution errors (see
 * <a href="http://www.khronos.org/registry/cl/specs/opencl-1.2.pdf">OpenCL 1.2 Specification</a>,
 * Page 183, footnote 18). For all these error values, the is_error()
 * returns \c true. Otherwise it returns \c false.
 *
 * \param status the command execution status as returned by get_event_info().
 * \return \c true is **status** represents an error of \c false otherwise.
 */ // }}}
constexpr bool is_error(command_exec_status_t status) noexcept
{
  return (static_cast<cl_int>(status) < 0);
}
/** // doc: is_success(command_exec_status_t) {{{
 * \brief Check if a command execution status represents success (complete).
 *
 * The values returned by
 * ``clGetEventInfo(...,CL_EVENT_COMMAND_EXECUTION_STATUS,...)`` may be
 * negative indicating execution errors, positive or zero (see
 * <a href="http://www.khronos.org/registry/cl/specs/opencl-1.2.pdf">OpenCL 1.2 Specification</a>,
 * Page 183, footnote 18). A value of zero (\c CL_COMPLETE or \c CL_SUCCESS)
 * indicates an execution success. The is_success() returns \c true for this
 * case and \c false for all others.
 *
 * \param status the command execution status as returned by get_event_info().
 * \return \c true is **status** represents success or \c false otherwise.
 */ // }}}
constexpr bool is_success(command_exec_status_t status) noexcept
{
  return status == command_exec_status_t::complete;
}
/** // doc: is_state(command_exec_status_t) {{{
 * \brief Check if a command execution status represents a state.
 *
 * The values returned by
 * \c clGetEventInfo(...,CL_EVENT_COMMAND_EXECUTION_STATUS,...) may be negative
 * indicating execution errors or non-negative indicating execution state
 * (see <a href="http://www.khronos.org/registry/cl/specs/opencl-1.2.pdf">OpenCL 1.2 Specification</a>,
 * Page 183, footnote 18).
 * The is_state() returns \c true for all the state values (i.e. non-error),
 * and \c false for error codes.
 *
 * \param status the command execution status as returned by get_event_info().
 * \return \c true is **status** represents a state or \c false otherwise.
 */ // }}}
constexpr bool is_state(command_exec_status_t status) noexcept
{
  return (static_cast<cl_int>(status) >= 0);
}
#if !defined(SWIG) || !CLXX_SWIG_NO_CLASS_ENUM_CMPOPS
/** // doc: operator==(status_t, command_exec_status_t) {{{
 * \brief Compare \ref clxx::status_t "status_t" with \ref clxx::command_exec_status_t "command_exec_status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if codes are equal or \c false otherwise
 */ // }}}
constexpr bool operator == (status_t s1, command_exec_status_t s2) noexcept
{
  return static_cast<cl_int>(s1) == static_cast<cl_int>(s2);
}
/** // doc: operator==(command_exec_status_t, status_t) {{{
 * \brief Compare \ref clxx::command_exec_status_t "command_exec_status_t" with \ref clxx::status_t "status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if codes are equal or \c false otherwise
 */ // }}}
constexpr bool operator == (command_exec_status_t s1, status_t s2) noexcept
{
  return static_cast<cl_int>(s1) == static_cast<cl_int>(s2);
}
/** // doc: operator!=(status_t, command_exec_status_t) {{{
 * \brief Compare \ref clxx::status_t "status_t" with \ref clxx::command_exec_status_t "command_exec_status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c false if codes are equal or \c true otherwise
 */ // }}}
constexpr bool operator != (status_t s1, command_exec_status_t s2) noexcept
{
  return static_cast<cl_int>(s1) != static_cast<cl_int>(s2);
}
/** // doc: operator!=(command_exec_status_t, status_t) {{{
 * \brief Compare \ref clxx::command_exec_status_t "command_exec_status_t" with \ref clxx::status_t "status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c false if codes are equal or \c true otherwise
 */ // }}}
constexpr bool operator != (command_exec_status_t s1, status_t s2) noexcept
{
  return static_cast<cl_int>(s1) != static_cast<cl_int>(s2);
}
/** // doc: operator<(status_t, command_exec_status_t) {{{
 * \brief Compare \ref clxx::status_t "status_t" with \ref clxx::command_exec_status_t "command_exec_status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 < \em s2  or \c false otherwise
 */ // }}}
constexpr bool operator < (status_t s1, command_exec_status_t s2) noexcept
{
  return static_cast<cl_int>(s1) < static_cast<cl_int>(s2);
}
/** // doc: operator<(command_exec_status_t, status_t) {{{
 * \brief Compare \ref clxx::command_exec_status_t "command_exec_status_t" with \ref clxx::status_t "status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 < \em s2 or \c false otherwise
 */ // }}}
constexpr bool operator < (command_exec_status_t s1, status_t s2) noexcept
{
  return static_cast<cl_int>(s1) < static_cast<cl_int>(s2);
}
/** // doc: operator>(status_t, command_exec_status_t) {{{
 * \brief Compare \ref clxx::status_t "status_t" with \ref clxx::command_exec_status_t "command_exec_status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 > \em s2  or \c false otherwise
 */ // }}}
constexpr bool operator > (status_t s1, command_exec_status_t s2) noexcept
{
  return static_cast<cl_int>(s1) > static_cast<cl_int>(s2);
}
/** // doc: operator>(command_exec_status_t, status_t) {{{
 * \brief Compare \ref clxx::command_exec_status_t "command_exec_status_t" with \ref clxx::status_t "status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 > \em s2 or \c false otherwise
 */ // }}}
constexpr bool operator > (command_exec_status_t s1, status_t s2) noexcept
{
  return static_cast<cl_int>(s1) > static_cast<cl_int>(s2);
}
/** // doc: operator<=(status_t, command_exec_status_t) {{{
 * \brief Compare \ref clxx::status_t "status_t" with \ref clxx::command_exec_status_t "command_exec_status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 <= \em s2  or \c false otherwise
 */ // }}}
constexpr bool operator <= (status_t s1, command_exec_status_t s2) noexcept
{
  return static_cast<cl_int>(s1) <= static_cast<cl_int>(s2);
}
/** // doc: operator<=(command_exec_status_t, status_t) {{{
 * \brief Compare \ref clxx::command_exec_status_t "command_exec_status_t" with \ref clxx::status_t "status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 <= \em s2 or \c false otherwise
 */ // }}}
constexpr bool operator <= (command_exec_status_t s1, status_t s2) noexcept
{
  return static_cast<cl_int>(s1) <= static_cast<cl_int>(s2);
}
/** // doc: operator>=(status_t, command_exec_status_t) {{{
 * \brief Compare \ref clxx::status_t "status_t" with \ref clxx::command_exec_status_t "command_exec_status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 >= \em s2  or \c false otherwise
 */ // }}}
constexpr bool operator >= (status_t s1, command_exec_status_t s2) noexcept
{
  return static_cast<cl_int>(s1) >= static_cast<cl_int>(s2);
}
/** // doc: operator>=(command_exec_status_t, status_t) {{{
 * \brief Compare \ref clxx::command_exec_status_t "command_exec_status_t" with \ref clxx::status_t "status_t"
 * \param s1 First operand
 * \param s2 Second operand
 * \returns \c true if \em s1 >= \em s2 or \c false otherwise
 */ // }}}
constexpr bool operator >= (command_exec_status_t s1, status_t s2) noexcept
{
  return static_cast<cl_int>(s1) >= static_cast<cl_int>(s2);
}
#endif

#if CLXX_CL_H_VERSION_1_1
/** // doc: buffer_create_type_t {{{
 * \brief Corresponds to OpenCL's \c cl_buffer_create_type
 *
 * The OpenCL's \c cl_buffer_create_type is used by \c clCreateSubBuffer(). The
 * \ref buffer_create_type_t is a C++ equivalent of the \c
 * cl_buffer_create_type.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \todo Elaborate where and how the clxx::buffer_create_type_t is used.
 *
 */ // }}}
enum class buffer_create_type_t : cl_buffer_create_type {
  /// Corresponds to \c CL_BUFFER_CREATE_TYPE_REGION
  region = CL_BUFFER_CREATE_TYPE_REGION
};

CLXX_MAKE_INTEGER_ENUM(buffer_create_type_t, cl_buffer_create_type)
#endif

/** // doc: profiling_info_t {{{
 * \brief Corresponds to OpenCL's \c cl_profiling_info
 *
 * The OpenCL's \c cl_profiling_info is used by \c clGetEventProfilingInfo()
 * to select particular information to be queried from the OpenCL. The
 * \ref profiling_info_t is a C++ equivalent of the \c cl_profiling_info. It's
 * used by get_event_profiling_info() for the same purpose.
 *
 * \par Supported OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 */ // }}}
enum class profiling_info_t : cl_profiling_info {
  /// Corresponds to \c CL_PROFILING_COMMAND_QUEUED
  queued  = CL_PROFILING_COMMAND_QUEUED,
  /// Corresponds to \c CL_PROFILING_COMMAND_SUBMIT
  submit  = CL_PROFILING_COMMAND_SUBMIT,
  /// Corresponds to \c CL_PROFILING_COMMAND_START
  start   = CL_PROFILING_COMMAND_START,
  /// Corresponds to \c CL_PROFILING_COMMAND_END
  end     = CL_PROFILING_COMMAND_END
};

CLXX_MAKE_INTEGER_ENUM(profiling_info_t, cl_profiling_info)
} // end namespace clxx

#endif /* CLXX_TYPES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
