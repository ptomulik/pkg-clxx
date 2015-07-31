// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_generator.cpp {{{
 * \file clxx/cl/program_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_generator.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/command_queue.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
thread_local program_generator::program_ctor_t program_generator::
_default_program_ctor = [](clxx::context const& context, std::string const& src)
      -> clxx::program
{
  return clxx::program(context, clxx::program_sources{ src });
};
/* ----------------------------------------------------------------------- */
program_generator::program_ctor_t const& program_generator::
default_program_ctor()
{
  return _default_program_ctor;
}
/* ----------------------------------------------------------------------- */
void program_generator::
set_default_program_ctor(program_ctor_t const& ctor)
{
  _default_program_ctor = ctor;
}
/* ----------------------------------------------------------------------- */
program_generator::
program_generator()
{
}
/* ----------------------------------------------------------------------- */
program_generator::
program_generator(program_ctor_t const& program_ctor)
  : _program_ctor(program_ctor)
{
}
/* ----------------------------------------------------------------------- */
program_generator::
~program_generator()
{
}
/* ----------------------------------------------------------------------- */
clxx::program program_generator::
create_program(clxx::context const& context, std::string const& src) const
{
  return _program_ctor ? _program_ctor(context, src)
                       : _default_program_ctor(context, src);
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
line_directive(clxx::context const& context, size_t line) const
{
  return "#line " + std::to_string(line) + " \"" + this->program_path(context) + "\"";
}
/* ----------------------------------------------------------------------- */
clxx::program program_generator::
get_program(clxx::context const& context) const
{
  std::string src;
  this->generate_program_source(src, context);
  return this->create_program(context, src);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
