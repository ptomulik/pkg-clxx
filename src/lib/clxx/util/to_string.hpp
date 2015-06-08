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
 * \todo Write documentation
 */ // }}}
template<typename E>
std::string enum_to_name_or_hex(E x)
{
  char const* name = clxx::enum2name(x);
  return name ? std::string(name) : enum2hex(x);
}
/** // doc: enum_to_name_of_hex {{{
 * \todo Write documentation
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
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::status_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::platform_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::platform_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_type_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::device_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_fp_config_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_fp_config_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::device_mem_cache_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_mem_cache_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_local_mem_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_local_mem_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::device_exec_capabilities_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_exec_capabilities_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::command_queue_properties_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::command_queue_properties_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::context_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::context_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::context_properties_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::context_properties_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::device_partition_property_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_partition_property_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::device_affinity_domain_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::device_affinity_domain_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::command_queue_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::command_queue_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::mem_flags_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::mem_flags_t x)
{ return clxx::enum_bitmask_to_string(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::mem_migration_flags_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::mem_migration_flags_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::channel_order_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::channel_order_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::channel_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::channel_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::mem_object_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::mem_object_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::mem_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::mem_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::image_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::image_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::addressing_mode_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::addressing_mode_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::filter_mode_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::filter_mode_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::sampler_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::sampler_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::map_flags_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::map_flags_t x)
{ return clxx::enum_bitmask_to_string(x); }
/** // doc: to_string(clxx::program_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::program_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::program_build_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::program_build_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::program_binary_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::program_binary_type_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::build_status_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::build_status_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::kernel_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::kernel_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::kernel_arg_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_address_qualifier_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::kernel_arg_address_qualifier_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_access_qualifier_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::kernel_arg_access_qualifier_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
#if CL_VERSION_1_2
/** // doc: to_string(clxx::kernel_arg_type_qualifier_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::kernel_arg_type_qualifier_t x)
{ return clxx::enum_bitmask_to_string(x); }
#endif
/** // doc: to_string(clxx::kernel_work_group_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::kernel_work_group_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::event_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::event_info_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::command_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::command_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
/** // doc: to_string(clxx::command_exec_status_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::command_exec_status_t x)
{ return clxx::enum_to_name_or_hex(x); }
#if CL_VERSION_1_1
/** // doc: to_string(clxx::buffer_create_type_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::buffer_create_type_t x)
{ return clxx::enum_to_name_or_hex(x); }
#endif
/** // doc: to_string(clxx::profiling_info_t) {{{
 * \todo Write documentation
 */ // }}}
inline string to_string(clxx::profiling_info_t x)
{ return clxx::enum_to_name_or_hex(x); }

} // end namespace std

#endif /* CLXX_UTIL_TO_STRING_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
