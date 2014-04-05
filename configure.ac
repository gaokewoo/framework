#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([seal], 0.01, gaokewoo@126.com)
AC_PROG_LIBTOOL

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB


# Checks for libraries.
# FIXME: Replace `main' with a function in `-lsealcontainer':
AC_CHECK_LIB([sealcontainer], [main])
# FIXME: Replace `main' with a function in `-lsealplugin':
AC_CHECK_LIB([sealplugin], [main])
# FIXME: Replace `main' with a function in `-lsealrequestqueue':
AC_CHECK_LIB([sealrequestqueue], [main])
# FIXME: Replace `main' with a function in `-lsealsharedobject':
AC_CHECK_LIB([sealsharedobject], [main])
# FIXME: Replace `main' with a function in `-lsealtest':
AC_CHECK_LIB([sealtest], [main])
# FIXME: Replace `main' with a function in `-lsealthread':
AC_CHECK_LIB([sealthread], [main])
# FIXME: Replace `main' with a function in `-lsealthrift':
AC_CHECK_LIB([sealthrift], [main])
# FIXME: Replace `main' with a function in `-lsealtinyxml2':
AC_CHECK_LIB([sealtinyxml2], [main])
# FIXME: Replace `main' with a function in `-lthrift':
AC_CHECK_LIB([thrift], [main])

# Checks for header files.
AC_CHECK_HEADERS([limits.h stddef.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_CHECK_FUNCS([memset strchr])

AC_CONFIG_FILES([Makefile
                 src/container/Makefile
                 src/controller/Makefile
                 src/plugin/Makefile
                 src/requestqueue/Makefile
                 src/sharedobject/Makefile
                 src/test/Makefile
                 src/thread/Makefile
                 src/thrift/Makefile
                 src/tinyxml2/Makefile])

AC_CONFIG_SUBDIRS([3rd/gmock
                   3rd/glog])
AC_OUTPUT
