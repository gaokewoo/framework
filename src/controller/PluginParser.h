#include <iostream>
#include <vector>
#include "tinyxml2.h"

#ifndef __PLUGINPARSER__
#define __PLUGINPARSER__

using namespace std;
using namespace tinyxml2;

class PluginInfo
{
    public:
        string m_pluginName;
        string m_soName;
};

class PluginParser
{
    public:
        PluginParser(string xml_file);
        void printXML();
        vector<PluginInfo> getPluginInfo();

    private:
        string m_xml_file;
        XMLDocument doc;

};

#endif
