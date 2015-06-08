// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/device_info.li.swg {{{
 * \file clxx/device_info.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/device_info.hpp>
%}
%include <clxx/exception_support.swg>

%throws_uninitialized_value_error(clxx::device_info::id() const);
%throws_uninitialized_value_error(clxx::device_info::type() const);
%throws_uninitialized_value_error(clxx::device_info::vendor_id() const);
%throws_uninitialized_value_error(clxx::device_info::max_compute_units() const);
%throws_uninitialized_value_error(clxx::device_info::max_work_item_dimensions() const);
%throws_uninitialized_value_error(clxx::device_info::max_work_group_size() const);
%throws_badalloc_uninitialized_value_error(clxx::device_info::max_work_item_sizes() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_vector_width_char() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_vector_width_short() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_vector_width_int() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_vector_width_long() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_vector_width_float() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_vector_width_double() const);
%throws_uninitialized_value_error(clxx::device_info::max_clock_frequency() const);
%throws_uninitialized_value_error(clxx::device_info::address_bits() const);
%throws_uninitialized_value_error(clxx::device_info::max_read_image_args() const);
%throws_uninitialized_value_error(clxx::device_info::max_write_image_args() const);
%throws_uninitialized_value_error(clxx::device_info::max_mem_alloc_size() const);
%throws_uninitialized_value_error(clxx::device_info::image2d_max_width() const);
%throws_uninitialized_value_error(clxx::device_info::image2d_max_height() const);
%throws_uninitialized_value_error(clxx::device_info::image3d_max_width() const);
%throws_uninitialized_value_error(clxx::device_info::image3d_max_height() const);
%throws_uninitialized_value_error(clxx::device_info::image3d_max_depth() const);
%throws_uninitialized_value_error(clxx::device_info::image_support() const);
%throws_uninitialized_value_error(clxx::device_info::max_parameter_size() const);
%throws_uninitialized_value_error(clxx::device_info::max_samplers() const);
%throws_uninitialized_value_error(clxx::device_info::mem_base_addr_align() const);
%throws_uninitialized_value_error(clxx::device_info::min_data_type_align_size() const);
%throws_uninitialized_value_error(clxx::device_info::single_fp_config() const);
%throws_uninitialized_value_error(clxx::device_info::global_mem_cache_type() const);
%throws_uninitialized_value_error(clxx::device_info::global_mem_cacheline_size() const);
%throws_uninitialized_value_error(clxx::device_info::global_mem_cache_size() const);
%throws_uninitialized_value_error(clxx::device_info::global_mem_size() const);
%throws_uninitialized_value_error(clxx::device_info::max_constant_buffer_size() const);
%throws_uninitialized_value_error(clxx::device_info::max_constant_args() const);
%throws_uninitialized_value_error(clxx::device_info::local_mem_type() const);
%throws_uninitialized_value_error(clxx::device_info::local_mem_size() const);
%throws_uninitialized_value_error(clxx::device_info::error_correction_support() const);
%throws_uninitialized_value_error(clxx::device_info::profiling_timer_resolution() const);
%throws_uninitialized_value_error(clxx::device_info::endian_little() const);
%throws_uninitialized_value_error(clxx::device_info::available() const);
%throws_uninitialized_value_error(clxx::device_info::compiler_available() const);
%throws_uninitialized_value_error(clxx::device_info::execution_capabilities() const);
%throws_uninitialized_value_error(clxx::device_info::queue_properties() const);
%throws_uninitialized_value_error(clxx::device_info::name() const);
%throws_uninitialized_value_error(clxx::device_info::vendor() const);
%throws_uninitialized_value_error(clxx::device_info::driver_version() const);
%throws_uninitialized_value_error(clxx::device_info::profile() const);
%throws_uninitialized_value_error(clxx::device_info::version() const);
%throws_uninitialized_value_error(clxx::device_info::extensions() const);
%throws_uninitialized_value_error(clxx::device_info::platform_id() const);
%throws_uninitialized_value_error(clxx::device_info::double_fp_config() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_vector_width_half() const);
%throws_uninitialized_value_error(clxx::device_info::host_unified_memory() const);
%throws_uninitialized_value_error(clxx::device_info::native_vector_width_char() const);
%throws_uninitialized_value_error(clxx::device_info::native_vector_width_short() const);
%throws_uninitialized_value_error(clxx::device_info::native_vector_width_int() const);
%throws_uninitialized_value_error(clxx::device_info::native_vector_width_long() const);
%throws_uninitialized_value_error(clxx::device_info::native_vector_width_float() const);
%throws_uninitialized_value_error(clxx::device_info::native_vector_width_double() const);
%throws_uninitialized_value_error(clxx::device_info::native_vector_width_half() const);
%throws_uninitialized_value_error(clxx::device_info::opencl_c_version() const);
%throws_uninitialized_value_error(clxx::device_info::linker_available() const);
%throws_uninitialized_value_error(clxx::device_info::built_in_kernels() const);
%throws_uninitialized_value_error(clxx::device_info::image_max_buffer_size() const);
%throws_uninitialized_value_error(clxx::device_info::image_max_array_size() const);
%throws_uninitialized_value_error(clxx::device_info::parent_device_id() const);
%throws_uninitialized_value_error(clxx::device_info::partition_max_sub_devices() const);
%throws_badalloc_uninitialized_value_error(clxx::device_info::partition_properties() const);
%throws_uninitialized_value_error(clxx::device_info::partition_affinity_domain() const);
%throws_uninitialized_value_error(clxx::device_info::partition_type() const);
%throws_uninitialized_value_error(clxx::device_info::reference_count() const);
%throws_uninitialized_value_error(clxx::device_info::preferred_interop_user_sync() const);
%throws_uninitialized_value_error(clxx::device_info::printf_buffer_size() const);
%throws_uninitialized_value_error(clxx::device_info::image_pitch_alignment() const);
%throws_uninitialized_value_error(clxx::device_info::image_base_address_alignment() const);


%throws_badalloc(clxx::device_info::set_max_work_item_sizes(std::vector<size_t> const&));
%throws_badalloc(clxx::device_info::set_name(std::string const&));
%throws_badalloc(clxx::device_info::set_vendor(std::string const&));
%throws_badalloc(clxx::device_info::set_driver_version(std::string const&));
%throws_badalloc(clxx::device_info::set_profile(std::string const&));
%throws_badalloc(clxx::device_info::set_version(std::string const&));
%throws_badalloc(clxx::device_info::set_extensions(std::string const&));
%throws_badalloc(clxx::device_info::set_opencl_c_version(std::string const&));
%throws_badalloc(clxx::device_info::set_built_in_kernels(std::string const&));
%throws_badalloc(clxx::device_info::set_partition_properties(std::vector<device_partition_property_t> const&));
%throws_badalloc(clxx::device_info::set_partition_type(std::vector<device_partition_property_t> const&));

%include <clxx/device_info.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
