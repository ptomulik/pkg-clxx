// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/enum2cstr.t.h

/** // doc: clxx/enum2cstr.t.h {{{
 * \file clxx/enum2cstr.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_ENUM2STR_T_H_INCLUDED
#define CLXX_UTIL_ENUM2STR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/enum2cstr.hpp>

namespace clxx { class enum2cstr_test_suite; }

/** // doc: class clxx::enum2cstr_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enum2cstr_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_status_t() {{{
   * \brief Ensure that enum2cstr() works with status_t.
   */ // }}}
  void test_status_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(status_t::success),"success");
    TS_ASSERT_EQUALS(enum2cstr(status_t::device_not_found),"device not found");
    TS_ASSERT_EQUALS(enum2cstr(status_t::device_not_available),"device not available");
    TS_ASSERT_EQUALS(enum2cstr(status_t::compiler_not_available),"compiler not available");
    TS_ASSERT_EQUALS(enum2cstr(status_t::mem_object_allocation_failure),"memory object allocation failure");
    TS_ASSERT_EQUALS(enum2cstr(status_t::out_of_resources),"out of resources");
    TS_ASSERT_EQUALS(enum2cstr(status_t::out_of_host_memory),"out of host memory");
    TS_ASSERT_EQUALS(enum2cstr(status_t::profiling_info_not_available),"profiling info not available");
    TS_ASSERT_EQUALS(enum2cstr(status_t::mem_copy_overlap),"memory copy overlap");
    TS_ASSERT_EQUALS(enum2cstr(status_t::image_format_mismatch),"image format mismatch");
    TS_ASSERT_EQUALS(enum2cstr(status_t::image_format_not_supported),"image format not supported");
    TS_ASSERT_EQUALS(enum2cstr(status_t::build_program_failure),"build program failure");
    TS_ASSERT_EQUALS(enum2cstr(status_t::map_failure),"map failure");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(status_t::misaligned_sub_buffer_offset),"misaligned sub buffer offset");
    TS_ASSERT_EQUALS(enum2cstr(status_t::exec_status_error_for_events_in_wait_list),"execution status error for events in wait list");
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(status_t::compile_program_failure),"compile program failure");
    TS_ASSERT_EQUALS(enum2cstr(status_t::linker_not_available),"linker not available");
    TS_ASSERT_EQUALS(enum2cstr(status_t::link_program_failure),"link program failure");
    TS_ASSERT_EQUALS(enum2cstr(status_t::device_partition_failed),"device partition failed");
    TS_ASSERT_EQUALS(enum2cstr(status_t::kernel_arg_info_not_available),"kernel argument info not available");
#endif
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_value),"invalid value");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_device_type),"invalid device type");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_platform),"invalid platform");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_device),"invalid device");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_context),"invalid context");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_queue_properties),"invalid queue properties");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_command_queue),"invalid command queue");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_host_ptr),"invalid host ptr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_mem_object),"invalid memory object");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_image_format_descriptor),"invalid image format descriptor");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_image_size),"invalid image size");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_sampler),"invalid sampler");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_binary),"invalid binary");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_build_options),"invalid build options");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_program),"invalid program");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_program_executable),"invalid program executable");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_kernel_name),"invalid kernel name");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_kernel_definition),"invalid kernel definition");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_kernel),"invalid kernel");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_arg_index),"invalid argument index");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_arg_value),"invalid argument value");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_arg_size),"invalid argument size");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_kernel_args),"invalid kernel arguments");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_work_dimension),"invalid work dimension");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_work_group_size),"invalid work group size");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_work_item_size),"invalid work item size");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_global_offset),"invalid global offset");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_event_wait_list),"invalid event wait list");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_event),"invalid event");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_operation),"invalid operation");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_gl_object),"invalid GL object");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_buffer_size),"invalid buffer size");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_mip_level),"invalid mip level");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_global_work_size),"invalid global work size");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_property),"invalid property");
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_image_descriptor),"invalid image descriptor");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_compiler_options),"invalid compiler options");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_linker_options),"invalid linker options");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_device_partition_count),"invalid device partition count");
#endif
#if CLXX_CL_H_VERSION_2_0
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_pipe_size),"invalid pipe size");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_device_queue),"invalid device queue");
#endif
#if cl_khr_icd
    TS_ASSERT_EQUALS(enum2cstr(status_t::platform_not_found_khr),"platform not found khr");
#endif
#if cl_ext_device_fission
    TS_ASSERT_EQUALS(enum2cstr(status_t::device_partition_failed_ext),"device partition failed ext");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_partition_count_ext),"invalid partition count ext");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_partition_name_ext),"invalid partition name ext");
#endif
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_gl_sharegroup_reference_khr),"invalid gl sharegroup reference khr");
#endif
#if cl_khr_dx9_media_sharing
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_dx9_media_adapter_khr),"invalid dx9 media adapter khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_dx9_media_surface_khr),"invalid dx9 media surface khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::dx9_media_surface_already_acquired_khr),"dx9 media surface already acquired khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::dx9_media_surface_not_acquired_khr),"dx9 media surface not acquired khr");
#endif
#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_d3d10_device_khr),"invalid d3d10 device khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_d3d10_resource_khr),"invalid d3d10 resource khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::d3d10_resource_already_acquired_khr),"d3d10 resource already acquired khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::d3d10_resource_not_acquired_khr),"d3d10 resource not acquired khr");
#endif
#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_d3d11_device_khr),"invalid d3d11 device khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::invalid_d3d11_resource_khr),"invalid d3d11 resource khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::d3d11_resource_already_acquired_khr),"d3d11 resource already acquired khr");
    TS_ASSERT_EQUALS(enum2cstr(status_t::d3d11_resource_not_acquired_khr),"d3d11 resource not acquired khr");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<status_t>(0x7FFF)), nullptr);
    TS_ASSERT_EQUALS(enum2cstr(static_cast<status_t>(-0x7FFF)), nullptr);
  }
  /** // doc: test_platform_info_t() {{{
   * \brief Ensure that enum2cstr() works with platform_info_t.
   */ // }}}
  void test_platform_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(platform_info_t::profile), "profile");
    TS_ASSERT_EQUALS(enum2cstr(platform_info_t::version), "version");
    TS_ASSERT_EQUALS(enum2cstr(platform_info_t::name), "name");
    TS_ASSERT_EQUALS(enum2cstr(platform_info_t::vendor), "vendor");
    TS_ASSERT_EQUALS(enum2cstr(platform_info_t::extensions), "extensions");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<platform_info_t>(-1l)), nullptr);
  }
  /** // doc: test_device_type_t() {{{
   * \brief Ensure that enum2cstr() works with device_type_t.
   */ // }}}
  void test_device_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_type_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(device_type_t::default_), "default");
    TS_ASSERT_EQUALS(enum2cstr(device_type_t::cpu), "cpu");
    TS_ASSERT_EQUALS(enum2cstr(device_type_t::gpu), "gpu");
    TS_ASSERT_EQUALS(enum2cstr(device_type_t::accelerator), "accelerator");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(device_type_t::custom), "custom");
#endif
    TS_ASSERT_EQUALS(enum2cstr(device_type_t::all), "all");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_type_t>(-1l)), nullptr);
  }
  /** // doc: test_device_info_t() {{{
   * \brief Ensure that enum2cstr() works with device_info_t.
   */ // }}}
  void test_device_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::type), "type");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::vendor_id), "vendor id");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_compute_units), "max compute units");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_work_item_dimensions), "max work item dimensions");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_work_group_size), "max work group size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_work_item_sizes), "max work item sizes");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_vector_width_char), "preferred vector width char");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_vector_width_short), "preferred vector width short");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_vector_width_int), "preferred vector width int");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_vector_width_long), "preferred vector width long");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_vector_width_float), "preferred vector width float");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_vector_width_double), "preferred vector width double");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_clock_frequency), "max clock frequency");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::address_bits), "address bits");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_read_image_args), "max read image args");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_write_image_args), "max write image args");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_mem_alloc_size), "max mem alloc size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image2d_max_width), "image2d max width");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image2d_max_height), "image2d max height");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image3d_max_width), "image3d max width");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image3d_max_height), "image3d max height");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image3d_max_depth), "image3d max depth");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image_support), "image support");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_parameter_size), "max parameter size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_samplers), "max samplers");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::mem_base_addr_align), "mem base addr align");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::min_data_type_align_size), "min data type align size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::single_fp_config), "single fp config");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::global_mem_cache_type), "global mem cache type");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::global_mem_cacheline_size), "global mem cacheline size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::global_mem_cache_size), "global mem cache size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::global_mem_size), "global mem size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_constant_buffer_size), "max constant buffer size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::max_constant_args), "max constant args");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::local_mem_type), "local mem type");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::local_mem_size), "local mem size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::error_correction_support), "error correction support");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::profiling_timer_resolution), "profiling timer resolution");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::endian_little), "endian little");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::available), "available");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::compiler_available), "compiler available");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::execution_capabilities), "execution capabilities");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::queue_properties), "queue properties");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::name), "name");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::vendor), "vendor");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::driver_version), "driver version");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::profile), "profile");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::version), "version");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::extensions), "extensions");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::platform), "platform");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::double_fp_config), "double fp config");
#endif
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_vector_width_half), "preferred vector width half");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::host_unified_memory), "host unified memory");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::native_vector_width_char), "native vector width char");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::native_vector_width_short), "native vector width short");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::native_vector_width_int), "native vector width int");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::native_vector_width_long), "native vector width long");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::native_vector_width_float), "native vector width float");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::native_vector_width_double), "native vector width double");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::native_vector_width_half), "native vector width half");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::opencl_c_version), "opencl c version");
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::linker_available), "linker available");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::built_in_kernels), "built in kernels");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image_max_buffer_size), "image max buffer size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image_max_array_size), "image max array size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::parent_device), "parent device");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::partition_max_sub_devices), "partition max sub devices");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::partition_properties), "partition properties");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::partition_affinity_domain), "partition affinity domain");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::partition_type), "partition type");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::preferred_interop_user_sync), "preferred interop user sync");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::printf_buffer_size), "printf buffer size");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image_pitch_alignment), "image pitch alignment");
    TS_ASSERT_EQUALS(enum2cstr(device_info_t::image_base_address_alignment), "image base address alignment");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_info_t>(-1l)), nullptr);
  }
  /** // doc: test_device_fp_config_t() {{{
   * \brief Ensure that enum2cstr() works with device_fp_config_t.
   */ // }}}
  void test_device_fp_config_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::denorm), "denorm");
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::inf_nan), "inf nan");
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::round_to_nearest), "round to nearest");
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::round_to_zero), "round to zero");
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::round_to_inf), "round to inf");
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::fma), "fma");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::soft_float), "soft float");
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(device_fp_config_t::correctly_rounded_divide_sqrt), "correctly rounded divide sqrt");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_fp_config_t>(-1l)), nullptr);
  }
  /** // doc: test_device_mem_cache_type_t() {{{
   * \brief Ensure that enum2cstr() works with device_mem_cache_type_t.
   */ // }}}
  void test_device_mem_cache_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_mem_cache_type_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(device_mem_cache_type_t::read_only_cache), "read-only cache");
    TS_ASSERT_EQUALS(enum2cstr(device_mem_cache_type_t::read_write_cache), "read-write cache");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_mem_cache_type_t>(-1l)), nullptr);
  }
  /** // doc: test_device_local_mem_type_t() {{{
   * \brief Ensure that enum2cstr() works with device_local_mem_type_t.
   */ // }}}
  void test_device_local_mem_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_local_mem_type_t::local), "local");
    TS_ASSERT_EQUALS(enum2cstr(device_local_mem_type_t::global), "global");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_local_mem_type_t>(-1l)), nullptr);
  }
  /** // doc: test_device_exec_capabilities_t() {{{
   * \brief Ensure that enum2cstr() works with device_exec_capabilities_t.
   */ // }}}
  void test_device_exec_capabilities_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_exec_capabilities_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(device_exec_capabilities_t::kernel), "kernel");
    TS_ASSERT_EQUALS(enum2cstr(device_exec_capabilities_t::native_kernel), "native_kernel");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_exec_capabilities_t>(-1l)), nullptr);
  }
  /** // doc: test_command_queue_properties_t() {{{
   * \brief Ensure that enum2cstr() works with command_queue_properties_t.
   */ // }}}
  void test_command_queue_properties_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(command_queue_properties_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(command_queue_properties_t::out_of_order_exec_mode_enable), "out_of_order_exec_mode_enable");
    TS_ASSERT_EQUALS(enum2cstr(command_queue_properties_t::profiling_enable), "profiling_enable");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<command_queue_properties_t>(-1l)), nullptr);
  }
  /** // doc: test_context_info_t() {{{
   * \brief Ensure that enum2cstr() works with context_info_t.
   */ // }}}
  void test_context_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(context_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(context_info_t::devices), "devices");
    TS_ASSERT_EQUALS(enum2cstr(context_info_t::properties), "properties");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(context_info_t::num_devices), "num devices");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<context_info_t>(-1l)), nullptr);
  }
  /** // doc: test_context_properties_t() {{{
   * \brief Ensure that enum2cstr() works with context_properties_t.
   */ // }}}
  void test_context_properties_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::platform),"platform");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::interop_user_sync),"interop user sync");
#endif
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::gl_context_khr),"gl context khr");
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::egl_display_khr),"egl display khr");
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::glx_display_khr),"glx display khr");
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::wgl_hdc_khr),"wgl hdc khr");
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::cgl_sharegroup_khr),"cgl sharegroup khr");
#endif
#if cl_khr_dx9_media_sharing
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::adapter_d3d9_khr),"adapter d3d9 khr");
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::adapter_d3d9ex_khr),"adapter d3d9eh khr");
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::adapter_dxva_khr),"adapter dxva khr");
#endif
#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::d3d10_device_khr),"d3d10 device khr");
#endif
#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(enum2cstr(context_properties_t::d3d11_device_khr),"d3d11 device khr");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<context_properties_t>(-1l)), nullptr);
  }
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_device_partition_property_t() {{{
   * \brief Ensure that enum2cstr() works with device_partition_property_t.
   */ // }}}
  void test_device_partition_property_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_partition_property_t::equally), "equally");
    TS_ASSERT_EQUALS(enum2cstr(device_partition_property_t::by_counts), "by counts");
    TS_ASSERT_EQUALS(enum2cstr(device_partition_property_t::by_counts_list_end), "by counts list end");
    TS_ASSERT_EQUALS(enum2cstr(device_partition_property_t::by_affinity_domain), "by affinity domain");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_partition_property_t>(-1l)), nullptr);
  }
#endif
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_device_affinity_domain_t() {{{
   * \brief Ensure that enum2cstr() works with device_affinity_domain_t.
   */ // }}}
  void test_device_affinity_domain_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(device_affinity_domain_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(device_affinity_domain_t::numa), "numa");
    TS_ASSERT_EQUALS(enum2cstr(device_affinity_domain_t::l4_cache), "l4 cache");
    TS_ASSERT_EQUALS(enum2cstr(device_affinity_domain_t::l3_cache), "l3 cache");
    TS_ASSERT_EQUALS(enum2cstr(device_affinity_domain_t::l2_cache), "l2 cache");
    TS_ASSERT_EQUALS(enum2cstr(device_affinity_domain_t::l1_cache), "l1 cache");
    TS_ASSERT_EQUALS(enum2cstr(device_affinity_domain_t::next_partitionable), "next partitionable");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<device_affinity_domain_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_command_queue_info_t() {{{
   * \brief Ensure that enum2cstr() works with command_queue_info_t.
   */ // }}}
  void test_command_queue_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(command_queue_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2cstr(command_queue_info_t::device), "device");
    TS_ASSERT_EQUALS(enum2cstr(command_queue_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(command_queue_info_t::properties), "properties");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<command_queue_info_t>(-1l)), nullptr);
  }
  /** // doc: test_mem_flags_t() {{{
   * \brief Ensure that enum2cstr() works with mem_flags_t.
   */ // }}}
  void test_mem_flags_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::read_write), "read-write");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::write_only), "write-only");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::read_only), "read-only");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::use_host_ptr), "use host ptr");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::alloc_host_ptr), "alloc host ptr");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::copy_host_ptr), "copy host ptr");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::host_write_only), "host write only");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::host_read_only), "host read only");
    TS_ASSERT_EQUALS(enum2cstr(mem_flags_t::host_no_access), "host no access");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<mem_flags_t>(-1l)), nullptr);
  }
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_mem_migration_flags_t() {{{
   * \brief Ensure that enum2cstr() works with mem_migration_flags_t.
   */ // }}}
  void test_mem_migration_flags_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(mem_migration_flags_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(mem_migration_flags_t::mem_object_host), "mem_object_host");
    TS_ASSERT_EQUALS(enum2cstr(mem_migration_flags_t::mem_object_content_undefined), "mem_object_content_undefined");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<mem_migration_flags_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_channel_order_t() {{{
   * \brief Ensure that enum2cstr() works with channel_order_t.
   */ // }}}
  void test_channel_order_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::r), "R");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::a), "A");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::rg), "RG");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::ra), "RA");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::rgb), "RGB");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::rgba), "RGBA");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::bgra), "BGRA");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::argb), "ARGB");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::intensity), "intensity");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::luminance), "luminance");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::rx), "Rx");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::rgx), "RGx");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::rgbx), "RGBx");
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::depth), "depth");
    TS_ASSERT_EQUALS(enum2cstr(channel_order_t::depth_stencil), "depth stencil");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<channel_order_t>(-1l)), nullptr);
  }
  /** // doc: test_channel_type_t() {{{
   * \brief Ensure that enum2cstr() works with channel_type_t.
   */ // }}}
  void test_channel_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::snorm_int8), "snorm_int8");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::snorm_int16), "snorm_int16");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unorm_int8), "unorm_int8");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unorm_int16), "unorm_int16");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unorm_short_565), "unorm_short_565");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unorm_short_555), "unorm_short_555");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unorm_int_101010), "unorm_int_101010");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::signed_int8), "signed_int8");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::signed_int16), "signed_int16");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::signed_int32), "signed_int32");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unsigned_int8), "unsigned_int8");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unsigned_int16), "unsigned_int16");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unsigned_int32), "unsigned_int32");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::half_float), "half_float");
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::float_), "float");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(channel_type_t::unorm_int24), "unorm_int24");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<channel_type_t>(-1l)), nullptr);
  }
  /** // doc: test_mem_object_type_t() {{{
   * \brief Ensure that enum2cstr() works with mem_object_type_t.
   */ // }}}
  void test_mem_object_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(mem_object_type_t::buffer), "buffer");
    TS_ASSERT_EQUALS(enum2cstr(mem_object_type_t::image2d), "image2d");
    TS_ASSERT_EQUALS(enum2cstr(mem_object_type_t::image3d), "image3d");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(mem_object_type_t::image2d_array), "image2d array");
    TS_ASSERT_EQUALS(enum2cstr(mem_object_type_t::image1d), "image1d");
    TS_ASSERT_EQUALS(enum2cstr(mem_object_type_t::image1d_array), "image1d array");
    TS_ASSERT_EQUALS(enum2cstr(mem_object_type_t::image1d_buffer), "image1d buffer");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<mem_object_type_t>(-1l)), nullptr);
  }
  /** // doc: test_mem_info_t() {{{
   * \brief Ensure that enum2cstr() works with mem_info_t.
   */ // }}}
  void test_mem_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::type), "type");
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::flags), "flags");
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::size), "size");
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::host_ptr), "host ptr");
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::map_count), "map count");
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::context), "context");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::associated_memobject), "associated memobject");
    TS_ASSERT_EQUALS(enum2cstr(mem_info_t::offset), "offset");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<mem_info_t>(-1l)), nullptr);
  }
  /** // doc: test_image_info_t() {{{
   * \brief Ensure that enum2cstr() works with image_info_t.
   */ // }}}
  void test_image_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::format), "format");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::element_size), "element size");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::row_pitch), "row pitch");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::slice_pitch), "slice pitch");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::width), "width");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::height), "height");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::depth), "depth");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::array_size), "array size");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::buffer), "buffer");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::num_mip_levels), "num mip levels");
    TS_ASSERT_EQUALS(enum2cstr(image_info_t::num_samples), "num samples");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<image_info_t>(-1l)), nullptr);
  }
  /** // doc: test_addressing_mode_t() {{{
   * \brief Ensure that enum2cstr() works with addressing_mode_t.
   */ // }}}
  void test_addressing_mode_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(addressing_mode_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(addressing_mode_t::clamp_to_edge), "clamp to edge");
    TS_ASSERT_EQUALS(enum2cstr(addressing_mode_t::clamp), "clamp");
    TS_ASSERT_EQUALS(enum2cstr(addressing_mode_t::repeat), "repeat");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(addressing_mode_t::mirrored_repeat), "mirrored repeat");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<addressing_mode_t>(-1l)), nullptr);
  }
  /** // doc: test_filter_mode_t() {{{
   * \brief Ensure that enum2cstr() works with filter_mode_t.
   */ // }}}
  void test_filter_mode_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(filter_mode_t::nearest), "nearest");
    TS_ASSERT_EQUALS(enum2cstr(filter_mode_t::linear), "linear");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<filter_mode_t>(-1l)), nullptr);
  }
  /** // doc: test_sampler_info_t() {{{
   * \brief Ensure that enum2cstr() works with sampler_info_t.
   */ // }}}
  void test_sampler_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(sampler_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(sampler_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2cstr(sampler_info_t::normalized_coords), "normalized coords");
    TS_ASSERT_EQUALS(enum2cstr(sampler_info_t::addressing_mode), "addressing mode");
    TS_ASSERT_EQUALS(enum2cstr(sampler_info_t::filter_mode), "filter mode");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<sampler_info_t>(-1l)), nullptr);
  }
  /** // doc: test_map_flags_t() {{{
   * \brief Ensure that enum2cstr() works with map_flags_t.
   */ // }}}
  void test_map_flags_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(map_flags_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(map_flags_t::read), "read");
    TS_ASSERT_EQUALS(enum2cstr(map_flags_t::write), "write");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(map_flags_t::write_invalidate_region), "write invalidate region");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<map_flags_t>(-1l)), nullptr);
  }
  /** // doc: test_program_info_t() {{{
   * \brief Ensure that enum2cstr() works with program_info_t.
   */ // }}}
  void test_program_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::num_devices), "num devices");
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::devices), "devices");
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::source), "source");
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::binary_sizes), "binary sizes");
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::binaries), "binaries");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::num_kernels), "num kernels");
    TS_ASSERT_EQUALS(enum2cstr(program_info_t::kernel_names), "kernel names");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<program_info_t>(-1l)), nullptr);
  }
  /** // doc: test_program_build_info_t() {{{
   * \brief Ensure that enum2cstr() works with program_build_info_t.
   */ // }}}
  void test_program_build_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(program_build_info_t::status), "status");
    TS_ASSERT_EQUALS(enum2cstr(program_build_info_t::options), "options");
    TS_ASSERT_EQUALS(enum2cstr(program_build_info_t::log), "log");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(program_build_info_t::binary_type), "binary type");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<program_build_info_t>(-1l)), nullptr);
  }
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_program_binary_type_t() {{{
   * \brief Ensure that enum2cstr() works with program_binary_type_t.
   */ // }}}
  void test_program_binary_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(program_binary_type_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(program_binary_type_t::compiled_object), "compiled object");
    TS_ASSERT_EQUALS(enum2cstr(program_binary_type_t::library), "library");
    TS_ASSERT_EQUALS(enum2cstr(program_binary_type_t::executable), "executable");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<program_binary_type_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_build_status_t() {{{
   * \brief Ensure that enum2cstr() works with build_status_t.
   */ // }}}
  void test_build_status_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(build_status_t::success), "success");
    TS_ASSERT_EQUALS(enum2cstr(build_status_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(build_status_t::error), "error");
    TS_ASSERT_EQUALS(enum2cstr(build_status_t::in_progress), "in progress");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<build_status_t>(-12345l)), nullptr);
  }
  /** // doc: test_kernel_info_t() {{{
   * \brief Ensure that enum2cstr() works with kernel_info_t.
   */ // }}}
  void test_kernel_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(kernel_info_t::function_name), "function name");
    TS_ASSERT_EQUALS(enum2cstr(kernel_info_t::num_args), "num args");
    TS_ASSERT_EQUALS(enum2cstr(kernel_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(kernel_info_t::context), "context");
    TS_ASSERT_EQUALS(enum2cstr(kernel_info_t::program), "program");
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(kernel_info_t::attributes), "attributes");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<kernel_info_t>(-1l)), nullptr);
  }
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_kernel_arg_info_t() {{{
   * \brief Ensure that enum2cstr() works with kernel_arg_info_t.
   */ // }}}
  void test_kernel_arg_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_info_t::address_qualifier), "address qualifier");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_info_t::access_qualifier), "access qualifier");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_info_t::type_name), "type name");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_info_t::type_qualifier), "type qualifier");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_info_t::name), "name");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<kernel_arg_info_t>(-1l)), nullptr);
  }
#endif
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_kernel_arg_address_qualifier_t() {{{
   * \brief Ensure that enum2cstr() works with kernel_arg_address_qualifier_t.
   */ // }}}
  void test_kernel_arg_address_qualifier_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_address_qualifier_t::global), "global");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_address_qualifier_t::local), "local");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_address_qualifier_t::constant), "constant");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_address_qualifier_t::private_), "private");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<kernel_arg_address_qualifier_t>(-1l)), nullptr);
  }
#endif
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_kernel_arg_access_qualifier_t() {{{
   * \brief Ensure that enum2cstr() works with kernel_arg_access_qualifier_t.
   */ // }}}
  void test_kernel_arg_access_qualifier_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_access_qualifier_t::read_only), "read-only");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_access_qualifier_t::write_only), "write-only");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_access_qualifier_t::read_write), "read-write");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_access_qualifier_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<kernel_arg_access_qualifier_t>(-1l)), nullptr);
  }
#endif
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_kernel_arg_type_qualifier_t() {{{
   * \brief Ensure that enum2cstr() works with kernel_arg_type_qualifier_t.
   */ // }}}
  void test_kernel_arg_type_qualifier_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_type_qualifier_t::none), "none");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_type_qualifier_t::const_), "const");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_type_qualifier_t::restrict_), "restrict");
    TS_ASSERT_EQUALS(enum2cstr(kernel_arg_type_qualifier_t::volatile_), "volatile");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<kernel_arg_type_qualifier_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_kernel_work_group_info_t() {{{
   * \brief Ensure that enum2cstr() works with kernel_work_group_info_t.
   */ // }}}
  void test_kernel_work_group_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(kernel_work_group_info_t::work_group_size), "work group size");
    TS_ASSERT_EQUALS(enum2cstr(kernel_work_group_info_t::compile_work_group_size), "compile work group size");
    TS_ASSERT_EQUALS(enum2cstr(kernel_work_group_info_t::local_mem_size), "local mem size");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(kernel_work_group_info_t::preferred_work_group_size_multiple), "preferred work group size multiple");
    TS_ASSERT_EQUALS(enum2cstr(kernel_work_group_info_t::private_mem_size), "private mem size");
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(kernel_work_group_info_t::global_work_size), "global work size");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<kernel_work_group_info_t>(-1l)), nullptr);
  }
  /** // doc: test_event_info_t() {{{
   * \brief Ensure that enum2cstr() works with event_info_t.
   */ // }}}
  void test_event_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(event_info_t::command_queue), "command queue");
    TS_ASSERT_EQUALS(enum2cstr(event_info_t::command_type), "command type");
    TS_ASSERT_EQUALS(enum2cstr(event_info_t::reference_count), "reference count");
    TS_ASSERT_EQUALS(enum2cstr(event_info_t::command_execution_status), "command execution status");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(event_info_t::context), "context");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<event_info_t>(-1l)), nullptr);
  }
  /** // doc: test_command_type_t() {{{
   * \brief Ensure that enum2cstr() works with command_type_t.
   */ // }}}
  void test_command_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::ndrange_kernel), "ndrange kernel");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::task), "task");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::native_kernel), "native kernel");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::read_buffer), "read buffer");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::write_buffer), "write buffer");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::copy_buffer), "copy buffer");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::read_image), "read image");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::write_image), "write image");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::copy_image), "copy image");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::copy_image_to_buffer), "copy image to buffer");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::copy_buffer_to_image), "copy buffer to image");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::map_buffer), "map buffer");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::map_image), "map image");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::unmap_mem_object), "unmap mem object");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::marker), "marker");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::acquire_gl_objects), "acquire GL objects");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::release_gl_objects), "release GL objects");
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::read_buffer_rect), "read buffer rect");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::write_buffer_rect), "write buffer rect");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::copy_buffer_rect), "copy buffer rect");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::user), "user");
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::barrier), "barrier");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::migrate_mem_objects), "migrate mem objects");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::fill_buffer), "fill buffer");
    TS_ASSERT_EQUALS(enum2cstr(command_type_t::fill_image), "fill image");
#endif
    TS_ASSERT_EQUALS(enum2cstr(static_cast<command_type_t>(-1l)), nullptr);
  }
  /** // doc: test_command_exec_status_t() {{{
   * \brief Ensure that enum2cstr() works with command_exec_status_t.
   */ // }}}
  void test_command_exec_status_t( )
  {
    //
    // well-defined states
    //
    TS_ASSERT_EQUALS(enum2cstr(command_exec_status_t::complete), "complete");
    TS_ASSERT_EQUALS(enum2cstr(command_exec_status_t::running), "running");
    TS_ASSERT_EQUALS(enum2cstr(command_exec_status_t::submitted), "submitted");
    TS_ASSERT_EQUALS(enum2cstr(command_exec_status_t::queued), "queued");
    //
    // unknown state
    //
    TS_ASSERT_EQUALS(enum2cstr(static_cast<command_exec_status_t>(0x7FFF)), nullptr);
    //
    // Error codes should be handled by enum2cstr(status_t)
    //
    TS_ASSERT_EQUALS(enum2cstr(static_cast<command_exec_status_t>(status_t::invalid_value)), "invalid value");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<command_exec_status_t>(-0x7FFF)), nullptr);
  }
#if CLXX_CL_H_VERSION_1_1
  /** // doc: test_buffer_create_type_t() {{{
   * \brief Ensure that enum2cstr() works with buffer_create_type_t.
   */ // }}}
  void test_buffer_create_type_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(buffer_create_type_t::region), "region");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<buffer_create_type_t>(-1l)), nullptr);
  }
#endif
  /** // doc: test_profiling_info_t() {{{
   * \brief Ensure that enum2cstr() works with profiling_info_t.
   */ // }}}
  void test_profiling_info_t( )
  {
    TS_ASSERT_EQUALS(enum2cstr(profiling_info_t::queued), "queued");
    TS_ASSERT_EQUALS(enum2cstr(profiling_info_t::submit), "submit");
    TS_ASSERT_EQUALS(enum2cstr(profiling_info_t::start), "start");
    TS_ASSERT_EQUALS(enum2cstr(profiling_info_t::end), "end");
    TS_ASSERT_EQUALS(enum2cstr(static_cast<profiling_info_t>(-1l)), nullptr);
  }
};

#endif /* CLXX_UTIL_ENUM2STR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
