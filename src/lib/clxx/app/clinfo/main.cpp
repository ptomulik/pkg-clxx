// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/main.cpp

/** // doc: clxx/app/clinfo/main.cpp {{{
 * \file clxx/app/clinfo/main.cpp
 * \brief Implements the \ref clxx::app::clinfo::main class
 */ // }}}
#include <clxx/app/clinfo/main.hpp>
#include <clxx/app/clinfo/create_query.hpp>

#include <clxx/platform_layer.hpp>
#include <clxx/platform_layer_info.hpp>
#include <clxx/s11n/platform_layer_info.hpp>
#include <clxx/io/platform_layer_info.hpp>
#include <clxx/app/options/rethrow.hpp>

#include <boost/program_options/parsers.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

namespace clxx { namespace app { namespace clinfo {

/** doc: io_format {{{
 * \todo Write documentation
 */ // }}}
enum io_format {
  iof_uff,          // User-friendly format (only for output)
  iof_txt,          // boost::archive::text_(io)archive,
  iof_xml,          // boost::archive::xml_(io)archive,
  iof_bin,          // boost::archive::binary_(io)archive
  iof_unknown = -1  // Unknown format
};

using clxx::app::options::options_map;
using clxx::platform_layer_info;

static bool
process_help_options( options_map const& om, options_description const& od )
{
  if(om.count("help") || om.count("help-detail") || om.count("help-platform")
     || om.count("help-device") )
    {
      std::cout << "Usage: " << "clxx-clinfo [options]"
                << std::endl << std::endl;
    }
  if(om.count("help"))
    {
      std::cout << od.common_options() << std::endl;
      std::cout << od.io_options() << std::endl;
      std::cout << od.platform_general_options() << std::endl;
      std::cout << od.device_general_options() << std::endl;
      return true;
    }
  if(om.count("help-detail"))
    {
      std::cout << od << std::endl;
      return true;
    }
  if(om.count("help-platform"))
    {
      std::cout << od.platform_general_options() << std::endl;
      std::cout << od.platform_detail_options() << std::endl;
      return true;
    }
  if(om.count("help-device"))
    {
      std::cout << od.device_general_options() << std::endl;
      std::cout << od.device_detail_options() << std::endl;
      return true;
    }
  return false;
}

static io_format
determine_io_format(std::string const& opt)
{
  if(opt == "uff")
    return iof_uff;
  else if(opt == "txt")
    return iof_txt;
  else if(opt == "xml")
    return iof_xml;
  else if(opt == "bin")
    return iof_bin;
  else
    return iof_unknown;
}

template<class Archive>
static void
load_from_archive(std::istream& ifs, platform_layer_info& obj)
{
  Archive ar(ifs);
  ar >> boost::serialization::make_nvp("platform_layer_info", obj);
}

template<class Archive>
static void
save_to_archive(std::ostream& ofs, platform_layer_info const& obj)
{
  Archive ar(ofs);
  ar << boost::serialization::make_nvp("platform_layer_info", obj);
}

static platform_layer_info
read_from_istream(std::istream& ifs, io_format fmt)
{
  using namespace boost::archive;
  platform_layer_info pli;
  switch(fmt)
    {
      case iof_txt:
        load_from_archive<text_iarchive>(ifs, pli);
        break;
      case iof_xml:
        load_from_archive<xml_iarchive>(ifs, pli);
        break;
      case iof_bin:
        load_from_archive<binary_iarchive>(ifs, pli);
        break;
      default:
        // FIXME: throw error? unsupported format for output
        break;
    }
  return pli;
}

static void
write_to_ostream( platform_layer_info const& pli
                 , std::ostream& ofs
                 , io_format fmt
                 , int indent )
{
  using namespace boost::archive;
  switch(fmt)
    {
      case iof_uff:
        clxx::io::write(ofs, pli, indent);
        break;
      case iof_txt:
        save_to_archive<text_oarchive>(ofs, pli);
        break;
      case iof_xml:
        save_to_archive<xml_oarchive>(ofs, pli);
        break;
      case iof_bin:
        save_to_archive<binary_oarchive>(ofs, pli);
        break;
      default:
        // FIXME: throw error? unsupported format for output
        break;
    }
}

static shared_ptr<std::istream>
determine_input(options_map const& om)
{
  if(om.count("input"))
    {
      std::string file(om["input"].as<std::string>());

      if(file == "-")
        return shared_ptr<std::istream>(&std::cin);
      else
        return shared_ptr<std::istream>(new std::ifstream(file));
    }
  else
    return shared_ptr<std::istream>();
}

static shared_ptr<std::ostream>
determine_output(options_map const& om)
{
  struct noop { void operator()(...) const{}; };
  io_format fmt;

  shared_ptr<std::ostream> ofs;
  if(om.count("output"))
    {
      std::string file(om["output"].as<std::string>());
      if(file == "-")
        {
          ofs.reset(&std::cout, noop());
          fmt = iof_uff; // default for stdout
        }
      else
        {
          ofs.reset(new std::ofstream(file));
          fmt = iof_xml; // default for file
        }
    }
  else
    {
      ofs.reset(&std::cout, noop());
      fmt = iof_uff; // default for stdout
    }

  if(om.count("output-format"))
    {
      fmt = determine_io_format(om["output-format"].as<std::string>());
      if(fmt == iof_unknown)
        {
          // FIXME: throw an exception?
        }
    }

  return ofs;
}

static io_format
determine_output_format(options_map const& om)
{
  io_format fmt;

  // First, establish default value
  if(om.count("output"))
    {
      std::string file(om["output"].as<std::string>());
      if(file == "-")
        fmt = iof_uff; // default for stdout
      else
        fmt = iof_xml; // default for file
    }
  else
    fmt = iof_uff; // default for stdout

  // then eventually overwrite with user's choice
  if(om.count("output-format"))
    {
      fmt = determine_io_format(om["output-format"].as<std::string>());
      if(fmt == iof_unknown)
        {
          // FIXME: throw an exception?
        }
    }

  return fmt;
}

static platform_layer_info
retrieve_info(options_map const& om)
{
  shared_ptr<std::istream> ifs(determine_input(om));
  if(ifs)
    {
      io_format fmt = iof_xml;
      if(om.count("input-format"))
        {
          fmt = determine_io_format(om["input-format"].as<std::string>());
          if(fmt == iof_unknown)
            {
              // FIXME: throw error? unsupported format ...
            }
        }
      return read_from_istream(*ifs, fmt);
    }
  else
    {
      return clxx::query_platform_layer_info(
          clxx::platform_layer(true),
          create_platform_query(om),
          create_device_query(om)
     );
    }
}

static void
output_info(platform_layer_info const& pli, options_map const& om)
{
  shared_ptr<std::ostream> ofs(determine_output(om));

  int indent = 2;
  if(om.count("indent"))
    indent = om["indent"].as<int>();

  write_to_ostream(pli, *ofs, determine_output_format(om), indent);
}

main::
main()
  : clxx::app::main()
{
  this->_init_main();
}

main::
main(int argc, char const* argv[])
  : clxx::app::main()
{
  this->_init_main();
  this->init(argc,argv);
}

main::
~main()
{
}

int main::
run()
{
  options_map const& om = this->get_options_map();
  options_description const& od = this->get_options_description();

  if(process_help_options(om, od))
    return EXIT_SUCCESS;

  output_info(retrieve_info(om), om);

  return EXIT_SUCCESS;
}

void main::
init(int argc, char const* argv[])
{
  using boost::program_options::command_line_parser;
  using boost::program_options::notify;
  using boost::program_options::store;

  /* FIXME: move it such that it becomes a class member */
  boost::program_options::positional_options_description p;

  this->_options_map.clear();
  try
    {
      store(command_line_parser(argc, argv).
            options(this->get_options_description()).
            positional(p).run(),
            this->_options_map);
    }
  CLXX_APP_OPTIONS_RETHROW_ALL()

  notify(this->_options_map);
}

void main::
_init_main()
{
}

/** \cond SHOW_IGNORED_COMPOUNDS */
int
run(int argc, char const* argv[])
{
  main clinfo(argc,argv);
  return clinfo.run();
}
/* \endcond */

} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
