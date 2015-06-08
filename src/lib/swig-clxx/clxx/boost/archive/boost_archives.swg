// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/boost_archives.swg {{{
 * \file clxx/boost/archive/boost_archives.swg
 * \todo Write documentation
 */ // }}}

%include <clxx/boost/archive/text_iarchive.swg>
%include <clxx/boost/archive/text_oarchive.swg>
%include <clxx/boost/archive/xml_iarchive.swg>
%include <clxx/boost/archive/xml_oarchive.swg>
%include <clxx/boost/archive/binary_iarchive.swg>
%include <clxx/boost/archive/binary_oarchive.swg>

%include <clxx/boost/serialization/nvp.swg>

%define CLXX_EXTEND_BOOST_TEXT_OARCHIVE(__klass)
%extend boost::archive::detail::interface_oarchive<boost::archive::text_oarchive> {
  %template() operator<< < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define CLXX_EXTEND_BOOST_XML_OARCHIVE(__klass)
%extend boost::archive::detail::interface_oarchive<boost::archive::xml_oarchive> {
  %template() operator<< < boost::serialization::nvp< __klass > const >;
  %template() operator& < boost::serialization::nvp< __klass > const >;
}
%enddef

%define CLXX_EXTEND_BOOST_BINARY_OARCHIVE(__klass)
%extend boost::archive::detail::interface_oarchive<boost::archive::binary_oarchive> {
  %template() operator<< < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define CLXX_EXTEND_BOOST_TEXT_IARCHIVE(__klass)
%extend boost::archive::detail::interface_iarchive<boost::archive::text_iarchive> {
  %template() operator>> < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define CLXX_EXTEND_BOOST_XML_IARCHIVE(__klass)
%extend boost::archive::detail::interface_iarchive<boost::archive::xml_iarchive> {
  %template() operator>> < boost::serialization::nvp< __klass > const >;
  %template() operator& < boost::serialization::nvp< __klass > const >;
}
%enddef

%define CLXX_EXTEND_BOOST_BINARY_IARCHIVE(__klass)
%extend boost::archive::detail::interface_iarchive<boost::archive::binary_iarchive> {
  %template() operator>> < __klass >;
  %template() operator& < __klass >;
}
%enddef

%define CLXX_EXTEND_BOOST_OARCHIVES(__klass)
CLXX_EXTEND_BOOST_TEXT_OARCHIVE(__klass)
CLXX_EXTEND_BOOST_XML_OARCHIVE(__klass)
CLXX_EXTEND_BOOST_BINARY_OARCHIVE(__klass)
%enddef

%define CLXX_EXTEND_BOOST_IARCHIVES(__klass)
CLXX_EXTEND_BOOST_TEXT_IARCHIVE(__klass)
CLXX_EXTEND_BOOST_XML_IARCHIVE(__klass)
CLXX_EXTEND_BOOST_BINARY_IARCHIVE(__klass)
%enddef

%define CLXX_EXTEND_BOOST_ARCHIVES(__klass)
// TODO: move the commented-out code to its appropriate place. Also, see what
// can we do to have the nvp working (currently it's not well recognized by
// swig, and "no destructor found" warning is displayed by python).
//%template(make_nvp) boost::serialization::make_nvp< __klass >;
//%template(make_nvp) boost::serialization::make_nvp< CLXX_SHARED_PTR(__klass) >;
CLXX_EXTEND_BOOST_IARCHIVES(__klass);
CLXX_EXTEND_BOOST_OARCHIVES(__klass);
%enddef

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
