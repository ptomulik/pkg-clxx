// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/events.hpp

/** // doc: clxx/events.hpp {{{
 * \file clxx/events.hpp
 * \brief Defines the \ref clxx::events collection
 */ // }}}
#ifndef CLXX_EVENTS_HPP_INCLUDED
#define CLXX_EVENTS_HPP_INCLUDED

#include <clxx/event.hpp>
#include <vector>

namespace clxx {
/** // doc: events {{{
 * \ingroup clxx_event_objects
 * \brief Collection of clxx::event objects.
 */ // }}}
typedef std::vector<event> events;
} // end namespace clxx

#endif /* CLXX_EVENTS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
