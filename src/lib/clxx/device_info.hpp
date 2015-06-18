// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_info.hpp

/** // doc: clxx/device_info.hpp {{{
* \file clxx/device_info.hpp
* \brief Defines \ref clxx::device_info class
*/ // }}}
#ifndef CLXX_DEVICE_INFO_HPP_INCLUDED
#define CLXX_DEVICE_INFO_HPP_INCLUDED

#include <clxx/types.hpp>
#include <boost/optional.hpp>
#include <vector>
#include <string>

namespace clxx {
/** // doc: class device_info {{{
 * \ingroup clxx_info
 * \class clxx::device_info
 * \brief Encapsulates parameters of an OpenCL device
 *
 * Encapsulates parameters describing an OpenCL device. It is used, for example,
 * to store a result of device info query performed with
 * \ref clxx::query_device_info() "query_device_info()". The class allows one
 * to easily maintain and exchange device information.
 *
 * \ref clxx::device_info "Device_info" objects can be easily serialized to
 * an archive (see \ref clxx_s11n) or printed in a human-readable form to an
 * output stream (see \ref clxx_io).
 *
 * The internal representation of \ref clxx::device_info "device_info" consists
 * of a number of attributes each of which may have a value or may be in
 * uninitialized state (absent). For each parameter, four methods are provided:
 *
 * - presence checker: \em has_xxx() - to determine if \c xxx is initialized,
 * - getter: \em xxx() - to retrieve value of \c xxx if it's initialized,
 * - setter: \em set_xxx() - to set value of \c xxx,
 * - cleaner: \em clear_xxx() - to clear (uninitialize) \c xxx atribute.
 *
 * For example, \c vendor_id is accessed with has_vendor_id(), vendor_id(),
 * set_vendor_id() and clear_vendor_id().
 *
 * \par Example:
 *
 * Manipulating #device_info attributes "by hand"
 *
 * \snippet clxx/device_info1.cpp Program
 *
 * \par Output:
 *
 * \snippet clxx/device_info1.cpp Output
 */ // }}}
class device_info
{
template <class Archive>
friend void _serialize(Archive&, device_info&, const unsigned int);
public:
/** // doc: class_version {{{
 * \brief Class version number, used by serialization module
 */ // }}}
static constexpr unsigned int class_version = 0x000001;
public:
/** // doc: device_info() {{{
 * \brief Default constructor
 *
 * Creates empty \ref clxx::device_info "device_info" object (all fields are
 * uninitialized, i.e. set to none).
 */ // }}}
device_info() noexcept;
/** // doc: ~device_info() {{{
 * \brief Destructor
 */ // }}}
virtual ~device_info() noexcept;
/** // doc: clear() {{{
 * \brief Unset all fields of the device info
 *
 * After the call to \ref clear() all fields are uninitialized (set to \c
 * none).
 *
 * \returns A mutable reference to this object
 */ // }}}
device_info& clear();
/** // doc: cmp(rhs) {{{
 * \brief Compare two \ref clxx::device_info "device_info" objects
 * \param other
 *    The other \ref device_info object to be compared to \c this one.
 * \returns
 *    \c true, if \c *this and \em other contain same information (all fields
 *    have same values in both objects), or \c false otherwise.
 */ // }}}
bool cmp(device_info const& other) const noexcept;
// getters {{{
/** // doc: id() {{{
 * \brief Device identifier (\c cl_device_id converted to unsigned long).
 * \returns Device identifier converted to <tt>unsigned long</tt>.
 * \throws uninitialized_value_error if the \c id is uninitialized
 */ // }}}
unsigned long id() const;
/** // doc: type() {{{
 * \brief Device type
 * \returns Device type
 * \throws uninitialized_value_error if the \c id is uninitialized
 */ // }}}
device_type_t type() const;
/** // doc: vendor_id() {{{
 * \brief Device vendor's ID
 * \returns Vendor's ID
 * \throws uninitialized_value_error if the \c vendor_id is uninitialized
 */ // }}}
cl_uint vendor_id() const;
/** // doc: max_compute_units() {{{
 * \brief Max number of compute units
 * \returns Max number of compute units
 * \throws uninitialized_value_error if the \c max_compute_units is uninitialized
 */ // }}}
cl_uint max_compute_units() const;
/** // doc: max_work_item_dimensions() {{{
 * \brief Max number of work item dimensions
 * \returns Max number of work item dimensions
 * \throws uninitialized_value_error if the \c max_work_item_dimensions is uninitialized
 */ // }}}
cl_uint max_work_item_dimensions() const;
/** // doc: max_work_group_size() {{{
 * \brief Max work group size
 * \return Max work group size
 * \throws uninitialized_value_error if the \c max_work_group_size is uninitialized
 */ // }}}
size_t max_work_group_size() const;
/** // doc: max_work_item_sizes() {{{
 * \brief Maximum sizes of work items
 * \return Maximum sizes of work items
 * \throws uninitialized_value_error if the \c max_work_item_sizes is uninitialized
 */ // }}}
std::vector<size_t> max_work_item_sizes() const;
/** // doc: preferred_vector_width_char() {{{
 * \brief Preferred vector width for \c char data type
 * \returns Preferred vector width for \c char data type
 * \throws uninitialized_value_error if the \c preferred_vector_width_char is uninitialized
 */ // }}}
cl_uint preferred_vector_width_char() const;
/** // doc: preferred_vector_width_short() {{{
 * \brief Preferred vector width for \c short data type
 * \returns Preferred vector width for \c short data type
 * \throws uninitialized_value_error if the \c preferred_vector_width_short is uninitialized
 */ // }}}
cl_uint preferred_vector_width_short() const;
/** // doc: preferred_vector_width_int() {{{
 * \brief Preferred vector width for \c int data type
 * \returns Preferred vector width for \c int data type
 * \throws uninitialized_value_error if the \c preferred_vector_width_int is uninitialized
 */ // }}}
cl_uint preferred_vector_width_int() const;
/** // doc: preferred_vector_width_long() {{{
 * \brief Preferred vector width for \c long data type
 * \returns Preferred vector width for \c long data type
 * \throws uninitialized_value_error if the \c preferred_vector_width_long is uninitialized
 */ // }}}
cl_uint preferred_vector_width_long() const;
/** // doc: preferred_vector_width_float() {{{
 * \brief Preferred vector width for \c float data type
 * \returns Preferred vector width for \c float data type
 * \throws uninitialized_value_error if the \c preferred_vector_width_float is uninitialized
 */ // }}}
cl_uint preferred_vector_width_float() const;
/** // doc: preferred_vector_width_double() {{{
 * \brief Preferred vector width for \c double data type
 * \returns Preferred vector width for \c double data type
 * \throws uninitialized_value_error if the \c preferred_vector_width_double is uninitialized
 */ // }}}
cl_uint preferred_vector_width_double() const;
/** // doc: max_clock_frequency() {{{
 * \brief Max clock frequency
 * \return Max clock frequency
 * \throws uninitialized_value_error if the \c max_clock_frequency is uninitialized
 */ // }}}
cl_uint max_clock_frequency() const;
/** // doc: {ddress_bits() {{
 * \brief Default compute device address space size of the global address space
 * \returns Default compute device address space size of the global address
 *    space expressed in bits.
 * \throws uninitialized_value_error if the \c address_bits is uninitialized
 */ // }}}
cl_uint address_bits() const;
/** // doc: max_read_image_args() {{{
 * \brief Max number of image objects arguments of a read-only kernel
 * \returns Max number of image objects arguments of a kernel declared with
 *    the \c read_only qualifier.
 * \throws uninitialized_value_error if the \c max_read_image_args is uninitialized
 */ // }}}
cl_uint max_read_image_args() const;
/** // doc: max_write_image_args() {{{
 * \brief Max number of image objects arguments of a write-only kernel
 * \returns Max number of image objects arguments of a kernel declared with
 *    the \c write_only qualifier.
 * \throws uninitialized_value_error if the \c max_write_image_args is uninitialized
 */ // }}}
cl_uint max_write_image_args() const;
/** // doc: max_mem_alloc_size() {{{
 * \brief Max size of memory object allocation in bytes
 * \returns Max size of memory object allocation in bytes.
 * \throws uninitialized_value_error if the \c max_mem_alloc_size is uninitialized
 */ // }}}
cl_ulong max_mem_alloc_size() const;
/** // doc: image2d_max_width() {{{
 * \brief Max width of 2D image or 1D image (not from a buffer)
 * \returns Max width of 2D image or 1D image not created from a buffer in pixels
 * \throws uninitialized_value_error if the \c image2d_max_width is uninitialized
 */ // }}}
size_t image2d_max_width() const;
/** // doc: mage2d_max_height() {{{
 * \brief Max height of 2D image
 * \returns Max height of 2D image in pixels
 * \throws uninitialized_value_error if the \c image2d_max_height is uninitialized
 */ // }}}
size_t image2d_max_height() const;
/** // doc: image3d_max_width() {{{
 * \brief Max width of 3D image
 * \returns Max width of 3D image in pixels
 * \throws uninitialized_value_error if the \c image3d_max_width is uninitialized
 */ // }}}
size_t image3d_max_width() const;
/** // doc: image3d_max_height() {{{
 * \brief Max height of 3D image
 * \returns Max height of 3D image in pixels
 * \throws uninitialized_value_error if the \c image3d_max_height is uninitialized
 */ // }}}
size_t image3d_max_height() const;
/** // doc: image3d_max_depth() {{{
 * \brief Max depth of 3D image
 * \returns Max height of 3D image in pixels
 * \throws uninitialized_value_error if the \c image3d_max_depth is uninitialized
 */ // }}}
size_t image3d_max_depth() const;
/** // doc: image_support() {{{
 * \brief Image support status
 * \returns \c CL_TRUE if images are supported by the device and \c CL_FALSE
 *          otherwise
 * \throws uninitialized_value_error if the \c image_support is uninitialized
 */ // }}}
cl_bool image_support() const;
/** // doc: max_parameter_size() {{{
 * \brief Max size of all arguments of a kernel
 * \returns Max size in bytes of all arguments that can be passed to a kernel.
 * \throws uninitialized_value_error if the \c max_parameter_size is uninitialized
 */ // }}}
size_t max_parameter_size() const;
/** // doc: max_samplers() {{{
 * \brief Max number of samplers
 * \returns Max number of samplers that can be used in a kernel.
 * \throws uninitialized_value_error if the \c max_samplers is uninitialized
 */ // }}}
cl_uint max_samplers() const;
/** // doc: mem_base_addr_align() {{{
 * \brief Base address alignment
 * \returns Base address alignment
 * \throws uninitialized_value_error if the attribute \c mem_base_addr_align is uninitialized
 */ // }}}
cl_uint mem_base_addr_align() const;
/** // doc: min_data_type_align_size() {{{
 * \brief The smallest alignment in bytes which can be used for any data type
 * \returns The smallest alignment in bytes which can be used for any data type
 * \throws uninitialized_value_error if the attribute \c min_data_type_align_size is uninitialized
 *
 * \note The OpenCL device info named CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE
 *       (which corresponds to min_data_type_align_size) is deprecated in
 *       OpenCL 1.2
 */ // }}}
cl_uint min_data_type_align_size() const;
/** // doc: single_fp_config() {{{
 * \brief The description of single-precision floating-point capability
 * \returns The description of single-precision floating-point capability of
 *          the device
 * \throws uninitialized_value_error if the attribute \c single_fp_config is uninitialized
 */ // }}}
device_fp_config_t single_fp_config() const;
/** // doc: global_mem_cache_type() {{{
 * \brief Type of global memory cache supported
 * \returns Type of global memory cache supported
 * \throws uninitialized_value_error if the attribute \c global_mem_cache_type is uninitialized
 */ // }}}
device_mem_cache_type_t global_mem_cache_type() const;
/** // doc: global_mem_cacheline_size() {{{
 * \brief Size of global memory cache line in bytes
 * \returns Size of global memory cache line in bytes
 * \throws uninitialized_value_error if the attribute \c global_mem_cacheline_size is uninitialized
 */ // }}}
cl_uint global_mem_cacheline_size() const;
/** // doc: global_mem_cache_size() {{{
 * \brief Size of global memory cache in bytes
 * \returns Size of global memory cache in bytes
 * \throws uninitialized_value_error if the attribute \c global_mem_cache_size is uninitialized
 */ // }}}
cl_ulong global_mem_cache_size() const;
/** // doc: global_mem_size() {{{
 * \brief Size of global memory in bytes
 * \returns Size of global memory in bytes
 * \throws uninitialized_value_error if the attribute \c global_mem_size is uninitialized
 */ // }}}
cl_ulong global_mem_size() const;
/** // doc: max_constant_buffer_size() {{{
 * \brief Max size of constant buffer allocation
 * \returns Max size in bytes of a constant buffer allocation
 * \throws uninitialized_value_error if the attribute \c max_constant_buffer_size is uninitialized
 */ // }}}
cl_ulong max_constant_buffer_size() const;
/** // doc: max_constant_args() {{{
 * \brief Max number of kernel \c __constant arguments
 * \returns Max number of arguments declared with the \c __constant qualifier in a kernel
 * \throws uninitialized_value_error if the attribute \c max_constant_args is uninitialized
 */ // }}}
cl_uint max_constant_args() const;
/** // doc: local_mem_type() {{{
 * \brief Type of local memory supported
 * \returns Type of local memory supported (local, global, none)
 * \throws uninitialized_value_error if the attribute \c local_mem_type is uninitialized
 */ // }}}
device_local_mem_type_t local_mem_type() const;
/** // doc: local_mem_size() {{{
 * \brief Size of local memory arena in bytes
 * \returns Size of local memory arena in bytes
 * \throws uninitialized_value_error if the attribute \c local_mem_size  is uninitialized
 */ // }}}
cl_ulong local_mem_size() const;
/** // doc: error_correction_support() {{{
 * \brief Error correction support status
 * \returns \c CL_TRUE, if the device implements error correction for all
 *    accesses to compute device memory (global and constant)
 * \throws uninitialized_value_error if the attribute \c error_correction_support is uninitialized
 */ // }}}
cl_bool error_correction_support() const;
/** // doc: profiling_timer_resolution() {{{
 * \brief Resolution of device timer
 * \returns Device timer resolution in nanoseconds
 * \throws uninitialized_value_error if the attribute \c profiling_timer_resolution is uninitialized
 */ // }}}
size_t profiling_timer_resolution() const;
/** // doc: endian_little() {{{
 * \brief Whether device is a little endian device
 * \returns \c CL_TRUE if the device is a little endian device and \c
 *    CL_FALSE otherwise
 * \throws uninitialized_value_error if the attribute \c endian_little is uninitialized
 */ // }}}
cl_bool endian_little() const;
/** // doc: available() {{{
 * \brief Whether the device is available
 * \returns \c CL_TRUE if the device is available and \c CL_FALSE if it's not
 * \throws uninitialized_value_error if the attribute \c available is uninitialized
 */ // }}}
cl_bool available() const;
/** // doc: compiler_available() {{{
 * \brief Whether the implementation has a compiler available
 * \returns \c CL_FALSE if the implementation does not have a compiler
 *    available to compile program source; \c CL_true if the compiler is
 *    available
 * \throws uninitialized_value_error if the attribute \c compiler_available is uninitialized
 */ // }}}
cl_bool compiler_available() const;
/** // doc: execution_capabilities() {{{
 * \brief Execution capabilities of the device
 * \returns A bit-field enum representing execution capabilities of the device
 * \throws uninitialized_value_error if the attribute \c execution_capabilities is uninitialized
 */ // }}}
device_exec_capabilities_t execution_capabilities() const;
/** // doc: queue_properties() {{{
 * \brief Command queue properties supported by the device
 * \returns Command-queue properties supported by the device (a bit-field)
 * \throws uninitialized_value_error if the attribute \c queue_properties is uninitialized
 */ // }}}
command_queue_properties_t queue_properties() const;
/** // doc: name() {{{
 * \brief Device name
 * \returns Device name string
 * \throws uninitialized_value_error if the attribute \c name is uninitialized
 */ // }}}
std::string const& name() const;
/** // doc: vendor() {{{
 * \brief Device vendor name
 * \throws uninitialized_value_error if the attribute \c vendor is uninitialized
 */ // }}}
std::string const& vendor() const;
/** // doc: driver_version() {{{
 * \brief OpenCL software driver version string
 * \returns OpenCL software driver version string in the form
 *          \em major_number.minor_number.
 * \throws uninitialized_value_error if the attribute \c driver_version is uninitialized
 */ // }}}
std::string const& driver_version() const;
/** // doc: profile() {{{
 * \brief OpenCL profile string
 * \returns The profile name supported by the device (e.g. FULL_PROFILE,
 *    EMBEDDED_PROFILE)
 * \throws uninitialized_value_error if the attribute \c profile is uninitialized
 */ // }}}
std::string const& profile() const;
/** // doc: version() {{{
 * \brief OpenCL version string
 * \returns OpenCL version supported by the device.
 * \throws uninitialized_value_error if the attribute \c version is uninitialized
 */ // }}}
std::string const& version() const;
/** // doc: extensions() {{{
 * \brief Extension names
 * \returns Space separated list of extension names supported by the device
 * \throws uninitialized_value_error if the attribute \c extensions is uninitialized
 */ // }}}
std::string const& extensions() const;
/** // doc: platform_id() {{{
 * \brief Platform ID of device's platform
 * \returns ID of the OpenCL platform associated with this device
 * \throws uninitialized_value_error if the attribute \c platform_id is uninitialized
 */ // }}}
unsigned long platform_id() const;
#if CL_VERSION_1_2
/** // doc: double_fp_config() {{{
 * \brief Double precision floating-point capability
 * \returns Bit-field that describes double precision floating-point
 *    capability of the OpenCL device.
 * \throws uninitialized_value_error if the attribute \c double_fp_config is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
device_fp_config_t double_fp_config() const;
#endif
#if CL_VERSION_1_1
/** // doc: preferred_vector_width_half() {{{
 * \brief Preferred native vector width size for char type
 * \returns Preferred native vector width size for char type
 * \throws uninitialized_value_error if the attribute \c preferred_vector_width_half is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint preferred_vector_width_half() const;
/** // doc: host_unified_memory() {{{
 * \brief Whether the device and the host have a unified memory
 * \returns \c CL_TRUE if the device and the host have a unified memory
 *    subsystem and is \c CL_FALSE otherwise.
 * \throws uninitialized_value_error if the attribute \c host_unified_memory is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_bool host_unified_memory() const;
/** // doc: native_vector_width_char() {{{
 * \brief Native ISA vector width for \c char type
 * \returns Native ISA vector width as the number of scalar elements that can
 *    be stored in the vector
 * \throws uninitialized_value_error if the attribute \c native_vector_width_char is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint native_vector_width_char() const;
/** // doc: native_vector_width_short() {{{
 * \brief Native ISA vector width for \c short type
 * \returns Native ISA vector width as the number of scalar elements that can
 *    be stored in the vector
 * \throws uninitialized_value_error if the attribute \c native_vector_width_short is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint native_vector_width_short() const;
/** // doc: native_vector_width_int() {{{
 * \brief Native ISA vector width for \c int type
 * \returns Native ISA vector width as the number of scalar elements that can
 *    be stored in the vector
 * \throws uninitialized_value_error if the attribute \c native_vector_width_int is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint native_vector_width_int() const;
/** // doc: native_vector_width_long() {{{
 * \brief Native ISA vector width for \c long type
 * \returns Native ISA vector width as the number of scalar elements that can
 *    be stored in the vector
 * \throws uninitialized_value_error if the attribute \c native_vector_width_long is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint native_vector_width_long() const;
/** // doc: native_vector_width_float() {{{
 * \brief Native ISA vector width for \c float type
 * \returns Native ISA vector width as the number of scalar elements that can
 *    be stored in the vector
 * \throws uninitialized_value_error if the attribute \c native_vector_width_float is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint native_vector_width_float() const;
/** // doc: native_vector_width_double() {{{
 * \brief Native ISA vector width for \c double type
 * \returns Native ISA vector width as the number of scalar elements that can
 *    be stored in the vector
 * \throws uninitialized_value_error if the attribute \c native_vector_width_double is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint native_vector_width_double() const;
/** // doc: native_vector_width_half() {{{
 * \brief Native ISA vector width for \c half type
 * \returns Native ISA vector width as the number of scalar elements that can
 *    be stored in the vector
 * \throws uninitialized_value_error if the attribute \c native_vector_width_half is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint native_vector_width_half() const;
/** // doc: opencl_c_version() {{{
 * \brief OpenCL C version string
 * \returns The highest OpenCL C version supported by the compiler for this
 *    device that is not of type \ref device_type_t::custom
 * \throws uninitialized_value_error if the attribute \c opencl_c_version is uninitialized
 * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
std::string const& opencl_c_version() const;
#endif
#if CL_VERSION_1_2
/** // doc: linker_available() {{{
 * \brief Whether the OpenCL implementation has a linker available
 * \returns \c CL_FALSE if the implementation does not have a linker
 *    available or \c CL_TRUE if the linker is available.
 * \throws uninitialized_value_error if the attribute \c linker_available is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_bool linker_available() const;
/** // doc: built_in_kernels() {{{
 * \brief Built-in kernels supported by the device
 * \returns A semi-colon separated list of built-in kernels supported by the
 *    device. An empty string is returned if no built-in kernels are
 *    supported by the device.
 * \throws uninitialized_value_error if the attribute \c built_in_kernels is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
std::string const& built_in_kernels() const;
/** // doc: image_max_buffer_size() {{{
 * \brief Max image buffer size
 * \returns Max number of pixels for a 1D image created from a buffer object
 * \throws uninitialized_value_error if the attribute \c image_max_buffer_size is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
size_t image_max_buffer_size() const;
/** // doc: image_max_array_size() {{{
 * \brief Max number of images in a 1D or 2D image array
 * \returns Max number of images in a 1D or 2D image array
 * \throws uninitialized_value_error if the attribute \c image_max_array_size is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
size_t image_max_array_size() const;
/** // doc: parent_device_id() {{{
 * \brief ID of parent device
 * \returns \c cl_device_id (converted do <tt>unsigned long</tt>)of the
 *    parent device to which this sub-device belongs. If device is a
 *    root-level device, a NULL value is returned
 * \throws uninitialized_value_error if the attribute \c parent_device_id is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
unsigned long parent_device_id() const;
/** // doc: partition_max_sub_devices() {{{
 * \brief Maximum number of possible sub-devices
 * \returns Maximum number of sub-devices that can be created when a device
 *    is partitioned.
 * \throws uninitialized_value_error if the attribute \c partition_max_sub_devices is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint partition_max_sub_devices() const;
/** // doc: partition_properties() {{{
 * \brief Partition types supported by device
 * \returns The list of partition types supported by device
 * \throws uninitialized_value_error if the attribute \c partition_properties is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
std::vector<device_partition_property_t> partition_properties() const;
/** // doc: partition_affinity_domain() {{{
 * \brief Supported affinity domains for partitioning
 * \returns the list of supported affinity domains for partitioning the
 *    device using \ref device_partition_property_t::by_affinity_domain.
 * \throws uninitialized_value_error if the attribute \c partition_affinity_domain is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
device_affinity_domain_t partition_affinity_domain() const;
/** // doc: partition_type() {{{
 * \brief Properties argument specified in create_sub_devices()
 * \returns The properties argument specified in create_sub_devices() if
 *    device is a subdevice
 * \throws uninitialized_value_error if the attribute \c partition_type is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
std::vector<device_partition_property_t> partition_type() const;
/** // doc: reference_count() {{{
 * \brief Device reference count
 * \returns The device reference count. If the device is a root-level device,
 *    a reference count of one is returned.
 * \throws uninitialized_value_error if the attribute \c reference_count is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint reference_count() const;
/** // doc: preferred_interop_user_sync() {{{
 * \brief Whether device's preference is for the user to be responsible for synchronization
 * \returns \c CL_TRUE if the device's preference is for the user to be
 *    responsible for synchronization, when sharing memory objects between
 *    OpenCL and other APIs.
 * \throws uninitialized_value_error if the attribute \c preferred_interop_user_sync is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_bool preferred_interop_user_sync() const;
/** // doc: printf_buffer_size() {{{
 * \brief Maximum size of the internal printf buffer
 * \returns Maximum size of the internal buffer that holds the output of
 *    \c printf calls from a kernel.
 * \throws uninitialized_value_error if the attribute \c printf_buffer_size is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
size_t printf_buffer_size() const;
/** // doc: image_pitch_alignment() {{{
 * \brief Corresponds to CL_DEVICE_IMAGE_PITCH_ALIGNMENT
 *
 * This property is not documented in the official documentation of
 * \c clGetDeviceInfo(), but appears in \c CL/cl.h. It appears in other places
 * of the OpenCL documentation, for example documentation of \c cl_image_desc
 * or <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/enums.html">documentation of enums</a>.
 *
 * \throws uninitialized_value_error if the attribute \c image_pitch_alignment is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint image_pitch_alignment() const;
/** // doc: image_base_address_alignment() {{{
 * \brief Corresponds to CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT
 *
 * This property is not documented in the official documentation of
 * \c clGetDeviceInfo(), but appears in \c CL/cl.h. It appears in other places
 * of the OpenCL documentation, for example documentation of
 * <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/enums.html">documentation of enums</a>.
 *
 * \c cl_image_desc.
 * \throws uninitialized_value_error if the attribute \c image_base_address_alignment is uninitialized
 * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
 */ // }}}
cl_uint image_base_address_alignment() const;
#endif
// }}}
  // setters {{{
  /** // doc: set_id(val) {{{
   * \brief Set the #id attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_id(unsigned long val) noexcept;
  /** // doc: set_type(val) {{{
   * \brief Set the #type attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_type(device_type_t val) noexcept;
  /** // doc: set_vendor_id(val) {{{
   * \brief Set the #vendor_id attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_vendor_id(cl_uint val) noexcept;
  /** // doc: set_max_compute_units(val) {{{
   * \brief Set the #max_compute_units attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_compute_units(cl_uint val) noexcept;
  /** // doc: set_max_work_item_dimensions(val) {{{
   * \brief Set the #max_work_item_dimensions attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_work_item_dimensions(cl_uint val) noexcept;
  /** // doc: set_max_work_group_size(val) {{{
   * \brief Set the #max_work_group_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_work_group_size(size_t val) noexcept;
  /** // doc: set_max_work_item_sizes(val) {{{
   * \brief Set the #max_work_item_sizes attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_work_item_sizes(std::vector<size_t> const& val);
  /** // doc: set_preferred_vector_width_char(val) {{{
   * \brief Set the #preferred_vector_width_char attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_preferred_vector_width_char(cl_uint val) noexcept;
  /** // doc: set_preferred_vector_width_short(val) {{{
   * \brief Set the #preferred_vector_width_short attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_preferred_vector_width_short(cl_uint val) noexcept;
  /** // doc: set_preferred_vector_width_int(val) {{{
   * \brief Set the #preferred_vector_width_int attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_preferred_vector_width_int(cl_uint val) noexcept;
  /** // doc: set_preferred_vector_width_long(val) {{{
   * \brief Set the #preferred_vector_width_long attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_preferred_vector_width_long(cl_uint val) noexcept;
  /** // doc: set_preferred_vector_width_float(val) {{{
   * \brief Set the #preferred_vector_width_float attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_preferred_vector_width_float(cl_uint val) noexcept;
  /** // doc: set_preferred_vector_width_double(val) {{{
   * \brief Set the #preferred_vector_width_double attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_preferred_vector_width_double(cl_uint val) noexcept;
  /** // doc: set_max_clock_frequency(val) {{{
   * \brief Set the #max_clock_frequency attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_clock_frequency(cl_uint val) noexcept;
  /** // doc: set_address_bits(val) {{{
   * \brief Set the #address_bits attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_address_bits(cl_uint val) noexcept;
  /** // doc: set_max_read_image_args(val) {{{
   * \brief Set the #max_read_image_args attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_read_image_args(cl_uint val) noexcept;
  /** // doc: set_max_write_image_args(val) {{{
   * \brief Set the #max_write_image_args  attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_write_image_args(cl_uint val) noexcept;
  /** // doc: set_max_mem_alloc_size(val) {{{
   * \brief Set the #max_mem_alloc_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_mem_alloc_size(cl_ulong val) noexcept;
  /** // doc: set_image2d_max_width(val) {{{
   * \brief Set the #image2d_max_width attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_image2d_max_width(size_t val) noexcept;
  /** // doc: set_image2d_max_height(val) {{{
   * \brief Set the #image2d_max_height attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_image2d_max_height(size_t val) noexcept;
  /** // doc: set_image3d_max_width(val) {{{
   * \brief Set the #image3d_max_width attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_image3d_max_width(size_t val) noexcept;
  /** // doc: set_image3d_max_height(val) {{{
   * \brief Set the #image3d_max_height attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_image3d_max_height(size_t val) noexcept;
  /** // doc: set_image3d_max_depth(val) {{{
   * \brief Set the #image3d_max_depth attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_image3d_max_depth(size_t val) noexcept;
  /** // doc: set_image_support(val) {{{
   * \brief Set the #image_support attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_image_support(cl_bool val) noexcept;
  /** // doc: set_max_parameter_size(val) {{{
   * \brief Set the #max_parameter_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_parameter_size(size_t val) noexcept;
  /** // doc: set_max_samplers(val) {{{
   * \brief Set the #max_samplers attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_samplers(cl_uint val) noexcept;
  /** // doc: set_mem_base_addr_align(val) {{{
   * \brief Set the #mem_base_addr_align attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_mem_base_addr_align(cl_uint val) noexcept;
  /** // doc: set_min_data_type_align_size(val) {{{
   * \brief Set the #min_data_type_align_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_min_data_type_align_size(cl_uint val) noexcept;
  /** // doc: set_single_fp_config(val) {{{
   * \brief Set the #single_fp_config attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_single_fp_config(device_fp_config_t val) noexcept;
  /** // doc: set_global_mem_cache_type(val) {{{
   * \brief Set the #global_mem_cache_type attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_global_mem_cache_type(device_mem_cache_type_t val) noexcept;
  /** // doc: set_global_mem_cacheline_size(val) {{{
   * \brief Set the #global_mem_cacheline_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_global_mem_cacheline_size(cl_uint val) noexcept;
  /** // doc: set_global_mem_cache_size(val) {{{
   * \brief Set the #global_mem_cache_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_global_mem_cache_size(cl_ulong val) noexcept;
  /** // doc: set_global_mem_size(val) {{{
   * \brief Set the #global_mem_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_global_mem_size(cl_ulong val) noexcept;
  /** // doc: set_max_constant_buffer_size(val) {{{
   * \brief Set the #max_constant_buffer_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_constant_buffer_size(cl_uint val) noexcept;
  /** // doc: set_max_constant_args(val) {{{
   * \brief Set the #max_constant_args attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_max_constant_args(cl_uint val) noexcept;
  /** // doc: set_local_mem_type(val) {{{
   * \brief Set the #local_mem_type attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_local_mem_type(device_local_mem_type_t val) noexcept;
  /** // doc: set_local_mem_size(val) {{{
   * \brief Set the #local_mem_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_local_mem_size(cl_ulong val) noexcept;
  /** // doc: set_error_correction_support(val) {{{
   * \brief Set the #error_correction_support attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_error_correction_support(cl_bool val) noexcept;
  /** // doc: set_profiling_timer_resolution(val) {{{
   * \brief Set the #profiling_timer_resolution attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_profiling_timer_resolution(size_t val) noexcept;
  /** // doc: set_endian_little(val) {{{
   * \brief Set the #endian_little attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_endian_little(cl_bool val) noexcept;
  /** // doc: set_available(val) {{{
   * \brief Set the #available attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_available(cl_bool val) noexcept;
  /** // doc: set_compiler_available(val) {{{
   * \brief Set the #compiler_available attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_compiler_available(cl_bool val) noexcept;
  /** // doc: set_execution_capabilities(val) {{{
   * \brief Set the #execution_capabilities attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_execution_capabilities(device_exec_capabilities_t val) noexcept;
  /** // doc: set_queue_properties(val) {{{
   * \brief Set the #queue_properties attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_queue_properties(command_queue_properties_t val) noexcept;
  /** // doc: set_name(val) {{{
   * \brief Set the #name attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_name(std::string const& val);
  /** // doc: set_vendor(val) {{{
   * \brief Set the #vendor attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_vendor(std::string const& val);
  /** // doc: set_driver_version(val) {{{
   * \brief Set the #driver_version attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_driver_version(std::string const& val);
  /** // doc: set_profile(val) {{{
   * \brief Set the #profile attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_profile(std::string const& val);
  /** // doc: set_version(val) {{{
   * \brief Set the #version attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_version(std::string const& val);
  /** // doc: set_extensions(val) {{{
   * \brief Set the #extensions attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_extensions(std::string const& val);
  /** // doc: set_platform_id(val) {{{
   * \brief Set the #platform_id attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& set_platform_id(unsigned long val) noexcept;
#if CL_VERSION_1_2
  /** // doc: set_double_fp_config(val) {{{
   * \brief Set the #double_fp_config attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_double_fp_config(device_fp_config_t val) noexcept;
#endif
#if CL_VERSION_1_1
  /** // doc: set_preferred_vector_width_half(val) {{{
   * \brief Set the #preferred_vector_width_half attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_preferred_vector_width_half(cl_uint val) noexcept;
  /** // doc: set_host_unified_memory(val) {{{
   * \brief Set the #host_unified_memory attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_host_unified_memory(cl_bool val) noexcept;
  /** // doc: set_native_vector_width_char(val) {{{
   * \brief Set the #native_vector_width_char attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_native_vector_width_char(cl_uint val) noexcept;
  /** // doc: set_native_vector_width_short(val) {{{
   * \brief Set the #native_vector_width_short attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_native_vector_width_short(cl_uint val) noexcept;
  /** // doc: set_native_vector_width_int(val) {{{
   * \brief Set the #native_vector_width_int attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_native_vector_width_int(cl_uint val) noexcept;
  /** // doc: set_native_vector_width_long(val) {{{
   * \brief Set the #native_vector_width_long attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_native_vector_width_long(cl_uint val) noexcept;
  /** // doc: set_native_vector_width_float(val) {{{
   * \brief Set the #native_vector_width_float attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_native_vector_width_float(cl_uint val) noexcept;
  /** // doc: set_native_vector_width_double(val) {{{
   * \brief Set the #native_vector_width_double attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_native_vector_width_double(cl_uint val) noexcept;
  /** // doc: set_native_vector_width_half(val) {{{
   * \brief Set the #native_vector_width_half attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_native_vector_width_half(cl_uint val) noexcept;
  /** // doc: set_opencl_c_version(val) {{{
   * \brief Set the #opencl_c_version attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_opencl_c_version(std::string const& val);
#endif
#if CL_VERSION_1_2
  /** // doc: set_linker_available(val) {{{
   * \brief Set the #linker_available attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_linker_available(cl_bool val) noexcept;
  /** // doc: set_built_in_kernels(val) {{{
   * \brief Set the #built_in_kernels attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_built_in_kernels(std::string const& val);
  /** // doc: set_image_max_buffer_size(val) {{{
   * \brief Set the #image_max_buffer_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_image_max_buffer_size(size_t val) noexcept;
  /** // doc: set_image_max_array_size(val) {{{
   * \brief Set the #image_max_array_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_image_max_array_size(size_t val) noexcept;
  /** // doc: set_parent_device_id(val) {{{
   * \brief Set the #parent_device_id attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_parent_device_id(unsigned long val) noexcept;
  /** // doc: set_partition_max_sub_devices(val) {{{
   * \brief Set the #partition_max_sub_devices attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_partition_max_sub_devices(cl_uint val) noexcept;
  /** // doc: set_partition_properties(val) {{{
   * \brief Set the #partition_properties attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_partition_properties(std::vector<device_partition_property_t> const& val);
  /** // doc: set_partition_affinity_domain(val) {{{
   * \brief Set the #partition_affinity_domain attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_partition_affinity_domain(device_affinity_domain_t val) noexcept;
  /** // doc: set_partition_type(val) {{{
   * \brief Set the #partition_type attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_partition_type(std::vector<device_partition_property_t> const& val);
  /** // doc: set_reference_count(val) {{{
   * \brief Set the #reference_count attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_reference_count(cl_uint val) noexcept;
  /** // doc: set_preferred_interop_user_sync(val) {{{
   * \brief Set the #preferred_interop_user_sync attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_preferred_interop_user_sync(cl_bool val) noexcept;
  /** // doc: set_printf_buffer_size(val) {{{
   * \brief Set the #printf_buffer_size attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_printf_buffer_size(size_t val) noexcept;
  /** // doc: set_image_pitch_alignment(val) {{{
   * \brief Set the #image_pitch_alignment attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_image_pitch_alignment(cl_uint val) noexcept;
  /** // doc: set_image_base_address_alignment(val) {{{
   * \brief Set the #image_base_address_alignment attribute
   * \param val The value to be set to the attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& set_image_base_address_alignment(cl_uint val) noexcept;
#endif
  // }}}
  // cleaners {{{
  /** // doc: clear_id() {{{
   * \brief Clears the #id attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_id() noexcept;
  /** // doc: clear_type() {{{
   * \brief Clears the #type attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_type() noexcept;
  /** // doc: clear_vendor_id() {{{
   * \brief Clears the #vendor_id attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_vendor_id() noexcept;
  /** // doc: clear_max_compute_units() {{{
   * \brief Clears the #max_compute_units attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_compute_units() noexcept;
  /** // doc: clear_max_work_item_dimensions() {{{
   * \brief Clears the #max_work_item_dimensions attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_work_item_dimensions() noexcept;
  /** // doc: clear_max_work_group_size() {{{
   * \brief Clears the #max_work_group_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_work_group_size() noexcept;
  /** // doc: clear_max_work_item_sizes() {{{
   * \brief Clears the #max_work_item_sizes attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_work_item_sizes() noexcept;
  /** // doc: clear_preferred_vector_width_char() {{{
   * \brief Clears the #preferred_vector_width_char attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_preferred_vector_width_char() noexcept;
  /** // doc: clear_preferred_vector_width_short() {{{
   * \brief Clears the #preferred_vector_width_short attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_preferred_vector_width_short() noexcept;
  /** // doc: clear_preferred_vector_width_int() {{{
   * \brief Clears the #preferred_vector_width_int attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_preferred_vector_width_int() noexcept;
  /** // doc: clear_preferred_vector_width_long() {{{
   * \brief Clears the #preferred_vector_width_long attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_preferred_vector_width_long() noexcept;
  /** // doc: clear_preferred_vector_width_float() {{{
   * \brief Clears the #preferred_vector_width_float attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_preferred_vector_width_float() noexcept;
  /** // doc: clear_preferred_vector_width_double() {{{
   * \brief Clears the #preferred_vector_width_double attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_preferred_vector_width_double() noexcept;
  /** // doc: clear_max_clock_frequency() {{{
   * \brief Clears the #max_clock_frequency attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_clock_frequency() noexcept;
  /** // doc: clear_address_bits() {{{
   * \brief Clears the #address_bits attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_address_bits() noexcept;
  /** // doc: clear_max_read_image_args() {{{
   * \brief Clears the #max_read_image_args attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_read_image_args() noexcept;
  /** // doc: clear_max_write_image_args() {{{
   * \brief Clears the #max_write_image_args attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_write_image_args() noexcept;
  /** // doc: clear_max_mem_alloc_size() {{{
   * \brief Clears the #max_mem_alloc_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_mem_alloc_size() noexcept;
  /** // doc: clear_image2d_max_width() {{{
   * \brief Clears the #image2d_max_width attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image2d_max_width() noexcept;
  /** // doc: clear_image2d_max_height() {{{
   * \brief Clears the #image2d_max_height attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image2d_max_height() noexcept;
  /** // doc: clear_image3d_max_width() {{{
   * \brief Clears the #image3d_max_width attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image3d_max_width() noexcept;
  /** // doc: clear_image3d_max_height() {{{
   * \brief Clears the #image3d_max_height attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image3d_max_height() noexcept;
  /** // doc: clear_image3d_max_depth() {{{
   * \brief Clears the #image3d_max_depth attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image3d_max_depth() noexcept;
  /** // doc: clear_image_support() {{{
   * \brief Clears the #image_support attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image_support() noexcept;
  /** // doc: clear_max_parameter_size() {{{
   * \brief Clears the #max_parameter_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_parameter_size() noexcept;
  /** // doc: clear_max_samplers() {{{
   * \brief Clears the #max_samplers attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_samplers() noexcept;
  /** // doc: clear_mem_base_addr_align() {{{
   * \brief Clears the #mem_base_addr_align attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_mem_base_addr_align() noexcept;
  /** // doc: clear_min_data_type_align_size() {{{
   * \brief Clears the #min_data_type_align_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_min_data_type_align_size() noexcept;
  /** // doc: clear_single_fp_config() {{{
   * \brief Clears the #single_fp_config attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_single_fp_config() noexcept;
  /** // doc: clear_global_mem_cache_type() {{{
   * \brief Clears the #global_mem_cache_type attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_global_mem_cache_type() noexcept;
  /** // doc: clear_global_mem_cacheline_size() {{{
   * \brief Clears the #global_mem_cacheline_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_global_mem_cacheline_size() noexcept;
  /** // doc: clear_global_mem_cache_size() {{{
   * \brief Clears the #global_mem_cache_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_global_mem_cache_size() noexcept;
  /** // doc: clear_global_mem_size() {{{
   * \brief Clears the #global_mem_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_global_mem_size() noexcept;
  /** // doc: clear_max_constant_buffer_size() {{{
   * \brief Clears the #max_constant_buffer_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_constant_buffer_size() noexcept;
  /** // doc: clear_max_constant_args() {{{
   * \brief Clears the #max_constant_args attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_max_constant_args() noexcept;
  /** // doc: clear_local_mem_type() {{{
   * \brief Clears the #local_mem_type attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_local_mem_type() noexcept;
  /** // doc: clear_local_mem_size() {{{
   * \brief Clears the #local_mem_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_local_mem_size() noexcept;
  /** // doc: clear_error_correction_support() {{{
   * \brief Clears the #error_correction_support attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_error_correction_support() noexcept;
  /** // doc: clear_profiling_timer_resolution() {{{
   * \brief Clears the #profiling_timer_resolution attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_profiling_timer_resolution() noexcept;
  /** // doc: clear_endian_little() {{{
   * \brief Clears the #endian_little attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_endian_little() noexcept;
  /** // doc: clear_available() {{{
   * \brief Clears the #available attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_available() noexcept;
  /** // doc: clear_compiler_available() {{{
   * \brief Clears the #compiler_available attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_compiler_available() noexcept;
  /** // doc: clear_execution_capabilities() {{{
   * \brief Clears the #execution_capabilities attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_execution_capabilities() noexcept;
  /** // doc: clear_queue_properties() {{{
   * \brief Clears the #queue_properties attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_queue_properties() noexcept;
  /** // doc: clear_name() {{{
   * \brief Clears the #name attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_name() noexcept;
  /** // doc: clear_vendor() {{{
   * \brief Clears the #vendor attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_vendor() noexcept;
  /** // doc: clear_driver_version() {{{
   * \brief Clears the #driver_version attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_driver_version() noexcept;
  /** // doc: clear_profile() {{{
   * \brief Clears the #profile attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_profile() noexcept;
  /** // doc: clear_version() {{{
   * \brief Clears the #version attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_version() noexcept;
  /** // doc: clear_extensions() {{{
   * \brief Clears the #extensions attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_extensions() noexcept;
  /** // doc: clear_platform_id() {{{
   * \brief Clears the #platform_id attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_platform_id() noexcept;
#if CL_VERSION_1_2
  /** // doc: clear_double_fp_config() {{{
   * \brief Clears the #double_fp_config attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_double_fp_config() noexcept;
#endif
#if CL_VERSION_1_1
  /** // doc: clear_preferred_vector_width_half() {{{
   * \brief Clears the #preferred_vector_width_half attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_preferred_vector_width_half() noexcept;
  /** // doc: clear_host_unified_memory() {{{
   * \brief Clears the #host_unified_memory attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_host_unified_memory() noexcept;
  /** // doc: clear_native_vector_width_char() {{{
   * \brief Clears the #native_vector_width_char attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_native_vector_width_char() noexcept;
  /** // doc: clear_native_vector_width_short() {{{
   * \brief Clears the #native_vector_width_short attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_native_vector_width_short() noexcept;
  /** // doc: clear_native_vector_width_int() {{{
   * \brief Clears the #native_vector_width_int attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_native_vector_width_int() noexcept;
  /** // doc: clear_native_vector_width_long() {{{
   * \brief Clears the #native_vector_width_long attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_native_vector_width_long() noexcept;
  /** // doc: clear_native_vector_width_float() {{{
   * \brief Clears the #native_vector_width_float attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_native_vector_width_float() noexcept;
  /** // doc: clear_native_vector_width_double() {{{
   * \brief Clears the #native_vector_width_double attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_native_vector_width_double() noexcept;
  /** // doc: clear_native_vector_width_half() {{{
   * \brief Clears the #native_vector_width_half attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_native_vector_width_half() noexcept;
  /** // doc: clear_opencl_c_version() {{{
   * \brief Clears the #opencl_c_version attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_opencl_c_version() noexcept;
#endif
#if CL_VERSION_1_2
  /** // doc: clear_linker_available() {{{
   * \brief Clears the #linker_available attribute
   * \returns Reference to the modified \ref device_info object
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  device_info& clear_linker_available() noexcept;
  /** // doc: clear_built_in_kernels() {{{
   * \brief Clears the #built_in_kernels attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_built_in_kernels() noexcept;
  /** // doc: clear_image_max_buffer_size() {{{
   * \brief Clears the #image_max_buffer_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image_max_buffer_size() noexcept;
  /** // doc: clear_image_max_array_size() {{{
   * \brief Clears the #image_max_array_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image_max_array_size() noexcept;
  /** // doc: clear_parent_device_id() {{{
   * \brief Clears the #parent_device_id attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_parent_device_id() noexcept;
  /** // doc: clear_partition_max_sub_devices() {{{
   * \brief Clears the #partition_max_sub_devices attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_partition_max_sub_devices() noexcept;
  /** // doc: clear_partition_properties() {{{
   * \brief Clears the #partition_properties attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_partition_properties() noexcept;
  /** // doc: clear_partition_affinity_domain() {{{
   * \brief Clears the #partition_affinity_domain attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_partition_affinity_domain() noexcept;
  /** // doc: clear_partition_type() {{{
   * \brief Clears the #partition_type attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_partition_type() noexcept;
  /** // doc: clear_reference_count() {{{
   * \brief Clears the #reference_count attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_reference_count() noexcept;
  /** // doc: clear_preferred_interop_user_sync() {{{
   * \brief Clears the #preferred_interop_user_sync attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_preferred_interop_user_sync() noexcept;
  /** // doc: clear_printf_buffer_size() {{{
   * \brief Clears the #printf_buffer_size attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_printf_buffer_size() noexcept;
  /** // doc: clear_image_pitch_alignment() {{{
   * \brief Clears the #image_pitch_alignment attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image_pitch_alignment() noexcept;
  /** // doc: clear_image_base_address_alignment() {{{
   * \brief Clears the #image_base_address_alignment attribute
   * \returns Reference to the modified \ref device_info object
   */ // }}}
  device_info& clear_image_base_address_alignment() noexcept;
#endif
  // }}}
  // presence {{{
  /** // doc: has_id(val) {{{
   * \brief Check if the #id attribute is initialized
   * \returns \c true if #id is initialized or \c false otherwise
   */ // }}}
  bool has_id() const noexcept;
  /** // doc: has_type(val) {{{
   * \brief Check if the #type attribute is initialized
   * \returns \c true if #type is initialized or \c false otherwise
   */ // }}}
  bool has_type() const noexcept;
  /** // doc: has_vendor_id(val) {{{
   * \brief Check if the #vendor_id attribute is initialized
   * \returns \c true if #vendor_id is initialized or \c false otherwise
   */ // }}}
  bool has_vendor_id() const noexcept;
  /** // doc: has_max_compute_units(val) {{{
   * \brief Check if the #max_compute_units attribute is initialized
   * \returns \c true if #max_compute_units is initialized or \c false otherwise
   */ // }}}
  bool has_max_compute_units() const noexcept;
  /** // doc: has_max_work_item_dimensions(val) {{{
   * \brief Check if the #max_work_item_dimensions attribute is initialized
   * \returns \c true if #max_work_item_dimensions is initialized or \c false otherwise
   */ // }}}
  bool has_max_work_item_dimensions() const noexcept;
  /** // doc: has_max_work_group_size(val) {{{
   * \brief Check if the #max_work_group_size attribute is initialized
   * \returns \c true if #max_work_group_size is initialized or \c false otherwise
   */ // }}}
  bool has_max_work_group_size() const noexcept;
  /** // doc: has_max_work_item_sizes(val) {{{
   * \brief Check if the #max_work_item_sizes attribute is initialized
   * \returns \c true if #max_work_item_sizes is initialized or \c false otherwise
   */ // }}}
  bool has_max_work_item_sizes() const noexcept;
  /** // doc: has_preferred_vector_width_char(val) {{{
   * \brief Check if the #preferred_vector_width_char attribute is initialized
   * \returns \c true if #preferred_vector_width_char is initialized or \c false otherwise
   */ // }}}
  bool has_preferred_vector_width_char() const noexcept;
  /** // doc: has_preferred_vector_width_short(val) {{{
   * \brief Check if the #preferred_vector_width_short attribute is initialized
   * \returns \c true if #preferred_vector_width_short is initialized or \c false otherwise
   */ // }}}
  bool has_preferred_vector_width_short() const noexcept;
  /** // doc: has_preferred_vector_width_int(val) {{{
   * \brief Check if the #preferred_vector_width_int attribute is initialized
   * \returns \c true if #preferred_vector_width_int is initialized or \c false otherwise
   */ // }}}
  bool has_preferred_vector_width_int() const noexcept;
  /** // doc: has_preferred_vector_width_long(val) {{{
   * \brief Check if the #preferred_vector_width_long attribute is initialized
   * \returns \c true if #preferred_vector_width_long is initialized or \c false otherwise
   */ // }}}
  bool has_preferred_vector_width_long() const noexcept;
  /** // doc: has_preferred_vector_width_float(val) {{{
   * \brief Check if the #preferred_vector_width_float attribute is initialized
   * \returns \c true if #preferred_vector_width_float is initialized or \c false otherwise
   */ // }}}
  bool has_preferred_vector_width_float() const noexcept;
  /** // doc: has_preferred_vector_width_double(val) {{{
   * \brief Check if the #preferred_vector_width_double attribute is initialized
   * \returns \c true if #preferred_vector_width_double is initialized or \c false otherwise
   */ // }}}
  bool has_preferred_vector_width_double() const noexcept;
  /** // doc: has_max_clock_frequency(val) {{{
   * \brief Check if the #max_clock_frequency attribute is initialized
   * \returns \c true if #max_clock_frequency is initialized or \c false otherwise
   */ // }}}
  bool has_max_clock_frequency() const noexcept;
  /** // doc: has_address_bits(val) {{{
   * \brief Check if the #address_bits attribute is initialized
   * \returns \c true if #address_bits is initialized or \c false otherwise
   */ // }}}
  bool has_address_bits() const noexcept;
  /** // doc: has_max_read_image_args(val) {{{
   * \brief Check if the #max_read_image_args attribute is initialized
   * \returns \c true if #max_read_image_args is initialized or \c false otherwise
   */ // }}}
  bool has_max_read_image_args() const noexcept;
  /** // doc: has_max_write_image_args(val) {{{
   * \brief Check if the #max_write_image_args attribute is initialized
   * \returns \c true if #max_write_image_args is initialized or \c false otherwise
   */ // }}}
  bool has_max_write_image_args() const noexcept;
  /** // doc: has_max_mem_alloc_size(val) {{{
   * \brief Check if the #max_mem_alloc_size attribute is initialized
   * \returns \c true if #max_mem_alloc_size is initialized or \c false otherwise
   */ // }}}
  bool has_max_mem_alloc_size() const noexcept;
  /** // doc: has_image2d_max_width(val) {{{
   * \brief Check if the #image2d_max_width attribute is initialized
   * \returns \c true if #image2d_max_width is initialized or \c false otherwise
   */ // }}}
  bool has_image2d_max_width() const noexcept;
  /** // doc: has_image2d_max_height(val) {{{
   * \brief Check if the #image2d_max_height attribute is initialized
   * \returns \c true if #image2d_max_height is initialized or \c false otherwise
   */ // }}}
  bool has_image2d_max_height() const noexcept;
  /** // doc: has_image3d_max_width(val) {{{
   * \brief Check if the #image3d_max_width attribute is initialized
   * \returns \c true if #image3d_max_width is initialized or \c false otherwise
   */ // }}}
  bool has_image3d_max_width() const noexcept;
  /** // doc: has_image3d_max_height(val) {{{
   * \brief Check if the #image3d_max_height attribute is initialized
   * \returns \c true if #image3d_max_height is initialized or \c false otherwise
   */ // }}}
  bool has_image3d_max_height() const noexcept;
  /** // doc: has_image3d_max_depth(val) {{{
   * \brief Check if the #image3d_max_depth attribute is initialized
   * \returns \c true if #image3d_max_depth is initialized or \c false otherwise
   */ // }}}
  bool has_image3d_max_depth() const noexcept;
  /** // doc: has_image_support(val) {{{
   * \brief Check if the #image_support attribute is initialized
   * \returns \c true if #image_support is initialized or \c false otherwise
   */ // }}}
  bool has_image_support() const noexcept;
  /** // doc: has_max_parameter_size(val) {{{
   * \brief Check if the #max_parameter_size attribute is initialized
   * \returns \c true if #max_parameter_size is initialized or \c false otherwise
   */ // }}}
  bool has_max_parameter_size() const noexcept;
  /** // doc: has_max_samplers(val) {{{
   * \brief Check if the #max_samplers attribute is initialized
   * \returns \c true if #max_samplers is initialized or \c false otherwise
   */ // }}}
  bool has_max_samplers() const noexcept;
  /** // doc: has_mem_base_addr_align(val) {{{
   * \brief Check if the #mem_base_addr_align attribute is initialized
   * \returns \c true if #mem_base_addr_align is initialized or \c false otherwise
   */ // }}}
  bool has_mem_base_addr_align() const noexcept;
  /** // doc: has_min_data_type_align_size(val) {{{
   * \brief Check if the #min_data_type_align_size attribute is initialized
   * \returns \c true if #min_data_type_align_size is initialized or \c false otherwise
   */ // }}}
  bool has_min_data_type_align_size() const noexcept;
  /** // doc: has_single_fp_config(val) {{{
   * \brief Check if the #single_fp_config attribute is initialized
   * \returns \c true if #single_fp_config is initialized or \c false otherwise
   */ // }}}
  bool has_single_fp_config() const noexcept;
  /** // doc: has_global_mem_cache_type(val) {{{
   * \brief Check if the #global_mem_cache_type attribute is initialized
   * \returns \c true if #global_mem_cache_type is initialized or \c false otherwise
   */ // }}}
  bool has_global_mem_cache_type() const noexcept;
  /** // doc: has_global_mem_cacheline_size(val) {{{
   * \brief Check if the #global_mem_cacheline_size attribute is initialized
   * \returns \c true if #global_mem_cacheline_size is initialized or \c false otherwise
   */ // }}}
  bool has_global_mem_cacheline_size() const noexcept;
  /** // doc: has_global_mem_cache_size(val) {{{
   * \brief Check if the #global_mem_cache_size attribute is initialized
   * \returns \c true if #global_mem_cache_size is initialized or \c false otherwise
   */ // }}}
  bool has_global_mem_cache_size() const noexcept;
  /** // doc: has_global_mem_size(val) {{{
   * \brief Check if the #global_mem_size attribute is initialized
   * \returns \c true if #global_mem_size is initialized or \c false otherwise
   */ // }}}
  bool has_global_mem_size() const noexcept;
  /** // doc: has_max_constant_buffer_size(val) {{{
   * \brief Check if the #max_constant_buffer_size attribute is initialized
   * \returns \c true if #max_constant_buffer_size is initialized or \c false otherwise
   */ // }}}
  bool has_max_constant_buffer_size() const noexcept;
  /** // doc: has_max_constant_args(val) {{{
   * \brief Check if the #max_constant_args attribute is initialized
   * \returns \c true if #max_constant_args is initialized or \c false otherwise
   */ // }}}
  bool has_max_constant_args() const noexcept;
  /** // doc: has_local_mem_type(val) {{{
   * \brief Check if the #local_mem_type attribute is initialized
   * \returns \c true if #local_mem_type is initialized or \c false otherwise
   */ // }}}
  bool has_local_mem_type() const noexcept;
  /** // doc: has_local_mem_size(val) {{{
   * \brief Check if the #local_mem_size attribute is initialized
   * \returns \c true if #local_mem_size is initialized or \c false otherwise
   */ // }}}
  bool has_local_mem_size() const noexcept;
  /** // doc: has_error_correction_support(val) {{{
   * \brief Check if the #error_correction_support attribute is initialized
   * \returns \c true if #error_correction_support is initialized or \c false otherwise
   */ // }}}
  bool has_error_correction_support() const noexcept;
  /** // doc: has_profiling_timer_resolution(val) {{{
   * \brief Check if the #profiling_timer_resolution attribute is initialized
   * \returns \c true if #profiling_timer_resolution is initialized or \c false otherwise
   */ // }}}
  bool has_profiling_timer_resolution() const noexcept;
  /** // doc: has_endian_little(val) {{{
   * \brief Check if the #endian_little attribute is initialized
   * \returns \c true if #endian_little is initialized or \c false otherwise
   */ // }}}
  bool has_endian_little() const noexcept;
  /** // doc: has_available(val) {{{
   * \brief Check if the #available attribute is initialized
   * \returns \c true if #available is initialized or \c false otherwise
   */ // }}}
  bool has_available() const noexcept;
  /** // doc: has_compiler_available(val) {{{
   * \brief Check if the #compiler_available attribute is initialized
   * \returns \c true if #compiler_available is initialized or \c false otherwise
   */ // }}}
  bool has_compiler_available() const noexcept;
  /** // doc: has_execution_capabilities(val) {{{
   * \brief Check if the #execution_capabilities attribute is initialized
   * \returns \c true if #execution_capabilities is initialized or \c false otherwise
   */ // }}}
  bool has_execution_capabilities() const noexcept;
  /** // doc: has_queue_properties(val) {{{
   * \brief Check if the #queue_properties attribute is initialized
   * \returns \c true if #queue_properties is initialized or \c false otherwise
   */ // }}}
  bool has_queue_properties() const noexcept;
  /** // doc: has_name(val) {{{
   * \brief Check if the #name attribute is initialized
   * \returns \c true if #name is initialized or \c false otherwise
   */ // }}}
  bool has_name() const noexcept;
  /** // doc: has_vendor(val) {{{
   * \brief Check if the #vendor attribute is initialized
   * \returns \c true if #vendor is initialized or \c false otherwise
   */ // }}}
  bool has_vendor() const noexcept;
  /** // doc: has_driver_version(val) {{{
   * \brief Check if the #driver_version attribute is initialized
   * \returns \c true if #driver_version is initialized or \c false otherwise
   */ // }}}
  bool has_driver_version() const noexcept;
  /** // doc: has_profile(val) {{{
   * \brief Check if the #profile attribute is initialized
   * \returns \c true if #profile is initialized or \c false otherwise
   */ // }}}
  bool has_profile() const noexcept;
  /** // doc: has_version(val) {{{
   * \brief Check if the #version attribute is initialized
   * \returns \c true if #version is initialized or \c false otherwise
   */ // }}}
  bool has_version() const noexcept;
  /** // doc: has_extensions(val) {{{
   * \brief Check if the #extensions attribute is initialized
   * \returns \c true if #extensions is initialized or \c false otherwise
   */ // }}}
  bool has_extensions() const noexcept;
  /** // doc: has_platform_id(val) {{{
   * \brief Check if the #platform_id attribute is initialized
   * \returns \c true if #platform_id is initialized or \c false otherwise
   */ // }}}
  bool has_platform_id() const noexcept;
#if CL_VERSION_1_2
  /** // doc: has_double_fp_config(val) {{{
   * \brief Check if the #double_fp_config attribute is initialized
   * \returns \c true if #double_fp_config is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_double_fp_config() const noexcept;
#endif
#if CL_VERSION_1_1
  /** // doc: has_preferred_vector_width_half(val) {{{
   * \brief Check if the #preferred_vector_width_half attribute is initialized
   * \returns \c true if #preferred_vector_width_half is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_preferred_vector_width_half() const noexcept;
  /** // doc: has_host_unified_memory(val) {{{
   * \brief Check if the #host_unified_memory attribute is initialized
   * \returns \c true if #host_unified_memory is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_host_unified_memory() const noexcept;
  /** // doc: has_native_vector_width_char(val) {{{
   * \brief Check if the #native_vector_width_char attribute is initialized
   * \returns \c true if #native_vector_width_char is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_native_vector_width_char() const noexcept;
  /** // doc: has_native_vector_width_short(val) {{{
   * \brief Check if the #native_vector_width_short attribute is initialized
   * \returns \c true if #native_vector_width_short is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_native_vector_width_short() const noexcept;
  /** // doc: has_native_vector_width_int(val) {{{
   * \brief Check if the #native_vector_width_int attribute is initialized
   * \returns \c true if #native_vector_width_int is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_native_vector_width_int() const noexcept;
  /** // doc: has_native_vector_width_long(val) {{{
   * \brief Check if the #native_vector_width_long attribute is initialized
   * \returns \c true if #native_vector_width_long is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_native_vector_width_long() const noexcept;
  /** // doc: has_native_vector_width_float(val) {{{
   * \brief Check if the #native_vector_width_float attribute is initialized
   * \returns \c true if #native_vector_width_float is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_native_vector_width_float() const noexcept;
  /** // doc: has_native_vector_width_double(val) {{{
   * \brief Check if the #native_vector_width_double attribute is initialized
   * \returns \c true if #native_vector_width_double is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_native_vector_width_double() const noexcept;
  /** // doc: has_native_vector_width_half(val) {{{
   * \brief Check if the #native_vector_width_half attribute is initialized
   * \returns \c true if #native_vector_width_half is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_native_vector_width_half() const noexcept;
  /** // doc: has_opencl_c_version(val) {{{
   * \brief Check if the #opencl_c_version attribute is initialized
   * \returns \c true if #opencl_c_version is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.1 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_opencl_c_version() const noexcept;
#endif
#if CL_VERSION_1_2
  /** // doc: has_linker_available(val) {{{
   * \brief Check if the #linker_available attribute is initialized
   * \returns \c true if #linker_available is initialized or \c false otherwise
   * \note Only available if the clxx library is compiled with version 1.2 or later of the <tt>CL/cl.h</tt> header.
   */ // }}}
  bool has_linker_available() const noexcept;
  /** // doc: has_built_in_kernels(val) {{{
   * \brief Check if the #built_in_kernels attribute is initialized
   * \returns \c true if #built_in_kernels is initialized or \c false otherwise
   */ // }}}
  bool has_built_in_kernels() const noexcept;
  /** // doc: has_image_max_buffer_size(val) { {{
   * \brief Check if the #image_max_buffer_size attribute is initialized
   * \returns \c true if #image_max_buffer_size is initialized or \c false otherwise
   */ // }}}
  bool has_image_max_buffer_size() const noexcept;
  /** // doc: has_image_max_array_size(val) {{{
   * \brief Check if the #image_max_array_size attribute is initialized
   * \returns \c true if #image_max_array_size is initialized or \c false otherwise
   */ // }}}
  bool has_image_max_array_size() const noexcept;
  /** // doc: has_parent_device_id(val) {{{
   * \brief Check if the #parent_device_id attribute is initialized
   * \returns \c true if #parent_device_id is initialized or \c false otherwise
   */ // }}}
  bool has_parent_device_id() const noexcept;
  /** // doc: has_partition_max_sub_devices(val) {{{
   * \brief Check if the #partition_max_sub_devices attribute is initialized
   * \returns \c true if #partition_max_sub_devices is initialized or \c false otherwise
   */ // }}}
  bool has_partition_max_sub_devices() const noexcept;
  /** // doc: has_partition_properties(val) {{{
   * \brief Check if the #partition_properties attribute is initialized
   * \returns \c true if #partition_properties is initialized or \c false otherwise
   */ // }}}
  bool has_partition_properties() const noexcept;
  /** // doc: has_partition_affinity_domain(val) {{{
   * \brief Check if the #partition_affinity_domain attribute is initialized
   * \returns \c true if #partition_affinity_domain is initialized or \c false otherwise
   */ // }}}
  bool has_partition_affinity_domain() const noexcept;
  /** // doc: has_partition_type(val) {{{
   * \brief Check if the #partition_type attribute is initialized
   * \returns \c true if #partition_type is initialized or \c false otherwise
   */ // }}}
  bool has_partition_type() const noexcept;
  /** // doc: has_reference_count(val) {{{
   * \brief Check if the #reference_count attribute is initialized
   * \returns \c true if #reference_count is initialized or \c false otherwise
   */ // }}}
  bool has_reference_count() const noexcept;
  /** // doc: has_preferred_interop_user_sync(val) {{{
   * \brief Check if the #preferred_interop_user_sync attribute is initialized
   * \returns \c true if #preferred_interop_user_sync is initialized or \c false otherwise
   */ // }}}
  bool has_preferred_interop_user_sync() const noexcept;
  /** // doc: has_printf_buffer_size(val) {{{
   * \brief Check if the #printf_buffer_size attribute is initialized
   * \returns \c true if #printf_buffer_size is initialized or \c false otherwise
   */ // }}}
  bool has_printf_buffer_size() const noexcept;
  /** // doc: has_image_pitch_alignment(val) {{{
   * \brief Check if the #image_pitch_alignment attribute is initialized
   * \returns \c true if #image_pitch_alignment is initialized or \c false otherwise
   */ // }}}
  bool has_image_pitch_alignment() const noexcept;
  /** // doc: has_image_base_address_alignment(val) {{{
   * \brief Check if the #image_base_address_alignment attribute is initialized
   * \returns \c true if #image_base_address_alignment is initialized or \c false otherwise
   */ // }}}
  bool has_image_base_address_alignment() const noexcept;
#endif
  // }}}
private:
  void _init();
  void _clear();
  // attributes {{{
  boost::optional<unsigned long> _id;
  boost::optional<device_type_t> _type;
  boost::optional<cl_uint> _vendor_id;
  boost::optional<cl_uint> _max_compute_units;
  boost::optional<cl_uint> _max_work_item_dimensions;
  boost::optional<size_t> _max_work_group_size;
  boost::optional<std::vector<size_t> > _max_work_item_sizes;
  boost::optional<cl_uint> _preferred_vector_width_char;
  boost::optional<cl_uint> _preferred_vector_width_short;
  boost::optional<cl_uint> _preferred_vector_width_int;
  boost::optional<cl_uint> _preferred_vector_width_long;
  boost::optional<cl_uint> _preferred_vector_width_float;
  boost::optional<cl_uint> _preferred_vector_width_double;
  boost::optional<cl_uint> _max_clock_frequency;
  boost::optional<cl_uint> _address_bits;
  boost::optional<cl_uint> _max_read_image_args;
  boost::optional<cl_uint> _max_write_image_args;
  boost::optional<cl_ulong> _max_mem_alloc_size;
  boost::optional<size_t> _image2d_max_width;
  boost::optional<size_t> _image2d_max_height;
  boost::optional<size_t> _image3d_max_width;
  boost::optional<size_t> _image3d_max_height;
  boost::optional<size_t> _image3d_max_depth;
  boost::optional<cl_bool> _image_support;
  boost::optional<size_t> _max_parameter_size;
  boost::optional<cl_uint> _max_samplers;
  boost::optional<cl_uint> _mem_base_addr_align;
  boost::optional<cl_uint> _min_data_type_align_size;
  boost::optional<device_fp_config_t> _single_fp_config;
  boost::optional<device_mem_cache_type_t> _global_mem_cache_type;
  boost::optional<cl_uint> _global_mem_cacheline_size;
  boost::optional<cl_ulong> _global_mem_cache_size;
  boost::optional<cl_ulong> _global_mem_size;
  boost::optional<cl_uint> _max_constant_buffer_size;
  boost::optional<cl_uint> _max_constant_args;
  boost::optional<device_local_mem_type_t> _local_mem_type;
  boost::optional<cl_ulong> _local_mem_size;
  boost::optional<cl_bool> _error_correction_support;
  boost::optional<size_t> _profiling_timer_resolution;
  boost::optional<cl_bool> _endian_little;
  boost::optional<cl_bool> _available;
  boost::optional<cl_bool> _compiler_available;
  boost::optional<device_exec_capabilities_t> _execution_capabilities;
  boost::optional<command_queue_properties_t> _queue_properties;
  boost::optional<std::string>  _name;
  boost::optional<std::string>  _vendor;
  boost::optional<std::string>  _driver_version;
  boost::optional<std::string>  _profile;
  boost::optional<std::string>  _version;
  boost::optional<std::string>  _extensions;
  boost::optional<unsigned long> _platform_id;
#if CL_VERSION_1_2
  boost::optional<device_fp_config_t> _double_fp_config;
#endif
#if CL_VERSION_1_1
  boost::optional<cl_uint> _preferred_vector_width_half;
  boost::optional<cl_bool> _host_unified_memory;
  boost::optional<cl_uint> _native_vector_width_char;
  boost::optional<cl_uint> _native_vector_width_short;
  boost::optional<cl_uint> _native_vector_width_int;
  boost::optional<cl_uint> _native_vector_width_long;
  boost::optional<cl_uint> _native_vector_width_float;
  boost::optional<cl_uint> _native_vector_width_double;
  boost::optional<cl_uint> _native_vector_width_half;
  boost::optional<std::string>  _opencl_c_version;
#endif
#if CL_VERSION_1_2
  boost::optional<cl_bool> _linker_available;
  boost::optional<std::string>  _built_in_kernels;
  boost::optional<size_t> _image_max_buffer_size;
  boost::optional<size_t> _image_max_array_size;
  boost::optional<unsigned long> _parent_device_id;
  boost::optional<cl_uint> _partition_max_sub_devices;
  boost::optional<std::vector<device_partition_property_t> > _partition_properties;
  boost::optional<device_affinity_domain_t> _partition_affinity_domain;
  boost::optional<std::vector<device_partition_property_t> > _partition_type;
  boost::optional<cl_uint> _reference_count;
  boost::optional<cl_bool> _preferred_interop_user_sync;
  boost::optional<size_t> _printf_buffer_size;
  boost::optional<cl_uint> _image_pitch_alignment;
  boost::optional<cl_uint> _image_base_address_alignment;
#endif
  // }}}
};

/** \addtogroup clxx_info
 * @{ */
/** // doc: operator==(a,b) {{{
 * \brief Compare two \ref clxx::device_info "device_info" objects
 * Two \ref clxx::device_info "device_info" objects are equal iff any attribute
 * of the first object is equal to its corresponding attribute in the second
 * object.
 * \returns \c true if \em a and \em b are equal, or \c false otherwise
 */ // }}}
inline bool operator== (device_info const& a, device_info const& b) noexcept
{ return a.cmp(b); }
/** // doc: operator==(a,b) {{{
 * \brief Compare two \ref clxx::device_info "device_info" objects
 * Two \ref clxx::device_info "device_info" objects are equal iff any attribute
 * of the first object is equal to its corresponding attribute in the second
 * object.
 * \returns \c false if \em a and \em b are equal, or \c true otherwise
 */ // }}}
inline bool operator!= (device_info const& a, device_info const& b) noexcept
{ return !(a == b); }
/** @} */

} // end namespace clxx
#endif /* CLXX_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
