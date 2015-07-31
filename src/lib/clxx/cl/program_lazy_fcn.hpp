// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_lazy_fcn.hpp

/** // doc: clxx/cl/program_lazy_fcn.hpp {{{
 * \file clxx/cl/program_lazy_fcn.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_LAZY_FCN_HPP_INCLUDED
#define CLXX_CL_PROGRAM_LAZY_FCN_HPP_INCLUDED

#include <clxx/cl/program_fwd.hpp>
#include <clxx/cl/devices.hpp>
#include <clxx/cl/program_observer.hpp>

namespace clxx {
/** \addtogroup clxx_program_objects
 * @{ */
/** // doc: build_program(options) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all the devices in the OpenCL context associated with program.
 * Actual build action is performed only for devices which need it, that is
 * for devices for which the program has not been built yet or for which
 * program has been built with different set of build options.
 *
 * \param program
 *    the \ref clxx::program "program" to be built,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard,
 * \param force_build
 *    if \c true, the program is rebuilt unconditionally, otherwise it gets
 *    rebuilt only if its build status is either #build_status_t::none or
 *    #build_status_t::error, or if it is #build_status_t::success but the
 *    previous build options differ from \p options.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object
 *    (see \ref clxx::program::is_initialized() "program::is_initialized()").
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 *
 * \par Example
 *
 * \snippet clxx/cl/lazy_build_program1.cpp Program
 *
 * \par Output
 *
 * \snippet clxx/cl/lazy_build_program1.cpp Output
 *
 */ // }}}
void lazy_build_program(clxx::program const& program,
                        std::string const& options,
                        bool force_build = false);
/** // doc: build_program(devices, options) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for specific devices in the OpenCL context associated with program.
 * Actual build action is performed only for devices which need it, that is
 * for devices for which the program has not been built yet or for which
 * program has been built with different set of build options.
 *
 * \param program
 *    the \ref clxx::program "program" to be built,
 * \param devices
 *    devices associated with the program \p program; the executable is built
 *    for these devices, for which a source or binary has been loaded,
 * \param options
 *    string of build options to be used for building the program executable;
 *    the list of supported options is defined by the OpenCL standard.
 * \param force_build
 *    if \c true, the program is rebuilt unconditionally, otherwise it gets
 *    rebuilt only if its build status is either #build_status_t::none or
 *    #build_status_t::error, or if it is #build_status_t::success but the
 *    previous build options differ from \p options.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object.
 * \throws uninitialized_device_error
 *    when one of the \p devices is uninitialized
 *    (see \ref clxx::device::is_initialized() "device::is_initialized()").
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 *
 */ // }}}
void lazy_build_program(clxx::program const& program,
                        clxx::devices const& devices,
                        std::string const& options,
                        bool force_build = false);
/** // doc: build_program(options, observer) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all devices in the OpenCL context associated with program.
 * Actual build action is performed only for devices which need it, that is
 * for devices for which the program has not been built yet or for which
 * program has been built with different set of build options.
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
 * \param force_build
 *    if \c true, the program is rebuilt unconditionally, otherwise it gets
 *    rebuilt only if its build status is either #build_status_t::none or
 *    #build_status_t::error, or if it is #build_status_t::success but the
 *    previous build options differ from \p options.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object
 *    (see \ref clxx::program::is_initialized() "program::is_initialized()").
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()"
 *
 */ // }}}
void lazy_build_program(clxx::program const& program,
                        std::string const& options,
                        clxx::program_observer& observer,
                        bool force_build = false);
/** // doc: build_program(devices, options, observer) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *        source or binary
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for specific devices in the OpenCL context associated with program.
 * Actual build action is performed only for devices which need it, that is for
 * devices for which the program has not been built yet or for which program
 * has been built with different set of build options.
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
 * \param force_build
 *    if \c true, the program is rebuilt unconditionally, otherwise it gets
 *    rebuilt only if its build status is either #build_status_t::none or
 *    #build_status_t::error, or if it is #build_status_t::success but the
 *    previous build options differ from \p options.
 *
 * \throws uninitialized_program_error
 *    when \p program is an uninitialized program object
 *    (see \ref clxx::program::is_initialized() "program::is_initialized()").
 * \throws uninitialized_device_error
 *    when one of the devices in \p devices is uninitialized (see \ref
 *    clxx::device::is_initialized()).
 *
 * It also throws exceptions originating from the basic wrapper
 * \ref clxx::build_program() "build_program()".
 *
 */ // }}}
void lazy_build_program(clxx::program const& program,
                        clxx::devices const& devices,
                        std::string const& options,
                        clxx::program_observer& observer,
                        bool force_build = false);
/** @} */
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_LAZY_FCN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
