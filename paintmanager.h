#ifndef PAINTMANAGER_H
#define PAINTMANAGER_H

#include "basemanager.h"

#include "basepainter.h"
#include "basecanvas.h"

#include "compositeobject.h"
#include "basecamera.h"
#include "basescene.h"

#include "ListContainer/list.h"

class PaintManager : public BaseManager
{
private:
    BaseCanvas*   canvas;
    BasePainter*  painter;

public:
    PaintManager(const CanvasInfo*);
    ~PaintManager();

    void drawObject (BaseObject*, BaseCamera *);
    void drawObject (CompositeObject*, BaseCamera*);
    void drawScene  (BaseScene*, Iterator<BaseCamera*>&);

};


#endif // PAINTMANAGER_H
