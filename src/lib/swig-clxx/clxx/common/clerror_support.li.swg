// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/clerror_support.li.swg {{{
 * \file clxx/common/clerror_support.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/common/clerror.hpp>
int SWIG_Clxx_clerror_type(clxx::clerror const& e)
{
  switch(e.code())
    {
      case clxx::status_t::device_not_found:
        return SWIG_RuntimeError;
      case clxx::status_t::device_not_available:
        return SWIG_RuntimeError;
      case clxx::status_t::compiler_not_available:
        return SWIG_RuntimeError;
      case clxx::status_t::mem_object_allocation_failure:
        return SWIG_MemoryError;
      case clxx::status_t::out_of_resources:
        return SWIG_RuntimeError;
      case clxx::status_t::out_of_host_memory:
        return SWIG_MemoryError;
      case clxx::status_t::profiling_info_not_available:
        return SWIG_RuntimeError;
      case clxx::status_t::mem_copy_overlap:
        return SWIG_ValueError;
      case clxx::status_t::image_format_mismatch:
        return SWIG_ValueError;
      case clxx::status_t::image_format_not_supported:
        return SWIG_RuntimeError;
      case clxx::status_t::build_program_failure:
        return SWIG_RuntimeError;
      case clxx::status_t::map_failure:
        return SWIG_RuntimeError;
#if CLXX_CL_H_VERSION_1_1
      case clxx::status_t::misaligned_sub_buffer_offset:
        return SWIG_ValueError;
      case clxx::status_t::exec_status_error_for_events_in_wait_list:
        return SWIG_RuntimeError;
#endif
#if CLXX_CL_H_VERSION_1_2
      case clxx::status_t::compile_program_failure:
        return SWIG_RuntimeError;
      case clxx::status_t::linker_not_available:
        return SWIG_RuntimeError;
      case clxx::status_t::link_program_failure:
        return SWIG_RuntimeError;
      case clxx::status_t::device_partition_failed:
        return SWIG_RuntimeError;
      case clxx::status_t::kernel_arg_info_not_available:
        return SWIG_RuntimeError;
#endif
      case clxx::status_t::invalid_value:
        return SWIG_ValueError;
      case clxx::status_t::invalid_device_type:
        return SWIG_ValueError;
      case clxx::status_t::invalid_platform:
        return SWIG_ValueError;
      case clxx::status_t::invalid_device:
        return SWIG_ValueError;
      case clxx::status_t::invalid_context:
        return SWIG_ValueError;
      case clxx::status_t::invalid_queue_properties:
        return SWIG_ValueError;
      case clxx::status_t::invalid_command_queue:
        return SWIG_ValueError;
      case clxx::status_t::invalid_host_ptr:
        return SWIG_ValueError;
      case clxx::status_t::invalid_mem_object:
        return SWIG_ValueError;
      case clxx::status_t::invalid_image_format_descriptor:
        return SWIG_ValueError;
      case clxx::status_t::invalid_image_size:
        return SWIG_ValueError;
      case clxx::status_t::invalid_sampler:
        return SWIG_ValueError;
      case clxx::status_t::invalid_binary:
        return SWIG_ValueError;
      case clxx::status_t::invalid_build_options:
        return SWIG_ValueError;
      case clxx::status_t::invalid_program:
        return SWIG_ValueError;
      case clxx::status_t::invalid_program_executable:
        return SWIG_ValueError;
      case clxx::status_t::invalid_kernel_name:
        return SWIG_ValueError;
      case clxx::status_t::invalid_kernel_definition:
        return SWIG_ValueError;
      case clxx::status_t::invalid_kernel:
        return SWIG_ValueError;
      case clxx::status_t::invalid_arg_index:
        return SWIG_ValueError;
      case clxx::status_t::invalid_arg_value:
        return SWIG_ValueError;
      case clxx::status_t::invalid_arg_size:
        return SWIG_ValueError;
      case clxx::status_t::invalid_kernel_args:
        return SWIG_ValueError;
      case clxx::status_t::invalid_work_dimension:
        return SWIG_ValueError;
      case clxx::status_t::invalid_work_group_size:
        return SWIG_ValueError;
      case clxx::status_t::invalid_work_item_size:
        return SWIG_ValueError;
      case clxx::status_t::invalid_global_offset:
        return SWIG_ValueError;
      case clxx::status_t::invalid_event_wait_list:
        return SWIG_ValueError;
      case clxx::status_t::invalid_event:
        return SWIG_ValueError;
      case clxx::status_t::invalid_operation:
        return SWIG_ValueError;
      case clxx::status_t::invalid_gl_object:
        return SWIG_ValueError;
      case clxx::status_t::invalid_buffer_size:
        return SWIG_ValueError;
      case clxx::status_t::invalid_mip_level:
        return SWIG_ValueError;
      case clxx::status_t::invalid_global_work_size:
        return SWIG_ValueError;
#if CLXX_CL_H_VERSION_1_1
      case clxx::status_t::invalid_property:
        return SWIG_ValueError;
#endif
#if CLXX_CL_H_VERSION_1_2
      case clxx::status_t::invalid_image_descriptor:
        return SWIG_ValueError;
      case clxx::status_t::invalid_compiler_options:
        return SWIG_ValueError;
      case clxx::status_t::invalid_linker_options:
        return SWIG_ValueError;
      case clxx::status_t::invalid_device_partition_count:
        return SWIG_ValueError;
#endif
#if cl_khr_icd
      case clxx::status_t::platform_not_found_khr:
        return SWIG_RuntimeError;
#endif
#if cl_ext_device_fission
      case clxx::status_t::device_partition_failed_ext:
        return SWIG_RuntimeError;
      case clxx::status_t::invalid_partition_count_ext:
        return SWIG_ValueError;
      case clxx::status_t::invalid_partition_name_ext:
        return SWIG_ValueError;
#endif
#if cl_khr_gl_sharing
      case clxx::status_t::invalid_gl_sharegroup_reference_khr:
        return SWIG_ValueError;
#endif
#if cl_khr_dx9_media_sharing
      case clxx::status_t::invalid_dx9_media_adapter_khr:
        return SWIG_ValueError;
      case clxx::status_t::invalid_dx9_media_surface_khr:
        return SWIG_ValueError;
      case clxx::status_t::dx9_media_surface_already_acquired_khr:
        return SWIG_RuntimeError;
      case clxx::status_t::dx9_media_surface_not_acquired_khr:
        return SWIG_RuntimeError;
#endif
#if cl_khr_d3d10_sharing
      case clxx::status_t::invalid_d3d10_device_khr:
        return SWIG_ValueError;
      case clxx::status_t::invalid_d3d10_resource_khr:
        return SWIG_ValueError;
      case clxx::status_t::d3d10_resource_already_acquired_khr:
        return SWIG_RuntimeError;
      case clxx::status_t::d3d10_resource_not_acquired_khr:
        return SWIG_RuntimeError;
#endif
#if cl_khr_d3d11_sharing
      case clxx::status_t::invalid_d3d11_device_khr:
        return SWIG_ValueError;
      case clxx::status_t::invalid_d3d11_resource_khr:
        return SWIG_ValueError;
      case clxx::status_t::d3d11_resource_already_acquired_khr:
        return SWIG_RuntimeError;
      case clxx::status_t::d3d11_resource_not_acquired_khr:
        return SWIG_RuntimeError;
#endif
      default:
        return SWIG_RuntimeError;
    }
}
#define SWIG_Clxx_clerror_msg(e) (e).clxx2std().what()
#define SWIG_Clxx_clerror(e) SWIG_exception(SWIG_Clxx_clerror_type(e), SWIG_Clxx_clerror_msg(e))
%}

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
