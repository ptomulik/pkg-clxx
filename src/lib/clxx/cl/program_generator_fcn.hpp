// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_generator_fcn.hpp

/** // doc: clxx/cl/program_generator_fcn.hpp {{{
 * \file clxx/cl/program_generator_fcn.hpp
 * \brief Declares functions related to \ref clxx::program_generator "program_generator"
 */ // }}}
#ifndef CLXX_CL_PROGRAM_GENERATOR_FCN_HPP_INCLUDED
#define CLXX_CL_PROGRAM_GENERATOR_FCN_HPP_INCLUDED

#include <clxx/cl/program_generator_fwd.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/cl/command_queue_fwd.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/devices.hpp>
#include <string>

namespace clxx {
/** doc: generate_and_lazy_build_program() {{{
 * \todo Write documentation
 */ // }}}
void generate_build_program(clxx::program& program_ret,
                            clxx::program_generator const& program_generator,
                            clxx::context const& context,
                            std::string const& build_options = "",
                            bool force_build = false);
/** doc: generate_and_lazy_build_program() {{{
 * \todo Write documentation
 */ // }}}
void generate_build_program(clxx::program& program_ret,
                            clxx::program_generator const& program_generator,
                            clxx::context const& context,
                            clxx::devices const& devices,
                            std::string const& build_options = "",
                            bool force_build = false);
} // end namespace clxx

#endif /* CLXX_CL_PROGRAM_GENERATOR_FCN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
