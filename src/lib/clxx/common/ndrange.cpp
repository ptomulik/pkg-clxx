// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/ndrange.cpp {{{
 * \file clxx/common/ndrange.cpp
 * \brief Implements the \ref clxx::ndrange class
 */ // }}}
#include <clxx/common/ndrange.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
ndrange::
ndrange(size_t dimension,
                   const size_t* global_offset,
                   const size_t* global_size,
                   const size_t* local_size)
{
  setup(dimension, global_offset, global_size, local_size);
}
ndrange::
ndrange(size_t dimension, std::vector<size_t> const& global_offset,
                          std::vector<size_t> const& global_size,
                          std::vector<size_t> const& local_size)
{
  setup(dimension, global_offset, global_size, local_size);
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
setup(size_t dimension,
      const size_t* global_offset,
      const size_t* global_size,
      const size_t* local_size)
{
  set_dimension(dimension);

  if(global_offset)
    {
      for(size_t i=0; i < dimension; ++i)
        _global_offset[i] = global_offset[i];
      _has_global_offset = true;
    }
  else
    _has_global_offset = false;

  if(global_size)
    {
      for(size_t i=0; i < dimension; ++i)
        _global_size[i] = global_size[i];
      _has_global_size = true;
    }
  else
    _has_global_size = false;

  if(local_size)
    {
      for(size_t i=0; i < dimension; ++i)
        _local_size[i] = local_size[i];
      _has_local_size = true;
    }
  else
    _has_local_size = false;

  return *this;
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
setup(size_t dimension,
      std::vector<size_t> const& global_offset,
      std::vector<size_t> const& global_size,
      std::vector<size_t> const& local_size)
{
  if(global_offset.size() && (global_offset.size() != dimension))
    throw length_error();
  if(global_size.size() && (global_size.size() != dimension))
    throw length_error();
  if(local_size.size() && (local_size.size() != dimension))
    throw length_error();
  return setup(dimension, global_offset.size() ? global_offset.data() : nullptr,
                          global_size.size() ? global_size.data() : nullptr,
                          local_size.size() ? local_size.data() : nullptr);
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
set_dimension(size_t value)
{
  if(value > CLXX_MAX_NDRANGE_DIMENSIONS)
    {
      throw invalid_argument_error();
    }
  _dimension = value;

  return *this;
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
set_global_offset(size_t i, size_t value)
{
  if(i >= dimension())
    {
      throw invalid_index_error();
    }
  _has_global_offset = true;
  _global_offset[i] = value;
  return *this;
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
set_global_size(size_t i, size_t value)
{
  if(i >= dimension())
    {
      throw invalid_index_error();
    }
  _has_global_size = true;
  _global_size[i] = value;
  return *this;
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
set_local_size(size_t i, size_t value)
{
  if(i >= dimension())
    {
      throw invalid_index_error();
    }
  _has_local_size = true;
  _local_size[i] = value;
  return *this;
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
clear_global_offset() noexcept
{
  _has_global_offset = false;
  return *this;
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
clear_global_size() noexcept
{
  _has_global_size = false;
  return *this;
}
/* ------------------------------------------------------------------------ */
ndrange& ndrange::
clear_local_size() noexcept
{
  _has_local_size = false;
  return *this;
}
/* ------------------------------------------------------------------------ */
size_t ndrange::
global_offset(size_t i) const
{
  if(!has_global_offset())
    throw uninitialized_value_error();
  if(i >= dimension())
    throw invalid_index_error();
  return _global_offset[i];
}
/* ------------------------------------------------------------------------ */
size_t ndrange::
global_size(size_t i) const
{
  if(!has_global_size())
    throw uninitialized_value_error();
  if(i >= dimension())
    throw invalid_index_error();
  return _global_size[i];
}
/* ------------------------------------------------------------------------ */
size_t ndrange::
local_size(size_t i) const
{
  if(!has_local_size())
    throw uninitialized_value_error();
  if(i >= dimension())
    throw invalid_index_error();
  return _local_size[i];
}
/* ------------------------------------------------------------------------ */
std::vector<size_t> ndrange::
global_offset() const
{
  if(!has_global_offset())
    throw uninitialized_value_error();
  return std::vector<size_t>(_global_offset, _global_offset + dimension());
}
/* ------------------------------------------------------------------------ */
std::vector<size_t> ndrange::
global_size() const
{
  if(!has_global_size())
    throw uninitialized_value_error();
  return std::vector<size_t>(_global_size, _global_size + dimension());
}
/* ------------------------------------------------------------------------ */
std::vector<size_t> ndrange::
local_size() const
{
  if(!has_local_size())
    throw uninitialized_value_error();
  return std::vector<size_t>(_local_size, _local_size + dimension());
}
/* ------------------------------------------------------------------------ */
bool ndrange::
cmp(ndrange const& other) const noexcept
{
  if(dimension() != other.dimension()) return false;
  if(has_global_offset() != other.has_global_offset()) return false;
  if(has_global_size() != other.has_global_size()) return false;
  if(has_local_size() != other.has_local_size()) return false;

  if(has_global_offset())
    {
      for(size_t i = 0; i < dimension(); ++i)
        if (_global_offset[i] != other._global_offset[i]) return false;
    }
  if(has_global_size())
    {
      for(size_t i = 0; i < dimension(); ++i)
        if (_global_size[i] != other._global_size[i]) return false;
    }
  if(has_local_size())
    {
      for(size_t i = 0; i < dimension(); ++i)
        if (_local_size[i] != other._local_size[i]) return false;
    }
  return true;
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
