service PluginManagerServant
{
    string load(1:string pluginInfo);
    void unload(1:string pluginInfo);
    void killContainer(1:string containerName);
    void updateHostList(1:string newHostList);
}
