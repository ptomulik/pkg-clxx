// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_generator_fcn.cpp {{{
 * \file clxx/cl/program_generator_fcn.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_generator_fcn.hpp>
#include <clxx/cl/program_generator.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/command_queue.hpp>
#include <clxx/cl/program_lazy_fcn.hpp>
#include <clxx/cl/device.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
void generate_build_program(clxx::program& program_ret,
                            clxx::program_generator const& program_generator,
                            clxx::context const& context,
                            std::string const& build_options,
                            bool force_build)
{
  program_ret = program_generator.get_program(context);
  clxx::lazy_build_program(program_ret, build_options, force_build);
}
/* ----------------------------------------------------------------------- */
void generate_build_program(clxx::program& program_ret,
                            clxx::program_generator const& program_generator,
                            clxx::context const& context,
                            clxx::devices const& devices,
                            std::string const& build_options,
                            bool force_build)
{
  program_ret = program_generator.get_program(context);
  clxx::lazy_build_program(program_ret, devices, build_options, force_build);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
