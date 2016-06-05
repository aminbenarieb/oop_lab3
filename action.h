#ifndef ACTION_H
#define ACTION_H

#include "basemanager.h"
#include "scenemanager.h"
#include "loadmanager.h"
#include "paintmanager.h"

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
    LoadManager  *loadManager;
    PaintManager *paintManager;
    BaseManager transformManager;

public:
    Action(const CanvasInfo *canvasInfo = nullptr);
    Action(BaseScene*);
    ~Action();

    void uploadModel(const StreamInfo*);
    void uploadCamera(const StreamInfo*);

    void drawScene();
    void clearScene();

    void transformModel(const TransformInfo*);
    void transformCamera(const TransformInfo*);

};

#endif // ACTION_H
