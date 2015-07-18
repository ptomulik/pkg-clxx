// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/events.hpp

/** // doc: clxx/cl/events.hpp {{{
 * \file clxx/cl/events.hpp
 * \brief Defines the \ref clxx::events collection
 */ // }}}
#ifndef CLXX_CL_EVENTS_HPP_INCLUDED
#define CLXX_CL_EVENTS_HPP_INCLUDED

#include <clxx/cl/event.hpp>
#include <vector>

namespace clxx {
/** // doc: events {{{
 * \ingroup clxx_event_objects
 * \brief Collection of clxx::event objects.
 */ // }}}
typedef std::vector<event> events;
} // end namespace clxx

namespace clxx {
/** \addtogroup clxx_event_objects
 * @{ */
/** // doc: wait_for_events() {{{
 * \brief Waits on the host thread for commands identified by event objects to complete
 *
 * \param event_list
 *    The events specified in \p event_list act as synchronization points.
 *
 * \par Exceptions
 *
 * Throws exceptions originating from
 * \ref clxx::wait_for_events(cl_uint,const cl_event*) "wait_for_events()".
 */ // }}}
void wait_for_events(clxx::events const& event_list);
/** @} */
}

#endif /* CLXX_CL_EVENTS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
