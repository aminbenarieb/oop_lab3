#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "exception"

class BaseException : public std::exception
{
public:
    virtual const char* what() = 0;
};


#endif // EXCEPTION_H
