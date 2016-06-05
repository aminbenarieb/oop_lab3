#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "baseobject.h"
#include "point.h"
#include "edge.h"
#include "ListContainer/list.h"

class ModelImp
{
public:
    virtual ~ModelImp() {}
    virtual void transform(const BaseTransformer&) = 0;

    virtual void addPoint(Point&) = 0;
    virtual void addPoint(double,double,double) = 0;
    virtual void addEdge(Edge&) = 0;
    virtual void addEdge(Point*,Point*) = 0;

    virtual List<Point>& getPoints() = 0;
    virtual List<Edge>& getEdges()  = 0;

    virtual size_t getPointsCount() const = 0;
    virtual size_t getEdgesCount() const = 0;
};

class BaseModel : public BaseObject
{
protected:
    ModelImp* imp;

public:
    virtual ~BaseModel() {}

    virtual void transform(const BaseTransformer&) = 0;

    virtual void addPoint(Point&) = 0;
    virtual void addPoint(double,double,double) = 0;
    virtual void addEdge(Edge&) = 0;
    virtual void addEdge(Point*,Point*) = 0;

    virtual List<Point>& getPoints() = 0;
    virtual List<Edge>& getEdges() = 0;

    virtual size_t getPointsCount() const = 0;
    virtual size_t getEdgesCount() const = 0;

};

#endif // BASEMODEL_H
