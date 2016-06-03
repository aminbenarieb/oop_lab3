#ifndef FACADE_H
#define FACADE_H

#include "action.h"
#include "concreteiostreamservice.h"

class Facade
{
private:
    AlertWindowService* alertWindowService;
    Action* action;

public:
    Facade();
    ~Facade();

    void transformModel(TransformInfo);
    void transformCamera(TransformInfo);

    void uploadModelFromFile();
    void uploadCameraFromFile();

    void clearScene();

};

#endif // FACADE_H
