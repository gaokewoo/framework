#include <iostream>
#include <cstdlib>
#include "PluginManagerServer.h"

using namespace std;

int main(int args,char* argv[])
{

    try
    {
        PluginManagerServer *pluginManagerServer = new PluginManagerServer();

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

