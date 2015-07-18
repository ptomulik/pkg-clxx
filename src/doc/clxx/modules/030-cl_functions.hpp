// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // \defgroup clxx_cl_functions {{{
 * \defgroup clxx_cl_functions Functional interface to OpenCL
 *
 * The functions documented in this module provide thin wrappers around OpenCL
 * functions. Their purpose is to:
 *   - introduce \ref clxx_exceptions "our exceptions" &mdash; the new
 *     functions throw appropriate \ref clxx_exceptions "exceptions" instead of
 *     returning OpenCL error codes,
 *   - introduce \ref clxx/common/types.hpp "our strongly typed enums" &mdash;
 *     whenever appropriate, the new functions accept strongly typed enums
 *     defined in \ref clxx/common/types.hpp, instead of the OpenCL's \c CL_* constants,
 *   - introduce cxxtest mocks &mdash; this is used internally for unit
 *     testing.
 */ // }}}
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
