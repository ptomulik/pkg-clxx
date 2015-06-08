// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/device_query.hpp

/** // doc: clxx/io/device_query.hpp {{{
 * \file clxx/io/device_query.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_IO_DEVICE_QUERY_HPP_INCLUDED
#define CLXX_IO_DEVICE_QUERY_HPP_INCLUDED

#include <clxx/device_query.hpp>
#include <iosfwd>

namespace clxx { namespace io {

/**
 * \ingroup clxx_io
 * @{
 */
/** // doc: write(os, info, pre) {{{
 * \brief Write out clxx::device_query object to a stream
 *
 * \param os    Output stream.
 * \param query An object to be written out to the stream.
 * \param ind   Indentation level.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, clxx::device_query const& query, int ind);
/** // doc: write(os, info) {{{
 * \brief Write out clxx::device_query object to a stream
 *
 * \param os    Output stream.
 * \param query An object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, clxx::device_query const& query);
/** @} */

} } // end namespace clxx::io

/** // doc: os << info {{{
 * \ingroup clxx_io
 * \brief Write clxx::device_query object to a stream
 *
 * \param os    Output stream.
 * \param query An object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::device_query const& query);

#endif /* CLXX_IO_DEVICE_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
