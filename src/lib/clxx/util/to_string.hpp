// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/to_string.hpp

/** // doc: clxx/util/to_string.hpp {{{
 * \file clxx/util/to_string.hpp
 * \brief Conversions of several types of data to string
 *
 * This header implements overloaded std::to_string for several types defined
 * in clxx.
 */ // }}}
#ifndef CLXX_UTIL_TO_STRING_HPP_INCLUDED
#define CLXX_UTIL_TO_STRING_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/util/enum2name.hpp>
#include <clxx/util/enum2hex.hpp>
#include <string>
#include <type_traits>

namespace clxx {
/** // doc: enum_to_name_of_hex {{{
 * \brief Convert an enum value to its string representation
 *
 * For most values of enums defined in <tt>clxx/types.hpp</tt> it returns a
 * string representation of enum value (name of enum). For the values not
 * recognized by the library, however, it returns a string representation
 * of a hexadecimal value of the enum.
 *
 * \param x The value to be converted
 * \returns String representation of the value \em x
 */ // }}}
template<typename E>
std::string enum_to_name_or_hex(E x)
{
  char const* name = clxx::enum2name(x);
  return name ? std::string(name) : enum2hex(x);
}
/** // doc: enum_to_name_of_hex {{{
 * \brief Convert an enum value to string interpreting it as a bitmask
 *
 * Generates a string composed of or'ed values of enum-bits that are present
 * in the provided value \em x.
 *
 * \param x The value to be converted
 * \param end Final value of a moving bit when the function stops scanning for
 *            active bits in the bit-field \em x
 * \returns The string representation of the bits contained in \em x
 *
 * \par Example
 *
 * The invocation:
 *
 * \code
 *  s = enum_bitmask_to_string(device_type_t::cpu | device_type_t::gpu);
 * \endcode
 *
 * shall return string <tt>"cpu | gpu"</tt>
 */ // }}}
template<typename E>
std::string enum_bitmask_to_string(E x, typename std::underlying_type<E>::type end = 0)
{
  typedef typename std::underlying_type<E>::type T;
  T const t = static_cast<T>(x);
  if(t == static_cast<T>(0))
    {
      return enum_to_name_or_hex(x);
    }
  else
    {
      std::string result;
      std::string sep;
      for (T bit = 1; bit != end; bit <<= 1)
        {
          if(t & bit)
            {
              result += (sep + enum_to_name_or_hex(static_cast<E>(bit)));
              sep = " | ";
            }
        }
      return result;
    }
}

} // end namespace clxx

namespace std {

/** // doc: to_string(clxx::status_t) {{{
 * \brief Convert \ref clxx::status_t "status_t" value to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the status code contained in \em x
 */ // }}}
inline string to_string(clxx::status_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::platform_info_t) {{{
 * \brief Convert \ref clxx::platform_info_t "platform_info_t" value to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the platform info code contained in \em x
 */ // }}}
inline string to_string(clxx::platform_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_type_t) {{{
 * \brief Convert \ref clxx::device_type_t "device_type_t" value to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the device type bits contained in \em x
 */ // }}}
inline string to_string(clxx::device_type_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::device_info_t) {{{
 * \brief Convert \ref clxx::device_info_t "device_info_t" value to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the device info code contained in \em x
 */ // }}}
inline string to_string(clxx::device_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_fp_config_t) {{{
 * \brief Convert \ref clxx::device_fp_config_t "device_fp_config_t" value to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the device fp config bits contained in \em x
 */ // }}}
inline string to_string(clxx::device_fp_config_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::device_mem_cache_type_t) {{{
 * \brief Convert \ref clxx::device_mem_cache_type_t "device_mem_cache_type_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the device mem cache type code contained in \em x
 */ // }}}
inline string to_string(clxx::device_mem_cache_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_local_mem_type_t) {{{
 * \brief Convert \ref clxx::device_local_mem_type_t "device_local_mem_type_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the device local mem type code contained in \em x
 */ // }}}
inline string to_string(clxx::device_local_mem_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_exec_capabilities_t) {{{
 * \brief Convert \ref clxx::device_exec_capabilities_t "device_exec_capabilities_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the device exec capabilities bits contained in \em x
 */ // }}}
inline string to_string(clxx::device_exec_capabilities_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::command_queue_properties_t) {{{
 * \brief Convert \ref clxx::command_queue_properties_t "command_queue_properties_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the command queue properties bits contained in \em x
 */ // }}}
inline string to_string(clxx::command_queue_properties_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::context_info_t) {{{
 * \brief Convert \ref clxx::context_info_t "context_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the context info code contained in \em x
 */ // }}}
inline string to_string(clxx::context_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::context_properties_t) {{{
 * \brief Convert \ref clxx::context_properties_t "context_properties_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the context info code contained in \em x
 */ // }}}
inline string to_string(clxx::context_properties_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::device_partition_property_t) {{{
 * \brief Convert \ref clxx::device_partition_property_t "device_partition_property_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the device partition property code constained in \em x
 */ // }}}
inline string to_string(clxx::device_partition_property_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::device_affinity_domain_t) {{{
 * \brief Convert \ref clxx::device_affinity_domain_t "device_affinity_domain_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the device affinity domain bits contained in \em x
 */ // }}}
inline string to_string(clxx::device_affinity_domain_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::command_queue_info_t) {{{
 * \brief Convert \ref clxx::command_queue_info_t "command_queue_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the command queue info code contained in \em x
 */ // }}}
inline string to_string(clxx::command_queue_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::mem_flags_t) {{{
 * \brief Convert \ref clxx::mem_flags_t "mem_flags_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the mem flags contained in \em x
 */ // }}}
inline string to_string(clxx::mem_flags_t x)
{ return clxx::enum_bitmask_to_string(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::mem_migration_flags_t) {{{
 * \brief Convert \ref clxx::mem_migration_flags_t "mem_flags_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the mem migration flags contained in \em x
 */ // }}}
inline string to_string(clxx::mem_migration_flags_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::channel_order_t) {{{
 * \brief Convert \ref clxx::channel_order_t "channel_order_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the channel order code contained in \em x
 */ // }}}
inline string to_string(clxx::channel_order_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::channel_type_t) {{{
 * \brief Convert \ref clxx::channel_type_t "channel_type_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the channel type code contained in \em x
 */ // }}}
inline string to_string(clxx::channel_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::mem_object_type_t) {{{
 * \brief Convert \ref clxx::mem_object_type_t "mem_object_type_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the mem object type code contained in \em x
 */ // }}}
inline string to_string(clxx::mem_object_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::mem_info_t) {{{
 * \brief Convert \ref clxx::mem_info_t "mem_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the mem info code contained in \em x
 */ // }}}
inline string to_string(clxx::mem_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::image_info_t) {{{
 * \brief Convert \ref clxx::image_info_t "image_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the image info code contained in \em x
 */ // }}}
inline string to_string(clxx::image_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::addressing_mode_t) {{{
 * \brief Convert \ref clxx::addressing_mode_t "addressing_mode_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the addressing mode code contained in \em x
 */ // }}}
inline string to_string(clxx::addressing_mode_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::filter_mode_t) {{{
 * \brief Convert \ref clxx::filter_mode_t "filter_mode_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the filter mode code contained in \em x
 */ // }}}
inline string to_string(clxx::filter_mode_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::sampler_info_t) {{{
 * \brief Convert \ref clxx::sampler_info_t "sampler_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the sampler info code contained in \em x
 */ // }}}
inline string to_string(clxx::sampler_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::map_flags_t) {{{
 * \brief Convert \ref clxx::map_flags_t "map_flags_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the map flags bits contained in \em x
 */ // }}}
inline string to_string(clxx::map_flags_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::program_info_t) {{{
 * \brief Convert \ref clxx::program_info_t "program_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the program info code contained in \em x
 */ // }}}
inline string to_string(clxx::program_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::program_build_info_t) {{{
 * \brief Convert \ref clxx::program_build_info_t "program_build_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the program build info code contained in \em x
 */ // }}}
inline string to_string(clxx::program_build_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::program_binary_type_t) {{{
 * \brief Convert \ref clxx::program_binary_type_t "program_binary_type_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the program binary type bits contained in \em x
 */ // }}}
inline string to_string(clxx::program_binary_type_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::build_status_t) {{{
 * \brief Convert \ref clxx::build_status_t "build_status_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the build status code contained in \em x
 */ // }}}
inline string to_string(clxx::build_status_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::kernel_info_t) {{{
 * \brief Convert \ref clxx::kernel_info_t "kernel_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the kernel info code contained in \em x
 */ // }}}
inline string to_string(clxx::kernel_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_info_t) {{{
 * \brief Convert \ref clxx::kernel_arg_info_t "kernel_arg_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the kernel arg info code contained in \em x
 */ // }}}
inline string to_string(clxx::kernel_arg_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_address_qualifier_t) {{{
 * \brief Convert \ref clxx::kernel_arg_address_qualifier_t "kernel_arg_address_qualifier_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the kernel arg address qualifier code contained in \em x
 */ // }}}
inline string to_string(clxx::kernel_arg_address_qualifier_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_access_qualifier_t) {{{
 * \brief Convert \ref clxx::kernel_arg_access_qualifier_t "kernel_arg_access_qualifier_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the kernel arg access qualifier code contained in \em x
 */ // }}}
inline string to_string(clxx::kernel_arg_access_qualifier_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_type_qualifier_t) {{{
 * \brief Convert \ref clxx::kernel_arg_type_qualifier_t "kernel_arg_type_qualifier_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of the kernel arg type qualifier bits contained in \em x
 */ // }}}
inline string to_string(clxx::kernel_arg_type_qualifier_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::kernel_work_group_info_t) {{{
 * \brief Convert \ref clxx::kernel_work_group_info_t "kernel_work_group_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation of kernel work group info code contained in \em x
 */ // }}}
inline string to_string(clxx::kernel_work_group_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::event_info_t) {{{
 * \brief Convert \ref clxx::event_info_t "event_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the event info code contained in \em x
 */ // }}}
inline string to_string(clxx::event_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::command_type_t) {{{
 * \brief Convert \ref clxx::command_type_t "command_type_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the command type code contained in \em x
 */ // }}}
inline string to_string(clxx::command_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::command_exec_status_t) {{{
 * \brief Convert \ref clxx::command_exec_status_t "command_exec_status_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the command exec status code contained in \em x
 */ // }}}
inline string to_string(clxx::command_exec_status_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_1
/** // doc: to_string(clxx::buffer_create_type_t) {{{
 * \brief Convert \ref clxx::buffer_create_type_t "buffer_create_type_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the buffer create type code contained in \em x
 */ // }}}
inline string to_string(clxx::buffer_create_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
/** // doc: to_string(clxx::profiling_info_t) {{{
 * \brief Convert \ref clxx::profiling_info_t "profiling_info_t" to string
 * \param x An enum value to be converted to a string
 * \returns String representation (name) of the profiling info code contained in \em x
 */ // }}}
inline string to_string(clxx::profiling_info_t x)
{ return clxx::enum_to_name_or_hex(x); }

} // end namespace std

#endif /* CLXX_UTIL_TO_STRING_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
