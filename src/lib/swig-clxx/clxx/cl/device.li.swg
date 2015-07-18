// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/device.li.swg {{{
 * \file clxx/cl/device.li.swg
 * \todo Write documentation
 */ // }}}
%{
#include <clxx/cl/device.hpp>
%}
%include <std_vector.i>
%include <std_string.i>
%template() std::vector<size_t>;
%template() std::vector<clxx::device_partition_property_t>;

%include <clxx/exception_support.swg>

%define %throws_as_device_get_pod_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_device_error
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_as_device_get_vec_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_device_error
  %catch_clerror
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_as_device_get_str_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_device_error
  %catch_clerror
  %catch_badalloc
  %catch_exception
}
%enddef

%exception clxx::device::chk_get() {
  try { $action }
  %catch_uninitialized_device_error
  %catch_exception
}

%exception clxx::device::get_info() {
  try { $action }
  %catch_uninitialized_device_error
  %catch_clerror
  %catch_exception
}

%throws_as_device_get_pod_info(clxx::device::get_type() const);
%throws_as_device_get_pod_info(clxx::device::get_vendor_id() const);
%throws_as_device_get_pod_info(clxx::device::get_max_compute_units() const);
%throws_as_device_get_pod_info(clxx::device::get_max_work_item_dimensions() const);
%throws_as_device_get_pod_info(clxx::device::get_max_work_group_size() const);
%throws_as_device_get_vec_info(clxx::device::get_max_work_item_sizes() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_vector_width_char() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_vector_width_short() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_vector_width_int() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_vector_width_long() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_vector_width_float() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_vector_width_double() const);
%throws_as_device_get_pod_info(clxx::device::get_max_clock_frequency() const);
%throws_as_device_get_pod_info(clxx::device::get_address_bits() const);
%throws_as_device_get_pod_info(clxx::device::get_max_read_image_args() const);
%throws_as_device_get_pod_info(clxx::device::get_max_write_image_args() const);
%throws_as_device_get_pod_info(clxx::device::get_max_mem_alloc_size() const);
%throws_as_device_get_pod_info(clxx::device::get_image2d_max_width() const);
%throws_as_device_get_pod_info(clxx::device::get_image2d_max_height() const);
%throws_as_device_get_pod_info(clxx::device::get_image3d_max_width() const);
%throws_as_device_get_pod_info(clxx::device::get_image3d_max_height() const);
%throws_as_device_get_pod_info(clxx::device::get_image3d_max_depth() const);
%throws_as_device_get_pod_info(clxx::device::get_image_support() const);
%throws_as_device_get_pod_info(clxx::device::get_max_parameter_size() const);
%throws_as_device_get_pod_info(clxx::device::get_max_samplers() const);
%throws_as_device_get_pod_info(clxx::device::get_mem_base_addr_align() const);
%throws_as_device_get_pod_info(clxx::device::get_min_data_type_align_size() const);
%throws_as_device_get_pod_info(clxx::device::get_single_fp_config() const);
%throws_as_device_get_pod_info(clxx::device::get_global_mem_cache_type() const);
%throws_as_device_get_pod_info(clxx::device::get_global_mem_cacheline_size() const);
%throws_as_device_get_pod_info(clxx::device::get_global_mem_cache_size() const);
%throws_as_device_get_pod_info(clxx::device::get_global_mem_size() const);
%throws_as_device_get_pod_info(clxx::device::get_max_constant_buffer_size() const);
%throws_as_device_get_pod_info(clxx::device::get_max_constant_args() const);
%throws_as_device_get_pod_info(clxx::device::get_local_mem_type() const);
%throws_as_device_get_pod_info(clxx::device::get_local_mem_size() const);
%throws_as_device_get_pod_info(clxx::device::get_error_correction_support() const);
%throws_as_device_get_pod_info(clxx::device::get_profiling_timer_resolution() const);
%throws_as_device_get_pod_info(clxx::device::get_endian_little() const);
%throws_as_device_get_pod_info(clxx::device::get_available() const);
%throws_as_device_get_pod_info(clxx::device::get_compiler_available() const);
%throws_as_device_get_pod_info(clxx::device::get_execution_capabilities() const);
%throws_as_device_get_pod_info(clxx::device::get_queue_properties() const);
%throws_as_device_get_str_info(clxx::device::get_name() const);
%throws_as_device_get_str_info(clxx::device::get_vendor() const);
%throws_as_device_get_str_info(clxx::device::get_driver_version() const);
%throws_as_device_get_str_info(clxx::device::get_profile() const);
%throws_as_device_get_str_info(clxx::device::get_version() const);
%throws_as_device_get_str_info(clxx::device::get_extensions() const);
%throws_as_device_get_pod_info(clxx::device::get_platform_id() const);
%throws_as_device_get_pod_info(clxx::device::get_double_fp_config() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_vector_width_half() const);
%throws_as_device_get_pod_info(clxx::device::get_host_unified_memory() const);
%throws_as_device_get_pod_info(clxx::device::get_native_vector_width_char() const);
%throws_as_device_get_pod_info(clxx::device::get_native_vector_width_short() const);
%throws_as_device_get_pod_info(clxx::device::get_native_vector_width_int() const);
%throws_as_device_get_pod_info(clxx::device::get_native_vector_width_long() const);
%throws_as_device_get_pod_info(clxx::device::get_native_vector_width_float() const);
%throws_as_device_get_pod_info(clxx::device::get_native_vector_width_double() const);
%throws_as_device_get_pod_info(clxx::device::get_native_vector_width_half() const);
%throws_as_device_get_str_info(clxx::device::get_opencl_c_version() const);
%throws_as_device_get_pod_info(clxx::device::get_linker_available() const);
%throws_as_device_get_str_info(clxx::device::get_built_in_kernels() const);
%throws_as_device_get_pod_info(clxx::device::get_image_max_buffer_size() const);
%throws_as_device_get_pod_info(clxx::device::get_image_max_array_size() const);
%throws_as_device_get_pod_info(clxx::device::get_parent_device_id() const);
%throws_as_device_get_pod_info(clxx::device::get_partition_max_sub_devices() const);
%throws_as_device_get_pod_info(clxx::device::get_partition_properties() const);
%throws_as_device_get_pod_info(clxx::device::get_partition_affinity_domain() const);
%throws_as_device_get_vec_info(clxx::device::get_partition_type() const);
%throws_as_device_get_pod_info(clxx::device::get_reference_count() const);
%throws_as_device_get_pod_info(clxx::device::get_preferred_interop_user_sync() const);
%throws_as_device_get_pod_info(clxx::device::get_printf_buffer_size() const);
%throws_as_device_get_pod_info(clxx::device::get_image_pitch_alignment() const);
%throws_as_device_get_pod_info(clxx::device::get_image_base_address_alignment() const);

// TODO: specify exceptions for this function
//clxx::query_device_info(device const&, device_query const&)

%template(clobj_device) clxx::clobj<cl_device_id>;

%include <clxx/cl/device.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
