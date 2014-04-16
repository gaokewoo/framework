#include "Configuration.h"

Configuration & Configuration::getInstance()
{
    static Configuration instance;

    return instance;
}

Configuration::Configuration()
{
    System & mySystem=System::getInstance();
    string filePath=mySystem.getSealConfigurationHome()+"/config.ini";

    CONF_PARSER_SIMPLE_INIT(filePath.c_str());
}

int Configuration::getIntValue(string category, string item)
{
    return CONF_PARSER_GET_NUM_VAL(category.c_str(), item.c_str());
}

string Configuration::getStringValue(string category, string item)
{
    return CONF_PARSER_GET_VAL(category.c_str(), item.c_str());
}

