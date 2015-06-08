// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_info.hpp

/** // doc: clxx/device_info.hpp {{{
 * \file clxx/device_info.hpp
 * \todo Refine
 *
 * This module contains class clxx::device_info which stores paramteres
 * of an OpenClinfo device.
 *
 */ // }}}
#ifndef CLXX_DEVICE_INFO_HPP_INCLUDED
#define CLXX_DEVICE_INFO_HPP_INCLUDED

#include <clxx/types.hpp>
#include <boost/optional.hpp>
#include <vector>
#include <string>

namespace clxx {

/** // doc: class device_info {{{
 * \class clxx::device_info
 * \brief Container for device parameters.
 *
 * \todo Write documentation
 */ // }}}
class device_info
{
  template <class Archive>
  friend void _serialize(Archive&, device_info&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \todo Write documentation
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: device_info() {{{
   * \todo Write documentation
   */ // }}}
  device_info();
  /** // doc: ~device_info() {{{
   * \todo Write documentation for class device_info
   */ // }}}
  virtual ~device_info();
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear();
  /** // doc: cmp(rhs) {{{
   * \todo Write documentation
   */ // }}}
  bool cmp(device_info const&) const noexcept;
  // getters {{{
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long id() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  device_type_t type() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint vendor_id() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_compute_units() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_work_item_dimensions() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t max_work_group_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::vector<size_t> max_work_item_sizes() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_char() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_short() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_int() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_long() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_float() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_double() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_clock_frequency() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint address_bits() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_read_image_args() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_write_image_args() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong max_mem_alloc_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image2d_max_width() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image2d_max_height() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_width() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_height() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image3d_max_depth() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool image_support() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t max_parameter_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_samplers() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint mem_base_addr_align() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint min_data_type_align_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  device_fp_config_t single_fp_config() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  device_mem_cache_type_t global_mem_cache_type() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint global_mem_cacheline_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong global_mem_cache_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong global_mem_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong max_constant_buffer_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint max_constant_args() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  device_local_mem_type_t local_mem_type() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_ulong local_mem_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool error_correction_support() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t profiling_timer_resolution() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool endian_little() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool available() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool compiler_available() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  device_exec_capabilities_t execution_capabilities() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  command_queue_properties_t queue_properties() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& name() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& vendor() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& driver_version() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& profile() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& version() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& extensions() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long platform_id() const;
#if CL_VERSION_1_2
  /** // {{{
   * \todo Write documentation
   */ // }}}
  device_fp_config_t double_fp_config() const;
#endif
#if CL_VERSION_1_1
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint preferred_vector_width_half() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool host_unified_memory() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_char() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_short() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_int() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_long() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_float() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_double() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint native_vector_width_half() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& opencl_c_version() const;
#endif
#if CL_VERSION_1_2
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool linker_available() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::string const& built_in_kernels() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image_max_buffer_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t image_max_array_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  unsigned long parent_device_id() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint partition_max_sub_devices() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::vector<device_partition_property_t> partition_properties() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  device_affinity_domain_t partition_affinity_domain() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  std::vector<device_partition_property_t> partition_type() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint reference_count() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_bool preferred_interop_user_sync() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  size_t printf_buffer_size() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint image_pitch_alignment() const;
  /** // {{{
   * \todo Write documentation
   */ // }}}
  cl_uint image_base_address_alignment() const;
#endif
  // }}}
  // setters {{{
  /** doc: set_id(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_id(unsigned long val) noexcept;
  /** doc: set_type(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_type(device_type_t val) noexcept;
  /** doc: set_vendor_id(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_vendor_id(cl_uint val) noexcept;
  /** doc: set_max_compute_units(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_compute_units(cl_uint val) noexcept;
  /** doc: set_max_work_item_dimensions(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_work_item_dimensions(cl_uint val) noexcept;
  /** doc: set_max_work_group_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_work_group_size(size_t val) noexcept;
  /** doc: set_max_work_item_sizes(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_work_item_sizes(std::vector<size_t> const& val);
  /** doc: set_preferred_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_vector_width_char(cl_uint val) noexcept;
  /** doc: set_preferred_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_vector_width_short(cl_uint val) noexcept;
  /** doc: set_preferred_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_vector_width_int(cl_uint val) noexcept;
  /** doc: set_preferred_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_vector_width_long(cl_uint val) noexcept;
  /** doc: set_preferred_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_vector_width_float(cl_uint val) noexcept;
  /** doc: set_preferred_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_vector_width_double(cl_uint val) noexcept;
  /** doc: set_max_clock_frequency(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_clock_frequency(cl_uint val) noexcept;
  /** doc: set_address_bits(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_address_bits(cl_uint val) noexcept;
  /** doc: set_max_read_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_read_image_args(cl_uint val) noexcept;
  /** doc: set_max_write_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_write_image_args(cl_uint val) noexcept;
  /** doc: set_max_mem_alloc_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_mem_alloc_size(cl_ulong val) noexcept;
  /** doc: set_image2d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image2d_max_width(size_t val) noexcept;
  /** doc: set_image2d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image2d_max_height(size_t val) noexcept;
  /** doc: set_image3d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image3d_max_width(size_t val) noexcept;
  /** doc: set_image3d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image3d_max_height(size_t val) noexcept;
  /** doc: set_image3d_max_depth(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image3d_max_depth(size_t val) noexcept;
  /** doc: set_image_support(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image_support(cl_bool val) noexcept;
  /** doc: set_max_parameter_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_parameter_size(size_t val) noexcept;
  /** doc: set_max_samplers(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_samplers(cl_uint val) noexcept;
  /** doc: set_mem_base_addr_align(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_mem_base_addr_align(cl_uint val) noexcept;
  /** doc: set_min_data_type_align_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_min_data_type_align_size(cl_uint val) noexcept;
  /** doc: set_single_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_single_fp_config(device_fp_config_t val) noexcept;
  /** doc: set_global_mem_cache_type(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_global_mem_cache_type(device_mem_cache_type_t val) noexcept;
  /** doc: set_global_mem_cacheline_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_global_mem_cacheline_size(cl_uint val) noexcept;
  /** doc: set_global_mem_cache_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_global_mem_cache_size(cl_ulong val) noexcept;
  /** doc: set_global_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_global_mem_size(cl_ulong val) noexcept;
  /** doc: set_max_constant_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_constant_buffer_size(cl_uint val) noexcept;
  /** doc: set_max_constant_args(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_max_constant_args(cl_uint val) noexcept;
  /** doc: set_local_mem_type(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_local_mem_type(device_local_mem_type_t val) noexcept;
  /** doc: set_local_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_local_mem_size(cl_ulong val) noexcept;
  /** doc: set_error_correction_support(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_error_correction_support(cl_bool val) noexcept;
  /** doc: set_profiling_timer_resolution(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_profiling_timer_resolution(size_t val) noexcept;
  /** doc: set_endian_little(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_endian_little(cl_bool val) noexcept;
  /** doc: set_available(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_available(cl_bool val) noexcept;
  /** doc: set_compiler_available(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_compiler_available(cl_bool val) noexcept;
  /** doc: set_execution_capabilities(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_execution_capabilities(device_exec_capabilities_t val) noexcept;
  /** doc: set_queue_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_queue_properties(command_queue_properties_t val) noexcept;
  /** doc: set_name(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_name(std::string const& val);
  /** doc: set_vendor(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_vendor(std::string const& val);
  /** doc: set_driver_version(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_driver_version(std::string const& val);
  /** doc: set_profile(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_profile(std::string const& val);
  /** doc: set_version(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_version(std::string const& val);
  /** doc: set_extensions(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_extensions(std::string const& val);
  /** doc: set_platform_id(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_platform_id(unsigned long val) noexcept;
#if CL_VERSION_1_2
  /** doc: set_double_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_double_fp_config(device_fp_config_t val) noexcept;
#endif
#if CL_VERSION_1_1
  /** doc: set_preferred_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_vector_width_half(cl_uint val) noexcept;
  /** doc: set_host_unified_memory(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_host_unified_memory(cl_bool val) noexcept;
  /** doc: set_native_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_native_vector_width_char(cl_uint val) noexcept;
  /** doc: set_native_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_native_vector_width_short(cl_uint val) noexcept;
  /** doc: set_native_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_native_vector_width_int(cl_uint val) noexcept;
  /** doc: set_native_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_native_vector_width_long(cl_uint val) noexcept;
  /** doc: set_native_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_native_vector_width_float(cl_uint val) noexcept;
  /** doc: set_native_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_native_vector_width_double(cl_uint val) noexcept;
  /** doc: set_native_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_native_vector_width_half(cl_uint val) noexcept;
  /** doc: set_opencl_c_version(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_opencl_c_version(std::string const& val);
#endif
#if CL_VERSION_1_2
  /** doc: set_linker_available(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_linker_available(cl_bool val) noexcept;
  /** doc: set_built_in_kernels(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_built_in_kernels(std::string const& val);
  /** doc: set_image_max_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image_max_buffer_size(size_t val) noexcept;
  /** doc: set_image_max_array_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image_max_array_size(size_t val) noexcept;
  /** doc: set_parent_device_id(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_parent_device_id(unsigned long val) noexcept;
  /** doc: set_partition_max_sub_devices(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_partition_max_sub_devices(cl_uint val) noexcept;
  /** doc: set_partition_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_partition_properties(std::vector<device_partition_property_t> const& val);
  /** doc: set_partition_affinity_domain(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_partition_affinity_domain(device_affinity_domain_t val) noexcept;
  /** doc: set_partition_type(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_partition_type(std::vector<device_partition_property_t> const& val);
  /** doc: set_reference_count(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_reference_count(cl_uint val) noexcept;
  /** doc: set_preferred_interop_user_sync(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_preferred_interop_user_sync(cl_bool val) noexcept;
  /** doc: set_printf_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_printf_buffer_size(size_t val) noexcept;
  /** doc: set_image_pitch_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image_pitch_alignment(cl_uint val) noexcept;
  /** doc: set_image_base_address_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  device_info& set_image_base_address_alignment(cl_uint val) noexcept;
#endif
  // }}}
  // cleaners {{{
  /** doc: clear_id() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_id() noexcept;
  /** doc: clear_type() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_type() noexcept;
  /** doc: clear_vendor_id() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_vendor_id() noexcept;
  /** doc: clear_max_compute_units() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_compute_units() noexcept;
  /** doc: clear_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_work_item_dimensions() noexcept;
  /** doc: clear_max_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_work_group_size() noexcept;
  /** doc: clear_max_work_item_sizes() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_work_item_sizes() noexcept;
  /** doc: clear_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_vector_width_char() noexcept;
  /** doc: clear_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_vector_width_short() noexcept;
  /** doc: clear_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_vector_width_int() noexcept;
  /** doc: clear_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_vector_width_long() noexcept;
  /** doc: clear_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_vector_width_float() noexcept;
  /** doc: clear_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_vector_width_double() noexcept;
  /** doc: clear_max_clock_frequency() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_clock_frequency() noexcept;
  /** doc: clear_address_bits() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_address_bits() noexcept;
  /** doc: clear_max_read_image_args() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_read_image_args() noexcept;
  /** doc: clear_max_write_image_args() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_write_image_args() noexcept;
  /** doc: clear_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_mem_alloc_size() noexcept;
  /** doc: clear_image2d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image2d_max_width() noexcept;
  /** doc: clear_image2d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image2d_max_height() noexcept;
  /** doc: clear_image3d_max_width() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image3d_max_width() noexcept;
  /** doc: clear_image3d_max_height() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image3d_max_height() noexcept;
  /** doc: clear_image3d_max_depth() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image3d_max_depth() noexcept;
  /** doc: clear_image_support() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image_support() noexcept;
  /** doc: clear_max_parameter_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_parameter_size() noexcept;
  /** doc: clear_max_samplers() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_samplers() noexcept;
  /** doc: clear_mem_base_addr_align() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_mem_base_addr_align() noexcept;
  /** doc: clear_min_data_type_align_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_min_data_type_align_size() noexcept;
  /** doc: clear_single_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_single_fp_config() noexcept;
  /** doc: clear_global_mem_cache_type() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_global_mem_cache_type() noexcept;
  /** doc: clear_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_global_mem_cacheline_size() noexcept;
  /** doc: clear_global_mem_cache_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_global_mem_cache_size() noexcept;
  /** doc: clear_global_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_global_mem_size() noexcept;
  /** doc: clear_max_constant_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_constant_buffer_size() noexcept;
  /** doc: clear_max_constant_args() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_max_constant_args() noexcept;
  /** doc: clear_local_mem_type() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_local_mem_type() noexcept;
  /** doc: clear_local_mem_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_local_mem_size() noexcept;
  /** doc: clear_error_correction_support() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_error_correction_support() noexcept;
  /** doc: clear_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_profiling_timer_resolution() noexcept;
  /** doc: clear_endian_little() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_endian_little() noexcept;
  /** doc: clear_available() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_available() noexcept;
  /** doc: clear_compiler_available() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_compiler_available() noexcept;
  /** doc: clear_execution_capabilities() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_execution_capabilities() noexcept;
  /** doc: clear_queue_properties() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_queue_properties() noexcept;
  /** doc: clear_name() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_name() noexcept;
  /** doc: clear_vendor() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_vendor() noexcept;
  /** doc: clear_driver_version() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_driver_version() noexcept;
  /** doc: clear_profile() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_profile() noexcept;
  /** doc: clear_version() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_version() noexcept;
  /** doc: clear_extensions() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_extensions() noexcept;
  /** doc: clear_platform_id() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_platform_id() noexcept;
#if CL_VERSION_1_2
  /** doc: clear_double_fp_config() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_double_fp_config() noexcept;
#endif
#if CL_VERSION_1_1
  /** doc: clear_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_vector_width_half() noexcept;
  /** doc: clear_host_unified_memory() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_host_unified_memory() noexcept;
  /** doc: clear_native_vector_width_char() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_native_vector_width_char() noexcept;
  /** doc: clear_native_vector_width_short() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_native_vector_width_short() noexcept;
  /** doc: clear_native_vector_width_int() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_native_vector_width_int() noexcept;
  /** doc: clear_native_vector_width_long() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_native_vector_width_long() noexcept;
  /** doc: clear_native_vector_width_float() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_native_vector_width_float() noexcept;
  /** doc: clear_native_vector_width_double() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_native_vector_width_double() noexcept;
  /** doc: clear_native_vector_width_half() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_native_vector_width_half() noexcept;
  /** doc: clear_opencl_c_version() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_opencl_c_version() noexcept;
#endif
#if CL_VERSION_1_2
  /** doc: clear_linker_available() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_linker_available() noexcept;
  /** doc: clear_built_in_kernels() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_built_in_kernels() noexcept;
  /** doc: clear_image_max_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image_max_buffer_size() noexcept;
  /** doc: clear_image_max_array_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image_max_array_size() noexcept;
  /** doc: clear_parent_device_id() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_parent_device_id() noexcept;
  /** doc: clear_partition_max_sub_devices() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_partition_max_sub_devices() noexcept;
  /** doc: clear_partition_properties() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_partition_properties() noexcept;
  /** doc: clear_partition_affinity_domain() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_partition_affinity_domain() noexcept;
  /** doc: clear_partition_type() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_partition_type() noexcept;
  /** doc: clear_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_reference_count() noexcept;
  /** doc: clear_preferred_interop_user_sync() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_preferred_interop_user_sync() noexcept;
  /** doc: clear_printf_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_printf_buffer_size() noexcept;
  /** doc: clear_image_pitch_alignment() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image_pitch_alignment() noexcept;
  /** doc: clear_image_base_address_alignment() {{{
   * \todo Write documentation
   */ // }}}
  device_info& clear_image_base_address_alignment() noexcept;
#endif
  // }}}
  // presence {{{
  /** doc: has_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_id() const noexcept;
  /** doc: has_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_type() const noexcept;
  /** doc: has_vendor_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_vendor_id() const noexcept;
  /** doc: has_max_compute_units(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_compute_units() const noexcept;
  /** doc: has_max_work_item_dimensions(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_work_item_dimensions() const noexcept;
  /** doc: has_max_work_group_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_work_group_size() const noexcept;
  /** doc: has_max_work_item_sizes(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_work_item_sizes() const noexcept;
  /** doc: has_preferred_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_char() const noexcept;
  /** doc: has_preferred_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_short() const noexcept;
  /** doc: has_preferred_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_int() const noexcept;
  /** doc: has_preferred_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_long() const noexcept;
  /** doc: has_preferred_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_float() const noexcept;
  /** doc: has_preferred_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_double() const noexcept;
  /** doc: has_max_clock_frequency(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_clock_frequency() const noexcept;
  /** doc: has_address_bits(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_address_bits() const noexcept;
  /** doc: has_max_read_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_read_image_args() const noexcept;
  /** doc: has_max_write_image_args(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_write_image_args() const noexcept;
  /** doc: has_max_mem_alloc_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_mem_alloc_size() const noexcept;
  /** doc: has_image2d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image2d_max_width() const noexcept;
  /** doc: has_image2d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image2d_max_height() const noexcept;
  /** doc: has_image3d_max_width(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image3d_max_width() const noexcept;
  /** doc: has_image3d_max_height(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image3d_max_height() const noexcept;
  /** doc: has_image3d_max_depth(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image3d_max_depth() const noexcept;
  /** doc: has_image_support(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_support() const noexcept;
  /** doc: has_max_parameter_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_parameter_size() const noexcept;
  /** doc: has_max_samplers(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_samplers() const noexcept;
  /** doc: has_mem_base_addr_align(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_mem_base_addr_align() const noexcept;
  /** doc: has_min_data_type_align_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_min_data_type_align_size() const noexcept;
  /** doc: has_single_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_single_fp_config() const noexcept;
  /** doc: has_global_mem_cache_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_cache_type() const noexcept;
  /** doc: has_global_mem_cacheline_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_cacheline_size() const noexcept;
  /** doc: has_global_mem_cache_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_cache_size() const noexcept;
  /** doc: has_global_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_global_mem_size() const noexcept;
  /** doc: has_max_constant_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_constant_buffer_size() const noexcept;
  /** doc: has_max_constant_args(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_max_constant_args() const noexcept;
  /** doc: has_local_mem_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_local_mem_type() const noexcept;
  /** doc: has_local_mem_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_local_mem_size() const noexcept;
  /** doc: has_error_correction_support(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_error_correction_support() const noexcept;
  /** doc: has_profiling_timer_resolution(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_profiling_timer_resolution() const noexcept;
  /** doc: has_endian_little(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_endian_little() const noexcept;
  /** doc: has_available(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_available() const noexcept;
  /** doc: has_compiler_available(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_compiler_available() const noexcept;
  /** doc: has_execution_capabilities(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_execution_capabilities() const noexcept;
  /** doc: has_queue_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_queue_properties() const noexcept;
  /** doc: has_name(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_name() const noexcept;
  /** doc: has_vendor(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_vendor() const noexcept;
  /** doc: has_driver_version(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_driver_version() const noexcept;
  /** doc: has_profile(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_profile() const noexcept;
  /** doc: has_version(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_version() const noexcept;
  /** doc: has_extensions(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_extensions() const noexcept;
  /** doc: has_platform_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_platform_id() const noexcept;
#if CL_VERSION_1_2
  /** doc: has_double_fp_config(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_double_fp_config() const noexcept;
#endif
#if CL_VERSION_1_1
  /** doc: has_preferred_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_vector_width_half() const noexcept;
  /** doc: has_host_unified_memory(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_host_unified_memory() const noexcept;
  /** doc: has_native_vector_width_char(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_char() const noexcept;
  /** doc: has_native_vector_width_short(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_short() const noexcept;
  /** doc: has_native_vector_width_int(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_int() const noexcept;
  /** doc: has_native_vector_width_long(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_long() const noexcept;
  /** doc: has_native_vector_width_float(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_float() const noexcept;
  /** doc: has_native_vector_width_double(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_double() const noexcept;
  /** doc: has_native_vector_width_half(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_native_vector_width_half() const noexcept;
  /** doc: has_opencl_c_version(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_opencl_c_version() const noexcept;
#endif
#if CL_VERSION_1_2
  /** doc: has_linker_available(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_linker_available() const noexcept;
  /** doc: has_built_in_kernels(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_built_in_kernels() const noexcept;
  /** doc: has_image_max_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_max_buffer_size() const noexcept;
  /** doc: has_image_max_array_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_max_array_size() const noexcept;
  /** doc: has_parent_device_id(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_parent_device_id() const noexcept;
  /** doc: has_partition_max_sub_devices(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_max_sub_devices() const noexcept;
  /** doc: has_partition_properties(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_properties() const noexcept;
  /** doc: has_partition_affinity_domain(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_affinity_domain() const noexcept;
  /** doc: has_partition_type(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_partition_type() const noexcept;
  /** doc: has_reference_count(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_reference_count() const noexcept;
  /** doc: has_preferred_interop_user_sync(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_preferred_interop_user_sync() const noexcept;
  /** doc: has_printf_buffer_size(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_printf_buffer_size() const noexcept;
  /** doc: has_image_pitch_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_pitch_alignment() const noexcept;
  /** doc: has_image_base_address_alignment(val) {{{
   * \todo Write documentation
   */ // }}}
  bool has_image_base_address_alignment() const noexcept;
#endif
  // }}}
private:
  void _init();
  void _clear();
  // attributes {{{
  boost::optional<unsigned long> _id;
  boost::optional<device_type_t> _type;
  boost::optional<cl_uint> _vendor_id;
  boost::optional<cl_uint> _max_compute_units;
  boost::optional<cl_uint> _max_work_item_dimensions;
  boost::optional<size_t> _max_work_group_size;
  boost::optional<std::vector<size_t> > _max_work_item_sizes;
  boost::optional<cl_uint> _preferred_vector_width_char;
  boost::optional<cl_uint> _preferred_vector_width_short;
  boost::optional<cl_uint> _preferred_vector_width_int;
  boost::optional<cl_uint> _preferred_vector_width_long;
  boost::optional<cl_uint> _preferred_vector_width_float;
  boost::optional<cl_uint> _preferred_vector_width_double;
  boost::optional<cl_uint> _max_clock_frequency;
  boost::optional<cl_uint> _address_bits;
  boost::optional<cl_uint> _max_read_image_args;
  boost::optional<cl_uint> _max_write_image_args;
  boost::optional<cl_ulong> _max_mem_alloc_size;
  boost::optional<size_t> _image2d_max_width;
  boost::optional<size_t> _image2d_max_height;
  boost::optional<size_t> _image3d_max_width;
  boost::optional<size_t> _image3d_max_height;
  boost::optional<size_t> _image3d_max_depth;
  boost::optional<cl_bool> _image_support;
  boost::optional<size_t> _max_parameter_size;
  boost::optional<cl_uint> _max_samplers;
  boost::optional<cl_uint> _mem_base_addr_align;
  boost::optional<cl_uint> _min_data_type_align_size;
  boost::optional<device_fp_config_t> _single_fp_config;
  boost::optional<device_mem_cache_type_t> _global_mem_cache_type;
  boost::optional<cl_uint> _global_mem_cacheline_size;
  boost::optional<cl_ulong> _global_mem_cache_size;
  boost::optional<cl_ulong> _global_mem_size;
  boost::optional<cl_uint> _max_constant_buffer_size;
  boost::optional<cl_uint> _max_constant_args;
  boost::optional<device_local_mem_type_t> _local_mem_type;
  boost::optional<cl_ulong> _local_mem_size;
  boost::optional<cl_bool> _error_correction_support;
  boost::optional<size_t> _profiling_timer_resolution;
  boost::optional<cl_bool> _endian_little;
  boost::optional<cl_bool> _available;
  boost::optional<cl_bool> _compiler_available;
  boost::optional<device_exec_capabilities_t> _execution_capabilities;
  boost::optional<command_queue_properties_t> _queue_properties;
  boost::optional<std::string>  _name;
  boost::optional<std::string>  _vendor;
  boost::optional<std::string>  _driver_version;
  boost::optional<std::string>  _profile;
  boost::optional<std::string>  _version;
  boost::optional<std::string>  _extensions;
  boost::optional<unsigned long> _platform_id;
#if CL_VERSION_1_2
  boost::optional<device_fp_config_t> _double_fp_config;
#endif
#if CL_VERSION_1_1
  boost::optional<cl_uint> _preferred_vector_width_half;
  boost::optional<cl_bool> _host_unified_memory;
  boost::optional<cl_uint> _native_vector_width_char;
  boost::optional<cl_uint> _native_vector_width_short;
  boost::optional<cl_uint> _native_vector_width_int;
  boost::optional<cl_uint> _native_vector_width_long;
  boost::optional<cl_uint> _native_vector_width_float;
  boost::optional<cl_uint> _native_vector_width_double;
  boost::optional<cl_uint> _native_vector_width_half;
  boost::optional<std::string>  _opencl_c_version;
#endif
#if CL_VERSION_1_2
  boost::optional<cl_bool> _linker_available;
  boost::optional<std::string>  _built_in_kernels;
  boost::optional<size_t> _image_max_buffer_size;
  boost::optional<size_t> _image_max_array_size;
  boost::optional<unsigned long> _parent_device_id;
  boost::optional<cl_uint> _partition_max_sub_devices;
  boost::optional<std::vector<device_partition_property_t> > _partition_properties;
  boost::optional<device_affinity_domain_t> _partition_affinity_domain;
  boost::optional<std::vector<device_partition_property_t> > _partition_type;
  boost::optional<cl_uint> _reference_count;
  boost::optional<cl_bool> _preferred_interop_user_sync;
  boost::optional<size_t> _printf_buffer_size;
  boost::optional<cl_uint> _image_pitch_alignment;
  boost::optional<cl_uint> _image_base_address_alignment;
#endif
  // }}}
};

/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator== (device_info const& a, device_info const& b) noexcept
{ return a.cmp(b); }
/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!= (device_info const& a, device_info const& b) noexcept
{ return !(a == b); }

} // end namespace clxx

#endif /* CLXX_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
