AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealplugin.la

INCLUDES=-I${SEAL_HOME}/thrift/include \
         -I${top_srcdir}/src/thrift \
         -I${top_srcdir}/src/requestqueue

libsealplugin_la_SOURCES=PluginBridge.cpp  PluginBridge.h  Plugin.cpp  Plugin.h
