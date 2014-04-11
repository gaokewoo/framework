#ifndef __STANDARD_EXCEPTION__
#define __STANDARD_EXCEPTION__

#include <iostream>
#include <thrift/Thrift.h>

using namespace std;
using namespace ::apache::thrift;

class StandardException : public TException
{
    public:
        StandardException();
        StandardException(const string & errorCode,const string & message);
        virtual ~StandardException() throw();

        virtual const char* what() const throw();

    protected:
        string errorCode_;
};

#endif

