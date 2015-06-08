// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/std/bad_alloc.li.i {{{
 * \file clxx/std/bad_alloc.li.i
 * \todo Write documentation
 */ // }}}

%import <clxx/std/exception.i> // we use ::std::exception
%{
#include <clxx/std/exception.i.hpp>
%}

%{
#include <new>
%}
%exceptionclass std::bad_alloc;
namespace std {
  class bad_alloc : public ::std::exception
  {
  public:
    bad_alloc() throw() { }
    virtual ~bad_alloc() throw();
    virtual const char* what() const throw();
  };
} // namespace std

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
