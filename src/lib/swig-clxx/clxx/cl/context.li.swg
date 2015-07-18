// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/context.li.swg {{{
 * \file clxx/cl/context.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/cl/context.hpp>
%}

%include <clxx/exception_support.swg>

%define %throws_as_context_get_pod_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_context_error
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_as_context_get_vec_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_context_error
  %catch_clerror
  %catch_badalloc
  %catch_exception
}
%enddef

%define %throws_uninitialized_context(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_context_error
  %catch_exception
}
%enddef

%define %throws_uninitialized_context_clerror(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_context_error
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_as_context_ctor1(decl)
%exception decl {
  try { $action }
  %catch_invalid_argument_error
  %catch_not_enough_space_error
  %catch_badalloc
  %catch_exception
}
%enddef

%throws_as_context_ctor1(clxx::context::context(context_properties const&, devices const&, void(*)(const char *, const void*, size_t, void *), void *));
%throws_as_context_ctor1(clxx::context::context(context_properties const&, device_type_t, void(*)(const char *, const void*, size_t, void *), void *));
%throws_uninitialized_context(clxx::context::context(context const&));
%throws_as_context_get_pod_info(clxx::context::get_info(context_info_t, size_t, void *, size_t *) const);
%throws_uninitialized_context(clxx::context::chk_get() const);
%throws_uninitialized_context_clerror(clxx::context::operator=(context const&));
%throws_uninitialized_context_clerror(clxx::context::assign(context const&));
%throws_as_context_get_pod_info(clxx::context::get_reference_count() const);
%throws_as_context_get_pod_info(clxx::context::get_num_devices() const);
%throws_as_context_get_vec_info(clxx::context::get_devices() const);
%throws_as_context_get_vec_info(clxx::context::get_properties() const);

%template (clobj_context) clxx::clobj<cl_context>;

%include <clxx/cl/context.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
