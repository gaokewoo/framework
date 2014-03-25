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
const string DESTROY_PLUGIN_FUNC="_ZN%classlength%%classname%13destroyPluginEPS_";
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
    string create_func_name = CREATE_PLUGIN_FUNC;
    create_func_name.replace(create_func_name.index(CLASS_LENGTH,0),CLASS_LENGTH.length(),plugin_name.length());
    create_func_name.replace(create_func_name.index(CLASS_NAME,0),CLASS_NAME.length(),plugin_name);
    cout<<create_func_name<<endl;
    create_t* create_plugin = (create_t*)dlsym(handle,CREATE_PLUGIN_FUNC);
    char *error = dlerror();
    if(error != NULL)
    {
        printf("dlsym createPlugin failed,%s\n",error);
        dlclose(handle);
        handle = NULL;

        return -1;
    }

    destroy_t* destroy_plugin = (destroy_t*)dlsym(handle,DESTROY_PLUGIN_FUNC);
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
