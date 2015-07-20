// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/clobj_impl.hpp

/** // doc: clxx/cl/clobj_impl.hpp {{{
 * \file clxx/cl/clobj_impl.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_CLOBJ_IMPL_HPP_INCLUDED
#define CLXX_CL_CLOBJ_IMPL_HPP_INCLUDED

#include <clxx/cl/clobj.hpp>
#include <clxx/cl/clobj_fcn.hpp>
#include <vector>
#include <string>
#include <memory>

namespace clxx {
/** \cond SHOW_IGNORED_COMPOUNDS */
/* ----------------------------------------------------------------------- */
template< typename Handle > std::string
_get_str_info(clobj<Handle> const& obj, typename clobj<Handle>::info_t name)
{
  size_t size;
  obj.get_info(name, 0ul, nullptr, &size);

  std::unique_ptr<char[]> str(new char[size]);
  obj.get_info(name, size, str.get(), nullptr);
  return std::string(str.get());
}

/* ----------------------------------------------------------------------- */
template<typename T, typename Handle> T
_get_pod_info(clobj<Handle> const& obj, typename clobj<Handle>::info_t name)
{
  T value;
  obj.get_info(name, sizeof(value), &value, nullptr);
  return value;
}

/* ----------------------------------------------------------------------- */
template<typename T, typename Handle> std::vector<T>
_get_vec_info(clobj<Handle> const& obj, typename clobj<Handle>::info_t name)
{
  size_t size;
  obj.get_info(name, 0ul, nullptr, &size);
  std::vector<T> values(size/sizeof(T));
  obj.get_info(name, values.size() * sizeof(T), &values.front(), nullptr);
  return values;
}
/** \endcond */
} // end namespace clxx

namespace clxx {
/* ------------------------------------------------------------------------ */
template< typename Handle >
void clobj<Handle>::
_set_handle(handle_t handle, bool retain_new, bool release_old)
{
  if(handle != this->_handle) // Avoid unintended deletion by release_cl_object()
    {
      if(release_old && this->_handle)
        {
          _release(this->_handle);
        }
      this->_handle = handle;
      if(retain_new && this->_handle)
        {
          _retain(this->_handle);
        }
    }
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
void clobj<Handle>::
_retain(handle_t handle)
{
  retain_cl_object(handle);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
void clobj<Handle>::
_release(handle_t handle)
{
  release_cl_object(handle);
}
/** \cond DOXYGEN_SHOW_TEMPLATE_SPECIALIZATIONS */
/* ----------------------------------------------------------------------- */
template<>
inline void clobj<cl_device_id>::
_retain(cl_device_id)
{
  // NOTE: I've fought a while with a SEGFAULT originating from 1.1 NVIDIA
  //       driver. I had a 2.0 OpenCL header and 1.1 NVIDIA OpenCL driver
  //       (also 1.1 GPU) where the clRetainDevice was not implemented.
  //       Finally decided to ignore the reference count management for
  //       device class. This needs to be fixed at some point.
  // 
  // NOTE: I could eventually check if this device is a subdevice (with
  //       get_device_info()) and maintain the reference count conditionally,
  //       but this would introduce clGetDeviceInfo mock into the code of
  //       _retain() so that writting unit-tests would become unbearable.
}
/* ----------------------------------------------------------------------- */
template<>
inline void clobj<cl_device_id>::
_release(cl_device_id)
{
  // NOTE: I've fought a while with a SEGFAULT originating from 1.1 NVIDIA
  //       driver. I had a 2.0 OpenCL header and 1.1 NVIDIA OpenCL driver
  //       (also 1.1 GPU) where the clReleaseDevice was not implemented.
  //       Finally decided to ignore the reference count management for
  //       device class. This needs to be fixed at some point.
  // 
  // NOTE: I could eventually check if this device is a subdevice (with
  //       get_device_info()) and maintain the reference count conditionally
  //       but this would introduce clGetDeviceInfo mock into the code of
  //       _release() so that writting unit-tests would become unbearable.
}
/* ----------------------------------------------------------------------- */
template<>
inline void clobj<cl_platform_id>::
_retain(cl_platform_id)
{
}
/* ----------------------------------------------------------------------- */
template<>
inline void clobj<cl_platform_id>::
_release(cl_platform_id)
{
}
/** \endcond */
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
clobj() noexcept
  :_handle((handle_t)NULL)
{
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
clobj(handle_t h)
  :_handle((handle_t)NULL) // because it's read by _set_handle
{
  this->_set_handle(h, true, false);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
clobj(clobj const& other)
  :_handle((handle_t)NULL) // because it's read by _set_handle
{
  this->_set_handle(other.get(), true, false);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
~clobj()
{
  if(this->is_initialized())
    {
      try { this->_set_handle((handle_t)NULL, false, true); }
      catch(clerror_no<invalid_cl_object_errcode<Handle>::value> const&) { }
    }
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
is_initialized() const noexcept
{
  return this->get() != (handle_t)NULL;
}
/* ----------------------------------------------------------------------- */
template< typename Handle>
Handle clobj<Handle>::
get() const noexcept
{
  return this->_handle;
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
Handle clobj<Handle>::
chk_get() const
{
  if(!this->is_initialized())
    throw typename uninitialized_cl_object_error<Handle>::type();
  return this->_handle;
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
void clobj<Handle>::
get_info(info_t name, size_t value_size, void* value, size_t* value_size_ret) const
{
  get_cl_object_info(this->chk_get(), name, value_size, value, value_size_ret);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
cl_uint clobj<Handle>::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, info_t::reference_count);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
void clobj<Handle>::
assign(clobj const& rhs)
{
  if(&rhs != this)
    this->_set_handle(rhs.get(), true, true);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>& clobj<Handle>::
operator=(clobj const& rhs)
{ this->assign(rhs); return *this; }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator == (clobj const& rhs) const noexcept
{ return this->get() == rhs.get(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator != (clobj const& rhs) const noexcept
{ return this->get() != rhs.get(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator < (clobj const& rhs) const noexcept
{ return this->get() < rhs.get(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator > (clobj const& rhs) const noexcept
{ return this->get() > rhs.get(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator <= (clobj const& rhs) const noexcept
{ return this->get() <= rhs.get(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator >= (clobj const& rhs) const noexcept
{ return this->get() >= rhs.get(); }
/* ----------------------------------------------------------------------- */
} // end namespace clxx

#endif /* CLXX_CL_CLOBJ_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
