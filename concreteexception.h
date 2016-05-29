#ifndef CONCRETEEXCEPTION_H
#define CONCRETEEXCEPTION_H

#include "baseexception.h"

class MemoryException  : public BaseException
{
    virtual const char* what()
    {
        return "Memory exception!";
    }
};

class FileNotFoundException  : public BaseException
{
    virtual const char* what()
    {
        return "Unable to open file!";
    }
};

class InputException  : public BaseException
{
    virtual const char* what()
    {
        return "File is corrupted or has unsupported format!";
    }
};


#endif // CONCRETEEXCEPTION_H
