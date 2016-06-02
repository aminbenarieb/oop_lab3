#ifndef FACADE_H
#define FACADE_H

#include "action.h"

class Facade
{
public:
    Facade();

    void rotateModelX(double);
    void rotateModelY(double);
    void rotateModelZ(double);

    void rotateCameraX(double);
    void rotateCameraY(double);
    void rotateCameraZ(double);

    void scaleModel(double);
    void scaleCamera(double);

    void uploadModelFromFile();
    void uploadCameraFromFile();

    void clearScene();

};

#endif // FACADE_H
