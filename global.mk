CC_FLAGS= -g3 -Wall -fpic
CC=g++
AR_CMD=ar -rv

SUBDIRS=tinyxml2 container plugin controller 

#define lib path
SEAL_LIB_PATH=$(SEAL_DEV_HOME)/lib/
SEAL_LIBS=$(SEAL_LIB_PATH)/ -ltinyxml2 -lsealcontainer -lsealplugin

#define plugin path
SEAL_PLUGIN_INCLUDE=$(SEAL_DEV_HOME)/plugin/
SEAL_CONTAINER_INCLUDE=$(SEAL_DEV_HOME)/container/
SEAL_CONTROLLER_INCLUDE=$(SEAL_DEV_HOME)/controller/

#tinyxml2
TINYXML2_INCLUDE=$(SEAL_DEV_HOME)/tinyxml2/

#gmock dir
GMOCK_INCLUDE=$(SEAL_DEV_HOME)/gmock/include/
GTEST_INCLUDE=$(SEAL_DEV_HOME)/gmock/gtest/include/

#thrift dir
THRIFT_INCLUDE=$(SEAL_HOME)/thrift/include/
THRIFT_LIBS=$(SEAL_HOME)/thrift/lib -lthrift

#zerozmq dir
ZMQ_INCLUDE=$(SEAL_HOME)/libzmq/include/
ZMQ_LIBS=$(SEAL_HOME)/zeromq/lib -lzmq


CC_INCLDIR=-I. \
		   -I$(THRIFT_INCLUDE)/ \
		   -I$(ZMQ_INCLUDE)/ \
		   -I$(GMOCK_INCLUDE)/ \
		   -I$(GTEST_INCLUDE)/ \
		   -I$(TINYXML2_INCLUDE) \
		   -I$(SEAL_PLUGIN_INCLUDE) \
		   -I$(SEAL_CONTAINER_INCLUDE) \
		   -I$(SEAL_CONTROLLER_INCLUDE) \
		   -I/usr/include

LIBS= -L$(SEAL_LIBS) -L$(THRIFT_LIBS) -L$(ZMQ_LIBS) -ldl -lpthread
