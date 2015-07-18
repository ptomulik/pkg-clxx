// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/device_info.t.h

/** // doc: clxx/s11n/device_info.t.h {{{
 * \file clxx/s11n/device_info.t.h
 * \brief Unit tests for clxx::device_info
 */ // }}}
#ifndef CLXX_S11N_DEVICE_INFO_T_H_INCLUDED
#define CLXX_S11N_DEVICE_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/s11n/device_info.hpp>
#include <clxx/device_info_fixtures.hpp>

// For serialization
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <sstream>

namespace clxx { class s11n_device_info_test_suite; }

/** // doc: class clxx::s11n_device_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::s11n_device_info_test_suite : public CxxTest::TestSuite
{
public:
//  /** // doc: test_serialize_text() {{{
//   * \todo Write documentation
//   */ // }}}
  void test_serialize_text( )
  {
    device_info orig(device_info_fixtures::_1());
    device_info info;

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << orig;

    boost::archive::text_iarchive ia(ss);
    ia >> info;

    TS_ASSERT_EQUALS(info, orig);
  }
//  /** // doc: test_serialize_xml() {{{
//   * \todo Write documentation
//   */ // }}}
  void test_serialize_xml( )
  {
    using boost::serialization::make_nvp;
    device_info orig(device_info_fixtures::_1());
    device_info info;

    std::stringstream ss;

    boost::archive::xml_oarchive oa(ss);
    oa << make_nvp("device_info", orig);

    boost::archive::xml_iarchive ia(ss);
    ia >> make_nvp("device_info", info);

    TS_ASSERT_EQUALS(info, orig);
  }
//  /** // doc: test_serialize_binary() {{{
//   * \todo Write documentation
//   */ // }}}
  void test_serialize_binary( )
  {
    device_info orig(device_info_fixtures::_1());
    device_info info;

    std::stringstream ss;

    boost::archive::binary_oarchive oa(ss);
    oa << orig;

    boost::archive::binary_iarchive ia(ss);
    ia >> info;

    TS_ASSERT_EQUALS(info, orig);
  }
};

#endif /* CLXX_S11N_DEVICE_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
