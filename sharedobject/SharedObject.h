#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <dlfcn.h>
#include <memory>

using namespace std;

#ifndef __SHAREDOBJECT__
#define __SHAREDOBJECT__

class SharedObject
{
    public:
        SharedObject(string soName);
        ~SharedObject();
        void * symbol(string pluginName);

    private:
        void * handler;
};

#endif

