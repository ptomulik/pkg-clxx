// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/kernel_lazy_ctor.hpp

/** // doc: clxx/cl/kernel_lazy_ctor.hpp {{{
 * \file clxx/cl/kernel_lazy_ctor.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_KERNEL_LAZY_CTOR_HPP_INCLUDED
#define CLXX_CL_KERNEL_LAZY_CTOR_HPP_INCLUDED
#include <clxx/common/memoized_function.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/cl/kernel.hpp>
#include <string>

namespace clxx {
/** // doc: kernel_lazy_ctor {{{
 * \brief Memoized \ref clxx::kernel "kernel" constructor
 *
 * This is a callable object. When invoked for the first time with given
 * parameters, creates and memoizes a \ref clxx::kernel "kernel" object. Each
 * subsequent invocation with the same parameters returns the memoized
 * \ref clxx::kernel "kernel". The cache used for memoization may be
 * manipulated with #discard_memoized_kernel() and #discard_memoized_kernels().
 *
 * \par Example
 *
 * \snippet clxx/cl/kernel_lazy_ctor1.cpp Program
 *
 * \par Output
 *
 * \snippet clxx/cl/kernel_lazy_ctor1.cpp Output
 */ // }}}
class kernel_lazy_ctor
{
private:
  typedef clxx::kernel orig_kernel_ctor_t(clxx::program const&, std::string const&);
  typedef clxx::memoized_function<orig_kernel_ctor_t> kernel_ctor_wrapper_t;
  kernel_ctor_wrapper_t _kernel_ctor_wrapper;
public:
  /** // doc: kernel_lazy_ctor() {{{
   * \brief Default constructor
   */ // }}}
  kernel_lazy_ctor();
  /** // doc: ~kernel_lazy_ctor() {{{
   * \brief Destructor
   */ // }}}
  virtual ~kernel_lazy_ctor() {}
  /** // doc: get_kernel(program, name) {{{
   * \brief Call operator
   *
   * Implements the memoized construction of \ref clxx::kernel "kenel" objects.
   * When called for the first time with given \p program and \p kernel_name
   * it creates and memoizes new \ref clxx::kernel "kernel" object. The object
   * is created with the \ref clxx::kernel::kernel(clxx::program const&, std::string const&)
   * constructor. Each subsequent call just returns the memoized
   * \ref clxx::kernel "kernel" object, until it's discarded with
   * #discard_memoized_kernel() or #discard_memoized_kernels.
   *
   * \param program
   *    A \ref clxx::program "program" object with a successfully built executable,
   * \param kernel_name
   *    A function name in the program declared with the \c __kernel qualifier.
   * \returns
   *    The memoized \ref clxx::kernel "kernel" object with the given \p
   *    program and \p kernel_name.
   */ // }}}
  virtual clxx::kernel operator()(clxx::program const& program,
                                  std::string const& kernel_name) const;
  /** // doc: get_memoized_kernel() {{{
   * \brief Returns memoized kernel
   *
   * The method returns reference to the kernel memoized for the given
   * arguments (\p program and \p kernel_name). If the kernel has not
   * been memoized yet, the method throws
   * \ref clxx::invalid_key_error "invalid_key_error".
   *
   * \param program
   *    A \ref clxx::program "program" object which contained the kernel,
   * \param kernel_name
   *    A kernel name that is to be returned.
   * \returns
   *    Const reference to the requested memoized kernel.
   * \throws clxx::invalid_key_error
   *    If there is no kernel memoized for the given arguments.
   *
   * It may also throw other exceptions originating from 
   */ // }}}
  clxx::kernel get_memoized_kernel(clxx::program const& program,
                                   std::string const& kernel_name) const;
  /** // doc: discard_memoized_kernel(program, kernel) {{{
   * \brief Discard memoized kernel
   *
   * \param program
   *    A \ref clxx::program "program" object which contained the kernel,
   * \param kernel_name
   *    A kernel name that is to be removed from memoizer cache
   * \returns
   *    Number of kernels discarded from cache, which may be either 0 or 1.
   */ // }}}
  size_t discard_memoized_kernel(clxx::program const& program,
                                 std::string const& kernel_name) const;
  /** // doc: discard_memoized_kernels() {{{
   * \brief Discard all memoized kernels
   */ // }}}
  void discard_memoized_kernels() const;
};
} // end namespace clxx
#endif /* CLXX_CL_KERNEL_LAZY_CTOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
