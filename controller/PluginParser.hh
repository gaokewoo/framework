#include <iostream>
#include "tinyxml2.h"

#ifndef __PLUGINPARSER__
#define __PLUGINPARSER__

using namespace std;
using namespace tinyxml2;

class PluginParser
{
    public:
        PluginParser(string xml_file);
        void printXML();

    private:
        string m_xml_file;

};

#endif
