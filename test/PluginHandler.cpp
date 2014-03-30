#include "PluginHandler.h"


Plugin * PluginHandler::createPlugin()
{
    return new PluginHandler();
}

void PluginHandler::destroyPlugin(Plugin *p)
{
    delete p;
}

PluginHandler::PluginHandler()
{
}

PluginHandler::~PluginHandler()
{

}

