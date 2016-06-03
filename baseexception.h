#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "exception"

class BaseException : public std::exception
{
public:
    using std::exception::what;
    const char* what()
    {
       return "Unexpected exception occured.";
    }
};


#endif // EXCEPTION_H
