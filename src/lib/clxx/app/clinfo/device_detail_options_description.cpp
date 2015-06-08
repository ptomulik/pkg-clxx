// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/device_detail_options_description.cpp

/** // doc: clxx/app/clinfo/device_detail_options_description.cpp {{{
 * \file clxx/app/clinfo/device_detail_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/app/clinfo/device_detail_options_description.hpp>
#include <clxx/app/options/option_value.hpp>
#include <vector>
#include <string>

namespace clxx { namespace app { namespace clinfo {

device_detail_options_description::
device_detail_options_description( unsigned line_length
                                 , unsigned min_description_length)
  : clxx::app::options::options_description("Device Detail Options"
                                            , line_length
                                            , min_description_length)
{
  this->_init_options_description();
}

device_detail_options_description::
device_detail_options_description( const std::string & caption
                                 , unsigned line_length
                                 , unsigned min_description_length )
  : clxx::app::options::options_description( caption, line_length
                                            , min_description_length)
{
  this->_init_options_description();
}

device_detail_options_description::
~device_detail_options_description()
{
}

void device_detail_options_description::
_init_options_description()
{
  using clxx::app::options::value;
  using std::vector;
  using std::string;
  this->add_options()
    ("device-id"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for device id")
    // device-info
    ("device-type"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for device type")
    ("vendor-id"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for device vendor-id")

    // compute-unit-info {{{
    ("max-compute-units"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-compute-units")
    ("max-work-item-dimensions"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-work-item-dimensions")
    ("max-work-item-sizes"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-work-item-sizes")
    ("max-work-group-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-work-group-size")
    // vector-width-info {{{
    ("preferred-vector-width-char"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-vector-width-char")
    ("preferred-vector-width-short"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-vector-width-short")
    ("preferred-vector-width-int"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-vector-width-int")
    ("preferred-vector-width-long"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-vector-width-long")
    ("preferred-vector-width-float"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-vector-width-float")
    ("preferred-vector-width-double"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-vector-width-double")
    ("preferred-vector-width-half"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-vector-width-half")
    ("native-vector-width-char"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for native-vector-width-char")
    ("native-vector-width-short"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for native-vector-width-short")
    ("native-vector-width-int"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for native-vector-width-int")
    ("native-vector-width-long"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for native-vector-width-long")
    ("native-vector-width-float"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for native-vector-width-float")
    ("native-vector-width-double"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for native-vector-width-double")
    ("native-vector-width-half"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for native-vector-width-half")
    // }}}
    ("max-clock-frequency"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-clock-frequency")
    ("address-bits"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for address-bits")
    // }}}

    ("max-mem-alloc-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-mem-alloc-size")

    // image-support-info {{{
    ("image-support"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image-support")
    ("max-read-image-args"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-read-image-args")
    ("max-write-image-args"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-write-image-args")
    ("image2d-max-width"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image2d-max-width")
    ("image2d-max-height"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image2d-max-height")
    ("image3d-max-width"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image3d-max-width")
    ("image3d-max-height"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image3d-max-height")
    ("image3d-max-depth"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image3d-max-depth")
    ("image-max-buffer-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image-max-buffer-size")
    ("image-max-array-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image-max-array-size")
    ("image-pitch-alignment"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image-pitch-alignment")
    ("image-base-address-alignment"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for image-base-address-alignment")
    ("max-samplers"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-samplers")
    // }}}

    ("max-parameter-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-parameter-size")
    ("mem-base-addr-align"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for mem-base-addr-align")
    ("min-data-type-align-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for min-data-type-align-size")
    ("single-fp-config"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for single-fp-config")
    ("double-fp-config"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for double-fp-config")

    // global-mem-info {{{
    ("global-mem-cache-type"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for global-mem-cache-type")
    ("global-mem-cacheline-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for global-mem-cacheline-size")
    ("global-mem-cache-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for global-mem-cache-size")
    ("global-mem-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for global-mem-size")
    // }}}

    ("max-constant-buffer-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-constant-buffer-size")
    ("max-constant-args"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for max-constant-args")

    ("local-mem-type"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for local-mem-type")
    ("local-mem-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for local-mem-size")
    ("error-correction-support"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for error-correction-support")

    ("host-unified-memory"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for host-unified-memory")

    ("profiling-timer-resolution"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for profiling-timer-resolution")

    ("endian-little"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for endian-little")

    ("available"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for availability")

    ("compiler-available"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for compiler-availability")

    ("linker-available"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for linker-availability")

    ("execution-capabilities"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for execution-capabilities")

    ("queue-properties"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for queue-properties")

    ("built-in-kernels"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for built-in-kernels")

    ("platform-id"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for platform-id")

    // device-generic-info {{{
    ("name"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for name")
    ("vendor"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for vendor")
    ("driver-version"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for driver-version")
    ("profile"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for profile")
    ("device-version"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for version")
    ("opencl-c-version"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for opencl-c-version")
    ("extensions"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for extensions")
    ("preferred-interop-user-sync"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for preferred-interop-user-sync")
    ("printf-buffer-size"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for printf-buffer-size")
    ("parent-device"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for parent-device")
    ("partition-max-sub-devices"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for partition-max-sub-devices")
    ("partition-properties"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for partition-properties")
    ("partition-affinity-domain"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for partition-affinity-domain")
    ("partition-type"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for partition-type")
    ("reference-count"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    ,"query for reference-count")
    // }}}
  ;
}

} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
