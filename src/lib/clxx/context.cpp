// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/context.cpp {{{
 * \file clxx/context.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/context.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <vector>

namespace clxx {

/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(context const& p, context_info_t name)
{
  T value;
  p.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
template<typename T> static std::vector<T>
_get_vec_info(context const& p, context_info_t name)
{
  size_t size;
  p.get_info(name,0,NULL,&size);
  std::vector<T> values(size/sizeof(T));
  p.get_info(name,values.size()*sizeof(T),&values.front(),NULL);
  return values;
}
/* ------------------------------------------------------------------------ */
void context::
_set_id(cl_context id, bool retain_new, bool release_old)
{
  if(id != this->_id) // Avoid unintended deletion by clReleaseContext()
    {
      if(release_old && this->is_initialized())
        {
          release_context(this->_id);
        }
      this->_id = id;
      if(retain_new)
        {
          retain_context(this->_id);
        }
    }
}
/* ------------------------------------------------------------------------ */
context::
context(cl_context id)
{
  this->_set_id(id, true, false);
}
/* ------------------------------------------------------------------------ */
context::
context(context_properties const& props, devices const& devs,
        void(*pfn_notify)(const char* errinfo, const void* private_info,
                          size_t cb, void* user_data),
        void* user_data)
{
  const size_t props_n = context_properties_array_size(props);
  std::vector<cl_context_properties> props_v(props_n);
  context_properties_fill_array(props, &props_v.front(), props_n);
  const size_t devs_n = devs.size();
  std::vector<cl_device_id> dev_ids(devs_n);
  for(size_t i = 0; i < devs_n; dev_ids[i] = devs[i].id(), ++i) { }
  cl_context id = create_context(&props_v.front(), devs_n, &dev_ids.front(),
                                  pfn_notify, user_data);
  this->_set_id(id, false, false);
}
/* ------------------------------------------------------------------------ */
context::
context(const context_properties& props,
        device_type_t dev_type,
        void(*pfn_notify)(const char* errinfo, const void* private_info,
                          size_t cb, void* user_data),
        void* user_data)
{
  const size_t props_n = context_properties_array_size(props);
  std::vector<cl_context_properties> props_v(props_n);
  context_properties_fill_array(props, &props_v.front(), props_n);
  cl_context id = create_context_from_type(&props_v.front(), dev_type,
                                            pfn_notify, user_data);
  this->_set_id(id, false, false);
}
/* ------------------------------------------------------------------------ */
context::
context(const context& rhs)
{
  this->_set_id(rhs.get_valid_id(), true, false);
}
/* ------------------------------------------------------------------------ */
context::
~context()
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(clerror_no<status_t::invalid_context> const&){ }
    }
}
/* ------------------------------------------------------------------------ */
void context::
get_info(context_info_t name, size_t value_size, void* value,
         size_t* value_size_ret) const
{
  get_context_info(this->get_valid_id(), name, value_size, value, value_size_ret);
}
/* ------------------------------------------------------------------------ */
cl_context context::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_context_error();
  return this->_id;
}
/* ------------------------------------------------------------------------ */
void context::
assign(context const& rhs)
{
  if(&rhs != this)
    this->_set_id(rhs.get_valid_id(), true, true);
}
/* ------------------------------------------------------------------------ */
cl_uint context::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, context_info_t::reference_count);
}
/* ------------------------------------------------------------------------ */
cl_uint context::
get_num_devices() const
{
  return _get_pod_info<cl_uint>(*this, context_info_t::num_devices);
}
/* ------------------------------------------------------------------------ */
devices context::
get_devices() const
{
  typedef cl_device_id T;
  std::vector<T> devs(_get_vec_info<T>(*this, context_info_t::devices));
  return devices(devs.begin(), devs.end());
}
/* ------------------------------------------------------------------------ */
context_properties context::
get_properties() const
{
  typedef cl_context_properties T;
  std::vector<T> cl_props(_get_vec_info<T>(*this, context_info_t::properties));
  context_properties props;
  context_properties_parse_array(props, &cl_props.front());
  return props;
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
