#include "RequestQueue.h"

RequestQueue::RequestQueue()
{
}


RequestQueue::~RequestQueue()
{
}

void RequestQueue::addObject(PluginServantIf *p)
{
    mlistPluginServant.push_back(p);

    int port = 9090;                                                                                                                   
    shared_ptr<PluginServantIf> handler(p);
    shared_ptr<TProcessor> processor(new PluginServantProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
}

void RequestQueue::start()
{

}

void RequestQueue::stop()
{

}

