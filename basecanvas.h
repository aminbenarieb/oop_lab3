#ifndef BASECANVAS_H
#define BASECANVAS_H

class QGraphicsScene;
class QPen;


struct CanvasInfo
{
    QGraphicsScene* qscene;
};


class BaseCanvasImp {
public:
    virtual ~BaseCanvasImp(){}

    virtual void clear() = 0;
    virtual void drawPoint(double, double) = 0;
    virtual void drawEdge(double, double, double, double) = 0;
};

class BaseCanvas
{
protected:
    BaseCanvasImp* imp;

public:
    virtual ~BaseCanvas() {}

    virtual void clear() = 0;
    virtual void drawPoint(double, double) = 0;
    virtual void drawEdge(double, double, double, double) = 0;
};

#endif // BASECANVAS_H
