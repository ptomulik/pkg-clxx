// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/std_except_ctor_arg.hpp

/** // doc: clxx/util/std_except_ctor_arg.hpp {{{
 * \file clxx/util/std_except_ctor_arg.hpp
 * \brief Defines the \ref clxx::std_except_ctor_arg "std_except_ctor_arg" meta-function
 */ // }}}
#ifndef CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED
#define CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED

#include <clxx/util/std_except_ctor_arg_fwd.hpp>
#include <stdexcept>

namespace clxx {
/** // doc: std_except_ctor_arg {{{
 * \brief Determine how to construct a given standard exception.
 *
 * There are two kinds of standard exceptions:
 *
 * - those taking a message string as an argument to constructor, and
 * - those having only the default (and copy) constructor.
 *
 * An example of exception from the first group (with mutable message) is the
 * \c std::runtime_error. An example of the later (with fixed message)
 * is the \c std::bad_alloc. One feature which distinguishes one standard
 * exceptions from others is thus the additional constructor which takes the
 * message string as an argument.
 *
 * The std_except_ctor_arg metafunction determines whether we should construct
 * given standard exception using the extra constructor taking an argument or
 * rather shall we use the default constructor. For exceptions taking an
 * argument, the metafunction returns the type of the argument we shall use.
 *
 * **Example**:
 * \code
 * #include <clxx/util/std_except_ctor_arg.hpp>
 *
 * template<class StdExcept, class CtorArg = typename std_except_ctor_arg<StdExcept>::type>
 *   struct my_except
 *    : public StdExcept
 *   {
 *     my_except(CtorArg arg) : StdExcept(arg) { }
 *     // ...
 *   };
 *
 * template < class StdExcept >
 *   struct my_except<StdExcept, std_except_no_ctor_arg_tag >
 *    : public StdExcept
 *   {
 *     my_except() : StdExcept() { }
 *     // ...
 *   };
 *
 * \endcode
 */ // }}}
template<class> struct std_except_ctor_arg;
/** // doc: std_except_no_ctor_arg_tag {{{
 * \brief A tag denoting that certain standard exception has no constructor
 *        accepting an argument other than the copy constructor.
 */ // }}}
struct std_except_no_ctor_arg_tag {};
/** // doc: std_except_xstring_ctor_arg_tag {{{
 * \brief A tag denoting that certain standard exception has constructors
 *        accepting <tt>std::string const&</tt> and <tt>const char*</tt>.
 */ // }}}
struct std_except_xstring_ctor_arg_tag {};
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< std::exception >
  { typedef std_except_no_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::bad_exception >
  { typedef std_except_no_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::logic_error >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::domain_error >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::invalid_argument >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::length_error >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::out_of_range >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::runtime_error >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::range_error >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::overflow_error >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::underflow_error >
  { typedef std_except_xstring_ctor_arg_tag type; };
template<>
struct std_except_ctor_arg< std::bad_alloc>
  { typedef std_except_no_ctor_arg_tag type; };
/** \endcond */
} // end namespace clxx

#endif /* CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
