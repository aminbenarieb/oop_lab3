#ifndef CANVAS_H
#define CANVAS_H

#include "basecanvas.h"
#include "basemodel.h"
#include "baseexception.h"

class EmptyCanvasException : public BaseException
{
public:
    virtual const char* what()
    {
        return "Canvas instance is empty!";
    }
};


class QCanvasImp : public BaseCanvasImp
{
private:
    CanvasInfo info;
    QPen *pen;
public:
    QCanvasImp(const CanvasInfo*);
    ~QCanvasImp();

    virtual void clear() override;
    virtual void drawEdge(double, double, double, double) override;
    virtual void drawPoint(double, double) override;
};
class Canvas : public BaseCanvas
{
public:
    Canvas(BaseCanvasImp*);
    ~Canvas();

    virtual void clear() override;
    virtual void drawEdge(double, double, double, double) override;
    virtual void drawPoint(double, double) override;

};


#endif // CANVAS_H
