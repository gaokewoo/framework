#include "GLog.h"

GLog::GLog(string pluginName)
{
    google::InitGoogleLogging(pluginName.c_str());
}

GLog::~GLog()
{

}


