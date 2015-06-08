// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_info_fixtures.hpp

/** // doc: clxx/device_info_fixtures.hpp {{{
 * \file clxx/device_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_INFO_FIXTURES_HPP_INCLUDED
#define CLXX_DEVICE_INFO_FIXTURES_HPP_INCLUDED

#include <clxx/device_info.hpp>

namespace clxx {

struct device_info_fixtures
  {
    static device_info _1()
    {
      size_t max_work_item_sizes[3] = { 1, 2, 3 };
      device_partition_property_t partition_properties[2] = {
        device_partition_property_t::by_counts,
        device_partition_property_t::by_affinity_domain
      };
      device_partition_property_t partition_type[2] = {
        device_partition_property_t::by_counts,
        device_partition_property_t::by_affinity_domain
      };

      return device_info()
         .set_id(0x1234ul)
         .set_type(device_type_t::cpu)
         .set_vendor_id(0x1234u)
         .set_max_compute_units(0x1234u)
         .set_max_work_item_dimensions(0x1234u)
         .set_max_work_group_size(0x1234ul)
         .set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes,max_work_item_sizes+3))
         .set_preferred_vector_width_char(0x1234u)
         .set_preferred_vector_width_short(0x1234u)
         .set_preferred_vector_width_int(0x1234u)
         .set_preferred_vector_width_long(0x1234u)
         .set_preferred_vector_width_float(0x1234u)
         .set_preferred_vector_width_double(0x1234u)
         .set_max_clock_frequency(0x1234u)
         .set_address_bits(0x1234u)
         .set_max_read_image_args(0x1234u)
         .set_max_write_image_args(0x1234u)
         .set_max_mem_alloc_size(0x1234ul)
         .set_image2d_max_width(0x1234ul)
         .set_image2d_max_height(0x1234ul)
         .set_image3d_max_width(0x1234ul)
         .set_image3d_max_height(0x1234ul)
         .set_image3d_max_depth(0x1234ul)
         .set_image_support(0)
         .set_max_parameter_size(0x1234ul)
         .set_max_samplers(0x1234u)
         .set_mem_base_addr_align(0x1234u)
         .set_min_data_type_align_size(0x1234u)
         .set_single_fp_config(device_fp_config_t::denorm)
         .set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache)
         .set_global_mem_cacheline_size(0x1234u)
         .set_global_mem_cache_size(0x1234ul)
         .set_global_mem_size(0x1234ul)
         .set_max_constant_buffer_size(0x1234u)
         .set_max_constant_args(0x1234u)
         .set_local_mem_type(device_local_mem_type_t::local)
         .set_local_mem_size(0x1234ul)
         .set_error_correction_support(0)
         .set_profiling_timer_resolution(0x1234ul)
         .set_endian_little(0)
         .set_available(0)
         .set_compiler_available(0)
         .set_execution_capabilities(device_exec_capabilities_t::kernel)
         .set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable)
         .set_name("_name")
         .set_vendor("_vendor")
         .set_driver_version("_driver_version")
         .set_profile("_profile")
         .set_version("_version")
         .set_extensions("_extensions")
         .set_platform_id(0x1234ul)
         .set_double_fp_config(device_fp_config_t::denorm)
         .set_preferred_vector_width_half(0x1234u)
         .set_host_unified_memory(0)
         .set_native_vector_width_char(0x1234u)
         .set_native_vector_width_short(0x1234u)
         .set_native_vector_width_int(0x1234u)
         .set_native_vector_width_long(0x1234u)
         .set_native_vector_width_float(0x1234u)
         .set_native_vector_width_double(0x1234u)
         .set_native_vector_width_half(0x1234u)
         .set_opencl_c_version("_opencl_c_version")
         .set_linker_available(0)
         .set_built_in_kernels("_built_in_kernels")
         .set_image_max_buffer_size(0x1234ul)
         .set_image_max_array_size(0x1234ul)
         .set_parent_device_id(0x1234ul)
         .set_partition_max_sub_devices(0x1234u)
         .set_partition_properties(std::vector<device_partition_property_t>(partition_properties,partition_properties+2))
         .set_partition_affinity_domain(device_affinity_domain_t::numa)
         .set_partition_type(std::vector<device_partition_property_t>(partition_type,partition_type+2))
         .set_reference_count(0x1234u)
         .set_preferred_interop_user_sync(0)
         .set_printf_buffer_size(0x1234ul)
         .set_image_pitch_alignment(0x1234u)
         .set_image_base_address_alignment(0x1234u);
    }
    static device_info _2()
    {
      size_t max_work_item_sizes[3] = { 3, 2, 1 };
      device_partition_property_t partition_properties[2] = {
        device_partition_property_t::by_affinity_domain,
        device_partition_property_t::by_counts
      };
      device_partition_property_t partition_type[2] = {
        device_partition_property_t::by_affinity_domain,
        device_partition_property_t::by_counts
      };

      return device_info()
          .set_id(0x4321ul)
          .set_type(device_type_t::gpu)
          .set_vendor_id(0x4321u)
          .set_max_compute_units(0x4321u)
          .set_max_work_item_dimensions(0x4321u)
          .set_max_work_group_size(0x4321ul)
          .set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes,max_work_item_sizes+3))
          .set_preferred_vector_width_char(0x4321u)
          .set_preferred_vector_width_short(0x4321u)
          .set_preferred_vector_width_int(0x4321u)
          .set_preferred_vector_width_long(0x4321u)
          .set_preferred_vector_width_float(0x4321u)
          .set_preferred_vector_width_double(0x4321u)
          .set_max_clock_frequency(0x4321u)
          .set_address_bits(0x4321u)
          .set_max_read_image_args(0x4321u)
          .set_max_write_image_args(0x4321u)
          .set_max_mem_alloc_size(0x4321ul)
          .set_image2d_max_width(0x4321ul)
          .set_image2d_max_height(0x4321ul)
          .set_image3d_max_width(0x4321ul)
          .set_image3d_max_height(0x4321ul)
          .set_image3d_max_depth(0x4321ul)
          .set_image_support(1)
          .set_max_parameter_size(0x4321ul)
          .set_max_samplers(0x4321u)
          .set_mem_base_addr_align(0x4321u)
          .set_min_data_type_align_size(0x4321u)
          .set_single_fp_config(device_fp_config_t::inf_nan)
          .set_global_mem_cache_type(device_mem_cache_type_t::read_write_cache)
          .set_global_mem_cacheline_size(0x4321u)
          .set_global_mem_cache_size(0x4321ul)
          .set_global_mem_size(0x4321ul)
          .set_max_constant_buffer_size(0x4321u)
          .set_max_constant_args(0x4321u)
          .set_local_mem_type(device_local_mem_type_t::global)
          .set_local_mem_size(0x4321ul)
          .set_error_correction_support(1)
          .set_profiling_timer_resolution(0x4321ul)
          .set_endian_little(1)
          .set_available(1)
          .set_compiler_available(1)
          .set_execution_capabilities(device_exec_capabilities_t::native_kernel)
          .set_queue_properties(command_queue_properties_t::profiling_enable)
          .set_name("x_namex")
          .set_vendor("x_vendorx")
          .set_driver_version("x_driver_versionx")
          .set_profile("x_profilex")
          .set_version("x_versionx")
          .set_extensions("x_extensionsx")
          .set_platform_id(0x4321ul)
          .set_double_fp_config(device_fp_config_t::inf_nan)
          .set_preferred_vector_width_half(0x4321u)
          .set_host_unified_memory(1)
          .set_native_vector_width_char(0x4321u)
          .set_native_vector_width_short(0x4321u)
          .set_native_vector_width_int(0x4321u)
          .set_native_vector_width_long(0x4321u)
          .set_native_vector_width_float(0x4321u)
          .set_native_vector_width_double(0x4321u)
          .set_native_vector_width_half(0x4321u)
          .set_opencl_c_version("x_opencl_c_versionx")
          .set_linker_available(1)
          .set_built_in_kernels("x_built_in_kernelsx")
          .set_image_max_buffer_size(0x4321ul)
          .set_image_max_array_size(0x4321ul)
          .set_parent_device_id(0x4321ul)
          .set_partition_max_sub_devices(0x4321u)
          .set_partition_properties(std::vector<device_partition_property_t>(partition_properties,partition_properties+2))
          .set_partition_affinity_domain(device_affinity_domain_t::l2_cache)
          .set_partition_type(std::vector<device_partition_property_t>(partition_type,partition_type+2))
          .set_reference_count(0x4321u)
          .set_preferred_interop_user_sync(1)
          .set_printf_buffer_size(0x4321ul)
          .set_image_pitch_alignment(0x4321u)
          .set_image_base_address_alignment(0x4321u);
    }
  };

} // end namespace clxx

#endif /* CLXX_DEVICE_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
