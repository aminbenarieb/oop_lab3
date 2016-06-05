#include "concretemodel.h"


RefinedModelImp::RefinedModelImp(){}
RefinedModelImp::~RefinedModelImp()
{
    this->points.clear();
    this->edges.clear();
}

List<Point>& RefinedModelImp::getPoints()
{
    return this->points;
}
List<Edge>& RefinedModelImp::getEdges()
{
    return this->edges;
}

void RefinedModelImp::addPoint(Point& point)
{
    this->points.push_front(point);
}
void RefinedModelImp::addPoint(double x,double y,double z)
{
    this->points.push_front(Point(x, y, z));
}

void RefinedModelImp::addEdge(Edge &edge)
{
    this->edges.push_front(edge);
}
void RefinedModelImp::addEdge(Point* from, Point* to)
{
    this->edges.push_front( Edge(from, to) );
}

size_t RefinedModelImp::getPointsCount() const
{
    return this->points.size();
}
size_t RefinedModelImp::getEdgesCount() const
{
    return this->edges.size();
}

void RefinedModelImp::transform(const BaseTransformer &transformer)
{
    Iterator<Point> iterator(this->points);
    while (!iterator.isDone())
    {
        (*iterator++).transform(transformer);
    }
}


RefinedModel::RefinedModel(ModelImp* imp){
    this->imp = imp;
}
RefinedModel::RefinedModel(const RefinedModel& model)
{
    (*this) = model;
}
RefinedModel& RefinedModel::operator =(const RefinedModel& model)
{
    this->imp = model.imp; //?????????!!!?!!!!
    return *this;
}

RefinedModel::~RefinedModel()
{
    delete this->imp;
}

List<Point>& RefinedModel::getPoints()
{
    return this->imp->getPoints();
}
List<Edge>& RefinedModel::getEdges()
{
    return this->imp->getEdges();
}

void RefinedModel::addPoint(Point& point)
{
    this->imp->addPoint(point);
}
void RefinedModel::addPoint(double x,double y,double z)
{
    this->imp->addPoint(x,y,z);
}

void RefinedModel::addEdge(Edge &edge)
{
    this->imp->addEdge(edge);
}
void RefinedModel::addEdge(Point* from, Point* to)
{
    this->imp->addEdge(from, to);
}

size_t RefinedModel::getPointsCount() const
{
    return this->imp->getPointsCount();
}
size_t RefinedModel::getEdgesCount() const
{
    return this->imp->getEdgesCount();
}

void RefinedModel::transform(const BaseTransformer &transformer)
{
    this->transform(transformer);
}
