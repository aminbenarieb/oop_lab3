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


void CompositeObject::addObject(BaseObject *object)
{
    if (object)
    {
        this->objects.push_front(object);
    }
}
void CompositeObject::removeAll()
{
    Iterator<BaseObject*> iterator(this->objects);

    while(!iterator.isDone())
    {
        delete *iterator;
        iterator.del();
    }

    if (this->getSize())
    {
        this->objects.clear();
    }
}
void CompositeObject::transform(const TransformerManager &transformer)
{

    Iterator<BaseObject*> iterator(this->objects);
    while(!iterator.isDone())
    {
        (*iterator)->transform(transformer);
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
