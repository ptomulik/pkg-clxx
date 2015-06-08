// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/archive/detail/interface_oarchive.swg {{{
 * \file clxx/boost/archive/detail/interface_oarchive.swg
 * \todo Write documentation
 */ // }}}

namespace boost {
namespace archive {
namespace detail {

template <class Archive>
class interface_oarchive
  {
  protected:
    interface_oarchive();
  public:
    template <class T> Archive& operator<<(T & t);
    template <class T> Archive& operator& (T & t);
  };

} /* namespace detail */
} /* namespace archive */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
