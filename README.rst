clxx - c++11 wrappers for OpenCL
================================

.. image:: https://travis-ci.org/ptomulik/clxx.png?branch=master
    :target: https://travis-ci.org/ptomulik/clxx

.. image:: https://coveralls.io/repos/ptomulik/clxx/badge.png?branch=master
   :target: https://coveralls.io/r/ptomulik/clxx?branch=master



Welcome to the clxx development tree.

START
-----

Start with cloning this repository (note: we use git submodules so we need
``--recursive`` flag):

.. code:: bash

    git clone --recursive git://github.com/ptomulik/clxx.git

HOWTO
-----

See files under ``HOWTO/`` directory to read about most common routines. There
are several documents.

For everyone:

==================================== ===========================================
           File                              Description
==================================== ===========================================
 `HOWTO/compile.rst`_                 compiling the sources
==================================== ===========================================

For clxx developers:

==================================== ===========================================
            File                              Description
==================================== ===========================================
 `HOWTO/create-source.rst`_           creating new source file
------------------------------------ -------------------------------------------
 `HOWTO/test.rst`_                    running tests
==================================== ===========================================


DIRECTORY STRUCTURE
-------------------

Top level source directory contains following subdirs:

================= ==============================================================
    Directory      Description
================= ==============================================================
 ``bin/``          contains mainainer scripts and additional utilities,
----------------- --------------------------------------------------------------
 ``build/``        this is main (default) variant directory, all the results of
                   compilation go there; the directory is created by scons,
----------------- --------------------------------------------------------------
 ``HOWTO/``        several HOWTO documents are placed here,
----------------- --------------------------------------------------------------
 ``debian/``       debian packaging files (currently empty),
----------------- --------------------------------------------------------------
 ``rpm/``          rpm packaging files (currently empty)
----------------- --------------------------------------------------------------
 ``site_scons/``   extensions used by scons,
----------------- --------------------------------------------------------------
 ``src/``          main source tree with source files to be compiled,
----------------- --------------------------------------------------------------
 ``template/``     templates for source files,
----------------- --------------------------------------------------------------
 ``valgrind/``     configuration files for valgrind
================= ==============================================================

.. _HOWTO/compile.rst: HOWTO/compile.rst
.. _HOWTO/create-source.rst: HOWTO/create-source.rst
.. _HOWTO/test.rst: HOWTO/test.rst

LICENSE
-------

@COPYRIGHT@

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE

.. <!--- vim: set expandtab tabstop=2 shiftwidth=2 syntax=rst: -->
