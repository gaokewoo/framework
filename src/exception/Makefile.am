AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealstandardexception.la

INCLUDES=-I${SEAL_HOME}/thrift/include

libsealstandardexception_la_SOURCES=StandardException.cpp  StandardException.h

libsealstandardexception_la_LIBADD=-lthrift

libsealstandardexception_la_LDFLAGS=-L${SEAL_HOME}/thrift/lib
