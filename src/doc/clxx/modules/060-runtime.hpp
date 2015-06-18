// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)
/**
 * \defgroup clxx_runtime OpenCL runtime
 *
 * This module documents object-oriented c++11 interface to *OpenCL runtime*
 * described by the OpenCL specification under chapter 5 "The OpenCL
 * Runtime". Most of the functionalities is exposed in object oriented
 * way, some calls are simplified. OpenCL errors are turned-out into %clxx
 * exceptions (see \ref clxx_exceptions). The API defined by this module is
 * type-safe.
 *
 * @{
 */

/**
 * \defgroup clxx_command_queues Command Queues
 *
 * This module documents an object-oriented c++11 interface to *OpenCL command
 * queues*. OpenCL command queues are described by the OpenCL specification as
 * follows.
 *
 * OpenCL objects such as memory, program and kernel objects are created using
 * a context. Operations on these objects are performed using a command-queue.
 * The command-queue can be used to queue a set of operations (referred to as
 * commands) in order. Having multiple command-queues allows applications to
 * queue multiple independent commands without requiring synchronization. This
 * should work as long as these objects are not being shared. Sharing of
 * objects across multiple command-queues will require the application to
 * perform appropriate synchronization.
 */

/**
 * \defgroup clxx_buffer_objects Buffer Objects
 *
 * This module documents an object-oriented c++11 interface to OpenCL buffer
 * objects. OpenCL buffer objects are described by the OpenCL specification as
 * follows.
 *
 * A *buffer* object stores a one-dimensional collection of elements. Element
 * of a *buffer* object can be a scalar data type (such as an \c int, \c
 * float), vector data type, or a user-defined structure.
 */

/**
 * \defgroup clxx_image_objects Image Objects
 *
 * This module documents an object-oriented c++11 interface to OpenCL image
 * objets. OpenCL image objects are described by the OpenCL specification as
 * follows.
 *
 * An *image* object is used to store a one-, two- or three- dimensional
 * texture, frame-buffer or image. The elements of an image object are selected
 * from a list of predefined image formats.  The minimum number of elements in
 * a memory object is one.
 */

/**
 * \defgroup clxx_pipes Pipes
 */

/**
 * \defgroup clxx_sampler_objects Sampler Objects
 */

/**
 * \defgroup clxx_program_objects Program Objects
 */

/**
 * \defgroup clxx_kernel_objects Kernel Objects
 */

/**
 * \defgroup clxx_executing_kernels Executng Kernel
 */

/**
 * \defgroup clxx_event_objects Event Objects
 */

/**
 * \defgroup clxx_markers_barriers_waiting Markers, Barriers, and Waiting
 */

/**
 * \defgroup clxx_flush_and_finish Flush and Finish
 */

/**
 * \defgroup clxx_svm Shared Virtual Memory
 */

/** @} */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
