// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/mem.hpp

/** // doc: clxx/mem.hpp {{{
 * \file clxx/mem.hpp
 * \brief Declares the \ref clxx::mem "mem" class
 */ // }}}
#ifndef CLXX_MEM_HPP_INCLUDED
#define CLXX_MEM_HPP_INCLUDED

#include <clxx/mem_fwd.hpp>
#include <clxx/context_fwd.hpp>
#include <clxx/types.hpp>
#include <clxx/cl/cl.h>
#include <clxx/clobj.hpp>

namespace clxx {
/** // doc: mem {{{
 * \ingroup clxx_buffer_objects
 * \brief Encapsulates an OpenCL memory object
 *
 * This class represents OpenCL memory object (e.g. buffer or image) and
 * forwards basic operations on memory objects to OpenCL. It encapsulates a
 * \c cl_mem identifier and supports following operations:
 *
 * - memory object creation (constructors),
 * - automatic reference count management by using internally
 *   \ref retain_mem_object() and \ref release_mem_object(),
 * - retrieving mem information from OpenCL (via class methods), by
 *   invoking internally \ref get_mem_object_info() and \ref get_image_info().
 *
 * Although \ref clxx::mem "mem" maintains internally reference count
 * for its \c cl_mem handle, it doesn't prevent one from stealing the
 * \c cl_mem handle (#get(), #chk_get()). This gives rise to manipulate the
 * reference count outside of the \ref clxx::mem object for the given OpenCL
 * memory object. If you need to steal, use the retrieved handle with care. If
 * you retrieve the handle from \ref clxx::mem "mem" object, increase its
 * reference count with \ref clxx::retain_mem_object() "retain_mem_object()"
 * as soon as possible, and decrease the reference count with
 * \ref clxx::release_mem_object() "release_mem_object()" once you don't need
 * the handle. If you don't retain the mem, it may be unexpectedly released by
 * \ref clxx::mem "mem's"  destructor, assignment operator or the #assign()
 * method.
 *
 * There are constructors which create new OpenCL memory object (a costly
 * operation). However, assignment operator and copy constructors just copy
 * over the \c cl_mem handle and maintain reference count appropriately. To
 * verify if two \ref clxx::mem "mem" objects refer to the same OpenCL
 * mem, use \c == operator (of \c != operator).
 *
 * An OpenCL memory object (identified by \c cl_mem handle) is not released
 * until there is at least one \ref clxx::mem "mem" object
 * encapsulating its handle. On the other hand - the mem may get released
 * by OpenCL when last \ref clxx::mem "mem" object gets deleted (the
 * ~mem() destructor decreases reference count for its \c cl_mem
 * handle with \ref clxx::release_mem_object() "release_mem_object()") or when
 * the last object gets assigned another OpenCL memory object (assignment
 * operator or the #assign() method).
 */ // }}}
class alignas(cl_mem) mem
  : public clobj<cl_mem>
{
public:
  /** // doc: Base {{{
   * \brief Typedef for the base class type
   */ // }}}
  typedef clobj<cl_mem> Base;
  using Base::Base;
  /** // doc: mem() {{{
   * \brief Default constructor, see \ref clobj::clobj()
   */ // }}}
  mem() = default;
  /** // doc: mem() {{{
   * \brief Copy constructor, see \ref clobj::clobj(clobj const&)
   */ // }}}
  mem(mem const&) = default;
  /** // doc: mem(context const&, mem_flags_t, size_t, void*) {{{
   * \brief Constructor
   *
   * Creates new OpenCL buffer via #create_buffer().
   *
   * \param ctx
   *    A valid #context object used to create the buffer object. 
   * \param flags
   *    A bit-field that is used to specify allocation and usage information
   *    such as the memory arena that should be used to allocate the buffer
   *    object and how it will be used.
   * \param size
   *    The size in bytes of the buffer memory object to be allocated.
   * \param host_ptr
   *    A pointer to the buffer data that may already be allocated by the
   *    application. The size of the buffer that \p host_ptr points to must be
   *    >= \p size bytes.
   *
   * \throw uninitialized_context_error
   *    If the \p ctx is uninitialized
   *
   * Also throws exceptions originating from #create_buffer().
   */ // }}}
  explicit mem(context const& ctx, mem_flags_t flags, size_t size, void* host_ptr);
  /** // doc: get_type() {{{
   * \brief Returns the memory object type
   *
   * \returns An enum value indicating the type of the memory object, may it
   *          be, for example, mem_object_type_t::buffer or
   *          mem_object_type_t::image2d.
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  mem_object_type_t get_type() const;
  /** // doc: get_flags() {{{
   * \brief Returns the \e flags argument value specified when this #mem object
   *        is created
   *
   * \returns An bit-field indicating the flags used at creation time
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  mem_flags_t get_flags() const;
  /** // doc: get_size() {{{
   * \brief Return actual size of the data store associated with this memory
   *        object in bytes
   * \returns actual size of the data store associated with this memory object
   *          in bytes
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  size_t get_size() const;
  /** // doc: get_host_ptr() {{{
   * \brief Return host pointer
   *
   *  If the underlying memory object is created with #create_buffer() or
   *  #create_image() and \c mem_flags_t::use_host_ptr is specified in
   *  \e mem_flags, return the \e host_ptr argument value specified when memobj
   *  is created. Otherwise a \c NULL value is returned.
   *
   *  If memobj is created with #create_sub_buffer(), return the \e host_ptr +
   *  \e origin value specified when memobj is created. \e host_ptr is the
   *  argument value specified to #create_buffer() and
   *  mem_flags_t::use_host_ptr is specified in \e mem_flags for memory object
   *  from which memobj is created. Otherwise a \c NULL value is returned
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  void* get_host_ptr() const;
  /** // doc: get_map_count() {{{
   * \brief Returns map count
   *
   * The map count returned should be considered immediately stale. It is
   * unsuitable for general use in applications. This feature is provided for
   * debugging.
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  cl_uint get_map_count() const;
  /** // doc: get_context() {{{
   * \brief Return context specified when memory object is created
   *
   * If the #mem object is created with #create_sub_buffer(), the context
   * associated with the memory object specified as the \e buffer argument to
   * create_sub_buffer() is returned. 
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  context get_context() const;
#if CLXX_CL_H_VERSION_1_1
  /** // doc: get_associated_memobject() {{{
   * \brief Return memory object from which this #mem object is created
   *
   * This returns the memory object specified as buffer argument to
   * #create_buffer() if memobj is a sub-buffer object created using
   * #create_sub_buffer().
   *
   * This returns the \e mem_object specified in \c cl_image_desc if #mem
   * object is an image object.
   *
   * Otherwise a \c NULL value is returned
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  mem get_associated_memobject() const;
  /** // doc: get_offset() {{{
   * \brief Return offset if the #mem object is a sub-buffer created using #create_sub_buffer() 
   *
   * This returns 0 if memobj is not a subbuffer object
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  size_t get_offset() const;
#endif
#if CLXX_CL_H_VERSION_2_0
  /** // doc: get_uses_svm_pointer() {{{
   * \brief Whether the #mem object was created with mem_flags_t::use_host_ptr
   *
   * Return \c CL_TRUE if #mem object is a buffer object that was created with
   * mem_flags_t::use_host_ptr or is a sub-buffer object of a buffer object
   * that was created with mem_flags_t::use_host_ptr and the \e host_ptr
   * specified when the \e buffer object was created is a SVM pointer;
   * otherwise returns \c CL_FALSE. 
   *
   * \throw uninitialized_mem_error
   *    If the #mem object (this) is uninitialized
   *
   * Also throws exceptions originating from #get_mem_object_info()
   */ // }}}
  cl_bool get_uses_svm_pointer() const;
#endif
};
} // end namespace clxx

#endif /* CLXX_MEM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
