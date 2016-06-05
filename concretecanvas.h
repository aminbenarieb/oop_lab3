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

    void clear();
    void drawEdge(double, double, double, double);
    void drawPoint(double, double);
};
class Canvas : public BaseCanvas
{
public:
    Canvas(BaseCanvasImp*);
    ~Canvas();

    void clear();
    void drawEdge(double, double, double, double);
    void drawPoint(double, double);

};


#endif // CANVAS_H
