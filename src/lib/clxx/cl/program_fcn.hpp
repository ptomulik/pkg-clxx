// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_fcn.hpp

/** // doc: clxx/cl/program_fcn.hpp {{{
 * \file clxx/cl/program_fcn.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_FCN_HPP_INCLUDED
#define CLXX_CL_PROGRAM_FCN_HPP_INCLUDED

#include <clxx/cl/programs.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/program_observer.hpp>
#include <clxx/cl/devices.hpp>

namespace clxx {
/** \addtogroup clxx_program_objects
 * @{ */
/** // doc: build_program(options) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all the devices in the OpenCL context associated with program.
 *
 * \param program
 *    the \ref clxx::program "program" to be built,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object
 *    (see \ref clxx::program::is_initialized() "program::is_initialized()").
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 */ // }}}
void build_program(clxx::program const& program,
                   std::string const& options);
/** // doc: build_program(devices, options) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for specific devices in the OpenCL context associated with program.
 *
 * \param program
 *    the \ref clxx::program "program" to be built,
 * \param devices
 *    devices associated with the program \p program; the executable is built
 *    for these devices, for which a source or binary has been loaded,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object
 *    (see \ref clxx::program::is_initialized() "program::is_initialized()").
 * \throws uninitialized_device_error
 *    when one of the \p devices is uninitialized
 *    (see \ref clxx::device::is_initialized() "device::is_initialized()").
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 */ // }}}
void build_program(clxx::program const& program,
                   clxx::devices const& devices,
                   std::string const& options);
/** // doc: build_program(options, observer) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all devices in the OpenCL context associated with program.
 *
 * \param program
 *    the \ref clxx::program "program" to be built,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 * \param observer
 *    observer object (see \ref program_observer) used to receive notifications
 *    the callback may be called asynchronously by the OpenCL implementation,
 *    it's the application's responsibility to ensure that the callback
 *    function is thread-safe.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object
 *    (see \ref clxx::program::is_initialized() "program::is_initialized()").
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()"
 */ // }}}
void build_program(clxx::program const& program,
                   std::string const& options,
                   clxx::program_observer& observer);
/** // doc: build_program(devices, options, observer) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for specific devices in the OpenCL context associated with program.
 *
 * \param program
 *    the \ref clxx::program "program" to be built,
 * \param devices
 *    devices associated with the program \p prog; the executable is built for
 *    these devices, for which a source or binary has been loaded,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 * \param observer
 *    observer object (see \ref program_observer) used to receive notifications
 *    the callback may be called asynchronously by the OpenCL implementation,
 *    it's the application's responsibility to ensure that the callback
 *    function is thread-safe.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object
 *    (see \ref clxx::program::is_initialized() "program::is_initialized()").
 * \throws uninitialized_device_error
 *    when one of the \p devices is uninitialized
 *    (see \ref clxx::device::is_initialized() "device::is_initialized()").
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 */ // }}}
void build_program(clxx::program const& program,
                   clxx::devices const& devices,
                   std::string const& options,
                   clxx::program_observer& observer);
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for all associated devices
 *
 * Compiles a program’s source for all the devices in the OpenCL
 * context associated with program \p program. The compiled binary can be queried
 * using <tt>program.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param program
 *    the program object that is the compilation target,
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 *
 * \throws uninitialized_program_error when the \p program object was not
 *         properly initialized (see \ref clxx::program::is_initialized()).
 *
 * Throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program()".
 */ // }}}
void compile_program(clxx::program const& program,
                     std::string const& options,
                     clxx::programs const& input_headers,
                     std::vector<std::string> const& header_include_names);
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for all associated devices
 *
 * Compiles a program’s source for all the devices in the OpenCL
 * context associated with program \p program. The compiled binary can be
 * queried using <tt>program.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param program
 *    the program object that is the compilation target,
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 * \param observer
 *    an oberver object (\ref clxx::program_observer "program_observer") that
 *    will be notified when program executable has been built; the observer
 *    may be notified asynchronously; it is the application’s responsibility to
 *    ensure that the callback function is thread-safe.
 *
 * \throws uninitialized_program_error when the \p program object was not
 *         properly initialized (see \ref clxx::program::is_initialized()).
 *
 * Throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program().
 */ // }}}
void compile_program(clxx::program const& program,
                     std::string const& options,
                     clxx::programs const& input_headers,
                     std::vector<std::string> const& header_include_names,
                     clxx::program_observer& observer);
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for specific devices
 *
 * Compiles a program’s source for all specific devices in the OpenCL
 * context associated with program \p program. The compiled binary can be
 * queried using <tt>program.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param program
 *    the program object that is the compilation target,
 * \param devices
 *    devices associated with \p program, for which the compile is performed
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 *
 * \throws uninitialized_program_error when the \p program object was not properly
 *        initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *    when one of the devices in \p devices is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program()".
 */ // }}}
void compile_program(clxx::program const& program,
                     clxx::devices const& devices,
                     std::string const& options,
                     clxx::programs const& input_headers,
                     std::vector<std::string> const& header_include_names);
/** // doc: compile_program(...) {{{
 * \brief Compile \ref clxx::program "program"’s  source for specific devices
 *
 * Compiles a program’s source for specific devices in the OpenCL
 * context associated with program \p program. The compiled binary can be
 * queried using <tt>program.get_binaries()</tt> and can be specified to
 * \ref clxx::program "program"'s constructor to create a new
 * \ref clxx::program "program" object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param program
 *    the program object that is the compilation target,
 * \param devices
 *    devices associated with \p program, for which the compile is performed
 * \param options
 *    string of characters that describes the compilation options to be used
 *    for building the program executable,
 * \param input_headers
 *    program embedded headers created from source,
 * \param header_include_names
 *    a vector that has a one to one correspondence with \e input_headers. Each
 *    entry in \e header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \e input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \e header_include_names refer to the same
 *    header name, the first one encountered will be used.
 * \param observer
 *    an oberver object (\ref clxx::program_observer "program_observer") that
 *    will be notified when program executable has been built; the observer
 *    may be notified asynchronously; it is the application’s responsibility to
 *    ensure that the callback function is thread-safe.
 *
 * \throws uninitialized_program_error when the \p program object was not
 *         properly initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *    when one of the devices in \p devices is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::compile_program() "compile_program()".
 */ // }}}
void compile_program(clxx::program const& program,
                     clxx::devices const& devices,
                     std::string const& options,
                     clxx::programs const& input_headers,
                     std::vector<std::string> const& header_include_names,
                     clxx::program_observer& observer);
#endif
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
/** // doc: link_program(context, devices, options, input_programs) {{{
 * \brief Links a set of compiled program objects and libraries and creates an
 *    executable.
 *
 *  Creates a new program object which contains executable. The executable
 *  binary can be queried using \ref clxx::program::get_binaries() on the
 *  returned object, and can be specified to \ref clxx::program "program"'s
 *  constructor to create a new program object with binary.
 *
 *  The devices associated with the returned program object will be the list of
 *  devices specified by \e device_list or if \e device_list is \c NULL it will
 *  be the list of devices associated with \e context.
 *
 *  The linking operation can begin if the context, list of devices, input
 *  programs and linker options specified are all valid and appropriate host
 *  and device resources needed to perform the link are available. If the
 *  linking operation can begin, the function returns a valid program object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param context
 *    must be a valid \ref clxx::context "context",
 * \param device_list
 *    devices that are in context \p context, for which the link is to be
 *    performed,
 * \param options
 *    string of characters that describes the link options to be used for
 *    building the program executable,
 * \param input_programs
 *    \ref clxx::program "program" objects that are compiled binaries or
 *    libraries that are to be linked to create the program executable.
 *
 * \throws uninitialized_context_error when the \p context object was not
 *        properly initialized (see \ref clxx::context::is_initialized()).
 * \throws uninitialized_program_error when the \p program object was not
 *        properly initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *    when one of the devices in \e device_list is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::link_program() "link_program()".
 */ // }}}
program link_program(clxx::context const& context,
                     clxx::devices const& device_list,
                     std::string const& options,
                     clxx::programs const& input_programs);
/** // doc: link_program(context, devices, options, input_programs, observer) {{{
 * \brief Links a set of compiled program objects and libraries and creates an
 *    executable.
 *
 *  Creates a new program object which contains executable. The executable
 *  binary can be queried using \ref clxx::program::get_binaries() on the
 *  returned object, and can be specified to \ref clxx::program "program"'s
 *  constructor to create a new program object with binary.
 *
 *  The devices associated with the returned program object will be the list of
 *  devices specified by \e device_list or if \e device_list is \c NULL it will
 *  be the list of devices associated with \e context.
 *
 *  The linking operation can begin if the context, list of devices, input
 *  programs and linker options specified are all valid and appropriate host
 *  and device resources needed to perform the link are available. If the
 *  linking operation can begin, the function returns a valid program object.
 *
 * \note The function is available only when clxx is built with OpenCL 1.2 or
 *       later.
 *
 * \param context
 *    must be a valid \ref clxx::context "context",
 * \param device_list
 *    devices that are in context \p context, for which the link is to be
 *    performed,
 * \param options
 *    string of characters that describes the link options to be used for
 *    building the program executable,
 * \param input_programs
 *    \ref clxx::program "program" objects that are compiled binaries or
 *    libraries that are to be linked to create the program executable,
 * \param observer
 *    a \ref clxx::program_observer "program_observer" object which will be
 *    notified when the program executable has been built (successfully or
 *    unsuccessfully); the observer may be called asynchronously, it's the
 *    application's responsibility to ensure that the callback is thread-safe.
 *
 * \throws uninitialized_context_error when the \p context object was not
 *        properly initialized (see \ref clxx::context::is_initialized()).
 * \throws uninitialized_program_error when one of the \p input_programs was
 *        not properly initialized (see \ref clxx::program::is_initialized()).
 * \throws uninitialized_device_error
 *        when one of the devices in \e device_list is uninitialized (see \ref
 *        clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::link_program() "link_program()".
 */ // }}}
program link_program(clxx::context const& context,
                     clxx::devices const& device_list,
                     std::string const& options,
                     clxx::programs const& input_programs,
                     clxx::program_observer& observer);
#endif
/** @} */
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_FCN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
