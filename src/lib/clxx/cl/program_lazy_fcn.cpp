// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_lazy_fcn.cpp {{{
 * \file clxx/cl/program_lazy_fcn.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_lazy_fcn.hpp>
#include <clxx/cl/program_fcn.hpp>
#include <clxx/cl/device.hpp>
#include <clxx/cl/program.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
static clxx::devices
_determine_build_devices(clxx::program const& program,
                         clxx::devices const& devices,
                         std::string const& options)
{
  clxx::devices build_devices;
  for(auto d = devices.begin(); d != devices.end(); ++d)
    {
      build_status_t status = program.get_build_status(*d);
      if(status == build_status_t::none || status == build_status_t::error)
        build_devices.push_back(*d);
      else if(status == build_status_t::success)
        {
          if(program.get_build_options(*d) != options)
            build_devices.push_back(*d);
        }
    }
  return build_devices;
}
/* ----------------------------------------------------------------------- */
void
lazy_build_program(clxx::program const& program,
                   std::string const& options,
                   bool force_build)
{
  if(force_build)
    {
      build_program(program, options);
      return;
    }
  lazy_build_program(program, program.get_devices(), options, force_build);
}
/* ----------------------------------------------------------------------- */
void
lazy_build_program(clxx::program const& program,
                   clxx::devices const& devices,
                   std::string const& options,
                   bool force_build)
{
  if(force_build)
    {
      build_program(program, devices, options);
      return;
    }
  clxx::devices build_devices(_determine_build_devices(program, devices, options));
  if(!build_devices.empty())
   build_program(program, build_devices, options);
}
/* ----------------------------------------------------------------------- */
void
lazy_build_program(clxx::program const& program,
                   std::string const& options,
                   clxx::program_observer& observer,
                   bool force_build)
{
  if(force_build)
    {
      build_program(program, options, observer);
      return;
    }
  lazy_build_program(program, program.get_devices(), options, observer, force_build);
}
/* ----------------------------------------------------------------------- */
void
lazy_build_program(clxx::program const& program,
                   clxx::devices const& devices,
                   std::string const& options,
                   clxx::program_observer& observer,
                   bool force_build)
{
  if(force_build)
    {
      build_program(program, devices, options, observer);
      return;
    }
  clxx::devices build_devices(_determine_build_devices(program, devices, options));
  if(!build_devices.empty())
   build_program(program, build_devices, options, observer);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
