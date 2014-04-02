#ifndef __REQUEST_QUEUE__
#define __REQUEST_QUEUE__

#include <iostream>
#include <list>

#include "gen-cpp/PluginServant.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace std;

class RequestQueue
{
    public:
        RequestQueue();
        ~RequestQueue();

        void addObject(PluginServantIf *p);
        static void* run(void *);
        void start();
        void stop();

    private:
        static list<PluginServantIf*> mlistPluginServant;
        static PluginServantIf *mpPlugin; //a tmp member variable, it will be deleted in future

};

#endif

