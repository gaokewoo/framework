#include "SharedObject.hh"

const string SharedObject::CLASS_LENGTH="%classlength%";
const string SharedObject::CLASS_NAME="%classname%";
const string SharedObject::CREATE_PLUGIN_FUNC="_ZN%classlength%%classname%12createPluginEv";
const string SharedObject::DESTROY_PLUGIN_FUNC="_ZN%classlength%%classname%13destroyPluginEP6Plugin";

SharedObject::SharedObject(string pluginName,string soName):m_pluginName(pluginName),m_soName(soName)
{
    handler = dlopen(m_soName.c_str(),RTLD_NOW);
    if(handler == NULL)
    {
        cerr<<"dlopen file error,errorinfo="<<dlerror()<<endl;
        
        throw;
    }

}

SharedObject::~SharedObject()
{
    //destroy the instance
    destroyRef(plugin);
   
    dlclose(handler);
    handler = NULL;
}

Plugin * SharedObject::createPlugin()
{

    // reset errors
    dlerror();
 
    char pluginNameLength[20];
    snprintf(pluginNameLength,sizeof(pluginNameLength),"%ld",m_pluginName.length());

    string create_func_name = CREATE_PLUGIN_FUNC;
    create_func_name.replace(create_func_name.find_first_of(CLASS_LENGTH,0),CLASS_LENGTH.length(),pluginNameLength);
    create_func_name.replace(create_func_name.find_first_of(CLASS_NAME,0),CLASS_NAME.length(),m_pluginName.c_str());
    createRef = (CreateType*)dlsym(handler,create_func_name.c_str());
    char *error = dlerror();
    if(error != NULL)
    {
        cerr<<"dlsym createPlugin failed"<<error<<endl;
        dlclose(handler);
        handler = NULL;
        
        throw;
    }

    string destroy_func_name = DESTROY_PLUGIN_FUNC;
    destroy_func_name.replace(destroy_func_name.find_first_of(CLASS_LENGTH,0),CLASS_LENGTH.length(),pluginNameLength);
    destroy_func_name.replace(destroy_func_name.find_first_of(CLASS_NAME,0),CLASS_NAME.length(),m_pluginName.c_str());

    destroyRef = (DestroyType*)dlsym(handler,destroy_func_name.c_str());
    error = dlerror();
    if(error != NULL)
    {
        cerr<<"dlsym destroyPlugin failed"<<error<<endl;
        dlclose(handler);
        handler = NULL;

        throw;
    }

    // create an instance of the class
    plugin = createRef();
    if(plugin == NULL)
    {
        cerr<<"create plugin instance failed"<<endl;
        dlclose(handler);
        handler = NULL;

        throw;

    }

    return plugin;

}

