#include "Plugin.h"

Plugin::Plugin()
{
    mpPluginBridge.reset(new PluginBridge(this));
}

/*Plugin::~Plugin()
{

}*/

