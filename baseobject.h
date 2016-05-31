#ifndef BASEOBJECT_H
#define BASEOBJECT_H

class BaseTransformManager;
class BaseObject{
    virtual void addObject(BaseObject *){}
    virtual void transform(const BaseTransformManager& transformManager) = 0;
};


#endif // BASEOBJECT_H
