#ifndef BASEEDGE_H
#define BASEEDGE_H


#include "baseobject.h"

class BaseEdge : public BaseObject
{
public:
    virtual void transform() = 0;

    virtual void setFirstPoint(unsigned int) = 0;
    virtual void setSecondPoint(unsigned int) = 0;

    virtual int getFirstPoint() = 0;
    virtual int getSecondPoint() = 0;
};

#endif // BASEEDGE_H
