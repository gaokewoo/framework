AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealtest.la

INCLUDES=-I../thrift \
         -I../requestqueue \
         -I../plugin \
         -I${SEAL_HOME}/thrift/include

libsealtest_la_SOURCES=PluginHandler.cpp  PluginHandler.h
