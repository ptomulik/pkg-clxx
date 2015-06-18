// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_info.cpp

/** // doc: clxx/device_info.cpp {{{
 * \file clxx/device_info.cpp
 * \brief Implements the \ref clxx::device_info "device_info" class
 */ // }}}
#include <clxx/device_info.hpp>
#include <clxx/exceptions.hpp>
#include <string>

namespace clxx {
/* ----------------------------------------------------------------------- */
device_info::
device_info() noexcept
{
}
/* ----------------------------------------------------------------------- */
device_info::
~device_info() noexcept
{
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear()
{
  this->_clear();
  return *this;
}
/* ----------------------------------------------------------------------- */
bool device_info::
cmp(device_info const& rhs) const
  noexcept
{
  return (this->_id == rhs._id)
      && (this->_type == rhs._type)
      && (this->_vendor_id == rhs._vendor_id)
      && (this->_max_compute_units == rhs._max_compute_units)
      && (this->_max_work_item_dimensions == rhs._max_work_item_dimensions)
      && (this->_max_work_group_size == rhs._max_work_group_size)
      && (this->_max_work_item_sizes == rhs._max_work_item_sizes)
      && (this->_preferred_vector_width_char == rhs._preferred_vector_width_char)
      && (this->_preferred_vector_width_short == rhs._preferred_vector_width_short)
      && (this->_preferred_vector_width_int == rhs._preferred_vector_width_int)
      && (this->_preferred_vector_width_long == rhs._preferred_vector_width_long)
      && (this->_preferred_vector_width_float == rhs._preferred_vector_width_float)
      && (this->_preferred_vector_width_double == rhs._preferred_vector_width_double)
      && (this->_max_clock_frequency == rhs._max_clock_frequency)
      && (this->_address_bits == rhs._address_bits)
      && (this->_max_read_image_args == rhs._max_read_image_args)
      && (this->_max_write_image_args == rhs._max_write_image_args)
      && (this->_max_mem_alloc_size == rhs._max_mem_alloc_size)
      && (this->_image2d_max_width == rhs._image2d_max_width)
      && (this->_image2d_max_height == rhs._image2d_max_height)
      && (this->_image3d_max_width == rhs._image3d_max_width)
      && (this->_image3d_max_height == rhs._image3d_max_height)
      && (this->_image3d_max_depth == rhs._image3d_max_depth)
      && (this->_image_support == rhs._image_support)
      && (this->_max_parameter_size == rhs._max_parameter_size)
      && (this->_max_samplers == rhs._max_samplers)
      && (this->_mem_base_addr_align == rhs._mem_base_addr_align)
      && (this->_min_data_type_align_size == rhs._min_data_type_align_size)
      && (this->_single_fp_config == rhs._single_fp_config)
      && (this->_global_mem_cache_type == rhs._global_mem_cache_type)
      && (this->_global_mem_cacheline_size == rhs._global_mem_cacheline_size)
      && (this->_global_mem_cache_size == rhs._global_mem_cache_size)
      && (this->_global_mem_size == rhs._global_mem_size)
      && (this->_max_constant_buffer_size == rhs._max_constant_buffer_size)
      && (this->_max_constant_args == rhs._max_constant_args)
      && (this->_local_mem_type == rhs._local_mem_type)
      && (this->_local_mem_size == rhs._local_mem_size)
      && (this->_error_correction_support == rhs._error_correction_support)
      && (this->_profiling_timer_resolution == rhs._profiling_timer_resolution)
      && (this->_endian_little == rhs._endian_little)
      && (this->_available == rhs._available)
      && (this->_compiler_available == rhs._compiler_available)
      && (this->_execution_capabilities == rhs._execution_capabilities)
      && (this->_queue_properties == rhs._queue_properties)
      && (this->_name == rhs._name)
      && (this->_vendor == rhs._vendor)
      && (this->_driver_version == rhs._driver_version)
      && (this->_profile == rhs._profile)
      && (this->_version == rhs._version)
      && (this->_extensions == rhs._extensions)
      && (this->_platform_id == rhs._platform_id)
#if CL_VERSION_1_2
      && (this->_double_fp_config == rhs._double_fp_config)
#endif
#if CL_VERSION_1_1
      && (this->_preferred_vector_width_half == rhs._preferred_vector_width_half)
      && (this->_host_unified_memory == rhs._host_unified_memory)
      && (this->_native_vector_width_char == rhs._native_vector_width_char)
      && (this->_native_vector_width_short == rhs._native_vector_width_short)
      && (this->_native_vector_width_int == rhs._native_vector_width_int)
      && (this->_native_vector_width_long == rhs._native_vector_width_long)
      && (this->_native_vector_width_float == rhs._native_vector_width_float)
      && (this->_native_vector_width_double == rhs._native_vector_width_double)
      && (this->_native_vector_width_half == rhs._native_vector_width_half)
      && (this->_opencl_c_version == rhs._opencl_c_version)
#endif
#if CL_VERSION_1_2
      && (this->_linker_available == rhs._linker_available)
      && (this->_built_in_kernels == rhs._built_in_kernels)
      && (this->_image_max_buffer_size == rhs._image_max_buffer_size)
      && (this->_image_max_array_size == rhs._image_max_array_size)
      && (this->_parent_device_id == rhs._parent_device_id)
      && (this->_partition_max_sub_devices == rhs._partition_max_sub_devices)
      && (this->_partition_properties == rhs._partition_properties)
      && (this->_partition_affinity_domain == rhs._partition_affinity_domain)
      && (this->_partition_type == rhs._partition_type)
      && (this->_reference_count == rhs._reference_count)
      && (this->_preferred_interop_user_sync == rhs._preferred_interop_user_sync)
      && (this->_printf_buffer_size == rhs._printf_buffer_size)
      && (this->_image_pitch_alignment == rhs._image_pitch_alignment)
      && (this->_image_base_address_alignment == rhs._image_base_address_alignment)
#endif
      ;
}
// getters {{{
/* ----------------------------------------------------------------------- */
unsigned long device_info::
id() const
{
  if(!this->has_id()) { throw uninitialized_value_error(); }
  return this->_id.get();
}
/* ----------------------------------------------------------------------- */
device_type_t device_info::
type() const
{
  if(!this->has_type()) { throw uninitialized_value_error(); }
  return this->_type.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
vendor_id() const
{
  if(!this->has_vendor_id()) { throw uninitialized_value_error(); }
  return this->_vendor_id.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
max_compute_units() const
{
  if(!this->has_max_compute_units()) { throw uninitialized_value_error(); }
  return this->_max_compute_units.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
max_work_item_dimensions() const
{
  if(!this->has_max_work_item_dimensions()) { throw uninitialized_value_error(); }
  return this->_max_work_item_dimensions.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
max_work_group_size() const
{
  if(!this->has_max_work_group_size()) { throw uninitialized_value_error(); }
  return this->_max_work_group_size.get();
}
/* ----------------------------------------------------------------------- */
std::vector<size_t> device_info::
max_work_item_sizes() const
{
  if(!this->has_max_work_item_sizes()) { throw uninitialized_value_error(); }
  return this->_max_work_item_sizes.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
preferred_vector_width_char() const
{
  if(!this->has_preferred_vector_width_char()) { throw uninitialized_value_error(); }
  return this->_preferred_vector_width_char.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
preferred_vector_width_short() const
{
  if(!this->has_preferred_vector_width_short()) { throw uninitialized_value_error(); }
  return this->_preferred_vector_width_short.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
preferred_vector_width_int() const
{
  if(!this->has_preferred_vector_width_int()) { throw uninitialized_value_error(); }
  return this->_preferred_vector_width_int.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
preferred_vector_width_long() const
{
  if(!this->has_preferred_vector_width_long()) { throw uninitialized_value_error(); }
  return this->_preferred_vector_width_long.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
preferred_vector_width_float() const
{
  if(!this->has_preferred_vector_width_float()) { throw uninitialized_value_error(); }
  return this->_preferred_vector_width_float.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
preferred_vector_width_double() const
{
  if(!this->has_preferred_vector_width_double()) { throw uninitialized_value_error(); }
  return this->_preferred_vector_width_double.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
max_clock_frequency() const
{
  if(!this->has_max_clock_frequency()) { throw uninitialized_value_error(); }
  return this->_max_clock_frequency.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
address_bits() const
{
  if(!this->has_address_bits()) { throw uninitialized_value_error(); }
  return this->_address_bits.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
max_read_image_args() const
{
  if(!this->has_max_read_image_args()) { throw uninitialized_value_error(); }
  return this->_max_read_image_args.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
max_write_image_args() const
{
  if(!this->has_max_write_image_args()) { throw uninitialized_value_error(); }
  return this->_max_write_image_args.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong device_info::
max_mem_alloc_size() const
{
  if(!this->has_max_mem_alloc_size()) { throw uninitialized_value_error(); }
  return this->_max_mem_alloc_size.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
image2d_max_width() const
{
  if(!this->has_image2d_max_width()) { throw uninitialized_value_error(); }
  return this->_image2d_max_width.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
image2d_max_height() const
{
  if(!this->has_image2d_max_height()) { throw uninitialized_value_error(); }
  return this->_image2d_max_height.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
image3d_max_width() const
{
  if(!this->has_image3d_max_width()) { throw uninitialized_value_error(); }
  return this->_image3d_max_width.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
image3d_max_height() const
{
  if(!this->has_image3d_max_height()) { throw uninitialized_value_error(); }
  return this->_image3d_max_height.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
image3d_max_depth() const
{
  if(!this->has_image3d_max_depth()) { throw uninitialized_value_error(); }
  return this->_image3d_max_depth.get();
}
/* ----------------------------------------------------------------------- */
cl_bool device_info::
image_support() const
{
  if(!this->has_image_support()) { throw uninitialized_value_error(); }
  return this->_image_support.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
max_parameter_size() const
{
  if(!this->has_max_parameter_size()) { throw uninitialized_value_error(); }
  return this->_max_parameter_size.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
max_samplers() const
{
  if(!this->has_max_samplers()) { throw uninitialized_value_error(); }
  return this->_max_samplers.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
mem_base_addr_align() const
{
  if(!this->has_mem_base_addr_align()) { throw uninitialized_value_error(); }
  return this->_mem_base_addr_align.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
min_data_type_align_size() const
{
  if(!this->has_min_data_type_align_size()) { throw uninitialized_value_error(); }
  return this->_min_data_type_align_size.get();
}
/* ----------------------------------------------------------------------- */
device_fp_config_t device_info::
single_fp_config() const
{
  if(!this->has_single_fp_config()) { throw uninitialized_value_error(); }
  return this->_single_fp_config.get();
}
/* ----------------------------------------------------------------------- */
device_mem_cache_type_t device_info::
global_mem_cache_type() const
{
  if(!this->has_global_mem_cache_type()) { throw uninitialized_value_error(); }
  return this->_global_mem_cache_type.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
global_mem_cacheline_size() const
{
  if(!this->has_global_mem_cacheline_size()) { throw uninitialized_value_error(); }
  return this->_global_mem_cacheline_size.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong device_info::
global_mem_cache_size() const
{
  if(!this->has_global_mem_cache_size()) { throw uninitialized_value_error(); }
  return this->_global_mem_cache_size.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong device_info::
global_mem_size() const
{
  if(!this->has_global_mem_size()) { throw uninitialized_value_error(); }
  return this->_global_mem_size.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong device_info::
max_constant_buffer_size() const
{
  if(!this->has_max_constant_buffer_size()) { throw uninitialized_value_error(); }
  return this->_max_constant_buffer_size.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
max_constant_args() const
{
  if(!this->has_max_constant_args()) { throw uninitialized_value_error(); }
  return this->_max_constant_args.get();
}
/* ----------------------------------------------------------------------- */
device_local_mem_type_t device_info::
local_mem_type() const
{
  if(!this->has_local_mem_type()) { throw uninitialized_value_error(); }
  return this->_local_mem_type.get();
}
/* ----------------------------------------------------------------------- */
cl_ulong device_info::
local_mem_size() const
{
  if(!this->has_local_mem_size()) { throw uninitialized_value_error(); }
  return this->_local_mem_size.get();
}
/* ----------------------------------------------------------------------- */
cl_bool device_info::
error_correction_support() const
{
  if(!this->has_error_correction_support()) { throw uninitialized_value_error(); }
  return this->_error_correction_support.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
profiling_timer_resolution() const
{
  if(!this->has_profiling_timer_resolution()) { throw uninitialized_value_error(); }
  return this->_profiling_timer_resolution.get();
}
/* ----------------------------------------------------------------------- */
cl_bool device_info::
endian_little() const
{
  if(!this->has_endian_little()) { throw uninitialized_value_error(); }
  return this->_endian_little.get();
}
/* ----------------------------------------------------------------------- */
cl_bool device_info::
available() const
{
  if(!this->has_available()) { throw uninitialized_value_error(); }
  return this->_available.get();
}
/* ----------------------------------------------------------------------- */
cl_bool device_info::
compiler_available() const
{
  if(!this->has_compiler_available()) { throw uninitialized_value_error(); }
  return this->_compiler_available.get();
}
/* ----------------------------------------------------------------------- */
device_exec_capabilities_t device_info::
execution_capabilities() const
{
  if(!this->has_execution_capabilities()) { throw uninitialized_value_error(); }
  return this->_execution_capabilities.get();
}
/* ----------------------------------------------------------------------- */
command_queue_properties_t device_info::
queue_properties() const
{
  if(!this->has_queue_properties()) { throw uninitialized_value_error(); }
  return this->_queue_properties.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
name() const
{
  if(!this->has_name()) { throw uninitialized_value_error(); }
  return this->_name.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
vendor() const
{
  if(!this->has_vendor()) { throw uninitialized_value_error(); }
  return this->_vendor.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
driver_version() const
{
  if(!this->has_driver_version()) { throw uninitialized_value_error(); }
  return this->_driver_version.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
profile() const
{
  if(!this->has_profile()) { throw uninitialized_value_error(); }
  return this->_profile.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
version() const
{
  if(!this->has_version()) { throw uninitialized_value_error(); }
  return this->_version.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
extensions() const
{
  if(!this->has_extensions()) { throw uninitialized_value_error(); }
  return this->_extensions.get();
}
/* ----------------------------------------------------------------------- */
unsigned long device_info::
platform_id() const
{
  if(!this->has_platform_id()) { throw uninitialized_value_error(); }
  return this->_platform_id.get();
}
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
device_fp_config_t device_info::
double_fp_config() const
{
  if(!this->has_double_fp_config()) { throw uninitialized_value_error(); }
  return this->_double_fp_config.get();
}
#endif
#if CL_VERSION_1_1
/* ----------------------------------------------------------------------- */
cl_uint device_info::
preferred_vector_width_half() const
{
  if(!this->has_preferred_vector_width_half()) { throw uninitialized_value_error(); }
  return this->_preferred_vector_width_half.get();
}
/* ----------------------------------------------------------------------- */
cl_bool device_info::
host_unified_memory() const
{
  if(!this->has_host_unified_memory()) { throw uninitialized_value_error(); }
  return this->_host_unified_memory.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
native_vector_width_char() const
{
  if(!this->has_native_vector_width_char()) { throw uninitialized_value_error(); }
  return this->_native_vector_width_char.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
native_vector_width_short() const
{
  if(!this->has_native_vector_width_short()) { throw uninitialized_value_error(); }
  return this->_native_vector_width_short.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
native_vector_width_int() const
{
  if(!this->has_native_vector_width_int()) { throw uninitialized_value_error(); }
  return this->_native_vector_width_int.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
native_vector_width_long() const
{
  if(!this->has_native_vector_width_long()) { throw uninitialized_value_error(); }
  return this->_native_vector_width_long.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
native_vector_width_float() const
{
  if(!this->has_native_vector_width_float()) { throw uninitialized_value_error(); }
  return this->_native_vector_width_float.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
native_vector_width_double() const
{
  if(!this->has_native_vector_width_double()) { throw uninitialized_value_error(); }
  return this->_native_vector_width_double.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
native_vector_width_half() const
{
  if(!this->has_native_vector_width_half()) { throw uninitialized_value_error(); }
  return this->_native_vector_width_half.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
opencl_c_version() const
{
  if(!this->has_opencl_c_version()) { throw uninitialized_value_error(); }
  return this->_opencl_c_version.get();
}
#endif
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
cl_bool device_info::
linker_available() const
{
  if(!this->has_linker_available()) { throw uninitialized_value_error(); }
  return this->_linker_available.get();
}
/* ----------------------------------------------------------------------- */
std::string const& device_info::
built_in_kernels() const
{
  if(!this->has_built_in_kernels()) { throw uninitialized_value_error(); }
  return this->_built_in_kernels.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
image_max_buffer_size() const
{
  if(!this->has_image_max_buffer_size()) { throw uninitialized_value_error(); }
  return this->_image_max_buffer_size.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
image_max_array_size() const
{
  if(!this->has_image_max_array_size()) { throw uninitialized_value_error(); }
  return this->_image_max_array_size.get();
}
/* ----------------------------------------------------------------------- */
unsigned long device_info::
parent_device_id() const
{
  if(!this->has_parent_device_id()) { throw uninitialized_value_error(); }
  return this->_parent_device_id.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
partition_max_sub_devices() const
{
  if(!this->has_partition_max_sub_devices()) { throw uninitialized_value_error(); }
  return this->_partition_max_sub_devices.get();
}
/* ----------------------------------------------------------------------- */
std::vector<device_partition_property_t> device_info::
partition_properties() const
{
  if(!this->has_partition_properties()) { throw uninitialized_value_error(); }
  return this->_partition_properties.get();
}
/* ----------------------------------------------------------------------- */
device_affinity_domain_t device_info::
partition_affinity_domain() const
{
  if(!this->has_partition_affinity_domain()) { throw uninitialized_value_error(); }
  return this->_partition_affinity_domain.get();
}
/* ----------------------------------------------------------------------- */
std::vector<device_partition_property_t> device_info::
partition_type() const
{
  if(!this->has_partition_type()) { throw uninitialized_value_error(); }
  return this->_partition_type.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
reference_count() const
{
  if(!this->has_reference_count()) { throw uninitialized_value_error(); }
  return this->_reference_count.get();
}
/* ----------------------------------------------------------------------- */
cl_bool device_info::
preferred_interop_user_sync() const
{
  if(!this->has_preferred_interop_user_sync()) { throw uninitialized_value_error(); }
  return this->_preferred_interop_user_sync.get();
}
/* ----------------------------------------------------------------------- */
size_t device_info::
printf_buffer_size() const
{
  if(!this->has_printf_buffer_size()) { throw uninitialized_value_error(); }
  return this->_printf_buffer_size.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
image_pitch_alignment() const
{
  if(!this->has_image_pitch_alignment()) { throw uninitialized_value_error(); }
  return this->_image_pitch_alignment.get();
}
/* ----------------------------------------------------------------------- */
cl_uint device_info::
image_base_address_alignment() const
{
  if(!this->has_image_base_address_alignment()) { throw uninitialized_value_error(); }
  return this->_image_base_address_alignment.get();
}
#endif
// }}}
// setters {{{
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_id(unsigned long val) noexcept
{
  this->_id = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_type(device_type_t val) noexcept
{
  this->_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_vendor_id(cl_uint val) noexcept
{
  this->_vendor_id = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_compute_units(cl_uint val) noexcept
{
  this->_max_compute_units = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_work_item_dimensions(cl_uint val) noexcept
{
  this->_max_work_item_dimensions = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_work_group_size(size_t val) noexcept
{
  this->_max_work_group_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_work_item_sizes(std::vector<size_t> const& val)
{
  this->_max_work_item_sizes = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_vector_width_char(cl_uint val) noexcept
{
  this->_preferred_vector_width_char = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_vector_width_short(cl_uint val) noexcept
{
  this->_preferred_vector_width_short = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_vector_width_int(cl_uint val) noexcept
{
  this->_preferred_vector_width_int = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_vector_width_long(cl_uint val) noexcept
{
  this->_preferred_vector_width_long = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_vector_width_float(cl_uint val) noexcept
{
  this->_preferred_vector_width_float = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_vector_width_double(cl_uint val) noexcept
{
  this->_preferred_vector_width_double = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_clock_frequency(cl_uint val) noexcept
{
  this->_max_clock_frequency = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_address_bits(cl_uint val) noexcept
{
  this->_address_bits = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_read_image_args(cl_uint val) noexcept
{
  this->_max_read_image_args = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_write_image_args(cl_uint val) noexcept
{
  this->_max_write_image_args = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_mem_alloc_size(cl_ulong val) noexcept
{
  this->_max_mem_alloc_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image2d_max_width(size_t val) noexcept
{
  this->_image2d_max_width = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image2d_max_height(size_t val) noexcept
{
  this->_image2d_max_height = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image3d_max_width(size_t val) noexcept
{
  this->_image3d_max_width = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image3d_max_height(size_t val) noexcept
{
  this->_image3d_max_height = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image3d_max_depth(size_t val) noexcept
{
  this->_image3d_max_depth = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image_support(cl_bool val) noexcept
{
  this->_image_support = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_parameter_size(size_t val) noexcept
{
  this->_max_parameter_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_samplers(cl_uint val) noexcept
{
  this->_max_samplers = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_mem_base_addr_align(cl_uint val) noexcept
{
  this->_mem_base_addr_align = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_min_data_type_align_size(cl_uint val) noexcept
{
  this->_min_data_type_align_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_single_fp_config(device_fp_config_t val) noexcept
{
  this->_single_fp_config = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_global_mem_cache_type(device_mem_cache_type_t val) noexcept
{
  this->_global_mem_cache_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_global_mem_cacheline_size(cl_uint val) noexcept
{
  this->_global_mem_cacheline_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_global_mem_cache_size(cl_ulong val) noexcept
{
  this->_global_mem_cache_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_global_mem_size(cl_ulong val) noexcept
{
  this->_global_mem_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_constant_buffer_size(cl_uint val) noexcept
{
  this->_max_constant_buffer_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_max_constant_args(cl_uint val) noexcept
{
  this->_max_constant_args = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_local_mem_type(device_local_mem_type_t val) noexcept
{
  this->_local_mem_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_local_mem_size(cl_ulong val) noexcept
{
  this->_local_mem_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_error_correction_support(cl_bool val) noexcept
{
  this->_error_correction_support = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_profiling_timer_resolution(size_t val) noexcept
{
  this->_profiling_timer_resolution = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_endian_little(cl_bool val) noexcept
{
  this->_endian_little = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_available(cl_bool val) noexcept
{
  this->_available = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_compiler_available(cl_bool val) noexcept
{
  this->_compiler_available = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_execution_capabilities(device_exec_capabilities_t val) noexcept
{
  this->_execution_capabilities = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_queue_properties(command_queue_properties_t val) noexcept
{
  this->_queue_properties = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_name(std::string const& val)
{
  this->_name = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_vendor(std::string const& val)
{
  this->_vendor = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_driver_version(std::string const& val)
{
  this->_driver_version = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_profile(std::string const& val)
{
  this->_profile = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_version(std::string const& val)
{
  this->_version = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_extensions(std::string const& val)
{
  this->_extensions = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_platform_id(unsigned long val) noexcept
{
  this->_platform_id = val;
  return *this;
}
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_double_fp_config(device_fp_config_t val) noexcept
{
  this->_double_fp_config = val;
  return *this;
}
#endif
#if CL_VERSION_1_1
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_vector_width_half(cl_uint val) noexcept
{
  this->_preferred_vector_width_half = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_host_unified_memory(cl_bool val) noexcept
{
  this->_host_unified_memory = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_native_vector_width_char(cl_uint val) noexcept
{
  this->_native_vector_width_char = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_native_vector_width_short(cl_uint val) noexcept
{
  this->_native_vector_width_short = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_native_vector_width_int(cl_uint val) noexcept
{
  this->_native_vector_width_int = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_native_vector_width_long(cl_uint val) noexcept
{
  this->_native_vector_width_long = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_native_vector_width_float(cl_uint val) noexcept
{
  this->_native_vector_width_float = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_native_vector_width_double(cl_uint val) noexcept
{
  this->_native_vector_width_double = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_native_vector_width_half(cl_uint val) noexcept
{
  this->_native_vector_width_half = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_opencl_c_version(std::string const& val)
{
  this->_opencl_c_version = val;
  return *this;
}
#endif
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_linker_available(cl_bool val) noexcept
{
  this->_linker_available = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_built_in_kernels(std::string const& val)
{
  this->_built_in_kernels = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image_max_buffer_size(size_t val) noexcept
{
  this->_image_max_buffer_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image_max_array_size(size_t val) noexcept
{
  this->_image_max_array_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_parent_device_id(unsigned long val) noexcept
{
  this->_parent_device_id = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_partition_max_sub_devices(cl_uint val) noexcept
{
  this->_partition_max_sub_devices = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_partition_properties(std::vector<device_partition_property_t> const& val)
{
  this->_partition_properties = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_partition_affinity_domain(device_affinity_domain_t val) noexcept
{
  this->_partition_affinity_domain = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_partition_type(std::vector<device_partition_property_t> const& val)
{
  this->_partition_type = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_reference_count(cl_uint val) noexcept
{
  this->_reference_count = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_preferred_interop_user_sync(cl_bool val) noexcept
{
  this->_preferred_interop_user_sync = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_printf_buffer_size(size_t val) noexcept
{
  this->_printf_buffer_size = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image_pitch_alignment(cl_uint val) noexcept
{
  this->_image_pitch_alignment = val;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
set_image_base_address_alignment(cl_uint val) noexcept
{
  this->_image_base_address_alignment = val;
  return *this;
}
#endif
// }}}
// cleaners {{{
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_id() noexcept
{
  this->_id = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_type() noexcept
{
  this->_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_vendor_id() noexcept
{
  this->_vendor_id = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_compute_units() noexcept
{
  this->_max_compute_units = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_work_item_dimensions() noexcept
{
  this->_max_work_item_dimensions = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_work_group_size() noexcept
{
  this->_max_work_group_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_work_item_sizes() noexcept
{
  this->_max_work_item_sizes = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_vector_width_char() noexcept
{
  this->_preferred_vector_width_char = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_vector_width_short() noexcept
{
  this->_preferred_vector_width_short = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_vector_width_int() noexcept
{
  this->_preferred_vector_width_int = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_vector_width_long() noexcept
{
  this->_preferred_vector_width_long = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_vector_width_float() noexcept
{
  this->_preferred_vector_width_float = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_vector_width_double() noexcept
{
  this->_preferred_vector_width_double = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_clock_frequency() noexcept
{
  this->_max_clock_frequency = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_address_bits() noexcept
{
  this->_address_bits = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_read_image_args() noexcept
{
  this->_max_read_image_args = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_write_image_args() noexcept
{
  this->_max_write_image_args = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_mem_alloc_size() noexcept
{
  this->_max_mem_alloc_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image2d_max_width() noexcept
{
  this->_image2d_max_width = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image2d_max_height() noexcept
{
  this->_image2d_max_height = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image3d_max_width() noexcept
{
  this->_image3d_max_width = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image3d_max_height() noexcept
{
  this->_image3d_max_height = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image3d_max_depth() noexcept
{
  this->_image3d_max_depth = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image_support() noexcept
{
  this->_image_support = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_parameter_size() noexcept
{
  this->_max_parameter_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_samplers() noexcept
{
  this->_max_samplers = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_mem_base_addr_align() noexcept
{
  this->_mem_base_addr_align = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_min_data_type_align_size() noexcept
{
  this->_min_data_type_align_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_single_fp_config() noexcept
{
  this->_single_fp_config = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_global_mem_cache_type() noexcept
{
  this->_global_mem_cache_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_global_mem_cacheline_size() noexcept
{
  this->_global_mem_cacheline_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_global_mem_cache_size() noexcept
{
  this->_global_mem_cache_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_global_mem_size() noexcept
{
  this->_global_mem_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_constant_buffer_size() noexcept
{
  this->_max_constant_buffer_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_max_constant_args() noexcept
{
  this->_max_constant_args = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_local_mem_type() noexcept
{
  this->_local_mem_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_local_mem_size() noexcept
{
  this->_local_mem_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_error_correction_support() noexcept
{
  this->_error_correction_support = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_profiling_timer_resolution() noexcept
{
  this->_profiling_timer_resolution = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_endian_little() noexcept
{
  this->_endian_little = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_available() noexcept
{
  this->_available = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_compiler_available() noexcept
{
  this->_compiler_available = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_execution_capabilities() noexcept
{
  this->_execution_capabilities = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_queue_properties() noexcept
{
  this->_queue_properties = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_name() noexcept
{
  this->_name = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_vendor() noexcept
{
  this->_vendor = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_driver_version() noexcept
{
  this->_driver_version = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_profile() noexcept
{
  this->_profile = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_version() noexcept
{
  this->_version = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_extensions() noexcept
{
  this->_extensions = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_platform_id() noexcept
{
  this->_platform_id = boost::none;
  return *this;
}
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_double_fp_config() noexcept
{
  this->_double_fp_config = boost::none;
  return *this;
}
#endif
#if CL_VERSION_1_1
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_vector_width_half() noexcept
{
  this->_preferred_vector_width_half = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_host_unified_memory() noexcept
{
  this->_host_unified_memory = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_native_vector_width_char() noexcept
{
  this->_native_vector_width_char = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_native_vector_width_short() noexcept
{
  this->_native_vector_width_short = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_native_vector_width_int() noexcept
{
  this->_native_vector_width_int = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_native_vector_width_long() noexcept
{
  this->_native_vector_width_long = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_native_vector_width_float() noexcept
{
  this->_native_vector_width_float = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_native_vector_width_double() noexcept
{
  this->_native_vector_width_double = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_native_vector_width_half() noexcept
{
  this->_native_vector_width_half = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_opencl_c_version() noexcept
{
  this->_opencl_c_version = boost::none;
  return *this;
}
#endif
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_linker_available() noexcept
{
  this->_linker_available = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_built_in_kernels() noexcept
{
  this->_built_in_kernels = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image_max_buffer_size() noexcept
{
  this->_image_max_buffer_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image_max_array_size() noexcept
{
  this->_image_max_array_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_parent_device_id() noexcept
{
  this->_parent_device_id = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_partition_max_sub_devices() noexcept
{
  this->_partition_max_sub_devices = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_partition_properties() noexcept
{
  this->_partition_properties = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_partition_affinity_domain() noexcept
{
  this->_partition_affinity_domain = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_partition_type() noexcept
{
  this->_partition_type = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_reference_count() noexcept
{
  this->_reference_count = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_preferred_interop_user_sync() noexcept
{
  this->_preferred_interop_user_sync = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_printf_buffer_size() noexcept
{
  this->_printf_buffer_size = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image_pitch_alignment() noexcept
{
  this->_image_pitch_alignment = boost::none;
  return *this;
}
/* ----------------------------------------------------------------------- */
device_info& device_info::
clear_image_base_address_alignment() noexcept
{
  this->_image_base_address_alignment = boost::none;
  return *this;
}
#endif
// }}}
// presence {{{
/* ----------------------------------------------------------------------- */
bool device_info::
has_id() const noexcept
{
  return this->_id.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_type() const noexcept
{
  return this->_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_vendor_id() const noexcept
{
  return this->_vendor_id.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_compute_units() const noexcept
{
  return this->_max_compute_units.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_work_item_dimensions() const noexcept
{
  return this->_max_work_item_dimensions.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_work_group_size() const noexcept
{
  return this->_max_work_group_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_work_item_sizes() const noexcept
{
  return this->_max_work_item_sizes.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_vector_width_char() const noexcept
{
  return this->_preferred_vector_width_char.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_vector_width_short() const noexcept
{
  return this->_preferred_vector_width_short.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_vector_width_int() const noexcept
{
  return this->_preferred_vector_width_int.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_vector_width_long() const noexcept
{
  return this->_preferred_vector_width_long.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_vector_width_float() const noexcept
{
  return this->_preferred_vector_width_float.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_vector_width_double() const noexcept
{
  return this->_preferred_vector_width_double.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_clock_frequency() const noexcept
{
  return this->_max_clock_frequency.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_address_bits() const noexcept
{
  return this->_address_bits.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_read_image_args() const noexcept
{
  return this->_max_read_image_args.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_write_image_args() const noexcept
{
  return this->_max_write_image_args.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_mem_alloc_size() const noexcept
{
  return this->_max_mem_alloc_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image2d_max_width() const noexcept
{
  return this->_image2d_max_width.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image2d_max_height() const noexcept
{
  return this->_image2d_max_height.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image3d_max_width() const noexcept
{
  return this->_image3d_max_width.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image3d_max_height() const noexcept
{
  return this->_image3d_max_height.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image3d_max_depth() const noexcept
{
  return this->_image3d_max_depth.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image_support() const noexcept
{
  return this->_image_support.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_parameter_size() const noexcept
{
  return this->_max_parameter_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_samplers() const noexcept
{
  return this->_max_samplers.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_mem_base_addr_align() const noexcept
{
  return this->_mem_base_addr_align.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_min_data_type_align_size() const noexcept
{
  return this->_min_data_type_align_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_single_fp_config() const noexcept
{
  return this->_single_fp_config.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_global_mem_cache_type() const noexcept
{
  return this->_global_mem_cache_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_global_mem_cacheline_size() const noexcept
{
  return this->_global_mem_cacheline_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_global_mem_cache_size() const noexcept
{
  return this->_global_mem_cache_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_global_mem_size() const noexcept
{
  return this->_global_mem_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_constant_buffer_size() const noexcept
{
  return this->_max_constant_buffer_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_max_constant_args() const noexcept
{
  return this->_max_constant_args.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_local_mem_type() const noexcept
{
  return this->_local_mem_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_local_mem_size() const noexcept
{
  return this->_local_mem_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_error_correction_support() const noexcept
{
  return this->_error_correction_support.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_profiling_timer_resolution() const noexcept
{
  return this->_profiling_timer_resolution.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_endian_little() const noexcept
{
  return this->_endian_little.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_available() const noexcept
{
  return this->_available.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_compiler_available() const noexcept
{
  return this->_compiler_available.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_execution_capabilities() const noexcept
{
  return this->_execution_capabilities.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_queue_properties() const noexcept
{
  return this->_queue_properties.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_name() const noexcept
{
  return this->_name.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_vendor() const noexcept
{
  return this->_vendor.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_driver_version() const noexcept
{
  return this->_driver_version.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_profile() const noexcept
{
  return this->_profile.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_version() const noexcept
{
  return this->_version.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_extensions() const noexcept
{
  return this->_extensions.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_platform_id() const noexcept
{
  return this->_platform_id.is_initialized();
}
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
bool device_info::
has_double_fp_config() const noexcept
{
  return this->_double_fp_config.is_initialized();
}
#endif
#if CL_VERSION_1_1
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_vector_width_half() const noexcept
{
  return this->_preferred_vector_width_half.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_host_unified_memory() const noexcept
{
  return this->_host_unified_memory.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_native_vector_width_char() const noexcept
{
  return this->_native_vector_width_char.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_native_vector_width_short() const noexcept
{
  return this->_native_vector_width_short.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_native_vector_width_int() const noexcept
{
  return this->_native_vector_width_int.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_native_vector_width_long() const noexcept
{
  return this->_native_vector_width_long.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_native_vector_width_float() const noexcept
{
  return this->_native_vector_width_float.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_native_vector_width_double() const noexcept
{
  return this->_native_vector_width_double.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_native_vector_width_half() const noexcept
{
  return this->_native_vector_width_half.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_opencl_c_version() const noexcept
{
  return this->_opencl_c_version.is_initialized();
}
#endif
#if CL_VERSION_1_2
/* ----------------------------------------------------------------------- */
bool device_info::
has_linker_available() const noexcept
{
  return this->_linker_available.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_built_in_kernels() const noexcept
{
  return this->_built_in_kernels.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image_max_buffer_size() const noexcept
{
  return this->_image_max_buffer_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image_max_array_size() const noexcept
{
  return this->_image_max_array_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_parent_device_id() const noexcept
{
  return this->_parent_device_id.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_partition_max_sub_devices() const noexcept
{
  return this->_partition_max_sub_devices.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_partition_properties() const noexcept
{
  return this->_partition_properties.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_partition_affinity_domain() const noexcept
{
  return this->_partition_affinity_domain.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_partition_type() const noexcept
{
  return this->_partition_type.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_reference_count() const noexcept
{
  return this->_reference_count.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_preferred_interop_user_sync() const noexcept
{
  return this->_preferred_interop_user_sync.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_printf_buffer_size() const noexcept
{
  return this->_printf_buffer_size.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image_pitch_alignment() const noexcept
{
  return this->_image_pitch_alignment.is_initialized();
}
/* ----------------------------------------------------------------------- */
bool device_info::
has_image_base_address_alignment() const noexcept
{
  return this->_image_base_address_alignment.is_initialized();
}
#endif
// }}}
/* ----------------------------------------------------------------------- */
void device_info::
_clear()
{
  this -> _id = boost::none;
  this -> _type = boost::none;
  this -> _vendor_id = boost::none;
  this -> _max_compute_units = boost::none;
  this -> _max_work_item_dimensions = boost::none;
  this -> _max_work_item_sizes = boost::none;
  this -> _max_work_group_size = boost::none;
  this -> _preferred_vector_width_char = boost::none;
  this -> _preferred_vector_width_short = boost::none;
  this -> _preferred_vector_width_int = boost::none;
  this -> _preferred_vector_width_long = boost::none;
  this -> _preferred_vector_width_float = boost::none;
  this -> _preferred_vector_width_double = boost::none;
  this -> _max_clock_frequency = boost::none;
  this -> _address_bits = boost::none;
  this -> _max_read_image_args = boost::none;
  this -> _max_write_image_args = boost::none;
  this -> _max_mem_alloc_size = boost::none;
  this -> _image2d_max_width = boost::none;
  this -> _image2d_max_height = boost::none;
  this -> _image3d_max_width = boost::none;
  this -> _image3d_max_height = boost::none;
  this -> _image3d_max_depth = boost::none;
  this -> _image_support = boost::none;
  this -> _max_parameter_size = boost::none;
  this -> _max_samplers = boost::none;
  this -> _mem_base_addr_align = boost::none;
  this -> _min_data_type_align_size = boost::none;
  this -> _single_fp_config = boost::none;
  this -> _global_mem_cache_type = boost::none;
  this -> _global_mem_cacheline_size = boost::none;
  this -> _global_mem_cache_size = boost::none;
  this -> _global_mem_size = boost::none;
  this -> _max_constant_buffer_size = boost::none;
  this -> _max_constant_args = boost::none;
  this -> _local_mem_type = boost::none;
  this -> _local_mem_size = boost::none;
  this -> _error_correction_support = boost::none;
  this -> _profiling_timer_resolution = boost::none;
  this -> _endian_little = boost::none;
  this -> _available = boost::none;
  this -> _compiler_available = boost::none;
  this -> _execution_capabilities = boost::none;
  this -> _queue_properties = boost::none;
  this -> _name = boost::none;
  this -> _vendor = boost::none;
  this -> _driver_version = boost::none;
  this -> _profile = boost::none;
  this -> _version = boost::none;
  this -> _extensions = boost::none;
  this -> _platform_id = boost::none;
#if CL_VERSION_1_2
  this -> _double_fp_config = boost::none;
#endif
#if CL_VERSION_1_1
  this -> _preferred_vector_width_half = boost::none;
  this -> _host_unified_memory = boost::none;
  this -> _native_vector_width_char = boost::none;
  this -> _native_vector_width_short = boost::none;
  this -> _native_vector_width_int = boost::none;
  this -> _native_vector_width_long = boost::none;
  this -> _native_vector_width_float = boost::none;
  this -> _native_vector_width_double = boost::none;
  this -> _native_vector_width_half = boost::none;
  this -> _opencl_c_version = boost::none;
#endif
#if CL_VERSION_1_2
  this -> _linker_available = boost::none;
  this -> _built_in_kernels = boost::none;
  this -> _image_max_buffer_size = boost::none;
  this -> _image_max_array_size = boost::none;
  this -> _parent_device_id = boost::none;
  this -> _partition_max_sub_devices = boost::none;
  this -> _partition_properties = boost::none;
  this -> _partition_affinity_domain = boost::none;
  this -> _partition_type = boost::none;
  this -> _reference_count = boost::none;
  this -> _preferred_interop_user_sync = boost::none;
  this -> _printf_buffer_size = boost::none;
  this -> _image_pitch_alignment = boost::none;
  this -> _image_base_address_alignment = boost::none;
#endif
}

} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
