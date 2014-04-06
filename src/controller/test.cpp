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
#include "PluginParser.h"

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
    //testPlugin();
    PluginParser myPluginParser("../../config/plugin.xml");
    vector<PluginInfo> v_pluginInfo = myPluginParser.getPluginInfo();
    vector<PluginInfo>::iterator it;
    for(it=v_pluginInfo.begin();it!=v_pluginInfo.end();++it)
    {
        cout<<it->m_pluginName<<":"<<it->m_soName<<endl;
    }

    return 0;
}
