#include <iostream>
#include "plugin.h"

using namespace std;


class Test:public Plugin
{
    public:
        Test();
        ~Test();
        static Plugin * createPlugin();
        static void destroyPlugin(Plugin *);
        void Hello();
};