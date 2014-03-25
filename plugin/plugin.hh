#include <iostream>
using namespace std;
class Plugin
{
    public:
        virtual Plugin * createPlugin()=0;
        virtual void destroyPlugin(Plugin *)=0;
        virtual void Hello()=0;
};

