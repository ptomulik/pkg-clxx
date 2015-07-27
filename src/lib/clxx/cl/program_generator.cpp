// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_generator.cpp {{{
 * \file clxx/cl/program_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_generator.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
program_generator::
~program_generator()
{
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_path() const
{
  return this->program_name();
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
line_directive(size_t line) const
{
  return "#line " + std::to_string(line) + " \"" + this->program_path() + "\"";
}
/* ----------------------------------------------------------------------- */
clxx::program program_generator::
get_program(clxx::context const& context) const
{
  std::string src;
  this->generate_program_source(src, context);
  return clxx::program(context, clxx::program_sources{ src });
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

namespace clxx {
/* ----------------------------------------------------------------------- */
void
generate_and_build_program(clxx::program& program,
                           clxx::program_generator const& program_generator,
                           clxx::command_queue const& command_queue,
                           std::string const& build_options)
{
  clxx::context context{ command_queue.get_context() };
  clxx::device device{ command_queue.get_device() };

  program = program_generator.get_program(context);
  build_program(program, clxx::devices{ device }, build_options);
}
/* ----------------------------------------------------------------------- */
void
generate_and_lazy_build_program(clxx::program& program,
                                clxx::program_generator const& program_generator,
                                clxx::command_queue const& command_queue,
                                std::string const& build_options)
{
  clxx::context context{ command_queue.get_context() };
  clxx::device device{ command_queue.get_device() };

  program = program_generator.get_program(context);

  switch(program.get_build_status(device))
    {
      case build_status_t::none:
      case build_status_t::error:
        build_program(program, clxx::devices{ device }, build_options);
        break;
      default:
        break;
    }
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
