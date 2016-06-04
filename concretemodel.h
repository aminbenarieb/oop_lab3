#ifndef REFINEDMODEL_H
#define REFINEDMODEL_H

#include "basemodel.h"

class RefinedModelImp
{
    virtual ~RefinedModelImp() {}
    virtual void transform(const BaseTransformer&);
};

class RefinedModel : public BaseModel
{
private:
    List<Point> points;
    List<Edge> edges;

public:
    RefinedModel();
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
