#include "compositeobject.h"

CompositeObject::CompositeObject() {}
CompositeObject::~CompositeObject()
{
    this->removeAll();
}


size_t CompositeObject::getSize()
{
    return this->objects.size();
}


bool CompositeObject::addObject(BaseObject *object)
{
    if (object)
    {
        this->objects.push_front(object);
    }

    return true;
}
void CompositeObject::removeAll()
{
    Iterator<BaseObject*> iterator(this->objects);

    while(!iterator.isDone())
    {
        delete *iterator;
        iterator++;
    }

    if (this->getSize())
    {
        this->objects.clear();
    }
}


Iterator<BaseObject *> CompositeObject::begin()
{
    Iterator<BaseObject*> iterator(this->objects);
    iterator.begin();
    return iterator;
}
Iterator<BaseObject *> CompositeObject::end()
{
    Iterator<BaseObject*> iterator(this->objects);
    iterator.end();
    return iterator;
}
