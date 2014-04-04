#include "PluginBridge.h"


PluginBridge::PluginBridge(Plugin *p)
{
    mpPlugin.reset(p);
}

PluginBridge::~PluginBridge()
{

}

void PluginBridge::initialize(const int level,const string & configuration)
{
    mpPlugin->initialize(level,configuration);
}

void PluginBridge::prepareForStart()
{
    mpPlugin->prepareForStart();
}

void PluginBridge::start()
{
    mpPlugin->start();
}

void PluginBridge::active()
{
    mpPlugin->active();
}

void PluginBridge::passive()
{
    mpPlugin->passive();
}

void PluginBridge::stop()
{
    mpPlugin->stop();
}

void PluginBridge::prepareForUnload()
{
    mpPlugin->prepareForUnload();
}

void PluginBridge::destroy(const int level)
{
    mpPlugin->destroy(level);
}
