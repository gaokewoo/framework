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

        enum LOG_LEVEL{INFO=0,WARNING,ERROR,FATAL};

        void setLogFilenameExtension(string extension);
        void setLogDestination(LOG_LEVEL level,string prefix);

    private:
        GLog();
        GLog(const GLog&){}
        GLog & operator = (const GLog&){}
        google::LogSeverity getMappingLevel(LOG_LEVEL level);

};

#endif

