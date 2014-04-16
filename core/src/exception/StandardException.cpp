#include "StandardException.h"

StandardException::StandardException():TException("Default StandardException")
{
    errorCode_ = "Unknow";
}

StandardException::StandardException(const string & errorCode,const string & message):TException(message)
{
    errorCode_ = errorCode;
}

StandardException::~StandardException() throw()
{

}

const char * StandardException::what() const throw()
{
    if(message_.empty())
    {
        string err = "Error Code: Unknow\nError Reason: Unkonw";

        return err.c_str();
    }
    else
    {
        string err = "Error Code: "+errorCode_+"\nError Reason: "+message_;

        return err.c_str();
    }
}

