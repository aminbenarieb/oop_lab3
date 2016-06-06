#ifndef REFINEDMODEL_H
#define REFINEDMODEL_H

#include "basemodel.h"

class ConcreteModelImp : public ModelImp
{
private:
    List<Point> points;
    List<Edge>  edges;

public:
    ConcreteModelImp();
    ~ConcreteModelImp();

    virtual List<Point>& getPoints();
    virtual List<Edge>& getEdges();

    virtual void addPoint(Point&);
    virtual void addPoint(double,double,double);
    virtual void addEdge(Edge&);
    virtual void addEdge(Point*,Point*);

    virtual size_t getPointsCount() const;
    virtual size_t getEdgesCount() const;

    virtual void transform(const BaseTransformer&);

};

class ConcreteModel : public BaseModel
{
private:
    ModelImp *imp;

public:
    ConcreteModel(ModelImp*);
    ConcreteModel(const ConcreteModel&);
    ConcreteModel& operator=(const ConcreteModel&);

    ~ConcreteModel();

    List<Point>& getPoints();
    List<Edge>& getEdges();

    void addPoint(Point&);
    void addPoint(double,double,double);
    void addEdge(Edge&);
    void addEdge(Point*,Point*);

    size_t getPointsCount() const;
    size_t getEdgesCount() const;

    virtual void transform(const BaseTransformer&);

};

#endif // REFINEDMODEL_H
