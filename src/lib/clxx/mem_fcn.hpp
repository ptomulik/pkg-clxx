// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/mem_fcn.hpp

/** // doc: clxx/mem_fcn.hpp {{{
 * \file clxx/mem_fcn.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_MEM_FCN_HPP_INCLUDED
#define CLXX_MEM_FCN_HPP_INCLUDED


#include <clxx/mem.hpp>
#include <clxx/command_queue.hpp>
#include <clxx/events.hpp>

namespace clxx {
/** \addtogroup clxx_buffer_objects
 * @{ */
/** // doc: enqueue_read_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::events const& event_wait_list,
                    clxx::event& event);
/** // doc: enqueue_read_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::event& event);
/** // doc: enqueue_read_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::events const& event_wait_list);
/** // doc: enqueue_read_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr);
/** // doc: enqueue_write_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::events const& event_wait_list,
                     clxx::event& event);
/** // doc: enqueue_write_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::event& event);
/** // doc: enqueue_write_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::events const& event_wait_list);
/** // doc: enqueue_write_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr);
/** // doc: enqueue_copy_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::events const& event_wait_list,
                    clxx::event& event);
/** // doc: enqueue_copy_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::event& event);
/** // doc: enqueue_copy_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::events const& event_wait_list);
/** // doc: enqueue_copy_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::events const& event_wait_list,
                   clxx::event& event);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::event& event);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::events const& event_wait_list);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::events const& event_wait_list,
                         clxx::event& event);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::event& event);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::events const& event_wait_list);
/** // doc: enqueue_map_buffer() {{{
 * \todo Write documentation
 */ // }}}
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr);
/** @} */
} // end namespace clxx

#endif /* CLXX_MEM_FCN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
