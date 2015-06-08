// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platforms.hpp

/** // doc: clxx/platforms.hpp {{{
 * \file clxx/platforms.hpp
 *
 * This file provides functions to retrieve platform identifiers (and platform
 * proxy objects) of (all) locally available OpenCL platforms.
 */ // }}}
#ifndef CLXX_PLATFORMS_HPP_INCLUDED
#define CLXX_PLATFORMS_HPP_INCLUDED

#include <clxx/platform.hpp>
#include <clxx/cl/cl.h>
#include <vector>

namespace clxx {

/** // {{{ doc: platforms
 * \ingroup clxx_platform_layer
 * \brief Collection of clxx::platform objects.
 */ // }}}
typedef std::vector<platform> platforms;

/** \ingroup clxx_platform_layer */
/** @{ */
/** // {{{ doc: get_num_platforms()
 * \brief Get number of OpenCL platforms available locally.
 *
 * \return The number of available OpenCL platforms
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 */ // }}}
cl_uint get_num_platforms();
/** // {{{ doc: get_platform_ids()
 * \brief Retrieve platform identifiers of locally available OpenCL platforms.
 * \return Vector of \c cl_platform_id identifiers.
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The \c clerror_no<status_t::invalid_value> should never appear in practice.
 * Otherwise the function is buggy.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 */ // }}}
std::vector<cl_platform_id> get_platform_ids();
/** // {{{ doc: get_platforms()
 * \brief Get proxy platform objects for locally available OpenCL platforms.
 *
 * \return clxx::platforms.
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The \c clerror_no<status_t::invalid_value> should never appear in practice.
 * Otherwise the function is buggy.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 */ // }}}
platforms get_platforms();
/** // {{{ doc: make_platforms(ids)
 * \brief Wrap platform identifiers with clxx::platform objects.
 *
 * \param ids OpenCL platform identifiers
 *
 * \return clxx::platforms a collection of platform objects for the given
 *         identifiers
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 */ // }}}
platforms make_platforms(std::vector<cl_platform_id> const& ids);
/** @} */

} // end namespace clxx

#endif /* CLXX_PLATFORMS_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
