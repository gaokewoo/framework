#ifndef __PLUGIN_HANDLER__
#define __PLUGIN_HANDLER__

#include "Plugin.h"

class PluginHandler : public Plugin 
{
    public:
        PluginHandler();

        ~PluginHandler(); 

        void initialize(int level,string configuration) 
        {
            printf("initialize\n");
        }

        void prepareForStart() 
        {
            printf("prepareForStart\n");
        }

        void start() 
        {
            printf("start\n");
        }

        void active() 
        {
            printf("active\n");
        }

        void passive() 
        {
            printf("passive\n");
        }

        void stop() 
        {
            printf("stop\n");
        }

        void prepareForUnload() 
        {
            printf("prepareForStop\n");
        }

        void destroy(int level) 
        {
            printf("destroy\n");
        }

        static Plugin * createPlugin();
        static void destroyPlugin(Plugin * p);

    private:
        PluginBridge * mpPluginBridge;
};

#endif

