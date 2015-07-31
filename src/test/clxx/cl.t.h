// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl.t.h

/** // doc: clxx/cl.t.h {{{
 * \file clxx/cl.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_T_H_INCLUDED
#define CLXX_CL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl.hpp>

namespace clxx { class cl_hpp_test_suite; }

/** // doc: class clxx::cl_hpp_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::cl_hpp_test_suite : public CxxTest::TestSuite
{
public:
  void test__clxx_cl_clobj_fcn_hpp_included()
  {
#ifdef CLXX_CL_CLOBJ_FCN_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_CLOBJ_FCN_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_clobj_hpp_included()
  {
#ifdef CLXX_CL_CLOBJ_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_CLOBJ_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_command_queue_hpp_included()
  {
#ifdef CLXX_CL_COMMAND_QUEUE_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_COMMAND_QUEUE_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_context_hpp_included()
  {
#ifdef CLXX_CL_CONTEXT_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_CONTEXT_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_context_properties_hpp_included()
  {
#ifdef CLXX_CL_CONTEXT_PROPERTIES_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_CONTEXT_PROPERTIES_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_context_property_hpp_included()
  {
#ifdef CLXX_CL_CONTEXT_PROPERTY_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_CONTEXT_PROPERTY_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_devices_hpp_included()
  {
#ifdef CLXX_CL_DEVICES_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_DEVICES_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_device_hpp_included()
  {
#ifdef CLXX_CL_DEVICE_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_DEVICE_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_device_partition_hpp_included()
  {
#ifdef CLXX_CL_DEVICE_PARTITION_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_DEVICE_PARTITION_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_device_partition_properties_hpp_included()
  {
#ifdef CLXX_CL_DEVICE_PARTITION_PROPERTIES_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_DEVICE_PARTITION_PROPERTIES_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_device_partition_property_hpp_included()
  {
#ifdef CLXX_CL_DEVICE_PARTITION_PROPERTY_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_DEVICE_PARTITION_PROPERTY_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_events_hpp_included()
  {
#ifdef CLXX_CL_EVENTS_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_EVENTS_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_event_hpp_included()
  {
#ifdef CLXX_CL_EVENT_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_EVENT_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_functions_hpp_included()
  {
#ifdef CLXX_CL_FUNCTIONS_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_FUNCTIONS_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_kernels_hpp_included()
  {
#ifdef CLXX_CL_KERNELS_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_KERNELS_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_kernel_fcn_hpp_included()
  {
#ifdef CLXX_CL_KERNEL_FCN_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_KERNEL_FCN_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_kernel_hpp_included()
  {
#ifdef CLXX_CL_KERNEL_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_KERNEL_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_kernel_lazy_ctor_hpp_included()
  {
#ifdef CLXX_CL_KERNEL_LAZY_CTOR_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_KERNEL_LAZY_CTOR_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_mem_fcn_hpp_included()
  {
#ifdef CLXX_CL_MEM_FCN_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_MEM_FCN_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_mem_hpp_included()
  {
#ifdef CLXX_CL_MEM_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_MEM_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_platforms_hpp_included()
  {
#ifdef CLXX_CL_PLATFORMS_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PLATFORMS_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_platform_hpp_included()
  {
#ifdef CLXX_CL_PLATFORM_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PLATFORM_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_platform_layer_hpp_included()
  {
#ifdef CLXX_CL_PLATFORM_LAYER_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PLATFORM_LAYER_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_program_hpp_included()
  {
#ifdef CLXX_CL_PROGRAM_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAM_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_program_fcn_hpp_included()
  {
#ifdef CLXX_CL_PROGRAM_FCN_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAM_FCN_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_program_generator_hpp_included()
  {
#ifdef CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_program_generator_fcn_hpp_included()
  {
#ifdef CLXX_CL_PROGRAM_GENERATOR_FCN_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAM_GENERATOR_FCN_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_program_lazy_fcn_hpp_included()
  {
#ifdef CLXX_CL_PROGRAM_LAZY_FCN_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAM_LAZY_FCN_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_program_lazy_generator_hpp_included()
  {
#ifdef CLXX_CL_PROGRAM_LAZY_GENERATOR_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAM_LAZY_GENERATOR_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_program_observer_hpp_included()
  {
#ifdef CLXX_CL_PROGRAM_OBSERVER_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAM_OBSERVER_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_programs_hpp_included()
  {
#ifdef CLXX_CL_PROGRAMS_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_PROGRAMS_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_cl_runtime_hpp_included()
  {
#ifdef CLXX_CL_RUNTIME_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_CL_RUNTIME_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_common_ndrange_hpp_included()
  {
#ifdef CLXX_COMMON_NDRANGE_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_COMMON_NDRANGE_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_common_program_binaries_hpp_included()
  {
#ifdef CLXX_COMMON_PROGRAM_BINARIES_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_COMMON_PROGRAM_BINARIES_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_common_program_binary_hpp_included()
  {
#ifdef CLXX_COMMON_PROGRAM_BINARY_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_COMMON_PROGRAM_BINARY_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_common_program_sources_hpp_included()
  {
#ifdef CLXX_COMMON_PROGRAM_SOURCES_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_COMMON_PROGRAM_SOURCES_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
  void test__clxx_common_program_source_hpp_included()
  {
#ifdef CLXX_COMMON_PROGRAM_SOURCE_HPP_INCLUDED
    TS_ASSERT(true);
#else
    TS_FAIL("check for CLXX_COMMON_PROGRAM_SOURCE_HPP_INCLUDED in clxx/cl.hpp failed");
#endif
  }
};

#endif /* CLXX_CL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
