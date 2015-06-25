// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions.hpp

/** // doc: clxx/functions.hpp {{{
 * \file clxx/functions.hpp
 * \brief Bare C++ wrappers around OpenCL functions.
 */ // }}}
#ifndef CLXX_FUNCTIONS_HPP_INCLUDED
#define CLXX_FUNCTIONS_HPP_INCLUDED

#include <clxx/types.hpp>

namespace clxx {

/** \addtogroup clxx_cl_functions
 *  @{ */
/** // {{{ doc: get_platform_ids(...)
 * \brief Retrieve platform identifiers of locally available OpenCL platforms.
 *
 * This function is a C++ wrapper for \c clGetPlatformIDs().
 *
 * \param num_entries
 *    The number of \c cl_platform_id entries that can be added to \c
 *    platforms. If \c platforms is not \c NULL, the \c num_entries must be
 *    greater than zero
 * \param platforms
 *    Returns a list of OpenCL platforms found. The \c cl_platform_id values
 *    returned in \c platforms can be used to identify a specific OpenCL
 *    platform. If platforms argument is \c NULL, this argument is ignored. The
 *    number ofOpenCL platforms returned is the mininum of the value specified
 *    by \c num_entries or the number of OpenCL platforms available
 * \param num_platforms
 *    Returns the number of OpenCL platforms available. If \c num_platforms is
 *    \c NULL, this argument is ignored
 * \return void
 *
 * \throw clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throw clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throw unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |  \check   |  \check   |  \check   |  \check   |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetPlatformIDs.html">clGetPlatformIDs()</a>
 */ // }}}
void
get_platform_ids(cl_uint num_entries,
                 cl_platform_id* platforms,
                 cl_uint* num_platforms);
/** // doc: get_platform_info(...) {{{
 *
 * \brief Query OpenCL platform layer for platform information.
 *
 * This function is a C++ wrapper for \c clGetGetPlatformInfo().
 *
 * \param platform
 *    The platform ID - one of these returned by clxx::get_platform_ids(),
 *    or can be NULL. If platform is NULL, the behavior is
 *    implementation-defined.
 * \param param_name
 *    An enumeration constant that identifies the platform information being
 *    queried. See \ref platform_info_t for details.
 * \param param_value_size
 *    Specifies the size in bytes of memory pointed to by \c param_value. This
 *    size in bytes must be ≥ size of return type specified in the OpenCL
 *    specification (\c clGetPlatformInfo()).
 * \param param_value
 *    A pointer to memory location where appropriate values for a given
 *    \c param_value will be returned. Possible \c param_value values returned
 *    are described in the OpenCL specification (\c clGetPlatformInfo()). If
 *    \c param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by \c param_value.
 *    If \c param_value_size_ret is \c NULL, it is ignored.
 *
 * \return void
 *
 * \throw clerror_no<status_t::invalid_platform>
 *         when \c clGetPlatformInfo() returns \c CL_INVALID_PLATFORM,
 * \throw clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformInfo() returns \c CL_INVALID_VALUE,
 * \throw clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformInfo() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throw unexpected_clerror
 *         when \c clGetPlatformInfo() returns other status code.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformInfo()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_info() has a bug.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetPlatformInfo.html">clGetPlatformInfo()</a>
 */ // }}}
void
get_platform_info(cl_platform_id platform,
                  platform_info_t param_name,
                  size_t param_value_size,
                  void* param_value,
                  size_t* param_value_size_ret);
/** // doc: get_device_ids() {{{
 * \brief Retrieve device identifiers of locally available OpenCL devices.
 *
 * This function is a C++ wrapper for \c clGetDeviceIDs(). The main difference
 * between clxx::get_device_ids() and \c clGetDeviceIDs() is that it throws
 * exceptions instead of returning error codes.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \e platform is \c NULL, the behavior is
 *        implementation-defined.
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The
 *        \e device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \e device_type are
 *        specified by clxx::device_type_t.
 * \param num_entries
 *        The number of \c cl_device_id entries that can be added to \e
 *        devices. If \e devices is not \c NULL, the \e num_entries must be
 *        greater than zero.
 * \param devices
 *        A list of OpenCL devices found. The \c cl_device_id values returned
 *        in \e devices can be used to identify a specific OpenCL device. If
 *        \e devices argument is \c NULL, this argument is ignored. The number
 *        of OpenCL devices returned is the minimum of the value specified by
 *        \e num_entries or the number of OpenCL devices whose type matches
 *        \e device_type.
 * \param num_devices
 *        Returns the number of OpenCL devices available. If \c num_devices is
 *        \c NULL, this argument is ignored.
 *
 * \return The number of available OpenCL devices
 *
 * \throw clerror_no<status_t::invalid_platform>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_PLATFORM,
 * \throw clerror_no<status_t::invalid_device_type>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_DEVICE_TYPE,
 * \throw clerror_no<status_t::invalid_value>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_VALUE,
 * \throw clerror_no<status_t::out_of_resources>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_RESOURCES,
 * \throw clerror_no<status_t::out_of_host_memory>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throw unexpected_clerror
 *         when \c clGetDeviceIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetDeviceIDs()
 * implementation is not standard conformant, its version is not supported by
 * %clxx, or when get_platform_ids() has a bug.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetDeviceIDs.html">clGetDeviceIDs()</a>
 */ // }}}
void
get_device_ids(cl_platform_id platform,
               device_type_t device_type,
               cl_uint num_entries,
               cl_device_id* devices,
               cl_uint* num_devices);
/** // doc: get_device_info(...) {{{
 * \brief Get certain information from device.
 *
 * This is a wrapper around \c clGetDeviceInfo(). The call to this function
 * yields same information as call to
 *   - \c clGetDeviceInfo(device,name,value_size,value,value_size_ret).
 *
 * The main difference between clxx::get_device_info() and \c clGetDeviceInfo()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param device
 *    %device identifier of type cl_device_id.
 * \param name
 *    An enumeration constant that identifies the device information being
 *    queried. It can be one of the values as specified in the OpenCL
 *    specification (\c clGetDeviceInfo()).
 * \param value_size
 *    Specifies the size in bytes of memory pointed to by \c param_value.
 *    This size in bytes must be greater than or equal to size of return type
 *    specified in the OpenCL specification (\c clGetDeviceInfo()).
 * \param value
 *    A pointer to memory location where appropriate values for a given
 *    \c param_name as specified in the OpenCL specification
 *    (\c clGetDeviceInfo()) will be returned. If \c param_value is \c NULL, it
 *    is ignored.
 * \param value_size_ret
 *    Returns the actual size in bytes of data being queried by \c
 *    param_value. If \c param_value_size_ret is \c NULL, it is ignored
 *
 * \throw  clxx::clerror_no<clxx::status_t::invalid_device>
 *    when \c clGetDeviceInfo() returns \c CL_INVALID_DEVICE,
 * \throw  clxx::clerror_no<clxx::status_t::invalid_value>
 *    when \c clGetDeviceInfo() returns \c CL_INVALID_VALUE,
 * \throw  clxx::clerror_no<clxx::status_t::out_of_resources>
 *    when \c clGetDeviceInfo() returns \c CL_OUT_OF_RESOURCES,
 * \throw  clxx::clerror_no<clxx::status_t::out_of_host_memory>
 *    when \c clGetDeviceInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw  clxx::unexpected_clerror
 *    when \c clGetDeviceInfo() returns any other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetDeviceInfo.html">clGetDeviceInfo()</a>
 */ // }}}
void
get_device_info(cl_device_id device,
                device_info_t name,
                size_t value_size,
                void* value,
                size_t* value_size_ret);
/** // doc: create_context(...) {{{
 * \brief Create OpenCL context
 *
 * This is a wrapper around \c clCreateContext(). The call to this function has
 * same effect as call to
 *   - \c clCreateContext(properties,num_devices,devices,pfn_notify,user_data,errcode_ret)
 *
 * The main difference between clxx::create_context() and \c clCreateContext()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param properties
 *    Specifies a list of context property names and their corresponding
 *    values. Each property name is immediately followed by the corresponding
 *    desired value. The list is terminated with \c 0. \e properties can be
 *    NULL in which case the platform that is selected is
 *    implementation-defined. The list of supported propertes is described in
 *    the OpenCL standard.
 * \param num_devices
 *    The number of devices specified in \e devices argument.
 * \param devices
 *    A pointer to a list of unique devices returned by \ref get_device_ids()
 *    or sub-devices created by \ref create_sub_devices().
 * \param pfn_notify
 *    A callback function that can be registered by the application. This
 *    callback function will be used by the OpenCL implementation to report
 *    information on errors during context creation as well as errors that
 *    occur at runtime in this context. This callback function may be called
 *    asynchronously by the OpenCL implementation. It is the application's
 *    responsibility to ensure that the callback function is thread-save. If
 *    \e pfn_notify is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when \e pfn_notify is called.
 *    \e user_data can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the \e pfn_notify callback.
 *    Where these notification go is implementation-defined.
 *
 * \throw clerror_no<status_t::invalid_platform>
 *    When \c clCreateContext() returns error \c CL_INVALID_PLATFORM
 * \throw clerror_no<status_t::invalid_property>
 *    When \c clCreateContext() returns error \c CL_INVALID_PROPERTY
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateContext() returns error \c CL_INVALID_OPERATION
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateContext() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateContext() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::device_not_available>
 *    When \c clCreateContext() returns error \c CL_DEVICE_NOT_AVAILABLE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateContext() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateContext() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR
 * \throw clerror_no<status_t::invalid_dx9_media_adapter_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_DX9_MEDIA_ADAPTER_KHR
 * \throw clerror_no<status_t::invalid_d3d10_device_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_D3D10_DEVICE_KHR
 * \throw clerror_no<status_t::invalid_d3d11_device_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_D3D11_DEVICE_KHR
 * \throw unexpected_clerror
 *    When \c clCreateContext() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateContext.html">clCreateContext()</a>
 */ // }}}
cl_context
create_context(const cl_context_properties* properties,
               cl_uint num_devices, const cl_device_id* devices,
               void(*pfn_notify)(const char* errinfo,
                                 const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data);
/** // doc: create_context_from_type_from_type(...) {{{
 * \brief Create OpenCL context
 *
 * This is a wrapper around \c clCreateContextFromType(). The call to this function has
 * same effect as call to
 *   - \c clCreateContextFromType(properties,static_cast<cl_device_type>(device_type),pfn_notify,user_data,errcode_ret)
 *
 * The main difference between clxx::create_context_from_type() and
 * \c clCreateContextFromType() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param properties
 *    Specifies a list of context property names and their corresponding
 *    values. Each property name is immediately followed by the corresponding
 *    desired value. The list is terminated with \c 0. \e properties can be
 *    NULL in which case the platform that is selected is
 *    implementation-defined. The list of supported propertes is described in
 *    the OpenCL standard.
 * \param device_type
 *    A bit-field that identifies the type of device, see \ref device_type_t.
 * \param pfn_notify
 *    A callback function that can be registered by the application. This
 *    callback function will be used by the OpenCL implementation to report
 *    information on errors during context creation as well as errors that
 *    occur at runtime in this context. This callback function may be called
 *    asynchronously by the OpenCL implementation. It is the application's
 *    responsibility to ensure that the callback function is thread-save. If
 *    \e pfn_notify is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when \e pfn_notify is called.
 *    \e user_data can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the \e pfn_notify callback.
 *    Where these notification go is implementation-defined.
 *
 * \throw clerror_no<status_t::invalid_platform>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_PLATFORM
 * \throw clerror_no<status_t::invalid_property>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_PROPERTY
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_OPERATION
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::device_not_available>
 *    When \c clCreateContextFromType() returns error \c CL_DEVICE_NOT_AVAILABLE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateContextFromType() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateContextFromType() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR
 * \throw clerror_no<status_t::invalid_dx9_media_adapter_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_DX9_MEDIA_ADAPTER_KHR
 * \throw clerror_no<status_t::invalid_d3d10_device_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_D3D10_DEVICE_KHR
 * \throw clerror_no<status_t::invalid_d3d11_device_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_D3D11_DEVICE_KHR
 * \throw unexpected_clerror
 *    When \c clCreateContextFromType() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateContextFromType.html">clCreateContextFromType()</a>
 */ // }}}
cl_context
create_context_from_type(const cl_context_properties* properties,
                         device_type_t device_type,
                         void(*pfn_notify)(const char* errinfo,
                                           const void* private_info,
                                           size_t cb,
                                           void* user_data),
                         void* user_data);
/** // doc: retain_context(...) {{{
 * \brief Increment the context reference count
 *
 * This is a wrapper around \c clRetainContext(). The call to this function has
 * same effect as call to
 *  - \c clRetainContext(context)
 *
 * The difference between \ref retain_context() and \c clRetainContext() is
 * that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    The OpenCL context to retain.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clRetainContext() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainContext() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainContext() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clRetainContext() returns other error code.
 *
 * \note \ref create_context() and \ref create_context_from_type() perform an
 *    implicit retain.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainContext.html">clRetainContext()</a>
 */ // }}}
void
retain_context(cl_context context);
/** // doc: release_context(...) {{{
 * \brief Decrement the context reference count
 *
 * This is a wrapper around \c clReleaseContext(). The call to this function has
 * same effect as call to
 *  - \c clReleaseContext(context)
 *
 * The difference between \ref release_context() and \c clReleaseContext() is
 * that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    The OpenCL context to release.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clReleaseContext() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseContext() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseContext() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clReleaseContext() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseContext.html">clReleaseContext()</a>
 */ // }}}
void
release_context(cl_context context);
/** // doc: get_context_info(...) {{{
 * \brief Query information about a context.
 *
 * This is a wrapper for \c clGetContextInfo(). The call to \ref
 * get_context_info() has same effect as a call to
 *    - \c clGetContextinfo(context,static_cast<cl_context_info>(param_name),param_value_size,param_value,param_value_size_ret)
 *
 *  The main difference between get_context_info() and \c clGetContextInfo() is
 *  that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    Specifies the OpenCl context being queried.
 * \param param_name
 *    An enumeration constant that specifies the information to query. See \ref
 *    context_info_t.
 * \param param_value_size
 *    Specifies the size in bytes of memory pointed to by \e param_value. This
 *    size must be grater than or equal to the size of return type for
 *    \e param_name as described in the OpenCL standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. if *param_value* is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by
 *    \e param_value. If \e param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clGetContextInfo() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetContextInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetContextInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetContextInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetContextInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetContextInfo.html">clGetContextInfo()</a>
 */ // }}}
void
get_context_info(cl_context context,
                 context_info_t param_name,
                 size_t param_value_size,
                 void* param_value,
                 size_t* param_value_size_ret);
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
/** // doc: create_sub_devices(...) {{{
 * \brief Creates an array of sub-devices that each reference
 *    a non-intersecting set of compute units within \e in_device.
 *
 * This function is a wrapper around \c clCreateSubDevices(). The main
 * difference between \ref create_sub_devices() and \c clCreateSubDevices() is
 * that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param in_device
 *    The device to be partitioned
 * \param properties
 *    Specifies how \e in_device is to be partition described by a partition
 *    name and its corresponding value. Each partition name is immediately
 *    followed by the corresponding desired value. The list is terminated with
 *    0. The list of supported partitioning schemes is described by the OpenCL
 *    standard (ver. 1.2 and later), see documentation for
 *    \c clCreateSubDevices().
 * \param num_devices
 *    Size of memory pointed to by **out_devices&& specified as the number of
 *    \c cl_device_id entries.
 * \param out_devices
 *    The buffer where OpenCL sub-devices will be returned. If \e out_devices
 *    is \c NULL, this argument is ignored. If \e out_devices is not \c NULL,
 *    \e num_devices must be greater than or equal to the number of
 *    sub-devices than \e in_device may be partitioned into according to the
 *    partitioning scheme specified in \e properties.
 * \param num_devices_ret
 *    Returns the number of sub-devices that device may be partitioned into
 *    according to the partitioning scheme specified in \e properties. If
 *    \e num_devices_reg is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateSubDevices() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateSubDevices() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::device_partition_failed>
 *    When \c clCreateSubDevices() returns CL_DEVICE_PARTITION_FAILED.
 * \throw clerror_no<status_t::invalid_device_partition_count>
 *    When \c clCreateSubDevices() returns CL_INVALID_DEVICE_PARTITION_COUNT.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateSubDevices() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateSubDevices() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateSubDevices() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateSubDevices.html">clCreateSubDevices()</a>
 */ // }}}
void
create_sub_devices(cl_device_id in_device,
                   const cl_device_partition_property* properties,
                   cl_uint num_devices,
                   cl_device_id* out_devices,
                   cl_uint *num_devices_ret);
#endif
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
/** // doc: retain_device(...) {{{
 * \brief Increments the \e devices reference count
 *
 * This function is a wrapper around \c clRetainDevice(). The call to this
 * function has same effect as
 *  - \c clRetainDevice(device)
 *
 * The main difference between \ref retain_device() and
 * \c clRetainDevice() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function increments the \e device reference count if \e device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \e device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \e device reference count remains unchanged.
 *
 * \param device
 *    The device to be retained
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clRetainDevice() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainDevice() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainDevice() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clRetainDevice() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainDevice.html">clRetainDevice()</a>
 */ // }}}
void
retain_device(cl_device_id device);
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
/** // doc: release_device(...) {{{
 * \brief Decrements the \e devices reference count
 *
 * This function is a wrapper around \c clReleaseDevice(). The call to this
 * function has same effect as
 *  - \c clReleaseDevice(device)
 *
 * The main difference between \ref release_device() and
 * \c clReleaseDevice() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function decrements the \e device reference count if \e device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \e device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \e device reference count remains unchanged.
 *
 * \param device
 *    The device to be released
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clReleaseDevice() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseDevice() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseDevice() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseDevice() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseDevice.html">clReleaseDevice()</a>
 */ // }}}
void
release_device(cl_device_id device);
#endif
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
/** // doc: create_command_queue(...) {{{
 * \brief Create a command-queue on a specific device
 *
 * This is a wrapper around \c clCreateCommandQueue(). The call to this function has
 * same effect as call to
 *   - \c clCreateCommandQueue(context,device,static_cast<cl_command_queue_properties>(properties),errcode_ret)
 *
 * with \e errcode_ret being defined internaly in the create_command_queue().
 *
 * The main difference between clxx::create_command_queue() and
 * \c clCreateCommandQueue() is that it throws %clxx exceptions
 * instead of returning OpenCL error codes and accepts
 * \ref clxx::command_queue_properties_t "command_queue_properties_t"
 * instead of \c cl_command_queue_properties as the \e properties argument.
 *
 * OpenCL objects such as memory, program and kernel objects are created using
 * a context. Operations on these objects are performed using a command-queue.
 * The command-queue can be used to queue a set of operations (referred to as
 * commands) in order. Having multiple command-queues allows applications to
 * queue multiple independent commands without requiring synchronization. Note
 * that this should work as long as these objects are not being shared. Sharing
 * of objects across multiple command-queues will require the application to
 * perform appropriate synchronization. For more informations see the
 * <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueue.html">documentation of the clCreateCommandQueue()</a>.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param device
 *    Must be a device associated with \e context. It can either be in the list
 *    of devices specified when \e context is created using
 *    \ref clxx::create_context() "create_context()" or have the same device
 *    type as the device type specified when the context is created using
 *    \ref clxx::create_context_from_type() "create_context_from_type()".
 * \param properties
 *    Specifies a list of properties for the command-queue. This is a
 *    bit-field. For bits definitions see documentation of
 *    \ref clxx::command_queue_properties_t "command_queue_properties_t".
 *
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_queue_properties>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_QUEUE_PROPERTIES
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateCommandQueue() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateCommandQueue() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateCommandQueue() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \cross  |    ???    |
 *
 * \cross - \c clCreateCommandQueue() has been removed from OpenCL in the
 * version 2.0, however <tt>CL/cl.h</tt> header still declares it (but
 * marks it as deprecated); as long as \c clCreateCommandQueue() is
 * physically available at the library built time (in both, CL/cl.h and
 * libOpenCL.so), the create_command_queue() will also be present.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueue.html">clCreateCommandQueue()</a>
 */ // }}}
cl_command_queue
create_command_queue(cl_context context,
                     cl_device_id device,
                     command_queue_properties_t properties);
#endif
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
/** // doc: create_command_queue_with_properties(...) {{{
 * \brief Create a host or device command-queue on a specific device
 *
 * This is a wrapper around \c clCreateCommandQueueWithProperties(). The call
 * to this function has same effect as call to
 *   - \c clCreateCommandQueueWithProperties(context,device,properties,errcode_ret)
 *
 * with \e errcode_ret being defined internaly in the
 * create_command_queue_with_properties().
 *
 * The main difference between clxx::create_command_queue_with_properties() and
 * \c clCreateCommandQueueWithProperties() is that it throws %clxx exceptions
 * instead of returning OpenCL error codes.
 *
 * OpenCL objects such as memory, program and kernel objects are created using
 * a context. Operations on these objects are performed using a command-queue.
 * The command-queue can be used to queue a set of operations (referred to as
 * commands) in order. Having multiple command-queues allows applications to
 * queue multiple independent commands without requiring synchronization. Note
 * that this should work as long as these objects are not being shared. Sharing
 * of objects across multiple command-queues will require the application to
 * perform appropriate synchronization. For more informations see the
 * <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueueWithProperties.html">documentation of the clCreateCommandQueueWithProperties()</a>.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param device
 *    Must be a device associated with \e context. It can either be in the list
 *    of devices specified when \e context is created using
 *    \ref clxx::create_context() "create_context()" or have the same device
 *    type as the device type specified when the context is created using
 *    \ref clxx::create_context_from_type() "create_context_from_type()".
 * \param properties
 *    Specifies a list of properties for the command-queue and their
 *    corresponding values. Each property name is immediately followed by the
 *    corresponding desired value. This list is terminated with 0. The list of
 *    supported properties is defined in the OpenCL standard. If a supported
 *    property and its value is not specified in \e properties, its default
 *    value will be used. \e properties can be \c NULL in which case the
 *    default values for supported command-queue properties will be used.
 *
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_queue_properties>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_QUEUE_PROPERTIES
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateCommandQueueWithProperties() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |           |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueueWithProperties.html">clCreateCommandQueueWithProperties()</a>
 */ // }}}
cl_command_queue
create_command_queue_with_properties(cl_context context,
                                     cl_device_id device,
                                     const cl_queue_properties* properties);
#endif
/** // doc: retain_command_queue(...) {{{
 * \brief Increment the \e command_queue reference count
 *
 * This is a wrapper around \c clRetainCommandQueue(). The call to this
 * function has same effect as call to
 *  - \c clRetainCommandQueue(command_queue)
 *
 * The difference between \ref retain_command_queue() and
 * \c clRetainCommandQueue() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    The OpenCL command-queue to retain.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clRetainCommandQueue() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainCommandQueue() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainCommandQueue() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clRetainCommandQueue() returns other error code.
 *
 * \note \ref create_command_queue() performs an implicit retain.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainCommandQueue.html">clRetainCommandQueue()</a>
 */ // }}}
void
retain_command_queue(cl_command_queue command_queue);
/** // doc: release_command_queue(...) {{{
 * \brief Decrement the \e command_queue reference count
 *
 * This is a wrapper around \c clReleaseCommandQueue(). The call to this
 * function has same effect as call to
 *  - \c clReleaseCommandQueue(command_queue)
 *
 * The difference between \ref release_command_queue() and
 * \c clReleaseCommandQueue() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    The OpenCL command-queue to release.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clReleaseCommandQueue() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseCommandQueue() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseCommandQueue() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clReleaseCommandQueue() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseCommandQueue.html">clReleaseCommandQueue()</a>
 */ // }}}
void
release_command_queue(cl_command_queue command_queue);
/** // doc: get_command_queue_info(...) {{{
 * \brief Query information about a command-queue.
 *
 * This is a wrapper for \c clGetCommandQueueInfo(). The call to \ref
 * get_command_queue_info() has same effect as a call to
 *    - \c clGetCommandQueueinfo(command_queue,static_cast<cl_command_queue_info>(param_name),param_value_size,param_value,param_value_size_ret)
 *
 *  The main difference between get_command_queue_info() and
 *  \c clGetCommandQueueInfo() is that it throws %clxx exceptions instead of
 *  returning OpenCL error codes.
 *
 * \param command_queue
 *    Specifies the OpenCl command-queue being queried.
 * \param param_name
 *    An enumeration constant that specifies the information to query. See
 *    \ref command_queue_info_t.
 * \param param_value_size
 *    Specifies the size in bytes of memory pointed to by \e param_value. This
 *    size must be grater than or equal to the size of return type for
 *    \e param_name as described in the OpenCL standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \e param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by
 *    \e param_value. If \e param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clGetCommandQueueInfo() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetCommandQueueInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetCommandQueueInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetCommandQueueInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetCommandQueueInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetCommandQueueInfo.html">clGetCommandQueueInfo()</a>
 */ // }}}
void
get_command_queue_info(cl_command_queue command_queue,
                       command_queue_info_t param_name,
                       size_t param_value_size,
                       void* param_value,
                       size_t* param_value_size_ret);
/** // doc: create_buffer() {{{
 * \todo Write documentation
 */ // }}}
cl_mem
create_buffer(cl_context context,
              mem_flags_t flags,
              size_t size,
              void* host_ptr);
#if CLXX_OPENCL_ALLOWED(clCreateSubBuffer)
/** // doc: create_sub_buffer() {{{
 * \todo Write documentation
 */ // }}}
cl_mem
create_sub_buffer(cl_mem buffer,
                  mem_flags_t flags,
                  buffer_create_type_t buffer_create_type,
                  const void* buffer_create_info);
#endif
/** // doc: enqueue_read_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_read_buffer(cl_command_queue command_queue,
                    cl_mem buffer,
                    cl_bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event);
/** // doc: enqueue_write_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_write_buffer(cl_command_queue command_queue,
                     cl_mem buffer,
                     cl_bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event);
/** // doc: enqueue_copy_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_buffer(cl_command_queue command_queue,
                    cl_mem src_buffer,
                    cl_mem dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void*
enqueue_map_buffer(cl_command_queue command_queue,
                   cl_mem buffer,
                   cl_bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event);
/** // doc: get_supported_image_formats() {{{
 * \todo Write documentation
 */ // }}}
void
get_supported_image_formats(cl_context context,
                            mem_flags_t flags,
                            mem_object_type_t image_type,
                            cl_uint num_entries,
                            cl_image_format* image_formats,
                            cl_uint* num_image_formats);
/** // doc: enqueue_read_image() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_read_image(cl_command_queue command_queue,
                   cl_mem image,
                   cl_bool blocking_read,
                   const size_t* origin,
                   const size_t* region,
                   size_t row_pitch,
                   size_t slice_pitch,
                   void* ptr,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event);
/** // doc: enqueue_write_image() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_write_image(cl_command_queue command_queue,
                    cl_mem image,
                    cl_bool blocking_write,
                    const size_t* origin,
                    const size_t* region,
                    size_t input_row_pitch,
                    size_t input_slice_pitch,
                    const void* ptr,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event);
/** // doc: enqueue_copy_image() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_image(cl_command_queue command_queue,
                   cl_mem src_image,
                   cl_mem dst_image,
                   const size_t* src_origin,
                   const size_t* dst_origin,
                   const size_t* region,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event);
/** // doc: enqueue_copy_image_to_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_image_to_buffer(cl_command_queue command_queue,
                             cl_mem src_image,
                             cl_mem dst_buffer,
                             const size_t* src_origin,
                             const size_t* region,
                             size_t dst_offset,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event);
/** // doc: enqueue_copy_buffer_to_image() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_buffer_to_image(cl_command_queue command_queue,
                             cl_mem src_buffer,
                             cl_mem dst_image,
                             size_t src_offset,
                             const size_t* dst_origin,
                             const size_t* region,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event);
/** // doc: enqueue_map_image() {{{
 * \todo Write documentation
 */ // }}}
void*
enqueue_map_image(cl_command_queue command_queue,
                  cl_mem image,
                  cl_bool blocking_map,
                  map_flags_t map_flags,
                  const size_t* origin,
                  const size_t* region,
                  size_t* image_row_pitch,
                  size_t* image_slice_pitch,
                  cl_uint num_events_in_wait_list,
                  const cl_event* event_wait_list,
                  cl_event* event);
/** // doc: enqueue_unmap_mem_object() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_unmap_mem_object(cl_command_queue command_queue,
                         cl_mem memobj,
                         void* mapped_ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event);
/** // doc: enqueue_migrate_mem_objects() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_migrate_mem_objects(cl_command_queue command_queue,
                            cl_uint num_mem_objects,
                            const cl_mem* mem_objects,
                            mem_migration_flags_t flags,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event);
/** // doc: get_image_info() {{{
 * \todo Write documentation
 */ // }}}
void
get_image_info(cl_mem image,
               image_info_t param_name,
               size_t param_value_size, void* param_value,
               size_t* param_value_size_ret);
/** // doc: get_mem_object_info() {{{
 * \todo Write documentation
 */ // }}}
void
get_mem_object_info(cl_mem memobj,
                    mem_info_t param_name,
                    size_t param_value_size, void* param_value,
                    size_t* param_value_size_ret);
/** // doc: retain_mem_object() {{{
 * \todo Write documentation
 */ // }}}
void
retain_mem_object(cl_mem memobj);
/** // doc: release_mem_object() {{{
 * \todo Write documentation
 */ // }}}
void
release_mem_object(cl_mem memobj);
/** // doc: create_program_with_source(...) {{{
 * \brief Creates a program object for a context, and loads the source
 *    code specified by the text strings in the \e strings array into the program
 *    object.
 *
 * This function is a wrapper around \c clCreateProgramWithSource(). The call
 * to this function has same effect as
 *  - \c clCreateProgramWithSource(context, count, strings, lengths, &errcode_ret)
 * with \c errcode_ret defined internally in create_program_with_source().
 *
 * The main difference between \ref create_program_with_source() and
 * \c clCreateProgramWithSource() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * This function creates a program object for a context, and loads the source
 * code specified by the text strings in the \e strings array into the program
 * object. The devices associated with the program object are the devices
 * associated with \e context. The source code specified by \e strings is
 * either an OpenCL C program source, header or implementation-defined source
 * for custom devices that support an online compiler.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param count
 *    Number of elements in \e strings and \e lengths.
 * \param strings
 *    An array of \e count pointers to optionally null-terminated character
 *    strings that make up the source code.
 * \param lengths
 *    An array with the number of chars in each string (the string length). I
 *    an element in lengths i zero, its accompanuing string is null-terminated.
 *    If \e lengths is NULL, all strings in the \e strings argument are
 *    considered null-terminated. Any length value passed in that is greater
 *    than zero excludes the null terminator in its count.
 *
 * \returns
 *    A valid non-zero program object if the program object is created
 *    successfully (otherwise it throws an exception).
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithSource() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithSource() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithSource() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateProgramWithSource.html">clCreateProgramWithSource()</a>
 */ // }}}
cl_program
create_program_with_source(cl_context context,
                           cl_uint count,
                           const char** strings,
                           const size_t* lengths);
/** // doc: create_program_with_binary(...) {{{
 * \brief Creates a program object for a context, and loads the binary bits
 *    specified by binary into the program object
 *
 * This function is a wrapper around \c clCreateProgramWithBinary(). The call
 * to this function has same effect as
 *  - \c clCreateProgramWithBinary(context, num_devices, device_list, lengths, binaries, binary_status, &errcode_ret)
 * with \c errcode_ret defined internally in create_program_with_binary().
 *
 * The main difference between \ref create_program_with_binary() and
 * \c clCreateProgramWithBinary() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * OpenCL allows applications to create a program object using the program
 * source or binary and build appropriate program executables. This can be very
 * useful as it allows applications to load program source and then compile and
 * link to generate a program executable online on its first instance for
 * appropriate OpenCL devices in the system. These executables can now be
 * queried and cached by the application. Future instances of the application
 * launching will no longer need to compile and link the program executables.
 * The cached executables can be read and loaded by the application, which can
 * help significantly reduce the application initialization time.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param num_devices
 *    The number of devices listed in \e device_list.
 *    The devices associated with the program object will be the list of
 *    devices specified by \e device_list. The list of devices specified by \e
 *    device_list must be devices associated with context.
 * \param device_list
 *    A pointer to a list of devices that are in \e context. \c device_list
 *    must be a non-NULL value. The binaries are loaded for devices specified
 *    in this list.
 * \param lengths
 *    Lengths of the \e binaries arrays. For each \c i \e lengths[i] defines
 *    length of \e binaries[i] array.
 * \param binaries
 *    An array of pointers to program binaries to be loaded for devices
 *    specified by \e device_list. For each device given by \e device_list[i],
 *    the pointer to the program binary for that device is given by
 *    \e binaries[i] and the length of this corresponding binary is given by
 *    \e lengths[i]. \e lengths[i] cannot be zero and \e binaries[i] cannot be
 *    a NULL pointer. The program binaries specified by binaries contain the
 *    bits that describe one of the following:
 *      - a program executable to be run on the device(s) associated with \e context.
 *      - a compiled program for \e device(s) associated with context.
 *      - a library of compiled programs for \e device(s) associated with context.
 *    The program binary can consist of either or both of device-specific code
 *    and/or implementation-specific intermediate representation (IR) which
 *    will be converted to the device-specific code.
 * \param binary_status
 *    Returns whether the program binary for each device specified in
 *    device_list was loaded successfully or not. It is an array of
 *    \e num_devices entries and returns \c CL_SUCCESS in \e binary_status[i]
 *    if binary was successfully loaded for device specified by \e device_list[i];
 *    otherwise returns CL_INVALID_VALUE if \e lengths[i] is zero or if
 *    \e binaries[i] is a \c NULL value or \c CL_INVALID_BINARY in
 *    \e binary_status[i] if program binary is not a valid binary for the
 *    specified device. If \e binary_status is \c NULL, it is ignored.
 *
 * \returns
 *    A valid non-zero program object if the program object is created
 *    successfully (otherwise it throws an exception).
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_binary>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_BINARY.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithBinary() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithBinary() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithBinary() returns other error code.
 *
 * \note This function throws <tt>clerror_no<status_t::invalid_binary></tt>
 *    if any of the provided binaries is invalid. Before raising the exception,
 *    the array pointed to by \e binary_status gets filled with error
 *    information. To ensure that storage for \e binary_status is maintained
 *    properly and does not go out of scope when exception is caught or
 *    propagated, the following (or similar) code pattern should be used
 *    \code
 *      cl_int binary_status[SIZE]; // the array declared in the outer scope
 *      cl_program program = NULL;
 *      try {
 *        program = create_program_with_binary( ..., binary_status );
 *      } catch(clerror_no<status_t::invalid_binary> const& e) {
 *        // scan binary_status to find out which binary caused the problem ...
 *      }
 *    \endcode
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateProgramWithBinary.html">clCreateProgramWithBinary()</a>
 */ // }}}
cl_program
create_program_with_binary(cl_context context,
                           cl_uint num_devices,
                           const cl_device_id* device_list,
                           const size_t* lengths,
                           const unsigned char** binaries,
                           cl_int* binary_status);
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
/** // doc: create_program_with_built_in_kernels(...) {{{
 * \brief  Creates a program object for a context, and loads the information
 * related to the built-in kernels into a program object.
 *
 * This function is a wrapper around \c clCreateProgramWithBuiltInKernels().
 * The call to this function has same effect as
 *  - \c clCreateProgramWithBuiltInKernels(context, num_devices, device_list, kernel_names, &errcode_ret)
 *
 * with \c errcode_ret defined internally in create_program_with_built_in_kernels().
 *
 * The main difference between \ref create_program_with_built_in_kernels() and
 * \c clCreateProgramWithBuiltInKernels() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function decrements the \e device reference count if \e device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \e device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \e device reference count remains unchanged.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param num_devices
 *    The number of devices listed in \e device_list.
 * \param device_list
 *    A pointer to a list of devices that are in \e context. \e device_list
 *    must be a non-NULL value. The built-in kernels are loaded for devices
 *    specified in this list. The devices associated with the program object
 *    will be the list of devices specified by \e device_list. The list of
 *    devices specified by device_list must be devices associated with context.
 * \param kernel_names
 *    A semi-colon separated list of built-in kernel names.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithBuiltInKernels() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateProgramWithBuiltInKernels.html">clCreateProgramWithBuiltInKernels()</a>
 */ // }}}
cl_program
create_program_with_built_in_kernels(cl_context context,
                                     cl_uint num_devices,
                                     const cl_device_id* device_list,
                                     const char* kernel_names);
#endif
/** // doc: retain_program(...) {{{
 * \brief Increments the \e program reference count
 *
 * This function is a wrapper around \c clRetainProgram(). The call to this
 * function has same effect as
 *  - \c clRetainProgram(program)
 *
 * The main difference between \ref retain_program() and
 * \c clRetainProgram() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * \note create_program_with_source(), create_program_with_binary() and
 *    create_program_with_built_in_kernels() does an implicit retain. The same
 *    applies to \c clCreateProgramXyz() functions.
 *
 * \param program
 *    The program to be retained
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clRetainProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clRetainProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainProgram.html">clRetainProgram()</a>
 */ // }}}
void
retain_program(cl_program program);
/** // doc: release_program(...) {{{
 * \brief Decrements the \e program reference count
 *
 * This function is a wrapper around \c clReleaseProgram(). The call to this
 * function has same effect as
 *  - \c clReleaseProgram(program)
 *
 * The main difference between \ref release_program() and
 * \c clReleaseProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note The program object is deleted after all kernel objects associated with
 *    program have been deleted and the program reference count becomes zero.
 *
 * \param program
 *    The program to be released
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clReleaseProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseProgram.html">clReleaseProgram()</a>
 */ // }}}
void
release_program(cl_program program);
/** // doc: build_program(...) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *    source or binary
 *
 * This function is a wrapper around \c clBuildProgram(). The call to this
 * function has same effect as
 *  - \c clBuildProgram(program, num_devices, device_list, options, pfn_notify, user_data)
 *
 * The main difference between \ref build_program() and
 * \c clBuildProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all the devices or a specific device(s) in the OpenCL context
 * associated with program. OpenCL allows program executables to be built
 * using the source or the binary. \ref build_program() must be called for
 * program created using either create_program_with_source() or
 * create_program_with_binary() to build the program executable for one or
 * more devices associated with \e program. If \e program is created with
 * create_program_with_binary(), then the program binary must be an executable
 * binary (not a compiled binary or library).
 *
 * The executable binary can be queried using get_program_info(program,
 * program_info_t::binaries, ...) and can be specified to
 * create_program_with_binary() to create a new program object.
 *
 * \par Compiler Options
 *
 * See [clBuildProgram()](https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clBuildProgram.html).
 *
 * \param program
 *    The program object.
 * \param num_devices
 *    The number of devices listed in \e device_list.
 * \param device_list
 *    A pointer to a list of devices associated with program. If device_list is
 *    \c NULL value, the program executable is built for all devices associated
 *    with program for which a source or binary has been loaded. If device_list
 *    is a non-NULL value, the program executable is built for devices
 *    specified in this list for which a source or binary has been loaded.
 * \param options
 *    A pointer to a null-terminated string of characters that describes the
 *    build options to be used for building the program executable. The list of
 *    supported options is described in the OpenCL standard.
 * \param pfn_notify
 *    A function pointer to a notification routine. The notification routine is
 *    a callback function that an application can register and which will be
 *    called when the program executable has been built (successfully or
 *    unsuccessfully). If \e pfn_notify is not \c NULL, build_program() does
 *    not need to wait for the build to complete and can return immediately
 *    once the build operation can begin. The build operation can begin if the
 *    context, program whose sources are being compiled and linked, list of
 *    devices and build options specified are all valid and appropriate host
 *    and device resources needed to perform the build are available. If
 *    \e pfn_notify is \c NULL, build_program() does not return until the build
 *    has completed. This callback function may be called asynchronously by the
 *    OpenCL implementation. It is the application’s responsibility to ensure
 *    that the callback function is thread-safe.
 * \param user_data
 *    Passed as an argument when \e pfn_notify is called. \e user_data can be
 *    \c NULL.
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clBuildProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clBuildProgram() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clBuildProgram() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_binary>
 *    When \c clBuildProgram() returns CL_INVALID_BINARY.
 * \throw clerror_no<status_t::invalid_build_options>
 *    When \c clBuildProgram() returns CL_INVALID_BUILD_OPTIONS.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clBuildProgram() returns CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::compiler_not_available>
 *    When \c clBuildProgram() returns CL_COMPILER_NOT_AVAILABLE.
 * \throw clerror_no<status_t::build_program_failure>
 *    When \c clBuildProgram() returns CL_BUILD_PROGRAM_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clBuildProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clBuildProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clBuildProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clBuildProgram.html">clBuildProgram()</a>
 */ // }}}
void
build_program(cl_program program,
              cl_uint num_devices,
              const cl_device_id* device_list,
              const char* options,
              void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
              void* user_data);
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
/** // doc: compile_program(...) {{{
 * \brief Compiles a program’s source for all the devices or a specific
 *    device(s) in the OpenCL context associated with program.
 *
 * This function is a wrapper around \c clCompileProgram(). The call to this
 * function has same effect as
 *  - \c clCompileProgram(program, num_devices, device_list, options, num_input_headers, input_headers, header_include_names, pfn_notify, user_data)
 *
 * The main difference between \ref compile_program() and
 * \c clCompileProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * Compiles a program’s source for all the devices or a specific device(s) in
 * the OpenCL context associated with \e program. The pre-processor runs before
 * the program sources are compiled. The compiled binary is built for all
 * devices associated with \e program or the list of devices specified. The
 * compiled binary can be queried using get_program_info(program,
 * program_info_t::binaries, ...) and can be specified to
 * create_program_with_binary() to create a new program object.
 *
 * \par Compiler Options
 *
 * See [clCompileProgram()](https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCompileProgram.html).
 *
 * \param program
 *    The program object that is the compilation target.
 * \param num_devices
 *    The number of devices listed in \e device_list.
 * \param device_list
 *    A pointer to a list of devices associated with program. If \e device_list
 *    is a \c NULL value, the compile is performed for all devices associated
 *    with program. If device_list is a non-NULL value, the compile is
 *    performed for devices specified in this list.
 * \param options
 *    A pointer to a null-terminated string of characters that describes the
 *    compilation options to be used for building the program executable.
 * \param num_input_headers
 *    Specifies the number of programs that describe headers in the array
 *    referenced by \e input_headers.
 * \param input_headers
 *    An array of program embedded headers created with
 *    create_program_with_source().
 * \param header_include_names
 *    An array that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 * \param pfn_notify
 *    A function pointer to a notification routine. The notification routine is
 *    a callback function that an application can register and which will be
 *    called when the program executable has been built (successfully or
 *    unsuccessfully). If \e pfn_notify is not \c NULL, compile_program() does
 *    not need to wait for the compile to complete and can return immediately
 *    once the compile operation can begin. The compile operation can begin if the
 *    context, program whose sources are being compiled and linked, list of
 *    devices and compile options specified are all valid and appropriate host
 *    and device resources needed to perform the compile are available. If
 *    \e pfn_notify is \c NULL, compile_program() does not return until the compile
 *    has completed. This callback function may be called asynchronously by the
 *    OpenCL implementation. It is the application’s responsibility to ensure
 *    that the callback function is thread-safe.
 * \param user_data
 *    Passed as an argument when \e pfn_notify is called. \e user_data can be
 *    \c NULL.
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clCompileProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCompileProgram() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCompileProgram() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_compiler_options>
 *    When \c clCompileProgram() returns CL_COMPILER_OPTIONS.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCompileProgram() returns CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::compiler_not_available>
 *    When \c clCompileProgram() returns CL_COMPILER_NOT_AVAILABLE.
 * \throw clerror_no<status_t::compile_program_failure>
 *    When \c clCompileProgram() returns CL_COMPILE_PROGRAM_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCompileProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCompileProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCompileProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCompileProgram.html">clCompileProgram()</a>
 */ // }}}
void
compile_program(cl_program program,
                cl_uint num_devices,
                const cl_device_id* device_list,
                const char* options,
                cl_uint num_input_headers,
                const cl_program* input_headers,
                const char** header_include_names,
                void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
                void* user_data);
#endif
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
/** // doc: link_program(...) {{{
 * \brief Links a set of compiled program objects and libraries for all the
 *    devices or a specific device(s) in the OpenCL context and creates an
 *    executable.
 *
 * This function is a wrapper around \c clLinkProgram(). The call to this
 * function has same effect as
 *  - \c clLinkProgram(context, num_devices, device_list, options, num_input_programs, input_programs, pfn_notify, user_data, &errcode_ret)
 * with \e errcode_ret being defined internally in link_program().
 *
 *
 * The main difference between \ref link_program() and
 * \c clLinkProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 *  link_program() creates a new program object which contains this executable.
 *  The executable binary can be queried using get_program_info(program,
 *  program_info_t::binaries, ...) and can be specified to
 *  create_program_with_binary() to create a new program object.
 *
 *  The devices associated with the returned program object will be the list of
 *  devices specified by \e device_list or if \e device_list is \c NULL it will
 *  be the list of devices associated with \e context.
 *
 *  The linking operation can begin if the context, list of devices, input
 *  programs and linker options specified are all valid and appropriate host
 *  and device resources needed to perform the link are available. If the
 *  linking operation can begin, link_program() returns a valid non-zero
 *  program object.
 *
 * \b Linker Options
 *
 * See [clLinkProgram()](https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clLinkProgram.html).
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param num_devices
 *    The number of devices listed in \e device_list.
 * \param device_list
 *    A pointer to a list of devices that are in context. If device_list is a
 *    NULL value, the link is performed for all devices associated with context
 *    for which a compiled object is available. If device_list is a non-NULL
 *    value, the compile is performed for devices specified in this list for
 *    which a source has been loaded.
 * \param options
 *    A pointer to a null-terminated string of characters that describes the
 *    link options to be used for building the program executable.
 * \param num_input_programs
 *    Specifies the number of programs in array referenced by \e input_programs.
 * \param input_programs
 *    An array of program objects that are compiled binaries or libraries that
 *    are to be linked to create the program executable. For each device in
 *    \e device_list or if device_list is \c NULL the list of devices
 *    associated with \e context, the following cases occur:
 *      - All programs specified by \e input_programs contain a compiled binary
 *        or library for the device. In this case, a link is performed to
 *        generate a program executable for this device.
 *      - None of the programs contain a compiled binary or library for that
 *        device. In this case, no link is performed and there will be no
 *        program executable generated for this device.
 *      - All other cases will throw clerror_no<status_t::invalid_operation>.
 * \param pfn_notify
 *    A function pointer to a notification routine. The notification routine is
 *    a callback function that an application can register and which will be
 *    called when the program executable has been built (successfully or
 *    unsuccessfully). If \e pfn_notify is not \c NULL, link_program() does
 *    not need to wait for the link to complete and can return immediately
 *    once the link operation can begin. The link operation can begin if the
 *    context, program whose sources are being linkd and linked, list of
 *    devices and link options specified are all valid and appropriate host
 *    and device resources needed to perform the link are available. If
 *    \e pfn_notify is \c NULL, link_program() does not return until the link
 *    has completed. This callback function may be called asynchronously by the
 *    OpenCL implementation. It is the application’s responsibility to ensure
 *    that the callback function is thread-safe.
 * \param user_data
 *    Passed as an argument when \e pfn_notify is called. \e user_data can be
 *    \c NULL.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clLinkProgram() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clLinkProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clLinkProgram() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clLinkProgram() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_linker_options>
 *    When \c clLinkProgram() returns CL_LINKER_OPTIONS.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clLinkProgram() returns CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::linker_not_available>
 *    When \c clLinkProgram() returns CL_LINKER_NOT_AVAILABLE.
 * \throw clerror_no<status_t::link_program_failure>
 *    When \c clLinkProgram() returns CL_LINK_PROGRAM_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clLinkProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clLinkProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clLinkProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clLinkProgram.html">clLinkProgram()</a>
 */ // }}}
cl_program
link_program(cl_context context,
             cl_uint num_devices,
             const cl_device_id* device_list,
             const char* options,
              cl_uint num_input_programs,
              const cl_program* input_programs,
              void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
              void* user_data);
#endif
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
/** // doc: unload_platform_compiler(...) {{{
 * \brief Allows the implementation to release the resources allocated by the
 *    OpenCL compiler for \e platform.
 *
 * This function is a wrapper around \c clUnloadPlatformCompiler(). The call to
 * this function has same effect as
 *  - \c clUnloadPlatformCompiler(platform)
 *
 * The main difference between \ref unload_platform_compiler() and
 * \c clUnloadPlatformCompiler() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * This is a hint from the application and does not guarantee that the compiler
 * will not be used in the future or that the compiler will actually be
 * unloaded by the implementation. Calls to build_program(), compile_program(),
 * or link_program() after unload_platform_compiler() will reload the compiler,
 * if necessary, to build the appropriate program executable.
 *
 * \param platform
 *    The platform whose compiler may be unloaded
 *
 * \throw clerror_no<status_t::invalid_platform>
 *    When \c clUnloadPlatformCompiler() returns CL_INVALID_PLATFORM.
 * \throw unexpected_clerror
 *    When \c clUnloadPlatformCompiler() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clUnloadPlatformCompiler.html">clUnloadPlatformCompiler()</a>
 */ // }}}
void
unload_platform_compiler(cl_platform_id platform);
#endif
/** // doc: get_program_info {{{
 * \brief Returns information about the program object.
 *
 * This function is a wrapper around \c clGetProgramInfo(). The call to this
 * function has same effect as
 *  - \c clGetProgramInfo(program, static_cast<cl_program_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between \ref get_program_info() and
 * \c clGetProgramInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes and accepts \ref clxx::program_info_t
 * "program_info_t" instead of \c cl_program_info as \e param_name.
 *
 * \param program
 *    Specifies the program object being queried.
 * \param param_name
 *    Specifies the information to query. The list of supported \e param_name
 *    types is documented in \ref clxx::program_info_t "program_info_t".
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by param_value.
 *    This size must be >= size of return type as described in the table above.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to param_value. If
 *    \e param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetProgramInfo() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clGetProgramInfo() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When \c clGetProgramInfo() returns CL_INVALID_PROGRAM_EXECUTABLE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetProgramInfo() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetProgramInfo() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetProgramInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetProgramInfo.html">clGetProgramInfo()</a>
 */ // }}}
void
get_program_info(cl_program program,
                 program_info_t param_name,
                 size_t param_value_size,
                 void* param_value,
                 size_t* param_value_size_ret);
/** // doc: get_program_build_info {{{
 * \brief Returns build information for each device in the program object.
 *
 * This function is a wrapper around \c clGetProgramBuildInfo(). The call to this
 * function has same effect as
 *  - \c clGetProgramBuildInfo(program, device, static_cast<cl_program_build_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between \ref get_program_build_info() and
 * \c clGetProgramBuildInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes and accepts \ref clxx::program_build_info_t
 * "program_build_info_t" instead of \c cl_program_build_info as \e param_name.
 *
 * A program binary (compiled binary, library binary or executable binary)
 * built for a parent device can be used by all its sub-devices. If a program
 * binary has not been built for a sub-device, the program binary associated
 * with the parent device will be used.
 *
 * A program binary for a device specified with create_program_with_binary() or
 * queried using get_program_info() can be used as the binary for the
 * associated root device, and all sub-devices created from the root-level
 * device or sub-devices thereof.
 *
 * \param program
 *    Specifies the program object being queried.
 * \param device
 *    Specifies the device for which build information is being queried. \e
 *    device must be a valid device associated with \e program.
 * \param param_name
 *    Specifies the information to query. The list of supported \e param_name
 *    types is documented in \ref clxx::program_build_info_t "program_build_info_t".
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by param_value.
 *    This size must be >= size of return type as described in the table above.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to param_value. If
 *    \e param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clGetProgramBuildInfo() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetProgramBuildInfo() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clGetProgramBuildInfo() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetProgramBuildInfo() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetProgramBuildInfo() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetProgramBuildInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetProgramBuildInfo.html">clGetProgramBuildInfo()</a>
 */ // }}}
void
get_program_build_info(cl_program program,
                       cl_device_id device,
                       program_build_info_t param_name,
                       size_t param_value_size, void* param_value,
                       size_t* param_value_size_ret);
/** // doc: create_kernel() {{{
 * \brief Creates OpenCL kernel
 *
 * This function is a wrapper around \c clCreateKernel(). The call to this
 * function has same effect as
 * - \c clCreateKernel(program, kernel_name, &errcode_ret),
 * with \c errcode_ret being defined internally in #create_kernel().
 *
 * The main difference between #create_kernel() and \c clCreateKernel() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * A kernel is a function declared in a program. A kernel is identified by the
 * \c __kernel qualifier applied to any function in a program. A kernel object
 * encapsulates the specific \c __kernel function declared in a program and the
 * argument values to be used when executing this \c __kernel function.
 *
 * \param program A program object with a successfully built executable.
 * \param kernel_name A function name in the program declared with the __kernel qualifier.
 * \returns A handle to the newly created kernel object
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clCreateKernel() returns CL_INVALID_PROGRAM
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When \c clCreateKernel() returns CL_INVALID_PROGRAM_EXECUTABLE
 * \throw clerror_no<status_t::invalid_kernel_name>
 *    When \c clCreateKernel() returns CL_INVALID_KERNEL_NAME
 * \throw clerror_no<status_t::invalid_kernel_definition>
 *    When \c clCreateKernel() returns CL_INVALID_KERNEL_DEFINITION
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateKernel() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateKernel() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateKernel() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateKernel() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clXxx.html">clXxx()</a>
 */ // }}}
cl_kernel
create_kernel(cl_program program,
              const char* kernel_name);
/** // doc: create_kernels_in_program() {{{
 * \brief Create kernel objects for all kernel functions in \em program
 *
 * This function is a wrapper around \c clCreateKernelsInProgram(). The call to
 * this function has same effect as
 * - \c clCreateKernelsInProgram(program, num_kernels, kernels, num_kernels_ret).
 *
 * The main difference between #create_kernels_in_program() and
 * \c clCreateKernelsInProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param program
 *    A program object with a successfully built executable.
 * \param num_kernels
 *    The size of memory pointed to by \em kernels specified as the number of
 *    \c cl_kernel entries.
 * \param kernels
 *    The buffer where the kernel objects for kernels in program will be
 *    returned. If kernels is \c NULL, it is ignored. If kernels is not \c NULL,
 *    \em num_kernels must be greater than or equal to the number of kernels in
 *    program.
 * \param num_kernels_ret
 *    The number of kernels in program. If \em num_kernels_ret is \c NULL, it
 *    is ignored.
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clCreateKernelsInProgram() returns CL_INVALID_PROGRAM
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When \c clCreateKernelsInProgram() returns CL_INVALID_PROGRAM_EXECUTABLE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateKernelsInProgram() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateKernelsInProgram() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateKernelsInProgram() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateKernelsInProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateKernelsInProgram.html">clCreateKernelsInProgram()</a>
 */ // }}}
void
create_kernels_in_program(cl_program program,
                          cl_uint num_kernels,
                          cl_kernel* kernels,
                          cl_uint* num_kernels_ret);
/** // doc: get_kernel_info() {{{
 * \brief Returns information about the kernel object
 *
 * This function is a wrapper around \c clGetKernelInfo(). The call to
 * this function has same effect as
 * - \c clGetKernelInfo(kernel, static_cast<cl_kernel_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_kernel_info() and
 * \c clGetKernelInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param param_name
 *    Specifies the information to query.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    The actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clGetKernelInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_kernel>
 *    When the \c clGetKernelInfo() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clGetKernelInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clGetKernelInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetKernelInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetKernelInfo.html">clGetKernelInfo()</a>
 */ // }}}
void
get_kernel_info(cl_kernel kernel,
                kernel_info_t param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret);
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
/** // doc: get_kernel_arg_info() {{{
 * \brief Returns information about the arguments of a kernel.
 *
 * This function is a wrapper around \c clGetKernelArgInfo(). The call to
 * this function has same effect as
 * - \c clGetKernelArgInfo(kernel, arg_index, static_cast<cl_kernel_arg_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_kernel_arg_info() and
 * \c clGetKernelArgInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param arg_index
 *    The argument index. Arguments to the kernel are referred by indices that
 *    go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where \c n is
 *    the total number of arguments declared by a kernel.
 * \param param_name
 *    Specifies the argument information to query. The list of supported \em
 *    param_name types and the information returned in \em param_value by
 *    get_kernel_arg_info is described in the OpenCL standard.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be > size of return type as described in the OpenCL
 *    standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_arg_index>
 *    When \c clGetKernelArgInfo() returns CL_INVALID_ARG_INDEX.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetKernelArgInfo() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::arg_info_not_available>
 *    When \c clGetKernelArgInfo() returns CL_ARG_INFO_NOT_AVAILABLE.
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clGetKernelArgInfo() returns CL_INVALID_KERNEL.
 * \throw unexpected_clerror
 *    When \c clGetKernelArgInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetKernelArgInfo.html">clGetKernelArgInfo()</a>
 */ // }}}
void
get_kernel_arg_info(cl_kernel kernel,
                    cl_uint arg_index,
                    kernel_arg_info_t param_name,
                    size_t param_value_size, void* param_value,
                    size_t* param_value_size_ret);
#endif
/** // doc: get_kernel_arg_info() {{{
 * \brief Returns information about the kernel object that may be specific to a device.
 *
 * This function is a wrapper around \c clGetKernelWorkGroupInfo(). The call to
 * this function has same effect as
 * - \c clGetKernelWorkGroupInfo(kernel, device, static_cast<cl_kernel_work_group_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_kernel_work_group_info() and
 * \c clGetKernelWorkGroupInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param device
 *    Identifies a specific device in the list of devices associated with
 *    kernel. The list of devices is the list of devices in the OpenCL context
 *    that is associated with kernel. If the list of devices associated with
 *    kernel is a single device, \em device can be a \c NULL value.
 * \param param_name
 *    Specifies the information to query. The list of supported \em param_name
 *    types is documented in \ref clxx::kernel_work_group_info_t. The
 *    information returned in \em param_value is described in the OpenCL
 *    standard.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type as described in the OpenCL
 *    standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clGetKernelWorkGroupInfo() returns CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetKernelWorkGroupInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clGetKernelWorkGroupInfo() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetKernelWorkGroupInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetKernelWorkGroupInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetKernelWorkGroupInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetKernelWorkGroupInfo.html">clGetKernelWorkGroupInfo()</a>
 */ // }}}
void
get_kernel_work_group_info(cl_kernel kernel,
                           cl_device_id device,
                           kernel_work_group_info_t param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
/** // doc: retain_kernel() {{{
 * \brief Increments the kernel object reference count.
 *
 * This function is a wrapper around \c clRetainKernel(). The call to this
 * function has same effect as
 *  - \c clRetainKernel(kernel)
 *
 * The main difference between #retain_kernel() and \c clRetainKernel() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \note create_kernel() and create_kernels_in_program() do an implicit retain.
 *
 * \param kernel
 *    The kernel to be retained
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clRetainKernel() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainKernel() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainKernel() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clRetainKernel() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainKernel.html">clRetainKernel()</a>
 */ // }}}
void
retain_kernel(cl_kernel kernel);
/** // doc: release_kernel() {{{
 * \brief Decrements the \e kernel reference count
 *
 * This function is a wrapper around \c clReleaseKernel(). The call to this
 * function has same effect as
 *  - \c clReleaseKernel(kernel)
 *
 * The main difference between \ref release_kernel() and
 * \c clReleaseKernel() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note The kernel object is deleted once the number of instances that are
 *       retained to kernel become zero and the kernel object is no longer
 *       needed by any enqueued commands that use kernel.
 *
 * \param kernel
 *    The kernel to be released
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clReleaseKernel() returns CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseKernel() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseKernel() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseKernel() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseKernel.html">clReleaseKernel()</a>
 */ // }}}
void
release_kernel(cl_kernel kernel);
/** // doc: set_kernel_arg() {{{
 * \brief Used to set the argument value for a specific argument of a kernel
 *
 * This function is a wrapper around \c clSetKernelArg(). The call to this
 * function has same effect as
 *  - \c clSetKernelArg(kernel, arg_index, arg_size, arg_value)
 *
 * The main difference between \ref set_kernel_arg() and
 * \c clSetKernelArg() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    A valid kernel object.
 * \param arg_index
 *    The argument index. Arguments to the kernel are referred by indices that
 *    go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where \c n is
 *    the total number of arguments declared by a kernel.
 * \param arg_size
 *    Specifies the size of the argument value. If the argument is a memory
 *    object, the size is the size of the memory object. For arguments declared
 *    with the local qualifier, the size specified will be the size in bytes of
 *    the buffer that must be allocated for the local argument. If the argument
 *    is of type \c sampler_t, the \em arg_size value must be equal to
 *    <tt>sizeof(cl_sampler)</tt>. If the argument is of type \c queue_t, the
 *    \em arg_size value must be equal to <tt>sizeof(cl_command_queue)</tt>.
 *    For all other arguments, the size will be the size of argument type.
 * \param arg_value
 *    A pointer to data that should be used as the argument value for argument
 *    specified by \em arg_index. The argument data pointed to by \em arg_value
 *    is copied and the \em arg_value pointer can therefore be reused by the
 *    application after #set_kernel_arg() returns. The argument value specified
 *    is the value used by all API calls that enqueue kernel
 *    (#enqueue_ndrange_kernel()) until the argument value is changed by a
 *    call to #set_kernel_arg() for kernel.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelArg.html">clSetKernelArg()</a>
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clSetKernelArg() returns CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::invalid_arg_index>
 *    When \c clSetKernelArg() returns CL_INVALID_ARG_INDEX.
 * \throw clerror_no<status_t::invalid_arg_value>
 *    When \c clSetKernelArg() returns CL_INVALID_ARG_VALUE.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clSetKernelArg() returns CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_sampler>
 *    When \c clSetKernelArg() returns CL_INVALID_SAMPLER.
 * \throw clerror_no<status_t::invalid_device_queue>
 *    When \c clSetKernelArg() returns CL_INVALID_DEVICE_QUEUE.
 * \throw clerror_no<status_t::invalid_arg_size>
 *    When \c clSetKernelArg() returns CL_INVALID_ARG_SIZE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetKernelArg() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetKernelArg() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clSetKernelArg() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelArg.html">clSetKernelArg()</a>
 */ // }}}
void
set_kernel_arg(cl_kernel kernel,
               cl_uint arg_index,
               size_t arg_size,
               const void* arg_value);
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
/** // doc: set_kernel_arg_svm_pointer() {{{
 * \brief Used to set a SVM pointer as the argument value for a specific
 *        argument of a kernel
 *
 * This function is a wrapper around \c clSetKernelArgSVMPointer(). The call to this
 * function has same effect as
 *  - \c clSetKernelArgSVMPointer(kernel, arg_index, arg_value)
 *
 * The main difference between \ref set_kernel_arg_svm_pointer() and
 * \c clSetKernelArgSVMPointer() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    A valid kernel object.
 * \param arg_index
 *    The argument index. Arguments to the kernel are referred by indices that
 *    go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where \c n is
 *    the total number of arguments declared by a kernel.
 * \param arg_value
 *    A pointer to the SVM pointer that should be used as the argument value
 *    for argument specified by \em arg_index. The SVM pointer specified is the
 *    value used by all API calls that enqueue kernel (#enqueue_ndrange_kernel())
 *    until the argument value is changed by a call to set_kernel_arg_svm_pointer()
 *    for kernel. The SVM pointer can only be used for arguments that are
 *    declared to be a pointer to global or constant memory. The SVM pointer
 *    value must be aligned according to the argument's type. For example, if
 *    the argument is declared to be global <tt>float4 *p</tt>, the SVM pointer
 *    value passed for \c p must be at a minimum aligned to a \c float4. The
 *    SVM pointer value specified as the argument value can be the pointer
 *    returned by clSVMAlloc or can be a pointer + offset into the SVM region.
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::invalid_arg_index>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_INVALID_ARG_INDEX.
 * \throw clerror_no<status_t::invalid_arg_value>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_INVALID_ARG_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clSetKernelArgSVMPointer() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |           |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelArgSVMPointer.html">clSetKernelArgSVMPointer()</a>
 */ // }}}
void
set_kernel_arg_svm_pointer(cl_kernel kernel,
                           cl_uint arg_index,
                           const void* arg_value);
#endif
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
/** // doc: set_kernel_exec_info() {{{
 * \brief Used to pass additional information other than argument values to a kernel
 *
 * This function is a wrapper around \c clSetKernelExecInfo(). The call to this
 * function has same effect as
 *  - \c clSetKernelExecInfo(kernel, param_name, param_value_size, param_value)
 *
 * The main difference between \ref set_kernel_exec_info() and
 * \c clSetKernelExecInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param param_name
 *    Specifies the information to be passed to kernel. The list of supported
 *    \em param_name types may be found in the documentation of
 *    \ref clxx::kernel_exec_info_t "kernel_exec_info_t". The corresponding
 *    values passed in \em param_value are described in the OpenCL standard.
 * \param param_value_size
 *    Specifies the size in bytes of the memory pointed to by \em param_value.
 * \param param_value
 *    A pointer to memory where the appropriate values determined by
 *    \em param_name are specified.
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clSetKernelExecInfo() returns \c CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clSetKernelExecInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clSetKernelExecInfo() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetKernelExecInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetKernelExecInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clSetKernelExecInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |           |           |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelExecInfo.html">clSetKernelExecInfo()</a>
 */ // }}}
void
set_kernel_exec_info(cl_kernel kernel,
                     kernel_exec_info_t param_name,
                     size_t param_value_size,
                     const void* param_value);
#endif
/** // doc: enqueue_ndrange_kernel() {{{
 * \brief Enqueues a command to execute a kernel on a device
 *
 * This function is a wrapper around \c clEnqueueNDRangeKernel(). The call to this
 * function has same effect as
 *  - \c clEnqueueNDRangeKernel(command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between \ref enqueue_ndrange_kernel() and
 * \c clEnqueueNDRangeKernel() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command-queue. The kernel will be queued for execution on
 *    the device associated with \em %command_queue.
 * \param kernel
 *    A valid kernel object. The OpenCL context associated with \em kernel and
 *    \em %command_queue must be the same.
 * \param work_dim
 *    The number of dimensions used to specify the global work-items and
 *    work-items in the work-group. \em work_dim must be greater than zero and
 *    less than or equal to \c CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS.
 * \param global_work_offset
 *    \em global_work_offset can be used to specify an array of work_dim
 *    unsigned values that describe the offset used to calculate the global ID
 *    of a work-item. If \em global_work_offset is \c NULL, the global IDs
 *    start at offset <tt>(0, 0, ... 0)</tt>.
 * \param global_work_size
 *    Points to an array of \em work_dim unsigned values that describe the
 *    number of global work-items in work_dim dimensions that will execute the
 *    kernel function. The total number of global work-items is computed as
 *    <tt>global_work_size[0] *...* global_work_size[work_dim - 1]</tt>.
 * \param local_work_size
 *    Points to an array of \em work_dim unsigned values that describe the
 *    number of work-items that make up a work-group (also referred to as the
 *    size of the work-group) that will execute the kernel specified by kernel.
 *    See <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueNDRangeKernel.html">clEnqueueNDRangeKernel()</a>
 *    for more details.
 * \param num_events_in_wait_list
 *    Number of events in \em event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \em event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If event_wait_list is
 *    \c NULL, \em num_events_in_wait_list must be \c 0. If event_wait_list is
 *    not \c NULL, the list of events pointed to by \em event_wait_list must be
 *    valid and \em num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \em event_wait_list act as synchronization points.
 *    The context associated with events in \em event_wait_list and
 *    \em %command_queue must be the same. The memory associated with
 *    \em event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular kernel execution
 *    instance. Event objects are unique and can be used to identify a
 *    particular kernel execution instance later on. If event is \c NULL, no
 *    event will be created for this kernel execution instance and therefore it
 *    will not be possible for the application to query or queue a wait for
 *    this particular kernel execution instance. If the event_wait_list and the
 *    event arguments are not \c NULL, the event argument should not refer to
 *    an element of the \em event_wait_list array.
 *
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_PROGRAM_EXECUTABLE
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::invalid_kenel>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::invalid_context>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_kernel_args>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_KERNEL_ARGS
 * \throw clerror_no<status_t::invalid_work_dimension>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_WORK_DIMENSION
 * \throw clerror_no<status_t::invalid_global_work_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_GLOBAL_WORK_SIZE
 * \throw clerror_no<status_t::invalid_global_offset>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_GLOBAL_OFFSET
 * \throw clerror_no<status_t::invalid_work_group_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_WORK_GROUP_SIZE
 * \throw clerror_no<status_t::invalid_work_item_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_WORK_ITEM_SIZE
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When the \c clEnqueueNDRangeKernel() returns CL_MISALIGNED_SUB_BUSSER_OFFSET
 * \throw clerror_no<status_t::invalid_image_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_IMAGE_SIZE
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When the \c clEnqueueNDRangeKernel() returns CL_IMAGE_FORMAT_NOT_SUPPORTED
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clEnqueueNDRangeKernel() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When the \c clEnqueueNDRangeKernel() returns CL_MEM_OBJECT_ALLOCATION_FAILURE
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_EVENT_WAIT_LIST
 * \throw clerror_no<status_t::invalid_operation>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_OPERATION
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clEnqueueNDRangeKernel() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When other error code is returned
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueNDRangeKernel.html">clEnqueueNDRangeKernel()</a>
 */ // }}}
void
enqueue_ndrange_kernel(cl_command_queue command_queue,
                        cl_kernel kernel,
                        cl_uint work_dim,
                        const size_t* global_work_offset,
                        const size_t* global_work_size,
                        const size_t* local_work_size,
                        cl_uint num_events_in_wait_list,
                        const cl_event* event_wait_list,
                        cl_event* event);
/** // doc: enqueue_native_kernel() {{{
 * \brief Enqueues a command to execute a native C/C++ function
 *
 * Enqueues a command to execute a native C/C++ function not compiled using the
 * OpenCL compiler.
 *
 * This function is a wrapper around \c clEnqueueNativeKernel(). The call to this
 * function has same effect as
 *  - \c clEnqueueNativeKernel(command_queue, user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between \ref enqueue_native_kernel() and
 * \c clEnqueueNativeKernel() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command-queue. A native user function can only be executed
 *    on a command-queue created on a device that has \c CL_EXEC_NATIVE_KERNEL
 *    capability set in \c CL_DEVICE_EXECUTION_CAPABILITIES as specified in the
 *    table of OpenCL Device Queries for \c clGetDeviceInfo.
 * \param user_func
 *    A pointer to a host-callable user function.
 * \param args
 *    A pointer to the args list that \em user_func should be called with.
 * \param cb_args
 *    The size in bytes of the \em args list that args points to.
 * \param num_mem_objects
 *    The number of buffer objects that are passed in \em args.
 * \param mem_list
 *    A list of valid buffer objects, if \em num_mem_objects > 0. The buffer
 *    object values specified in \em mem_list are memory object handles
 *    (\c cl_mem values) returned by #create_buffer() or \c NULL.
 * \param args_mem_loc
 *    A pointer to appropriate locations that \em args points to where memory
 *    object handles (\c cl_mem values) are stored. Before the user function is
 *    executed, the memory object handles are replaced by pointers to global
 *    memory.
 * \param num_events_in_wait_list
 *    Number of events in \em event_wait_list
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \em event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If \em event_wait_list is
 *    \c NULL, \em num_events_in_wait_list must be \c 0. If \em event_wait_list
 *    is not \c NULL, the list of events pointed to by \em event_wait_list must
 *    be valid and \em num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \em event_wait_list act as synchronization points.
 *    The context associated with events in \em event_wait_list and
 *    \em %command_queue must be the same. The memory associated with
 *    \em event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular kernel execution
 *    instance. Event objects are unique and can be used to identify a
 *    particular kernel execution instance later on. If event is \c NULL, no
 *    event will be created for this kernel execution instance and therefore it
 *    will not be possible for the application to query or queue a wait for
 *    this particular kernel execution instance. If the \em event_wait_list and
 *    the event arguments are not \c NULL, the event argument should not refer
 *    to an element of the \em event_wait_list array.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_OPERATION
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_MEM_OBJECT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueNativeKernel returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueNativeKernel returns CL_MEM_OBJECT_ALLOCATION_FAILURE
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_EVENT_WAIT_LIST
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueNativeKernel returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clEnqueueNativeKernel returns other error code
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueNativeKernel.html">clEnqueueNativeKernel()</a>
 */ // }}}
void
enqueue_native_kernel(cl_command_queue command_queue,
                      void (CL_CALLBACK* user_func)(void*),
                      void* args,
                      size_t cb_args,
                      cl_uint num_mem_objects,
                      const cl_mem* mem_list,
                      const void** args_mem_loc,
                      cl_uint num_events_in_wait_list,
                      const cl_event* event_wait_list,
                      cl_event* event);
#if CLXX_OPENCL_ALLOWED(clCreateUserEvent)
/** // doc: create_user_event() {{{
 * \brief Creates an OpenCL user event object
 *
 * This function is a wrapper around \c clCreateUserEvent(). The call to this
 * function has same effect as
 * - \c clCreateUserEvent(context, &errcode_ret),
 * with \c errcode_ret being defined internally in #create_user_event().
 *
 * The main difference between #create_user_event() and \c clCreateUserEvent() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * User events allow applications to enqueue commands that wait on a user event
 * to finish before the command is executed by the device
 *
 * \param context A valid OpenCL context
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateUserEvent() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateUserEvent() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateUserEvent() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateUserEvent() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateUserEvent.html">clCreateUserEvent()</a>
 */ // }}}
cl_event
create_user_event(cl_context context);
#endif
#if CLXX_OPENCL_ALLOWED(clSetUserEventStatus)
/** // doc: set_user_event_status() {{{
 * \brief Sets the execution status of a user event object
 *
 * This function is a wrapper around \c clSetUserEventStatus(). The call to this
 * function has same effect as
 * - \c clSetUserEventStatus(event, execution_status),
 *
 * The main difference between #set_user_event_status() and
 * \c clSetUserEventStatus() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    A user event object created using #create_user_event.
 * \param execution_status
 *    Specifies the new execution status to be set and can be \c CL_COMPLETE or
 *    a negative integer value to indicate an error. A negative integer value
 *    causes all enqueued commands that wait on this user event to be
 *    terminated. #set_user_event_status() can only be called once to change the
 *    execution status of event.
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clSetUserEventStatus() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clSetUserEventStatus() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clSetUserEventStatus() returns CL_INVALID_OPERATION
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetUserEventStatus() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetUserEventStatus() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clSetUserEventStatus() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetUserEventStatus.html">clSetUserEventStatus()</a>
 */ // }}}
void
set_user_event_status(cl_event event, cl_int execution_status);
#endif
/** // doc: wait_for_events() {{{
 * \brief Waits on the host thread for commands identified by event objects to complete
 *
 * This function is a wrapper around \c clWaitForEvents(). The call to this
 * function has same effect as
 * - \c clWaitForEvents(num_events, event_list),
 *
 * The main difference between #set_user_event_status() and
 * \c clWaitForEvents() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param num_events
 *    Number of events in \p event_list
 * \param event_list
 *    The events specified in \p event_list act as synchronization points
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clWaitForEvents.html">clWaitForEvents()</a>
 */ // }}}
void
wait_for_events(cl_uint num_events, const cl_event* event_list);
/** // doc: get_event_info() {{{
 * \brief Returns information about the event object
 *
 * This function is a wrapper around \c clGetEventInfo(). The call to
 * this function has same effect as
 * - \c clGetEventInfo(event, static_cast<cl_event_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_event_info() and
 * \c clGetEventInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    Specifies the event object being queried.
 * \param param_name
 *    Specifies the information to query.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    The actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clGetEventInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_event>
 *    When the \c clGetEventInfo() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clGetEventInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clGetEventInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetEventInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetEventInfo.html">clGetEventInfo()</a>
 */ // }}}
void
get_event_info(cl_event event, event_info_t param_name,
               size_t param_value_size, void* param_value,
               size_t* param_value_size_ret);
#if CLXX_OPENCL_ALLOWED(clSetEventCallback)
/** // doc: set_event_callback() {{{
 * \brief Registers a user callback function for a specific command execution status
 *
 * This function is a wrapper around \c clSetEventCallback(). The call to
 * this function has same effect as
 * - \c clSetEventCallback(event, command_exec_callback_type, pfn_event_notify, user_data)
 *
 * The main difference between #set_event_callback() and
 * \c clSetEventCallback() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    A valid event object
 * \param command_exec_callback_type
 *    Specifies the command execution status for which the callback is
 *    registered. The command execution callback values for which a callback
 *    can be registered are \c CL_SUBMITTED, \c CL_RUNNING, or \c CL_COMPLETE.
 * \param pfn_event_notify
 *    The event callback function that can be registered by the application.
 *    This callback function may be called asynchronously by the OpenCL
 *    implementation. It is the application's responsibility to ensure that the
 *    callback function is thread-safe.
 * \param user_data
 *    Will be passed as the user_data argument when \p pfn_notify is called.
 *    \p user_data can be \c NULL.
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When the \c clGetEventInfo() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clGetEventInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clGetEventInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clGetEventInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetEventInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |           |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetEventCallback.html">clSetEventCallback()</a>
 */ // }}}
void
set_event_callback(cl_event event, cl_int command_exec_callback_type,
                   void(CL_CALLBACK* pfn_event_notify)(cl_event, cl_int, void*),
                   void* user_data);
#endif
/** // doc: retain_event() {{{
 * \brief Increments the event object reference count.
 *
 * This function is a wrapper around \c clRetainEvent(). The call to this
 * function has same effect as
 *  - \c clRetainEvent(event)
 *
 * The main difference between #retain_event() and \c clRetainEvent() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \note create_user_event() performs an implicit retain.
 *
 * \param event
 *    The event to be retained
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clRetainEvent() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainEvent() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainEvent() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clRetainEvent() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainEvent.html">clRetainEvent()</a>
 */ // }}}
void
retain_event(cl_event event);
/** // doc: release_event() {{{
 * \brief Decrements the \e event reference count
 *
 * This function is a wrapper around \c clReleaseEvent(). The call to this
 * function has same effect as
 *  - \c clReleaseEvent(event)
 *
 * The main difference between \ref release_event() and
 * \c clReleaseEvent() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note The event object is deleted once the number of instances that are
 *       retained to event become zero and the event object is no longer
 *       needed by any enqueued commands that use event.
 *
 * \param event
 *    The event to be released
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clReleaseEvent() returns CL_INVALID_EVENT.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseEvent() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseEvent() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseEvent() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseEvent.html">clReleaseEvent()</a>
 */ // }}}
void
release_event(cl_event event);
/** // doc: get_event_profiling_info() {{{
 * \brief Returns profiling information for the command associated with event
 *        if profiling is enabled
 *
 * This function is a wrapper around \c clGetEventProfilingInfo(). The call to
 * this function has same effect as
 * - \c clGetEventProfilingInfo(event, static_cast<cl_profiling_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_event_profiling_info() and
 * \c clGetEventProfilingInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    Specifies the event object.
 * \param param_name
 *    Specifies the profiling data to query.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    The actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::profiling_info_not_available>
 *    When the \c clGetEventProfilingInfo() returns CL_PROFILING_INFO_NOT_AVAILABLE
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clGetEventProfilingInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_event>
 *    When the \c clGetEventProfilingInfo() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clGetEventProfilingInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clGetEventProfilingInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetEventProfilingInfo() returns other error code.
 *
 * \par Available in OpenCL versions
 * |    1.0    |    1.1    |    1.2    |    2.0    |    2.1    |
 * | --------- | --------- | --------- | --------- | --------- |
 * |   \check  |   \check  |   \check  |   \check  |    ???    |
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetEventProfilingInfo.html">clGetEventProfilingInfo()</a>
 */ // }}}
void
get_event_profiling_info(cl_event event,
                         profiling_info_t param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
/** // doc: flush() {{{
 * \todo Write documentation
 */ // }}}
void
flush(cl_command_queue command_queue);
/** // doc: finish() {{{
 * \todo Write documentation
 */ // }}}
void
finish(cl_command_queue command_queue);
/** @} */
} // end namespace clxx

#endif /* CLXX_FUNCTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
