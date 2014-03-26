#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <dlfcn.h>
#include <memory>
#include "../plugin/plugin.h"

using namespace std;

#ifndef __SHAREDOBJECT__
#define __SHAREDOBJECT__

typedef Plugin* CreateType(); 
typedef void DestroyType(Plugin*); 

class SharedObject
{
    public:
        SharedObject(string pluginName,string soName);
        ~SharedObject();
        Plugin * createPlugin();
        void destroyPlugin(Plugin * p);

    private:
        string m_pluginName;
        string m_soName;
        void * handler;
        CreateType * createRef;
        DestroyType * destroyRef;
        Plugin * plugin;
        static const string CLASS_LENGTH;
        static const string CLASS_NAME;
        static const string CREATE_PLUGIN_FUNC;
        static const string DESTROY_PLUGIN_FUNC;

};

#endif

