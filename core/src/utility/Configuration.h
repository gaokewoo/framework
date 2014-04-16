#ifndef __CONFIGURATION__
#define __CONFIGURATION__

#include <iostream>
#include "confparser/confparser.hpp"
#include "System.h"

using namespace std;

class Configuration
{
    public:
       static Configuration & getInstance();
       int getIntValue(string category, string item);
       string getStringValue(string category, string item);

    private:
        Configuration();
        Configuration(const Configuration&){};
        Configuration & operator = (const Configuration&){} 

};

#endif

