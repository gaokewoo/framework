AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=libsealglog.la

INCLUDES= -I${SEAL_HOME}/glog/include

libsealglog_la_SOURCES=GLog.cpp  GLog.h

libsealglog_la_LIBADD=-lglog

libsealglog_la_LDFLAGS=-L${SEAL_HOME}/glog/lib
