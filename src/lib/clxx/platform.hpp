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
{
private:
  cl_platform_id _platform_id;
public:
  /** // {{{
   * \brief Defalt constructor
   *
   * Sets underlying platform ID to NULL, so the proxy object is regarder
   * uninitialized (is_initialized() returns \c false).
   */ // }}}
  constexpr platform() noexcept
    : _platform_id(nullptr)
  { }
  /** // {{{
   * \brief Copy constructor
   *
   * Initializes this object with the platform ID of another one (\c rhs).
   */ // }}}
  constexpr platform(platform const& rhs) noexcept
    : _platform_id(rhs.id())
  { }
  /** // {{{
   * \brief Constructor with explicit conversion.
   *
   * Initializes this object with platform ID provided by caller.
   */ // }}}
  explicit
#ifndef SWIG // workaround for swig issue #284
  constexpr
#endif
  platform(cl_platform_id id) noexcept
    : _platform_id(id)
  { }
  /** // {{{
   * \brief Assignment operator.
   * \return Reference to this object.
   */ // }}}
  platform& operator=(platform const& rhs) noexcept
  {
    this->assign(rhs);
    return *this;
  }
  /** // {{{
   * \brief Conversion operator.
   * \return %platform ID keept by this proxy object.
   *
   * Casts platform object to \c cl_platform_id.
   */ // }}}
  explicit
#ifndef SWIG // workaround for swig issue #284
  constexpr
#endif
  operator cl_platform_id () const noexcept
  {
    return this->id();
  }
  /** // {{{
   * \brief Assignment
   *
   * Assign new platform ID to this proxy object (start proxying to another
   * OpenCL platform).
   */ // }}}
  void assign(platform const& rhs) noexcept
  {
    if(&rhs != this)
      {
        this->_platform_id = rhs.id();
      }
  }
  /** // {{{
   * \brief Tell whether this object is initialized or not
   * \return \c true if object is initialized or \c false otherwise
   */ // }}}
  constexpr bool is_initialized() const noexcept
  {
    return (this->_platform_id != NULL);
  }
  /** // {{{
   * \brief Get the OpenCL platform ID of this platform.
   * \return The platform ID of this platform
   */ // }}}
  constexpr cl_platform_id id() const noexcept
  {
    return this->_platform_id;
  }
  /** // {{{
   * \brief Get the OpenCL platform ID of this platform
   * \return The platform ID of this platform
   *
   * This function also checks, if the platform ID is not NULL (proxy
   * initialized). If it is NULL, then the exception
   * CLXX_EXCEPTION(Uninitialized_Platform) is thrown.
   */ // }}}
  cl_platform_id get_valid_id() const;
  /** // {{{
   * \brief Query OpenCL platform for certain information.
   *
   * \param name
   *    An enumeration constant that identifies the platform information being
   *    queried. It may be \c CL_PLATFORM_PROFILE, \c CL_PLATFORM_VERSION, and
   *    so on. See OpenCL specification (\c clGetPlatformInfo()) for details.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by param_value. This
   *    size in bytes must be ≥ size of return type specified in the OpenCL
   *    specification (\c clGetPlatformInfo()).
   * \param value
   *    A pointer to memory location where appropriate values for a given
   *    param_value will be returned. Possible param_value values returned are
   *    described in the OpenCL specification (\c clGetPlatformInfo()). If
   *    param_value is NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by param_value.
   *    If param_value_size_ret is NULL, it is ignored.
   *
   * This function maps directly to \c clGetGetPlatformInfo(). The platform ID
   * encapsulated by this proxy object is used as first argument to \c
   * clGetPlatformInfo().
   *
   * If this object holds uninitialized platform ID, then the method throws
   * exception CLXX_EXCEPTION(Uninitialized_Platform).
   *
   */ // }}}
  void get_info(platform_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
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
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_VERSION,...)
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
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_NAME,...)
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
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_VENDOR,...)
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
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_EXTENSIONS,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_extensions() const;
  /** // {{{
   * \brief Equal-to overloaded operator.
   * Compares identifiers of two \ref platform objects.
   */ // }}}
  bool operator == (platform const& x) const
  { return this->id() == x.id(); }
  /** // {{{
   * \brief Not equal-to overloaded operator.
   * Compares identifiers of two \ref platform objects.
   */ // }}}
  bool operator != (platform const& x) const
  { return this->id() != x.id(); }
  /** // {{{
   * \brief Less-than overloaded operator.
   * Compares identifiers of two \ref platform objects.
   */ // }}}
  bool operator < (platform const& x) const
  { return this->id() < x.id(); }
  /** // {{{
   * \brief Greater-than overloaded operator.
   * Compares identifiers of two \ref platform objects.
   */ // }}}
  bool operator > (platform const& x) const
  { return this->id() > x.id(); }
  /** // {{{
   * \brief Less-or-equal-to overloaded operator.
   * Compares identifiers of two \ref platform objects.
   */ // }}}
  bool operator <= (platform const& x) const
  { return this->id() <= x.id(); }
  /** // {{{
   * \brief Greater-or-equal-to overloaded operator.
   * Compares identifiers of two \ref platform objects.
   */ // }}}
  bool operator >= (platform const& x) const
  { return this->id() >= x.id(); }
  /** // {{{
   * \brief Conversion to bool
   * \returns true if the object is initialized or false otherwise
   */ // }}}
  operator bool() const
  { return this->is_initialized(); }
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
