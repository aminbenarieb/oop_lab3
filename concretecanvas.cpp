#include "concretecanvas.h"
#include <QGraphicsScene>
#include <QPen>

QCanvasImp::QCanvasImp(const CanvasInfo* canvasInfo){

    this->info.qscene = canvasInfo->qscene;
    this->pen = new QPen();
    this->pen->setWidth(2.0);
    this->pen->setColor(QColor(Qt::darkRed));
}

QCanvasImp::~QCanvasImp()
{
    this->clear();
    this->info.qscene = nullptr;
    delete this->pen;
}

void QCanvasImp::clear()
{
    if (!this->info.qscene)
    {
        throw EmptyCanvasException();
    }
    this->info.qscene->clear();
}
void QCanvasImp::drawEdge(double x1, double y1, double x2, double y2)
{
    if (!this->info.qscene)
    {
        throw EmptyCanvasException();
    }
    this->info.qscene->addLine(x1, y1, x2, y2, *this->pen);
}
void QCanvasImp::drawPoint(double x, double y)
{
    if (!this->info.qscene)
    {
        throw EmptyCanvasException();
    }
    this->info.qscene->addLine(x, y, x, y, *this->pen);
}


Canvas::Canvas(BaseCanvasImp* imp)
{
    this->imp = imp;
}

Canvas::~Canvas()
{
    delete this->imp;
}

void Canvas::clear()
{
    this->imp->clear();
}
void Canvas::drawEdge(double x1, double y1, double x2, double y2)
{
    this->imp->drawEdge(x1,y1,x2,y2);
}
void Canvas::drawPoint(double x, double y)
{
    this->imp->drawPoint(x,y);
}
