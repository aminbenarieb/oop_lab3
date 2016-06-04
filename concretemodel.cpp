#include "concretemodel.h"

RefinedModel::RefinedModel(){}
RefinedModel::RefinedModel(const RefinedModel& model)
{
    (*this) = model;
}
RefinedModel& RefinedModel::operator =(const RefinedModel& model)
{
    this->points = model.points;
    this->edges = model.edges;
    return *this;
}

RefinedModel::~RefinedModel()
{
    this->points.clear();
    this->edges.clear();
}

List<Point>& RefinedModel::getPoints()
{
    return this->points;
}
List<Edge>& RefinedModel::getEdges()
{
    return this->edges;
}

void RefinedModel::addPoint(Point& point)
{
    this->points.push_front(point);
}
void RefinedModel::addEdge(Edge &edge)
{
    this->edges.push_front(edge);
}

size_t RefinedModel::getPointsCount()
{
    return this->points.size();
}
size_t RefinedModel::getEdgesCount()
{
    return this->edges.size();
}

void RefinedModel::transform(const BaseTransformer &transformer)
{
    Iterator<Point> iterator(this->points);
    while (!iterator.isDone())
    {
        (*iterator++).transform(transformer);
    }
}
