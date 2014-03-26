#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <memory>
#include "../plugin/plugin.hh"

using namespace std;

const string CLASS_LENGTH="%classlength%";
const string CLASS_NAME="%classname%";
const string CREATE_PLUGIN_FUNC="_ZN%classlength%%classname%12createPluginEv";
const string DESTROY_PLUGIN_FUNC="_ZN%classlength%%classname%13destroyPluginEP6Plugin";
// the types of the class factories                                                                                              
typedef Plugin* create_t(); 
typedef void destroy_t(Plugin*); 

int main()
{

    void * handle = dlopen("../lib/libsealplugin.so",RTLD_NOW);
    if(handle == NULL)
    {
        printf("dlopen file error,errorinfo=%s\n",dlerror());

        return -1;
    }

    // reset errors
    dlerror();
 
    string plugin_name = "Test";
    char plugin_name_length[20];
    snprintf(plugin_name_length,sizeof(plugin_name_length),"%d",plugin_name.length());

    string create_func_name = CREATE_PLUGIN_FUNC;
    create_func_name.replace(create_func_name.find_first_of(CLASS_LENGTH,0),CLASS_LENGTH.length(),plugin_name_length);
    create_func_name.replace(create_func_name.find_first_of(CLASS_NAME,0),CLASS_NAME.length(),plugin_name);
    create_t* create_plugin = (create_t*)dlsym(handle,create_func_name.c_str());
    char *error = dlerror();
    if(error != NULL)
    {
        printf("dlsym createPlugin failed,%s\n",error);
        dlclose(handle);
        handle = NULL;

        return -1;
    }

    string destroy_func_name = DESTROY_PLUGIN_FUNC;
    destroy_func_name.replace(destroy_func_name.find_first_of(CLASS_LENGTH,0),CLASS_LENGTH.length(),plugin_name_length);
    destroy_func_name.replace(destroy_func_name.find_first_of(CLASS_NAME,0),CLASS_NAME.length(),plugin_name);

    destroy_t* destroy_plugin = (destroy_t*)dlsym(handle,destroy_func_name.c_str());
    error = dlerror();
    if(error != NULL)
    {
        printf("dlsym destroyPlugin failed,%s\n",error);
        dlclose(handle);
        handle = NULL;

        return -1;
    }

    // create an instance of the class
    Plugin * plugin = create_plugin();

    //use the instance
    plugin->Hello();

    //destroy the instance
    destroy_plugin(plugin);
   
    dlclose(handle);
    handle = NULL;

    return 0;
}
