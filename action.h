#ifndef ACTION_H
#define ACTION_H

#include "concretescene.h"
#include "basemanager.h"

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
enum SourceType
{
    SOURCE_FILE
};
struct StreamInfo
{
    SourceType sourceType;
    const char *sourceName;
};
//--------------


class Action
{

private:
    BaseScene* scene;
    BaseManager sceneManager;
    BaseManager loadManager;
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
