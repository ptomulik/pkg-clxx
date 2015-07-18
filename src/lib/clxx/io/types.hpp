// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/types.hpp

/** // doc: clxx/io/types.hpp {{{
 * \file clxx/io/types.hpp
 * \brief Declares I/O functions for types defined in clxx/common/types.hpp
 */ // }}}
#ifndef CLXX_IO_TYPES_HPP_INCLUDED
#define CLXX_IO_TYPES_HPP_INCLUDED

#include <clxx/common/types.hpp>
#include <iosfwd>

/** \addtogroup clxx_io
 * @{ */
/** // doc: operator << (os, status_t) {{{
 * \brief Write a value of clxx::status_t to an output stream.
 *
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::status_t x);
/** // doc: operator << (os, platform_info_t) {{{
 * \brief Write out clxx::platform_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::platform_info_t x);
/** // doc: operator << (os, device_type_t) {{{
 * \brief Write out clxx::device_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_type_t x);
/** // doc: operator << (os, device_info_t) {{{
 * \brief Write out clxx::device_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_info_t x);
/** // doc: operator << (os, device_fp_config_t) {{{
 * \brief Write out clxx::device_fp_config_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_fp_config_t x);
/** // doc: operator << (os, device_mem_cache_type_t) {{{
 * \brief Write out clxx::device_mem_cache_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_mem_cache_type_t x);
/** // doc: operator << (os, device_local_mem_type_t) {{{
 * \brief Write out clxx::device_local_mem_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_local_mem_type_t x);
/** // doc: operator << (os, device_exec_capabilities_t) {{{
 * \brief Write out clxx::device_exec_capabilities_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_exec_capabilities_t x);
/** // doc: operator << (os, command_queue_properties_t) {{{
 * \brief Write out clxx::command_queue_properties_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_queue_properties_t x);
/** // doc: operator << (os, context_info_t) {{{
 * \brief Write out clxx::context_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::context_info_t x);
/** // doc: operator << (os, context_properties_t) {{{
 * \brief Write out clxx::context_properties_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::context_properties_t x);
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, device_partition_property_t) {{{
 * \brief Write out clxx::device_partition_property_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_partition_property_t x);
#endif
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, device_affinity_domain_t) {{{
 * \brief Write out clxx::device_affinity_domain_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_affinity_domain_t x);
#endif
/** // doc: operator << (os, command_queue_info_t) {{{
 * \brief Write out clxx::command_queue_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_queue_info_t x);
/** // doc: operator << (os, mem_flags_t) {{{
 * \brief Write out clxx::mem_flags_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_flags_t x);
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, mem_migration_flags_t) {{{
 * \brief Write out clxx::mem_migration_flags_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_migration_flags_t x);
#endif
/** // doc: operator << (os, channel_order_t) {{{
 * \brief Write out clxx::channel_order_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::channel_order_t x);
/** // doc: operator << (os, channel_type_t) {{{
 * \brief Write out clxx::channel_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::channel_type_t x);
/** // doc: operator << (os, mem_object_type_t) {{{
 * \brief Write out clxx::mem_object_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_object_type_t x);
/** // doc: operator << (os, mem_info_t) {{{
 * \brief Write out clxx::mem_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_info_t x);
/** // doc: operator << (os, image_info_t) {{{
 * \brief Write out clxx::image_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::image_info_t x);
/** // doc: operator << (os, addressing_mode_t) {{{
 * \brief Write out clxx::addressing_mode_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::addressing_mode_t x);
/** // doc: operator << (os, filter_mode_t) {{{
 * \brief Write out clxx::filter_mode_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::filter_mode_t x);
/** // doc: operator << (os, sampler_info_t) {{{
 * \brief Write out clxx::sampler_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::sampler_info_t x);
/** // doc: operator << (os, map_flags_t) {{{
 * \brief Write out clxx::map_flags_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::map_flags_t x);
/** // doc: operator << (os, program_info_t) {{{
 * \brief Write out clxx::program_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_info_t x);
/** // doc: operator << (os, program_build_info_t) {{{
 * \brief Write out clxx::program_build_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_build_info_t x);
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, program_binary_type_t) {{{
 * \brief Write out clxx::program_binary_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_binary_type_t x);
#endif
/** // doc: operator << (os, build_status_t) {{{
 * \brief Write out clxx::build_status_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::build_status_t x);
/** // doc: operator << (os, kernel_info_t) {{{
 * \brief Write out clxx::kernel_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_info_t x);
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, kernel_arg_info_t) {{{
 * \brief Write out clxx::kernel_arg_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_info_t x);
#endif
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, kernel_arg_address_qualifier_t) {{{
 * \brief Write out clxx::kernel_arg_address_qualifier_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_address_qualifier_t x);
#endif
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, kernel_arg_access_qualifier_t) {{{
 * \brief Write out clxx::kernel_arg_access_qualifier_t to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_access_qualifier_t x);
#endif
#if CLXX_CL_H_VERSION_1_2
/** // doc: operator << (os, kernel_arg_type_qualifier_t) {{{
 * \brief Write out clxx::kernel_arg_type_qualifier_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_type_qualifier_t x);
#endif
/** // doc: operator << (os, kernel_work_group_info_t) {{{
 * \brief Write out clxx::kernel_work_group_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_work_group_info_t x);
/** // doc: operator << (os, event_info_t) {{{
 * \brief Write out clxx::event_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::event_info_t x);
/** // doc: operator << (os, command_type_t) {{{
 * \brief Write out clxx::command_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_type_t x);
/** // doc: operator << (os, command_exec_status_t) {{{
 * \brief Write out clxx::command_exec_status_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_exec_status_t x);
#if CLXX_CL_H_VERSION_1_1
/** // doc: operator << (os, buffer_create_type_t) {{{
 * \brief Write out clxx:buffer_create_type_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::buffer_create_type_t x);
#endif
/** // doc: operator << (os, profiling_info_t) {{{
 * \brief Write out clxx::profiling_info_t value to a stream
 * \param os  The output stream.
 * \param x   A value to be written-out to \c os.
 * \returns   Modified output stream \c os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::profiling_info_t x);
/** @} */

#endif /* CLXX_IO_TYPES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
