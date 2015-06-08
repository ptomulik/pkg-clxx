// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

#ifndef  CLXX_S11N_BOOST_UNORDERED_SET_HPP_INCLUDED
#define CLXX_S11N_BOOST_UNORDERED_SET_HPP_INCLUDED

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <boost/unordered_set.hpp>

#include <boost/config.hpp>

#include <boost/serialization/collections_save_imp.hpp>
#include <boost/serialization/collections_load_imp.hpp>
#include <boost/serialization/split_free.hpp>

namespace boost {
namespace serialization {

template<class Archive, class Key, class Compare, class Allocator >
inline void save(
    Archive & ar,
    const boost::unordered_set<Key, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::save_collection<
        Archive, boost::unordered_set<Key, Compare, Allocator>
    >(ar, t);
}

template<class Archive, class Key, class Compare, class Allocator >
inline void load(
    Archive & ar,
    boost::unordered_set<Key, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::load_collection<
        Archive,
        boost::unordered_set<Key, Compare, Allocator>,
        boost::serialization::stl::archive_input_set<
            Archive, boost::unordered_set<Key, Compare, Allocator>
        >,
        boost::serialization::stl::no_reserve_imp<boost::unordered_set<
            Key, Compare, Allocator>
        >
    >(ar, t);
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class Key, class Compare, class Allocator >
inline void serialize(
    Archive & ar,
    boost::unordered_set<Key, Compare, Allocator> & t,
    const unsigned int file_version
){
    boost::serialization::split_free(ar, t, file_version);
}

// multiset
template<class Archive, class Key, class Compare, class Allocator >
inline void save(
    Archive & ar,
    const std::multiset<Key, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::save_collection<
        Archive,
        std::multiset<Key, Compare, Allocator>
    >(ar, t);
}

template<class Archive, class Key, class Compare, class Allocator >
inline void load(
    Archive & ar,
    std::multiset<Key, Compare, Allocator> &t,
    const unsigned int /* file_version */
){
    boost::serialization::stl::load_collection<
        Archive,
        std::multiset<Key, Compare, Allocator>,
        boost::serialization::stl::archive_input_set<
            Archive, std::multiset<Key, Compare, Allocator>
        >,
        boost::serialization::stl::no_reserve_imp<
            std::multiset<Key, Compare, Allocator>
        >
    >(ar, t);
}

// split non-intrusive serialization function member into separate
// non intrusive save/load member functions
template<class Archive, class Key, class Compare, class Allocator >
inline void serialize(
    Archive & ar,
    std::multiset<Key, Compare, Allocator> & t,
    const unsigned int file_version
){
    boost::serialization::split_free(ar, t, file_version);
}

} // namespace serialization
} // namespace boost

#include <boost/serialization/collection_traits.hpp>

BOOST_SERIALIZATION_COLLECTION_TRAITS(boost::unordered_set)
BOOST_SERIALIZATION_COLLECTION_TRAITS(std::multiset)

#endif // CLXX_S11N_BOOST_UNORDERED_SET_HPP_INCLUDED
