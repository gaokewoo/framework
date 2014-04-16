#include "PluginParser.h"

PluginParser::PluginParser(string xml_file)
{
    m_xml_file = xml_file;
    doc.LoadFile(m_xml_file.c_str());
}

void PluginParser::printXML()
{
    doc.Print();
}

vector<PluginInfo> PluginParser::getPluginInfo()
{
    vector<PluginInfo> v_pluginInfo;

    XMLElement *plugins=doc.RootElement();  
    XMLElement *plugin=plugins->FirstChildElement("plugin");
    while(plugin)
    {
        PluginInfo pluginInfo;
        pluginInfo.m_pluginName=plugin->FirstChildElement("pluginName")->GetText();
        pluginInfo.m_soName=plugin->FirstChildElement("library")->GetText();
        v_pluginInfo.push_back(pluginInfo);

        plugin=plugin->NextSiblingElement();
    }

    return v_pluginInfo;
}

