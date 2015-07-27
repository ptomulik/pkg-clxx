// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/kernel_lazy_constructor.cpp {{{
 * \file clxx/cl/kernel_lazy_constructor.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/kernel_lazy_constructor.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
kernel_lazy_constructor::
kernel_lazy_constructor()
  : _lazy_kernel_ctor(
      [](clxx::program const& program, std::string const& name)
          -> clxx::kernel { return clxx::kernel(program, name); }
    )
{ }
/* ----------------------------------------------------------------------- */
clxx::kernel kernel_lazy_constructor::
operator()(clxx::program const& program, std::string const& name) const
{
  return _lazy_kernel_ctor(program, name);
}
/* ----------------------------------------------------------------------- */
size_t kernel_lazy_constructor::
discard_cached_kernel(clxx::program const& program, std::string const& name) const
{
  return _lazy_kernel_ctor.discard_cached_result(program, name);
}
/* ----------------------------------------------------------------------- */
void kernel_lazy_constructor::
discard_cached_kernels() const
{
  return _lazy_kernel_ctor.discard_cached_results();
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
