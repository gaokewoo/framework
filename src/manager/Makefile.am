AUTOMAKE_OPTIONS=foreign

INCLUDES=-I../tinyxml2 \
         -I../thrift \
         -I../thread \
         -I../requestqueue \
         -I../sharedobject \
         -I../plugin \
         -I../container \
         -I../test \
         -I${SEAL_HOME}/thrift/include

bin_PROGRAMS=PluginManagerMain

PluginManagerMain_SOURCES=PluginManagerMain.cpp  PluginManagerServer.cpp  PluginManagerServer.h


PluginManagerMain_LDADD=-lthrift \
           -lsealtinyxml2 \
           -lsealthrift \
           -lsealthread \
           -lsealrequestqueue \
           -lsealsharedobject \
           -lsealplugin \
           -lsealcontainer \
           -lsealtest

PluginManagerMain_LDFLAGS=-L${SEAL_HOME}/thrift/lib \
             -L$(top_srcdir)/src/tinyxml2 \
             -L$(top_srcdir)/src/thrift \
             -L$(top_srcdir)/src/thread \
             -L$(top_srcdir)/src/requestqueue \
             -L$(top_srcdir)/src/sharedobject \
             -L$(top_srcdir)/src/plugin \
             -L$(top_srcdir)/src/container \
             -L$(top_srcdir)/src/test

