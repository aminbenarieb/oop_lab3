#include "concretepainter.h"
#include "math.h"
#include "point.h"
#include <QDebug>

Painter::Painter() {}

Painter::~Painter() {}

void Painter::setCoordsForProjection(List<Point> &pointList, BaseCamera *camera)
{
    Iterator<Point> iterator(pointList);
    while( !iterator.isDone() )
    {
        Point point,
              tmp = *iterator;

        point.setX((tmp.getX()*camera->getCenter().getZ() + tmp.getZ()*camera->getCenter().getX()) /
                (tmp.getZ() + camera->getCenter().getZ()));
        point.setY((tmp.getY() * camera->getCenter().getZ() + tmp.getZ()*camera->getCenter().getY()) /
                (tmp.getZ() + camera->getCenter().getZ()));

        iterator<<point;
        iterator++;
    }
}

void Painter::drawEdges(BaseCanvas *canvas, BaseModel *model)
{
    IteratorConst<Edge> iterator(model->getEdges());
    while( !iterator.isDone() )
    {
        Edge edge = *iterator;
        Point* fromPoint = edge.getFirstPoint();
        Point* toPoint  = edge.getLastPoint();

        canvas->drawEdge(fromPoint->getX(), fromPoint->getY(),
                         toPoint->getX(), toPoint->getY());
        iterator++;
    }
}

void Painter::draw(BaseCanvas *canvas, BaseObject *object, BaseCamera *camera)
{
    BaseModel* model = static_cast<BaseModel*>(object);
    List<Point> pointList = model->getPoints();

    this->setCoordsForProjection(model->getPoints(), camera);
    this->drawEdges(canvas, model);

    for (size_t i = 0; i < pointList.size(); i++)
    {
        model->getPoints()[i] = pointList[i];
    }
}
