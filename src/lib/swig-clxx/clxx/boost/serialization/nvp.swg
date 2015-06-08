// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/boost/serialization/nvp.swg {{{
 * \file clxx/boost/serialization/nvp.swg
 * \todo Write documentation
 */ // }}}

namespace boost {
namespace serialization {
template<class T>
struct nvp
  {
    explicit nvp(const char * name_, T & t);
    nvp(const nvp & rhs);
    const char* name() const;
    T & value() const;
    const T & const_value() const;
  };
template<class T> nvp<T> make_nvp(const char* name, T & t);
} /* namespace serialization */
} /* namespace boost */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
