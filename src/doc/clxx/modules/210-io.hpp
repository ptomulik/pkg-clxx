// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)
/**
 * \defgroup clxx_io Clxx I/O module
 *
 * This module implements several I/O routines which stream out %clxx objects
 * to output streams in a user-readable form. They may be used for simple
 * diagnostics, debugging or user-interface implementation.
 *
 * The implemented functions cover all the %clxx enum classes defined in
 * clxx/types.hpp and some of the object classes, such as clxx::platform_info.
 * For convenience, we have specialized the "shift" operator (\c <<) for these
 * types and these specializations work with most standard streams. In
 * addition, there are also specialized functions named clxx::io::write which
 * accept additional parameters to tune the output layout (indentation etc.).
 *
 * \par Linking
 *
 * Programs using functions described in this module shall be linked against
 * \c libclxx_io library (\c -lclxx_io).
 *
 */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
