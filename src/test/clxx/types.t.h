// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/types.t.h

/** // doc: clxx/types.t.h {{{
 * \file clxx/types.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_TYPES_T_H_INCLUDED
#define CLXX_TYPES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/types.hpp>
#include <type_traits>

namespace clxx { class types_test; }

/** // doc: class types_test {{{
 * \todo Write documentation
 */ // }}}
class clxx::types_test : public CxxTest::TestSuite
{
public:
  /** // doc: test_status_t() {{{
   * \brief Test the status_t type.
   */ // }}}
  void test_status_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<status_t>::type, cl_int>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::success), CL_SUCCESS);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::device_not_found), CL_DEVICE_NOT_FOUND);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::device_not_available), CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::compiler_not_available), CL_COMPILER_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::mem_object_allocation_failure), CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::out_of_resources), CL_OUT_OF_RESOURCES);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::out_of_host_memory), CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::profiling_info_not_available), CL_PROFILING_INFO_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::mem_copy_overlap), CL_MEM_COPY_OVERLAP);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::image_format_mismatch), CL_IMAGE_FORMAT_MISMATCH);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::image_format_not_supported), CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::build_program_failure), CL_BUILD_PROGRAM_FAILURE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::map_failure), CL_MAP_FAILURE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::misaligned_sub_buffer_offset), CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::exec_status_error_for_events_in_wait_list), CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::compile_program_failure), CL_COMPILE_PROGRAM_FAILURE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::linker_not_available), CL_LINKER_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::link_program_failure), CL_LINK_PROGRAM_FAILURE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::device_partition_failed), CL_DEVICE_PARTITION_FAILED);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::kernel_arg_info_not_available), CL_KERNEL_ARG_INFO_NOT_AVAILABLE);
#endif
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_value), CL_INVALID_VALUE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_device_type), CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_platform), CL_INVALID_PLATFORM);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_device), CL_INVALID_DEVICE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_context), CL_INVALID_CONTEXT);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_queue_properties), CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_command_queue), CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_host_ptr), CL_INVALID_HOST_PTR);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_mem_object), CL_INVALID_MEM_OBJECT);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_image_format_descriptor), CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_image_size), CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_sampler), CL_INVALID_SAMPLER);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_binary), CL_INVALID_BINARY);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_build_options), CL_INVALID_BUILD_OPTIONS);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_program), CL_INVALID_PROGRAM);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_program_executable), CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_kernel_name), CL_INVALID_KERNEL_NAME);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_kernel_definition), CL_INVALID_KERNEL_DEFINITION);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_kernel), CL_INVALID_KERNEL);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_arg_index), CL_INVALID_ARG_INDEX);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_arg_value), CL_INVALID_ARG_VALUE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_arg_size), CL_INVALID_ARG_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_kernel_args), CL_INVALID_KERNEL_ARGS);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_work_dimension), CL_INVALID_WORK_DIMENSION);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_work_group_size), CL_INVALID_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_work_item_size), CL_INVALID_WORK_ITEM_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_global_offset), CL_INVALID_GLOBAL_OFFSET);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_event_wait_list), CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_event), CL_INVALID_EVENT);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_operation), CL_INVALID_OPERATION);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_gl_object), CL_INVALID_GL_OBJECT);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_buffer_size), CL_INVALID_BUFFER_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_mip_level), CL_INVALID_MIP_LEVEL);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_global_work_size), CL_INVALID_GLOBAL_WORK_SIZE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_property), CL_INVALID_PROPERTY);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_image_descriptor), CL_INVALID_IMAGE_DESCRIPTOR);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_compiler_options), CL_INVALID_COMPILER_OPTIONS);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_linker_options), CL_INVALID_LINKER_OPTIONS);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_device_partition_count), CL_INVALID_DEVICE_PARTITION_COUNT);
#endif
#if CLXX_CL_H_VERSION_2_0
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_pipe_size), CL_INVALID_PIPE_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_device_queue), CL_INVALID_DEVICE_QUEUE);
#endif
#if cl_khr_icd
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::platform_not_found_khr), CL_PLATFORM_NOT_FOUND_KHR);
#endif
#if cl_ext_device_fission
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::device_partition_failed_ext), CL_DEVICE_PARTITION_FAILED_EXT);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_partition_count_ext), CL_INVALID_PARTITION_COUNT_EXT);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_partition_name_ext), CL_INVALID_PARTITION_NAME_EXT);
#endif
#if cl_khr_gl_sharing
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_gl_sharegroup_reference_khr), CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR);
#endif
#if cl_khr_dx9_media_sharing
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_dx9_media_adapter_khr), CL_INVALID_DX9_MEDIA_ADAPTER_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_dx9_media_surface_khr), CL_INVALID_DX9_MEDIA_SURFACE_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::dx9_media_surface_already_acquired_khr), CL_DX9_MEDIA_SURFACE_ALREADY_ACQUIRED_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::dx9_media_surface_not_acquired_khr), CL_DX9_MEDIA_SURFACE_NOT_ACQUIRED_KHR);
#endif
#if cl_khr_d3d10_sharing
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_d3d10_device_khr), CL_INVALID_D3D10_DEVICE_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_d3d10_resource_khr), CL_INVALID_D3D10_RESOURCE_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::d3d10_resource_already_acquired_khr), CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::d3d10_resource_not_acquired_khr), CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR);
#endif
#if cl_khr_d3d11_sharing
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_d3d11_device_khr), CL_INVALID_D3D11_DEVICE_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::invalid_d3d11_resource_khr), CL_INVALID_D3D11_RESOURCE_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::d3d11_resource_already_acquired_khr), CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR);
  TS_ASSERT_EQUALS(static_cast<cl_int>(status_t::d3d11_resource_not_acquired_khr), CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR);
#endif
  }
  /** // doc: test_status_t__intval() {{{
   * \brief Test the status_t type.
   */ // }}}
  void test_status_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(status_t::success), CL_SUCCESS);
    TS_ASSERT_EQUALS(intval(status_t::device_not_found), CL_DEVICE_NOT_FOUND);
    TS_ASSERT_EQUALS(intval(status_t::device_not_available), CL_DEVICE_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(intval(status_t::compiler_not_available), CL_COMPILER_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(intval(status_t::mem_object_allocation_failure), CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_EQUALS(intval(status_t::out_of_resources), CL_OUT_OF_RESOURCES);
    TS_ASSERT_EQUALS(intval(status_t::out_of_host_memory), CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_EQUALS(intval(status_t::profiling_info_not_available), CL_PROFILING_INFO_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(intval(status_t::mem_copy_overlap), CL_MEM_COPY_OVERLAP);
    TS_ASSERT_EQUALS(intval(status_t::image_format_mismatch), CL_IMAGE_FORMAT_MISMATCH);
    TS_ASSERT_EQUALS(intval(status_t::image_format_not_supported), CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_EQUALS(intval(status_t::build_program_failure), CL_BUILD_PROGRAM_FAILURE);
    TS_ASSERT_EQUALS(intval(status_t::map_failure), CL_MAP_FAILURE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(status_t::misaligned_sub_buffer_offset), CL_MISALIGNED_SUB_BUFFER_OFFSET);
    TS_ASSERT_EQUALS(intval(status_t::exec_status_error_for_events_in_wait_list), CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(status_t::compile_program_failure), CL_COMPILE_PROGRAM_FAILURE);
    TS_ASSERT_EQUALS(intval(status_t::linker_not_available), CL_LINKER_NOT_AVAILABLE);
    TS_ASSERT_EQUALS(intval(status_t::link_program_failure), CL_LINK_PROGRAM_FAILURE);
    TS_ASSERT_EQUALS(intval(status_t::device_partition_failed), CL_DEVICE_PARTITION_FAILED);
    TS_ASSERT_EQUALS(intval(status_t::kernel_arg_info_not_available), CL_KERNEL_ARG_INFO_NOT_AVAILABLE);
#endif
    TS_ASSERT_EQUALS(intval(status_t::invalid_value), CL_INVALID_VALUE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_device_type), CL_INVALID_DEVICE_TYPE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_platform), CL_INVALID_PLATFORM);
    TS_ASSERT_EQUALS(intval(status_t::invalid_device), CL_INVALID_DEVICE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_context), CL_INVALID_CONTEXT);
    TS_ASSERT_EQUALS(intval(status_t::invalid_queue_properties), CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_EQUALS(intval(status_t::invalid_command_queue), CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_host_ptr), CL_INVALID_HOST_PTR);
    TS_ASSERT_EQUALS(intval(status_t::invalid_mem_object), CL_INVALID_MEM_OBJECT);
    TS_ASSERT_EQUALS(intval(status_t::invalid_image_format_descriptor), CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
    TS_ASSERT_EQUALS(intval(status_t::invalid_image_size), CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_sampler), CL_INVALID_SAMPLER);
    TS_ASSERT_EQUALS(intval(status_t::invalid_binary), CL_INVALID_BINARY);
    TS_ASSERT_EQUALS(intval(status_t::invalid_build_options), CL_INVALID_BUILD_OPTIONS);
    TS_ASSERT_EQUALS(intval(status_t::invalid_program), CL_INVALID_PROGRAM);
    TS_ASSERT_EQUALS(intval(status_t::invalid_program_executable), CL_INVALID_PROGRAM_EXECUTABLE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_kernel_name), CL_INVALID_KERNEL_NAME);
    TS_ASSERT_EQUALS(intval(status_t::invalid_kernel_definition), CL_INVALID_KERNEL_DEFINITION);
    TS_ASSERT_EQUALS(intval(status_t::invalid_kernel), CL_INVALID_KERNEL);
    TS_ASSERT_EQUALS(intval(status_t::invalid_arg_index), CL_INVALID_ARG_INDEX);
    TS_ASSERT_EQUALS(intval(status_t::invalid_arg_value), CL_INVALID_ARG_VALUE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_arg_size), CL_INVALID_ARG_SIZE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_kernel_args), CL_INVALID_KERNEL_ARGS);
    TS_ASSERT_EQUALS(intval(status_t::invalid_work_dimension), CL_INVALID_WORK_DIMENSION);
    TS_ASSERT_EQUALS(intval(status_t::invalid_work_group_size), CL_INVALID_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_work_item_size), CL_INVALID_WORK_ITEM_SIZE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_global_offset), CL_INVALID_GLOBAL_OFFSET);
    TS_ASSERT_EQUALS(intval(status_t::invalid_event_wait_list), CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_EQUALS(intval(status_t::invalid_event), CL_INVALID_EVENT);
    TS_ASSERT_EQUALS(intval(status_t::invalid_operation), CL_INVALID_OPERATION);
    TS_ASSERT_EQUALS(intval(status_t::invalid_gl_object), CL_INVALID_GL_OBJECT);
    TS_ASSERT_EQUALS(intval(status_t::invalid_buffer_size), CL_INVALID_BUFFER_SIZE);
    TS_ASSERT_EQUALS(intval(status_t::invalid_mip_level), CL_INVALID_MIP_LEVEL);
    TS_ASSERT_EQUALS(intval(status_t::invalid_global_work_size), CL_INVALID_GLOBAL_WORK_SIZE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(status_t::invalid_property), CL_INVALID_PROPERTY);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(status_t::invalid_image_descriptor), CL_INVALID_IMAGE_DESCRIPTOR);
    TS_ASSERT_EQUALS(intval(status_t::invalid_compiler_options), CL_INVALID_COMPILER_OPTIONS);
    TS_ASSERT_EQUALS(intval(status_t::invalid_linker_options), CL_INVALID_LINKER_OPTIONS);
    TS_ASSERT_EQUALS(intval(status_t::invalid_device_partition_count), CL_INVALID_DEVICE_PARTITION_COUNT);
#endif
#if cl_khr_icd
  TS_ASSERT_EQUALS(intval(status_t::platform_not_found_khr), CL_PLATFORM_NOT_FOUND_KHR);
#endif
#if cl_ext_device_fission
  TS_ASSERT_EQUALS(intval(status_t::device_partition_failed_ext), CL_DEVICE_PARTITION_FAILED_EXT);
  TS_ASSERT_EQUALS(intval(status_t::invalid_partition_count_ext), CL_INVALID_PARTITION_COUNT_EXT);
  TS_ASSERT_EQUALS(intval(status_t::invalid_partition_name_ext), CL_INVALID_PARTITION_NAME_EXT);
#endif
#if cl_khr_gl_sharing
  TS_ASSERT_EQUALS(intval(status_t::invalid_gl_sharegroup_reference_khr), CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR);
#endif
#if cl_khr_dx9_media_sharing
  TS_ASSERT_EQUALS(intval(status_t::invalid_dx9_media_adapter_khr), CL_INVALID_DX9_MEDIA_ADAPTER_KHR);
  TS_ASSERT_EQUALS(intval(status_t::invalid_dx9_media_surface_khr), CL_INVALID_DX9_MEDIA_SURFACE_KHR);
  TS_ASSERT_EQUALS(intval(status_t::dx9_media_surface_already_acquired_khr), CL_DX9_MEDIA_SURFACE_ALREADY_ACQUIRED_KHR);
  TS_ASSERT_EQUALS(intval(status_t::dx9_media_surface_not_acquired_khr), CL_DX9_MEDIA_SURFACE_NOT_ACQUIRED_KHR);
#endif
#if cl_khr_d3d10_sharing
  TS_ASSERT_EQUALS(intval(status_t::invalid_d3d10_device_khr), CL_INVALID_D3D10_DEVICE_KHR);
  TS_ASSERT_EQUALS(intval(status_t::invalid_d3d10_resource_khr), CL_INVALID_D3D10_RESOURCE_KHR);
  TS_ASSERT_EQUALS(intval(status_t::d3d10_resource_already_acquired_khr), CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR);
  TS_ASSERT_EQUALS(intval(status_t::d3d10_resource_not_acquired_khr), CL_D3D10_RESOURCE_ALREADY_ACQUIRED_KHR);
#endif
#if cl_khr_d3d11_sharing
  TS_ASSERT_EQUALS(intval(status_t::invalid_d3d11_device_khr), CL_INVALID_D3D11_DEVICE_KHR);
  TS_ASSERT_EQUALS(intval(status_t::invalid_d3d11_resource_khr), CL_INVALID_D3D11_RESOURCE_KHR);
  TS_ASSERT_EQUALS(intval(status_t::d3d11_resource_already_acquired_khr), CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR);
  TS_ASSERT_EQUALS(intval(status_t::d3d11_resource_not_acquired_khr), CL_D3D11_RESOURCE_ALREADY_ACQUIRED_KHR);
#endif
  }
  /** // doc: test_status_t__is_success() {{{
   * \brief Ensure that is_success() works correctly with status_t.
   */ // }}}
  void test_status_t__is_success( )
  {
    //
    // Success
    //
    TS_ASSERT(is_success(status_t::success));
    //
    // Errors
    //
    TS_ASSERT(!is_success(status_t::device_not_found));
    TS_ASSERT(!is_success(status_t::device_not_available));
    TS_ASSERT(!is_success(status_t::compiler_not_available));
    TS_ASSERT(!is_success(status_t::mem_object_allocation_failure));
    TS_ASSERT(!is_success(status_t::out_of_resources));
    TS_ASSERT(!is_success(status_t::out_of_host_memory));
    TS_ASSERT(!is_success(status_t::profiling_info_not_available));
    TS_ASSERT(!is_success(status_t::mem_copy_overlap));
    TS_ASSERT(!is_success(status_t::image_format_mismatch));
    TS_ASSERT(!is_success(status_t::image_format_not_supported));
    TS_ASSERT(!is_success(status_t::build_program_failure));
    TS_ASSERT(!is_success(status_t::map_failure));
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT(!is_success(status_t::misaligned_sub_buffer_offset));
    TS_ASSERT(!is_success(status_t::exec_status_error_for_events_in_wait_list));
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT(!is_success(status_t::compile_program_failure));
    TS_ASSERT(!is_success(status_t::linker_not_available));
    TS_ASSERT(!is_success(status_t::link_program_failure));
    TS_ASSERT(!is_success(status_t::device_partition_failed));
    TS_ASSERT(!is_success(status_t::kernel_arg_info_not_available));
#endif
    TS_ASSERT(!is_success(status_t::invalid_value));
    TS_ASSERT(!is_success(status_t::invalid_device_type));
    TS_ASSERT(!is_success(status_t::invalid_platform));
    TS_ASSERT(!is_success(status_t::invalid_device));
    TS_ASSERT(!is_success(status_t::invalid_context));
    TS_ASSERT(!is_success(status_t::invalid_queue_properties));
    TS_ASSERT(!is_success(status_t::invalid_command_queue));
    TS_ASSERT(!is_success(status_t::invalid_host_ptr));
    TS_ASSERT(!is_success(status_t::invalid_mem_object));
    TS_ASSERT(!is_success(status_t::invalid_image_format_descriptor));
    TS_ASSERT(!is_success(status_t::invalid_image_size));
    TS_ASSERT(!is_success(status_t::invalid_sampler));
    TS_ASSERT(!is_success(status_t::invalid_binary));
    TS_ASSERT(!is_success(status_t::invalid_build_options));
    TS_ASSERT(!is_success(status_t::invalid_program));
    TS_ASSERT(!is_success(status_t::invalid_program_executable));
    TS_ASSERT(!is_success(status_t::invalid_kernel_name));
    TS_ASSERT(!is_success(status_t::invalid_kernel_definition));
    TS_ASSERT(!is_success(status_t::invalid_kernel));
    TS_ASSERT(!is_success(status_t::invalid_arg_index));
    TS_ASSERT(!is_success(status_t::invalid_arg_value));
    TS_ASSERT(!is_success(status_t::invalid_arg_size));
    TS_ASSERT(!is_success(status_t::invalid_kernel_args));
    TS_ASSERT(!is_success(status_t::invalid_work_dimension));
    TS_ASSERT(!is_success(status_t::invalid_work_group_size));
    TS_ASSERT(!is_success(status_t::invalid_work_item_size));
    TS_ASSERT(!is_success(status_t::invalid_global_offset));
    TS_ASSERT(!is_success(status_t::invalid_event_wait_list));
    TS_ASSERT(!is_success(status_t::invalid_event));
    TS_ASSERT(!is_success(status_t::invalid_operation));
    TS_ASSERT(!is_success(status_t::invalid_gl_object));
    TS_ASSERT(!is_success(status_t::invalid_buffer_size));
    TS_ASSERT(!is_success(status_t::invalid_mip_level));
    TS_ASSERT(!is_success(status_t::invalid_global_work_size));
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT(!is_success(status_t::invalid_property));
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT(!is_success(status_t::invalid_image_descriptor));
    TS_ASSERT(!is_success(status_t::invalid_compiler_options));
    TS_ASSERT(!is_success(status_t::invalid_linker_options));
    TS_ASSERT(!is_success(status_t::invalid_device_partition_count));
#endif
#if cl_khr_icd
  TS_ASSERT(!is_success(status_t::platform_not_found_khr));
#endif
#if cl_ext_device_fission
  TS_ASSERT(!is_success(status_t::device_partition_failed_ext));
  TS_ASSERT(!is_success(status_t::invalid_partition_count_ext));
  TS_ASSERT(!is_success(status_t::invalid_partition_name_ext));
#endif
#if cl_khr_gl_sharing
  TS_ASSERT(!is_success(status_t::invalid_gl_sharegroup_reference_khr));
#endif
#if cl_khr_dx9_media_sharing
  TS_ASSERT(!is_success(status_t::invalid_dx9_media_adapter_khr));
  TS_ASSERT(!is_success(status_t::invalid_dx9_media_surface_khr));
  TS_ASSERT(!is_success(status_t::dx9_media_surface_already_acquired_khr));
  TS_ASSERT(!is_success(status_t::dx9_media_surface_not_acquired_khr));
#endif
#if cl_khr_d3d10_sharing
  TS_ASSERT(!is_success(status_t::invalid_d3d10_device_khr));
  TS_ASSERT(!is_success(status_t::invalid_d3d10_resource_khr));
  TS_ASSERT(!is_success(status_t::d3d10_resource_already_acquired_khr));
  TS_ASSERT(!is_success(status_t::d3d10_resource_not_acquired_khr));
#endif
#if cl_khr_d3d11_sharing
  TS_ASSERT(!is_success(status_t::invalid_d3d11_device_khr));
  TS_ASSERT(!is_success(status_t::invalid_d3d11_resource_khr));
  TS_ASSERT(!is_success(status_t::d3d11_resource_already_acquired_khr));
  TS_ASSERT(!is_success(status_t::d3d11_resource_not_acquired_khr));
#endif
  }
  /** // doc: test_status_t__is_error() {{{
   * \brief Ensure that is_error() works correctly with status_t.
   */ // }}}
  void test_status_t__is_error( )
  {
    //
    // Success
    //
    TS_ASSERT(!is_error(status_t::success));
    //
    // Errors
    //
    TS_ASSERT(is_error(status_t::device_not_found));
    TS_ASSERT(is_error(status_t::device_not_available));
    TS_ASSERT(is_error(status_t::compiler_not_available));
    TS_ASSERT(is_error(status_t::mem_object_allocation_failure));
    TS_ASSERT(is_error(status_t::out_of_resources));
    TS_ASSERT(is_error(status_t::out_of_host_memory));
    TS_ASSERT(is_error(status_t::profiling_info_not_available));
    TS_ASSERT(is_error(status_t::mem_copy_overlap));
    TS_ASSERT(is_error(status_t::image_format_mismatch));
    TS_ASSERT(is_error(status_t::image_format_not_supported));
    TS_ASSERT(is_error(status_t::build_program_failure));
    TS_ASSERT(is_error(status_t::map_failure));
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT(is_error(status_t::misaligned_sub_buffer_offset));
    TS_ASSERT(is_error(status_t::exec_status_error_for_events_in_wait_list));
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT(is_error(status_t::compile_program_failure));
    TS_ASSERT(is_error(status_t::linker_not_available));
    TS_ASSERT(is_error(status_t::link_program_failure));
    TS_ASSERT(is_error(status_t::device_partition_failed));
    TS_ASSERT(is_error(status_t::kernel_arg_info_not_available));
#endif
    TS_ASSERT(is_error(status_t::invalid_value));
    TS_ASSERT(is_error(status_t::invalid_device_type));
    TS_ASSERT(is_error(status_t::invalid_platform));
    TS_ASSERT(is_error(status_t::invalid_device));
    TS_ASSERT(is_error(status_t::invalid_context));
    TS_ASSERT(is_error(status_t::invalid_queue_properties));
    TS_ASSERT(is_error(status_t::invalid_command_queue));
    TS_ASSERT(is_error(status_t::invalid_host_ptr));
    TS_ASSERT(is_error(status_t::invalid_mem_object));
    TS_ASSERT(is_error(status_t::invalid_image_format_descriptor));
    TS_ASSERT(is_error(status_t::invalid_image_size));
    TS_ASSERT(is_error(status_t::invalid_sampler));
    TS_ASSERT(is_error(status_t::invalid_binary));
    TS_ASSERT(is_error(status_t::invalid_build_options));
    TS_ASSERT(is_error(status_t::invalid_program));
    TS_ASSERT(is_error(status_t::invalid_program_executable));
    TS_ASSERT(is_error(status_t::invalid_kernel_name));
    TS_ASSERT(is_error(status_t::invalid_kernel_definition));
    TS_ASSERT(is_error(status_t::invalid_kernel));
    TS_ASSERT(is_error(status_t::invalid_arg_index));
    TS_ASSERT(is_error(status_t::invalid_arg_value));
    TS_ASSERT(is_error(status_t::invalid_arg_size));
    TS_ASSERT(is_error(status_t::invalid_kernel_args));
    TS_ASSERT(is_error(status_t::invalid_work_dimension));
    TS_ASSERT(is_error(status_t::invalid_work_group_size));
    TS_ASSERT(is_error(status_t::invalid_work_item_size));
    TS_ASSERT(is_error(status_t::invalid_global_offset));
    TS_ASSERT(is_error(status_t::invalid_event_wait_list));
    TS_ASSERT(is_error(status_t::invalid_event));
    TS_ASSERT(is_error(status_t::invalid_operation));
    TS_ASSERT(is_error(status_t::invalid_gl_object));
    TS_ASSERT(is_error(status_t::invalid_buffer_size));
    TS_ASSERT(is_error(status_t::invalid_mip_level));
    TS_ASSERT(is_error(status_t::invalid_global_work_size));
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT(is_error(status_t::invalid_property));
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT(is_error(status_t::invalid_image_descriptor));
    TS_ASSERT(is_error(status_t::invalid_compiler_options));
    TS_ASSERT(is_error(status_t::invalid_linker_options));
    TS_ASSERT(is_error(status_t::invalid_device_partition_count));
#endif
#if cl_khr_icd
  TS_ASSERT(is_error(status_t::platform_not_found_khr));
#endif
#if cl_ext_device_fission
  TS_ASSERT(is_error(status_t::device_partition_failed_ext));
  TS_ASSERT(is_error(status_t::invalid_partition_count_ext));
  TS_ASSERT(is_error(status_t::invalid_partition_name_ext));
#endif
#if cl_khr_gl_sharing
  TS_ASSERT(is_error(status_t::invalid_gl_sharegroup_reference_khr));
#endif
#if cl_khr_dx9_media_sharing
  TS_ASSERT(is_error(status_t::invalid_dx9_media_adapter_khr));
  TS_ASSERT(is_error(status_t::invalid_dx9_media_surface_khr));
  TS_ASSERT(is_error(status_t::dx9_media_surface_already_acquired_khr));
  TS_ASSERT(is_error(status_t::dx9_media_surface_not_acquired_khr));
#endif
#if cl_khr_d3d10_sharing
  TS_ASSERT(is_error(status_t::invalid_d3d10_device_khr));
  TS_ASSERT(is_error(status_t::invalid_d3d10_resource_khr));
  TS_ASSERT(is_error(status_t::d3d10_resource_already_acquired_khr));
  TS_ASSERT(is_error(status_t::d3d10_resource_not_acquired_khr));
#endif
#if cl_khr_d3d11_sharing
  TS_ASSERT(is_error(status_t::invalid_d3d11_device_khr));
  TS_ASSERT(is_error(status_t::invalid_d3d11_resource_khr));
  TS_ASSERT(is_error(status_t::d3d11_resource_already_acquired_khr));
  TS_ASSERT(is_error(status_t::d3d11_resource_not_acquired_khr));
#endif
  }
  /** // doc: test_platform_info_t() {{{
   * \brief Test the platform_info_t type.
   */ // }}}
  void test_platform_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<platform_info_t>::type, cl_platform_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_platform_info>(platform_info_t::profile), CL_PLATFORM_PROFILE);
    TS_ASSERT_EQUALS(static_cast<cl_platform_info>(platform_info_t::version), CL_PLATFORM_VERSION);
    TS_ASSERT_EQUALS(static_cast<cl_platform_info>(platform_info_t::name), CL_PLATFORM_NAME);
    TS_ASSERT_EQUALS(static_cast<cl_platform_info>(platform_info_t::vendor), CL_PLATFORM_VENDOR);
    TS_ASSERT_EQUALS(static_cast<cl_platform_info>(platform_info_t::extensions), CL_PLATFORM_EXTENSIONS);
  }
  /** // doc: test_platform_info_t__intval() {{{
   * \brief Test the platform_info_t__intval type.
   */ // }}}
  void test_platform_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(platform_info_t::profile), CL_PLATFORM_PROFILE);
    TS_ASSERT_EQUALS(intval(platform_info_t::version), CL_PLATFORM_VERSION);
    TS_ASSERT_EQUALS(intval(platform_info_t::name), CL_PLATFORM_NAME);
    TS_ASSERT_EQUALS(intval(platform_info_t::vendor), CL_PLATFORM_VENDOR);
    TS_ASSERT_EQUALS(intval(platform_info_t::extensions), CL_PLATFORM_EXTENSIONS);
  }
  /** // doc: test_device_type_t() {{{
   * \brief Test the device_type_t type.
   */ // }}}
  void test_device_type_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_type_t>::type, cl_device_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_type>(device_type_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_device_type>(device_type_t::default_), CL_DEVICE_TYPE_DEFAULT);
    TS_ASSERT_EQUALS(static_cast<cl_device_type>(device_type_t::cpu), CL_DEVICE_TYPE_CPU);
    TS_ASSERT_EQUALS(static_cast<cl_device_type>(device_type_t::gpu), CL_DEVICE_TYPE_GPU);
    TS_ASSERT_EQUALS(static_cast<cl_device_type>(device_type_t::accelerator), CL_DEVICE_TYPE_ACCELERATOR);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_device_type>(device_type_t::custom), CL_DEVICE_TYPE_CUSTOM);
#endif
    TS_ASSERT_EQUALS(static_cast<cl_device_type>(device_type_t::all), CL_DEVICE_TYPE_ALL);
  }
  /** // doc: test_device_type_t__intval() {{{
   * \brief Test the device_type_t type with intval().
   */ // }}}
  void test_device_type_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_type_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(device_type_t::default_), CL_DEVICE_TYPE_DEFAULT);
    TS_ASSERT_EQUALS(intval(device_type_t::cpu), CL_DEVICE_TYPE_CPU);
    TS_ASSERT_EQUALS(intval(device_type_t::gpu), CL_DEVICE_TYPE_GPU);
    TS_ASSERT_EQUALS(intval(device_type_t::accelerator), CL_DEVICE_TYPE_ACCELERATOR);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(device_type_t::custom), CL_DEVICE_TYPE_CUSTOM);
#endif
    TS_ASSERT_EQUALS(intval(device_type_t::all), CL_DEVICE_TYPE_ALL);
  }
  /** // doc: test_device_type_t__bitops() {{{
   * \brief Ensure that bitwise operators work with device_type_t
   */ // }}}
  void test_device_type_t__bitops( )
  {
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(device_type_t::cpu), static_cast<device_type_t>(~CL_DEVICE_TYPE_CPU));
    TS_ASSERT_EQUALS((device_type_t::cpu & device_type_t::gpu), static_cast<device_type_t>(CL_DEVICE_TYPE_CPU & CL_DEVICE_TYPE_GPU));
    TS_ASSERT_EQUALS((device_type_t::cpu | device_type_t::gpu), static_cast<device_type_t>(CL_DEVICE_TYPE_CPU | CL_DEVICE_TYPE_GPU));
    TS_ASSERT_EQUALS((device_type_t::cpu ^ device_type_t::gpu), static_cast<device_type_t>(CL_DEVICE_TYPE_CPU ^ CL_DEVICE_TYPE_GPU));

    device_type_t x(device_type_t::cpu);

    x |= device_type_t::gpu;
    TS_ASSERT_EQUALS(x, static_cast<device_type_t>(CL_DEVICE_TYPE_CPU | CL_DEVICE_TYPE_GPU));
    x &= ~device_type_t::gpu;
    TS_ASSERT_EQUALS(x, static_cast<device_type_t>(CL_DEVICE_TYPE_CPU));
    x ^= device_type_t::gpu;
    TS_ASSERT_EQUALS(x, static_cast<device_type_t>(CL_DEVICE_TYPE_CPU | CL_DEVICE_TYPE_GPU));
  }
  /** // doc: test_device_info_t() {{{
   * \brief Test the device_info_t type.
   */ // }}}
  void test_device_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_info_t>::type, cl_device_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::type), CL_DEVICE_TYPE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::vendor_id), CL_DEVICE_VENDOR_ID);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_compute_units), CL_DEVICE_MAX_COMPUTE_UNITS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_work_item_dimensions), CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_work_group_size), CL_DEVICE_MAX_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_work_item_sizes), CL_DEVICE_MAX_WORK_ITEM_SIZES);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_vector_width_char), CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_vector_width_short), CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_vector_width_int), CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_vector_width_long), CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_vector_width_float), CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_vector_width_double), CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_clock_frequency), CL_DEVICE_MAX_CLOCK_FREQUENCY);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::address_bits), CL_DEVICE_ADDRESS_BITS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_read_image_args), CL_DEVICE_MAX_READ_IMAGE_ARGS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_write_image_args), CL_DEVICE_MAX_WRITE_IMAGE_ARGS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_mem_alloc_size), CL_DEVICE_MAX_MEM_ALLOC_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image2d_max_width), CL_DEVICE_IMAGE2D_MAX_WIDTH);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image2d_max_height), CL_DEVICE_IMAGE2D_MAX_HEIGHT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image3d_max_width), CL_DEVICE_IMAGE3D_MAX_WIDTH);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image3d_max_height), CL_DEVICE_IMAGE3D_MAX_HEIGHT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image3d_max_depth), CL_DEVICE_IMAGE3D_MAX_DEPTH);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image_support), CL_DEVICE_IMAGE_SUPPORT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_parameter_size), CL_DEVICE_MAX_PARAMETER_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_samplers), CL_DEVICE_MAX_SAMPLERS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::mem_base_addr_align), CL_DEVICE_MEM_BASE_ADDR_ALIGN);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::min_data_type_align_size), CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::single_fp_config), CL_DEVICE_SINGLE_FP_CONFIG);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::global_mem_cache_type), CL_DEVICE_GLOBAL_MEM_CACHE_TYPE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::global_mem_cacheline_size), CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::global_mem_cache_size), CL_DEVICE_GLOBAL_MEM_CACHE_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::global_mem_size), CL_DEVICE_GLOBAL_MEM_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_constant_buffer_size), CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::max_constant_args), CL_DEVICE_MAX_CONSTANT_ARGS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::local_mem_type), CL_DEVICE_LOCAL_MEM_TYPE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::local_mem_size), CL_DEVICE_LOCAL_MEM_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::error_correction_support), CL_DEVICE_ERROR_CORRECTION_SUPPORT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::profiling_timer_resolution), CL_DEVICE_PROFILING_TIMER_RESOLUTION);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::endian_little), CL_DEVICE_ENDIAN_LITTLE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::available), CL_DEVICE_AVAILABLE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::compiler_available), CL_DEVICE_COMPILER_AVAILABLE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::execution_capabilities), CL_DEVICE_EXECUTION_CAPABILITIES);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::queue_properties), CL_DEVICE_QUEUE_PROPERTIES);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::name), CL_DEVICE_NAME);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::vendor), CL_DEVICE_VENDOR);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::driver_version), CL_DRIVER_VERSION);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::profile), CL_DEVICE_PROFILE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::version), CL_DEVICE_VERSION);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::extensions), CL_DEVICE_EXTENSIONS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::platform), CL_DEVICE_PLATFORM);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::double_fp_config), CL_DEVICE_DOUBLE_FP_CONFIG);
#endif
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_vector_width_half), CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::host_unified_memory), CL_DEVICE_HOST_UNIFIED_MEMORY);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::native_vector_width_char), CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::native_vector_width_short), CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::native_vector_width_int), CL_DEVICE_NATIVE_VECTOR_WIDTH_INT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::native_vector_width_long), CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::native_vector_width_float), CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::native_vector_width_double), CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::native_vector_width_half), CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::opencl_c_version), CL_DEVICE_OPENCL_C_VERSION);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::linker_available), CL_DEVICE_LINKER_AVAILABLE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::built_in_kernels), CL_DEVICE_BUILT_IN_KERNELS);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image_max_buffer_size), CL_DEVICE_IMAGE_MAX_BUFFER_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image_max_array_size), CL_DEVICE_IMAGE_MAX_ARRAY_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::parent_device), CL_DEVICE_PARENT_DEVICE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::partition_max_sub_devices), CL_DEVICE_PARTITION_MAX_SUB_DEVICES);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::partition_properties), CL_DEVICE_PARTITION_PROPERTIES);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::partition_affinity_domain), CL_DEVICE_PARTITION_AFFINITY_DOMAIN);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::partition_type), CL_DEVICE_PARTITION_TYPE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::reference_count), CL_DEVICE_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::preferred_interop_user_sync), CL_DEVICE_PREFERRED_INTEROP_USER_SYNC);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::printf_buffer_size), CL_DEVICE_PRINTF_BUFFER_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image_pitch_alignment), CL_DEVICE_IMAGE_PITCH_ALIGNMENT);
    TS_ASSERT_EQUALS(static_cast<cl_device_info>(device_info_t::image_base_address_alignment), CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT);
#endif
  }
  /** // doc: test_device_info_t__intval() {{{
   * \brief Test the device_info_t type with intval().
   */ // }}}
  void test_device_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_info_t::type), CL_DEVICE_TYPE);
    TS_ASSERT_EQUALS(intval(device_info_t::vendor_id), CL_DEVICE_VENDOR_ID);
    TS_ASSERT_EQUALS(intval(device_info_t::max_compute_units), CL_DEVICE_MAX_COMPUTE_UNITS);
    TS_ASSERT_EQUALS(intval(device_info_t::max_work_item_dimensions), CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS);
    TS_ASSERT_EQUALS(intval(device_info_t::max_work_group_size), CL_DEVICE_MAX_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::max_work_item_sizes), CL_DEVICE_MAX_WORK_ITEM_SIZES);
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_vector_width_char), CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_vector_width_short), CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_vector_width_int), CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT);
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_vector_width_long), CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_vector_width_float), CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_vector_width_double), CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
    TS_ASSERT_EQUALS(intval(device_info_t::max_clock_frequency), CL_DEVICE_MAX_CLOCK_FREQUENCY);
    TS_ASSERT_EQUALS(intval(device_info_t::address_bits), CL_DEVICE_ADDRESS_BITS);
    TS_ASSERT_EQUALS(intval(device_info_t::max_read_image_args), CL_DEVICE_MAX_READ_IMAGE_ARGS);
    TS_ASSERT_EQUALS(intval(device_info_t::max_write_image_args), CL_DEVICE_MAX_WRITE_IMAGE_ARGS);
    TS_ASSERT_EQUALS(intval(device_info_t::max_mem_alloc_size), CL_DEVICE_MAX_MEM_ALLOC_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::image2d_max_width), CL_DEVICE_IMAGE2D_MAX_WIDTH);
    TS_ASSERT_EQUALS(intval(device_info_t::image2d_max_height), CL_DEVICE_IMAGE2D_MAX_HEIGHT);
    TS_ASSERT_EQUALS(intval(device_info_t::image3d_max_width), CL_DEVICE_IMAGE3D_MAX_WIDTH);
    TS_ASSERT_EQUALS(intval(device_info_t::image3d_max_height), CL_DEVICE_IMAGE3D_MAX_HEIGHT);
    TS_ASSERT_EQUALS(intval(device_info_t::image3d_max_depth), CL_DEVICE_IMAGE3D_MAX_DEPTH);
    TS_ASSERT_EQUALS(intval(device_info_t::image_support), CL_DEVICE_IMAGE_SUPPORT);
    TS_ASSERT_EQUALS(intval(device_info_t::max_parameter_size), CL_DEVICE_MAX_PARAMETER_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::max_samplers), CL_DEVICE_MAX_SAMPLERS);
    TS_ASSERT_EQUALS(intval(device_info_t::mem_base_addr_align), CL_DEVICE_MEM_BASE_ADDR_ALIGN);
    TS_ASSERT_EQUALS(intval(device_info_t::min_data_type_align_size), CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::single_fp_config), CL_DEVICE_SINGLE_FP_CONFIG);
    TS_ASSERT_EQUALS(intval(device_info_t::global_mem_cache_type), CL_DEVICE_GLOBAL_MEM_CACHE_TYPE);
    TS_ASSERT_EQUALS(intval(device_info_t::global_mem_cacheline_size), CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::global_mem_cache_size), CL_DEVICE_GLOBAL_MEM_CACHE_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::global_mem_size), CL_DEVICE_GLOBAL_MEM_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::max_constant_buffer_size), CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::max_constant_args), CL_DEVICE_MAX_CONSTANT_ARGS);
    TS_ASSERT_EQUALS(intval(device_info_t::local_mem_type), CL_DEVICE_LOCAL_MEM_TYPE);
    TS_ASSERT_EQUALS(intval(device_info_t::local_mem_size), CL_DEVICE_LOCAL_MEM_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::error_correction_support), CL_DEVICE_ERROR_CORRECTION_SUPPORT);
    TS_ASSERT_EQUALS(intval(device_info_t::profiling_timer_resolution), CL_DEVICE_PROFILING_TIMER_RESOLUTION);
    TS_ASSERT_EQUALS(intval(device_info_t::endian_little), CL_DEVICE_ENDIAN_LITTLE);
    TS_ASSERT_EQUALS(intval(device_info_t::available), CL_DEVICE_AVAILABLE);
    TS_ASSERT_EQUALS(intval(device_info_t::compiler_available), CL_DEVICE_COMPILER_AVAILABLE);
    TS_ASSERT_EQUALS(intval(device_info_t::execution_capabilities), CL_DEVICE_EXECUTION_CAPABILITIES);
    TS_ASSERT_EQUALS(intval(device_info_t::queue_properties), CL_DEVICE_QUEUE_PROPERTIES);
    TS_ASSERT_EQUALS(intval(device_info_t::name), CL_DEVICE_NAME);
    TS_ASSERT_EQUALS(intval(device_info_t::vendor), CL_DEVICE_VENDOR);
    TS_ASSERT_EQUALS(intval(device_info_t::driver_version), CL_DRIVER_VERSION);
    TS_ASSERT_EQUALS(intval(device_info_t::profile), CL_DEVICE_PROFILE);
    TS_ASSERT_EQUALS(intval(device_info_t::version), CL_DEVICE_VERSION);
    TS_ASSERT_EQUALS(intval(device_info_t::extensions), CL_DEVICE_EXTENSIONS);
    TS_ASSERT_EQUALS(intval(device_info_t::platform), CL_DEVICE_PLATFORM);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(device_info_t::double_fp_config), CL_DEVICE_DOUBLE_FP_CONFIG);
#endif
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_vector_width_half), CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
    TS_ASSERT_EQUALS(intval(device_info_t::host_unified_memory), CL_DEVICE_HOST_UNIFIED_MEMORY);
    TS_ASSERT_EQUALS(intval(device_info_t::native_vector_width_char), CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
    TS_ASSERT_EQUALS(intval(device_info_t::native_vector_width_short), CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT);
    TS_ASSERT_EQUALS(intval(device_info_t::native_vector_width_int), CL_DEVICE_NATIVE_VECTOR_WIDTH_INT);
    TS_ASSERT_EQUALS(intval(device_info_t::native_vector_width_long), CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG);
    TS_ASSERT_EQUALS(intval(device_info_t::native_vector_width_float), CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT);
    TS_ASSERT_EQUALS(intval(device_info_t::native_vector_width_double), CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE);
    TS_ASSERT_EQUALS(intval(device_info_t::native_vector_width_half), CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF);
    TS_ASSERT_EQUALS(intval(device_info_t::opencl_c_version), CL_DEVICE_OPENCL_C_VERSION);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(device_info_t::linker_available), CL_DEVICE_LINKER_AVAILABLE);
    TS_ASSERT_EQUALS(intval(device_info_t::built_in_kernels), CL_DEVICE_BUILT_IN_KERNELS);
    TS_ASSERT_EQUALS(intval(device_info_t::image_max_buffer_size), CL_DEVICE_IMAGE_MAX_BUFFER_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::image_max_array_size), CL_DEVICE_IMAGE_MAX_ARRAY_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::parent_device), CL_DEVICE_PARENT_DEVICE);
    TS_ASSERT_EQUALS(intval(device_info_t::partition_max_sub_devices), CL_DEVICE_PARTITION_MAX_SUB_DEVICES);
    TS_ASSERT_EQUALS(intval(device_info_t::partition_properties), CL_DEVICE_PARTITION_PROPERTIES);
    TS_ASSERT_EQUALS(intval(device_info_t::partition_affinity_domain), CL_DEVICE_PARTITION_AFFINITY_DOMAIN);
    TS_ASSERT_EQUALS(intval(device_info_t::partition_type), CL_DEVICE_PARTITION_TYPE);
    TS_ASSERT_EQUALS(intval(device_info_t::reference_count), CL_DEVICE_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(device_info_t::preferred_interop_user_sync), CL_DEVICE_PREFERRED_INTEROP_USER_SYNC);
    TS_ASSERT_EQUALS(intval(device_info_t::printf_buffer_size), CL_DEVICE_PRINTF_BUFFER_SIZE);
    TS_ASSERT_EQUALS(intval(device_info_t::image_pitch_alignment), CL_DEVICE_IMAGE_PITCH_ALIGNMENT);
    TS_ASSERT_EQUALS(intval(device_info_t::image_base_address_alignment), CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT);
#endif
  }
  /** // doc: test_device_fp_config_t() {{{
   * \brief Test the device_fp_config_t type.
   */ // }}}
  void test_device_fp_config_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_fp_config_t>::type, cl_device_fp_config>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::denorm), CL_FP_DENORM);
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::inf_nan), CL_FP_INF_NAN);
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::round_to_nearest), CL_FP_ROUND_TO_NEAREST);
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::round_to_zero), CL_FP_ROUND_TO_ZERO);
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::round_to_inf), CL_FP_ROUND_TO_INF);
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::fma), CL_FP_FMA);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::soft_float), CL_FP_SOFT_FLOAT);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_device_fp_config>(device_fp_config_t::correctly_rounded_divide_sqrt), CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT);
#endif
  }
  /** // doc: test_device_fp_config_t__intval() {{{
   * \brief Test the device_fp_config_t type with intval().
   */ // }}}
  void test_device_fp_config_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_fp_config_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(device_fp_config_t::denorm), CL_FP_DENORM);
    TS_ASSERT_EQUALS(intval(device_fp_config_t::inf_nan), CL_FP_INF_NAN);
    TS_ASSERT_EQUALS(intval(device_fp_config_t::round_to_nearest), CL_FP_ROUND_TO_NEAREST);
    TS_ASSERT_EQUALS(intval(device_fp_config_t::round_to_zero), CL_FP_ROUND_TO_ZERO);
    TS_ASSERT_EQUALS(intval(device_fp_config_t::round_to_inf), CL_FP_ROUND_TO_INF);
    TS_ASSERT_EQUALS(intval(device_fp_config_t::fma), CL_FP_FMA);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(device_fp_config_t::soft_float), CL_FP_SOFT_FLOAT);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(device_fp_config_t::correctly_rounded_divide_sqrt), CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT);
#endif
  }
  /** // doc: test_device_fp_confit_t__bitops() {{{
   * \brief Ensure that bitwise operators work with device_fp_config_t
   */ // }}}
  void test_device_fp_confit_t__bitops( )
  {
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(device_fp_config_t::denorm), static_cast<device_fp_config_t>(~CL_FP_DENORM));
    TS_ASSERT_EQUALS((device_fp_config_t::denorm & device_fp_config_t::inf_nan), static_cast<device_fp_config_t>(CL_FP_DENORM & CL_FP_INF_NAN));
    TS_ASSERT_EQUALS((device_fp_config_t::denorm | device_fp_config_t::inf_nan), static_cast<device_fp_config_t>(CL_FP_DENORM | CL_FP_INF_NAN));
    TS_ASSERT_EQUALS((device_fp_config_t::denorm ^ device_fp_config_t::inf_nan), static_cast<device_fp_config_t>(CL_FP_DENORM ^ CL_FP_INF_NAN));

    device_fp_config_t x(device_fp_config_t::denorm);

    x |= device_fp_config_t::inf_nan;
    TS_ASSERT_EQUALS(x, static_cast<device_fp_config_t>(CL_FP_DENORM | CL_FP_INF_NAN));
    x &= ~device_fp_config_t::inf_nan;
    TS_ASSERT_EQUALS(x, static_cast<device_fp_config_t>(CL_FP_DENORM));
    x ^= device_fp_config_t::inf_nan;
    TS_ASSERT_EQUALS(x, static_cast<device_fp_config_t>(CL_FP_DENORM | CL_FP_INF_NAN));
  }
  /** // doc: test_device_mem_cache_type_t() {{{
   * \brief Test the device_mem_cache_type_t type.
   */ // }}}
  void test_device_mem_cache_type_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_mem_cache_type_t>::type, cl_device_mem_cache_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_mem_cache_type>(device_mem_cache_type_t::none), CL_NONE);
    TS_ASSERT_EQUALS(static_cast<cl_device_mem_cache_type>(device_mem_cache_type_t::read_only_cache), CL_READ_ONLY_CACHE);
    TS_ASSERT_EQUALS(static_cast<cl_device_mem_cache_type>(device_mem_cache_type_t::read_write_cache), CL_READ_WRITE_CACHE);
  }
  /** // doc: test_device_mem_cache_type_t__intval() {{{
   * \brief Test the device_mem_cache_type_t type with intval().
   */ // }}}
  void test_device_mem_cache_type_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_mem_cache_type_t::none), CL_NONE);
    TS_ASSERT_EQUALS(intval(device_mem_cache_type_t::read_only_cache), CL_READ_ONLY_CACHE);
    TS_ASSERT_EQUALS(intval(device_mem_cache_type_t::read_write_cache), CL_READ_WRITE_CACHE);
  }
  /** // doc: test_device_local_mem_type_t() {{{
   * \brief Test the device_local_mem_type_t type.
   */ // }}}
  void test_device_local_mem_type_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_local_mem_type_t>::type, cl_device_local_mem_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_local_mem_type>(device_local_mem_type_t::local), CL_LOCAL);
    TS_ASSERT_EQUALS(static_cast<cl_device_local_mem_type>(device_local_mem_type_t::global), CL_GLOBAL);
  }
  /** // doc: test_device_local_mem_type_t__intval() {{{
   * \brief Test the device_local_mem_type_t type with intval().
   */ // }}}
  void test_device_local_mem_type_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_local_mem_type_t::local), CL_LOCAL);
    TS_ASSERT_EQUALS(intval(device_local_mem_type_t::global), CL_GLOBAL);
  }
  /** // doc: test_device_exec_capabilities_t() {{{
   * \brief Test the device_exec_capabilities_t type.
   */ // }}}
  void test_device_exec_capabilities_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_exec_capabilities_t>::type, cl_device_exec_capabilities>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_exec_capabilities>(device_exec_capabilities_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_device_exec_capabilities>(device_exec_capabilities_t::kernel), CL_EXEC_KERNEL);
    TS_ASSERT_EQUALS(static_cast<cl_device_exec_capabilities>(device_exec_capabilities_t::native_kernel), CL_EXEC_NATIVE_KERNEL);
  }
  /** // doc: test_device_exec_capabilities_t__intval() {{{
   * \brief Test the device_exec_capabilities_t type with intval().
   */ // }}}
  void test_device_exec_capabilities_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_exec_capabilities_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(device_exec_capabilities_t::kernel), CL_EXEC_KERNEL);
    TS_ASSERT_EQUALS(intval(device_exec_capabilities_t::native_kernel), CL_EXEC_NATIVE_KERNEL);
  }
  /** // doc: test_device_exec_capabilities_t__bitops() {{{
   * \brief Ensure that bitwise operators work with device_exec_capabilities_t
   */ // }}}
  void test_device_exec_capabilities_t__bitops( )
  {
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(device_exec_capabilities_t::kernel), static_cast<device_exec_capabilities_t>(~CL_EXEC_KERNEL));
    TS_ASSERT_EQUALS((device_exec_capabilities_t::kernel & device_exec_capabilities_t::native_kernel), static_cast<device_exec_capabilities_t>(CL_EXEC_KERNEL & CL_EXEC_NATIVE_KERNEL));
    TS_ASSERT_EQUALS((device_exec_capabilities_t::kernel | device_exec_capabilities_t::native_kernel), static_cast<device_exec_capabilities_t>(CL_EXEC_KERNEL | CL_EXEC_NATIVE_KERNEL));
    TS_ASSERT_EQUALS((device_exec_capabilities_t::kernel ^ device_exec_capabilities_t::native_kernel), static_cast<device_exec_capabilities_t>(CL_EXEC_KERNEL ^ CL_EXEC_NATIVE_KERNEL));

    device_exec_capabilities_t x(device_exec_capabilities_t::kernel);

    x |= device_exec_capabilities_t::native_kernel;
    TS_ASSERT_EQUALS(x, static_cast<device_exec_capabilities_t>(CL_EXEC_KERNEL | CL_EXEC_NATIVE_KERNEL));
    x &= ~device_exec_capabilities_t::native_kernel;
    TS_ASSERT_EQUALS(x, static_cast<device_exec_capabilities_t>(CL_EXEC_KERNEL));
    x ^= device_exec_capabilities_t::native_kernel;
    TS_ASSERT_EQUALS(x, static_cast<device_exec_capabilities_t>(CL_EXEC_KERNEL | CL_EXEC_NATIVE_KERNEL));
  }
  /** // doc: test_command_queue_properties_t() {{{
   * \brief Test the command_queue_properties_t type.
   */ // }}}
  void test_command_queue_properties_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<command_queue_properties_t>::type, cl_command_queue_properties>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_command_queue_properties>(command_queue_properties_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_command_queue_properties>(command_queue_properties_t::out_of_order_exec_mode_enable), CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE);
    TS_ASSERT_EQUALS(static_cast<cl_command_queue_properties>(command_queue_properties_t::profiling_enable), CL_QUEUE_PROFILING_ENABLE);
  }
  /** // doc: test_command_queue_properties_t__intval() {{{
   * \brief Test the command_queue_properties_t type with intval().
   */ // }}}
  void test_command_queue_properties_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(command_queue_properties_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(command_queue_properties_t::out_of_order_exec_mode_enable), CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE);
    TS_ASSERT_EQUALS(intval(command_queue_properties_t::profiling_enable), CL_QUEUE_PROFILING_ENABLE);
  }
  /** // doc: test_command_queue_properties_t__bitops() {{{
   * \brief Ensure that bitwise operators work with command_queue_properties_t
   */ // }}}
  void test_command_queue_properties_t__bitops( )
  {
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(command_queue_properties_t::out_of_order_exec_mode_enable), static_cast<command_queue_properties_t>(~CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE));
    TS_ASSERT_EQUALS((command_queue_properties_t::out_of_order_exec_mode_enable & command_queue_properties_t::profiling_enable), static_cast<command_queue_properties_t>(CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE & CL_QUEUE_PROFILING_ENABLE));
    TS_ASSERT_EQUALS((command_queue_properties_t::out_of_order_exec_mode_enable | command_queue_properties_t::profiling_enable), static_cast<command_queue_properties_t>(CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE));
    TS_ASSERT_EQUALS((command_queue_properties_t::out_of_order_exec_mode_enable ^ command_queue_properties_t::profiling_enable), static_cast<command_queue_properties_t>(CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE ^ CL_QUEUE_PROFILING_ENABLE));

    command_queue_properties_t x(command_queue_properties_t::out_of_order_exec_mode_enable);

    x |= command_queue_properties_t::profiling_enable;
    TS_ASSERT_EQUALS(x, static_cast<command_queue_properties_t>(CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE));
    x &= ~command_queue_properties_t::profiling_enable;
    TS_ASSERT_EQUALS(x, static_cast<command_queue_properties_t>(CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE));
    x ^= command_queue_properties_t::profiling_enable;
    TS_ASSERT_EQUALS(x, static_cast<command_queue_properties_t>(CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE));
  }
  /** // doc: test_context_info_t() {{{
   * \brief Test the context_info_t type.
   */ // }}}
  void test_context_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<context_info_t>::type, cl_context_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_context_info>(context_info_t::reference_count), CL_CONTEXT_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_context_info>(context_info_t::devices), CL_CONTEXT_DEVICES);
    TS_ASSERT_EQUALS(static_cast<cl_context_info>(context_info_t::properties), CL_CONTEXT_PROPERTIES);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_context_info>(context_info_t::num_devices), CL_CONTEXT_NUM_DEVICES);
#endif
  }
  /** // doc: test_context_info_t__intval() {{{
   * \brief Test the context_info_t type with intval().
   */ // }}}
  void test_context_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(context_info_t::reference_count), CL_CONTEXT_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(context_info_t::devices), CL_CONTEXT_DEVICES);
    TS_ASSERT_EQUALS(intval(context_info_t::properties), CL_CONTEXT_PROPERTIES);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(context_info_t::num_devices), CL_CONTEXT_NUM_DEVICES);
#endif
  }
  /** // doc: test_context_properties_t() {{{
   * \brief Test the context_properties_t type.
   */ // }}}
  void test_context_properties_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<context_properties_t>::type, cl_context_properties>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::platform), CL_CONTEXT_PLATFORM);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::interop_user_sync), CL_CONTEXT_INTEROP_USER_SYNC);
#endif
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::gl_context_khr), CL_GL_CONTEXT_KHR);
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::egl_display_khr), CL_EGL_DISPLAY_KHR);
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::glx_display_khr), CL_GLX_DISPLAY_KHR);
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::wgl_hdc_khr), CL_WGL_HDC_KHR);
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::cgl_sharegroup_khr), CL_CGL_SHAREGROUP_KHR);
#endif
#if cl_khr_dx9_media_sharing
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::adapter_d3d9_khr), CL_CONTEXT_ADAPTER_D3D9_KHR);
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::adapter_d3d9ex_khr), CL_CONTEXT_ADAPTER_D3D9EX_KHR);
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::adapter_dxva_khr), CL_CONTEXT_ADAPTER_DXVA_KHR);
#endif
#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::d3d10_device_khr), CL_CONTEXT_D3D10_DEVICE_KHR);
#endif
#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(static_cast<cl_context_properties>(context_properties_t::d3d11_device_khr), CL_CONTEXT_D3D11_DEVICE_KHR);
#endif
  }
  /** // doc: test_context_properties_t__intval() {{{
   * \brief Test the context_properties_t type with intval().
   */ // }}}
  void test_context_properties_t__intval( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<context_properties_t>::type, cl_context_properties>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(context_properties_t::platform), CL_CONTEXT_PLATFORM);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(context_properties_t::interop_user_sync), CL_CONTEXT_INTEROP_USER_SYNC);
#endif
#if cl_khr_gl_sharing
    TS_ASSERT_EQUALS(intval(context_properties_t::gl_context_khr), CL_GL_CONTEXT_KHR);
    TS_ASSERT_EQUALS(intval(context_properties_t::egl_display_khr), CL_EGL_DISPLAY_KHR);
    TS_ASSERT_EQUALS(intval(context_properties_t::glx_display_khr), CL_GLX_DISPLAY_KHR);
    TS_ASSERT_EQUALS(intval(context_properties_t::wgl_hdc_khr), CL_WGL_HDC_KHR);
    TS_ASSERT_EQUALS(intval(context_properties_t::cgl_sharegroup_khr), CL_CGL_SHAREGROUP_KHR);
#endif
#if cl_khr_dx9_media_sharing
    TS_ASSERT_EQUALS(intval(context_properties_t::adapter_d3d9_khr), CL_CONTEXT_ADAPTER_D3D9_KHR);
    TS_ASSERT_EQUALS(intval(context_properties_t::adapter_d3d9ex_khr), CL_CONTEXT_ADAPTER_D3D9EX_KHR);
    TS_ASSERT_EQUALS(intval(context_properties_t::adapter_dxva_khr), CL_CONTEXT_ADAPTER_DXVA_KHR);
#endif
#if cl_khr_d3d10_sharing
    TS_ASSERT_EQUALS(intval(context_properties_t::d3d10_device_khr), CL_CONTEXT_D3D10_DEVICE_KHR);
#endif
#if cl_khr_d3d11_sharing
    TS_ASSERT_EQUALS(intval(context_properties_t::d3d11_device_khr), CL_CONTEXT_D3D11_DEVICE_KHR);
#endif
  }
  /** // doc: test_device_partition_property_t() {{{
   * \brief Test the device_partition_property_t type.
   */ // }}}
  void test_device_partition_property_t( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_partition_property_t>::type, cl_device_partition_property>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_partition_property>(device_partition_property_t::equally), CL_DEVICE_PARTITION_EQUALLY);
    TS_ASSERT_EQUALS(static_cast<cl_device_partition_property>(device_partition_property_t::by_counts), CL_DEVICE_PARTITION_BY_COUNTS);
    TS_ASSERT_EQUALS(static_cast<cl_device_partition_property>(device_partition_property_t::by_counts_list_end), CL_DEVICE_PARTITION_BY_COUNTS_LIST_END);
    TS_ASSERT_EQUALS(static_cast<cl_device_partition_property>(device_partition_property_t::by_affinity_domain), CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN);
#endif
  }
  /** // doc: test_device_partition_property_t__intval() {{{
   * \brief Test the device_partition_property_t type with intval().
   */ // }}}
  void test_device_partition_property_t__intval( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_partition_property_t::equally), CL_DEVICE_PARTITION_EQUALLY);
    TS_ASSERT_EQUALS(intval(device_partition_property_t::by_counts), CL_DEVICE_PARTITION_BY_COUNTS);
    TS_ASSERT_EQUALS(intval(device_partition_property_t::by_counts_list_end), CL_DEVICE_PARTITION_BY_COUNTS_LIST_END);
    TS_ASSERT_EQUALS(intval(device_partition_property_t::by_affinity_domain), CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN);
#endif
  }
  /** // doc: test_device_affinity_domain_t() {{{
   * \brief Test the device_affinity_domain_t type.
   */ // }}}
  void test_device_affinity_domain_t( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<device_affinity_domain_t>::type, cl_device_affinity_domain>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_device_affinity_domain>(device_affinity_domain_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_device_affinity_domain>(device_affinity_domain_t::numa), CL_DEVICE_AFFINITY_DOMAIN_NUMA);
    TS_ASSERT_EQUALS(static_cast<cl_device_affinity_domain>(device_affinity_domain_t::l4_cache), CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE);
    TS_ASSERT_EQUALS(static_cast<cl_device_affinity_domain>(device_affinity_domain_t::l3_cache), CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE);
    TS_ASSERT_EQUALS(static_cast<cl_device_affinity_domain>(device_affinity_domain_t::l2_cache), CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE);
    TS_ASSERT_EQUALS(static_cast<cl_device_affinity_domain>(device_affinity_domain_t::l1_cache), CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE);
    TS_ASSERT_EQUALS(static_cast<cl_device_affinity_domain>(device_affinity_domain_t::next_partitionable), CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE);
#endif
  }
  /** // doc: test_device_affinity_domain_t__intval() {{{
   * \brief Test the device_affinity_domain_t type with intval().
   */ // }}}
  void test_device_affinity_domain_t__intval( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(device_affinity_domain_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(device_affinity_domain_t::numa), CL_DEVICE_AFFINITY_DOMAIN_NUMA);
    TS_ASSERT_EQUALS(intval(device_affinity_domain_t::l4_cache), CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE);
    TS_ASSERT_EQUALS(intval(device_affinity_domain_t::l3_cache), CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE);
    TS_ASSERT_EQUALS(intval(device_affinity_domain_t::l2_cache), CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE);
    TS_ASSERT_EQUALS(intval(device_affinity_domain_t::l1_cache), CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE);
    TS_ASSERT_EQUALS(intval(device_affinity_domain_t::next_partitionable), CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE);
#endif
  }
  /** // doc: test_device_affinity_domain_t__bitops() {{{
   * \brief Ensure that bitwise operators work with device_affinity_domain_t
   */ // }}}
  void test_device_affinity_domain_t__bitops( )
  {
#if CLXX_CL_H_VERSION_1_2
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(device_affinity_domain_t::numa), static_cast<device_affinity_domain_t>(~CL_DEVICE_AFFINITY_DOMAIN_NUMA));
    TS_ASSERT_EQUALS((device_affinity_domain_t::numa & device_affinity_domain_t::l4_cache), static_cast<device_affinity_domain_t>(CL_DEVICE_AFFINITY_DOMAIN_NUMA & CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE));
    TS_ASSERT_EQUALS((device_affinity_domain_t::numa | device_affinity_domain_t::l4_cache), static_cast<device_affinity_domain_t>(CL_DEVICE_AFFINITY_DOMAIN_NUMA | CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE));
    TS_ASSERT_EQUALS((device_affinity_domain_t::numa ^ device_affinity_domain_t::l4_cache), static_cast<device_affinity_domain_t>(CL_DEVICE_AFFINITY_DOMAIN_NUMA ^ CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE));

    device_affinity_domain_t x(device_affinity_domain_t::numa);

    x |= device_affinity_domain_t::l4_cache;
    TS_ASSERT_EQUALS(x, static_cast<device_affinity_domain_t>(CL_DEVICE_AFFINITY_DOMAIN_NUMA | CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE));
    x &= ~device_affinity_domain_t::l4_cache;
    TS_ASSERT_EQUALS(x, static_cast<device_affinity_domain_t>(CL_DEVICE_AFFINITY_DOMAIN_NUMA));
    x ^= device_affinity_domain_t::l4_cache;
    TS_ASSERT_EQUALS(x, static_cast<device_affinity_domain_t>(CL_DEVICE_AFFINITY_DOMAIN_NUMA | CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE));
#endif
  }
  /** // doc: test_command_queue_info_t() {{{
   * \brief Test the command_queue_info_t type.
   */ // }}}
  void test_command_queue_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<command_queue_info_t>::type, cl_command_queue_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_command_queue_info>(command_queue_info_t::context), CL_QUEUE_CONTEXT);
    TS_ASSERT_EQUALS(static_cast<cl_command_queue_info>(command_queue_info_t::device), CL_QUEUE_DEVICE);
    TS_ASSERT_EQUALS(static_cast<cl_command_queue_info>(command_queue_info_t::reference_count), CL_QUEUE_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_command_queue_info>(command_queue_info_t::properties), CL_QUEUE_PROPERTIES);
  }
  /** // doc: test_command_queue_info_t__intval() {{{
   * \brief Test the command_queue_info_t type with intval().
   */ // }}}
  void test_command_queue_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(command_queue_info_t::context), CL_QUEUE_CONTEXT);
    TS_ASSERT_EQUALS(intval(command_queue_info_t::device), CL_QUEUE_DEVICE);
    TS_ASSERT_EQUALS(intval(command_queue_info_t::reference_count), CL_QUEUE_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(command_queue_info_t::properties), CL_QUEUE_PROPERTIES);
  }
  /** // doc: test_mem_flags_t() {{{
   * \brief Test the mem_flags_t type.
   */ // }}}
  void test_mem_flags_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<mem_flags_t>::type, cl_mem_flags>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::read_write), CL_MEM_READ_WRITE);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::write_only), CL_MEM_WRITE_ONLY);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::read_only), CL_MEM_READ_ONLY);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::use_host_ptr), CL_MEM_USE_HOST_PTR);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::alloc_host_ptr), CL_MEM_ALLOC_HOST_PTR);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::copy_host_ptr), CL_MEM_COPY_HOST_PTR);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::host_write_only), CL_MEM_HOST_WRITE_ONLY);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::host_read_only), CL_MEM_HOST_READ_ONLY);
    TS_ASSERT_EQUALS(static_cast<cl_mem_flags>(mem_flags_t::host_no_access), CL_MEM_HOST_NO_ACCESS);
#endif
  }
  /** // doc: test_mem_flags_t__intval() {{{
   * \brief Test the mem_flags_t type with intval().
   */ // }}}
  void test_mem_flags_t__intvall( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(mem_flags_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(mem_flags_t::read_write), CL_MEM_READ_WRITE);
    TS_ASSERT_EQUALS(intval(mem_flags_t::write_only), CL_MEM_WRITE_ONLY);
    TS_ASSERT_EQUALS(intval(mem_flags_t::read_only), CL_MEM_READ_ONLY);
    TS_ASSERT_EQUALS(intval(mem_flags_t::use_host_ptr), CL_MEM_USE_HOST_PTR);
    TS_ASSERT_EQUALS(intval(mem_flags_t::alloc_host_ptr), CL_MEM_ALLOC_HOST_PTR);
    TS_ASSERT_EQUALS(intval(mem_flags_t::copy_host_ptr), CL_MEM_COPY_HOST_PTR);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(mem_flags_t::host_write_only), CL_MEM_HOST_WRITE_ONLY);
    TS_ASSERT_EQUALS(intval(mem_flags_t::host_read_only), CL_MEM_HOST_READ_ONLY);
    TS_ASSERT_EQUALS(intval(mem_flags_t::host_no_access), CL_MEM_HOST_NO_ACCESS);
#endif
  }
  /** // doc: test_mem_flags_t__bitops() {{{
   * \brief Ensure that bitwise operators work with mem_flags_t
   */ // }}}
  void test_mem_flags_t__bitops( )
  {
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(mem_flags_t::read_write), static_cast<mem_flags_t>(~CL_MEM_READ_WRITE));
    TS_ASSERT_EQUALS((mem_flags_t::read_write & mem_flags_t::read_only), static_cast<mem_flags_t>(CL_MEM_READ_WRITE & CL_MEM_READ_ONLY));
    TS_ASSERT_EQUALS((mem_flags_t::read_write | mem_flags_t::read_only), static_cast<mem_flags_t>(CL_MEM_READ_WRITE | CL_MEM_READ_ONLY));
    TS_ASSERT_EQUALS((mem_flags_t::read_write ^ mem_flags_t::read_only), static_cast<mem_flags_t>(CL_MEM_READ_WRITE ^ CL_MEM_READ_ONLY));

    mem_flags_t x(mem_flags_t::read_write);

    x |= mem_flags_t::read_only;
    TS_ASSERT_EQUALS(x, static_cast<mem_flags_t>(CL_MEM_READ_WRITE | CL_MEM_READ_ONLY));
    x &= ~mem_flags_t::read_only;
    TS_ASSERT_EQUALS(x, static_cast<mem_flags_t>(CL_MEM_READ_WRITE));
    x ^= mem_flags_t::read_only;
    TS_ASSERT_EQUALS(x, static_cast<mem_flags_t>(CL_MEM_READ_WRITE | CL_MEM_READ_ONLY));
  }
  /** // doc: test_mem_migration_flags_t() {{{
   * \brief Test the mem_migration_flags_t type.
   */ // }}}
  void test_mem_migration_flags_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<mem_migration_flags_t>::type, cl_mem_migration_flags>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_mem_migration_flags>(mem_migration_flags_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_mem_migration_flags>(mem_migration_flags_t::mem_object_host), CL_MIGRATE_MEM_OBJECT_HOST);
    TS_ASSERT_EQUALS(static_cast<cl_mem_migration_flags>(mem_migration_flags_t::mem_object_content_undefined), CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED);
  }
  /** // doc: test_mem_migration_flags_t__intval() {{{
   * \brief Test the mem_migration_flags_t type with intval().
   */ // }}}
  void test_mem_migration_flags_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(mem_migration_flags_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(mem_migration_flags_t::mem_object_host), CL_MIGRATE_MEM_OBJECT_HOST);
    TS_ASSERT_EQUALS(intval(mem_migration_flags_t::mem_object_content_undefined), CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED);
  }
  /** // doc: test_mem_migration_flags_t__bitops() {{{
   * \brief Ensure that bitwise operators work with mem_migration_flags_t
   */ // }}}
  void test_mem_migration_flags_t__bitops( )
  {
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(mem_migration_flags_t::mem_object_host), static_cast<mem_migration_flags_t>(~CL_MIGRATE_MEM_OBJECT_HOST));
    TS_ASSERT_EQUALS((mem_migration_flags_t::mem_object_host & mem_migration_flags_t::mem_object_content_undefined), static_cast<mem_migration_flags_t>(CL_MIGRATE_MEM_OBJECT_HOST & CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED));
    TS_ASSERT_EQUALS((mem_migration_flags_t::mem_object_host | mem_migration_flags_t::mem_object_content_undefined), static_cast<mem_migration_flags_t>(CL_MIGRATE_MEM_OBJECT_HOST | CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED));
    TS_ASSERT_EQUALS((mem_migration_flags_t::mem_object_host ^ mem_migration_flags_t::mem_object_content_undefined), static_cast<mem_migration_flags_t>(CL_MIGRATE_MEM_OBJECT_HOST ^ CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED));

    mem_migration_flags_t x(mem_migration_flags_t::mem_object_host);

    x |= mem_migration_flags_t::mem_object_content_undefined;
    TS_ASSERT_EQUALS(x, static_cast<mem_migration_flags_t>(CL_MIGRATE_MEM_OBJECT_HOST | CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED));
    x &= ~mem_migration_flags_t::mem_object_content_undefined;
    TS_ASSERT_EQUALS(x, static_cast<mem_migration_flags_t>(CL_MIGRATE_MEM_OBJECT_HOST));
    x ^= mem_migration_flags_t::mem_object_content_undefined;
    TS_ASSERT_EQUALS(x, static_cast<mem_migration_flags_t>(CL_MIGRATE_MEM_OBJECT_HOST | CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED));
  }
  /** // doc: test_channel_order_t() {{{
   * \brief Test the channel_order_t type.
   */ // }}}
  void test_channel_order_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<channel_order_t>::type, cl_channel_order>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::r), CL_R);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::a), CL_A);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::rg), CL_RG);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::ra), CL_RA);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::rgb), CL_RGB);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::rgba), CL_RGBA);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::bgra), CL_BGRA);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::argb), CL_ARGB);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::intensity), CL_INTENSITY);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::luminance), CL_LUMINANCE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::rx), CL_Rx);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::rgx), CL_RGx);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::rgbx), CL_RGBx);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::depth), CL_DEPTH);
    TS_ASSERT_EQUALS(static_cast<cl_channel_order>(channel_order_t::depth_stencil), CL_DEPTH_STENCIL);
#endif
  }
  /** // doc: test_channel_order_t__intval() {{{
   * \brief Test the channel_order_t type with intval().
   */ // }}}
  void test_channel_order_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(channel_order_t::r), CL_R);
    TS_ASSERT_EQUALS(intval(channel_order_t::a), CL_A);
    TS_ASSERT_EQUALS(intval(channel_order_t::rg), CL_RG);
    TS_ASSERT_EQUALS(intval(channel_order_t::ra), CL_RA);
    TS_ASSERT_EQUALS(intval(channel_order_t::rgb), CL_RGB);
    TS_ASSERT_EQUALS(intval(channel_order_t::rgba), CL_RGBA);
    TS_ASSERT_EQUALS(intval(channel_order_t::bgra), CL_BGRA);
    TS_ASSERT_EQUALS(intval(channel_order_t::argb), CL_ARGB);
    TS_ASSERT_EQUALS(intval(channel_order_t::intensity), CL_INTENSITY);
    TS_ASSERT_EQUALS(intval(channel_order_t::luminance), CL_LUMINANCE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(channel_order_t::rx), CL_Rx);
    TS_ASSERT_EQUALS(intval(channel_order_t::rgx), CL_RGx);
    TS_ASSERT_EQUALS(intval(channel_order_t::rgbx), CL_RGBx);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(channel_order_t::depth), CL_DEPTH);
    TS_ASSERT_EQUALS(intval(channel_order_t::depth_stencil), CL_DEPTH_STENCIL);
#endif
  }
  /** // doc: test_channel_type_t() {{{
   * \brief Test the channel_type_t type.
   */ // }}}
  void test_channel_type_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<channel_type_t>::type, cl_channel_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::snorm_int8), CL_SNORM_INT8);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::snorm_int16), CL_SNORM_INT16);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unorm_int8), CL_UNORM_INT8);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unorm_int16), CL_UNORM_INT16);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unorm_short_565), CL_UNORM_SHORT_565);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unorm_short_555), CL_UNORM_SHORT_555);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unorm_int_101010), CL_UNORM_INT_101010);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::signed_int8), CL_SIGNED_INT8);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::signed_int16), CL_SIGNED_INT16);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::signed_int32), CL_SIGNED_INT32);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unsigned_int8), CL_UNSIGNED_INT8);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unsigned_int16), CL_UNSIGNED_INT16);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unsigned_int32), CL_UNSIGNED_INT32);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::half_float), CL_HALF_FLOAT);
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::float_), CL_FLOAT);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_channel_type>(channel_type_t::unorm_int24), CL_UNORM_INT24);
#endif
  }
  /** // doc: test_channel_type_t__intval() {{{
   * \brief Test the channel_type_t type with intval().
   */ // }}}
  void test_channel_type_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(channel_type_t::snorm_int8), CL_SNORM_INT8);
    TS_ASSERT_EQUALS(intval(channel_type_t::snorm_int16), CL_SNORM_INT16);
    TS_ASSERT_EQUALS(intval(channel_type_t::unorm_int8), CL_UNORM_INT8);
    TS_ASSERT_EQUALS(intval(channel_type_t::unorm_int16), CL_UNORM_INT16);
    TS_ASSERT_EQUALS(intval(channel_type_t::unorm_short_565), CL_UNORM_SHORT_565);
    TS_ASSERT_EQUALS(intval(channel_type_t::unorm_short_555), CL_UNORM_SHORT_555);
    TS_ASSERT_EQUALS(intval(channel_type_t::unorm_int_101010), CL_UNORM_INT_101010);
    TS_ASSERT_EQUALS(intval(channel_type_t::signed_int8), CL_SIGNED_INT8);
    TS_ASSERT_EQUALS(intval(channel_type_t::signed_int16), CL_SIGNED_INT16);
    TS_ASSERT_EQUALS(intval(channel_type_t::signed_int32), CL_SIGNED_INT32);
    TS_ASSERT_EQUALS(intval(channel_type_t::unsigned_int8), CL_UNSIGNED_INT8);
    TS_ASSERT_EQUALS(intval(channel_type_t::unsigned_int16), CL_UNSIGNED_INT16);
    TS_ASSERT_EQUALS(intval(channel_type_t::unsigned_int32), CL_UNSIGNED_INT32);
    TS_ASSERT_EQUALS(intval(channel_type_t::half_float), CL_HALF_FLOAT);
    TS_ASSERT_EQUALS(intval(channel_type_t::float_), CL_FLOAT);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(channel_type_t::unorm_int24), CL_UNORM_INT24);
#endif
  }
  /** // doc: test_mem_object_type_t() {{{
   * \brief Test the mem_object_type_t type.
   */ // }}}
  void test_mem_object_type_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<mem_object_type_t>::type, cl_mem_object_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_mem_object_type>(mem_object_type_t::buffer), CL_MEM_OBJECT_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_mem_object_type>(mem_object_type_t::image2d), CL_MEM_OBJECT_IMAGE2D);
    TS_ASSERT_EQUALS(static_cast<cl_mem_object_type>(mem_object_type_t::image3d), CL_MEM_OBJECT_IMAGE3D);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_mem_object_type>(mem_object_type_t::image2d_array), CL_MEM_OBJECT_IMAGE2D_ARRAY);
    TS_ASSERT_EQUALS(static_cast<cl_mem_object_type>(mem_object_type_t::image1d), CL_MEM_OBJECT_IMAGE1D);
    TS_ASSERT_EQUALS(static_cast<cl_mem_object_type>(mem_object_type_t::image1d_array), CL_MEM_OBJECT_IMAGE1D_ARRAY);
    TS_ASSERT_EQUALS(static_cast<cl_mem_object_type>(mem_object_type_t::image1d_buffer), CL_MEM_OBJECT_IMAGE1D_BUFFER);
#endif
  }
  /** // doc: test_mem_object_type_t__intval() {{{
   * \brief Test the mem_object_type_t type with intval().
   */ // }}}
  void test_mem_object_type_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(mem_object_type_t::buffer), CL_MEM_OBJECT_BUFFER);
    TS_ASSERT_EQUALS(intval(mem_object_type_t::image2d), CL_MEM_OBJECT_IMAGE2D);
    TS_ASSERT_EQUALS(intval(mem_object_type_t::image3d), CL_MEM_OBJECT_IMAGE3D);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(mem_object_type_t::image2d_array), CL_MEM_OBJECT_IMAGE2D_ARRAY);
    TS_ASSERT_EQUALS(intval(mem_object_type_t::image1d), CL_MEM_OBJECT_IMAGE1D);
    TS_ASSERT_EQUALS(intval(mem_object_type_t::image1d_array), CL_MEM_OBJECT_IMAGE1D_ARRAY);
    TS_ASSERT_EQUALS(intval(mem_object_type_t::image1d_buffer), CL_MEM_OBJECT_IMAGE1D_BUFFER);
#endif
  }
  /** // doc: test_mem_info_t() {{{
   * \brief Test the mem_info_t type.
   */ // }}}
  void test_mem_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<mem_info_t>::type, cl_mem_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::type), CL_MEM_TYPE);
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::flags), CL_MEM_FLAGS);
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::size), CL_MEM_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::host_ptr), CL_MEM_HOST_PTR);
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::map_count), CL_MEM_MAP_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::reference_count), CL_MEM_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::context), CL_MEM_CONTEXT);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::associated_memobject), CL_MEM_ASSOCIATED_MEMOBJECT);
    TS_ASSERT_EQUALS(static_cast<cl_mem_info>(mem_info_t::offset), CL_MEM_OFFSET);
#endif
  }
  /** // doc: test_mem_info_t__intval() {{{
   * \brief Test the mem_info_t type with intval().
   */ // }}}
  void test_mem_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(mem_info_t::type), CL_MEM_TYPE);
    TS_ASSERT_EQUALS(intval(mem_info_t::flags), CL_MEM_FLAGS);
    TS_ASSERT_EQUALS(intval(mem_info_t::size), CL_MEM_SIZE);
    TS_ASSERT_EQUALS(intval(mem_info_t::host_ptr), CL_MEM_HOST_PTR);
    TS_ASSERT_EQUALS(intval(mem_info_t::map_count), CL_MEM_MAP_COUNT);
    TS_ASSERT_EQUALS(intval(mem_info_t::reference_count), CL_MEM_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(mem_info_t::context), CL_MEM_CONTEXT);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(mem_info_t::associated_memobject), CL_MEM_ASSOCIATED_MEMOBJECT);
    TS_ASSERT_EQUALS(intval(mem_info_t::offset), CL_MEM_OFFSET);
#endif
  }
  /** // doc: test_image_info_t() {{{
   * \brief Test the image_info_t type.
   */ // }}}
  void test_image_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<image_info_t>::type, cl_image_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::format), CL_IMAGE_FORMAT);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::element_size), CL_IMAGE_ELEMENT_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::row_pitch), CL_IMAGE_ROW_PITCH);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::slice_pitch), CL_IMAGE_SLICE_PITCH);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::width), CL_IMAGE_WIDTH);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::height), CL_IMAGE_HEIGHT);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::depth), CL_IMAGE_DEPTH);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::array_size), CL_IMAGE_ARRAY_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::buffer), CL_IMAGE_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::num_mip_levels), CL_IMAGE_NUM_MIP_LEVELS);
    TS_ASSERT_EQUALS(static_cast<cl_image_info>(image_info_t::num_samples), CL_IMAGE_NUM_SAMPLES);
#endif
  }
  /** // doc: test_image_info_t__intval() {{{
   * \brief Test the image_info_t type with intval().
   */ // }}}
  void test_image_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(image_info_t::format), CL_IMAGE_FORMAT);
    TS_ASSERT_EQUALS(intval(image_info_t::element_size), CL_IMAGE_ELEMENT_SIZE);
    TS_ASSERT_EQUALS(intval(image_info_t::row_pitch), CL_IMAGE_ROW_PITCH);
    TS_ASSERT_EQUALS(intval(image_info_t::slice_pitch), CL_IMAGE_SLICE_PITCH);
    TS_ASSERT_EQUALS(intval(image_info_t::width), CL_IMAGE_WIDTH);
    TS_ASSERT_EQUALS(intval(image_info_t::height), CL_IMAGE_HEIGHT);
    TS_ASSERT_EQUALS(intval(image_info_t::depth), CL_IMAGE_DEPTH);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(image_info_t::array_size), CL_IMAGE_ARRAY_SIZE);
    TS_ASSERT_EQUALS(intval(image_info_t::buffer), CL_IMAGE_BUFFER);
    TS_ASSERT_EQUALS(intval(image_info_t::num_mip_levels), CL_IMAGE_NUM_MIP_LEVELS);
    TS_ASSERT_EQUALS(intval(image_info_t::num_samples), CL_IMAGE_NUM_SAMPLES);
#endif
  }
  /** // doc: test_addressing_mode_t() {{{
   * \brief Test the addressing_mode_t type.
   */ // }}}
  void test_addressing_mode_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<addressing_mode_t>::type, cl_addressing_mode>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_addressing_mode>(addressing_mode_t::none), CL_ADDRESS_NONE);
    TS_ASSERT_EQUALS(static_cast<cl_addressing_mode>(addressing_mode_t::clamp_to_edge), CL_ADDRESS_CLAMP_TO_EDGE);
    TS_ASSERT_EQUALS(static_cast<cl_addressing_mode>(addressing_mode_t::clamp), CL_ADDRESS_CLAMP);
    TS_ASSERT_EQUALS(static_cast<cl_addressing_mode>(addressing_mode_t::repeat), CL_ADDRESS_REPEAT);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_addressing_mode>(addressing_mode_t::mirrored_repeat), CL_ADDRESS_MIRRORED_REPEAT);
#endif
  }
  /** // doc: test_addressing_mode_t__intval() {{{
   * \brief Test the addressing_mode_t type with intval().
   */ // }}}
  void test_addressing_mode_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(addressing_mode_t::none), CL_ADDRESS_NONE);
    TS_ASSERT_EQUALS(intval(addressing_mode_t::clamp_to_edge), CL_ADDRESS_CLAMP_TO_EDGE);
    TS_ASSERT_EQUALS(intval(addressing_mode_t::clamp), CL_ADDRESS_CLAMP);
    TS_ASSERT_EQUALS(intval(addressing_mode_t::repeat), CL_ADDRESS_REPEAT);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(addressing_mode_t::mirrored_repeat), CL_ADDRESS_MIRRORED_REPEAT);
#endif
  }
  /** // doc: test_filter_mode_t() {{{
   * \brief Test the filter_mode_t type.
   */ // }}}
  void test_filter_mode_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<filter_mode_t>::type, cl_filter_mode>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_filter_mode>(filter_mode_t::nearest), CL_FILTER_NEAREST);
    TS_ASSERT_EQUALS(static_cast<cl_filter_mode>(filter_mode_t::linear), CL_FILTER_LINEAR);
  }
  /** // doc: test_filter_mode_t__intval() {{{
   * \brief Test the filter_mode_t type with intval().
   */ // }}}
  void test_filter_mode_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(filter_mode_t::nearest), CL_FILTER_NEAREST);
    TS_ASSERT_EQUALS(intval(filter_mode_t::linear), CL_FILTER_LINEAR);
  }
  /** // doc: test_sampler_info_t() {{{
   * \brief Test the sampler_info_t type.
   */ // }}}
  void test_sampler_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<sampler_info_t>::type, cl_sampler_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_sampler_info>(sampler_info_t::reference_count), CL_SAMPLER_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_sampler_info>(sampler_info_t::context), CL_SAMPLER_CONTEXT);
    TS_ASSERT_EQUALS(static_cast<cl_sampler_info>(sampler_info_t::normalized_coords), CL_SAMPLER_NORMALIZED_COORDS);
    TS_ASSERT_EQUALS(static_cast<cl_sampler_info>(sampler_info_t::addressing_mode), CL_SAMPLER_ADDRESSING_MODE);
    TS_ASSERT_EQUALS(static_cast<cl_sampler_info>(sampler_info_t::filter_mode), CL_SAMPLER_FILTER_MODE);
  }
  /** // doc: test_sampler_info_t__intval() {{{
   * \brief Test the sampler_info_t type with intval().
   */ // }}}
  void test_sampler_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(sampler_info_t::reference_count), CL_SAMPLER_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(sampler_info_t::context), CL_SAMPLER_CONTEXT);
    TS_ASSERT_EQUALS(intval(sampler_info_t::normalized_coords), CL_SAMPLER_NORMALIZED_COORDS);
    TS_ASSERT_EQUALS(intval(sampler_info_t::addressing_mode), CL_SAMPLER_ADDRESSING_MODE);
    TS_ASSERT_EQUALS(intval(sampler_info_t::filter_mode), CL_SAMPLER_FILTER_MODE);
  }
  /** // doc: test_map_flags_t() {{{
   * \brief Test the map_flags_t type.
   */ // }}}
  void test_map_flags_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<map_flags_t>::type, cl_map_flags>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_map_flags>(map_flags_t::none), 0ul);
    TS_ASSERT_EQUALS(static_cast<cl_map_flags>(map_flags_t::read), CL_MAP_READ);
    TS_ASSERT_EQUALS(static_cast<cl_map_flags>(map_flags_t::write), CL_MAP_WRITE);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_map_flags>(map_flags_t::write_invalidate_region), CL_MAP_WRITE_INVALIDATE_REGION);
#endif
  }
  /** // doc: test_map_flags_t__intval() {{{
   * \brief Test the map_flags_t type with intval().
   */ // }}}
  void test_map_flags_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(map_flags_t::none), 0ul);
    TS_ASSERT_EQUALS(intval(map_flags_t::read), CL_MAP_READ);
    TS_ASSERT_EQUALS(intval(map_flags_t::write), CL_MAP_WRITE);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(map_flags_t::write_invalidate_region), CL_MAP_WRITE_INVALIDATE_REGION);
#endif
  }
  /** // doc: test_map_flags_t__bitops() {{{
   * \brief Ensure that bitwise operators work with map_flags_t
   */ // }}}
  void test_map_flags_t__bitops( )
  {
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(map_flags_t::read), static_cast<map_flags_t>(~CL_MAP_READ));
    TS_ASSERT_EQUALS((map_flags_t::read & map_flags_t::write), static_cast<map_flags_t>(CL_MAP_READ & CL_MAP_WRITE));
    TS_ASSERT_EQUALS((map_flags_t::read | map_flags_t::write), static_cast<map_flags_t>(CL_MAP_READ | CL_MAP_WRITE));
    TS_ASSERT_EQUALS((map_flags_t::read ^ map_flags_t::write), static_cast<map_flags_t>(CL_MAP_READ ^ CL_MAP_WRITE));

    map_flags_t x(map_flags_t::read);

    x |= map_flags_t::write;
    TS_ASSERT_EQUALS(x, static_cast<map_flags_t>(CL_MAP_READ | CL_MAP_WRITE));
    x &= ~map_flags_t::write;
    TS_ASSERT_EQUALS(x, static_cast<map_flags_t>(CL_MAP_READ));
    x ^= map_flags_t::write;
    TS_ASSERT_EQUALS(x, static_cast<map_flags_t>(CL_MAP_READ | CL_MAP_WRITE));
  }
  /** // doc: test_program_info_t() {{{
   * \brief Test the program_info_t type.
   */ // }}}
  void test_program_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<program_info_t>::type, cl_program_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::reference_count), CL_PROGRAM_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::context), CL_PROGRAM_CONTEXT);
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::num_devices), CL_PROGRAM_NUM_DEVICES);
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::devices), CL_PROGRAM_DEVICES);
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::source), CL_PROGRAM_SOURCE);
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::binary_sizes), CL_PROGRAM_BINARY_SIZES);
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::binaries), CL_PROGRAM_BINARIES);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::num_kernels), CL_PROGRAM_NUM_KERNELS);
    TS_ASSERT_EQUALS(static_cast<cl_program_info>(program_info_t::kernel_names), CL_PROGRAM_KERNEL_NAMES);
#endif
  }
  /** // doc: test_program_info_t__intval() {{{
   * \brief Test the program_info_t type with intval().
   */ // }}}
  void test_program_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(program_info_t::reference_count), CL_PROGRAM_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(program_info_t::context), CL_PROGRAM_CONTEXT);
    TS_ASSERT_EQUALS(intval(program_info_t::num_devices), CL_PROGRAM_NUM_DEVICES);
    TS_ASSERT_EQUALS(intval(program_info_t::devices), CL_PROGRAM_DEVICES);
    TS_ASSERT_EQUALS(intval(program_info_t::source), CL_PROGRAM_SOURCE);
    TS_ASSERT_EQUALS(intval(program_info_t::binary_sizes), CL_PROGRAM_BINARY_SIZES);
    TS_ASSERT_EQUALS(intval(program_info_t::binaries), CL_PROGRAM_BINARIES);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(program_info_t::num_kernels), CL_PROGRAM_NUM_KERNELS);
    TS_ASSERT_EQUALS(intval(program_info_t::kernel_names), CL_PROGRAM_KERNEL_NAMES);
#endif
  }
  /** // doc: test_program_build_info_t() {{{
   * \brief Test the program_build_info_t type.
   */ // }}}
  void test_program_build_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<program_build_info_t>::type, cl_program_build_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_program_build_info>(program_build_info_t::status), CL_PROGRAM_BUILD_STATUS);
    TS_ASSERT_EQUALS(static_cast<cl_program_build_info>(program_build_info_t::options), CL_PROGRAM_BUILD_OPTIONS);
    TS_ASSERT_EQUALS(static_cast<cl_program_build_info>(program_build_info_t::log), CL_PROGRAM_BUILD_LOG);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_program_build_info>(program_build_info_t::binary_type), CL_PROGRAM_BINARY_TYPE);
#endif
  }
  /** // doc: test_program_build_info_t__intval() {{{
   * \brief Test the program_build_info_t type with intval().
   */ // }}}
  void test_program_build_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(program_build_info_t::status), CL_PROGRAM_BUILD_STATUS);
    TS_ASSERT_EQUALS(intval(program_build_info_t::options), CL_PROGRAM_BUILD_OPTIONS);
    TS_ASSERT_EQUALS(intval(program_build_info_t::log), CL_PROGRAM_BUILD_LOG);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(program_build_info_t::binary_type), CL_PROGRAM_BINARY_TYPE);
#endif
  }
  /** // doc: test_program_binary_type_t() {{{
   * \brief Test the program_binary_type_t type.
   */ // }}}
  void test_program_binary_type_t( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<program_binary_type_t>::type, cl_program_binary_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_program_binary_type>(program_binary_type_t::none), CL_PROGRAM_BINARY_TYPE_NONE);
    TS_ASSERT_EQUALS(static_cast<cl_program_binary_type>(program_binary_type_t::compiled_object), CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT);
    TS_ASSERT_EQUALS(static_cast<cl_program_binary_type>(program_binary_type_t::library), CL_PROGRAM_BINARY_TYPE_LIBRARY);
    TS_ASSERT_EQUALS(static_cast<cl_program_binary_type>(program_binary_type_t::executable), CL_PROGRAM_BINARY_TYPE_EXECUTABLE);
#endif
  }
  /** // doc: test_program_binary_type_t__intval() {{{
   * \brief Test the program_binary_type_t type with intval().
   */ // }}}
  void test_program_binary_type_t__intval( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(program_binary_type_t::none), CL_PROGRAM_BINARY_TYPE_NONE);
    TS_ASSERT_EQUALS(intval(program_binary_type_t::compiled_object), CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT);
    TS_ASSERT_EQUALS(intval(program_binary_type_t::library), CL_PROGRAM_BINARY_TYPE_LIBRARY);
    TS_ASSERT_EQUALS(intval(program_binary_type_t::executable), CL_PROGRAM_BINARY_TYPE_EXECUTABLE);
#endif
  }
  /** // doc: test_program_binary_type_t__bitops() {{{
   * \brief Ensure that bitwise operators work for program_binary_type_t
   */ // }}}
  void test_program_binary_type_t__bitops( )
  {
#if CLXX_CL_H_VERSION_1_2
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(program_binary_type_t::none), static_cast<program_binary_type_t>(~CL_PROGRAM_BINARY_TYPE_NONE));
    TS_ASSERT_EQUALS((program_binary_type_t::none & program_binary_type_t::compiled_object), program_binary_type_t::none);
    TS_ASSERT_EQUALS((program_binary_type_t::none | program_binary_type_t::compiled_object), program_binary_type_t::compiled_object);
    TS_ASSERT_EQUALS((program_binary_type_t::none ^ program_binary_type_t::compiled_object), static_cast<program_binary_type_t>(CL_PROGRAM_BINARY_TYPE_NONE ^ CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT));

    program_binary_type_t x(program_binary_type_t::none);

    x |= program_binary_type_t::compiled_object;
    TS_ASSERT_EQUALS(x, program_binary_type_t::compiled_object);
    x &= ~program_binary_type_t::compiled_object;
    TS_ASSERT_EQUALS(x, program_binary_type_t::none);
    x ^= program_binary_type_t::library;
    TS_ASSERT_EQUALS(x, program_binary_type_t::library);
#endif
  }
  /** // doc: test_build_status_t() {{{
   * \brief Test the build_status_t type.
   */ // }}}
  void test_build_status_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<build_status_t>::type, cl_build_status>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_build_status>(build_status_t::success), CL_BUILD_SUCCESS);
    TS_ASSERT_EQUALS(static_cast<cl_build_status>(build_status_t::none), CL_BUILD_NONE);
    TS_ASSERT_EQUALS(static_cast<cl_build_status>(build_status_t::error), CL_BUILD_ERROR);
    TS_ASSERT_EQUALS(static_cast<cl_build_status>(build_status_t::in_progress), CL_BUILD_IN_PROGRESS);
  }
  /** // doc: test_build_status_t__intval() {{{
   * \brief Test the build_status_t type with intval().
   */ // }}}
  void test_build_status_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(build_status_t::success), CL_BUILD_SUCCESS);
    TS_ASSERT_EQUALS(intval(build_status_t::none), CL_BUILD_NONE);
    TS_ASSERT_EQUALS(intval(build_status_t::error), CL_BUILD_ERROR);
    TS_ASSERT_EQUALS(intval(build_status_t::in_progress), CL_BUILD_IN_PROGRESS);
  }
  /** // doc: test_build_status_t__is_success() {{{
   * \brief Ensure that is_success() works with build_status_t.
   */ // }}}
  void test_build_status_t__is_success( )
  {
    TS_ASSERT(is_success(build_status_t::success));
    TS_ASSERT(!is_success(build_status_t::none));
    TS_ASSERT(!is_success(build_status_t::error));
    TS_ASSERT(!is_success(build_status_t::in_progress));
  }
  /** // doc: test_build_status_t__is_error() {{{
   * \brief Ensure that is_error() works with build_status_t.
   */ // }}}
  void test_build_status_t__is_error( )
  {
    TS_ASSERT(!is_error(build_status_t::success));
    TS_ASSERT(is_error(build_status_t::none));
    TS_ASSERT(is_error(build_status_t::error));
    TS_ASSERT(is_error(build_status_t::in_progress));
  }
  /** // doc: test_kernel_info_t() {{{
   * \brief Test the kernel_info_t type.
   */ // }}}
  void test_kernel_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<kernel_info_t>::type, cl_kernel_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_kernel_info>(kernel_info_t::function_name), CL_KERNEL_FUNCTION_NAME);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_info>(kernel_info_t::num_args), CL_KERNEL_NUM_ARGS);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_info>(kernel_info_t::reference_count), CL_KERNEL_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_info>(kernel_info_t::context), CL_KERNEL_CONTEXT);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_info>(kernel_info_t::program), CL_KERNEL_PROGRAM);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_kernel_info>(kernel_info_t::attributes), CL_KERNEL_ATTRIBUTES);
#endif
  }
  /** // doc: test_kernel_info_t__intval() {{{
   * \brief Test the kernel_info_t type with intval().
   */ // }}}
  void test_kernel_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(kernel_info_t::function_name), CL_KERNEL_FUNCTION_NAME);
    TS_ASSERT_EQUALS(intval(kernel_info_t::num_args), CL_KERNEL_NUM_ARGS);
    TS_ASSERT_EQUALS(intval(kernel_info_t::reference_count), CL_KERNEL_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(kernel_info_t::context), CL_KERNEL_CONTEXT);
    TS_ASSERT_EQUALS(intval(kernel_info_t::program), CL_KERNEL_PROGRAM);
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(kernel_info_t::attributes), CL_KERNEL_ATTRIBUTES);
#endif
  }
#if CLXX_CL_H_VERSION_1_2
  /** // doc: test_kernel_arg_info_t() {{{
   * \brief Test the kernel_arg_info_t type.
   */ // }}}
  void test_kernel_arg_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<kernel_arg_info_t>::type, cl_kernel_arg_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_info>(kernel_arg_info_t::address_qualifier), CL_KERNEL_ARG_ADDRESS_QUALIFIER);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_info>(kernel_arg_info_t::access_qualifier), CL_KERNEL_ARG_ACCESS_QUALIFIER);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_info>(kernel_arg_info_t::type_name), CL_KERNEL_ARG_TYPE_NAME);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_info>(kernel_arg_info_t::type_qualifier), CL_KERNEL_ARG_TYPE_QUALIFIER);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_info>(kernel_arg_info_t::name), CL_KERNEL_ARG_NAME);
  }
  /** // doc: test_kernel_arg_info_t__intval() {{{
   * \brief Test the kernel_arg_info_t type with intval().
   */ // }}}
  void test_kernel_arg_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(kernel_arg_info_t::address_qualifier), CL_KERNEL_ARG_ADDRESS_QUALIFIER);
    TS_ASSERT_EQUALS(intval(kernel_arg_info_t::access_qualifier), CL_KERNEL_ARG_ACCESS_QUALIFIER);
    TS_ASSERT_EQUALS(intval(kernel_arg_info_t::type_name), CL_KERNEL_ARG_TYPE_NAME);
    TS_ASSERT_EQUALS(intval(kernel_arg_info_t::type_qualifier), CL_KERNEL_ARG_TYPE_QUALIFIER);
    TS_ASSERT_EQUALS(intval(kernel_arg_info_t::name), CL_KERNEL_ARG_NAME);
  }
#endif
  void test_kernel_exec_info_t( )
  {
#if CLXX_CL_H_VERSION_2_0
    // Check the underlying type
    TS_ASSERT((std::is_same<std::underlying_type<kernel_exec_info_t>::type, cl_kernel_exec_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_kernel_exec_info>(kernel_exec_info_t::svm_ptrs), CL_KERNEL_EXEC_INFO_SVM_PTRS);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_exec_info>(kernel_exec_info_t::svm_fine_grain_system), CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM);
#endif
  }
  void test_kernel_exec_info_t__intval( )
  {
#if CLXX_CL_H_VERSION_2_0
    TS_ASSERT_EQUALS(intval(kernel_exec_info_t::svm_ptrs), CL_KERNEL_EXEC_INFO_SVM_PTRS);
    TS_ASSERT_EQUALS(intval(kernel_exec_info_t::svm_fine_grain_system), CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM);
#endif
  }
  /** // doc: test_kernel_arg_address_qualifier_t() {{{
   * \brief Test the kernel_arg_address_qualifier_t type.
   */ // }}}
  void test_kernel_arg_address_qualifier_t( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<kernel_arg_address_qualifier_t>::type, cl_kernel_arg_address_qualifier>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_address_qualifier>(kernel_arg_address_qualifier_t::global), CL_KERNEL_ARG_ADDRESS_GLOBAL);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_address_qualifier>(kernel_arg_address_qualifier_t::local), CL_KERNEL_ARG_ADDRESS_LOCAL);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_address_qualifier>(kernel_arg_address_qualifier_t::constant), CL_KERNEL_ARG_ADDRESS_CONSTANT);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_address_qualifier>(kernel_arg_address_qualifier_t::private_), CL_KERNEL_ARG_ADDRESS_PRIVATE);
#endif
  }
  /** // doc: test_kernel_arg_address_qualifier_t__intval() {{{
   * \brief Test the kernel_arg_address_qualifier_t type with intval().
   */ // }}}
  void test_kernel_arg_address_qualifier_t__intval( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(kernel_arg_address_qualifier_t::global), CL_KERNEL_ARG_ADDRESS_GLOBAL);
    TS_ASSERT_EQUALS(intval(kernel_arg_address_qualifier_t::local), CL_KERNEL_ARG_ADDRESS_LOCAL);
    TS_ASSERT_EQUALS(intval(kernel_arg_address_qualifier_t::constant), CL_KERNEL_ARG_ADDRESS_CONSTANT);
    TS_ASSERT_EQUALS(intval(kernel_arg_address_qualifier_t::private_), CL_KERNEL_ARG_ADDRESS_PRIVATE);
#endif
  }
  /** // doc: test_kernel_arg_access_qualifier_t() {{{
   * \brief Test the kernel_arg_access_qualifier_t type.
   */ // }}}
  void test_kernel_arg_access_qualifier_t( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<kernel_arg_access_qualifier_t>::type, cl_kernel_arg_access_qualifier>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_access_qualifier>(kernel_arg_access_qualifier_t::read_only), CL_KERNEL_ARG_ACCESS_READ_ONLY);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_access_qualifier>(kernel_arg_access_qualifier_t::write_only), CL_KERNEL_ARG_ACCESS_WRITE_ONLY);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_access_qualifier>(kernel_arg_access_qualifier_t::read_write), CL_KERNEL_ARG_ACCESS_READ_WRITE);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_access_qualifier>(kernel_arg_access_qualifier_t::none), CL_KERNEL_ARG_ACCESS_NONE);
#endif
  }
  /** // doc: test_kernel_arg_access_qualifier_t__intval() {{{
   * \brief Test the kernel_arg_access_qualifier_t type with intval().
   */ // }}}
  void test_kernel_arg_access_qualifier_t__intval( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(kernel_arg_access_qualifier_t::read_only), CL_KERNEL_ARG_ACCESS_READ_ONLY);
    TS_ASSERT_EQUALS(intval(kernel_arg_access_qualifier_t::write_only), CL_KERNEL_ARG_ACCESS_WRITE_ONLY);
    TS_ASSERT_EQUALS(intval(kernel_arg_access_qualifier_t::read_write), CL_KERNEL_ARG_ACCESS_READ_WRITE);
    TS_ASSERT_EQUALS(intval(kernel_arg_access_qualifier_t::none), CL_KERNEL_ARG_ACCESS_NONE);
#endif
  }
  /** // doc: test_kernel_arg_type_qualifier_t() {{{
   * \brief Test the kernel_arg_type_qualifier_t type.
   */ // }}}
  void test_kernel_arg_type_qualifier_t( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<kernel_arg_type_qualifier_t>::type, cl_kernel_arg_type_qualifier>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_type_qualifier>(kernel_arg_type_qualifier_t::none), CL_KERNEL_ARG_TYPE_NONE);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_type_qualifier>(kernel_arg_type_qualifier_t::const_), CL_KERNEL_ARG_TYPE_CONST);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_type_qualifier>(kernel_arg_type_qualifier_t::restrict_), CL_KERNEL_ARG_TYPE_RESTRICT);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_arg_type_qualifier>(kernel_arg_type_qualifier_t::volatile_), CL_KERNEL_ARG_TYPE_VOLATILE);
#endif
  }
  /** // doc: test_kernel_arg_type_qualifier_t__intval() {{{
   * \brief Test the kernel_arg_type_qualifier_t type with intval().
   */ // }}}
  void test_kernel_arg_type_qualifier_t__intval( )
  {
#if CLXX_CL_H_VERSION_1_2
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(kernel_arg_type_qualifier_t::none), CL_KERNEL_ARG_TYPE_NONE);
    TS_ASSERT_EQUALS(intval(kernel_arg_type_qualifier_t::const_), CL_KERNEL_ARG_TYPE_CONST);
    TS_ASSERT_EQUALS(intval(kernel_arg_type_qualifier_t::restrict_), CL_KERNEL_ARG_TYPE_RESTRICT);
    TS_ASSERT_EQUALS(intval(kernel_arg_type_qualifier_t::volatile_), CL_KERNEL_ARG_TYPE_VOLATILE);
#endif
  }
  /** // doc: test_kernel_arg_type_qualifier_t__bitops() {{{
   * \brief Ensure that bitwise operations work fow kernel_arg_type_qualifier_t
   */ // }}}
  void test_kernel_arg_type_qualifier_t__bitops( )
  {
#if CLXX_CL_H_VERSION_1_2
    // Just ensure that certain expressions get compiled ...
    TS_ASSERT_EQUALS(~(kernel_arg_type_qualifier_t::none), static_cast<kernel_arg_type_qualifier_t>(~CL_KERNEL_ARG_TYPE_NONE));
    TS_ASSERT_EQUALS((kernel_arg_type_qualifier_t::none & kernel_arg_type_qualifier_t::const_), kernel_arg_type_qualifier_t::none);
    TS_ASSERT_EQUALS((kernel_arg_type_qualifier_t::none | kernel_arg_type_qualifier_t::const_), kernel_arg_type_qualifier_t::const_);
    TS_ASSERT_EQUALS((kernel_arg_type_qualifier_t::none ^ kernel_arg_type_qualifier_t::const_), static_cast<kernel_arg_type_qualifier_t>(CL_KERNEL_ARG_TYPE_NONE ^ CL_KERNEL_ARG_TYPE_CONST));

    kernel_arg_type_qualifier_t x(kernel_arg_type_qualifier_t::none);

    x |= kernel_arg_type_qualifier_t::const_;
    TS_ASSERT_EQUALS(x, kernel_arg_type_qualifier_t::const_);
    x &= ~kernel_arg_type_qualifier_t::const_;
    TS_ASSERT_EQUALS(x, kernel_arg_type_qualifier_t::none);
    x ^= kernel_arg_type_qualifier_t::volatile_;
    TS_ASSERT_EQUALS(x, kernel_arg_type_qualifier_t::volatile_);
#endif
  }
  /** // doc: test_kernel_work_group_info_t() {{{
   * \brief Test the kernel_work_group_info_t type.
   */ // }}}
  void test_kernel_work_group_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<kernel_work_group_info_t>::type, cl_kernel_work_group_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_kernel_work_group_info>(kernel_work_group_info_t::work_group_size), CL_KERNEL_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_work_group_info>(kernel_work_group_info_t::compile_work_group_size), CL_KERNEL_COMPILE_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_work_group_info>(kernel_work_group_info_t::local_mem_size), CL_KERNEL_LOCAL_MEM_SIZE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_kernel_work_group_info>(kernel_work_group_info_t::preferred_work_group_size_multiple), CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE);
    TS_ASSERT_EQUALS(static_cast<cl_kernel_work_group_info>(kernel_work_group_info_t::private_mem_size), CL_KERNEL_PRIVATE_MEM_SIZE);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_kernel_work_group_info>(kernel_work_group_info_t::global_work_size), CL_KERNEL_GLOBAL_WORK_SIZE);
#endif
  }
  /** // doc: test_kernel_work_group_info_t__intval() {{{
   * \brief Test the kernel_work_group_info_t type with intval().
   */ // }}}
  void test_kernel_work_group_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(kernel_work_group_info_t::work_group_size), CL_KERNEL_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(intval(kernel_work_group_info_t::compile_work_group_size), CL_KERNEL_COMPILE_WORK_GROUP_SIZE);
    TS_ASSERT_EQUALS(intval(kernel_work_group_info_t::local_mem_size), CL_KERNEL_LOCAL_MEM_SIZE);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(kernel_work_group_info_t::preferred_work_group_size_multiple), CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE);
    TS_ASSERT_EQUALS(intval(kernel_work_group_info_t::private_mem_size), CL_KERNEL_PRIVATE_MEM_SIZE);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(kernel_work_group_info_t::global_work_size), CL_KERNEL_GLOBAL_WORK_SIZE);
#endif
  }
  /** // doc: test_event_info_t() {{{
   * \brief Test the event_info_t type.
   */ // }}}
  void test_event_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<event_info_t>::type, cl_event_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_event_info>(event_info_t::command_queue), CL_EVENT_COMMAND_QUEUE);
    TS_ASSERT_EQUALS(static_cast<cl_event_info>(event_info_t::command_type), CL_EVENT_COMMAND_TYPE);
    TS_ASSERT_EQUALS(static_cast<cl_event_info>(event_info_t::reference_count), CL_EVENT_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(static_cast<cl_event_info>(event_info_t::command_execution_status), CL_EVENT_COMMAND_EXECUTION_STATUS);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_event_info>(event_info_t::context), CL_EVENT_CONTEXT);
#endif
  }
  /** // doc: test_event_info_t__intval() {{{
   * \brief Test the event_info_t type with intval().
   */ // }}}
  void test_event_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(event_info_t::command_queue), CL_EVENT_COMMAND_QUEUE);
    TS_ASSERT_EQUALS(intval(event_info_t::command_type), CL_EVENT_COMMAND_TYPE);
    TS_ASSERT_EQUALS(intval(event_info_t::reference_count), CL_EVENT_REFERENCE_COUNT);
    TS_ASSERT_EQUALS(intval(event_info_t::command_execution_status), CL_EVENT_COMMAND_EXECUTION_STATUS);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(event_info_t::context), CL_EVENT_CONTEXT);
#endif
  }
  /** // doc: test_command_type_t() {{{
   * \brief Test the command_type_t type.
   */ // }}}
  void test_command_type_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<command_type_t>::type, cl_command_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::ndrange_kernel), CL_COMMAND_NDRANGE_KERNEL);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::task), CL_COMMAND_TASK);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::native_kernel), CL_COMMAND_NATIVE_KERNEL);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::read_buffer), CL_COMMAND_READ_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::write_buffer), CL_COMMAND_WRITE_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::copy_buffer), CL_COMMAND_COPY_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::read_image), CL_COMMAND_READ_IMAGE);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::write_image), CL_COMMAND_WRITE_IMAGE);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::copy_image), CL_COMMAND_COPY_IMAGE);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::copy_image_to_buffer), CL_COMMAND_COPY_IMAGE_TO_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::copy_buffer_to_image), CL_COMMAND_COPY_BUFFER_TO_IMAGE);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::map_buffer), CL_COMMAND_MAP_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::map_image), CL_COMMAND_MAP_IMAGE);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::unmap_mem_object), CL_COMMAND_UNMAP_MEM_OBJECT);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::marker), CL_COMMAND_MARKER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::acquire_gl_objects), CL_COMMAND_ACQUIRE_GL_OBJECTS);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::release_gl_objects), CL_COMMAND_RELEASE_GL_OBJECTS);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::read_buffer_rect), CL_COMMAND_READ_BUFFER_RECT);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::write_buffer_rect), CL_COMMAND_WRITE_BUFFER_RECT);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::copy_buffer_rect), CL_COMMAND_COPY_BUFFER_RECT);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::user), CL_COMMAND_USER);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::barrier), CL_COMMAND_BARRIER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::migrate_mem_objects), CL_COMMAND_MIGRATE_MEM_OBJECTS);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::fill_buffer), CL_COMMAND_FILL_BUFFER);
    TS_ASSERT_EQUALS(static_cast<cl_command_type>(command_type_t::fill_image), CL_COMMAND_FILL_IMAGE);
#endif
  }
  /** // doc: test_command_type_t__intval() {{{
   * \brief Test the command_type_t type intval().
   */ // }}}
  void test_command_type_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(command_type_t::ndrange_kernel), CL_COMMAND_NDRANGE_KERNEL);
    TS_ASSERT_EQUALS(intval(command_type_t::task), CL_COMMAND_TASK);
    TS_ASSERT_EQUALS(intval(command_type_t::native_kernel), CL_COMMAND_NATIVE_KERNEL);
    TS_ASSERT_EQUALS(intval(command_type_t::read_buffer), CL_COMMAND_READ_BUFFER);
    TS_ASSERT_EQUALS(intval(command_type_t::write_buffer), CL_COMMAND_WRITE_BUFFER);
    TS_ASSERT_EQUALS(intval(command_type_t::copy_buffer), CL_COMMAND_COPY_BUFFER);
    TS_ASSERT_EQUALS(intval(command_type_t::read_image), CL_COMMAND_READ_IMAGE);
    TS_ASSERT_EQUALS(intval(command_type_t::write_image), CL_COMMAND_WRITE_IMAGE);
    TS_ASSERT_EQUALS(intval(command_type_t::copy_image), CL_COMMAND_COPY_IMAGE);
    TS_ASSERT_EQUALS(intval(command_type_t::copy_image_to_buffer), CL_COMMAND_COPY_IMAGE_TO_BUFFER);
    TS_ASSERT_EQUALS(intval(command_type_t::copy_buffer_to_image), CL_COMMAND_COPY_BUFFER_TO_IMAGE);
    TS_ASSERT_EQUALS(intval(command_type_t::map_buffer), CL_COMMAND_MAP_BUFFER);
    TS_ASSERT_EQUALS(intval(command_type_t::map_image), CL_COMMAND_MAP_IMAGE);
    TS_ASSERT_EQUALS(intval(command_type_t::unmap_mem_object), CL_COMMAND_UNMAP_MEM_OBJECT);
    TS_ASSERT_EQUALS(intval(command_type_t::marker), CL_COMMAND_MARKER);
    TS_ASSERT_EQUALS(intval(command_type_t::acquire_gl_objects), CL_COMMAND_ACQUIRE_GL_OBJECTS);
    TS_ASSERT_EQUALS(intval(command_type_t::release_gl_objects), CL_COMMAND_RELEASE_GL_OBJECTS);
#if CLXX_CL_H_VERSION_1_1
    TS_ASSERT_EQUALS(intval(command_type_t::read_buffer_rect), CL_COMMAND_READ_BUFFER_RECT);
    TS_ASSERT_EQUALS(intval(command_type_t::write_buffer_rect), CL_COMMAND_WRITE_BUFFER_RECT);
    TS_ASSERT_EQUALS(intval(command_type_t::copy_buffer_rect), CL_COMMAND_COPY_BUFFER_RECT);
    TS_ASSERT_EQUALS(intval(command_type_t::user), CL_COMMAND_USER);
#endif
#if CLXX_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(intval(command_type_t::barrier), CL_COMMAND_BARRIER);
    TS_ASSERT_EQUALS(intval(command_type_t::migrate_mem_objects), CL_COMMAND_MIGRATE_MEM_OBJECTS);
    TS_ASSERT_EQUALS(intval(command_type_t::fill_buffer), CL_COMMAND_FILL_BUFFER);
    TS_ASSERT_EQUALS(intval(command_type_t::fill_image), CL_COMMAND_FILL_IMAGE);
#endif
  }
  /** // doc: test_command_exec_status_t() {{{
   * \brief Test the command_exec_status_t type.
   */ // }}}
  void test_command_exec_status_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<command_exec_status_t>::type, cl_int>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_int>(command_exec_status_t::complete), CL_COMPLETE);
    TS_ASSERT_EQUALS(static_cast<cl_int>(command_exec_status_t::running), CL_RUNNING);
    TS_ASSERT_EQUALS(static_cast<cl_int>(command_exec_status_t::submitted), CL_SUBMITTED);
    TS_ASSERT_EQUALS(static_cast<cl_int>(command_exec_status_t::queued), CL_QUEUED);
  }
  /** // doc: test_command_exec_status_t__intval() {{{
   * \brief Test the command_exec_status_t type with intval().
   */ // }}}
  void test_command_exec_status_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(command_exec_status_t::complete), CL_COMPLETE);
    TS_ASSERT_EQUALS(intval(command_exec_status_t::running), CL_RUNNING);
    TS_ASSERT_EQUALS(intval(command_exec_status_t::submitted), CL_SUBMITTED);
    TS_ASSERT_EQUALS(intval(command_exec_status_t::queued), CL_QUEUED);
  }
  /** // doc: test_command_exec_status_t__is_error() {{{
   * \brief Ensure that is_error() works with command_exec_status_t
   */ // }}}
  void test_command_exec_status_t__is_error( )
  {
    TS_ASSERT(!is_error(command_exec_status_t::complete));
    TS_ASSERT(!is_error(command_exec_status_t::running));
    TS_ASSERT(!is_error(command_exec_status_t::submitted));
    TS_ASSERT(!is_error(command_exec_status_t::queued));
  }
  /** // doc: test_command_exec_status_t__is_success() {{{
   * \brief Ensure that is_success() works with command_exec_status_t
   */ // }}}
  void test_command_exec_status_t__is_success( )
  {
    TS_ASSERT(is_success(command_exec_status_t::complete));
    TS_ASSERT(!is_success(command_exec_status_t::running));
    TS_ASSERT(!is_success(command_exec_status_t::submitted));
    TS_ASSERT(!is_success(command_exec_status_t::queued));
  }
  /** // doc: test_command_exec_status_t__is_state() {{{
   * \brief Ensure that is_state() works with command_exec_status_t
   */ // }}}
  void test_command_exec_status_t__is_state( )
  {
    TS_ASSERT(is_state(command_exec_status_t::complete));
    TS_ASSERT(is_state(command_exec_status_t::running));
    TS_ASSERT(is_state(command_exec_status_t::submitted));
    TS_ASSERT(is_state(command_exec_status_t::queued));
  }
  /** // doc: test_command_exec_status_t__cmp_status_t() {{{
   * \brief Ensure that comarison works with command_exec_status_t + status_t.
   */ // }}}
  void test_command_exec_status_t__cmp__status_t( )
  {
    TS_ASSERT(command_exec_status_t::complete == status_t::success);
    TS_ASSERT(status_t::success == command_exec_status_t::complete);
    TS_ASSERT(status_t::invalid_value != command_exec_status_t::complete);
    TS_ASSERT(command_exec_status_t::complete != status_t::invalid_value);
    TS_ASSERT(status_t::invalid_value < command_exec_status_t::complete);
    TS_ASSERT(!(command_exec_status_t::complete < status_t::invalid_value));
    TS_ASSERT(!(status_t::invalid_value > command_exec_status_t::complete));
    TS_ASSERT(command_exec_status_t::complete > status_t::invalid_value);
    TS_ASSERT(status_t::invalid_value <= command_exec_status_t::complete);
    TS_ASSERT(!(command_exec_status_t::complete <= status_t::invalid_value));
    TS_ASSERT(!(status_t::invalid_value >= command_exec_status_t::complete));
    TS_ASSERT(command_exec_status_t::complete >= status_t::invalid_value);
    TS_ASSERT(command_exec_status_t::complete <= status_t::success);
    TS_ASSERT(status_t::success <= command_exec_status_t::complete);
    TS_ASSERT(command_exec_status_t::complete >= status_t::success);
    TS_ASSERT(status_t::success >= command_exec_status_t::complete);
  }
  /** // doc: test_buffer_create_type_t() {{{
   * \brief Test the buffer_create_type_t type.
   */ // }}}
  void test_buffer_create_type_t( )
  {
#if CLXX_CL_H_VERSION_1_1
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<buffer_create_type_t>::type, cl_buffer_create_type>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_buffer_create_type>(buffer_create_type_t::region), CL_BUFFER_CREATE_TYPE_REGION);
#endif
  }
  /** // doc: test_buffer_create_type_t__intval() {{{
   * \brief Test the buffer_create_type_t type with intval().
   */ // }}}
  void test_buffer_create_type_t__intval( )
  {
#if CLXX_CL_H_VERSION_1_1
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(buffer_create_type_t::region), CL_BUFFER_CREATE_TYPE_REGION);
#endif
  }
  /** // doc: test_profiling_info_t() {{{
   * \brief Test the profiling_info_t type.
   */ // }}}
  void test_profiling_info_t( )
  {
    //
    // Check the underlying type
    //
    TS_ASSERT((std::is_same<std::underlying_type<profiling_info_t>::type, cl_profiling_info>::value));
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(static_cast<cl_profiling_info>(profiling_info_t::queued), CL_PROFILING_COMMAND_QUEUED);
    TS_ASSERT_EQUALS(static_cast<cl_profiling_info>(profiling_info_t::submit), CL_PROFILING_COMMAND_SUBMIT);
    TS_ASSERT_EQUALS(static_cast<cl_profiling_info>(profiling_info_t::start), CL_PROFILING_COMMAND_START);
    TS_ASSERT_EQUALS(static_cast<cl_profiling_info>(profiling_info_t::end), CL_PROFILING_COMMAND_END);
  }
  /** // doc: test_profiling_info_t__intval() {{{
   * \brief Test the profiling_info_t type with intval().
   */ // }}}
  void test_profiling_info_t__intval( )
  {
    //
    // Check enum values
    //
    TS_ASSERT_EQUALS(intval(profiling_info_t::queued), CL_PROFILING_COMMAND_QUEUED);
    TS_ASSERT_EQUALS(intval(profiling_info_t::submit), CL_PROFILING_COMMAND_SUBMIT);
    TS_ASSERT_EQUALS(intval(profiling_info_t::start), CL_PROFILING_COMMAND_START);
    TS_ASSERT_EQUALS(intval(profiling_info_t::end), CL_PROFILING_COMMAND_END);
  }
};

#endif /* CLXX_TYPES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
