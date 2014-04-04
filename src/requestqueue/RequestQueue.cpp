#include "RequestQueue.h"
#include "Thread.h"

PluginServantIf* RequestQueue::mpPlugin = NULL;
list<PluginServantIf*> RequestQueue::mlistPluginServant;

RequestQueue::RequestQueue()
{
}


RequestQueue::~RequestQueue()
{
}

void RequestQueue::addObject(PluginServantIf *p)
{
    mlistPluginServant.push_back(p);
    mpPlugin = p;
}

void * RequestQueue::run(void *)
{
    int port = 9090;                                                                                                                   
    shared_ptr<PluginServantIf> handler(mpPlugin);
    shared_ptr<TProcessor> processor(new PluginServantProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
}

void RequestQueue::start()
{
    /*list<PluginServantIf*>::const_iterator iter;
    for(iter = mlistPluginServant.begin();iter != mlistPluginServant.end();++iter)
    {
        cout<<*iter;
    }*/

    Thread myfunc;
    myfunc.makeThreadFunc(&run);
    myfunc.start();
    myfunc.join();
}

void RequestQueue::stop()
{

}

