#ifndef __GLOG__
#define __GLOG__

#include <iostream>
#include <glog/logging.h>

using namespace std;

class GLog
{
    public:
        static GLog & getInstance()
        {
            static GLog instance;

            return instance;
        }

        enum {INFO=0,WARNING,ERROR,FATAL};

    private:
        GLog();
        GLog(const GLog&){}
        GLog & operator = (const GLog&){}
        google::LogSeverity getMappingLevel(int level);

};

#endif

