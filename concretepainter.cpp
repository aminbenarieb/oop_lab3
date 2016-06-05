#include "concretepainter.h"
#include "math.h"
#include "point.h"

Painter::Painter() {}

Painter::~Painter() {}

void Painter::setCoordsForProjection(List<Point> &pointList, BaseCamera *camera)
{
    IteratorConst<Point> iterator(pointList);
    while( !iterator.isDone() )
    {
        Point point,
              tmp = *(iterator++);

        point.setX((tmp.getX()*camera->getCenter().getZ() + tmp.getZ()*camera->getCenter().getX()) /
                (tmp.getZ() + camera->getCenter().getZ()));
        point.setY((tmp.getY() * camera->getCenter().getZ() + tmp.getZ()*camera->getCenter().getY()) /
                (tmp.getZ() + camera->getCenter().getZ()));
        tmp.setX(point.getX());
        tmp.setY(point.getY());
    }
}

void Painter::drawEdges(BaseCanvas *canvas, BaseModel *model)
{
    IteratorConst<Edge> iterator(model->getEdges());
    while( !iterator.isDone() )
    {
        Edge edge = *iterator++;
        Point* firstPoint = edge.getFirstPoint();
        Point* lastPoint  = edge.getLastPoint();
        canvas->drawEdge(firstPoint->getX(), firstPoint->getY(),
                         lastPoint->getX(), lastPoint->getY());
    }
}

void Painter::draw(BaseCanvas *canvas, BaseObject *object, BaseCamera *camera)
{
    BaseModel* model = static_cast<BaseModel*>(object);
    List<Point> tmp_p = model->getPoints();

    this->setCoordsForProjection(model->getPoints(), camera);
    this->drawEdges(canvas, model);

    model->getPoints() = tmp_p;
}
