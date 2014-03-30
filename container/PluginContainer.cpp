#include "PluginContainer.h"

const string PluginContainer::CLASS_LENGTH="%classlength%";
const string PluginContainer::CLASS_NAME="%classname%";
const string PluginContainer::CREATE_PLUGIN_FUNC="_ZN%classlength%%classname%12createPluginEv";
const string PluginContainer::DESTROY_PLUGIN_FUNC="_ZN%classlength%%classname%13destroyPluginEP6Plugin";

PluginContainer::PluginContainer()
{
    mpPlugin = NULL;
    mpSharedObj = new SharedObject("../lib/libsealtest.so");
}

PluginContainer::~PluginContainer()
{
    delete mpSharedObj;
    mpSharedObj=NULL;
}

Plugin * PluginContainer::createPlugin(string name)
{

    char pluginNameLength[20];
    snprintf(pluginNameLength,sizeof(pluginNameLength),"%ld",name.length());

    string create_func_name = CREATE_PLUGIN_FUNC;
    create_func_name.replace(create_func_name.find_first_of(CLASS_LENGTH,0),CLASS_LENGTH.length(),pluginNameLength);
    create_func_name.replace(create_func_name.find_first_of(CLASS_NAME,0),CLASS_NAME.length(),name.c_str());

    Plugin * (*createRef)();//func pointer 
    createRef = reinterpret_cast<Plugin * (*)()>(mpSharedObj->symbol(create_func_name));
    if((Plugin * (*) ())0 == createRef)
    {
        cerr<<"get createPlugin func pointer failed"<<endl;
        
        throw;
    }

    string destroy_func_name = DESTROY_PLUGIN_FUNC;
    destroy_func_name.replace(destroy_func_name.find_first_of(CLASS_LENGTH,0),CLASS_LENGTH.length(),pluginNameLength);
    destroy_func_name.replace(destroy_func_name.find_first_of(CLASS_NAME,0),CLASS_NAME.length(),name.c_str());

    void (*destroyRef)(Plugin *);//func pointer 
    destroyRef = reinterpret_cast<void (*)(Plugin *)>(mpSharedObj->symbol(destroy_func_name));
    if((void (*)(Plugin *))0 == destroyRef)
    {
        cerr<<"get destroyPlugin func pointer failed"<<endl;

        throw;
    }

    // create an instance of the class
    mpPlugin = createRef();
    if(mpPlugin == NULL)
    {
        cerr<<"create plugin instance failed"<<endl;

        throw;

    }

    return mpPlugin;

}

