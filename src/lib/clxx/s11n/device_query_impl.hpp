// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/device_query.hpp

/** // doc: clxx/s11n/device_query.hpp {{{
 * \file clxx/s11n/device_query.hpp
 * \brief Implements serialization of \ref clxx::device_query "device_query"
 */ // }}}
#ifndef CLXX_S11N_DEVICE_QUERY_IMPL_HPP_INCLUDED
#define CLXX_S11N_DEVICE_QUERY_IMPL_HPP_INCLUDED

#include <clxx/s11n/device_query.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/optional.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>

namespace clxx {

/** // doc: _serialize(Archive, device_query&, const unsigned int) {{{
 * \brief Implements serialization of \ref clxx::device_query "device_query"
 *
 * \param ar  Archive used for serialization.
 * \param obj Object to be serialized.
 * \param ver Class version
 */ // }}}
template<class Archive>
void _serialize(Archive& ar, device_query& obj, const unsigned int ver)
{
  (void)ver;
  using boost::serialization::make_nvp;
  ar  & make_nvp("id", obj._id)
      & make_nvp("type", obj._type)
      & make_nvp("vendor_id", obj._vendor_id)
      & make_nvp("max_compute_units", obj._max_compute_units)
      & make_nvp("max_work_item_dimensions", obj._max_work_item_dimensions)
      & make_nvp("max_work_group_size", obj._max_work_group_size)
      & make_nvp("max_work_item_sizes", obj._max_work_item_sizes)
      & make_nvp("preferred_vector_width_char", obj._preferred_vector_width_char)
      & make_nvp("preferred_vector_width_short", obj._preferred_vector_width_short)
      & make_nvp("preferred_vector_width_int", obj._preferred_vector_width_int)
      & make_nvp("preferred_vector_width_long", obj._preferred_vector_width_long)
      & make_nvp("preferred_vector_width_float", obj._preferred_vector_width_float)
      & make_nvp("preferred_vector_width_double", obj._preferred_vector_width_double)
      & make_nvp("max_clock_frequency", obj._max_clock_frequency)
      & make_nvp("address_bits", obj._address_bits)
      & make_nvp("max_read_image_args", obj._max_read_image_args)
      & make_nvp("max_write_image_args", obj._max_write_image_args)
      & make_nvp("max_mem_alloc_size", obj._max_mem_alloc_size)
      & make_nvp("image2d_max_width", obj._image2d_max_width)
      & make_nvp("image2d_max_height", obj._image2d_max_height)
      & make_nvp("image3d_max_width", obj._image3d_max_width)
      & make_nvp("image3d_max_height", obj._image3d_max_height)
      & make_nvp("image3d_max_depth", obj._image3d_max_depth)
      & make_nvp("image_support", obj._image_support)
      & make_nvp("max_parameter_size", obj._max_parameter_size)
      & make_nvp("max_samplers", obj._max_samplers)
      & make_nvp("mem_base_addr_align", obj._mem_base_addr_align)
      & make_nvp("min_data_type_align_size", obj._min_data_type_align_size)
      & make_nvp("single_fp_config", obj._single_fp_config)
      & make_nvp("global_mem_cache_type", obj._global_mem_cache_type)
      & make_nvp("global_mem_cacheline_size", obj._global_mem_cacheline_size)
      & make_nvp("global_mem_cache_size", obj._global_mem_cache_size)
      & make_nvp("global_mem_size", obj._global_mem_size)
      & make_nvp("max_constant_buffer_size", obj._max_constant_buffer_size)
      & make_nvp("max_constant_args", obj._max_constant_args)
      & make_nvp("local_mem_type", obj._local_mem_type)
      & make_nvp("local_mem_size", obj._local_mem_size)
      & make_nvp("error_correction_support", obj._error_correction_support)
      & make_nvp("profiling_timer_resolution", obj._profiling_timer_resolution)
      & make_nvp("endian_little", obj._endian_little)
      & make_nvp("available", obj._available)
      & make_nvp("compiler_available", obj._compiler_available)
      & make_nvp("execution_capabilities", obj._execution_capabilities)
      & make_nvp("queue_properties", obj._queue_properties)
      & make_nvp("name", obj._name)
      & make_nvp("vendor", obj._vendor)
      & make_nvp("driver_version", obj._driver_version)
      & make_nvp("profile", obj._profile)
      & make_nvp("version", obj._version)
      & make_nvp("extensions", obj._extensions)
      & make_nvp("platform_id", obj._platform_id)
      & make_nvp("double_fp_config", obj._double_fp_config)
      & make_nvp("preferred_vector_width_half", obj._preferred_vector_width_half)
      & make_nvp("host_unified_memory", obj._host_unified_memory)
      & make_nvp("native_vector_width_char", obj._native_vector_width_char)
      & make_nvp("native_vector_width_short", obj._native_vector_width_short)
      & make_nvp("native_vector_width_int", obj._native_vector_width_int)
      & make_nvp("native_vector_width_long", obj._native_vector_width_long)
      & make_nvp("native_vector_width_float", obj._native_vector_width_float)
      & make_nvp("native_vector_width_double", obj._native_vector_width_double)
      & make_nvp("native_vector_width_half", obj._native_vector_width_half)
      & make_nvp("opencl_c_version", obj._opencl_c_version)
      & make_nvp("linker_available", obj._linker_available)
      & make_nvp("built_in_kernels", obj._built_in_kernels)
      & make_nvp("image_max_buffer_size", obj._image_max_buffer_size)
      & make_nvp("image_max_array_size", obj._image_max_array_size)
      & make_nvp("parent_device_id", obj._parent_device_id)
      & make_nvp("partition_max_sub_devices", obj._partition_max_sub_devices)
      & make_nvp("partition_properties", obj._partition_properties)
      & make_nvp("partition_affinity_domain", obj._partition_affinity_domain)
      & make_nvp("partition_type", obj._partition_type)
      & make_nvp("reference_count", obj._reference_count)
      & make_nvp("preferred_interop_user_sync", obj._preferred_interop_user_sync)
      & make_nvp("printf_buffer_size", obj._printf_buffer_size)
      & make_nvp("image_pitch_alignment", obj._image_pitch_alignment)
      & make_nvp("image_base_address_alignment", obj._image_base_address_alignment);
}

} // end namespace clxx

namespace boost {
namespace serialization {

/* ------------------------------------------------------------------------ */
template <class Archive>
void serialize(Archive& ar, clxx::device_query& obj, const unsigned int ver)
{
  clxx::_serialize(ar, obj, ver);
}
/* ------------------------------------------------------------------------ */

} /* namespace boost */
} /* namespace serialization */

#endif /* CLXX_S11N_DEVICE_QUERY_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
