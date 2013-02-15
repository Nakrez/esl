AC_INIT([esl], [PRE-ALPA], [b.covolato@gmail.com])

AC_CONFIG_AUX_DIR([build])

AM_INIT_AUTOMAKE([foreign -Wall -Werror dist-bzip2 subdir-objects])

AM_PROG_AR

LT_INIT(shared)

AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_YACC
AC_PROG_CXX
AC_PROG_LEX
AC_PROG_MAKE_SET

# Checks for libraries.
AC_CHECK_LIB([dl], [dlopen])
AC_CHECK_LIB([dl], [dlsym])
AC_CHECK_LIB([dl], [dlclose])

# Checks for header files.
AC_CHECK_HEADERS([sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([gettimeofday])

AC_CONFIG_FILES(Makefile)

AC_OUTPUT
