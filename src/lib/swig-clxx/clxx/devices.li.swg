// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/devices.li.swg {{{
 * \file clxx/devices.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/devices.hpp>
%}

//%include <clxx/device.swg>
//%include <clxx/platform.swg>
%include <std_vector.i>
%template() std::vector<cl_device_id>; // used by get_device_ids();
%template(devices) std::vector<clxx::device>;
%ignore clxx::devices;

%include <clxx/exception_support.swg>

%throws_clerror(clxx::get_num_devices(cl_platform_id, clxx::device_type_t));
%throws_clerror_badalloc(clxx::get_device_ids(cl_platform_id, clxx::device_type_t));
%throws_clerror_badalloc(clxx::get_devices(cl_platform_id, clxx::device_type_t));
%throws_clerror_badalloc(clxx::get_devices(clxx::platform const&, clxx::device_type_t));
%throws_badalloc(clxx::make_devices(std::vector<cl_device_id> const&));

%include <clxx/devices.hpp>


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
