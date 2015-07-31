// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/kernel_lazy_ctor.cpp {{{
 * \file clxx/cl/kernel_lazy_ctor.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/kernel_lazy_ctor.hpp>
#include <clxx/cl/program.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
kernel_lazy_ctor::
kernel_lazy_ctor()
  : _kernel_ctor_wrapper(
      [](clxx::program const& program, std::string const& kernel_name)
          -> clxx::kernel
      { return clxx::kernel(program, kernel_name); }
    )
{ }
/* ----------------------------------------------------------------------- */
clxx::kernel kernel_lazy_ctor::
operator()(clxx::program const& program, std::string const& kernel_name) const
{
  return _kernel_ctor_wrapper(program, kernel_name);
}
/* ----------------------------------------------------------------------- */
clxx::kernel kernel_lazy_ctor::
get_memoized_kernel(clxx::program const& program, std::string const& kernel_name) const
{
  return _kernel_ctor_wrapper.get_memoized_result(program, kernel_name);
}
/* ----------------------------------------------------------------------- */
size_t kernel_lazy_ctor::
discard_memoized_kernel(clxx::program const& program, std::string const& kernel_name) const
{
  return _kernel_ctor_wrapper.discard_memoized_result(program, kernel_name);
}
/* ----------------------------------------------------------------------- */
void kernel_lazy_ctor::
discard_memoized_kernels() const
{
  return _kernel_ctor_wrapper.discard_memoized_results();
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
