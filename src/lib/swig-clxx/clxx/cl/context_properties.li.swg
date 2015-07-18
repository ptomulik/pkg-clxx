// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/context_properties.li.swg {{{
 * \file clxx/cl/context_properties.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/cl/context_properties.hpp>
%}
%include <std_vector.i>
%template (context_properties) std::vector<clxx::context_property>;

%include <clxx/exception_support.swg>

%exception clxx::context_properties_fill_array(clxx::context_properties const&, cl_context_properties *, size_t) {
  try { $action }
  %catch_invalid_argument_error
  %catch_not_enough_space_error
  %catch_exception
}
%exception clxx::context_properties_parse_array(clxx::context_properties&, cl_context_properties const *) {
  try { $action }
  %catch_invalid_argument_error
  %catch_badalloc
  %catch_exception
}
%throws_badalloc(clxx::operator&(context_property const&, context_property const&));
%throws_badalloc(clxx::operator&(context_properties const&, context_property const&))
%throws_badalloc(clxx::operator&(context_property const&, context_properties const&));
%throws_badalloc(clxx::operator&(context_properties const&, context_properties const&));
%throws_badalloc(clxx::make_context_properties);

%include <clxx/cl/context_properties.hpp>

namespace clxx {
  inline context_properties make_context_properties(context_property const&);
  inline context_properties make_context_properties(context_property const&, context_property const&);
  inline context_properties make_context_properties(context_property const&, context_property const&, context_property const&);
  inline context_properties make_context_properties(context_property const&, context_property const&, context_property const&, context_property const&);

  inline context_properties make_context_properties(platform const&);
  inline context_properties make_context_properties(platform const&, context_property const&);
  inline context_properties make_context_properties(platform const&, context_property const&, context_property const&);
  inline context_properties make_context_properties(platform const&, context_property const&, context_property const&, context_property const&);

  inline context_properties make_context_properties(context_properties const&);
  inline context_properties make_context_properties(context_properties const&, context_property const&);
  inline context_properties make_context_properties(context_properties const&, context_property const&, context_property const&);
  inline context_properties make_context_properties(context_properties const&, context_property const&, context_property const&, context_property const&);

  inline context_properties make_context_properties(platform const&, context_properties const&);
};

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
