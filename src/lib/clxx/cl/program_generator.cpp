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
program_namespace() const
{
  return "";
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_full_name() const
{
  return program_namespace() + "::" + program_name();
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_file_suffix() const
{
  return ".cl";
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_dir() const
{
  return "";
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_file() const
{
  return program_name() + program_file_suffix();
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_path() const
{
  std::string path(this->program_dir());
  if(!path.empty())
    if(path.back() != '/')
      path.push_back('/');
  path.append(this->program_file());
  return path;
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

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
