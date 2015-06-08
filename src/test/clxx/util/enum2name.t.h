// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/enum2name.t.h

/** // doc: clxx/enum2name.t.h {{{
 * \file clxx/enum2name.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_ENUM2NAME_T_H_INCLUDED
#define CLXX_UTIL_ENUM2NAME_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/util/enum2name.hpp>

namespace clxx { class enum2name_test_suite; }

/** // doc: class clxx::enum2name_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enum2name_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_status_t() {{{
   * \brief Ensure that enum2name() works with status_t.
   */ // }}}
  void test_status_t( )
  {
    TS_ASSERT_EQUALS(enum2name(status_t::success), "success");
    TS_ASSERT_EQUALS(enum2name(status_t::device_not_found), "device_not_found");
    TS_ASSERT_EQUALS(enum2name(status_t::device_not_available), "device_not_available");
    TS_ASSERT_EQUALS(enum2name(status_t::compiler_not_available), "compiler_not_available");
    TS_ASSERT_EQUALS(enum2name(status_t::mem_object_allocation_failure), "mem_object_allocation_failure");
    TS_ASSERT_EQUALS(enum2name(status_t::out_of_resources), "out_of_resources");
    TS_ASSERT_EQUALS(enum2name(status_t::out_of_host_memory), "out_of_host_memory");
    TS_ASSERT_EQUALS(enum2name(status_t::profiling_info_not_available), "profiling_info_not_available");
    TS_ASSERT_EQUALS(enum2name(status_t::mem_copy_overlap), "mem_copy_overlap");
    TS_ASSERT_EQUALS(enum2name(status_t::image_format_mismatch), "image_format_mismatch");
    TS_ASSERT_EQUALS(enum2name(status_t::image_format_not_supported), "image_format_not_supported");
    TS_ASSERT_EQUALS(enum2name(status_t::build_program_failure), "build_program_failure");
    TS_ASSERT_EQUALS(enum2name(status_t::map_failure), "map_failure");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(status_t::misaligned_sub_buffer_offset), "misaligned_sub_buffer_offset");
    TS_ASSERT_EQUALS(enum2name(status_t::exec_status_error_for_events_in_wait_list), "exec_status_error_for_events_in_wait_list");
#endif
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(status_t::compile_program_failure), "compile_program_failure");
    TS_ASSERT_EQUALS(enum2name(status_t::linker_not_available), "linker_not_available");
    TS_ASSERT_EQUALS(enum2name(status_t::link_program_failure), "link_program_failure");
    TS_ASSERT_EQUALS(enum2name(status_t::device_partition_failed), "device_partition_failed");
    TS_ASSERT_EQUALS(enum2name(status_t::kernel_arg_info_not_available), "kernel_arg_info_not_available");
#endif
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_value), "invalid_value");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_device_type), "invalid_device_type");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_platform), "invalid_platform");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_device), "invalid_device");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_context), "invalid_context");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_queue_properties), "invalid_queue_properties");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_command_queue), "invalid_command_queue");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_host_ptr), "invalid_host_ptr");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_mem_object), "invalid_mem_object");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_image_format_descriptor), "invalid_image_format_descriptor");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_image_size), "invalid_image_size");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_sampler), "invalid_sampler");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_binary), "invalid_binary");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_build_options), "invalid_build_options");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_program), "invalid_program");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_program_executable), "invalid_program_executable");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_kernel_name), "invalid_kernel_name");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_kernel_definition), "invalid_kernel_definition");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_kernel), "invalid_kernel");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_arg_index), "invalid_arg_index");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_arg_value), "invalid_arg_value");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_arg_size), "invalid_arg_size");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_kernel_args), "invalid_kernel_args");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_work_dimension), "invalid_work_dimension");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_work_group_size), "invalid_work_group_size");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_work_item_size), "invalid_work_item_size");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_global_offset), "invalid_global_offset");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_event_wait_list), "invalid_event_wait_list");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_event), "invalid_event");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_operation), "invalid_operation");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_gl_object), "invalid_gl_object");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_buffer_size), "invalid_buffer_size");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_mip_level), "invalid_mip_level");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_global_work_size), "invalid_global_work_size");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_property), "invalid_property");
#endif
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_image_descriptor), "invalid_image_descriptor");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_compiler_options), "invalid_compiler_options");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_linker_options), "invalid_linker_options");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_device_partition_count), "invalid_device_partition_count");
#endif
#if cl_khr_icd
    TS_ASSERT_EQUALS(enum2name(status_t::platform_not_found_khr),"platform_not_found_khr");
#endif
#if cl_ext_device_fission
    TS_ASSERT_EQUALS(enum2name(status_t::device_partition_failed_ext),"device_partition_failed_ext");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_partition_count_ext),"invalid_partition_count_ext");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_partition_name_ext),"invalid_partition_name_ext");
#endif
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_gl_sharegroup_reference_khr),"invalid_gl_sharegroup_reference_khr");
#endif
#if cl_khr_dx9_media_sharing
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_dx9_media_adapter_khr),"invalid_dx9_media_adapter_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_dx9_media_surface_khr),"invalid_dx9_media_surface_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::dx9_media_surface_already_acquired_khr),"dx9_media_surface_already_acquired_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::dx9_media_surface_not_acquired_khr),"dx9_media_surface_not_acquired_khr");
#endif
#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_d3d10_device_khr),"invalid_d3d10_device_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_d3d10_resource_khr),"invalid_d3d10_resource_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::d3d10_resource_already_acquired_khr),"d3d10_resource_already_acquired_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::d3d10_resource_not_acquired_khr),"d3d10_resource_not_acquired_khr");
#endif
#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_d3d11_device_khr),"invalid_d3d11_device_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::invalid_d3d11_resource_khr),"invalid_d3d11_resource_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::d3d11_resource_already_acquired_khr),"d3d11_resource_already_acquired_khr");
    TS_ASSERT_EQUALS(enum2name(status_t::d3d11_resource_not_acquired_khr),"d3d11_resource_not_acquired_khr");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<status_t>(0x7FFF)), nullptr);
    TS_ASSERT_EQUALS(enum2name(static_cast<status_t>(-0x7FFF)), nullptr);
  }
  /** // doc: test_platform_info_t() {{{
   * \brief Ensure that enum2name() works with platform_info_t.
   */ // }}}
  void test_platform_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(platform_info_t::profile), "profile");
    TS_ASSERT_EQUALS(enum2name(platform_info_t::version), "version");
    TS_ASSERT_EQUALS(enum2name(platform_info_t::name), "name");
    TS_ASSERT_EQUALS(enum2name(platform_info_t::vendor), "vendor");
    TS_ASSERT_EQUALS(enum2name(platform_info_t::extensions), "extensions");
    TS_ASSERT_EQUALS(enum2name(static_cast<platform_info_t>(-1l)), nullptr);
  }
  /** // doc: test_device_type_t() {{{
   * \brief Ensure that enum2name() works with device_type_t.
   */ // }}}
  void test_device_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_type_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(device_type_t::default_), "default_");
    TS_ASSERT_EQUALS(enum2name(device_type_t::cpu), "cpu");
    TS_ASSERT_EQUALS(enum2name(device_type_t::gpu), "gpu");
    TS_ASSERT_EQUALS(enum2name(device_type_t::accelerator), "accelerator");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(device_type_t::custom), "custom");
#endif
    TS_ASSERT_EQUALS(enum2name(device_type_t::all), "all");
    TS_ASSERT_EQUALS(enum2name(static_cast<device_type_t>(-1l)), nullptr);
  }
  /** // doc: test_device_info_t() {{{
   * \brief Ensure that enum2name() works with device_info_t.
   */ // }}}
  void test_device_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_info_t::type), "type");
    TS_ASSERT_EQUALS(enum2name(device_info_t::vendor_id), "vendor_id");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_compute_units), "max_compute_units");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_work_item_dimensions), "max_work_item_dimensions");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_work_group_size), "max_work_group_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_work_item_sizes), "max_work_item_sizes");
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_vector_width_char), "preferred_vector_width_char");
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_vector_width_short), "preferred_vector_width_short");
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_vector_width_int), "preferred_vector_width_int");
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_vector_width_long), "preferred_vector_width_long");
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_vector_width_float), "preferred_vector_width_float");
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_vector_width_double), "preferred_vector_width_double");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_clock_frequency), "max_clock_frequency");
    TS_ASSERT_EQUALS(enum2name(device_info_t::address_bits), "address_bits");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_read_image_args), "max_read_image_args");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_write_image_args), "max_write_image_args");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_mem_alloc_size), "max_mem_alloc_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image2d_max_width), "image2d_max_width");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image2d_max_height), "image2d_max_height");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image3d_max_width), "image3d_max_width");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image3d_max_height), "image3d_max_height");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image3d_max_depth), "image3d_max_depth");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image_support), "image_support");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_parameter_size), "max_parameter_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_samplers), "max_samplers");
    TS_ASSERT_EQUALS(enum2name(device_info_t::mem_base_addr_align), "mem_base_addr_align");
    TS_ASSERT_EQUALS(enum2name(device_info_t::min_data_type_align_size), "min_data_type_align_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::single_fp_config), "single_fp_config");
    TS_ASSERT_EQUALS(enum2name(device_info_t::global_mem_cache_type), "global_mem_cache_type");
    TS_ASSERT_EQUALS(enum2name(device_info_t::global_mem_cacheline_size), "global_mem_cacheline_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::global_mem_cache_size), "global_mem_cache_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::global_mem_size), "global_mem_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_constant_buffer_size), "max_constant_buffer_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::max_constant_args), "max_constant_args");
    TS_ASSERT_EQUALS(enum2name(device_info_t::local_mem_type), "local_mem_type");
    TS_ASSERT_EQUALS(enum2name(device_info_t::local_mem_size), "local_mem_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::error_correction_support), "error_correction_support");
    TS_ASSERT_EQUALS(enum2name(device_info_t::profiling_timer_resolution), "profiling_timer_resolution");
    TS_ASSERT_EQUALS(enum2name(device_info_t::endian_little), "endian_little");
    TS_ASSERT_EQUALS(enum2name(device_info_t::available), "available");
    TS_ASSERT_EQUALS(enum2name(device_info_t::compiler_available), "compiler_available");
    TS_ASSERT_EQUALS(enum2name(device_info_t::execution_capabilities), "execution_capabilities");
    TS_ASSERT_EQUALS(enum2name(device_info_t::queue_properties), "queue_properties");
    TS_ASSERT_EQUALS(enum2name(device_info_t::name), "name");
    TS_ASSERT_EQUALS(enum2name(device_info_t::vendor), "vendor");
    TS_ASSERT_EQUALS(enum2name(device_info_t::driver_version), "driver_version");
    TS_ASSERT_EQUALS(enum2name(device_info_t::profile), "profile");
    TS_ASSERT_EQUALS(enum2name(device_info_t::version), "version");
    TS_ASSERT_EQUALS(enum2name(device_info_t::extensions), "extensions");
    TS_ASSERT_EQUALS(enum2name(device_info_t::platform), "platform");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(device_info_t::double_fp_config), "double_fp_config");
#endif
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_vector_width_half), "preferred_vector_width_half");
    TS_ASSERT_EQUALS(enum2name(device_info_t::host_unified_memory), "host_unified_memory");
    TS_ASSERT_EQUALS(enum2name(device_info_t::native_vector_width_char), "native_vector_width_char");
    TS_ASSERT_EQUALS(enum2name(device_info_t::native_vector_width_short), "native_vector_width_short");
    TS_ASSERT_EQUALS(enum2name(device_info_t::native_vector_width_int), "native_vector_width_int");
    TS_ASSERT_EQUALS(enum2name(device_info_t::native_vector_width_long), "native_vector_width_long");
    TS_ASSERT_EQUALS(enum2name(device_info_t::native_vector_width_float), "native_vector_width_float");
    TS_ASSERT_EQUALS(enum2name(device_info_t::native_vector_width_double), "native_vector_width_double");
    TS_ASSERT_EQUALS(enum2name(device_info_t::native_vector_width_half), "native_vector_width_half");
    TS_ASSERT_EQUALS(enum2name(device_info_t::opencl_c_version), "opencl_c_version");
#endif
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(device_info_t::linker_available), "linker_available");
    TS_ASSERT_EQUALS(enum2name(device_info_t::built_in_kernels), "built_in_kernels");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image_max_buffer_size), "image_max_buffer_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image_max_array_size), "image_max_array_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::parent_device), "parent_device");
    TS_ASSERT_EQUALS(enum2name(device_info_t::partition_max_sub_devices), "partition_max_sub_devices");
    TS_ASSERT_EQUALS(enum2name(device_info_t::partition_properties), "partition_properties");
    TS_ASSERT_EQUALS(enum2name(device_info_t::partition_affinity_domain), "partition_affinity_domain");
    TS_ASSERT_EQUALS(enum2name(device_info_t::partition_type), "partition_type");
    TS_ASSERT_EQUALS(enum2name(device_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(device_info_t::preferred_interop_user_sync), "preferred_interop_user_sync");
    TS_ASSERT_EQUALS(enum2name(device_info_t::printf_buffer_size), "printf_buffer_size");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image_pitch_alignment), "image_pitch_alignment");
    TS_ASSERT_EQUALS(enum2name(device_info_t::image_base_address_alignment), "image_base_address_alignment");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<device_info_t>(-1l)), nullptr);
  }
  /** // doc: test_device_fp_config_t() {{{
   * \brief Ensure that enum2name() works with device_fp_config_t.
   */ // }}}
  void test_device_fp_config_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::denorm), "denorm");
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::inf_nan), "inf_nan");
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::round_to_nearest), "round_to_nearest");
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::round_to_zero), "round_to_zero");
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::round_to_inf), "round_to_inf");
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::fma), "fma");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::soft_float), "soft_float");
#endif
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(device_fp_config_t::correctly_rounded_divide_sqrt), "correctly_rounded_divide_sqrt");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<device_fp_config_t>(-1l)), nullptr);
  }
  /** // doc: test_device_mem_cache_type_t() {{{
   * \brief Ensure that enum2name() works with device_mem_cache_type_t.
   */ // }}}
  void test_device_mem_cache_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_mem_cache_type_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(device_mem_cache_type_t::read_only_cache), "read_only_cache");
    TS_ASSERT_EQUALS(enum2name(device_mem_cache_type_t::read_write_cache), "read_write_cache");
    TS_ASSERT_EQUALS(enum2name(static_cast<device_mem_cache_type_t>(-1l)), nullptr);
  }
  /** // doc: test_device_local_mem_type_t() {{{
   * \brief Ensure that enum2name() works with device_local_mem_type_t.
   */ // }}}
  void test_device_local_mem_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_local_mem_type_t::local), "local");
    TS_ASSERT_EQUALS(enum2name(device_local_mem_type_t::global), "global");
    TS_ASSERT_EQUALS(enum2name(static_cast<device_local_mem_type_t>(-1l)), nullptr);
  }
  /** // doc: test_device_exec_capabilities_t() {{{
   * \brief Ensure that enum2name() works with device_exec_capabilities_t.
   */ // }}}
  void test_device_exec_capabilities_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_exec_capabilities_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(device_exec_capabilities_t::kernel), "kernel");
    TS_ASSERT_EQUALS(enum2name(device_exec_capabilities_t::native_kernel), "native_kernel");
    TS_ASSERT_EQUALS(enum2name(static_cast<device_exec_capabilities_t>(-1l)), nullptr);
  }
  /** // doc: test_command_queue_properties_t() {{{
   * \brief Ensure that enum2name() works with command_queue_properties_t.
   */ // }}}
  void test_command_queue_properties_t( )
  {
    TS_ASSERT_EQUALS(enum2name(command_queue_properties_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(command_queue_properties_t::out_of_order_exec_mode_enable), "out_of_order_exec_mode_enable");
    TS_ASSERT_EQUALS(enum2name(command_queue_properties_t::profiling_enable), "profiling_enable");
    TS_ASSERT_EQUALS(enum2name(static_cast<command_queue_properties_t>(-1l)), nullptr);
  }
  /** // doc: test_context_info_t() {{{
   * \brief Ensure that enum2name() works with context_info_t.
   */ // }}}
  void test_context_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(context_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(context_info_t::devices), "devices");
    TS_ASSERT_EQUALS(enum2name(context_info_t::properties), "properties");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(context_info_t::num_devices), "num_devices");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<context_info_t>(-1l)), nullptr);
  }
  /** // doc: test_context_properties_t() {{{
   * \brief Ensure that enum2name() works with context_properties_t.
   */ // }}}
  void test_context_properties_t( )
  {
    TS_ASSERT_EQUALS(enum2name(context_properties_t::platform), "platform");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(context_properties_t::interop_user_sync), "interop_user_sync");
#endif
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(enum2name(context_properties_t::gl_context_khr),"gl_context_khr");
    TS_ASSERT_EQUALS(enum2name(context_properties_t::egl_display_khr),"egl_display_khr");
    TS_ASSERT_EQUALS(enum2name(context_properties_t::glx_display_khr),"glx_display_khr");
    TS_ASSERT_EQUALS(enum2name(context_properties_t::wgl_hdc_khr),"wgl_hdc_khr");
    TS_ASSERT_EQUALS(enum2name(context_properties_t::cgl_sharegroup_khr),"cgl_sharegroup_khr");
#endif
#if cl_khr_dx9_media_sharing
    TS_ASSERT_EQUALS(enum2name(context_properties_t::adapter_d3d9_khr),"adapter_d3d9_khr");
    TS_ASSERT_EQUALS(enum2name(context_properties_t::adapter_d3d9ex_khr),"adapter_d3d9ex_khr");
    TS_ASSERT_EQUALS(enum2name(context_properties_t::adapter_dxva_khr),"adapter_dxva_khr");
#endif
#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(enum2name(context_properties_t::d3d10_device_khr),"d3d10_device_khr");
#endif
#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(enum2name(context_properties_t::d3d11_device_khr),"d3d11_device_khr");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<context_properties_t>(-1l)), nullptr);
  }
#if CL_VERSION_1_2
  /** // doc: test_device_partition_property_t() {{{
   * \brief Ensure that enum2name() works with device_partition_property_t.
   */ // }}}
  void test_device_partition_property_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_partition_property_t::equally), "equally");
    TS_ASSERT_EQUALS(enum2name(device_partition_property_t::by_counts), "by_counts");
    TS_ASSERT_EQUALS(enum2name(device_partition_property_t::by_counts_list_end), "by_counts_list_end");
    TS_ASSERT_EQUALS(enum2name(device_partition_property_t::by_affinity_domain), "by_affinity_domain");
    TS_ASSERT_EQUALS(enum2name(static_cast<device_partition_property_t>(-1l)), nullptr);
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_device_affinity_domain_t() {{{
   * \brief Ensure that enum2name() works with device_affinity_domain_t.
   */ // }}}
  void test_device_affinity_domain_t( )
  {
    TS_ASSERT_EQUALS(enum2name(device_affinity_domain_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(device_affinity_domain_t::numa), "numa");
    TS_ASSERT_EQUALS(enum2name(device_affinity_domain_t::l4_cache), "l4_cache");
    TS_ASSERT_EQUALS(enum2name(device_affinity_domain_t::l3_cache), "l3_cache");
    TS_ASSERT_EQUALS(enum2name(device_affinity_domain_t::l2_cache), "l2_cache");
    TS_ASSERT_EQUALS(enum2name(device_affinity_domain_t::l1_cache), "l1_cache");
    TS_ASSERT_EQUALS(enum2name(device_affinity_domain_t::next_partitionable), "next_partitionable");
    TS_ASSERT_EQUALS(enum2name(static_cast<device_affinity_domain_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_command_queue_info_t() {{{
   * \brief Ensure that enum2name() works with command_queue_info_t.
   */ // }}}
  void test_command_queue_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(command_queue_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2name(command_queue_info_t::device), "device");
    TS_ASSERT_EQUALS(enum2name(command_queue_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(command_queue_info_t::properties), "properties");
    TS_ASSERT_EQUALS(enum2name(static_cast<command_queue_info_t>(-1l)), nullptr);
  }
  /** // doc: test_mem_flags_t() {{{
   * \brief Ensure that enum2name() works with mem_flags_t.
   */ // }}}
  void test_mem_flags_t( )
  {
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::read_write), "read_write");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::write_only), "write_only");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::read_only), "read_only");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::use_host_ptr), "use_host_ptr");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::alloc_host_ptr), "alloc_host_ptr");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::copy_host_ptr), "copy_host_ptr");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::host_write_only), "host_write_only");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::host_read_only), "host_read_only");
    TS_ASSERT_EQUALS(enum2name(mem_flags_t::host_no_access), "host_no_access");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<mem_flags_t>(-1l)), nullptr);
  }
#if CL_VERSION_1_2
  /** // doc: test_mem_migration_flags_t() {{{
   * \brief Ensure that enum2name() works with mem_migration_flags_t.
   */ // }}}
  void test_mem_migration_flags_t( )
  {
    TS_ASSERT_EQUALS(enum2name(mem_migration_flags_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(mem_migration_flags_t::mem_object_host), "mem_object_host");
    TS_ASSERT_EQUALS(enum2name(mem_migration_flags_t::mem_object_content_undefined), "mem_object_content_undefined");
    TS_ASSERT_EQUALS(enum2name(static_cast<mem_migration_flags_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_channel_order_t() {{{
   * \brief Ensure that enum2name() works with channel_order_t.
   */ // }}}
  void test_channel_order_t( )
  {
    TS_ASSERT_EQUALS(enum2name(channel_order_t::r), "r");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::a), "a");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::rg), "rg");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::ra), "ra");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::rgb), "rgb");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::rgba), "rgba");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::bgra), "bgra");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::argb), "argb");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::intensity), "intensity");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::luminance), "luminance");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(channel_order_t::rx), "rx");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::rgx), "rgx");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::rgbx), "rgbx");
#endif
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(channel_order_t::depth), "depth");
    TS_ASSERT_EQUALS(enum2name(channel_order_t::depth_stencil), "depth_stencil");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<channel_order_t>(-1l)), nullptr);
  }
  /** // doc: test_channel_type_t() {{{
   * \brief Ensure that enum2name() works with channel_type_t.
   */ // }}}
  void test_channel_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(channel_type_t::snorm_int8), "snorm_int8");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::snorm_int16), "snorm_int16");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unorm_int8), "unorm_int8");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unorm_int16), "unorm_int16");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unorm_short_565), "unorm_short_565");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unorm_short_555), "unorm_short_555");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unorm_int_101010), "unorm_int_101010");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::signed_int8), "signed_int8");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::signed_int16), "signed_int16");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::signed_int32), "signed_int32");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unsigned_int8), "unsigned_int8");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unsigned_int16), "unsigned_int16");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unsigned_int32), "unsigned_int32");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::half_float), "half_float");
    TS_ASSERT_EQUALS(enum2name(channel_type_t::float_), "float_");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(channel_type_t::unorm_int24), "unorm_int24");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<channel_type_t>(-1l)), nullptr);
  }
  /** // doc: test_mem_object_type_t() {{{
   * \brief Ensure that enum2name() works with mem_object_type_t.
   */ // }}}
  void test_mem_object_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(mem_object_type_t::buffer), "buffer");
    TS_ASSERT_EQUALS(enum2name(mem_object_type_t::image2d), "image2d");
    TS_ASSERT_EQUALS(enum2name(mem_object_type_t::image3d), "image3d");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(mem_object_type_t::image2d_array), "image2d_array");
    TS_ASSERT_EQUALS(enum2name(mem_object_type_t::image1d), "image1d");
    TS_ASSERT_EQUALS(enum2name(mem_object_type_t::image1d_array), "image1d_array");
    TS_ASSERT_EQUALS(enum2name(mem_object_type_t::image1d_buffer), "image1d_buffer");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<mem_object_type_t>(-1l)), nullptr);
  }
  /** // doc: test_mem_info_t() {{{
   * \brief Ensure that enum2name() works with mem_info_t.
   */ // }}}
  void test_mem_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(mem_info_t::type), "type");
    TS_ASSERT_EQUALS(enum2name(mem_info_t::flags), "flags");
    TS_ASSERT_EQUALS(enum2name(mem_info_t::size), "size");
    TS_ASSERT_EQUALS(enum2name(mem_info_t::host_ptr), "host_ptr");
    TS_ASSERT_EQUALS(enum2name(mem_info_t::map_count), "map_count");
    TS_ASSERT_EQUALS(enum2name(mem_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(mem_info_t::context), "context");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(mem_info_t::associated_memobject), "associated_memobject");
    TS_ASSERT_EQUALS(enum2name(mem_info_t::offset), "offset");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<mem_info_t>(-1l)), nullptr);
  }
  /** // doc: test_image_info_t() {{{
   * \brief Ensure that enum2name() works with image_info_t.
   */ // }}}
  void test_image_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(image_info_t::format), "format");
    TS_ASSERT_EQUALS(enum2name(image_info_t::element_size), "element_size");
    TS_ASSERT_EQUALS(enum2name(image_info_t::row_pitch), "row_pitch");
    TS_ASSERT_EQUALS(enum2name(image_info_t::slice_pitch), "slice_pitch");
    TS_ASSERT_EQUALS(enum2name(image_info_t::width), "width");
    TS_ASSERT_EQUALS(enum2name(image_info_t::height), "height");
    TS_ASSERT_EQUALS(enum2name(image_info_t::depth), "depth");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(image_info_t::array_size), "array_size");
    TS_ASSERT_EQUALS(enum2name(image_info_t::buffer), "buffer");
    TS_ASSERT_EQUALS(enum2name(image_info_t::num_mip_levels), "num_mip_levels");
    TS_ASSERT_EQUALS(enum2name(image_info_t::num_samples), "num_samples");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<image_info_t>(-1l)), nullptr);
  }
  /** // doc: test_addressing_mode_t() {{{
   * \brief Ensure that enum2name() works with addressing_mode_t.
   */ // }}}
  void test_addressing_mode_t( )
  {
    TS_ASSERT_EQUALS(enum2name(addressing_mode_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(addressing_mode_t::clamp_to_edge), "clamp_to_edge");
    TS_ASSERT_EQUALS(enum2name(addressing_mode_t::clamp), "clamp");
    TS_ASSERT_EQUALS(enum2name(addressing_mode_t::repeat), "repeat");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(addressing_mode_t::mirrored_repeat), "mirrored_repeat");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<addressing_mode_t>(-1l)), nullptr);
  }
  /** // doc: test_filter_mode_t() {{{
   * \brief Ensure that enum2name() works with filter_mode_t.
   */ // }}}
  void test_filter_mode_t( )
  {
    TS_ASSERT_EQUALS(enum2name(filter_mode_t::nearest), "nearest");
    TS_ASSERT_EQUALS(enum2name(filter_mode_t::linear), "linear");
    TS_ASSERT_EQUALS(enum2name(static_cast<filter_mode_t>(-1l)), nullptr);
  }
  /** // doc: test_sampler_info_t() {{{
   * \brief Ensure that enum2name() works with sampler_info_t.
   */ // }}}
  void test_sampler_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(sampler_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(sampler_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2name(sampler_info_t::normalized_coords), "normalized_coords");
    TS_ASSERT_EQUALS(enum2name(sampler_info_t::addressing_mode), "addressing_mode");
    TS_ASSERT_EQUALS(enum2name(sampler_info_t::filter_mode), "filter_mode");
    TS_ASSERT_EQUALS(enum2name(static_cast<sampler_info_t>(-1l)), nullptr);
  }
  /** // doc: test_map_flags_t() {{{
   * \brief Ensure that enum2name() works with map_flags_t.
   */ // }}}
  void test_map_flags_t( )
  {
    TS_ASSERT_EQUALS(enum2name(map_flags_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(map_flags_t::read), "read");
    TS_ASSERT_EQUALS(enum2name(map_flags_t::write), "write");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(map_flags_t::write_invalidate_region), "write_invalidate_region");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<map_flags_t>(-1l)), nullptr);
  }
  /** // doc: test_program_info_t() {{{
   * \brief Ensure that enum2name() works with program_info_t.
   */ // }}}
  void test_program_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(program_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(program_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2name(program_info_t::num_devices), "num_devices");
    TS_ASSERT_EQUALS(enum2name(program_info_t::devices), "devices");
    TS_ASSERT_EQUALS(enum2name(program_info_t::source), "source");
    TS_ASSERT_EQUALS(enum2name(program_info_t::binary_sizes), "binary_sizes");
    TS_ASSERT_EQUALS(enum2name(program_info_t::binaries), "binaries");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(program_info_t::num_kernels), "num_kernels");
    TS_ASSERT_EQUALS(enum2name(program_info_t::kernel_names), "kernel_names");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<program_info_t>(-1l)), nullptr);
  }
  /** // doc: test_program_build_info_t() {{{
   * \brief Ensure that enum2name() works with program_build_info_t.
   */ // }}}
  void test_program_build_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(program_build_info_t::status), "status");
    TS_ASSERT_EQUALS(enum2name(program_build_info_t::options), "options");
    TS_ASSERT_EQUALS(enum2name(program_build_info_t::log), "log");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(program_build_info_t::binary_type), "binary_type");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<program_build_info_t>(-1l)), nullptr);
  }
#if CL_VERSION_1_2
  /** // doc: test_program_binary_type_t() {{{
   * \brief Ensure that enum2name() works with program_binary_type_t.
   */ // }}}
  void test_program_binary_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(program_binary_type_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(program_binary_type_t::compiled_object), "compiled_object");
    TS_ASSERT_EQUALS(enum2name(program_binary_type_t::library), "library");
    TS_ASSERT_EQUALS(enum2name(program_binary_type_t::executable), "executable");
    TS_ASSERT_EQUALS(enum2name(static_cast<program_binary_type_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_build_status_t() {{{
   * \brief Ensure that enum2name() works with build_status_t.
   */ // }}}
  void test_build_status_t( )
  {
    TS_ASSERT_EQUALS(enum2name(build_status_t::success), "success");
    TS_ASSERT_EQUALS(enum2name(build_status_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(build_status_t::error), "error");
    TS_ASSERT_EQUALS(enum2name(build_status_t::in_progress), "in_progress");
    TS_ASSERT_EQUALS(enum2name(static_cast<build_status_t>(-12345l)), nullptr);
  }
  /** // doc: test_kernel_info_t() {{{
   * \brief Ensure that enum2name() works with kernel_info_t.
   */ // }}}
  void test_kernel_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(kernel_info_t::function_name), "function_name");
    TS_ASSERT_EQUALS(enum2name(kernel_info_t::num_args), "num_args");
    TS_ASSERT_EQUALS(enum2name(kernel_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(kernel_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2name(kernel_info_t::program), "program");
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(kernel_info_t::attributes), "attributes");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<kernel_info_t>(-1l)), nullptr);
  }
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_info_t() {{{
   * \brief Ensure that enum2name() works with kernel_arg_info_t.
   */ // }}}
  void test_kernel_arg_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(kernel_arg_info_t::address_qualifier), "address_qualifier");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_info_t::access_qualifier), "access_qualifier");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_info_t::type_name), "type_name");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_info_t::type_qualifier), "type_qualifier");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_info_t::name), "name");
    TS_ASSERT_EQUALS(enum2name(static_cast<kernel_arg_info_t>(-1l)), nullptr);
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_address_qualifier_t() {{{
   * \brief Ensure that enum2name() works with kernel_arg_address_qualifier_t.
   */ // }}}
  void test_kernel_arg_address_qualifier_t( )
  {
    TS_ASSERT_EQUALS(enum2name(kernel_arg_address_qualifier_t::global), "global");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_address_qualifier_t::local), "local");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_address_qualifier_t::constant), "constant");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_address_qualifier_t::private_), "private_");
    TS_ASSERT_EQUALS(enum2name(static_cast<kernel_arg_address_qualifier_t>(-1l)), nullptr);
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_access_qualifier_t() {{{
   * \brief Ensure that enum2name() works with kernel_arg_access_qualifier_t.
   */ // }}}
  void test_kernel_arg_access_qualifier_t( )
  {
    TS_ASSERT_EQUALS(enum2name(kernel_arg_access_qualifier_t::read_only), "read_only");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_access_qualifier_t::write_only), "write_only");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_access_qualifier_t::read_write), "read_write");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_access_qualifier_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(static_cast<kernel_arg_access_qualifier_t>(-1l)), nullptr);
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_type_qualifier_t() {{{
   * \brief Ensure that enum2name() works with kernel_arg_type_qualifier_t.
   */ // }}}
  void test_kernel_arg_type_qualifier_t( )
  {
    TS_ASSERT_EQUALS(enum2name(kernel_arg_type_qualifier_t::none), "none");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_type_qualifier_t::const_), "const_");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_type_qualifier_t::restrict_), "restrict_");
    TS_ASSERT_EQUALS(enum2name(kernel_arg_type_qualifier_t::volatile_), "volatile_");
    TS_ASSERT_EQUALS(enum2name(static_cast<kernel_arg_type_qualifier_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_kernel_work_group_info_t() {{{
   * \brief Ensure that enum2name() works with kernel_work_group_info_t.
   */ // }}}
  void test_kernel_work_group_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(kernel_work_group_info_t::work_group_size), "work_group_size");
    TS_ASSERT_EQUALS(enum2name(kernel_work_group_info_t::compile_work_group_size), "compile_work_group_size");
    TS_ASSERT_EQUALS(enum2name(kernel_work_group_info_t::local_mem_size), "local_mem_size");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(kernel_work_group_info_t::preferred_work_group_size_multiple), "preferred_work_group_size_multiple");
    TS_ASSERT_EQUALS(enum2name(kernel_work_group_info_t::private_mem_size), "private_mem_size");
#endif
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(kernel_work_group_info_t::global_work_size), "global_work_size");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<kernel_work_group_info_t>(-1l)), nullptr);
  }
  /** // doc: test_event_info_t() {{{
   * \brief Ensure that enum2name() works with event_info_t.
   */ // }}}
  void test_event_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(event_info_t::command_queue), "command_queue");
    TS_ASSERT_EQUALS(enum2name(event_info_t::command_type), "command_type");
    TS_ASSERT_EQUALS(enum2name(event_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(enum2name(event_info_t::command_execution_status), "command_execution_status");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(event_info_t::context), "context");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<event_info_t>(-1l)), nullptr);
  }
  /** // doc: test_command_type_t() {{{
   * \brief Ensure that enum2name() works with command_type_t.
   */ // }}}
  void test_command_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(command_type_t::ndrange_kernel), "ndrange_kernel");
    TS_ASSERT_EQUALS(enum2name(command_type_t::task), "task");
    TS_ASSERT_EQUALS(enum2name(command_type_t::native_kernel), "native_kernel");
    TS_ASSERT_EQUALS(enum2name(command_type_t::read_buffer), "read_buffer");
    TS_ASSERT_EQUALS(enum2name(command_type_t::write_buffer), "write_buffer");
    TS_ASSERT_EQUALS(enum2name(command_type_t::copy_buffer), "copy_buffer");
    TS_ASSERT_EQUALS(enum2name(command_type_t::read_image), "read_image");
    TS_ASSERT_EQUALS(enum2name(command_type_t::write_image), "write_image");
    TS_ASSERT_EQUALS(enum2name(command_type_t::copy_image), "copy_image");
    TS_ASSERT_EQUALS(enum2name(command_type_t::copy_image_to_buffer), "copy_image_to_buffer");
    TS_ASSERT_EQUALS(enum2name(command_type_t::copy_buffer_to_image), "copy_buffer_to_image");
    TS_ASSERT_EQUALS(enum2name(command_type_t::map_buffer), "map_buffer");
    TS_ASSERT_EQUALS(enum2name(command_type_t::map_image), "map_image");
    TS_ASSERT_EQUALS(enum2name(command_type_t::unmap_mem_object), "unmap_mem_object");
    TS_ASSERT_EQUALS(enum2name(command_type_t::marker), "marker");
    TS_ASSERT_EQUALS(enum2name(command_type_t::acquire_gl_objects), "acquire_gl_objects");
    TS_ASSERT_EQUALS(enum2name(command_type_t::release_gl_objects), "release_gl_objects");
#if CL_VERSION_1_1
    TS_ASSERT_EQUALS(enum2name(command_type_t::read_buffer_rect), "read_buffer_rect");
    TS_ASSERT_EQUALS(enum2name(command_type_t::write_buffer_rect), "write_buffer_rect");
    TS_ASSERT_EQUALS(enum2name(command_type_t::copy_buffer_rect), "copy_buffer_rect");
    TS_ASSERT_EQUALS(enum2name(command_type_t::user), "user");
#endif
#if CL_VERSION_1_2
    TS_ASSERT_EQUALS(enum2name(command_type_t::barrier), "barrier");
    TS_ASSERT_EQUALS(enum2name(command_type_t::migrate_mem_objects), "migrate_mem_objects");
    TS_ASSERT_EQUALS(enum2name(command_type_t::fill_buffer), "fill_buffer");
    TS_ASSERT_EQUALS(enum2name(command_type_t::fill_image), "fill_image");
#endif
    TS_ASSERT_EQUALS(enum2name(static_cast<command_type_t>(-1l)), nullptr);
  }
  /** // doc: test_command_exec_status_t() {{{
   * \brief Ensure that enum2name() works with command_exec_status_t.
   */ // }}}
  void test_command_exec_status_t( )
  {
    //
    // well-defined states
    //
    TS_ASSERT_EQUALS(enum2name(command_exec_status_t::complete), "complete");
    TS_ASSERT_EQUALS(enum2name(command_exec_status_t::running), "running");
    TS_ASSERT_EQUALS(enum2name(command_exec_status_t::submitted), "submitted");
    TS_ASSERT_EQUALS(enum2name(command_exec_status_t::queued), "queued");
    //
    // unknown state
    //
    TS_ASSERT_EQUALS(enum2name(static_cast<command_exec_status_t>(0x7FFF)), nullptr);
    //
    // Error codes should be handled by enum2name(status_t)
    //
    TS_ASSERT_EQUALS(enum2name(static_cast<command_exec_status_t>(status_t::invalid_value)), "invalid_value");
    TS_ASSERT_EQUALS(enum2name(static_cast<command_exec_status_t>(-0x7FFF)), nullptr);
  }
#if CL_VERSION_1_1
  /** // doc: test_buffer_create_type_t() {{{
   * \brief Ensure that enum2name() works with buffer_create_type_t.
   */ // }}}
  void test_buffer_create_type_t( )
  {
    TS_ASSERT_EQUALS(enum2name(buffer_create_type_t::region), "region");
    TS_ASSERT_EQUALS(enum2name(static_cast<buffer_create_type_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_profiling_info_t() {{{
   * \brief Ensure that enum2name() works with profiling_info_t.
   */ // }}}
  void test_profiling_info_t( )
  {
    TS_ASSERT_EQUALS(enum2name(profiling_info_t::queued), "queued");
    TS_ASSERT_EQUALS(enum2name(profiling_info_t::submit), "submit");
    TS_ASSERT_EQUALS(enum2name(profiling_info_t::start), "start");
    TS_ASSERT_EQUALS(enum2name(profiling_info_t::end), "end");
    TS_ASSERT_EQUALS(enum2name(static_cast<profiling_info_t>(-1l)), nullptr);
  }
};

#endif /* CLXX_UTIL_ENUM2NAME_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
