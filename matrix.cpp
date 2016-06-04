#include "matrix.h"

Matrix::Matrix()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->matrix[i][j] = 0;
        }
    }
}

void Matrix::operator *=(double vec[4])
{
    double tmp[4];

    int i, j;
    for(i = 0; i < 4; i++)
    {
        tmp[i] = vec[i];
        vec[i] = 0;
    }

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            vec[i] += this->matrix[i][j] * tmp[j];
        }
    }
}

void Matrix::rotateX(Matrix &matrixObject, double angle)
{


    matrixObject.matrix[0][0] = 1;
    matrixObject.matrix[0][1] = 0;
    matrixObject.matrix[0][2] = 0;
    matrixObject.matrix[0][3] = 0;
    matrixObject.matrix[1][0] = 0;
    matrixObject.matrix[1][1] = cos(angle);
    matrixObject.matrix[1][2] = sin(angle);
    matrixObject.matrix[1][3] = 0;
    matrixObject.matrix[2][0] = 0;
    matrixObject.matrix[2][1] = -sin(angle);
    matrixObject.matrix[2][2] = cos(angle);
    matrixObject.matrix[2][3] = 0;
    matrixObject.matrix[3][0] = 0;
    matrixObject.matrix[3][1] = 0;
    matrixObject.matrix[3][2] = 0;
    matrixObject.matrix[3][3] = 1;
}
void Matrix::rotateY(Matrix &matrixObject, double angle)
{
    matrixObject.matrix[0][0] = cos(angle);
    matrixObject.matrix[0][1] = 0;
    matrixObject.matrix[0][2] = sin(angle);
    matrixObject.matrix[0][3] = 0;
    matrixObject.matrix[1][0] = 0;
    matrixObject.matrix[1][1] = 1;
    matrixObject.matrix[1][2] = 0;
    matrixObject.matrix[1][3] = 0;
    matrixObject.matrix[2][0] = -sin(angle);
    matrixObject.matrix[2][1] = 0;
    matrixObject.matrix[2][2] = cos(angle);
    matrixObject.matrix[2][3] = 0;
    matrixObject.matrix[3][0] = 0;
    matrixObject.matrix[3][1] = 0;
    matrixObject.matrix[3][2] = 0;
    matrixObject.matrix[3][3] = 1;

}
void Matrix::rotateZ(Matrix &matrixObject, double angle)
{
    matrixObject.matrix[0][0] = cos(angle);
    matrixObject.matrix[0][1] = sin(angle);
    matrixObject.matrix[0][2] = 0;
    matrixObject.matrix[0][3] = 0;
    matrixObject.matrix[1][0] = -sin(angle);
    matrixObject.matrix[1][1] = cos(angle);
    matrixObject.matrix[1][2] = 0;
    matrixObject.matrix[1][3] = 0;
    matrixObject.matrix[2][0] = 0;
    matrixObject.matrix[2][1] = 0;
    matrixObject.matrix[2][2] = 1;
    matrixObject.matrix[2][3] = 0;
    matrixObject.matrix[3][0] = 0;
    matrixObject.matrix[3][1] = 0;
    matrixObject.matrix[3][2] = 0; matrixObject.matrix[3][3] = 1;

}

void Matrix::scale(Matrix &matrixObject, double k)
{

    matrixObject.matrix[0][0] = k;
    matrixObject.matrix[0][1] = 0;
    matrixObject.matrix[0][2] = 0;
    matrixObject.matrix[0][3] = 0;
    matrixObject.matrix[1][0] = 0;
    matrixObject.matrix[1][1] = k;
    matrixObject.matrix[1][2] = 0;
    matrixObject.matrix[1][3] = 0;
    matrixObject.matrix[2][0] = 0;
    matrixObject.matrix[2][1] = 0;
    matrixObject.matrix[2][2] = k;
    matrixObject.matrix[2][3] = 0;
    matrixObject.matrix[3][0] = 0;
    matrixObject.matrix[3][1] = 0;
    matrixObject.matrix[3][2] = 0;
    matrixObject.matrix[3][3] = 1;
}

