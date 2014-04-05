AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealcontainer.la

INCLUDES=-I../thrift \
         -I../requestqueue \
         -I../sharedobject \
         -I../plugin \
         -I${SEAL_HOME}/thrift/include

libsealcontainer_la_SOURCES=PluginContainer.cpp  PluginContainer.h

libsealcontainer_la_LIBADD=-lsealsharedobject

libsealcontainer_la_LDFLAGS= -L$(top_srcdir)/src/sharedobject 
