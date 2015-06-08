// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/device_partition.li.swg {{{
 * \file clxx/device_partition.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/device_partition.hpp>
%}

%include <clxx/exception_support.swg>
%throws_clerror_badalloc(clxx::get_num_sub_devices(device const&, device_partition_properties const&));
%throws_clerror_badalloc(clxx::create_sub_devices(device const&, device_partition_properties const&));

%include <clxx/device_partition.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
