#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <dlfcn.h>
#include <memory>
#include "Plugin.h"

using namespace std;

#ifndef __SHAREDOBJECT__
#define __SHAREDOBJECT__

typedef PluginIf* CreateType(); 
typedef void DestroyType(PluginIf*); 

class SharedObject
{
    public:
        SharedObject(string pluginName,string soName);
        ~SharedObject();
        PluginIf * createPlugin();
        void destroyPlugin(PluginIf * p);

    private:
        string m_pluginName;
        string m_soName;
        void * handler;
        CreateType * createRef;
        DestroyType * destroyRef;
        PluginIf * plugin;
        static const string CLASS_LENGTH;
        static const string CLASS_NAME;
        static const string CREATE_PLUGIN_FUNC;
        static const string DESTROY_PLUGIN_FUNC;

};

#endif

