// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/runtime.hpp

/** // doc: clxx/cl/runtime.hpp {{{
 * \file clxx/cl/runtime.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_RUNTIME_HPP_INCLUDED
#define CLXX_CL_RUNTIME_HPP_INCLUDED

#include <clxx/cl/program_lazy_generator.hpp>
#include <clxx/cl/kernel_lazy_ctor.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/cl/devices.hpp>
#include <unordered_map>
#include <string>

namespace clxx {
/** // doc: runtime {{{
 * \todo Write documentation
 */ // }}}
class runtime
{
private:
  static thread_local runtime* __current_instance;
  typedef std::unordered_map<std::string, program_generator_ptr> program_generator_map_t;
  program_generator_map_t _program_generators;
public:
  /** // doc: get_current_instance() {{{
   * \brief Returns a reference to "current runtime"
   *
   * The reference returned by #get_current_instance() may actually point to
   * any \ref clxx::runtime "runtime" instance previously indicated with
   * #set_current_instance(). If not previously set with
   * #set_current_instance(), the first call to #get_current_instance() from
   * the current thread will bind to the shared singleton instance as returned
   * by #get_shared_instance() and return reference to the shared instance in
   * this first and the subsequent calls (until #set_current_instance() is
   * used). 
   *
   * Each thread has its own
   * <a href="http://en.cppreference.com/w/cpp/language/storage_duration">thread_local</a>
   * pointer used by #get_current_instance() which points to the "current
   * instance". At a given moment it may point to an instance that resides in
   * static storage (shared between threads), thread_local storage, automatic,
   * or any other compatible. Concluding, the reference/pointer that implement
   * "current instance" is local to the current thread, but it may point to an
   * object that is shared between threads.
   *
   * \returns A mutable reference to \ref clxx::runtime "runtime" instance
   *          that is set as "current instance" for the current thread.
   */ // }}}
  static runtime& get_current_instance();
  /** // doc: set_current_instance() {{{
   * \brief Set \p runtime object to be used as the "current instance" referred
   *        to by #get_current_instance()
   * \param runtime
   *    Reference to the object that will be treated as a current instance
   */ // }}}
  static void set_current_instance(clxx::runtime& runtime) noexcept;
  /** // doc: get_global_instance() {{{
   * \brief Returns a reference to initialized shared singleton instance
   *
   * The global singleton instance is shared between threads. The lifetime of
   * the object referenced by #get_shared_instance() starts with the first
   * invocation of #get_shared_instance() by any thread in the current process
   * and lasts to the end of current process.
   *
   * \returns A mutable reference to global instance shared between threads
   */ // }}}
  static runtime& get_shared_instance();
  /** // doc: get_local_instance() {{{
   * \brief Returns a reference to initialized thread-local singleton instance
   *
   * The thread-local singleton instance is distinct from the shared instance
   * returned by #get_shared_instance(). The lifetime of the object referenced
   * by #get_local_instance() starts with the first invocation of
   * #get_local_instance() and lasts until the end of current thread.
   *
   * \returns A mutable reference to thread-local singleton instance of \ref clxx::runtime
   */ // }}}
  static runtime& get_local_instance();
  /** // doc: get_program_generator(name) {{{
   * \brief Returns named \ref clxx::program "program" generator
   * \param name
   *    Name of the generator in question
   * \returns
   *    Named program generator
   * \throw clxx::invalid_key_error
   *    If \p name does not name a stored program generator
   */ // }}}
  program_generator_ptr const& get_program_generator(std::string const& name) const;
  /** // doc: set_program_generator(generator) {{{
   * \todo Write documentation
   */ // }}}
  program_generator_ptr const& set_program_generator(std::string const& name,
                                                     clxx::program_generator_ptr const& generator);
  /** // doc: has_program_generator(name) {{{
   * \todo Write documentation
   */ // }}}
  bool has_program_generator(std::string const& name) const;
  /** // doc: generate_program(name, context) {{{
   * \todo Write documentation
   */ // }}}
  clxx::program generate_program(std::string const& name, clxx::context const& context) const;
  /** // doc: generate_build_program(program, name, context, build_options, force_build) {{{
   * \todo Write documentation
   */ // }}}
  void generate_build_program(clxx::program& program,
                              std::string const& name,
                              clxx::context const& context,
                              std::string const& build_options = "",
                              bool force_build = false) const;
  /** // doc: generate_build_program(program, name, devices, build_options, force_build) {{{
   * \todo Write documentation
   */ // }}}
  void generate_build_program(clxx::program& program,
                              std::string const& name,
                              clxx::context const& context,
                              clxx::devices const& devices,
                              std::string const& build_options = "",
                              bool force_build = false) const;
};
} // end namespace clxx

#endif /* CLXX_CL_RUNTIME_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
