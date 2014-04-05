AUTOMAKE_OPTIONS=foreign

INCLUDES=-I../tinyxml2 \
         -I../thrift \
         -I../thread \
         -I../requestqueue \
         -I../sharedobject \
         -I../plugin \
         -I../container

bin_PROGRAMS=test

test_SOURCES=test.cpp

test_LDADD=-lsealtinyxml2 -lsealthrift -lsealthread -lsealrequestqueue -lsealsharedobject -lsealplugin -lsealcontainer

test_LDFLAGS=-L$(top_srcdir)/src/tinyxml2 \
             -L$(top_srcdir)/src/thrift \
             -L$(top_srcdir)/src/thread \
             -L$(top_srcdir)/src/requestqueue \
             -L$(top_srcdir)/src/sharedobject \
             -L$(top_srcdir)/src/plugin \
             -L$(top_srcdir)/src/container

