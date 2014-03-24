#include "test.hh"

extern "C" Plugin * createPlugin()
{
    return new Test();
}

extern "C" void destroyPlugin(Plugin *p)
{
    delete p;
}

void Test::Hello()
{
    cout<<"Hello World."<<endl;
}
