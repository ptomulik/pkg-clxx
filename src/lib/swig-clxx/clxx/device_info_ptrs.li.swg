// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/device_info_ptrs.li.swg {{{
 * \file clxx/device_info_ptrs.li.swg
 * \todo Write documentation
 */ // }}}
%import <clxx/swig_config.swg>

%{
#include <clxx/device_info_ptrs.hpp>
%}

%include <clxx/device_info_ptr.swg>
%include <std_vector.i>
%template(device_info_ptrs) std::vector<clxx::device_info_ptr>;
%template(const_device_info_ptrs) std::vector<clxx::const_device_info_ptr>;
%include <clxx/device_info_ptrs.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
