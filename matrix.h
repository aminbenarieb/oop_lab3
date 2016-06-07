#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>

class Matrix
{
private:
    double matrix[4][4];

public:
    Matrix();
    void operator *= (double vec[4]);

    static void rotateX(Matrix&, double);
    static void rotateY(Matrix&, double);
    static void rotateZ(Matrix&, double);
    static void scale  (Matrix&, double);
};


#endif // MATRIX_H
