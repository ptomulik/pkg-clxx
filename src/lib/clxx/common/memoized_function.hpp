// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/memoized_function.hpp

/** // doc: clxx/common/memoized_function.hpp {{{
 * \file clxx/common/memoized_function.hpp
 * \brief Provides the \ref clxx::memoized_function "memoized_function"
 */ // }}}
#ifndef CLXX_COMMON_MEMOIZED_FUNCTION_HPP_INCLUDED
#define CLXX_COMMON_MEMOIZED_FUNCTION_HPP_INCLUDED

#include <clxx/common/exceptions.hpp>
#include <functional>
#include <type_traits>
#include <map>
#include <mutex>

namespace clxx {
/** \cond DOXYGEN_SHOW_IGNORED_COMPOUNDS */
template<typename F>
struct memoized_function;
/** \endcond */
/** // doc: memoized_function<R(Args...)> {{{
 * \brief Memoized function
 *
 * The \ref clxx::memoized_function<R(Args...)> adds result caching feature to
 * a callable object (function, method and such).
 *
 * The internal map used to cache the results is maintained in a thread-safe
 * way. The memoized function object is copy-constructible and copyable.
 *
 * \tparam R
 *    Type of the result of the wrapped calleble object
 * \tparam Args
 *    Types of arguments accepted by the wrapped callable object
 *
 * \par Example
 * \snippet clxx/common/memoized_function1.cpp Program
 *
 * \par Output
 * \snippet clxx/common/memoized_function1.cpp Output
 */ // }}}
template<typename R, typename... Args>
struct memoized_function<R(Args...)>
  : std::function<R(Args...)>
{
private:
  typedef std::function<R(Args...)> Base;
  typedef std::tuple<typename std::decay<Args>::type...> args_tuple_t;
  typedef std::map<args_tuple_t, R> cache_t;
  mutable cache_t _cache;
  mutable std::mutex _mutex;
public:
  using Base::Base;
  /** // doc: memoized_function(memoized_function const&) {{{
   * \brief Copy constructor
   *
   * The copy constructor copies the callable object wrapped by \p other and
   * and copy of the internally maintained result cache.
   *
   * \param other
   *    The other object which initialized this one
   */ // }}}
  memoized_function(memoized_function const& other)
  {
    if(this == &other) return; // avoid self-deadlock
    // To be thread-safe we have to protect mutable member(s)
    std::lock(_mutex, other._mutex); // acquire both mutexes or wait
    std::lock_guard<std::mutex> lock1(_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(other._mutex, std::adopt_lock);
    _cache = other._cache;
  }
  /** // doc: memoized_function(memoized_function const&) {{{
   * \brief Assignment operator
   *
   * The assignment operator assigns the copy of the callable object and 
   * and copy of the internally maintained result cache.
   *
   * \param other
   *    The other object to be assigned to this one.
   * \returns
   *    A mutable reference to \c this object.
   */ // }}}
  memoized_function& operator=(memoized_function const& other)
  {
    if(this == &other) return *this; // avoid self-deadlock
    // To be thread-safe we have to protect mutable member(s)
    std::lock(_mutex, other._mutex); // acquire both mutexes or wait
    std::lock_guard<std::mutex> lock1(_mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(other._mutex, std::adopt_lock);
    _cache = other._cache;
    return *this;
  }
  /** // doc: operator()() {{{
   * \brief Returns the result of wrapped function.
   *
   * Returns the result of wrapped function. The wrapped function is invoked
   * only once and the result is memoized in the internal cache. Each succesive
   * call to this operator returns the cached result, until it gets removed
   * from cache (see #discard_cached_result() and #discard_cached_results()).
   *
   * \param args
   *    Arguments passed to the wrapped callable object
   *
   * \returns
   *    The result computed by the wrapped callable object
   */ // }}}
  R operator()(Args... args) const
  {
    // To be thread-safe we have to protect mutable member(s)
    std::lock_guard<std::mutex> lock(_mutex);
    auto argt = std::make_tuple(args...);
    auto memoized = _cache.find(argt);
    if(memoized == _cache.end())
      return _cache[argt] = static_cast<Base const&>(*this)(args...);
    else
      return memoized->second;
  }
  /** // doc: get_cached_result() {{{
   * \brief Returns cached result
   *
   * The method returns memoized result for the given arguments.
   * If the result has not been memoized yet, the method throws
   * \ref clxx::invalid_key_error.
   *
   * \param args
   *    Arguments passed to the wrapped callable object
   *
   * \returns
   *    The result computed by the wrapped callable object
   *
   * \throw
   *    clxx::invalid_key_error
   *      If the result has not been memorized yet.
   */ // }}}
  R const& get_cached_result(Args... args) const
  {
    // To be thread-safe we have to protect mutable member(s)
    std::lock_guard<std::mutex> lock(_mutex);
    auto argt = std::make_tuple(args...);
    auto memoized =  _cache.find(argt);
    if(memoized == _cache.cend())
      throw clxx::invalid_key_error("function result not found in cache");
    else
      return memoized->second;
  }
  /** // doc: discard_cached_result() {{{
   * \brief Discard result cached for given arguments
   *
   * \param args
   *    Argument values which determine the particular result
   * \return
   *    Number of elements removed from cache, which might be either 0 or 1.
   */ // }}}
  size_t discard_cached_result(Args... args) const
  {
    // To be thread-safe we have to protect mutable member(s)
    std::lock_guard<std::mutex> lock(_mutex);
    return _cache.erase(std::make_tuple(args...));
  }
  /** // doc: discard_cached_results() {{{
   * \brief Discard all the cached results
   */ // }}}
  void discard_cached_results() const
  {
    // To be thread-safe we have to protect mutable member(s)
    std::lock_guard<std::mutex> lock(_mutex);
    _cache.clear();
  }
};
/** // doc: make_memoized_function() {{{
 * \brief Wrap function \p fn with \ref clxx::memoized_function "memoized_function"
 */ // }}}
template<typename R, typename... Args>
memoized_function<R(Args...)>
make_memoized_function(R(*fn)(Args...))
{
  return memoized_function<R(Args...)>(fn);
}
/** // doc: make_memoized_function() {{{
 * \brief Wrap function \p fn with \ref clxx::memoized_function "memoized_function"
 */ // }}}
template<typename R, typename... Args>
memoized_function<R(Args...)>
make_memoized_function(std::function<R(Args...)> const& fn)
{
  return memoized_function<R(Args...)>(fn);
}
/** // doc: make_memoized_function() {{{
 * \brief Wrap non-static method \p fn with \ref clxx::memoized_function "memoized_function"
 */ // }}}
template<typename T1, typename T2, typename R, typename... Args>
memoized_function<R(Args...)>
make_memoized_function(R (T1::*fn)(Args...) const, T2 const* obj)
{
  static_assert(std::is_base_of<T1,T2>::value, "");
  return std::bind(fn, obj, std::placeholders::_1);
}
/** // doc: make_memoized_function() {{{
 * \brief Wrap non-static method \p fn with \ref clxx::memoized_function "memoized_function"
 */ // }}}
template<typename T1, typename T2, typename R, typename... Args>
memoized_function<R(Args...)>
make_memoized_function(R (T1::*fn)(Args...), T2* obj)
{
  static_assert(std::is_base_of<T1,T2>::value, "");
  return std::bind(fn, obj, std::placeholders::_1);
}
} // end namespace clxx

#endif /* CLXX_COMMON_MEMOIZED_FUNCTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
