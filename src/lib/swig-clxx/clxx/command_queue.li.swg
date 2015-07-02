// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/command_queue.li.swg {{{
 * \file clxx/command_queue.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/command_queue.hpp>
%}

%include <clxx/exception_support.swg>

%define %throws_as_command_queue_get_pod_info(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_command_queue_error
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_uninitialized_command_queue(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_command_queue_error
  %catch_exception
}
%enddef

%define %throws_uninitialized_command_queue_clerror(decl)
%exception decl {
  try { $action }
  %catch_uninitialized_command_queue_error
  %catch_clerror
  %catch_exception
}
%enddef

%define %throws_as_command_queue_ctor1(decl)
%exception decl {
  try { $action }
  %catch_invalid_argument_error
  %catch_not_enough_space_error
  %catch_badalloc
  %catch_exception
}
%enddef

%throws_as_command_queue_ctor1(clxx::command_queue::command_queue(context const&, device const&, command_queue_properties_t));
%throws_uninitialized_command_queue(clxx::command_queue::command_queue(clxx::command_queue const&));
%throws_as_command_queue_get_pod_info(clxx::command_queue::get_info(command_queue_info_t, size_t, void *, size_t *) const);
%throws_uninitialized_command_queue(clxx::command_queue::get_valid_handle() const);
%throws_uninitialized_command_queue_clerror(clxx::command_queue::operator=(command_queue const&));
%throws_uninitialized_command_queue_clerror(clxx::command_queue::assign(command_queue const&));
%throws_as_command_queue_get_pod_info(clxx::command_queue::get_reference_count() const);
%throws_as_command_queue_get_pod_info(clxx::command_queue::get_num_devices() const);
%throws_as_command_queue_get_pod_info(clxx::command_queue::get_devices() const);
%throws_as_command_queue_get_pod_info(clxx::command_queue::get_properties() const);

%template(clobj_command_queue) clxx::clobj<cl_command_queue>;

%include <clxx/command_queue.hpp>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
