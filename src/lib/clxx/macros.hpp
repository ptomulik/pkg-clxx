// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/macros.hpp

/** // doc: clxx/macros.hpp {{{
 * \file clxx/macros.hpp
 * \brief Several macros commonly used across the CLXX library.
 *
 * This file implements several macros used across the library. Currently
 * defined macros include:
 *
 * - macros which "enhance" strongly typed enums by implementing additional
 *   functions to operate on the selected enums or overloading standard
 *   operators,
 */ // }}}
#ifndef CLXX_MACROS_HPP_INCLUDED
#define CLXX_MACROS_HPP_INCLUDED

#include <clxx/config.hpp>

//#if defined(SWIG) && CLXX_SWIG_NO_CLASS_ENUM_BITOPS
//# define CLXX_DEFINE_ENUM_BITOPS(__t, __ut)
//#else
/** // doc: CLXX_DEFINE_ENUM_BITOPS {{{
 * \brief Overload bitwise operators for an (enum) type.
 *
 * The macro defines all the bitwise operators necessary for a given (enum)
 * type to behave as a bitmask. The macro implementation follows guidelines
 * given in the \c 17.5.2.1.3 of
 * <a href="https://isocpp.org/files/papers/N3690.pdf">C++11 standard draft (N3690)</a>.
 *
 * \param [in] __t enum type,
 * \param [in] __ut underlying type.
 *
 * \note Do not put a semicolon \c ; after the macro.
 * \note Put the macro in an appropriate namespace.
 *
 * **Example**:
 *
 * \code
 * enum class flags_t : int
 *   {
 *     f1 = 1,
 *     f2 = 2,
 *     f3 = 4
 *   };
 * CLXX_DEFINE_ENUM_BITOPS(flags_t, int)
 *
 * flags_t f = flags_t::f1 | flags_t::f3;
 * \endcode
 *
 * \see CLXX_MAKE_BITMASK_ENUM
 * \hideinitializer
 */ // }}}
# define CLXX_DEFINE_ENUM_BITOPS(__t, __ut) \
  constexpr __t operator&(__t x, __t y) noexcept \
  { return static_cast<__t>(static_cast<__ut>(x) & static_cast<__ut>(y)); } \
  constexpr __t operator|(__t x, __t y) noexcept \
  { return static_cast<__t>(static_cast<__ut>(x) | static_cast<__ut>(y)); } \
  constexpr __t operator^(__t x, __t y) noexcept \
  { return static_cast<__t>(static_cast<__ut>(x) ^ static_cast<__ut>(y)); } \
  constexpr __t operator~(__t x) noexcept \
  { return static_cast<__t>(~static_cast<__ut>(x)); } \
  inline __t& operator&=(__t& x, __t y) noexcept \
  { x = x & y; return x; } \
  inline __t& operator|=(__t& x, __t y) noexcept \
  { x = x | y; return x; } \
  inline __t& operator^=(__t& x, __t y) noexcept \
  { x = x ^ y; return x; }
//#endif

#if defined(SWIG) && CLXX_SWIG_NO_CLASS_ENUM_BOOLVAL
# define CLXX_DEFINE_ENUM_BOOLVAL(__t, __ut)
#else
/** // doc: CLXX_DEFINE_ENUM_BOOLVAL {{{
 * \brief Define functions that convert an enum to a boolean value.
 *
 * This macro defines for a given type \b __t a function named \c boolval(),
 * which converts an enum to a boolean value.
 *
 * \param [in] __t enum type,
 * \param [in] __ut underlying type.
 *
 * \note Do not put a semicolon \c ; after the macro.
 * \note Put the macro in an appropriate namespace.
 *
 * **Example**:
 * \code
 * enum class flags_t : int
 *   {
 *     f0 = 0,
 *     f1 = 1,
 *     f2 = 2,
 *     f3 = 4
 *   };
 * CLXX_DEFINE_ENUM_BOOLVAL(flags_t, int)
 *
 * flags_t f;
 * // ...
 * if(boolval(f))
 *   {
 *     // ...
 *   }
 * \endcode
 *
 * \see CLXX_MAKE_BITMASK_ENUM
 * \hideinitializer
 */ // }}}
# define CLXX_DEFINE_ENUM_BOOLVAL(__t, __ut) \
  constexpr bool boolval(__t x) noexcept \
  { return static_cast<bool>(x); }
#endif

#if defined(SWIG) && CLXX_SWIG_NO_CLASS_ENUM_INTVAL
# define CLXX_DEFINE_ENUM_INTVAL(__t, __ut)
#else
/** // doc: CLXX_DEFINE_ENUM_INTVAL {{{
 * \brief Define functions converting an enum to its underlying integer.
 *
 * This macro defines for a given type \b __t a function named \c intval(),
 * which converts a value of an enumerated integer to its underlying integer.
 *
 * \param [in] __t enum type,
 * \param [in] __ut underlying type.
 *
 * \note Do not put a semicolon \c ; after the macro.
 * \note Put the macro in an appropriate namespace.
 *
 * **Example**:
 * \code
 * enum class flags_t : int
 *   {
 *     f0 = 0,
 *     f1 = 1,
 *     f2 = 2,
 *     f3 = 4
 *   };
 * CLXX_DEFINE_ENUM_INTVAL(flags_t, int)
 *
 * int x = intval(flags_t::f2)
 * \endcode
 *
 * \see CLXX_MAKE_BITMASK_ENUM
 * \hideinitializer
 */ // }}}
# define CLXX_DEFINE_ENUM_INTVAL(__t, __ut) \
  constexpr __ut intval(__t x) noexcept \
  { return static_cast<__ut>(x); }
#endif

/** // doc: CLXX_MAKE_BITMASK_ENUM {{{
 * \brief Implement bitmask operations for a strongly typed enum.
 *
 * For given enum type \b __t a set of bitwise operators as well as additional
 * functions is implemented, such that most of the standard bitwise operations
 * gets available. Particularly, this macro invokes:
 *
 * - CLXX_DEFINE_ENUM_BITOPS,
 * - CLXX_DEFINE_ENUM_BOOLVAL,
 * - CLXX_DEFINE_ENUM_INTVAL,
 *
 * \param [in] __t enum type,
 * \param [in] __ut underlying type.
 *
 * \note Do not put a semicolon \c ; after the macro.
 * \note Put the macro in an appropriate namespace.
 *
 * **Example**:
 * \code
 * enum class flags_t : int
 *   {
 *     f0 = 0,
 *     f1 = 1,
 *     f2 = 2,
 *     f3 = 4
 *   };
 * CLXX_MAKE_BITMASK_ENUM(flags_t, int)
 *
 * int x = intval(flags_t::f1 | flags_t::f2)
 * x |= flags_t::f3;
 * x &= ~flags_t::f1;
 *
 * if(boolval(x))
 *   {
 *     int y = intval(x);
 *     // ...
 *   }
 * \endcode
 *
 * \hideinitializer
 */ // }}}
#define CLXX_MAKE_BITMASK_ENUM(__t, __ut) \
  CLXX_DEFINE_ENUM_BITOPS(__t, __ut) \
  CLXX_DEFINE_ENUM_BOOLVAL(__t, __ut) \
  CLXX_DEFINE_ENUM_INTVAL(__t, __ut)

/** // doc: CLXX_MAKE_INTEGER_ENUM {{{
 * \brief Implement functions for converting a strongly typed enum to its
 * underlying integer and to bool
 *
 * For given enum type \b __t functions are implemented which convert the enum
 * values to underlying integer type and to bool. Particularly, this macro
 * invokes:
 *
 * - CLXX_DEFINE_ENUM_INTVAL,
 * - CLXX_DEFINE_ENUM_BOOLVAL.
 *
 * \param [in] __t enum type,
 * \param [in] __ut underlying type.
 *
 * \note Do not put a semicolon \c ; after the macro.
 * \note Put the macro in an appropriate namespace.
 *
 * **Example**:
 * \code
 * enum class flags_t : int
 *   {
 *     f0 = 0,
 *     f1 = 1,
 *     f2 = 2,
 *     f3 = 4
 *   };
 * CLXX_MAKE_INTEGER_ENUM(flags_t, int)
 *
 * int x = intval(flags_t::f1 | flags_t::f2)
 * if(boolval(x))
 *   {
 *     // ...
 *   }
 * \endcode
 *
 * \hideinitializer
 */ // }}}
#define CLXX_MAKE_INTEGER_ENUM(__t, __ut) \
  CLXX_DEFINE_ENUM_BOOLVAL(__t, __ut) \
  CLXX_DEFINE_ENUM_INTVAL(__t, __ut)

#endif /* CLXX_MACROS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
