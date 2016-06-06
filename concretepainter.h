#ifndef PAINTER_H
#define PAINTER_H

#include "basepainter.h"
#include "basemodel.h"

class Painter : public BasePainter
{
private:
    void setCoordsForProjection(List<Point>&, BaseCamera*);
    void drawEdges(BaseCanvas*, BaseModel*);

public:
    Painter();
    ~Painter();

    virtual void draw(BaseCanvas *, BaseObject *, BaseCamera *) override;
};

#endif // PAINTER_H
