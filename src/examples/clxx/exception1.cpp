// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/exception1.cpp {{{
 * \file clxx/exception1.cpp
 * \brief Example with CLXX exception.
 */ // }}}
/** // {{{
 * \example exception1.cpp
 * This example illustrates the basic technique for extending the hierarchy of
 * clxx exceptions. We define new exception class named \c exception1 which
 * derives directly from clxx::exception and std::runtime_error.
 */ // }}}

// [Includes]
#include <clxx/common/exception.hpp>
#include <stdexcept>
// [Includes]

// [ExceptionDefinition]
namespace clxx {
/// \brief Sample exception class
struct exception1
  : public clxx::exception,
    public std::runtime_error
  {
    /// \brief Default constructor
    exception1() noexcept
      : clxx::exception(), std::runtime_error("exception1")
    { }
    /// \brief Type cast to std::exception
    std::exception const& clxx2std() const noexcept
    { return *this; }
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
    throw clxx::exception1();
  } catch(clxx::exception1 const& e) {
    std::cout << "A. caught clxx::exception1: " << e.what() << std::endl;
  }
  // [CatchClxxException1]
  // [CatchClxxException]
  try {
    throw clxx::exception1();
  } catch(clxx::exception const& e) {
    std::cout << "B. caught clxx::exception: " << e.clxx2std().what() << std::endl;
  }
  // [CatchClxxException]

  // [CatchStdRuntimeError]
  try {
    throw clxx::exception1();
  } catch(std::runtime_error const& e) {
    std::cout << "C. caught std::runtime_error: " << e.what() << std::endl;
  }
  // [CatchStdRuntimeError]

  // [CatchStdException]
  try {
    throw clxx::exception1();
  } catch(std::exception const& e) {
    std::cout << "D. caught std::exception: " << e.what() << std::endl;
  }
  // [CatchStdException]

  // [CatchHierarchy]
  try {
    throw clxx::exception1();
  } catch(clxx::exception1 const& e) {
    std::cout << "E. caught clxx::exception1: " << e.what() << std::endl;
  } catch(clxx::exception const& e) {
    std::cout << "E. caught clxx::exception: " << e.clxx2std().what() << std::endl;
  } catch(std::runtime_error const& e) {
    std::cout << "E. caught std::runtime_error: " << e.what() << std::endl;
  } catch(std::exception const& e) {
    std::cout << "E. caught std::exception: " << e.what() << std::endl;
  }
  // [CatchHierarchy]

  return 0;
}
// [Test]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
