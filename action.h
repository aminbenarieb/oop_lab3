#ifndef ACTION_H
#define ACTION_H

#include "scenemanager.h"
#include "loadmanager.h"
#include "paintmanager.h"
#include "transformmanager.h"

class Action
{

private:
    SceneManager  *sceneManager;
    LoadManager   *loadManager;
    PaintManager  *paintManager;
    TransformManager *transformManager;

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
