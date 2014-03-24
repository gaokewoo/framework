#include <iostream>
#include "plugin.hh"

using namespace std;

extern "C" Plugin * createPlugin();
extern "C" void destroyPlugin(Plugin *);

class Test:public Plugin
{
    public:
        void Hello();
};
