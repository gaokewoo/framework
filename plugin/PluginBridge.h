#include <iostream>
#include <memory>
#include "Plugin.h"

using namespace std;

#ifndef __PLUGINBRIDGE__
#define __PLUGINBRIDGE__

class PluginBridge
{
    public:
        PluginBridge(Plugin *p);

        ~PluginBridge();

        void initialize(int level,string configuration);

        void prepareForStart();

        void start();

        void active();

        void passive();

        void stop();

        void prepareForUnload();

        void destroy(int level);

    private:
        auto_ptr<Plugin> mpPlugin;

};

#endif

