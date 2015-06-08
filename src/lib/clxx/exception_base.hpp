// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/exception_base.hpp

/** // doc: clxx/exception_base.hpp {{{
 * \file clxx/exception_base.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_EXCEPTION_BASE_HPP_INCLUDED
#define CLXX_EXCEPTION_BASE_HPP_INCLUDED

#include <clxx/exception.hpp>
#include <clxx/util/std_except_ctor_arg.hpp>
#include <string>

namespace clxx {

/** \ingroup clxx_exceptions */
/** @{ */
/** // doc: exception_base {{{
 * \brief Template to generate clxx exceptions.
 *
 * \tparam ClxxExcept clxx base class for the exception, usually
 *         clxx::exception or clxx::clerror,
 * \tparam StdExcept standard base class for the exception, e.g.
 *         \c std::runtime_error,
 * \tparam StdCtorArg type of argument that should be passed to the
 *         \c StdExcept constructor. For most standard exceptions sane defaults
 *         are provided.
 *
 * This class is designed to be used as a base for particular clxx exceptions.
 * The main purpose is to ensure, that each new exception inherits two
 * exception base classes (clxx::exception and one standard class) and
 * implements the clxx2std() method. The template provides default
 * implementation of the clxx2std() method.
 *
 * The **StdCtorArg** should be set to std_except_no_ctor_arg_tag for standard
 * exceptions having only default constructors (without arguments), such as
 * \c std::bad_alloc.
 *
 * The basic usage is the following:
 * 1. Include necessary headers:
 *
 *    \snippet exception3.cpp Includes
 *
 * 2. Define new exception class, for example a class based on clxx::exception
 *    and std::runtime_error:
 *
 *    \snippet exception3.cpp ExceptionDefinition
 *
 *    Some standard exceptions, such as \c std::bad_alloc, use hard-coded
 *    exception message and have only default constructor. In these cases, one
 *    has to implement the \c what() method instead of providing a default
 *    message to the constructor:
 *
 *    \snippet exception4.cpp ExceptionDefinition
 */ // }}}
template < class ClxxExcept
         , class StdExcept
         , class StdCtorArg = typename std_except_ctor_arg<StdExcept>::type >
  struct exception_base
      : public ClxxExcept,
        public StdExcept
  {
    /** // doc: exception_base(StdCtorArg const&) {{{
     * \brief Initializing constructor
     *
     * Initializes the underlying standard exception **StdExcept** with a
     * value of argument **arg**.
     *
     * \param arg a value used to initialize the underlying standard exception.
     */ // }}}
    explicit exception_base(StdCtorArg arg)
      : ClxxExcept(), StdExcept(arg) { }
    /** // doc: clxx2std() const {{{
     * \brief Default implementation of the clxx2std() method.
     *
     * \returns a reference to the underlying standard exception.
     */ // }}}
    virtual std::exception const& clxx2std() const noexcept { return *this; }
    /** // doc: ~exception_base() {{{
     * \brief Destructor
     */ // }}}
    virtual ~exception_base() noexcept {}
  };

/** // doc: exception_base {{{
 * \brief Template to generate clxx exceptions.
 *
 * \tparam ClxxExcept clxx base class for the exception, usually
 *         clxx::exception or clxx::clerror,
 * \tparam StdExcept standard base class for the exception, e.g.
 *         \c std::runtime_error,
 * \tparam StdCtorArg type of argument that should be passed to the
 *         \c StdExcept constructor. For most standard exceptions sane defaults
 *         are provided.
 *
 * This class is designed to be used as a base for particular clxx exceptions.
 * The main purpose is to ensure, that each new exception inherits two
 * exception base classes (clxx::exception and one standard class) and
 * implements the clxx2std() method. The template provides default
 * implementation of the clxx2std() method.
 *
 * The **StdCtorArg** should be set to std_except_no_ctor_arg_tag for standard
 * exceptions having only default constructors (without arguments), such as
 * \c std::bad_alloc.
 *
 * The basic usage is the following:
 * 1. Include necessary headers:
 *
 *    \snippet exception3.cpp Includes
 *
 * 2. Define new exception class, for example a class based on clxx::exception
 *    and std::runtime_error:
 *
 *    \snippet exception3.cpp ExceptionDefinition
 *
 *    Some standard exceptions, such as \c std::bad_alloc, use hard-coded
 *    exception message and have only default constructor. In these cases, one
 *    has to implement the \c what() method instead of providing a default
 *    message to the constructor:
 *
 *    \snippet exception4.cpp ExceptionDefinition
 */ // }}}
template < class ClxxExcept
         , class StdExcept>
  struct exception_base<ClxxExcept, StdExcept, std_except_xstring_ctor_arg_tag>
      : public ClxxExcept,
        public StdExcept
  {
    /** // doc: exception_base(StdCtorArg const&) {{{
     * \brief Initializing constructor
     *
     * Initializes the underlying standard exception **StdExcept** with a
     * value of argument **arg**.
     *
     * \param arg a value used to initialize the underlying standard exception.
     */ // }}}
    explicit exception_base(const std::string& arg)
      : ClxxExcept(), StdExcept(arg) { }
    /** // doc: exception_base(StdCtorArg const&) {{{
     * \brief Initializing constructor
     *
     * Initializes the underlying standard exception **StdExcept** with a
     * value of argument **arg**.
     *
     * \param arg a value used to initialize the underlying standard exception.
     */ // }}}
    explicit exception_base(const char* arg)
      : ClxxExcept(), StdExcept(arg) { }
    /** // doc: clxx2std() const {{{
     * \brief Default implementation of the clxx2std() method.
     *
     * \returns a reference to the underlying standard exception.
     */ // }}}
    virtual std::exception const& clxx2std() const noexcept { return *this; }
    /** // doc: ~exception_base() {{{
     * \brief Destructor
     */ // }}}
    virtual ~exception_base() noexcept {}
  };

/** // doc: exception_base<StdExcept, std_except_no_ctor_arg_tag> {{{
 * \brief Partial specialization of clxx::exception_base.
 *
 * This is partial specialization of clxx::exception_base for cases when the
 * **StdExcept** hard-codes its exception message. More generally, it's for
 * such cases where **StdExcept** has only default constructor (without an
 * argument).
 */ // }}}
template <class ClxxExcept, class StdExcept>
  struct exception_base<ClxxExcept, StdExcept, std_except_no_ctor_arg_tag>
    : public ClxxExcept,
      public StdExcept
  {
    /** // doc: clxx2std() const {{{
     * \brief Default implementation of the clxx2std() method.
     *
     * \returns a reference to the underlying standard exception.
     */ // }}}
    virtual std::exception const& clxx2std() const noexcept { return *this; }
    /** // doc: ~exception_base() {{{
     * \brief Destructor
     */ // }}}
    virtual ~exception_base() noexcept {}
  };
/** @} */

} // end namespace clxx

#endif /* CLXX_EXCEPTION_BASE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
