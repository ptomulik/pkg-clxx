// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/kernel_lazy_constructor.hpp

/** // doc: clxx/cl/kernel_lazy_constructor.hpp {{{
 * \file clxx/cl/kernel_lazy_constructor.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_KERNEL_LAZY_CONSTRUCTOR_HPP_INCLUDED
#define CLXX_CL_KERNEL_LAZY_CONSTRUCTOR_HPP_INCLUDED
#include <clxx/common/memoized_function.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/kernel.hpp>
#include <string>

namespace clxx {
/** // doc: kernel_lazy_constructor {{{
 * \brief Lazy constructor for OpenCL kernels
 *
 * This is a callable object. When invoked for the first time with given
 * parameters, creates and caches a \ref clxx::kernel "kernel" object. Each
 * subsequent invocation with the same parameters returns the cached
 * \ref clxx::kernel "kernel".
 *
 * \par Example
 *
 * \snippet clxx/cl/kernel_lazy_constructor1.cpp Program
 *
 * \par Output
 *
 * \snippet clxx/cl/kernel_lazy_constructor1.cpp Output
 */ // }}}
class kernel_lazy_constructor
{
private:
  typedef clxx::memoized_function<clxx::kernel(clxx::program const&, std::string const&)> lazy_kernel_ctor_t;
  lazy_kernel_ctor_t _lazy_kernel_ctor;
public:
  /** // doc: kernel_lazy_constructor() {{{
   * \todo Write documentation
   */ // }}}
  kernel_lazy_constructor();
  /** // doc: ~kernel_lazy_constructor() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~kernel_lazy_constructor() {}
  /** // doc: get_kernel(program, name) {{{
   * \todo Write documentation
   */ // }}}
  virtual clxx::kernel operator()(clxx::program const& program, std::string const& name) const;
  /** // doc: discard_cached_kernel(program, kernel) {{{
   * \todo Write documentation
   */ // }}}
  size_t discard_cached_kernel(clxx::program const& program, std::string const& name) const;
  /** // doc: discard_cached_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void discard_cached_kernels() const;
};
} // end namespace clxx
#endif /* CLXX_CL_KERNEL_LAZY_CONSTRUCTOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
