#include "concretemodel.h"


ConcreteModelImp::ConcreteModelImp(){}
ConcreteModelImp::~ConcreteModelImp()
{
    this->points.clear();
    this->edges.clear();
}

List<Point>& ConcreteModelImp::getPoints()
{
    return this->points;
}
List<Edge>& ConcreteModelImp::getEdges()
{
    return this->edges;
}

void ConcreteModelImp::addPoint(Point& point)
{
    this->points.push_front(point);
}
void ConcreteModelImp::addPoint(double x,double y,double z)
{
    this->points.push_front(Point(x, y, z));
}

void ConcreteModelImp::addEdge(Edge &edge)
{
    this->edges.push_front(edge);
}
void ConcreteModelImp::addEdge(Point* from, Point* to)
{
    this->edges.push_front( Edge(from, to) );
}

size_t ConcreteModelImp::getPointsCount() const
{
    return this->points.size();
}
size_t ConcreteModelImp::getEdgesCount() const
{
    return this->edges.size();
}

ConcreteModel::ConcreteModel(ModelImp* imp){
    this->imp = imp;
}
ConcreteModel::ConcreteModel(const ConcreteModel& model)
{
    (*this) = model;
}
ConcreteModel& ConcreteModel::operator =(const ConcreteModel& model)
{
    this->imp = model.imp; //?????????!!!?!!!!
    return *this;
}

ConcreteModel::~ConcreteModel()
{
    delete this->imp;
}

List<Point>& ConcreteModel::getPoints()
{
    return this->imp->getPoints();
}
List<Edge>& ConcreteModel::getEdges()
{
    return this->imp->getEdges();
}

void ConcreteModel::addPoint(Point& point)
{
    this->imp->addPoint(point);
}
void ConcreteModel::addPoint(double x,double y,double z)
{
    this->imp->addPoint(x,y,z);
}

void ConcreteModel::addEdge(Edge &edge)
{
    this->imp->addEdge(edge);
}
void ConcreteModel::addEdge(Point* from, Point* to)
{
    this->imp->addEdge(from, to);
}

size_t ConcreteModel::getPointsCount() const
{
    return this->imp->getPointsCount();
}
size_t ConcreteModel::getEdgesCount() const
{
    return this->imp->getEdgesCount();
}
