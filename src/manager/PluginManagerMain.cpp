#include <iostream>
#include <cstdlib>
#include "PluginManagerServer.h"
#include "GLog.h"

using namespace std;

int main(int args,char* argv[])
{

    try
    {
        GLog & logger=GLog::getInstance();

        PluginManagerServer *pluginManagerServer = new PluginManagerServer();

        LOG(INFO) << "Hello glog." <<endl;

        pluginManagerServer->run();

        delete pluginManagerServer;
        pluginManagerServer=NULL;
    }
    catch(...)
    {
        cerr<<"new PluginManagerServer error."<<endl;

        exit(1);
    }
}

