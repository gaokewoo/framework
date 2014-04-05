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

int main()
{
    PluginParser parser("../../config/plugin.xml");
    //parser.printXML();
    vector<PluginInfo> v_pluginInfo=parser.getPluginInfo();

    vector<PluginInfo>::iterator it;
    for(it=v_pluginInfo.begin();it!=v_pluginInfo.end();++it)
    {
        cout<<it->m_pluginName<<":"<<it->m_soName<<endl;
    }

    return 0;
}
