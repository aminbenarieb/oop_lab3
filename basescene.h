#ifndef BASESCENE_H
#define BASESCENE_H

#include "basecamera.h"
#include "compositeobject.h"
#include "ListContainer/iterator.h"

class BaseScene
{
public:
    virtual ~BaseScene() {}

    virtual void clear() = 0;

    virtual Iterator<BaseCamera*>  addCamera(BaseCamera*) = 0;
    virtual Iterator<BaseObject*>  addObject(BaseObject*) = 0;

    virtual  Iterator<BaseCamera *> cameraBegin() = 0;
    virtual  Iterator<BaseCamera *> cameraEnd() = 0;

    virtual  Iterator<BaseObject *> compositorBegin() = 0;
    virtual  Iterator<BaseObject *> compositorEnd() = 0;
};


#endif // BASESCENE_H
