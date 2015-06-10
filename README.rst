pkg-clxx
========

This projects maintains the packaging and releasing process of clxx_ library.

- for debian packages we use git-buildpackage_,

Branches
--------

The repository contains several separate branches for different purposes

+---------------------------------+-----------------------------------------------------------------------------------------------------------+
| Branch                          | Purpose                                                                                                   |
+=================================+===========================================================================================================+
| *default*                       | default branch with common scripts, instructions and files, not used for actual packaging                 |
+---------------------------------+-----------------------------------------------------------------------------------------------------------+
| *debian-debian/<release>*       | the Debian packaging for a <release> (e.g., jessie, wheezy, sid or experimental)                          |
+---------------------------------+-----------------------------------------------------------------------------------------------------------+
| *debian-upstream/<release>*     | the upstream sources for a release matching one of the above                                              |
+---------------------------------+-----------------------------------------------------------------------------------------------------------+
| *debian-security/<release>*     | security updates for a certain release                                                                    |
+---------------------------------+-----------------------------------------------------------------------------------------------------------+
| *debian-backports/<release>*    | backports to a certain release                                                                            |
+---------------------------------+-----------------------------------------------------------------------------------------------------------+
| *debian-dfsg/<release>*         | the dfsg clean upstream sources in case the cleanup is done via a Git merge from upstream to this branch. |
+---------------------------------+-----------------------------------------------------------------------------------------------------------+


Tasks
-----

General: Creating soruce tarball
````````````````````````````````

- Create tarball out of upstream's ``v0.1.1`` tag::

    git checkout default
    ./scripts/create-tarball v0.1.1

- Create source tarball from most recent upstream commit::

    git checkout default
    ./scripts/create-tarball master

The script requires an access to temporary directory (usually ``/tmp``, see
``mktemp(1)``) where it clones the upstream repository and manipulates files.


Debian: Creating soruce tarball
```````````````````````````````

- Create normal source tarball and rename it appropriatelly::

    git checkout default
    ./scripts/create-tarball v0.1.1
    mv ../clxx-0.1.1.tar.gz ../clxx0_0.1.1.orig.tar.gz

Debian: Enable support for new Debian release
`````````````````````````````````````````````

In the following replace ``stretch`` with your preferred release codename.

- Prepare initial ``debian`` directory::

    git checkout default
    rm -rf debian.stretch
    ./scripts/create-debian-release stretch 0.1.1

  this shall create ``debian.stretch`` with the initial contents of ``debian``
  directory for stretch release.

- create branch for debian upstream::

    git checkout --orphan debian-upstream/stretch
    git rm -rf --cached .
    git commit --allow-empty -m 'initial commit for debian-upstream/stretch'

- create branch for debian packaging::

    git checkout -b debian-debian/stretch
    git commit --allow-empty -m 'initial commit for debian-debian/stretch'


- add ``debian/`` directory to ``debian-debian/stretch`` branch::

    git checkout debian-debian/stretch
    rm -rf debian/
    mv debian.stretch debian
    git add debian
    git commit -m 'added debian/ directory'


- prepare a source tarball::

    git checkout default
    ./scripts/create-tarball v0.1.1
    mv ../clxx-0.1.1.tar.gz ../clxx0.1_0.1.1.orig.tar.gz

- import the source tarball::

    git checkout debian-debian/stretch
    gbp import-orig ../clxx_0.1.1.orig.tar.gz

- build the package::

    gbp buildpackage

  or (parallel build, 12 jobs)::

    DEB_BUILD_OPTIONS="parallel=12" gbp buildpackage 


Debian: Build package
`````````````````````

.. code::

    git checkout debian-debian/stretch
    debian/rules clean
    gbp buildpackage

Debian: New release of package
``````````````````````````````

.. code::

    git checkout debian-debian/stretch
    gbp dch --release --auto

.. _clxx: https://github.com/ptomulik/clxx
.. _git-buildpackage: https://honk.sigxcpu.org/piki/projects/git-buildpackage/
.. _gbp-manual: http://honk.sigxcpu.org/projects/git-buildpackage/manual-html/gbp.html

.. <!--- vim: set expandtab tabstop=2 shiftwidth=2 syntax=rst: -->
