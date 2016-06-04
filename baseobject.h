#ifndef BASEOBJECT_H
#define BASEOBJECT_H

class TransformerManager;
class BaseObject{
public:
    virtual ~BaseObject() {}
    virtual void addObject(BaseObject *){}
    virtual void transform(const TransformerManager&) = 0;
};


#endif // BASEOBJECT_H
