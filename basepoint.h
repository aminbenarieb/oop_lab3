#ifndef BASEPOINT_H
#define BASEPOINT_H

#include "baseobject.h"

class BasePoint : public BaseObject
{
public:

    virtual void setX(double) = 0;
    virtual void setY(double) = 0;
    virtual void setZ(double) = 0;

    virtual double getX() = 0;
    virtual double getY() = 0;
    virtual double getZ() = 0;
};

#endif // BASEPOINT_H
