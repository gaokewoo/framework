AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealcontainer.la

INCLUDES=-I${SEAL_HOME}/thrift/include \
         -I${top_srcdir}/3rd/glog/src \
         -I${top_srcdir}/src/thrift \
         -I${top_srcdir}/src/requestqueue \
         -I${top_srcdir}/src/sharedobject \
         -I${top_srcdir}/src/plugin \
         -I${top_srcdir}/src/glog

libsealcontainer_la_SOURCES=PluginContainer.cpp  PluginContainer.h

libsealcontainer_la_LIBADD=-lsealsharedobject -lglog

libsealcontainer_la_LDFLAGS= -L$(top_srcdir)/src/sharedobject 
