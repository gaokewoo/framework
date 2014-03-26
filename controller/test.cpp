#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <memory>
#include "SharedObject.h"
#include "Plugin.h"

using namespace std;

void testPlugin()
{
    SharedObject object("PluginHandler","../lib/libsealtest.so");
    PluginIf *plugin = object.createPlugin();
    plugin->start();
}

int main()
{
    testPlugin();

    return 0;
}
