// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/mem_fcn.hpp

/** // doc: clxx/mem_fcn.hpp {{{
 * \file clxx/mem_fcn.hpp
 * \brief Declares mem object functions
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
 * \brief Enqueue commands to read from a buffer object to host memory
 *
 * \param command_queue
 *    A valid host command-queue in which the read command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    \ref clxx::context "context".
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_read
 *    Indicates if the read operations are blocking or non-blocking.
 * \param offset
 *    The offset in bytes in the buffer object to read from.
 * \param size
 *    The size in bytes of data being read.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read into.
 * \param num_events_in_wait_list
 *    Number of events in \p event_wait_list. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular read command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_read_buffer().
 */ // }}}
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    cl_uint num_events_in_wait_list,
                    clxx::event const* event_wait_list,
                    clxx::event* event = nullptr);
/** // doc: enqueue_read_buffer() {{{
 * \brief Enqueue commands to read from a buffer object to host memory
 *
 * \param command_queue
 *    A valid host command-queue in which the read command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    \ref clxx::context "context".
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_read
 *    Indicates if the read operations are blocking or non-blocking.
 * \param offset
 *    The offset in bytes in the buffer object to read from.
 * \param size
 *    The size in bytes of data being read.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read into.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular read command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_read_buffer().
 */ // }}}
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::events const& event_wait_list,
                    clxx::event* event = nullptr);
/** // doc: enqueue_read_buffer() {{{
 * \brief Enqueue commands to read from a buffer object to host memory
 *
 * \param command_queue
 *    A valid host command-queue in which the read command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    \ref clxx::context "context".
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_read
 *    Indicates if the read operations are blocking or non-blocking.
 * \param offset
 *    The offset in bytes in the buffer object to read from.
 * \param size
 *    The size in bytes of data being read.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read into.
 * \param event
 *    Returns an event object that identifies this particular read command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_read_buffer().
 */ // }}}
void
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::event* event = nullptr);
/** // doc: enqueue_write_buffer() {{{
 * \brief Enqueue commands to write to a buffer object from host memory
 *
 * \param command_queue
 *    A valid host command-queue in which the write command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    \ref clxx::context "context".
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_write
 *    Indicates if the write operations are blocking or non-blocking.
 * \param offset
 *    The offset in bytes in the buffer object to write to.
 * \param size
 *    The size in bytes of data being written.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read from.
 * \param num_events_in_wait_list
 *    Number of events in \p event_wait_list. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_write_buffer().
 */ // }}}
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     cl_uint num_events_in_wait_list,
                     clxx::event const* event_wait_list,
                     clxx::event* event = nullptr);
/** // doc: enqueue_write_buffer() {{{
 * \brief Enqueue commands to write to a buffer object from host memory
 *
 * \param command_queue
 *    A valid host command-queue in which the write command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    \ref clxx::context "context".
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_write
 *    Indicates if the write operations are blocking or non-blocking.
 * \param offset
 *    The offset in bytes in the buffer object to write to.
 * \param size
 *    The size in bytes of data being written.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read from.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_write_buffer().
 */ // }}}
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::events const& event_wait_list,
                     clxx::event* event = nullptr);
/** // doc: enqueue_write_buffer() {{{
 * \brief Enqueue commands to write to a buffer object from host memory
 *
 * \param command_queue
 *    A valid host command-queue in which the write command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    \ref clxx::context "context".
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_write
 *    Indicates if the write operations are blocking or non-blocking.
 * \param offset
 *    The offset in bytes in the buffer object to write to.
 * \param size
 *    The size in bytes of data being written.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read from.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_write_buffer().
 */ // }}}
void
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::event* event = nullptr);
/** // doc: enqueue_copy_buffer() {{{
 * \brief Enqueues a command to copy from one buffer object to another
 *
 * \param command_queue
 *    The host command-queue in which the copy command will be queued. The
 *    OpenCL context associated with \p command_queue, \p src_buffer, and
 *    \p dst_buffer must be the same
 * \param src_buffer
 *    Source buffer.
 * \param dst_buffer
 *    Destination buffer.
 * \param src_offset
 *    The offset where to begin copying data from \p src_buffer.
 * \param dst_offset
 *    The offset where to begin copying data into \p dst_buffer.
 * \param size
 *    Refers to the size in bytes to copy.
 * \param num_events_in_wait_list
 *    Number of events in \p event_wait_list. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p src_buffer or \p dst_buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_copy_buffer().
 */ // }}}
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    cl_uint num_events_in_wait_list,
                    clxx::event const* event_wait_list,
                    clxx::event* event = nullptr);
/** // doc: enqueue_copy_buffer() {{{
 * \brief Enqueues a command to copy from one buffer object to another
 *
 * \param command_queue
 *    The host command-queue in which the copy command will be queued. The
 *    OpenCL context associated with \p command_queue, \p src_buffer, and
 *    \p dst_buffer must be the same
 * \param src_buffer
 *    Source buffer.
 * \param dst_buffer
 *    Destination buffer.
 * \param src_offset
 *    The offset where to begin copying data from \p src_buffer.
 * \param dst_offset
 *    The offset where to begin copying data into \p dst_buffer.
 * \param size
 *    Refers to the size in bytes to copy.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p src_buffer or \p dst_buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_copy_buffer().
 */ // }}}
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::events const& event_wait_list,
                    clxx::event* event = nullptr);
/** // doc: enqueue_copy_buffer() {{{
 * \brief Enqueues a command to copy from one buffer object to another
 *
 * \param command_queue
 *    The host command-queue in which the copy command will be queued. The
 *    OpenCL context associated with \p command_queue, \p src_buffer, and
 *    \p dst_buffer must be the same
 * \param src_buffer
 *    Source buffer.
 * \param dst_buffer
 *    Destination buffer.
 * \param src_offset
 *    The offset where to begin copying data from \p src_buffer.
 * \param dst_offset
 *    The offset where to begin copying data into \p dst_buffer.
 * \param size
 *    Refers to the size in bytes to copy.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p src_buffer or \p dst_buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_copy_buffer().
 */ // }}}
void
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::event* event = nullptr);
/** // doc: enqueue_map_buffer() {{{
 * \brief Enqueues a command to map a region of the buffer object given by
 *        \p buffer into the host address space and returns a pointer to this
 *        mapped region
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param buffer
 *    A valid buffer object. The OpenCL context associated with
 *    \p command_queue and \p buffer must be the same
 * \param blocking_map
 *    Indicates if the map operation is blocking or non-blocking.
 * \param map_flags
 *    A bit-field with the mapping options. See the documentation of
 *    #map_flags_t for the list of predefined bit values.
 * \param offset
 *    The offset in bytes of the region in the buffer object that is being
 *    mapped.
 * \param size
 *    The size in bytes of the region in the buffer object that is being
 *    mapped.
 * \param num_events_in_wait_list
 *    Number of events in \p event_wait_list. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \returns A pointer to the mapped memory
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_map_buffer().
 */ // }}}
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   cl_uint num_events_in_wait_list,
                   clxx::event const* event_wait_list,
                   clxx::event* event = nullptr);
/** // doc: enqueue_map_buffer() {{{
 * \brief Enqueues a command to map a region of the buffer object given by
 *        \p buffer into the host address space and returns a pointer to this
 *        mapped region
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param buffer
 *    A valid buffer object. The OpenCL context associated with
 *    \p command_queue and \p buffer must be the same
 * \param blocking_map
 *    Indicates if the map operation is blocking or non-blocking.
 * \param map_flags
 *    A bit-field with the mapping options. See the documentation of
 *    #map_flags_t for the list of predefined bit values.
 * \param offset
 *    The offset in bytes of the region in the buffer object that is being
 *    mapped.
 * \param size
 *    The size in bytes of the region in the buffer object that is being
 *    mapped.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \returns A pointer to the mapped memory
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_map_buffer().
 */ // }}}
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::events const& event_wait_list,
                   clxx::event* event = nullptr);
/** // doc: enqueue_map_buffer() {{{
 * \brief Enqueues a command to map a region of the buffer object given by
 *        \p buffer into the host address space and returns a pointer to this
 *        mapped region
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param buffer
 *    A valid buffer object. The OpenCL context associated with
 *    \p command_queue and \p buffer must be the same
 * \param blocking_map
 *    Indicates if the map operation is blocking or non-blocking.
 * \param map_flags
 *    A bit-field with the mapping options. See the documentation of
 *    #map_flags_t for the list of predefined bit values.
 * \param offset
 *    The offset in bytes of the region in the buffer object that is being
 *    mapped.
 * \param size
 *    The size in bytes of the region in the buffer object that is being
 *    mapped.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \returns A pointer to the mapped memory
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_map_buffer().
 */ // }}}
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::event* event = nullptr);
/** // doc: enqueue_map_buffer() {{{
 * \brief Enqueues a command to unmap a previously mapped region of a memory
 *        object
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param memobj
 *    A valid memory (buffer or image) object. The OpenCL context associated
 *    with \p command_queue and \p memobj must be the same.
 * \param mapped_ptr
 *    The host address returned by a previous call to #enqueue_map_buffer() or
 *    #enqueue_map_image() for \p memobj.
 * \param num_events_in_wait_list
 *    Number of events in \p event_wait_list. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_map_buffer().
 */ // }}}
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         cl_uint num_events_in_wait_list,
                         clxx::event const* event_wait_list,
                         clxx::event* event = nullptr);
/** // doc: enqueue_map_buffer() {{{
 * \brief Enqueues a command to unmap a previously mapped region of a memory
 *        object
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param memobj
 *    A valid memory (buffer or image) object. The OpenCL context associated
 *    with \p command_queue and \p memobj must be the same.
 * \param mapped_ptr
 *    The host address returned by a previous call to #enqueue_map_buffer() or
 *    #enqueue_map_image() for \p memobj.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns. 
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_map_buffer().
 */ // }}}
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::events const& event_wait_list,
                         clxx::event* event = nullptr);
/** // doc: enqueue_map_buffer() {{{
 * \brief Enqueues a command to unmap a previously mapped region of a memory
 *        object
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param memobj
 *    A valid memory (buffer or image) object. The OpenCL context associated
 *    with \p command_queue and \p memobj must be the same.
 * \param mapped_ptr
 *    The host address returned by a previous call to #enqueue_map_buffer() or
 *    #enqueue_map_image() for \p memobj.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete. The \p event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw uninitialized_command_queue_error
 *    When the \p command_queue is uninitialized
 * \throw uninitialized_mem_error
 *    When the \p buffer is uninitialized
 *
 * Also throws exceptions originating from the basic wrapper #enqueue_map_buffer().
 */ // }}}
void
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::event* event = nullptr);
/** @} */
} // end namespace clxx

#endif /* CLXX_MEM_FCN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
