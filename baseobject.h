#ifndef BASEOBJECT_H
#define BASEOBJECT_H

class BaseTransformer;
class BaseObject {
public:
    virtual ~BaseObject() {}
    virtual bool addObject(BaseObject *){ return false; }
};


#endif // BASEOBJECT_H
