// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** \defgroup clxx_cl libclxx_cl
 * @{ */

/**
 * \defgroup clxx_cl_functions Functional interface to OpenCL
 *
 * \brief Thin wrappers around OpenCL functions
 *
 * The functions documented in this module provide thin wrappers around OpenCL
 * functions. Their purpose is to:
 *   - introduce \ref clxx_exceptions "our exceptions" &mdash; the new
 *     functions throw appropriate \ref clxx_exceptions "exceptions" instead of
 *     returning OpenCL error codes,
 *   - introduce \ref clxx_types "clxx enumerative types" &mdash; whenever
 *     appropriate, the new functions accept strongly typed enums defined in
 *     \ref clxx/common/types.hpp, instead of the OpenCL's \c CL_* constants,
 *   - introduce cxxtest mocks &mdash; this is used internally for unit
 *     testing.
 */

/**
 * \defgroup clxx_platform_layer OpenCL platform layer
 *
 * \brief Object-oriented API to OpenCL platform layer
 *
 * This module documents object-oriented c++11 interface to *OpenCL platform
 * layer* described by the OpenCL specification under chapter 4 "The OpenCL
 * Platform Layer". Most of the functionalities is exposed in object oriented
 * way, some calls are simplified. OpenCL errors are turned-out into %clxx
 * exceptions (see \ref clxx_exceptions). The API defined by this module is
 * type-safe.
 *
 * <h4>Platforms and devices</h4>
 *
 * Interaction with OpenCL platforms and devices in %clxx is handled by the
 * following classes
 *   - clxx::platform,
 *   - clxx::device.
 *
 * There are also collections of platforms and devices provided by
 *   - clxx::platforms,
 *   - clxx::devices.
 *
 * The whole OpenCL platform layer (all locally available OpenCL platforms and
 * devices) is represented by
 *   - clxx::platform_layer
 *
 * object. These classes are accompanied by some free-standing functions
 *   - clxx::get_num_platforms(),
 *   - clxx::get_platforms(),
 *   - clxx::get_num_devices(),
 *   - clxx::get_devices().
 *
 * The clxx::platform object is used to query information from a single OpenCL
 * platform. The clxx::device is used to do the same with an OpenCL device. The
 * clxx::platform and clxx::device objects are lightweight. The only data
 * encapsulated by clxx::platform is a \c cl_platform_id identifier, and the
 * clxx::device encapsulates its \c cl_device_id identifier (both are just
 * pointers).
 *
 * A collection of clxx::platform objects representing locally available OpenCL
 * platforms may be retrieved with clxx::get_platforms(), for example:
 *
 * \code
 *  clxx::platforms ps(clxx::get_platforms());
 * \endcode
 *
 * Similarly, a collection of clxx::device objects representing devices
 * comprising given OpenCL platform may be retrieved with clxx::get_devices(),
 * for example:
 *
 * \code
 *  clxx::devices ds(clxx::get_devices(ps[0]));
 * \endcode
 *
 * <h4>Contexts</h4>
 *
 * OpenCL contexs are supported by the following classes:
 *   - clxx::context,
 *   - clxx::context_property,
 *   - clxx::context_properties,
 *
 * and these helper functions:
 *   - clxx::context_platform(),
 *   - clxx::context_interop_user_sync(),
 *   - clxx::context_gl_context_khr(),
 *   - clxx::context_egl_display_khr(),
 *   - clxx::context_glx_display_khr(),
 *   - clxx::context_wgl_hdc_khr(),
 *   - clxx::context_cgl_sharegroup_khr(),
 *   - clxx::context_adapter_d3d9_khr(),
 *   - clxx::context_adapter_d3d9ex_khr(),
 *   - clxx::context_adapter_dxva_khr(),
 *   - clxx::context_d3d10_device_khr(),
 *   - clxx::context_d3d11_device_khr(),
 *   - clxx::make_context_property(),
 *   - clxx::make_context_properties().
 *
 * The clxx::context is a lightweight object encapsulating only OpenCL context
 * handle (\c cl_context). It provides methods for querying context information
 * such as context reference count or context properties. It also internally
 * maintains reference count for context.
 *
 */

/**
 * \defgroup clxx_runtime OpenCL runtime
 *
 * \brief Object-oriented API to OpenCL runtime
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
 * \sa \ref clxx::command_queue::flush() "command_queue::flush()"
 * \sa \ref clxx::command_queue::finish() "command_queue::finish()"
 */

/**
 * \defgroup clxx_svm Shared Virtual Memory
 */

/** @} */
/** @} */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
