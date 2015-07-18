// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/platform_layer_info.hpp

/** // doc: clxx/io/platform_layer_info.hpp {{{
 * \file clxx/io/platform_layer_info.hpp
 * \brief Declares I/O functions for \ref clxx::platform_layer_info "platform_layer_info" objects
 */ // }}}
#ifndef CLXX_IO_PLATFORM_LAYER_INFO_HPP_INCLUDED
#define CLXX_IO_PLATFORM_LAYER_INFO_HPP_INCLUDED

#include <clxx/info/platform_layer_info.hpp>
#include <iosfwd>

namespace clxx { namespace io {

/** \addtogroup clxx_io
 * @{ */
/** // doc: write(os, info, pre) {{{
 * \brief Write out clxx::platform_layer_info object to a stream
 *
 * \param os    Output stream.
 * \param info  Info object to be written out to the stream.
 * \param ind   Indentation level.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_layer_info const& info, int ind);
/** // doc: write(os, info) {{{
 * \brief Write out clxx::platform_layer_info object to a stream
 *
 * \param os    Output stream.
 * \param info  Info object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_layer_info const& info);
/** @} */

} } // end namespace clxx::io

/** // doc: os << info {{{
 * \ingroup clxx_io
 * \brief Write out clxx::platform_layer_info object to a stream
 *
 * \param os    Output stream.
 * \param info  Info object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::platform_layer_info const& info);

#endif /* CLXX_IO_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
