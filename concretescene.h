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

    virtual void clear() override;

    virtual  Iterator<BaseObject *> addObject(BaseObject *) override;
    virtual  Iterator<BaseCamera *> addCamera(BaseCamera *) override;

    virtual  Iterator<BaseCamera *> cameraBegin() override;
    virtual  Iterator<BaseCamera *> cameraEnd() override;

    virtual  Iterator<BaseObject *> compositorBegin() override;
    virtual  Iterator<BaseObject *> compositorEnd() override;
};

#endif // CONCRETESCENE_H
