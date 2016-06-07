#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "ListContainer/iterator.h"

class BaseTransformer;
class BaseObject {
public:
    virtual ~BaseObject() {}
    virtual bool addObject(BaseObject *){ return false; }
    virtual void removeAll(){}

    virtual Iterator<BaseObject *> begin(){ return Iterator<BaseObject*>(); }
    virtual Iterator<BaseObject *> end(){ return Iterator<BaseObject*>(); }

    virtual size_t getSize(){return 0;}

};


#endif // BASEOBJECT_H
