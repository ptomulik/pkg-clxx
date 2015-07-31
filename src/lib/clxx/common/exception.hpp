// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/exception.hpp

/** // doc: clxx/common/exception.hpp {{{
 * \file clxx/common/exception.hpp
 * \brief Provides the clxx::exception class.
 */ // }}}
#ifndef CLXX_COMMON_EXCEPTION_HPP_INCLUDED
#define CLXX_COMMON_EXCEPTION_HPP_INCLUDED

#include <exception>

namespace clxx {

/** // doc: exception {{{
 * \ingroup clxx_exceptions
 * \brief Base class for all clxx exceptions.
 *
 * By design, all the clxx exceptions derive from clxx::exception class and
 * from one of the standard exceptions. The clxx2std() member method may be
 * used to access the underlying standard exception.
 *
 * A basic pattern for deriving new exception is to:
 *
 * 1. Include necessary headers:
 *
 *    \snippet clxx/common/exception1.cpp Includes
 *
 * 2. Define custom exception class which derives from both, the
 *    clxx::exception and a standard exception (for example
 *    \c std::runtime_error):
 *
 *    \snippet clxx/common/exception1.cpp ExceptionDefinition
 *
 *    The new exception must implement the clxx2std() member method. The
 *    exception message is passed as an argument to \c std::runtime_error
 *    constructor. Some of the standard exceptions, such as \c std::bad_alloc,
 *    return hard-coded messages, and have no constructors that would allow to
 *    store the message. For these classes we have to use default constructor
 *    for object creation and implement the member method \c what() as in the
 *    following snippet
 *
 *    \snippet clxx/common/exception2.cpp ExceptionDefinition
 *
 *    The above snippets are provided only to explain some basic concepts. As
 *    it can be seen, there is some code repetition (clxx2std() implementation
 *    is almost always the same). In practice, one shall rather use the
 *    clxx::exception_base template (instead of deriving directly from
 *    clxx::exception) to avoid the code bloat.
 *
 * 3. From now on, the new exception may be caught in a several ways:
 *    - as the new clxx::exception1 object:
 *
 *      \snippet clxx/common/exception1.cpp CatchClxxException1
 *
 *    - as a clxx::exception:
 *
 *      \snippet clxx/common/exception1.cpp CatchClxxException
 *
 *    - as a std::runtime_error
 *
 *      \snippet clxx/common/exception1.cpp CatchStdRuntimeError
 *
 *    - as a std::exception:
 *
 *      \snippet clxx/common/exception1.cpp CatchStdException
 *
 *    - you may also catch exceptions "by priority", starting from most
 *      particular ones and falling-back to more generic ones:
 *
 *      \snippet clxx/common/exception1.cpp CatchHierarchy
 *
 *      In the above case, the first catch clause is executed.
 */ // }}}
struct exception
  {
    /** // doc: clxx2std() const {{{
     * \brief Return reference to underlying standard exception.
     *
     * By design, all the exception defined by clxx derive from clxx::exception
     * and from \c std::exception. This method shall perform a safe cast and
     * return a reference to the underlying standard exception.
     *
     * \return reference to underlying standard exception.
     *
     * \note This method must be implemented in a derived class.
     */ // }}}
    virtual std::exception const& clxx2std() const noexcept = 0;
    /** // doc: clxx2std() {{{
     * \brief Non-const version of the method.
     *
     * \note This default implementation performs all necessary const casts.
     *       It's not necessary to implement the non-const version in derived
     *       classes, as it comes for free here.
     */ // }}}
    virtual std::exception& clxx2std() noexcept
    {
      return const_cast<std::exception&>(
          const_cast<exception const*>(this)->clxx2std()
      );
    }
    /** // doc: ~exception() {{{
     * \brief Destructor
     */ // }}}
    virtual ~exception() noexcept { }
  };

} // end namespace clxx

#endif /* CLXX_COMMON_EXCEPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
