// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clerror_no.t.h

/** // doc: clxx/clerror_no.t.h {{{
 * \file clxx/clerror_no.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_CLERROR_NO_T_H_INCLUDED
#define CLXX_CL_CLERROR_NO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/clerror_no.hpp>

namespace clxx { class clerror_no_test; }

/** // doc: class clxx::clerror_no_test {{{
 * \todo Write documentation
 */ // }}}
class clxx::clerror_no_test : public CxxTest::TestSuite
{
public:
  /** // doc: test_device_not_found() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_not_found()
  {
    typedef clerror_no<status_t::device_not_found> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::device_not_found);
    TS_ASSERT_EQUALS(T().code(), status_t::device_not_found);
    TS_ASSERT_EQUALS(T().what(),"device not found");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    // TS_ASSERT_THROWS(throw T(), std::runtime_error const&); // ???
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_device_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_not_available()
  {
    typedef clerror_no<status_t::device_not_available> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::device_not_available);
    TS_ASSERT_EQUALS(T().code(), status_t::device_not_available);
    TS_ASSERT_EQUALS(T().what(),"device not available");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    // TS_ASSERT_THROWS(throw T(), std::runtime_error const&); // ???
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_compiler_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_compiler_not_available()
  {
    typedef clerror_no<status_t::compiler_not_available> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::compiler_not_available);
    TS_ASSERT_EQUALS(T().code(), status_t::compiler_not_available);
    TS_ASSERT_EQUALS(T().what(),"compiler not available");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    // TS_ASSERT_THROWS(throw T(), std::runtime_error const&); // ???
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test_mem_object_allocation_failure()
  {
    typedef clerror_no<status_t::mem_object_allocation_failure> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::mem_object_allocation_failure);
    TS_ASSERT_EQUALS(T().code(), status_t::mem_object_allocation_failure);
    TS_ASSERT_EQUALS(T().what(),"memory object allocation failure");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::bad_alloc const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test_out_of_resources()
  {
    typedef clerror_no<status_t::out_of_resources> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::out_of_resources);
    TS_ASSERT_EQUALS(T().code(), status_t::out_of_resources);
    TS_ASSERT_EQUALS(T().what(),"out of resources");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test_out_of_host_memory()
  {
    typedef clerror_no<status_t::out_of_host_memory> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::out_of_host_memory);
    TS_ASSERT_EQUALS(T().code(), status_t::out_of_host_memory);
    TS_ASSERT_EQUALS(T().what(),"out of host memory");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::bad_alloc const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_profiling_info_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_profiling_info_not_available()
  {
    typedef clerror_no<status_t::profiling_info_not_available> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::profiling_info_not_available);
    TS_ASSERT_EQUALS(T().code(), status_t::profiling_info_not_available);
    TS_ASSERT_EQUALS(T().what(),"profiling info not available");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    // TS_ASSERT_THROWS(throw T(), std::runtime_error const&); // ???
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_mem_copy_overlap() {{{
   * \todo Write documentation
   */ // }}}
  void test_mem_copy_overlap()
  {
    typedef clerror_no<status_t::mem_copy_overlap> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::mem_copy_overlap);
    TS_ASSERT_EQUALS(T().code(), status_t::mem_copy_overlap);
    TS_ASSERT_EQUALS(T().what(),"memory copy overlap");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    // TS_ASSERT_THROWS(throw T(), std::runtime_error const&); // ???
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_image_format_mismatch() {{{
   * \todo Write documentation
   */ // }}}
  void test_image_format_mismatch()
  {
    typedef clerror_no<status_t::image_format_mismatch> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::image_format_mismatch);
    TS_ASSERT_EQUALS(T().code(), status_t::image_format_mismatch);
    TS_ASSERT_EQUALS(T().what(),"image format mismatch");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    // TS_ASSERT_THROWS(throw T(), std::runtime_error const&); // ???
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_image_format_not_supported() {{{
   * \todo Write documentation
   */ // }}}
  void test_image_format_not_supported()
  {
    typedef clerror_no<status_t::image_format_not_supported> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::image_format_not_supported);
    TS_ASSERT_EQUALS(T().code(), status_t::image_format_not_supported);
    TS_ASSERT_EQUALS(T().what(),"image format not supported");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    // TS_ASSERT_THROWS(throw T(), std::runtime_error const&); // ???
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_build_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test_build_program_failure()
  {
    typedef clerror_no<status_t::build_program_failure> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::build_program_failure);
    TS_ASSERT_EQUALS(T().code(), status_t::build_program_failure);
    TS_ASSERT_EQUALS(T().what(),"build program failure");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_map_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test_map_failure()
  {
    typedef clerror_no<status_t::map_failure> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::map_failure);
    TS_ASSERT_EQUALS(T().code(), status_t::map_failure);
    TS_ASSERT_EQUALS(T().what(),"map failure");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
#if CL_VERSION_1_1
  /** // doc: test_misaligned_sub_buffer_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test_misaligned_sub_buffer_offset()
  {
    typedef clerror_no<status_t::misaligned_sub_buffer_offset> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::misaligned_sub_buffer_offset);
    TS_ASSERT_EQUALS(T().code(), status_t::misaligned_sub_buffer_offset);
    TS_ASSERT_EQUALS(T().what(),"misaligned sub buffer offset");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test_exec_status_error_for_events_in_wait_list()
  {
    typedef clerror_no<status_t::exec_status_error_for_events_in_wait_list> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::exec_status_error_for_events_in_wait_list);
    TS_ASSERT_EQUALS(T().code(), status_t::exec_status_error_for_events_in_wait_list);
    TS_ASSERT_EQUALS(T().what(),"execution status error for events in wait list");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_compile_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test_compile_program_failure()
  {
    typedef clerror_no<status_t::compile_program_failure> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::compile_program_failure);
    TS_ASSERT_EQUALS(T().code(), status_t::compile_program_failure);
    TS_ASSERT_EQUALS(T().what(),"compile program failure");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_linker_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_linker_not_available()
  {
    typedef clerror_no<status_t::linker_not_available> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::linker_not_available);
    TS_ASSERT_EQUALS(T().code(), status_t::linker_not_available);
    TS_ASSERT_EQUALS(T().what(),"linker not available");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_link_program_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test_link_program_failure()
  {
    typedef clerror_no<status_t::link_program_failure> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::link_program_failure);
    TS_ASSERT_EQUALS(T().code(), status_t::link_program_failure);
    TS_ASSERT_EQUALS(T().what(),"link program failure");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_device_partition_failed() {{{
   * \todo Write documentation
   */ // }}}
  void test_device_partition_failed()
  {
    typedef clerror_no<status_t::device_partition_failed> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::device_partition_failed);
    TS_ASSERT_EQUALS(T().code(), status_t::device_partition_failed);
    TS_ASSERT_EQUALS(T().what(),"device partition failed");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_kernel_arg_info_not_available() {{{
   * \todo Write documentation
   */ // }}}
  void test_kernel_arg_info_not_available()
  {
    typedef clerror_no<status_t::kernel_arg_info_not_available> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::kernel_arg_info_not_available);
    TS_ASSERT_EQUALS(T().code(), status_t::kernel_arg_info_not_available);
    TS_ASSERT_EQUALS(T().what(),"kernel argument info not available");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
#endif
  /** // doc: test_invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_value()
  {
    typedef clerror_no<status_t::invalid_value> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_value);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_value);
    TS_ASSERT_EQUALS(T().what(),"invalid value");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_device_type() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_device_type()
  {
    typedef clerror_no<status_t::invalid_device_type> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_device_type);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_device_type);
    TS_ASSERT_EQUALS(T().what(),"invalid device type");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_platform() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_platform()
  {
    typedef clerror_no<status_t::invalid_platform> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_platform);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_platform);
    TS_ASSERT_EQUALS(T().what(),"invalid platform");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_device() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_device()
  {
    typedef clerror_no<status_t::invalid_device> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_device);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_device);
    TS_ASSERT_EQUALS(T().what(),"invalid device");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_context()
  {
    typedef clerror_no<status_t::invalid_context> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_context);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_context);
    TS_ASSERT_EQUALS(T().what(),"invalid context");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_queue_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_queue_properties()
  {
    typedef clerror_no<status_t::invalid_queue_properties> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_queue_properties);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_queue_properties);
    TS_ASSERT_EQUALS(T().what(),"invalid queue properties");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_command_queue()
  {
    typedef clerror_no<status_t::invalid_command_queue> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_command_queue);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_command_queue);
    TS_ASSERT_EQUALS(T().what(),"invalid command queue");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_host_ptr() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_host_ptr()
  {
    typedef clerror_no<status_t::invalid_host_ptr> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_host_ptr);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_host_ptr);
    TS_ASSERT_EQUALS(T().what(),"invalid host ptr");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_mem_object()
  {
    typedef clerror_no<status_t::invalid_mem_object> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_mem_object);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_mem_object);
    TS_ASSERT_EQUALS(T().what(),"invalid memory object");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_image_format_descriptor() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_image_format_descriptor()
  {
    typedef clerror_no<status_t::invalid_image_format_descriptor> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_image_format_descriptor);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_image_format_descriptor);
    TS_ASSERT_EQUALS(T().what(),"invalid image format descriptor");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_image_size()
  {
    typedef clerror_no<status_t::invalid_image_size> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_image_size);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_image_size);
    TS_ASSERT_EQUALS(T().what(),"invalid image size");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_sampler()
  {
    typedef clerror_no<status_t::invalid_sampler> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_sampler);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_sampler);
    TS_ASSERT_EQUALS(T().what(),"invalid sampler");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_binary()
  {
    typedef clerror_no<status_t::invalid_binary> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_binary);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_binary);
    TS_ASSERT_EQUALS(T().what(),"invalid binary");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_build_options() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_build_options()
  {
    typedef clerror_no<status_t::invalid_build_options> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_build_options);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_build_options);
    TS_ASSERT_EQUALS(T().what(),"invalid build options");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_program_executable() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_program_executable()
  {
    typedef clerror_no<status_t::invalid_program_executable> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_program_executable);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_program_executable);
    TS_ASSERT_EQUALS(T().what(),"invalid program executable");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_program() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_program()
  {
    typedef clerror_no<status_t::invalid_program> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_program);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_program);
    TS_ASSERT_EQUALS(T().what(),"invalid program");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_kernel_name() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_kernel_name()
  {
    typedef clerror_no<status_t::invalid_kernel_name> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_kernel_name);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_kernel_name);
    TS_ASSERT_EQUALS(T().what(),"invalid kernel name");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_kernel_definition() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_kernel_definition()
  {
    typedef clerror_no<status_t::invalid_kernel_definition> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_kernel_definition);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_kernel_definition);
    TS_ASSERT_EQUALS(T().what(),"invalid kernel definition");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_kernel_args() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_kernel_args()
  {
    typedef clerror_no<status_t::invalid_kernel_args> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_kernel_args);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_kernel_args);
    TS_ASSERT_EQUALS(T().what(),"invalid kernel arguments");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_kernel()
  {
    typedef clerror_no<status_t::invalid_kernel> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_kernel);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_kernel);
    TS_ASSERT_EQUALS(T().what(),"invalid kernel");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_arg_index() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_arg_index()
  {
    typedef clerror_no<status_t::invalid_arg_index> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_arg_index);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_arg_index);
    TS_ASSERT_EQUALS(T().what(),"invalid argument index");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_arg_value() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_arg_value()
  {
    typedef clerror_no<status_t::invalid_arg_value> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_arg_value);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_arg_value);
    TS_ASSERT_EQUALS(T().what(),"invalid argument value");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_arg_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_arg_size()
  {
    typedef clerror_no<status_t::invalid_arg_size> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_arg_size);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_arg_size);
    TS_ASSERT_EQUALS(T().what(),"invalid argument size");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_work_dimension() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_work_dimension()
  {
    typedef clerror_no<status_t::invalid_work_dimension> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_work_dimension);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_work_dimension);
    TS_ASSERT_EQUALS(T().what(),"invalid work dimension");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_work_group_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_work_group_size()
  {
    typedef clerror_no<status_t::invalid_work_group_size> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_work_group_size);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_work_group_size);
    TS_ASSERT_EQUALS(T().what(),"invalid work group size");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_work_item_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_work_item_size()
  {
    typedef clerror_no<status_t::invalid_work_item_size> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_work_item_size);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_work_item_size);
    TS_ASSERT_EQUALS(T().what(),"invalid work item size");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_global_offset() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_global_offset()
  {
    typedef clerror_no<status_t::invalid_global_offset> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_global_offset);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_global_offset);
    TS_ASSERT_EQUALS(T().what(),"invalid global offset");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_event_wait_list()
  {
    typedef clerror_no<status_t::invalid_event_wait_list> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_event_wait_list);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_event_wait_list);
    TS_ASSERT_EQUALS(T().what(),"invalid event wait list");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_event() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_event()
  {
    typedef clerror_no<status_t::invalid_event> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_event);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_event);
    TS_ASSERT_EQUALS(T().what(),"invalid event");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_operation()
  {
    typedef clerror_no<status_t::invalid_operation> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_operation);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_operation);
    TS_ASSERT_EQUALS(T().what(),"invalid operation");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_gl_object() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_gl_object()
  {
    typedef clerror_no<status_t::invalid_gl_object> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_gl_object);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_gl_object);
    TS_ASSERT_EQUALS(T().what(),"invalid GL object");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_buffer_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_buffer_size()
  {
    typedef clerror_no<status_t::invalid_buffer_size> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_buffer_size);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_buffer_size);
    TS_ASSERT_EQUALS(T().what(),"invalid buffer size");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_mip_level() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_mip_level()
  {
    typedef clerror_no<status_t::invalid_mip_level> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_mip_level);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_mip_level);
    TS_ASSERT_EQUALS(T().what(),"invalid mip level");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_global_work_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_global_work_size()
  {
    typedef clerror_no<status_t::invalid_global_work_size> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_global_work_size);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_global_work_size);
    TS_ASSERT_EQUALS(T().what(),"invalid global work size");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
#if CL_VERSION_1_1
  /** // doc: test_invalid_property() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_property()
  {
    typedef clerror_no<status_t::invalid_property> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_property);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_property);
    TS_ASSERT_EQUALS(T().what(),"invalid property");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
#endif
#if CL_VERSION_1_2
  /** // doc: test_invalid_image_descriptor() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_image_descriptor()
  {
    typedef clerror_no<status_t::invalid_image_descriptor> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_image_descriptor);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_image_descriptor);
    TS_ASSERT_EQUALS(T().what(),"invalid image descriptor");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_compiler_options() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_compiler_options()
  {
    typedef clerror_no<status_t::invalid_compiler_options> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_compiler_options);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_compiler_options);
    TS_ASSERT_EQUALS(T().what(),"invalid compiler options");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_linker_options() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_linker_options()
  {
    typedef clerror_no<status_t::invalid_linker_options> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_linker_options);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_linker_options);
    TS_ASSERT_EQUALS(T().what(),"invalid linker options");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
  /** // doc: test_invalid_device_partition_count() {{{
   * \todo Write documentation
   */ // }}}
  void test_invalid_device_partition_count()
  {
    typedef clerror_no<status_t::invalid_device_partition_count> T;
    TS_ASSERT_EQUALS(T::static_code, status_t::invalid_device_partition_count);
    TS_ASSERT_EQUALS(T().code(), status_t::invalid_device_partition_count);
    TS_ASSERT_EQUALS(T().what(),"invalid device partition count");
    TS_ASSERT_THROWS(throw T(), T const&);
    TS_ASSERT_THROWS(throw T(), clxx::clerror const&);
    TS_ASSERT_THROWS(throw T(), clxx::exception const&);
    TS_ASSERT_THROWS(throw T(), std::invalid_argument const&);
    TS_ASSERT_THROWS(throw T(), std::exception const&);
  }
#endif
};

#endif /* CLXX_CL_CLERROR_NO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
