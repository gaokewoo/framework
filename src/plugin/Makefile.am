AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealplugin.la

INCLUDES=-I../thrift \
         -I../requestqueue \
         -I${SEAL_HOME}/thrift/include

libsealplugin_la_SOURCES=PluginBridge.cpp  PluginBridge.h  Plugin.cpp  Plugin.h
