#ifndef ACTION_H
#define ACTION_H

#include "concretescene.h"
#include "basemanager.h"
#include "scenemanager.h"
#include "loadmanager.h"

//--------------
//TEMP LOCATION
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
//--------------


class Action
{

private:
    SceneManager sceneManager;
    LoadManager loadManager;
    BaseManager paintManager;
    BaseManager transformManager;

public:
    Action();
    Action(BaseScene*);
    ~Action();

    void uploadModel(StreamInfo);
    void uploadCamera(StreamInfo);

//    void setCanvas(const CanvasInfo& info);
    void drawModel();

    void transformModel(TransformInfo);
    void transformCamera(TransformInfo);

    void clearScene();
};

#endif // ACTION_H
