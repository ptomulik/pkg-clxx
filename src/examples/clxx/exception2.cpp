// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exception2.cpp {{{
 * \file clxx/exception2.cpp
 * \todo Write documentation
 */ // }}}
/** // doc: \example exception2.cpp {{{
 * \example exception2.cpp
 * This example illustrates the basic technique for extending the hierarchy of
 * clxx exceptions. We define new exception class named \c exception2 which
 * derives directly from clxx::exception and std::bad_alloc.
 */ // }}}

// [Includes]
#include <clxx/exception.hpp>
#include <stdexcept>
// [Includes]

// [ExceptionDefinition]
namespace clxx {
/// \brief Sample exception class
struct exception2
  : public clxx::exception,
    public std::bad_alloc
  {
    /// \brief Type cast to std::exception
    std::exception const& clxx2std() const noexcept
    { return *this; }
    /// \brief Exception message
    const char* what() const noexcept
    { return "exception2"; }
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
    throw clxx::exception2();
  } catch(clxx::exception2 const& e) {
    std::cout << "A. caught clxx::exception2: " << e.what() << std::endl;
  }
  // [CatchClxxException1]
  // [CatchClxxException]
  try {
    throw clxx::exception2();
  } catch(clxx::exception const& e) {
    std::cout << "B. caught clxx::exception: " << e.clxx2std().what() << std::endl;
  }
  // [CatchClxxException]

  // [CatchStdRuntimeError]
  try {
    throw clxx::exception2();
  } catch(std::bad_alloc const& e) {
    std::cout << "C. caught std::bad_alloc: " << e.what() << std::endl;
  }
  // [CatchStdRuntimeError]

  // [CatchStdException]
  try {
    throw clxx::exception2();
  } catch(std::exception const& e) {
    std::cout << "D. caught std::exception: " << e.what() << std::endl;
  }
  // [CatchStdException]

  // [CatchHierarchy]
  try {
    throw clxx::exception2();
  } catch(clxx::exception2 const& e) {
    std::cout << "E. caught clxx::exception2: " << e.what() << std::endl;
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
