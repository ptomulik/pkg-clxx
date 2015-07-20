// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)
/**
 * \defgroup clxx_s11n libclxx_s11n
 *
 * \brief This module documents \ref clxx_s11n package
 *
 * The package implements routines for serialization of certain clxx objects
 * using the <a href="http://www.boost.org/doc/libs/release/libs/serialization/">Boost.Serialization</a> library.
 *
 * The following usage examples illustrate the possible use of the \ref
 * clxx_s11n library.
 *
 * \par Linking
 *
 * Programs which use this package should be linked against \c libclxx_s11n
 * library (\c -lclxx_s11n).
 *
 * \par Example
 *
 * Serialize platform layer info to an XML archive using
 * <a href="http://www.boost.org/doc/libs/release/libs/serialization/doc/archives.html#archive_models">boost::xml_oarchive</a>.
 *
 * \snippet clxx/s11n1.cpp Program
 *
 * \par Example
 *
 * Read platform layer info from an XML archive using 
 * <a href="http://www.boost.org/doc/libs/release/libs/serialization/doc/archives.html#archive_models">boost::xml_iarchive</a>
 * and print it out to standard output.
 *
 * \snippet clxx/s11n2.cpp Program
 */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
