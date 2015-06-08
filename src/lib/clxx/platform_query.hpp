// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/platform_query.hpp

/** // doc: clxx/platform_query.hpp {{{
 * \file clxx/platform_query.hpp
 * \brief Provides the clxx::platform_query class.
 *
 * This file contains definition of clxx::platform_query class, which
 * configures queries to OpenCL platforms.
 */ // }}}
#ifndef CLXX_PLATFORM_QUERY_HPP_INCLUDED
#define CLXX_PLATFORM_QUERY_HPP_INCLUDED

namespace clxx {

/** // doc: class platform_query {{{
 * \brief Indicate what information to retrieve from an OpenCL platform.
 *
 * This class encapsulates several boolean flags which indicate what
 * information should be retrieved from an OpenCL platform. Objects of type
 * clxx::platform_query are used together with clxx::platform_info to query
 * several parmeters describing local OpenCL platform(s) at once.
 */ // }}}
class platform_query
{
  template <class Archive>
  friend void _serialize(Archive&, platform_query&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \todo Write documentation
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: ~platform_query() {{{
   * \todo Write documentation for class platform_query
   */ // }}}
  virtual ~platform_query();
  /** // doc: platform_query() {{{
   * \todo Write documentation
   */ // }}}
  platform_query();
  /** // doc: platform_query(flag) {{{
   * \todo Write documentation
   */ // }}}
  platform_query(bool flag);
  /** // doc: select_all() {{{
  * \todo Write documentation
  */ // }}}
  platform_query& select_all();
  /** // doc: select_none() {{{
  * \todo Write documentation
  */ // }}}
  platform_query& select_none();
  /** // doc: select_default() {{{
  * \todo Write documentation
  */ // }}}
  platform_query& select_default();
  // getters {{{
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool id_selected() const
  {
    return this->_id;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool profile_selected() const
  {
    return this->_profile;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool version_selected() const
  {
    return this->_version;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool name_selected() const
  {
    return this->_name;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool vendor_selected() const
  {
    return this->_vendor;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline bool extensions_selected() const
  {
    return this->_extensions;
  }
  // }}}
  // selectors {{{
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline platform_query& select_id(bool flag = true)
  {
    this->_id = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline platform_query& select_profile(bool flag = true)
  {
    this->_profile = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline platform_query& select_version(bool flag = true)
  {
    this->_version = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline platform_query& select_name(bool flag = true)
  {
    this->_name = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline platform_query& select_vendor(bool flag = true)
  {
    this->_vendor = flag;
    return *this;
  }
  /** // {{{
  * \todo Write documentation
  */ // }}}
  inline platform_query& select_extensions(bool flag = true)
  {
    this->_extensions = flag;
    return *this;
  }
  // }}}
private:
  void _select(bool flag);
  void _init(bool flag);
  // Attributes {{{
  bool _id;
  bool _profile;
  bool _version;
  bool _name;
  bool _vendor;
  bool _extensions;
  // }}}
};
/** // doc: operator==(platform_query, platform_query) {{{
 * \todo Write documentation
 */ // }}}
bool operator==(platform_query const&, platform_query const&);
/** // doc: operator==(platform_query, platform_query) {{{
 * \todo Write documentation
 */ // }}}
inline bool operator!=(platform_query const& a, platform_query const& b)
{ return !(a == b); }

} // end namespace clxx

#endif /* CLXX_PLATFORM_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
