// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device.hpp

/** // doc: clxx/device.hpp {{{
 * \file clxx/device.hpp
 * \brief Provides the clxx::device class.
 *
 * This file contains definition of clxx::device class which provides
 * proxy object to access locally available OpenCL device.
 */ // }}}
#ifndef CLXX_DEVICE_HPP_INCLUDED
#define CLXX_DEVICE_HPP_INCLUDED

#include <clxx/device_fwd.hpp>
#include <clxx/clobj.hpp>
#include <clxx/types.hpp>
#include <vector>
#include <string>

namespace clxx {

/** // doc: device {{{
 * \ingroup clxx_platform_layer
 * \brief OpenCL device proxy
 *
 * This class provides access to OpenCL device information equivalent to
 * OpenCL's \c clGetDeviceInfo(), but:
 *
 * - it has easy to use, type-safe c++ interface,
 * - whenever necessary, returns \c std::string, \c std::vector and so on,
 *   instead of operating on plain C buffers/arrays,
 * - replaces OpenCL error codes with exceptions (see \ref clxx_exceptions).
 *
 * The object is lightweight, it encapsulates only a single \c cl_device_id
 * identifier.
 *
 * The class has no virtual destructor to not bloat the objects with virtual
 * tables. It should not be used as a base class.
 *
 * \par Example:
 * Simple functor to dump some device info to stdout
 * \snippet device1.cpp DumpDevice
 *
 *
 * Depending on the OpenCL version, the following device info may be queried.
 *
 * \todo Elaborate how OpenCL interface and library versions influence the
 *       interface and functionality of this class.
 *
 * | METHOD                                  | INFO                                    | 1.0     | 1.1     | 1.2     |
 * | --------------------------------------- | --------------------------------------- | ------- | ------- | ------- |
 * | get_type()                              | CL_DEVICE_TYPE                          |  \check |  \check |  \check |
 * | get_vendor_id()                         | CL_DEVICE_VENDOR_ID                     |  \check |  \check |  \check |
 * | get_max_compute_units()                 | CL_DEVICE_MAX_COMPUTE_UNITS             |  \check |  \check |  \check |
 * | get_max_work_item_dimensions()          | CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS      |  \check |  \check |  \check |
 * | get_max_work_group_size()               | CL_DEVICE_MAX_WORK_GROUP_SIZE           |  \check |  \check |  \check |
 * | get_max_work_item_sizes()               | CL_DEVICE_MAX_WORK_ITEM_SIZES           |  \check |  \check |  \check |
 * | get_preferred_vector_width_char()       | CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR   |  \check |  \check |  \check |
 * | get_preferred_vector_width_short()      | CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT  |  \check |  \check |  \check |
 * | get_preferred_vector_width_int()        | CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT    |  \check |  \check |  \check |
 * | get_preferred_vector_width_long()       | CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG   |  \check |  \check |  \check |
 * | get_preferred_vector_width_float()      | CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT  |  \check |  \check |  \check |
 * | get_preferred_vector_width_double()     | CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE |  \check |  \check |  \check |
 * | get_max_clock_frequency()               | CL_DEVICE_MAX_CLOCK_FREQUENCY           |  \check |  \check |  \check |
 * | get_address_bits()                      | CL_DEVICE_ADDRESS_BITS                  |  \check |  \check |  \check |
 * | get_max_read_image_args()               | CL_DEVICE_MAX_READ_IMAGE_ARGS           |  \check |  \check |  \check |
 * | get_max_write_image_args()              | CL_DEVICE_MAX_WRITE_IMAGE_ARGS          |  \check |  \check |  \check |
 * | get_max_mem_alloc_size()                | CL_DEVICE_MAX_MEM_ALLOC_SIZE            |  \check |  \check |  \check |
 * | get_image2d_max_width()                 | CL_DEVICE_IMAGE2D_MAX_WIDTH             |  \check |  \check |  \check |
 * | get_image2d_max_height()                | CL_DEVICE_IMAGE2D_MAX_HEIGHT            |  \check |  \check |  \check |
 * | get_image3d_max_width()                 | CL_DEVICE_IMAGE3D_MAX_WIDTH             |  \check |  \check |  \check |
 * | get_image3d_max_height()                | CL_DEVICE_IMAGE3D_MAX_HEIGHT            |  \check |  \check |  \check |
 * | get_image3d_max_depth()                 | CL_DEVICE_IMAGE3D_MAX_DEPTH             |  \check |  \check |  \check |
 * | get_image_support()                     | CL_DEVICE_IMAGE_SUPPORT                 |  \check |  \check |  \check |
 * | get_max_parameter_size()                | CL_DEVICE_MAX_PARAMETER_SIZE            |  \check |  \check |  \check |
 * | get_max_samplers()                      | CL_DEVICE_MAX_SAMPLERS                  |  \check |  \check |  \check |
 * | get_mem_base_addr_align()               | CL_DEVICE_MEM_BASE_ADDR_ALIGN           |  \check |  \check |  \check |
 * | get_min_data_type_align_size()          | CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE      |  \check |  \check |  \check |
 * | get_single_fp_config()                  | CL_DEVICE_SINGLE_FP_CONFIG              |  \check |  \check |  \check |
 * | get_global_mem_cache_type()             | CL_DEVICE_GLOBAL_MEM_CACHE_TYPE         |  \check |  \check |  \check |
 * | get_global_mem_cacheline_size()         | CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE     |  \check |  \check |  \check |
 * | get_global_mem_cache_size()             | CL_DEVICE_GLOBAL_MEM_CACHE_SIZE         |  \check |  \check |  \check |
 * | get_global_mem_size()                   | CL_DEVICE_GLOBAL_MEM_SIZE               |  \check |  \check |  \check |
 * | get_max_constant_buffer_size()          | CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE      |  \check |  \check |  \check |
 * | get_max_constant_args()                 | CL_DEVICE_MAX_CONSTANT_ARGS             |  \check |  \check |  \check |
 * | get_local_mem_type()                    | CL_DEVICE_LOCAL_MEM_TYPE                |  \check |  \check |  \check |
 * | get_local_mem_size()                    | CL_DEVICE_LOCAL_MEM_SIZE                |  \check |  \check |  \check |
 * | get_error_correction_support()          | CL_DEVICE_ERROR_CORRECTION_SUPPORT      |  \check |  \check |  \check |
 * | get_profiling_timer_resolution()        | CL_DEVICE_PROFILING_TIMER_RESOLUTION    |  \check |  \check |  \check |
 * | get_endian_little()                     | CL_DEVICE_ENDIAN_LITTLE                 |  \check |  \check |  \check |
 * | get_available()                         | CL_DEVICE_AVAILABLE                     |  \check |  \check |  \check |
 * | get_compiler_available()                | CL_DEVICE_COMPILER_AVAILABLE            |  \check |  \check |  \check |
 * | get_execution_capabilities()            | CL_DEVICE_EXECUTION_CAPABILITIES        |  \check |  \check |  \check |
 * | get_queue_properties()                  | CL_DEVICE_QUEUE_PROPERTIES              |  \check |  \check |  \check |
 * | get_name()                              | CL_DEVICE_NAME                          |  \check |  \check |  \check |
 * | get_vendor()                            | CL_DEVICE_VENDOR                        |  \check |  \check |  \check |
 * | get_driver_version()                    | CL_DRIVER_VERSION                       |  \check |  \check |  \check |
 * | get_profile()                           | CL_DEVICE_PROFILE                       |  \check |  \check |  \check |
 * | get_version()                           | CL_DEVICE_VERSION                       |  \check |  \check |  \check |
 * | get_extensions()                        | CL_DEVICE_EXTENSIONS                    |  \check |  \check |  \check |
 * | get_platform_id()                       | CL_DEVICE_PLATFORM                      |  \check |  \check |  \check |
 * | get_double_fp_config()                  | CL_DEVICE_DOUBLE_FP_CONFIG              |         |         |  \check |
 * | get_preferred_vector_width_half()       | CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF   |         |  \check |  \check |
 * | get_host_unified_memory()               | CL_DEVICE_HOST_UNIFIED_MEMORY           |         |  \check |  \check |
 * | get_native_vector_width_char()          | CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR      |         |  \check |  \check |
 * | get_native_vector_width_short()         | CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT     |         |  \check |  \check |
 * | get_native_vector_width_int()           | CL_DEVICE_NATIVE_VECTOR_WIDTH_INT       |         |  \check |  \check |
 * | get_native_vector_width_long()          | CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG      |         |  \check |  \check |
 * | get_native_vector_width_float()         | CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT     |         |  \check |  \check |
 * | get_native_vector_width_double()        | CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE    |         |  \check |  \check |
 * | get_native_vector_width_half()          | CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF      |         |  \check |  \check |
 * | get_opencl_c_version()                  | CL_DEVICE_OPENCL_C_VERSION              |         |  \check |  \check |
 * | get_linker_available()                  | CL_DEVICE_LINKER_AVAILABLE              |         |         |  \check |
 * | get_built_in_kernels()                  | CL_DEVICE_BUILT_IN_KERNELS              |         |         |  \check |
 * | get_image_max_buffer_size()             | CL_DEVICE_IMAGE_MAX_BUFFER_SIZE         |         |         |  \check |
 * | get_image_max_array_size()              | CL_DEVICE_IMAGE_MAX_ARRAY_SIZE          |         |         |  \check |
 * | get_parent_device_id()                  | CL_DEVICE_PARENT_DEVICE                 |         |         |  \check |
 * | get_partition_max_sub_devices()         | CL_DEVICE_PARTITION_MAX_SUB_DEVICES     |         |         |  \check |
 * | get_partition_properties()              | CL_DEVICE_PARTITION_PROPERTIES          |         |         |  \check |
 * | get_partition_affinity_domain()         | CL_DEVICE_PARTITION_AFFINITY_DOMAIN     |         |         |  \check |
 * | get_partition_type()                    | CL_DEVICE_PARTITION_TYPE                |         |         |  \check |
 * | get_reference_count()                   | CL_DEVICE_REFERENCE_COUNT               |         |         |  \check |
 * | get_preferred_interop_user_sync()       | CL_DEVICE_PREFERRED_INTEROP_USER_SYNC   |         |         |  \check |
 * | get_printf_buffer_size()                | CL_DEVICE_PRINTF_BUFFER_SIZE            |         |         |  \check |
 * | get_image_pitch_alignment()             | CL_DEVICE_IMAGE_PITCH_ALIGNMENT         |         |         |  \check |
 * | get_image_base_address_alignment()      | CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT  |         |         |  \check |
 */ // }}}
class alignas(cl_device_id) device
  : public clobj<cl_device_id>
{
public:
  /** // doc: Base {{{
   * \brief Typedef for the base class type
   */ // }}}
  typedef clobj<cl_device_id> Base;
  using Base::Base;
  /** // doc: device() {{{
   * \brief Default constructor, see \ref clobj::clobj()
   */ // }}}
  device() = default;
  /** // doc: device() {{{
   * \brief Copy constructor, see \ref clobj::clobj(clobj const&)
   */ // }}}
  device(device const&) = default;
  /** // {{{
   *  \brief Get \c CL_DEVICE_TYPE information.
   *  \return The OpenCL device type, see clxx::device_type_t.
   */ // }}}
  device_type_t get_type() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_VENDOR information.
   * \return A unique device vendor identifier. An example of a unique device
   *    identifier could be the PCIe ID
   */ // }}}
  cl_uint get_vendor_id() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_COMPUTE_UNITS information.
   * \return The number of parallel compute cores on the OpenCL device. The
   *    minimum value is 1.
   */ // }}}
  cl_uint get_max_compute_units() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS information.
   * \return Maximum dimensions that specify the global and local work-item IDs
   *    used by the data parallel execution model. The minimum value is 3.
   */ // }}}
  cl_uint get_max_work_item_dimensions() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WORK_GROUP_SIZE information.
   * \return Maximum number of work-items in a work-group executing a kernel
   *    using the data parallel execution model. The minimum value is \c 1.
   */ // }}}
  size_t get_max_work_group_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WORK_ITEM_SIZES information.
   * \return Maximum number of work-items that can be specified in each
   *    dimension of the work-group to \c clEnqueueNDRangeKernel. Returns \c n
   *    \c size_t entries, where \c n is the value returned by the query for \c
   *    CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS. The minimum value is
   *    \c (1,\c 1, \c 1).
   */ // }}}
  std::vector<size_t> get_max_work_item_sizes() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR information.
   * \return Preferred native vector width size for built-in \c char scalar
   *    when put into vector. The vector width is defined as the number of \c
   *    char elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_char() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT information.
   * \return Preferred native vector width size for built-in \c short scalar
   *    when put into vector. The vector width is defined as the number of \c
   *    short elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_short() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT information.
   * \return Preferred native vector width size for built-in \c int scalar
   *    when put into vector. The vector width is defined as the number of
   *    \c int elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_int() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG information.
   * \return Preferred native vector width size for built-in \c long scalar
   *    when put longo vector. The vector width is defined as the number of
   *    \c long elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_long() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT information.
   * \return Preferred native vector width size for built-in \c float scalar
   *    when put floato vector. The vector width is defined as the number of
   *    \c float elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_float() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE information.
   * \return Preferred native vector width size for built-in \c double scalar
   *    when put doubleo vector. The vector width is defined as the number of
   *    \c double elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_double() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_CLOCK_FREQUENCY information.
   * \return Maximum configured clock frequency of the device in MHz.
   */ // }}}
  cl_uint get_max_clock_frequency() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_ADDRESS_BITS information.
   * \return The default compute device address space size specified as an
   *    unsigned integer value in bits (e.g. 32 or 64 bits).
   */ // }}}
  cl_uint get_address_bits() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_READ_IMAGE_ARGS information.
   * \return Max number of simultaneous image objects that can be read by a
   *    kernel. The minimum value is 128 if \c CL_DEVICE_IMAGE_SUPPORT is
   *    \c CL_TRUE.
   */ // }}}
  cl_uint get_max_read_image_args() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_WRITE_IMGE_ARGS information.
   * \return Max number of simultaneous image objects that can be written to by
   * a kernel. The minimum value is 8 if \c CL_DEVICE_IMAGE_SUPPORT is
   * \c CL_TRUE.
   */ // }}}
  cl_uint get_max_write_image_args() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_MEM_ALLOC_SIZE information.
   * \return Max size of memory object allocation in bytes. The minimum value
   *    is max (1/4th of CL_DEVICE_GLOBAL_MEM_SIZE, 128*1024*1024)
   */ // }}}
  cl_ulong get_max_mem_alloc_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE2D_MAX_WIDTH information.
   * \return Max width of 2D image in pixels. The minimum value is 8192 if \c
   *    CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image2d_max_width() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE2D_MAX_HEIGHT information.
   * \return Max height of 2D image in pixels. The minimum value is 8192 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image2d_max_height() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE3D_MAX_WIDTH information.
   * \return Max width of 3D image in pixels. The minimum value is 2048 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image3d_max_width() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE3D_MAX_HEIGHT information.
   * \return Max height of 3D image in pixels. The minimum value is 2048 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image3d_max_height() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE3D_MAX_DEPTH information.
   * \return Max depth of 3D image in pixels. The minimum value is 2048 if
   *    \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image3d_max_depth() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE_SUPPORT information.
   * \return CL_TRUE if images are supported by the OpenCL device and CL_FALSE
   *    otherwise.
   */ // }}}
  cl_bool get_image_support() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_PARAMETER_SIZE information.
   * \return Max size in bytes of the arguments that can be passed to a kernel.
   *    The minimum value is 1024. For this minimum value, only a maximum of
   *    128 arguments can be passed to a kernel.
   */ // }}}
  size_t get_max_parameter_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_SAMPLERS information.
   * \return Maximum number of samplers that can be used in a kernel. The
   *    minimum value is 16 if \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  cl_uint get_max_samplers() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MEM_BASE_ADDR_ALIGN information.
   * \return Describes the alignment in bits of the base address of any
   *    allocated memory object.
   */ // }}}
  cl_uint get_mem_base_addr_align() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE information.
   * \return The smallest alignment in bytes which can be used for any data
   *    type.
   */ // }}}
  cl_uint get_min_data_type_align_size() const;
  /** // {{{
   * \brief Get CL_DEVICE_SINGLE_FP_CONFIG information
   * \return Value of type clxx::device_fp_config_t.
   *
   * The returned value describes single precision floating-point capability of
   * the device. This is a bit-field that describes one or more of the
   * values defined by clxx::device_fp_config_t.
   */ // }}}
  device_fp_config_t get_single_fp_config() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_CACHE_TYPE information.
   * \return Type of global memory cache supported. Possible values are
   *    defined by clxx::device_mem_cache_type_t.
   */ // }}}
  device_mem_cache_type_t get_global_mem_cache_type() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE information.
   * \return Size of global memory cache line in bytes.
   */ // }}}
  cl_uint get_global_mem_cacheline_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_CACHE_SIZE information.
   * \return Type of global memory cache supported. Possible values are:
   *    \c CL_NONE, \c CL_READ_ONLY_CACHE, and \c CL_READ_WRITE_CACHE.
   */ // }}}
  cl_ulong get_global_mem_cache_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_GLOBAL_MEM_SIZE information.
   * \return Size of global device memory in bytes.
   */ // }}}
  cl_ulong get_global_mem_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE information.
   * \return Max size in bytes of a constant buffer allocation. The minimum
   *         value is 64KB.
   */ // }}}
  cl_ulong get_max_constant_buffer_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_MAX_CONSTANT_ARGS information.
   * \return Max number of arguments declared with the \c __constant qualifier
   *    in a kernel. The minimum value is 8.
   */ // }}}
  cl_uint get_max_constant_args() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_LOCAL_MEM_TYPE information.
   * \return Type of local memory supported, see clxx::device_local_mem_type_t.
   */ // }}}
  device_local_mem_type_t get_local_mem_type() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_LOCAL_MEM_SIZE information.
   * \return Size of local memory arena in bytes. The minimum value is 32 KB.
   */ // }}}
  cl_ulong get_local_mem_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_ERROR_CORRECTION_SUPPORT information.
   * \return \c CL_TRUE if the device implements error correction for all
   *    accesses to compute device memory (global and constant);
   *    \c CL_FALSE if * the device does not implement such error correction.
   */ // }}}
  cl_bool get_error_correction_support() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PROFILING_TIMER_RESOLUTION information.
   * \return Describes the resolution of device timer. This is measured in
   *    nanoseconds.
   */ // }}}
  size_t get_profiling_timer_resolution() const;
  /** // {{{
   * \brief Get \c CL_ENDIAN_LITTLE information.
   * \return \c CL_TRUE if the OpenCL device is a little endian device and \c
   *    CL_FALSE otherwise.
   */ // }}}
  cl_bool get_endian_little() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_AVAILABLE information.
   * \return CL_TRUE if the device is available and CL_FALSE if the device is
   *  not available.
   */ // }}}
  cl_bool get_available() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_COMPILER_AVAILABLE information.
   * \return \c CL_FALSE if the implementation does not have a compiler
   *    available to compile the program source; \c CL_TRUE if the compiler is
   *    available. This can be \c CL_FALSE for the embedded platform profile
   *    only.
   */ // }}}
  cl_bool get_compiler_available() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_EXECUTION_CAPABILITIES information.
   * \return Value of type: \c device_exec_capabilities_t
   *
   * The returned value describes the execution capabilities of the device.
   * This is a bit-field that describes one or more of the values defined by
   * clxx::device_exec_capabilities_t.
   */ // }}}
  device_exec_capabilities_t get_execution_capabilities() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_QUEUE_PROPERTIES information.
   * \return Value of type clxx::command_queue_properties_t.
   *
   * The returned value describes the command-queue properties supported by the
   * device. This is a bit-field that describes one or more of the values
   * defined by clxx::command_queue_properties_t.
   */ // }}}
  command_queue_properties_t get_queue_properties() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NAME information.
   * \return %device name string.
   */ // }}}
  std::string get_name() const;
  /** // {{{
   * \brief Get CL_DEVICE_VENDOR information.
   * \return Vendor name string.
   */ // }}}
  std::string get_vendor() const;
  /** // {{{
   * \brief Get \c CL_DRIVER_VERSION information.
   * \return OpenCL software driver version string in the form
   *    \c major_number.minor_number.
   */ // }}}
  std::string get_driver_version() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PROFILE information.
   * \return OpenCL profile string.
   *
   * Returns the profile name supported by the device (see note). The profile
   * name returned can be one of the following strings:
   *
   * - \c FULL_PROFILE - if the device supports the OpenCL specification
   *   (functionality defined as part of the core specification and does not
   *   require any extensions to be supported).
   * - \c EMBEDDED_PROFILE - if the device supports the OpenCL embedded
   *   profile.
   */ // }}}
  std::string get_profile() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_VERSION
   * \return OpenCL version string.
   *
   * Returns the OpenCL version supported by the device. This version string
   * has the following format:
    \verbatim
    OpenCL<space><major_version.minor_version><space><vendor-specific information>
    \endverbatim
   */ // }}}
  std::string get_version() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_EXTENSIONS information.
   * \return Returns a space-separated list of extension names.
   *
   * The list of extension names returned is defined by OpenCL standard and
   * depends on OpenCL version.
   */ // }}}
  std::string get_extensions() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PLATFORM information.
   * \return ID of the platform associated with this device.
   */ // }}}
  cl_platform_id get_platform_id() const;
#if CLXX_CL_H_VERSION_1_2
  /** // {{{
   * \brief Get \c CL_DEVICE_PLATFORM information.
   * \return ID of the platform associated with this device.
   */ // }}}
  device_fp_config_t get_double_fp_config() const;
#endif
#if CLXX_CL_H_VERSION_1_1
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF information.
   * \return Preferred native vector width size for built-in \c half scalar
   *    when put halfo vector. The vector width is defined as the number of
   *    \c half elements that can be stored in the vector.
   */ // }}}
  cl_uint get_preferred_vector_width_half() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_HOST_UNIFIED_MEMORY information.
   * \return \c CL_TRUE if the device and the host have a unified memory
   *    subsystem; \c CL_FALSE otherwise
   */ // }}}
  cl_bool get_host_unified_memory() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_char() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_short() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_INT information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_int() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_long() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_float() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_double() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF information.
   * \return Returns the native ISA vector width. The vector width is defined
   *    as the number of scalar elements that can be stored in the vector.
   */ // }}}
  cl_uint get_native_vector_width_half() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_OPENCL_C_VERSION information.
   * \return OpenCL C version string.
   *
   * Returns the highest OpenCL C version supported by the compiler for this
   * device. This version string has the following format:
   * \verbatim
      OpenCL<space>C<space><major_version.minor_version><space><vendor-specific information>
    \endverbatim
   */ // }}}
  std::string get_opencl_c_version() const;
#endif
#if CLXX_CL_H_VERSION_1_2
  /** // {{{
   * \brief Get \c CL_DEVICE_LINKER_AVAILABLE information.
   * \return \c CL_FALSE if the implementation does not have a linker available.
   *         \c CL_TRUE if the linker is available.
   *
   * This can be \c CL_FALSE for the embedded platform profile only. Must be
   * \c CL_TRUE if \c CL_DEVICE_COMPILER_AVAILABLE is \c CL_TRUE.
   */ // }}}
  cl_bool get_linker_available() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_BUILT_IN_KERNELS information.
   * \return A semi-colon separated list of built-in kernels supported by the
   *         device. An empty string is returned if no built-in kernels are
   *         supported by the device.
   */ // }}}
  std::string get_built_in_kernels() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE_MAX_BUFFER_SIZE information.
   * \return Max number of pixels for a 1D image created from a buffer object.
   *         The minimum value is 2048 if \c CL_DEVICE_IMAGE_SUPPORT is
   *         \c CL_TRUE.
   *    nanoseconds.
   */ // }}}
  size_t get_image_max_buffer_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE_MAX_ARRAY_SIZE information.
   * \return Max number of images in a 1D or 2D image array.
   *
   *  The minimum value is 256 if \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_image_max_array_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PARAENT_DEVICE information.
   * \return Returns the \c cl_device_id of the parent device to which this
   *         sub-device belongs. If *device* is a root-level device, a NULL
   *         value is returned.
   */ // }}}
  cl_device_id get_parent_device_id() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PARTITION_MAX_SUB_DEVICES information.
   */ // }}}
  cl_uint get_partition_max_sub_devices() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PARTITION_PROPERTIES information.
   * \return The list of partition types supported by *device*.
   *
   * The return is a vector of \c device_partition_property_t values drawn
   * from the following list:
   *
   * - CL_DEVICE_PARTITION_EQUALLY,
   * - CL_DEVICE_PARTITION_BY_COUNTS,
   * - CL_DEVICE_PARTITION_BY_AFFINITY_DO_MAIN
   *
   * If the device does not support any partition types, a value of 0 will be
   * returned.
   */ // }}}
  std::vector<device_partition_property_t> get_partition_properties() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PARTITION_AFFINITY_DOMAIN information.
   * \return The list of supported affinity domains for partitioning the
   *         *device* using \c CL_DEVICE_PARTITION_BY_AFFINITY_DO_MAIN.
   *
   * This is a bit-field that describes one or more of the folowing values:
   * - CL_AFFINITY_DOMAIN_NUMA
   * - CL_AFFINITY_DOMAIN_L4_CACHE
   * - CL_AFFINITY_DOMAIN_L3_CACHE
   * - CL_AFFINITY_DOMAIN_L2_CACHE
   * - CL_AFFINITY_DOMAIN_L1_CACHE
   * - CL_AFFINITY_DOMAIN_NEXT_PARTITIONABLE
   *
   * If the device does not support any affinity domains, a value of 0 will be
   * returned.
   */ // }}}
  device_affinity_domain_t get_partition_affinity_domain() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PARTITION_TYPE information.
   * \return The properties argument specified in \c clCreateSubDevices if
   *         *device* is a sub-device.
   *
   * If *device* is not a sub-device, implementation may either return a
   * *param_value_size_ret* of 0 i.e. thare is no partition type associated
   * with device or can return a propertu value of 0 (where 9 is used to
   * terminate the partition property list) in the memory that *param_value*
   * points to.
   */ // }}}
  std::vector<device_partition_property_t> get_partition_type() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PREFERRED_INTEROP_USER_SYNC information.
   * \return \c CL_TRUE if the device's preference is for the user to be
   *         responsible for synchronization, when sharing  memory objects
   *         between OpenCL and other APIs sucha s DirectX, \c CL_FALSE if the
   *         device/implementation has a performant path for performing
   *         synchronization.
   */ // }}}
  cl_bool get_preferred_interop_user_sync() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_PRINTF_BUFFER_SIZE information.
   * \return Maximum size of the internal buffer that holds the output of
   *         printf calls from a kernel. The minimum value for the FULL profile
   *         is 1 MB.
   *
   *  The minimum value is 256 if \c CL_DEVICE_IMAGE_SUPPORT is \c CL_TRUE.
   */ // }}}
  size_t get_printf_buffer_size() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE_PITCH_ALIGNMENT information.
   */ // }}}
  cl_uint get_image_pitch_alignment() const;
  /** // {{{
   * \brief Get \c CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT information.
   */ // }}}
  cl_uint get_image_base_address_alignment() const;
#endif
};

} // end namespace clxx

#include <clxx/device_info.hpp>
#include <clxx/device_query.hpp>

namespace clxx {
/** \addtogroup clxx_info
 * @{ */
/** // doc: query_device_info(device, query) {{{
 * \brief Query device info
 *
 * Queries the OpenCL platform layer for information describing particular
 * device. By default all supported device parameters are retrieved.
 *
 * \param device  The device to be described.
 * \param query   Query specification (what attributes to retrieve).
 * \returns \ref clxx::device_info "device_info" object containing the result
 *    of the query
 *
 * \par Example
 *
 * Print device info for a first OpenCL device of a first OpenCL platform found
 * in operating system
 *
 * \snippet clxx/query_device_info1.cpp Program
 */ // }}}
device_info
query_device_info( device const& device,
                   device_query const& query = device_query() );
/** @} */
} // end namespace clxx

#endif /* CLXX_DEVICE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
