// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/runtime.cpp {{{
 * \file clxx/cl/runtime.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/runtime.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/device.hpp>
#include <clxx/cl/program_lazy_fcn.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
thread_local runtime* runtime::__current_instance = nullptr;
/* ----------------------------------------------------------------------- */
clxx::runtime& runtime::
get_current_instance()
{
  if(!__current_instance) __current_instance = &get_shared_instance();
  return *__current_instance;
}
/* ----------------------------------------------------------------------- */
void runtime::
set_current_instance(clxx::runtime& runtime) noexcept
{
  __current_instance = &runtime;
}
/* ----------------------------------------------------------------------- */
clxx::runtime& runtime::
get_shared_instance()
{
  static clxx::runtime r;
  return r;
}
/* ----------------------------------------------------------------------- */
clxx::runtime& runtime::
get_local_instance()
{
  thread_local clxx::runtime r;
  return r;
}
/* ----------------------------------------------------------------------- */
program_generator_ptr const& runtime::
get_program_generator(std::string const& name) const
{
  try {
    return _program_generators.at(name);
  } catch(std::out_of_range const&) {
    throw clxx::invalid_key_error("program generator not found (name = '" + name + "')");
  }
}
/* ----------------------------------------------------------------------- */
program_generator_ptr const& runtime::
set_program_generator(std::string const& name, clxx::program_generator_ptr const& generator)
{
  return _program_generators[name] = generator;
}
/* ----------------------------------------------------------------------- */
bool runtime::
has_program_generator(std::string const& name) const
{
  return _program_generators.find(name) != _program_generators.end();
}
/* ----------------------------------------------------------------------- */
clxx::program runtime::
generate_program(std::string const& name, clxx::context const& context) const
{
  return this->get_program_generator(name)->get_program(context);
}
/* ----------------------------------------------------------------------- */
void runtime::
generate_build_program(clxx::program& program,
                       std::string const& name,
                       clxx::context const& context,
                       std::string const& build_options,
                       bool force_build) const
{
  program = this->generate_program(name, context);
  clxx::lazy_build_program(program, build_options, force_build);
}
/* ----------------------------------------------------------------------- */
void runtime::
generate_build_program(clxx::program& program,
                       std::string const& name,
                       clxx::context const& context,
                       clxx::devices const& devices,
                       std::string const& build_options,
                       bool force_build) const
{
  if(devices.empty()) return;
  program = this->generate_program(name, context);
  clxx::lazy_build_program(program, devices, build_options, force_build);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
