// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/**
 * \mainpage Clxx - c++11 library for OpenCL programmers
 *
 * Clxx is a C++ library which exposes OpenCL's functionality in an
 * object-oriented way. Its goal is to simplify usage of the OpenCL functions
 * by providing type-safe and easy to use interface.
 *
 * Clxx is not just a set of bare wrappers around OpenCL calls. In addition to
 * several objects and functions provided for accessing the OpenCL
 * functionality, it also implements additional utilities such as specialized
 * I/O functions, serialization, and swig-based wrappers to access %clxx from
 * scripting languages (python).
 *
 * To have a first impression, let us present a simple clxx-based
 * implementation of the well-known program called **clinfo** (see example
 * \ref platform4.cpp):
 *
 * \snippet platform4.cpp Program
 *
 * The above program enumerates all OpenCL platforms/devices available on a
 * host running the program including their properties. Using standard OpenCL
 * API (in C language) such program usually involves few screens of code.
 *
 * In the following paragraphs we'll briefly present basic features of the
 * %clxx library.
 *
 * \par Enums instead of OpenCL constants
 *
 * As an OpenCL programmer you've probably noticed that most of the OpenCL's
 * features, queries, error codes, etc. are identified by numeric constants
 * (the <tt>CL_...</tt> constants). In %clxx we have replaced these constants
 * with C++11 enum classes. For each specific set of constants (e.g. error
 * codes) we provide a separate enum class with appropriate set of values. All
 * these enums are defined in the header clxx/types.hpp. For example, status
 * codes (including error codes) are covered by clxx::status_t enum class.
 *
 * This classification is a first step towards type safety. In addition, it
 * also allows for specialized functions operating on these identifiers, such
 * as I/O operators or serialization, for example:
 *
 * \code
 *  std::ostream& operator<< (std::ostream& os, clxx::status_t x);
 *  std::ostream& operator<< (std::ostream& os, clxx::platform_info_t x);
 *  ...
 * \endcode
 *
 * \par Exceptions instead of error codes
 *
 * Clxx defines extensive (and extensible) hierarchy of exception classes to
 * represent errors occurring inside calls to %clxx functions/methods. As a
 * %clxx programmer, you should get familiar with the exception hierarchy and
 * forget checking OpenCL return codes. See \ref clxx_exceptions for details.
 *
 * \par Proxy objects for OpenCL resources
 *
 * OpenCL API uses identifiers to represent certain OpenCL resources such as
 * platforms, devices, contexts, etc.. OpenCL functions are then used to
 * access these resources. Clxx encapsulates these identifiers with C++
 * objects, such that the programmers mostly uses object's interface instead
 * of raw OpenCL calls. For example, the clxx::platform class wraps the \c
 * cl_platform_id identifier and implements methods which provide same
 * functionality as the \c clGetPlatformInfo(). A short code snippet
 * illustrates this interface:
 *
 * \code
 *  clxx::platform const p;
 *  // ...
 *  std::cout << "  Id ........ : " << p.get() << std::endl;
 *  std::cout << "  Name ...... : " << p.get_name() << std::endl;
 *  std::cout << "  Vendor .... : " << p.get_vendor() << std::endl;
 *  std::cout << "  Version ... : " << p.get_version() << std::endl;
 * \endcode
 *
 * \par I/O functions
 *
 * %Clxx implements several specialized functions to stream-out %clxx objects
 * or enums in a human-readable form. This may be used for diagnostics,
 * debugging or to implement user interfaces. The detailed list of the I/O
 * functions may be found in module \ref clxx_io. With the I/O module, you may
 * easily dump object internals or print %clxx error codes such as:
 *
 * \snippet io1.cpp OutputStatusT
 *
 * \par Serialization
 *
 * Some of the %clxx objects are serializable. These objects may be saved to a
 * file or a stream and reconstructed later. We use
 * <a href="http://boost.org/doc/libs/release/libs/serialization/">
 * boost.serialization</a> as a serialization engine. The %clxx provides
 * out-of-box support for \c text (\c text_iarchive/\c text_oarchive) , \c xml
 * (\c xml_iarchive/\c xml_oarchive), and \c binary (\c binary_iarchive/\c
 * binary_oarchive) boost archives. More details may be found in module
 * \ref clxx_s11n.
 *
 * \par SWIG-based bindings
 *
 * \todo Write this paragraph.
 *
 * \par Unit tests
 *
 * \todo Write this paragraph.
 *
 */
