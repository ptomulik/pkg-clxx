// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/clerror_no.hpp

/** // doc: clxx/common/clerror_no.hpp {{{
 * \file clxx/common/clerror_no.hpp
 * \brief Provides the clxx::clerror_no template class.
 */ // }}}
#ifndef CLXX_COMMON_CLERROR_NO_HPP_INCLUDED
#define CLXX_COMMON_CLERROR_NO_HPP_INCLUDED

#include <clxx/common/clerror_base.hpp>
#include <clxx/util/std_except_ctor_arg.hpp>
#include <clxx/util/clerror_stdexcept.hpp>
#include <string>

namespace clxx {

/** // doc: clerror_no {{{
 * \ingroup clxx_exceptions
 * \brief Template class for all exceptions that result from OpenCL errors.
 *
 * OpenCL functions used to return error codes whenever an error occured. The
 * %clxx wrappers turn these error codes into exceptions and throw exceptions
 * instead of returning error codes. This template is used to generate
 * exception classes based on the OpenCL error codes (status_t values
 * actually).
 *
 * \tparam Code error code as returned by an OpenCL function.
 * \tparam StdExcept standard exception base class
 * \tparam StdCtorArg determines what (extra) constructors the standard
 *         exception base class has
 *
 * **Example**:
 * \code
 *   cl_uint n;
 *   status_t s = static_cast<status_t>(clGetPlatformIDs(0,NULL,&n));
 *   if(is_error(s))
 *     {
 *       switch(s)
 *         {
 *           case status_t::invalid_value:
 *             throw clerror_no<status_t::invalid_value>();
 *           case status_t::invalid_platform:
 *             throw clerror_no<status_t::invalid_platform>();
 *           default:
 *             throw unexpected_clerror(s);
 *         }
 *     }
 * \endcode
 */ // }}}
template < status_t Code
         , class StdExcept = typename clerror_stdexcept<Code>::type
         , class StdCtorArg = typename std_except_ctor_arg<StdExcept>::type >
  struct clerror_no;
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <status_t Code, class StdExcept>
  struct clerror_no<Code, StdExcept, std_except_no_ctor_arg_tag>
    : public clerror_base<Code,StdExcept, std_except_no_ctor_arg_tag>
  {
    typedef clerror_base<Code,StdExcept, std_except_no_ctor_arg_tag> Base;
    clerror_no() : Base() { }
  };
template <status_t Code, class StdExcept>
  struct clerror_no<Code, StdExcept, std_except_xstring_ctor_arg_tag>
    : public clerror_base<Code, StdExcept, std_except_xstring_ctor_arg_tag>
  {
    typedef clerror_base<Code,StdExcept, std_except_xstring_ctor_arg_tag> Base;
    clerror_no() : Base() { }
    explicit clerror_no(std::string const& what_arg) : Base(what_arg) { }
    explicit clerror_no(char const* what_arg) : Base(what_arg) { }
  };
/** \endcond **/

} // end namespace clxx

#endif /* CLXX_COMMON_CLERROR_NO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
