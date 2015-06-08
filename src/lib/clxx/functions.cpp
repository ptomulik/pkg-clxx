// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/functions.cpp {{{
 * \file clxx/functions.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx {
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
      switch(s)
        {
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
    switch(s)
      {
        case status_t::invalid_platform:
          throw clerror_no<status_t::invalid_platform>();
        case status_t::invalid_value:
          throw clerror_no<status_t::invalid_value>();
        case status_t::out_of_host_memory:
          throw clerror_no<status_t::out_of_host_memory>();
        default:
          throw unexpected_clerror(s);
      }
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
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_platform:
            throw clerror_no<status_t::invalid_platform>();
          case status_t::invalid_device_type:
            throw clerror_no<status_t::invalid_device_type>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::device_not_found:
            break; // not found, so we return "empty sequence"
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_platform:
            throw clerror_no<status_t::invalid_platform>();
#if CL_VERSION_1_1
          case status_t::invalid_property:
            throw clerror_no<status_t::invalid_property>();
          case status_t::invalid_operation:
            throw clerror_no<status_t::invalid_operation>();
#endif
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::device_not_available:
            throw clerror_no<status_t::device_not_available>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
#if cl_khr_gl_sharing
          case status_t::invalid_gl_sharegroup_reference_khr:
            throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>();
#endif
#if cl_khr_dx9_media_sharing
          case status_t::invalid_dx9_media_adapter_khr:
            throw clerror_no<status_t::invalid_dx9_media_adapter_khr>();
#endif
#if cl_khr_d3d10_sharing
          case status_t::invalid_d3d10_device_khr:
            throw clerror_no<status_t::invalid_d3d10_device_khr>();
#endif
#if cl_khr_d3d11_sharing
          case status_t::invalid_d3d11_device_khr:
            throw clerror_no<status_t::invalid_d3d11_device_khr>();
#endif
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_platform:
            throw clerror_no<status_t::invalid_platform>();
#if CL_VERSION_1_1
          case status_t::invalid_property:
            throw clerror_no<status_t::invalid_property>();
          case status_t::invalid_operation:
            throw clerror_no<status_t::invalid_operation>();
#endif
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device_type:
            throw clerror_no<status_t::invalid_device_type>();
          case status_t::device_not_available:
            throw clerror_no<status_t::device_not_available>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::device_not_found:
            throw clerror_no<status_t::device_not_found>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
#if cl_khr_gl_sharing
          case status_t::invalid_gl_sharegroup_reference_khr:
            throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>();
#endif
#if cl_khr_dx9_media_sharing
          case status_t::invalid_dx9_media_adapter_khr:
            throw clerror_no<status_t::invalid_dx9_media_adapter_khr>();
#endif
#if cl_khr_d3d10_sharing
          case status_t::invalid_d3d10_device_khr:
            throw clerror_no<status_t::invalid_d3d10_device_khr>();
#endif
#if cl_khr_d3d11_sharing
          case status_t::invalid_d3d11_device_khr:
            throw clerror_no<status_t::invalid_d3d11_device_khr>();
#endif
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
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
      switch(s)
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void
release_context(cl_context context)
{
  status_t s = static_cast<status_t>(T::clReleaseContext(context));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
      switch(s)
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clCreateSubDevices
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
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::device_partition_failed:
            throw clerror_no<status_t::device_partition_failed>();
          case status_t::invalid_device_partition_count:
            throw clerror_no<status_t::invalid_device_partition_count>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clCreateSubDevices
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clRetainDevice
void
retain_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clRetainDevice(device));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clRetainDevice
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clReleaseDevice
void
release_device(cl_device_id device)
{
  status_t s = static_cast<status_t>(T::clReleaseDevice(device));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clReleaseDevice
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clCreateCommandQueue
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_queue_properties:
            throw clerror_no<status_t::invalid_queue_properties>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }

  return queue;
}
#endif
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clCreateCommandQueueWithProperties
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_queue_properties:
            throw clerror_no<status_t::invalid_queue_properties>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
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
      switch(s)
        {
          case status_t::invalid_command_queue:
            throw clerror_no<status_t::invalid_command_queue>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void
release_command_queue(cl_command_queue command_queue)
{
  status_t s = static_cast<status_t>(T::clReleaseCommandQueue(command_queue));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_command_queue:
            throw clerror_no<status_t::invalid_command_queue>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
      switch(s)
        {
          case status_t::invalid_command_queue:
            throw clerror_no<status_t::invalid_command_queue>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_binary:
            throw clerror_no<status_t::invalid_binary>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }
  return p;
}
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }
  return p;
}
#endif // HAVE_OPENCL_clCreateProgramWithBuiltInKernels
/* ------------------------------------------------------------------------ */
void
retain_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clRetainProgram(program));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
void
release_program(cl_program program)
{
  status_t s = static_cast<status_t>(T::clReleaseProgram(program));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
      switch(s)
        {
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_binary:
            throw clerror_no<status_t::invalid_binary>();
          case status_t::invalid_build_options:
            throw clerror_no<status_t::invalid_build_options>();
          case status_t::invalid_operation:
            throw clerror_no<status_t::invalid_operation>();
          case status_t::compiler_not_available:
            throw clerror_no<status_t::compiler_not_available>();
          case status_t::build_program_failure:
            throw clerror_no<status_t::build_program_failure>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clCompileProgram
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
      switch(s)
        {
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_compiler_options:
            throw clerror_no<status_t::invalid_compiler_options>();
          case status_t::invalid_operation:
            throw clerror_no<status_t::invalid_operation>();
          case status_t::compiler_not_available:
            throw clerror_no<status_t::compiler_not_available>();
          case status_t::compile_program_failure:
            throw clerror_no<status_t::compile_program_failure>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clCompileProgram
/* ------------------------------------------------------------------------ */
#if HAVE_OPENCL_clLinkProgram
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
      switch(static_cast<status_t>(s))
        {
          case status_t::invalid_context:
            throw clerror_no<status_t::invalid_context>();
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_linker_options:
            throw clerror_no<status_t::invalid_linker_options>();
          case status_t::invalid_operation:
            throw clerror_no<status_t::invalid_operation>();
          case status_t::linker_not_available:
            throw clerror_no<status_t::linker_not_available>();
          case status_t::link_program_failure:
            throw clerror_no<status_t::link_program_failure>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(static_cast<status_t>(s));
        }
    }
  return p;
}
#endif // HAVE_OPENCL_clLinkProgram
#if HAVE_OPENCL_clUnloadPlatformCompiler
/* ------------------------------------------------------------------------ */
void
unload_platform_compiler(cl_platform_id platform)
{
  status_t s = static_cast<status_t>(T::clUnloadPlatformCompiler(platform));
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_platform:
            throw clerror_no<status_t::invalid_platform>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
#endif // HAVE_OPENCL_clUnloadPlatformCompiler
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
      switch(s)
        {
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::invalid_program_executable:
            throw clerror_no<status_t::invalid_program_executable>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
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
      switch(s)
        {
          case status_t::invalid_device:
            throw clerror_no<status_t::invalid_device>();
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::invalid_program:
            throw clerror_no<status_t::invalid_program>();
          case status_t::out_of_resources:
            throw clerror_no<status_t::out_of_resources>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
