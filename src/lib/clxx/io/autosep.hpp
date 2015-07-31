// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/autosep.hpp

/** // doc: clxx/io/autosep.hpp {{{
 * \file clxx/io/autosep.hpp
 * \brief Contains template class clxx::io::autosep
 */ // }}}
#ifndef CLXX_IO_AUTOSEP_HPP_INCLUDED
#define CLXX_IO_AUTOSEP_HPP_INCLUDED

#include <ostream>

namespace clxx { namespace io {

/** // doc: class autosep {{{
 * \ingroup clxx_io
 *
 * \brief Automatic separator used to format strings representing lists,
 *        vectors and alike.
 *
 * \tparam SepT Type used for separator string (e.g. \c const \c char* or
 *         \c std::string).
 *
 * The autosep object may be used to simplify task of writting out lists,
 * vectors, and other sequences to streams. The output() methods writes out the
 * separator to an output stream at its second and consecutive invocations
 * (first call prints nothing). The object may be used in expressions involving
 * operator \c <<.
 *
 * \b Example:
 * \snippet clxx/io/autosep1.cpp Program
 *
 * The output of the above program is
 * \verbatim
   tab[] = {1, 2, 3}
\endverbatim
 *
 */ // }}}
template<typename SepT>
class autosep_
{
public:
  /** // doc: autosep_(sep) {{{
   * \brief Constructor
   *
   * \param sep Separator to be used by autosep_::output(), for example ","
   */ // }}}
  autosep_(SepT sep) : _sep(sep), _do_sep(false) { }
  /** // doc: output(os) {{{
   * \brief Output separator to a stream.
   * \param os Output stream used to output the separator to.
   * \return Output stream \c os.
   */ // }}}
  template<class Ostream>
  Ostream& output(Ostream& os) const
  {
    if(this->_do_sep)
      os << this->_sep;
    else
      this->_do_sep = true;
    return os;
  }
  /** // doc: reset() {{{
   * \brief Reset the autosep_ to initial state.
   *
   * Call this method to reset autosep's state before reusing it to print
   * another sequence.
   *
   */ // }}}
  void reset() const
  {
    this->_do_sep = false;
  }
private:
  autosep_();
private:
  SepT _sep;
  mutable bool _do_sep;
};

/** // doc: autosep(sep) {{{
 * \ingroup clxx_io
 *
 * \brief Create autosep object (automatic separator).
 *
 * \tparam  SepT type of data used to represent automatic separator (e.g.
 *          const char* or std::string). It shall be deduced from \c sep
 *          argument.
 * \param   sep A value that will be used as a separator, for example \c ",".
 *
 * \return  An instance of autosep<SepT>.
 *
 * This function is useful in expressions, where you don't have to declare
 * autosep object by hand. The template parameter is deduced by C++ compiler.
 */ // }}}
template<typename SepT>
autosep_<SepT> autosep(SepT sep)
{
  return autosep_<SepT>(sep);
}

} } // end namespace clxx::io

/** // doc: autosep(sep) {{{
 * \ingroup clxx_io
 *
 * \brief Ouput autosep to stream.
 * \tparam _CharT Same as in std::basic_string<_CharT, _Traits>, deduced from
 *         argument \c os.
 * \tparam _Traits Same as in std::basic_string<_CharT, _Traits>, deduced from
 *         argument \c os.
 * \tparam SepT Same as in autosep<SepT>, deduced from argument \c as.
 * \param os Output stream.
 * \param as clxx::io::autosep object (auto-separator).
 * \return The reference provided by \c os argument
 *
 * This is template of overloaded operator \c << which outputs
 * clxx::io::autosep object to a stream.
 *
 */ // }}}
template<typename _CharT, typename _Traits, typename SepT>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::io::autosep_<SepT> const& as)
{
  return as.output(os);
}
#endif /* CLXX_IO_AUTOSEP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
