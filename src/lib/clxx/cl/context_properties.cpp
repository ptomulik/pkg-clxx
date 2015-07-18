// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)
/** // doc: clxx/cl/context_properties.cpp {{{
 * \file clxx/cl/context_properties.cpp
 * \brief Implements the \ref clxx::context_properties "context_properties" class
 */ // }}}
#include <clxx/cl/context_properties.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
size_t
context_properties_array_size(const context_properties& props)
{
  typedef context_properties::const_iterator iter;
  size_t size = 1; // one entry for trailing zero
  for(iter p = props.begin(); p != props.end(); size += p->size(), ++p) {}
  return size;
}
/* ----------------------------------------------------------------------- */
size_t
context_properties_fill_array(const context_properties& props,
                              cl_context_properties* array,
                              size_t size)
{
  typedef context_properties::const_iterator iter;

  if(array == nullptr)
    throw invalid_argument_error();

  size_t count = context_properties_array_size(props);
  if(size < count)
    throw not_enough_space_error();

  for(iter p = props.begin(); p != props.end(); ++p)
    {
      p->write(array);
      array += p->size();
    }
  *array = (cl_context_properties)0ul;

  return count;
}
/* ----------------------------------------------------------------------- */
size_t
context_properties_parse_array(context_properties& props,
                               const cl_context_properties* array)
{
  if(array == nullptr)
    throw invalid_argument_error();

  size_t count = 0;
  context_property prop;
  for(;array[count] != (cl_context_properties)0; count+=prop.size())
    {
      prop.read(array + count);
      props.push_back(prop);
    }
  return count;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_property const& left, context_property const& right)
{
  context_properties cp;
  cp.push_back(left);
  cp.push_back(right);
  return cp;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_properties const& left, context_property const& right)
{
  context_properties cp(left);
  cp.push_back(right);
  return cp;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_property const& left, context_properties const& right)
{
  context_properties cp;
  cp.push_back(left);
  cp.insert(cp.end(),right.begin(),right.end());
  return cp;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_properties const& left, context_properties const& right)
{
  context_properties cp(left);
  cp.insert(cp.end(),right.begin(),right.end());
  return cp;
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
