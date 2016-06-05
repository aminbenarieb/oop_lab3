#ifndef BASEPAINTER_H
#define BASEPAINTER_H

#include "basecanvas.h"
#include "basemodel.h"
#include "basecamera.h"

class BasePainter
{
public:
    virtual ~BasePainter() {}
    virtual void draw(BaseCanvas*, BaseObject*, BaseCamera*) = 0;
};


#endif // BASEPAINTER_H
