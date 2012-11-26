# Init autoconf
AC_INIT([esl], [0.1])

# Put auxiliary files in build/
AC_CONFIG_AUX_DIR([build])

# Init automake
AM_INIT_AUTOMAKE([foreign -Wall -Werror -Wno-portability subdir-objects])

# Check for a C++ compiler
AC_PROG_CXX

# Check for flex
AC_PROG_LEX

# Check for bison
AC_PROG_YACC

# Safety check. Ensure autoconf is not being run from outer space
AC_CONFIG_SRCDIR([AUTHORS])

# Declare src/config.h as output header
AC_CONFIG_HEADERS([src/config.h])

# Declare output files
AC_CONFIG_FILES([Makefile])

# Actually output said files
AC_OUTPUT
