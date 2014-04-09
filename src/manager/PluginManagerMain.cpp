#include <iostream>
#include <cstdlib>
#include <dlfcn.h>
#include "PluginManagerServer.h"
#include "PluginContainer.h"
#include "GLog.h"

using namespace std;

int main(int args,char* argv[])
{

    try
    {
        GLog & logger=GLog::getInstance();

        PluginManagerServer *pluginManagerServer = new PluginManagerServer();
        PluginContainer *pluginContainer = new PluginContainer();

        LOG(INFO) << "Hello glog." <<endl;
        LOG(ERROR) << "Hello glog." <<endl;

        pluginManagerServer->run();

        delete pluginManagerServer;
        pluginManagerServer=NULL;

        delete pluginContainer;
        pluginContainer=NULL;
    }
    catch(...)
    {
        cerr<<"new PluginManagerServer error."<<endl;

        exit(1);
    }
}

