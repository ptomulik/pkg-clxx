// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/devices.hpp

/** // doc: clxx/devices.hpp {{{
 * \file clxx/devices.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICES_HPP_INCLUDED
#define CLXX_DEVICES_HPP_INCLUDED

#include <clxx/device.hpp>
#include <clxx/platform.hpp>
#include <clxx/types.hpp>
#include <vector>

namespace clxx {

/** // doc: devices {{{
 * \ingroup clxx_platform_layer
 * \brief Collection of clxx::device objects.
 */ // }}}
typedef std::vector<device> devices;

/** \ingroup clxx_platform_layer */
/** @{ */
/** // doc: get_num_devices() {{{
 * \brief Get number of OpenCL devices available locally.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \b platform is \c NULL, the behavior is
 *        implementation-defined.
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The \b
 *        device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \b device_type are
 *        specified by the documentation of the clxx::device_type_t.
 *
 * \return The number of available OpenCL devices
 *
 * \throws clerror_no<status_t::invalid_platform>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_PLATFORM,
 * \throws clerror_no<status_t::invalid_device_type>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_DEVICE_TYPE,
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_resources>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_RESOURCES,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetDeviceIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetDeviceIDs()
 * implementation is not standard conformant, its version is not supported by
 * %clxx, or when get_device_ids() has a bug.
 */ // }}}
cl_uint get_num_devices(cl_platform_id platform, device_type_t device_type);
/** // doc: get_device_ids() {{{
 * \brief Retrieve device identifiers of locally available OpenCL devices.
 *
 * This function is a C++ wrapper for \c clGetDeviceIDs(). The main differences
 * between clxx::get_device_ids() and \c clGetDeviceIDs() is that
 *   - it throws exceptions instead of returning error codes,
 *   - it internally allocates memory to store the returned identifiers and
 *        returns them as <tt>std::vector&lt;cl_device_id&gt;</tt>.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \b platform is \c NULL, the behavior is
 *        implementation-defined.
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The
 *        \b device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \b device_type are
 *        specified by clxx::device_type_t.
 *
 * \return std::vector<cl_device_id>.
 *        A collection of device identifiers (<tt>cl_device_id</tt>).
 *
 * \throws clerror_no<status_t::invalid_platform>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_PLATFORM,
 * \throws clerror_no<status_t::invalid_device_type>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_DEVICE_TYPE,
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_resources>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_RESOURCES,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetDeviceIDs() returns other error code.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 * The unexpected_clerror is thrown only when the \c clGetDeviceIDs()
 * implementation is not standard conformant, its version is not supported by
 * %clxx, or when get_device_ids() has a bug.
 */ // }}}
std::vector<cl_device_id>
get_device_ids(cl_platform_id platform,
               device_type_t device_type = device_type_t::all);
/** // doc: get_devices() {{{
 * \brief Get proxy device objects for locally available OpenCL devices.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \b platform is \c NULL, the behavior is
 *        implementation-defined
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The
 *        \b device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \b device_type are
 *        specified by clxx::device_type_t
 *
 * \return clxx::devices.
 *         A collection of device identifiers for the given platform.
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The \c clerror_no<status_t::invalid_value> should never appear in practice.
 * Otherwise the function is buggy.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * %clxx, or when get_platform_ids() has a bug.
 */ // }}}
devices
get_devices(cl_platform_id platform,
            device_type_t device_type = device_type_t::all);
/** // doc: get_devices() {{{
 * \brief Get proxy device objects for locally available OpenCL devices.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \b platform is \c NULL, the behavior is
 *        implementation-defined
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The
 *        \b device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \b device_type are
 *        specified by clxx::device_type_t
 *
 * \return clxx::devices.
 *         A collection of device objects for the given platform.
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The \c clerror_no<status_t::invalid_value> should never appear in practice.
 * Otherwise the function is buggy.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * %clxx, or when get_platform_ids() has a bug.
 */ // }}}
devices
get_devices(platform const& platform,
            device_type_t device_type = device_type_t::all);
/** // {{{ doc: make_devices(ids)
 * \brief Wrap device identifiers with clxx::device objects.
 *
 * \param ids OpenCL device identifiers
 *
 * \return clxx::devices.
 *         A collection of device objects for the given identifiers.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 */ // }}}
devices
make_devices(std::vector<cl_device_id> const& ids);
/** @} */

} // end namespace clxx

#endif /* CLXX_DEVICES_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
