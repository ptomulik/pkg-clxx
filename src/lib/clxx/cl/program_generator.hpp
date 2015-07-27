// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_generator.hpp

/** // doc: clxx/cl/program_generator.hpp {{{
 * \file clxx/cl/program_generator.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED
#define CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED

#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/command_queue.hpp>
#include <string>

namespace clxx {
/** // doc: program_generator {{{
 * \brief Abstract base class for OpenCL program generators
 *
 * A program generator object (an instance of program generator class derived
 * from \ref clxx::program_generator "program_generator") generates program
 * source which is then used to create an OpenCL program object. The program is
 * created for an OpenCL \c context given as an argument to generator. The
 * programs created by program generators are NOT assumed to be automatically
 * compiled/built (generators are not responsible for building their generated
 * programs). As such, they will require to be built for one or more devices in
 * the \c context before the actual use.
 *
 * A program generator class (derived from \ref clxx::program_generator
 * "program_generator") \b MUST implement following virtual methods:
 *
 * - \ref generate_program_source(std::string&, clxx::context const&) const,
 * - \ref program_name() const.
 *
 * It also \b MAY overwrite the following virtual methods:
 *
 * - \ref program_path() const,
 * - \ref line_directive(size_t) const,
 * - \ref get_program(clxx::context const&) const.
 *
 * \par Example
 *
 * Usage example for the \ref clxx::program_generator "program_generator":
 *
 * \snippet clxx/cl/program_generator1.cpp Program
 */ // }}}
class program_generator
{
public:
  /** // doc: ~program_generator() {{{
   * \brief Destructor
   */ // }}}
  virtual ~program_generator();
  /** // doc: generate_program_source(std::string&) {{{
   * \brief Generate program source
   *
   * \pure
   *
   * The \p context may be used by generator to select particular
   * implementation of the program being generated (this enables possible
   * device-dependent optimizations).
   *
   * \param str
   *    The implementation should append its program source to this string,
   * \param context
   *    Specifies the OpenCL contex for which the program is generated.
   */ // }}}
  virtual void generate_program_source(std::string& str, clxx::context const& context) const = 0;
  /** // doc: program_name() {{{
   * \brief Returns program name
   *
   * The program name shall identify particular source code snippet generated
   * by the generator. For, example <tt>"mylib::blas1<float>"</tt> may be
   * a program which implements kernels used to implement level-1
   * (vector-vector operations) of basic linear algebra by a numerical library
   * named \c mylib.
   *
   * The program name shall not change for a particular instance of the program
   * generator. It shall at least remain constant after the first call to
   * \ref get_program(clxx::context const&) const "get_program()" for a given
   * instance.
   *
   * \returns program name as c++ string
   */ // }}}
  virtual std::string program_name() const = 0;
  /** // doc: program_path() {{{
   * \brief Returns the virtual path of the generated program
   *
   * Program path identifies the generated program source in a similar manner
   * as the #program_name() does, but it may, for example, use different syntax.
   * The #program_path() shall follow syntax of file-system path names. The
   * string returned by #program_path() does not have to point to actual file,
   * it's rather a virtual path. The string returned by #program_path() is used
   * by the #line_directive() method to generate line control stamps in the 
   * generated source code. The #program_path() should thus return strings
   * that can be correctly parsed by an OpenCL C99 compiler as a file path.
   *
   * The default implementation of #program_path() returns the #program_name().
   *
   * \returns program path as c++ string
   */ // }}}
  virtual std::string program_path() const;
  /** // doc: line_directive() {{{
   * \brief Returns a line directive
   *
   * This function shall generate a single line of code of the form
   *
   * \code
   *  #line linenum "program/path"
   * \endcode
   *
   * The \e linenum in the above snippet is the line number as provided in
   * \p linenum parameter, whereas the \e "program/path" is a string
   * returned by the #program_path() method.
   *
   * \param linenum
   *    Line number, starting from \c 1 for the first line.
   *
   * \returns
   *    The generated line directive as a c++ string 
   *
   * \note Inserting the line directive at the beginning of each program source
   *       is a recommended practice. This shall help with identifying
   *       generated programs that have compilation problems. Example:
   * \code
   *  void my_program_generator::
   *  generate_program_source(std::string& src, clxx::context const& context) const
   *  {
   *    // The very first line should be:
   *    src.append(this->line_directive(1)); src.append("\n");
   *    // ...
   *  }
   * \endcode
   */ // }}}
  virtual std::string line_directive(size_t linenum) const;
  /** // doc: get_program() {{{
   * \brief Get the program created for \p context
   *
   * The default implementation invokes the #generate_program_source() for
   * the provided \p context, and returns new instance of \ref clxx::program
   * created from the source generated by #generate_program_source().
   *
   * \param context
   *    A valid OpenCL \ref clxx::context "context"
   */ // }}}
  virtual clxx::program get_program(clxx::context const& context) const;
};
} // end namespace clxx

namespace clxx {
/** doc: generate_and_lazy_build_program() {{{
 * \todo Write documentation
 */ // }}}
void
generate_and_build_program(clxx::program& program,
                           clxx::program_generator const& program_generator,
                           clxx::command_queue const& command_queue,
                           std::string const& build_options = "");
/** doc: generate_and_lazy_build_program() {{{
 * \todo Write documentation
 */ // }}}
void
generate_and_lazy_build_program(clxx::program& program,
                                clxx::program_generator const& program_generator,
                                clxx::command_queue const& command_queue,
                                std::string const& build_options = "");
} // end namespace clxx
#endif /* CLXX_CL_PROGRAM_GENERATOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
