// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)
/**
 * \defgroup clxx_exceptions Exceptions
 *
 * This module introduces clxx exceptions.
 *
 * <h4>User's view</h4>
 *
 * %Clxx uses exceptions to report errors. A hierarchy of exception classes is
 * developed to represent all errors which may occur in %clxx. This hierarchy
 * may be easily extended when new exceptions are needed.
 *
 * From user's view, the exceptions are categorized as follows:
 * - #clxx::exception - base class for all clxx exceptions
 *   - #clxx::clerror - base class for exceptions originating from OpenCL errors
 *     - #clxx::clerror_no - particular OpenCL errors (template class with OpenCL error code as parameter)
 *     - #clxx::unexpected_clerror - OpenCL error not expected by clxx,
 *   - #clxx::uninitialized_platform_error - a non-OpenCL exception ,
 *   - ... - other exceptions, originating from other source than OpenCL.
 *
 * When handling exception, the user may wish to catch all %clxx exceptions
 * (and ignore others):
 * \code
 *   try {
 *     // ...
 *   } catch(clxx::exception const& e) {
 *     // ...
 *   }
 * \endcode
 * or (s)he may wish to handle only exceptions that fall to a predefined
 * \e category in %clxx &mdash; for example exceptions raised due to OpenCL
 * errors (error codes returned from OpenCL functions converted to exceptions)
 * \code
 *   try {
 *     // ...
 *   } catch (clxx::clerror const& e) {
 *     // ...
 *   }
 * \endcode
 * When necessary, an exception might be tracked down up to a particular error
 * code:
 * \code
 *   try {
 *     // ...
 *   } catch (clxx::clerror_no<clxx::status_t::device_not_found> const& e) {
 *     // ...
 *   }
 * \endcode
 *
 * Each %clxx exception has one of the standard exceptions as its base class,
 * for example \c std::exception, \c std::runtime_error or \c std::logic_error.
 * The following code
 * \code
 *   try {
 *    ...
 *   } catch (const std::exception& e) {
 *     // clxx exceptions also caught here ...
 *   }
 * \endcode
 * will, thus, catch all exceptions including %clxx exceptions.
 *
 * When handling %clxx exception, the standard interface is available via
 * the method \ref clxx::exception::clxx2std() "clxx2std()".
 * \code
 * try {
 *   // ...
 * } catch (clxx::exception const& e) {
 *   std::cout << e.clxx2std().what() << std::endl;
 * }
 * \endcode
 *
 * <h4>Developer's view</h4>
 *
 * Developers should derive new exceptions from clxx::exception_base. It takes
 * a base exception class as the first template argument. The clxx::exception
 * is the first candidate to be put here,
 * \code
 * struct fooerror1
 *   : public clxx::exception_base<clxx::exception, std::exception>
 *   {
 *     // ...
 *   };
 * \endcode
 * but you may also introduce a subclass of clxx::exception to create a new
 * \e category of clxx exceptions
 * \code
 * struct fooerror
 *   : public clxx::exception
 *   {
 *     // ...
 *   };
 * struct fooerror1
 *   : public clxx::exception_base<fooerror, std::exception>
 *   {
 *     // ...
 *   };
 * \endcode
 *
 * Whenever a new \e category has to be implemented, a new base class for the
 * \e category should be defined (the "branch base"). For example, the a base
 * for errors returned by OpenCL functions is the clxx::clerror class. The
 * category class should be derived from clxx::exception.
 *
 * For quick start we'll follow the \ref exception3.cpp example. In this
 * example we create a custom exception without a category. Include followig
 * headers
 * \snippet exception3.cpp Includes
 *
 * Next, define within the clxx namespace the new exception class:
 * \snippet exception3.cpp ExceptionDefinition
 *
 * That's all, we can test our new exception with the following program
 * \snippet exception3.cpp Test
 *
 * The output from above program will be the following
 * \verbatim
   user@host:$ ./build/examples/clxx/exception3
   A. caught clxx::exception3: exception3
   B. caught clxx::exception: exception3
   C. caught std::runtime_error: exception3
   D. caught std::exception: exception3
   E. caught clxx::exception3: exception3
   \endverbatim
 *
 * This complete example should give basic understanding about %clxx
 * exceptions. More information about exceptions may be inferred from file
 * and class documentation.
 *
 * \see clxx/exception.hpp
 * \see clxx/exception_base.hpp
 * \see clxx/clerror.hpp
 * \see clxx/clerror_base.hpp
 * \see clxx/clerror_no.hpp
 * \see clxx/exceptions.hpp
 * \see clxx::exception,
 * \see clxx::exception_base,
 * \see clxx::clerror,
 * \see clxx::clerror_base,
 * \see clxx::clerror_no.
 */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
