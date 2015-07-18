// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_info_fixtures.hpp

/** // doc: clxx/platform_info_fixtures.hpp {{{
 * \file clxx/platform_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PLATFORM_INFO_FIXTURES_HPP_INCLUDED
#define CLXX_PLATFORM_INFO_FIXTURES_HPP_INCLUDED

#include <clxx/info/platform_info.hpp>

namespace clxx {

struct platform_info_fixtures
{
  static platform_info _1()
  {
    return platform_info()
        .set_id(0x1234ul)
        .set_profile("FULL_PROFILE")
        .set_version("OpenCL 1.2 AMD-APP (1348.4)")
        .set_name("AMD Accelerated Parallel Processing")
        .set_vendor("Advanced Micro Devices, Inc.")
        .set_extensions("cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }

  static platform_info _2()
  {
    return platform_info()
        .set_id(0x54321ul)
        .set_profile("xprofilex")
        .set_version("xversionx")
        .set_name("xnamex")
        .set_vendor("xvendorx")
        .set_extensions("xextensionsx");
  }
};


} // end namespace clxx

#endif /* CLXX_PLATFORM_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
