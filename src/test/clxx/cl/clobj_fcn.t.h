// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clobj_fcn.t.h

/** // doc: clxx/clobj_fcn.t.h {{{
 * \file clxx/clobj_fcn.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CLOBJ_FCN_T_H_INCLUDED
#define CLXX_CLOBJ_FCN_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/clobj_fcn.hpp>
#include <clxx/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class clobj_fcn_test_suite; }

/** // doc: class clxx::clobj_fcn_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::clobj_fcn_test_suite : public CxxTest::TestSuite
{
public:
  //
  // retain_cl_object()
  //
  /** // doc: test__retain_cl_object__cl_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_command_queue( )
  {
    {
      T::Dummy_clRetainCommandQueue mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_command_queue)0x1234));
      TS_ASSERT(mock.called_once_with((cl_command_queue)0x1234));
    }
    {
      T::Dummy_clRetainCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
      TS_ASSERT_THROWS(retain_cl_object((cl_command_queue)0), clerror_no<status_t::invalid_command_queue>);
    }
    {
      T::Dummy_clRetainCommandQueue mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_command_queue)0), unexpected_clerror);
    }
  }
  /** // doc: test__retain_cl_object__cl_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_context( )
  {
    {
      T::Dummy_clRetainContext mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_context)0x1234));
      TS_ASSERT(mock.called_once_with((cl_context)0x1234));
    }
    {
      T::Dummy_clRetainContext mock(CL_INVALID_CONTEXT);
      TS_ASSERT_THROWS(retain_cl_object((cl_context)0), clerror_no<status_t::invalid_context>);
    }
    {
      T::Dummy_clRetainContext mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_context)0), unexpected_clerror);
    }
  }
  /** // doc: test__retain_cl_object__cl_device_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_device_id( )
  {
    {
      T::Dummy_clRetainDevice mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_device_id)0x1234));
      TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
    }
    {
      T::Dummy_clRetainDevice mock(CL_INVALID_DEVICE);
      TS_ASSERT_THROWS(retain_cl_object((cl_device_id)0), clerror_no<status_t::invalid_device>);
    }
    {
      T::Dummy_clRetainDevice mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_device_id)0), unexpected_clerror);
    }
  }
  /** // doc: test__retain_cl_object__cl_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_event( )
  {
    {
      T::Dummy_clRetainEvent mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_event)0x1234));
      TS_ASSERT(mock.called_once_with((cl_event)0x1234));
    }
    {
      T::Dummy_clRetainEvent mock(CL_INVALID_EVENT);
      TS_ASSERT_THROWS(retain_cl_object((cl_event)0), clerror_no<status_t::invalid_event>);
    }
    {
      T::Dummy_clRetainEvent mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_event)0), unexpected_clerror);
    }
  }
  /** // doc: test__retain_cl_object__cl_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_kernel( )
  {
    {
      T::Dummy_clRetainKernel mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_kernel)0x1234));
      TS_ASSERT(mock.called_once_with((cl_kernel)0x1234));
    }
    {
      T::Dummy_clRetainKernel mock(CL_INVALID_KERNEL);
      TS_ASSERT_THROWS(retain_cl_object((cl_kernel)0), clerror_no<status_t::invalid_kernel>);
    }
    {
      T::Dummy_clRetainKernel mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_kernel)0), unexpected_clerror);
    }
  }
  /** // doc: test__retain_cl_object__cl_mem() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_mem( )
  {
    {
      T::Dummy_clRetainMemObject mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_mem)0x1234));
      TS_ASSERT(mock.called_once_with((cl_mem)0x1234));
    }
    {
      T::Dummy_clRetainMemObject mock(CL_INVALID_MEM_OBJECT);
      TS_ASSERT_THROWS(retain_cl_object((cl_mem)0), clerror_no<status_t::invalid_mem_object>);
    }
    {
      T::Dummy_clRetainMemObject mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_mem)0), unexpected_clerror);
    }
  }
  /** // doc: test__retain_cl_object__cl_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_program( )
  {
    {
      T::Dummy_clRetainProgram mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_program)0x1234));
      TS_ASSERT(mock.called_once_with((cl_program)0x1234));
    }
    {
      T::Dummy_clRetainProgram mock(CL_INVALID_PROGRAM);
      TS_ASSERT_THROWS(retain_cl_object((cl_program)0), clerror_no<status_t::invalid_program>);
    }
    {
      T::Dummy_clRetainProgram mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_program)0), unexpected_clerror);
    }
  }
  /** // doc: test__retain_cl_object__cl_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__retain_cl_object__cl_sampler( )
  {
#if 0
    {
      T::Dummy_clRetainSampler mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(retain_cl_object((cl_sampler)0x1234));
      TS_ASSERT(mock.called_once_with((cl_sampler)0x1234));
    }
    {
      T::Dummy_clRetainSampler mock(CL_INVALID_SAMPLER);
      TS_ASSERT_THROWS(retain_cl_object((cl_sampler)0), clerror_no<status_t::invalid_sampler>);
    }
    {
      T::Dummy_clRetainSampler mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(retain_cl_object((cl_sampler)0), unexpected_clerror);
    }
#endif
  }

  //
  // release_cl_object()
  //
  /** // doc: test__release_cl_object__cl_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_command_queue( )
  {
    {
      T::Dummy_clReleaseCommandQueue mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_command_queue)0x1234));
      TS_ASSERT(mock.called_once_with((cl_command_queue)0x1234));
    }
    {
      T::Dummy_clReleaseCommandQueue mock(CL_INVALID_COMMAND_QUEUE);
      TS_ASSERT_THROWS(release_cl_object((cl_command_queue)0), clerror_no<status_t::invalid_command_queue>);
    }
    {
      T::Dummy_clReleaseCommandQueue mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_command_queue)0), unexpected_clerror);
    }
  }
  /** // doc: test__release_cl_object__cl_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_context( )
  {
    {
      T::Dummy_clReleaseContext mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_context)0x1234));
      TS_ASSERT(mock.called_once_with((cl_context)0x1234));
    }
    {
      T::Dummy_clReleaseContext mock(CL_INVALID_CONTEXT);
      TS_ASSERT_THROWS(release_cl_object((cl_context)0), clerror_no<status_t::invalid_context>);
    }
    {
      T::Dummy_clReleaseContext mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_context)0), unexpected_clerror);
    }
  }
  /** // doc: test__release_cl_object__cl_device_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_device_id( )
  {
    {
      T::Dummy_clReleaseDevice mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_device_id)0x1234));
      TS_ASSERT(mock.called_once_with((cl_device_id)0x1234));
    }
    {
      T::Dummy_clReleaseDevice mock(CL_INVALID_DEVICE);
      TS_ASSERT_THROWS(release_cl_object((cl_device_id)0), clerror_no<status_t::invalid_device>);
    }
    {
      T::Dummy_clReleaseDevice mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_device_id)0), unexpected_clerror);
    }
  }
  /** // doc: test__release_cl_object__cl_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_event( )
  {
    {
      T::Dummy_clReleaseEvent mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_event)0x1234));
      TS_ASSERT(mock.called_once_with((cl_event)0x1234));
    }
    {
      T::Dummy_clReleaseEvent mock(CL_INVALID_EVENT);
      TS_ASSERT_THROWS(release_cl_object((cl_event)0), clerror_no<status_t::invalid_event>);
    }
    {
      T::Dummy_clReleaseEvent mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_event)0), unexpected_clerror);
    }
  }
  /** // doc: test__release_cl_object__cl_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_kernel( )
  {
    {
      T::Dummy_clReleaseKernel mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_kernel)0x1234));
      TS_ASSERT(mock.called_once_with((cl_kernel)0x1234));
    }
    {
      T::Dummy_clReleaseKernel mock(CL_INVALID_KERNEL);
      TS_ASSERT_THROWS(release_cl_object((cl_kernel)0), clerror_no<status_t::invalid_kernel>);
    }
    {
      T::Dummy_clReleaseKernel mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_kernel)0), unexpected_clerror);
    }
  }
  /** // doc: test__release_cl_object__cl_mem() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_mem( )
  {
    {
      T::Dummy_clReleaseMemObject mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_mem)0x1234));
      TS_ASSERT(mock.called_once_with((cl_mem)0x1234));
    }
    {
      T::Dummy_clReleaseMemObject mock(CL_INVALID_MEM_OBJECT);
      TS_ASSERT_THROWS(release_cl_object((cl_mem)0), clerror_no<status_t::invalid_mem_object>);
    }
    {
      T::Dummy_clReleaseMemObject mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_mem)0), unexpected_clerror);
    }
  }
  /** // doc: test__release_cl_object__cl_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_program( )
  {
    {
      T::Dummy_clReleaseProgram mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_program)0x1234));
      TS_ASSERT(mock.called_once_with((cl_program)0x1234));
    }
    {
      T::Dummy_clReleaseProgram mock(CL_INVALID_PROGRAM);
      TS_ASSERT_THROWS(release_cl_object((cl_program)0), clerror_no<status_t::invalid_program>);
    }
    {
      T::Dummy_clReleaseProgram mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_program)0), unexpected_clerror);
    }
  }
  /** // doc: test__release_cl_object__cl_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__release_cl_object__cl_sampler( )
  {
#if 0
    {
      T::Dummy_clReleaseSampler mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(release_cl_object((cl_sampler)0x1234));
      TS_ASSERT(mock.called_once_with((cl_sampler)0x1234));
    }
    {
      T::Dummy_clReleaseSampler mock(CL_INVALID_SAMPLER);
      TS_ASSERT_THROWS(release_cl_object((cl_sampler)0), clerror_no<status_t::invalid_sampler>);
    }
    {
      T::Dummy_clReleaseSampler mock((cl_int)-0x1234567);
      TS_ASSERT_THROWS(release_cl_object((cl_sampler)0), unexpected_clerror);
    }
#endif
  }

  //
  // get_cl_object_info()
  //
  /** // doc: test__get_cl_object_info__cl_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_command_queue( )
  {
    {
      T::Dummy_clGetCommandQueueInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_command_queue)0x1234,
            command_queue_info_t::reference_count,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_command_queue)0x1234,
            CL_QUEUE_REFERENCE_COUNT,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetCommandQueueInfo mock(CL_INVALID_COMMAND_QUEUE);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_command_queue)0,
            command_queue_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_command_queue>
      );
    }
    {
      T::Dummy_clGetCommandQueueInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_command_queue)0,
            command_queue_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_context( )
  {
    {
      T::Dummy_clGetContextInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_context)0x1234,
            context_info_t::reference_count,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_context)0x1234,
            CL_CONTEXT_REFERENCE_COUNT,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetContextInfo mock(CL_INVALID_CONTEXT);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_context)0,
            context_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_context>
      );
    }
    {
      T::Dummy_clGetContextInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_context)0,
            context_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_device() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_device( )
  {
    {
      T::Dummy_clGetDeviceInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_device_id)0x1234,
            device_info_t::platform,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_device_id)0x1234,
            CL_DEVICE_PLATFORM,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetDeviceInfo mock(CL_INVALID_DEVICE);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_device_id)0,
            device_info_t::platform,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_device>
      );
    }
    {
      T::Dummy_clGetDeviceInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_device_id)0,
            device_info_t::platform,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_event( )
  {
    {
      T::Dummy_clGetEventInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_event)0x1234,
            event_info_t::reference_count,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_event)0x1234,
            CL_EVENT_REFERENCE_COUNT,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetEventInfo mock(CL_INVALID_EVENT);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_event)0,
            event_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_event>
      );
    }
    {
      T::Dummy_clGetEventInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_event)0,
            event_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_kernel( )
  {
    {
      T::Dummy_clGetKernelInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_kernel)0x1234,
            kernel_info_t::reference_count,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_kernel)0x1234,
            CL_KERNEL_REFERENCE_COUNT,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetKernelInfo mock(CL_INVALID_KERNEL);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_kernel)0,
            kernel_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_kernel>
      );
    }
    {
      T::Dummy_clGetKernelInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_kernel)0,
            kernel_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_mem() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_mem( )
  {
    {
      T::Dummy_clGetMemObjectInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_mem)0x1234,
            mem_info_t::reference_count,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_mem)0x1234,
            CL_MEM_REFERENCE_COUNT,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetMemObjectInfo mock(CL_INVALID_MEM_OBJECT);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_mem)0,
            mem_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_mem_object>
      );
    }
    {
      T::Dummy_clGetMemObjectInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_mem)0,
            mem_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_platform_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_platform_id( )
  {
    {
      T::Dummy_clGetPlatformInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_platform_id)0x1234,
            platform_info_t::name,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_platform_id)0x1234,
            CL_PLATFORM_NAME,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetPlatformInfo mock(CL_INVALID_PLATFORM);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_platform_id)0,
            platform_info_t::name,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_platform>
      );
    }
    {
      T::Dummy_clGetPlatformInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_platform_id)0,
            platform_info_t::name,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_program() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_program( )
  {
    {
      T::Dummy_clGetProgramInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_program)0x1234,
            program_info_t::reference_count,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_program)0x1234,
            CL_PROGRAM_REFERENCE_COUNT,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetProgramInfo mock(CL_INVALID_PROGRAM);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_program)0,
            program_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_program>
      );
    }
    {
      T::Dummy_clGetProgramInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_program)0,
            program_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
  }
  /** // doc: test__get_cl_object_info__cl_sampler() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_cl_object_info__cl_sampler( )
  {
#if 0
    {
      T::Dummy_clGetSamplerInfo mock(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(get_cl_object_info(
            (cl_sampler)0x1234,
            sampler_info_t::reference_count,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
      TS_ASSERT(mock.called_once_with(
            (cl_sampler)0x1234,
            CL_SAMPLER_REFERENCE_COUNT,
            123,
            (void*)0x5678,
            (size_t*)0x9012
      ));
    }
    {
      T::Dummy_clGetSamplerInfo mock(CL_INVALID_SAMPLER);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_sampler)0,
            sampler_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          clerror_no<status_t::invalid_sampler>
      );
    }
    {
      T::Dummy_clGetSamplerInfo mock(-0x1234567);
      TS_ASSERT_THROWS(
          get_cl_object_info(
            (cl_sampler)0,
            sampler_info_t::reference_count,
            0,
            (void*)0,
            (size_t*)0
          ),
          unexpected_clerror
      );
    }
#endif
  }
};

#endif /* CLXX_CLOBJ_FCN_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
