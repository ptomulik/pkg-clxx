// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/enum2name.hpp

/** // doc: clxx/util/enum2name.hpp {{{
 * \file clxx/util/enum2name.hpp
 * \brief Provides enum2namen() function.
 */ // }}}
#ifndef CLXX_UTIL_ENUM2NAME_HPP_INCLUDED
#define CLXX_UTIL_ENUM2NAME_HPP_INCLUDED

#include <clxx/types.hpp>
#include <stdexcept>
#include <type_traits>

namespace clxx {
/** // doc: enum2name(status_t, char const*) {{{
 * \brief Convert #status_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(status_t x, char const* dflt = nullptr) noexcept
{
  return  (x == status_t::success) ? "success" :
          (x == status_t::device_not_found) ? "device_not_found" :
          (x == status_t::device_not_available) ? "device_not_available" :
          (x == status_t::compiler_not_available) ? "compiler_not_available" :
          (x == status_t::mem_object_allocation_failure) ? "mem_object_allocation_failure" :
          (x == status_t::out_of_resources) ? "out_of_resources" :
          (x == status_t::out_of_host_memory) ? "out_of_host_memory" :
          (x == status_t::profiling_info_not_available) ? "profiling_info_not_available" :
          (x == status_t::mem_copy_overlap) ? "mem_copy_overlap" :
          (x == status_t::image_format_mismatch) ? "image_format_mismatch" :
          (x == status_t::image_format_not_supported) ? "image_format_not_supported" :
          (x == status_t::build_program_failure) ? "build_program_failure" :
          (x == status_t::map_failure) ? "map_failure" :
#if CLXX_CL_H_VERSION_1_1
          (x == status_t::misaligned_sub_buffer_offset) ? "misaligned_sub_buffer_offset" :
          (x == status_t::exec_status_error_for_events_in_wait_list) ? "exec_status_error_for_events_in_wait_list" :
#endif
#if CLXX_CL_H_VERSION_1_2
          (x == status_t::compile_program_failure) ? "compile_program_failure" :
          (x == status_t::linker_not_available) ? "linker_not_available" :
          (x == status_t::link_program_failure) ? "link_program_failure" :
          (x == status_t::device_partition_failed) ? "device_partition_failed" :
          (x == status_t::kernel_arg_info_not_available) ? "kernel_arg_info_not_available" :
#endif
          (x == status_t::invalid_value) ? "invalid_value" :
          (x == status_t::invalid_device_type) ? "invalid_device_type" :
          (x == status_t::invalid_platform) ? "invalid_platform" :
          (x == status_t::invalid_device) ? "invalid_device" :
          (x == status_t::invalid_context) ? "invalid_context" :
          (x == status_t::invalid_queue_properties) ? "invalid_queue_properties" :
          (x == status_t::invalid_command_queue) ? "invalid_command_queue" :
          (x == status_t::invalid_host_ptr) ? "invalid_host_ptr" :
          (x == status_t::invalid_mem_object) ? "invalid_mem_object" :
          (x == status_t::invalid_image_format_descriptor) ? "invalid_image_format_descriptor" :
          (x == status_t::invalid_image_size) ? "invalid_image_size" :
          (x == status_t::invalid_sampler) ? "invalid_sampler" :
          (x == status_t::invalid_binary) ? "invalid_binary" :
          (x == status_t::invalid_build_options) ? "invalid_build_options" :
          (x == status_t::invalid_program) ? "invalid_program" :
          (x == status_t::invalid_program_executable) ? "invalid_program_executable" :
          (x == status_t::invalid_kernel_name) ? "invalid_kernel_name" :
          (x == status_t::invalid_kernel_definition) ? "invalid_kernel_definition" :
          (x == status_t::invalid_kernel) ? "invalid_kernel" :
          (x == status_t::invalid_arg_index) ? "invalid_arg_index" :
          (x == status_t::invalid_arg_value) ? "invalid_arg_value" :
          (x == status_t::invalid_arg_size) ? "invalid_arg_size" :
          (x == status_t::invalid_kernel_args) ? "invalid_kernel_args" :
          (x == status_t::invalid_work_dimension) ? "invalid_work_dimension" :
          (x == status_t::invalid_work_group_size) ? "invalid_work_group_size" :
          (x == status_t::invalid_work_item_size) ? "invalid_work_item_size" :
          (x == status_t::invalid_global_offset) ? "invalid_global_offset" :
          (x == status_t::invalid_event_wait_list) ? "invalid_event_wait_list" :
          (x == status_t::invalid_event) ? "invalid_event" :
          (x == status_t::invalid_operation) ? "invalid_operation" :
          (x == status_t::invalid_gl_object) ? "invalid_gl_object" :
          (x == status_t::invalid_buffer_size) ? "invalid_buffer_size" :
          (x == status_t::invalid_mip_level) ? "invalid_mip_level" :
          (x == status_t::invalid_global_work_size) ? "invalid_global_work_size" :
#if CLXX_CL_H_VERSION_1_1
          (x == status_t::invalid_property) ? "invalid_property" :
#endif
#if CLXX_CL_H_VERSION_1_2
          (x == status_t::invalid_image_descriptor) ? "invalid_image_descriptor" :
          (x == status_t::invalid_compiler_options) ? "invalid_compiler_options" :
          (x == status_t::invalid_linker_options) ? "invalid_linker_options" :
          (x == status_t::invalid_device_partition_count) ? "invalid_device_partition_count" :
#endif
#if CLXX_CL_H_VERSION_2_0
          (x == status_t::invalid_pipe_size) ? "invalid_pipe_size" :
          (x == status_t::invalid_device_queue) ? "invalid_device_queue" :
#endif
#if cl_khr_icd
          (x == status_t::platform_not_found_khr) ? "platform_not_found_khr" :
#endif
#if cl_ext_device_fission
          (x == status_t::device_partition_failed_ext) ? "device_partition_failed_ext" :
          (x == status_t::invalid_partition_count_ext) ? "invalid_partition_count_ext" :
          (x == status_t::invalid_partition_name_ext) ? "invalid_partition_name_ext" :
#endif
#if cl_khr_gl_sharing
          (x == status_t::invalid_gl_sharegroup_reference_khr) ? "invalid_gl_sharegroup_reference_khr" :
#endif
#if cl_khr_dx9_media_sharing
          (x == status_t::invalid_dx9_media_adapter_khr) ? "invalid_dx9_media_adapter_khr" :
          (x == status_t::invalid_dx9_media_surface_khr) ? "invalid_dx9_media_surface_khr" :
          (x == status_t::dx9_media_surface_already_acquired_khr) ? "dx9_media_surface_already_acquired_khr" :
          (x == status_t::dx9_media_surface_not_acquired_khr) ? "dx9_media_surface_not_acquired_khr" :
#endif
#if cl_khr_d3d10_sharing
          (x == status_t::invalid_d3d10_device_khr) ? "invalid_d3d10_device_khr" :
          (x == status_t::invalid_d3d10_resource_khr) ? "invalid_d3d10_resource_khr" :
          (x == status_t::d3d10_resource_already_acquired_khr) ? "d3d10_resource_already_acquired_khr" :
          (x == status_t::d3d10_resource_not_acquired_khr) ? "d3d10_resource_not_acquired_khr" :
#endif
#if cl_khr_d3d11_sharing
          (x == status_t::invalid_d3d11_device_khr) ? "invalid_d3d11_device_khr" :
          (x == status_t::invalid_d3d11_resource_khr) ? "invalid_d3d11_resource_khr" :
          (x == status_t::d3d11_resource_already_acquired_khr) ? "d3d11_resource_already_acquired_khr" :
          (x == status_t::d3d11_resource_not_acquired_khr) ? "d3d11_resource_not_acquired_khr" :
#endif
          dflt;
}
/** // doc: enum2name(platform_info_t, char const*) {{{
 * \brief Convert #platform_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(platform_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == platform_info_t::profile) ? "profile" :
          (x == platform_info_t::version) ? "version" :
          (x == platform_info_t::name) ? "name" :
          (x == platform_info_t::vendor) ? "vendor" :
          (x == platform_info_t::extensions) ? "extensions" :
          dflt;
}
/** // doc: enum2name(device_type_t, char const*) {{{
 * \brief Convert #device_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(device_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_type_t::none) ? "none" :
          (x == device_type_t::default_) ? "default_" :
          (x == device_type_t::cpu) ? "cpu" :
          (x == device_type_t::gpu) ? "gpu" :
          (x == device_type_t::accelerator) ? "accelerator" :
#if CLXX_CL_H_VERSION_1_2
          (x == device_type_t::custom) ? "custom" :
#endif
          (x == device_type_t::all) ? "all" :
          dflt;
}
/** // doc: enum2name(device_info_t, char const*) {{{
 * \brief Convert #device_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(device_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_info_t::type) ? "type" :
          (x == device_info_t::vendor_id) ? "vendor_id" :
          (x == device_info_t::max_compute_units) ? "max_compute_units" :
          (x == device_info_t::max_work_item_dimensions) ? "max_work_item_dimensions" :
          (x == device_info_t::max_work_group_size) ? "max_work_group_size" :
          (x == device_info_t::max_work_item_sizes) ? "max_work_item_sizes" :
          (x == device_info_t::preferred_vector_width_char) ? "preferred_vector_width_char" :
          (x == device_info_t::preferred_vector_width_short) ? "preferred_vector_width_short" :
          (x == device_info_t::preferred_vector_width_int) ? "preferred_vector_width_int" :
          (x == device_info_t::preferred_vector_width_long) ? "preferred_vector_width_long" :
          (x == device_info_t::preferred_vector_width_float) ? "preferred_vector_width_float" :
          (x == device_info_t::preferred_vector_width_double) ? "preferred_vector_width_double" :
          (x == device_info_t::max_clock_frequency) ? "max_clock_frequency" :
          (x == device_info_t::address_bits) ? "address_bits" :
          (x == device_info_t::max_read_image_args) ? "max_read_image_args" :
          (x == device_info_t::max_write_image_args) ? "max_write_image_args" :
          (x == device_info_t::max_mem_alloc_size) ? "max_mem_alloc_size" :
          (x == device_info_t::image2d_max_width) ? "image2d_max_width" :
          (x == device_info_t::image2d_max_height) ? "image2d_max_height" :
          (x == device_info_t::image3d_max_width) ? "image3d_max_width" :
          (x == device_info_t::image3d_max_height) ? "image3d_max_height" :
          (x == device_info_t::image3d_max_depth) ? "image3d_max_depth" :
          (x == device_info_t::image_support) ? "image_support" :
          (x == device_info_t::max_parameter_size) ? "max_parameter_size" :
          (x == device_info_t::max_samplers) ? "max_samplers" :
          (x == device_info_t::mem_base_addr_align) ? "mem_base_addr_align" :
          (x == device_info_t::min_data_type_align_size) ? "min_data_type_align_size" :
          (x == device_info_t::single_fp_config) ? "single_fp_config" :
          (x == device_info_t::global_mem_cache_type) ? "global_mem_cache_type" :
          (x == device_info_t::global_mem_cacheline_size) ? "global_mem_cacheline_size" :
          (x == device_info_t::global_mem_cache_size) ? "global_mem_cache_size" :
          (x == device_info_t::global_mem_size) ? "global_mem_size" :
          (x == device_info_t::max_constant_buffer_size) ? "max_constant_buffer_size" :
          (x == device_info_t::max_constant_args) ? "max_constant_args" :
          (x == device_info_t::local_mem_type) ? "local_mem_type" :
          (x == device_info_t::local_mem_size) ? "local_mem_size" :
          (x == device_info_t::error_correction_support) ? "error_correction_support" :
          (x == device_info_t::profiling_timer_resolution) ? "profiling_timer_resolution" :
          (x == device_info_t::endian_little) ? "endian_little" :
          (x == device_info_t::available) ? "available" :
          (x == device_info_t::compiler_available) ? "compiler_available" :
          (x == device_info_t::execution_capabilities) ? "execution_capabilities" :
          (x == device_info_t::queue_properties) ? "queue_properties" :
          (x == device_info_t::name) ? "name" :
          (x == device_info_t::vendor) ? "vendor" :
          (x == device_info_t::driver_version) ? "driver_version" :
          (x == device_info_t::profile) ? "profile" :
          (x == device_info_t::version) ? "version" :
          (x == device_info_t::extensions) ? "extensions" :
          (x == device_info_t::platform) ? "platform" :
#if CLXX_CL_H_VERSION_1_2
          (x == device_info_t::double_fp_config) ? "double_fp_config" :
#endif
#if CLXX_CL_H_VERSION_1_1
          (x == device_info_t::preferred_vector_width_half) ? "preferred_vector_width_half" :
          (x == device_info_t::host_unified_memory) ? "host_unified_memory" :
          (x == device_info_t::native_vector_width_char) ? "native_vector_width_char" :
          (x == device_info_t::native_vector_width_short) ? "native_vector_width_short" :
          (x == device_info_t::native_vector_width_int) ? "native_vector_width_int" :
          (x == device_info_t::native_vector_width_long) ? "native_vector_width_long" :
          (x == device_info_t::native_vector_width_float) ? "native_vector_width_float" :
          (x == device_info_t::native_vector_width_double) ? "native_vector_width_double" :
          (x == device_info_t::native_vector_width_half) ? "native_vector_width_half" :
          (x == device_info_t::opencl_c_version) ? "opencl_c_version" :
#endif
#if CLXX_CL_H_VERSION_1_2
          (x == device_info_t::linker_available) ? "linker_available" :
          (x == device_info_t::built_in_kernels) ? "built_in_kernels" :
          (x == device_info_t::image_max_buffer_size) ? "image_max_buffer_size" :
          (x == device_info_t::image_max_array_size) ? "image_max_array_size" :
          (x == device_info_t::parent_device) ? "parent_device" :
          (x == device_info_t::partition_max_sub_devices) ? "partition_max_sub_devices" :
          (x == device_info_t::partition_properties) ? "partition_properties" :
          (x == device_info_t::partition_affinity_domain) ? "partition_affinity_domain" :
          (x == device_info_t::partition_type) ? "partition_type" :
          (x == device_info_t::reference_count) ? "reference_count" :
          (x == device_info_t::preferred_interop_user_sync) ? "preferred_interop_user_sync" :
          (x == device_info_t::printf_buffer_size) ? "printf_buffer_size" :
          (x == device_info_t::image_pitch_alignment) ? "image_pitch_alignment" :
          (x == device_info_t::image_base_address_alignment) ? "image_base_address_alignment" :
#endif
          dflt;
}
/** // doc: enum2name(device_fp_config_t, char const*) {{{
 * \brief Convert #device_fp_config_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(device_fp_config_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_fp_config_t::none) ? "none" :
          (x == device_fp_config_t::denorm) ? "denorm" :
          (x == device_fp_config_t::inf_nan) ? "inf_nan" :
          (x == device_fp_config_t::round_to_nearest) ? "round_to_nearest" :
          (x == device_fp_config_t::round_to_zero) ? "round_to_zero" :
          (x == device_fp_config_t::round_to_inf) ? "round_to_inf" :
          (x == device_fp_config_t::fma) ? "fma" :
#if CLXX_CL_H_VERSION_1_1
          (x == device_fp_config_t::soft_float) ? "soft_float" :
#endif
#if CLXX_CL_H_VERSION_1_2
          (x == device_fp_config_t::correctly_rounded_divide_sqrt) ? "correctly_rounded_divide_sqrt" :
#endif
          dflt;
}
/** // doc: enum2name(device_mem_cache_type_t, char const*) {{{
 * \brief Convert #device_mem_cache_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(device_mem_cache_type_t x, char const* dflt = nullptr) noexcept
{
  return (x == device_mem_cache_type_t::none) ? "none" :
         (x == device_mem_cache_type_t::read_only_cache) ? "read_only_cache" :
         (x == device_mem_cache_type_t::read_write_cache) ? "read_write_cache" :
          dflt;
}
/** // doc: enum2name(device_local_mem_type_t, char const*) {{{
 * \brief Convert #device_local_mem_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(device_local_mem_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_local_mem_type_t::local) ? "local" :
          (x == device_local_mem_type_t::global) ? "global" :
          dflt;
}
/** // doc: enum2name(device_exec_capabilities_t, char const*) {{{
 * \brief Convert #device_exec_capabilities_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(device_exec_capabilities_t x, char const* dflt = nullptr) noexcept
{
  return (x == device_exec_capabilities_t::none) ? "none" :
         (x == device_exec_capabilities_t::kernel) ? "kernel" :
         (x == device_exec_capabilities_t::native_kernel) ? "native_kernel" :
          dflt;
}
/** // doc: enum2name(command_queue_properties_t, char const*) {{{
 * \brief Convert #command_queue_properties_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(command_queue_properties_t x, char const* dflt = nullptr) noexcept
{
  return  (x == command_queue_properties_t::none) ? "none" :
          (x == command_queue_properties_t::out_of_order_exec_mode_enable) ? "out_of_order_exec_mode_enable" :
          (x == command_queue_properties_t::profiling_enable) ? "profiling_enable" :
          dflt;
}
/** // doc: enum2name(context_info_t, char const*) {{{
 * \brief Convert #context_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(context_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == context_info_t::reference_count) ? "reference_count" :
          (x == context_info_t::devices) ? "devices" :
          (x == context_info_t::properties) ? "properties" :
#if CLXX_CL_H_VERSION_1_1
          (x == context_info_t::num_devices) ? "num_devices" :
#endif
          dflt;
}
/** // doc: enum2name(context_properties_t, char const*) {{{
 * \brief Convert #context_properties_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(context_properties_t x, char const* dflt = nullptr) noexcept
{
  return  (x == context_properties_t::platform) ? "platform" :
#if CLXX_CL_H_VERSION_1_2
          (x == context_properties_t::interop_user_sync) ? "interop_user_sync" :
#endif
#if cl_khr_gl_sharing
          (x == context_properties_t::gl_context_khr) ? "gl_context_khr" :
          (x == context_properties_t::egl_display_khr) ? "egl_display_khr" :
          (x == context_properties_t::glx_display_khr) ? "glx_display_khr" :
          (x == context_properties_t::wgl_hdc_khr) ? "wgl_hdc_khr" :
          (x == context_properties_t::cgl_sharegroup_khr) ? "cgl_sharegroup_khr" :
#endif
#if cl_khr_dx9_media_sharing
          (x == context_properties_t::adapter_d3d9_khr) ? "adapter_d3d9_khr" :
          (x == context_properties_t::adapter_d3d9ex_khr) ? "adapter_d3d9ex_khr" :
          (x == context_properties_t::adapter_dxva_khr) ? "adapter_dxva_khr" :
#endif
#if cl_khr_d3d10_sharing
          (x == context_properties_t::d3d10_device_khr) ? "d3d10_device_khr" :
#endif
#if cl_khr_d3d11_sharing
          (x == context_properties_t::d3d11_device_khr) ? "d3d11_device_khr" :
#endif
          dflt;
}
/** // doc: enum2name(device_partition_property_t, char const*) {{{
 * \brief Convert #device_partition_property_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(device_partition_property_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_partition_property_t::equally) ? "equally" :
          (x == device_partition_property_t::by_counts) ? "by_counts" :
          (x == device_partition_property_t::by_counts_list_end) ? "by_counts_list_end" :
          (x == device_partition_property_t::by_affinity_domain) ? "by_affinity_domain" :
          dflt;
}
#endif
/** // doc: enum2name(device_affinity_domain_t, char const*) {{{
 * \brief Convert #device_affinity_domain_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(device_affinity_domain_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_affinity_domain_t::none) ? "none" :
          (x == device_affinity_domain_t::numa) ? "numa" :
          (x == device_affinity_domain_t::l4_cache) ? "l4_cache" :
          (x == device_affinity_domain_t::l3_cache) ? "l3_cache" :
          (x == device_affinity_domain_t::l2_cache) ? "l2_cache" :
          (x == device_affinity_domain_t::l1_cache) ? "l1_cache" :
          (x == device_affinity_domain_t::next_partitionable) ? "next_partitionable" :
          dflt;
}
#endif
/** // doc: enum2name(command_queue_info_t, char const*) {{{
 * \brief Convert #command_queue_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(command_queue_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == command_queue_info_t::context) ? "context" :
          (x == command_queue_info_t::device) ? "device" :
          (x == command_queue_info_t::reference_count) ? "reference_count" :
          (x == command_queue_info_t::properties) ? "properties" :
          dflt;
}
/** // doc: enum2name(mem_flags_t, char const*) {{{
 * \brief Convert #mem_flags_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(mem_flags_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_flags_t::none) ? "none" :
          (x == mem_flags_t::read_write) ? "read_write" :
          (x == mem_flags_t::write_only) ? "write_only" :
          (x == mem_flags_t::read_only) ? "read_only" :
          (x == mem_flags_t::use_host_ptr) ? "use_host_ptr" :
          (x == mem_flags_t::alloc_host_ptr) ? "alloc_host_ptr" :
          (x == mem_flags_t::copy_host_ptr) ? "copy_host_ptr" :
#if CLXX_CL_H_VERSION_1_2
          (x == mem_flags_t::host_write_only) ? "host_write_only" :
          (x == mem_flags_t::host_read_only) ? "host_read_only" :
          (x == mem_flags_t::host_no_access) ? "host_no_access" :
#endif
          dflt;
}
/** // doc: enum2name(mem_migration_flags_t, char const*) {{{
 * \brief Convert #mem_migration_flags_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(mem_migration_flags_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_migration_flags_t::none) ? "none" :
          (x == mem_migration_flags_t::mem_object_host) ? "mem_object_host" :
          (x == mem_migration_flags_t::mem_object_content_undefined) ? "mem_object_content_undefined" :
          dflt;
}
#endif
/** // doc: enum2name(channel_order_t, char const*) {{{
 * \brief Convert #channel_order_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(channel_order_t x, char const* dflt = nullptr) noexcept
{
  return  (x == channel_order_t::r) ? "r" :
          (x == channel_order_t::a) ? "a" :
          (x == channel_order_t::rg) ? "rg" :
          (x == channel_order_t::ra) ? "ra" :
          (x == channel_order_t::rgb) ? "rgb" :
          (x == channel_order_t::rgba) ? "rgba" :
          (x == channel_order_t::bgra) ? "bgra" :
          (x == channel_order_t::argb) ? "argb" :
          (x == channel_order_t::intensity) ? "intensity" :
          (x == channel_order_t::luminance) ? "luminance" :
#if CLXX_CL_H_VERSION_1_1
          (x == channel_order_t::rx) ? "rx" :
          (x == channel_order_t::rgx) ? "rgx" :
          (x == channel_order_t::rgbx) ? "rgbx" :
#endif
#if CLXX_CL_H_VERSION_1_2
          (x == channel_order_t::depth) ? "depth" :
          (x == channel_order_t::depth_stencil) ? "depth_stencil" :
#endif
          dflt;
}
/** // doc: enum2name(channel_type_t, char const*) {{{
 * \brief Convert #channel_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(channel_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == channel_type_t::snorm_int8) ? "snorm_int8" :
          (x == channel_type_t::snorm_int16) ? "snorm_int16" :
          (x == channel_type_t::unorm_int8) ? "unorm_int8" :
          (x == channel_type_t::unorm_int16) ? "unorm_int16" :
          (x == channel_type_t::unorm_short_565) ? "unorm_short_565" :
          (x == channel_type_t::unorm_short_555) ? "unorm_short_555" :
          (x == channel_type_t::unorm_int_101010) ? "unorm_int_101010" :
          (x == channel_type_t::signed_int8) ? "signed_int8" :
          (x == channel_type_t::signed_int16) ? "signed_int16" :
          (x == channel_type_t::signed_int32) ? "signed_int32" :
          (x == channel_type_t::unsigned_int8) ? "unsigned_int8" :
          (x == channel_type_t::unsigned_int16) ? "unsigned_int16" :
          (x == channel_type_t::unsigned_int32) ? "unsigned_int32" :
          (x == channel_type_t::half_float) ? "half_float" :
          (x == channel_type_t::float_) ? "float_" :
#if CLXX_CL_H_VERSION_1_2
          (x == channel_type_t::unorm_int24) ? "unorm_int24" :
#endif
          dflt;
}
/** // doc: enum2name(mem_object_type_t, char const*) {{{
 * \brief Convert #mem_object_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(mem_object_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_object_type_t::buffer) ? "buffer" :
          (x == mem_object_type_t::image2d) ? "image2d" :
          (x == mem_object_type_t::image3d) ? "image3d" :
#if CLXX_CL_H_VERSION_1_2
          (x == mem_object_type_t::image2d_array) ? "image2d_array" :
          (x == mem_object_type_t::image1d) ? "image1d" :
          (x == mem_object_type_t::image1d_array) ? "image1d_array" :
          (x == mem_object_type_t::image1d_buffer) ? "image1d_buffer" :
#endif
          dflt;
}
/** // doc: enum2name(mem_info_t, char const*) {{{
 * \brief Convert #mem_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(mem_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_info_t::type) ? "type" :
          (x == mem_info_t::flags) ? "flags" :
          (x == mem_info_t::size) ? "size" :
          (x == mem_info_t::host_ptr) ? "host_ptr" :
          (x == mem_info_t::map_count) ? "map_count" :
          (x == mem_info_t::reference_count) ? "reference_count" :
          (x == mem_info_t::context) ? "context" :
#if CLXX_CL_H_VERSION_1_1
          (x == mem_info_t::associated_memobject) ? "associated_memobject" :
          (x == mem_info_t::offset) ? "offset" :
#endif
          dflt;
}
/** // doc: enum2name(image_info_t, char const*) {{{
 * \brief Convert #image_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(image_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == image_info_t::format) ? "format" :
          (x == image_info_t::element_size) ? "element_size" :
          (x == image_info_t::row_pitch) ? "row_pitch" :
          (x == image_info_t::slice_pitch) ? "slice_pitch" :
          (x == image_info_t::width) ? "width" :
          (x == image_info_t::height) ? "height" :
          (x == image_info_t::depth) ? "depth" :
#if CLXX_CL_H_VERSION_1_2
          (x == image_info_t::array_size) ? "array_size" :
          (x == image_info_t::buffer) ? "buffer" :
          (x == image_info_t::num_mip_levels) ? "num_mip_levels" :
          (x == image_info_t::num_samples) ? "num_samples" :
#endif
          dflt;
}
/** // doc: enum2name(addressing_mode_t, char const*) {{{
 * \brief Convert #addressing_mode_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(addressing_mode_t x, char const* dflt = nullptr) noexcept
{
  return  (x == addressing_mode_t::none) ? "none" :
          (x == addressing_mode_t::clamp_to_edge) ? "clamp_to_edge" :
          (x == addressing_mode_t::clamp) ? "clamp" :
          (x == addressing_mode_t::repeat) ? "repeat" :
#if CLXX_CL_H_VERSION_1_1
          (x == addressing_mode_t::mirrored_repeat) ? "mirrored_repeat" :
#endif
          dflt;
}
/** // doc: enum2name(filter_mode_t, char const*) {{{
 * \brief Convert #filter_mode_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(filter_mode_t x, char const* dflt = nullptr) noexcept
{
  return  (x == filter_mode_t::nearest) ? "nearest" :
          (x == filter_mode_t::linear) ? "linear" :
          dflt;
}
/** // doc: enum2name(sampler_info_t, char const*) {{{
 * \brief Convert #sampler_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(sampler_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == sampler_info_t::reference_count) ? "reference_count" :
          (x == sampler_info_t::context) ? "context" :
          (x == sampler_info_t::normalized_coords) ? "normalized_coords" :
          (x == sampler_info_t::addressing_mode) ? "addressing_mode" :
          (x == sampler_info_t::filter_mode) ? "filter_mode" :
          dflt;
}
/** // doc: enum2name(mem_flags_t, char const*) {{{
 * \brief Convert #map_flags_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(map_flags_t x, char const* dflt = nullptr) noexcept
{
  return  (x == map_flags_t::none) ? "none" :
          (x == map_flags_t::read) ? "read" :
          (x == map_flags_t::write) ? "write" :
#if CLXX_CL_H_VERSION_1_2
          (x == map_flags_t::write_invalidate_region) ? "write_invalidate_region" :
#endif
          dflt;
}
/** // doc: enum2name(program_info_t, char const*) {{{
 * \brief Convert #program_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(program_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == program_info_t::reference_count) ? "reference_count" :
          (x == program_info_t::context) ? "context" :
          (x == program_info_t::num_devices) ? "num_devices" :
          (x == program_info_t::devices) ? "devices" :
          (x == program_info_t::source) ? "source" :
          (x == program_info_t::binary_sizes) ? "binary_sizes" :
          (x == program_info_t::binaries) ? "binaries" :
#if CLXX_CL_H_VERSION_1_2
          (x == program_info_t::num_kernels) ? "num_kernels" :
          (x == program_info_t::kernel_names) ? "kernel_names" :
#endif
          dflt;
}
/** // doc: enum2name(program_build_info_t, char const*) {{{
 * \brief Convert #program_build_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(program_build_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == program_build_info_t::status) ? "status" :
          (x == program_build_info_t::options) ? "options" :
          (x == program_build_info_t::log) ? "log" :
#if CLXX_CL_H_VERSION_1_2
          (x == program_build_info_t::binary_type) ? "binary_type" :
#endif
          dflt;
}
/** // doc: enum2name(program_binary_type_t, char const*) {{{
 * \brief Convert #program_binary_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(program_binary_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == program_binary_type_t::none) ? "none" :
          (x == program_binary_type_t::compiled_object) ? "compiled_object" :
          (x == program_binary_type_t::library) ? "library" :
          (x == program_binary_type_t::executable) ? "executable" :
          dflt;
}
#endif
/** // doc: enum2name(build_status_t, char const*) {{{
 * \brief Convert #build_status_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(build_status_t x, char const* dflt = nullptr) noexcept
{
  return  (x == build_status_t::success) ? "success" :
          (x == build_status_t::none) ? "none" :
          (x == build_status_t::error) ? "error" :
          (x == build_status_t::in_progress) ? "in_progress" :
          dflt;
}
/** // doc: enum2name(kernel_info_t, char const*) {{{
 * \brief Convert #kernel_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(kernel_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_info_t::function_name) ? "function_name" :
          (x == kernel_info_t::num_args) ? "num_args" :
          (x == kernel_info_t::reference_count) ? "reference_count" :
          (x == kernel_info_t::context) ? "context" :
          (x == kernel_info_t::program) ? "program" :
#if CLXX_CL_H_VERSION_1_2
          (x == kernel_info_t::attributes) ? "attributes" :
#endif
          dflt;
}
/** // doc: enum2name(kernel_arg_info_t, char const*) {{{
 * \brief Convert #kernel_arg_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(kernel_arg_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_info_t::address_qualifier) ? "address_qualifier" :
          (x == kernel_arg_info_t::access_qualifier) ? "access_qualifier" :
          (x == kernel_arg_info_t::type_name) ? "type_name" :
          (x == kernel_arg_info_t::type_qualifier) ? "type_qualifier" :
          (x == kernel_arg_info_t::name) ? "name" :
          dflt;
}
#endif
/** // doc: enum2name(kernel_arg_address_qualifier_t, char const*) {{{
 * \brief Convert #kernel_arg_address_qualifier_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(kernel_arg_address_qualifier_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_address_qualifier_t::global) ? "global" :
          (x == kernel_arg_address_qualifier_t::local) ? "local" :
          (x == kernel_arg_address_qualifier_t::constant) ? "constant" :
          (x == kernel_arg_address_qualifier_t::private_) ? "private_" :
          dflt;
}
#endif
/** // doc: enum2name(kernel_arg_access_qualifier_t, char const*) {{{
 * \brief Convert #kernel_arg_access_qualifier_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(kernel_arg_access_qualifier_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_access_qualifier_t::read_only) ? "read_only" :
          (x == kernel_arg_access_qualifier_t::write_only) ? "write_only" :
          (x == kernel_arg_access_qualifier_t::read_write) ? "read_write" :
          (x == kernel_arg_access_qualifier_t::none) ? "none" :
          dflt;
}
#endif
/** // doc: enum2name(kernel_arg_type_qualifier_t, char const*) {{{
 * \brief Convert #kernel_arg_type_qualifier_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_2
constexpr char const*
enum2name(kernel_arg_type_qualifier_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_type_qualifier_t::none) ? "none" :
          (x == kernel_arg_type_qualifier_t::const_) ? "const_" :
          (x == kernel_arg_type_qualifier_t::restrict_) ? "restrict_" :
          (x == kernel_arg_type_qualifier_t::volatile_) ? "volatile_" :
          dflt;
}
#endif
/** // doc: enum2name(kernel_work_group_info_t, char const*) {{{
 * \brief Convert #kernel_work_group_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(kernel_work_group_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_work_group_info_t::work_group_size) ? "work_group_size" :
          (x == kernel_work_group_info_t::compile_work_group_size) ? "compile_work_group_size" :
          (x == kernel_work_group_info_t::local_mem_size) ? "local_mem_size" :
#if CLXX_CL_H_VERSION_1_1
          (x == kernel_work_group_info_t::preferred_work_group_size_multiple) ? "preferred_work_group_size_multiple" :
          (x == kernel_work_group_info_t::private_mem_size) ? "private_mem_size" :
#endif
#if CLXX_CL_H_VERSION_1_2
          (x == kernel_work_group_info_t::global_work_size) ? "global_work_size" :
#endif
          dflt;
}
/** // doc: enum2name(event_info_t, char const*) {{{
 * \brief Convert #event_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(event_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == event_info_t::command_queue) ? "command_queue" :
          (x == event_info_t::command_type) ? "command_type" :
          (x == event_info_t::reference_count) ? "reference_count" :
          (x == event_info_t::command_execution_status) ? "command_execution_status" :
#if CLXX_CL_H_VERSION_1_1
          (x == event_info_t::context) ? "context" :
#endif
          dflt;
}
/** // doc: enum2name(command_type_t, char const*) {{{
 * \brief Convert #command_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(command_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == command_type_t::ndrange_kernel) ? "ndrange_kernel" :
          (x == command_type_t::task) ? "task" :
          (x == command_type_t::native_kernel) ? "native_kernel" :
          (x == command_type_t::read_buffer) ? "read_buffer" :
          (x == command_type_t::write_buffer) ? "write_buffer" :
          (x == command_type_t::copy_buffer) ? "copy_buffer" :
          (x == command_type_t::read_image) ? "read_image" :
          (x == command_type_t::write_image) ? "write_image" :
          (x == command_type_t::copy_image) ? "copy_image" :
          (x == command_type_t::copy_image_to_buffer) ? "copy_image_to_buffer" :
          (x == command_type_t::copy_buffer_to_image) ? "copy_buffer_to_image" :
          (x == command_type_t::map_buffer) ? "map_buffer" :
          (x == command_type_t::map_image) ? "map_image" :
          (x == command_type_t::unmap_mem_object) ? "unmap_mem_object" :
          (x == command_type_t::marker) ? "marker" :
          (x == command_type_t::acquire_gl_objects) ? "acquire_gl_objects" :
          (x == command_type_t::release_gl_objects) ? "release_gl_objects" :
#if CLXX_CL_H_VERSION_1_1
          (x == command_type_t::read_buffer_rect) ? "read_buffer_rect" :
          (x == command_type_t::write_buffer_rect) ? "write_buffer_rect" :
          (x == command_type_t::copy_buffer_rect) ? "copy_buffer_rect" :
          (x == command_type_t::user) ? "user" :
#endif
#if CLXX_CL_H_VERSION_1_2
          (x == command_type_t::barrier) ? "barrier" :
          (x == command_type_t::migrate_mem_objects) ? "migrate_mem_objects" :
          (x == command_type_t::fill_buffer) ? "fill_buffer" :
          (x == command_type_t::fill_image) ? "fill_image" :
#endif
          dflt;
}
/** // doc: enum2name(command_exec_status_t, char const*) {{{
 * \brief Convert #command_exec_status_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(command_exec_status_t x, char const* dflt = nullptr) noexcept
{
  return (x == command_exec_status_t::complete) ? "complete" :
         (x == command_exec_status_t::running) ? "running" :
         (x == command_exec_status_t::submitted) ? "submitted" :
         (x == command_exec_status_t::queued) ? "queued" :
         enum2name(static_cast<status_t>(x), dflt);
}
/** // doc: enum2name(buffer_create_type_t, char const*) {{{
 * \brief Convert #buffer_create_type_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
#if CLXX_CL_H_VERSION_1_1
constexpr char const*
enum2name(buffer_create_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == buffer_create_type_t::region) ? "region" :
          dflt;
}
#endif
/** // doc: enum2name(profiling_info_t, char const*) {{{
 * \brief Convert #profiling_info_t to C string (human-readable enum name)
 * \param x The enum value to be converted
 * \param dflt A pointer to string to be returned in case \e x is not recognized by #enum2name()
 * \returns A null-terminated C string containig the enum name of value \e x
 */ // }}}
constexpr char const*
enum2name(profiling_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == profiling_info_t::queued) ? "queued" :
          (x == profiling_info_t::submit) ? "submit" :
          (x == profiling_info_t::start) ? "start" :
          (x == profiling_info_t::end) ? "end" :
          dflt;
}
} // end namespace clxx

#endif /* CLXX_UTIL_ENUM2NAME_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
