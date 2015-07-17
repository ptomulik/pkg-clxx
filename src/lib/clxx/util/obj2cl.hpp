// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/obj2cl.hpp

/** // doc: clxx/util/obj2cl.hpp {{{
 * \file clxx/util/obj2cl.hpp
 * \brief Convert clxx objects to corresponding OpenCL objects
 */ // }}}
#ifndef CLXX_OBJ2CL_HPP_INCLUDED
#define CLXX_OBJ2CL_HPP_INCLUDED

#include <clxx/command_queue_fwd.hpp>
#include <clxx/context_fwd.hpp>
#include <clxx/device_fwd.hpp>
#include <clxx/event_fwd.hpp>
#include <clxx/kernel_fwd.hpp>
#include <clxx/mem_fwd.hpp>
#include <clxx/platform_fwd.hpp>
#include <clxx/program_fwd.hpp>
#include <clxx/cl/cl.h>
#include <vector>

namespace clxx {
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_command_queue const*
obj2cl(clxx::command_queue const* command_queue)
{
  return reinterpret_cast<cl_command_queue const*>(command_queue);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_command_queue*
obj2cl(clxx::command_queue* command_queue)
{
  return reinterpret_cast<cl_command_queue*>(command_queue);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_context const*
obj2cl(clxx::context const* context)
{
  return reinterpret_cast<cl_context const*>(context);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_context*
obj2cl(clxx::context* context)
{
  return reinterpret_cast<cl_context*>(context);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_device_id const*
obj2cl(clxx::device const* device)
{
  return reinterpret_cast<cl_device_id const*>(device);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_device_id*
obj2cl(clxx::device* device)
{
  return reinterpret_cast<cl_device_id*>(device);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_event const*
obj2cl(clxx::event const* event)
{
  return reinterpret_cast<cl_event const*>(event);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_event*
obj2cl(clxx::event* event)
{
  return reinterpret_cast<cl_event*>(event);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_kernel const*
obj2cl(clxx::kernel const* kernel)
{
  return reinterpret_cast<cl_kernel const*>(kernel);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_kernel*
obj2cl(clxx::kernel* kernel)
{
  return reinterpret_cast<cl_kernel*>(kernel);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_mem const*
obj2cl(clxx::mem const* mem)
{
  return reinterpret_cast<cl_mem const*>(mem);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_mem*
obj2cl(clxx::mem* mem)
{
  return reinterpret_cast<cl_mem*>(mem);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_platform_id const*
obj2cl(clxx::platform const* platform)
{
  return reinterpret_cast<cl_platform_id const*>(platform);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_platform_id*
obj2cl(clxx::platform* platform)
{
  return reinterpret_cast<cl_platform_id*>(platform);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_program const*
obj2cl(clxx::program const* program)
{
  return reinterpret_cast<cl_program const*>(program);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
inline cl_program*
obj2cl(clxx::program* program)
{
  return reinterpret_cast<cl_program*>(program);
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T> const& v)
  -> decltype(obj2cl(v.data()))
{
  return obj2cl(v.data());
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T>& v)
  -> decltype(obj2cl(v.data()))
{
  return obj2cl(v.data());
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T> const* v)
  -> decltype(obj2cl(v->data()))
{
  return v ? obj2cl(v->data()) : nullptr;
}
/** // doc: obj2cl {{{
 * \todo Write documentation
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T>* v)
  -> decltype(obj2cl(v->data()))
{
  return v ? obj2cl(v->data()) : nullptr;
}
} // end namespace clxx

#endif /* CLXX_OBJ2CL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
