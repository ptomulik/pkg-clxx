// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/option_value.hpp

/** // doc: clxx/app/options/option_value.hpp {{{
 * \file clxx/app/options/option_value.hpp
 * \brief Defines the \ref clxx::app::options::option_value class
 */ // }}}
#ifndef CLXX_APP_OPTIONS_OPTION_VALUE_HPP_INCLUDED
#define CLXX_APP_OPTIONS_OPTION_VALUE_HPP_INCLUDED

#include <boost/program_options/value_semantic.hpp>

/** // doc: BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX {{{
 * \brief Whether to use a workaround for missing
 *    boost::program_options::typed_value<T,CharT>::value_name()
 *
 * Older versions of Boost.Program_Options were missing the
 * boost::program_options::typed_value<T,CharT>::name() and
 * boost::program_options::typed_value<T,CharT>::value_name() methods.
 * For those versions, we provide special workaround, that is we implement
 * these methods in our subclass clxx::app::options::option_value.
 *
 * This constant decides, whether this workaround should be enabled or not.
 */ // }}}
#define BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX 1
// FIXME: I'm not sure, in which version of Boost.ProgramOptions the member
// function boost::program_options::typed_value<T,charT>::value_name()'
// will be implemented (it's already in svn, but ...). When it will be clear,
// just uncomment following lines (replacing 2 with correct version number):
/* #include <boost/program_options/version.hpp>
 * #define BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX \
 *   (BOOST_PROGRAM_OPTIONS_VERSION <= 2) */

/** \cond SHOW_IGNORED_COMPOUNDS */
#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX
namespace boost { namespace program_options {
extern BOOST_PROGRAM_OPTIONS_DECL std::string arg;
}}
#endif
/** \endcond */

namespace clxx { namespace app { namespace options {

/** // doc: class option_value {{{
 * \brief Single option value
 *
 * The option_value object encapsuates the actual value and also has a name.
 */ // }}}
template <class T, class charT = char>
class option_value
  : public boost::program_options::typed_value<T, charT>
{
public:
  /** // doc: ~option_value() {{{
   * \brief Destructor
   */ // }}}
  virtual ~option_value()
  {
  }

  /** // doc: option_value(...) {{{
   * \brief Constructor
   */ // }}}
  option_value(T* store_to)
    : boost::program_options::typed_value<T,charT>(store_to)
  {
  }

#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX
  /** // doc: foo() {{{
   * \brief Returns option value's name
   */ // }}}
  std::string name( ) const;

  /** // doc: value_name(n) {{{
   * \brief Sets option value's name
   *
   * \param n The new name
   * \returns Pointer to this object
   */ // }}}
  option_value* value_name(std::string const& n)
  {
    this->_value_name = n;
    return this;
  }
#endif

private:
#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX
  std::string _value_name;
#endif
};

/** // doc: value(v) {{{
 * \brief Generate \ref option_value wrapper for value of type T
 * \tparam T Type of the underlying value
 * \param v Pointer to the variable being wrapped with the option_value object.
 * \returns A pointer to newly allocated \ref option_value object. The returned
 *    value is allocated with the \c new operator.
 */ // }}}
template<class T>
option_value<T>*
value(T* v)
{
  option_value<T> *r = new option_value<T>(v);
  return r;
}

/** // doc: value() {{{
 * \brief Generate \ref option_value object wrapping \c nullptr.
 * \tparam T Type of the underlying value
 * \returns A pointer to new \ref option_value object.
 */ // }}}
template<class T>
option_value<T>*
value()
{
  return clxx::app::options::value<T>(nullptr);
}

/** // doc: wvalue(v) {{{
 * \brief Generate \ref option_value wrapper for value of type T
 * \tparam T Type of the underlying value
 *
 * The returned option_value object uses \c wchar_t string to represent its
 * name.
 *
 * \param v Pointer to the variable being wrapped with the option_value object.
 * \returns A pointer to newly allocated \ref option_value object. The returned
 *    value is allocated with the \c new operator.
 */ // }}}
template<class T>
option_value<T, wchar_t>*
wvalue(T* v)
{
  option_value<T,wchar_t>* r = new option_value<T,wchar_t>(v);
  return r;
}

/** // doc: wvalue() {{{
 * \brief Generate \ref option_value object wrapping \c nullptr.
 *
 * The returned option_value object uses \c wchar_t string to represent its
 * name.
 *
 * \tparam T Type of the underlying value
 * \returns A pointer to new \ref option_value object.
 */ // }}}
template<class T>
option_value<T, wchar_t>*
wvalue()
{
  return clxx::app::options::wvalue<T>(0);
}

/** // doc: bool_switch(v) {{{
 * \brief Generate \ref option_value object wrapping a boolean value
 * \param v Pointer to the variable being wrapped with the new \ref
 *    option_value object.
 * \returns A pointer newly created option_value object. The object is
 *    allocated with the operator \c new.
 */ // }}}
BOOST_PROGRAM_OPTIONS_DECL inline option_value<bool>*
bool_switch(bool* v)
{
  option_value<bool>* r = new option_value<bool>(v);
  r->default_value(0);
  r->zero_tokens();

  return r;
}

/** // doc: bool_switch() {{{
 * \brief Generate \ref option_value object wrapping \c nullptr.
 * \tparam T Type of the underlying value
 * \returns A pointer to new \ref option_value object.
 */ // }}}
BOOST_PROGRAM_OPTIONS_DECL inline option_value<bool>*
bool_switch()
{
  return bool_switch(0);
}

#if BOOST_PROGRAM_OPTIONS_NEED_VALUE_NAME_FIX
template<class T, class charT>
std::string option_value<T, charT>::
name() const
{
  using std::string;
  string my_name(boost::program_options::typed_value<T,charT>::name());
  if(!this->_value_name.empty())
    {
      // Ugly fix. I hope, that BOOST > 1.49 will implement "value_name" on its
      // own. The code is based on reverse engineering of name() implementation
      // found in boost/program_options/detail/value_semantic.hpp (ver. 1.49).
      size_t pos;
      using boost::program_options::arg;
      string pattern("[=arg(=");
      pos = my_name.find(pattern);
      if(pos != string::npos)
        {
          string replacement(string("[=") + this->_value_name + string("(="));
          my_name.replace(pos,pattern.length(),replacement);
        }
      pos = my_name.find(arg);
      if(pos != string::npos)
        {
          my_name.replace(pos,arg.length(),this->_value_name);
        }
    }
  return my_name;
}
#endif
} } } // end namespace clxx::app::options
#endif /* CLXX_APP_OPTIONS_OPTION_VALUE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
