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

    virtual List<Point>& getPoints() override;
    virtual List<Edge>& getEdges() override;

    virtual void addPoint(Point&) override;
    virtual void addPoint(double,double,double) override;
    virtual void addEdge(Edge&) override;
    virtual void addEdge(Point*,Point*) override;

    virtual size_t getPointsCount() const override;
    virtual size_t getEdgesCount() const override;

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

    virtual List<Point>& getPoints() override;
    virtual List<Edge>& getEdges() override;

    virtual void addPoint(Point&) override;
    virtual void addPoint(double,double,double) override;
    virtual void addEdge(Edge&) override;
    virtual void addEdge(Point*,Point*) override;

    virtual size_t getPointsCount() const override;
    virtual size_t getEdgesCount() const override;

};

#endif // REFINEDMODEL_H
