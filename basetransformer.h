#ifndef BASETRANSFORMER_H
#define BASETRANSFORMER_H

#include "matrix.h"
#include "point.h"
#include "baseexception.h"

enum TransformType
{
    TRANSFORM_ROTATE_X,
    TRANSFORM_ROTATE_Y,
    TRANSFORM_ROTATE_Z,
    TRANSFORM_SCALE
};
struct TransformInfo
{
    TransformType type;
    double delta;
};

class InvalidTransformException : public BaseException
{
public:
    virtual const char* what()
    {
        return "Transform type is not set!";
    }
};

class BaseTransformer
{
protected:
    double delta;
    double beta;
    double scale;

public:
    BaseTransformer() : delta(0), beta(0), scale(0) {}
    BaseTransformer(double _delta) : delta(_delta), beta(0), scale(0) {}
    BaseTransformer(double _delta, double _beta, double _scale) : delta(_delta), beta(_beta), scale(_scale) {}

    virtual ~BaseTransformer() {}

    static double convertRadToDeg(double angle) { return (angle * M_PI) / 180.0; }
    virtual void transformPoint(Point* const, const TransformInfo *) const = 0;
    virtual void transformParams(double*,double*,double*) const = 0;

};

#endif // BASETRANSFORMER_H
