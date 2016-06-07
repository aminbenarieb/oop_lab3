#include "concretetransformer.h"
#include "assert.h"

ConcreteTransformer::ConcreteTransformer(){}

void ConcreteTransformer::transformPoint(Point * const point, const TransformInfo *transformInfo) const
{
    Matrix matrix;

    switch(transformInfo->type)
    {
    case TRANSFORM_ROTATE_X:
        Matrix::rotateX(matrix, BaseTransformer::convertRadToDeg(transformInfo->delta));
                break;
    case TRANSFORM_ROTATE_Y:
        Matrix::rotateY(matrix, BaseTransformer::convertRadToDeg(transformInfo->delta));
                break;
    case TRANSFORM_ROTATE_Z:
        Matrix::rotateZ(matrix, BaseTransformer::convertRadToDeg(transformInfo->delta));
                break;
    case TRANSFORM_SCALE:
        Matrix::scale(matrix, transformInfo->delta);
                break;
    default:
        throw InvalidTransformException();
        break;
    }

    double coord[4];
    point->getCoordList(coord);
    matrix *= coord;
    point->setCoordList(coord);
}

void ConcreteTransformer::transformParams(double *delta, double *beta, double *scale) const
{
    *delta *= this->delta;
    *beta  *= this->beta;
    *scale *= this->scale;
}
