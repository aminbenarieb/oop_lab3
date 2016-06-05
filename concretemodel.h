#ifndef REFINEDMODEL_H
#define REFINEDMODEL_H

#include "basemodel.h"

class RefinedModelImp : public ModelImp
{
private:
    List<Point> points;
    List<Edge>  edges;

public:
    RefinedModelImp();
    ~RefinedModelImp();

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

class RefinedModel : public BaseModel
{
private:
    ModelImp *imp;

public:
    RefinedModel(ModelImp*);
    RefinedModel(const RefinedModel&);
    RefinedModel& operator=(const RefinedModel&);

    ~RefinedModel();

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
