#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"
#include "concretescene.h"

class SceneManager : public BaseManager
{
private:
    BaseScene *scene;
    Iterator<BaseCamera*> camera;
    Iterator<BaseObject*> object;

public:
    SceneManager(BaseScene *);
    ~SceneManager();

    Iterator<BaseObject *> addObject(BaseObject *);
    Iterator<BaseCamera *> addCamera(BaseCamera *);

    Iterator<BaseCamera *>& currentCamera();
    Iterator<BaseObject *>& currentObject();

    BaseScene *getScene();

    void clear();
};

#endif // SCENEMANAGER_H
