// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clobj_fcn.hpp

/** // doc: clxx/clobj_fcn.hpp {{{
 * \file clxx/clobj_fcn.hpp
 * \brief Implements helper functions used by \ref clxx::clobj "clobj".
 */ // }}}
#ifndef CLXX_CLOBJ_FCN_HPP_INCLUDED
#define CLXX_CLOBJ_FCN_HPP_INCLUDED

#include <clxx/cl/cl.h>
#include <clxx/functions.hpp>

namespace clxx {
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_command_queue()
 */ // }}}
inline void
retain_cl_object(cl_command_queue queue)
{
  retain_command_queue(queue);
}
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_context()
 */ // }}}
inline void
retain_cl_object(cl_context context)
{
  retain_context(context);
}
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_device() (but no-op for OpenCL < 1.2)
 */ // }}}
inline void
retain_cl_object(cl_device_id device)
{
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
  retain_device(device);
#else
  (void)device;
#endif
}
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_event()
 */ // }}}
inline void
retain_cl_object(cl_event event)
{
  retain_event(event);
}
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_kernel()
 */ // }}}
inline void
retain_cl_object(cl_kernel kernel)
{
  retain_kernel(kernel);
}
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_mem_object()
 */ // }}}
inline void
retain_cl_object(cl_mem memobj)
{
  retain_mem_object(memobj);
}
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_program()
 */ // }}}
inline void
retain_cl_object(cl_program program)
{
  retain_program(program);
}
#if 0
/** // doc: retain_cl_object() {{{
 * \brief Same as #retain_sampler()
 */ // }}}
inline void
retain_cl_object(cl_sampler sampler)
{
  retain_sampler(sampler);
}
#endif

/** // doc: release_cl_object() {{{
 * \brief Same as release_command_queue()
 */ // }}}
inline void
release_cl_object(cl_command_queue queue)
{
  release_command_queue(queue);
}
/** // doc: release_cl_object() {{{
 * \brief Same as release_context()
 */ // }}}
inline void
release_cl_object(cl_context context)
{
  release_context(context);
}
/** // doc: release_cl_object() {{{
 * \brief Same as #release_device() (but no-op for OpenCL < 1.2)
 */ // }}}
inline void
release_cl_object(cl_device_id device)
{
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
  release_device(device);
#else
  (void)device;
#endif
}
/** // doc: release_cl_object() {{{
 * \brief Same as release_event()
 */ // }}}
inline void
release_cl_object(cl_event event)
{
  release_event(event);
}
/** // doc: release_cl_object() {{{
 * \brief Same as #release_kernel()
 */ // }}}
inline void
release_cl_object(cl_kernel kernel)
{
  release_kernel(kernel);
}
/** // doc: release_cl_object() {{{
 * \brief Same as #release_mem_object()
 */ // }}}
inline void
release_cl_object(cl_mem memobj)
{
  release_mem_object(memobj);
}
/** // doc: release_cl_object() {{{
 * \brief Same as #release_program()
 */ // }}}
inline void
release_cl_object(cl_program program)
{
  release_program(program);
}
#if 0
/** // doc: release_cl_object() {{{
 * \brief Same as #release_sampler()
 */ // }}}
inline void
release_cl_object(cl_sampler sampler)
{
  release_sampler(sampler);
}
#endif

/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_command_queue_info()
 */ // }}}
inline void
get_cl_object_info(cl_command_queue queue,
                   command_queue_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_command_queue_info( queue,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_cl_object_info() {{{
 * \brief Same as get_context_info()
 */ // }}}
inline void
get_cl_object_info(cl_context context,
                   context_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_context_info(       context,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_device_info()
 */ // }}}
inline void
get_cl_object_info(cl_device_id device,
                   device_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_device_info(        device,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_event_info()
 */ // }}}
inline void
get_cl_object_info(cl_event event,
                   event_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_event_info(         event,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_kernel_info()
 */ // }}}
inline void
get_cl_object_info(cl_kernel kernel,
                   kernel_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_kernel_info(        kernel,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_mem_object_info()
 */ // }}}
inline void
get_cl_object_info(cl_mem memobj,
                   mem_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_mem_object_info(    memobj,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_platform_info()
 */ // }}}
inline void
get_cl_object_info(cl_platform_id platform,
                   platform_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_platform_info(      platform,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_program_info()
 */ // }}}
inline void
get_cl_object_info(cl_program program,
                   program_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_program_info(       program,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
#if 0
/** // doc: get_cl_object_info() {{{
 * \brief Same as #get_sampler_info()
 */ // }}}
inline void
get_cl_object_info(cl_sampler sampler,
                   sampler_info_t param_name,
                   size_t param_value_size,
                   void* param_value,
                   size_t* param_value_size_ret)
{
  get_sampler_info(       sampler,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
#endif
} // end namespace clxx

#endif /* CLXX_CLOBJ_FCN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
