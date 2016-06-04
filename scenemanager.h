#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"
#include "basescene.h"

class SceneManager : public BaseManager
{
private:
    BaseScene *scene;
    Iterator<BaseCamera*> camera;
    Iterator<BaseObject*> object;

public:
    SceneManager();
    ~SceneManager();

    Iterator<BaseObject *> addObject(BaseObject *);
    Iterator<BaseCamera *> addCamera(BaseCamera *);

    Iterator<BaseCamera *>& currentCamera();
    Iterator<BaseObject *>& currentObject();

    void clear();
};

#endif // SCENEMANAGER_H
