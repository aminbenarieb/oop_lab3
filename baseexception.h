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

class MemoryException : public BaseException
{
public:
    using std::exception::what;
    const char* what()
    {
       return "Unable to allocate memory";
    }
};




#endif // EXCEPTION_H
