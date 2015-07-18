src/lib/swig-clxx/
```````````````````

This subtree contains swig_ library used to generate wrappers for *target
languages* (other than C/C++). The typical library use is to ``%include``
appropriate ``.li.i`` files in a target-language-specific ``.i`` interface
files.

By wrapping our C++ code, most of the functionality implemented here in C++ is
available also in other languages. The list of target languages may be further
extended with relatively low effort.

This is the top level ``swig-clxx`` library directory for clxx project. The
sub-directory ``clxx/`` starts a hierarchy which resembles the hierarchy of
``#/src/lib/clxx/`` directory (the hash ``#`` denotes top-level source
directory). For example, we have following correspondence:

- ``#/src/lib/clxx/ ->  clxx/``
- ``#/src/lib/clxx/cl/ -> clxx/cl/``
- ``[...]``

There are some extra directories:

==================== ========================================================
Subdirectory          Description
==================== ========================================================
``clxx/std``          contains modules that wrap things from standard C++
                      library, such as exceptions, strings and so on
==================== ========================================================

file types
::::::::::

You'll find four types of files here

- ``.li.i``, language-independent swig interface, one for each output module
  to be generated,
- ``.i.hpp``, interface header, one for each ``.li.i`` file,
- ``.swg``, - language-dependent swig library, one for each header in
  ``#/src/lib/clxx``.,
- ``.li.swg``, language-independent swig library, one for each ``.swg`` file.

The intended way to generate a module using this library is to just create a
language-specific interface file ``*.i`` which set's up appropriate ``%module``
and include corresponding ``*.li.i`` file, for example:

.. code-block::

    // clxx/cl/platforms.i
    %module(package="clxx") platforms
    %include <clxx/cl/platforms.li.i>

See files under ``#/src/lib/python-clxx`` for details.

When generating wrappers with swig, the top-level directory of this subtree, i.e
``#/src/lib/swig-clxx`` must be in swig's include path (the ``-I`` flag).

files that enter bindings: the ``.swg`` files
:::::::::::::::::::::::::::::::::::::::::::::

This subtree provides one ``.swg`` and one ``.li.swg`` file for each ``.hpp``,
whose interfaces may be potentially wrapped with swig. For example, we have
following correspondence:

- ``#/src/lib/clxx/exception.hpp -> clxx/exception.swg, clxx/exceptions.li.swg``
- ``#/src/lib/clxx/cl/device.hpp -> clxx/cl/device.swg, clxx/cl/device.li.swg``
- ``[...]``

The inclusion order is the following:

- file ``.i`` shall include its corresponding ``.li.i`` file,
- file ``.li.i`` includes one or more ``.swg`` files to gather module contents,
- file ``.swg`` includes its corresponding ``.li.swg`` file.

The ``.li.swg`` files are language-independent wrapper definitions. The
``.swg`` files are language dependent, and may be redefined under target
language subdirectories to provide workarounds and language-specific features.
For example, the wrappers for ``#/src/lib/clxx/cl/platform.hpp`` involve following
files

- ``clxx/cl/platform.li.swg`` - language independent part of the wrapper, includes
  ``#/src/lib/clxx/cl/platform.hpp``,
- ``clxx/cl/platform.swg`` - default language-dependent ``.swg`` file,
- ``python/clxx/cl/platform.swg`` - language-dependent ``.swg`` file for python.

The default ``.swg`` files will almost always contain just the
``%include <*.li.swg>`` directive (all necessary and language-agnostic code is
already in the ``.li.swg`` file).

target subtree(s) with bindings definition(s)
:::::::::::::::::::::::::::::::::::::::::::::

Bindings for particular languages are compiled from separate subtrees of clxx
source tree. For example, bindings for python are defined under
``#/src/lib/python-clxx/``. We'll call them  *target subtrees*.

A target subtree contains ``SConscript`` files which drive the compilation of
swig ``.i`` interfaces located under the target subtree. Usually, these target
``.i`` files define modules for target language and just ``%include``
appropriate ``.li.i`` files from this swig library to make-up the body of the
module.

When generating wrappers with swig, the top-level directory of the target
tree (``#/src/lib/python-clxx``, for example) must be in swig's include path
(the ``-I`` flag). The same applies to it's corresponding directory in variant
dir (``#/build/lib/python-clxx`` for example).

files that define modules: the ``.li.i`` and ``.i`` files
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

There are several files in this subtree that end with ``.li.i``. These are
"module files". An ``.li.i`` file usually includes all the contents of a
module located in ``.swg`` files (mentioned previously). It, however, has
no ``%module`` directive.

The ``.li.i`` files are designated for %inclusion in target ``.i`` files.
It is responsibility of the target subtree to define module names and location of
``.i`` files (target subtree layout don't have to be same as the swig
subtree). For python language, for example, we have such a correspondence:

- ``#/build/lib/python-clxx/clxx/exceptions.i`` %includes ``clxx/exceptions.li.i``
- ``#/build/lib/python-clxx/clxx/cl/platforms.i`` %includes ``clxx/cl/platforms.li.i``

.. _swig: https://swig.org

.. <!--- vim: set expandtab tabstop=2 shiftwidth=2 syntax=rst: -->
