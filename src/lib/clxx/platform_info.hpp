// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_info.hpp

/** // // doc: clxx/platform_info.hpp {{{
 * \file clxx/platform_info.hpp
 * \brief Provides clxx::platform_info class.
 *
 * This file contains definition of clxx::platform_info class, which
 * encapsulates several parameters retrieved from OpenCL platfrom.
 */ // }}}
#ifndef CLXX_PLATFORM_INFO_HPP_INCLUDED
#define CLXX_PLATFORM_INFO_HPP_INCLUDED

#include <string>
#include <boost/optional.hpp>

namespace clxx {
/** // doc: class platform_info {{{
 * \ingroup clxx_info
 * \brief Encapsulates parameters retrieved from OpenCL platfrom.
 *
 * An object of type clxx::platform_info keeps the result of an aggregate query
 * to a single OpenCL platform. It may be used, for example, to pass that
 * information between computers, serialize it or write it to a stream.
 *
 * \par Example
 *
 * Manipulating #platform_info attributes "by hand"
 *
 * \snippet clxx/platform_info1.cpp Program
 *
 * \par Output
 *
 * \snippet clxx/platform_info1.cpp Output
 */ // }}}
class platform_info
{
  template <class Archive>
  friend void _serialize(Archive&, platform_info&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \brief Class version number
   *
   * It's be used by the serialization machinery (see \ref clxx_s11n).
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: platform_info() {{{
   * \brief Default constructor
   *
   * Sets all the attributes to be uninitialized
   */ // }}}
  platform_info();
  /** // doc: ~platform_info() {{{
   * \brief Destructor.
   */ // }}}
  virtual ~platform_info() { }
  /** // doc: clear() {{{
   * \brief Clear all attributes
   *
   * After this operations, all the attributes of platform info are uninitialized.
   *
   * \returns A mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& clear();
  /** // doc: cmp() {{{
   * \brief Compare this #platform_info object to another one
   *
   * The comparison is performed attribute-by-attribute.
   *
   * \param other Another #platform_info object to be compared to this one
   * \returns \c true if objects are equal or \c false otherwise
   */ // }}}
  bool cmp(platform_info const& other) const noexcept;
  // getters {{{
  /** // // doc: id() {{{
   * \brief Identifier of the recently queried OpenCL platform.
   * \return The \c cl_platform_id identifier of an OpenCL platform, whose
   *    parameters are keeps in this object.
   * \throws uninitialized_value_error If #id is not initialized (see #has_id())
   */ // }}}
  unsigned long id() const;
  /** // // doc: profile() {{{
   * \brief Platform profile string retrieved with Platform::get_profile().
   * \returns Immutable reference to the string containing platform profile info
   * \throws uninitialized_value_error If #profile is not initialized (see #has_profile())
   */ // }}}
  std::string const& profile() const;
  /** // // doc: version() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \returns Immutable reference to the string containing platform version
   * \throws uninitialized_value_error If #version is not initialized (see #has_version())
   */ // }}}
  std::string const& version() const;
  /** // // doc: name() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \returns Immutable reference to the string containing platform name
   * \throws uninitialized_value_error If #name is not initialized (see #has_name())
   */ // }}}
  std::string const& name() const;
  /** // // doc: vendor() {{{
   * \brief Platform vendor string retrieved with Platform::get_vendor().
   * \returns Immutable reference to the string containing platform's vendor name
   * \throws uninitialized_value_error If #vendor is not initialized (see #has_vendor())
   */ // }}}
  std::string const& vendor() const;
  /** // // doc: extensions() {{{
   * \brief Platform extensions string retrieved with Platform::get_extensions().
   * \returns Immutable reference to the string containing platform extensions
   * \throws uninitialized_value_error If #extensions is not initialized (see #has_extensions())
   */ // }}}
  std::string const& extensions() const;
  // }}}
  // setters {{{
  /** // doc: set_id() {{{
   * \brief Set platform ID
   * \param val New value of the attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& set_id(unsigned long val) noexcept;
  /** // doc: set_profile() {{{
   * \brief Set platform profile string
   * \param val New value of the attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& set_profile(std::string const& val);
  /** // doc: set_version() {{{
   * \brief Set platform version string
   * \param val New value of the attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& set_version(std::string const& val);
  /** // doc: set_name() {{{
   * \brief Set platform name string
   * \param val New value of the attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& set_name(std::string const& val);
  /** // doc: set_vendor() {{{
   * \brief Set platform vendor name string
   * \param val New value of the attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& set_vendor(std::string const& val);
  /** // doc: set_extensions() {{{
   * \brief Set platform extensions string
   * \param val New value of the attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& set_extensions(std::string const& val);
  // }}}
  // cleaners {{{
  /** // doc: clear_id() {{{
   * \brief Clear platform #id attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& clear_id() noexcept;
  /** // doc: clear_profile() {{{
   * \brief Clear platform #profile attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& clear_profile() noexcept;
  /** // doc: clear_version() {{{
   * \brief Clear platform #version attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& clear_version() noexcept;
  /** // doc: clear_name() {{{
   * \brief Clear platform #name attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& clear_name() noexcept;
  /** // doc: clear_vendor() {{{
   * \brief Clear platform #vendor attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& clear_vendor() noexcept;
  /** // doc: clear_extensions() {{{
   * \brief Clear platform #extensions attribute
   * \returns Mutable reference to the modified #platform_info object
   */ // }}}
  platform_info& clear_extensions() noexcept;
  // }}}
  // presence {{{
  /** // doc: has_id() {{{
   * \brief Whether the #id attribute is initialized
   * \returns \c true if #id is initialized or \c false otherwise
   */ // }}}
  bool has_id() const noexcept;
  /** // doc: has_profile() {{{
   * \brief Whether the #profile attribute is initialized
   * \returns \c true if #profile is initialized or \c false otherwise
   */ // }}}
  bool has_profile() const noexcept;
  /** // doc: has_version() {{{
   * \brief Whether the #version attribute is initialized
   * \returns \c true if #version is initialized or \c false otherwise
   */ // }}}
  bool has_version() const noexcept;
  /** // doc: has_name() {{{
   * \brief Whether the #name attribute is initialized
   * \returns \c true if #name is initialized or \c false otherwise
   */ // }}}
  bool has_name() const noexcept;
  /** // doc: has_vendor() {{{
   * \brief Whether the #vendor attribute is initialized
   * \returns \c true if #vendor is initialized or \c false otherwise
   */ // }}}
  bool has_vendor() const noexcept;
  /** // doc: has_extensions() {{{
   * \brief Whether the #extensions attribute is initialized
   * \returns \c true if #extensions is initialized or \c false otherwise
   */ // }}}
  bool has_extensions() const noexcept;
  // }}}
private:
  void _init();
  void _clear();
  // attributes {{{
  boost::optional<unsigned long> _id;
  boost::optional<std::string> _profile;
  boost::optional<std::string> _version;
  boost::optional<std::string> _name;
  boost::optional<std::string> _vendor;
  boost::optional<std::string> _extensions;
  // }}}
};

/** \addtogroup clxx_info
 * @{ */
/** // doc: operator==(a,b) {{{
 * \brief Compare two \ref clxx::platform_info "platform_info" objects
 * \param a Left-hand side operand to the comparison
 * \param b Right-hand side operand to the comparison
 * \returns \c true if objects are equal or \c false otherwise
 *
 * This compares object attribute-by-attribute
 */ // }}}
inline bool operator== (platform_info const& a, platform_info const& b)
  noexcept
{ return a.cmp(b); }
/** // doc: operator==(a,b) {{{
 * \brief Compare two \ref clxx::platform_info "platform_info" objects
 * \param a Left-hand side operand to the comparison
 * \param b Right-hand side operand to the comparison
 * \returns \c false if objects are equal or \c true otherwise
 *
 * This compares object attribute-by-attribute
 */ // }}}
inline bool operator!= (platform_info const& a, platform_info const& b)
  noexcept
{ return !(a == b); }
/** @} */

} // end namespace clxx
#endif /* CLXX_PLATFORM_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
