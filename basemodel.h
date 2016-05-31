#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "baseobject.h"

class BaseModel : BaseObject
{
    virtual bool addObject(BaseObject *) = 0;
    virtual void change(const BaseTransformManager&) = 0;
};

#endif // BASEMODEL_H
