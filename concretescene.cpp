#include "concretescene.h"

ConcreteScene::ConcreteScene(){}

ConcreteScene::~ConcreteScene()
{
    this->clear();
}


void ConcreteScene::clear()
{
    this->compositor.removeAll();
    this->cameraList.clear();
}


Iterator<BaseObject *> ConcreteScene::addObject(BaseObject *object)
{
    this->compositor.addObject(object);
    return this->compositor.begin();
}
Iterator<BaseCamera *> ConcreteScene::addCamera(BaseCamera *camera)
{
    this->cameraList.push_front(camera);
    Iterator<BaseCamera*>iterator(this->cameraList);
    iterator.begin();
    return iterator;
}


Iterator<BaseObject *> ConcreteScene::compositorBegin()
{
    return compositor.begin();
}
Iterator<BaseObject *> ConcreteScene::compositorEnd()
{
    return compositor.end();
}
