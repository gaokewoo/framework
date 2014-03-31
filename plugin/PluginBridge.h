#ifndef __PLUGINBRIDGE__
#define __PLUGINBRIDGE__

#include <iostream>
#include <memory>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "gen-cpp/PluginServant.h"
#include "Plugin.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace std;

class Plugin;
class PluginBridge:public PluginServantIf
{
    public:
        PluginBridge(Plugin *p);

        ~PluginBridge();

        void initialize(const int level,const string & configuration);

        void prepareForStart();

        void start();

        void active();

        void passive();

        void stop();

        void prepareForUnload();

        void destroy(const int level);

        int getState(){ return miState; }

    private:
        int miState;
        auto_ptr<Plugin> mpPlugin;

};

#endif

