// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/to_string.t.h

/** // doc: clxx/to_string.t.h {{{
 * \file clxx/to_string.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_TO_STRING_T_H_INCLUDED
#define CLXX_UTIL_TO_STRING_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/util/to_string.hpp>
#include <clxx/types.hpp>
#include <clxx/util/enum2hex.hpp>

namespace clxx { class to_string_test_suite; }

/** // doc: class clxx::to_string_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::to_string_test_suite : public CxxTest::TestSuite
{
  // We take just few named codes for each enum type. Thorough tests are
  // provided by enum2name.t.h.
public:
  /** // doc: test_status_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_status_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(status_t::success), "success");
    TS_ASSERT_EQUALS(std::to_string(static_cast<status_t>(0x1234)), enum2hex(static_cast<status_t>(0x1234)));
  }
  /** // doc: test_platform_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_platform_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(platform_info_t::profile), "profile");
    TS_ASSERT_EQUALS(std::to_string(static_cast<platform_info_t>(0x1234)), enum2hex(static_cast<platform_info_t>(0x1234)));
  }
  /** // doc: test_device_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_type_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(device_type_t::cpu), "cpu");
    TS_ASSERT_EQUALS(std::to_string(device_type_t::cpu | device_type_t::gpu), "cpu | gpu");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_type_t>(0x1200)), enum2hex(static_cast<device_type_t>(0x0200)) + " | " + enum2hex(static_cast<device_type_t>(0x1000)));
  }
  /** // doc: test_device_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_info_t::vendor_id), "vendor_id");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_info_t>(0x1234)), enum2hex(static_cast<device_info_t>(0x1234)));
  }
  /** // doc: test_device_fp_config_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_fp_config_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_fp_config_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(device_fp_config_t::denorm), "denorm");
    TS_ASSERT_EQUALS(std::to_string(device_fp_config_t::denorm | device_fp_config_t::fma), "denorm | fma");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_fp_config_t>(0x1200)), enum2hex(static_cast<device_fp_config_t>(0x0200)) + " | " + enum2hex(static_cast<device_fp_config_t>(0x1000)));
  }
  /** // doc: test_device_mem_cache_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_mem_cache_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_mem_cache_type_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(device_mem_cache_type_t::read_only_cache), "read_only_cache");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_mem_cache_type_t>(0x1234)), enum2hex(static_cast<device_mem_cache_type_t>(0x1234)));
  }
  /** // doc: test_device_local_mem_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_local_mem_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_local_mem_type_t::local), "local");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_local_mem_type_t>(0x1234)), enum2hex(static_cast<device_local_mem_type_t>(0x1234)));
  }
  /** // doc: test_device_exec_capabilities_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_exec_capabilities_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_exec_capabilities_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(device_exec_capabilities_t::kernel), "kernel");
    TS_ASSERT_EQUALS(std::to_string(device_exec_capabilities_t::kernel | device_exec_capabilities_t::native_kernel), "kernel | native_kernel");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_exec_capabilities_t>(0x1200)), enum2hex(static_cast<device_exec_capabilities_t>(0x0200)) + " | " + enum2hex(static_cast<device_exec_capabilities_t>(0x1000)));
  }
  /** // doc: test_command_queue_properties_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_command_queue_properties_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(command_queue_properties_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(command_queue_properties_t::out_of_order_exec_mode_enable), "out_of_order_exec_mode_enable");
    TS_ASSERT_EQUALS(std::to_string(command_queue_properties_t::out_of_order_exec_mode_enable | command_queue_properties_t::profiling_enable), "out_of_order_exec_mode_enable | profiling_enable");
    TS_ASSERT_EQUALS(std::to_string(static_cast<command_queue_properties_t>(0x1200)), enum2hex(static_cast<command_queue_properties_t>(0x0200)) + " | " + enum2hex(static_cast<command_queue_properties_t>(0x1000)));
  }
  /** // doc: test_context_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(context_info_t::reference_count), "reference_count");
    TS_ASSERT_EQUALS(std::to_string(static_cast<context_info_t>(0x1234)), enum2hex(static_cast<context_info_t>(0x1234)));
  }
  /** // doc: test_context_properties_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(context_properties_t::platform), "platform");
    TS_ASSERT_EQUALS(std::to_string(static_cast<context_properties_t>(0x1234)), enum2hex(static_cast<context_properties_t>(0x1234)));
  }
#if CL_VERSION_1_2
  /** // doc: test_device_partition_property_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_property_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_partition_property_t::equally), "equally");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_partition_property_t>(0x1234)), enum2hex(static_cast<device_partition_property_t>(0x1234)));
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_device_affinity_domain_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_affinity_domain_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(device_affinity_domain_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(device_affinity_domain_t::numa), "numa");
    TS_ASSERT_EQUALS(std::to_string(device_affinity_domain_t::numa | device_affinity_domain_t::l3_cache), "numa | l3_cache");
    TS_ASSERT_EQUALS(std::to_string(static_cast<device_affinity_domain_t>(0x1200)), enum2hex(static_cast<device_affinity_domain_t>(0x0200)) + " | " + enum2hex(static_cast<device_affinity_domain_t>(0x1000)));
  }
#endif
  /** // doc: test_command_queue_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_command_queue_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(command_queue_info_t::context), "context");
    TS_ASSERT_EQUALS(std::to_string(static_cast<command_queue_info_t>(0x1234)), enum2hex(static_cast<command_queue_info_t>(0x1234)));
  }
  /** // doc: test_mem_flags_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_mem_flags_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(mem_flags_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(mem_flags_t::read_write), "read_write");
    TS_ASSERT_EQUALS(std::to_string(mem_flags_t::read_write | mem_flags_t::use_host_ptr), "read_write | use_host_ptr");
    TS_ASSERT_EQUALS(std::to_string(static_cast<mem_flags_t>(0x1800)), enum2hex(static_cast<mem_flags_t>(0x0800)) + " | " + enum2hex(static_cast<mem_flags_t>(0x1000)));
  }
#if CL_VERSION_1_2
  /** // doc: test_mem_migration_flags_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_mem_migration_flags_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(mem_migration_flags_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(mem_migration_flags_t::mem_object_host), "mem_object_host");
    TS_ASSERT_EQUALS(std::to_string(mem_migration_flags_t::mem_object_host | mem_migration_flags_t::mem_object_content_undefined), "mem_object_host | mem_object_content_undefined");
    TS_ASSERT_EQUALS(std::to_string(static_cast<mem_migration_flags_t>(0x1200)), enum2hex(static_cast<mem_migration_flags_t>(0x0200)) + " | " + enum2hex(static_cast<mem_migration_flags_t>(0x1000)));
  }
#endif
  /** // doc: test_channel_order_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_channel_order_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(channel_order_t::rg), "rg");
    TS_ASSERT_EQUALS(std::to_string(static_cast<channel_order_t>(0x1234)), enum2hex(static_cast<channel_order_t>(0x1234)));
  }
  /** // doc: test_channel_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_channel_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(channel_type_t::unorm_int16), "unorm_int16");
    TS_ASSERT_EQUALS(std::to_string(static_cast<channel_type_t>(0x1234)), enum2hex(static_cast<channel_type_t>(0x1234)));
  }
  /** // doc: test_mem_object_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_mem_object_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(mem_object_type_t::buffer), "buffer");
    TS_ASSERT_EQUALS(std::to_string(static_cast<mem_object_type_t>(0x1234)), enum2hex(static_cast<mem_object_type_t>(0x1234)));
  }
  /** // doc: test_mem_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_mem_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(mem_info_t::flags), "flags");
    TS_ASSERT_EQUALS(std::to_string(static_cast<mem_info_t>(0x1234)), enum2hex(static_cast<mem_info_t>(0x1234)));
  }
  /** // doc: test_image_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_image_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(image_info_t::element_size), "element_size");
    TS_ASSERT_EQUALS(std::to_string(static_cast<image_info_t>(0x1234)), enum2hex(static_cast<image_info_t>(0x1234)));
  }
  /** // doc: test_addressing_mode_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_addressing_mode_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(addressing_mode_t::clamp_to_edge), "clamp_to_edge");
    TS_ASSERT_EQUALS(std::to_string(static_cast<addressing_mode_t>(0x1234)), enum2hex(static_cast<addressing_mode_t>(0x1234)));
  }
  /** // doc: test_filter_mode_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_filter_mode_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(filter_mode_t::nearest), "nearest");
    TS_ASSERT_EQUALS(std::to_string(static_cast<filter_mode_t>(0x1234)), enum2hex(static_cast<filter_mode_t>(0x1234)));
  }
  /** // doc: test_sampler_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_sampler_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(sampler_info_t::normalized_coords), "normalized_coords");
    TS_ASSERT_EQUALS(std::to_string(static_cast<sampler_info_t>(0x1234)), enum2hex(static_cast<sampler_info_t>(0x1234)));
  }
  /** // doc: test_map_flags_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_map_flags_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(map_flags_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(map_flags_t::read), "read");
    TS_ASSERT_EQUALS(std::to_string(map_flags_t::read | map_flags_t::write), "read | write");
    TS_ASSERT_EQUALS(std::to_string(static_cast<map_flags_t>(0x1200)), enum2hex(static_cast<map_flags_t>(0x0200)) + " | " + enum2hex(static_cast<map_flags_t>(0x1000)));
  }
  /** // doc: test_program_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_program_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(program_info_t::num_devices), "num_devices");
    TS_ASSERT_EQUALS(std::to_string(static_cast<program_info_t>(0x1234)), enum2hex(static_cast<program_info_t>(0x1234)));
  }
  /** // doc: test_program_build_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_program_build_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(program_build_info_t::options), "options");
    TS_ASSERT_EQUALS(std::to_string(static_cast<program_build_info_t>(0x1234)), enum2hex(static_cast<program_build_info_t>(0x1234)));
  }
#if CL_VERSION_1_2
  /** // doc: test_program_binary_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_program_binary_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(program_binary_type_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(program_binary_type_t::compiled_object), "compiled_object");
    TS_ASSERT_EQUALS(std::to_string(program_binary_type_t::compiled_object | program_binary_type_t::library), "compiled_object | library");
    TS_ASSERT_EQUALS(std::to_string(static_cast<program_binary_type_t>(0x1200)), enum2hex(static_cast<program_binary_type_t>(0x0200)) + " | " + enum2hex(static_cast<program_binary_type_t>(0x1000)));
  }
#endif
  /** // doc: test_build_status_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_build_status_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(build_status_t::error), "error");
    TS_ASSERT_EQUALS(std::to_string(static_cast<build_status_t>(0x1234)), enum2hex(static_cast<build_status_t>(0x1234)));
  }
  /** // doc: test_kernel_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_kernel_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(kernel_info_t::num_args), "num_args");
    TS_ASSERT_EQUALS(std::to_string(static_cast<kernel_info_t>(0x1234)), enum2hex(static_cast<kernel_info_t>(0x1234)));
  }
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_kernel_arg_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(kernel_arg_info_t::access_qualifier), "access_qualifier");
    TS_ASSERT_EQUALS(std::to_string(static_cast<kernel_arg_info_t>(0x1234)), enum2hex(static_cast<kernel_arg_info_t>(0x1234)));
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_address_qualifier_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_kernel_arg_address_qualifier_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(kernel_arg_address_qualifier_t::local), "local");
    TS_ASSERT_EQUALS(std::to_string(static_cast<kernel_arg_address_qualifier_t>(0x1234)), enum2hex(static_cast<kernel_arg_address_qualifier_t>(0x1234)));
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_access_qualifier_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_kernel_arg_access_qualifier_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(kernel_arg_access_qualifier_t::write_only), "write_only");
    TS_ASSERT_EQUALS(std::to_string(static_cast<kernel_arg_access_qualifier_t>(0x1234)), enum2hex(static_cast<kernel_arg_access_qualifier_t>(0x1234)));
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_kernel_arg_type_qualifier_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_kernel_arg_type_qualifier_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(kernel_arg_type_qualifier_t::none), "none");
    TS_ASSERT_EQUALS(std::to_string(kernel_arg_type_qualifier_t::const_), "const_");
    TS_ASSERT_EQUALS(std::to_string(kernel_arg_type_qualifier_t::const_ | kernel_arg_type_qualifier_t::restrict_), "const_ | restrict_");
    TS_ASSERT_EQUALS(std::to_string(static_cast<kernel_arg_type_qualifier_t>(0x1200)), enum2hex(static_cast<kernel_arg_type_qualifier_t>(0x0200)) + " | " + enum2hex(static_cast<kernel_arg_type_qualifier_t>(0x1000)));
  }
#endif
  /** // doc: test_kernel_work_group_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_kernel_work_group_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(kernel_work_group_info_t::work_group_size), "work_group_size");
    TS_ASSERT_EQUALS(std::to_string(static_cast<kernel_work_group_info_t>(0x1234)), enum2hex(static_cast<kernel_work_group_info_t>(0x1234)));
  }
  /** // doc: test_event_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_event_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(event_info_t::command_type), "command_type");
    TS_ASSERT_EQUALS(std::to_string(static_cast<event_info_t>(0x1234)), enum2hex(static_cast<event_info_t>(0x1234)));
  }
  /** // doc: test_command_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_command_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(command_type_t::native_kernel), "native_kernel");
    TS_ASSERT_EQUALS(std::to_string(static_cast<command_type_t>(0x1234)), enum2hex(static_cast<command_type_t>(0x1234)));
  }
  /** // doc: test_command_exec_status_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_command_exec_status_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(command_exec_status_t::running), "running");
    TS_ASSERT_EQUALS(std::to_string(static_cast<command_exec_status_t>(0x1234)), enum2hex(static_cast<command_exec_status_t>(0x1234)));
  }
#if CL_VERSION_1_1
  /** // doc: test_buffer_create_type_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_buffer_create_type_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(buffer_create_type_t::region), "region");
    TS_ASSERT_EQUALS(std::to_string(static_cast<buffer_create_type_t>(0x1234)), enum2hex(static_cast<buffer_create_type_t>(0x1234)));
  }
#endif
  /** // doc: test_profiling_info_t() {{{
   * \todo Write documentation
   */ // }}}
  void test_profiling_info_t( )
  {
    TS_ASSERT_EQUALS(std::to_string(profiling_info_t::submit), "submit");
    TS_ASSERT_EQUALS(std::to_string(static_cast<profiling_info_t>(0x1234)), enum2hex(static_cast<profiling_info_t>(0x1234)));
  }
};

#endif /* CLXX_UTIL_TO_STRING_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
