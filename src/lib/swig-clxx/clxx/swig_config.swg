// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/swig_config.swg {{{
 * \file clxx/swig_config.swg
 * \todo Write documentation
 */ // }}}

#if SWIG_VERSION < 0x030000
# define constexpr const
#endif

// TODO: provide better implementation for BOOST_CLASS_VERSION,
//       maybe it should be moved to a better place as well
#define BOOST_CLASS_VERSION(__klass,__ver)

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
