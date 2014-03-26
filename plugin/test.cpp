#include "test.h"

Test::Test()
{
}

Test::~Test()
{
}

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
