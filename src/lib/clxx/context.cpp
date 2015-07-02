// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/context.cpp {{{
 * \file clxx/context.cpp
 * \brief Implements the \ref clxx::context "context" class
 */ // }}}
#include <clxx/context.hpp>
#include <clxx/functions.hpp>
#include <clxx/clobj_impl.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
// Instantiate the base class
template class clobj<cl_context>;
static_assert(
    sizeof(clobj<cl_context>) == sizeof(cl_context),
    "sizeof(clobj<cl_context>) differs from sizeof(cl_context)"
);
/* ------------------------------------------------------------------------ */
context::
context(context_properties const& props, devices const& devs,
        void(*pfn_notify)(const char* errinfo, const void* private_info,
                          size_t cb, void* user_data),
        void* user_data)
  : Base((cl_context)NULL) // because it's read by _set_handle()
{
  const size_t props_n = context_properties_array_size(props);
  std::vector<cl_context_properties> props_v(props_n);
  context_properties_fill_array(props, &props_v.front(), props_n);
  const size_t devs_n = devs.size();
  std::vector<cl_device_id> dev_ids(devs_n);
  for(size_t i = 0; i < devs_n; dev_ids[i] = devs[i].handle(), ++i) { }
  cl_context handle = create_context(&props_v.front(), devs_n, &dev_ids.front(),
                                      pfn_notify, user_data);
  this->_set_handle(handle, false, false);
}
/* ------------------------------------------------------------------------ */
context::
context(const context_properties& props,
        device_type_t dev_type,
        void(*pfn_notify)(const char* errinfo, const void* private_info,
                          size_t cb, void* user_data),
        void* user_data)
  : Base((cl_context)NULL) // because it's read by _set_handle()
{
  const size_t props_n = context_properties_array_size(props);
  std::vector<cl_context_properties> props_v(props_n);
  context_properties_fill_array(props, &props_v.front(), props_n);
  cl_context handle = create_context_from_type(&props_v.front(), dev_type,
                                               pfn_notify, user_data);
  this->_set_handle(handle, false, false);
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
  auto devs(_get_vec_info<cl_device_id>(*this, context_info_t::devices));
  return devices(devs.begin(), devs.end());
}
/* ------------------------------------------------------------------------ */
context_properties context::
get_properties() const
{
  auto cl_props(_get_vec_info<cl_context_properties>(*this, context_info_t::properties));
  context_properties props;
  context_properties_parse_array(props, &cl_props.front());
  return props;
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
