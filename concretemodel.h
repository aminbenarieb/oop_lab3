#ifndef REFINEDMODEL_H
#define REFINEDMODEL_H

#include "basemodel.h"

class RefinedModelImp : public ModelImp
{
private:
    List<Point> points;
    List<Edge>  edges;

public:
    ~RefinedModelImp();

    virtual List<Point>& getPoints();
    virtual List<Edge>& getEdges();

    virtual void addPoint(Point&);
    virtual void addEdge(Edge&);

    virtual size_t getPointsCount();
    virtual size_t getEdgesCount();

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
    void addEdge(Edge&);

    size_t getPointsCount();
    size_t getEdgesCount();

    virtual void transform(const BaseTransformer&);

};

#endif // REFINEDMODEL_H
