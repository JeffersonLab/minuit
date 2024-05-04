dnl Process this file with autoconf to produce a configure script.
dnl
dnl Author: Paul F. Kunz <Paul_Kunz@slac.stanford.edu>
dnl

AC_INIT([Minuit2],[5.28.00],[edwards@jlab.org])
AM_CONFIG_HEADER(config.h)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(src/VariableMetricBuilder.cxx)

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_LANG([C++])
AC_PROG_RANLIB

dnl check STD C++ library
AC_CHECK_LIB(stdc++, main, LIBSTDCPP="lstdc++", LIBSTDCPP=)
dnl substitute this value 
AC_SUBST(LIBSTDCPP)

dnl Turn on -Wall if compiling with gcc
#AC_COMPILE_WARNINGS

dnl Initialise automake
AM_INIT_AUTOMAKE

AC_OPENMP
CFLAGS="$CFLAGS $OPENMP_CFLAGS"
CXXFLAGS="$CXXFLAGS $OPENMP_CXXFLAGS"

dnl files to be generated 
AC_CONFIG_FILES([Makefile inc/Makefile inc/Minuit2/Makefile inc/Math/Makefile src/Makefile 
  doc/Doxyfile doc/Makefile test/Makefile test/MnSim/Makefile 
  test/MnTutorial/Makefile ])
AC_OUTPUT

AC_MSG_RESULT([
    Minuit2 project now configured.
])
