// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/util/std_except_ctor_arg.hpp

/** // doc: clxx/util/std_except_ctor_arg.hpp {{{
 * \file clxx/util/std_except_ctor_arg.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED
#define CLXX_UTIL_STD_EXCEPT_CTOR_ARG_HPP_INCLUDED

#include <stdexcept>
#include <clxx/util/std_except_ctor_arg_fwd.hpp>

namespace clxx {
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
