#ifndef CONCRETESCENE_H
#define CONCRETESCENE_H

#include "basescene.h"
#include "compositeobject.h"

class ConcreteScene : public BaseScene
{
private:
    CompositeObject compositor;
    List<BaseCamera*> cameraList;

public:
    ConcreteScene();
    ~ConcreteScene();

    virtual void clear();

    virtual  Iterator<BaseObject *> addObject(BaseObject *);
    virtual  Iterator<BaseCamera *> addCamera(BaseCamera *);

    virtual  Iterator<BaseObject *> compositorBegin();
    virtual  Iterator<BaseObject *> compositorEnd();
};

#endif // CONCRETESCENE_H
