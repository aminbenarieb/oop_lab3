#include "edge.h"


Edge::Edge() : firstPoint(nullptr), lastPoint(nullptr) {}

Edge::Edge(Point *_firstPoint, Point *_lastPoint): firstPoint(_firstPoint), lastPoint(_lastPoint) {}

Edge::~Edge() {}


bool Edge::operator==(const Edge& edge)
{
    return *(this->firstPoint) == *(edge.getFirstPoint()) &&
           *(this->lastPoint)  == *(edge.getLastPoint());
}

bool Edge::operator!=(const Edge& edge)
{
    return !(*this == edge);
}

void Edge::transform(const BaseTransformer &transformer)
{
    this->firstPoint->transform(transformer);
    this->lastPoint->transform(transformer);
}

Point* Edge::getLastPoint() const
{
    return lastPoint;
}

void Edge::setLastPoint(Point *value)
{
    lastPoint = value;
}

Point* Edge::getFirstPoint() const
{
    return firstPoint;
}

void Edge::setFirstPoint(Point *value)
{
    firstPoint = value;
}
