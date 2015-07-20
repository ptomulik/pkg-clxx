// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/clerror_stdexcept.hpp

/** // doc: clxx/util/clerror_stdexcept.hpp {{{
 * \file clxx/util/clerror_stdexcept.hpp
 * \brief Provides the clxx::clerror_stdexcept metafunction.
 */ // }}}
#ifndef CLXX_UTIL_CLERROR_STDEXCEPT_HPP_INCLUDED
#define CLXX_UTIL_CLERROR_STDEXCEPT_HPP_INCLUDED

#include <clxx/common/types.hpp>
#include <stdexcept>

namespace clxx {

/** // doc: clerror_stdexcept {{{
 * \ingroup clxx_util
 * \brief Determine an underlying standard exception for given error code.
 *
 * \tparam Code error code
 *
 * This metafunction takes an OpenCL error code as an argument and returns a
 * corresponding standard exception type. The returned type may be used as a
 * standard base exception for a given clxx::clerror_no exception.
 *
 * **Example**:
 * \code
 * using T = clerror_stdexcept<status_t::invalid_value>::type; // -> std::invalid_argument
 * \endcode
 *
 */ // }}}
template<status_t Code> struct clerror_stdexcept { };

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
  struct clerror_stdexcept<status_t::device_not_found>
  { typedef std::exception type; };
template<>
  struct clerror_stdexcept<status_t::device_not_available>
  { typedef std::exception type; };
template<>
  struct clerror_stdexcept<status_t::compiler_not_available>
  { typedef std::exception type; };
template<>
  struct clerror_stdexcept<status_t::mem_object_allocation_failure>
  { typedef std::bad_alloc type; };
template<>
  struct clerror_stdexcept<status_t::out_of_resources>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::out_of_host_memory>
  { typedef std::bad_alloc type; };
template<>
  struct clerror_stdexcept<status_t::profiling_info_not_available>
  { typedef std::exception type; };
template<>
  struct clerror_stdexcept<status_t::mem_copy_overlap>
  { typedef std::exception type; };
template<>
  struct clerror_stdexcept<status_t::image_format_mismatch>
  { typedef std::exception type; };
template<>
  struct clerror_stdexcept<status_t::image_format_not_supported>
  { typedef std::exception type; };
template<>
  struct clerror_stdexcept<status_t::build_program_failure>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::map_failure>
  { typedef std::runtime_error type; };
#if CLXX_CL_H_VERSION_1_1
template<>
  struct clerror_stdexcept<status_t::misaligned_sub_buffer_offset>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::exec_status_error_for_events_in_wait_list>
  { typedef std::invalid_argument type; };
#endif
#if CLXX_CL_H_VERSION_1_2
template<>
  struct clerror_stdexcept<status_t::compile_program_failure>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::linker_not_available>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::link_program_failure>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::device_partition_failed>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::kernel_arg_info_not_available>
  { typedef std::runtime_error type; };
#endif
template<>
  struct clerror_stdexcept<status_t::invalid_value>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_device_type>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_platform>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_device>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_context>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_queue_properties>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_command_queue>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_host_ptr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_mem_object>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_image_format_descriptor>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_image_size>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_sampler>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_binary>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_build_options>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_program>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_program_executable>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_kernel_name>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_kernel_definition>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_kernel>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_arg_index>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_arg_value>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_arg_size>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_kernel_args>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_work_dimension>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_work_group_size>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_work_item_size>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_global_offset>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_event_wait_list>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_event>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_operation>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_gl_object>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_buffer_size>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_mip_level>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_global_work_size>
  { typedef std::invalid_argument type; };
#if CLXX_CL_H_VERSION_1_1
template<>
  struct clerror_stdexcept<status_t::invalid_property>
  { typedef std::invalid_argument type; };
#endif
#if CLXX_CL_H_VERSION_1_2
template<>
  struct clerror_stdexcept<status_t::invalid_image_descriptor>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_compiler_options>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_linker_options>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_device_partition_count>
  { typedef std::invalid_argument type; };
#endif
#if CLXX_CL_H_VERSION_2_0
template<>
  struct clerror_stdexcept<status_t::invalid_pipe_size>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_device_queue>
  { typedef std::invalid_argument type; };
#endif
#if cl_khr_d3d10_sharing
template<>
  struct clerror_stdexcept<status_t::invalid_d3d10_device_khr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_d3d10_resource_khr>
  { typedef std::invalid_argument type; };
#endif
#if cl_khr_icd
template<>
  struct clerror_stdexcept<status_t::platform_not_found_khr>
  { typedef std::runtime_error type; };
#endif
#if cl_ext_device_fission
template<>
  struct clerror_stdexcept<status_t::device_partition_failed_ext>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::invalid_partition_count_ext>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_partition_name_ext>
  { typedef std::invalid_argument type; };
#endif
#if cl_khr_gl_sharing
template<>
  struct clerror_stdexcept<status_t::invalid_gl_sharegroup_reference_khr>
  { typedef std::invalid_argument type; };
#endif
#if cl_khr_dx9_media_sharing
template<>
  struct clerror_stdexcept<status_t::invalid_dx9_media_adapter_khr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_dx9_media_surface_khr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::dx9_media_surface_already_acquired_khr>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::dx9_media_surface_not_acquired_khr>
  { typedef std::runtime_error type; };
#endif
#if cl_khr_d3d10_sharing
template<>
  struct clerror_stdexcept<status_t::invalid_d3d10_device_khr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_d3d10_resource_khr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::d3d10_resource_already_acquired_khr>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::d3d10_resource_not_acquired_khr>
  { typedef std::runtime_error type; };
#endif
#if cl_khr_d3d11_sharing
template<>
  struct clerror_stdexcept<status_t::invalid_d3d11_device_khr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::invalid_d3d11_resource_khr>
  { typedef std::invalid_argument type; };
template<>
  struct clerror_stdexcept<status_t::d3d11_resource_already_acquired_khr>
  { typedef std::runtime_error type; };
template<>
  struct clerror_stdexcept<status_t::d3d11_resource_not_acquired_khr>
  { typedef std::runtime_error type; };
#endif
/** \endcond */

} // end namespace clxx

#endif /* CLXX_UTIL_CLERROR_STDEXCEPT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
