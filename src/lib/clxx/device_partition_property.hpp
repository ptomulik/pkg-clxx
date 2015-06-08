// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/device_partition_property.hpp

/** // doc: clxx/device_partition_property.hpp {{{
 * \file clxx/device_partition_property.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_DEVICE_PARTITION_PROPERTY_HPP_INCLUDED
#define CLXX_DEVICE_PARTITION_PROPERTY_HPP_INCLUDED

#include <clxx/util/device_partition_property_type.hpp>
#include <clxx/types.hpp>
#include <clxx/exceptions.hpp>
#include <vector>

namespace clxx {

/** \ingroup clxx_platform_layer
 * @{ */

/** // doc: device_partition_counts {{{
 * \todo Write documentation
 */ // }}}
typedef std::vector<unsigned int> device_partition_counts;

/** // struct device_partition_property {{{
 * \todo Write documentation
 */ // }}}
struct device_partition_property
{
  /** // doc: class_version {{{
   * \todo Write documentation
   */ // }}}
  static constexpr unsigned int class_version = 0x000001;
  /** // doc: device_partition_property() {{{
   * \brief Default constructor
   *
   * Initializes empty property (with zeroed name and value).
   */ // }}}
  device_partition_property() noexcept
    : _name(static_cast<device_partition_property_t>(0ul)), _values(1,(cl_device_partition_property)0ul)
  {}
  /** // doc: device_partition_property(device_partition_property_t, cl_device_partition_property) {{{
   * \brief Constructor
   *
   * \param name property name
   * \param value property value
   */ // }}}
  device_partition_property(device_partition_property_t name, cl_device_partition_property value) noexcept
    : _name(name), _values(1,value)
  {}
  /** // doc: device_partition_property(cl_device_partition_property, cl_device_partition_property) {{{
   * \brief Constructor
   *
   * \param name property name
   * \param value property value
   */ // }}}
  device_partition_property(cl_device_partition_property name, cl_device_partition_property value) noexcept
    : _name(static_cast<device_partition_property_t>(name)), _values(1,value)
  {}
  /** // doc: device_partition_property(device_partition_property_t, cl_device_partition_property) {{{
   * \brief Constructor
   * \todo Refine documentation
   * \param name property name
   * \param values property values
   */ // }}}
  template <typename T, typename A>
  device_partition_property(device_partition_property_t name, std::vector<T,A> const& values)
    : _name(name)
  {
    set_values(values);
  }
  /** // doc: device_partition_property(device_partition_property_t, cl_device_partition_property) {{{
   * \brief Constructor
   * \todo Refine documentation
   * \param name property name
   * \param values property value
   */ // }}}
  template <typename T, typename A>
  device_partition_property(cl_device_partition_property name, std::vector<T,A> const& values)
    : _name(static_cast<device_partition_property_t>(name))
  {
    set_values(values);
  }
  /** // doc: name() const {{{
   * \brief Returns property's name
   * \returns The name of this property
   */ // }}}
  device_partition_property_t name() const noexcept
  { return _name; }
  /** // doc: value() const {{{
   * \todo Amend documentation (exception specification)
   * \brief Returns property's value
   * \returns The value of this property
   */ // }}}
  cl_device_partition_property value() const
  {
    if(is_list())
      throw value_access_error();
    return _values[0];
  }
  /** // doc: value(n) const {{{
   * \todo Amend documentation (parameter etc.)
   * \brief Returns property's value
   * \returns The value of this property
   */ // }}}
  cl_device_partition_property value(size_t n) const
  {
    if(!is_list())
      throw value_access_error();
    return _values[n];
  }
  /** // doc: values() const {{{
   * \todo Write documentation
   */ // }}}
  std::vector<cl_device_partition_property> const& values() const
  {
    if(!is_list())
      throw value_access_error();
    return _values;
  }
  /** // doc: set_name() {{{
   * \brief Set property's name
   *
   * \param name new name for this property
   */ // }}}
  void set_name(device_partition_property_t name) noexcept
  { _name = name; }
  /** // doc: set_value() {{{
   * \brief Set property value
   *
   * \param value new value for this property
   */ // }}}
  void set_value(cl_device_partition_property value)
  {
    if(is_list())
      throw value_access_error();
    _values.clear();
    _values.push_back(value);
  }
  /** // doc: set_values() {{{
   * \todo Write documentation
   *
   * \param values new value for this property
   */ // }}}
  template <typename T, typename A>
  void set_values(std::vector<T,A> const& values)
  {
    typedef typename std::vector<T,A>::const_iterator IterIn;
    typedef typename std::vector<cl_device_partition_property>::iterator IterOut;
    if(!is_list())
      throw value_access_error();
    _values.resize(values.size());
    IterOut j = _values.begin();
    for(IterIn i = values.begin(); i != values.end(); ++i, ++j)
      {
        *j = (cl_device_partition_property)*i;
      }
  }
  /** // doc: write(cl_device_partition_property*) const {{{
   * \brief Write the property to OpenCL array
   *
   * \param props pointer to the starting position of the destination array
   *
   * \note **props[0]** and **props[1]** must be writeable. The function **does
   *        not** append trailing zero to array.
   */ // }}}
  size_t write(cl_device_partition_property* props) const noexcept
  {
    props[0] = intval(_name);
    cl_device_partition_property* end = std::copy(_values.begin(),_values.end(), props + 1);
    if(is_list())
      {
        *end++ = (cl_device_partition_property)0;
      }
    return (end - props);
  }
  /** // doc: read(const cl_device_partition_property*) {{{
   * \todo Correct the note.
   *
   * \brief Read single property from OpenCL array
   *
   * \param props pointer to the starting position of the source array
   *
   * \note **props[0]** and **props[1]** must be readable.
   */ // }}}
  size_t read(const cl_device_partition_property* props)
  {
    _name = static_cast<device_partition_property_t>(props[0]);
    _values.clear();
    if(is_list())
      {
        size_t i;
        for(i = 1; props[i]; ++i)
          {
            _values.push_back(props[i]);
          }
        return i;
      }
    else
      {
        _values.push_back(props[1]);
        return 2;
      }
  }
  /** // doc: is_list() {{{
   * \todo Write documentation
   */ // }}}
  bool is_list() const noexcept
  { return name() == device_partition_property_t::by_counts; }
  /** // doc: size() {{{
   * \brief Return size of the property
   *
   * \returns number of elements occupied by the property when stored in an
   *          OpenCL array.
   */ // }}}
  size_t size() const noexcept
  { return 1 + _values.size() + (is_list() ? 1 : 0); }
private:
  device_partition_property_t _name;
  std::vector<cl_device_partition_property> _values;
};
/** @} */

/** \ingroup clxx_platform_layer
 * @{ */
/** // doc: make_device_partition_property_c<N>(device_partition_property_type<N>::type) {{{
 * \brief Type-safe constructor for \ref device_partition_property
 *
 * \tparam N property name
 * \param x Property value
 *
 * \returns A new instance of \ref device_partition_property with value
 *  initialized to \b x.
 */ // }}}
template <device_partition_property_t N>
inline device_partition_property
make_device_partition_property(typename device_partition_property_type<N>::type x)
{
  return device_partition_property(N, (cl_device_partition_property)x);
}
template<>
inline device_partition_property
make_device_partition_property<device_partition_property_t::by_counts>(device_partition_counts const& x)
{
  return device_partition_property(device_partition_property_t::by_counts,x);
}
/** // doc: device_partition_equally() {{{
 * \brief Type-safe constructor for \ref device_partition_property
 *
 * The invocation
 * \code
 *   y = device_partition_equally(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_device_partition_property<device_partition_property_t::equally>(x);
 * \endcode
 */ // }}}
inline device_partition_property
device_partition_equally(unsigned int x)
  {
    return make_device_partition_property<device_partition_property_t::equally>(x);
  }
/** // doc: device_partition_by_counts() {{{
 * \brief Type-safe constructor for \ref device_partition_property
 *
 * The invocation
 * \code
 *   y = device_partition_by_counts(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_device_partition_property<device_partition_property_t::by_counts>(x);
 * \endcode
 */ // }}}
inline device_partition_property
device_partition_by_counts(device_partition_counts const& x)
  {
    return make_device_partition_property<device_partition_property_t::by_counts>(x);
  }
#if CL_VERSION_1_2
/** // doc: device_partition_by_affinity_domain() {{{
 * \brief Type-safe constructor for \ref device_partition_property
 *
 * The invocation
 * \code
 *   y = device_partition_by_affinity_domain(x)
 * \endcode
 *
 * is equivalent to
 *
 * \code
 *   y = make_device_partition_property<device_partition_property_t::by_affinity_domain>(x);
 * \endcode
 */ // }}}
inline device_partition_property
device_partition_by_affinity_domain(device_affinity_domain_t x)
  {
    return make_device_partition_property<device_partition_property_t::by_affinity_domain>(x);
  }
#endif
/** @} */

} // end namespace clxx

#endif /* CLXX_DEVICE_PARTITION_PROPERTY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
