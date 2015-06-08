// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/shared_ptr.li.swg {{{
 * \file clxx/shared_ptr.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/shared_ptr.hpp>
%}

// NOTE: clxx/shared_ptr.hpp uses alias template, which is not yet supported
//       by swig, so we replace the clxx::shared_ptr alias with
//       CLXX_SHARED_PTR macro defined here
//%include <clxx/shared_ptr.hpp>
%include <boost_shared_ptr.i>
%include <boost/shared_ptr.hpp>

#define CLXX_SHARED_PTR(__t) boost::shared_ptr<__t>

// CLXX_DECL_CLASS_SHARED_PTR1(__ns1,__klass)
// Having __ns1::__klass create wrappers for its shared_ptr, such that
// the following objects will be available to target language:
//
// * <__klass>_ptr        (shared_ptr<__ns1::__klass>)
// * const_<__klass>_ptr  (shared_ptr<__ns1::__klass const>)
//
%define CLXX_DECL_CLASS_SHARED_PTR1(__ns1,__klass)
%shared_ptr(__ns1::__klass);
namespace __ns1 {
  struct __klass;
  typedef CLXX_SHARED_PTR(__ns1::__klass) __klass ## _ptr;
  typedef CLXX_SHARED_PTR(__ns1::__klass const) const_ ## __klass ## _ptr;
}
//%template(__klass ## _ptr) CLXX_SHARED_PTR(__ns1::__klass ## _ptr);
//%template(const_ ## __klass ## _ptr) CLXX_SHARED_PTR(__ns1::__klass ## _ptr const);
%enddef

// CLXX_DECL_CLASS_SHARED_PTR2(__ns1,__ns2,__klass)
// Having __ns1::__ns2::__klass create wrappers for its shared_ptr, such that
// the following objects will be available to target language:
//
// * <__klass>_ptr        (shared_ptr<__ns1::__ns2::__klass>)
// * const_<__klass>_ptr  (shared_ptr<__ns1::__ns2::__klass const>)
//
%define CLXX_DECL_CLASS_SHARED_PTR2(__ns1,__ns2,__klass)
%shared_ptr(__ns1::__ns2::__klass);
namespace __ns1 { namespace __ns2 {
  struct __klass;
  typedef CLXX_SHARED_PTR(__ns1::__ns2::__klass) __klass ## _ptr;
  typedef CLXX_SHARED_PTR(__ns1::__ns2::__klass const) const_ ## __klass ## _ptr;
} }
//%template(__klass ## _ptr) CLXX_SHARED_PTR(__ns1::__ns2::__klass ## _ptr);
//%template(const_ ## __klass ## _ptr) CLXX_SHARED_PTR(__ns1::__ns2::__klass ## _ptr const);
%enddef

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
