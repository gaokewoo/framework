#include <iostream>
using namespace std;
class Plugin
{
    public:
        Plugin(){};
        virtual ~Plugin(){};
        virtual void Hello()=0;
};

