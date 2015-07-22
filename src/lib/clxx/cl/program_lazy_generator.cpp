// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_lazy_generator.cpp {{{
 * \file clxx/cl/program_lazy_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_lazy_generator.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
clxx::program program_lazy_generator::
get_program(clxx::context const& context) const
{
  // To be thread-safe we have to protect mutable member(s) in const functions,
  // otherwise user may be surprised. The std::lock_guard is exception-safe.
  try {
    std::lock_guard<std::mutex> lock(this->_programs_mutex);
    return _programs.at(context);
  } catch(std::out_of_range const&) {
    clxx::program const& p = this->program_generator::get_program(context);
    std::lock_guard<std::mutex> lock(this->_programs_mutex);
    return _programs[context] = p;
  }
  // _programs_mutex is automatically released when lock goes out of scope
}
/* ----------------------------------------------------------------------- */
size_t program_lazy_generator::
forget_memoized_program(clxx::context const& context) const
{
  // To be thread-safe we have to protect mutable member(s) in const functions,
  // otherwise user may be surprised. The std::lock_guard is exception-safe.
  std::lock_guard<std::mutex> lock(this->_programs_mutex);
  return _programs.erase(context);
  // _programs_mutex is automatically released when lock goes out of scope
}
/* ----------------------------------------------------------------------- */
void program_lazy_generator::
forget_memoized_programs() const
{
  // To be thread-safe we have to protect mutable member(s) in const functions,
  // otherwise user may be surprised. The std::lock_guard is exception-safe.
  std::lock_guard<std::mutex> lock(this->_programs_mutex);
  _programs.clear();
  // _programs_mutex is automatically released when lock goes out of scope
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
