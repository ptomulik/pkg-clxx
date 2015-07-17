// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/mem_fcn.cpp {{{
 * \file clxx/mem_fcn.cpp
 * \brief Implements mem object functions
 */ // }}}
#include <clxx/mem_fcn.hpp>
#include <clxx/functions.hpp>
#include <clxx/util/obj2cl.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    cl_uint num_events_in_wait_list,
                    clxx::event const* event_wait_list,
                    clxx::event* event)
{
  clxx::event tmp;
  enqueue_read_buffer(command_queue.chk_get(),
                      buffer.chk_get(),
                      static_cast<cl_bool>(blocking_read),
                      offset,
                      size,
                      ptr,
                      num_events_in_wait_list,
                      obj2cl(event_wait_list),
                      event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::events const& event_wait_list,
                    clxx::event* event)
{
  clxx::event tmp;
  enqueue_read_buffer(command_queue.chk_get(),
                      buffer.chk_get(),
                      static_cast<cl_bool>(blocking_read),
                      offset,
                      size,
                      ptr,
                      static_cast<cl_uint>(event_wait_list.size()),
                      obj2cl(event_wait_list),
                      event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::event* event)
{
  clxx::event tmp;
  enqueue_read_buffer(command_queue.chk_get(),
                      buffer.chk_get(),
                      static_cast<cl_bool>(blocking_read),
                      offset,
                      size,
                      ptr,
                      0,
                      nullptr,
                      event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     cl_uint num_events_in_wait_list,
                     clxx::event const* event_wait_list,
                     clxx::event* event)
{
  clxx::event tmp;
  enqueue_write_buffer(command_queue.chk_get(),
                       buffer.chk_get(),
                       static_cast<cl_bool>(blocking_write),
                       offset,
                       size,
                       ptr,
                       num_events_in_wait_list,
                       obj2cl(event_wait_list),
                       event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::events const& event_wait_list,
                     clxx::event* event)
{
  clxx::event tmp;
  enqueue_write_buffer(command_queue.chk_get(),
                       buffer.chk_get(),
                       static_cast<cl_bool>(blocking_write),
                       offset,
                       size,
                       ptr,
                       static_cast<cl_uint>(event_wait_list.size()),
                       obj2cl(event_wait_list),
                       event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::event* event)
{
  clxx::event tmp;
  enqueue_write_buffer(command_queue.chk_get(),
                       buffer.chk_get(),
                       static_cast<cl_bool>(blocking_write),
                       offset,
                       size,
                       ptr,
                       0,
                       nullptr,
                       event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    cl_uint num_events_in_wait_list,
                    clxx::event const* event_wait_list,
                    clxx::event* event)
{
  clxx::event tmp;
  enqueue_copy_buffer(command_queue.chk_get(),
                      src_buffer.chk_get(),
                      dst_buffer.chk_get(),
                      src_offset,
                      dst_offset,
                      size,
                      num_events_in_wait_list,
                      obj2cl(event_wait_list),
                      event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::events const& event_wait_list,
                    clxx::event* event)
{
  clxx::event tmp;
  enqueue_copy_buffer(command_queue.chk_get(),
                      src_buffer.chk_get(),
                      dst_buffer.chk_get(),
                      src_offset,
                      dst_offset,
                      size,
                      static_cast<cl_uint>(event_wait_list.size()),
                      obj2cl(event_wait_list),
                      event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::event* event)
{
  clxx::event tmp;
  enqueue_copy_buffer(command_queue.chk_get(),
                      src_buffer.chk_get(),
                      dst_buffer.chk_get(),
                      src_offset,
                      dst_offset,
                      size,
                      0,
                      nullptr,
                      event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   cl_uint num_events_in_wait_list,
                   clxx::event const* event_wait_list,
                   clxx::event* event)
{
  clxx::event tmp;
  void* result = enqueue_map_buffer(command_queue.chk_get(),
                                    buffer.chk_get(),
                                    static_cast<cl_bool>(blocking_map),
                                    map_flags,
                                    offset,
                                    size,
                                    num_events_in_wait_list,
                                    obj2cl(event_wait_list),
                                    event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
  return result;
}
/* ------------------------------------------------------------------------ */
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::events const& event_wait_list,
                   clxx::event* event)
{
  clxx::event tmp;
  void* result = enqueue_map_buffer(command_queue.chk_get(),
                                    buffer.chk_get(),
                                    static_cast<cl_bool>(blocking_map),
                                    map_flags,
                                    offset,
                                    size,
                                    static_cast<cl_uint>(event_wait_list.size()),
                                    obj2cl(event_wait_list),
                                    event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
  return result;
}
/* ------------------------------------------------------------------------ */
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::event* event)
{
  clxx::event tmp;
  void* result = enqueue_map_buffer(command_queue.chk_get(),
                                    buffer.chk_get(),
                                    static_cast<cl_bool>(blocking_map),
                                    map_flags,
                                    offset,
                                    size,
                                    0,
                                    nullptr,
                                    event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
  return result;
}
/* ------------------------------------------------------------------------ */
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         cl_uint num_events_in_wait_list,
                         clxx::event const* event_wait_list,
                         clxx::event* event)
{
  clxx::event tmp;
  enqueue_unmap_mem_object(command_queue.chk_get(),
                           memobj.chk_get(),
                           mapped_ptr,
                           num_events_in_wait_list,
                           obj2cl(event_wait_list),
                           event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::events const& event_wait_list,
                         clxx::event* event)
{
  clxx::event tmp;
  enqueue_unmap_mem_object(command_queue.chk_get(),
                           memobj.chk_get(),
                           mapped_ptr,
                           static_cast<cl_uint>(event_wait_list.size()),
                           obj2cl(event_wait_list),
                           event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::event* event)
{
  clxx::event tmp;
  enqueue_unmap_mem_object(command_queue.chk_get(),
                           memobj.chk_get(),
                           mapped_ptr,
                           0,
                           nullptr,
                           event ? obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintains reference count in *event
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
