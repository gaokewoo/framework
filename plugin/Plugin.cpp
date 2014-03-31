#include "Plugin.h"

Plugin::Plugin()
{
    mpRequestQueue.reset(new RequestQueue);
    mpPluginBridge.reset(new PluginBridge(this));

    mpRequestQueue->addObject(mpPluginBridge);
}

Plugin::~Plugin()
{

}


