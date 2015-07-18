// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/types.cpp

/** // doc: clxx/io/types.cpp {{{
 * \file clxx/io/types.cpp
 * \brief Instantiates template I/O functions for types defined in clxx/common/types.hpp
 */ // }}}
#include <ostream>
#include <string>

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}

#include <clxx/io/types_impl.hpp>

//
// Instantiations for char
//
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::status_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::platform_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_fp_config_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_mem_cache_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_local_mem_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_exec_capabilities_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_queue_properties_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::context_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::context_properties_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_partition_property_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_affinity_domain_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_queue_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_flags_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_migration_flags_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::channel_order_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::channel_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_object_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::image_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::addressing_mode_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::filter_mode_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::sampler_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::map_flags_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::program_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::program_build_info_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::program_binary_type_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::build_status_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_info_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_info_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_address_qualifier_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_access_qualifier_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_type_qualifier_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_work_group_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::event_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_exec_status_t);
#if CLXX_CL_H_VERSION_1_1
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::buffer_create_type_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::profiling_info_t);

//
// Instantiations for wchar_t
//
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::status_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::platform_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_fp_config_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_mem_cache_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_local_mem_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_exec_capabilities_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_queue_properties_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::context_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::context_properties_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_partition_property_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_affinity_domain_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_queue_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_flags_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_migration_flags_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::channel_order_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::channel_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_object_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::image_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::addressing_mode_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::filter_mode_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::sampler_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::map_flags_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::program_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::program_build_info_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::program_binary_type_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::build_status_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_info_t);
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_info_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_address_qualifier_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_access_qualifier_t);
#endif
#if CLXX_CL_H_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_type_qualifier_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_work_group_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::event_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_exec_status_t);
#if CLXX_CL_H_VERSION_1_1
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::buffer_create_type_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::profiling_info_t);
/** \endcond */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
