// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)
/**
 * \defgroup clxx_platform_layer OpenCL platform layer
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
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
