#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "baseobject.h"
#include "ListContainer/list.h"
#include "ListContainer/iterator.h"

class CompositeObject : public BaseObject
{
private:
    List<BaseObject*> objects;

public:
    CompositeObject();
    ~CompositeObject();

    void addObject(BaseObject*);
    void transform(const TransformerManager&);
    void removeAll();

    Iterator<BaseObject *> begin();
    Iterator<BaseObject *> end();

    size_t getSize();

};


#endif // COMPOSITE_H
