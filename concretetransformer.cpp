#include "concretetransformer.h"
#include "assert.h"

ConcreteTransformer::ConcreteTransformer(){}

void ConcreteTransformer::transformPoint(Point * const point) const
{
    Matrix matrix;
    Matrix::rotateX(matrix, BaseTransformer::convertRadToDeg(this->delta));

    double coord[4];
    point->getCoordList(coord);
    matrix *= coord;
    point->getCoordList(coord);
}

void ConcreteTransformer::transformParams(double *delta, double *beta, double *scale) const
{
    *delta *= this->delta;
    *beta  *= this->beta;
    *scale *= this->scale;
}
