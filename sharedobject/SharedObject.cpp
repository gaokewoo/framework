#include "SharedObject.h"

SharedObject::SharedObject(string soName)
{
    handler = dlopen(soName.c_str(),RTLD_LAZY|RTLD_GLOBAL);
    if(handler == NULL)
    {
        cerr<<"dlopen file error,errorinfo="<<dlerror()<<endl;
        
        throw;
    }
}

void * SharedObject::symbol(string pluginName)
{
    return dlsym(handler,pluginName.c_str());
}

SharedObject::~SharedObject()
{
    dlclose(handler);
    handler = NULL;
}

