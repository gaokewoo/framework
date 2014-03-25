#include <iostream>
#include "plugin.hh"

using namespace std;


class Test:public Plugin
{
    public:
        Plugin * createPlugin();
        void destroyPlugin(Plugin *);
        void Hello();
};
