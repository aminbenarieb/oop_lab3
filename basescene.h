#ifndef BASESCENE_H
#define BASESCENE_H

#include "basecamera.h"
#include "compositeobject.h"
#include "ListContainer/iterator.h"

class BaseScene
{

private:


public:
    virtual ~BaseScene() {}

    virtual void clear() = 0;

    virtual Iterator<BaseCamera*>  addCamera(BaseCamera*) = 0;
    virtual Iterator<BaseObject*>  addObject(BaseObject*) = 0;

    virtual  Iterator<BaseObject *> compositorBegin() = 0;
    virtual  Iterator<BaseObject *> compositorEnd() = 0;

//    virtual size_t modelCount() = 0;
//    virtual size_t viewerCount() = 0;
};


#endif // BASESCENE_H
