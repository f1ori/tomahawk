# Find libphonon
# Once done this will define
#
#  PHONON_FOUND    - system has Phonon Library
#  PHONON_INCLUDES - the Phonon include directory
#  PHONON_LIBS     - link these to use Phonon
#  PHONON_VERSION  - the version of the Phonon Library

# Copyright (c) 2008, Matthias Kretz <kretz@kde.org>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.


find_package(Phonon4Qt5 NO_MODULE)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Phonon4Qt5  DEFAULT_MSG  Phonon4Qt5_DIR )