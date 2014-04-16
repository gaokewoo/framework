#ifndef __SYSTEM__
#define __SYSTEM__

#include <iostream>
#include <cstdlib>

using namespace std;

class System
{
    public:
        static System & getInstance();
        string getSealHome();
        string getSealConfigurationHome();
        string getSealLogHome();

    private:
        System();
        System(const System&){};
        System & operator = (const System&){} 

};

#endif

