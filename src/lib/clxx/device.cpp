// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device.cpp

/** // doc: clxx/device.cpp {{{
 * \file clxx/device.cpp
 * \brief Implements the \ref clxx::device "device" class
 */ // }}}
#include <clxx/device.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <boost/shared_array.hpp>
#include <string>
#include <cstdio>

namespace clxx {

static std::string
_get_str_info(device const& dev, device_info_t name)
{
  size_t size;
  dev.get_info(name, 0, NULL, &size);

  boost::shared_array<char> str(new char[size]);
  dev.get_info(name, size, str.get(), &size);
  return std::string(str.get());
}
template<typename T> static T
_get_pod_info(device const& dev, device_info_t name)
{
  T value;
  dev.get_info(name, sizeof(value), &value, NULL);
  return value;
}
template<typename T> static std::vector<T>
_get_vec_info(device const& dev, device_info_t name)
{
  size_t size;
  dev.get_info(name, 0, NULL, &size);
  std::vector<T> values(size/sizeof(T));
  dev.get_info(name, values.size() * sizeof(T), &values.front(), NULL);
  return values;
}
/* ------------------------------------------------------------------------ */
cl_device_id device::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_device_error();
  return this->_device_id;
}
/* ------------------------------------------------------------------------ */
void device::
get_info( device_info_t name, size_t value_size, void* value,
          size_t* value_size_ret) const
{
  get_device_info(this->get_valid_id(), name, value_size, value, value_size_ret);
}
/* ------------------------------------------------------------------------ */
device_type_t device::
get_type() const
{
  return _get_pod_info<device_type_t>(*this, device_info_t::type);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_vendor_id() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::vendor_id);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_max_compute_units() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::max_compute_units);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_max_work_item_dimensions() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::max_work_item_dimensions);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_max_work_group_size() const
{
  return _get_pod_info<size_t>(*this, device_info_t::max_work_group_size);
}
/* ------------------------------------------------------------------------ */
std::vector<size_t> device::
get_max_work_item_sizes() const
{
  return _get_vec_info<size_t>(*this, device_info_t::max_work_item_sizes);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_preferred_vector_width_char() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::preferred_vector_width_char);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_preferred_vector_width_short() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::preferred_vector_width_short);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_preferred_vector_width_int() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::preferred_vector_width_int);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_preferred_vector_width_long() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::preferred_vector_width_long);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_preferred_vector_width_float() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::preferred_vector_width_float);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_preferred_vector_width_double() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::preferred_vector_width_double);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_max_clock_frequency() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::max_clock_frequency);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_address_bits() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::address_bits);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_max_read_image_args() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::max_read_image_args);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_max_write_image_args() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::max_write_image_args);
}
/* ------------------------------------------------------------------------ */
cl_ulong device::
get_max_mem_alloc_size() const
{
  return _get_pod_info<cl_ulong>(*this, device_info_t::max_mem_alloc_size);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_image2d_max_width() const
{
  return _get_pod_info<size_t>(*this, device_info_t::image2d_max_width);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_image2d_max_height() const
{
  return _get_pod_info<size_t>(*this, device_info_t::image2d_max_height);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_image3d_max_width() const
{
  return _get_pod_info<size_t>(*this, device_info_t::image3d_max_width);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_image3d_max_height() const
{
  return _get_pod_info<size_t>(*this, device_info_t::image3d_max_height);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_image3d_max_depth() const
{
  return _get_pod_info<size_t>(*this, device_info_t::image3d_max_depth);
}
/* ------------------------------------------------------------------------ */
cl_bool device::
get_image_support() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::image_support);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_max_parameter_size() const
{
  return _get_pod_info<size_t>(*this, device_info_t::max_parameter_size);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_max_samplers() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::max_samplers);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_mem_base_addr_align() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::mem_base_addr_align);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_min_data_type_align_size() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::min_data_type_align_size);
}
/* ------------------------------------------------------------------------ */
device_fp_config_t device::
get_single_fp_config() const
{
  return _get_pod_info<device_fp_config_t >(*this, device_info_t::single_fp_config);
}
/* ------------------------------------------------------------------------ */
device_mem_cache_type_t device::
get_global_mem_cache_type() const
{
  return _get_pod_info<device_mem_cache_type_t>(*this,
    device_info_t::global_mem_cache_type);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_global_mem_cacheline_size() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::global_mem_cacheline_size);
}
/* ------------------------------------------------------------------------ */
cl_ulong device::
get_global_mem_cache_size() const
{
  return _get_pod_info<cl_ulong>(*this, device_info_t::global_mem_cache_size);
}
/* ------------------------------------------------------------------------ */
cl_ulong device::
get_global_mem_size() const
{
  return _get_pod_info<cl_ulong>(*this, device_info_t::global_mem_size);
}
/* ------------------------------------------------------------------------ */
cl_ulong device::
get_max_constant_buffer_size() const
{
  return _get_pod_info<cl_ulong>(*this, device_info_t::max_constant_buffer_size);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_max_constant_args() const
{
  return _get_pod_info<cl_int>(*this, device_info_t::max_constant_args);
}
/* ------------------------------------------------------------------------ */
device_local_mem_type_t device::
get_local_mem_type() const
{
  return _get_pod_info<device_local_mem_type_t>(*this,
    device_info_t::local_mem_type);
}
/* ------------------------------------------------------------------------ */
cl_ulong device::
get_local_mem_size() const
{
  return _get_pod_info<cl_ulong>(*this, device_info_t::local_mem_size);
}
/* ------------------------------------------------------------------------ */
cl_bool device::
get_error_correction_support() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::error_correction_support);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_profiling_timer_resolution() const
{
  return _get_pod_info<size_t>(*this, device_info_t::profiling_timer_resolution);
}
/* ------------------------------------------------------------------------ */
cl_bool device::
get_endian_little() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::endian_little);
}
/* ------------------------------------------------------------------------ */
cl_bool device::
get_available() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::available);
}
/* ------------------------------------------------------------------------ */
cl_bool device::
get_compiler_available() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::compiler_available);
}
/* ------------------------------------------------------------------------ */
device_exec_capabilities_t device::
get_execution_capabilities() const
{
  return _get_pod_info<device_exec_capabilities_t>(*this,
    device_info_t::execution_capabilities);
}
/* ------------------------------------------------------------------------ */
command_queue_properties_t device::
get_queue_properties() const
{
  return _get_pod_info<command_queue_properties_t>(*this,
    device_info_t::queue_properties);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_name() const
{
  return _get_str_info(*this, device_info_t::name);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_vendor() const
{
  return _get_str_info(*this, device_info_t::vendor);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_driver_version() const
{
  return _get_str_info(*this, device_info_t::driver_version);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_profile() const
{
  return _get_str_info(*this, device_info_t::profile);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_version() const
{
  return _get_str_info(*this, device_info_t::version);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_extensions() const
{
  return _get_str_info(*this, device_info_t::extensions);
}
/* ------------------------------------------------------------------------ */
cl_platform_id device::
get_platform_id() const
{
  return _get_pod_info<cl_platform_id>(*this, device_info_t::platform);
}
#if CL_VERSION_1_2
/* ------------------------------------------------------------------------ */
device_fp_config_t device::
get_double_fp_config() const
{
  return _get_pod_info<device_fp_config_t>(*this, device_info_t::double_fp_config);
}
#endif
#if CL_VERSION_1_1
/* ------------------------------------------------------------------------ */
cl_uint device::
get_preferred_vector_width_half() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::preferred_vector_width_half);
}
/* ------------------------------------------------------------------------ */
cl_bool device::
get_host_unified_memory() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::host_unified_memory);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_native_vector_width_char() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::native_vector_width_char);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_native_vector_width_short() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::native_vector_width_short);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_native_vector_width_int() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::native_vector_width_int);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_native_vector_width_long() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::native_vector_width_long);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_native_vector_width_float() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::native_vector_width_float);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_native_vector_width_double() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::native_vector_width_double);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_native_vector_width_half() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::native_vector_width_half);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_opencl_c_version() const
{
  return _get_str_info(*this, device_info_t::opencl_c_version);
}
#endif
#if CL_VERSION_1_2
/* ------------------------------------------------------------------------ */
cl_bool device::
get_linker_available() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::linker_available);
}
/* ------------------------------------------------------------------------ */
std::string device::
get_built_in_kernels() const
{
  return _get_str_info(*this, device_info_t::built_in_kernels);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_image_max_buffer_size() const
{
  return _get_pod_info<size_t>(*this, device_info_t::image_max_buffer_size);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_image_max_array_size() const
{
  return _get_pod_info<size_t>(*this, device_info_t::image_max_array_size);
}
/* ------------------------------------------------------------------------ */
cl_device_id device::
get_parent_device_id() const
{
  return _get_pod_info<cl_device_id>(*this, device_info_t::parent_device);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_partition_max_sub_devices() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::partition_max_sub_devices);
}
/* ------------------------------------------------------------------------ */
std::vector<device_partition_property_t> device::
get_partition_properties() const
{
  return _get_vec_info<device_partition_property_t>(*this, device_info_t::partition_properties);
}
/* ------------------------------------------------------------------------ */
device_affinity_domain_t device::
get_partition_affinity_domain() const
{
  return _get_pod_info<device_affinity_domain_t>(*this, device_info_t::partition_affinity_domain);
}
/* ------------------------------------------------------------------------ */
std::vector<device_partition_property_t> device::
get_partition_type() const
{
  return _get_vec_info<device_partition_property_t>(*this, device_info_t::partition_type);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::reference_count);
}
/* ------------------------------------------------------------------------ */
cl_bool device::
get_preferred_interop_user_sync() const
{
  return _get_pod_info<cl_bool>(*this, device_info_t::preferred_interop_user_sync);
}
/* ------------------------------------------------------------------------ */
size_t device::
get_printf_buffer_size() const
{
  return _get_pod_info<size_t>(*this, device_info_t::printf_buffer_size);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_image_pitch_alignment() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::image_pitch_alignment);
}
/* ------------------------------------------------------------------------ */
cl_uint device::
get_image_base_address_alignment() const
{
  return _get_pod_info<cl_uint>(*this, device_info_t::image_base_address_alignment);
}
/* ------------------------------------------------------------------------ */
#endif

} // end namespace clxx

namespace clxx {

/* ------------------------------------------------------------------------ */
device_info
query_device_info(device const& dev, device_query const& query)
{
  std::string vs(dev.get_version());
  unsigned int major, minor;

  if(std::sscanf(vs.c_str(), "OpenCL %u.%u", &major, &minor) != 2)
    {
      major = 1;
      minor = 0;
    }

  device_query query2(query);
  query2.restrict_to(major, minor);

  device_info info;

  if(query2.id_selected()) {
    info.set_id(reinterpret_cast<unsigned long>(dev.id()));
  }
  if(query2.type_selected()) {
    info.set_type(dev.get_type());
  }
  if(query2.vendor_id_selected()) {
    info.set_vendor_id(dev.get_vendor_id());
  }
  if(query2.max_compute_units_selected()) {
    info.set_max_compute_units(dev.get_max_compute_units());
  }
  if(query2.max_work_item_dimensions_selected()) {
    info.set_max_work_item_dimensions(dev.get_max_work_item_dimensions());
  }
  if(query2.max_work_item_sizes_selected()) {
    info.set_max_work_item_sizes(dev.get_max_work_item_sizes());
  }
  if(query2.max_work_group_size_selected()) {
    info.set_max_work_group_size(dev.get_max_work_group_size());
  }
  if(query2.preferred_vector_width_char_selected()) {
    info.set_preferred_vector_width_char(dev.get_preferred_vector_width_char());
  }
  if(query2.preferred_vector_width_short_selected()) {
    info.set_preferred_vector_width_short(dev.get_preferred_vector_width_short());
  }
  if(query2.preferred_vector_width_int_selected()) {
    info.set_preferred_vector_width_int(dev.get_preferred_vector_width_int());
  }
  if(query2.preferred_vector_width_long_selected()) {
    info.set_preferred_vector_width_long(dev.get_preferred_vector_width_long());
  }
  if(query2.preferred_vector_width_float_selected()) {
    info.set_preferred_vector_width_float(dev.get_preferred_vector_width_float());
  }
  if(query2.preferred_vector_width_double_selected()) {
    info.set_preferred_vector_width_double(dev.get_preferred_vector_width_double());
  }
  if(query2.max_clock_frequency_selected()) {
    info.set_max_clock_frequency(dev.get_max_clock_frequency());
  }
  if(query2.address_bits_selected()) {
    info.set_address_bits(dev.get_address_bits());
  }
  if(query2.max_read_image_args_selected()) {
    info.set_max_read_image_args(dev.get_max_read_image_args());
  }
  if(query2.max_write_image_args_selected()) {
    info.set_max_write_image_args(dev.get_max_write_image_args());
  }
  if(query2.max_mem_alloc_size_selected()) {
    info.set_max_mem_alloc_size(dev.get_max_mem_alloc_size());
  }
  if(query2.image2d_max_width_selected()) {
    info.set_image2d_max_width(dev.get_image2d_max_width());
  }
  if(query2.image2d_max_height_selected()) {
    info.set_image2d_max_height(dev.get_image2d_max_height());
  }
  if(query2.image3d_max_width_selected()) {
    info.set_image3d_max_width(dev.get_image3d_max_width());
  }
  if(query2.image3d_max_height_selected()) {
    info.set_image3d_max_height(dev.get_image3d_max_height());
  }
  if(query2.image3d_max_depth_selected()) {
    info.set_image3d_max_depth(dev.get_image3d_max_depth());
  }
  if(query2.image_support_selected()) {
    info.set_image_support(dev.get_image_support());
  }
  if(query2.max_parameter_size_selected()) {
    info.set_max_parameter_size(dev.get_max_parameter_size());
  }
  if(query2.max_samplers_selected()) {
    info.set_max_samplers(dev.get_max_samplers());
  }
  if(query2.mem_base_addr_align_selected()) {
    info.set_mem_base_addr_align(dev.get_mem_base_addr_align());
  }
  if(query2.min_data_type_align_size_selected()) {
    info.set_min_data_type_align_size(dev.get_min_data_type_align_size());
  }
  if(query2.single_fp_config_selected()) {
    info.set_single_fp_config(dev.get_single_fp_config());
  }
  if(query2.global_mem_cache_type_selected()) {
    info.set_global_mem_cache_type(dev.get_global_mem_cache_type());
  }
  if(query2.global_mem_cacheline_size_selected()) {
    info.set_global_mem_cacheline_size(dev.get_global_mem_cacheline_size());
  }
  if(query2.global_mem_cache_size_selected()) {
    info.set_global_mem_cache_size(dev.get_global_mem_cache_size());
  }
  if(query2.global_mem_size_selected()) {
    info.set_global_mem_size(dev.get_global_mem_size());
  }
  if(query2.max_constant_buffer_size_selected()) {
    info.set_max_constant_buffer_size(dev.get_max_constant_buffer_size());
  }
  if(query2.max_constant_args_selected()) {
    info.set_max_constant_args(dev.get_max_constant_args());
  }
  if(query2.local_mem_type_selected()) {
    info.set_local_mem_type(dev.get_local_mem_type());
  }
  if(query2.local_mem_size_selected()) {
    info.set_local_mem_size(dev.get_local_mem_size());
  }
  if(query2.error_correction_support_selected()) {
    info.set_error_correction_support(dev.get_error_correction_support());
  }
  if(query2.profiling_timer_resolution_selected()) {
    info.set_profiling_timer_resolution(dev.get_profiling_timer_resolution());
  }
  if(query2.endian_little_selected()) {
    info.set_endian_little(dev.get_endian_little());
  }
  if(query2.available_selected()) {
    info.set_available(dev.get_available());
  }
  if(query2.compiler_available_selected()) {
    info.set_compiler_available(dev.get_compiler_available());
  }
  if(query2.execution_capabilities_selected()) {
    info.set_execution_capabilities(dev.get_execution_capabilities());
  }
  if(query2.queue_properties_selected()) {
    info.set_queue_properties(dev.get_queue_properties());
  }
  if(query2.name_selected()) {
    info.set_name(dev.get_name());
  }
  if(query2.vendor_selected()) {
    info.set_vendor(dev.get_vendor());
  }
  if(query2.driver_version_selected()) {
    info.set_driver_version(dev.get_driver_version());
  }
  if(query2.profile_selected()) {
    info.set_profile(dev.get_profile());
  }
  if(query2.version_selected()) {
    info.set_version(vs);
  }
  if(query2.extensions_selected()) {
    info.set_extensions(dev.get_extensions());
  }
  if(query2.platform_id_selected()) {
    info.set_platform_id(reinterpret_cast<unsigned long>(dev.get_platform_id()));
  }
#if CL_VERSION_1_2
  if(query2.double_fp_config_selected()) {
    info.set_double_fp_config(dev.get_double_fp_config());
  }
#endif
#if CL_VERSION_1_1
  if(query2.preferred_vector_width_half_selected()) {
    info.set_preferred_vector_width_half(dev.get_preferred_vector_width_half());
  }
  if(query2.host_unified_memory_selected()) {
    info.set_host_unified_memory(dev.get_host_unified_memory());
  }
  if(query2.native_vector_width_char_selected()) {
    info.set_native_vector_width_char(dev.get_native_vector_width_char());
  }
  if(query2.native_vector_width_short_selected()) {
    info.set_native_vector_width_short(dev.get_native_vector_width_short());
  }
  if(query2.native_vector_width_int_selected()) {
    info.set_native_vector_width_int(dev.get_native_vector_width_int());
  }
  if(query2.native_vector_width_long_selected()) {
    info.set_native_vector_width_long(dev.get_native_vector_width_long());
  }
  if(query2.native_vector_width_float_selected()) {
    info.set_native_vector_width_float(dev.get_native_vector_width_float());
  }
  if(query2.native_vector_width_double_selected()) {
    info.set_native_vector_width_double(dev.get_native_vector_width_double());
  }
  if(query2.native_vector_width_half_selected()) {
    info.set_native_vector_width_half(dev.get_native_vector_width_half());
  }
  if(query2.opencl_c_version_selected()) {
    info.set_opencl_c_version(dev.get_opencl_c_version());
  }
#endif
#if CL_VERSION_1_2
  if(query2.linker_available_selected()) {
    info.set_linker_available(dev.get_linker_available());
  }
  if(query2.built_in_kernels_selected()) {
    info.set_built_in_kernels(dev.get_built_in_kernels());
  }
  if(query2.image_max_buffer_size_selected()) {
    info.set_image_max_buffer_size(dev.get_image_max_buffer_size());
  }
  if(query2.image_max_array_size_selected()) {
    info.set_image_max_array_size(dev.get_image_max_array_size());
  }
  if(query2.parent_device_id_selected()) {
    info.set_parent_device_id(reinterpret_cast<unsigned long>(dev.get_parent_device_id()));
  }
  if(query2.partition_max_sub_devices_selected()) {
    info.set_partition_max_sub_devices(dev.get_partition_max_sub_devices());
  }
  if(query2.partition_properties_selected()) {
    info.set_partition_properties(dev.get_partition_properties());
  }
  if(query2.partition_affinity_domain_selected()) {
    info.set_partition_affinity_domain(dev.get_partition_affinity_domain());
  }
  if(query2.partition_type_selected()) {
    info.set_partition_type(dev.get_partition_type());
  }
  if(query2.reference_count_selected()) {
    info.set_reference_count(dev.get_reference_count());
  }
  if(query2.preferred_interop_user_sync_selected()) {
    info.set_preferred_interop_user_sync(dev.get_preferred_interop_user_sync());
  }
  if(query2.printf_buffer_size_selected()) {
    info.set_printf_buffer_size(dev.get_printf_buffer_size());
  }
  if(query2.image_pitch_alignment_selected()) {
    info.set_image_pitch_alignment(dev.get_image_pitch_alignment());
  }
  if(query2.image_base_address_alignment_selected()) {
    info.set_image_base_address_alignment(dev.get_image_base_address_alignment());
  }
#endif

  return info;
}
/* ----------------------------------------------------------------------- */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
