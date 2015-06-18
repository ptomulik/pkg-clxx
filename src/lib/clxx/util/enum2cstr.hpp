// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/enum2cstr.hpp

/** // doc: clxx/util/enum2cstr.hpp {{{
 * \file clxx/util/enum2cstr.hpp
 * \brief Provides enum2cstr() function.
 */ // }}}
#ifndef CLXX_UTIL_ENUM2STR_HPP_INCLUDED
#define CLXX_UTIL_ENUM2STR_HPP_INCLUDED

#include <clxx/types.hpp>
#include <stdexcept>
#include <type_traits>

namespace clxx {
/** // doc: enum2cstr(status_t, char const*) {{{
 * \brief Convert #status_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(status_t x, char const* dflt = nullptr) noexcept
{
  return  (x == status_t::success) ? "success" :
          (x == status_t::device_not_found) ? "device not found" :
          (x == status_t::device_not_available) ? "device not available" :
          (x == status_t::compiler_not_available) ? "compiler not available" :
          (x == status_t::mem_object_allocation_failure) ? "memory object allocation failure" :
          (x == status_t::out_of_resources) ? "out of resources" :
          (x == status_t::out_of_host_memory) ? "out of host memory" :
          (x == status_t::profiling_info_not_available) ? "profiling info not available" :
          (x == status_t::mem_copy_overlap) ? "memory copy overlap" :
          (x == status_t::image_format_mismatch) ? "image format mismatch" :
          (x == status_t::image_format_not_supported) ? "image format not supported" :
          (x == status_t::build_program_failure) ? "build program failure" :
          (x == status_t::map_failure) ? "map failure" :
#if CL_VERSION_1_1
          (x == status_t::misaligned_sub_buffer_offset) ? "misaligned sub buffer offset" :
          (x == status_t::exec_status_error_for_events_in_wait_list) ? "execution status error for events in wait list" :
#endif
#if CL_VERSION_1_2
          (x == status_t::compile_program_failure) ? "compile program failure" :
          (x == status_t::linker_not_available) ? "linker not available" :
          (x == status_t::link_program_failure) ? "link program failure" :
          (x == status_t::device_partition_failed) ? "device partition failed" :
          (x == status_t::kernel_arg_info_not_available) ? "kernel argument info not available" :
#endif
          (x == status_t::invalid_value) ? "invalid value" :
          (x == status_t::invalid_device_type) ? "invalid device type" :
          (x == status_t::invalid_platform) ? "invalid platform" :
          (x == status_t::invalid_device) ? "invalid device" :
          (x == status_t::invalid_context) ? "invalid context" :
          (x == status_t::invalid_queue_properties) ? "invalid queue properties" :
          (x == status_t::invalid_command_queue) ? "invalid command queue" :
          (x == status_t::invalid_host_ptr) ? "invalid host ptr" :
          (x == status_t::invalid_mem_object) ? "invalid memory object" :
          (x == status_t::invalid_image_format_descriptor) ? "invalid image format descriptor" :
          (x == status_t::invalid_image_size) ? "invalid image size" :
          (x == status_t::invalid_sampler) ? "invalid sampler" :
          (x == status_t::invalid_binary) ? "invalid binary" :
          (x == status_t::invalid_build_options) ? "invalid build options" :
          (x == status_t::invalid_program) ? "invalid program" :
          (x == status_t::invalid_program_executable) ? "invalid program executable" :
          (x == status_t::invalid_kernel_name) ? "invalid kernel name" :
          (x == status_t::invalid_kernel_definition) ? "invalid kernel definition" :
          (x == status_t::invalid_kernel) ? "invalid kernel" :
          (x == status_t::invalid_arg_index) ? "invalid argument index" :
          (x == status_t::invalid_arg_value) ? "invalid argument value" :
          (x == status_t::invalid_arg_size) ? "invalid argument size" :
          (x == status_t::invalid_kernel_args) ? "invalid kernel arguments" :
          (x == status_t::invalid_work_dimension) ? "invalid work dimension" :
          (x == status_t::invalid_work_group_size) ? "invalid work group size" :
          (x == status_t::invalid_work_item_size) ? "invalid work item size" :
          (x == status_t::invalid_global_offset) ? "invalid global offset" :
          (x == status_t::invalid_event_wait_list) ? "invalid event wait list" :
          (x == status_t::invalid_event) ? "invalid event" :
          (x == status_t::invalid_operation) ? "invalid operation" :
          (x == status_t::invalid_gl_object) ? "invalid GL object" :
          (x == status_t::invalid_buffer_size) ? "invalid buffer size" :
          (x == status_t::invalid_mip_level) ? "invalid mip level" :
          (x == status_t::invalid_global_work_size) ? "invalid global work size" :
#if CL_VERSION_1_1
          (x == status_t::invalid_property) ? "invalid property" :
#endif
#if CL_VERSION_1_2
          (x == status_t::invalid_image_descriptor) ? "invalid image descriptor" :
          (x == status_t::invalid_compiler_options) ? "invalid compiler options" :
          (x == status_t::invalid_linker_options) ? "invalid linker options" :
          (x == status_t::invalid_device_partition_count) ? "invalid device partition count" :
#endif
#if CL_VERSION_2_0
          (x == status_t::invalid_pipe_size) ? "invalid pipe size" :
          (x == status_t::invalid_device_queue) ? "invalid device queue" :
#endif
#if cl_khr_icd
          (x == status_t::platform_not_found_khr) ? "platform not found khr" :
#endif
#if cl_ext_device_fission
          (x == status_t::device_partition_failed_ext) ? "device partition failed ext" :
          (x == status_t::invalid_partition_count_ext) ? "invalid partition count ext" :
          (x == status_t::invalid_partition_name_ext) ? "invalid partition name ext" :
#endif
#if cl_khr_gl_sharing
          (x == status_t::invalid_gl_sharegroup_reference_khr) ? "invalid gl sharegroup reference khr" :
#endif
#if cl_khr_dx9_media_sharing
          (x == status_t::invalid_dx9_media_adapter_khr) ? "invalid dx9 media adapter khr" :
          (x == status_t::invalid_dx9_media_surface_khr) ? "invalid dx9 media surface khr" :
          (x == status_t::dx9_media_surface_already_acquired_khr) ? "dx9 media surface already acquired khr" :
          (x == status_t::dx9_media_surface_not_acquired_khr) ? "dx9 media surface not acquired khr" :
#endif
#if cl_khr_d3d10_sharing
          (x == status_t::invalid_d3d10_device_khr) ? "invalid d3d10 device khr" :
          (x == status_t::invalid_d3d10_resource_khr) ? "invalid d3d10 resource khr" :
          (x == status_t::d3d10_resource_already_acquired_khr) ? "d3d10 resource already acquired khr" :
          (x == status_t::d3d10_resource_not_acquired_khr) ? "d3d10 resource not acquired khr" :
#endif
#if cl_khr_d3d11_sharing
          (x == status_t::invalid_d3d11_device_khr) ? "invalid d3d11 device khr" :
          (x == status_t::invalid_d3d11_resource_khr) ? "invalid d3d11 resource khr" :
          (x == status_t::d3d11_resource_already_acquired_khr) ? "d3d11 resource already acquired khr" :
          (x == status_t::d3d11_resource_not_acquired_khr) ? "d3d11 resource not acquired khr" :
#endif
          dflt;
}
/** // doc: enum2cstr(platform_info_t, char const*) {{{
 * \brief Convert #platform_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(platform_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == platform_info_t::profile) ? "profile" :
          (x == platform_info_t::version) ? "version" :
          (x == platform_info_t::name) ? "name" :
          (x == platform_info_t::vendor) ? "vendor" :
          (x == platform_info_t::extensions) ? "extensions" :
          dflt;
}
/** // doc: enum2cstr(device_type_t, char const*) {{{
 * \brief Convert #device_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_type_t::none) ? "none" :
          (x == device_type_t::default_) ? "default" :
          (x == device_type_t::cpu) ? "cpu" :
          (x == device_type_t::gpu) ? "gpu" :
          (x == device_type_t::accelerator) ? "accelerator" :
#if CL_VERSION_1_2
          (x == device_type_t::custom) ? "custom" :
#endif
          (x == device_type_t::all) ? "all" :
          dflt;
}
/** // doc: enum2cstr(device_info_t, char const*) {{{
 * \brief Convert #device_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_info_t::type) ? "type" :
          (x == device_info_t::vendor_id) ? "vendor id" :
          (x == device_info_t::max_compute_units) ? "max compute units" :
          (x == device_info_t::max_work_item_dimensions) ? "max work item dimensions" :
          (x == device_info_t::max_work_group_size) ? "max work group size" :
          (x == device_info_t::max_work_item_sizes) ? "max work item sizes" :
          (x == device_info_t::preferred_vector_width_char) ? "preferred vector width char" :
          (x == device_info_t::preferred_vector_width_short) ? "preferred vector width short" :
          (x == device_info_t::preferred_vector_width_int) ? "preferred vector width int" :
          (x == device_info_t::preferred_vector_width_long) ? "preferred vector width long" :
          (x == device_info_t::preferred_vector_width_float) ? "preferred vector width float" :
          (x == device_info_t::preferred_vector_width_double) ? "preferred vector width double" :
          (x == device_info_t::max_clock_frequency) ? "max clock frequency" :
          (x == device_info_t::address_bits) ? "address bits" :
          (x == device_info_t::max_read_image_args) ? "max read image args" :
          (x == device_info_t::max_write_image_args) ? "max write image args" :
          (x == device_info_t::max_mem_alloc_size) ? "max mem alloc size" :
          (x == device_info_t::image2d_max_width) ? "image2d max width" :
          (x == device_info_t::image2d_max_height) ? "image2d max height" :
          (x == device_info_t::image3d_max_width) ? "image3d max width" :
          (x == device_info_t::image3d_max_height) ? "image3d max height" :
          (x == device_info_t::image3d_max_depth) ? "image3d max depth" :
          (x == device_info_t::image_support) ? "image support" :
          (x == device_info_t::max_parameter_size) ? "max parameter size" :
          (x == device_info_t::max_samplers) ? "max samplers" :
          (x == device_info_t::mem_base_addr_align) ? "mem base addr align" :
          (x == device_info_t::min_data_type_align_size) ? "min data type align size" :
          (x == device_info_t::single_fp_config) ? "single fp config" :
          (x == device_info_t::global_mem_cache_type) ? "global mem cache type" :
          (x == device_info_t::global_mem_cacheline_size) ? "global mem cacheline size" :
          (x == device_info_t::global_mem_cache_size) ? "global mem cache size" :
          (x == device_info_t::global_mem_size) ? "global mem size" :
          (x == device_info_t::max_constant_buffer_size) ? "max constant buffer size" :
          (x == device_info_t::max_constant_args) ? "max constant args" :
          (x == device_info_t::local_mem_type) ? "local mem type" :
          (x == device_info_t::local_mem_size) ? "local mem size" :
          (x == device_info_t::error_correction_support) ? "error correction support" :
          (x == device_info_t::profiling_timer_resolution) ? "profiling timer resolution" :
          (x == device_info_t::endian_little) ? "endian little" :
          (x == device_info_t::available) ? "available" :
          (x == device_info_t::compiler_available) ? "compiler available" :
          (x == device_info_t::execution_capabilities) ? "execution capabilities" :
          (x == device_info_t::queue_properties) ? "queue properties" :
          (x == device_info_t::name) ? "name" :
          (x == device_info_t::vendor) ? "vendor" :
          (x == device_info_t::driver_version) ? "driver version" :
          (x == device_info_t::profile) ? "profile" :
          (x == device_info_t::version) ? "version" :
          (x == device_info_t::extensions) ? "extensions" :
          (x == device_info_t::platform) ? "platform" :
#if CL_VERSION_1_2
          (x == device_info_t::double_fp_config) ? "double fp config" :
#endif
#if CL_VERSION_1_1
          (x == device_info_t::preferred_vector_width_half) ? "preferred vector width half" :
          (x == device_info_t::host_unified_memory) ? "host unified memory" :
          (x == device_info_t::native_vector_width_char) ? "native vector width char" :
          (x == device_info_t::native_vector_width_short) ? "native vector width short" :
          (x == device_info_t::native_vector_width_int) ? "native vector width int" :
          (x == device_info_t::native_vector_width_long) ? "native vector width long" :
          (x == device_info_t::native_vector_width_float) ? "native vector width float" :
          (x == device_info_t::native_vector_width_double) ? "native vector width double" :
          (x == device_info_t::native_vector_width_half) ? "native vector width half" :
          (x == device_info_t::opencl_c_version) ? "opencl c version" :
#endif
#if CL_VERSION_1_2
          (x == device_info_t::linker_available) ? "linker available" :
          (x == device_info_t::built_in_kernels) ? "built in kernels" :
          (x == device_info_t::image_max_buffer_size) ? "image max buffer size" :
          (x == device_info_t::image_max_array_size) ? "image max array size" :
          (x == device_info_t::parent_device) ? "parent device" :
          (x == device_info_t::partition_max_sub_devices) ? "partition max sub devices" :
          (x == device_info_t::partition_properties) ? "partition properties" :
          (x == device_info_t::partition_affinity_domain) ? "partition affinity domain" :
          (x == device_info_t::partition_type) ? "partition type" :
          (x == device_info_t::reference_count) ? "reference count" :
          (x == device_info_t::preferred_interop_user_sync) ? "preferred interop user sync" :
          (x == device_info_t::printf_buffer_size) ? "printf buffer size" :
          (x == device_info_t::image_pitch_alignment) ? "image pitch alignment" :
          (x == device_info_t::image_base_address_alignment) ? "image base address alignment" :
#endif
          dflt;
}
/** // doc: enum2cstr(device_fp_config_t, char const*) {{{
 * \brief Convert #device_fp_config_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_fp_config_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_fp_config_t::none) ? "none" :
          (x == device_fp_config_t::denorm) ? "denorm" :
          (x == device_fp_config_t::inf_nan) ? "inf nan" :
          (x == device_fp_config_t::round_to_nearest) ? "round to nearest" :
          (x == device_fp_config_t::round_to_zero) ? "round to zero" :
          (x == device_fp_config_t::round_to_inf) ? "round to inf" :
          (x == device_fp_config_t::fma) ? "fma" :
#if CL_VERSION_1_1
          (x == device_fp_config_t::soft_float) ? "soft float" :
#endif
#if CL_VERSION_1_2
          (x == device_fp_config_t::correctly_rounded_divide_sqrt) ? "correctly rounded divide sqrt" :
#endif
          dflt;
}
/** // doc: enum2cstr(device_mem_cache_type_t, char const*) {{{
 * \brief Convert #device_mem_cache_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_mem_cache_type_t x, char const* dflt = nullptr) noexcept
{
  return (x == device_mem_cache_type_t::none) ? "none" :
         (x == device_mem_cache_type_t::read_only_cache) ? "read-only cache" :
         (x == device_mem_cache_type_t::read_write_cache) ? "read-write cache" :
          dflt;
}
/** // doc: enum2cstr(device_local_mem_type_t, char const*) {{{
 * \brief Convert #device_local_mem_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_local_mem_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_local_mem_type_t::local) ? "local" :
          (x == device_local_mem_type_t::global) ? "global" :
          dflt;
}
/** // doc: enum2cstr(device_exec_capabilities_t, char const*) {{{
 * \brief Convert #device_exec_capabilities_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_exec_capabilities_t x, char const* dflt = nullptr) noexcept
{
  return (x == device_exec_capabilities_t::none) ? "none" :
         (x == device_exec_capabilities_t::kernel) ? "kernel" :
         (x == device_exec_capabilities_t::native_kernel) ? "native_kernel" :
          dflt;
}
/** // doc: enum2cstr(command_queue_properties_t, char const*) {{{
 * \brief Convert #command_queue_properties_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(command_queue_properties_t x, char const* dflt = nullptr) noexcept
{
  return  (x == command_queue_properties_t::none) ? "none" :
          (x == command_queue_properties_t::out_of_order_exec_mode_enable) ? "out_of_order_exec_mode_enable" :
          (x == command_queue_properties_t::profiling_enable) ? "profiling_enable" :
          dflt;
}
/** // doc: enum2cstr(context_info_t, char const*) {{{
 * \brief Convert #context_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(context_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == context_info_t::reference_count) ? "reference count" :
          (x == context_info_t::devices) ? "devices" :
          (x == context_info_t::properties) ? "properties" :
#if CL_VERSION_1_1
          (x == context_info_t::num_devices) ? "num devices" :
#endif
          dflt;
}
/** // doc: enum2cstr(context_properties_t, char const*) {{{
 * \brief Convert #context_properties_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(context_properties_t x, char const* dflt = nullptr) noexcept
{
  return  (x == context_properties_t::platform) ? "platform" :
#if CL_VERSION_1_2
          (x == context_properties_t::interop_user_sync) ? "interop user sync" :
#endif
#if cl_khr_gl_sharing
          (x == context_properties_t::gl_context_khr) ? "gl context khr" :
          (x == context_properties_t::egl_display_khr) ? "egl display khr" :
          (x == context_properties_t::glx_display_khr) ? "glx display khr" :
          (x == context_properties_t::wgl_hdc_khr) ? "wgl hdc khr" :
          (x == context_properties_t::cgl_sharegroup_khr) ? "cgl sharegroup khr" :
#endif
#if cl_khr_dx9_media_sharing
          (x == context_properties_t::adapter_d3d9_khr) ? "adapter d3d9 khr" :
          (x == context_properties_t::adapter_d3d9ex_khr) ? "adapter d3d9eh khr" :
          (x == context_properties_t::adapter_dxva_khr) ? "adapter dxva khr" :
#endif
#if cl_khr_d3d10_sharing
          (x == context_properties_t::d3d10_device_khr) ? "d3d10 device khr" :
#endif
#if cl_khr_d3d11_sharing
          (x == context_properties_t::d3d11_device_khr) ? "d3d11 device khr" :
#endif
          dflt;
}
#if CL_VERSION_1_2
/** // doc: enum2cstr(device_partition_property_t, char const*) {{{
 * \brief Convert #device_partition_property_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_partition_property_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_partition_property_t::equally) ? "equally" :
          (x == device_partition_property_t::by_counts) ? "by counts" :
          (x == device_partition_property_t::by_counts_list_end) ? "by counts list end" :
          (x == device_partition_property_t::by_affinity_domain) ? "by affinity domain" :
          dflt;
}
#endif
#if CL_VERSION_1_2
/** // doc: enum2cstr(device_affinity_domain_t, char const*) {{{
 * \brief Convert #device_affinity_domain_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(device_affinity_domain_t x, char const* dflt = nullptr) noexcept
{
  return  (x == device_affinity_domain_t::none) ? "none" :
          (x == device_affinity_domain_t::numa) ? "numa" :
          (x == device_affinity_domain_t::l4_cache) ? "l4 cache" :
          (x == device_affinity_domain_t::l3_cache) ? "l3 cache" :
          (x == device_affinity_domain_t::l2_cache) ? "l2 cache" :
          (x == device_affinity_domain_t::l1_cache) ? "l1 cache" :
          (x == device_affinity_domain_t::next_partitionable) ? "next partitionable" :
          dflt;
}
#endif
/** // doc: enum2cstr(command_queue_info_t, char const*) {{{
 * \brief Convert #command_queue_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(command_queue_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == command_queue_info_t::context) ? "context" :
          (x == command_queue_info_t::device) ? "device" :
          (x == command_queue_info_t::reference_count) ? "reference count" :
          (x == command_queue_info_t::properties) ? "properties" :
          dflt;
}
/** // doc: enum2cstr(mem_flags_t, char const*) {{{
 * \brief Convert #mem_flags_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(mem_flags_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_flags_t::none) ? "none" :
          (x == mem_flags_t::read_write) ? "read-write" :
          (x == mem_flags_t::write_only) ? "write-only" :
          (x == mem_flags_t::read_only) ? "read-only" :
          (x == mem_flags_t::use_host_ptr) ? "use host ptr" :
          (x == mem_flags_t::alloc_host_ptr) ? "alloc host ptr" :
          (x == mem_flags_t::copy_host_ptr) ? "copy host ptr" :
#if CL_VERSION_1_2
          (x == mem_flags_t::host_write_only) ? "host write only" :
          (x == mem_flags_t::host_read_only) ? "host read only" :
          (x == mem_flags_t::host_no_access) ? "host no access" :
#endif
          dflt;
}
#if CL_VERSION_1_2
/** // doc: enum2cstr(mem_migration_flags_t, char const*) {{{
 * \brief Convert #mem_migration_flags_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(mem_migration_flags_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_migration_flags_t::none) ? "none" :
          (x == mem_migration_flags_t::mem_object_host) ? "mem_object_host" :
          (x == mem_migration_flags_t::mem_object_content_undefined) ? "mem_object_content_undefined" :
          dflt;
}
#endif
/** // doc: enum2cstr(channel_order_t, char const*) {{{
 * \brief Convert #channel_order_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(channel_order_t x, char const* dflt = nullptr) noexcept
{
  return  (x == channel_order_t::r) ? "R" :
          (x == channel_order_t::a) ? "A" :
          (x == channel_order_t::rg) ? "RG" :
          (x == channel_order_t::ra) ? "RA" :
          (x == channel_order_t::rgb) ? "RGB" :
          (x == channel_order_t::rgba) ? "RGBA" :
          (x == channel_order_t::bgra) ? "BGRA" :
          (x == channel_order_t::argb) ? "ARGB" :
          (x == channel_order_t::intensity) ? "intensity" :
          (x == channel_order_t::luminance) ? "luminance" :
#if CL_VERSION_1_1
          (x == channel_order_t::rx) ? "Rx" :
          (x == channel_order_t::rgx) ? "RGx" :
          (x == channel_order_t::rgbx) ? "RGBx" :
#endif
#if CL_VERSION_1_2
          (x == channel_order_t::depth) ? "depth" :
          (x == channel_order_t::depth_stencil) ? "depth stencil" :
#endif
          dflt;
}
/** // doc: enum2cstr(channel_type_t, char const*) {{{
 * \brief Convert #channel_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(channel_type_t x, char const* dflt = nullptr) noexcept
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
          (x == channel_type_t::float_) ? "float" :
#if CL_VERSION_1_2
          (x == channel_type_t::unorm_int24) ? "unorm_int24" :
#endif
          dflt;
}
/** // doc: enum2cstr(mem_object_type_t, char const*) {{{
 * \brief Convert #mem_object_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(mem_object_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_object_type_t::buffer) ? "buffer" :
          (x == mem_object_type_t::image2d) ? "image2d" :
          (x == mem_object_type_t::image3d) ? "image3d" :
#if CL_VERSION_1_2
          (x == mem_object_type_t::image2d_array) ? "image2d array" :
          (x == mem_object_type_t::image1d) ? "image1d" :
          (x == mem_object_type_t::image1d_array) ? "image1d array" :
          (x == mem_object_type_t::image1d_buffer) ? "image1d buffer" :
#endif
          dflt;
}
/** // doc: enum2cstr(mem_info_t, char const*) {{{
 * \brief Convert #mem_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(mem_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == mem_info_t::type) ? "type" :
          (x == mem_info_t::flags) ? "flags" :
          (x == mem_info_t::size) ? "size" :
          (x == mem_info_t::host_ptr) ? "host ptr" :
          (x == mem_info_t::map_count) ? "map count" :
          (x == mem_info_t::reference_count) ? "reference count" :
          (x == mem_info_t::context) ? "context" :
#if CL_VERSION_1_1
          (x == mem_info_t::associated_memobject) ? "associated memobject" :
          (x == mem_info_t::offset) ? "offset" :
#endif
          dflt;
}
/** // doc: enum2cstr(image_info_t, char const*) {{{
 * \brief Convert #image_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(image_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == image_info_t::format) ? "format" :
          (x == image_info_t::element_size) ? "element size" :
          (x == image_info_t::row_pitch) ? "row pitch" :
          (x == image_info_t::slice_pitch) ? "slice pitch" :
          (x == image_info_t::width) ? "width" :
          (x == image_info_t::height) ? "height" :
          (x == image_info_t::depth) ? "depth" :
#if CL_VERSION_1_2
          (x == image_info_t::array_size) ? "array size" :
          (x == image_info_t::buffer) ? "buffer" :
          (x == image_info_t::num_mip_levels) ? "num mip levels" :
          (x == image_info_t::num_samples) ? "num samples" :
#endif
          dflt;
}
/** // doc: enum2cstr(addressing_mode_t, char const*) {{{
 * \brief Convert #addressing_mode_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(addressing_mode_t x, char const* dflt = nullptr) noexcept
{
  return  (x == addressing_mode_t::none) ? "none" :
          (x == addressing_mode_t::clamp_to_edge) ? "clamp to edge" :
          (x == addressing_mode_t::clamp) ? "clamp" :
          (x == addressing_mode_t::repeat) ? "repeat" :
#if CL_VERSION_1_1
          (x == addressing_mode_t::mirrored_repeat) ? "mirrored repeat" :
#endif
          dflt;
}
/** // doc: enum2cstr(filter_mode_t, char const*) {{{
 * \brief Convert #filter_mode_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(filter_mode_t x, char const* dflt = nullptr) noexcept
{
  return  (x == filter_mode_t::nearest) ? "nearest" :
          (x == filter_mode_t::linear) ? "linear" :
          dflt;
}
/** // doc: enum2cstr(sampler_info_t, char const*) {{{
 * \brief Convert #sampler_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(sampler_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == sampler_info_t::reference_count) ? "reference count" :
          (x == sampler_info_t::context) ? "context" :
          (x == sampler_info_t::normalized_coords) ? "normalized coords" :
          (x == sampler_info_t::addressing_mode) ? "addressing mode" :
          (x == sampler_info_t::filter_mode) ? "filter mode" :
          dflt;
}
/** // doc: enum2cstr(map_flags_t, char const*) {{{
 * \brief Convert #map_flags_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(map_flags_t x, char const* dflt = nullptr) noexcept
{
  return  (x == map_flags_t::none) ? "none" :
          (x == map_flags_t::read) ? "read" :
          (x == map_flags_t::write) ? "write" :
#if CL_VERSION_1_2
          (x == map_flags_t::write_invalidate_region) ? "write invalidate region" :
#endif
          dflt;
}
/** // doc: enum2cstr(program_info_t, char const*) {{{
 * \brief Convert #program_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(program_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == program_info_t::reference_count) ? "reference count" :
          (x == program_info_t::context) ? "context" :
          (x == program_info_t::num_devices) ? "num devices" :
          (x == program_info_t::devices) ? "devices" :
          (x == program_info_t::source) ? "source" :
          (x == program_info_t::binary_sizes) ? "binary sizes" :
          (x == program_info_t::binaries) ? "binaries" :
#if CL_VERSION_1_2
          (x == program_info_t::num_kernels) ? "num kernels" :
          (x == program_info_t::kernel_names) ? "kernel names" :
#endif
          dflt;
}
/** // doc: enum2cstr(program_build_info_t, char const*) {{{
 * \brief Convert #program_build_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(program_build_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == program_build_info_t::status) ? "status" :
          (x == program_build_info_t::options) ? "options" :
          (x == program_build_info_t::log) ? "log" :
#if CL_VERSION_1_2
          (x == program_build_info_t::binary_type) ? "binary type" :
#endif
          dflt;
}
/** // doc: enum2cstr(program_binary_type_t, char const*) {{{
 * \brief Convert #program_binary_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
#if CL_VERSION_1_2
constexpr char const*
enum2cstr(program_binary_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == program_binary_type_t::none) ? "none" :
          (x == program_binary_type_t::compiled_object) ? "compiled object" :
          (x == program_binary_type_t::library) ? "library" :
          (x == program_binary_type_t::executable) ? "executable" :
          dflt;
}
#endif
/** // doc: enum2cstr(build_status_t, char const*) {{{
 * \brief Convert #build_status_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(build_status_t x, char const* dflt = nullptr) noexcept
{
  return  (x == build_status_t::success) ? "success" :
          (x == build_status_t::none) ? "none" :
          (x == build_status_t::error) ? "error" :
          (x == build_status_t::in_progress) ? "in progress" :
          dflt;
}
/** // doc: enum2cstr(kernel_info_t, char const*) {{{
 * \brief Convert #kernel_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(kernel_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_info_t::function_name) ? "function name" :
          (x == kernel_info_t::num_args) ? "num args" :
          (x == kernel_info_t::reference_count) ? "reference count" :
          (x == kernel_info_t::context) ? "context" :
          (x == kernel_info_t::program) ? "program" :
#if CL_VERSION_1_2
          (x == kernel_info_t::attributes) ? "attributes" :
#endif
          dflt;
}
#if CL_VERSION_1_2
/** // doc: enum2cstr(kernel_arg_info_t, char const*) {{{
 * \brief Convert #kernel_arg_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(kernel_arg_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_info_t::address_qualifier) ? "address qualifier" :
          (x == kernel_arg_info_t::access_qualifier) ? "access qualifier" :
          (x == kernel_arg_info_t::type_name) ? "type name" :
          (x == kernel_arg_info_t::type_qualifier) ? "type qualifier" :
          (x == kernel_arg_info_t::name) ? "name" :
          dflt;
}
#endif
#if CL_VERSION_1_2
/** // doc: enum2cstr(kernel_arg_address_qualifier_t, char const*) {{{
 * \brief Convert #kernel_arg_address_qualifier_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(kernel_arg_address_qualifier_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_address_qualifier_t::global) ? "global" :
          (x == kernel_arg_address_qualifier_t::local) ? "local" :
          (x == kernel_arg_address_qualifier_t::constant) ? "constant" :
          (x == kernel_arg_address_qualifier_t::private_) ? "private" :
          dflt;
}
#endif
#if CL_VERSION_1_2
/** // doc: enum2cstr(kernel_arg_access_qualifier_t, char const*) {{{
 * \brief Convert #kernel_arg_access_qualifier_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(kernel_arg_access_qualifier_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_access_qualifier_t::read_only) ? "read-only" :
          (x == kernel_arg_access_qualifier_t::write_only) ? "write-only" :
          (x == kernel_arg_access_qualifier_t::read_write) ? "read-write" :
          (x == kernel_arg_access_qualifier_t::none) ? "none" :
          dflt;
}
#endif
#if CL_VERSION_1_2
/** // doc: enum2cstr(kernel_arg_type_qualifier_t, char const*) {{{
 * \brief Convert #kernel_arg_type_qualifier_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(kernel_arg_type_qualifier_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_arg_type_qualifier_t::none) ? "none" :
          (x == kernel_arg_type_qualifier_t::const_) ? "const" :
          (x == kernel_arg_type_qualifier_t::restrict_) ? "restrict" :
          (x == kernel_arg_type_qualifier_t::volatile_) ? "volatile" :
          dflt;
}
#endif
/** // doc: enum2cstr(kernel_work_group_info_t, char const*) {{{
 * \brief Convert #kernel_work_group_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(kernel_work_group_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == kernel_work_group_info_t::work_group_size) ? "work group size" :
          (x == kernel_work_group_info_t::compile_work_group_size) ? "compile work group size" :
          (x == kernel_work_group_info_t::local_mem_size) ? "local mem size" :
#if CL_VERSION_1_1
          (x == kernel_work_group_info_t::preferred_work_group_size_multiple) ? "preferred work group size multiple" :
          (x == kernel_work_group_info_t::private_mem_size) ? "private mem size" :
#endif
#if CL_VERSION_1_2
          (x == kernel_work_group_info_t::global_work_size) ? "global work size" :
#endif
          dflt;
}
/** // doc: enum2cstr(event_info_t, char const*) {{{
 * \brief Convert #event_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(event_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == event_info_t::command_queue) ? "command queue" :
          (x == event_info_t::command_type) ? "command type" :
          (x == event_info_t::reference_count) ? "reference count" :
          (x == event_info_t::command_execution_status) ? "command execution status" :
#if CL_VERSION_1_1
          (x == event_info_t::context) ? "context" :
#endif
          dflt;
}
/** // doc: enum2cstr(command_type_t, char const*) {{{
 * \brief Convert #command_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(command_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == command_type_t::ndrange_kernel) ? "ndrange kernel" :
          (x == command_type_t::task) ? "task" :
          (x == command_type_t::native_kernel) ? "native kernel" :
          (x == command_type_t::read_buffer) ? "read buffer" :
          (x == command_type_t::write_buffer) ? "write buffer" :
          (x == command_type_t::copy_buffer) ? "copy buffer" :
          (x == command_type_t::read_image) ? "read image" :
          (x == command_type_t::write_image) ? "write image" :
          (x == command_type_t::copy_image) ? "copy image" :
          (x == command_type_t::copy_image_to_buffer) ? "copy image to buffer" :
          (x == command_type_t::copy_buffer_to_image) ? "copy buffer to image" :
          (x == command_type_t::map_buffer) ? "map buffer" :
          (x == command_type_t::map_image) ? "map image" :
          (x == command_type_t::unmap_mem_object) ? "unmap mem object" :
          (x == command_type_t::marker) ? "marker" :
          (x == command_type_t::acquire_gl_objects) ? "acquire GL objects" :
          (x == command_type_t::release_gl_objects) ? "release GL objects" :
#if CL_VERSION_1_1
          (x == command_type_t::read_buffer_rect) ? "read buffer rect" :
          (x == command_type_t::write_buffer_rect) ? "write buffer rect" :
          (x == command_type_t::copy_buffer_rect) ? "copy buffer rect" :
          (x == command_type_t::user) ? "user" :
#endif
#if CL_VERSION_1_2
          (x == command_type_t::barrier) ? "barrier" :
          (x == command_type_t::migrate_mem_objects) ? "migrate mem objects" :
          (x == command_type_t::fill_buffer) ? "fill buffer" :
          (x == command_type_t::fill_image) ? "fill image" :
#endif
          dflt;
}
/** // doc: enum2cstr(command_exec_status_t, char const*) {{{
 * \brief Convert #command_exec_status_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(command_exec_status_t x, char const* dflt = nullptr) noexcept
{
  return (x == command_exec_status_t::complete) ? "complete" :
         (x == command_exec_status_t::running) ? "running" :
         (x == command_exec_status_t::submitted) ? "submitted" :
         (x == command_exec_status_t::queued) ? "queued" :
         is_error(x) ?  enum2cstr(static_cast<status_t>(x), dflt) :
         dflt;
}
#if CL_VERSION_1_1
/** // doc: enum2cstr(buffer_create_type_t, char const*) {{{
 * \brief Convert #buffer_create_type_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(buffer_create_type_t x, char const* dflt = nullptr) noexcept
{
  return  (x == buffer_create_type_t::region) ? "region" :
          dflt;
}
#endif
/** // doc: enum2cstr(profiling_info_t, char const*) {{{
 * \brief Convert #profiling_info_t to C string (human-readable message)
 * \param x The enum value to be converted
 * \param dflt Default string to be returned if \em x is not recognized by #enum2cstr()
 * \returns Pointer to a null-terminated C string representing the enum value \em x as a human-readable message
 */ // }}}
constexpr char const*
enum2cstr(profiling_info_t x, char const* dflt = nullptr) noexcept
{
  return  (x == profiling_info_t::queued) ? "queued" :
          (x == profiling_info_t::submit) ? "submit" :
          (x == profiling_info_t::start) ? "start" :
          (x == profiling_info_t::end) ? "end" :
          dflt;
}

} // namespace clxx

#endif /* CLXX_UTIL_ENUM2STR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
