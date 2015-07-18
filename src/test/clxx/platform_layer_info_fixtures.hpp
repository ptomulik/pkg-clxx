// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_layer_info_fixtures.hpp

/** // doc: clxx/platform_layer_info_fixtures.hpp {{{
 * \file clxx/platform_layer_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PLATFORM_LAYER_INFO_FIXTURES_HPP_INCLUDED
#define CLXX_PLATFORM_LAYER_INFO_FIXTURES_HPP_INCLUDED

#include <clxx/info/platform_layer_info.hpp>
#include <clxx/info/platform_info.hpp>
#include <clxx/info/device_info.hpp>

namespace clxx {

struct platform_layer_info_fixtures
  {
    static platform_layer_info _1()
    {
      platform_info_ptr p1(new platform_info());
      platform_info_ptr p2(new platform_info());
      device_info_ptr d11(new device_info());
      device_info_ptr d12(new device_info());
      device_info_ptr d21(new device_info());
      device_info_ptr d22(new device_info());

      p1->set_name("platform 1");
      p2->set_name("platform 2");

      d11->set_name("platform 1 device 1");
      d12->set_name("platform 1 device 2");
      d21->set_name("platform 2 device 1");
      d22->set_name("platform 2 device 2");

      platform_layer_info pli;

      pli.push_back(d11,p1);
      pli.push_back(d12,p1);
      pli.push_back(d21,p2);
      pli.push_back(d22,p2);

      return pli;
    }
  };

} // end namespace clxx

#endif /* CLXX_PLATFORM_LAYER_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
