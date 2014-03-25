#include "test.hh"

Plugin * Test::createPlugin()
{
    return new Test();
}

void Test::destroyPlugin(Plugin *p)
{
    delete p;
}

void Test::Hello()
{
    cout<<"Hello World."<<endl;
}
