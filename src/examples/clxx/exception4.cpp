// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exception4.cpp {{{
 * \file clxx/exception4.cpp
 * \brief Example with clxx exceptions
 */ // }}}
/** // doc: \example exception4.cpp {{{
 * \example exception4.cpp
 * This example illustrates the basic technique for extending the hierarchy of
 * clxx exceptions. We define new exception class named \c exception4 based
 * on std::bad_alloc. Instead of deriving directly from clxx::exception
 * we use the clxx::exception_base template.
 */ // }}}

// [Includes]
#include <clxx/exception_base.hpp>
// [Includes]

// [ExceptionDefinition]
namespace clxx {
/// \brief Example exception
struct exception4
  : public clxx::exception_base<clxx::exception, std::bad_alloc>
  {
    /// \brief Exception message
    char const* what() const noexcept { return "exception4"; }
  };
} /* namespace clxx { */
// [ExceptionDefinition]

// [Test]
#include <iostream>
/// \brief Main function
int main()
{
  // [CatchClxxException1]
  try {
    throw clxx::exception4();
  } catch(clxx::exception4 const& e) {
    std::cout << "A. caught clxx::exception4: " << e.what() << std::endl;
  }
  // [CatchClxxException1]
  // [CatchClxxException]
  try {
    throw clxx::exception4();
  } catch(clxx::exception const& e) {
    std::cout << "B. caught clxx::exception: " << e.clxx2std().what() << std::endl;
  }
  // [CatchClxxException]

  // [CatchStdRuntimeError]
  try {
    throw clxx::exception4();
  } catch(std::bad_alloc const& e) {
    std::cout << "C. caught std::bad_alloc: " << e.what() << std::endl;
  }
  // [CatchStdRuntimeError]

  // [CatchStdException]
  try {
    throw clxx::exception4();
  } catch(std::exception const& e) {
    std::cout << "D. caught std::exception: " << e.what() << std::endl;
  }
  // [CatchStdException]

  // [CatchHierarchy]
  try {
    throw clxx::exception4();
  } catch(clxx::exception4 const& e) {
    std::cout << "E. caught clxx::exception4: " << e.what() << std::endl;
  } catch(clxx::exception const& e) {
    std::cout << "E. caught clxx::exception: " << e.clxx2std().what() << std::endl;
  } catch(std::bad_alloc const& e) {
    std::cout << "E. caught std::bad_alloc: " << e.what() << std::endl;
  } catch(std::exception const& e) {
    std::cout << "E. caught std::exception: " << e.what() << std::endl;
  }
  // [CatchHierarchy]

  return 0;
}
// [Test]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
