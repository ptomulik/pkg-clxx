// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/platform_query.hpp

/** // doc: clxx/io/platform_query.hpp {{{
 * \file clxx/io/platform_query.hpp
 * \brief Declares I/O functions for \ref clxx::platform_query "platform_query" objects
 */ // }}}
#ifndef CLXX_IO_PLATFORM_QUERY_HPP_INCLUDED
#define CLXX_IO_PLATFORM_QUERY_HPP_INCLUDED

#include <clxx/info/platform_query.hpp>
#include <iosfwd>

namespace clxx { namespace io {

/** \addtogroup clxx_io
 *  @{ */
/** // doc: write(os,query){{{
 * \brief Write out clxx::platform_query object to a stream
 *
 * \param os    Output stream.
 * \param query An object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_query const& query);
/** @} */
} } // end namespace clxx::io

/** // os << query {{{
 * \ingroup clxx_io
 * \brief Write out clxx::platform_query object to a stream
 *
 * \param os    Output stream.
 * \param query An object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::platform_query const& query );

#endif /* CLXX_IO_PLATFORM_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
