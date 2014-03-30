#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <memory>
#include "SharedObject.h"
#include "Plugin.h"
#include "PluginHandler.h"
#include "PluginContainer.h"

using namespace std;

void testPlugin()
{
    PluginContainer pluginContainer;
    Plugin *plugin = pluginContainer.createPlugin("PluginHandler");
    plugin->start();
}

int main()
{
    testPlugin();

    return 0;
}
