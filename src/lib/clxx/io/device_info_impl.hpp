// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/device_info_impl.hpp

#ifndef CLXX_IO_DEVICE_INFO_IMPL
#define CLXX_IO_DEVICE_INFO_IMPL

/** // doc: clxx/io/device_info_impl.hpp {{{
 * \file clxx/io/device_info_impl.hpp
 * \brief Implements I/O routines for \ref clxx::device_info "device_info" objects
 */ // }}}
#include <clxx/io/device_info.hpp>
#include <clxx/io/autosep.hpp>
#include <clxx/io/types.hpp>

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

// local implementation of << operator for vectors (we have one here)
template<class Ostream, typename T>
static Ostream&
operator << (Ostream& os, std::vector<T> const& v)
{
  typedef typename std::vector<T>::const_iterator iterator;
  iterator cur(v.begin());
  iterator end(v.end());
  clxx::io::autosep_<const char*> as(", ");
  while(cur != end)
    os << as << *cur++;
  return os;
}

template <typename T>
static std::string
to_hex(T const& x)
{
  std::ostringstream oss;
  oss << "0x" << std::hex << x;
  return oss.str();
}

namespace clxx { namespace io {

template <class Ostream> Ostream&
write(Ostream& os, clxx::device_info const& info, int ind)
{
  autosep_<const char*> as("\n");
  std::string pre(ind, ' ');

  if(info.has_id()) {
    os  << as << pre << "Id (within current process) ..: "
        << to_hex(info.id());
  }
  if(info.has_type()) {
    os  << as << pre << "Type .........................: "
        << info.type();
  }
  if(info.has_vendor_id()) {
    os  << as << pre << "Vendor Id ....................: "
        << to_hex(info.vendor_id());
  }
  if(info.has_max_compute_units()) {
    os  << as << pre << "Max Compute Units ............: "
        << info.max_compute_units();
  }
  if(info.has_max_work_item_dimensions()) {
    os  << as << pre << "Max Work Item Dimensions .....: "
        << info.max_work_item_dimensions();
  }
  if(info.has_max_work_item_sizes()) {
    os  << as << pre << "Max Work Item Sizes ..........: "
        << info.max_work_item_sizes();
  }
  if(info.has_max_work_group_size()) {
    os  << as << pre << "Max Work Group Size ..........: "
        << info.max_work_group_size();
  }
  if(info.has_preferred_vector_width_char()) {
    os  << as << pre << "Preferred Vector Width Char ..: "
        << info.preferred_vector_width_char();
  }
  if(info.has_preferred_vector_width_short()) {
    os  << as << pre << "Preferred Vector Width Short .: "
        << info.preferred_vector_width_short();
  }
  if(info.has_preferred_vector_width_int()) {
    os  << as << pre << "Preferred Vector Width Int ...: "
        << info.preferred_vector_width_int();
  }
  if(info.has_preferred_vector_width_long()) {
    os  << as << pre << "Preferred Vector Width Long ..: "
        << info.preferred_vector_width_long();
  }
  if(info.has_preferred_vector_width_float()) {
    os  << as << pre << "Preferred Vector Width Float .: "
        << info.preferred_vector_width_float();
  }
  if(info.has_preferred_vector_width_double()) {
    os  << as << pre << "Preferred Vector Width Double : "
        << info.preferred_vector_width_double();
  }
  if(info.has_preferred_vector_width_half()) {
    os  << as << pre << "Preferred Vector Width Half ..: "
        << info.preferred_vector_width_half();
  }
  if(info.has_native_vector_width_char()) {
    os  << as << pre << "Native Vector Width Char .....: "
        << info.native_vector_width_char();
  }
  if(info.has_native_vector_width_short()) {
    os  << as << pre << "Native Vector Width Short ....: "
        << info.native_vector_width_short();
  }
  if(info.has_native_vector_width_int()) {
    os  << as << pre << "Native Vector Width Int ......: "
        << info.native_vector_width_int();
  }
  if(info.has_native_vector_width_long()) {
    os  << as << pre << "Native Vector Width Long .....: "
        << info.native_vector_width_long();
  }
  if(info.has_native_vector_width_float()) {
    os  << as << pre << "Native Vector Width Float ....: "
        << info.native_vector_width_float();
  }
  if(info.has_native_vector_width_double()) {
    os  << as << pre << "Native Vector Width Double ...: "
        << info.native_vector_width_double();
  }
  if(info.has_native_vector_width_half()) {
    os  << as << pre << "Native Vector Width Half .....: "
        << info.native_vector_width_half();
  }
  if(info.has_max_clock_frequency()) {
    os  << as << pre << "Max Clock Frequency ..........: "
        << info.max_clock_frequency();
  }
  if(info.has_address_bits()) {
    os  << as << pre << "Address Bits .................: "
        << info.address_bits();
  }
  if(info.has_max_mem_alloc_size()) {
    os  << as << pre << "Max Mem Alloc Size ...........: "
        << info.max_mem_alloc_size();
  }
  if(info.has_image_support()) {
    os  << as << pre << "Image Support ................: "
        << info.image_support();
  }
  if(info.has_max_read_image_args()) {
    os  << as << pre << "Max Read Image Args ..........: "
        << info.max_read_image_args();
  }
  if(info.has_max_write_image_args()) {
    os  << as << pre << "Max Write Image Args .........: "
        << info.max_write_image_args();
  }
  if(info.has_image2d_max_width()) {
    os  << as << pre << "Image2d Max Width ............: "
        << info.image2d_max_width();
  }
  if(info.has_image2d_max_height()) {
    os  << as << pre << "Image2d Max Height ...........: "
        << info.image2d_max_height();
  }
  if(info.has_image3d_max_width()) {
    os  << as << pre << "Image3d Max Width ............: "
        << info.image3d_max_width();
  }
  if(info.has_image3d_max_height()) {
    os  << as << pre << "Image3d Max Height ...........: "
        << info.image3d_max_height();
  }
  if(info.has_image3d_max_depth()) {
    os  << as << pre << "Image3d Max Depth ............: "
        << info.image3d_max_depth();
  }
  if(info.has_image_max_buffer_size()) {
    os  << as << pre << "Image Max Buffer Size ........: "
        << info.image_max_buffer_size();
  }
  if(info.has_image_max_array_size()) {
    os  << as << pre << "Image Max Array Size  ........: "
        << info.image_max_array_size();
  }
  if(info.has_max_samplers()) {
    os  << as << pre << "Max Samplers .................: "
        << info.max_samplers();
  }
  if(info.has_max_parameter_size()) {
    os  << as << pre << "Max Parameter Size ...........: "
        << info.max_parameter_size();
  }
  if(info.has_mem_base_addr_align()) {
    os  << as << pre << "Mem Base Addr Align ..........: "
        << info.mem_base_addr_align();
  }
  if(info.has_min_data_type_align_size()) {
    os  << as << pre << "Min Data Type Align Size .....: "
        << info.min_data_type_align_size();
  }
  if(info.has_single_fp_config()) {
    os  << as << pre << "Single Prec. Floating Pt Caps : "
        << info.single_fp_config();
  }
  if(info.has_double_fp_config()) {
    os  << as << pre << "Double Prec. Floating Pt Caps : "
        << info.double_fp_config();
  }
  if(info.has_global_mem_cache_type()) {
    os  << as << pre << "Global Mem Cache Type ........: "
        << info.global_mem_cache_type();
  }
  if(info.has_global_mem_cacheline_size()) {
    os  << as << pre << "Global Mem Cacheline Size ....: "
        << info.global_mem_cacheline_size();
  }
  if(info.has_global_mem_cache_size()) {
    os  << as << pre << "Global Mem Cache Size ........: "
        << info.global_mem_cache_size();
  }
  if(info.has_global_mem_size()) {
    os  << as << pre << "Global Mem Size ..............: "
        << info.global_mem_size();
  }
  if(info.has_max_constant_buffer_size()) {
    os  << as << pre << "Max Constant Buffer Size .....: "
        << info.max_constant_buffer_size();
  }
  if(info.has_max_constant_args()) {
    os  << as << pre << "Max Constant Args ............: "
        << info.max_constant_args();
  }
  if(info.has_local_mem_type()) {
    os  << as << pre << "Local Mem Type ...............: "
        << info.local_mem_type();
  }
  if(info.has_local_mem_size()) {
    os  << as << pre << "Local Mem Size ...............: "
        << info.local_mem_size();
  }
  if(info.has_error_correction_support()) {
    os  << as << pre << "Error Correction Support .....: "
        << info.error_correction_support();
  }
  if(info.has_host_unified_memory()) {
    os  << as << pre << "Host Unified Memory ..........: "
        << info.host_unified_memory();
  }
  if(info.has_profiling_timer_resolution()) {
    os  << as << pre << "Profiling Timer Resolution ...: "
        << info.profiling_timer_resolution();
  }
  if(info.has_endian_little()) {
    os  << as << pre << "Endian Little ................: "
        << info.endian_little();
  }
  if(info.has_available()) {
    os  << as << pre << "Available ....................: "
        << info.available();
  }
  if(info.has_compiler_available()) {
    os  << as << pre << "Compiler Available ...........: "
        << info.compiler_available();
  }
  if(info.has_linker_available()) {
    os  << as << pre << "Linker Available .............: "
        << info.linker_available();
  }
  if(info.has_execution_capabilities()) {
    os  << as << pre << "Execution Capabilities .......: "
        << info.execution_capabilities();
  }
  if(info.has_queue_properties()) {
    os  << as << pre << "Queue Properties .............: "
        << info.queue_properties();
  }
  if(info.has_platform_id()) {
    os  << as << pre << "Platform Id (current process).: "
        << info.platform_id();
  }
  if(info.has_name()) {
    os  << as << pre << "Name .........................: "
        << info.name();
  }
  if(info.has_vendor()) {
    os  << as << pre << "Vendor .......................: "
        << info.vendor();
  }
  if(info.has_driver_version()) {
    os  << as << pre << "Driver Version ...............: "
        << info.driver_version();
  }
  if(info.has_profile()) {
    os  << as << pre << "Profile ......................: "
        << info.profile();
  }
  if(info.has_version()) {
    os  << as << pre << "Version ......................: "
        << info.version();
  }
  if(info.has_opencl_c_version()) {
    os  << as << pre << "Opencl C Version .............: "
        << info.opencl_c_version();
  }
  if(info.has_extensions()) {
    os  << as << pre << "Extensions ...................: "
        << info.extensions();
  }
  if(info.has_built_in_kernels()) {
    os  << as << pre << "Built in Kernels .............: "
        << info.built_in_kernels();
  }
  if(info.has_parent_device_id()) {
    os  << as << pre << "Parent Device ................: "
        << info.parent_device_id();
  }
  if(info.has_partition_max_sub_devices()) {
    os  << as << pre << "Partition Max SubDevices .....: "
        << info.partition_max_sub_devices();
  }
  if(info.has_partition_properties()) {
    os  << as << pre << "Partition Properties .........: "
        << info.partition_properties();
  }
  if(info.has_partition_affinity_domain()) {
    os  << as << pre << "Partition Affinity Domain ....: "
        << info.partition_affinity_domain();
  }
  if(info.has_partition_type()) {
    os  << as << pre << "Partition Type ...............: "
        << info.partition_type();
  }
  if(info.has_reference_count()) {
    os  << as << pre << "Reference Count ..............: "
        << info.reference_count();
  }
  if(info.has_preferred_interop_user_sync()) {
    os  << as << pre << "Preferred Interop User Sync ..: "
        << info.preferred_interop_user_sync();
  }
  if(info.has_printf_buffer_size()) {
    os  << as << pre << "Printf Buffer Size ...........: "
        << info.printf_buffer_size();
  }
  if(info.has_image_pitch_alignment()) {
    os  << as << pre << "Image Pitch Alignment ........: "
        << info.image_pitch_alignment();
  }
  if(info.has_image_base_address_alignment()) {
    os  << as << pre << "Image Base Address Alignment .: "
        << info.image_base_address_alignment();
  }
  return os;
}

template <class Ostream> Ostream&
write(Ostream& os, clxx::device_info const& dev)
{
  return write(os, dev, 0);
}

} } // end namespace clxx::io

#endif /* CLXX_IO_DEVICE_INFO_IMPL */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
