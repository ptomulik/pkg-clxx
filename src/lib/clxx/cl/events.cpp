// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/events.cpp {{{
 * \file clxx/cl/events.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/events.hpp>
#include <clxx/cl/functions.hpp>
#include <clxx/common/obj2cl.hpp>

namespace clxx {
void
wait_for_events(clxx::events const& event_list)
{
  if(!event_list.empty())
    {
      wait_for_events(static_cast<cl_uint>(event_list.size()),
                      obj2cl(event_list));
    }
}
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
