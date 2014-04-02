#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <memory>
#include "SharedObject.h"
#include "Plugin.h"
#include "PluginHandler.h"
#include "PluginContainer.h"
#include "PluginBridge.h"
#include "RequestQueue.h"

using namespace std;

void testPlugin()
{
    auto_ptr<PluginBridge> mpPluginBridge;
    auto_ptr<RequestQueue> mpRequestQueue;

    PluginContainer pluginContainer;
    Plugin *plugin = pluginContainer.createPlugin("PluginHandler");
    mpRequestQueue.reset(new RequestQueue);
    mpPluginBridge.reset(new PluginBridge(plugin));

    mpRequestQueue->addObject(mpPluginBridge.get());
    mpRequestQueue->start();
}

int main()
{
    testPlugin();

    return 0;
}
