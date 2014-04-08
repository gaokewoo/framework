AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealtest.la

INCLUDES=-I${SEAL_HOME}/thrift/include \
         -I${top_srcdir}/src/thrift \
         -I${top_srcdir}/src/requestqueue \
         -I${top_srcdir}/src/plugin

libsealtest_la_SOURCES=PluginHandler.cpp  PluginHandler.h
