// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/functions.cpp {{{
 * \file clxx/functions.cpp
 * \brief Implements thin wrappers for OpenCL functions
 */ // }}}
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx {
static void _throw_clerror_no(status_t s)
{
  switch(s)
    {
      case status_t::device_not_found:
        throw clerror_no<status_t::device_not_found>();
      case status_t::device_not_available:
        throw clerror_no<status_t::device_not_available>();
      case status_t::compiler_not_available:
        throw clerror_no<status_t::compiler_not_available>();
      case status_t::mem_object_allocation_failure:
        throw clerror_no<status_t::mem_object_allocation_failure>();
      case status_t::out_of_resources:
        throw clerror_no<status_t::out_of_resources>();
      case status_t::out_of_host_memory:
        throw clerror_no<status_t::out_of_host_memory>();
      case status_t::profiling_info_not_available:
        throw clerror_no<status_t::profiling_info_not_available>();
      case status_t::mem_copy_overlap:
        throw clerror_no<status_t::mem_copy_overlap>();
      case status_t::image_format_mismatch:
        throw clerror_no<status_t::image_format_mismatch>();
      case status_t::image_format_not_supported:
        throw clerror_no<status_t::image_format_not_supported>();
      case status_t::build_program_failure:
        throw clerror_no<status_t::build_program_failure>();
      case status_t::map_failure:
        throw clerror_no<status_t::map_failure>();
#if CL_VERSION_1_1
      case status_t::misaligned_sub_buffer_offset:
        throw clerror_no<status_t::misaligned_sub_buffer_offset>();
      case status_t::exec_status_error_for_events_in_wait_list:
        throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>();
#endif
#if CL_VERSION_1_2
      case status_t::compile_program_failure:
        throw clerror_no<status_t::compile_program_failure>();
      case status_t::linker_not_available:
        throw clerror_no<status_t::linker_not_available>();
      case status_t::link_program_failure:
        throw clerror_no<status_t::link_program_failure>();
      case status_t::device_partition_failed:
        throw clerror_no<status_t::device_partition_failed>();
      case status_t::kernel_arg_info_not_available:
        throw clerror_no<status_t::kernel_arg_info_not_available>();
#endif
      case status_t::invalid_value:
        throw clerror_no<status_t::invalid_value>();
      case status_t::invalid_device_type:
        throw clerror_no<status_t::invalid_device_type>();
      case status_t::invalid_platform:
        throw clerror_no<status_t::invalid_platform>();
      case status_t::invalid_device:
        throw clerror_no<status_t::invalid_device>();
      case status_t::invalid_context:
        throw clerror_no<status_t::invalid_context>();
      case status_t::invalid_queue_properties:
        throw clerror_no<status_t::invalid_queue_properties>();
      case status_t::invalid_command_queue:
        throw clerror_no<status_t::invalid_command_queue>();
      case status_t::invalid_host_ptr:
        throw clerror_no<status_t::invalid_host_ptr>();
      case status_t::invalid_mem_object:
        throw clerror_no<status_t::invalid_mem_object>();
      case status_t::invalid_image_format_descriptor:
        throw clerror_no<status_t::invalid_image_format_descriptor>();
      case status_t::invalid_image_size:
        throw clerror_no<status_t::invalid_image_size>();
      case status_t::invalid_sampler:
        throw clerror_no<status_t::invalid_sampler>();
      case status_t::invalid_binary:
        throw clerror_no<status_t::invalid_binary>();
      case status_t::invalid_build_options:
        throw clerror_no<status_t::invalid_build_options>();
      case status_t::invalid_program:
        throw clerror_no<status_t::invalid_program>();
      case status_t::invalid_program_executable:
        throw clerror_no<status_t::invalid_program_executable>();
      case status_t::invalid_kernel_name:
        throw clerror_no<status_t::invalid_kernel_name>();
      case status_t::invalid_kernel_definition:
        throw clerror_no<status_t::invalid_kernel_definition>();
      case status_t::invalid_kernel:
        throw clerror_no<status_t::invalid_kernel>();
      case status_t::invalid_arg_index:
        throw clerror_no<status_t::invalid_arg_index>();
      case status_t::invalid_arg_value:
        throw clerror_no<status_t::invalid_arg_value>();
      case status_t::invalid_arg_size:
        throw clerror_no<status_t::invalid_arg_size>();
      case status_t::invalid_kernel_args:
        throw clerror_no<status_t::invalid_kernel_args>();
      case status_t::invalid_work_dimension:
        throw clerror_no<status_t::invalid_work_dimension>();
      case status_t::invalid_work_group_size:
        throw clerror_no<status_t::invalid_work_group_size>();
      case status_t::invalid_work_item_size:
        throw clerror_no<status_t::invalid_work_item_size>();
      case status_t::invalid_global_offset:
        throw clerror_no<status_t::invalid_global_offset>();
      case status_t::invalid_event_wait_list:
        throw clerror_no<status_t::invalid_event_wait_list>();
      case status_t::invalid_event:
        throw clerror_no<status_t::invalid_event>();
      case status_t::invalid_operation:
        throw clerror_no<status_t::invalid_operation>();
      case status_t::invalid_gl_object:
        throw clerror_no<status_t::invalid_gl_object>();
      case status_t::invalid_buffer_size:
        throw clerror_no<status_t::invalid_buffer_size>();
      case status_t::invalid_mip_level:
        throw clerror_no<status_t::invalid_mip_level>();
      case status_t::invalid_global_work_size:
        throw clerror_no<status_t::invalid_global_work_size>();
#if CL_VERSION_1_1
      case status_t::invalid_property:
        throw clerror_no<status_t::invalid_property>();
#endif
#if CL_VERSION_1_2
      case status_t::invalid_image_descriptor:
        throw clerror_no<status_t::invalid_image_descriptor>();
      case status_t::invalid_compiler_options:
        throw clerror_no<status_t::invalid_compiler_options>();
      case status_t::invalid_linker_options:
        throw clerror_no<status_t::invalid_linker_options>();
      case status_t::invalid_device_partition_count:
        throw clerror_no<status_t::invalid_device_partition_count>();
#endif
#if CL_VERSION_2_0
      case status_t::invalid_pipe_size:
        throw clerror_no<status_t::invalid_pipe_size>();
      case status_t::invalid_device_queue:
        throw clerror_no<status_t::invalid_device_queue>();
#endif
    //
    // codes defined by OpenCL extensions
    //
#if cl_khr_icd
      case status_t::platform_not_found_khr:
        throw clerror_no<status_t::platform_not_found_khr>();
#endif
#if cl_ext_device_fission
      case status_t::device_partition_failed_ext:
        throw clerror_no<status_t::device_partition_failed_ext>();
      case status_t::invalid_partition_count_ext:
        throw clerror_no<status_t::invalid_partition_count_ext>();
      case status_t::invalid_partition_name_ext:
        throw clerror_no<status_t::invalid_partition_name_ext>();
#endif
#if cl_khr_gl_sharing
      case status_t::invalid_gl_sharegroup_reference_khr:
        throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>();
#endif
#if cl_khr_dx9_media_sharing
      case status_t::invalid_dx9_media_adapter_khr:
        throw clerror_no<status_t::invalid_dx9_media_adapter_khr>();
      case status_t::invalid_dx9_media_surface_khr:
        throw clerror_no<status_t::invalid_dx9_media_surface_khr>();
      case status_t::dx9_media_surface_already_acquired_khr:
        throw clerror_no<status_t::dx9_media_surface_already_acquired_khr>();
      case status_t::dx9_media_surface_not_acquired_khr:
        throw clerror_no<status_t::dx9_media_surface_not_acquired_khr>();
#endif
#if cl_khr_d3d10_sharing
      case status_t::invalid_d3d10_device_khr:
        throw clerror_no<status_t::invalid_d3d10_device_khr>();
      case status_t::invalid_d3d10_resource_khr:
        throw clerror_no<status_t::invalid_d3d10_resource_khr>();
      case status_t::d3d10_resource_already_acquired_khr:
        throw clerror_no<status_t::d3d10_resource_already_acquired_khr>();
      case status_t::d3d10_resource_not_acquired_khr:
        throw clerror_no<status_t::d3d10_resource_not_acquired_khr>();
#endif
#if cl_khr_d3d11_sharing
      case status_t::invalid_d3d11_device_khr:
        throw clerror_no<status_t::invalid_d3d11_device_khr>();
      case status_t::invalid_d3d11_resource_khr:
        throw clerror_no<status_t::invalid_d3d11_resource_khr>();
      case status_t::d3d11_resource_already_acquired_khr:
        throw clerror_no<status_t::d3d11_resource_already_acquired_khr>();
      case status_t::d3d11_resource_not_acquired_khr:
        throw clerror_no<status_t::d3d11_resource_not_acquired_khr>();
#endif
      default:
        throw unexpected_clerror(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_platform_ids(cl_uint num_entries,
                 cl_platform_id* platforms,
                 cl_uint* num_platforms)
{
  status_t s = static_cast<status_t>(
      T::clGetPlatformIDs(num_entries, platforms, num_platforms)
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_platform_info(cl_platform_id platform,
                  platform_info_t param_name,
                  size_t param_value_size,
                  void* param_value,
                  size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetPlatformInfo( platform,
                            static_cast<cl_platform_info>(param_name),
                            param_value_size,
                            param_value,
                            param_value_size_ret )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_device_ids(cl_platform_id platform,
               device_type_t device_type,
               cl_uint num_entries,
               cl_device_id* devices,
               cl_uint* num_devices)
{
  status_t s = static_cast<status_t>(
    T::clGetDeviceIDs(
      platform,
      static_cast<cl_device_type>(device_type),
      num_entries,
      devices,
      num_devices
    )
  );
  if(is_error(s) && s != status_t::device_not_found)
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_device_info(cl_device_id device,
                device_info_t param_name,
                size_t param_value_size,
                void* param_value,
                size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetDeviceInfo(
        device,
        static_cast<cl_device_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
cl_context
create_context(const cl_context_properties* properties,
               cl_uint num_devices,
               const cl_device_id* devices,
               void(*pfn_notify)(const char* errinfo,
                                 const void* private_info,
                                 size_t cb,
                                 void* user_data),
               void* user_data)
{
  cl_int s = CL_SUCCESS;
  cl_context ctx;
  ctx = T::clCreateContext(properties, num_devices, devices, pfn_notify, user_data, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return ctx;
}
/* ------------------------------------------------------------------------ */
cl_context
create_context_from_type(const cl_context_properties* properties,
                         device_type_t device_type,
                         void(*pfn_notify)(const char* errinfo,
                                           const void* private_info,
                                           size_t cb,
                                           void* user_data),
                         void* user_data)
{
  cl_int s = CL_SUCCESS;
  cl_context ctx;
  ctx = T::clCreateContextFromType(
      properties,
      static_cast<cl_device_type>(device_type),
      pfn_notify,
      user_data,
      &s);

  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return ctx;
}
/* ------------------------------------------------------------------------ */
void
retain_context(cl_context context)
{
  status_t s = static_cast<status_t>(T::clRetainContext(context));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
release_context(cl_context context)
{
  status_t s = static_cast<status_t>(T::clReleaseContext(context));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_context_info(cl_context context,
                 context_info_t param_name,
                 size_t param_value_size,
                 void* param_value,
                 size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
    T::clGetContextInfo(
      context,
      static_cast<cl_context_info>(param_name),
      param_value_size,
      param_value,
      param_value_size_ret
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
void
create_sub_devices(cl_device_id in_device,
                   const cl_device_partition_property* properties,
                   cl_uint num_devices,
                   cl_device_id* out_devices,
                   cl_uint *num_devices_ret)
{
  status_t s = static_cast<status_t>(
      T::clCreateSubDevices(
        in_device,
        properties,
        num_devices,
        out_devices,
        num_devices_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif // CLXX_OPENCL_ALLOWED(clCreateSubDevices)
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
void
retain_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clRetainDevice(device));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif // CLXX_OPENCL_ALLOWED(clRetainDevice)
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
void
release_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clReleaseDevice(device));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif // CLXX_OPENCL_ALLOWED(clReleaseDevice)
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
cl_command_queue
create_command_queue(cl_context context,
                     cl_device_id device,
                     command_queue_properties_t properties)
{
  cl_int s = CL_SUCCESS;
  cl_command_queue queue;
  queue = T::clCreateCommandQueue(context, device, static_cast<cl_command_queue_properties>(properties), &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return queue;
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
cl_command_queue
create_command_queue_with_properties(cl_context context,
                                     cl_device_id device,
                                     const cl_queue_properties* properties)
{
  cl_int s = CL_SUCCESS;
  cl_command_queue queue;
  queue = T::clCreateCommandQueueWithProperties(context, device, properties, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }

  return queue;
}
#endif
/* ------------------------------------------------------------------------ */
void
retain_command_queue(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clRetainCommandQueue(command_queue));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
release_command_queue(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clReleaseCommandQueue(command_queue));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_command_queue_info(cl_command_queue command_queue,
                       command_queue_info_t param_name,
                       size_t param_value_size,
                       void* param_value,
                       size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
    T::clGetCommandQueueInfo(
      command_queue,
      static_cast<cl_command_queue_info>(param_name),
      param_value_size,
      param_value,
      param_value_size_ret
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
cl_program
create_program_with_source(cl_context context,
                           cl_uint count,
                           const char** strings,
                           const size_t* lengths)
{
  cl_int s = CL_SUCCESS;
  cl_program p;
  p = T::clCreateProgramWithSource(context, count, strings, lengths, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
/* ------------------------------------------------------------------------ */
cl_program
create_program_with_binary(cl_context context,
                           cl_uint num_devices,
                           const cl_device_id* device_list,
                           const size_t* lengths,
                           const unsigned char** binaries,
                           cl_int* binary_status)
{
  cl_int s = CL_SUCCESS;
  cl_program p = T::clCreateProgramWithBinary(
      context,
      num_devices,
      device_list,
      lengths,
      binaries,
      binary_status,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
/* ------------------------------------------------------------------------ */
cl_program
create_program_with_built_in_kernels(cl_context context,
                                     cl_uint num_devices,
                                     const cl_device_id* device_list,
                                     const char* kernel_names)
{
  cl_int s = CL_SUCCESS;
  cl_program p = T::clCreateProgramWithBuiltInKernels(
      context,
      num_devices,
      device_list,
      kernel_names,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#endif // CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
/* ------------------------------------------------------------------------ */
void
retain_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clRetainProgram(program));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
release_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clReleaseProgram(program));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
build_program(cl_program program,
              cl_uint num_devices,
              const cl_device_id* device_list,
              const char* options,
              void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
              void* user_data)
{
  status_t s = static_cast<status_t>(
    T::clBuildProgram(
      program,
      num_devices,
      device_list,
      options,
      pfn_notify,
      user_data
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
void
compile_program(cl_program program,
                cl_uint num_devices,
                const cl_device_id* device_list,
                const char* options,
                cl_uint num_input_headers,
                const cl_program* input_headers,
                const char** header_include_names,
                void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
                void* user_data)
{
  status_t s = static_cast<status_t>(
    T::clCompileProgram(
      program,
      num_devices,
      device_list,
      options,
      num_input_headers,
      input_headers,
      header_include_names,
      pfn_notify,
      user_data
    )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif // CLXX_OPENCL_ALLOWED(clCompileProgram)
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
cl_program
link_program(cl_context context,
             cl_uint num_devices,
             const cl_device_id* device_list,
             const char* options,
             cl_uint num_input_programs,
             const cl_program* input_programs,
             void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
             void* user_data)
{

  cl_int s = CL_SUCCESS;
  cl_program p = T::clLinkProgram(
      context,
      num_devices,
      device_list,
      options,
      num_input_programs,
      input_programs,
      pfn_notify,
      user_data,
      &s
  );
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return p;
}
#endif // CLXX_OPENCL_ALLOWED(clLinkProgram)
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
/* ------------------------------------------------------------------------ */
void
unload_platform_compiler(cl_platform_id platform)
{
  status_t s = static_cast<status_t>(T::clUnloadPlatformCompiler(platform));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif // CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
/* ------------------------------------------------------------------------ */
void
get_program_info(cl_program program,
                 program_info_t param_name,
                 size_t param_value_size,
                 void* param_value,
                 size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetProgramInfo(
        program,
        static_cast<cl_program_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_program_build_info(cl_program program,
                       cl_device_id device,
                       program_build_info_t param_name,
                       size_t param_value_size,
                       void* param_value,
                       size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetProgramBuildInfo(
        program,
        device,
        static_cast<cl_program_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
cl_kernel
create_kernel(cl_program program,
              const char* kernel_name)
{
  cl_int s = CL_SUCCESS;
  cl_kernel kern;
  kern = T::clCreateKernel(program, kernel_name, &s);
  if(is_error(static_cast<status_t>(s)))
    {
      _throw_clerror_no(static_cast<status_t>(s));
    }
  return kern;
}
/* ------------------------------------------------------------------------ */
void
create_kernels_in_program(cl_program program,
                          cl_uint num_kernels,
                          cl_kernel* kernels,
                          cl_uint* num_kernels_ret)
{
  status_t s = static_cast<status_t>(
      T::clCreateKernelsInProgram(
        program,
        num_kernels,
        kernels,
        num_kernels_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
get_kernel_info(cl_kernel kernel,
                kernel_info_t param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetKernelInfo(
        kernel,
        static_cast<cl_kernel_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
     )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
void
get_kernel_arg_info(cl_kernel kernel,
                    cl_uint arg_index,
                    kernel_arg_info_t param_name,
                    size_t param_value_size, void* param_value,
                    size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetKernelArgInfo(
        kernel,
        arg_index,
        static_cast<cl_kernel_arg_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
void
get_kernel_work_group_info(cl_kernel kernel,
                           cl_device_id device,
                           kernel_work_group_info_t param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret)
{
  status_t s = static_cast<status_t>(
      T::clGetKernelWorkGroupInfo(
        kernel,
        device,
        static_cast<cl_kernel_work_group_info>(param_name),
        param_value_size,
        param_value,
        param_value_size_ret
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
retain_kernel(cl_kernel kernel)
{
  status_t s = static_cast<status_t>(T::clRetainKernel(kernel));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
release_kernel(cl_kernel kernel)
{
  status_t s = static_cast<status_t>(T::clReleaseKernel(kernel));
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
void
set_kernel_arg(cl_kernel kernel,
               cl_uint arg_index,
               size_t arg_size,
               const void* arg_value)
{
  status_t s = static_cast<status_t>(
      T::clSetKernelArg(
        kernel,
        arg_index,
        arg_size,
        arg_value
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
void
set_kernel_arg_svm_pointer(cl_kernel kernel,
                           cl_uint arg_index,
                           const void* arg_value)
{
  status_t s = static_cast<status_t>(
      T::clSetKernelArgSVMPointer(
        kernel,
        arg_index,
        arg_value
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
/* ------------------------------------------------------------------------ */
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
void
set_kernel_exec_info(cl_kernel kernel,
                     kernel_exec_info_t param_name,
                     size_t param_value_size,
                     const void* param_value)
{
  status_t s = static_cast<status_t>(
      T::clSetKernelExecInfo(
        kernel,
        static_cast<cl_kernel_exec_info>(param_name),
        param_value_size,
        param_value
      )
  );
  if(is_error(s))
    {
      _throw_clerror_no(s);
    }
}
#endif
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
