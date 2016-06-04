#ifndef BASEOBJECT_H
#define BASEOBJECT_H

class BaseTransformer;
class BaseObject{
public:
    virtual ~BaseObject() {}
    virtual void addObject(BaseObject *){}
    virtual void transform(const BaseTransformer&) = 0;
};


#endif // BASEOBJECT_H
