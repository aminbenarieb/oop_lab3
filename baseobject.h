#ifndef BASEOBJECT_H
#define BASEOBJECT_H

class BaseTransformManager;
class BaseObject{

    virtual bool addObject(BaseObject *) = 0;
    virtual void change(const BaseTransformManager& transformManager) = 0;

};


#endif // BASEOBJECT_H
