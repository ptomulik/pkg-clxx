// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/ndrange.hpp

/** // doc: clxx/ndrange.hpp {{{
 * \file clxx/ndrange.hpp
 * \brief Defines the \ref clxx::ndrange class
 */ // }}}
#ifndef CLXX_NDRANGE_HPP_INCLUDED
#define CLXX_NDRANGE_HPP_INCLUDED

#include <clxx/command_queue.hpp>
#include <clxx/kernel.hpp>

#ifndef CLXX_MAX_NDRANGE_DIMENSIONS
/** // doc: CLXX_MAX_NDRANGE_DIMENSIONS {{{
 * \ingroup clxx_executing_kernels
 * \brief Max number of dimensions supported by \ref clxx::ndrange
 */ // }}}
# define CLXX_MAX_NDRANGE_DIMENSIONS 3
#endif

namespace clxx {
/** // doc: ndrange {{{
 * \ingroup clxx_executing_kernels
 * \brief Describes an ND-range over which a kernel is supposed to execute
 *
 * This object gathers together numbers used to describe size of an OpenCL work
 * and work groups. The following information is encapsulated by
 * \ref clxx::ndrange "ndrange"
 *
 * - #dimension &mdash; the number of dimensions used to specify the global
 *   work-items and work-items in a work-group; the maximum number of
 *   dimensions supported by clxx is defined by #CLXX_MAX_NDRANGE_DIMENSIONS,
 * - #global_offset &mdash; an array of #dimension unsigned values that
 *   describe the offset used to calculate the global ID of a work-item,
 * - #global_size &mdash; and array of #dimension unsigned values that describe
 *   the number of global work-items in #dimension dimensions that will execute
 *   the kernel function,
 * - #local_size &mdash; an array of #dimension unsigned values that describe
 *   the number of work-items that make up a work-group.
 *
 * The information encapsulated in \ref clxx::ndrange "ndrange"
 * is used by \ref clxx::enqueue_ndrange_kernel(command_queue const&, kernel const&, ndrange const&, events const&) "enqueue_ndrange_kernel(kernel, queue, ndrange,...)".
 * When invoking this function, particular attributes of the
 * \ref clxx::ndrange "ndrange" are passed to appropriate
 * arguments of the #enqueue_ndrange_kernel() as follows:
 *
 * - #dimension &mdash; is passed to \ref enqueue_ndrange_kernel() "work_dim",
 * - #global_offset &mdash; is passed to \ref enqueue_ndrange_kernel() "global_work_offset",
 * - #global_size &mdash; is passed to \ref enqueue_ndrange_kernel() "global_work_size",
 * - #local_size &mdash; is passed to \ref enqueue_ndrange_kernel() "local_work_size".
 *
 * All the attributes (except #dimension) are optional, that is an attribute
 * may be uninitialized or it may be set/initialized. The class provides
 * methods for checking the presence of a given attribute, and attribute
 * accessors that allow set, get or clear each attribute:
 *
 * |    attribute   |  check             |  get           |  set               |  clear               |
 * | -------------- | ------------------ | -------------- | ------------------ | -------------------- |
 * | dimension      |      n/a           | #dimension     | #set_dimension     |       n/a            |
 * | global_offset  | #has_global_offset | #global_offset | #set_global_offset | #clear_global_offset |
 * | global_size    | #has_global_size   | #global_size   | #set_global_size   | #clear_global_size   |
 * | local_size     | #has_local_size    | #local_size    | #set_local_size    | #clear_local_size   |
 *
 */ // }}}
struct ndrange
{
  /** // doc: ndrange() {{{
   * \brief Default constructor
   *
   * The default-constructed object has the following properties
   *
   * - #dimension set to 1,
   * - #global_offset is uninitialized,
   * - #global_size is uninitialized,
   * - #local_size is uninitialized.
   */ // }}}
  constexpr ndrange() noexcept
    : _dimension{1},
      _global_offset{0},
      _global_size{1},
      _local_size{1},
      _has_global_offset{false},
      _has_global_size{false},
      _has_local_size{false}
  { }
  /** // doc: ndrange() {{{
   * \brief Constructor
   *
   * Sets the attributes as with #setup() method.
   *
   * \param dimension
   *    Initial #dimension, must be <= CLXX_MAX_NDRANGE_DIMENSIONS.
   * \param global_offset
   *    A pointer to an array of \p dimension numbers to be copied to
   *    #global_offset array. If \c NULL, the #global_offset is
   *    uninitialized.
   * \param global_size
   *    A pointer to an array of \p dimension numbers to be copied to
   *    #global_size array. If \c NULL, the #global_size is
   *    uninitialized.
   * \param local_size
   *    A pointer to an array of \p dimension numbers to be copied to
   *    #local_size array. If \c NULL, the #local_size is
   *    uninitialized.
   *
   * \throw invalid_argument_error
   *    if \p dimension is greater than CLXX_MAX_NDRANGE_DIMENSIONS
   */ // }}}
  ndrange(size_t dimension, size_t const* global_offset,
                            size_t const* global_size,
                            size_t const* local_size);
  /** // doc: ndrange() {{{
   * \brief Constructor
   *
   * Sets the attributes as with #setup() method.
   *
   * \param dimension
   *    Initial #dimension, must be <= CLXX_MAX_NDRANGE_DIMENSIONS.
   * \param global_offset
   *    A vector of at least \p dimension unsigned integers to be copied to
   *    #global_offset array. If <tt>global_offset.size() == 0</tt>,
   *    the #global_offset is uninitialized.
   * \param global_size
   *    A vector of at least \p dimension unsigned integers to be copied to
   *    #global_size array. If \c NULL, the #global_size is uninitialized.
   * \param local_size
   *    A vector of at least \p dimension unsigned integers to be copied to
   *    #local_size array. If \c NULL, the #local_size is uninitialized.
   *
   * \throw invalid_argument_error
   *    if \p dimension is greater than CLXX_MAX_NDRANGE_DIMENSIONS,
   * \throw length_error
   *    if any of \p global_offset, \p global_size or \p local_size
   *    has non-zero size which is not equal to \p dimension.
   */ // }}}
  ndrange(size_t dimension, std::vector<size_t> const& global_offset,
                            std::vector<size_t> const& global_size,
                            std::vector<size_t> const& local_size);
  /** // doc: setup() {{{
   * \brief Setup all the attributes of \ref clxx::ndrange "ndrange"
   *
   * \param dimension
   *    New value for #dimension attribute, must be <= CLXX_MAX_NDRANGE_DIMENSIONS.
   * \param global_offset
   *    A pointer to an array of \p dimension unsigned integers to be copied
   *    to #global_offset array. If \p global_offset is \c NULL, the
   *    #global_offset attribute is uninitialized.
   * \param global_size
   *    A pointer to an array of \p dimension unsigned integers to be
   *    copied to #global_size array. If \p global_size is \c NULL, the
   *    #global_size attribute is uninitialized.
   * \param local_size
   *    A pointer to an array of \p dimension unsigned integers to be
   *    copied to #local_size array. If \p local_size is \c NULL, the
   *    #local_size attribute is uninitialized.
   *
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   *
   * \throw invalid_argument_error
   *    if \p dimension is greater than CLXX_MAX_NDRANGE_DIMENSIONS
   */ // }}}
  ndrange& setup(size_t dimension, size_t const* global_offset,
                                   size_t const* global_size,
                                   size_t const* local_size);
  /** // doc: setup() {{{
   * \brief Setup all the attributes of \ref clxx::ndrange "ndrange"
   *
   * \param dimension
   *    New #dimension, must be <= CLXX_MAX_NDRANGE_DIMENSIONS.
   * \param global_offset
   *    A vector of at least \p dimension unsigned integers to be copied to
   *    #global_offset array. If <tt>global_offset.size() == 0</tt>,
   *    the #global_offset is uninitialized.
   * \param global_size
   *    A vector of at least \p dimension unsigned integers to be copied to
   *    #global_size array. If \c NULL, the #global_size is uninitialized.
   * \param local_size
   *    A vector of at least \p dimension unsigned integers to be copied to
   *    #local_size array. If \c NULL, the #local_size is uninitialized.
   *
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   *
   * \throw invalid_argument_error
   *    if \p dimension is greater than CLXX_MAX_NDRANGE_DIMENSIONS,
   * \throw length_error
   *    if any of \p global_offset, \p global_size or \p local_size
   *    has non-zero size which is not equal to \p dimension.
   */ // }}}
  ndrange& setup(size_t dimension, std::vector<size_t> const& global_offset,
                                   std::vector<size_t> const& global_size,
                                   std::vector<size_t> const& local_size);
  /** // doc: set_dimension() {{{
   * \brief Set the #dimension attribute
   *
   * \param value
   *    New value of the #dimension attribute
   *
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   *
   * \throw invalid_argument_error
   *    if \p value is greater than CLXX_MAX_NDRANGE_DIMENSIONS
   */ // }}}
  ndrange& set_dimension(size_t value);
  /** // doc: set_global_offset() {{{
   * \brief Set the \p i'th element of the #global_offset array to \p value
   * \param i Which element of the #global_offset array to set
   * \param value New value of \ref global_offset(size_t) const "global_offset(i)"
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   * \throws invalid_index_error If \p i >= #dimension()
   */ // }}}
  ndrange& set_global_offset(size_t i, size_t value);
  /** // doc: set_global_size() {{{
   * \brief Set the \p i'th element of the #global_size array to \p value
   * \param i Which element of the #global_size array to set
   * \param value New value of \ref global_size(size_t) const "global_size(i)"
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   * \throws invalid_index_error If \p i >= #dimension()
   */ // }}}
  ndrange& set_global_size(size_t i, size_t value);
  /** // doc: set_local_size() {{{
   * \brief Set the \p i'th element of the #local_size array to \p value
   * \param i Which element of the #local_size array to set
   * \param value New value of \ref local_size(size_t) const "local_size(i)"
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   * \throws invalid_index_error If \p i >= #dimension()
   */ // }}}
  ndrange& set_local_size(size_t i, size_t value);
  /** // doc: clear_global_offset() {{{
   * \brief Clear the #global_offset attribute
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   */ // }}}
  ndrange& clear_global_offset() noexcept;
  /** // doc: clear_global_size() {{{
   * \brief Clear the #global_size attribute
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   */ // }}}
  ndrange& clear_global_size() noexcept;
  /** // doc: clear_local_size() {{{
   * \brief Clear the #local_size attribute
   * \returns A mutable reference to the modified \ref clxx::ndrange "ndrange" object.
   */ // }}}
  ndrange& clear_local_size() noexcept;
  /** // doc: dimension() {{{
   * \brief Return the number of dimensions of the work-group
   * \returns The number of dimension of the work-group described by this
   *          \ref clxx::ndrange "ndrange" object.
   */ // }}}
  constexpr size_t dimension() const noexcept
  { return _dimension; }
  /** // doc: has_global_offset() {{{
   * \brief Whether the #global_offset is initialized
   * \returns \c true if the #global_offset attribute is initialized or \c
   *          false if not
   */ // }}}
  constexpr bool has_global_offset() const noexcept
  { return _has_global_offset; }
  /** // doc: has_global_size() {{{
   * \brief Whether the #global_size is initialized
   * \returns \c true if the #global_size attribute is initialized or \c
   *          false if not
   */ // }}}
  constexpr bool has_global_size() const noexcept
  { return _has_global_size; }
  /** // doc: has_local_size() {{{
   * \brief Whether the #local_size is initialized
   * \returns \c true if the #local_size attribute is initialized or \c
   *          false if not
   */ // }}}
  constexpr bool has_local_size() const noexcept
  { return _has_local_size; }
  /** // doc: global_offset_ptr() {{{
   * \brief Return pointer to the #global_offset array
   * \returns Pointer to the #global_offset array if #has_global_offset() is \c
   *          true, or \c NULL if #has_global_offset() is \c false.
   */ // }}}
  constexpr size_t const* global_offset_ptr() const noexcept
  { return has_global_offset() ? _global_offset : nullptr; }
  /** // doc: global_size_ptr() {{{
   * \brief Return pointer to the #global_size array
   * \returns Pointer to the #global_size array if #has_global_size() is \c
   *          true, or \c NULL if #has_global_size() is \c false.
   */ // }}}
  constexpr size_t const* global_size_ptr() const noexcept
  { return has_global_size() ? _global_size : nullptr; }
  /** // doc: local_size_ptr() {{{
   * \brief Return pointer to the #local_size array
   * \returns Pointer to the #local_size array if #has_local_size() is \c
   *          true, or \c NULL if #has_local_size() is \c false.
   */ // }}}
  constexpr size_t const* local_size_ptr() const noexcept
  { return has_local_size() ? _local_size : nullptr; }
  /** // doc: global_offset() {{{
   * \brief Return global work offset
   *
   * Global work offset is an array of unsigned values that describes the
   * offset used to calculate the global ID of a work-item. If this attribute
   * is uninitialized, the global IDs start at offset <tt>(0,0, ..., 0)</tt>.
   *
   * \returns Global work offset
   *
   * \throw uninitialized_value_error
   *    If #has_global_offset() is \c false
   * \throw std::bad_alloc
   *    From \c std::vector's constructor
   */ // }}}
  std::vector<size_t> global_offset() const;
  /** // doc: global_size() {{{
   * \brief Return global work size
   *
   * Global work size is an array of unsigned values that describe the number
   * of global work-items in consecutive dimensions that will execute the
   * kernel function. The total number of global work-items is computed as
   * <tt>global_size()[0]*..*global_size()[dimension()-1]</tt>.
   *
   * \returns Global work size
   *
   * \throw uninitialized_value_error
   *    If #has_global_offset() is \c false
   * \throw std::bad_alloc
   *    From \c std::vector's constructor
   */ // }}}
  std::vector<size_t> global_size() const;
  /** // doc: local_size() {{{
   * \brief Returns local work size
   *
   * Local work size is an array of unsigned values that describe the number
   * of work-items that make up a work-group (also referred to as the size of
   * the work-group) that will execute a kernel. The total number of work-items
   * in a work-group is computed as <tt>local_size()[0] *...*
   * local_size()[dimension()-1]</tt>.
   *
   * \returns Local work size
   *
   * \throw uninitialized_value_error
   *    If #has_global_offset() is \c false
   * \throw std::bad_alloc
   *    From \c std::vector's constructor
   */ // }}}
  std::vector<size_t> local_size() const;
  /** // doc: global_offset() {{{
   * \brief Return i'th element of the #global_offset array
   * \param i index of the requested element in the #global_offset array
   * \returns i'th element of the #global_offset array
   * \throw uninitialized_value_error  If #has_global_offset() is \c false
   * \throw invalid_index_error If \p i >= #dimension()
   */ // }}}
  size_t global_offset(size_t i) const;
  /** // doc: global_size() {{{
   * \brief Return i'th element of the #global_size array
   * \param i index of the requested element in the #global_size array
   * \returns i'th element of the #global_size array
   * \throw uninitialized_value_error  If #has_global_size() is \c false
   * \throw invalid_index_error If \p i >= #dimension()
   */ // }}}
  size_t global_size(size_t i) const;
  /** // doc: local_size() {{{
   * \brief Return i'th element of the #local_size array
   * \param i index of the requested element in the #local_size array
   * \returns i'th element of the #local_size array
   * \throw uninitialized_value_error  If #has_local_size() is \c false
   * \throw invalid_index_error If \p i >= #dimension()
   */ // }}}
  size_t local_size(size_t i) const;
  /** // doc: cmp() {{{
   * \brief Compare this object to \p other \ref clxx::ndrange "ndrange" object
   *
   * Two \ref clxx::ndrange "ndrange" objects, \c a and \c b, are equal if and only if
   * all of the following conditions are met:
   *
   * - <tt>a.dimension() == b.dimension()</tt>,
   * - <tt>a.has_global_offset() == b.has_global_offset()</tt>,
   * - <tt>a.has_global_size() == b.has_global_size()</tt>,
   * - <tt>a.has_local_size() == b.has_local_size()</tt>,
   * - <tt>a.has_global_offset() == false</tt> or
   *   <tt>a.global_offset(i) == b.global_offset(i)</tt> for <tt>i = 0, ..., a.dimension()-1</tt>,
   * - <tt>a.has_global_size() == false</tt> or
   *   <tt>a.global_size(i) == b.global_size(i)</tt> for <tt>i = 0, ..., a.dimension()-1</tt>, and
   * - <tt>a.has_local_size() == false</tt> or
   *   <tt>a.local_size(i) == b.local_size(i)</tt> for <tt>i = 0, ..., a.dimension()-1</tt>.
   *
   * \param other Another object to be compared to this one
   * \returns \c true if \c *this is equal to \p other or \c false otherwise
   */ // }}}
  bool cmp(ndrange const& other) const noexcept;
private:
  //
  size_t  _dimension;
  size_t  _global_offset[CLXX_MAX_NDRANGE_DIMENSIONS];
  size_t  _global_size[CLXX_MAX_NDRANGE_DIMENSIONS];
  size_t  _local_size[CLXX_MAX_NDRANGE_DIMENSIONS];
  bool    _has_global_offset;
  bool    _has_global_size;
  bool    _has_local_size;
};


/** \addtogroup clxx_executing_kernels
 * @{ */
/** // doc: operator==(ndrange, ndrange) {{{
 * \brief Compare two \ref clxx::ndrange "ndrange" objects
 *
 * \param a First object,
 * \param b Second object,
 * \returns <tt>a.cmp(b)</tt>, see \ref ndrange::cmp()
 */ // }}}
inline bool operator==(ndrange const& a, ndrange const& b) noexcept
{ return a.cmp(b); }
/** // doc: operator!=(ndrange, ndrange) {{{
 * \brief Compare two \ref clxx::ndrange "ndrange" objects
 *
 * \param a First object,
 * \param b Second object,
 * \returns <tt>!a.cmp(b)</tt>, see \ref ndrange::cmp()
 */ // }}}
inline bool operator!=(ndrange const& a, ndrange const& b) noexcept
{ return !a.cmp(b); }
/* @} */
} // end namespace clxx

#endif /* CLXX_NDRANGE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
