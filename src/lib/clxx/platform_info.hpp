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
 * \brief Encapsulates parameters retrieved from OpenCL platfrom.
 *
 * An object of type clxx::platform_info keeps the result of an aggregate query
 * to a single OpenCL platform. It may be used, for example, to pass that
 * information between comuters, serialize it or write it to a stream.
 */ // }}}
class platform_info
{
  template <class Archive>
  friend void _serialize(Archive&, platform_info&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \todo Write documentation
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: platform_info() {{{
   * \brief Default constructor.
   */ // }}}
  platform_info();
  /** // doc: ~platform_info() {{{
   * \brief Destructor.
   */ // }}}
  virtual ~platform_info() { }
  /** // doc: clear() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& clear();
  /** // doc: cmp() {{{
   * \todo Write documentation
   */ // }}}
  bool cmp(platform_info const&) const noexcept;
  // getters {{{
  /** // // doc: id() {{{
   * \brief Identifier of the recently queried OpenCL platform.
   * \return The \c cl_platform_id identifier of an OpenCL platform, whose
   *    parameters are keeps in this object.
   */ // }}}
  unsigned long id() const;
  /** // // doc: profile() {{{
   * \brief Platform profile string retrieved with Platform::get_profile().
   * \todo Refine documentation
   */ // }}}
  std::string const& profile() const;
  /** // // doc: version() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  std::string const& version() const;
  /** // // doc: name() {{{
   * \brief Platform version string retrieved with Platform::get_version().
   * \todo Refine documentation
   */ // }}}
  std::string const& name() const;
  /** // // doc: vendor() {{{
   * \todo Refine documentation
   * \brief Platform vendor string retrieved with Platform::get_vendor().
   */ // }}}
  std::string const& vendor() const;
  /** // // doc: extensions() {{{
   * \todo Refine documentation
   * \brief Platform extensions string retrieved with
   *        Platform::get_extensions().
   */ // }}}
  std::string const& extensions() const;
  // }}}
  // setters {{{
  /** // doc: set_id() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& set_id(unsigned long val) noexcept;
  /** // doc: set_profile() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& set_profile(std::string const& val);
  /** // doc: set_version() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& set_version(std::string const& val);
  /** // doc: set_name() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& set_name(std::string const& val);
  /** // doc: set_vendor() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& set_vendor(std::string const& val);
  /** // doc: set_extensions() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& set_extensions(std::string const& val);
  // }}}
  // cleaners {{{
  /** // doc: clear_id() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& clear_id() noexcept;
  /** // doc: clear_profile() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& clear_profile() noexcept;
  /** // doc: clear_version() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& clear_version() noexcept;
  /** // doc: clear_name() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& clear_name() noexcept;
  /** // doc: clear_vendor() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& clear_vendor() noexcept;
  /** // doc: clear_extensions() {{{
   * \todo Write documentation
   */ // }}}
  platform_info& clear_extensions() noexcept;
  // }}}
  // presence {{{
  /** // doc: has_id() {{{
   * \todo Write documentation
   */ // }}}
  bool has_id() const noexcept;
  /** // doc: has_profile() {{{
   * \todo Write documentation
   */ // }}}
  bool has_profile() const noexcept;
  /** // doc: has_version() {{{
   * \todo Write documentation
   */ // }}}
  bool has_version() const noexcept;
  /** // doc: has_name() {{{
   * \todo Write documentation
   */ // }}}
  bool has_name() const noexcept;
  /** // doc: has_vendor() {{{
   * \todo Write documentation
   */ // }}}
  bool has_vendor() const noexcept;
  /** // doc: has_extensions() {{{
   * \todo Write documentation
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

/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator== (platform_info const& a, platform_info const& b)
  noexcept
{ return a.cmp(b); }
/** // doc: operator==(a,b) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!= (platform_info const& a, platform_info const& b)
  noexcept
{ return !(a == b); }

} // end namespace clxx

#endif /* CLXX_PLATFORM_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
