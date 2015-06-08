// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_query.t.h

/** // doc: clxx/device_query.t.h {{{
 * \file clxx/device_query.t.h
 * \brief Unit tests for clxx::device_query
 */ // }}}
#ifndef CLXX_DEVICE_QUERY_T_H_INCLUDED
#define CLXX_DEVICE_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/device_query.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace clxx { class device_query_test_suite; }

/** // doc: class clxx::device_query_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::device_query_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \todo Write documentation
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(device_query().id_selected());
    TS_ASSERT(device_query().type_selected());
    TS_ASSERT(device_query().vendor_id_selected());
    TS_ASSERT(device_query().max_compute_units_selected());
    TS_ASSERT(device_query().max_work_item_dimensions_selected());
    TS_ASSERT(device_query().max_work_group_size_selected());
    TS_ASSERT(device_query().max_work_item_sizes_selected());
    TS_ASSERT(device_query().preferred_vector_width_char_selected());
    TS_ASSERT(device_query().preferred_vector_width_short_selected());
    TS_ASSERT(device_query().preferred_vector_width_int_selected());
    TS_ASSERT(device_query().preferred_vector_width_long_selected());
    TS_ASSERT(device_query().preferred_vector_width_float_selected());
    TS_ASSERT(device_query().preferred_vector_width_double_selected());
    TS_ASSERT(device_query().max_clock_frequency_selected());
    TS_ASSERT(device_query().address_bits_selected());
    TS_ASSERT(device_query().max_read_image_args_selected());
    TS_ASSERT(device_query().max_write_image_args_selected());
    TS_ASSERT(device_query().max_mem_alloc_size_selected());
    TS_ASSERT(device_query().image2d_max_width_selected());
    TS_ASSERT(device_query().image2d_max_height_selected());
    TS_ASSERT(device_query().image3d_max_width_selected());
    TS_ASSERT(device_query().image3d_max_height_selected());
    TS_ASSERT(device_query().image3d_max_depth_selected());
    TS_ASSERT(device_query().image_support_selected());
    TS_ASSERT(device_query().max_parameter_size_selected());
    TS_ASSERT(device_query().max_samplers_selected());
    TS_ASSERT(device_query().mem_base_addr_align_selected());
    TS_ASSERT(device_query().min_data_type_align_size_selected());
    TS_ASSERT(device_query().single_fp_config_selected());
    TS_ASSERT(device_query().global_mem_cache_type_selected());
    TS_ASSERT(device_query().global_mem_cacheline_size_selected());
    TS_ASSERT(device_query().global_mem_cache_size_selected());
    TS_ASSERT(device_query().global_mem_size_selected());
    TS_ASSERT(device_query().max_constant_buffer_size_selected());
    TS_ASSERT(device_query().max_constant_args_selected());
    TS_ASSERT(device_query().local_mem_type_selected());
    TS_ASSERT(device_query().local_mem_size_selected());
    TS_ASSERT(device_query().error_correction_support_selected());
    TS_ASSERT(device_query().profiling_timer_resolution_selected());
    TS_ASSERT(device_query().endian_little_selected());
    TS_ASSERT(device_query().available_selected());
    TS_ASSERT(device_query().compiler_available_selected());
    TS_ASSERT(device_query().execution_capabilities_selected());
    TS_ASSERT(device_query().queue_properties_selected());
    TS_ASSERT(device_query().name_selected());
    TS_ASSERT(device_query().vendor_selected());
    TS_ASSERT(device_query().driver_version_selected());
    TS_ASSERT(device_query().profile_selected());
    TS_ASSERT(device_query().version_selected());
    TS_ASSERT(device_query().extensions_selected());
    TS_ASSERT(device_query().platform_id_selected());
    TS_ASSERT(device_query().double_fp_config_selected());
    TS_ASSERT(device_query().preferred_vector_width_half_selected());
    TS_ASSERT(device_query().host_unified_memory_selected());
    TS_ASSERT(device_query().native_vector_width_char_selected());
    TS_ASSERT(device_query().native_vector_width_short_selected());
    TS_ASSERT(device_query().native_vector_width_int_selected());
    TS_ASSERT(device_query().native_vector_width_long_selected());
    TS_ASSERT(device_query().native_vector_width_float_selected());
    TS_ASSERT(device_query().native_vector_width_double_selected());
    TS_ASSERT(device_query().native_vector_width_half_selected());
    TS_ASSERT(device_query().opencl_c_version_selected());
    TS_ASSERT(device_query().linker_available_selected());
    TS_ASSERT(device_query().built_in_kernels_selected());
    TS_ASSERT(device_query().image_max_buffer_size_selected());
    TS_ASSERT(device_query().image_max_array_size_selected());
    TS_ASSERT(device_query().parent_device_id_selected());
    TS_ASSERT(device_query().partition_max_sub_devices_selected());
    TS_ASSERT(device_query().partition_properties_selected());
    TS_ASSERT(device_query().partition_affinity_domain_selected());
    TS_ASSERT(device_query().partition_type_selected());
    TS_ASSERT(device_query().reference_count_selected());
    TS_ASSERT(device_query().preferred_interop_user_sync_selected());
    TS_ASSERT(device_query().printf_buffer_size_selected());
    TS_ASSERT(device_query().image_pitch_alignment_selected());
    TS_ASSERT(device_query().image_base_address_alignment_selected());
  }
  /** // doc: test_ctor_true() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_true( )
  {
    TS_ASSERT(device_query(true).id_selected());
    TS_ASSERT(device_query(true).type_selected());
    TS_ASSERT(device_query(true).vendor_id_selected());
    TS_ASSERT(device_query(true).max_compute_units_selected());
    TS_ASSERT(device_query(true).max_work_item_dimensions_selected());
    TS_ASSERT(device_query(true).max_work_group_size_selected());
    TS_ASSERT(device_query(true).max_work_item_sizes_selected());
    TS_ASSERT(device_query(true).preferred_vector_width_char_selected());
    TS_ASSERT(device_query(true).preferred_vector_width_short_selected());
    TS_ASSERT(device_query(true).preferred_vector_width_int_selected());
    TS_ASSERT(device_query(true).preferred_vector_width_long_selected());
    TS_ASSERT(device_query(true).preferred_vector_width_float_selected());
    TS_ASSERT(device_query(true).preferred_vector_width_double_selected());
    TS_ASSERT(device_query(true).max_clock_frequency_selected());
    TS_ASSERT(device_query(true).address_bits_selected());
    TS_ASSERT(device_query(true).max_read_image_args_selected());
    TS_ASSERT(device_query(true).max_write_image_args_selected());
    TS_ASSERT(device_query(true).max_mem_alloc_size_selected());
    TS_ASSERT(device_query(true).image2d_max_width_selected());
    TS_ASSERT(device_query(true).image2d_max_height_selected());
    TS_ASSERT(device_query(true).image3d_max_width_selected());
    TS_ASSERT(device_query(true).image3d_max_height_selected());
    TS_ASSERT(device_query(true).image3d_max_depth_selected());
    TS_ASSERT(device_query(true).image_support_selected());
    TS_ASSERT(device_query(true).max_parameter_size_selected());
    TS_ASSERT(device_query(true).max_samplers_selected());
    TS_ASSERT(device_query(true).mem_base_addr_align_selected());
    TS_ASSERT(device_query(true).min_data_type_align_size_selected());
    TS_ASSERT(device_query(true).single_fp_config_selected());
    TS_ASSERT(device_query(true).global_mem_cache_type_selected());
    TS_ASSERT(device_query(true).global_mem_cacheline_size_selected());
    TS_ASSERT(device_query(true).global_mem_cache_size_selected());
    TS_ASSERT(device_query(true).global_mem_size_selected());
    TS_ASSERT(device_query(true).max_constant_buffer_size_selected());
    TS_ASSERT(device_query(true).max_constant_args_selected());
    TS_ASSERT(device_query(true).local_mem_type_selected());
    TS_ASSERT(device_query(true).local_mem_size_selected());
    TS_ASSERT(device_query(true).error_correction_support_selected());
    TS_ASSERT(device_query(true).profiling_timer_resolution_selected());
    TS_ASSERT(device_query(true).endian_little_selected());
    TS_ASSERT(device_query(true).available_selected());
    TS_ASSERT(device_query(true).compiler_available_selected());
    TS_ASSERT(device_query(true).execution_capabilities_selected());
    TS_ASSERT(device_query(true).queue_properties_selected());
    TS_ASSERT(device_query(true).name_selected());
    TS_ASSERT(device_query(true).vendor_selected());
    TS_ASSERT(device_query(true).driver_version_selected());
    TS_ASSERT(device_query(true).profile_selected());
    TS_ASSERT(device_query(true).version_selected());
    TS_ASSERT(device_query(true).extensions_selected());
    TS_ASSERT(device_query(true).platform_id_selected());
    TS_ASSERT(device_query(true).double_fp_config_selected());
    TS_ASSERT(device_query(true).preferred_vector_width_half_selected());
    TS_ASSERT(device_query(true).host_unified_memory_selected());
    TS_ASSERT(device_query(true).native_vector_width_char_selected());
    TS_ASSERT(device_query(true).native_vector_width_short_selected());
    TS_ASSERT(device_query(true).native_vector_width_int_selected());
    TS_ASSERT(device_query(true).native_vector_width_long_selected());
    TS_ASSERT(device_query(true).native_vector_width_float_selected());
    TS_ASSERT(device_query(true).native_vector_width_double_selected());
    TS_ASSERT(device_query(true).native_vector_width_half_selected());
    TS_ASSERT(device_query(true).opencl_c_version_selected());
    TS_ASSERT(device_query(true).linker_available_selected());
    TS_ASSERT(device_query(true).built_in_kernels_selected());
    TS_ASSERT(device_query(true).image_max_buffer_size_selected());
    TS_ASSERT(device_query(true).image_max_array_size_selected());
    TS_ASSERT(device_query(true).parent_device_id_selected());
    TS_ASSERT(device_query(true).partition_max_sub_devices_selected());
    TS_ASSERT(device_query(true).partition_properties_selected());
    TS_ASSERT(device_query(true).partition_affinity_domain_selected());
    TS_ASSERT(device_query(true).partition_type_selected());
    TS_ASSERT(device_query(true).reference_count_selected());
    TS_ASSERT(device_query(true).preferred_interop_user_sync_selected());
    TS_ASSERT(device_query(true).printf_buffer_size_selected());
    TS_ASSERT(device_query(true).image_pitch_alignment_selected());
    TS_ASSERT(device_query(true).image_base_address_alignment_selected());
  }
  /** // doc: test_ctor_false() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_false( )
  {
    TS_ASSERT(!device_query(false).id_selected());
    TS_ASSERT(!device_query(false).type_selected());
    TS_ASSERT(!device_query(false).vendor_id_selected());
    TS_ASSERT(!device_query(false).max_compute_units_selected());
    TS_ASSERT(!device_query(false).max_work_item_dimensions_selected());
    TS_ASSERT(!device_query(false).max_work_group_size_selected());
    TS_ASSERT(!device_query(false).max_work_item_sizes_selected());
    TS_ASSERT(!device_query(false).preferred_vector_width_char_selected());
    TS_ASSERT(!device_query(false).preferred_vector_width_short_selected());
    TS_ASSERT(!device_query(false).preferred_vector_width_int_selected());
    TS_ASSERT(!device_query(false).preferred_vector_width_long_selected());
    TS_ASSERT(!device_query(false).preferred_vector_width_float_selected());
    TS_ASSERT(!device_query(false).preferred_vector_width_double_selected());
    TS_ASSERT(!device_query(false).max_clock_frequency_selected());
    TS_ASSERT(!device_query(false).address_bits_selected());
    TS_ASSERT(!device_query(false).max_read_image_args_selected());
    TS_ASSERT(!device_query(false).max_write_image_args_selected());
    TS_ASSERT(!device_query(false).max_mem_alloc_size_selected());
    TS_ASSERT(!device_query(false).image2d_max_width_selected());
    TS_ASSERT(!device_query(false).image2d_max_height_selected());
    TS_ASSERT(!device_query(false).image3d_max_width_selected());
    TS_ASSERT(!device_query(false).image3d_max_height_selected());
    TS_ASSERT(!device_query(false).image3d_max_depth_selected());
    TS_ASSERT(!device_query(false).image_support_selected());
    TS_ASSERT(!device_query(false).max_parameter_size_selected());
    TS_ASSERT(!device_query(false).max_samplers_selected());
    TS_ASSERT(!device_query(false).mem_base_addr_align_selected());
    TS_ASSERT(!device_query(false).min_data_type_align_size_selected());
    TS_ASSERT(!device_query(false).single_fp_config_selected());
    TS_ASSERT(!device_query(false).global_mem_cache_type_selected());
    TS_ASSERT(!device_query(false).global_mem_cacheline_size_selected());
    TS_ASSERT(!device_query(false).global_mem_cache_size_selected());
    TS_ASSERT(!device_query(false).global_mem_size_selected());
    TS_ASSERT(!device_query(false).max_constant_buffer_size_selected());
    TS_ASSERT(!device_query(false).max_constant_args_selected());
    TS_ASSERT(!device_query(false).local_mem_type_selected());
    TS_ASSERT(!device_query(false).local_mem_size_selected());
    TS_ASSERT(!device_query(false).error_correction_support_selected());
    TS_ASSERT(!device_query(false).profiling_timer_resolution_selected());
    TS_ASSERT(!device_query(false).endian_little_selected());
    TS_ASSERT(!device_query(false).available_selected());
    TS_ASSERT(!device_query(false).compiler_available_selected());
    TS_ASSERT(!device_query(false).execution_capabilities_selected());
    TS_ASSERT(!device_query(false).queue_properties_selected());
    TS_ASSERT(!device_query(false).name_selected());
    TS_ASSERT(!device_query(false).vendor_selected());
    TS_ASSERT(!device_query(false).driver_version_selected());
    TS_ASSERT(!device_query(false).profile_selected());
    TS_ASSERT(!device_query(false).version_selected());
    TS_ASSERT(!device_query(false).extensions_selected());
    TS_ASSERT(!device_query(false).platform_id_selected());
    TS_ASSERT(!device_query(false).double_fp_config_selected());
    TS_ASSERT(!device_query(false).preferred_vector_width_half_selected());
    TS_ASSERT(!device_query(false).host_unified_memory_selected());
    TS_ASSERT(!device_query(false).native_vector_width_char_selected());
    TS_ASSERT(!device_query(false).native_vector_width_short_selected());
    TS_ASSERT(!device_query(false).native_vector_width_int_selected());
    TS_ASSERT(!device_query(false).native_vector_width_long_selected());
    TS_ASSERT(!device_query(false).native_vector_width_float_selected());
    TS_ASSERT(!device_query(false).native_vector_width_double_selected());
    TS_ASSERT(!device_query(false).native_vector_width_half_selected());
    TS_ASSERT(!device_query(false).opencl_c_version_selected());
    TS_ASSERT(!device_query(false).linker_available_selected());
    TS_ASSERT(!device_query(false).built_in_kernels_selected());
    TS_ASSERT(!device_query(false).image_max_buffer_size_selected());
    TS_ASSERT(!device_query(false).image_max_array_size_selected());
    TS_ASSERT(!device_query(false).parent_device_id_selected());
    TS_ASSERT(!device_query(false).partition_max_sub_devices_selected());
    TS_ASSERT(!device_query(false).partition_properties_selected());
    TS_ASSERT(!device_query(false).partition_affinity_domain_selected());
    TS_ASSERT(!device_query(false).partition_type_selected());
    TS_ASSERT(!device_query(false).reference_count_selected());
    TS_ASSERT(!device_query(false).preferred_interop_user_sync_selected());
    TS_ASSERT(!device_query(false).printf_buffer_size_selected());
    TS_ASSERT(!device_query(false).image_pitch_alignment_selected());
    TS_ASSERT(!device_query(false).image_base_address_alignment_selected());
  }
  /** // doc: test_set_get_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get_1( )
  {
    TS_ASSERT(!device_query(true).select_id(false).id_selected());
    TS_ASSERT(!device_query(true).select_type(false).type_selected());
    TS_ASSERT(!device_query(true).select_vendor_id(false).vendor_id_selected());
    TS_ASSERT(!device_query(true).select_max_compute_units(false).max_compute_units_selected());
    TS_ASSERT(!device_query(true).select_max_work_item_dimensions(false).max_work_item_dimensions_selected());
    TS_ASSERT(!device_query(true).select_max_work_group_size(false).max_work_group_size_selected());
    TS_ASSERT(!device_query(true).select_max_work_item_sizes(false).max_work_item_sizes_selected());
    TS_ASSERT(!device_query(true).select_preferred_vector_width_char(false).preferred_vector_width_char_selected());
    TS_ASSERT(!device_query(true).select_preferred_vector_width_short(false).preferred_vector_width_short_selected());
    TS_ASSERT(!device_query(true).select_preferred_vector_width_int(false).preferred_vector_width_int_selected());
    TS_ASSERT(!device_query(true).select_preferred_vector_width_long(false).preferred_vector_width_long_selected());
    TS_ASSERT(!device_query(true).select_preferred_vector_width_float(false).preferred_vector_width_float_selected());
    TS_ASSERT(!device_query(true).select_preferred_vector_width_double(false).preferred_vector_width_double_selected());
    TS_ASSERT(!device_query(true).select_max_clock_frequency(false).max_clock_frequency_selected());
    TS_ASSERT(!device_query(true).select_address_bits(false).address_bits_selected());
    TS_ASSERT(!device_query(true).select_max_read_image_args(false).max_read_image_args_selected());
    TS_ASSERT(!device_query(true).select_max_write_image_args(false).max_write_image_args_selected());
    TS_ASSERT(!device_query(true).select_max_mem_alloc_size(false).max_mem_alloc_size_selected());
    TS_ASSERT(!device_query(true).select_image2d_max_width(false).image2d_max_width_selected());
    TS_ASSERT(!device_query(true).select_image2d_max_height(false).image2d_max_height_selected());
    TS_ASSERT(!device_query(true).select_image3d_max_width(false).image3d_max_width_selected());
    TS_ASSERT(!device_query(true).select_image3d_max_height(false).image3d_max_height_selected());
    TS_ASSERT(!device_query(true).select_image3d_max_depth(false).image3d_max_depth_selected());
    TS_ASSERT(!device_query(true).select_image_support(false).image_support_selected());
    TS_ASSERT(!device_query(true).select_max_parameter_size(false).max_parameter_size_selected());
    TS_ASSERT(!device_query(true).select_max_samplers(false).max_samplers_selected());
    TS_ASSERT(!device_query(true).select_mem_base_addr_align(false).mem_base_addr_align_selected());
    TS_ASSERT(!device_query(true).select_min_data_type_align_size(false).min_data_type_align_size_selected());
    TS_ASSERT(!device_query(true).select_single_fp_config(false).single_fp_config_selected());
    TS_ASSERT(!device_query(true).select_global_mem_cache_type(false).global_mem_cache_type_selected());
    TS_ASSERT(!device_query(true).select_global_mem_cacheline_size(false).global_mem_cacheline_size_selected());
    TS_ASSERT(!device_query(true).select_global_mem_cache_size(false).global_mem_cache_size_selected());
    TS_ASSERT(!device_query(true).select_global_mem_size(false).global_mem_size_selected());
    TS_ASSERT(!device_query(true).select_max_constant_buffer_size(false).max_constant_buffer_size_selected());
    TS_ASSERT(!device_query(true).select_max_constant_args(false).max_constant_args_selected());
    TS_ASSERT(!device_query(true).select_local_mem_type(false).local_mem_type_selected());
    TS_ASSERT(!device_query(true).select_local_mem_size(false).local_mem_size_selected());
    TS_ASSERT(!device_query(true).select_error_correction_support(false).error_correction_support_selected());
    TS_ASSERT(!device_query(true).select_profiling_timer_resolution(false).profiling_timer_resolution_selected());
    TS_ASSERT(!device_query(true).select_endian_little(false).endian_little_selected());
    TS_ASSERT(!device_query(true).select_available(false).available_selected());
    TS_ASSERT(!device_query(true).select_compiler_available(false).compiler_available_selected());
    TS_ASSERT(!device_query(true).select_execution_capabilities(false).execution_capabilities_selected());
    TS_ASSERT(!device_query(true).select_queue_properties(false).queue_properties_selected());
    TS_ASSERT(!device_query(true).select_name(false).name_selected());
    TS_ASSERT(!device_query(true).select_vendor(false).vendor_selected());
    TS_ASSERT(!device_query(true).select_driver_version(false).driver_version_selected());
    TS_ASSERT(!device_query(true).select_profile(false).profile_selected());
    TS_ASSERT(!device_query(true).select_version(false).version_selected());
    TS_ASSERT(!device_query(true).select_extensions(false).extensions_selected());
    TS_ASSERT(!device_query(true).select_platform_id(false).platform_id_selected());
    TS_ASSERT(!device_query(true).select_double_fp_config(false).double_fp_config_selected());
    TS_ASSERT(!device_query(true).select_preferred_vector_width_half(false).preferred_vector_width_half_selected());
    TS_ASSERT(!device_query(true).select_host_unified_memory(false).host_unified_memory_selected());
    TS_ASSERT(!device_query(true).select_native_vector_width_char(false).native_vector_width_char_selected());
    TS_ASSERT(!device_query(true).select_native_vector_width_short(false).native_vector_width_short_selected());
    TS_ASSERT(!device_query(true).select_native_vector_width_int(false).native_vector_width_int_selected());
    TS_ASSERT(!device_query(true).select_native_vector_width_long(false).native_vector_width_long_selected());
    TS_ASSERT(!device_query(true).select_native_vector_width_float(false).native_vector_width_float_selected());
    TS_ASSERT(!device_query(true).select_native_vector_width_double(false).native_vector_width_double_selected());
    TS_ASSERT(!device_query(true).select_native_vector_width_half(false).native_vector_width_half_selected());
    TS_ASSERT(!device_query(true).select_opencl_c_version(false).opencl_c_version_selected());
    TS_ASSERT(!device_query(true).select_linker_available(false).linker_available_selected());
    TS_ASSERT(!device_query(true).select_built_in_kernels(false).built_in_kernels_selected());
    TS_ASSERT(!device_query(true).select_image_max_buffer_size(false).image_max_buffer_size_selected());
    TS_ASSERT(!device_query(true).select_image_max_array_size(false).image_max_array_size_selected());
    TS_ASSERT(!device_query(true).select_parent_device_id(false).parent_device_id_selected());
    TS_ASSERT(!device_query(true).select_partition_max_sub_devices(false).partition_max_sub_devices_selected());
    TS_ASSERT(!device_query(true).select_partition_properties(false).partition_properties_selected());
    TS_ASSERT(!device_query(true).select_partition_affinity_domain(false).partition_affinity_domain_selected());
    TS_ASSERT(!device_query(true).select_partition_type(false).partition_type_selected());
    TS_ASSERT(!device_query(true).select_reference_count(false).reference_count_selected());
    TS_ASSERT(!device_query(true).select_preferred_interop_user_sync(false).preferred_interop_user_sync_selected());
    TS_ASSERT(!device_query(true).select_printf_buffer_size(false).printf_buffer_size_selected());
    TS_ASSERT(!device_query(true).select_image_pitch_alignment(false).image_pitch_alignment_selected());
    TS_ASSERT(!device_query(true).select_image_base_address_alignment(false).image_base_address_alignment_selected());
  }
  /** // doc: test_set_get_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get_2( )
  {
    TS_ASSERT(device_query(false).select_id(true).id_selected());
    TS_ASSERT(device_query(false).select_type(true).type_selected());
    TS_ASSERT(device_query(false).select_vendor_id(true).vendor_id_selected());
    TS_ASSERT(device_query(false).select_max_compute_units(true).max_compute_units_selected());
    TS_ASSERT(device_query(false).select_max_work_item_dimensions(true).max_work_item_dimensions_selected());
    TS_ASSERT(device_query(false).select_max_work_group_size(true).max_work_group_size_selected());
    TS_ASSERT(device_query(false).select_max_work_item_sizes(true).max_work_item_sizes_selected());
    TS_ASSERT(device_query(false).select_preferred_vector_width_char(true).preferred_vector_width_char_selected());
    TS_ASSERT(device_query(false).select_preferred_vector_width_short(true).preferred_vector_width_short_selected());
    TS_ASSERT(device_query(false).select_preferred_vector_width_int(true).preferred_vector_width_int_selected());
    TS_ASSERT(device_query(false).select_preferred_vector_width_long(true).preferred_vector_width_long_selected());
    TS_ASSERT(device_query(false).select_preferred_vector_width_float(true).preferred_vector_width_float_selected());
    TS_ASSERT(device_query(false).select_preferred_vector_width_double(true).preferred_vector_width_double_selected());
    TS_ASSERT(device_query(false).select_max_clock_frequency(true).max_clock_frequency_selected());
    TS_ASSERT(device_query(false).select_address_bits(true).address_bits_selected());
    TS_ASSERT(device_query(false).select_max_read_image_args(true).max_read_image_args_selected());
    TS_ASSERT(device_query(false).select_max_write_image_args(true).max_write_image_args_selected());
    TS_ASSERT(device_query(false).select_max_mem_alloc_size(true).max_mem_alloc_size_selected());
    TS_ASSERT(device_query(false).select_image2d_max_width(true).image2d_max_width_selected());
    TS_ASSERT(device_query(false).select_image2d_max_height(true).image2d_max_height_selected());
    TS_ASSERT(device_query(false).select_image3d_max_width(true).image3d_max_width_selected());
    TS_ASSERT(device_query(false).select_image3d_max_height(true).image3d_max_height_selected());
    TS_ASSERT(device_query(false).select_image3d_max_depth(true).image3d_max_depth_selected());
    TS_ASSERT(device_query(false).select_image_support(true).image_support_selected());
    TS_ASSERT(device_query(false).select_max_parameter_size(true).max_parameter_size_selected());
    TS_ASSERT(device_query(false).select_max_samplers(true).max_samplers_selected());
    TS_ASSERT(device_query(false).select_mem_base_addr_align(true).mem_base_addr_align_selected());
    TS_ASSERT(device_query(false).select_min_data_type_align_size(true).min_data_type_align_size_selected());
    TS_ASSERT(device_query(false).select_single_fp_config(true).single_fp_config_selected());
    TS_ASSERT(device_query(false).select_global_mem_cache_type(true).global_mem_cache_type_selected());
    TS_ASSERT(device_query(false).select_global_mem_cacheline_size(true).global_mem_cacheline_size_selected());
    TS_ASSERT(device_query(false).select_global_mem_cache_size(true).global_mem_cache_size_selected());
    TS_ASSERT(device_query(false).select_global_mem_size(true).global_mem_size_selected());
    TS_ASSERT(device_query(false).select_max_constant_buffer_size(true).max_constant_buffer_size_selected());
    TS_ASSERT(device_query(false).select_max_constant_args(true).max_constant_args_selected());
    TS_ASSERT(device_query(false).select_local_mem_type(true).local_mem_type_selected());
    TS_ASSERT(device_query(false).select_local_mem_size(true).local_mem_size_selected());
    TS_ASSERT(device_query(false).select_error_correction_support(true).error_correction_support_selected());
    TS_ASSERT(device_query(false).select_profiling_timer_resolution(true).profiling_timer_resolution_selected());
    TS_ASSERT(device_query(false).select_endian_little(true).endian_little_selected());
    TS_ASSERT(device_query(false).select_available(true).available_selected());
    TS_ASSERT(device_query(false).select_compiler_available(true).compiler_available_selected());
    TS_ASSERT(device_query(false).select_execution_capabilities(true).execution_capabilities_selected());
    TS_ASSERT(device_query(false).select_queue_properties(true).queue_properties_selected());
    TS_ASSERT(device_query(false).select_name(true).name_selected());
    TS_ASSERT(device_query(false).select_vendor(true).vendor_selected());
    TS_ASSERT(device_query(false).select_driver_version(true).driver_version_selected());
    TS_ASSERT(device_query(false).select_profile(true).profile_selected());
    TS_ASSERT(device_query(false).select_version(true).version_selected());
    TS_ASSERT(device_query(false).select_extensions(true).extensions_selected());
    TS_ASSERT(device_query(false).select_platform_id(true).platform_id_selected());
    TS_ASSERT(device_query(false).select_double_fp_config(true).double_fp_config_selected());
    TS_ASSERT(device_query(false).select_preferred_vector_width_half(true).preferred_vector_width_half_selected());
    TS_ASSERT(device_query(false).select_host_unified_memory(true).host_unified_memory_selected());
    TS_ASSERT(device_query(false).select_native_vector_width_char(true).native_vector_width_char_selected());
    TS_ASSERT(device_query(false).select_native_vector_width_short(true).native_vector_width_short_selected());
    TS_ASSERT(device_query(false).select_native_vector_width_int(true).native_vector_width_int_selected());
    TS_ASSERT(device_query(false).select_native_vector_width_long(true).native_vector_width_long_selected());
    TS_ASSERT(device_query(false).select_native_vector_width_float(true).native_vector_width_float_selected());
    TS_ASSERT(device_query(false).select_native_vector_width_double(true).native_vector_width_double_selected());
    TS_ASSERT(device_query(false).select_native_vector_width_half(true).native_vector_width_half_selected());
    TS_ASSERT(device_query(false).select_opencl_c_version(true).opencl_c_version_selected());
    TS_ASSERT(device_query(false).select_linker_available(true).linker_available_selected());
    TS_ASSERT(device_query(false).select_built_in_kernels(true).built_in_kernels_selected());
    TS_ASSERT(device_query(false).select_image_max_buffer_size(true).image_max_buffer_size_selected());
    TS_ASSERT(device_query(false).select_image_max_array_size(true).image_max_array_size_selected());
    TS_ASSERT(device_query(false).select_parent_device_id(true).parent_device_id_selected());
    TS_ASSERT(device_query(false).select_partition_max_sub_devices(true).partition_max_sub_devices_selected());
    TS_ASSERT(device_query(false).select_partition_properties(true).partition_properties_selected());
    TS_ASSERT(device_query(false).select_partition_affinity_domain(true).partition_affinity_domain_selected());
    TS_ASSERT(device_query(false).select_partition_type(true).partition_type_selected());
    TS_ASSERT(device_query(false).select_reference_count(true).reference_count_selected());
    TS_ASSERT(device_query(false).select_preferred_interop_user_sync(true).preferred_interop_user_sync_selected());
    TS_ASSERT(device_query(false).select_printf_buffer_size(true).printf_buffer_size_selected());
    TS_ASSERT(device_query(false).select_image_pitch_alignment(true).image_pitch_alignment_selected());
    TS_ASSERT(device_query(false).select_image_base_address_alignment(true).image_base_address_alignment_selected());
  }
  /** // doc: test_select_all() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_all( )
  {
    device_query query(false);
    query.select_all();
    TS_ASSERT(query.id_selected());
    TS_ASSERT(query.type_selected());
    TS_ASSERT(query.vendor_id_selected());
    TS_ASSERT(query.max_compute_units_selected());
    TS_ASSERT(query.max_work_item_dimensions_selected());
    TS_ASSERT(query.max_work_group_size_selected());
    TS_ASSERT(query.max_work_item_sizes_selected());
    TS_ASSERT(query.preferred_vector_width_char_selected());
    TS_ASSERT(query.preferred_vector_width_short_selected());
    TS_ASSERT(query.preferred_vector_width_int_selected());
    TS_ASSERT(query.preferred_vector_width_long_selected());
    TS_ASSERT(query.preferred_vector_width_float_selected());
    TS_ASSERT(query.preferred_vector_width_double_selected());
    TS_ASSERT(query.max_clock_frequency_selected());
    TS_ASSERT(query.address_bits_selected());
    TS_ASSERT(query.max_read_image_args_selected());
    TS_ASSERT(query.max_write_image_args_selected());
    TS_ASSERT(query.max_mem_alloc_size_selected());
    TS_ASSERT(query.image2d_max_width_selected());
    TS_ASSERT(query.image2d_max_height_selected());
    TS_ASSERT(query.image3d_max_width_selected());
    TS_ASSERT(query.image3d_max_height_selected());
    TS_ASSERT(query.image3d_max_depth_selected());
    TS_ASSERT(query.image_support_selected());
    TS_ASSERT(query.max_parameter_size_selected());
    TS_ASSERT(query.max_samplers_selected());
    TS_ASSERT(query.mem_base_addr_align_selected());
    TS_ASSERT(query.min_data_type_align_size_selected());
    TS_ASSERT(query.single_fp_config_selected());
    TS_ASSERT(query.global_mem_cache_type_selected());
    TS_ASSERT(query.global_mem_cacheline_size_selected());
    TS_ASSERT(query.global_mem_cache_size_selected());
    TS_ASSERT(query.global_mem_size_selected());
    TS_ASSERT(query.max_constant_buffer_size_selected());
    TS_ASSERT(query.max_constant_args_selected());
    TS_ASSERT(query.local_mem_type_selected());
    TS_ASSERT(query.local_mem_size_selected());
    TS_ASSERT(query.error_correction_support_selected());
    TS_ASSERT(query.profiling_timer_resolution_selected());
    TS_ASSERT(query.endian_little_selected());
    TS_ASSERT(query.available_selected());
    TS_ASSERT(query.compiler_available_selected());
    TS_ASSERT(query.execution_capabilities_selected());
    TS_ASSERT(query.queue_properties_selected());
    TS_ASSERT(query.name_selected());
    TS_ASSERT(query.vendor_selected());
    TS_ASSERT(query.driver_version_selected());
    TS_ASSERT(query.profile_selected());
    TS_ASSERT(query.version_selected());
    TS_ASSERT(query.extensions_selected());
    TS_ASSERT(query.platform_id_selected());
    TS_ASSERT(query.double_fp_config_selected());
    TS_ASSERT(query.preferred_vector_width_half_selected());
    TS_ASSERT(query.host_unified_memory_selected());
    TS_ASSERT(query.native_vector_width_char_selected());
    TS_ASSERT(query.native_vector_width_short_selected());
    TS_ASSERT(query.native_vector_width_int_selected());
    TS_ASSERT(query.native_vector_width_long_selected());
    TS_ASSERT(query.native_vector_width_float_selected());
    TS_ASSERT(query.native_vector_width_double_selected());
    TS_ASSERT(query.native_vector_width_half_selected());
    TS_ASSERT(query.opencl_c_version_selected());
    TS_ASSERT(query.linker_available_selected());
    TS_ASSERT(query.built_in_kernels_selected());
    TS_ASSERT(query.image_max_buffer_size_selected());
    TS_ASSERT(query.image_max_array_size_selected());
    TS_ASSERT(query.parent_device_id_selected());
    TS_ASSERT(query.partition_max_sub_devices_selected());
    TS_ASSERT(query.partition_properties_selected());
    TS_ASSERT(query.partition_affinity_domain_selected());
    TS_ASSERT(query.partition_type_selected());
    TS_ASSERT(query.reference_count_selected());
    TS_ASSERT(query.preferred_interop_user_sync_selected());
    TS_ASSERT(query.printf_buffer_size_selected());
    TS_ASSERT(query.image_pitch_alignment_selected());
    TS_ASSERT(query.image_base_address_alignment_selected());
  }
  /** // doc: test_select_none() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_none( )
  {
    device_query query(true);
    query.select_none();
    TS_ASSERT(!query.id_selected());
    TS_ASSERT(!query.type_selected());
    TS_ASSERT(!query.vendor_id_selected());
    TS_ASSERT(!query.max_compute_units_selected());
    TS_ASSERT(!query.max_work_item_dimensions_selected());
    TS_ASSERT(!query.max_work_group_size_selected());
    TS_ASSERT(!query.max_work_item_sizes_selected());
    TS_ASSERT(!query.preferred_vector_width_char_selected());
    TS_ASSERT(!query.preferred_vector_width_short_selected());
    TS_ASSERT(!query.preferred_vector_width_int_selected());
    TS_ASSERT(!query.preferred_vector_width_long_selected());
    TS_ASSERT(!query.preferred_vector_width_float_selected());
    TS_ASSERT(!query.preferred_vector_width_double_selected());
    TS_ASSERT(!query.max_clock_frequency_selected());
    TS_ASSERT(!query.address_bits_selected());
    TS_ASSERT(!query.max_read_image_args_selected());
    TS_ASSERT(!query.max_write_image_args_selected());
    TS_ASSERT(!query.max_mem_alloc_size_selected());
    TS_ASSERT(!query.image2d_max_width_selected());
    TS_ASSERT(!query.image2d_max_height_selected());
    TS_ASSERT(!query.image3d_max_width_selected());
    TS_ASSERT(!query.image3d_max_height_selected());
    TS_ASSERT(!query.image3d_max_depth_selected());
    TS_ASSERT(!query.image_support_selected());
    TS_ASSERT(!query.max_parameter_size_selected());
    TS_ASSERT(!query.max_samplers_selected());
    TS_ASSERT(!query.mem_base_addr_align_selected());
    TS_ASSERT(!query.min_data_type_align_size_selected());
    TS_ASSERT(!query.single_fp_config_selected());
    TS_ASSERT(!query.global_mem_cache_type_selected());
    TS_ASSERT(!query.global_mem_cacheline_size_selected());
    TS_ASSERT(!query.global_mem_cache_size_selected());
    TS_ASSERT(!query.global_mem_size_selected());
    TS_ASSERT(!query.max_constant_buffer_size_selected());
    TS_ASSERT(!query.max_constant_args_selected());
    TS_ASSERT(!query.local_mem_type_selected());
    TS_ASSERT(!query.local_mem_size_selected());
    TS_ASSERT(!query.error_correction_support_selected());
    TS_ASSERT(!query.profiling_timer_resolution_selected());
    TS_ASSERT(!query.endian_little_selected());
    TS_ASSERT(!query.available_selected());
    TS_ASSERT(!query.compiler_available_selected());
    TS_ASSERT(!query.execution_capabilities_selected());
    TS_ASSERT(!query.queue_properties_selected());
    TS_ASSERT(!query.name_selected());
    TS_ASSERT(!query.vendor_selected());
    TS_ASSERT(!query.driver_version_selected());
    TS_ASSERT(!query.profile_selected());
    TS_ASSERT(!query.version_selected());
    TS_ASSERT(!query.extensions_selected());
    TS_ASSERT(!query.platform_id_selected());
    TS_ASSERT(!query.double_fp_config_selected());
    TS_ASSERT(!query.preferred_vector_width_half_selected());
    TS_ASSERT(!query.host_unified_memory_selected());
    TS_ASSERT(!query.native_vector_width_char_selected());
    TS_ASSERT(!query.native_vector_width_short_selected());
    TS_ASSERT(!query.native_vector_width_int_selected());
    TS_ASSERT(!query.native_vector_width_long_selected());
    TS_ASSERT(!query.native_vector_width_float_selected());
    TS_ASSERT(!query.native_vector_width_double_selected());
    TS_ASSERT(!query.native_vector_width_half_selected());
    TS_ASSERT(!query.opencl_c_version_selected());
    TS_ASSERT(!query.linker_available_selected());
    TS_ASSERT(!query.built_in_kernels_selected());
    TS_ASSERT(!query.image_max_buffer_size_selected());
    TS_ASSERT(!query.image_max_array_size_selected());
    TS_ASSERT(!query.parent_device_id_selected());
    TS_ASSERT(!query.partition_max_sub_devices_selected());
    TS_ASSERT(!query.partition_properties_selected());
    TS_ASSERT(!query.partition_affinity_domain_selected());
    TS_ASSERT(!query.partition_type_selected());
    TS_ASSERT(!query.reference_count_selected());
    TS_ASSERT(!query.preferred_interop_user_sync_selected());
    TS_ASSERT(!query.printf_buffer_size_selected());
    TS_ASSERT(!query.image_pitch_alignment_selected());
    TS_ASSERT(!query.image_base_address_alignment_selected());
  }
  /** // doc: test_restrict_to_1_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_select_default( )
  {
    TS_ASSERT(device_query(true).select_default() == device_query());
    TS_ASSERT(device_query(false).select_default() == device_query());
  }
  /** // doc: test_restrict_to_1_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_restrict_to_1_2( )
  {
    device_query a;
    device_query b;

    TS_ASSERT((a == b));
    a.restrict_to(1,2);
    TS_ASSERT((a == b));
  }
  /** // doc: test_restrict_to_1_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_restrict_to_1_1( )
  {
    device_query a;
    device_query b;

    TS_ASSERT((a == b));
    a.restrict_to(1,1);
    TS_ASSERT((a != b));

    // Make sure these are unselected
    TS_ASSERT(!a.double_fp_config_selected());
    TS_ASSERT(!a.linker_available_selected());
    TS_ASSERT(!a.built_in_kernels_selected());
    TS_ASSERT(!a.image_max_buffer_size_selected());
    TS_ASSERT(!a.image_max_array_size_selected());
    TS_ASSERT(!a.parent_device_id_selected());
    TS_ASSERT(!a.partition_max_sub_devices_selected());
    TS_ASSERT(!a.partition_properties_selected());
    TS_ASSERT(!a.partition_affinity_domain_selected());
    TS_ASSERT(!a.partition_type_selected());
    TS_ASSERT(!a.reference_count_selected());
    TS_ASSERT(!a.preferred_interop_user_sync_selected());
    TS_ASSERT(!a.printf_buffer_size_selected());
    TS_ASSERT(!a.image_pitch_alignment_selected());
    TS_ASSERT(!a.image_base_address_alignment_selected());

    // Make sure ONLY these were unselected
    a.select_double_fp_config();
    a.select_linker_available();
    a.select_built_in_kernels();
    a.select_image_max_buffer_size();
    a.select_image_max_array_size();
    a.select_parent_device_id();
    a.select_partition_max_sub_devices();
    a.select_partition_properties();
    a.select_partition_affinity_domain();
    a.select_partition_type();
    a.select_reference_count();
    a.select_preferred_interop_user_sync();
    a.select_printf_buffer_size();
    a.select_image_pitch_alignment();
    a.select_image_base_address_alignment();

    TS_ASSERT((a == b));
  }
  /** // doc: test_restrict_to_1_0() {{{
   * \todo Write documentation
   */ // }}}
  void test_restrict_to_1_0( )
  {
    device_query a;
    device_query b;

    TS_ASSERT((a == b));
    a.restrict_to(1,0);
    TS_ASSERT((a != b));

    // Make sure these are unselected
    TS_ASSERT(!a.preferred_vector_width_half_selected());
    TS_ASSERT(!a.host_unified_memory_selected());
    TS_ASSERT(!a.native_vector_width_char_selected());
    TS_ASSERT(!a.native_vector_width_short_selected());
    TS_ASSERT(!a.native_vector_width_int_selected());
    TS_ASSERT(!a.native_vector_width_long_selected());
    TS_ASSERT(!a.native_vector_width_float_selected());
    TS_ASSERT(!a.native_vector_width_double_selected());
    TS_ASSERT(!a.native_vector_width_half_selected());
    TS_ASSERT(!a.opencl_c_version_selected());
    TS_ASSERT(!a.double_fp_config_selected());
    TS_ASSERT(!a.linker_available_selected());
    TS_ASSERT(!a.built_in_kernels_selected());
    TS_ASSERT(!a.image_max_buffer_size_selected());
    TS_ASSERT(!a.image_max_array_size_selected());
    TS_ASSERT(!a.parent_device_id_selected());
    TS_ASSERT(!a.partition_max_sub_devices_selected());
    TS_ASSERT(!a.partition_properties_selected());
    TS_ASSERT(!a.partition_affinity_domain_selected());
    TS_ASSERT(!a.partition_type_selected());
    TS_ASSERT(!a.reference_count_selected());
    TS_ASSERT(!a.preferred_interop_user_sync_selected());
    TS_ASSERT(!a.printf_buffer_size_selected());
    TS_ASSERT(!a.image_pitch_alignment_selected());
    TS_ASSERT(!a.image_base_address_alignment_selected());

    // Make sure ONLY these were unselected
    a.select_preferred_vector_width_half();
    a.select_host_unified_memory();
    a.select_native_vector_width_char();
    a.select_native_vector_width_short();
    a.select_native_vector_width_int();
    a.select_native_vector_width_long();
    a.select_native_vector_width_float();
    a.select_native_vector_width_double();
    a.select_native_vector_width_half();
    a.select_opencl_c_version();
    a.select_double_fp_config();
    a.select_linker_available();
    a.select_built_in_kernels();
    a.select_image_max_buffer_size();
    a.select_image_max_array_size();
    a.select_parent_device_id();
    a.select_partition_max_sub_devices();
    a.select_partition_properties();
    a.select_partition_affinity_domain();
    a.select_partition_type();
    a.select_reference_count();
    a.select_preferred_interop_user_sync();
    a.select_printf_buffer_size();
    a.select_image_pitch_alignment();
    a.select_image_base_address_alignment();

    TS_ASSERT((a == b));
  }
  /** // doc: test_eq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_1( )
  {
    TS_ASSERT((device_query() == device_query()));
    TS_ASSERT((device_query(true) == device_query(true)));
    TS_ASSERT((device_query(false) == device_query(false)));
  }
  /** // doc: test_eq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_2( )
  {
    TS_ASSERT(!(device_query(true).select_id(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_type(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_vendor_id(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_compute_units(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_work_item_dimensions(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_work_group_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_work_item_sizes(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_vector_width_char(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_vector_width_int(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_vector_width_short(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_vector_width_long(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_vector_width_float(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_vector_width_double(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_clock_frequency(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_address_bits(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_read_image_args(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_write_image_args(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_mem_alloc_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image2d_max_width(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image2d_max_height(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image3d_max_width(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image3d_max_height(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image3d_max_depth(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image_support(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_parameter_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_samplers(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_mem_base_addr_align(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_min_data_type_align_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_single_fp_config(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_global_mem_cache_type(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_global_mem_cacheline_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_global_mem_cache_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_global_mem_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_constant_buffer_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_max_constant_args(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_local_mem_type(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_local_mem_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_error_correction_support(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_profiling_timer_resolution(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_endian_little(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_available(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_id(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_compiler_available(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_queue_properties(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_name(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_vendor(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_driver_version(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_extensions(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_platform_id(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_double_fp_config(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_vector_width_half(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_host_unified_memory(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_native_vector_width_char(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_native_vector_width_short(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_native_vector_width_int(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_native_vector_width_long(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_native_vector_width_float(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_native_vector_width_double(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_native_vector_width_half(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_opencl_c_version(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_linker_available(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_built_in_kernels(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image_max_buffer_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image_max_array_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_parent_device_id(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_partition_max_sub_devices(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_partition_properties(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_partition_affinity_domain(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_partition_type(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_reference_count(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_preferred_interop_user_sync(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_printf_buffer_size(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image_pitch_alignment(false) == device_query(true)));
    TS_ASSERT(!(device_query(true).select_image_base_address_alignment(false) == device_query(true)));
  }
  /** // doc: test_neq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_1( )
  {
    TS_ASSERT(!(device_query() != device_query()));
  }
  /** // doc: test_neq_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op( )
  {
    TS_ASSERT((device_query(true).select_id(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_type(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_vendor_id(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_compute_units(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_work_item_dimensions(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_work_group_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_work_item_sizes(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_vector_width_char(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_vector_width_int(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_vector_width_short(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_vector_width_long(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_vector_width_float(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_vector_width_double(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_clock_frequency(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_address_bits(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_read_image_args(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_write_image_args(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_mem_alloc_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image2d_max_width(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image2d_max_height(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image3d_max_width(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image3d_max_height(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image3d_max_depth(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image_support(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_parameter_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_samplers(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_mem_base_addr_align(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_min_data_type_align_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_single_fp_config(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_global_mem_cache_type(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_global_mem_cacheline_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_global_mem_cache_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_global_mem_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_constant_buffer_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_max_constant_args(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_local_mem_type(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_local_mem_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_error_correction_support(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_profiling_timer_resolution(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_endian_little(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_available(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_id(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_compiler_available(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_queue_properties(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_name(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_vendor(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_driver_version(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_extensions(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_platform_id(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_double_fp_config(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_vector_width_half(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_host_unified_memory(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_native_vector_width_char(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_native_vector_width_short(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_native_vector_width_int(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_native_vector_width_long(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_native_vector_width_float(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_native_vector_width_double(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_native_vector_width_half(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_opencl_c_version(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_linker_available(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_built_in_kernels(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image_max_buffer_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image_max_array_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_parent_device_id(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_partition_max_sub_devices(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_partition_properties(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_partition_affinity_domain(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_partition_type(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_reference_count(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_preferred_interop_user_sync(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_printf_buffer_size(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image_pitch_alignment(false) != device_query(true)));
    TS_ASSERT((device_query(true).select_image_base_address_alignment(false) != device_query(true)));
  }
};

#endif /* CLXX_DEVICE_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
