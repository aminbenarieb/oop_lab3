#ifndef FACADE_H
#define FACADE_H

#include "action.h"
#include "concreteiostreamservice.h"

class Facade
{
private:
    AlertWindowService* alertWindowService;
    Action* action;

    void processStream(StreamInfo);

public:
    Facade();
    ~Facade();

    void transformModel(TransformInfo);
    void transformCamera(TransformInfo);

    void uploadModelFromFile(StreamInfo streamInfo = {SOURCE_UNDEFINED, NULL});
    void uploadCameraFromFile(StreamInfo streamInfo = {SOURCE_UNDEFINED, NULL});

    void clearScene();

};

#endif // FACADE_H
