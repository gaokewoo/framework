AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealrequestqueue.la

INCLUDES=-I${SEAL_HOME}/thrift/include \
         -I${top_srcdir}/src/thrift \
         -I${top_srcdir}/src/thread

libsealrequestqueue_la_SOURCES=RequestQueue.cpp  RequestQueue.h

libsealrequestqueue_la_LIBADD=-lthrift -lsealthread -lsealthrift

libsealrequestqueue_la_LDFLAGS=-L${SEAL_HOME}/thrift/lib \
                               -L$(top_srcdir)/src/thrift \
                               -L$(top_srcdir)/src/thread
