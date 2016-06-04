#include "concretemodel.h"

//RefinedModelImp::RefinedModelImp(const RefinedModelImp& model)
//{
//    (*this) = model;
//}
//RefinedModelImp& RefinedModelImp::operator =(const RefinedModelImp& model)
//{
//    this->points = model.points;
//    this->edges = model.edges;
//    return *this;
//}

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
void RefinedModelImp::addEdge(Edge &edge)
{
    this->edges.push_front(edge);
}

size_t RefinedModelImp::getPointsCount()
{
    return this->points.size();
}
size_t RefinedModelImp::getEdgesCount()
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
void RefinedModel::addEdge(Edge &edge)
{
    this->imp->addEdge(edge);
}

size_t RefinedModel::getPointsCount()
{
    return this->imp->getPointsCount();
}
size_t RefinedModel::getEdgesCount()
{
    return this->imp->getEdgesCount();
}

void RefinedModel::transform(const BaseTransformer &transformer)
{
    this->transform(transformer);
}
