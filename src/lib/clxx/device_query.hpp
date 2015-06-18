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
 * \ingroup clxx_info
 * \brief Indicates what information to retrieve from a device.
 *
 * This class encapsulates several boolean flags which indicate what
 * information should be retrieved from an OpenCL device when performing
 * a device info query. Objects of type #device_query are used together with
 * #query_device_info() function and #clxx::device_info class to query and store
 * several parameters describing local OpenCL device(s) at once.
 *
 * For each device info parameter \em xxx two methods are provided by the
 * class:
 *
 * - \em xxx_selected() - to check if attribute \em xxx is selected for query,
 * - \em select_xxx() - to select or deselect attribute \em xxx.
 */ // }}}
class device_query
{
  template <class Archive>
  friend void _serialize(Archive&, device_query&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \brief Version number of this class
   *
   * This is used by the serialization module (see \ref clxx_s11n)
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: device_query() {{{
   * \brief Default constructor
   *
   * Initially selects all attributes to be queried (see #select_all())
   */ // }}}
  device_query() noexcept;
  /** // doc: device_query() {{{
   * \brief Constructor
   *
   * \param flag
   *    If set to \c true, then all attributes are selected to be queried.
   *    Otherwise (\em flag = \c false) all parameters are deselected.
   */ // }}}
  device_query(bool flag) noexcept;
  /** // doc: ~device_query() {{{
   * \brief Destructor
   */ // }}}
  virtual ~device_query() noexcept;
  /** // doc: select_all() {{{
   * \brief Select all attributes to be queried
   * \returns A mutable reference to the modified #device_query object
   */ // }}}
  device_query& select_all() noexcept;
  /** // doc: select_all() {{{
   * \brief Deselect all attributes in query
   * \returns A mutable reference to the modified #device_query object
   */ // }}}
  device_query& select_none() noexcept;
  /** // doc: select_default() {{{
   * \brief Set default selection
   *
   * This function sets default selection, which currently is "select none".
   * It's guaranteed that the query is exactly same when default-constructed
   * or after the call to #select_default().
   *
   * \returns A mutable reference to the modified #device_query object.
   */ // }}}
  device_query& select_default() noexcept;
  /** // doc: restrict_to(major,minor) {{{
   * \brief Restrict query setting to be compatible with given OpenCL version
   *
   * When performing actual query on an OpenCL device one has to take into
   * account the version of device's driver/firmware. Older devices may be
   * missing certain attributes which are defined in later versions of the
   * OpenCL standard. Querying device for an (unsupported) property would raise
   * an exception (invalid device info).
   *
   * The #restrict_to() method is provided to easily avoid this issue. Once
   * the device version is known, the #restrict_to() might be used to adjust
   * the query such that all the attributes not present in a given OpenCL
   * version automatically get deselected.
   *
   * \param major
   *    Major number of the OpenCL version
   * \param minor
   *    Minor number of the OpenCL version
   *
   * \returns A mutable reference to the modified #device_query object.
   */ // }}}
  device_query& restrict_to(int major, int minor) noexcept;
  // getters ... {{{
  /** // doc: id_selected() {{{
   * \brief Is \ref device_info::id "id" selected
   * \returns \c true if \ref device_info::id "id" is selected or \c false if not
   */ //  }}}
  inline bool id_selected() const noexcept
  {
    return this->_id;
  }
  /** // doc: type_selected() {{{
   * \brief Is \ref device_info::type "type" selected
   * \returns \c true if \ref device_info::type "type" is selected or \c false if not
   */ //  }}}
  inline bool type_selected() const noexcept
  {
    return this->_type;
  }
  /** // doc: vendor_id_selected() {{{
   * \brief Is \ref device_info::vendor_id "vendor_id" selected
   * \returns \c true if \ref device_info::vendor_id "vendor_id" is selected or \c false if not
   */ //  }}}
  inline bool vendor_id_selected() const noexcept
  {
    return this->_vendor_id;
  }
  /** // doc: max_compute_units_selected() {{{
   * \brief Is \ref device_info::max_compute_units "max_compute_units" selected
   * \returns \c true if \ref device_info::max_compute_units "max_compute_units" is selected or \c false if not
   */ //  }}}
  inline bool max_compute_units_selected() const noexcept
  {
    return this->_max_compute_units;
  }
  /** // doc: max_work_item_dimensions_selected() {{{
   * \brief Is \ref device_info::max_work_item_dimensions "max_work_item_dimensions" selected
   * \returns \c true if \ref device_info::max_work_item_dimensions "max_work_item_dimensions" is selected or \c false if not
   */ //  }}}
  inline bool max_work_item_dimensions_selected() const noexcept
  {
    return this->_max_work_item_dimensions;
  }
  /** // doc: max_work_group_size_selected() {{{
   * \brief Is \ref device_info::max_work_group_size "max_work_group_size" selected
   * \returns \c true if \ref device_info::max_work_group_size "max_work_group_size" is selected or \c false if not
   */ //  }}}
  inline bool max_work_group_size_selected() const noexcept
  {
    return this->_max_work_group_size;
  }
  /** // doc: max_work_item_sizes_selected() {{{
   * \brief Is \ref device_info::max_work_item_sizes "max_work_item_sizes" selected
   * \returns \c true if \ref device_info::max_work_item_sizes "max_work_item_sizes" is selected or \c false if not
   */ //  }}}
  inline bool max_work_item_sizes_selected() const noexcept
  {
    return this->_max_work_item_sizes;
  }
  /** // doc: preferred_vector_width_char_selected() {{{
   * \brief Is \ref device_info::preferred_vector_width_char "preferred_vector_width_char" selected
   * \returns \c true if \ref device_info::preferred_vector_width_char "preferred_vector_width_char" is selected or \c false if not
   */ //  }}}
  inline bool preferred_vector_width_char_selected() const noexcept
  {
    return this->_preferred_vector_width_char;
  }
  /** // doc: preferred_vector_width_short_selected() {{{
   * \brief Is \ref device_info::preferred_vector_width_short "preferred_vector_width_short" selected
   * \returns \c true if \ref device_info::preferred_vector_width_short "preferred_vector_width_short" is selected or \c false if not
   */ //  }}}
  inline bool preferred_vector_width_short_selected() const noexcept
  {
    return this->_preferred_vector_width_short;
  }
  /** // doc: preferred_vector_width_int_selected() {{{
   * \brief Is \ref device_info::preferred_vector_width_int "preferred_vector_width_int" selected
   * \returns \c true if \ref device_info::preferred_vector_width_int "preferred_vector_width_int" is selected or \c false if not
   */ //  }}}
  inline bool preferred_vector_width_int_selected() const noexcept
  {
    return this->_preferred_vector_width_int;
  }
  /** // doc: preferred_vector_width_long_selected() {{{
   * \brief Is \ref device_info::preferred_vector_width_long "preferred_vector_width_long" selected
   * \returns \c true if \ref device_info::preferred_vector_width_long "preferred_vector_width_long" is selected or \c false if not
   */ //  }}}
  inline bool preferred_vector_width_long_selected() const noexcept
  {
    return this->_preferred_vector_width_long;
  }
  /** // doc: preferred_vector_width_float_selected() {{{
   * \brief Is \ref device_info::preferred_vector_width_float "preferred_vector_width_float" selected
   * \returns \c true if \ref device_info::preferred_vector_width_float "preferred_vector_width_float" is selected or \c false if not
   */ //  }}}
  inline bool preferred_vector_width_float_selected() const noexcept
  {
    return this->_preferred_vector_width_float;
  }
  /** // doc: preferred_vector_width_double_selected() {{{
   * \brief Is \ref device_info::preferred_vector_width_double "preferred_vector_width_double" selected
   * \returns \c true if \ref device_info::preferred_vector_width_double "preferred_vector_width_double" is selected or \c false if not
   */ //  }}}
  inline bool preferred_vector_width_double_selected() const noexcept
  {
    return this->_preferred_vector_width_double;
  }
  /** // doc: max_clock_frequency_selected() {{{
   * \brief Is \ref device_info::max_clock_frequency "max_clock_frequency" selected
   * \returns \c true if \ref device_info::max_clock_frequency "max_clock_frequency" is selected or \c false if not
   */ //  }}}
  inline bool max_clock_frequency_selected() const noexcept
  {
    return this->_max_clock_frequency;
  }
  /** // doc: address_bits_selected() {{{
   * \brief Is \ref device_info::address_bits "address_bits" selected
   * \returns \c true if \ref device_info::address_bits "address_bits" is selected or \c false if not
   */ //  }}}
  inline bool address_bits_selected() const noexcept
  {
    return this->_address_bits;
  }
  /** // doc: max_read_image_args_selected() {{{
   * \brief Is \ref device_info::max_read_image_args "max_read_image_args" selected
   * \returns \c true if \ref device_info::max_read_image_args "max_read_image_args" is selected or \c false if not
   */ //  }}}
  inline bool max_read_image_args_selected() const noexcept
  {
    return this->_max_read_image_args;
  }
  /** // doc: max_write_image_args_selected() {{{
   * \brief Is \ref device_info::max_write_image_args "max_write_image_args" selected
   * \returns \c true if \ref device_info::max_write_image_args "max_write_image_args" is selected or \c false if not
   */ //  }}}
  inline bool max_write_image_args_selected() const noexcept
  {
    return this->_max_write_image_args;
  }
  /** // doc: max_mem_alloc_size_selected() {{{
   * \brief Is \ref device_info::max_mem_alloc_size "max_mem_alloc_size" selected
   * \returns \c true if \ref device_info::max_mem_alloc_size "max_mem_alloc_size" is selected or \c false if not
   */ //  }}}
  inline bool max_mem_alloc_size_selected() const noexcept
  {
    return this->_max_mem_alloc_size;
  }
  /** // doc: image2d_max_width_selected() {{{
   * \brief Is \ref device_info::image2d_max_width "image2d_max_width" selected
   * \returns \c true if \ref device_info::image2d_max_width "image2d_max_width" is selected or \c false if not
   */ //  }}}
  inline bool image2d_max_width_selected() const noexcept
  {
    return this->_image2d_max_width;
  }
  /** // doc: image2d_max_height_selected() {{{
   * \brief Is \ref device_info::image2d_max_height "image2d_max_height" selected
   * \returns \c true if \ref device_info::image2d_max_height "image2d_max_height" is selected or \c false if not
   */ //  }}}
  inline bool image2d_max_height_selected() const noexcept
  {
    return this->_image2d_max_height;
  }
  /** // doc: image3d_max_width_selected() {{{
   * \brief Is \ref device_info::image3d_max_width "image3d_max_width" selected
   * \returns \c true if \ref device_info::image3d_max_width "image3d_max_width" is selected or \c false if not
   */ //  }}}
  inline bool image3d_max_width_selected() const noexcept
  {
    return this->_image3d_max_width;
  }
  /** // doc: image3d_max_height_selected() {{{
   * \brief Is \ref device_info::image3d_max_height "image3d_max_height" selected
   * \returns \c true if \ref device_info::image3d_max_height "image3d_max_height" is selected or \c false if not
   */ //  }}}
  inline bool image3d_max_height_selected() const noexcept
  {
    return this->_image3d_max_height;
  }
  /** // doc: image3d_max_depth_selected() {{{
   * \brief Is \ref device_info::image3d_max_depth "image3d_max_depth" selected
   * \returns \c true if \ref device_info::image3d_max_depth "mage3d_max_depth" is selected or \c false if not
   */ //  }}}
  inline bool image3d_max_depth_selected() const noexcept
  {
    return this->_image3d_max_depth;
  }
  /** // doc: image_support_selected() {{{
   * \brief Is \ref device_info::image_support "image_support" selected
   * \returns \c true if \ref device_info::image_support "image_support" is selected or \c false if not
   */ //  }}}
  inline bool image_support_selected() const noexcept
  {
    return this->_image_support;
  }
  /** // doc: max_parameter_size_selected() {{{
   * \brief Is \ref device_info::max_parameter_size "max_parameter_size" selected
   * \returns \c true if \ref device_info::max_parameter_size "max_parameter_size" is selected or \c false if not
   */ //  }}}
  inline bool max_parameter_size_selected() const noexcept
  {
    return this->_max_parameter_size;
  }
  /** // doc: max_samplers_selected() {{{
   * \brief Is \ref device_info::max_samplers "max_samplers" selected
   * \returns \c true if \ref device_info::max_samplers "max_samplers" is selected or \c false if not
   */ //  }}}
  inline bool max_samplers_selected() const noexcept
  {
    return this->_max_samplers;
  }
  /** // doc: mem_base_addr_align_selected() {{{
   * \brief Is \ref device_info::mem_base_addr_align "mem_base_addr_align" selected
   * \returns \c true if \ref device_info::mem_base_addr_align "mem_base_addr_align" is selected or \c false if not
   */ //  }}}
  inline bool mem_base_addr_align_selected() const noexcept
  {
    return this->_mem_base_addr_align;
  }
  /** // doc: min_data_type_align_size_selected() {{{
   * \brief Is \ref device_info::min_data_type_align_size "min_data_type_align_size" selected
   * \returns \c true if \ref device_info::min_data_type_align_size "min_data_type_align_size" is selected or \c false if not
   */ //  }}}
  inline bool min_data_type_align_size_selected() const noexcept
  {
    return this->_min_data_type_align_size;
  }
  /** // doc: single_fp_config_selected() {{{
   * \brief Is \ref device_info::single_fp_config "single_fp_config" selected
   * \returns \c true if \ref device_info::single_fp_config "single_fp_config" is selected or \c false if not
   */ //  }}}
  inline bool single_fp_config_selected() const noexcept
  {
    return this->_single_fp_config;
  }
  /** // doc: global_mem_cache_type_selected() {{{
   * \brief Is \ref device_info::global_mem_cache_type "global_mem_cache_type" selected
   * \returns \c true if \ref device_info::global_mem_cache_type "global_mem_cache_type" is selected or \c false if not
   */ //  }}}
  inline bool global_mem_cache_type_selected() const noexcept
  {
    return this->_global_mem_cache_type;
  }
  /** // doc: global_mem_cacheline_size_selected() {{{
   * \brief Is \ref device_info::global_mem_cacheline_size "global_mem_cacheline_size" selected
   * \returns \c true if \ref device_info::global_mem_cacheline_size "global_mem_cacheline_size" is selected or \c false if not
   */ //  }}}
  inline bool global_mem_cacheline_size_selected() const noexcept
  {
    return this->_global_mem_cacheline_size;
  }
  /** // doc: global_mem_cache_size_selected() {{{
   * \brief Is \ref device_info::global_mem_cache_size "global_mem_cache_size" selected
   * \returns \c true if \ref device_info::global_mem_cache_size "global_mem_cache_size" is selected or \c false if not
   */ //  }}}
  inline bool global_mem_cache_size_selected() const noexcept
  {
    return this->_global_mem_cache_size;
  }
  /** // doc: global_mem_size_selected() {{{
   * \brief Is \ref device_info::global_mem_size "global_mem_size" selected
   * \returns \c true if \ref device_info::global_mem_size "global_mem_size" is selected or \c false if not
   */ //  }}}
  inline bool global_mem_size_selected() const noexcept
  {
    return this->_global_mem_size;
  }
  /** // doc: max_constant_buffer_size_selected() {{{
   * \brief Is \ref device_info::max_constant_buffer_size "max_constant_buffer_size" selected
   * \returns \c true if \ref device_info::max_constant_buffer_size "max_constant_buffer_size" is selected or \c false if not
   */ //  }}}
  inline bool max_constant_buffer_size_selected() const noexcept
  {
    return this->_max_constant_buffer_size;
  }
  /** // doc: max_constant_args_selected() {{{
   * \brief Is \ref device_info::max_constant_args "max_constant_args" selected
   * \returns \c true if \ref device_info::max_constant_args "max_constant_args" is selected or \c false if not
   */ //  }}}
  inline bool max_constant_args_selected() const noexcept
  {
    return this->_max_constant_args;
  }
  /** // doc: local_mem_type_selected() {{{
   * \brief Is \ref device_info::local_mem_type "local_mem_type" selected
   * \returns \c true if \ref device_info::local_mem_type "local_mem_type" is selected or \c false if not
   */ //  }}}
  inline bool local_mem_type_selected() const noexcept
  {
    return this->_local_mem_type;
  }
  /** // doc: local_mem_size_selected() {{{
   * \brief Is \ref device_info::local_mem_size "local_mem_size" selected
   * \returns \c true if \ref device_info::local_mem_size "local_mem_size" is selected or \c false if not
   */ //  }}}
  inline bool local_mem_size_selected() const noexcept
  {
    return this->_local_mem_size;
  }
  /** // doc: error_correction_support_selected() {{{
   * \brief Is \ref device_info::error_correction_support "error_correction_support" selected
   * \returns \c true if \ref device_info::error_correction_support "error_correction_support" is selected or \c false if not
   */ //  }}}
  inline bool error_correction_support_selected() const noexcept
  {
    return this->_error_correction_support;
  }
  /** // doc: profiling_timer_resolution_selected() {{{
   * \brief Is \ref device_info::profiling_timer_resolution "profiling_timer_resolution" selected
   * \returns \c true if \ref device_info::profiling_timer_resolution "profiling_timer_resolution" is selected or \c false if not
   */ //  }}}
  inline bool profiling_timer_resolution_selected() const noexcept
  {
    return this->_profiling_timer_resolution;
  }
  /** // doc: endian_little_selected() {{{
   * \brief Is \ref device_info::endian_little "endian_little" selected
   * \returns \c true if \ref device_info::endian_little "endian_little" is selected or \c false if not
   */ //  }}}
  inline bool endian_little_selected() const noexcept
  {
    return this->_endian_little;
  }
  /** // doc: available_selected() {{{
   * \brief Is \ref device_info::available "available" selected
   * \returns \c true if \ref device_info::available "available" is selected or \c false if not
   */ //  }}}
  inline bool available_selected() const noexcept
  {
    return this->_available;
  }
  /** // doc: compiler_available_selected() {{{
   * \brief Is \ref device_info::compiler_available "compiler_available" selected
   * \returns \c true if \ref device_info::compiler_available "compiler_available" is selected or \c false if not
   */ //  }}}
  inline bool compiler_available_selected() const noexcept
  {
    return this->_compiler_available;
  }
  /** // doc: execution_capabilities_selected() {{{
   * \brief Is \ref device_info::execution_capabilities "execution_capabilities" selected
   * \returns \c true if \ref device_info::execution_capabilities "execution_capabilities" is selected or \c false if not
   */ //  }}}
  inline bool execution_capabilities_selected() const noexcept
  {
    return this->_execution_capabilities;
  }
  /** // doc: queue_properties_selected() {{{
   * \brief Is \ref device_info::queue_properties "queue_properties" selected
   * \returns \c true if \ref device_info::queue_properties "queue_properties" is selected or \c false if not
   */ //  }}}
  inline bool queue_properties_selected() const noexcept
  {
    return this->_queue_properties;
  }
  /** // doc: name_selected() {{{
   * \brief Is \ref device_info::name "name" selected
   * \returns \c true if \ref device_info::name "name" is selected or \c false if not
   */ //  }}}
  inline bool name_selected() const noexcept
  {
    return this->_name;
  }
  /** // doc: vendor_selected() {{{
   * \brief Is \ref device_info::vendor "vendor" selected
   * \returns \c true if \ref device_info::vendor "vendor" is selected or \c false if not
   */ //  }}}
  inline bool vendor_selected() const noexcept
  {
    return this->_vendor;
  }
  /** // doc: driver_version_selected() {{{
   * \brief Is \ref device_info::driver_version "driver_version" selected
   * \returns \c true if \ref device_info::driver_version "driver_version" is selected or \c false if not
   */ //  }}}
  inline bool driver_version_selected() const noexcept
  {
    return this->_driver_version;
  }
  /** // doc: profile_selected() {{{
   * \brief Is \ref device_info::profile "profile" selected
   * \returns \c true if \ref device_info::profile "profile" is selected or \c false if not
   */ //  }}}
  inline bool profile_selected() const noexcept
  {
    return this->_profile;
  }
  /** // doc: version_selected() {{{
   * \brief Is \ref device_info::version "version" selected
   * \returns \c true if \ref device_info::version "version" is selected or \c false if not
   */ //  }}}
  inline bool version_selected() const noexcept
  {
    return this->_version;
  }
  /** // doc: extensions_selected() {{{
   * \brief Is \ref device_info::extensions "extensions" selected
   * \returns \c true if \ref device_info::extensions "extensions" is selected or \c false if not
   */ //  }}}
  inline bool extensions_selected() const noexcept
  {
    return this->_extensions;
  }
  /** // doc: platform_id_selected() {{{
   * \brief Is \ref device_info::platform_id "platform_id" selected
   * \returns \c true if \ref device_info::platform_id "platform_id" is selected or \c false if not
   */ //  }}}
  inline bool platform_id_selected() const noexcept
  {
    return this->_platform_id;
  }
  /** // doc: double_fp_config_selected() {{{
   * \brief Is \ref device_info::double_fp_config "double_fp_config" selected
   * \returns \c true if \ref device_info::double_fp_config "double_fp_config" is selected or \c false if not
   */ //  }}}
  inline bool double_fp_config_selected() const noexcept
  {
    return this->_double_fp_config;
  }
  /** // doc: preferred_vector_width_half_selected() {{{
   * \brief Is \ref device_info::preferred_vector_width_half "preferred_vector_width_half" selected
   * \returns \c true if \ref device_info::preferred_vector_width_half "preferred_vector_width_half" is selected or \c false if not
   */ //  }}}
  inline bool preferred_vector_width_half_selected() const noexcept
  {
    return this->_preferred_vector_width_half;
  }
  /** // doc: host_unified_memory_selected() {{{
   * \brief Is \ref device_info::host_unified_memory "host_unified_memory" selected
   * \returns \c true if \ref device_info::host_unified_memory "host_unified_memory" is selected or \c false if not
   */ //  }}}
  inline bool host_unified_memory_selected() const noexcept
  {
    return this->_host_unified_memory;
  }
  /** // doc: native_vector_width_char_selected() {{{
   * \brief Is \ref device_info::native_vector_width_char "native_vector_width_char" selected
   * \returns \c true if \ref device_info::native_vector_width_char "native_vector_width_char" is selected or \c false if not
   */ //  }}}
  inline bool native_vector_width_char_selected() const noexcept
  {
    return this->_native_vector_width_char;
  }
  /** // doc: native_vector_width_short_selected() {{{
   * \brief Is \ref device_info::native_vector_width_short "native_vector_width_short" selected
   * \returns \c true if \ref device_info::native_vector_width_short "native_vector_width_short" is selected or \c false if not
   */ //  }}}
  inline bool native_vector_width_short_selected() const noexcept
  {
    return this->_native_vector_width_short;
  }
  /** // doc: native_vector_width_int_selected() {{{
   * \brief Is \ref device_info::native_vector_width_int "native_vector_width_int" selected
   * \returns \c true if \ref device_info::native_vector_width_int "native_vector_width_int" is selected or \c false if not
   */ //  }}}
  inline bool native_vector_width_int_selected() const noexcept
  {
    return this->_native_vector_width_int;
  }
  /** // doc: native_vector_width_long_selected() {{{
   * \brief Is \ref device_info::native_vector_width_long "native_vector_width_long" selected
   * \returns \c true if \ref device_info::native_vector_width_long "native_vector_width_long" is selected or \c false if not
   */ //  }}}
  inline bool native_vector_width_long_selected() const noexcept
  {
    return this->_native_vector_width_long;
  }
  /** // doc: native_vector_width_float_selected() {{{
   * \brief Is \ref device_info::native_vector_width_float "native_vector_width_float" selected
   * \returns \c true if \ref device_info::native_vector_width_float "native_vector_width_float" is selected or \c false if not
   */ //  }}}
  inline bool native_vector_width_float_selected() const noexcept
  {
    return this->_native_vector_width_float;
  }
  /** // doc: native_vector_width_double_selected() {{{
   * \brief Is \ref device_info::native_vector_width_double "native_vector_width_double" selected
   * \returns \c true if \ref device_info::native_vector_width_double "native_vector_width_double" is selected or \c false if not
   */ //  }}}
  inline bool native_vector_width_double_selected() const noexcept
  {
    return this->_native_vector_width_double;
  }
  /** // doc: native_vector_width_half_selected() {{{
   * \brief Is \ref device_info::native_vector_width_half "native_vector_width_half" selected
   * \returns \c true if \ref device_info::native_vector_width_half "native_vector_width_half" is selected or \c false if not
   */ //  }}}
  inline bool native_vector_width_half_selected() const noexcept
  {
    return this->_native_vector_width_half;
  }
  /** // doc: opencl_c_version_selected() {{{
   * \brief Is \ref device_info::opencl_c_version "opencl_c_version" selected
   * \returns \c true if \ref device_info::opencl_c_version "opencl_c_version" is selected or \c false if not
   */ //  }}}
  inline bool opencl_c_version_selected() const noexcept
  {
    return this->_opencl_c_version;
  }
  /** // doc: linker_available_selected() {{{
   * \brief Is \ref device_info::linker_available "linker_available" selected
   * \returns \c true if \ref device_info::linker_available "linker_available" is selected or \c false if not
   */ //  }}}
  inline bool linker_available_selected() const noexcept
  {
    return this->_linker_available;
  }
  /** // doc: built_in_kernels_selected() {{{
   * \brief Is \ref device_info::built_in_kernels "built_in_kernels" selected
   * \returns \c true if \ref device_info::built_in_kernels "built_in_kernels" is selected or \c false if not
   */ //  }}}
  inline bool built_in_kernels_selected() const noexcept
  {
    return this->_built_in_kernels;
  }
  /** // doc: image_max_buffer_size_selected() {{{
   * \brief Is \ref device_info::image_max_buffer_size "image_max_buffer_size" selected
   * \returns \c true if \ref device_info::image_max_buffer_size "image_max_buffer_size" is selected or \c false if not
   */ //  }}}
  inline bool image_max_buffer_size_selected() const noexcept
  {
    return this->_image_max_buffer_size;
  }
  /** // doc: image_max_array_size_selected() {{{
   * \brief Is \ref device_info::image_max_array_size "image_max_array_size" selected
   * \returns \c true if \ref device_info::image_max_array_size "image_max_array_size" is selected or \c false if not
   */ //  }}}
  inline bool image_max_array_size_selected() const noexcept
  {
    return this->_image_max_array_size;
  }
  /** // doc: parent_device_id_selected() {{{
   * \brief Is \ref device_info::parent_device_id "parent_device_id" selected
   * \returns \c true if \ref device_info::parent_device_id "parent_device_id" is selected or \c false if not
   */ //  }}}
  inline bool parent_device_id_selected() const noexcept
  {
    return this->_parent_device_id;
  }
  /** // doc: partition_max_sub_devices_selected() {{{
   * \brief Is \ref device_info::partition_max_sub_devices "partition_max_sub_devices" selected
   * \returns \c true if \ref device_info::partition_max_sub_devices "partition_max_sub_devices" is selected or \c false if not
   */ //  }}}
  inline bool partition_max_sub_devices_selected() const noexcept
  {
    return this->_partition_max_sub_devices;
  }
  /** // doc: partition_properties_selected() {{{
   * \brief Is \ref device_info::partition_properties "partition_properties" selected
   * \returns \c true if \ref device_info::partition_properties "partition_properties" is selected or \c false if not
   */ //  }}}
  inline bool partition_properties_selected() const noexcept
  {
    return this->_partition_properties;
  }
  /** // doc: partition_affinity_domain_selected() {{{
   * \brief Is \ref device_info::partition_affinity_domain "partition_affinity_domain" selected
   * \returns \c true if \ref device_info::partition_affinity_domain "partition_affinity_domain" is selected or \c false if not
   */ //  }}}
  inline bool partition_affinity_domain_selected() const noexcept
  {
    return this->_partition_affinity_domain;
  }
  /** // doc: partition_type_selected() {{{
   * \brief Is \ref device_info::partition_type "partition_type" selected
   * \returns \c true if \ref device_info::partition_type "partition_type" is selected or \c false if not
   */ //  }}}
  inline bool partition_type_selected() const noexcept
  {
    return this->_partition_type;
  }
  /** // doc: reference_count_selected() {{{
   * \brief Is \ref device_info::reference_count "reference_count" selected
   * \returns \c true if \ref device_info::reference_count "reference_count" is selected or \c false if not
   */ //  }}}
  inline bool reference_count_selected() const noexcept
  {
    return this->_reference_count;
  }
  /** // doc: preferred_interop_user_sync_selected() {{{
   * \brief Is \ref device_info::preferred_interop_user_sync "preferred_interop_user_sync" selected
   * \returns \c true if \ref device_info::preferred_interop_user_sync "preferred_interop_user_sync" is selected or \c false if not
   */ //  }}}
  inline bool preferred_interop_user_sync_selected() const noexcept
  {
    return this->_preferred_interop_user_sync;
  }
  /** // doc: printf_buffer_size_selected() {{{
   * \brief Is \ref device_info::printf_buffer_size "printf_buffer_size" selected
   * \returns \c true if \ref device_info::printf_buffer_size "printf_buffer_size" is selected or \c false if not
   */ //  }}}
  inline bool printf_buffer_size_selected() const noexcept
  {
    return this->_printf_buffer_size;
  }
  /** // doc: image_pitch_alignment_selected() {{{
   * \brief Is \ref device_info::image_pitch_alignment "image_pitch_alignment" selected
   * \returns \c true if \ref device_info::image_pitch_alignment "image_pitch_alignment" is selected or \c false if not
   */ //  }}}
  inline bool image_pitch_alignment_selected() const noexcept
  {
    return this->_image_pitch_alignment;
  }
  /** // doc: image_base_address_alignment_selected() {{{
   * \brief Is \ref device_info::image_base_address_alignment "image_base_address_alignment" selected
   * \returns \c true if \ref device_info::image_base_address_alignment "image_base_address_alignment" is selected or \c false if not
   */ //  }}}
  inline bool image_base_address_alignment_selected() const noexcept
  {
    return this->_image_base_address_alignment;
  }
  // }}}
  // selectors {{{
  /** // doc: select_id() {{{
   * \brief Select or deselect \ref device_info::id "id"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_id(bool flag = true) noexcept
  {
    this->_id = flag;
    return *this;
  }
  /** // doc: select_type() {{{
   * \brief Select or deselect #device_info::type "type"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_type(bool flag = true) noexcept
  {
    this->_type = flag;
    return *this;
  }
  /** // doc: select_vendor_id() {{{
   * \brief Select or deselect \ref device_info::vendor_id "vendor_id"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_vendor_id(bool flag = true) noexcept
  {
    this->_vendor_id = flag;
    return *this;
  }
  /** // doc: select_max_compute_units() {{{
   * \brief Select or deselect \ref device_info::max_compute_units "max_compute_units"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_compute_units(bool flag = true) noexcept
  {
    this->_max_compute_units = flag;
    return *this;
  }
  /** // doc: select_max_work_item_dimensions() {{{
   * \brief Select or deselect \ref device_info::max_work_item_dimensions "max_work_item_dimensions"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_work_item_dimensions(bool flag = true) noexcept
  {
    this->_max_work_item_dimensions = flag;
    return *this;
  }
  /** // doc: select_max_work_group_size() {{{
   * \brief Select or deselect \ref device_info::max_work_group_size "max_work_group_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_work_group_size(bool flag = true) noexcept
  {
    this->_max_work_group_size = flag;
    return *this;
  }
  /** // doc: select_max_work_item_sizes() {{{
   * \brief Select or deselect \ref device_info::max_work_item_sizes "max_work_item_sizes"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_work_item_sizes(bool flag = true) noexcept
  {
    this->_max_work_item_sizes = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_char() {{{
   * \brief Select or deselect \ref device_info::preferred_vector_width_char "preferred_vector_width_char"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_vector_width_char(bool flag = true) noexcept
  {
    this->_preferred_vector_width_char = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_short() {{{
   * \brief Select or deselect \ref device_info::preferred_vector_width_short "preferred_vector_width_short"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_vector_width_short(bool flag = true) noexcept
  {
    this->_preferred_vector_width_short = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_int() {{{
   * \brief Select or deselect \ref device_info::preferred_vector_width_int "preferred_vector_width_int"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_vector_width_int(bool flag = true) noexcept
  {
    this->_preferred_vector_width_int = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_long() {{{
   * \brief Select or deselect \ref device_info::preferred_vector_width_long "preferred_vector_width_long"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_vector_width_long(bool flag = true) noexcept
  {
    this->_preferred_vector_width_long = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_float() {{{
   * \brief Select or deselect \ref device_info::preferred_vector_width_float "preferred_vector_width_float"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_vector_width_float(bool flag = true) noexcept
  {
    this->_preferred_vector_width_float = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_double() {{{
   * \brief Select or deselect \ref device_info::preferred_vector_width_double "preferred_vector_width_double"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_vector_width_double(bool flag = true) noexcept
  {
    this->_preferred_vector_width_double = flag;
    return *this;
  }
  /** // doc: select_max_clock_frequency() {{{
   * \brief Select or deselect \ref device_info::max_clock_frequency "max_clock_frequency"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_clock_frequency(bool flag = true) noexcept
  {
    this->_max_clock_frequency = flag;
    return *this;
  }
  /** // doc: select_address_bits() {{{
   * \brief Select or deselect \ref device_info::address_bits "address_bits"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_address_bits(bool flag = true) noexcept
  {
    this->_address_bits = flag;
    return *this;
  }
  /** // doc: select_max_read_image_args() {{{
   * \brief Select or deselect \ref device_info::max_read_image_args "max_read_image_args"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_read_image_args(bool flag = true) noexcept
  {
    this->_max_read_image_args = flag;
    return *this;
  }
  /** // doc: select_max_write_image_args() {{{
   * \brief Select or deselect \ref device_info::max_write_image_args "max_write_image_args"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_write_image_args(bool flag = true) noexcept
  {
    this->_max_write_image_args = flag;
    return *this;
  }
  /** // doc: select_max_mem_alloc_size() {{{
   * \brief Select or deselect \ref device_info::max_mem_alloc_size "max_mem_alloc_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_mem_alloc_size(bool flag = true) noexcept
  {
    this->_max_mem_alloc_size = flag;
    return *this;
  }
  /** // doc: select_image2d_max_width() {{{
   * \brief Select or deselect #device_info::image2d_max_width "image2d_max_width"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image2d_max_width(bool flag = true) noexcept
  {
    this->_image2d_max_width = flag;
    return *this;
  }
  /** // doc: select_image2d_max_height() {{{
   * \brief Select or deselect \ref device_info::image2d_max_height "image2d_max_height"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image2d_max_height(bool flag = true) noexcept
  {
    this->_image2d_max_height = flag;
    return *this;
  }
  /** // doc: select_image3d_max_width() {{{
   * \brief Select or deselect \ref device_info::image3d_max_width "image3d_max_width"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image3d_max_width(bool flag = true) noexcept
  {
    this->_image3d_max_width = flag;
    return *this;
  }
  /** // doc: select_image3d_max_height() {{{
   * \brief Select or deselect \ref device_info::image3d_max_height "image3d_max_height"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image3d_max_height(bool flag = true) noexcept
  {
    this->_image3d_max_height = flag;
    return *this;
  }
  /** // doc: select_image3d_max_depth() {{{
   * \brief Select or deselect \ref device_info::image3d_max_depth "image3d_max_depth"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image3d_max_depth(bool flag = true) noexcept
  {
    this->_image3d_max_depth = flag;
    return *this;
  }
  /** // doc: select_image_support() {{{
   * \brief Select or deselect \ref device_info::image_support "image_support"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image_support(bool flag = true) noexcept
  {
    this->_image_support = flag;
    return *this;
  }
  /** // doc: select_max_parameter_size() {{{
   * \brief Select or deselect \ref device_info::max_parameter_size "max_parameter_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_parameter_size(bool flag = true) noexcept
  {
    this->_max_parameter_size = flag;
    return *this;
  }
  /** // doc: select_max_samplers() {{{
   * \brief Select or deselect \ref device_info::max_samplers "max_samplers"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_samplers(bool flag = true) noexcept
  {
    this->_max_samplers = flag;
    return *this;
  }
  /** // doc: select_mem_base_addr_align() {{{
   * \brief Select or deselect \ref device_info::mem_base_addr_align "mem_base_addr_align"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_mem_base_addr_align(bool flag = true) noexcept
  {
    this->_mem_base_addr_align = flag;
    return *this;
  }
  /** // doc: select_min_data_type_align_size() {{{
   * \brief Select or deselect \ref device_info::min_data_type_align_size "min_data_type_align_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_min_data_type_align_size(bool flag = true) noexcept
  {
    this->_min_data_type_align_size = flag;
    return *this;
  }
  /** // doc: select_single_fp_config() {{{
   * \brief Select or deselect \ref device_info::single_fp_config "single_fp_config"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_single_fp_config(bool flag = true) noexcept
  {
    this->_single_fp_config = flag;
    return *this;
  }
  /** // doc: select_global_mem_cache_type() {{{
   * \brief Select or deselect \ref device_info::global_mem_cache_type "global_mem_cache_type"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_global_mem_cache_type(bool flag = true) noexcept
  {
    this->_global_mem_cache_type = flag;
    return *this;
  }
  /** // doc: select_global_mem_cacheline_size() {{{
   * \brief Select or deselect \ref device_info::global_mem_cacheline_size "global_mem_cacheline_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_global_mem_cacheline_size(bool flag = true) noexcept
  {
    this->_global_mem_cacheline_size = flag;
    return *this;
  }
  /** // doc: select_global_mem_cache_size() {{{
   * \brief Select or deselect \ref device_info::global_mem_cache_size "global_mem_cache_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_global_mem_cache_size(bool flag = true) noexcept
  {
    this->_global_mem_cache_size = flag;
    return *this;
  }
  /** // doc: select_global_mem_size() {{{
   * \brief Select or deselect \ref device_info::global_mem_size "global_mem_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_global_mem_size(bool flag = true) noexcept
  {
    this->_global_mem_size = flag;
    return *this;
  }
  /** // doc: select_max_constant_buffer_size() {{{
   * \brief Select or deselect \ref device_info::max_constant_buffer_size "max_constant_buffer_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_constant_buffer_size(bool flag = true) noexcept
  {
    this->_max_constant_buffer_size = flag;
    return *this;
  }
  /** // doc: select_max_constant_args() {{{
   * \brief Select or deselect \ref device_info::max_constant_args "max_constant_args"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_max_constant_args(bool flag = true) noexcept
  {
    this->_max_constant_args = flag;
    return *this;
  }
  /** // doc: select_local_mem_type() {{{
   * \brief Select or deselect \ref device_info::local_mem_type "local_mem_type"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_local_mem_type(bool flag = true) noexcept
  {
    this->_local_mem_type = flag;
    return *this;
  }
  /** // doc: select_local_mem_size() {{{
   * \brief Select or deselect \ref device_info::local_mem_size "local_mem_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_local_mem_size(bool flag = true) noexcept
  {
    this->_local_mem_size = flag;
    return *this;
  }
  /** // doc: select_error_correction_support() {{{
   * \brief Select or deselect \ref device_info::error_correction_support "error_correction_support"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_error_correction_support(bool flag = true) noexcept
  {
    this->_error_correction_support = flag;
    return *this;
  }
  /** // doc: select_profiling_timer_resolution() {{{
   * \brief Select or deselect \ref device_info::profiling_timer_resolution "profiling_timer_resolution"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_profiling_timer_resolution(bool flag = true) noexcept
  {
    this->_profiling_timer_resolution = flag;
    return *this;
  }
  /** // doc: select_endian_little() {{{
   * \brief Select or deselect \ref device_info::endian_little "endian_little"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_endian_little(bool flag = true) noexcept
  {
    this->_endian_little = flag;
    return *this;
  }
  /** // doc: select_available() {{{
   * \brief Select or deselect \ref device_info::available "available"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_available(bool flag = true) noexcept
  {
    this->_available = flag;
    return *this;
  }
  /** // doc: select_compiler_available() {{{
   * \brief Select or deselect \ref device_info::compiler_available "compiler_available"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_compiler_available(bool flag = true) noexcept
  {
    this->_compiler_available = flag;
    return *this;
  }
  /** // doc: select_execution_capabilities() {{{
   * \brief Select or deselect \ref device_info::execution_capabilities "execution_capabilities"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_execution_capabilities(bool flag = true) noexcept
  {
    this->_execution_capabilities = flag;
    return *this;
  }
  /** // doc: select_queue_properties() {{{
   * \brief Select or deselect \ref device_info::queue_properties "queue_properties"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_queue_properties(bool flag = true) noexcept
  {
    this->_queue_properties = flag;
    return *this;
  }
  /** // doc: select_name() {{{
   * \brief Select or deselect \ref device_info::name "name"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_name(bool flag = true) noexcept
  {
    this->_name = flag;
    return *this;
  }
  /** // doc: select_vendor() {{{
   * \brief Select or deselect \ref device_info::vendor "vendor"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_vendor(bool flag = true) noexcept
  {
    this->_vendor = flag;
    return *this;
  }
  /** // doc: select_driver_version() {{{
   * \brief Select or deselect \ref device_info::driver_version "driver_version"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_driver_version(bool flag = true) noexcept
  {
    this->_driver_version = flag;
    return *this;
  }
  /** // doc: select_profile() {{{
   * \brief Select or deselect \ref device_info::profile "profile"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_profile(bool flag = true) noexcept
  {
    this->_profile = flag;
    return *this;
  }
  /** // doc: select_version() {{{
   * \brief Select or deselect \ref device_info::version "version"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_version(bool flag = true) noexcept
  {
    this->_version = flag;
    return *this;
  }
  /** // doc: select_extensions() {{{
   * \brief Select or deselect \ref device_info::extensions "extensions"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_extensions(bool flag = true) noexcept
  {
    this->_extensions = flag;
    return *this;
  }
  /** // doc: select_platform_id() {{{
   * \brief Select or deselect \ref device_info::platform_id "platform_id"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_platform_id(bool flag = true) noexcept
  {
    this->_platform_id = flag;
    return *this;
  }
  /** // doc: select_double_fp_config() {{{
   * \brief Select or deselect \ref device_info::double_fp_config "double_fp_config"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_double_fp_config(bool flag = true) noexcept
  {
    this->_double_fp_config = flag;
    return *this;
  }
  /** // doc: select_preferred_vector_width_half() {{{
   * \brief Select or deselect \ref device_info::preferred_vector_width_half "preferred_vector_width_half"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_vector_width_half(bool flag = true) noexcept
  {
    this->_preferred_vector_width_half = flag;
    return *this;
  }
  /** // doc: select_host_unified_memory() {{{
   * \brief Select or deselect \ref device_info::host_unified_memory "host_unified_memory"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_host_unified_memory(bool flag = true) noexcept
  {
    this->_host_unified_memory = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_char() {{{
   * \brief Select or deselect \ref device_info::native_vector_width_char "native_vector_width_char"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_native_vector_width_char(bool flag = true) noexcept
  {
    this->_native_vector_width_char = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_short() {{{
   * \brief Select or deselect \ref device_info::native_vector_width_short "native_vector_width_short"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_native_vector_width_short(bool flag = true) noexcept
  {
    this->_native_vector_width_short = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_int() {{{
   * \brief Select or deselect \ref device_info::native_vector_width_int "native_vector_width_int"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_native_vector_width_int(bool flag = true) noexcept
  {
    this->_native_vector_width_int = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_long() {{{
   * \brief Select or deselect \ref device_info::native_vector_width_long "native_vector_width_long"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_native_vector_width_long(bool flag = true) noexcept
  {
    this->_native_vector_width_long = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_float() {{{
   * \brief Select or deselect \ref device_info::native_vector_width_float "native_vector_width_float"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_native_vector_width_float(bool flag = true) noexcept
  {
    this->_native_vector_width_float = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_double() {{{
   * \brief Select or deselect \ref device_info::native_vector_width_double "native_vector_width_double"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_native_vector_width_double(bool flag = true) noexcept
  {
    this->_native_vector_width_double = flag;
    return *this;
  }
  /** // doc: select_native_vector_width_half() {{{
   * \brief Select or deselect \ref device_info::native_vector_width_half "native_vector_width_half"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_native_vector_width_half(bool flag = true) noexcept
  {
    this->_native_vector_width_half = flag;
    return *this;
  }
  /** // doc: select_opencl_c_version() {{{
   * \brief Select or deselect \ref device_info::opencl_c_version "opencl_c_version"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_opencl_c_version(bool flag = true) noexcept
  {
    this->_opencl_c_version = flag;
    return *this;
  }
  /** // doc: select_linker_available() {{{
   * \brief Select or deselect \ref device_info::linker_available "linker_available"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_linker_available(bool flag = true) noexcept
  {
    this->_linker_available = flag;
    return *this;
  }
  /** // doc: select_built_in_kernels() {{{
   * \brief Select or deselect \ref device_info::built_in_kernels "built_in_kernels"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_built_in_kernels(bool flag = true) noexcept
  {
    this->_built_in_kernels = flag;
    return *this;
  }
  /** // doc: select_image_max_buffer_size() {{{
   * \brief Select or deselect \ref device_info::image_max_buffer_size "image_max_buffer_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image_max_buffer_size(bool flag = true) noexcept
  {
    this->_image_max_buffer_size = flag;
    return *this;
  }
  /** // doc: select_image_max_array_size() {{{
   * \brief Select or deselect \ref device_info::image_max_array_size "image_max_array_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image_max_array_size(bool flag = true) noexcept
  {
    this->_image_max_array_size = flag;
    return *this;
  }
  /** // doc: select_parent_device_id() {{{
   * \brief Select or deselect \ref device_info::parent_device_id "parent_device_id"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_parent_device_id(bool flag = true) noexcept
  {
    this->_parent_device_id = flag;
    return *this;
  }
  /** // doc: select_partition_max_sub_devices() {{{
   * \brief Select or deselect \ref device_info::partition_max_sub_devices "partition_max_sub_devices"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_partition_max_sub_devices(bool flag = true) noexcept
  {
    this->_partition_max_sub_devices = flag;
    return *this;
  }
  /** // doc: select_partition_properties() {{{
   * \brief Select or deselect \ref device_info::partition_properties "partition_properties"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_partition_properties(bool flag = true) noexcept
  {
    this->_partition_properties = flag;
    return *this;
  }
  /** // doc: select_partition_affinity_domain() {{{
   * \brief Select or deselect \ref device_info::partition_affinity_domain "partition_affinity_domain"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_partition_affinity_domain(bool flag = true) noexcept
  {
    this->_partition_affinity_domain = flag;
    return *this;
  }
  /** // doc: select_partition_type() {{{
   * \brief Select or deselect \ref device_info::partition_type "partition_type"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_partition_type(bool flag = true) noexcept
  {
    this->_partition_type = flag;
    return *this;
  }
  /** // doc: select_reference_count() {{{
   * \brief Select or deselect \ref device_info::reference_count "reference_count"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_reference_count(bool flag = true) noexcept
  {
    this->_reference_count = flag;
    return *this;
  }
  /** // doc: select_preferred_interop_user_sync() {{{
   * \brief Select or deselect \ref device_info::preferred_interop_user_sync "preferred_interop_user_sync"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_preferred_interop_user_sync(bool flag = true) noexcept
  {
    this->_preferred_interop_user_sync = flag;
    return *this;
  }
  /** // doc: select_printf_buffer_size() {{{
   * \brief Select or deselect \ref device_info::printf_buffer_size "printf_buffer_size"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_printf_buffer_size(bool flag = true) noexcept
  {
    this->_printf_buffer_size = flag;
    return *this;
  }
  /** // doc: select_image_pitch_alignment() {{{
   * \brief Select or deselect \ref device_info::image_pitch_alignment "image_pitch_alignment"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image_pitch_alignment(bool flag = true) noexcept
  {
    this->_image_pitch_alignment = flag;
    return *this;
  }
  /** // doc: select_image_base_address_alignment() {{{
   * \brief Select or deselect \ref device_info::image_base_address_alignment "image_base_address_alignment"
   * \param flag If \c true the attribute gets selected, if \c false it gets deselected
   * \returns A mutable reference to the modified #device_query object
   */ //  }}}
  inline device_query& select_image_base_address_alignment(bool flag = true) noexcept
  {
    this->_image_base_address_alignment = flag;
    return *this;
  }
  // }}}
private:
  void _select(bool flag) noexcept;
  void _init(bool flag) noexcept;
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
/** \addtogroup clxx_info
 * @{ */
/** // doc: operator==(device_query, device_query) {{{
 * \brief Compare two \ref clxx::device_query "device_query" objects
 * Two \ref clxx::device_query "device_query" objects are equall iff all their selections are same
 * \returns \c true if \em a and \b are equal, or \c false otherwise
 */ // }}}
bool operator==(device_query const& a, device_query const& b) noexcept;
/** // doc: operator!=(device_query, device_query) {{{
 * \brief Compare two \ref clxx::device_query "device_qery" objects
 * Two \ref clxx::device_query "device_query" objects are equall iff all their selections are same
 * \returns \c true if \em a and \b are equal, or \c false otherwise
 */ // }}}
inline bool operator!=(device_query const& a, device_query const& b) noexcept
{ return !(a == b);}
/** @} */

} // end namespace clxx
#endif /* CLXX_DEVICE_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
