// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/unit.hpp

/** // doc: clxx/unit.hpp {{{
 * \file clxx/unit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_MOCKS_LAZY_BUILD_PROGRAM_HPP_INCLUDED
#define CLXX_CL_MOCKS_LAZY_BUILD_PROGRAM_HPP_INCLUDED

namespace T {
class LazyBuildProgram_clGetProgramBuildInfo
  : Base_clGetProgramBuildInfo, 
    Dummy_CallArgs<cl_program, cl_device_id, cl_program_info, size_t, void*, size_t*>
{
public:
  typedef cl_device_id                       key_t;
  typedef std::map<key_t, cl_build_status>   status_map_t;
  typedef std::map<key_t, std::string>       options_map_t;
private:
  status_map_t  const& _status;
  options_map_t const& _options;
  cl_int clGetProgramBuildInfo(cl_program program,
                               cl_device_id device,
                               cl_program_build_info param_name,
                               size_t param_value_size,
                               void* param_value,
                               size_t* param_value_size_ret)
  {
    call_with(program, device, param_name, param_value_size, param_value, param_value_size_ret);
    size_t size_ret = 0;
    try {
      switch(param_name)
        {
          case CL_PROGRAM_BUILD_STATUS:
            size_ret = sizeof(cl_build_status);
            if(param_value)
              {
                if(param_value_size >= size_ret)
                  *static_cast<cl_build_status*>(param_value) = _status.at(device);
                else
                  return CL_INVALID_VALUE;
              }
            break;
          case CL_PROGRAM_BUILD_OPTIONS:
            {
              std::string const& options = _options.at(device);
              size_ret = options.size()+1;
              if(param_value)
                {
                  size_ret = std::min(size_ret, param_value_size);
                  if(size_ret > 1)
                    {
                      if(param_value_size >= size_ret)
                        std::strncpy(static_cast<char*>(param_value), options.data(), size_ret);
                      else
                        return CL_INVALID_VALUE;
                    }
                  else
                    *static_cast<char*>(param_value) = '\0';
                }
            }
            break;
          default:
            return CL_INVALID_VALUE;
        }
    } catch(std::out_of_range const&) {
      return CL_INVALID_DEVICE;
    }
    if(param_value_size_ret)
      *param_value_size_ret = size_ret;
    return CL_SUCCESS;
  }
public:
  /** // doc: Dummy_clGetProgramBuildInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  LazyBuildProgram_clGetProgramBuildInfo(status_map_t const& status, options_map_t const& options)
    : _status(status), _options(options)
  {
  }
};
} // end namespace T

#endif /* CLXX_CL_MOCKS_LAZY_BUILD_PROGRAM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
