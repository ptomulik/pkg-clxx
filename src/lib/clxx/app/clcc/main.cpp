// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clcc/main.cpp

/** // doc: clxx/app/clcc/main.cpp {{{
 * \file clxx/app/clcc/main.cpp
 * \brief Implements the \ref clxx::app::clcc::main class
 */ // }}}
#include <clxx/app/clcc/main.hpp>
#include <clxx/app/clinfo/main.hpp>
#include <clxx/app/options/rethrow.hpp>
#include <clxx/info/platform_layer_info.hpp>
#include <clxx/io/platform_layer_info.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/program_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/common/clerror_no.hpp>
#include <algorithm>
#include <fstream>
#include <sstream>

namespace clxx { namespace app { namespace clcc {
static program_sources
_read_program_sources(std::vector<std::string> const& input_files)
{
  program_sources sources;

  for(auto i = input_files.begin(); i != input_files.end(); ++i)
    {
      // FIXME: handle non-existing files etc.
      std::fstream f(*i, std::fstream::in);
      std::stringstream ss;
      ss << f.rdbuf();
      std::string src(ss.str());
      if(src.empty())
        src += "\n";
      sources.push_back(src);
    }
  return sources;
}

/* ------------------------------------------------------------------------ */
main::
main()
  : clxx::app::main(),
    _options(1,nullptr)
{
}
/* ------------------------------------------------------------------------ */
main::
main(int argc, char const* argv[])
  : clxx::app::main(),
    _options(argc, argv)
{
  init(argc, argv);
}
/* ------------------------------------------------------------------------ */
main::
~main()
{
}
/* ------------------------------------------------------------------------ */
int main::
run()
{
  if(options().help())
    return _execute_help();
  else if(options().version())
    return _execute_version();
  else if(options().info() || options().short_info())
    return _execute_info();
  else if(options().build())
    return _execute_build();
  else
    {
      // FIXME: replace the following with a suitable exception?
      std::cerr << "error: no input files" << std::endl;
      return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
/* ------------------------------------------------------------------------ */
int main::
_execute_build()
{
  program_sources sources(_read_program_sources(options().input_files()));

  // FIXME: throw appropriate exception...
  if(sources.size() == 0)
    return EXIT_FAILURE;

  platform_layer pl(_make_platform_layer());

  contexts cs(_make_contexts(pl));

  for(auto c = cs.begin(); c != cs.end(); ++c)
    {
      program p(*c, sources);
      devices ds(c->get_devices());
      try
        {
          build_program(p, options().cloptions());
        }
      catch(clerror_no<status_t::build_program_failure> const&)
        {
          std::string log;
          for(devices::const_iterator d = ds.begin(); d != ds.end(); ++d)
            {
              if(is_error(p.get_build_status(*d)))
                log += p.get_build_log(*d);
            }
          std::cerr << log << std::endl;
          return EXIT_FAILURE;
        }
    }

  return EXIT_SUCCESS;
}
/* ------------------------------------------------------------------------ */
int main::
_execute_info()
{
  platform_layer pl(_make_platform_layer());
  platform_query pq;
  device_query dq;
  if(options().short_info())
    {
      pq.select_none().select_name().
                       select_vendor().
                       select_version().
                       select_profile();
      dq.select_none().select_name().
                       select_vendor().
                       select_version().
                       select_profile().
                       select_opencl_c_version();
    }
  io::write(std::cout, query_platform_layer_info(pl,pq,dq), 2);
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
/* ------------------------------------------------------------------------ */
int main::
_execute_help()
{
  std::cout << "Usage: clxx-clcc [options] file(s)..." << std::endl;
  std::cout << options().visible_options_description() << std::endl;
  return EXIT_SUCCESS;
}
/* ------------------------------------------------------------------------ */
int main::
_execute_version()
{
  // TODO: implement
  throw std::runtime_error("not implemented yet");
}
/* ------------------------------------------------------------------------ */
platform_layer main::
_make_platform_layer() const
{
  platform_layer pl;
  platforms ps(get_platforms());
  if(options().platform_index() != -1)
    {
      size_t const i = static_cast<size_t>(options().platform_index());
      if(i >= ps.size())
        throw out_of_range_error("platform index out of range");
      devices ds(get_devices(ps[i], options().device_type()));
      if(options().device_index() != -1)
        {
          if(ds.size() > 0)
            {
              size_t const j = static_cast<size_t>(options().device_index());
              if(j >= ds.size())
                throw out_of_range_error("device index out of range");
              if(_match(ds[j]) && _match(ps[i]))
                pl.add(ds[j], ps[i]);
            }
        }
      else
        {
          if(_match(ps[i]))
            pl.add(_filter(ds), ps[i]);
        }
    }
  else
    {
      if(options().device_index() != -1)
        {
          size_t const j = static_cast<size_t>(options().device_index());
          for(size_t i = 0; i != ps.size(); ++i)
            {
              devices ds(get_devices(ps[i], options().device_type()));
              if(ds.size() > 0)
                {
                  if(j >= ds.size())
                    throw out_of_range_error("device index out of range");
                  if(_match(ds[j]) && _match(ps[i]))
                    pl.add(ds[j], ps[i]);
                }
            }
        }
      else
        {
          for(auto p = ps.begin(); p != ps.end(); ++p)
            {
              devices ds(get_devices(*p, options().device_type()));
              if(_match(*p))
                pl.add(_filter(ds), *p);
            }
        }
    }
  return pl;
}
/* ------------------------------------------------------------------------ */
contexts main::
_make_contexts(platform_layer const& pl) const
{
  contexts cs;
  platforms const& ps(pl.get_platforms());
  for(platforms::const_iterator p = ps.begin(); p != ps.end(); ++p)
    cs.push_back(context(make_context_properties(*p), pl.get_devices(*p)));
  return cs;
}
/* ------------------------------------------------------------------------ */
bool main::
_match(platform const& p) const
{
  if(options().platform_filter().empty())
    return true;
  return options().platform_filter() == p.get_name();
}
/* ------------------------------------------------------------------------ */
bool main::
_match(device const& d) const
{
  if(options().device_filter().empty())
    return true;
  return options().device_filter() == d.get_name();
}
/* ------------------------------------------------------------------------ */
platforms main::
_filter(platforms const& ds) const
{
  platforms res(ds);
  auto nm = [this](platform const& x) -> bool { return !this->_match(x); };
  platforms::const_iterator e = std::remove_if(res.begin(), res.end(), nm);
  res.resize(e - res.begin());
  return res;
}
/* ------------------------------------------------------------------------ */
devices main::
_filter(devices const& ds) const
{
  devices res(ds);
  auto nm = [this](device const& x) -> bool { return !this->_match(x); };
  devices::const_iterator e = std::remove_if(res.begin(), res.end(), nm);
  res.resize(e - res.begin());
  return res;
}
/* ------------------------------------------------------------------------ */
void main::
init(int argc, const char* argv[])
{
  (void)argc;
  (void)argv;
}
/* ------------------------------------------------------------------------ */
/** \cond SHOW_IGNORED_COMPOUNDS */
int
run(int argc, char const* argv[])
{
  main clcc(argc,argv);
  return clcc.run();
}
/* \endcond */
/* ------------------------------------------------------------------------ */
} } } // end namespace clxx::app::clcc

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
