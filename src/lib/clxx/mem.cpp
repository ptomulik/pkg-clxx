// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/mem.cpp {{{
 * \file clxx/mem.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/mem.hpp>
#include <clxx/context.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(mem const& p, mem_info_t name)
{
  T value;
  p.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ----------------------------------------------------------------------- */
void mem::
_set_id(cl_mem p, bool retain_new, bool release_old)
{
  if(p != this->_id) // Avoid unintended deletion by clReleaseEvent()
    {
      if(release_old && this->is_initialized())
        {
          release_mem_object(this->_id);
        }
      this->_id = p;
      if(retain_new)
        {
          retain_mem_object(this->_id);
        }
    }
}
/* ----------------------------------------------------------------------- */
mem::
mem() noexcept
  :_id((cl_mem)NULL)
{
}
/* ----------------------------------------------------------------------- */
mem::
mem(cl_mem id)
  :_id((cl_mem)NULL) // because it's read by _set_id()
{
  this->_set_id(id, true, false);
}
/* ----------------------------------------------------------------------- */
mem::
mem(mem const& p)
  :_id((cl_mem)NULL) // because it's read by _set_id()
{
  this->_set_id(p.id(), true, false);
}
/* ----------------------------------------------------------------------- */
mem::
mem(context const& ctx, mem_flags_t flags, size_t size, void* host_ptr)
  :_id((cl_mem)NULL) // because it's read by _set_id()
{
  this->_set_id(create_buffer(ctx.get_valid_id(), flags, size, host_ptr), false, false);
}
/* ----------------------------------------------------------------------- */
mem::
~mem()
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(clerror_no<status_t::invalid_event> const&) { }
    }
}
/* ------------------------------------------------------------------------ */
void mem::
get_info(mem_info_t name, size_t value_size, void* value,
         size_t* value_size_ret) const
{
  get_mem_object_info(
      this->get_valid_id(),
      name,
      value_size,
      value,
      value_size_ret
  );
}
/* ----------------------------------------------------------------------- */
cl_mem mem::
get_valid_id() const
{
  if(!this->is_initialized())
    throw uninitialized_mem_error();
  return this->_id;
}
/* ----------------------------------------------------------------------- */
mem_object_type_t mem::
get_type() const
{
  return _get_pod_info<mem_object_type_t>(*this, mem_info_t::type);
}
/* ----------------------------------------------------------------------- */
mem_flags_t mem::
get_flags() const
{
  return _get_pod_info<mem_flags_t>(*this, mem_info_t::flags);
}
/* ----------------------------------------------------------------------- */
size_t mem::
get_size() const
{
  return _get_pod_info<size_t>(*this, mem_info_t::size);
}
/* ----------------------------------------------------------------------- */
void* mem::
get_host_ptr() const
{
  return _get_pod_info<void*>(*this, mem_info_t::host_ptr);
}
/* ----------------------------------------------------------------------- */
cl_uint mem::
get_map_count() const
{
  return _get_pod_info<cl_uint>(*this, mem_info_t::map_count);
}
/* ----------------------------------------------------------------------- */
cl_uint mem::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, mem_info_t::reference_count);
}
/* ----------------------------------------------------------------------- */
context mem::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, mem_info_t::context));
}
/* ----------------------------------------------------------------------- */
mem mem::
get_associated_memobject() const
{
  return mem(_get_pod_info<cl_mem>(*this, mem_info_t::associated_memobject));
}
/* ----------------------------------------------------------------------- */
size_t mem::
get_offset() const
{
  return _get_pod_info<size_t>(*this, mem_info_t::offset);
}
/* ----------------------------------------------------------------------- */
#if CLXX_CL_H_VERSION_2_0
cl_bool mem::
get_uses_svm_pointer() const
{
  return _get_pod_info<cl_bool>(*this, mem_info_t::uses_svm_pointer);
}
#endif
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
