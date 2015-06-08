// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

#ifndef CLXX_S11N_BOOST_UNORDERED_MAP_HPP_INCLUDED
#define CLXX_S11N_BOOST_UNORDERED_MAP_HPP_INCLUDED

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <boost/unordered_map.hpp>

#include <boost/config.hpp>

#include <boost/serialization/utility.hpp>
#include <boost/serialization/collections_save_imp.hpp>
#include <boost/serialization/collections_load_imp.hpp>
#include <boost/serialization/split_free.hpp>

namespace boost {
namespace serialization {

template<class Archive, class Type, class Key, class Compare, class Allocator >
inline void save(
    Archive & ar,
    const boost::unordered_map<Key, Type, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::save_collection<
        Archive,
        boost::unordered_map<Key, Type, Compare, Allocator>
    >(ar, t);
}

template<class Archive, class Type, class Key, class Compare, class Allocator >
inline void load(
    Archive & ar,
    boost::unordered_map<Key, Type, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::load_collection<
        Archive,
        boost::unordered_map<Key, Type, Compare, Allocator>,
        boost::serialization::stl::archive_input_map<
            Archive, boost::unordered_map<Key, Type, Compare, Allocator> >,
            boost::serialization::stl::no_reserve_imp<boost::unordered_map<
                Key, Type, Compare, Allocator
            >
        >
    >(ar, t);
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class Type, class Key, class Compare, class Allocator >
inline void serialize(
    Archive & ar,
    boost::unordered_map<Key, Type, Compare, Allocator> &t,
    const unsigned int file_version
){
    boost::serialization::split_free(ar, t, file_version);
}

// multimap
template<class Archive, class Type, class Key, class Compare, class Allocator >
inline void save(
    Archive & ar,
    const std::multimap<Key, Type, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::save_collection<
        Archive,
        std::multimap<Key, Type, Compare, Allocator>
    >(ar, t);
}

template<class Archive, class Type, class Key, class Compare, class Allocator >
inline void load(
    Archive & ar,
    std::multimap<Key, Type, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::load_collection<
        Archive,
        std::multimap<Key, Type, Compare, Allocator>,
        boost::serialization::stl::archive_input_map<
            Archive, std::multimap<Key, Type, Compare, Allocator>
        >,
        boost::serialization::stl::no_reserve_imp<
            std::multimap<Key, Type, Compare, Allocator>
        >
    >(ar, t);
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class Type, class Key, class Compare, class Allocator >
inline void serialize(
    Archive & ar,
    std::multimap<Key, Type, Compare, Allocator> &t,
    const unsigned int file_version
){
    boost::serialization::split_free(ar, t, file_version);
}

} // serialization
} // namespace boost

#endif // CLXX_S11N_BOOST_UNORDERED_MAP_HPP_INCLUDED
