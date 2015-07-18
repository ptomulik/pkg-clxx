// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/device_info.t.h

/** // doc: clxx/info/device_info.t.h {{{
 * \file clxx/info/device_info.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_INFO_DEVICE_INFO_T_H_INCLUDED
#define CLXX_INFO_DEVICE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/info/device_info.hpp>
#include <clxx/device_info_fixtures.hpp>
#include <clxx/common/exceptions.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

namespace clxx { class device_info_test_suite; }

/** // doc: class clxx::device_info_test_suite {{{
 * \brief Unit tests for clxx::device_info class
 */ // }}}
class clxx::device_info_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_defaults() {{{
   * \todo Write documentation
   */ // }}}
  void test_defaults( )
  {
    TS_ASSERT(!device_info().has_id());
    TS_ASSERT(!device_info().has_type());
    TS_ASSERT(!device_info().has_vendor_id());
    TS_ASSERT(!device_info().has_max_compute_units());
    TS_ASSERT(!device_info().has_max_work_item_dimensions());
    TS_ASSERT(!device_info().has_max_work_group_size());
    TS_ASSERT(!device_info().has_max_work_item_sizes());
    TS_ASSERT(!device_info().has_preferred_vector_width_char());
    TS_ASSERT(!device_info().has_preferred_vector_width_short());
    TS_ASSERT(!device_info().has_preferred_vector_width_int());
    TS_ASSERT(!device_info().has_preferred_vector_width_long());
    TS_ASSERT(!device_info().has_preferred_vector_width_float());
    TS_ASSERT(!device_info().has_preferred_vector_width_double());
    TS_ASSERT(!device_info().has_max_clock_frequency());
    TS_ASSERT(!device_info().has_address_bits());
    TS_ASSERT(!device_info().has_max_read_image_args());
    TS_ASSERT(!device_info().has_max_write_image_args());
    TS_ASSERT(!device_info().has_max_mem_alloc_size());
    TS_ASSERT(!device_info().has_image2d_max_width());
    TS_ASSERT(!device_info().has_image2d_max_height());
    TS_ASSERT(!device_info().has_image3d_max_width());
    TS_ASSERT(!device_info().has_image3d_max_height());
    TS_ASSERT(!device_info().has_image3d_max_depth());
    TS_ASSERT(!device_info().has_image_support());
    TS_ASSERT(!device_info().has_max_parameter_size());
    TS_ASSERT(!device_info().has_max_samplers());
    TS_ASSERT(!device_info().has_mem_base_addr_align());
    TS_ASSERT(!device_info().has_min_data_type_align_size());
    TS_ASSERT(!device_info().has_single_fp_config());
    TS_ASSERT(!device_info().has_global_mem_cache_type());
    TS_ASSERT(!device_info().has_global_mem_cacheline_size());
    TS_ASSERT(!device_info().has_global_mem_cache_size());
    TS_ASSERT(!device_info().has_global_mem_size());
    TS_ASSERT(!device_info().has_max_constant_buffer_size());
    TS_ASSERT(!device_info().has_max_constant_args());
    TS_ASSERT(!device_info().has_local_mem_type());
    TS_ASSERT(!device_info().has_local_mem_size());
    TS_ASSERT(!device_info().has_error_correction_support());
    TS_ASSERT(!device_info().has_profiling_timer_resolution());
    TS_ASSERT(!device_info().has_endian_little());
    TS_ASSERT(!device_info().has_available());
    TS_ASSERT(!device_info().has_compiler_available());
    TS_ASSERT(!device_info().has_execution_capabilities());
    TS_ASSERT(!device_info().has_queue_properties());
    TS_ASSERT(!device_info().has_name());
    TS_ASSERT(!device_info().has_vendor());
    TS_ASSERT(!device_info().has_driver_version());
    TS_ASSERT(!device_info().has_profile());
    TS_ASSERT(!device_info().has_version());
    TS_ASSERT(!device_info().has_extensions());
    TS_ASSERT(!device_info().has_platform_id());
    TS_ASSERT(!device_info().has_double_fp_config());
    TS_ASSERT(!device_info().has_preferred_vector_width_half());
    TS_ASSERT(!device_info().has_host_unified_memory());
    TS_ASSERT(!device_info().has_native_vector_width_char());
    TS_ASSERT(!device_info().has_native_vector_width_short());
    TS_ASSERT(!device_info().has_native_vector_width_int());
    TS_ASSERT(!device_info().has_native_vector_width_long());
    TS_ASSERT(!device_info().has_native_vector_width_float());
    TS_ASSERT(!device_info().has_native_vector_width_double());
    TS_ASSERT(!device_info().has_native_vector_width_half());
    TS_ASSERT(!device_info().has_opencl_c_version());
    TS_ASSERT(!device_info().has_linker_available());
    TS_ASSERT(!device_info().has_built_in_kernels());
    TS_ASSERT(!device_info().has_image_max_buffer_size());
    TS_ASSERT(!device_info().has_image_max_array_size());
    TS_ASSERT(!device_info().has_parent_device_id());
    TS_ASSERT(!device_info().has_partition_max_sub_devices());
    TS_ASSERT(!device_info().has_partition_properties());
    TS_ASSERT(!device_info().has_partition_affinity_domain());
    TS_ASSERT(!device_info().has_partition_type());
    TS_ASSERT(!device_info().has_reference_count());
    TS_ASSERT(!device_info().has_preferred_interop_user_sync());
    TS_ASSERT(!device_info().has_printf_buffer_size());
    TS_ASSERT(!device_info().has_image_pitch_alignment());
    TS_ASSERT(!device_info().has_image_base_address_alignment());
  }
  /** // doc: test_getter_exceptions() {{{
   * \todo Write documentation
   */ // }}}
  void test_getter_exceptions( )
  {
    TS_ASSERT_THROWS(device_info().id(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().type(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().vendor_id(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_compute_units(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_work_item_dimensions(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_work_group_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_work_item_sizes(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_vector_width_char(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_vector_width_short(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_vector_width_int(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_vector_width_long(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_vector_width_float(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_vector_width_double(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_clock_frequency(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().address_bits(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_read_image_args(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_write_image_args(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_mem_alloc_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image2d_max_width(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image2d_max_height(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image3d_max_width(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image3d_max_height(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image3d_max_depth(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image_support(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_parameter_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_samplers(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().mem_base_addr_align(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().min_data_type_align_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().single_fp_config(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().global_mem_cache_type(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().global_mem_cacheline_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().global_mem_cache_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().global_mem_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_constant_buffer_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().max_constant_args(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().local_mem_type(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().local_mem_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().error_correction_support(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().profiling_timer_resolution(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().endian_little(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().available(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().compiler_available(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().execution_capabilities(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().queue_properties(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().name(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().vendor(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().driver_version(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().profile(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().version(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().extensions(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().platform_id(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().double_fp_config(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_vector_width_half(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().host_unified_memory(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().native_vector_width_char(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().native_vector_width_short(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().native_vector_width_int(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().native_vector_width_long(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().native_vector_width_float(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().native_vector_width_double(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().native_vector_width_half(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().opencl_c_version(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().linker_available(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().built_in_kernels(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image_max_buffer_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image_max_array_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().parent_device_id(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().partition_max_sub_devices(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().partition_properties(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().partition_affinity_domain(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().partition_type(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().reference_count(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().preferred_interop_user_sync(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().printf_buffer_size(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image_pitch_alignment(), uninitialized_value_error);
    TS_ASSERT_THROWS(device_info().image_base_address_alignment(), uninitialized_value_error);
  }
  /** // doc: test_set_get() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_get( )
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    device_partition_property_t partition_properties1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_type1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };

    TS_ASSERT_EQUALS(device_info().set_id(0x1234ul).id(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_type(device_type_t::cpu).type(),device_type_t::cpu);
    TS_ASSERT_EQUALS(device_info().set_vendor_id(0x1234u).vendor_id(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_compute_units(0x1234u).max_compute_units(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_work_item_dimensions(0x1234u).max_work_item_dimensions(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_work_group_size(0x1234ul).max_work_group_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)).max_work_item_sizes(),std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3));
    TS_ASSERT_EQUALS(device_info().set_preferred_vector_width_char(0x1234u).preferred_vector_width_char(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_preferred_vector_width_short(0x1234u).preferred_vector_width_short(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_preferred_vector_width_int(0x1234u).preferred_vector_width_int(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_preferred_vector_width_long(0x1234u).preferred_vector_width_long(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_preferred_vector_width_float(0x1234u).preferred_vector_width_float(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_preferred_vector_width_double(0x1234u).preferred_vector_width_double(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_clock_frequency(0x1234u).max_clock_frequency(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_address_bits(0x1234u).address_bits(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_read_image_args(0x1234u).max_read_image_args(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_write_image_args(0x1234u).max_write_image_args(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_mem_alloc_size(0x1234ul).max_mem_alloc_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image2d_max_width(0x1234ul).image2d_max_width(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image2d_max_height(0x1234ul).image2d_max_height(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image3d_max_width(0x1234ul).image3d_max_width(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image3d_max_height(0x1234ul).image3d_max_height(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image3d_max_depth(0x1234ul).image3d_max_depth(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image_support(0).image_support(),0);
    TS_ASSERT_EQUALS(device_info().set_max_parameter_size(0x1234ul).max_parameter_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_max_samplers(0x1234u).max_samplers(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_mem_base_addr_align(0x1234u).mem_base_addr_align(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_min_data_type_align_size(0x1234u).min_data_type_align_size(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_single_fp_config(device_fp_config_t::denorm).single_fp_config(),device_fp_config_t::denorm);
    TS_ASSERT_EQUALS(device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache).global_mem_cache_type(),device_mem_cache_type_t::read_only_cache);
    TS_ASSERT_EQUALS(device_info().set_global_mem_cacheline_size(0x1234u).global_mem_cacheline_size(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_global_mem_cache_size(0x1234ul).global_mem_cache_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_global_mem_size(0x1234ul).global_mem_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_max_constant_buffer_size(0x1234u).max_constant_buffer_size(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_max_constant_args(0x1234u).max_constant_args(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_local_mem_type(device_local_mem_type_t::local).local_mem_type(),device_local_mem_type_t::local);
    TS_ASSERT_EQUALS(device_info().set_local_mem_size(0x1234ul).local_mem_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_error_correction_support(0).error_correction_support(),0);
    TS_ASSERT_EQUALS(device_info().set_profiling_timer_resolution(0x1234ul).profiling_timer_resolution(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_endian_little(0).endian_little(),0);
    TS_ASSERT_EQUALS(device_info().set_available(0).available(),0);
    TS_ASSERT_EQUALS(device_info().set_compiler_available(0).compiler_available(),0);
    TS_ASSERT_EQUALS(device_info().set_execution_capabilities(device_exec_capabilities_t::kernel).execution_capabilities(),device_exec_capabilities_t::kernel);
    TS_ASSERT_EQUALS(device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable).queue_properties(),command_queue_properties_t::out_of_order_exec_mode_enable);
    TS_ASSERT_EQUALS(device_info().set_name("_name").name(),"_name");
    TS_ASSERT_EQUALS(device_info().set_vendor("_vendor").vendor(),"_vendor");
    TS_ASSERT_EQUALS(device_info().set_driver_version("_driver_version").driver_version(),"_driver_version");
    TS_ASSERT_EQUALS(device_info().set_profile("_profile").profile(),"_profile");
    TS_ASSERT_EQUALS(device_info().set_version("_version").version(),"_version");
    TS_ASSERT_EQUALS(device_info().set_extensions("_extensions").extensions(),"_extensions");
    TS_ASSERT_EQUALS(device_info().set_platform_id(0x1234ul).platform_id(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_double_fp_config(device_fp_config_t::denorm).double_fp_config(),device_fp_config_t::denorm);
    TS_ASSERT_EQUALS(device_info().set_preferred_vector_width_half(0x1234u).preferred_vector_width_half(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_host_unified_memory(0).host_unified_memory(),0);
    TS_ASSERT_EQUALS(device_info().set_native_vector_width_char(0x1234u).native_vector_width_char(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_native_vector_width_short(0x1234u).native_vector_width_short(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_native_vector_width_int(0x1234u).native_vector_width_int(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_native_vector_width_long(0x1234u).native_vector_width_long(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_native_vector_width_float(0x1234u).native_vector_width_float(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_native_vector_width_double(0x1234u).native_vector_width_double(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_native_vector_width_half(0x1234u).native_vector_width_half(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_opencl_c_version("_opencl_c_version").opencl_c_version(),"_opencl_c_version");
    TS_ASSERT_EQUALS(device_info().set_linker_available(0).linker_available(),0);
    TS_ASSERT_EQUALS(device_info().set_built_in_kernels("_built_in_kernels").built_in_kernels(),"_built_in_kernels");
    TS_ASSERT_EQUALS(device_info().set_image_max_buffer_size(0x1234ul).image_max_buffer_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image_max_array_size(0x1234ul).image_max_array_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_parent_device_id(0x1234ul).parent_device_id(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_partition_max_sub_devices(0x1234u).partition_max_sub_devices(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2)).partition_properties(),std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2));
    TS_ASSERT_EQUALS(device_info().set_partition_affinity_domain(device_affinity_domain_t::numa).partition_affinity_domain(),device_affinity_domain_t::numa);
    TS_ASSERT_EQUALS(device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2)).partition_type(),std::vector<device_partition_property_t>(partition_type1,partition_type1+2));
    TS_ASSERT_EQUALS(device_info().set_reference_count(0x1234u).reference_count(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_preferred_interop_user_sync(0).preferred_interop_user_sync(),0);
    TS_ASSERT_EQUALS(device_info().set_printf_buffer_size(0x1234ul).printf_buffer_size(),0x1234ul);
    TS_ASSERT_EQUALS(device_info().set_image_pitch_alignment(0x1234u).image_pitch_alignment(),0x1234u);
    TS_ASSERT_EQUALS(device_info().set_image_base_address_alignment(0x1234u).image_base_address_alignment(),0x1234u);
  }
  /** // doc: test_set_has() {{{
   * \todo Write documentation
   */ // }}}
  void test_set_has( )
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    device_partition_property_t partition_properties1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_type1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };

    TS_ASSERT(device_info().set_id(0x1234ul).has_id());
    TS_ASSERT(device_info().set_type(device_type_t::cpu).has_type());
    TS_ASSERT(device_info().set_vendor_id(0x1234u).has_vendor_id());
    TS_ASSERT(device_info().set_max_compute_units(0x1234u).has_max_compute_units());
    TS_ASSERT(device_info().set_max_work_item_dimensions(0x1234u).has_max_work_item_dimensions());
    TS_ASSERT(device_info().set_max_work_group_size(0x1234ul).has_max_work_group_size());
    TS_ASSERT(device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)).has_max_work_item_sizes());
    TS_ASSERT(device_info().set_preferred_vector_width_char(0x1234u).has_preferred_vector_width_char());
    TS_ASSERT(device_info().set_preferred_vector_width_short(0x1234u).has_preferred_vector_width_short());
    TS_ASSERT(device_info().set_preferred_vector_width_int(0x1234u).has_preferred_vector_width_int());
    TS_ASSERT(device_info().set_preferred_vector_width_long(0x1234u).has_preferred_vector_width_long());
    TS_ASSERT(device_info().set_preferred_vector_width_float(0x1234u).has_preferred_vector_width_float());
    TS_ASSERT(device_info().set_preferred_vector_width_double(0x1234u).has_preferred_vector_width_double());
    TS_ASSERT(device_info().set_max_clock_frequency(0x1234u).has_max_clock_frequency());
    TS_ASSERT(device_info().set_address_bits(0x1234u).has_address_bits());
    TS_ASSERT(device_info().set_max_read_image_args(0x1234u).has_max_read_image_args());
    TS_ASSERT(device_info().set_max_write_image_args(0x1234u).has_max_write_image_args());
    TS_ASSERT(device_info().set_max_mem_alloc_size(0x1234ul).has_max_mem_alloc_size());
    TS_ASSERT(device_info().set_image2d_max_width(0x1234ul).has_image2d_max_width());
    TS_ASSERT(device_info().set_image2d_max_height(0x1234ul).has_image2d_max_height());
    TS_ASSERT(device_info().set_image3d_max_width(0x1234ul).has_image3d_max_width());
    TS_ASSERT(device_info().set_image3d_max_height(0x1234ul).has_image3d_max_height());
    TS_ASSERT(device_info().set_image3d_max_depth(0x1234ul).has_image3d_max_depth());
    TS_ASSERT(device_info().set_image_support(0).has_image_support());
    TS_ASSERT(device_info().set_max_parameter_size(0x1234ul).has_max_parameter_size());
    TS_ASSERT(device_info().set_max_samplers(0x1234u).has_max_samplers());
    TS_ASSERT(device_info().set_mem_base_addr_align(0x1234u).has_mem_base_addr_align());
    TS_ASSERT(device_info().set_min_data_type_align_size(0x1234u).has_min_data_type_align_size());
    TS_ASSERT(device_info().set_single_fp_config(device_fp_config_t::denorm).has_single_fp_config());
    TS_ASSERT(device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache).has_global_mem_cache_type());
    TS_ASSERT(device_info().set_global_mem_cacheline_size(0x1234u).has_global_mem_cacheline_size());
    TS_ASSERT(device_info().set_global_mem_cache_size(0x1234ul).has_global_mem_cache_size());
    TS_ASSERT(device_info().set_global_mem_size(0x1234ul).has_global_mem_size());
    TS_ASSERT(device_info().set_max_constant_buffer_size(0x1234u).has_max_constant_buffer_size());
    TS_ASSERT(device_info().set_max_constant_args(0x1234u).has_max_constant_args());
    TS_ASSERT(device_info().set_local_mem_type(device_local_mem_type_t::local).has_local_mem_type());
    TS_ASSERT(device_info().set_local_mem_size(0x1234ul).has_local_mem_size());
    TS_ASSERT(device_info().set_error_correction_support(0).has_error_correction_support());
    TS_ASSERT(device_info().set_profiling_timer_resolution(0x1234ul).has_profiling_timer_resolution());
    TS_ASSERT(device_info().set_endian_little(0).has_endian_little());
    TS_ASSERT(device_info().set_available(0).has_available());
    TS_ASSERT(device_info().set_compiler_available(0).has_compiler_available());
    TS_ASSERT(device_info().set_execution_capabilities(device_exec_capabilities_t::kernel).has_execution_capabilities());
    TS_ASSERT(device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable).has_queue_properties());
    TS_ASSERT(device_info().set_name("_name").has_name());
    TS_ASSERT(device_info().set_vendor("_vendor").has_vendor());
    TS_ASSERT(device_info().set_driver_version("_driver_version").has_driver_version());
    TS_ASSERT(device_info().set_profile("_profile").has_profile());
    TS_ASSERT(device_info().set_version("_version").has_version());
    TS_ASSERT(device_info().set_extensions("_extensions").has_extensions());
    TS_ASSERT(device_info().set_platform_id(0x1234ul).has_platform_id());
    TS_ASSERT(device_info().set_double_fp_config(device_fp_config_t::denorm).has_double_fp_config());
    TS_ASSERT(device_info().set_preferred_vector_width_half(0x1234u).has_preferred_vector_width_half());
    TS_ASSERT(device_info().set_host_unified_memory(0).has_host_unified_memory());
    TS_ASSERT(device_info().set_native_vector_width_char(0x1234u).has_native_vector_width_char());
    TS_ASSERT(device_info().set_native_vector_width_short(0x1234u).has_native_vector_width_short());
    TS_ASSERT(device_info().set_native_vector_width_int(0x1234u).has_native_vector_width_int());
    TS_ASSERT(device_info().set_native_vector_width_long(0x1234u).has_native_vector_width_long());
    TS_ASSERT(device_info().set_native_vector_width_float(0x1234u).has_native_vector_width_float());
    TS_ASSERT(device_info().set_native_vector_width_double(0x1234u).has_native_vector_width_double());
    TS_ASSERT(device_info().set_native_vector_width_half(0x1234u).has_native_vector_width_half());
    TS_ASSERT(device_info().set_opencl_c_version("_opencl_c_version").has_opencl_c_version());
    TS_ASSERT(device_info().set_linker_available(0).has_linker_available());
    TS_ASSERT(device_info().set_built_in_kernels("_built_in_kernels").has_built_in_kernels());
    TS_ASSERT(device_info().set_image_max_buffer_size(0x1234ul).has_image_max_buffer_size());
    TS_ASSERT(device_info().set_image_max_array_size(0x1234ul).has_image_max_array_size());
    TS_ASSERT(device_info().set_parent_device_id(0x1234ul).has_parent_device_id());
    TS_ASSERT(device_info().set_partition_max_sub_devices(0x1234u).has_partition_max_sub_devices());
    TS_ASSERT(device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2)).has_partition_properties());
    TS_ASSERT(device_info().set_partition_affinity_domain(device_affinity_domain_t::numa).has_partition_affinity_domain());
    TS_ASSERT(device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2)).has_partition_type());
    TS_ASSERT(device_info().set_reference_count(0x1234u).has_reference_count());
    TS_ASSERT(device_info().set_preferred_interop_user_sync(0).has_preferred_interop_user_sync());
    TS_ASSERT(device_info().set_printf_buffer_size(0x1234ul).has_printf_buffer_size());
    TS_ASSERT(device_info().set_image_pitch_alignment(0x1234u).has_image_pitch_alignment());
    TS_ASSERT(device_info().set_image_base_address_alignment(0x1234u).has_image_base_address_alignment());
  }
  /** // doc: test_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_has_1( )
  {
    device_info const infos[2] = { device_info_fixtures::_1(), device_info_fixtures::_2() };
    for(device_info const* info = infos; info < infos + 2; ++info)
      {
        TS_ASSERT(info->has_id());
        TS_ASSERT(info->has_type());
        TS_ASSERT(info->has_vendor_id());
        TS_ASSERT(info->has_max_compute_units());
        TS_ASSERT(info->has_max_work_item_dimensions());
        TS_ASSERT(info->has_max_work_group_size());
        TS_ASSERT(info->has_max_work_item_sizes());
        TS_ASSERT(info->has_preferred_vector_width_char());
        TS_ASSERT(info->has_preferred_vector_width_short());
        TS_ASSERT(info->has_preferred_vector_width_int());
        TS_ASSERT(info->has_preferred_vector_width_long());
        TS_ASSERT(info->has_preferred_vector_width_float());
        TS_ASSERT(info->has_preferred_vector_width_double());
        TS_ASSERT(info->has_max_clock_frequency());
        TS_ASSERT(info->has_address_bits());
        TS_ASSERT(info->has_max_read_image_args());
        TS_ASSERT(info->has_max_write_image_args());
        TS_ASSERT(info->has_max_mem_alloc_size());
        TS_ASSERT(info->has_image2d_max_width());
        TS_ASSERT(info->has_image2d_max_height());
        TS_ASSERT(info->has_image3d_max_width());
        TS_ASSERT(info->has_image3d_max_height());
        TS_ASSERT(info->has_image3d_max_depth());
        TS_ASSERT(info->has_image_support());
        TS_ASSERT(info->has_max_parameter_size());
        TS_ASSERT(info->has_max_samplers());
        TS_ASSERT(info->has_mem_base_addr_align());
        TS_ASSERT(info->has_min_data_type_align_size());
        TS_ASSERT(info->has_single_fp_config());
        TS_ASSERT(info->has_global_mem_cache_type());
        TS_ASSERT(info->has_global_mem_cacheline_size());
        TS_ASSERT(info->has_global_mem_cache_size());
        TS_ASSERT(info->has_global_mem_size());
        TS_ASSERT(info->has_max_constant_buffer_size());
        TS_ASSERT(info->has_max_constant_args());
        TS_ASSERT(info->has_local_mem_type());
        TS_ASSERT(info->has_local_mem_size());
        TS_ASSERT(info->has_error_correction_support());
        TS_ASSERT(info->has_profiling_timer_resolution());
        TS_ASSERT(info->has_endian_little());
        TS_ASSERT(info->has_available());
        TS_ASSERT(info->has_compiler_available());
        TS_ASSERT(info->has_execution_capabilities());
        TS_ASSERT(info->has_queue_properties());
        TS_ASSERT(info->has_name());
        TS_ASSERT(info->has_vendor());
        TS_ASSERT(info->has_driver_version());
        TS_ASSERT(info->has_profile());
        TS_ASSERT(info->has_version());
        TS_ASSERT(info->has_extensions());
        TS_ASSERT(info->has_platform_id());
        TS_ASSERT(info->has_double_fp_config());
        TS_ASSERT(info->has_preferred_vector_width_half());
        TS_ASSERT(info->has_host_unified_memory());
        TS_ASSERT(info->has_native_vector_width_char());
        TS_ASSERT(info->has_native_vector_width_short());
        TS_ASSERT(info->has_native_vector_width_int());
        TS_ASSERT(info->has_native_vector_width_long());
        TS_ASSERT(info->has_native_vector_width_float());
        TS_ASSERT(info->has_native_vector_width_double());
        TS_ASSERT(info->has_native_vector_width_half());
        TS_ASSERT(info->has_opencl_c_version());
        TS_ASSERT(info->has_linker_available());
        TS_ASSERT(info->has_built_in_kernels());
        TS_ASSERT(info->has_image_max_buffer_size());
        TS_ASSERT(info->has_image_max_array_size());
        TS_ASSERT(info->has_parent_device_id());
        TS_ASSERT(info->has_partition_max_sub_devices());
        TS_ASSERT(info->has_partition_properties());
        TS_ASSERT(info->has_partition_affinity_domain());
        TS_ASSERT(info->has_partition_type());
        TS_ASSERT(info->has_reference_count());
        TS_ASSERT(info->has_preferred_interop_user_sync());
        TS_ASSERT(info->has_printf_buffer_size());
        TS_ASSERT(info->has_image_pitch_alignment());
        TS_ASSERT(info->has_image_base_address_alignment());
      }
  }
  /** // doc: test_clear_dont_has_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_dont_has_1( )
  {
    device_info info(device_info_fixtures::_1());

    info.clear();

    TS_ASSERT(!info.has_id());
    TS_ASSERT(!info.has_type());
    TS_ASSERT(!info.has_vendor_id());
    TS_ASSERT(!info.has_max_compute_units());
    TS_ASSERT(!info.has_max_work_item_dimensions());
    TS_ASSERT(!info.has_max_work_group_size());
    TS_ASSERT(!info.has_max_work_item_sizes());
    TS_ASSERT(!info.has_preferred_vector_width_char());
    TS_ASSERT(!info.has_preferred_vector_width_short());
    TS_ASSERT(!info.has_preferred_vector_width_int());
    TS_ASSERT(!info.has_preferred_vector_width_long());
    TS_ASSERT(!info.has_preferred_vector_width_float());
    TS_ASSERT(!info.has_preferred_vector_width_double());
    TS_ASSERT(!info.has_max_clock_frequency());
    TS_ASSERT(!info.has_address_bits());
    TS_ASSERT(!info.has_max_read_image_args());
    TS_ASSERT(!info.has_max_write_image_args());
    TS_ASSERT(!info.has_max_mem_alloc_size());
    TS_ASSERT(!info.has_image2d_max_width());
    TS_ASSERT(!info.has_image2d_max_height());
    TS_ASSERT(!info.has_image3d_max_width());
    TS_ASSERT(!info.has_image3d_max_height());
    TS_ASSERT(!info.has_image3d_max_depth());
    TS_ASSERT(!info.has_image_support());
    TS_ASSERT(!info.has_max_parameter_size());
    TS_ASSERT(!info.has_max_samplers());
    TS_ASSERT(!info.has_mem_base_addr_align());
    TS_ASSERT(!info.has_min_data_type_align_size());
    TS_ASSERT(!info.has_single_fp_config());
    TS_ASSERT(!info.has_global_mem_cache_type());
    TS_ASSERT(!info.has_global_mem_cacheline_size());
    TS_ASSERT(!info.has_global_mem_cache_size());
    TS_ASSERT(!info.has_global_mem_size());
    TS_ASSERT(!info.has_max_constant_buffer_size());
    TS_ASSERT(!info.has_max_constant_args());
    TS_ASSERT(!info.has_local_mem_type());
    TS_ASSERT(!info.has_local_mem_size());
    TS_ASSERT(!info.has_error_correction_support());
    TS_ASSERT(!info.has_profiling_timer_resolution());
    TS_ASSERT(!info.has_endian_little());
    TS_ASSERT(!info.has_available());
    TS_ASSERT(!info.has_compiler_available());
    TS_ASSERT(!info.has_execution_capabilities());
    TS_ASSERT(!info.has_queue_properties());
    TS_ASSERT(!info.has_name());
    TS_ASSERT(!info.has_vendor());
    TS_ASSERT(!info.has_driver_version());
    TS_ASSERT(!info.has_profile());
    TS_ASSERT(!info.has_version());
    TS_ASSERT(!info.has_extensions());
    TS_ASSERT(!info.has_platform_id());
    TS_ASSERT(!info.has_double_fp_config());
    TS_ASSERT(!info.has_preferred_vector_width_half());
    TS_ASSERT(!info.has_host_unified_memory());
    TS_ASSERT(!info.has_native_vector_width_char());
    TS_ASSERT(!info.has_native_vector_width_short());
    TS_ASSERT(!info.has_native_vector_width_int());
    TS_ASSERT(!info.has_native_vector_width_long());
    TS_ASSERT(!info.has_native_vector_width_float());
    TS_ASSERT(!info.has_native_vector_width_double());
    TS_ASSERT(!info.has_native_vector_width_half());
    TS_ASSERT(!info.has_opencl_c_version());
    TS_ASSERT(!info.has_linker_available());
    TS_ASSERT(!info.has_built_in_kernels());
    TS_ASSERT(!info.has_image_max_buffer_size());
    TS_ASSERT(!info.has_image_max_array_size());
    TS_ASSERT(!info.has_parent_device_id());
    TS_ASSERT(!info.has_partition_max_sub_devices());
    TS_ASSERT(!info.has_partition_properties());
    TS_ASSERT(!info.has_partition_affinity_domain());
    TS_ASSERT(!info.has_partition_type());
    TS_ASSERT(!info.has_reference_count());
    TS_ASSERT(!info.has_preferred_interop_user_sync());
    TS_ASSERT(!info.has_printf_buffer_size());
    TS_ASSERT(!info.has_image_pitch_alignment());
    TS_ASSERT(!info.has_image_base_address_alignment());
  }
  /** // doc: test_clear_dont_has_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear_dont_has_2( )
  {
    device_info info(device_info_fixtures::_1());

    TS_ASSERT(!info.clear_id().has_id());
    TS_ASSERT(!info.clear_type().has_type());
    TS_ASSERT(!info.clear_vendor_id().has_vendor_id());
    TS_ASSERT(!info.clear_max_compute_units().has_max_compute_units());
    TS_ASSERT(!info.clear_max_work_item_dimensions().has_max_work_item_dimensions());
    TS_ASSERT(!info.clear_max_work_group_size().has_max_work_group_size());
    TS_ASSERT(!info.clear_max_work_item_sizes().has_max_work_item_sizes());
    TS_ASSERT(!info.clear_preferred_vector_width_char().has_preferred_vector_width_char());
    TS_ASSERT(!info.clear_preferred_vector_width_short().has_preferred_vector_width_short());
    TS_ASSERT(!info.clear_preferred_vector_width_int().has_preferred_vector_width_int());
    TS_ASSERT(!info.clear_preferred_vector_width_long().has_preferred_vector_width_long());
    TS_ASSERT(!info.clear_preferred_vector_width_float().has_preferred_vector_width_float());
    TS_ASSERT(!info.clear_preferred_vector_width_double().has_preferred_vector_width_double());
    TS_ASSERT(!info.clear_max_clock_frequency().has_max_clock_frequency());
    TS_ASSERT(!info.clear_address_bits().has_address_bits());
    TS_ASSERT(!info.clear_max_read_image_args().has_max_read_image_args());
    TS_ASSERT(!info.clear_max_write_image_args().has_max_write_image_args());
    TS_ASSERT(!info.clear_max_mem_alloc_size().has_max_mem_alloc_size());
    TS_ASSERT(!info.clear_image2d_max_width().has_image2d_max_width());
    TS_ASSERT(!info.clear_image2d_max_height().has_image2d_max_height());
    TS_ASSERT(!info.clear_image3d_max_width().has_image3d_max_width());
    TS_ASSERT(!info.clear_image3d_max_height().has_image3d_max_height());
    TS_ASSERT(!info.clear_image3d_max_depth().has_image3d_max_depth());
    TS_ASSERT(!info.clear_image_support().has_image_support());
    TS_ASSERT(!info.clear_max_parameter_size().has_max_parameter_size());
    TS_ASSERT(!info.clear_max_samplers().has_max_samplers());
    TS_ASSERT(!info.clear_mem_base_addr_align().has_mem_base_addr_align());
    TS_ASSERT(!info.clear_min_data_type_align_size().has_min_data_type_align_size());
    TS_ASSERT(!info.clear_single_fp_config().has_single_fp_config());
    TS_ASSERT(!info.clear_global_mem_cache_type().has_global_mem_cache_type());
    TS_ASSERT(!info.clear_global_mem_cacheline_size().has_global_mem_cacheline_size());
    TS_ASSERT(!info.clear_global_mem_cache_size().has_global_mem_cache_size());
    TS_ASSERT(!info.clear_global_mem_size().has_global_mem_size());
    TS_ASSERT(!info.clear_max_constant_buffer_size().has_max_constant_buffer_size());
    TS_ASSERT(!info.clear_max_constant_args().has_max_constant_args());
    TS_ASSERT(!info.clear_local_mem_type().has_local_mem_type());
    TS_ASSERT(!info.clear_local_mem_size().has_local_mem_size());
    TS_ASSERT(!info.clear_error_correction_support().has_error_correction_support());
    TS_ASSERT(!info.clear_profiling_timer_resolution().has_profiling_timer_resolution());
    TS_ASSERT(!info.clear_endian_little().has_endian_little());
    TS_ASSERT(!info.clear_available().has_available());
    TS_ASSERT(!info.clear_compiler_available().has_compiler_available());
    TS_ASSERT(!info.clear_execution_capabilities().has_execution_capabilities());
    TS_ASSERT(!info.clear_queue_properties().has_queue_properties());
    TS_ASSERT(!info.clear_name().has_name());
    TS_ASSERT(!info.clear_vendor().has_vendor());
    TS_ASSERT(!info.clear_driver_version().has_driver_version());
    TS_ASSERT(!info.clear_profile().has_profile());
    TS_ASSERT(!info.clear_version().has_version());
    TS_ASSERT(!info.clear_extensions().has_extensions());
    TS_ASSERT(!info.clear_platform_id().has_platform_id());
    TS_ASSERT(!info.clear_double_fp_config().has_double_fp_config());
    TS_ASSERT(!info.clear_preferred_vector_width_half().has_preferred_vector_width_half());
    TS_ASSERT(!info.clear_host_unified_memory().has_host_unified_memory());
    TS_ASSERT(!info.clear_native_vector_width_char().has_native_vector_width_char());
    TS_ASSERT(!info.clear_native_vector_width_short().has_native_vector_width_short());
    TS_ASSERT(!info.clear_native_vector_width_int().has_native_vector_width_int());
    TS_ASSERT(!info.clear_native_vector_width_long().has_native_vector_width_long());
    TS_ASSERT(!info.clear_native_vector_width_float().has_native_vector_width_float());
    TS_ASSERT(!info.clear_native_vector_width_double().has_native_vector_width_double());
    TS_ASSERT(!info.clear_native_vector_width_half().has_native_vector_width_half());
    TS_ASSERT(!info.clear_opencl_c_version().has_opencl_c_version());
    TS_ASSERT(!info.clear_linker_available().has_linker_available());
    TS_ASSERT(!info.clear_built_in_kernels().has_built_in_kernels());
    TS_ASSERT(!info.clear_image_max_buffer_size().has_image_max_buffer_size());
    TS_ASSERT(!info.clear_image_max_array_size().has_image_max_array_size());
    TS_ASSERT(!info.clear_parent_device_id().has_parent_device_id());
    TS_ASSERT(!info.clear_partition_max_sub_devices().has_partition_max_sub_devices());
    TS_ASSERT(!info.clear_partition_properties().has_partition_properties());
    TS_ASSERT(!info.clear_partition_affinity_domain().has_partition_affinity_domain());
    TS_ASSERT(!info.clear_partition_type().has_partition_type());
    TS_ASSERT(!info.clear_reference_count().has_reference_count());
    TS_ASSERT(!info.clear_preferred_interop_user_sync().has_preferred_interop_user_sync());
    TS_ASSERT(!info.clear_printf_buffer_size().has_printf_buffer_size());
    TS_ASSERT(!info.clear_image_pitch_alignment().has_image_pitch_alignment());
    TS_ASSERT(!info.clear_image_base_address_alignment().has_image_base_address_alignment());
  }
  /** // doc: test_eq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_1()
  {
    TS_ASSERT((device_info() == device_info()));
  }
  /** // doc: test_eq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_2()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    device_partition_property_t partition_properties1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_type1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };

    // Note, we test separately each attribute
    TS_ASSERT(!(device_info().set_id(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_type(device_type_t::cpu) == device_info()));
    TS_ASSERT(!(device_info().set_vendor_id(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_compute_units(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_work_item_dimensions(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_work_group_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_vector_width_char(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_vector_width_short(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_vector_width_int(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_vector_width_long(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_vector_width_float(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_vector_width_double(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_clock_frequency(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_address_bits(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_read_image_args(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_write_image_args(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_mem_alloc_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image2d_max_width(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image2d_max_height(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image3d_max_width(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image3d_max_height(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image3d_max_depth(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image_support(0) == device_info()));
    TS_ASSERT(!(device_info().set_max_parameter_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_max_samplers(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_mem_base_addr_align(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_min_data_type_align_size(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_single_fp_config(device_fp_config_t::denorm) == device_info()));
    TS_ASSERT(!(device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache) == device_info()));
    TS_ASSERT(!(device_info().set_global_mem_cacheline_size(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_global_mem_cache_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_global_mem_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_max_constant_buffer_size(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_max_constant_args(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_local_mem_type(device_local_mem_type_t::local) == device_info()));
    TS_ASSERT(!(device_info().set_local_mem_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_error_correction_support(0) == device_info()));
    TS_ASSERT(!(device_info().set_profiling_timer_resolution(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_endian_little(0) == device_info()));
    TS_ASSERT(!(device_info().set_available(0) == device_info()));
    TS_ASSERT(!(device_info().set_compiler_available(0) == device_info()));
    TS_ASSERT(!(device_info().set_execution_capabilities(device_exec_capabilities_t::kernel) == device_info()));
    TS_ASSERT(!(device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable) == device_info()));
    TS_ASSERT(!(device_info().set_name("_name") == device_info()));
    TS_ASSERT(!(device_info().set_vendor("_vendor") == device_info()));
    TS_ASSERT(!(device_info().set_driver_version("_driver_version") == device_info()));
    TS_ASSERT(!(device_info().set_profile("_profile") == device_info()));
    TS_ASSERT(!(device_info().set_version("_version") == device_info()));
    TS_ASSERT(!(device_info().set_extensions("_extensions") == device_info()));
    TS_ASSERT(!(device_info().set_platform_id(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_double_fp_config(device_fp_config_t::denorm) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_vector_width_half(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_host_unified_memory(0) == device_info()));
    TS_ASSERT(!(device_info().set_native_vector_width_char(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_native_vector_width_short(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_native_vector_width_int(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_native_vector_width_long(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_native_vector_width_float(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_native_vector_width_double(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_native_vector_width_half(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_opencl_c_version("_opencl_c_version") == device_info()));
    TS_ASSERT(!(device_info().set_linker_available(0) == device_info()));
    TS_ASSERT(!(device_info().set_built_in_kernels("_built_in_kernels") == device_info()));
    TS_ASSERT(!(device_info().set_image_max_buffer_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image_max_array_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_parent_device_id(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_partition_max_sub_devices(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2)) == device_info()));
    TS_ASSERT(!(device_info().set_partition_affinity_domain(device_affinity_domain_t::numa) == device_info()));
    TS_ASSERT(!(device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2)) == device_info()));
    TS_ASSERT(!(device_info().set_reference_count(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_preferred_interop_user_sync(0) == device_info()));
    TS_ASSERT(!(device_info().set_printf_buffer_size(0x1234ul) == device_info()));
    TS_ASSERT(!(device_info().set_image_pitch_alignment(0x1234u) == device_info()));
    TS_ASSERT(!(device_info().set_image_base_address_alignment(0x1234u) == device_info()));
  }
  /** // doc: test_eq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_3()
  {
    TS_ASSERT(!(device_info_fixtures::_1() == device_info_fixtures::_2()));
  }
  /** // doc: test_eq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_eq_op_4()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    device_partition_property_t partition_properties1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_type1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };

    TS_ASSERT((device_info().set_id(0x1234ul) == device_info().set_id(0x1234ul)));
    TS_ASSERT((device_info().set_type(device_type_t::cpu) == device_info().set_type(device_type_t::cpu)));
    TS_ASSERT((device_info().set_vendor_id(0x1234u) == device_info().set_vendor_id(0x1234u)));
    TS_ASSERT((device_info().set_max_compute_units(0x1234u) == device_info().set_max_compute_units(0x1234u)));
    TS_ASSERT((device_info().set_max_work_item_dimensions(0x1234u) == device_info().set_max_work_item_dimensions(0x1234u)));
    TS_ASSERT((device_info().set_max_work_group_size(0x1234ul) == device_info().set_max_work_group_size(0x1234ul)));
    TS_ASSERT((device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) == device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3))));
    TS_ASSERT((device_info().set_preferred_vector_width_char(0x1234u) == device_info().set_preferred_vector_width_char(0x1234u)));
    TS_ASSERT((device_info().set_preferred_vector_width_short(0x1234u) == device_info().set_preferred_vector_width_short(0x1234u)));
    TS_ASSERT((device_info().set_preferred_vector_width_int(0x1234u) == device_info().set_preferred_vector_width_int(0x1234u)));
    TS_ASSERT((device_info().set_preferred_vector_width_long(0x1234u) == device_info().set_preferred_vector_width_long(0x1234u)));
    TS_ASSERT((device_info().set_preferred_vector_width_float(0x1234u) == device_info().set_preferred_vector_width_float(0x1234u)));
    TS_ASSERT((device_info().set_preferred_vector_width_double(0x1234u) == device_info().set_preferred_vector_width_double(0x1234u)));
    TS_ASSERT((device_info().set_max_clock_frequency(0x1234u) == device_info().set_max_clock_frequency(0x1234u)));
    TS_ASSERT((device_info().set_address_bits(0x1234u) == device_info().set_address_bits(0x1234u)));
    TS_ASSERT((device_info().set_max_read_image_args(0x1234u) == device_info().set_max_read_image_args(0x1234u)));
    TS_ASSERT((device_info().set_max_write_image_args(0x1234u) == device_info().set_max_write_image_args(0x1234u)));
    TS_ASSERT((device_info().set_max_mem_alloc_size(0x1234ul) == device_info().set_max_mem_alloc_size(0x1234ul)));
    TS_ASSERT((device_info().set_image2d_max_width(0x1234ul) == device_info().set_image2d_max_width(0x1234ul)));
    TS_ASSERT((device_info().set_image2d_max_height(0x1234ul) == device_info().set_image2d_max_height(0x1234ul)));
    TS_ASSERT((device_info().set_image3d_max_width(0x1234ul) == device_info().set_image3d_max_width(0x1234ul)));
    TS_ASSERT((device_info().set_image3d_max_height(0x1234ul) == device_info().set_image3d_max_height(0x1234ul)));
    TS_ASSERT((device_info().set_image3d_max_depth(0x1234ul) == device_info().set_image3d_max_depth(0x1234ul)));
    TS_ASSERT((device_info().set_image_support(0) == device_info().set_image_support(0)));
    TS_ASSERT((device_info().set_max_parameter_size(0x1234ul) == device_info().set_max_parameter_size(0x1234ul)));
    TS_ASSERT((device_info().set_max_samplers(0x1234u) == device_info().set_max_samplers(0x1234u)));
    TS_ASSERT((device_info().set_mem_base_addr_align(0x1234u) == device_info().set_mem_base_addr_align(0x1234u)));
    TS_ASSERT((device_info().set_min_data_type_align_size(0x1234u) == device_info().set_min_data_type_align_size(0x1234u)));
    TS_ASSERT((device_info().set_single_fp_config(device_fp_config_t::denorm) == device_info().set_single_fp_config(device_fp_config_t::denorm)));
    TS_ASSERT((device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache) == device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache)));
    TS_ASSERT((device_info().set_global_mem_cacheline_size(0x1234u) == device_info().set_global_mem_cacheline_size(0x1234u)));
    TS_ASSERT((device_info().set_global_mem_cache_size(0x1234ul) == device_info().set_global_mem_cache_size(0x1234ul)));
    TS_ASSERT((device_info().set_global_mem_size(0x1234ul) == device_info().set_global_mem_size(0x1234ul)));
    TS_ASSERT((device_info().set_max_constant_buffer_size(0x1234u) == device_info().set_max_constant_buffer_size(0x1234u)));
    TS_ASSERT((device_info().set_max_constant_args(0x1234u) == device_info().set_max_constant_args(0x1234u)));
    TS_ASSERT((device_info().set_local_mem_type(device_local_mem_type_t::local) == device_info().set_local_mem_type(device_local_mem_type_t::local)));
    TS_ASSERT((device_info().set_local_mem_size(0x1234ul) == device_info().set_local_mem_size(0x1234ul)));
    TS_ASSERT((device_info().set_error_correction_support(0) == device_info().set_error_correction_support(0)));
    TS_ASSERT((device_info().set_profiling_timer_resolution(0x1234ul) == device_info().set_profiling_timer_resolution(0x1234ul)));
    TS_ASSERT((device_info().set_endian_little(0) == device_info().set_endian_little(0)));
    TS_ASSERT((device_info().set_available(0) == device_info().set_available(0)));
    TS_ASSERT((device_info().set_compiler_available(0) == device_info().set_compiler_available(0)));
    TS_ASSERT((device_info().set_execution_capabilities(device_exec_capabilities_t::kernel) == device_info().set_execution_capabilities(device_exec_capabilities_t::kernel)));
    TS_ASSERT((device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable) == device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable)));
    TS_ASSERT((device_info().set_name("_name") == device_info().set_name("_name")));
    TS_ASSERT((device_info().set_vendor("_vendor") == device_info().set_vendor("_vendor")));
    TS_ASSERT((device_info().set_driver_version("_driver_version") == device_info().set_driver_version("_driver_version")));
    TS_ASSERT((device_info().set_profile("_profile") == device_info().set_profile("_profile")));
    TS_ASSERT((device_info().set_version("_version") == device_info().set_version("_version")));
    TS_ASSERT((device_info().set_extensions("_extensions") == device_info().set_extensions("_extensions")));
    TS_ASSERT((device_info().set_platform_id(0x1234ul) == device_info().set_platform_id(0x1234ul)));
    TS_ASSERT((device_info().set_double_fp_config(device_fp_config_t::denorm) == device_info().set_double_fp_config(device_fp_config_t::denorm)));
    TS_ASSERT((device_info().set_preferred_vector_width_half(0x1234u) == device_info().set_preferred_vector_width_half(0x1234u)));
    TS_ASSERT((device_info().set_host_unified_memory(0) == device_info().set_host_unified_memory(0)));
    TS_ASSERT((device_info().set_native_vector_width_char(0x1234u) == device_info().set_native_vector_width_char(0x1234u)));
    TS_ASSERT((device_info().set_native_vector_width_short(0x1234u) == device_info().set_native_vector_width_short(0x1234u)));
    TS_ASSERT((device_info().set_native_vector_width_int(0x1234u) == device_info().set_native_vector_width_int(0x1234u)));
    TS_ASSERT((device_info().set_native_vector_width_long(0x1234u) == device_info().set_native_vector_width_long(0x1234u)));
    TS_ASSERT((device_info().set_native_vector_width_float(0x1234u) == device_info().set_native_vector_width_float(0x1234u)));
    TS_ASSERT((device_info().set_native_vector_width_double(0x1234u) == device_info().set_native_vector_width_double(0x1234u)));
    TS_ASSERT((device_info().set_native_vector_width_half(0x1234u) == device_info().set_native_vector_width_half(0x1234u)));
    TS_ASSERT((device_info().set_opencl_c_version("_opencl_c_version") == device_info().set_opencl_c_version("_opencl_c_version")));
    TS_ASSERT((device_info().set_linker_available(0) == device_info().set_linker_available(0)));
    TS_ASSERT((device_info().set_built_in_kernels("_built_in_kernels") == device_info().set_built_in_kernels("_built_in_kernels")));
    TS_ASSERT((device_info().set_image_max_buffer_size(0x1234ul) == device_info().set_image_max_buffer_size(0x1234ul)));
    TS_ASSERT((device_info().set_image_max_array_size(0x1234ul) == device_info().set_image_max_array_size(0x1234ul)));
    TS_ASSERT((device_info().set_parent_device_id(0x1234ul) == device_info().set_parent_device_id(0x1234ul)));
    TS_ASSERT((device_info().set_partition_max_sub_devices(0x1234u) == device_info().set_partition_max_sub_devices(0x1234u)));
    TS_ASSERT((device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2)) == device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2))));
    TS_ASSERT((device_info().set_partition_affinity_domain(device_affinity_domain_t::numa) == device_info().set_partition_affinity_domain(device_affinity_domain_t::numa)));
    TS_ASSERT((device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2)) == device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2))));
    TS_ASSERT((device_info().set_reference_count(0x1234u) == device_info().set_reference_count(0x1234u)));
    TS_ASSERT((device_info().set_preferred_interop_user_sync(0) == device_info().set_preferred_interop_user_sync(0)));
    TS_ASSERT((device_info().set_printf_buffer_size(0x1234ul) == device_info().set_printf_buffer_size(0x1234ul)));
    TS_ASSERT((device_info().set_image_pitch_alignment(0x1234u) == device_info().set_image_pitch_alignment(0x1234u)));
    TS_ASSERT((device_info().set_image_base_address_alignment(0x1234u) == device_info().set_image_base_address_alignment(0x1234u)));
  }
  /** // doc: test_neq_op_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_1()
  {
    TS_ASSERT(!(device_info() != device_info()));
  }
  /** // doc: test_neq_op_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_2()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    device_partition_property_t partition_properties1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_type1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };

    TS_ASSERT((device_info().set_id(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_type(device_type_t::cpu) != device_info()));
    TS_ASSERT((device_info().set_vendor_id(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_compute_units(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_work_item_dimensions(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_work_group_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) != device_info()));
    TS_ASSERT((device_info().set_preferred_vector_width_char(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_preferred_vector_width_short(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_preferred_vector_width_int(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_preferred_vector_width_long(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_preferred_vector_width_float(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_preferred_vector_width_double(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_clock_frequency(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_address_bits(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_read_image_args(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_write_image_args(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_mem_alloc_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image2d_max_width(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image2d_max_height(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image3d_max_width(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image3d_max_height(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image3d_max_depth(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image_support(0) != device_info()));
    TS_ASSERT((device_info().set_max_parameter_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_max_samplers(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_mem_base_addr_align(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_min_data_type_align_size(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_single_fp_config(device_fp_config_t::denorm) != device_info()));
    TS_ASSERT((device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache) != device_info()));
    TS_ASSERT((device_info().set_global_mem_cacheline_size(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_global_mem_cache_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_global_mem_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_max_constant_buffer_size(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_max_constant_args(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_local_mem_type(device_local_mem_type_t::local) != device_info()));
    TS_ASSERT((device_info().set_local_mem_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_error_correction_support(0) != device_info()));
    TS_ASSERT((device_info().set_profiling_timer_resolution(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_endian_little(0) != device_info()));
    TS_ASSERT((device_info().set_available(0) != device_info()));
    TS_ASSERT((device_info().set_compiler_available(0) != device_info()));
    TS_ASSERT((device_info().set_execution_capabilities(device_exec_capabilities_t::kernel) != device_info()));
    TS_ASSERT((device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable) != device_info()));
    TS_ASSERT((device_info().set_name("_name") != device_info()));
    TS_ASSERT((device_info().set_vendor("_vendor") != device_info()));
    TS_ASSERT((device_info().set_driver_version("_driver_version") != device_info()));
    TS_ASSERT((device_info().set_profile("_profile") != device_info()));
    TS_ASSERT((device_info().set_version("_version") != device_info()));
    TS_ASSERT((device_info().set_extensions("_extensions") != device_info()));
    TS_ASSERT((device_info().set_platform_id(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_double_fp_config(device_fp_config_t::denorm) != device_info()));
    TS_ASSERT((device_info().set_preferred_vector_width_half(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_host_unified_memory(0) != device_info()));
    TS_ASSERT((device_info().set_native_vector_width_char(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_native_vector_width_short(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_native_vector_width_int(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_native_vector_width_long(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_native_vector_width_float(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_native_vector_width_double(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_native_vector_width_half(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_opencl_c_version("_opencl_c_version") != device_info()));
    TS_ASSERT((device_info().set_linker_available(0) != device_info()));
    TS_ASSERT((device_info().set_built_in_kernels("_built_in_kernels") != device_info()));
    TS_ASSERT((device_info().set_image_max_buffer_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image_max_array_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_parent_device_id(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_partition_max_sub_devices(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2)) != device_info()));
    TS_ASSERT((device_info().set_partition_affinity_domain(device_affinity_domain_t::numa) != device_info()));
    TS_ASSERT((device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2)) != device_info()));
    TS_ASSERT((device_info().set_reference_count(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_preferred_interop_user_sync(0) != device_info()));
    TS_ASSERT((device_info().set_printf_buffer_size(0x1234ul) != device_info()));
    TS_ASSERT((device_info().set_image_pitch_alignment(0x1234u) != device_info()));
    TS_ASSERT((device_info().set_image_base_address_alignment(0x1234u) != device_info()));
  }
  /** // doc: test_neq_op_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_3()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    size_t max_work_item_sizes2[3] = { 3, 2, 1 };
    device_partition_property_t partition_properties1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_properties2[2] = {
      device_partition_property_t::by_affinity_domain,
      device_partition_property_t::by_counts
    };
    device_partition_property_t partition_type1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_type2[2] = {
      device_partition_property_t::by_affinity_domain,
      device_partition_property_t::by_counts
    };

    TS_ASSERT((device_info().set_id(0x1234ul) != device_info().set_id(0x4321ul)));
    TS_ASSERT((device_info().set_type(device_type_t::cpu) != device_info().set_type(device_type_t::gpu)));
    TS_ASSERT((device_info().set_vendor_id(0x1234u) != device_info().set_vendor_id(0x4321u)));
    TS_ASSERT((device_info().set_max_compute_units(0x1234u) != device_info().set_max_compute_units(0x4321u)));
    TS_ASSERT((device_info().set_max_work_item_dimensions(0x1234u) != device_info().set_max_work_item_dimensions(0x4321u)));
    TS_ASSERT((device_info().set_max_work_group_size(0x1234ul) != device_info().set_max_work_group_size(0x4321ul)));
    TS_ASSERT((device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) != device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes2,max_work_item_sizes2+3))));
    TS_ASSERT((device_info().set_preferred_vector_width_char(0x1234u) != device_info().set_preferred_vector_width_char(0x4321u)));
    TS_ASSERT((device_info().set_preferred_vector_width_short(0x1234u) != device_info().set_preferred_vector_width_short(0x4321u)));
    TS_ASSERT((device_info().set_preferred_vector_width_int(0x1234u) != device_info().set_preferred_vector_width_int(0x4321u)));
    TS_ASSERT((device_info().set_preferred_vector_width_long(0x1234u) != device_info().set_preferred_vector_width_long(0x4321u)));
    TS_ASSERT((device_info().set_preferred_vector_width_float(0x1234u) != device_info().set_preferred_vector_width_float(0x4321u)));
    TS_ASSERT((device_info().set_preferred_vector_width_double(0x1234u) != device_info().set_preferred_vector_width_double(0x4321u)));
    TS_ASSERT((device_info().set_max_clock_frequency(0x1234u) != device_info().set_max_clock_frequency(0x4321u)));
    TS_ASSERT((device_info().set_address_bits(0x1234u) != device_info().set_address_bits(0x4321u)));
    TS_ASSERT((device_info().set_max_read_image_args(0x1234u) != device_info().set_max_read_image_args(0x4321u)));
    TS_ASSERT((device_info().set_max_write_image_args(0x1234u) != device_info().set_max_write_image_args(0x4321u)));
    TS_ASSERT((device_info().set_max_mem_alloc_size(0x1234ul) != device_info().set_max_mem_alloc_size(0x4321ul)));
    TS_ASSERT((device_info().set_image2d_max_width(0x1234ul) != device_info().set_image2d_max_width(0x4321ul)));
    TS_ASSERT((device_info().set_image2d_max_height(0x1234ul) != device_info().set_image2d_max_height(0x4321ul)));
    TS_ASSERT((device_info().set_image3d_max_width(0x1234ul) != device_info().set_image3d_max_width(0x4321ul)));
    TS_ASSERT((device_info().set_image3d_max_height(0x1234ul) != device_info().set_image3d_max_height(0x4321ul)));
    TS_ASSERT((device_info().set_image3d_max_depth(0x1234ul) != device_info().set_image3d_max_depth(0x4321ul)));
    TS_ASSERT((device_info().set_image_support(0) != device_info().set_image_support(1)));
    TS_ASSERT((device_info().set_max_parameter_size(0x1234ul) != device_info().set_max_parameter_size(0x4321ul)));
    TS_ASSERT((device_info().set_max_samplers(0x1234u) != device_info().set_max_samplers(0x4321u)));
    TS_ASSERT((device_info().set_mem_base_addr_align(0x1234u) != device_info().set_mem_base_addr_align(0x4321u)));
    TS_ASSERT((device_info().set_min_data_type_align_size(0x1234u) != device_info().set_min_data_type_align_size(0x4321u)));
    TS_ASSERT((device_info().set_single_fp_config(device_fp_config_t::denorm) != device_info().set_single_fp_config(device_fp_config_t::inf_nan)));
    TS_ASSERT((device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache) != device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_write_cache)));
    TS_ASSERT((device_info().set_global_mem_cacheline_size(0x1234u) != device_info().set_global_mem_cacheline_size(0x4321u)));
    TS_ASSERT((device_info().set_global_mem_cache_size(0x1234ul) != device_info().set_global_mem_cache_size(0x4321ul)));
    TS_ASSERT((device_info().set_global_mem_size(0x1234ul) != device_info().set_global_mem_size(0x4321ul)));
    TS_ASSERT((device_info().set_max_constant_buffer_size(0x1234u) != device_info().set_max_constant_buffer_size(0x4321u)));
    TS_ASSERT((device_info().set_max_constant_args(0x1234u) != device_info().set_max_constant_args(0x4321u)));
    TS_ASSERT((device_info().set_local_mem_type(device_local_mem_type_t::local) != device_info().set_local_mem_type(device_local_mem_type_t::global)));
    TS_ASSERT((device_info().set_local_mem_size(0x1234ul) != device_info().set_local_mem_size(0x4321ul)));
    TS_ASSERT((device_info().set_error_correction_support(0) != device_info().set_error_correction_support(1)));
    TS_ASSERT((device_info().set_profiling_timer_resolution(0x1234ul) != device_info().set_profiling_timer_resolution(0x4321ul)));
    TS_ASSERT((device_info().set_endian_little(0) != device_info().set_endian_little(1)));
    TS_ASSERT((device_info().set_available(0) != device_info().set_available(1)));
    TS_ASSERT((device_info().set_compiler_available(0) != device_info().set_compiler_available(1)));
    TS_ASSERT((device_info().set_execution_capabilities(device_exec_capabilities_t::kernel) != device_info().set_execution_capabilities(device_exec_capabilities_t::native_kernel)));
    TS_ASSERT((device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable) != device_info().set_queue_properties(command_queue_properties_t::profiling_enable)));
    TS_ASSERT((device_info().set_name("_name") != device_info().set_name("x_namex")));
    TS_ASSERT((device_info().set_vendor("_vendor") != device_info().set_vendor("x_vendorx")));
    TS_ASSERT((device_info().set_driver_version("_driver_version") != device_info().set_driver_version("x_driver_versionx")));
    TS_ASSERT((device_info().set_profile("_profile") != device_info().set_profile("x_profilex")));
    TS_ASSERT((device_info().set_version("_version") != device_info().set_version("x_versionx")));
    TS_ASSERT((device_info().set_extensions("_extensions") != device_info().set_extensions("x_extensionsx")));
    TS_ASSERT((device_info().set_platform_id(0x1234ul) != device_info().set_platform_id(0x4321ul)));
    TS_ASSERT((device_info().set_double_fp_config(device_fp_config_t::denorm) != device_info().set_double_fp_config(device_fp_config_t::inf_nan)));
    TS_ASSERT((device_info().set_preferred_vector_width_half(0x1234u) != device_info().set_preferred_vector_width_half(0x4321u)));
    TS_ASSERT((device_info().set_host_unified_memory(0) != device_info().set_host_unified_memory(1)));
    TS_ASSERT((device_info().set_native_vector_width_char(0x1234u) != device_info().set_native_vector_width_char(0x4321u)));
    TS_ASSERT((device_info().set_native_vector_width_short(0x1234u) != device_info().set_native_vector_width_short(0x4321u)));
    TS_ASSERT((device_info().set_native_vector_width_int(0x1234u) != device_info().set_native_vector_width_int(0x4321u)));
    TS_ASSERT((device_info().set_native_vector_width_long(0x1234u) != device_info().set_native_vector_width_long(0x4321u)));
    TS_ASSERT((device_info().set_native_vector_width_float(0x1234u) != device_info().set_native_vector_width_float(0x4321u)));
    TS_ASSERT((device_info().set_native_vector_width_double(0x1234u) != device_info().set_native_vector_width_double(0x4321u)));
    TS_ASSERT((device_info().set_native_vector_width_half(0x1234u) != device_info().set_native_vector_width_half(0x4321u)));
    TS_ASSERT((device_info().set_opencl_c_version("_opencl_c_version") != device_info().set_opencl_c_version("x_opencl_c_versionx")));
    TS_ASSERT((device_info().set_linker_available(0) != device_info().set_linker_available(1)));
    TS_ASSERT((device_info().set_built_in_kernels("_built_in_kernels") != device_info().set_built_in_kernels("x_built_in_kernelsx")));
    TS_ASSERT((device_info().set_image_max_buffer_size(0x1234ul) != device_info().set_image_max_buffer_size(0x4321ul)));
    TS_ASSERT((device_info().set_image_max_array_size(0x1234ul) != device_info().set_image_max_array_size(0x4321ul)));
    TS_ASSERT((device_info().set_parent_device_id(0x1234ul) != device_info().set_parent_device_id(0x4321ul)));
    TS_ASSERT((device_info().set_partition_max_sub_devices(0x1234u) != device_info().set_partition_max_sub_devices(0x4321u)));
    TS_ASSERT((device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2)) != device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties2,partition_properties2+2))));
    TS_ASSERT((device_info().set_partition_affinity_domain(device_affinity_domain_t::numa) != device_info().set_partition_affinity_domain(device_affinity_domain_t::l2_cache)));
    TS_ASSERT((device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2)) != device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type2,partition_type2+2))));
    TS_ASSERT((device_info().set_reference_count(0x1234u) != device_info().set_reference_count(0x4321u)));
    TS_ASSERT((device_info().set_preferred_interop_user_sync(0) != device_info().set_preferred_interop_user_sync(1)));
    TS_ASSERT((device_info().set_printf_buffer_size(0x1234ul) != device_info().set_printf_buffer_size(0x4321ul)));
    TS_ASSERT((device_info().set_image_pitch_alignment(0x1234u) != device_info().set_image_pitch_alignment(0x4321u)));
    TS_ASSERT((device_info().set_image_base_address_alignment(0x1234u) != device_info().set_image_base_address_alignment(0x4321u)));
  }
  /** // doc: test_neq_op_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_neq_op_4()
  {
    size_t max_work_item_sizes1[3] = { 1, 2, 3 };
    device_partition_property_t partition_properties1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };
    device_partition_property_t partition_type1[2] = {
      device_partition_property_t::by_counts,
      device_partition_property_t::by_affinity_domain
    };

    TS_ASSERT(!(device_info().set_id(0x1234ul) != device_info().set_id(0x1234ul)));
    TS_ASSERT(!(device_info().set_type(device_type_t::cpu) != device_info().set_type(device_type_t::cpu)));
    TS_ASSERT(!(device_info().set_vendor_id(0x1234u) != device_info().set_vendor_id(0x1234u)));
    TS_ASSERT(!(device_info().set_max_compute_units(0x1234u) != device_info().set_max_compute_units(0x1234u)));
    TS_ASSERT(!(device_info().set_max_work_item_dimensions(0x1234u) != device_info().set_max_work_item_dimensions(0x1234u)));
    TS_ASSERT(!(device_info().set_max_work_group_size(0x1234ul) != device_info().set_max_work_group_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3)) != device_info().set_max_work_item_sizes(std::vector<size_t>(max_work_item_sizes1,max_work_item_sizes1+3))));
    TS_ASSERT(!(device_info().set_preferred_vector_width_char(0x1234u) != device_info().set_preferred_vector_width_char(0x1234u)));
    TS_ASSERT(!(device_info().set_preferred_vector_width_short(0x1234u) != device_info().set_preferred_vector_width_short(0x1234u)));
    TS_ASSERT(!(device_info().set_preferred_vector_width_int(0x1234u) != device_info().set_preferred_vector_width_int(0x1234u)));
    TS_ASSERT(!(device_info().set_preferred_vector_width_long(0x1234u) != device_info().set_preferred_vector_width_long(0x1234u)));
    TS_ASSERT(!(device_info().set_preferred_vector_width_float(0x1234u) != device_info().set_preferred_vector_width_float(0x1234u)));
    TS_ASSERT(!(device_info().set_preferred_vector_width_double(0x1234u) != device_info().set_preferred_vector_width_double(0x1234u)));
    TS_ASSERT(!(device_info().set_max_clock_frequency(0x1234u) != device_info().set_max_clock_frequency(0x1234u)));
    TS_ASSERT(!(device_info().set_address_bits(0x1234u) != device_info().set_address_bits(0x1234u)));
    TS_ASSERT(!(device_info().set_max_read_image_args(0x1234u) != device_info().set_max_read_image_args(0x1234u)));
    TS_ASSERT(!(device_info().set_max_write_image_args(0x1234u) != device_info().set_max_write_image_args(0x1234u)));
    TS_ASSERT(!(device_info().set_max_mem_alloc_size(0x1234ul) != device_info().set_max_mem_alloc_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_image2d_max_width(0x1234ul) != device_info().set_image2d_max_width(0x1234ul)));
    TS_ASSERT(!(device_info().set_image2d_max_height(0x1234ul) != device_info().set_image2d_max_height(0x1234ul)));
    TS_ASSERT(!(device_info().set_image3d_max_width(0x1234ul) != device_info().set_image3d_max_width(0x1234ul)));
    TS_ASSERT(!(device_info().set_image3d_max_height(0x1234ul) != device_info().set_image3d_max_height(0x1234ul)));
    TS_ASSERT(!(device_info().set_image3d_max_depth(0x1234ul) != device_info().set_image3d_max_depth(0x1234ul)));
    TS_ASSERT(!(device_info().set_image_support(0) != device_info().set_image_support(0)));
    TS_ASSERT(!(device_info().set_max_parameter_size(0x1234ul) != device_info().set_max_parameter_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_max_samplers(0x1234u) != device_info().set_max_samplers(0x1234u)));
    TS_ASSERT(!(device_info().set_mem_base_addr_align(0x1234u) != device_info().set_mem_base_addr_align(0x1234u)));
    TS_ASSERT(!(device_info().set_min_data_type_align_size(0x1234u) != device_info().set_min_data_type_align_size(0x1234u)));
    TS_ASSERT(!(device_info().set_single_fp_config(device_fp_config_t::denorm) != device_info().set_single_fp_config(device_fp_config_t::denorm)));
    TS_ASSERT(!(device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache) != device_info().set_global_mem_cache_type(device_mem_cache_type_t::read_only_cache)));
    TS_ASSERT(!(device_info().set_global_mem_cacheline_size(0x1234u) != device_info().set_global_mem_cacheline_size(0x1234u)));
    TS_ASSERT(!(device_info().set_global_mem_cache_size(0x1234ul) != device_info().set_global_mem_cache_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_global_mem_size(0x1234ul) != device_info().set_global_mem_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_max_constant_buffer_size(0x1234u) != device_info().set_max_constant_buffer_size(0x1234u)));
    TS_ASSERT(!(device_info().set_max_constant_args(0x1234u) != device_info().set_max_constant_args(0x1234u)));
    TS_ASSERT(!(device_info().set_local_mem_type(device_local_mem_type_t::local) != device_info().set_local_mem_type(device_local_mem_type_t::local)));
    TS_ASSERT(!(device_info().set_local_mem_size(0x1234ul) != device_info().set_local_mem_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_error_correction_support(0) != device_info().set_error_correction_support(0)));
    TS_ASSERT(!(device_info().set_profiling_timer_resolution(0x1234ul) != device_info().set_profiling_timer_resolution(0x1234ul)));
    TS_ASSERT(!(device_info().set_endian_little(0) != device_info().set_endian_little(0)));
    TS_ASSERT(!(device_info().set_available(0) != device_info().set_available(0)));
    TS_ASSERT(!(device_info().set_compiler_available(0) != device_info().set_compiler_available(0)));
    TS_ASSERT(!(device_info().set_execution_capabilities(device_exec_capabilities_t::kernel) != device_info().set_execution_capabilities(device_exec_capabilities_t::kernel)));
    TS_ASSERT(!(device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable) != device_info().set_queue_properties(command_queue_properties_t::out_of_order_exec_mode_enable)));
    TS_ASSERT(!(device_info().set_name("_name") != device_info().set_name("_name")));
    TS_ASSERT(!(device_info().set_vendor("_vendor") != device_info().set_vendor("_vendor")));
    TS_ASSERT(!(device_info().set_driver_version("_driver_version") != device_info().set_driver_version("_driver_version")));
    TS_ASSERT(!(device_info().set_profile("_profile") != device_info().set_profile("_profile")));
    TS_ASSERT(!(device_info().set_version("_version") != device_info().set_version("_version")));
    TS_ASSERT(!(device_info().set_extensions("_extensions") != device_info().set_extensions("_extensions")));
    TS_ASSERT(!(device_info().set_platform_id(0x1234ul) != device_info().set_platform_id(0x1234ul)));
    TS_ASSERT(!(device_info().set_double_fp_config(device_fp_config_t::denorm) != device_info().set_double_fp_config(device_fp_config_t::denorm)));
    TS_ASSERT(!(device_info().set_preferred_vector_width_half(0x1234u) != device_info().set_preferred_vector_width_half(0x1234u)));
    TS_ASSERT(!(device_info().set_host_unified_memory(0) != device_info().set_host_unified_memory(0)));
    TS_ASSERT(!(device_info().set_native_vector_width_char(0x1234u) != device_info().set_native_vector_width_char(0x1234u)));
    TS_ASSERT(!(device_info().set_native_vector_width_short(0x1234u) != device_info().set_native_vector_width_short(0x1234u)));
    TS_ASSERT(!(device_info().set_native_vector_width_int(0x1234u) != device_info().set_native_vector_width_int(0x1234u)));
    TS_ASSERT(!(device_info().set_native_vector_width_long(0x1234u) != device_info().set_native_vector_width_long(0x1234u)));
    TS_ASSERT(!(device_info().set_native_vector_width_float(0x1234u) != device_info().set_native_vector_width_float(0x1234u)));
    TS_ASSERT(!(device_info().set_native_vector_width_double(0x1234u) != device_info().set_native_vector_width_double(0x1234u)));
    TS_ASSERT(!(device_info().set_native_vector_width_half(0x1234u) != device_info().set_native_vector_width_half(0x1234u)));
    TS_ASSERT(!(device_info().set_opencl_c_version("_opencl_c_version") != device_info().set_opencl_c_version("_opencl_c_version")));
    TS_ASSERT(!(device_info().set_linker_available(0) != device_info().set_linker_available(0)));
    TS_ASSERT(!(device_info().set_built_in_kernels("_built_in_kernels") != device_info().set_built_in_kernels("_built_in_kernels")));
    TS_ASSERT(!(device_info().set_image_max_buffer_size(0x1234ul) != device_info().set_image_max_buffer_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_image_max_array_size(0x1234ul) != device_info().set_image_max_array_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_parent_device_id(0x1234ul) != device_info().set_parent_device_id(0x1234ul)));
    TS_ASSERT(!(device_info().set_partition_max_sub_devices(0x1234u) != device_info().set_partition_max_sub_devices(0x1234u)));
    TS_ASSERT(!(device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2)) != device_info().set_partition_properties(std::vector<device_partition_property_t>(partition_properties1,partition_properties1+2))));
    TS_ASSERT(!(device_info().set_partition_affinity_domain(device_affinity_domain_t::numa) != device_info().set_partition_affinity_domain(device_affinity_domain_t::numa)));
    TS_ASSERT(!(device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2)) != device_info().set_partition_type(std::vector<device_partition_property_t>(partition_type1,partition_type1+2))));
    TS_ASSERT(!(device_info().set_reference_count(0x1234u) != device_info().set_reference_count(0x1234u)));
    TS_ASSERT(!(device_info().set_preferred_interop_user_sync(0) != device_info().set_preferred_interop_user_sync(0)));
    TS_ASSERT(!(device_info().set_printf_buffer_size(0x1234ul) != device_info().set_printf_buffer_size(0x1234ul)));
    TS_ASSERT(!(device_info().set_image_pitch_alignment(0x1234u) != device_info().set_image_pitch_alignment(0x1234u)));
    TS_ASSERT(!(device_info().set_image_base_address_alignment(0x1234u) != device_info().set_image_base_address_alignment(0x1234u)));
  }
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor()
  {
    device_info a(device_info_fixtures::_1());
    device_info b(a);
    TS_ASSERT((a == b));
  }
  /** // doc: test_assign_op() {{{
   * \todo Write documentation
   */ // }}}
  void test_assign_op()
  {
    device_info a(device_info_fixtures::_1());
    device_info b;
    b = a;
    TS_ASSERT((a == b));
  }
};

#endif /* CLXX_INFO_DEVICE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
