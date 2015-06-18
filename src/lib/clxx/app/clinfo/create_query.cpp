// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/create_query.cpp

/** // doc: clxx/app/clinfo/create_query.cpp {{{
 * \file clxx/app/clinfo/create_query.cpp
 * \brief Implements functions that prepare platform/device queries for clinfo application
 */ // }}}
#include <clxx/app/clinfo/create_query.hpp>

namespace clxx { namespace app { namespace clinfo {

static void
_select_device_info(clxx::device_query& query, bool flag)
{
  if(!flag)
    {
      query.select_none();
      query.select_id();
    }
}

static void
_select_vector_width_info(clxx::device_query& query, bool flag)
{
  query.select_preferred_vector_width_char(flag);
  query.select_preferred_vector_width_short(flag);
  query.select_preferred_vector_width_int(flag);
  query.select_preferred_vector_width_long(flag);
  query.select_preferred_vector_width_float(flag);
  query.select_preferred_vector_width_double(flag);
  query.select_preferred_vector_width_half(flag);
  query.select_native_vector_width_char(flag);
  query.select_native_vector_width_short(flag);
  query.select_native_vector_width_int(flag);
  query.select_native_vector_width_long(flag);
  query.select_native_vector_width_float(flag);
  query.select_native_vector_width_double(flag);
  query.select_native_vector_width_half(flag);
}
static void
_select_compute_unit_info(clxx::device_query& query, bool flag)
{
  query.select_max_compute_units(flag);
  query.select_max_work_item_dimensions(flag);
  query.select_max_work_item_sizes(flag);
  query.select_max_work_group_size(flag);

  _select_vector_width_info(query, flag);

  query.select_max_clock_frequency(flag);
  query.select_address_bits(flag);
}

static void
_select_image_support_info(clxx::device_query& query, bool flag)
{
  query.select_image_support(flag);
  query.select_max_read_image_args(flag);
  query.select_max_write_image_args(flag);
  query.select_image2d_max_width(flag);
  query.select_image2d_max_height(flag);
  query.select_image3d_max_width(flag);
  query.select_image3d_max_height(flag);
  query.select_image3d_max_depth(flag);
  query.select_image_max_buffer_size(flag);
  query.select_image_max_array_size(flag);
  query.select_image_pitch_alignment(flag);
  query.select_image_base_address_alignment(flag);
  query.select_max_samplers(flag);
}

static void
_select_global_mem_info(clxx::device_query& query, bool flag)
{
  query.select_global_mem_cache_type(flag);
  query.select_global_mem_cacheline_size(flag);
  query.select_global_mem_cache_size(flag);
  query.select_global_mem_size(flag);
}

static void
_select_device_generic_info(clxx::device_query& query, bool flag)
{
  query.select_name(flag);
  query.select_vendor(flag);
  query.select_driver_version(flag);
  query.select_profile(flag);
  query.select_version(flag);
  query.select_opencl_c_version(flag);
  query.select_extensions(flag);
  query.select_preferred_interop_user_sync(flag);
  query.select_printf_buffer_size(flag);
  query.select_parent_device_id(flag);
  query.select_partition_max_sub_devices(flag);
  query.select_partition_properties(flag);
  query.select_partition_affinity_domain(flag);
  query.select_partition_type(flag);
  query.select_reference_count(flag);
}

clxx::platform_query
create_platform_query( clxx::app::options::options_map const& optmap )
{
  clxx::platform_query query;
  if(optmap.count("short") && optmap["short"].as<bool>())
    {
      query.select_none();
      query.select_id();
      query.select_name();
      query.select_vendor();
    }
  else
    {
      if(optmap.count("platform-profile"))
        query.select_profile(optmap["platform-profile"].as<bool>());
      if(optmap.count("platform-version"))
        query.select_version(optmap["platform-version"].as<bool>());
      if(optmap.count("platform-name"))
        query.select_name(optmap["platform-name"].as<bool>());
      if(optmap.count("platform-vendor"))
        query.select_vendor(optmap["platform-vendor"].as<bool>());
      if(optmap.count("platform-extensions"))
        query.select_extensions(optmap["platform-extensions"].as<bool>());
    }
  return query;
}

clxx::device_query
create_device_query( clxx::app::options::options_map const& om )
{
  clxx::device_query query;

  if(om.count("short") && om["short"].as<bool>())
    {
      query.select_none();
      query.select_id();
      query.select_name();
      query.select_vendor();
    }
  else
    {
      if(om.count("device-id"))
        query.select_id(om["device-id"].as<bool>());
      if(om.count("device-type"))
        query.select_type(om["device-type"].as<bool>());
      if(om.count("vendor-id"))
        query.select_vendor_id(om["vendor-id"].as<bool>());
      if(om.count("max-compute-units"))
        query.select_max_compute_units(om["max-compute-units"].as<bool>());
      if(om.count("max-work-item-dimensions"))
        query.select_max_work_item_dimensions(om["max-work-item-dimensions"].as<bool>());
      if(om.count("max-work-item-sizes"))
        query.select_max_work_item_sizes(om["max-work-item-sizes"].as<bool>());
      if(om.count("max-work-group-size"))
        query.select_max_work_group_size(om["max-work-group-size"].as<bool>());
      if(om.count("preferred-vector-width-char"))
        query.select_preferred_vector_width_char(om["preferred-vector-width-char"].as<bool>());
      if(om.count("preferred-vector-width-short"))
        query.select_preferred_vector_width_short(om["preferred-vector-width-short"].as<bool>());
      if(om.count("preferred-vector-width-int"))
        query.select_preferred_vector_width_int(om["preferred-vector-width-int"].as<bool>());
      if(om.count("preferred-vector-width-long"))
        query.select_preferred_vector_width_long(om["preferred-vector-width-long"].as<bool>());
      if(om.count("preferred-vector-width-float"))
        query.select_preferred_vector_width_float(om["preferred-vector-width-float"].as<bool>());
      if(om.count("preferred-vector-width-double"))
        query.select_preferred_vector_width_double(om["preferred-vector-width-double"].as<bool>());
      if(om.count("preferred-vector-width-half"))
        query.select_preferred_vector_width_half(om["preferred-vector-width-half"].as<bool>());
      if(om.count("native-vector-width-char"))
        query.select_native_vector_width_char(om["native-vector-width-char"].as<bool>());
      if(om.count("native-vector-width-short"))
        query.select_native_vector_width_short(om["native-vector-width-short"].as<bool>());
      if(om.count("native-vector-width-int"))
        query.select_native_vector_width_int(om["native-vector-width-int"].as<bool>());
      if(om.count("native-vector-width-long"))
        query.select_native_vector_width_long(om["native-vector-width-long"].as<bool>());
      if(om.count("native-vector-width-float"))
        query.select_native_vector_width_float(om["native-vector-width-float"].as<bool>());
      if(om.count("native-vector-width-double"))
        query.select_native_vector_width_double(om["native-vector-width-double"].as<bool>());
      if(om.count("native-vector-width-half"))
        query.select_native_vector_width_half(om["native-vector-width-half"].as<bool>());
      if(om.count("max-clock-frequency"))
        query.select_max_clock_frequency(om["max-clock-frequency"].as<bool>());
      if(om.count("address-bits"))
        query.select_address_bits(om["address-bits"].as<bool>());
      if(om.count("max-mem-alloc-size"))
        query.select_max_mem_alloc_size(om["max-mem-alloc-size"].as<bool>());
      if(om.count("image-support"))
        query.select_image_support(om["image-support"].as<bool>());
      if(om.count("max-read-image-args"))
        query.select_max_read_image_args(om["max-read-image-args"].as<bool>());
      if(om.count("max-write-image-args"))
        query.select_max_write_image_args(om["max-write-image-args"].as<bool>());
      if(om.count("image2d-max-width"))
        query.select_image2d_max_width(om["image2d-max-width"].as<bool>());
      if(om.count("image2d-max-height"))
        query.select_image2d_max_height(om["image2d-max-height"].as<bool>());
      if(om.count("image3d-max-width"))
        query.select_image3d_max_width(om["image3d-max-width"].as<bool>());
      if(om.count("image3d-max-height"))
        query.select_image3d_max_height(om["image3d-max-height"].as<bool>());
      if(om.count("image3d-max-depth"))
        query.select_image3d_max_depth(om["image3d-max-depth"].as<bool>());
      if(om.count("image-max-buffer-size"))
        query.select_image_max_buffer_size(om["image-max-buffer-size"].as<bool>());
      if(om.count("image-max-array-size"))
        query.select_image_max_array_size(om["image-max-array-size"].as<bool>());
      if(om.count("image-pitch-alignment"))
        query.select_image_pitch_alignment(om["image-pitch-alignment"].as<bool>());
      if(om.count("image-base-address-alignment"))
        query.select_image_base_address_alignment(om["image-base-address-alignment"].as<bool>());
      if(om.count("max-samplers"))
        query.select_max_samplers(om["max-samplers"].as<bool>());
      if(om.count("max-parameter-size"))
        query.select_max_parameter_size(om["max-parameter-size"].as<bool>());
      if(om.count("mem-base-addr-align"))
        query.select_mem_base_addr_align(om["mem-base-addr-align"].as<bool>());
      if(om.count("min-data-type-align-size"))
        query.select_min_data_type_align_size(om["min-data-type-align-size"].as<bool>());
      if(om.count("single-fp-config"))
        query.select_single_fp_config(om["single-fp-config"].as<bool>());
      if(om.count("double-fp-config"))
        query.select_double_fp_config(om["double-fp-config"].as<bool>());
      if(om.count("global-mem-cache-type"))
        query.select_global_mem_cache_type(om["global-mem-cache-type"].as<bool>());
      if(om.count("global-mem-cacheline-size"))
        query.select_global_mem_cacheline_size(om["global-mem-cacheline-size"].as<bool>());
      if(om.count("global-mem-cache-size"))
        query.select_global_mem_cache_size(om["global-mem-cache-size"].as<bool>());
      if(om.count("global-mem-size"))
        query.select_global_mem_size(om["global-mem-size"].as<bool>());
      if(om.count("max-constant-args"))
        query.select_max_constant_args(om["max-constant-args"].as<bool>());
      if(om.count("local-mem-type"))
        query.select_local_mem_type(om["local-mem-type"].as<bool>());
      if(om.count("local-mem-size"))
        query.select_local_mem_size(om["local-mem-size"].as<bool>());
      if(om.count("error-correction-support"))
        query.select_error_correction_support(om["error-correction-support"].as<bool>());
      if(om.count("host-unified-memory"))
        query.select_host_unified_memory(om["host-unified-memory"].as<bool>());
      if(om.count("profiling-timer-resolution"))
        query.select_profiling_timer_resolution(om["profiling-timer-resolution"].as<bool>());
      if(om.count("endian-little"))
        query.select_endian_little(om["endian-little"].as<bool>());
      if(om.count("available"))
        query.select_available(om["available"].as<bool>());
      if(om.count("compiler-available"))
        query.select_compiler_available(om["compiler-available"].as<bool>());
      if(om.count("linker-available"))
        query.select_linker_available(om["linker-available"].as<bool>());
      if(om.count("execution-capabilities"))
        query.select_execution_capabilities(om["execution-capabilities"].as<bool>());
      if(om.count("queue-properties"))
        query.select_queue_properties(om["queue-properties"].as<bool>());
      if(om.count("built-in-kernels"))
        query.select_built_in_kernels(om["built-in-kernels"].as<bool>());
      if(om.count("platform-id"))
        query.select_platform_id(om["platform-id"].as<bool>());
      if(om.count("name"))
        query.select_name(om["name"].as<bool>());
      if(om.count("vendor"))
        query.select_vendor(om["vendor"].as<bool>());
      if(om.count("driver-version"))
        query.select_driver_version(om["driver-version"].as<bool>());
      if(om.count("profile"))
        query.select_profile(om["profile"].as<bool>());
      if(om.count("device-version"))
        query.select_version(om["device-version"].as<bool>());
      if(om.count("opencl-c-version"))
        query.select_opencl_c_version(om["opencl-c-version"].as<bool>());
      if(om.count("extensions"))
        query.select_extensions(om["extensions"].as<bool>());
      if(om.count("preferred-interop-user-sync"))
        query.select_preferred_interop_user_sync(om["preferred-interop-user-sync"].as<bool>());
      if(om.count("printf-buffer-size"))
        query.select_printf_buffer_size(om["printf-buffer-size"].as<bool>());
      if(om.count("parent-device"))
        query.select_parent_device_id(om["parent-device"].as<bool>());
      if(om.count("partition-max-sub-devices"))
        query.select_partition_max_sub_devices(om["partition-max-sub-devices"].as<bool>());
      if(om.count("partition-properties"))
        query.select_partition_properties(om["partition-properties"].as<bool>());
      if(om.count("partition-affinity-domain"))
        query.select_partition_affinity_domain(om["partition-affinity-domain"].as<bool>());
      if(om.count("partition-type"))
        query.select_partition_type(om["partition-type"].as<bool>());
      if(om.count("reference-count"))
        query.select_reference_count(om["reference-count"].as<bool>());
    }

  if(om.count("device-info"))
    _select_device_info(query, om["device-info"].as<bool>());
  if(om.count("compute-unit-info"))
    _select_compute_unit_info(query, om["compute-unit-info"].as<bool>());
  if(om.count("vector-width-info"))
    _select_vector_width_info(query, om["vector-width-info"].as<bool>());
  if(om.count("image-support-info"))
    _select_image_support_info(query, om["image-support-info"].as<bool>());
  if(om.count("global-mem-info"))
    _select_global_mem_info(query, om["global-mem-info"].as<bool>());
  if(om.count("device-generic-info"))
    _select_device_generic_info(query, om["device-generic-info"].as<bool>());
  return query;
}

} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
