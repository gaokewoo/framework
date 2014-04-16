#include "System.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

System & System::getInstance()
{
    static System instance;

    return instance;
}

System::System()
{

}

string System::getSealHome()
{
    char * home=getenv("SEAL_HOME");

    if(home==NULL)
    {
        cerr<<"The SEAL_HOME doesn't exist."<<endl;

        throw;
    }

    return home;
}

string System::getSealConfigurationHome()
{
    char * home=getenv("SEAL_CONFIGURATION_HOME");

    if(home==NULL)
    {
        cerr<<"The SEAL_CONFIGURATION_HOME doesn't exist."<<endl;

        throw;
    }

    return home;
}

string System::getSealLogHome()
{
    char * home=getenv("SEAL_LOG_HOME");

    if(home==NULL)
    {
        cerr<<"The SEAL_LOG_HOME doesn't exist."<<endl;

        throw;
    }

    int ret=access(home,755);
    if(ret<0)
    {
        if(errno == ENOENT)
        {
           ret=mkdir(home,755);
           if(ret<0)
           {
               cerr<<"Create directory "<<home<<" error."<<endl;
               cerr<<"Reason: "<<strerror(errno)<<endl;

               throw;
           }
        }
        else
        {
            cerr<<"Can't access directory "<<home<<" ."<<endl;
            cerr<<"Reason: "<<strerror(errno)<<endl;

            throw;
        }
    }

    return home;
}

