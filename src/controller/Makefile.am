AUTOMAKE_OPTIONS=foreign

INCLUDES=-I${SEAL_HOME}/thrift/include \
         -I${top_srcdir}/src/tinyxml2 \
         -I${top_srcdir}/src/thrift \
         -I${top_srcdir}/src/thread \
         -I${top_srcdir}/src/requestqueue \
         -I${top_srcdir}/src/sharedobject \
         -I${top_srcdir}/src/plugin \
         -I${top_srcdir}/src/container \
         -I${top_srcdir}/src/test

bin_PROGRAMS=test

test_SOURCES=test.cpp PluginParser.cpp PluginParser.h


test_LDADD=-lthrift \
           -lsealtinyxml2 \
           -lsealthrift \
           -lsealthread \
           -lsealrequestqueue \
           -lsealsharedobject \
           -lsealplugin \
           -lsealcontainer \
           -lsealtest

test_LDFLAGS=-L${SEAL_HOME}/thrift/lib \
             -L$(top_srcdir)/src/tinyxml2 \
             -L$(top_srcdir)/src/thrift \
             -L$(top_srcdir)/src/thread \
             -L$(top_srcdir)/src/requestqueue \
             -L$(top_srcdir)/src/sharedobject \
             -L$(top_srcdir)/src/plugin \
             -L$(top_srcdir)/src/container \
             -L$(top_srcdir)/src/test

