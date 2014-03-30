#include <iostream>
#include "SharedObject.h"
#include "Plugin.h"

using namespace std;

#ifndef __PLUGIN_CONTAINER__ 
#define __PLUGIN_CONTAINER__ 


class PluginContainer
{
    public:
        PluginContainer();
        ~PluginContainer();
        Plugin * createPlugin(string name);

    private:
        SharedObject * mpSharedObj;
        Plugin * mpPlugin;
        static const string CLASS_LENGTH;
        static const string CLASS_NAME;
        static const string CREATE_PLUGIN_FUNC;
        static const string DESTROY_PLUGIN_FUNC;

};

#endif

