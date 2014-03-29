#include <iostream>

using namespace std;

#ifndef __PLUGIN__
#define __PLUGIN__

class Plugin
{
    public:
        void initialize(int level,string configuration) {}

        void prepareForStart() {}

        void start() {}

        void active() {}

        void passive() {}

        void stop() {}

        void prepareForUnload() {}

        void destroy(int level) {}

};

#endif

