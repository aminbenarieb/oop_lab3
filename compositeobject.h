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

    virtual bool addObject(BaseObject*) override;
    virtual void removeAll() override;

    virtual Iterator<BaseObject *> begin() override;
    virtual Iterator<BaseObject *> end() override;

    virtual size_t getSize() override;

};


#endif // COMPOSITE_H
