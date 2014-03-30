#ifndef __PLUGIN__
#define __PLUGIN__

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory>
#include "PluginBridge.h"

using namespace std;


class PluginBridge;
class Plugin
{
    public:
        Plugin();

        //virtual ~Plugin();

        virtual void initialize(int level,string configuration)=0;

        virtual void prepareForStart()=0;

        virtual void start()=0;

        virtual void active()=0;

        virtual void passive()=0;

        virtual void stop()=0;

        virtual void prepareForUnload()=0;

        virtual void destroy(int level)=0;

    private:
        auto_ptr<PluginBridge> mpPluginBridge;

};

#endif

