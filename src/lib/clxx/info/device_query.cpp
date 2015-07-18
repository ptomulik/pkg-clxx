// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/device_query.cpp

/** // doc: clxx/info/device_query.cpp {{{
 * \file clxx/info/device_query.cpp
 * \brief Implements the \ref clxx::device_query "device_query" class
 */ // }}}
#include <clxx/info/device_query.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
device_query::
device_query() noexcept
{
  _init(true);
}
/* ------------------------------------------------------------------------ */
device_query::
device_query(bool flag) noexcept
{
  _init(flag);
}
/* ------------------------------------------------------------------------ */
device_query::
~device_query() noexcept
{
}
/* ------------------------------------------------------------------------ */
device_query& device_query::
select_all() noexcept
{
  this->_select(true);
  return *this;
}
/* ------------------------------------------------------------------------ */
device_query& device_query::
select_none() noexcept
{
  this->_select(false);
  return *this;
}
/* ------------------------------------------------------------------------ */
device_query& device_query::
select_default() noexcept
{
  return this->select_all();
}
/* ------------------------------------------------------------------------ */
device_query& device_query::
restrict_to(int major, int minor) noexcept
{
  if(major == 1 && minor < 1)
    {
      // ver < 1.1
      this->select_preferred_vector_width_half(false);
      this->select_host_unified_memory(false);
      this->select_native_vector_width_char(false);
      this->select_native_vector_width_short(false);
      this->select_native_vector_width_int(false);
      this->select_native_vector_width_long(false);
      this->select_native_vector_width_float(false);
      this->select_native_vector_width_double(false);
      this->select_native_vector_width_half(false);
      this->select_opencl_c_version(false);
    }
  if(major == 1 && minor < 2)
    {
      // ver < 1.2
      this->select_double_fp_config(false);
      this->select_linker_available(false);
      this->select_built_in_kernels(false);
      this->select_image_max_buffer_size(false);
      this->select_image_max_array_size(false);
      this->select_parent_device_id(false);
      this->select_partition_max_sub_devices(false);
      this->select_partition_properties(false);
      this->select_partition_affinity_domain(false);
      this->select_partition_type(false);
      this->select_reference_count(false);
      this->select_preferred_interop_user_sync(false);
      this->select_printf_buffer_size(false);
      this->select_image_pitch_alignment(false);
      this->select_image_base_address_alignment(false);
    }
  return *this;
}
/* ------------------------------------------------------------------------ */
void device_query::
_init(bool flag) noexcept
{
  this->_select(flag);
}
/* ------------------------------------------------------------------------ */
void device_query::
_select(bool flag) noexcept
{
  this -> select_id(flag);
  this -> select_type(flag);
  this -> select_vendor_id(flag);
  this -> select_max_compute_units(flag);
  this -> select_max_work_item_dimensions(flag);
  this -> select_max_work_group_size(flag);
  this -> select_max_work_item_sizes(flag);
  this -> select_preferred_vector_width_char(flag);
  this -> select_preferred_vector_width_short(flag);
  this -> select_preferred_vector_width_int(flag);
  this -> select_preferred_vector_width_long(flag);
  this -> select_preferred_vector_width_float(flag);
  this -> select_preferred_vector_width_double(flag);
  this -> select_max_clock_frequency(flag);
  this -> select_address_bits(flag);
  this -> select_max_read_image_args(flag);
  this -> select_max_write_image_args(flag);
  this -> select_max_mem_alloc_size(flag);
  this -> select_image2d_max_width(flag);
  this -> select_image2d_max_height(flag);
  this -> select_image3d_max_width(flag);
  this -> select_image3d_max_height(flag);
  this -> select_image3d_max_depth(flag);
  this -> select_image_support(flag);
  this -> select_max_parameter_size(flag);
  this -> select_max_samplers(flag);
  this -> select_mem_base_addr_align(flag);
  this -> select_min_data_type_align_size(flag);
  this -> select_single_fp_config(flag);
  this -> select_global_mem_cache_type(flag);
  this -> select_global_mem_cacheline_size(flag);
  this -> select_global_mem_cache_size(flag);
  this -> select_global_mem_size(flag);
  this -> select_max_constant_buffer_size(flag);
  this -> select_max_constant_args(flag);
  this -> select_local_mem_type(flag);
  this -> select_local_mem_size(flag);
  this -> select_error_correction_support(flag);
  this -> select_host_unified_memory(flag);
  this -> select_profiling_timer_resolution(flag);
  this -> select_endian_little(flag);
  this -> select_available(flag);
  this -> select_compiler_available(flag);
  this -> select_execution_capabilities(flag);
  this -> select_queue_properties(flag);
  this -> select_name(flag);
  this -> select_vendor(flag);
  this -> select_driver_version(flag);
  this -> select_profile(flag);
  this -> select_version(flag);
  this -> select_extensions(flag);
  this -> select_platform_id(flag);
  this -> select_double_fp_config(flag);
  this -> select_preferred_vector_width_half(flag);
  this -> select_native_vector_width_char(flag);
  this -> select_native_vector_width_short(flag);
  this -> select_native_vector_width_int(flag);
  this -> select_native_vector_width_long(flag);
  this -> select_native_vector_width_float(flag);
  this -> select_native_vector_width_double(flag);
  this -> select_native_vector_width_half(flag);
  this -> select_opencl_c_version(flag);
  this -> select_linker_available(flag);
  this -> select_built_in_kernels(flag);
  this -> select_image_max_buffer_size(flag);
  this -> select_image_max_array_size(flag);
  this -> select_parent_device_id(flag);
  this -> select_partition_max_sub_devices(flag);
  this -> select_partition_properties(flag);
  this -> select_partition_affinity_domain(flag);
  this -> select_partition_type(flag);
  this -> select_reference_count(flag);
  this -> select_preferred_interop_user_sync(flag);
  this -> select_printf_buffer_size(flag);
  this -> select_image_pitch_alignment(flag);
  this -> select_image_base_address_alignment(flag);
}
/* ------------------------------------------------------------------------ */
bool operator== (device_query const& a, device_query const& b) noexcept
{
  return (a.id_selected() == b.id_selected()
       && a.type_selected() == b.type_selected()
       && a.vendor_id_selected() == b.vendor_id_selected()
       && a.max_compute_units_selected() == b.max_compute_units_selected()
       && a.max_work_item_dimensions_selected() == b.max_work_item_dimensions_selected()
       && a.max_work_group_size_selected() == b.max_work_group_size_selected()
       && a.max_work_item_sizes_selected() == b.max_work_item_sizes_selected()
       && a.preferred_vector_width_char_selected() == b.preferred_vector_width_char_selected()
       && a.preferred_vector_width_short_selected() == b.preferred_vector_width_short_selected()
       && a.preferred_vector_width_int_selected() == b.preferred_vector_width_int_selected()
       && a.preferred_vector_width_long_selected() == b.preferred_vector_width_long_selected()
       && a.preferred_vector_width_float_selected() == b.preferred_vector_width_float_selected()
       && a.preferred_vector_width_double_selected() == b.preferred_vector_width_double_selected()
       && a.max_clock_frequency_selected() == b.max_clock_frequency_selected()
       && a.address_bits_selected() == b.address_bits_selected()
       && a.max_read_image_args_selected() == b.max_read_image_args_selected()
       && a.max_write_image_args_selected() == b.max_write_image_args_selected()
       && a.max_mem_alloc_size_selected() == b.max_mem_alloc_size_selected()
       && a.image2d_max_width_selected() == b.image2d_max_width_selected()
       && a.image2d_max_height_selected() == b.image2d_max_height_selected()
       && a.image3d_max_width_selected() == b.image3d_max_width_selected()
       && a.image3d_max_height_selected() == b.image3d_max_height_selected()
       && a.image3d_max_depth_selected() == b.image3d_max_depth_selected()
       && a.image_support_selected() == b.image_support_selected()
       && a.max_parameter_size_selected() == b.max_parameter_size_selected()
       && a.max_samplers_selected() == b.max_samplers_selected()
       && a.mem_base_addr_align_selected() == b.mem_base_addr_align_selected()
       && a.min_data_type_align_size_selected() == b.min_data_type_align_size_selected()
       && a.single_fp_config_selected() == b.single_fp_config_selected()
       && a.global_mem_cache_type_selected() == b.global_mem_cache_type_selected()
       && a.global_mem_cacheline_size_selected() == b.global_mem_cacheline_size_selected()
       && a.global_mem_cache_size_selected() == b.global_mem_cache_size_selected()
       && a.global_mem_size_selected() == b.global_mem_size_selected()
       && a.max_constant_buffer_size_selected() == b.max_constant_buffer_size_selected()
       && a.max_constant_args_selected() == b.max_constant_args_selected()
       && a.local_mem_type_selected() == b.local_mem_type_selected()
       && a.local_mem_size_selected() == b.local_mem_size_selected()
       && a.error_correction_support_selected() == b.error_correction_support_selected()
       && a.profiling_timer_resolution_selected() == b.profiling_timer_resolution_selected()
       && a.endian_little_selected() == b.endian_little_selected()
       && a.available_selected() == b.available_selected()
       && a.compiler_available_selected() == b.compiler_available_selected()
       && a.execution_capabilities_selected() == b.execution_capabilities_selected()
       && a.queue_properties_selected() == b.queue_properties_selected()
       && a.name_selected() == b.name_selected()
       && a.vendor_selected() == b.vendor_selected()
       && a.driver_version_selected() == b.driver_version_selected()
       && a.profile_selected() == b.profile_selected()
       && a.version_selected() == b.version_selected()
       && a.extensions_selected() == b.extensions_selected()
       && a.platform_id_selected() == b.platform_id_selected()
       && a.double_fp_config_selected() == b.double_fp_config_selected()
       && a.preferred_vector_width_half_selected() == b.preferred_vector_width_half_selected()
       && a.host_unified_memory_selected() == b.host_unified_memory_selected()
       && a.native_vector_width_char_selected() == b.native_vector_width_char_selected()
       && a.native_vector_width_short_selected() == b.native_vector_width_short_selected()
       && a.native_vector_width_int_selected() == b.native_vector_width_int_selected()
       && a.native_vector_width_long_selected() == b.native_vector_width_long_selected()
       && a.native_vector_width_float_selected() == b.native_vector_width_float_selected()
       && a.native_vector_width_double_selected() == b.native_vector_width_double_selected()
       && a.native_vector_width_half_selected() == b.native_vector_width_half_selected()
       && a.opencl_c_version_selected() == b.opencl_c_version_selected()
       && a.linker_available_selected() == b.linker_available_selected()
       && a.built_in_kernels_selected() == b.built_in_kernels_selected()
       && a.image_max_buffer_size_selected() == b.image_max_buffer_size_selected()
       && a.image_max_array_size_selected() == b.image_max_array_size_selected()
       && a.parent_device_id_selected() == b.parent_device_id_selected()
       && a.partition_max_sub_devices_selected() == b.partition_max_sub_devices_selected()
       && a.partition_properties_selected() == b.partition_properties_selected()
       && a.partition_affinity_domain_selected() == b.partition_affinity_domain_selected()
       && a.partition_type_selected() == b.partition_type_selected()
       && a.reference_count_selected() == b.reference_count_selected()
       && a.preferred_interop_user_sync_selected() == b.preferred_interop_user_sync_selected()
       && a.printf_buffer_size_selected() == b.printf_buffer_size_selected()
       && a.image_pitch_alignment_selected() == b.image_pitch_alignment_selected()
       && a.image_base_address_alignment_selected() == b.image_base_address_alignment_selected());
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
