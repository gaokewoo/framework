AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealrequestqueue.la

INCLUDES=-I../thrift \
         -I../thread \
         -I${SEAL_HOME}/thrift/include

libsealrequestqueue_la_SOURCES=RequestQueue.cpp  RequestQueue.h

libsealrequestqueue_la_LIBADD=-lthrift

libsealrequestqueue_la_LDFLAGS=-L${SEAL_HOME}/thrift/lib
