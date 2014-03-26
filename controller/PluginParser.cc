#include "PluginParser.hh"

PluginParser::PluginParser(string xml_file)
{
    m_xml_file = xml_file;
}

void PluginParser::printXML()
{
    XMLDocument doc;
    doc.LoadFile(m_xml_file.c_str());

    doc.Print();
}

int main()
{
    PluginParser parser("../config/plugin.xml");
    parser.printXML();

    return 0;
}
