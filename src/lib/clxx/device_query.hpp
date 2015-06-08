// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_query.hpp

/** // doc: clxx/device_query.hpp {{{
 * \file clxx/device_query.hpp
 *
 * This file contains definition of clxx::device_query class, which configures
 * queries to OpenCL devices.
 */ // }}}
#ifndef CLXX_DEVICE_QUERY_HPP_INCLUDED
#define CLXX_DEVICE_QUERY_HPP_INCLUDED

namespace clxx {

/** // doc: class device_query {{{
 * \brief Indicates what information to retrieve from a device.
 *
 * This class encapsulates several boolean flags which indicate what
 * information should be retrieved from an OpenCL device. Objects of type
 * clxx::device_query are used together with clxx::device_info to query several
 * parmeters describing local OpenCL device(s) at once.
 */ // }}}
class device_query
{
  template <class Archive>
  friend void _serialize(Archive&, device_query&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \todo Write documentation
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: device_query() {{{
   * \todo Write documentation
   */ // }}}
  device_query();
  /** // doc: device_query() {{{
   * \todo Write documentation
   */ // }}}
  device_query(bool flag);
  /** // doc: ~device_query() {{{
   * \todo Write documentation for class device_query
   */ // }}}
  virtual ~device_query();
  /** // doc: select_all() {{{
   * \todo Write documentation
   */ // }}}
  device_query& select_all() ;
  /** // doc: select_all() {{{
   * \todo Write documentation
   */ // }}}
  device_query& select_none() ;
  /** // doc: select_all() {{{
   * \todo Write documentation
   */ // }}}
  device_query& select_default() ;
  /** // doc: restrict_to(major,minor) {{{
   * \todo Write documentation
   */ // }}}
  device_query& restrict_to(int major, int minor);
  // getters ... {{{
  /** // doc: id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool id_selected() const
  {
    return this->_id;
  }
  /** // doc: type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool type_selected() const
  {
    return this->_type;
  }
  /** // doc: vendor_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool vendor_id_selected() const
  {
    return this->_vendor_id;
  }
  /** // doc: max_compute_units_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_compute_units_selected() const
  {
    return this->_max_compute_units;
  }
  /** // doc: max_work_item_dimensions_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_work_item_dimensions_selected() const
  {
    return this->_max_work_item_dimensions;
  }
  /** // doc: max_work_group_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_work_group_size_selected() const
  {
    return this->_max_work_group_size;
  }
  /** // doc: max_work_item_sizes_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_work_item_sizes_selected() const
  {
    return this->_max_work_item_sizes;
  }
  /** // doc: preferred_vector_width_char_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_char_selected() const
  {
    return this->_preferred_vector_width_char;
  }
  /** // doc: preferred_vector_width_short_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_short_selected() const
  {
    return this->_preferred_vector_width_short;
  }
  /** // doc: preferred_vector_width_int_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_int_selected() const
  {
    return this->_preferred_vector_width_int;
  }
  /** // doc: preferred_vector_width_long_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_long_selected() const
  {
    return this->_preferred_vector_width_long;
  }
  /** // doc: preferred_vector_width_float_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_float_selected() const
  {
    return this->_preferred_vector_width_float;
  }
  /** // doc: preferred_vector_width_double_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_double_selected() const
  {
    return this->_preferred_vector_width_double;
  }
  /** // doc: max_clock_frequency_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_clock_frequency_selected() const
  {
    return this->_max_clock_frequency;
  }
  /** // doc: address_bits_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool address_bits_selected() const
  {
    return this->_address_bits;
  }
  /** // doc: max_read_image_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_read_image_args_selected() const
  {
    return this->_max_read_image_args;
  }
  /** // doc: max_write_image_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_write_image_args_selected() const
  {
    return this->_max_write_image_args;
  }
  /** // doc: max_mem_alloc_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_mem_alloc_size_selected() const
  {
    return this->_max_mem_alloc_size;
  }
  /** // doc: image2d_max_width_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image2d_max_width_selected() const
  {
    return this->_image2d_max_width;
  }
  /** // doc: image2d_max_height_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image2d_max_height_selected() const
  {
    return this->_image2d_max_height;
  }
  /** // doc: image3d_max_width_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image3d_max_width_selected() const
  {
    return this->_image3d_max_width;
  }
  /** // doc: image3d_max_height_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image3d_max_height_selected() const
  {
    return this->_image3d_max_height;
  }
  /** // doc: image3d_max_depth_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image3d_max_depth_selected() const
  {
    return this->_image3d_max_depth;
  }
  /** // doc: image_support_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_support_selected() const
  {
    return this->_image_support;
  }
  /** // doc: max_parameter_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_parameter_size_selected() const
  {
    return this->_max_parameter_size;
  }
  /** // doc: max_samplers_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_samplers_selected() const
  {
    return this->_max_samplers;
  }
  /** // doc: mem_base_addr_align_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool mem_base_addr_align_selected() const
  {
    return this->_mem_base_addr_align;
  }
  /** // doc: min_data_type_align_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool min_data_type_align_size_selected() const
  {
    return this->_min_data_type_align_size;
  }
  /** // doc: single_fp_config_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool single_fp_config_selected() const
  {
    return this->_single_fp_config;
  }
  /** // doc: global_mem_cache_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_cache_type_selected() const
  {
    return this->_global_mem_cache_type;
  }
  /** // doc: global_mem_cacheline_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_cacheline_size_selected() const
  {
    return this->_global_mem_cacheline_size;
  }
  /** // doc: global_mem_cache_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_cache_size_selected() const
  {
    return this->_global_mem_cache_size;
  }
  /** // doc: global_mem_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool global_mem_size_selected() const
  {
    return this->_global_mem_size;
  }
  /** // doc: max_constant_buffer_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_constant_buffer_size_selected() const
  {
    return this->_max_constant_buffer_size;
  }
  /** // doc: max_constant_args_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool max_constant_args_selected() const
  {
    return this->_max_constant_args;
  }
  /** // doc: local_mem_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool local_mem_type_selected() const
  {
    return this->_local_mem_type;
  }
  /** // doc: local_mem_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool local_mem_size_selected() const
  {
    return this->_local_mem_size;
  }
  /** // doc: error_correction_support_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool error_correction_support_selected() const
  {
    return this->_error_correction_support;
  }
  /** // doc: profiling_timer_resolution_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool profiling_timer_resolution_selected() const
  {
    return this->_profiling_timer_resolution;
  }
  /** // doc: endian_little_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool endian_little_selected() const
  {
    return this->_endian_little;
  }
  /** // doc: available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool available_selected() const
  {
    return this->_available;
  }
  /** // doc: compiler_available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool compiler_available_selected() const
  {
    return this->_compiler_available;
  }
  /** // doc: execution_capabilities_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool execution_capabilities_selected() const
  {
    return this->_execution_capabilities;
  }
  /** // doc: queue_properties_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool queue_properties_selected() const
  {
    return this->_queue_properties;
  }
  /** // doc: name_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool name_selected() const
  {
    return this->_name;
  }
  /** // doc: vendor_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool vendor_selected() const
  {
    return this->_vendor;
  }
  /** // doc: driver_version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool driver_version_selected() const
  {
    return this->_driver_version;
  }
  /** // doc: profile_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool profile_selected() const
  {
    return this->_profile;
  }
  /** // doc: version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool version_selected() const
  {
    return this->_version;
  }
  /** // doc: extensions_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool extensions_selected() const
  {
    return this->_extensions;
  }
  /** // doc: platform_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool platform_id_selected() const
  {
    return this->_platform_id;
  }
  /** // doc: double_fp_config_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool double_fp_config_selected() const
  {
    return this->_double_fp_config;
  }
  /** // doc: preferred_vector_width_half_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_vector_width_half_selected() const
  {
    return this->_preferred_vector_width_half;
  }
  /** // doc: host_unified_memory_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool host_unified_memory_selected() const
  {
    return this->_host_unified_memory;
  }
  /** // doc: native_vector_width_char_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_char_selected() const
  {
    return this->_native_vector_width_char;
  }
  /** // doc: native_vector_width_short_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_short_selected() const
  {
    return this->_native_vector_width_short;
  }
  /** // doc: native_vector_width_int_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_int_selected() const
  {
    return this->_native_vector_width_int;
  }
  /** // doc: native_vector_width_long_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_long_selected() const
  {
    return this->_native_vector_width_long;
  }
  /** // doc: native_vector_width_float_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_float_selected() const
  {
    return this->_native_vector_width_float;
  }
  /** // doc: native_vector_width_double_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_double_selected() const
  {
    return this->_native_vector_width_double;
  }
  /** // doc: native_vector_width_half_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool native_vector_width_half_selected() const
  {
    return this->_native_vector_width_half;
  }
  /** // doc: opencl_c_version_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool opencl_c_version_selected() const
  {
    return this->_opencl_c_version;
  }
  /** // doc: linker_available_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool linker_available_selected() const
  {
    return this->_linker_available;
  }
  /** // doc: built_in_kernels_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool built_in_kernels_selected() const
  {
    return this->_built_in_kernels;
  }
  /** // doc: image_max_buffer_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_max_buffer_size_selected() const
  {
    return this->_image_max_buffer_size;
  }
  /** // doc: image_max_array_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_max_array_size_selected() const
  {
    return this->_image_max_array_size;
  }
  /** // doc: parent_device_id_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool parent_device_id_selected() const
  {
    return this->_parent_device_id;
  }
  /** // doc: partition_max_sub_devices_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_max_sub_devices_selected() const
  {
    return this->_partition_max_sub_devices;
  }
  /** // doc: partition_properties_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_properties_selected() const
  {
    return this->_partition_properties;
  }
  /** // doc: partition_affinity_domain_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_affinity_domain_selected() const
  {
    return this->_partition_affinity_domain;
  }
  /** // doc: partition_type_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool partition_type_selected() const
  {
    return this->_partition_type;
  }
  /** // doc: reference_count_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool reference_count_selected() const
  {
    return this->_reference_count;
  }
  /** // doc: preferred_interop_user_sync_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool preferred_interop_user_sync_selected() const
  {
    return this->_preferred_interop_user_sync;
  }
  /** // doc: printf_buffer_size_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool printf_buffer_size_selected() const
  {
    return this->_printf_buffer_size;
  }
  /** // doc: image_pitch_alignment_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_pitch_alignment_selected() const
  {
    return this->_image_pitch_alignment;
  }
  /** // doc: image_base_address_alignment_selected() {{{
   * \todo Write documentation
   */ //  }}}
  inline bool image_base_address_alignment_selected() const
  {
    return this->_image_base_address_alignment;
  }
  // }}}
  // selectors {{{
  /** // doc: select_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_id(bool flag = true)
  {
    this->_id = flag;
    return *this;
  }
  /** // doc: select_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_type(bool flag = true)
  {
    this->_type = flag;
    return *this;
  }
  /** // doc: select_vendor_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_vendor_id(bool flag = true)
  {
    this->_vendor_id = flag;
    return *this;
  }
  /** // doc: select_max_compute_units() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_compute_units(bool flag = true)
  {
    this->_max_compute_units = flag;
    return *this;
  }
  /** // doc: select_max_work_item_dimensions() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_work_item_dimensions(bool flag = true)
  {
    this->_max_work_item_dimensions = flag;
    return *this;
  }
  /** // doc: select_max_work_group_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_work_group_size(bool flag = true)
  {
    this->_max_work_group_size = flag;
    return *this;
  }
  /** // doc: select_max_work_item_sizes() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_work_item_sizes(bool flag = true)
  {
    this->_max_work_item_sizes = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_char() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_vector_width_char(bool flag = true)
  {
    this->_preferred_vector_width_char = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_short() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_vector_width_short(bool flag = true)
  {
    this->_preferred_vector_width_short = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_int() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_vector_width_int(bool flag = true)
  {
    this->_preferred_vector_width_int = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_long() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_vector_width_long(bool flag = true)
  {
    this->_preferred_vector_width_long = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_float() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_vector_width_float(bool flag = true)
  {
    this->_preferred_vector_width_float = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_double() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_vector_width_double(bool flag = true)
  {
    this->_preferred_vector_width_double = flag;
    return *this;
  }
  /** // doc: select_max_clock_frequency() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_clock_frequency(bool flag = true)
  {
    this->_max_clock_frequency = flag;
    return *this;
  }
  /** // doc: select_address_bits() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_address_bits(bool flag = true)
  {
    this->_address_bits = flag;
    return *this;
  }
  /** // doc: select_max_read_image_args() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_read_image_args(bool flag = true)
  {
    this->_max_read_image_args = flag;
    return *this;
  }
  /** // doc: select_max_write_image_args() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_write_image_args(bool flag = true)
  {
    this->_max_write_image_args = flag;
    return *this;
  }
  /** // doc: select_max_mem_alloc_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_mem_alloc_size(bool flag = true)
  {
    this->_max_mem_alloc_size = flag;
    return *this;
  }
  /** // doc: select_image2d_max_width() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image2d_max_width(bool flag = true)
  {
    this->_image2d_max_width = flag;
    return *this;
  }
  /** // doc: select_image2d_max_height() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image2d_max_height(bool flag = true)
  {
    this->_image2d_max_height = flag;
    return *this;
  }
  /** // doc: select_image3d_max_width() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image3d_max_width(bool flag = true)
  {
    this->_image3d_max_width = flag;
    return *this;
  }
  /** // doc: select_image3d_max_height() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image3d_max_height(bool flag = true)
  {
    this->_image3d_max_height = flag;
    return *this;
  }
  /** // doc: select_image3d_max_depth() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image3d_max_depth(bool flag = true)
  {
    this->_image3d_max_depth = flag;
    return *this;
  }
  /** // doc: select_image_support() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image_support(bool flag = true)
  {
    this->_image_support = flag;
    return *this;
  }
  /** // doc: select_max_parameter_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_parameter_size(bool flag = true)
  {
    this->_max_parameter_size = flag;
    return *this;
  }
  /** // doc: select_max_samplers() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_samplers(bool flag = true)
  {
    this->_max_samplers = flag;
    return *this;
  }
  /** // doc: select_mem_base_addr_align() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_mem_base_addr_align(bool flag = true)
  {
    this->_mem_base_addr_align = flag;
    return *this;
  }
  /** // doc: select_min_data_type_align_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_min_data_type_align_size(bool flag = true)
  {
    this->_min_data_type_align_size = flag;
    return *this;
  }
  /** // doc: select_single_fp_config() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_single_fp_config(bool flag = true)
  {
    this->_single_fp_config = flag;
    return *this;
  }
  /** // doc: select_global_mem_cache_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_global_mem_cache_type(bool flag = true)
  {
    this->_global_mem_cache_type = flag;
    return *this;
  }
  /** // doc: select_global_mem_cacheline_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_global_mem_cacheline_size(bool flag = true)
  {
    this->_global_mem_cacheline_size = flag;
    return *this;
  }
  /** // doc: select_global_mem_cache_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_global_mem_cache_size(bool flag = true)
  {
    this->_global_mem_cache_size = flag;
    return *this;
  }
  /** // doc: select_global_mem_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_global_mem_size(bool flag = true)
  {
    this->_global_mem_size = flag;
    return *this;
  }
  /** // doc: select_max_constant_buffer_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_constant_buffer_size(bool flag = true)
  {
    this->_max_constant_buffer_size = flag;
    return *this;
  }
  /** // doc: select_max_constant_args() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_max_constant_args(bool flag = true)
  {
    this->_max_constant_args = flag;
    return *this;
  }
  /** // doc: select_local_mem_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_local_mem_type(bool flag = true)
  {
    this->_local_mem_type = flag;
    return *this;
  }
  /** // doc: select_local_mem_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_local_mem_size(bool flag = true)
  {
    this->_local_mem_size = flag;
    return *this;
  }
  /** // doc: select_error_correction_support() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_error_correction_support(bool flag = true)
  {
    this->_error_correction_support = flag;
    return *this;
  }
  /** // doc: select_profiling_timer_resolution() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_profiling_timer_resolution(bool flag = true)
  {
    this->_profiling_timer_resolution = flag;
    return *this;
  }
  /** // doc: select_endian_little() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_endian_little(bool flag = true)
  {
    this->_endian_little = flag;
    return *this;
  }
  /** // doc: select_available() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_available(bool flag = true)
  {
    this->_available = flag;
    return *this;
  }
  /** // doc: select_compiler_available() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_compiler_available(bool flag = true)
  {
    this->_compiler_available = flag;
    return *this;
  }
  /** // doc: select_execution_capabilities() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_execution_capabilities(bool flag = true)
  {
    this->_execution_capabilities = flag;
    return *this;
  }
  /** // doc: select_queue_properties() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_queue_properties(bool flag = true)
  {
    this->_queue_properties = flag;
    return *this;
  }
  /** // doc: select_name() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_name(bool flag = true)
  {
    this->_name = flag;
    return *this;
  }
  /** // doc: select_vendor() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_vendor(bool flag = true)
  {
    this->_vendor = flag;
    return *this;
  }
  /** // doc: select_driver_version() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_driver_version(bool flag = true)
  {
    this->_driver_version = flag;
    return *this;
  }
  /** // doc: select_profile() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_profile(bool flag = true)
  {
    this->_profile = flag;
    return *this;
  }
  /** // doc: select_version() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_version(bool flag = true)
  {
    this->_version = flag;
    return *this;
  }
  /** // doc: select_extensions() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_extensions(bool flag = true)
  {
    this->_extensions = flag;
    return *this;
  }
  /** // doc: select_platform_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_platform_id(bool flag = true)
  {
    this->_platform_id = flag;
    return *this;
  }
  /** // doc: select_double_fp_config() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_double_fp_config(bool flag = true)
  {
    this->_double_fp_config = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_half() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_vector_width_half(bool flag = true)
  {
    this->_preferred_vector_width_half = flag;
    return *this;
  }
  /** // doc: select_host_unified_memory() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_host_unified_memory(bool flag = true)
  {
    this->_host_unified_memory = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_char() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_native_vector_width_char(bool flag = true)
  {
    this->_native_vector_width_char = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_short() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_native_vector_width_short(bool flag = true)
  {
    this->_native_vector_width_short = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_int() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_native_vector_width_int(bool flag = true)
  {
    this->_native_vector_width_int = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_long() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_native_vector_width_long(bool flag = true)
  {
    this->_native_vector_width_long = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_float() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_native_vector_width_float(bool flag = true)
  {
    this->_native_vector_width_float = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_double() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_native_vector_width_double(bool flag = true)
  {
    this->_native_vector_width_double = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_half() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_native_vector_width_half(bool flag = true)
  {
    this->_native_vector_width_half = flag;
    return *this;
  }
  /** // doc: select_opencl_c_version() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_opencl_c_version(bool flag = true)
  {
    this->_opencl_c_version = flag;
    return *this;
  }
  /** // doc: select_linker_available() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_linker_available(bool flag = true)
  {
    this->_linker_available = flag;
    return *this;
  }
  /** // doc: select_built_in_kernels() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_built_in_kernels(bool flag = true)
  {
    this->_built_in_kernels = flag;
    return *this;
  }
  /** // doc: select_image_max_buffer_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image_max_buffer_size(bool flag = true)
  {
    this->_image_max_buffer_size = flag;
    return *this;
  }
  /** // doc: select_image_max_array_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image_max_array_size(bool flag = true)
  {
    this->_image_max_array_size = flag;
    return *this;
  }
  /** // doc: select_parent_device_id() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_parent_device_id(bool flag = true)
  {
    this->_parent_device_id = flag;
    return *this;
  }
  /** // doc: select_partition_max_sub_devices() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_partition_max_sub_devices(bool flag = true)
  {
    this->_partition_max_sub_devices = flag;
    return *this;
  }
  /** // doc: select_partition_properties() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_partition_properties(bool flag = true)
  {
    this->_partition_properties = flag;
    return *this;
  }
  /** // doc: select_partition_affinity_domain() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_partition_affinity_domain(bool flag = true)
  {
    this->_partition_affinity_domain = flag;
    return *this;
  }
  /** // doc: select_partition_type() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_partition_type(bool flag = true)
  {
    this->_partition_type = flag;
    return *this;
  }
  /** // doc: select_reference_count() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_reference_count(bool flag = true)
  {
    this->_reference_count = flag;
    return *this;
  }
  /** // doc: select_preferred_interop_user_sync() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_preferred_interop_user_sync(bool flag = true)
  {
    this->_preferred_interop_user_sync = flag;
    return *this;
  }
  /** // doc: select_printf_buffer_size() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_printf_buffer_size(bool flag = true)
  {
    this->_printf_buffer_size = flag;
    return *this;
  }
  /** // doc: select_image_pitch_alignment() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image_pitch_alignment(bool flag = true)
  {
    this->_image_pitch_alignment = flag;
    return *this;
  }
  /** // doc: select_image_base_address_alignment() {{{
   * \todo Write documentation
   */ //  }}}
  inline device_query& select_image_base_address_alignment(bool flag = true)
  {
    this->_image_base_address_alignment = flag;
    return *this;
  }
  // }}}
private:
  void _select(bool flag);
  void _init(bool flag);
  // attributes {{{
  bool _id;
  bool _type;
  bool _vendor_id;
  bool _max_compute_units;
  bool _max_work_item_dimensions;
  bool _max_work_group_size;
  bool _max_work_item_sizes;
  bool _preferred_vector_width_char;
  bool _preferred_vector_width_short;
  bool _preferred_vector_width_int;
  bool _preferred_vector_width_long;
  bool _preferred_vector_width_float;
  bool _preferred_vector_width_double;
  bool _max_clock_frequency;
  bool _address_bits;
  bool _max_read_image_args;
  bool _max_write_image_args;
  bool _max_mem_alloc_size;
  bool _image2d_max_width;
  bool _image2d_max_height;
  bool _image3d_max_width;
  bool _image3d_max_height;
  bool _image3d_max_depth;
  bool _image_support;
  bool _max_parameter_size;
  bool _max_samplers;
  bool _mem_base_addr_align;
  bool _min_data_type_align_size;
  bool _single_fp_config;
  bool _global_mem_cache_type;
  bool _global_mem_cacheline_size;
  bool _global_mem_cache_size;
  bool _global_mem_size;
  bool _max_constant_buffer_size;
  bool _max_constant_args;
  bool _local_mem_type;
  bool _local_mem_size;
  bool _error_correction_support;
  bool _profiling_timer_resolution;
  bool _endian_little;
  bool _available;
  bool _compiler_available;
  bool _execution_capabilities;
  bool _queue_properties;
  bool _name;
  bool _vendor;
  bool _driver_version;
  bool _profile;
  bool _version;
  bool _extensions;
  bool _platform_id;
  bool _double_fp_config;
  bool _preferred_vector_width_half;
  bool _host_unified_memory;
  bool _native_vector_width_char;
  bool _native_vector_width_short;
  bool _native_vector_width_int;
  bool _native_vector_width_long;
  bool _native_vector_width_float;
  bool _native_vector_width_double;
  bool _native_vector_width_half;
  bool _opencl_c_version;
  bool _linker_available;
  bool _built_in_kernels;
  bool _image_max_buffer_size;
  bool _image_max_array_size;
  bool _parent_device_id;
  bool _partition_max_sub_devices;
  bool _partition_properties;
  bool _partition_affinity_domain;
  bool _partition_type;
  bool _reference_count;
  bool _preferred_interop_user_sync;
  bool _printf_buffer_size;
  bool _image_pitch_alignment;
  bool _image_base_address_alignment;
  // }}}
};
/** // doc: operator==(device_query, device_query) {{{
 * \todo Write documentation
 */ // }}}
bool operator==(device_query const&, device_query const&);
/** // doc: operator!=(device_query, device_query) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!=(device_query const& a, device_query const& b)
{ return !(a == b);}

} // end namespace clxx

#endif /* CLXX_DEVICE_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
