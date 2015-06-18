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
 * \ingroup clxx_info
 * \brief Indicate what information to retrieve from an OpenCL platform.
 *
 * This class encapsulates several boolean flags which indicate what
 * information should be retrieved from an OpenCL platform when performing
 * a platform info query. Objects of type #platform_query are used
 * together with #query_platform_info() function and #clxx::platform_info to
 * query several parmeters describing local OpenCL platform(s) at once.
 *
 * For each platform info parameter \em xxx two methods are provided by the
 * class:
 *
 * - \em xxx_selected() - to check if attribute \em xxx is selected for query,
 * - \em select_xxx() - to select or deselect attribute \em xxx.
 */ // }}}
class platform_query
{
  template <class Archive>
  friend void _serialize(Archive&, platform_query&, const unsigned int);
public:
  /** // doc: class_version {{{
   * \brief Class version number
   *
   * Used by the serialization machinery (see \ref clxx_s11n)
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
public:
  /** // doc: ~platform_query() {{{
   * \brief Destructor
   */ // }}}
  virtual ~platform_query() noexcept;
  /** // doc: platform_query() {{{
   * \brief Default constructor
   *
   * Selects all attributes to be queried.
   */ // }}}
  platform_query() noexcept;
  /** // doc: platform_query(flag) {{{
   * \brief Constructor
   * \param flag Determines, whether attributes shall be initially selected or
   *        deselected (\c true - selected, \c false - deselected)
   */ // }}}
  platform_query(bool flag) noexcept;
  /** // doc: select_all() {{{
  * \brief Select all the platform attributes
  * \returns A mutable reference to the modified #platform_query object.
  */ // }}}
  platform_query& select_all() noexcept;
  /** // doc: select_none() {{{
  * \brief Deselect all the platform attributes
  * \returns A mutable reference to the modified #platform_query object.
  */ // }}}
  platform_query& select_none() noexcept;
  /** // doc: select_default() {{{
   * \brief Make a default selection
   *
   * By default all attributes are selected. It's guaranteed, that default
   * selections is same as that after object initialization by default
   * constructor.
   *
   * \returns A mutable reference to the modified #platform_query object.
   */ // }}}
  platform_query& select_default() noexcept;
  // getters {{{
  /** // {{{
   * \brief Whether \ref clxx::platform_info::id "id" attribute is selected
   * \returns \c true if \ref clxx::platform_info::id "id" is selected or \c false if not
   */ // }}}
  inline bool id_selected() const noexcept
  {
    return this->_id;
  }
  /** // {{{
   * \brief Whether \ref clxx::platform_info::profile "profile" attribute is selected
   * \returns \c true if \ref clxx::platform_info::profile "profile" is selected or \c false if not
   */ // }}}
  inline bool profile_selected() const noexcept
  {
    return this->_profile;
  }
  /** // {{{
   * \brief Whether \ref clxx::platform_info::version "version" attribute is selected
   * \returns \c true if \ref clxx::platform_info::version "version" is selected or \c false if not
   */ // }}}
  inline bool version_selected() const noexcept
  {
    return this->_version;
  }
  /** // {{{
   * \brief Whether \ref clxx::platform_info::name "name" attribute is selected
   * \returns \c true if \ref clxx::platform_info::name "name" is selected or \c false if not
   */ // }}}
  inline bool name_selected() const noexcept
  {
    return this->_name;
  }
  /** // {{{
   * \brief Whether \ref clxx::platform_info::vendor "vendor" attribute is selected
   * \returns \c true if \ref clxx::platform_info::vendor "vendor" is selected or \c false if not
   */ // }}}
  inline bool vendor_selected() const noexcept
  {
    return this->_vendor;
  }
  /** // {{{
   * \brief Whether \ref clxx::platform_info::extensions "extensions" attribute is selected
   * \returns \c true if \ref clxx::platform_info::extensions "extensions" is selected or \c false if not
   */ // }}}
  inline bool extensions_selected() const noexcept
  {
    return this->_extensions;
  }
  // }}}
  // selectors {{{
  /** // {{{
   * \brief Select or deselect the \ref clxx::platform_info::id "id" attribute
   * \param flag \c true to select, \c false to deselected
   * \returns A mutable reference to the modified #platform_query object.
   */ // }}}
  inline platform_query& select_id(bool flag = true) noexcept
  {
    this->_id = flag;
    return *this;
  }
  /** // {{{
   * \brief Select or deselect the \ref clxx::platform_info::profile "profile" attribute
   * \param flag \c true to select, \c false to deselected
   * \returns A mutable reference to the modified #platform_query object.
   */ // }}}
  inline platform_query& select_profile(bool flag = true) noexcept
  {
    this->_profile = flag;
    return *this;
  }
  /** // {{{
   * \brief Select or deselect the \ref clxx::platform_info::version "version" attribute
   * \param flag \c true to select, \c false to deselected
   * \returns A mutable reference to the modified #platform_query object.
   */ // }}}
  inline platform_query& select_version(bool flag = true) noexcept
  {
    this->_version = flag;
    return *this;
  }
  /** // {{{
   * \brief Select or deselect the \ref clxx::platform_info::name "name" attribute
   * \param flag \c true to select, \c false to deselected
   * \returns A mutable reference to the modified #platform_query object.
   */ // }}}
  inline platform_query& select_name(bool flag = true) noexcept
  {
    this->_name = flag;
    return *this;
  }
  /** // {{{
   * \brief Select or deselect the \ref clxx::platform_info::vendor "vendor" attribute
   * \param flag \c true to select, \c false to deselected
   * \returns A mutable reference to the modified #platform_query object.
   */ // }}}
  inline platform_query& select_vendor(bool flag = true) noexcept
  {
    this->_vendor = flag;
    return *this;
  }
  /** // {{{
   * \brief Select or deselect the \ref clxx::platform_info::extensions "extensions" attribute
   * \param flag \c true to select, \c false to deselected
   * \returns A mutable reference to the modified #platform_query object.
   */ // }}}
  inline platform_query& select_extensions(bool flag = true) noexcept
  {
    this->_extensions = flag;
    return *this;
  }
  // }}}
private:
  void _select(bool flag) noexcept;
  void _init(bool flag) noexcept;
  // Attributes {{{
  bool _id;
  bool _profile;
  bool _version;
  bool _name;
  bool _vendor;
  bool _extensions;
  // }}}
};
/** \addtogroup clxx_info
 * @{ */
/** // doc: operator==(platform_query, platform_query) {{{
 * \brief Compare two \ref clxx::platform_query "platform_queries"
 *
 * Two \ref clxx::platform_query "platform_queries" are equal if and only if
 * their selections are identical.
 *
 * \param a Left hand side operand to comparison
 * \param b Right hand side operand to comparison
 * \returns \c true if two queries are equal or \c false otherwise
 */ // }}}
bool operator==(platform_query const& a, platform_query const& b) noexcept;
/** // doc: operator==(platform_query, platform_query) {{{
 * \brief Compare two \ref clxx::platform_query "platform_queries"
 *
 * Two \ref clxx::platform_query "platform_queries" are equal if and only if
 * their selections are identical.
 *
 * \param a Left hand side operand to comparison
 * \param b Right hand side operand to comparison
 * \returns \c true if two queries are equal or \c false otherwise
 */ // }}}
inline bool operator!=(platform_query const& a, platform_query const& b) noexcept
{ return !(a == b); }
/** @} */
} // end namespace clxx
#endif /* CLXX_PLATFORM_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
