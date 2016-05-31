#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "baseobject.h"
#include "ListContainer/list.h"

class CompositeObject : public BaseObject
{
private:
    List<BaseObject*> objects;

public:
    CompositeObject();
    ~CompositeObject();

    virtual void addObject(BaseObject*) override;
    virtual void transform() override;


    size_t getSize();

    void clear();
};


#endif // COMPOSITE_H
