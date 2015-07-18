// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/info/platform_query.t.h

/** // doc: clxx/s11n/platform_query.t.h {{{
 * \file clxx/s11n/platform_query.t.h
 * \brief Unit tests for clxx::platform_query
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_QUERY_T_H_INCLUDED
#define CLXX_S11N_PLATFORM_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/s11n/platform_query.hpp>
#include <clxx/platform_query_fixtures.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <sstream>

namespace clxx { class s11n_platform_query_test_suite; }

/** // doc: class clxx::s11n_platform_query_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::s11n_platform_query_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_serialize_text() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_text( )
  {
    platform_query a;
    platform_query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << a;

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    TS_ASSERT_EQUALS(a, b);
  }
  /** // doc: test_serialize_xml() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_xml( )
  {
    using boost::serialization::make_nvp;
    platform_query a;
    platform_query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::xml_oarchive oa(ss);
    oa << make_nvp("platform_query", a);

    boost::archive::xml_iarchive ia(ss);
    ia >> make_nvp("device_query", b);

    TS_ASSERT_EQUALS(a, b);
  }
  /** // doc: test_serialize_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_binary( )
  {
    platform_query a;
    platform_query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::binary_oarchive oa(ss);
    oa << a;

    boost::archive::binary_iarchive ia(ss);
    ia >> b;

    TS_ASSERT_EQUALS(a, b);
  }
};

#endif /* CLXX_S11N_PLATFORM_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
