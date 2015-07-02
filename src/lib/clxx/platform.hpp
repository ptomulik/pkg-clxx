// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform.hpp

/** // doc: clxx/platform.hpp {{{
 * \file clxx/platform.hpp
 * \brief Provides the clxx::platform and clxx::get_platform_info().
 *
 * This file contains clxx::platform class (OpenCL platform proxy object),
 * which provides access to OpenCL platform information.
 *
 */ // }}}
#ifndef CLXX_PLATFORM_HPP_INCLUDED
#define CLXX_PLATFORM_HPP_INCLUDED

#include <clxx/platform_fwd.hpp>
#include <clxx/types.hpp>
#include <clxx/clobj.hpp>
#include <string>

namespace clxx {

/** // {{{ doc: platform
 * \ingroup clxx_platform_layer
 * \brief OpenCL platform proxy
 *
 * This class provides access to OpenCL platform information, equivalent to
 * OpenCL's \c clGetPlatformInfo(), but:
 *
 * - it has easy to use, type-safe c++ interface,
 * - returns \c std::string instead of plain \c char* data,
 * - replaces OpenCL error codes with exceptions (see \ref clxx_exceptions),
 *
 * The object is lightweight. It encapsulates only a single \c cl_platform_id
 * identifier.
 *
 * The class has non-virtual destructor to not bloat the objects with virtual
 * tables. It should not be used as a base class.
 *
 *
 * \par Example:
 * Simple functor to print platform info:
 * \snippet platform1.cpp DumpPlatform
 *
 */ // }}}
class alignas(cl_platform_id) platform
  : public clobj<cl_platform_id>
{
public:
  /** // doc: Base {{{
   * \brief Typedef for the base class type
   */ // }}}
  typedef clobj<cl_platform_id> Base;
  using Base::Base;
  /** // doc: platform() {{{
   * \brief Default constructor, see \ref clobj::clobj()
   */ // }}}
  platform() = default;
  /** // doc: platform(platform const&) {{{
   * \brief Copy constructor, see \ref clobj::clobj(clobj const&)
   */ // }}}
  platform(platform const&) = default;
  /** // {{{
   * \brief Query the OpenCL for platform profile string.
   *
   * \return The profile name for this platform.
   *
   * This method returns the profile name supported by the implementation.
   * The profile name returned can be one of the following strings:
   * - \c FULL_PROFILE, if the implementation supports the OpenCL
   *   specification (functionality defined as part of the core specification
   *   and does not require any extensions to be supported)
   * - \c EMBEDDED_PROFILE, if the implementation supports the OpenCL
   *   embedded profile. The embedded profile is defined to be a subset
   *   for each version of OpenCL.
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS.
   */ // }}}
  std::string get_profile() const;
  /** // {{{
   * \brief Query the OpenCL for platform version string
   * \return OpenCL platform version string.
   *
   * This method returns the OpenCL version supported by the implementation.
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->handle(),CL_PLATFORM_VERSION,...)
   * According to OpenCL specification, this version string has the
   * following format:
     \verbatim OpenCL<space><major_version.minor_version><space><platform-specific information> \endverbatim
   * For example, in OpenCL 1.2 the \c major_version.minor_version value
   * returned will be \c 1.2.
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_version() const;
  /** // {{{
   * \brief Query the OpenCL for platform name string.
   * \return The platform name string.
   *
   * This method returns the name of this OpenCL platform.
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->handle(),CL_PLATFORM_NAME,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_name() const;
  /** // {{{
   * \brief Query the OpenCL for platform vendor string
   * \return The platform vendor string.
   *
   * This method returns vendor string shown by this OpenCL platform.
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->handle(),CL_PLATFORM_VENDOR,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_vendor() const;
  /** // {{{
   * \brief Query the OpenCL for platform extensions string
   * \return Space separated list of platform extension names
   *
   * This method returns a space separated list of extension names (the
   * extension names themselves do not contain any spaces) supported by
   * the platform. Extensions defined here must be supported by all devices
   * associated with this platform.
   *
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->handle(),CL_PLATFORM_EXTENSIONS,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_extensions() const;
};

} // end namespace clxx

#include <clxx/platform_info.hpp>
#include <clxx/platform_query.hpp>

namespace clxx {
/** \addtogroup clxx_info
 * @{ */
/** // doc: query_platform_info(platform, query) {{{
 * \brief Query platform info
 *
 * Queries the OpenCL platform layer for information describing particular
 * platform. By default, all supported platform attributes are retrieved.
 *
 * \param platform  An OpenCL platform to be queried for information.
 * \param query     Query specification (what attributes to query for).
 * \returns An object of type \ref clxx::platform_info "platform_info"
 *          containing the query result.
 *
 * \par Example
 *
 * Retrieve and print information describing a first OpenCL platform found by
 * clxx in operating system.
 *
 * \snippet clxx/query_platform_info1.cpp Program
 */ // }}}
platform_info
query_platform_info( platform const& platform,
                     platform_query const& query = platform_query() );
/** @} */
} // end namespace clxx

#endif /* CLXX_PLATFORM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
