// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/program_observer.hpp

/** // doc: clxx/program_observer.hpp {{{
 * \file clxx/program_observer.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PROGRAM_OBSERVER_HPP_INCLUDED
#define CLXX_PROGRAM_OBSERVER_HPP_INCLUDED

#include <clxx/types.hpp>

namespace clxx {
class program;
/** // doc: program_observer {{{
 * \todo Write documentation
 */ // }}}
class program_observer
{
public:
  /** // doc: fcn_ptr_t {{{
   * \todo Write documentation
   */ // }}}
  typedef void (CL_CALLBACK *fcn_ptr_t)(cl_program, void*);
private:
  static void CL_CALLBACK static_notify(cl_program prog, void* ptr);
protected:
  /** // doc: notify() {{{
   * \todo Write documentation
   */ // }}}
  virtual void notify(program const&) = 0;
public:
  /** // doc: ~program_observer() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~program_observer() { }
  /** // doc: fcn_ptr() {{{
   * \todo Write documentation
   */ // }}}
  virtual fcn_ptr_t fcn_ptr() const noexcept;
  /** // doc: fcn_arg() {{{
   * \todo Write documentation
   */ // }}}
  virtual void* fcn_arg() noexcept;
};
} // end namespace clxx

#endif /* CLXX_PROGRAM_OBSERVER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
