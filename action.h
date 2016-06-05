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
    SceneManager *sceneManager;
    LoadManager *loadManager;
    BaseManager paintManager;
    BaseManager transformManager;

public:
    Action();
    Action(BaseScene*);
    ~Action();

    void uploadModel(const StreamInfo*);
    void uploadCamera(const StreamInfo*);

//    void setCanvas(const CanvasInfo& info);
    void drawModel();

    void transformModel(const TransformInfo*);
    void transformCamera(const TransformInfo*);

    void clearScene();
};

#endif // ACTION_H
